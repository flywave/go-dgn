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
// and returns variant=(word3>>10)&0xf (D89). Variant payload layouts are
// class-reader owned; Rest keeps them raw.
type Dependency struct {
	Header  uint32
	W1, W2  uint16
	Variant uint8
	Rest    []byte
}

func decodeDependency(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 10 {
		return nil, fmt.Errorf("linkage: dependency too short (%d)", len(raw))
	}
	d := &Dependency{
		Header:  hdr,
		W1:      binary.LittleEndian.Uint16(raw[4:]),
		W2:      binary.LittleEndian.Uint16(raw[6:]),
		Variant: uint8((binary.LittleEndian.Uint16(raw[8:]) >> 10) & 0xf),
	}
	if len(raw) > 10 {
		d.Rest = append([]byte(nil), raw[10:]...)
	}
	return d, nil
}
