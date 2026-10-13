# Decompile the vendor DLL's algorithm exports with Ghidra (pyghidra as a library).
# Bring your own GoodixEngineAdapter.dll (see ../../README.md) and set GHIDRA_INSTALL_DIR.
#   GHIDRA_INSTALL_DIR=/opt/ghidra GOODIX_DLL=../GoodixEngineAdapter.dll \
#     <ghidra-venv-python> decompile_lib.py
import os
os.environ.setdefault("GHIDRA_INSTALL_DIR", "/opt/ghidra")
import pyghidra
pyghidra.start()

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

HERE = os.path.dirname(os.path.abspath(__file__))
outdir = os.path.join(HERE, "decomp")
os.makedirs(outdir, exist_ok=True)
targets = set("""enrolStart enrolStartEx enrolAddImage enrolFinish enrolGetTemplate
enrolDeleteImage identifyImage identifytemplate identifyUpdate getQuality
getAlgorithmVersion preprocessor preprocessor_init ppp_param_init templateStudy
templatePack templateUnPack templateGetPackedSize templateDelete GetTptOverlapRate
gx_sensorCheck preprocess_init_calidata preprocess_get_calidata_len
preprocess_set_mode""".split())

dll = os.environ.get("GOODIX_DLL", os.path.join(HERE, "..", "GoodixEngineAdapter.dll"))
with pyghidra.open_program(dll, project_location=os.path.join(HERE, "proj"),
                           project_name="gp", analyze=False) as api:
    prog = api.getCurrentProgram()
    d = DecompInterface()
    d.openProgram(prog)
    mon = ConsoleTaskMonitor()
    w = 0
    for f in prog.getFunctionManager().getFunctions(True):
        if f.getName() in targets:
            r = d.decompileFunction(f, 120, mon)
            if r and r.decompileCompleted():
                with open(os.path.join(outdir, f.getName() + ".c"), "w") as fh:
                    fh.write("// " + str(f.getEntryPoint()) + " " + f.getName() + "\n")
                    fh.write(r.getDecompiledFunction().getC())
                w += 1
                print("GHWROTE", f.getName())
    print("DECOMP_DONE wrote", w)
