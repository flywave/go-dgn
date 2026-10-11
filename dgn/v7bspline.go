package dgn

import (
	"encoding/binary"
	"fmt"
)

// V7BSplineCurveHeader is DGNT_BSPLINE_CURVE_HEADER(27)
// (GDAL dgnread L973-993).
type V7BSplineCurveHeader struct {
	DescWords  int32
	Order      byte // (flags&0x0f)+2
	Properties byte // flags&0xf0
	CurveType  byte
	NumPoles   uint16
	NumKnots   uint16
}

// ReadV7BSplineCurveHeader decodes type 27.
func ReadV7BSplineCurveHeader(el V7Element) (V7BSplineCurveHeader, error) {
	var h V7BSplineCurveHeader
	if el.Type != 27 {
		return h, fmt.Errorf("dgn/v7: not a bspline curve header (type %d)", el.Type)
	}
	if len(el.Body) < 42 {
		return h, fmt.Errorf("dgn/v7: bspline curve header body %d < 42", len(el.Body))
	}
	h.DescWords = V7Int32(el.Body[32:])
	flags := el.Body[36]
	h.Order = (flags & 0x0f) + 2
	h.Properties = flags & 0xf0
	h.CurveType = el.Body[37]
	h.NumPoles = binary.LittleEndian.Uint16(el.Body[38:])
	h.NumKnots = binary.LittleEndian.Uint16(el.Body[40:])
	return h, nil
}

// V7BSplineSurfaceHeader is DGNT_BSPLINE_SURFACE_HEADER(24)
// (GDAL dgnread L943-972).
type V7BSplineSurfaceHeader struct {
	DescWords   int32
	CurveType   byte
	UOrder      byte // (uflags&0x0f)+2
	VOrder      byte
	UProperties byte // uflags&0xf0
	VProperties byte
	NumPolesU   uint16
	NumKnotsU   uint16
	RuleLinesU  uint16
	NumPolesV   uint16
	NumKnotsV   uint16
	RuleLinesV  uint16
	NumBounds   uint16
}

// ReadV7BSplineSurfaceHeader decodes type 24. GDAL computes num_bounds with
// a *556 typo (byte@57 should be ×256); we read the proper u16.
func ReadV7BSplineSurfaceHeader(el V7Element) (V7BSplineSurfaceHeader, error) {
	var h V7BSplineSurfaceHeader
	if el.Type != 24 {
		return h, fmt.Errorf("dgn/v7: not a bspline surface header (type %d)", el.Type)
	}
	if len(el.Body) < 54 {
		return h, fmt.Errorf("dgn/v7: bspline surface header body %d < 54", len(el.Body))
	}
	h.DescWords = V7Int32(el.Body[32:])
	uflags := el.Body[36]
	h.UOrder = (uflags & 0x0f) + 2
	h.UProperties = uflags & 0xf0
	h.CurveType = el.Body[37]
	h.NumPolesU = binary.LittleEndian.Uint16(el.Body[38:])
	h.NumKnotsU = binary.LittleEndian.Uint16(el.Body[40:])
	h.RuleLinesU = binary.LittleEndian.Uint16(el.Body[42:])
	vflags := el.Body[44]
	h.VOrder = (vflags & 0x0f) + 2
	h.VProperties = vflags & 0xf0
	h.NumPolesV = binary.LittleEndian.Uint16(el.Body[46:])
	h.NumKnotsV = binary.LittleEndian.Uint16(el.Body[48:])
	h.RuleLinesV = binary.LittleEndian.Uint16(el.Body[50:])
	h.NumBounds = binary.LittleEndian.Uint16(el.Body[52:])
	return h, nil
}

// ReadV7KnotWeights decodes DGNT_BSPLINE_KNOT(26) and
// DGNT_BSPLINE_WEIGHT_FACTOR(28) (GDAL dgnread L1046-1072): count =
// (size − 36 − attrBytes)/4 words from body32, values = i32/(2^31−1).
func ReadV7KnotWeights(el V7Element) ([]float64, error) {
	if el.Type != 26 && el.Type != 28 {
		return nil, fmt.Errorf("dgn/v7: not a knot/weight element (type %d)", el.Type)
	}
	c := ParseV7Core(el)
	attr := 0
	if c.HasAttributes() {
		// GDAL: attr_bytes = nElemBytes − attrIndex*2 − 32 (element coords)
		attr = len(el.Body) - int(c.AttrIndex)*2 - 28
		if attr < 0 {
			attr = 0
		}
	}
	n := (len(el.Body) - 32 - attr) / 4
	if n < 1 {
		return nil, fmt.Errorf("dgn/v7: knot/weight count %d < 1", n)
	}
	out := make([]float64, 0, n)
	for i := 0; i < n; i++ {
		v := V7Int32(el.Body[32+i*4:])
		out = append(out, float64(v)/(float64(1<<31)-1))
	}
	return out, nil
}
