package linkage

import (
	"encoding/binary"
	"fmt"
)

// DB/sheet/document linkage payload decoders (U10b, D88-D90): DB
// linkages, sheet model/scale, ref attach path, annotations, OLE,
// boundary clip and shared cell flags.

// SharedCellFlags is kSharedCellFlags(0x56EA), handler FUN_1809d8150:
// u32 header, u32 flags.
type SharedCellFlags struct {
	Header, Flags uint32
}

func decodeSharedCellFlags(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	f, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	return &SharedCellFlags{Header: hdr, Flags: f}, nil
}

// SheetAnnotationScale is kSheetScale(0x56EE), handler FUN_1808c3990:
// u32 header + 5×f64 (degenerate→0).
type SheetAnnotationScale struct {
	Header uint32
	Values [5]float64
}

func decodeSheetScale(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	s := &SheetAnnotationScale{Header: hdr}
	for i := 0; i < 5; i++ {
		o := 4 + i*8
		if o+8 > len(raw) {
			return s, fmt.Errorf("linkage: sheet scale truncated at %d", o)
		}
		s.Values[i] = f64d(raw[o:])
	}
	return s, nil
}

// DBLinkage is the shared handler FUN_1808c07f0 payload for the ten DB
// linkage IDs: u32 header, u16 word (must equal a magic constant [?];
// non-matching → handler returns null), u16 subType, u32 id, u32 extra
// (D89).
type DBLinkage struct {
	Header  uint32
	Word    uint16
	SubType uint16
	ID      uint32
	Extra   uint32
	Kind    DBLinkageKind
}

func decodeDBLinkageFor(id uint16) func([]byte) (any, error) {
	return func(raw []byte) (any, error) {
		hdr, err := le32(raw, 0)
		if err != nil {
			return nil, err
		}
		if len(raw) < 6 {
			return nil, fmt.Errorf("linkage: db linkage too short (%d)", len(raw))
		}
		d := &DBLinkage{
			Header: hdr,
			Word:   binary.LittleEndian.Uint16(raw[4:]),
			Kind:   dbKindForID[id],
		}
		if len(raw) >= 16 {
			d.SubType = binary.LittleEndian.Uint16(raw[6:])
			d.ID = binary.LittleEndian.Uint32(raw[8:])
			d.Extra = binary.LittleEndian.Uint32(raw[12:])
		}
		return d, nil
	}
}

// ---- Third batch: class-delegate Impl readers (D90) ----
// Each layout below is pinned from the Impl's slot-15 reader (the +0x78
// virtual the handler invokes). "Rest raw" marks the tail of branchy
// readers that was not fully walked; the prefix is verified.

// TextAnnotation is kTextAnnotation(0x56F3), reader FUN_1808ab130:
// u32 header, u32 value, 2×f64 (degenerate→0).
type TextAnnotation struct {
	Header, Value uint32
	D             [2]float64
}

func decodeTextAnnotation(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	v, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	if len(raw) < 20 {
		return nil, fmt.Errorf("linkage: text annotation too short (%d)", len(raw))
	}
	return &TextAnnotation{Header: hdr, Value: v,
		D: [2]float64{f64d(raw[8:]), f64d(raw[16:])}}, nil
}

// RefAttachPath is kReferenceAttachmentPath(0x56F1), reader FUN_1808af600:
// u32 header, u32 a, u32 b, u32 count, count×f64.
type RefAttachPath struct {
	Header, A, B, Count uint32
	Values              []float64
}

func decodeRefAttachPath(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	a, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	b, err := le32(raw, 8)
	if err != nil {
		return nil, err
	}
	cnt, err := le32(raw, 12)
	if err != nil {
		return nil, err
	}
	r := &RefAttachPath{Header: hdr, A: a, B: b, Count: cnt}
	for i := uint32(0); i < cnt; i++ {
		o := 16 + int(i)*8
		if o+8 > len(raw) {
			return r, fmt.Errorf("linkage: ref attach path truncated at %d", o)
		}
		r.Values = append(r.Values, f64d(raw[o:]))
	}
	return r, nil
}

// SheetModelExtension is kSheetModelEx(0x5701), reader FUN_1808c3bc0:
// u32 header + 5×u32.
type SheetModelExtension struct {
	Header uint32
	Fields [5]uint32
}

