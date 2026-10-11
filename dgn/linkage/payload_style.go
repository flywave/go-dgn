package linkage

import (
	"encoding/binary"
	"fmt"
)

// Style linkage payload decoders (U10b, D88-D90): fill-style family,
// bit mask, line-style modification, dim text style and material.

// FillStyle is kFillStyle(0x41), the family dispatcher FUN_1808bef50:
// u32 header + u16 subType selects one of several fill-related linkages.
type FillStyle struct {
	Header  uint32
	SubType uint16
	Kind    FillKind
	Color   uint32 // FillColor
	Index   uint32 // InternalMaterial: subType-0xc
	ID      uint64 // InternalMaterial id
}

// FillKind enumerates the kFillStyle sub-variants (D88).
type FillKind uint8

const (
	FillUnknown          FillKind = iota
	FillDisplayStyle              // subType 0x10
	FillGradient                  // subType 8, inner == 1
	FillColorVal                  // subType 8, inner != 1
	FillInternalMaterial          // subType 0xc..0xe
	FillTransparency              // subType 9
)

func decodeFillStyle(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 6 {
		return nil, fmt.Errorf("linkage: fill style too short (%d)", len(raw))
	}
	sub := binary.LittleEndian.Uint16(raw[4:])
	f := &FillStyle{Header: hdr, SubType: sub}
	switch {
	case sub == 0x10:
		f.Kind = FillDisplayStyle
	case sub == 8:
		if len(raw) < 8 {
			return nil, fmt.Errorf("linkage: fill style subtype 8 too short (%d)", len(raw))
		}
		inner := binary.LittleEndian.Uint16(raw[6:])
		if inner == 1 {
			f.Kind = FillGradient
		} else {
			f.Kind = FillColorVal
			if len(raw) >= 12 {
				f.Color = binary.LittleEndian.Uint32(raw[8:])
			}
		}
	case sub >= 0xc && sub <= 0xe:
		f.Kind = FillInternalMaterial
		f.Index = uint32(sub - 0xc)
		if len(raw) >= 16 {
			f.ID = binary.LittleEndian.Uint64(raw[8:])
		}
	case sub == 9:
		f.Kind = FillTransparency
		if len(raw) >= 12 {
			f.Color = binary.LittleEndian.Uint32(raw[8:])
		}
	default:
		return nil, nil // handler returns null linkage
	}
	return f, nil
}

// BitMask is kBitMask(0x56D3), handler FUN_1808accc0: payload[4]==6 selects
// OdDgTextWhiteSpaceLinkage instead of OdDgBitMaskLinkage; both then parse
// via the class reader (D89).
type BitMask struct {
	IsWhiteSpace bool
	Rest         []byte
}

func decodeBitMask(raw []byte) (any, error) {
	if len(raw) < 5 {
		return nil, fmt.Errorf("linkage: bitmask too short (%d)", len(raw))
	}
	b := &BitMask{IsWhiteSpace: raw[4] == 6}
	if len(raw) > 5 {
		b.Rest = append([]byte(nil), raw[5:]...)
	}
	return b, nil
}

// LineStyleModification is kLStyleMod(0x79F9), reader FUN_1808c1fb0:
// u32 header, u32 flags, then one f64 per set bit 0..6 (degenerate→0);
// when flags&0x1800==0x1800 a u32 count + count×u32 dash array follows.
type LineStyleModification struct {
	Header, Flags uint32
	D             []float64
	Dashes        []uint32
}

func decodeLineStyleMod(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	flags, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	l := &LineStyleModification{Header: hdr, Flags: flags}
	off := 8
	for bit := 0; bit <= 6; bit++ {
		if flags&(1<<uint(bit)) == 0 {
			continue
		}
		if off+8 > len(raw) {
			return l, fmt.Errorf("linkage: lstylemod truncated at %d", off)
		}
		l.D = append(l.D, f64d(raw[off:]))
		off += 8
	}
	if flags&0x1800 == 0x1800 {
		n, err := le32(raw, off)
		if err != nil {
			return l, nil
		}
		off += 4
		for i := uint32(0); i < n; i++ {
			if off+4 > len(raw) {
				return l, fmt.Errorf("linkage: lstylemod dashes truncated at %d", off)
			}
			l.Dashes = append(l.Dashes, binary.LittleEndian.Uint32(raw[off:]))
			off += 4
		}
	}
	return l, nil
}

// DimTextStyle is kDimTextStyle(0x5801), reader FUN_180833880 prefix:
// u32 header, u32 x, u32 flags, u32 y; flags then gate a long bitmask of
// optional fields (u32/u16/f64) — prefix verified, optional stream left
// raw (D90).
type DimTextStyle struct {
	Header, X, Flags, Y uint32
	Rest                []byte
}

func decodeDimTextStyle(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 16 {
		return nil, fmt.Errorf("linkage: dim text style too short (%d)", len(raw))
	}
	d := &DimTextStyle{
		Header: hdr,
		X:      binary.LittleEndian.Uint32(raw[4:]),
		Flags:  binary.LittleEndian.Uint32(raw[8:]),
		Y:      binary.LittleEndian.Uint32(raw[12:]),
	}
	if len(raw) > 16 {
		d.Rest = append([]byte(nil), raw[16:]...)
	}
	return d, nil
}

// Material is kExternalMaterial(0x4F5A), reader FUN_1808c12d0 — branchy
// u16/u32 stream; prefix u32 header + Rest raw (D90).
type Material struct {
	Header uint32
	Rest   []byte
}

func decodeMaterial(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	m := &Material{Header: hdr}
	if len(raw) > 4 {
		m.Rest = append([]byte(nil), raw[4:]...)
	}
	return m, nil
}
