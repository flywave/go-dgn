package dgn

import (
	"encoding/binary"
	"fmt"
)

// V7TagValue is DGNT_TAG_VALUE(37) (GDAL dgnread L832-863).
// Note: TagSet is a plain little-endian u32 in GDAL (memcpy+CPL_LSBPTR32),
// unlike the DGN halfword-swapped i32 elsewhere — preserved as-is.
type V7TagValue struct {
	TagType   uint16 // 1=string, 3=int, 4=real
	TagSet    uint32 // plain LE
	TagIndex  uint16
	TagLength uint16
	String    string
	Int       int32 // plain LE (GDAL CPL_LSBPTR32)
	Real      float64
}

// ReadV7TagValue decodes type 37.
func ReadV7TagValue(el V7Element) (V7TagValue, error) {
	var t V7TagValue
	if el.Type != 37 {
		return t, fmt.Errorf("dgn/v7: not a tag value (type %d)", el.Type)
	}
	if len(el.Body) < 148 {
		return t, fmt.Errorf("dgn/v7: tag value body %d < 148", len(el.Body))
	}
	t.TagSet = binary.LittleEndian.Uint32(el.Body[64:])
	t.TagIndex = binary.LittleEndian.Uint16(el.Body[68:])
	t.TagType = binary.LittleEndian.Uint16(el.Body[70:])
	t.TagLength = binary.LittleEndian.Uint16(el.Body[146:])
	switch t.TagType {
	case 1:
		s, ok := v7NULString(el.Body, 150)
		if !ok {
			return t, fmt.Errorf("dgn/v7: tag string not terminated")
		}
		t.String = s
	case 3:
		if len(el.Body) < 154 {
			return t, fmt.Errorf("dgn/v7: tag value body %d < 154", len(el.Body))
		}
		t.Int = int32(binary.LittleEndian.Uint32(el.Body[150:]))
	case 4:
		if len(el.Body) < 158 {
			return t, fmt.Errorf("dgn/v7: tag value body %d < 158", len(el.Body))
		}
		t.Real = V7Double(el.Body[150:])
	}
	return t, nil
}

// v7NULString reads a NUL-terminated string at body offset off, bounded
// by the element end.
func v7NULString(body []byte, off int) (string, bool) {
	if off > len(body) {
		return "", false
	}
	for i := off; i < len(body); i++ {
		if body[i] == 0 {
			return string(body[off:i]), true
		}
	}
	return "", false
}

// V7TagDef is one tag definition inside a tag set.
type V7TagDef struct {
	Name          string
	ID            uint16
	Prompt        string
	Type          uint16 // 1=string 3=int 4/5=…
	DefaultString string
	DefaultInt    int32
	DefaultReal   float64
}

// V7TagSet is DGNT_APPLICATION_ELEM(66) at level 24 (GDAL DGNParseTagSet).
type V7TagSet struct {
	Flags    uint16
	Name     string
	TagSetID int16 // -1 when the attribute magic 03 10 2f 7d is absent
	Defs     []V7TagDef
}

// ReadV7TagSet decodes type 66 level 24.
func ReadV7TagSet(el V7Element) (V7TagSet, error) {
	var ts V7TagSet
	if el.Type != 66 || el.Level != 24 {
		return ts, fmt.Errorf("dgn/v7: not a tag set (type %d level %d)", el.Type, el.Level)
	}
	if len(el.Body) < 46 {
		return ts, fmt.Errorf("dgn/v7: tag set body %d < 46", len(el.Body))
	}
	ts.TagSetID = -1
	ts.Flags = binary.LittleEndian.Uint16(el.Body[42:])
	name, ok := v7NULString(el.Body, 44)
	if !ok {
		return ts, fmt.Errorf("dgn/v7: tag set name not terminated")
	}
	ts.Name = name

	// tag set number lives in the attribute region (magic 03 10 2f 7d)
	c := ParseV7Core(el)
	region := c.AttrRegion(el)
	if len(region) >= 8 && region[0] == 0x03 && region[1] == 0x10 &&
		region[2] == 0x2f && region[3] == 0x7d {
		ts.TagSetID = int16(binary.LittleEndian.Uint16(region[4:]))
	}

	// first definition: after name + NUL + 1 pad byte (GDAL nDataOffset)
	off := 44 + len(name) + 2
	count := int(binary.LittleEndian.Uint16(el.Body[40:]))
	for i := 0; i < count; i++ {
		var def V7TagDef
		dn, ok := v7NULString(el.Body, off)
		if !ok {
			return ts, fmt.Errorf("dgn/v7: tag def %d name overrun", i)
		}
		def.Name = dn
		off += len(dn) + 1
		if off+2 > len(el.Body) {
			return ts, fmt.Errorf("dgn/v7: tag def %d id overrun", i)
		}
		def.ID = binary.LittleEndian.Uint16(el.Body[off:])
		off += 2
		pr, ok := v7NULString(el.Body, off)
		if !ok {
			return ts, fmt.Errorf("dgn/v7: tag def %d prompt overrun", i)
		}
		def.Prompt = pr
		off += len(pr) + 1
		if off+2+5 > len(el.Body) {
			return ts, fmt.Errorf("dgn/v7: tag def %d type overrun", i)
		}
		def.Type = binary.LittleEndian.Uint16(el.Body[off:])
		off += 2 + 5 // type + 5 zero bytes
		switch def.Type {
		case 1:
			s, ok := v7NULString(el.Body, off)
			if !ok {
				return ts, fmt.Errorf("dgn/v7: tag def %d default string overrun", i)
			}
			def.DefaultString = s
			off += len(s) + 1
		case 3, 5:
			if off+4 > len(el.Body) {
				return ts, fmt.Errorf("dgn/v7: tag def %d default int overrun", i)
			}
			def.DefaultInt = int32(binary.LittleEndian.Uint32(el.Body[off:]))
			off += 4
		case 4:
			if off+8 > len(el.Body) {
				return ts, fmt.Errorf("dgn/v7: tag def %d default real overrun", i)
			}
			def.DefaultReal = V7Double(el.Body[off:])
			off += 8
		default:
			off += 4
		}
		ts.Defs = append(ts.Defs, def)
	}
	return ts, nil
}
