"""Safe capture-only runner for Goodix 27c6:5503 with an in-process TLS-PSK terminator.

  ./.venv/bin/python capture_bio_5503.py
"""
import os
import re
import ssl
import sys
from time import sleep

import goodix
import protocol
import tool

WORKING_FIRMWARE = r"GF32[05]8_RTSEC_APP_10062"

PSK = bytes.fromhex(
    "0000000000000000000000000000000000000000000000000000000000000000")
PSK_WHITE_BOX = bytes.fromhex(
    "ec35ae3abb45ed3f12c4751f1e5c2cc05b3c5452e9104d9f2a3118644f37a04b"
    "6fd66b1d97cf80f1345f76c84f03ff30bb51bf308f2a9875c41e6592cd2a2f9e"
    "60809b17b5316037b69bb2fa5d4c8ac31edb3394046ec06bbdacc57da6a756c5")
PMK_HASH = bytes.fromhex(
    "81b8ff490612022a121a9449ee3aad2792f32b9f3141182cd01019945ee50361")

DEVICE_CONFIG = bytes.fromhex(
    "581160712c9d2cc91ce518fd00fd00fd03ba000180ca0004008400c0b38600bb"
    "c48800baba8a00b2b28c00aaaa8e00c1c19000bbbb9200b1b1940000a8960000"
    "b6980000009a000000d2000000d4000000d6000000d800000050000105d00000"
    "00700000007200785674003412200010402a0102042200012024003200800001"
    "005c008000560024205800030032000c02660000027c000058820080152a0182"
    "032200012024001400800001005c000001560004205800030032000c02660000"
    "027c000058820080162a0108005c000001540000016200080464001000660000"
    "027c0000582a0108005c0000015200080054000001660000027c00005800a474"
)

SENSOR_WIDTH = 80
SENSOR_HEIGHT = 64
FDT_BASE = bytes.fromhex("0d018b0084008c0088008096809180928085808c8086")
IMG_PAYLOAD = bytes.fromhex("01008b0084008c008800")
FLAGS_TLS = goodix.FLAGS_TRANSPORT_LAYER_SECURITY


class TlsTerminator:
    """TLS 1.2 PSK server terminated entirely in this process."""

    def __init__(self, psk):
        ctx = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
        ctx.check_hostname = False
        ctx.verify_mode = ssl.CERT_NONE
        ctx.minimum_version = ssl.TLSVersion.TLSv1_2
        ctx.maximum_version = ssl.TLSVersion.TLSv1_2
        ctx.set_ciphers("PSK-AES128-CBC-SHA256:@SECLEVEL=0")
        ctx.set_psk_server_callback(lambda identity: psk)
        self.inc = ssl.MemoryBIO()
        self.out = ssl.MemoryBIO()
        self.obj = ctx.wrap_bio(self.inc, self.out, server_side=True)

    def _send_out_to_device(self, device):
        data = self.out.read()
        if data:
            device.protocol.write(goodix.encode_message_pack(data, FLAGS_TLS))
        return bool(data)

    def _read_device(self, device):
        reply = goodix.check_message_pack(device.protocol.read(), FLAGS_TLS)
        self.inc.write(reply)

    def handshake(self, device):
        self.inc.write(device.request_tls_connection())
        while True:
            try:
                self.obj.do_handshake()
                break
            except ssl.SSLWantReadError:
                if self._send_out_to_device(device):
                    self._read_device(device)
                else:
                    self._read_device(device)
        # Flush the server's final flight (CCS + Finished) to the device,
        # otherwise it never considers the session established.
        self._send_out_to_device(device)
        sleep(0.01)
        print(f">>> TLS established, cipher: {self.obj.cipher()}")

    def decrypt(self, tls_record):
        self.inc.write(tls_record)
        out = b""
        while True:
            try:
                chunk = self.obj.read(16384)
            except (ssl.SSLWantReadError, ssl.SSLWantWriteError):
                break
            if not chunk:
                break
            out += chunk
        return out


def init_device(product):
    device = goodix.Device(product, protocol.USBProtocol)
    device.nop()
    try:
        device.reset(True, False, 20)
        device.empty_buffer()
        device.nop()
    except Exception as e:
        print(f"(init reset note: {e})")
    return device


def check_psk(device):
    reply = device.preset_psk_read(0xbb020007)
    if not reply[0] or reply[1] != 0xbb020007:
        raise ValueError("Failed to read PSK")
    return reply[2] == PMK_HASH


