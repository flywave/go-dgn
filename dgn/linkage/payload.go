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
