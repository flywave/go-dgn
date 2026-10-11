import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ExportFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("usage: ExportFunctions.java <out.tsv>");
            return;
        }
        PrintWriter w = new PrintWriter(new FileWriter(args[0]));
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int n = 0;
        while (it.hasNext()) {
            Function f = it.next();
            String proto;
            try {
                proto = f.getSignature().getPrototypeString();
            } catch (Exception e) {
                proto = "";
            }
            w.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + proto);
            n++;
        }
        w.close();
        println("ExportFunctions: wrote " + n + " functions to " + args[0]);
    }
}
