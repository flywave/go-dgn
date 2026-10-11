package dgn

import "fmt"

// V7Document is the top-level read result of a v7 file: header, the first
// (effective) TCB, and the element forest with complex groups nested.
type V7Document struct {
	Header   V7Header
	TCB      V7TCB
	Elements []V7Element // flat frame order
	Top      []V7Node    // complex groups nested
}

// v7ExtentTypes mirrors GDAL DGNGetRawExtents (dgnread L156-187): the
// types whose header bbox is authoritative.
var v7ExtentTypes = map[byte]bool{
	3: true, 4: true, 6: true, 7: true, 11: true, 12: true, 14: true,
	15: true, 16: true, 17: true, 18: true, 19: true, 21: true,
	23: true, 24: true, 27: true,
}

// ParseV7Document reads a whole v7 file: header, elements, first TCB
// (required — GDAL DGNLoadTCB fails without one) and nested groups.
func ParseV7Document(b []byte) (V7Document, error) {
	var d V7Document
	h, err := ParseV7Header(b)
	if err != nil {
		return d, err
	}
	d.Header = h
	els, err := ReadV7Elements(b)
	if err != nil {
		return d, err
	}
	d.Elements = els
	// The magic (byte1=0x09) guarantees the first element is a type-9 TCB;
	// Validate it defensively.
	if len(els) == 0 {
		return d, fmt.Errorf("dgn/v7: file has no elements")
	}
	if els[0].Type != 9 {
		return d, fmt.Errorf("dgn/v7: first element is not a TCB (type %d)", els[0].Type)
	}
	tcb, err := ParseV7TCB(els[0])
	if err != nil {
		return d, err
	}
	d.TCB = tcb
	d.Top, err = GroupV7Elements(els)
	if err != nil {
		return d, err
	}
	return d, nil
}

// Extents unions the header bboxes (offset-binary decoded, GDAL extent
// type set) of all elements and maps them to master units via the TCB.
// ok=false when no extent-bearing element exists.
func (d V7Document) Extents() (min, max [3]float64, ok bool) {
	var rawMin, rawMax [3]int32
	seen := false
	for _, e := range d.Elements {
		if !v7ExtentTypes[e.Type] || len(e.Body) < 24 {
			continue
		}
		c := ParseV7Core(e)
		if !seen {
			rawMin = [3]int32{c.BBox[0], c.BBox[1], c.BBox[2]}
			rawMax = [3]int32{c.BBox[3], c.BBox[4], c.BBox[5]}
			seen = true
			continue
		}
		for i := 0; i < 3; i++ {
			if c.BBox[i] < rawMin[i] {
				rawMin[i] = c.BBox[i]
			}
			if c.BBox[i+3] > rawMax[i] {
				rawMax[i] = c.BBox[i+3]
			}
		}
	}
	if !seen {
		return
	}
	ok = true
	min = d.TCB.TransformPoint(V7Point{X: rawMin[0], Y: rawMin[1], Z: rawMin[2]})
	max = d.TCB.TransformPoint(V7Point{X: rawMax[0], Y: rawMax[1], Z: rawMax[2]})
	return
}
