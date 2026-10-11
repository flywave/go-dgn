import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Symbol;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ShowVtableAt extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: ShowVtableAt.java <comma-hex-addrs> <out.txt>");
            return;
        }
        PrintWriter w = new PrintWriter(new FileWriter(args[1]));
        for (String a : args[0].split(",")) {
            a = a.trim();
            if (a.isEmpty()) {
                continue;
            }
            Address va = currentProgram.getAddressFactory()
                .getDefaultAddressSpace().getAddress(Long.decode("0x" + a).longValue());
            w.println("== vtable @ " + va);
            Memory mem = currentProgram.getMemory();
            for (int i = 0; i < 256; i++) {
                Address slot = va.add(i * 8);
                if (!mem.contains(slot)) {
                    break;
                }
                long v = mem.getLong(slot);
                Address target;
                try {
                    target = currentProgram.getAddressFactory().getDefaultAddressSpace()
                        .getAddress(v);
                } catch (Exception e) {
                    w.println("  [" + i + "] " + Long.toHexString(v));
                    break;
                }
                Function f = getFunctionAt(target);
                String nm = f != null ? f.getName() : "";
                Symbol[] syms = currentProgram.getSymbolTable().getSymbols(target);
                if (nm.isEmpty() && syms.length > 0) {
                    nm = syms[0].getName();
                }
                w.println("  [" + i + "] " + Long.toHexString(v) + "  " + nm);
            }
        }
        w.close();
        println("ShowVtableAt done");
    }
}
