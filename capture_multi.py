"""Capture several separate finger presses to test match repeatability.

  ./.venv/bin/python capture_multi.py <label> <count>
"""
import os
import sys

import numpy as np
from scipy.ndimage import median_filter, gaussian_filter

import goodix
import tool
import capture_bio_5503 as cap

OUT = "presses"
N_BURST = 12


def interpolate_dead(img, mask):
    out = img.copy()
    out[mask] = 0.0
    todo = mask.copy()
    for size in (3, 3, 5, 5, 7, 9):
        if not todo.any():
            break
        med = median_filter(out, size=size)
        fill = todo & (med != 0)
        out[fill] = med[fill]
        todo = todo & (out == 0)
    return out


def save_png(clean, path):
    from PIL import Image, ImageOps
    a = clean - clean.min()
    a = (a / a.max() * 255).astype("uint8") if a.max() > 0 else a.astype("uint8")
    im = Image.fromarray(a).transpose(Image.TRANSPOSE)
    im = im.resize((im.size[0] * 6, im.size[1] * 6), Image.NEAREST)
    im = ImageOps.autocontrast(im, cutoff=1)
    im.save(path)


def setup(device, term):
    device.reset(True, False, 20)
    device.read_sensor_register(0x0000, 4)
    device.nop()
    device.read_otp()
    device.pov_image_check()
    term.handshake(device)
    if not device.upload_config_mcu(cap.DEVICE_CONFIG):
        raise SystemExit("config upload failed")
    device.set_drv_state()
    device.set_drv_state()
    device.mcu_get_pov_image()
    device.mcu_switch_to_fdt_mode(cap.FDT_BASE, True)


def capture_press(device, term):
    frames = []
    for _ in range(N_BURST):
        px = cap.frame_pixels(device, term)
        if px is not None:
            frames.append(np.array(px, float).reshape(cap.SENSOR_WIDTH,
                                                      cap.SENSOR_HEIGHT))
    return np.mean(frames, axis=0) if frames else None


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    label, count = sys.argv[1], int(sys.argv[2])
    os.makedirs(OUT, exist_ok=True)

    device = cap.init_device(0x5503)
    fw = device.firmware_version()
    print(f"Firmware: {fw}")
    if not cap.check_psk(device):
        print(">>> community PSK not present, restoring it...")
        if not device.preset_psk_write(0xbb010003, cap.PSK_WHITE_BOX) \
                or not cap.check_psk(device):
            sys.exit("PSK restore FAILED")
        print(">>> community PSK restored.")

    term = cap.TlsTerminator(cap.PSK)
    setup(device, term)

    # one empty-sensor baseline burst for the dead-pixel mask
    print(">>> capturing baseline (keep sensor EMPTY)...")
    bg = capture_press(device, term)
    dead = (bg < bg.max() * 0.3) | (bg == 0)

    existing = len([f for f in os.listdir(OUT)
                    if f.startswith(label + "-") and f.endswith(".pgm")])
    MIN_CONTRAST = 1500  # px that must differ from the empty baseline
    for i in range(existing, existing + count):
        while True:
            try:
                input(f"\n>>> [{label} #{i}] PLACE finger on the sensor and "
                      f"HOLD it there, THEN press Enter... ")
            except EOFError:
                pass
            fp = capture_press(device, term)
            if fp is None:
                print("    no frames captured; let's try again.")
                continue
            contrast = int((np.abs(bg - fp) > 150).sum())
            if contrast < MIN_CONTRAST:
                print(f"    finger NOT detected (contrast {contrast}). Keep "
                      f"your finger firmly on the sensor and retry this one.")
                continue
            break
        fpc = gaussian_filter(interpolate_dead(fp, dead), 0.8)
        base = os.path.join(OUT, f"{label}-{i}")
        tool.write_pgm([int(v) for v in fp.reshape(-1)],
                       cap.SENSOR_WIDTH, cap.SENSOR_HEIGHT, base + ".pgm")
        save_png(fpc, base + ".png")
        print(f"    OK, saved {base}.png  (finger contrast: {contrast} px). "
              f"You can lift your finger.")

    print("\nDone.")


if __name__ == "__main__":
    main()
