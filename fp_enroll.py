#!/usr/bin/env python3
"""Enroll a finger: capture coverage frames -> build vendor template via fpsvc.
  ./.venv/bin/python fp_enroll.py <name> [count]
Template is saved to re/templates/<name>.bin
"""
import os
import sys
import time
import subprocess
import numpy as np

import capture_bio_5503 as cap
import capture_multi as cm

HERE = os.path.dirname(os.path.abspath(__file__))
RE = os.path.join(HERE, "re")


def open_device():
    device = cap.init_device(0x5503)
    print("Firmware:", device.firmware_version())
    if not cap.check_psk(device):
        print(">>> restoring community PSK (Windows overwrote it)...")
        if not device.preset_psk_write(0xbb010003, cap.PSK_WHITE_BOX) \
                or not cap.check_psk(device):
            sys.exit("PSK restore failed")
        print(">>> PSK restored.")
    term = cap.TlsTerminator(cap.PSK)
    cm.setup(device, term)
    return device, term


def main():
    name = sys.argv[1] if len(sys.argv) > 1 else "thumb"
    count = int(sys.argv[2]) if len(sys.argv) > 2 else 15
    endir = os.path.join(RE, "templates", name + "_enroll")
    os.makedirs(endir, exist_ok=True)
    for f in os.listdir(endir):
        if f.endswith(".raw"):
            os.remove(os.path.join(endir, f))

    device, term = open_device()
    print(">>> baseline: keep the sensor EMPTY...")
    time.sleep(0.2)
    bg = cm.capture_press(device, term)

    print(f"\nEnrolling '{name}': {count} touches. Cover the whole pad, vary "
          f"position and angle each touch: center, up, down, sides, rolls.")
    got = 0
    while got < count:
        try:
            input(f">>> [{name} {got+1}/{count}] place finger + HOLD, then Enter... ")
        except EOFError:
            pass
        fp = cm.capture_press(device, term)
        if fp is None:
            print("   no frames; retry"); continue
        if int((np.abs(bg - fp) > 150).sum()) < 1500:
            print("   finger NOT detected; press firmly and retry"); continue
        np.asarray(fp, dtype=np.uint16).reshape(-1).tofile(
            os.path.join(endir, f"{got}.raw"))
        got += 1
        print(f"   captured {got}/{count}. Lift and reposition.")

    tmpl = os.path.join("templates", name + ".bin")
    env = dict(os.environ, FP_TEMPLATE=tmpl,
               WINEDEBUG="-all", WINEDLLOVERRIDES="winedbg.exe=d")
    r = subprocess.run(["wine", "fpsvc.exe", "enroll",
                        os.path.join("templates", name + "_enroll")],
                       cwd=RE, env=env, capture_output=True, text=True)
    res = [l for l in r.stdout.splitlines() if l.startswith("RESULT")]
    print("\n" + (res[0] if res else "ENROLL FAILED:\n" + r.stdout + r.stderr))
    print(f"template: {os.path.join(RE, tmpl)}")


if __name__ == "__main__":
    main()