func decodeSheetModelExtension(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 24 {
		return nil, fmt.Errorf("linkage: sheet model ex too short (%d)", len(raw))
	}
	x := &SheetModelExtension{Header: hdr}
	for i := 0; i < 5; i++ {
		x.Fields[i] = binary.LittleEndian.Uint32(raw[4+i*4:])
	}
	return x, nil
}

// BoundaryClip is kBoundaryClip(0x56DC), reader FUN_1808cb030:
// u32 header + 14×f64 (degenerate→0) + u32 + u32 count + count×(2×f64).
type BoundaryClip struct {
	Header uint32
	V      [14]float64
	W      uint32
	Count  uint32
	Pairs  [][2]float64
}

func decodeBoundaryClip(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 4+14*8+8 {
		return nil, fmt.Errorf("linkage: boundary clip too short (%d)", len(raw))
	}
	b := &BoundaryClip{Header: hdr}
	for i := 0; i < 14; i++ {
		b.V[i] = f64d(raw[4+i*8:])
	}
	off := 4 + 14*8
	b.W = binary.LittleEndian.Uint32(raw[off:])
	cnt, err := le32(raw, off+4)
	if err != nil {
		return b, nil
	}
	b.Count = cnt
	off += 8
	for i := uint32(0); i < cnt; i++ {
		if off+16 > len(raw) {
			return b, fmt.Errorf("linkage: boundary clip pairs truncated at %d", off)
		}
		b.Pairs = append(b.Pairs, [2]float64{f64d(raw[off:]), f64d(raw[off+8:])})
		off += 16
	}
	return b, nil
}

// SheetModel is kSheetModel(0x56ED), reader FUN_1808c3d40 prefix:
// u32 header, u32 a, u32 b, 5×f64 (degenerate→0), u32 c, u32 d + Rest
// (branchy tail, raw).
type SheetModel struct {
	Header, A, B, C, D uint32
	V                  [5]float64
	Rest               []byte
}

func decodeSheetModel(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 4+8+40+8 {
		return nil, fmt.Errorf("linkage: sheet model too short (%d)", len(raw))
	}
	s := &SheetModel{Header: hdr,
		A: binary.LittleEndian.Uint32(raw[4:]),
		B: binary.LittleEndian.Uint32(raw[8:])}
	for i := 0; i < 5; i++ {
		s.V[i] = f64d(raw[12+i*8:])
	}
	off := 12 + 40
	s.C = binary.LittleEndian.Uint32(raw[off:])
	s.D = binary.LittleEndian.Uint32(raw[off+4:])
	if off+8 < len(raw) {
		s.Rest = append([]byte(nil), raw[off+8:]...)
	}
	return s, nil
}

// Ole is kOLE(0xB01E), reader FUN_1808c4b60 prefix:
// u32 header + 7×u32 + Rest (count-driven tail, raw).
type Ole struct {
	Header uint32
	Fields [7]uint32
	Rest   []byte
}

func decodeOle(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 32 {
		return nil, fmt.Errorf("linkage: ole too short (%d)", len(raw))
	}
	o := &Ole{Header: hdr}
	for i := 0; i < 7; i++ {
		o.Fields[i] = binary.LittleEndian.Uint32(raw[4+i*4:])
	}
	if len(raw) > 32 {
		o.Rest = append([]byte(nil), raw[32:]...)
	}
	return o, nil
}

// TextIndentation is kTextIndentation(0x5810), reader FUN_1808ad230
// prefix: u32 header, u32 a, 2×f64 (degenerate→0), u32 b, u32 c + Rest
// (branchy tail, raw).
type TextIndentation struct {
	Header, A, B, C uint32
	D               [2]float64
	Rest            []byte
}

func decodeTextIndentation(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 32 {
		return nil, fmt.Errorf("linkage: text indentation too short (%d)", len(raw))
	}
	t := &TextIndentation{
		Header: hdr,
		A:      binary.LittleEndian.Uint32(raw[4:]),
		D:      [2]float64{f64d(raw[8:]), f64d(raw[16:])},
	}
	off := 24
	t.B = binary.LittleEndian.Uint32(raw[off:])
	t.C = binary.LittleEndian.Uint32(raw[off+4:])
	if off+8 < len(raw) {
		t.Rest = append([]byte(nil), raw[off+8:]...)
	}
	return t, nil
}
