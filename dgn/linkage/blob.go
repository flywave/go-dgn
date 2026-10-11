package linkage

import "encoding/binary"

const (
	flagUserData uint16 = 1 << 12
	flagRemote   uint16 = 1 << 14
)

type Mode uint8

const (
	ModeA Mode = iota
	ModeB
	ModeC
)

type Rec struct {
	TypeID uint16
	Mode   Mode
	Raw    []byte
}

func Iter(b []byte) []Rec {
	var out []Rec
	for off := 0; off+4 <= len(b); {
		h := binary.LittleEndian.Uint16(b[off:])
		count := uint32(h & 0xff)
		nibble := uint32(h>>8) & 0xf
		userData := h&flagUserData != 0
		remote := h&flagRemote != 0

		var n int
		var m Mode
		switch {
		case !userData:
			m, n = ModeA, 8
		case !remote:
			m, n = ModeB, int(count)*2+2
		default:
			m, n = ModeC, int(2<<nibble)*int(count)
		}
		if n == 0 {
			n = len(b) - off
		}
		if n < 0 || off+n > len(b) {
			return out
		}
		var typeID uint16
		if userData {
			typeID = binary.LittleEndian.Uint16(b[off+2:])
		}
		out = append(out, Rec{TypeID: typeID, Mode: m, Raw: b[off : off+n]})
		off += n
	}
	return out
}
