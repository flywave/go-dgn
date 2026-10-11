import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import java.io.FileWriter;
import java.io.PrintWriter;

public class FindCallsWithOffset extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: FindCallsWithOffset.java <+0xNNN> <out.txt>");
            return;
        }
        String needle = args[0];
        PrintWriter w = new PrintWriter(new FileWriter(args[1]));
        InstructionIterator it = currentProgram.getListing().getInstructions(true);
        int hits = 0;
        while (it.hasNext()) {
            Instruction ins = it.next();
            if (!ins.getMnemonicString().equalsIgnoreCase("CALL")) {
                continue;
            }
            String s = ins.toString();
            if (s.contains(needle)) {
                ghidra.program.model.listing.Function f =
                    getFunctionContaining(ins.getAddress());
                w.println(ins.getAddress() + "  in " + (f == null ? "?" : f.getName())
                    + "  ::  " + s);
                hits++;
                if (hits >= 600) {
                    break;
                }
            }
        }
        w.println("hits=" + hits);
        w.close();
        println("FindCallsWithOffset: " + hits);
    }
}
