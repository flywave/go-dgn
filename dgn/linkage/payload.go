package linkage

import (
	"encoding/binary"
	"fmt"
	"math"
)

// Payload decoders for typed linkage records (U10b, D88). Each decodes the
// handler-visible byte stream: Rec.Raw == the (data,size) buffer handed to
// the ODA handler registered via oddgSetLinkageHandler — the u32 header word
// at Raw[0:4] first, then the class-specific fields.
//
// Doubles use the ODA "degenerate" rule seen in every handler reader: an
// IEEE little-endian f64 whose exponent is 0 (zero/subnormal) or 0x7ff
// (Inf/NaN) is replaced by 0.0.

// f64d reads a degenerate-filtered little-endian IEEE double.
func f64d(b []byte) float64 {
	u := binary.LittleEndian.Uint64(b)
	if exp := (u >> 52) & 0x7ff; exp == 0 || exp == 0x7ff {
		return 0
	}
	return math.Float64frombits(u)
}

func le32(b []byte, off int) (uint32, error) {
	if off+4 > len(b) {
		return 0, fmt.Errorf("linkage: payload too short at %d (need 4, have %d)", off, len(b))
	}
	return binary.LittleEndian.Uint32(b[off:]), nil
}

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

// DoubleArray is kDoubleArray(0x56D5), handler FUN_1808acfc0:
// u32 header, u32 value, u32 count, count×f64 (degenerate→0).
type DoubleArray struct {
	Header, Value, Count uint32
	Values               []float64
}

func decodeDoubleArray(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	val, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	count, err := le32(raw, 8)
	if err != nil {
		return nil, err
	}
	d := &DoubleArray{Header: hdr, Value: val, Count: count}
	for i := uint32(0); i < count; i++ {
		o := 12 + int(i)*8
		if o+8 > len(raw) {
			return d, fmt.Errorf("linkage: double array truncated at %d", o)
		}
		d.Values = append(d.Values, f64d(raw[o:]))
	}
	return d, nil
}

// String is kString(0x56D2), handler FUN_1800481a0:
// u32 header, u32 id, u32 len, bytes[len] (raw; FF F1 BOM → wide variant,
// kept raw here).
type String struct {
	Header, ID, Len uint32
	Data            []byte
}

func decodeString(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	id, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	n, err := le32(raw, 8)
	if err != nil {
		return nil, err
	}
	s := &String{Header: hdr, ID: id, Len: n}
	end := 12 + int(n)
	if end > len(raw) {
		end = len(raw)
	}
	if 12 <= len(raw) {
		s.Data = append([]byte(nil), raw[12:end]...)
	}
	return s, nil
}

// ByteArray is kByteArray(0x5751), handler FUN_1808adc60:
// u32 count + count raw bytes (rest of the record).
type ByteArray struct {
	Count uint32
	Data  []byte
}

