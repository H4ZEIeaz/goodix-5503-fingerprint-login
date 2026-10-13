import os
os.environ["GHIDRA_INSTALL_DIR"] = "/opt/ghidra"
import pyghidra
pyghidra.start()
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
from ghidra.program.util import DefinedDataIterator

outdir = "./decomp"
dll = "../GoodixEngineAdapter.dll"

want_addr = ["1800aee90", "180097d90", "180095d00"]
want_name = ["preprocess_load_calidata", "preprocessor_get_CalibParam",
             "preprocess_save_calidata"]

with pyghidra.open_program(dll, project_location="./proj",
                           project_name="gp", analyze=False) as api:
    prog = api.getCurrentProgram()
    d = DecompInterface(); d.openProgram(prog); mon = ConsoleTaskMonitor()
    fm = prog.getFunctionManager()
    sp = prog.getAddressFactory().getDefaultAddressSpace()

    def dump(fn, tag):
        r = d.decompileFunction(fn, 120, mon)
        if r and r.decompileCompleted():
            with open(os.path.join(outdir, tag + ".c"), "w") as fh:
                fh.write("// " + str(fn.getEntryPoint()) + " " + fn.getName() + "\n")
                fh.write(r.getDecompiledFunction().getC())
            print("WROTE", tag, fn.getName())
        else:
            print("FAIL", tag)

    for a in want_addr:
        fn = fm.getFunctionAt(sp.getAddress(a))
        if fn:
            dump(fn, "_" + a)
    for n in want_name:
        for fn in fm.getFunctions(True):
            if fn.getName() == n:
                dump(fn, n); break

    # find function referencing the "croped_circle" string
    for data in DefinedDataIterator.definedStrings(prog):
        v = data.getValue()
        s = str(v) if v else ""
        if "croped_circle" in s:
            print("CROPSTR@", data.getAddress(), repr(s[:60]))
            for ref in prog.getReferenceManager().getReferencesTo(data.getAddress()):
                fn = fm.getFunctionContaining(ref.getFromAddress())
                if fn:
                    dump(fn, "_cropfn_" + str(fn.getEntryPoint()))
    print("DONE2")
