#!/usr/bin/env python3
"""Build frames/calidata.blob from frames/base.raw. Layout: re/research/README.md.

  python3 build_calidata.py [base.raw] [calidata.blob]
  python3 build_calidata.py --verify base.raw calidata.blob
"""
import sys
import zlib

BLOB_LEN = 0x224b0
NPX = 5120
OFF_BASE_A = 0x08
OFF_BASE_B = 0x9928
OFF_VERSION = 0x22490
VERSION = b"Preprocess_v_1.01.01"


def jamcrc(data: bytes) -> int:
    return zlib.crc32(data) ^ 0xFFFFFFFF


def build(base: bytes) -> bytes:
    if len(base) != NPX * 2:
        raise ValueError(f"base must be {NPX*2} bytes ({NPX} uint16), got {len(base)}")
    buf = bytearray(BLOB_LEN)
    crc = jamcrc(base).to_bytes(4, "little")
    buf[0x00:0x04] = crc
    buf[0x04:0x08] = crc
    buf[OFF_BASE_A:OFF_BASE_A + len(base)] = base
    buf[OFF_BASE_B:OFF_BASE_B + len(base)] = base
    buf[OFF_VERSION:OFF_VERSION + len(VERSION)] = VERSION
    return bytes(buf)


def main(argv):
    if len(argv) >= 2 and argv[1] == "--verify":
        # byte-compare against an existing (base, blob) pair
        base = open(argv[2], "rb").read()
        want = open(argv[3], "rb").read()
        got = build(base)
        ok = got == want
        print("VERIFY:", "byte-identical OK" if ok else "MISMATCH")
        if not ok:
            diffs = [i for i in range(min(len(got), len(want))) if got[i] != want[i]]
            print(f"  lengths got={len(got)} want={len(want)}; {len(diffs)} differing bytes"
                  + (f", first @ {hex(diffs[0])}" if diffs else ""))
        return 0 if ok else 1
    base_path = argv[1] if len(argv) > 1 else "frames/base.raw"
    out_path = argv[2] if len(argv) > 2 else "frames/calidata.blob"
    base = open(base_path, "rb").read()
    open(out_path, "wb").write(build(base))
    print(f"wrote {out_path} ({BLOB_LEN} bytes) from {base_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
