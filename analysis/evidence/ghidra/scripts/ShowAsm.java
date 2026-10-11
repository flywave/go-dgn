import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ShowAsm extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            println("usage: ShowAsm.java <comma-hex-addrs> <out.txt>");
            return;
        }
        PrintWriter w = new PrintWriter(new FileWriter(args[1]));
        for (String a : args[0].split(",")) {
            Address start = currentProgram.getAddressFactory()
                .getDefaultAddressSpace().getAddress(Long.decode("0x" + a.trim()).longValue());
            Function f = getFunctionContaining(start);
            w.println("== " + start + "  func=" + (f == null ? "?" : f.getName())
                + "  body=" + (f == null ? "?" : f.getBody()));
            if (f == null) {
                continue;
            }
            InstructionIterator it = currentProgram.getListing()
                .getInstructions(f.getBody(), true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                w.println("  " + ins.getAddress() + "  " + ins);
            }
        }
        w.close();
        println("ShowAsm done");
    }
}
