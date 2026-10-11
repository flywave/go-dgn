package dgn

import (
	"encoding/binary"
	"fmt"
	"math"
)

// V7Rad50 decodes one 16-bit MicroStation RAD50 word into 3 characters
// (GDAL DGNRad50ToAscii: base 40, mapping 0=' ', 1-26='A'-'Z', 27='$',
// 28='.', 29=' ', 30-39='0'-'9'; out-of-range digits keep the previous
// character, exactly like the GDAL loop).
func V7Rad50(w uint16) string {
	var out [4]byte
	ch := byte(0)
	quots := [3]uint16{1600, 40, 1}
	for i := 0; i < 3; i++ {
		v := w / quots[i]
		switch {
		case v == 0:
			ch = ' '
		case v <= 26:
			ch = byte(v-1) + 'A'
		case v == 27:
			ch = '$'
		case v == 28:
			ch = '.'
		case v == 29:
			ch = ' '
		case v <= 39:
			ch = byte(v-30) + '0'
		}
		out[i] = ch
		w -= v * quots[i]
	}
	return string(out[:3])
}

// V7CellHeader is DGNT_CELL_HEADER(2), a complex group whose children are
// not nested by GDAL/OGR (geometry ignored by the OGR driver).
type V7CellHeader struct {
	TotLength uint16
	Name      string // 6 chars (2×RAD50)
	Class     uint16
	Levels    [4]uint16
	RangeLow  V7Point // raw UOR
	RangeHigh V7Point
	Trans     [9]float64 // 2D uses [0..3] = i32/2^31
	Origin    V7Point    // raw UOR
	XScale    float64    // 2D only: GDAL derived value (unit×~10000)
	YScale    float64
	Rotation  float64 // 2D only, degrees CCW
	Is3D      bool
}

// ReadV7CellHeader decodes DGNT_CELL_HEADER(2) (GDAL dgnread L289-387).
func ReadV7CellHeader(el V7Element, is3d bool) (V7CellHeader, error) {
	var c V7CellHeader
	need := 88
	if is3d {
		need = 120
	}
	if len(el.Body) < need {
		return c, fmt.Errorf("dgn/v7: cell header body %d < %d", len(el.Body), need)
	}
	c.Is3D = is3d
	c.TotLength = binary.LittleEndian.Uint16(el.Body[32:])
	c.Name = V7Rad50(binary.LittleEndian.Uint16(el.Body[34:])) +
		V7Rad50(binary.LittleEndian.Uint16(el.Body[36:]))
	c.Class = binary.LittleEndian.Uint16(el.Body[38:])
	for i := 0; i < 4; i++ {
		c.Levels[i] = binary.LittleEndian.Uint16(el.Body[40+i*2:])
	}
	if is3d {
		c.RangeLow = V7Point{
			X: V7Int32(el.Body[48:]),
			Y: V7Int32(el.Body[52:]),
			Z: V7Int32(el.Body[56:]),
		}
		c.RangeHigh = V7Point{
			X: V7Int32(el.Body[60:]),
			Y: V7Int32(el.Body[64:]),
			Z: V7Int32(el.Body[68:]),
		}
		for i := 0; i < 9; i++ {
			c.Trans[i] = float64(V7Int32(el.Body[72+i*4:])) / (1 << 31)
		}
		c.Origin = V7Point{
			X: V7Int32(el.Body[108:]),
			Y: V7Int32(el.Body[112:]),
			Z: V7Int32(el.Body[116:]),
		}
		return c, nil
	}
	c.RangeLow = V7Point{X: V7Int32(el.Body[48:]), Y: V7Int32(el.Body[52:])}
	c.RangeHigh = V7Point{X: V7Int32(el.Body[56:]), Y: V7Int32(el.Body[60:])}
	for i := 0; i < 4; i++ {
		c.Trans[i] = float64(V7Int32(el.Body[64+i*4:])) / (1 << 31)
	}
	c.Origin = V7Point{X: V7Int32(el.Body[80:]), Y: V7Int32(el.Body[84:])}

	// GDAL-derived 2D scale/rotation from the 2x2 sub-matrix.
	a := float64(V7Int32(el.Body[64:]))
	b := float64(V7Int32(el.Body[68:]))
	cc := float64(V7Int32(el.Body[72:]))
	d := float64(V7Int32(el.Body[76:]))
	a2, c2 := a*a, cc*cc
	c.XScale = math.Sqrt(a2+c2) / 214748
	c.YScale = math.Sqrt(b*b+d*d) / 214748
	if a2+c2 <= 0 {
		c.Rotation = 0
	} else {
		c.Rotation = math.Acos(a / math.Sqrt(a2+c2))
		if b <= 0 {
			c.Rotation = c.Rotation * 180 / math.Pi
		} else {
			c.Rotation = 360 - c.Rotation*180/math.Pi
		}
	}
	return c, nil
}

