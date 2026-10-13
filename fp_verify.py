#!/usr/bin/env python3
"""Verify a finger against an enrolled template.
  ./.venv/bin/python fp_verify.py <name> [threshold]
Captures one touch, matches via the vendor algorithm, prints ACCEPT/REJECT.
Exit code 0 = ACCEPT, 1 = REJECT (usable by PAM/scripts).
"""
import os
import sys
import time
import subprocess
import numpy as np

import capture_bio_5503 as cap
import capture_multi as cm
from fp_enroll import open_device, RE


def main():
    name = sys.argv[1] if len(sys.argv) > 1 else "thumb"
    thr = sys.argv[2] if len(sys.argv) > 2 else "3"
    tmpl = os.path.join("templates", name + ".bin")
    if not os.path.exists(os.path.join(RE, tmpl)):
        sys.exit(f"no template for '{name}', run fp_enroll.py first")

    device, term = open_device()
    print(">>> baseline: keep the sensor EMPTY...")
    time.sleep(0.2)
    bg = cm.capture_press(device, term)

    try:
        input(">>> place finger + HOLD, then Enter to verify... ")
    except EOFError:
        pass
    fp = cm.capture_press(device, term)
    if fp is None or int((np.abs(bg - fp) > 150).sum()) < 1500:
        print("finger not detected"); sys.exit(1)

    probe = os.path.join(RE, "templates", "_probe.raw")
    np.asarray(fp, dtype=np.uint16).reshape(-1).tofile(probe)

    env = dict(os.environ, FP_TEMPLATE=tmpl, FP_THRESHOLD=str(thr),
               WINEDEBUG="-all", WINEDLLOVERRIDES="winedbg.exe=d")
    r = subprocess.run(["wine", "fpsvc.exe", "verify",
                        os.path.join("templates", "_probe.raw")],
                       cwd=RE, env=env, capture_output=True, text=True)
    res = [l for l in r.stdout.splitlines() if l.startswith("RESULT")]
    line = res[0] if res else "VERIFY FAILED: " + r.stdout + r.stderr
    print("\n>>> " + line)
    accept = "verdict=ACCEPT" in line
    print(">>> " + ("UNLOCK" if accept else "DENIED"))
    sys.exit(0 if accept else 1)


if __name__ == "__main__":
    main()
