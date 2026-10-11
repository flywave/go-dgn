import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DumpXrefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: DumpXrefs.java <hex-addr> <out.txt>");
            return;
        }
        Address target = currentProgram.getAddressFactory()
            .getDefaultAddressSpace().getAddress(Long.decode("0x" + args[0]).longValue());
        PrintWriter w = new PrintWriter(new FileWriter(args[1]));
        Function tf = getFunctionAt(target);
        w.println("target " + target + "  func=" + (tf == null ? "none" : tf.getName()));
        // incoming
        ReferenceIterator it = currentProgram.getReferenceManager()
            .getReferencesTo(target);
        int n = 0;
        while (it.hasNext() && n < 400) {
            Reference r = it.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            w.println("FROM " + from + "  in " + (f == null ? "?" : f.getName())
                + "  type=" + r.getReferenceType());
            n++;
        }
        w.println("incoming=" + n);
        // outgoing from target function
        if (tf != null) {
            int m = 0;
            Reference[] out = currentProgram.getReferenceManager()
                .getReferencesFrom(tf.getEntryPoint());
            for (Reference r : out) {
                if (m >= 400) {
                    break;
                }
                Address to = r.getToAddress();
                Function f = getFunctionAt(to);
                w.println("TO   " + to + "  " + (f == null ? "data" : f.getName()));
                m++;
            }
            w.println("outgoing=" + m);
        }
        w.close();
        println("DumpXrefs done");
    }
}
