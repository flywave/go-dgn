package dgn

import (
	"encoding/binary"
	"fmt"
)

// V7PointF is a raw-UOR vertex in floating point: v7 vertices carry
// fractional A951 deltas (±1 UOR, GDAL dgnread L470-480).
type V7PointF struct {
	X, Y, Z float64
}

// v7A951 scans an attribute region for the A951 delta record and returns
// the delta start offset and length (GDAL DGNProcessElement).
func v7A951(region []byte) (dStart, dLen int) {
	for i := 0; i+4 <= len(region); i++ {
		if region[i] == 0xA9 && region[i+1] == 0x51 {
			return i + 6, int(binary.LittleEndian.Uint16(region[i+2:])) * 2
		}
	}
	return 0, 0
}

// v7ApplyDelta adds the A951 fractional correction of vertex i when the
// record covers it (dStart+i*4+4 ≤ len(region), GDAL guard).
func v7ApplyDelta(region []byte, dStart, dLen, i int, p *V7PointF) {
	if dStart == 0 || dLen == 0 || dStart+i*4+4 > len(region) {
		return
	}
	dx := int16(binary.LittleEndian.Uint16(region[dStart+i*4:]))
	dy := int16(binary.LittleEndian.Uint16(region[dStart+i*4+2:]))
	p.X += float64(dx) / 32767.0
	p.Y += float64(dy) / 32767.0
}

// ReadV7LineF decodes a LINE(3) with A951 fractional deltas applied
// (GDAL-equivalent raw UOR floats; run through V7TCB for master units).
func ReadV7LineF(el V7Element, is3d bool) ([2]V7PointF, error) {
	var out [2]V7PointF
	raw, err := ReadV7Line(el, is3d)
	if err != nil {
		return out, err
	}
	for i := 0; i < 2; i++ {
		out[i] = V7PointF{X: float64(raw[i].X), Y: float64(raw[i].Y), Z: float64(raw[i].Z)}
	}
	c := ParseV7Core(el)
	region := c.AttrRegion(el)
	ds, dl := v7A951(region)
	for i := range out {
		v7ApplyDelta(region, ds, dl, i, &out[i])
	}
	return out, nil
}

// ReadV7MultiPointF decodes the multipoint family (4/6/11/21) with A951
// fractional deltas applied.
func ReadV7MultiPointF(el V7Element, is3d bool) ([]V7PointF, error) {
	raw, err := ReadV7MultiPoint(el, is3d)
	if err != nil {
		return nil, err
	}
	out := make([]V7PointF, len(raw))
	for i, p := range raw {
		out[i] = V7PointF{X: float64(p.X), Y: float64(p.Y), Z: float64(p.Z)}
	}
	c := ParseV7Core(el)
	region := c.AttrRegion(el)
	ds, dl := v7A951(region)
	for i := range out {
		v7ApplyDelta(region, ds, dl, i, &out[i])
	}
	return out, nil
}

// V7Boundary is DGNT_BSPLINE_SURFACE_BOUNDARY(25): number + UV vertices
// (z=0, A951 deltas applied; no TCB transform — GDAL dgnread L994-1045).
type V7Boundary struct {
	Number uint16
	Verts  []V7PointF
}

// ReadV7Boundary decodes type 25 (2D/3D files alike; z stays 0).
func ReadV7Boundary(el V7Element) (V7Boundary, error) {
	var bd V7Boundary
	if el.Type != 25 {
		return bd, fmt.Errorf("dgn/v7: not a bspline boundary (type %d)", el.Type)
	}
	if len(el.Body) < 36 {
		return bd, fmt.Errorf("dgn/v7: boundary body %d < 36", len(el.Body))
	}
	bd.Number = binary.LittleEndian.Uint16(el.Body[32:])
	numverts := int(int16(binary.LittleEndian.Uint16(el.Body[34:])))
	if numverts <= 0 {
		return bd, fmt.Errorf("dgn/v7: boundary numverts %d <= 0", numverts)
	}
	c := ParseV7Core(el)
	region := c.AttrRegion(el)
	ds, dl := v7A951(region)
	for i := 0; i < numverts; i++ {
		if 44+i*8 > len(el.Body) {
			break
		}
		p := V7PointF{
			X: float64(V7Int32(el.Body[36+i*8:])),
			Y: float64(V7Int32(el.Body[40+i*8:])),
		}
		v7ApplyDelta(region, ds, dl, i, &p)
		bd.Verts = append(bd.Verts, p)
	}
	return bd, nil
}
