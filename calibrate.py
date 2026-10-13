#!/usr/bin/env python3
"""Per-device calibration: capture an empty-sensor frame, build the calibration blob.

  ./.venv/bin/python calibrate.py
"""
import os
import sys
import time
import numpy as np

import capture_multi as cm
from fp_enroll import open_device, RE

sys.path.insert(0, os.path.join(RE))
import build_calidata  # noqa: E402


def main():
    frames_dir = os.path.join(RE, "frames")
    os.makedirs(frames_dir, exist_ok=True)
    base_path = os.path.join(frames_dir, "base.raw")
    blob_path = os.path.join(frames_dir, "calidata.blob")

    device, term = open_device()
    print(">>> capturing empty-sensor baseline, keep the sensor EMPTY...")
    time.sleep(0.3)
    frames = [cm.capture_press(device, term) for _ in range(3)]
    frames = [f for f in frames if f is not None]
    if not frames:
        sys.exit("no frames captured, is the device present?")
    base = np.mean(frames, axis=0)

    np.asarray(base, dtype=np.uint16).reshape(-1).tofile(base_path)
    base_bytes = open(base_path, "rb").read()
    open(blob_path, "wb").write(build_calidata.build(base_bytes))
    print(f">>> wrote {base_path} ({len(base_bytes)} bytes)")
    print(f">>> wrote {blob_path} ({os.path.getsize(blob_path)} bytes)")
    print(">>> calibration done. Next: enroll a finger with fp_enroll.py.")


if __name__ == "__main__":
    main()
