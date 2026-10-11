package dgn

import (
	"encoding/binary"
	"math/rand"
	"testing"
)

// The robustness tests feed deterministic pseudo-random and mutated-fixture
// bytes through every v7/v8 entry point: parsing must return errors, never
// panic. Seeds are fixed for reproducibility.

func mustNoPanic(t *testing.T, what string, iter int, fn func()) {
	t.Helper()
	defer func() {
		if r := recover(); r != nil {
			t.Fatalf("panic in %s (iter %d): %v", what, iter, r)
		}
	}()
	fn()
}

func TestParseV8PanicFree(t *testing.T) {
	rng := rand.New(rand.NewSource(0x0D68))

	// random headers + random spaces through ParseElement
	for i := 0; i < 800; i++ {
		space := make([]byte, rng.Intn(300))
		rng.Read(space)
		hb := make([]byte, HeaderSize)
		rng.Read(hb)
		h, err := ParseHeader(hb)
		if err != nil {
			continue
		}
		e := Entry{Index: 0, Pos: 0, Header: h}
		mustNoPanic(t, "ParseElement/random", i, func() {
			_, _ = ParseElement(space, e)
		})
	}

	// mutated/truncated valid fixture through ParseAll (multi-entry too)
	hdr := buildHeader(Header{Type: 3, Flag: FlagDisplayHeader, B: 12, C: 12, ID: 1})
	disp := make([]byte, DisplayHeaderSize)
	binary.LittleEndian.PutUint16(disp[8:], 1<<11)
	valid := join(hdr, disp, f64le(1, 2, 3, 4, 5, 6))
	for i := 0; i < 600; i++ {
		mut := append([]byte(nil), valid...)
		for k := 0; k < 1+rng.Intn(3); k++ {
			mut[rng.Intn(len(mut))] = byte(rng.Intn(256))
		}
		if rng.Intn(4) == 0 {
			mut = mut[:rng.Intn(len(mut)+1)]
		}
		offsets := []uint32{0}
		if rng.Intn(3) == 0 && len(mut) > HeaderSize {
			mid := uint32(1 + rng.Intn(len(mut)-1))
			if mid > 0 {
				offsets = []uint32{0, mid}
			}
		}
		mustNoPanic(t, "ParseAll/mutated", i, func() {
			_, _ = ParseAll(mut, Dir{Base: 0, Offsets: offsets})
		})
	}
}

// v7ElementReaders exercises every v7 body reader; each entry must fail
// cleanly on short/garbage bodies.
func v7ElementReaders() []struct {
	name string
	fn   func(V7Element, bool) error
} {
	return []struct {
		name string
		fn   func(V7Element, bool) error
	}{
		{"line", func(e V7Element, d bool) error { _, err := ReadV7Line(e, d); return err }},
		{"lineF", func(e V7Element, d bool) error { _, err := ReadV7LineF(e, d); return err }},
		{"multipoint", func(e V7Element, d bool) error { _, err := ReadV7MultiPoint(e, d); return err }},
		{"multipointF", func(e V7Element, d bool) error { _, err := ReadV7MultiPointF(e, d); return err }},
		{"arc", func(e V7Element, d bool) error { _, err := ReadV7Arc(e, d); return err }},
		{"ellipse", func(e V7Element, d bool) error { _, err := ReadV7Ellipse(e, d); return err }},
		{"text", func(e V7Element, d bool) error { _, err := ReadV7Text(e, d); return err }},
		{"textnode", func(e V7Element, d bool) error { _, err := ReadV7TextNode(e, d); return err }},
		{"cone", func(e V7Element, d bool) error { _, err := ReadV7Cone(e, d); return err }},
		{"cell", func(e V7Element, d bool) error { _, err := ReadV7CellHeader(e, d); return err }},
		{"celllib", func(e V7Element, d bool) error { _, err := ReadV7CellLibrary(e); return err }},
		{"bsc", func(e V7Element, d bool) error { _, err := ReadV7BSplineCurveHeader(e); return err }},
		{"bss", func(e V7Element, d bool) error { _, err := ReadV7BSplineSurfaceHeader(e); return err }},
		{"kw", func(e V7Element, d bool) error { _, err := ReadV7KnotWeights(e); return err }},
		{"boundary", func(e V7Element, d bool) error { _, err := ReadV7Boundary(e); return err }},
		{"tagvalue", func(e V7Element, d bool) error { _, err := ReadV7TagValue(e); return err }},
		{"tagset", func(e V7Element, d bool) error { _, err := ReadV7TagSet(e); return err }},
		{"tcb", func(e V7Element, d bool) error { _, err := ParseV7TCB(e); return err }},
		{"sharedcell", func(e V7Element, d bool) error { _, err := ReadV7SharedCellDefn(e); return err }},
		{"sharedcellref", func(e V7Element, d bool) error { _, err := ReadV7SharedCellRef(e); return err }},
		{"colortable", func(e V7Element, d bool) error { _, err := ReadV7ColorTable(e); return err }},
	}
}