// V7CellLibrary is DGNT_CELL_LIBRARY(1); its own property word lives at
// body34 (the element has no display header).
type V7CellLibrary struct {
	Name        string // 6 chars
	NumWords    uint16
	Properties  uint16
	DisplaySym  uint16
	Class       uint16
	Levels      [4]uint16
	Description string // 27 chars (9×RAD50)
}

// ReadV7CellLibrary decodes DGNT_CELL_LIBRARY(1) (GDAL dgnread L389-426).
func ReadV7CellLibrary(el V7Element) (V7CellLibrary, error) {
	var c V7CellLibrary
	if el.Type != 1 {
		return c, fmt.Errorf("dgn/v7: not a cell library (type %d)", el.Type)
	}
	if len(el.Body) < 66 {
		return c, fmt.Errorf("dgn/v7: cell library body %d < 66", len(el.Body))
	}
	c.Name = V7Rad50(binary.LittleEndian.Uint16(el.Body[28:])) +
		V7Rad50(binary.LittleEndian.Uint16(el.Body[30:]))
	c.NumWords = binary.LittleEndian.Uint16(el.Body[32:])
	c.Properties = binary.LittleEndian.Uint16(el.Body[34:])
	c.DisplaySym = binary.LittleEndian.Uint16(el.Body[36:])
	c.Class = binary.LittleEndian.Uint16(el.Body[38:])
	for i := 0; i < 4; i++ {
		c.Levels[i] = binary.LittleEndian.Uint16(el.Body[40+i*2:])
	}
	var desc [27]byte
	for i := 0; i < 9; i++ {
		w := binary.LittleEndian.Uint16(el.Body[48+i*2:])
		s := V7Rad50(w)
		copy(desc[i*3:], s)
	}
	c.Description = string(desc[:])
	return c, nil
}

// V7SharedCellDefn is DGNT_SHARED_CELL_DEFN(34); GDAL parses only
// totlength (dgnread L1074-1085). The sample-derived name lives at
// body160..176 (16B ASCII, NUL-padded) — same slot as the reference.
type V7SharedCellDefn struct {
	TotLength uint16
	Name      string // body160..176 ASCII (sample-derived, [?] upstream)
}

// ReadV7SharedCellDefn decodes type 34.
func ReadV7SharedCellDefn(el V7Element) (V7SharedCellDefn, error) {
	var s V7SharedCellDefn
	if el.Type != 34 {
		return s, fmt.Errorf("dgn/v7: not a shared cell defn (type %d)", el.Type)
	}
	if len(el.Body) < 34 {
		return s, fmt.Errorf("dgn/v7: shared cell defn body %d < 34", len(el.Body))
	}
	s.TotLength = binary.LittleEndian.Uint16(el.Body[32:])
	if len(el.Body) >= 176 {
		s.Name = v7ASCIIName(el.Body[160:176])
	}
	return s, nil
}

// V7SharedCellRef is DGNT_SHARED_CELL_REF(35), a shared-cell *instance*.
// Sample-derived (39 instances in sample.dgn, all size 176B): range6
// halfword-swapped i32 UOR @48..67 (3D cell-header convention), and an
// ASCII name @160..176 that cross-references a type-34 definition.
// Three uniform scale slots sit at @72/@104/@136 (i32-swapped; values
// read 0.5039 via i32/2^31 or 4.0 as swapped f32 — semantics [?]).
type V7SharedCellRef struct {
	TotLength  uint16
	RangeLow   V7Point // raw UOR, halfword-swapped i32
	RangeHigh  V7Point
	ScaleSlots [3]uint32 // raw @72/@104/@136 [?]
	Name       string    // body160..176 ASCII (cross-refs a defn name)
}

// ReadV7SharedCellRef decodes type 35. GDAL leaves this type in its
// default branch; the layout is pinned by the sample (39/39 uniform).
func ReadV7SharedCellRef(el V7Element) (V7SharedCellRef, error) {
	var s V7SharedCellRef
	if el.Type != 35 {
		return s, fmt.Errorf("dgn/v7: not a shared cell ref (type %d)", el.Type)
	}
	if len(el.Body) < 176 {
		return s, fmt.Errorf("dgn/v7: shared cell ref body %d < 176", len(el.Body))
	}
	s.TotLength = binary.LittleEndian.Uint16(el.Body[32:])
	s.RangeLow = V7Point{
		X: V7Int32(el.Body[48:]),
		Y: V7Int32(el.Body[52:]),
		Z: V7Int32(el.Body[56:]),
	}
	s.RangeHigh = V7Point{
		X: V7Int32(el.Body[60:]),
		Y: V7Int32(el.Body[64:]),
		Z: V7Int32(el.Body[68:]),
	}
	for i, p := range []int{72, 104, 136} {
		s.ScaleSlots[i] = uint32(V7Int32(el.Body[p:]))
	}
	s.Name = v7ASCIIName(el.Body[160:176])
	return s, nil
}

// v7ASCIIName trims a NUL-padded fixed-width ASCII field.
func v7ASCIIName(b []byte) string {
	for i, c := range b {
		if c == 0 {
			return string(b[:i])
		}
	}
	return string(b)
}
