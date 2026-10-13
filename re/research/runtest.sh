#!/bin/bash
# Export freshly captured presses (presses/{enroll,genuine,impostor}-*.pgm) to
# raw and run the vendor matcher (harness4.exe) to show genuine/impostor scores.
set -e
cd "$(dirname "$0")"
PROJ="$(cd ../.. && pwd)"
VENV="$PROJ/.venv"

"$VENV/bin/python" - "$PROJ" <<'PY'
import glob, os, sys, numpy as np
proj = sys.argv[1]
sys.path.insert(0, proj)
import tool
def export(pattern, dst):
    os.makedirs(dst, exist_ok=True)
    for f in glob.glob(os.path.join(dst, "*.raw")):
        os.remove(f)
    n = 0
    for f in sorted(glob.glob(pattern)):
        w, h, d, img = tool.read_pgm(f)
        if len(img) == 5120:
            np.array(img, dtype=np.uint16).tofile(os.path.join(dst, f"{n}.raw"))
            n += 1
    return n
P = os.path.join(proj, "presses")
e = export(os.path.join(P, "enroll-*.pgm"),   "testset/enroll")
g = export(os.path.join(P, "genuine-*.pgm"),  "testset/genuine")
i = export(os.path.join(P, "impostor-*.pgm"), "testset/impostor")
print(f"exported: enroll={e}  genuine={g}  impostor={i}")
if e == 0 or g == 0 or i == 0:
    print("!! missing frames, capture enroll/genuine/impostor first")
    sys.exit(1)
PY

echo "=== vendor matcher (correspondence count) ==="
OUTLEN=5120 WINEDEBUG=-all WINEDLLOVERRIDES="winedbg.exe=d" \
    wine harness4.exe 2>/dev/null | grep -vE 'fixme|wine:|preloader'
