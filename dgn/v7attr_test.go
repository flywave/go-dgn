package dgn

import (
	"encoding/binary"
	"testing"
)

func TestReadV7ColorTableSynthetic(t *testing.T) {
	body := make([]byte, 802)
	binary.LittleEndian.PutUint16(body[32:], 0x1234) // screen flag
	copy(body[34:], []byte{1, 2, 3})                 // entry 255 first
	for i := 0; i < 255; i++ {
		body[37+i*3] = byte(i)
		body[38+i*3] = byte(i + 1)
		body[39+i*3] = byte(i + 2)
	}
	el := V7Element{Level: 1, Type: 5, Words: uint16(len(body) / 2), Body: body}
	ct, err := ReadV7ColorTable(el)
	if err != nil {
		t.Fatal(err)
	}
	if ct.ScreenFlag != 0x1234 || ct.Colors[255] != [3]byte{1, 2, 3} {
		t.Fatalf("%+v", ct)
	}
	if ct.Colors[0] != [3]byte{0, 1, 2} || ct.Colors[254] != [3]byte{254, 255, 0} {
		t.Fatalf("c0=%v c254=%v", ct.Colors[0], ct.Colors[254])
	}

	// gate: wrong level / wrong type / short body
	if _, err := ReadV7ColorTable(V7Element{Level: 2, Type: 5, Body: body}); err == nil {
		t.Fatal("level 2 must fail")
	}
	if _, err := ReadV7ColorTable(V7Element{Level: 1, Type: 3, Body: body}); err == nil {
		t.Fatal("type 3 must fail")
	}
	if _, err := ReadV7ColorTable(V7Element{Level: 1, Type: 5, Body: make([]byte, 100)}); err == nil {
		t.Fatal("short body must fail")
	}
}

func TestSampleType5IsNotColorTable(t *testing.T) {
	// sample's lone type5 is level 2 group data: must NOT decode as color table
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	found := false
	for _, e := range els {
		if e.Type != 5 {
			continue
		}
		found = true
		if e.Level == 1 {
			t.Fatalf("expected sample type5 at non-CT level, got level 1")
		}
		if _, err := ReadV7ColorTable(e); err == nil {
			t.Fatalf("level %d type5 must be rejected by color table reader", e.Level)
		}
	}
	if !found {
		t.Fatal("sample has no type5 element")
	}
}
