import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolType;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class FindVtablesByRtti extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: FindVtablesByRtti.java <Class1,Class2,...> <out.txt>");
            return;
        }
        PrintWriter w = new PrintWriter(new FileWriter(args[1]));
        SymbolTableIter st = new SymbolTableIter();
        long codeLo = 0x180001000L, codeHi = 0x180052000L;
        for (String part : args[0].split(",")) {
            part = part.trim();
            String cls;
            Address td = null;
            int eq = part.indexOf('=');
            if (eq > 0) {
                cls = part.substring(0, eq);
                td = currentProgram.getAddressFactory().getDefaultAddressSpace()
                    .getAddress(Long.decode(part.substring(eq + 1)).longValue());
            } else {
                cls = part;
                String needle = "?AV" + cls + "@@";
                SymbolIterator it = currentProgram.getSymbolTable().getAllSymbols(true);
                while (it.hasNext()) {
                    Symbol s = it.next();
                    if (s.getName().contains(needle)) {
                        td = s.getAddress();
                        break;
                    }
                }
            }
            w.println("== " + cls + "  TD=" + td);
            if (td == null) {
                continue;
            }
            List<Address> tdRefs = new ArrayList<>(refsTo(td));
            tdRefs.addAll(refsTo(td.add(16)));
            w.println("  tdRefs=" + tdRefs.size());
            for (Address from : tdRefs) {
                long fv = from.getOffset();
                if (fv >= codeLo && fv < codeHi) {
                    w.println("  code-ref from " + from + " (dynamic_cast)");
                    continue;
                }
                List<Address> colRefs = refsTo(from);
                w.println("  colptr@" + from + " refs=" + colRefs.size());
                if (colRefs.isEmpty()) {
                    Address vt = from.add(8);
                    w.println("  candidate vtable @" + vt + " (ptr at " + from + ")");
                    dumpSlots(w, vt);
                } else {
                    for (Address loc : colRefs) {
                        Address vt = loc.add(8);
                        w.println("  candidate vtable @" + vt + " (ptr at " + loc + ")");
                        dumpSlots(w, vt);
                    }
                }
            }
        }
        w.close();
        println("FindVtablesByRtti done");
    }

    private List<Address> refsTo(Address target) {
        List<Address> out = new ArrayList<>();
        ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(target);
        while (it.hasNext()) {
            Reference r = it.next();
            if (r.getReferenceType().isData()) {
                out.add(r.getFromAddress());
            }
        }
        return out;
    }

    private void dumpSlots(PrintWriter w, Address va) throws Exception {
        Memory mem = currentProgram.getMemory();
        if (!mem.contains(va)) {
            w.println("    (unmapped)");
            return;
        }
        for (int i = 0; i < 96; i++) {
            Address slot = va.add(i * 8);
            if (!mem.contains(slot)) {
                break;
            }
            long v = mem.getLong(slot);
            Address tgt;
            try {
                tgt = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(v);
            } catch (Exception e) {
                w.println("    [" + i + "] " + Long.toHexString(v) + " (unmapped)");
                break;
            }
            Function f = getFunctionAt(tgt);
            String nm = f != null ? f.getName() : "";
            w.println("    [" + i + "] " + Long.toHexString(v) + "  " + nm);
        }
    }

    private static class SymbolTableIter {
    }
}