func decodeByteArray(raw []byte) (any, error) {
	count, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	b := &ByteArray{Count: count}
	end := 4 + int(count)
	if end > len(raw) {
		end = len(raw)
	}
	b.Data = append([]byte(nil), raw[4:end]...)
	return b, nil
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

// Note is kNoteLinkage(0x562E), handler FUN_1808340b0: fixed 32-byte record
// (u32 header + 7×u32) where payload bytes 8..11 spell ASCII "Note".
type Note struct {
	Fields [8]uint32
	IsNote bool
}

func decodeNote(raw []byte) (any, error) {
	if len(raw) < 32 {
		return nil, nil // handler rejects non-0x20 sizes
	}
	n := &Note{}
	for i := 0; i < 8; i++ {
		n.Fields[i] = binary.LittleEndian.Uint32(raw[i*4:])
	}
	n.IsNote = raw[8] == 'N' && raw[9] == 'o' && raw[10] == 't' && raw[11] == 'e'
	return n, nil
}

// decoders maps handler-registered primary IDs to payload decoders (D88).
// nil values mark IDs with a typed ODA handler not yet traced.
var decoders = map[uint16]func([]byte) (any, error){
	0x0041: decodeFillStyle,
	0x562e: decodeNote,
	0x56d2: decodeString,
	0x56d4: decodeThickness,
	0x56d5: decodeDoubleArray,
	0x56d0: decodeDependency,
	0x56d3: decodeBitMask,
	0x56d8: decodeAssocRegion,
	0x56da: decodeSeedPoints,
	0x56e9: decodeInfiniteLine,
	0x56ea: decodeSharedCellFlags,
	0x56ee: decodeSheetScale,
	0x5751: decodeByteArray,
}

// HandlerIDs lists every primary ID with a typed handler in TG_Db
// (oddgSetLinkageHandler registrations in FUN_1800548f0; D88/D89).
var HandlerIDs = []uint16{
	0x0000, 0x0020, 0x0041, 0x0f81, 0x1971, 0x3948, 0x3a77,
	0x4f58, 0x4f5a, 0x522e, 0x562e, 0x56d0, 0x56d2, 0x56d3, 0x56d4,
	0x56d5, 0x56d8, 0x56da, 0x56dc, 0x56dd, 0x56de, 0x56e3, 0x56e9,
	0x56ea, 0x56ed, 0x56ee, 0x56f1, 0x56f3, 0x5701, 0x5751,
	0x5800, 0x5801, 0x5810, 0x5e62, 0x6091, 0x71fb, 0x79f9, 0x7d28,
	0xb01e,
}

// HandlerNames maps each handler-registered primary ID to the ODA linkage
// class its handler constructs (D88/D89, from createObject calls in the
// decompiled handlers). IDs whose handler builds a family (FillStyle) or
// dispatches on a payload discriminator are annotated in the comment.
var HandlerNames = map[uint16]string{
	0x0000: "OdDgDMRSLinkage",
	0x0020: "OdDgDBLinkage(FRAMME)",
	0x0041: "FillStyle family", // dispatcher: DisplayStyle/Gradient/FillColor/InternalMaterial/Transparency
	0x0f81: "OdDgDBLinkage(BSI)",
	0x1971: "OdDgDBLinkage(XBASE)",
	0x3948: "OdDgDBLinkage(INFORMIX)",
	0x3a77: "OdDgDBLinkage(INGRES)",
	0x4f58: "OdDgDBLinkage(SYBASE)",
	0x4f5a: "OdDgMaterialLinkage",
	0x522e: "OdDgBrepLinkage",
	0x562e: "OdDgNoteLinkage",
	0x56d0: "OdDgDependencyLinkage", // 7-way subtype dispatch (variant=(hdr>>10)&0xf)
	0x56d2: "OdDgStringLinkage",
	0x56d3: "OdDgBitMaskLinkage", // payload[4]==6 → OdDgTextWhiteSpaceLinkage
	0x56d4: "OdDgThicknessLinkage",
	0x56d5: "OdDgDoubleArrayLinkage",
	0x56d8: "OdDgAssocRegionLinkage",
	0x56da: "OdDgSeedPointsLinkage",
	0x56dc: "OdDgBoundaryClipLinkage",
	0x56dd: "OdDgFilterMemberLinkage",
	0x56de: "OdDgDimensionLinkage",
	0x56e3: "OdDgXmlLinkage",
	0x56e9: "OdDgInfiniteLineLinkage",
	0x56ea: "OdDgSharedCellFlagsLinkage",
	0x56ed: "OdDgSheetModelLinkage",
	0x56ee: "OdDgSheetAnnotationScaleLinkage",
	0x56f1: "OdDgReferenceAttachPathLinkage",
	0x56f3: "OdDgTextAnnotationLinkage",
	0x5701: "OdDgSheetModelExtensionLinkage",
	0x5751: "OdDgByteArrayLinkage",
	0x5800: "OdDgDBLinkage(OLEDB)",
	0x5801: "OdDgDimensionTextStyleDataLinkage",
	0x5810: "OdDgTextIndentationLinkage",
	0x5e62: "OdDgDBLinkage(ODBC)",
	0x6091: "OdDgDBLinkage(ORACLE)",
	0x71fb: "OdDgDBLinkage(RIS)",
	0x79f9: "OdDgLineStyleModificationLinkage",
	0x7d28: "OdDgHatchLinkage",
	0xb01e: "OdDgOleLinkage",
}

// DBLinkageKind enumerates the OdDgDBLinkage::DBType values (FUN_1808c07f0).
type DBLinkageKind uint8

const (
	DBFRAMME   DBLinkageKind = 1
	DBInformix DBLinkageKind = 2
	DBIngres   DBLinkageKind = 3
	DBODBC     DBLinkageKind = 4
	DBOLEDB    DBLinkageKind = 5
	DBOracle   DBLinkageKind = 6
	DBRIS      DBLinkageKind = 7
	DBSybase   DBLinkageKind = 8
	DBXbase    DBLinkageKind = 9
)

// dbKindForID maps the ten DB-family primary IDs to their DBType.
var dbKindForID = map[uint16]DBLinkageKind{
	0x0020: DBFRAMME, 0x3948: DBInformix, 0x3a77: DBIngres, 0x5e62: DBODBC,
	0x5800: DBOLEDB, 0x6091: DBOracle, 0x71fb: DBRIS, 0x4f58: DBSybase,
	0x1971: DBXbase,
	// 0x0f81 (BSI) maps to kind 0 in the handler switch
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

func init() {
	for id := range dbKindForID {
		decoders[id] = decodeDBLinkageFor(id)
	}
	decoders[0x0f81] = decodeDBLinkageFor(0x0f81) // BSI: kind stays 0
}

// DecodePayload returns the typed payload for a record whose TypeID has a
// traced decoder, or (nil, nil) when the record should stay raw.
func DecodePayload(rec Rec) (any, error) {
	d := decoders[rec.TypeID]
	if d == nil {
		return nil, nil
	}
	return d(rec.Raw)
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

// XML is kXmlLinkage(0x56E3), reader FUN_1808d3970:
// u32 header, 6×u32 (skipped metadata), u32 len1, bytes[len1],
// u32 len2, bytes[len2].
type XML struct {
	Header uint32
	Meta   [6]uint32
	Parts  [][]byte
}

func decodeXML(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 32 {
		return nil, fmt.Errorf("linkage: xml too short (%d)", len(raw))
	}
	x := &XML{Header: hdr}
	for i := 0; i < 6; i++ {
		x.Meta[i] = binary.LittleEndian.Uint32(raw[4+i*4:])
	}
	off := 28
	for p := 0; p < 2; p++ {
		n, err := le32(raw, off)
		if err != nil {
			return x, nil // second part optional
		}
		off += 4
		end := off + int(n)
		if end > len(raw) {
			end = len(raw)
		}
		x.Parts = append(x.Parts, append([]byte(nil), raw[off:end]...))
		off = end
	}
	return x, nil
}

// FilterMember is kFilterMember(0x56DD), reader FUN_1808ae0b0 (payload
// after the header word): u32 x, u16 a, u16 b, u32 len1, u32 len2, u32 y,
// bytes[len1], bytes[len2].
type FilterMember struct {
	Header     uint32
	X          uint32
	A, B       uint16
	Y          uint32
	Str1, Str2 []byte
}

func decodeFilterMember(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 24 {
		return nil, fmt.Errorf("linkage: filter member too short (%d)", len(raw))
	}
	f := &FilterMember{
		Header: hdr,
		X:      binary.LittleEndian.Uint32(raw[4:]),
		A:      binary.LittleEndian.Uint16(raw[8:]),
		B:      binary.LittleEndian.Uint16(raw[10:]),
	}
	off := 12
	n1, err := le32(raw, off)
	if err != nil {
		return f, nil
	}
	off += 4
	n2, err := le32(raw, off)
	if err != nil {
		return f, nil
	}
	off += 4
	if y, err := le32(raw, off); err == nil {
		f.Y = y
		off += 4
	}
	end := off + int(n1)
	if end > len(raw) {
		end = len(raw)
	}
	f.Str1 = append([]byte(nil), raw[off:end]...)
	off = end
	end = off + int(n2)
	if end > len(raw) {
		end = len(raw)
	}
	f.Str2 = append([]byte(nil), raw[off:end]...)
	return f, nil
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

func init() {
	decoders[0x4f5a] = decodeMaterial
	decoders[0x56dd] = decodeFilterMember
	decoders[0x56dc] = decodeBoundaryClip
	decoders[0x56e3] = decodeXML
	decoders[0x56ed] = decodeSheetModel
	decoders[0x56f1] = decodeRefAttachPath
	decoders[0x56f3] = decodeTextAnnotation
	decoders[0x5701] = decodeSheetModelExtension
	decoders[0x5801] = decodeDimTextStyle
	decoders[0x5810] = decodeTextIndentation
	decoders[0x79f9] = decodeLineStyleMod
	decoders[0xb01e] = decodeOle
}
