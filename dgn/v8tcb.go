package dgn

import (
	"encoding/binary"
	"math"
)

// DesignFileHeader is the OdDgDesignFileHeaderData body (0x63C bytes). It
// lives in the Dgn~H stream — NOT in the type-9 element, which is a
// separate v7-compat TCB container: the stream stores the first 20 bytes
// of the body verbatim (WordA=1/WordB=4 from initialize) and the remaining
// 1576 bytes as its zlib payload. Field offsets from the REA
// read/write/initialize cross-check (D103); the impl struct has a 4-byte
// alignment hole at +0x13C, so u64 fields sit 4 bytes lower on file than
// in the struct.
type DesignFileHeader struct {
	Raw []byte

	WordA uint16 // @0x000 initialize default 1
	WordB uint16 // @0x002 default 4

	DefaultModelIs3D uint32 // @0x124
	Version          uint32 // @0x128 default 8
	SubVersion       uint32 // @0x12C default 0x68
	Format           uint32 // @0x130 default 2

	HighestModelID   uint32  // @0x134 default 0xFFFFFFFF
	DefaultModelID   uint32  // @0x138
	HighestUniqueID  uint64  // @0x13C (struct 0x140 − 4 hole)
	LastSaveTimeMS   float64 // @0x144 (struct 0x148; NaN/Inf → 0)
	NextGraphicGroup uint32  // @0x14C
	NextTextNode     uint32  // @0x150 default 1

	OriginalFormat                 uint32 // @0x328 default 2
	ModelSpecificDigitalSignatures uint32 // @0x32C
	FileWideDigitalSignatures      uint32 // @0x330
	PrimaryApplicationID           uint32 // @0x334
}

func (h *DesignFileHeader) ElementType() uint16 { return 9 }

// ParseDesignFileHeader decodes the typed fields from the reassembled
// Dgn~H body (prefix + inflated payload); the full body stays in Raw (the
// trailing u32 arrays are undecoded — D103 residuals).
func ParseDesignFileHeader(body []byte) *DesignFileHeader {
	raw := body
	h := &DesignFileHeader{Raw: raw}
	if len(raw) >= 4 {
		h.WordA = binary.LittleEndian.Uint16(raw[0:])
		h.WordB = binary.LittleEndian.Uint16(raw[2:])
	}
	u32 := func(off int) uint32 {
		if off+4 > len(raw) {
			return 0
		}
		return binary.LittleEndian.Uint32(raw[off:])
	}
	u64 := func(off int) uint64 {
		if off+8 > len(raw) {
			return 0
		}
		return binary.LittleEndian.Uint64(raw[off:])
	}
	h.DefaultModelIs3D = u32(0x124)
	h.Version = u32(0x128)
	h.SubVersion = u32(0x12C)
	h.Format = u32(0x130)
	h.HighestModelID = u32(0x134)
	h.DefaultModelID = u32(0x138)
	h.HighestUniqueID = u64(0x13C)
	if v := math.Float64frombits(u64(0x144)); !math.IsNaN(v) && !math.IsInf(v, 0) {
		h.LastSaveTimeMS = v
	}
	h.NextGraphicGroup = u32(0x14C)
	h.NextTextNode = u32(0x150)
	h.OriginalFormat = u32(0x328)
	h.ModelSpecificDigitalSignatures = u32(0x32C)
	h.FileWideDigitalSignatures = u32(0x330)
	h.PrimaryApplicationID = u32(0x334)
	return h
}
