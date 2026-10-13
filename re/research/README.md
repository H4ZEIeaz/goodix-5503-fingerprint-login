# re/research: reverse-engineering provenance

Not needed to run the login. This is the trail that made it work, kept for a
future native port and a how-to guide.

## Tools

- `harness2.c`: full enroll and identify harness under Wine, with the DLL's
  internal logger hooked. Its breakpoint sits at RVA 0x9faef and reads R13D, the
  geometric-verification result of FUN_18009bf60.
- `harness4.c` and `runtest.sh`: batch genuine and impostor evaluation. The
  breakpoint sits at RVA 0x9f79f and reads EDI, the correspondence count at the
  `cmp $0x4,%edi` in FUN_18009f4a0. This count is the match metric the project
  uses, and `re/fpsvc.c` reads it the same way.
- `decomp/`: about 50 Ghidra decompilations of the algorithm exports and their
  callees for enroll, identify, preprocess, template and calibration. The pipeline
  map in the project README is derived from these.
- `decompile_lib.py`: the method. pyghidra is used as a library. Set
  `GHIDRA_INSTALL_DIR` and `GOODIX_DLL`, then run with Ghidra's own venv Python.
- `decompile2.py`, `ExportFuncs.py`, `ExportFuncs.java`: earlier dumpers.

## Running runtest.sh

`harness4.exe` reads `frames/base.raw`, loads the DLL and reads `testset/` relative
to the current directory, which is `re/research/`. Build the harness and link the
DLL, the stub and the calibration frames from `re/`:

```bash
x86_64-w64-mingw32-gcc re/research/harness4.c -o re/research/harness4.exe
ln -s ../frames re/research/frames
ln -s ../GoodixEngineAdapter.dll re/research/GoodixEngineAdapter.dll
ln -s ../api-ms-win-core-debug-minidump-l1-1-0.dll re/research/api-ms-win-core-debug-minidump-l1-1-0.dll
```

Capture the test frames from the project root with `capture_multi.py`, which writes
them into `presses/`:

```bash
./.venv/bin/python capture_multi.py enroll 15
./.venv/bin/python capture_multi.py genuine 6
./.venv/bin/python capture_multi.py impostor 6
```

`runtest.sh` then exports those from `presses/` into `testset/` and runs the
matcher. Captured frames are biometric and are not shipped.

## Calibration blob layout

`re/build_calidata.py` writes `frames/calidata.blob`, size 0x224b0 bytes,
little-endian, zero-filled elsewhere. JAMCRC32 means crc32 followed by xor with
0xffffffff.

| Offset | Content |
|---|---|
| 0x00000 | u32, JAMCRC32 of the base frame |
| 0x00004 | u32, JAMCRC32 of the base frame, repeated |
| 0x00008 | base frame, 5120 int16, 0x2800 bytes |
| 0x09928 | base frame, second copy |
| 0x22490 | ascii string Preprocess_v_1.01.01 |

## Reproducing, high level

Check that the DLL loads under Wine, intercept the correspondence count with the
breakpoint, substitute your captured frames, test genuine against impostor,
extend with a threshold and enrollment, then use it through the daemon and PAM.
The vendor DLL also serves as a byte-exact oracle for a native reimplementation.
