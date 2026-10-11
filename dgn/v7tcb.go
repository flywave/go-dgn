package dgn

import (
	"encoding/binary"
	"fmt"
)

// V7TCB is the MicroStation Terminal Control Block (DGNT_TCB, type 9):
// the unit and scale basis for every coordinate in a v7 file.
type V7TCB struct {
	Dimension         int // 2 or 3 (flag byte body1210 bit0x40)
	UORPerSubunit     int32
	SubunitsPerMaster int32
	MasterUnits       string     // 2 chars, e.g. "in"
	SubUnits          string     // 2 chars, e.g. "th"
	Origin            [3]float64 // global origin, master units
	Scale             float64    // UOR → master units; 0 when units invalid
	Views             [8]V7View  // view control blocks @body42+i*118
}

// V7View is one of the eight view records in the TCB (GDAL DGNParseTCB
// view loop L1545-1575). Origin is in master units (scale−origin), Delta
// is UOR×Scale only (no origin subtraction), matrix/conversion stay raw.
type V7View struct {
	Flags      uint16
	Levels     [8]byte
	Origin     [3]float64 // master units
	Delta      [3]float64 // UOR × Scale
	TransMat   [9]float64
	Conversion float64
	ActiveZ    uint32
}

// ParseV7TCB decodes a type-9 element (GDAL DGNParseTCB). A file may hold
// several; only the first one takes effect (GDAL got_tcb latch).
func ParseV7TCB(el V7Element) (V7TCB, error) {
	var t V7TCB
	if el.Type != 9 {
		return t, fmt.Errorf("dgn/v7: not a TCB element (type %d)", el.Type)
	}
	if len(el.Body) < 1260 {
		return t, fmt.Errorf("dgn/v7: tcb body %d < 1260", len(el.Body))
	}
	if el.Body[1210]&0x40 != 0 {
		t.Dimension = 3
	} else {
		t.Dimension = 2
	}
	t.SubunitsPerMaster = V7Int32(el.Body[1108:])
	t.UORPerSubunit = V7Int32(el.Body[1112:])
	t.MasterUnits = string(el.Body[1116:1118])
	t.SubUnits = string(el.Body[1118:1120])

	raw := [3]float64{
		V7Double(el.Body[1236:]),
		V7Double(el.Body[1244:]),
		V7Double(el.Body[1252:]),
	}
	if t.UORPerSubunit != 0 && t.SubunitsPerMaster != 0 {
		t.Scale = 1 / (float64(t.UORPerSubunit) * float64(t.SubunitsPerMaster))
		for i := range raw {
			t.Origin[i] = raw[i] * t.Scale
		}
	} else {
		t.Origin = raw
	}

	for i := 0; i < 8; i++ {
		base := 42 + i*118
		v := &t.Views[i]
		v.Flags = binary.LittleEndian.Uint16(el.Body[base:])
		copy(v.Levels[:], el.Body[base+2:])
		p := V7Point{
			X: V7Int32(el.Body[base+10:]),
			Y: V7Int32(el.Body[base+14:]),
			Z: V7Int32(el.Body[base+18:]),
		}
		v.Origin = t.TransformPoint(p)
		for j := 0; j < 3; j++ {
			v.Delta[j] = float64(V7Int32(el.Body[base+22+j*4:])) * t.Scale
		}
		for j := 0; j < 9; j++ {
			v.TransMat[j] = V7Double(el.Body[base+34+j*8:])
		}
		v.Conversion = V7Double(el.Body[base+106:])
		v.ActiveZ = V7Uint32(el.Body[base+114:])
	}
	return t, nil
}

// TransformPoint maps a raw i32 UOR point to master units
// (GDAL DGNTransformPoint: p*scale − origin).
func (t V7TCB) TransformPoint(p V7Point) [3]float64 {
	return [3]float64{
		float64(p.X)*t.Scale - t.Origin[0],
		float64(p.Y)*t.Scale - t.Origin[1],
		float64(p.Z)*t.Scale - t.Origin[2],
	}
}

// ToMaster maps a raw VAX-double UOR triple (arc/ellipse/cone geometry)
// to master units.
func (t V7TCB) ToMaster(p [3]float64) [3]float64 {
	return [3]float64{
		p[0]*t.Scale - t.Origin[0],
		p[1]*t.Scale - t.Origin[1],
		p[2]*t.Scale - t.Origin[2],
	}
}

// TextMult converts a raw text length/height multiplier int32 to master
// units (GDAL: raw × scale × 6/1000).
func (t V7TCB) TextMult(raw int32) float64 {
	return float64(raw) * t.Scale * 6.0 / 1000.0
}
