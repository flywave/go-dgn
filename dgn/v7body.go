package dgn

import (
	"encoding/binary"
	"fmt"
)

type V7Point struct {
	X, Y, Z int32
}

var v7NoDispHdr = map[byte]bool{
	0: true, 1: true, 9: true, 10: true, 32: true, 44: true,
	48: true, 49: true, 50: true, 51: true, 57: true,
	60: true, 61: true, 62: true, 63: true,
}

type V7Core struct {
	BBox         [6]int32 // true UOR (offset-binary decoded)
	GraphicGroup uint16
	AttrIndex    uint16 // words from element start to attribute tail (body26)
	Properties   uint16
	Style        byte
	Weight       byte
	Color        byte
	HasDispHdr   bool
}

func ParseV7Core(el V7Element) V7Core {
	var c V7Core
	c.HasDispHdr = !v7NoDispHdr[el.Type]
	if len(el.Body) >= 24 {
		for i := 0; i < 6; i++ {
			c.BBox[i] = v7BBoxCoord(el.Body[i*4:])
		}
	}
	if c.HasDispHdr && len(el.Body) >= 32 {
		c.GraphicGroup = binary.LittleEndian.Uint16(el.Body[24:])
		c.AttrIndex = binary.LittleEndian.Uint16(el.Body[26:])
		c.Properties = binary.LittleEndian.Uint16(el.Body[28:])
		c.Style = el.Body[30] & 0x07
		c.Weight = el.Body[30] >> 3
		c.Color = el.Body[31]
	}
	return c
}

func (c V7Core) HasAttributes() bool { return c.Properties&0x0800 != 0 }

// AttrRegion returns the raw attribute/linkage tail of the element
// (GDAL DGNParseCore: start = attrIndex*2+28 in body coords, length =
// size − attrIndex*2 − 28); nil when the element has no attribute flag
// or the index points past the end.
func (c V7Core) AttrRegion(el V7Element) []byte {
	if !c.HasAttributes() {
		return nil
	}
	off := int(c.AttrIndex)*2 + 28
	if off > len(el.Body) {
		return nil
	}
	return el.Body[off:]
}

func v7PointSize(is3d bool) int {
	if is3d {
		return 12
	}
	return 8
}

func ReadV7Line(el V7Element, is3d bool) ([2]V7Point, error) {
	var out [2]V7Point
	ps := v7PointSize(is3d)
	if len(el.Body) < 32+2*ps {
		return out, fmt.Errorf("dgn/v7: line body %d too short", len(el.Body))
	}
	for i := 0; i < 2; i++ {
		o := 32 + i*ps
		out[i] = V7Point{
			X: V7Int32(el.Body[o:]),
			Y: V7Int32(el.Body[o+4:]),
		}
		if is3d {
			out[i].Z = V7Int32(el.Body[o+8:])
		}
	}
	return out, nil
}

func ReadV7MultiPoint(el V7Element, is3d bool) ([]V7Point, error) {
	if len(el.Body) < 34 {
		return nil, fmt.Errorf("dgn/v7: multipoint body %d too short", len(el.Body))
	}
	ps := v7PointSize(is3d)
	count := int(binary.LittleEndian.Uint16(el.Body[32:]))
	if count < 2 {
		return nil, fmt.Errorf("dgn/v7: multipoint count %d < 2", count)
	}
	if max := (el.Size() - 38) / ps; count > max {
		count = max
	}
	if count < 2 {
		return nil, fmt.Errorf("dgn/v7: multipoint trimmed below 2")
	}
	out := make([]V7Point, 0, count)
	for i := 0; i < count; i++ {
		o := 34 + i*ps
		p := V7Point{
			X: V7Int32(el.Body[o:]),
			Y: V7Int32(el.Body[o+4:]),
		}
		if is3d {
			p.Z = V7Int32(el.Body[o+8:])
		}
		out = append(out, p)
	}
	return out, nil
}

// V7Arc is the shared layout for DGNT_ARC(16) and DGNT_ELLIPSE(15):
// axes/origin are raw UOR (VAX doubles), angles in degrees,
// Quat components raw int32 (÷2^31 → unit quaternion).
type V7Arc struct {
	Start, Sweep       float64 // ARC only; Ellipse is fixed 0/360
	Primary, Secondary float64 // axis lengths, UOR
	Rotation           float64 // 2D: degrees CCW; 3D: 0 (use Quat)
	Quat               [4]int32
	Origin             [3]float64 // UOR
}

