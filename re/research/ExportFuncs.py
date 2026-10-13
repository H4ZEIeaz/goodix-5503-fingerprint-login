# Ghidra headless post-script: decompile exported functions of interest.
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

outdir = "./decomp"
try:
    os.makedirs(outdir)
except Exception:
    pass

targets = set("""enrolStart enrolStartEx enrolAddImage enrolFinish enrolGetTemplate
enrolDeleteImage identifyImage identifytemplate identifyUpdate getQuality
getAlgorithmVersion preprocessor preprocessor_init ppp_param_init templateStudy
templatePack templateUnPack templateGetPackedSize templateDelete GetTptOverlapRate
gx_sensorCheck preprocess_init_calidata preprocess_get_calidata_len
preprocess_set_mode WbioQueryEngineInterface""".split())

decomp = DecompInterface()
decomp.openProgram(currentProgram)
fm = currentProgram.getFunctionManager()
mon = ConsoleTaskMonitor()
written = 0
for f in fm.getFunctions(True):
    name = f.getName()
    if name in targets:
        res = decomp.decompileFunction(f, 90, mon)
        if res and res.decompileCompleted():
            with open(os.path.join(outdir, name + ".c"), "w") as fh:
                fh.write("// " + str(f.getEntryPoint()) + " " + name + "\n")
                fh.write(res.getDecompiledFunction().getC())
            written += 1
            print("GHWROTE " + name)
print("DECOMP_DONE wrote %d" % written)
