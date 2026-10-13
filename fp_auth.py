#!/usr/bin/env python3
"""Standalone verify without the daemon, slower: one Wine start per call.

  ./.venv/bin/python fp_auth.py <name> [threshold] [timeout_s]
"""
import os
import sys
import time
import subprocess
import numpy as np

import capture_bio_5503 as cap
import capture_multi as cm
from fp_enroll import open_device, RE

NAME = sys.argv[1] if len(sys.argv) > 1 else "thumb"
THR = sys.argv[2] if len(sys.argv) > 2 else "3"
TIMEOUT = float(sys.argv[3]) if len(sys.argv) > 3 else 10.0
CONTACT_MIN = 1500


def log(msg):
    print(msg, file=sys.stderr, flush=True)


def main():
    tmpl = os.path.join("templates", NAME + ".bin")
    if not os.path.exists(os.path.join(RE, tmpl)):
        log(f"no template for '{NAME}'"); sys.exit(1)

    device, term = open_device()
    bg = cm.capture_press(device, term)

    log("Touch the fingerprint sensor...")
    t0 = time.time()
    present = 0
    while time.time() - t0 < TIMEOUT:
        px = cap.frame_pixels(device, term)
        if px is None:
            continue
        f = np.array(px, float).reshape(cap.SENSOR_WIDTH, cap.SENSOR_HEIGHT)
        if int((np.abs(bg - f) > 150).sum()) > CONTACT_MIN:
            present += 1
            if present >= 2:
                break
        else:
            present = 0
    else:
        log("timeout, no finger detected"); sys.exit(1)

    fp = cm.capture_press(device, term)
    if fp is None or int((np.abs(bg - fp) > 150).sum()) < CONTACT_MIN:
        log("capture failed"); sys.exit(1)

    probe = os.path.join(RE, "templates", "_auth_probe.raw")
    np.asarray(fp, dtype=np.uint16).reshape(-1).tofile(probe)

    env = dict(os.environ, FP_TEMPLATE=tmpl, FP_THRESHOLD=str(THR),
               WINEDEBUG="-all", WINEDLLOVERRIDES="winedbg.exe=d")
    r = subprocess.run(["wine", "fpsvc.exe", "verify",
                        os.path.join("templates", "_auth_probe.raw")],
                       cwd=RE, env=env, capture_output=True, text=True)
    res = [l for l in r.stdout.splitlines() if l.startswith("RESULT")]
    line = res[0] if res else "verify failed"
    log(line)
    sys.exit(0 if "verdict=ACCEPT" in line else 1)


if __name__ == "__main__":
    main()
