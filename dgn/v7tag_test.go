package dgn

import (
	"encoding/binary"
	"testing"
)

func TestReadV7TagValue(t *testing.T) {
	// string variant
	body := make([]byte, 160)
	binary.LittleEndian.PutUint32(body[64:], 0x11223344) // tagSet (plain LE)
	binary.LittleEndian.PutUint16(body[68:], 7)          // index
	binary.LittleEndian.PutUint16(body[70:], 1)          // type=string
	binary.LittleEndian.PutUint16(body[146:], 3)         // length
	copy(body[150:], "hi")
	tv, err := ReadV7TagValue(V7Element{Type: 37, Words: 80, Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if tv.TagType != 1 || tv.TagSet != 0x11223344 || tv.TagIndex != 7 ||
		tv.TagLength != 3 || tv.String != "hi" {
		t.Fatalf("%+v", tv)
	}

	// int variant (plain LE per GDAL)
	binary.LittleEndian.PutUint16(body[70:], 3)
	binary.LittleEndian.PutUint32(body[150:], 0x89ABCDEF)
	tv3, err := ReadV7TagValue(V7Element{Type: 37, Words: 80, Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if uint32(tv3.Int) != 0x89ABCDEF {
		t.Fatalf("int=%d", tv3.Int)
	}

	// real variant (VAX double)
	binary.LittleEndian.PutUint16(body[70:], 4)
	V7PutDouble(body[150:], -1234.5)
	tv4, err := ReadV7TagValue(V7Element{Type: 37, Words: 80, Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if tv4.Real != -1234.5 {
		t.Fatalf("real=%v", tv4.Real)
	}

	if _, err := ReadV7TagValue(V7Element{Type: 3, Body: body}); err == nil {
		t.Fatal("wrong type must fail")
	}
	if _, err := ReadV7TagValue(V7Element{Type: 37, Body: make([]byte, 100)}); err == nil {
		t.Fatal("short body must fail")
	}
	// unterminated string
	binary.LittleEndian.PutUint16(body[70:], 1)
	for i := 150; i < len(body); i++ {
		body[i] = 'x'
	}
	if _, err := ReadV7TagValue(V7Element{Type: 37, Words: 80, Body: body}); err == nil {
		t.Fatal("unterminated string must fail")
	}
}

// v7TagSetBody builds a level-24 tag set with defs of types 1/3/4/9.
func v7TagSetBody(t *testing.T) (V7Element, []byte) {
	t.Helper()
	// name "SET" at body44; defs start body44+3+2 = 49
	buf := make([]byte, 256)
	buf[44], buf[45], buf[46] = 'S', 'E', 'T' // NUL at 47, pad at 48
	off := 49
	putStr := func(s string) {
		copy(buf[off:], s)
		off += len(s) + 1
	}
	putStr("FOO") // def0 name
	binary.LittleEndian.PutUint16(buf[off:], 1)
	off += 2
	putStr("prompt0")
	binary.LittleEndian.PutUint16(buf[off:], 1) // type string
	off += 2 + 5
	putStr("bar")
	putStr("BAZ") // def1
	binary.LittleEndian.PutUint16(buf[off:], 2)
	off += 2
	putStr("p1")
	binary.LittleEndian.PutUint16(buf[off:], 3) // int
	off += 2 + 5
	binary.LittleEndian.PutUint32(buf[off:], 42)
	off += 4
	putStr("QUX") // def2
	binary.LittleEndian.PutUint16(buf[off:], 3)
	off += 2
	putStr("p2")
	binary.LittleEndian.PutUint16(buf[off:], 4) // real
	off += 2 + 5
	V7PutDouble(buf[off:], 2.5)
	off += 8
	putStr("QUUX") // def3, unknown type → +4
	binary.LittleEndian.PutUint16(buf[off:], 4)
	off += 2
	putStr("p3")
	binary.LittleEndian.PutUint16(buf[off:], 9)
	off += 2 + 5
	binary.LittleEndian.PutUint32(buf[off:], 0)
	off += 4

	binary.LittleEndian.PutUint16(buf[40:], 4) // tagCount
	binary.LittleEndian.PutUint16(buf[42:], 5) // flags
	// pad to word alignment, then attach attribute region (magic → id=99)
	if off%2 == 1 {
		off++
	}
	body := buf[:off]
	idx := (len(body) - 28) / 2 // attr start = idx*2+28 = len(body)
	attr := []byte{0x03, 0x10, 0x2f, 0x7d, 99, 0, 0, 0}
	binary.LittleEndian.PutUint16(body[26:], uint16(idx))
	binary.LittleEndian.PutUint16(body[28:], 0x0800)
	el := V7Element{Level: 24, Type: 66, Words: uint16((len(body) + len(attr)) / 2),
		Body: append(append([]byte{}, body...), attr...)}
	return el, attr
}

func TestReadV7TagSet(t *testing.T) {
	el, _ := v7TagSetBody(t)
	ts, err := ReadV7TagSet(el)
	if err != nil {
		t.Fatal(err)
	}
	if ts.Name != "SET" || ts.Flags != 5 || ts.TagSetID != 99 {
		t.Fatalf("%+v", ts)
	}
	if len(ts.Defs) != 4 {
		t.Fatalf("defs=%d", len(ts.Defs))
	}
	d := ts.Defs
	if d[0].Name != "FOO" || d[0].ID != 1 || d[0].Prompt != "prompt0" ||
		d[0].Type != 1 || d[0].DefaultString != "bar" {
		t.Fatalf("def0=%+v", d[0])
	}
	if d[1].Type != 3 || d[1].DefaultInt != 42 {
		t.Fatalf("def1=%+v", d[1])
	}
	if d[2].Type != 4 || d[2].DefaultReal != 2.5 {
		t.Fatalf("def2=%+v", d[2])
	}
	if d[3].Type != 9 || d[3].Name != "QUUX" {
		t.Fatalf("def3=%+v", d[3])
	}

	// gates
	if _, err := ReadV7TagSet(V7Element{Level: 1, Type: 66, Body: el.Body}); err == nil {
		t.Fatal("wrong level must fail")
	}
	if _, err := ReadV7TagSet(V7Element{Level: 24, Type: 3, Body: el.Body}); err == nil {
		t.Fatal("wrong type must fail")
	}
	// count overrun
	bad, _ := v7TagSetBody(t)
	binary.LittleEndian.PutUint16(bad.Body[40:], 50)
	if _, err := ReadV7TagSet(bad); err == nil {
		t.Fatal("overrun must fail")
	}
}
