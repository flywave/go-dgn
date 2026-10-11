import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DumpDgnClassMap extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) {
            println("usage: DumpDgnClassMap.java <out.tsv>");
            return;
        }
        PrintWriter w = new PrintWriter(new FileWriter(args[0]));
        Memory mem = currentProgram.getMemory();
        Address base = addr("181020c38");
        if (!mem.contains(base)) {
            w.println("ERR global not mapped");
            w.close();
            return;
        }
        long mapPtr = mem.getLong(base);
        w.println("OdDgnClassMap @ " + Long.toHexString(mapPtr));
        if (mapPtr == 0) {
            w.close();
            return;
        }
        long dense = mem.getLong(addr(Long.toHexString(mapPtr)));
        w.println("dense @ " + Long.toHexString(dense));
        if (dense == 0) {
            w.close();
            return;
        }
        Address denseA = addr(Long.toHexString(dense));
        int len = mem.getInt(denseA.subtract(4));
        w.println("denseLen=" + len);
        for (int type = 0; type < len && type < 200; type++) {
            Address row = denseA.add(type * 0x10L);
            if (!mem.contains(row) || !mem.contains(row.add(8))) {
                break;
            }
            int count = mem.getByte(row) & 0xff;
            long varr = mem.getLong(row.add(8));
            if (count == 0 || varr == 0) {
                continue;
            }
            for (int v = 0; v < count && v < 64; v++) {
                Address vp = addr(Long.toHexString(varr)).add(v * 8L);
                if (!mem.contains(vp)) {
                    break;
                }
                long rx = mem.getLong(vp);
                if (rx == 0) {
                    continue;
                }
                w.println(type + "\t" + v + "\t" + resolveName(rx));
            }
        }
        w.close();
        println("DumpDgnClassMap done");
    }

    private Address addr(String hex) {
        return currentProgram.getAddressFactory().getDefaultAddressSpace()
            .getAddress(Long.decode("0x" + hex).longValue());
    }

    private String resolveName(long obj) {
        Memory mem = currentProgram.getMemory();
        for (int off = 8; off <= 0x40; off += 8) {
            try {
                Address p = addr(Long.toHexString(mem.getLong(addr(Long.toHexString(obj + off)))));
                if (!mem.contains(p)) {
                    continue;
                }
                byte[] raw = new byte[96];
                mem.getBytes(p, raw);
                String s = decode(raw);
                if (s != null && s.matches("[A-Za-z_][A-Za-z0-9_:]{2,79}")) {
                    return s;
                }
            } catch (Exception e) {
                // try next offset
            }
        }
        return "obj_" + Long.toHexString(obj);
    }

    private String decode(byte[] raw) {
        boolean utf16 = raw.length > 3 && raw[1] == 0 && raw[0] != 0;
        StringBuilder sb = new StringBuilder();
        if (utf16) {
            for (int i = 0; i + 1 < raw.length; i += 2) {
                if (raw[i] == 0 && raw[i + 1] == 0) {
                    break;
                }
                if (raw[i + 1] != 0 || raw[i] < 32) {
                    return null;
                }
                sb.append((char) raw[i]);
            }
        } else {
            for (byte b : raw) {
                if (b == 0) {
                    break;
                }
                if (b < 32 || b > 126) {
                    return null;
                }
                sb.append((char) b);
            }
        }
        return sb.toString();
    }
}
