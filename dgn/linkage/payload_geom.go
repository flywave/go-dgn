package linkage

import (
	"encoding/binary"
	"fmt"
)

// Geometry/dependency linkage payload decoders (U10b, D88/D89): seed
// points, thickness, infinite line, assoc region and dependency.

// SeedPoints is kSeedPoints(0x56DA), handler FUN_18082a140:
// u32 header, u32 count, count×Point3d (3×f64, degenerate→0; a truncated
// stream yields the origin triple).
type SeedPoints struct {
	Header uint32
	Count  uint32
	Points [][3]float64
}

func decodeSeedPoints(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	count, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	p := &SeedPoints{Header: hdr, Count: count}
	for i := uint32(0); i < count; i++ {
		o := 8 + int(i)*24
		if o+24 > len(raw) {
			break // handler keeps origin on short stream
		}
		p.Points = append(p.Points, [3]float64{
			f64d(raw[o:]), f64d(raw[o+8:]), f64d(raw[o+16:]),
		})
	}
	return p, nil
}

// Thickness is kThickness(0x56D4), handler FUN_1808bfd80:
// u32 header, u32 skipped, then either one f64 (scalar, record < 0x20) or
// three f64 (vector; thickness=|v|, direction=v̂).
type Thickness struct {
	Header  uint32
	Vector  [3]float64 // scalar form stores (v,0,0)
	IsVec   bool
	HasData bool
}

func decodeThickness(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if _, err := le32(raw, 4); err != nil {
		return nil, err
	}
	t := &Thickness{Header: hdr}
	if len(raw) < 0x20 {
		if len(raw) >= 16 {
			t.Vector[0] = f64d(raw[8:])
			t.HasData = true
		}
	} else {
		t.IsVec = true
		t.Vector = [3]float64{f64d(raw[8:]), f64d(raw[16:]), f64d(raw[24:])}
		t.HasData = true
	}
	return t, nil
}

// InfiniteLine is kInfiniteLine(0x56E9), handler FUN_1808ce340:
// u32 header, u32 value.
type InfiniteLine struct {
	Header, Value uint32
}

func decodeInfiniteLine(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	v, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	return &InfiniteLine{Header: hdr, Value: v}, nil
}

// AssocRegion is kAssocRegion(0x56D8), handler FUN_180829f90:
// u32 header, u32 value, then (if size > 8) one f64 (degenerate→0).
type AssocRegion struct {
	Header, Value uint32
	HasDouble     bool
	Double        float64
}

func decodeAssocRegion(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	v, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	a := &AssocRegion{Header: hdr, Value: v}
	if len(raw) > 8 {
		a.HasDouble = true
		if len(raw) >= 16 {
			a.Double = f64d(raw[8:])
		}
	}
	return a, nil
}

// Dependency is kDependency(0x56D0), handler FUN_18003be90 with 7-way
// subtype dispatch; the selector (FUN_1808af400) reads u32 header + u16×3
// and returns rootDataType=(word3>>10)&0xf (D89, DgAttributeLinkage.h
// RootDataType: 0=kElementId, 1=kElementId_V, 2/3=assoc points, 4/5=far
// element ids, 6=path). The kElementId roots are pinned by
// OdDgDepLinkageElementIdData::readRoots disassembly (D112):
// [u16 count][count × u64 element handle] — a shared-cell definition
// reference is the dependency with AppID 0x2716 and roots[0] = the
// definition's element handle. Non-element-id variants keep Rest raw.
type Dependency struct {
	Header       uint32
	AppID        uint16 // @4 (was W1)
	AppValue     uint16 // @6 (was W2)
	RootDataType uint8  // bits 10..13 of @8 (was Variant)
	Flags        uint16 // raw word @8
	RootCount    int    // @10 — element-id roots only
	Roots        []uint64
	Rest         []byte // tail beyond the roots (raw variants: from @10)
}

func decodeDependency(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 10 {
		return nil, fmt.Errorf("linkage: dependency too short (%d)", len(raw))
	}
	w3 := binary.LittleEndian.Uint16(raw[8:])
	d := &Dependency{
		Header:       hdr,
		AppID:        binary.LittleEndian.Uint16(raw[4:]),
		AppValue:     binary.LittleEndian.Uint16(raw[6:]),
		RootDataType: uint8((w3 >> 10) & 0xf),
		Flags:        w3,
	}
	switch {
	case d.RootDataType == 0 && len(raw) >= 12:
		n := int(binary.LittleEndian.Uint16(raw[10:]))
		if 12+n*8 > len(raw) {
			n = (len(raw) - 12) / 8 // short stream: take what's there
		}
		d.RootCount = n
		for i := 0; i < n; i++ {
			d.Roots = append(d.Roots, binary.LittleEndian.Uint64(raw[12+i*8:]))
		}
		if tail := 12 + n*8; tail < len(raw) {
			d.Rest = append([]byte(nil), raw[tail:]...)
		}
	default:
		d.RootCount = -1 // not an element-id dependency
		if len(raw) > 10 {
			d.Rest = append([]byte(nil), raw[10:]...)
		}
	}
	return d, nil
}