// ReadV7Arc decodes DGNT_ARC(16). Sweep is sign-magnitude (bit31 = sign);
// a raw sweep of 0 means a full circle (GDAL behavior).
func ReadV7Arc(el V7Element, is3d bool) (V7Arc, error) {
	var a V7Arc
	need := 76
	if is3d {
		need = 96
	}
	if len(el.Body) < need {
		return a, fmt.Errorf("dgn/v7: arc body %d < %d", len(el.Body), need)
	}
	a.Start = float64(V7Int32(el.Body[32:])) / 360000.0
	sw := V7Uint32(el.Body[36:])
	sweep := int32(sw & 0x7fffffff)
	if sw&0x80000000 != 0 {
		sweep = -sweep
	}
	if sweep == 0 {
		a.Sweep = 360
	} else {
		a.Sweep = float64(sweep) / 360000.0
	}
	a.Primary = V7Double(el.Body[40:])
	a.Secondary = V7Double(el.Body[48:])
	if is3d {
		for i := 0; i < 4; i++ {
			a.Quat[i] = V7Int32(el.Body[56+i*4:])
		}
		a.Origin = [3]float64{
			V7Double(el.Body[72:]),
			V7Double(el.Body[80:]),
			V7Double(el.Body[88:]),
		}
	} else {
		a.Rotation = float64(V7Int32(el.Body[56:])) / 360000.0
		a.Origin = [3]float64{V7Double(el.Body[60:]), V7Double(el.Body[68:])}
	}
	return a, nil
}

// ReadV7Ellipse decodes DGNT_ELLIPSE(15): same layout as arc minus the
// angle pair (Start=0, Sweep=360 by definition).
func ReadV7Ellipse(el V7Element, is3d bool) (V7Arc, error) {
	var a V7Arc
	need := 68
	if is3d {
		need = 88
	}
	if len(el.Body) < need {
		return a, fmt.Errorf("dgn/v7: ellipse body %d < %d", len(el.Body), need)
	}
	a.Start = 0
	a.Sweep = 360
	a.Primary = V7Double(el.Body[32:])
	a.Secondary = V7Double(el.Body[40:])
	if is3d {
		for i := 0; i < 4; i++ {
			a.Quat[i] = V7Int32(el.Body[48+i*4:])
		}
		a.Origin = [3]float64{
			V7Double(el.Body[64:]),
			V7Double(el.Body[72:]),
			V7Double(el.Body[80:]),
		}
	} else {
		a.Rotation = float64(V7Int32(el.Body[48:])) / 360000.0
		a.Origin = [3]float64{V7Double(el.Body[52:]), V7Double(el.Body[60:])}
	}
	return a, nil
}

// V7Text is DGNT_TEXT(17). LengthMult/HeightMult are raw UOR ints;
// use V7TCB.TextMult to reach master units (GDAL: raw × scale × 6/1000).
type V7Text struct {
	FontID, Justification  byte
	LengthMult, HeightMult int32
	Rotation               float64 // 2D degrees; 3D: 0 (use Quat)
	Quat                   [4]int32
	Origin                 [3]int32 // UOR (i32, unlike arc origins)
	String                 string
}

// ReadV7Text decodes DGNT_TEXT(17). num_chars is a byte at body54 (2D) /
// body70 (3D); the string follows at body56/body72. An FF,FD BOM switches
// to the packed UTF-16 variant (GDAL "experimental multibyte" path).
func ReadV7Text(el V7Element, is3d bool) (V7Text, error) {
	var t V7Text
	off, need := 56, 60
	nChar := 54
	if is3d {
		off, need, nChar = 72, 76, 70
	}
	if len(el.Body) < need {
		return t, fmt.Errorf("dgn/v7: text body %d < %d", len(el.Body), need)
	}
	t.FontID = el.Body[32]
	t.Justification = el.Body[33]
	t.LengthMult = V7Int32(el.Body[34:])
	t.HeightMult = V7Int32(el.Body[38:])
	if is3d {
		for i := 0; i < 4; i++ {
			t.Quat[i] = V7Int32(el.Body[42+i*4:])
		}
		t.Origin = [3]int32{
			V7Int32(el.Body[58:]),
			V7Int32(el.Body[62:]),
			V7Int32(el.Body[66:]),
		}
	} else {
		t.Rotation = float64(V7Int32(el.Body[42:])) / 360000.0
		t.Origin = [3]int32{V7Int32(el.Body[46:]), V7Int32(el.Body[50:])}
	}
	t.String = v7TextString(el.Body, off, int(el.Body[nChar]))
	return t, nil
}

