#!/usr/bin/env python3
"""fpd: fingerprint auth daemon, runs as the user.

  ./.venv/bin/python fpd.py [name] [threshold]
"""
import os
import sys
import time
import signal
import socket
import subprocess
import numpy as np

import capture_bio_5503 as cap
import capture_multi as cm
from fp_enroll import open_device, RE

NAME = sys.argv[1] if len(sys.argv) > 1 else "thumb"
THR = int(sys.argv[2]) if len(sys.argv) > 2 else 3
CONTACT_MIN = 1500
TOUCH_TIMEOUT = 10.0
SOCK_PATH = os.path.join(
    os.environ.get("XDG_RUNTIME_DIR", "/run/user/%d" % os.getuid()), "fpd.sock")
NPX = cap.SENSOR_WIDTH * cap.SENSOR_HEIGHT


def log(msg):
    print(time.strftime("%H:%M:%S"), msg, file=sys.stderr, flush=True)


class Matcher:
    """Persistent wine fpsvc.exe serve child: raw frame in, verdict line out."""

    def __init__(self, name, thr):
        tmpl = os.path.join("templates", name + ".bin")
        if not os.path.exists(os.path.join(RE, tmpl)):
            sys.exit(f"no template for '{name}', run fp_enroll.py first")
        env = dict(os.environ, FP_TEMPLATE=tmpl, FP_THRESHOLD=str(thr),
                   WINEDEBUG="-all", WINEDLLOVERRIDES="winedbg.exe=d")
        self.p = subprocess.Popen(
            ["wine", "fpsvc.exe", "serve"], cwd=RE, env=env,
            stdin=subprocess.PIPE, stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL, bufsize=0)
        for _ in range(200):
            line = self.p.stdout.readline()
            if not line:
                raise RuntimeError("matcher died before READY")
            if line.strip() == b"READY":
                log("matcher ready")
                return
        raise RuntimeError("matcher never signalled READY")

    def match(self, frame):
        """Send one frame to the matcher, return (corr, accept)."""
        buf = np.asarray(frame, dtype=np.uint16).reshape(-1)
        if buf.size != NPX:
            raise ValueError(f"frame has {buf.size} px, expected {NPX}")
        self.p.stdin.write(buf.tobytes())
        self.p.stdin.flush()
        line = self.p.stdout.readline().decode(errors="replace").strip()
        corr, accept = -1, False
        for tok in line.split():
            if tok.startswith("corr="):
                try:
                    corr = int(tok[5:])
                except ValueError:
                    pass
        accept = "verdict=ACCEPT" in line
        return corr, accept

    def alive(self):
        return self.p.poll() is None

    def close(self):
        try:
            self.p.stdin.close()
            self.p.terminate()
        except Exception:
            pass


def contrast(bg, px):
    """Count pixels that differ markedly from the empty-sensor baseline."""
    f = np.array(px, float).reshape(cap.SENSOR_WIDTH, cap.SENSOR_HEIGHT)
    return int((np.abs(bg - f) > 150).sum())


def wait_touch(device, term, bg, deadline):
    """Wait until the deadline for a stable finger, return a frame or None."""
    stable = 0
    while time.time() < deadline:
        px = cap.frame_pixels(device, term)
        if px is None:
            continue
        if contrast(bg, px) > CONTACT_MIN:
            stable += 1
            if stable >= 2:
                fp = cm.capture_press(device, term)
                if fp is not None and contrast(bg, fp) >= CONTACT_MIN:
                    return fp
                stable = 0
        else:
            stable = 0
    return None


def wait_lift(device, term, bg, deadline):
    """Wait until the deadline for the finger to leave the sensor."""
    clear = 0
    while time.time() < deadline:
        px = cap.frame_pixels(device, term)
        if px is None:
            continue
        if contrast(bg, px) < CONTACT_MIN:
            clear += 1
            if clear >= 2:
                return
        else:
            clear = 0


def do_auth(device, term, matcher, timeout, retries):
    """One baseline, then up to retries touch/match tries, lift between."""
    bg = cm.capture_press(device, term)
    last_corr = -1
    for i in range(retries):
        deadline = time.time() + timeout
        fp = wait_touch(device, term, bg, deadline)
        if fp is None:
            return ("nofinger" if i == 0 else "nomatch", last_corr)
        corr, accept = matcher.match(fp)
        last_corr = corr
        log(f"AUTH: try {i + 1}/{retries} corr={corr} -> {'ACCEPT' if accept else 'retry'}")
        if accept:
            return ("accept", corr)
        if i + 1 < retries:
            wait_lift(device, term, bg, time.time() + timeout)
    return ("nomatch", last_corr)


def serve_client(conn, device, term, matcher):
    conn.settimeout(60)
    try:
        req = conn.recv(64).decode(errors="replace").strip().upper()
    except socket.timeout:
        return
    tokens = req.split()
    if tokens and tokens[0] == "PING":
        conn.sendall(b"OK\n")
        return
    if not tokens or tokens[0] != "AUTH":
        conn.sendall(b"ERR bad-request\n")
        return
    if not matcher.alive():
        conn.sendall(b"ERR matcher-dead\n")
        return
    timeout = TOUCH_TIMEOUT
    retries = 1
    if len(tokens) > 1:
        try:
            timeout = max(1.0, min(30.0, float(tokens[1])))
        except ValueError:
            pass
    if len(tokens) > 2:
        try:
            retries = max(1, min(5, int(tokens[2])))
        except ValueError:
            pass
    log(f"AUTH: timeout {timeout:g}s, up to {retries} tries")
    result, corr = do_auth(device, term, matcher, timeout, retries)
    if result == "accept":
        conn.sendall(f"ACCEPT corr={corr}\n".encode())
    elif result == "nofinger":
        log("AUTH: no finger")
        conn.sendall(b"REJECT no-finger\n")
    else:
        log(f"AUTH: rejected (best corr={corr})")
        conn.sendall(f"REJECT corr={corr}\n".encode())


def main():
    signal.signal(signal.SIGTERM, lambda *_: sys.exit(0))
    log(f"opening device for template '{NAME}' (threshold {THR})")
    device, term = open_device()
    matcher = Matcher(NAME, THR)

    if os.path.exists(SOCK_PATH):
        os.unlink(SOCK_PATH)
    srv = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    srv.bind(SOCK_PATH)
    os.chmod(SOCK_PATH, 0o660)   # owner + group, root reaches it regardless
    srv.listen(1)
    log(f"listening on {SOCK_PATH}")

    try:
        while True:
            conn, _ = srv.accept()
            try:
                serve_client(conn, device, term, matcher)
            except Exception as e:
                log(f"client error: {e}")
                try:
                    conn.sendall(b"ERR internal\n")
                except Exception:
                    pass
            finally:
                conn.close()
    except KeyboardInterrupt:
        pass
    finally:
        matcher.close()
        try:
            os.unlink(SOCK_PATH)
        except OSError:
            pass
        log("stopped")


if __name__ == "__main__":
    main()
