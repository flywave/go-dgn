package linkage

import (
	"encoding/binary"
	"fmt"
)

// Brep is kIdBrep(0x522E), the OdDgBrepLinkage (D111): a SmartSolid/
// SmartSurface/FeatureSolid's kernel BRep carried by a type-2
// CellHeader3d (DgBRepEntityPE.h — eSmartSolid/eSmartSurface/
// eFeatureSolid; data = parasolid or ACIS native binary). Layout is
// read/write double-proven against CDGAttribEmbeddedBRep::read/write
// over the handler-visible record buffer — the 4-byte attribute-linkage
// envelope ([u16 bits][u16 id]) IS the leading u32 (getRawDataSize()=4:
// write() steps +4/+2/+2/+8; minimum = 4+0xC = 16):
//
//	[u16 bits][u16 id][u16 flag1][u16 flag2][f64 scale][native BRep bytes]
//
// Header is that first u32 (bits|id<<16), stored verbatim as the linkage
// header value. No Go/OCCT kernel consumes parasolid/ACIS, so Data stays
// raw; consumers surface these entities as metadata-bearing solids.
type Brep struct {
	Header uint32
	Flag1  uint16
	Flag2  uint16
	Scale  float64
	Data   []byte
}

// decodeBrep parses the 0x522E handler buffer (minimum 16 bytes: envelope
// + flags + scale before any BRep data).
func decodeBrep(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 16 {
		return nil, fmt.Errorf("linkage: brep payload too short (%d, need 16)", len(raw))
	}
	b := &Brep{
		Header: hdr,
		Flag1:  binary.LittleEndian.Uint16(raw[4:]),
		Flag2:  binary.LittleEndian.Uint16(raw[6:]),
		Scale:  f64d(raw[8:]),
	}
	b.Data = append([]byte(nil), raw[16:]...)
	return b, nil
}