def frame_pixels(device, term):
    """Capture one frame and return the decoded pixel list (no file write)."""
    record = device.mcu_get_image(
        IMG_PAYLOAD, goodix.FLAGS_TRANSPORT_LAYER_SECURITY_DATA)
    plain = term.decrypt(record[9:])
    if len(plain) < 6:
        return None
    data = plain[:-4] if len(plain) >= SENSOR_WIDTH * SENSOR_HEIGHT // 4 * 6 + 4 \
        else plain[:len(plain) // 6 * 6]
    return tool.decode_image(data)


def grab_frame(device, term, label):
    record = device.mcu_get_image(
        IMG_PAYLOAD, goodix.FLAGS_TRANSPORT_LAYER_SECURITY_DATA)
    tls_record = record[9:]
    plain = term.decrypt(tls_record)
    print(f">>> {label}: cipher {len(tls_record)}B -> plain {len(plain)}B")
    if len(plain) < 6:
        print(f">>> {label}: no plaintext, skipping")
        return False
    data = plain[:-4] if len(plain) >= SENSOR_WIDTH * SENSOR_HEIGHT // 4 * 6 + 4 \
        else plain[:len(plain) // 6 * 6]
    image = tool.decode_image(data)
    tool.write_pgm(image, SENSOR_WIDTH, SENSOR_HEIGHT, f"{label}.pgm")
    print(f">>> wrote {label}.pgm ({len(image)} px)")
    return True


def run_capture(device):
    if not device.reset(True, False, 20)[0]:
        raise ValueError("Reset failed")
    device.read_sensor_register(0x0000, 4)
    device.nop()
    device.read_otp()
    device.pov_image_check()

    term = TlsTerminator(PSK)
    term.handshake(device)

    if not device.upload_config_mcu(DEVICE_CONFIG):
        raise ValueError("Failed to upload config")
    device.set_drv_state()
    device.set_drv_state()
    device.mcu_get_pov_image()

    device.mcu_switch_to_fdt_mode(FDT_BASE, True)
    grab_frame(device, term, "clear-0")

    device.mcu_switch_to_fdt_mode(FDT_BASE, True)
    device.mcu_switch_to_idle_mode(20)
    device.read_sensor_register(0x0082, 2)
    grab_frame(device, term, "clear-1")

    if os.environ.get("GOODIX_CLEAR_ONLY"):
        print(">>> CLEAR_ONLY: calibration frames done, skipping finger.")
        return

    n_bg = int(os.environ.get("GOODIX_BG_FRAMES", "10"))
    print(f"\n>>> Capturing {n_bg} baseline frames (keep the sensor EMPTY)...")
    for i in range(n_bg):
        px = frame_pixels(device, term)
        if px is not None:
            tool.write_pgm(px, SENSOR_WIDTH, SENSOR_HEIGHT, f"bg-{i}.pgm")
        sleep(0.1)
    baseline = frame_pixels(device, term)

    try:
        input("\n>>> Put your finger FIRMLY on the sensor, then press Enter... ")
    except EOFError:
        pass

    n_fp = int(os.environ.get("GOODIX_FP_FRAMES", "12"))
    best = None
    best_score = -1
    for i in range(n_fp):
        px = frame_pixels(device, term)
        if px is None:
            continue
        tool.write_pgm(px, SENSOR_WIDTH, SENSOR_HEIGHT, f"fp-{i}.pgm")
        score = sum(1 for a, b in zip(px, baseline) if abs(a - b) > 150)
        print(f"    frame {i}: changed_px={score}")
        if score > best_score:
            best_score, best = score, px
        sleep(0.12)

    if best is None:
        print(">>> no frames captured")
        return
    tool.write_pgm(best, SENSOR_WIDTH, SENSOR_HEIGHT, "fingerprint-0.pgm")
    print(f">>> wrote fingerprint-0.pgm (best contrast: {best_score} px) + "
          f"fp-*.pgm / bg-*.pgm bursts for preprocessing.")
    print(f">>> If changed_px is near 0, the finger wasn't detected.")
    print("\n>>> You can remove your finger now.\n")


def main(product):
    device = init_device(product)
    fw = device.firmware_version()
    print(f"Firmware: {fw}")
    if not re.fullmatch(WORKING_FIRMWARE, fw):
        raise SystemExit(f"Firmware {fw!r} not in working family; aborting.")
    valid = check_psk(device)
    print(f"Valid community PSK already present: {valid}")
    if not valid:
        print(">>> device has no community PSK, writing the white-box PSK into NVM")
        if not device.preset_psk_write(0xbb010003, PSK_WHITE_BOX) \
                or not check_psk(device):
            raise SystemExit("Failed to write PSK")
    run_capture(device)
    print("\nDone.")


if __name__ == "__main__":
    main(0x5503)
