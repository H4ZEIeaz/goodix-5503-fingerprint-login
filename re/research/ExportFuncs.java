//@category Goodix
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.util.task.ConsoleTaskMonitor;
import java.io.*;
import java.util.*;

public class ExportFuncs extends GhidraScript {
    public void run() throws Exception {
        String outdir = "./decomp";
        new File(outdir).mkdirs();
        Set<String> targets = new HashSet<>(Arrays.asList(
            "enrolStart","enrolStartEx","enrolAddImage","enrolFinish",
            "enrolGetTemplate","enrolDeleteImage","identifyImage",
            "identifytemplate","identifyUpdate","getQuality",
            "getAlgorithmVersion","preprocessor","preprocessor_init",
            "ppp_param_init","templateStudy","templatePack","templateUnPack",
            "templateGetPackedSize","templateDelete","GetTptOverlapRate",
            "gx_sensorCheck","preprocess_init_calidata",
            "preprocess_get_calidata_len","preprocess_set_mode"));
        DecompInterface d = new DecompInterface();
        d.openProgram(currentProgram);
        FunctionManager fm = currentProgram.getFunctionManager();
        ConsoleTaskMonitor mon = new ConsoleTaskMonitor();
        int w = 0;
        for (Function f : fm.getFunctions(true)) {
            if (targets.contains(f.getName())) {
                DecompileResults r = d.decompileFunction(f, 120, mon);
                if (r != null && r.decompileCompleted()) {
                    PrintWriter pw = new PrintWriter(outdir + "/" + f.getName() + ".c");
                    pw.println("// " + f.getEntryPoint() + " " + f.getName());
                    pw.print(r.getDecompiledFunction().getC());
                    pw.close();
                    w++;
                    println("GHWROTE " + f.getName());
                }
            }
        }
        println("DECOMP_DONE wrote " + w);
    }
}
