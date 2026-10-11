package dgn

import (
	"encoding/binary"
	"fmt"
)

const HeaderSize = 36

const (
	FlagDisplayHeader uint16 = 1 << 12
	FlagComplex       uint16 = 1 << 13
	FlagExtra4        uint16 = 1 << 14
)

// Header is the 36-byte v8 element header. Field semantics:
// A u32@0 [?]; Type u16@4; Flag u16@6 (bit10=nonModel, bit11=locked,
// bit12=display, bit13=complex, bit14=extra4 — GetNonModel/GetLocked D66);
// B u32@8 = total word count (element size = B*2+4; D32/D65);
// C u32@12 = words before the attribute/linkage region (attrib=(B−C)*2;
// body ends at C*2+4; D65); Sub u32@16 = level entry id (D64);
// ID u64@20 = element unique id (SetElementUniqueID +0x20);
// Tail@28 = f64 timestamp (OdTimeStamp packedValue×1000 — read via
// rdDouble; CDGElmHeader ctor default = same formula; D66).
type Header struct {
	A    uint32
	Type uint16
	Flag uint16
	B    uint32
	C    uint32
	Sub  uint32
	ID   uint64
	Tail uint64
}

func (h Header) IsComplex() bool        { return h.Flag&FlagComplex != 0 }
func (h Header) HasDisplayHeader() bool { return h.Flag&FlagDisplayHeader != 0 }
func (h Header) HasExtra4() bool        { return h.Flag&FlagExtra4 != 0 }
func (h Header) IsLocked() bool         { return h.Flag&(1<<11) != 0 }
func (h Header) IsNonModel() bool       { return h.Flag&(1<<10) != 0 }

func ParseHeader(b []byte) (Header, error) {
	var h Header
	if len(b) < HeaderSize {
		return h, fmt.Errorf("dgn: element header needs %d bytes, got %d", HeaderSize, len(b))
	}
	h.A = binary.LittleEndian.Uint32(b[0:])
	h.Type = binary.LittleEndian.Uint16(b[4:])
	h.Flag = binary.LittleEndian.Uint16(b[6:])
	h.B = binary.LittleEndian.Uint32(b[8:])
	h.C = binary.LittleEndian.Uint32(b[12:])
	h.Sub = binary.LittleEndian.Uint32(b[16:])
	h.ID = binary.LittleEndian.Uint64(b[20:])
	h.Tail = binary.LittleEndian.Uint64(b[28:])
	return h, nil
}

const DisplayHeaderSize = 72

// DisplayHeader is the 72-byte display header. Field semantics from the
// CDGDispHeader getter chain (D64, evidence TG_Db.disphdr.c):
type DisplayHeader struct {
	GraphicsGroup uint32   // @0   GetGraphicsGroup (default 0; absent → 0xFFFFFFFF)
	Priority      int32    // @4   getPriority
	Properties    uint16   // @8   GetProperties/flags (see accessors)
	Unknown10     uint16   // @10  [?]
	LineStyle     int32    // @12  GetLineStyle (default 0; absent → 0x7FFFFFFF)
	LineWeight    uint32   // @16  GetLineWeight (default 1)
	Color         uint32   // @20  GetColor (default 0; absent → 0xFFFFFFFF)
	Range         [6]int64 // @24 min.xyz + extent.xyz (FUN_1808bd8b0: bb.max = min+extent)
}

// Properties word (@8) bit layout, per CDGDispHeader getters:
// bits0-3 class; bit7 invisible; bit11 3D format; bit12 view independent;
// bit13 non-planar; bit14 not snappable; bit15 HBIT.
func (d DisplayHeader) Class() byte             { return byte(d.Properties & 0x0f) }
func (d DisplayHeader) IsInvisible() bool       { return d.Properties&(1<<7) != 0 }
func (d DisplayHeader) Is3DFormat() bool        { return d.Properties&(1<<11) != 0 }
func (d DisplayHeader) IsViewIndependent() bool { return d.Properties&(1<<12) != 0 }
func (d DisplayHeader) IsNonPlanar() bool       { return d.Properties&(1<<13) != 0 }
func (d DisplayHeader) IsNotSnappable() bool    { return d.Properties&(1<<14) != 0 }
func (d DisplayHeader) IsHbit() bool            { return d.Properties&(1<<15) != 0 }

func ParseDisplayHeader(b []byte) (DisplayHeader, error) {
	var d DisplayHeader
	if len(b) < DisplayHeaderSize {
		return d, fmt.Errorf("dgn: display header needs %d bytes, got %d", DisplayHeaderSize, len(b))
	}
	d.GraphicsGroup = binary.LittleEndian.Uint32(b[0:])
	d.Priority = int32(binary.LittleEndian.Uint32(b[4:]))
	d.Properties = binary.LittleEndian.Uint16(b[8:])
	d.Unknown10 = binary.LittleEndian.Uint16(b[10:])
	d.LineStyle = int32(binary.LittleEndian.Uint32(b[12:]))
	d.LineWeight = binary.LittleEndian.Uint32(b[16:])
	d.Color = binary.LittleEndian.Uint32(b[20:])
	for i := range d.Range {
		d.Range[i] = int64(binary.LittleEndian.Uint64(b[24+8*i:]))
	}
	return d, nil
}

func IsImplicitDisplayHeader(typ uint16, sizeField uint32) bool {
	if typ != 35 {
		return false
	}
	return sizeField > 0xbc+0x47
}