func TestV7BodyReadersPanicFree(t *testing.T) {
	rng := rand.New(rand.NewSource(0xC0FFEE))
	readers := v7ElementReaders()
	types := []byte{1, 2, 3, 4, 5, 7, 9, 15, 16, 17, 19, 23, 24, 25, 26, 27, 34, 37, 66}
	for i := 0; i < 400; i++ {
		body := make([]byte, rng.Intn(200))
		rng.Read(body)
		typ := types[rng.Intn(len(types))]
		lvl := byte(rng.Intn(64))
		el := V7Element{Level: lvl, Type: typ, Words: uint16(len(body) / 2), Body: body}
		for _, rd := range readers {
			is3d := rng.Intn(2) == 0
			mustNoPanic(t, "v7/"+rd.name, i, func() {
				_ = rd.fn(el, is3d)
			})
		}
	}
}

func TestV7FrameAndDocPanicFree(t *testing.T) {
	rng := rand.New(rand.NewSource(0xF00DFACE))
	magic := []byte{0xC8, 0x09, 0xFE, 0x02}

	// random tails behind a valid magic
	for i := 0; i < 300; i++ {
		buf := append(append([]byte{}, magic...), make([]byte, rng.Intn(400))...)
		rng.Read(buf[4:])
		mustNoPanic(t, "ReadV7Elements/random", i, func() {
			_, _ = ReadV7Elements(buf)
		})
		mustNoPanic(t, "ParseV7Document/random", i, func() {
			_, _ = ParseV7Document(buf)
		})
	}

	// mutated minimal valid document
	valid := buildMinimalV7Doc()
	for i := 0; i < 300; i++ {
		mut := append([]byte(nil), valid...)
		for k := 0; k < 1+rng.Intn(3); k++ {
			mut[rng.Intn(len(mut))] = byte(rng.Intn(256))
		}
		if rng.Intn(4) == 0 {
			mut = mut[:rng.Intn(len(mut)+1)]
		}
		mustNoPanic(t, "ParseV7Document/mutated", i, func() {
			_, _ = ParseV7Document(mut)
		})
		mustNoPanic(t, "ReadV7Elements/mutated", i, func() {
			_, _ = ReadV7Elements(mut)
		})
	}
}

// buildMinimalV7Doc: magic+zero TCB (1532B) + one 3D LINE + EOF.
func buildMinimalV7Doc() []byte {
	doc := []byte{0xC8, 0x09, 0xFE, 0x02}
	doc = append(doc, make([]byte, 1532)...)
	doc = append(doc, 0x41, 0x03, 28, 0)
	doc = append(doc, make([]byte, 56)...)
	doc = append(doc, 0xFF, 0xFF)
	return doc
}

func TestV7GroupPanicFree(t *testing.T) {
	rng := rand.New(rand.NewSource(0x600D))
	types := []byte{3, 7, 12, 14, 18, 19, 21, 23, 27, 66}
	for i := 0; i < 300; i++ {
		n := 1 + rng.Intn(20)
		els := make([]V7Element, n)
		for j := range els {
			body := make([]byte, 40)
			rng.Read(body)
			binary.LittleEndian.PutUint16(body[34:], uint16(rng.Intn(40))) // numelems
			els[j] = V7Element{
				Level: 1, Type: types[rng.Intn(len(types))],
				Words: uint16(len(body) / 2), Body: body,
			}
		}
		mustNoPanic(t, "GroupV7Elements", i, func() {
			_, _ = GroupV7Elements(els)
		})
	}
}