func v7TextString(body []byte, off, n int) string {
	if off+2 <= len(body) && body[off] == 0xFF && body[off+1] == 0xFD {
		var out []byte
		for i := 0; i < n/2-1; i++ {
			p := off + 2 + i*2
			if p+2 > len(body) {
				break
			}
			w := binary.LittleEndian.Uint16(body[p:])
			if w < 256 {
				out = append(out, byte(w))
			} else {
				out = append(out, byte(w>>8), byte(w))
			}
		}
		return string(out)
	}
	if off >= len(body) {
		return ""
	}
	end := off + n
	if end > len(body) {
		end = len(body)
	}
	return string(body[off:end])
}

// V7TextNode is the header of DGNT_TEXT_NODE(7); the text strings live in
// subsequent elements (GDAL does not read them here either).
type V7TextNode struct {
	TotLength, NumElems uint16
	NodeNumber          uint16
	MaxLength, MaxUsed  byte
	FontID              byte
	Justification       byte
	LengthMult          int32
	HeightMult          int32
	Rotation            float64 // 2D degrees; 3D: 0 (use Quat)
	Quat                [4]int32
	Origin              [3]int32
}

// ReadV7TextNode decodes DGNT_TEXT_NODE(7).
func ReadV7TextNode(el V7Element, is3d bool) (V7TextNode, error) {
	var n V7TextNode
	need := 66
	if is3d {
		need = 82
	}
	if len(el.Body) < need {
		return n, fmt.Errorf("dgn/v7: text node body %d < %d", len(el.Body), need)
	}
	n.TotLength = binary.LittleEndian.Uint16(el.Body[32:])
	n.NumElems = binary.LittleEndian.Uint16(el.Body[34:])
	n.NodeNumber = binary.LittleEndian.Uint16(el.Body[36:])
	n.MaxLength = el.Body[38]
	n.MaxUsed = el.Body[39]
	n.FontID = el.Body[40]
	n.Justification = el.Body[41]
	n.LengthMult = V7Int32(el.Body[46:])
	n.HeightMult = V7Int32(el.Body[50:])
	if is3d {
		for i := 0; i < 4; i++ {
			n.Quat[i] = V7Int32(el.Body[54+i*4:])
		}
		n.Origin = [3]int32{
			V7Int32(el.Body[70:]),
			V7Int32(el.Body[74:]),
			V7Int32(el.Body[78:]),
		}
	} else {
		n.Rotation = float64(V7Int32(el.Body[54:])) / 360000.0
		n.Origin = [3]int32{V7Int32(el.Body[58:]), V7Int32(el.Body[62:])}
	}
	return n, nil
}

// V7Cone is DGNT_CONE(23), 3D only. Centers/radii are raw UOR VAX doubles
// (radii ×V7TCB.Scale → master; centers via V7TCB.ToMaster).
type V7Cone struct {
	Unknown          uint16
	Quat             [4]int32
	Center1, Center2 [3]float64
	Radius1, Radius2 float64
}

// ReadV7Cone decodes DGNT_CONE(23); the type only exists in 3D files
// (GDAL fails it in 2D).
func ReadV7Cone(el V7Element, is3d bool) (V7Cone, error) {
	var c V7Cone
	if !is3d {
		return c, fmt.Errorf("dgn/v7: cone requires 3D file")
	}
	if len(el.Body) < 114 {
		return c, fmt.Errorf("dgn/v7: cone body %d < 114", len(el.Body))
	}
	c.Unknown = binary.LittleEndian.Uint16(el.Body[32:])
	for i := 0; i < 4; i++ {
		c.Quat[i] = V7Int32(el.Body[34+i*4:])
	}
	c.Center1 = [3]float64{
		V7Double(el.Body[50:]),
		V7Double(el.Body[58:]),
		V7Double(el.Body[66:]),
	}
	c.Radius1 = V7Double(el.Body[74:])
	c.Center2 = [3]float64{
		V7Double(el.Body[82:]),
		V7Double(el.Body[90:]),
		V7Double(el.Body[98:]),
	}
	c.Radius2 = V7Double(el.Body[106:])
	return c, nil
}
