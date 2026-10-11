import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SymbolType;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.regex.Pattern;

public class DumpVtables extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: DumpVtables.java <name-regex> <out.txt>");
            return;
        }
        Pattern p = Pattern.compile(args[0]);
        PrintWriter w = new PrintWriter(new FileWriter(args[1]));
        SymbolTable st = currentProgram.getSymbolTable();
        Memory mem = currentProgram.getMemory();
        SymbolIterator it = st.getAllSymbols(true);
        int dumped = 0;
        while (it.hasNext()) {
            Symbol s = it.next();
            if (s.getSymbolType() != SymbolType.LABEL) {
                continue;
            }
            String name = s.getName(true);
            if (!p.matcher(name).find()) {
                continue;
            }
            Address a = s.getAddress();
            if (!mem.contains(a)) {
                continue;
            }
            w.println("== " + name + " @ " + a);
            dumped++;
            for (int i = 0; i < 256; i++) {
                Address slot = a.add(i * 8);
                if (!mem.contains(slot)) {
                    break;
                }
                long v = mem.getLong(slot);
                Address va;
                try {
                    va = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(v);
                } catch (Exception e) {
                    break;
                }
                Function f = getFunctionAt(va);
                String fn;
                if (f != null) {
                    fn = f.getName();
                } else {
                    Symbol[] ss = st.getSymbols(va);
                    fn = ss.length > 0 ? ss[0].getName() : ("data_" + Long.toHexString(v));
                    if (fn.startsWith("DAT_") || fn.startsWith("FUN_")) {
                        Function cf = getFunctionContaining(va);
                        fn = cf != null ? (cf.getName() + "(containing)") : fn;
                    }
                }
                w.println("  [" + i + "] " + Long.toHexString(v) + "  " + fn);
                if (i > 0 && (fn.equals("data_" + Long.toHexString(v)) || fn.startsWith("DAT_"))) {
                    break;
                }
            }
        }
        w.close();
        println("DumpVtables: dumped " + dumped + " symbols");
    }
}
