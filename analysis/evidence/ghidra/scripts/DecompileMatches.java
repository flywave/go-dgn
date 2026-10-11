import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.regex.Pattern;

public class DecompileMatches extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: DecompileMatches.java <name-regex> <out.c>");
            return;
        }
        Pattern p = Pattern.compile(args[0]);
        PrintWriter w = new PrintWriter(new FileWriter(args[1]));
        DecompInterface di = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        di.setOptions(opts);
        di.openProgram(currentProgram);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int hit = 0;
        while (it.hasNext()) {
            Function f = it.next();
            boolean hitName = p.matcher(f.getName()).find();
            boolean hitAddr = p.matcher(f.getEntryPoint().toString()).find();
            if (!hitName && !hitAddr) {
                continue;
            }
            DecompileResults r = di.decompileFunction(f, 60, monitor);
            w.println("/* ==== " + f.getEntryPoint() + " " + f.getName() + " ==== */");
            if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
                w.println(r.getDecompiledFunction().getC());
            } else {
                w.println("/* decompile failed: " + (r == null ? "null" : r.getErrorMessage()) + " */");
            }
            w.println();
            hit++;
            if (monitor.isCancelled()) {
                break;
            }
        }
        di.dispose();
        w.close();
        println("DecompileMatches: wrote " + hit + " functions to " + args[1]);
    }
}
