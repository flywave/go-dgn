package dgn

import (
	"bytes"
	"encoding/binary"
	"testing"
)

func TestReadV7ComplexHeader(t *testing.T) {
	body := make([]byte, 40)
	binary.LittleEndian.PutUint16(body[32:], 159)
	binary.LittleEndian.PutUint16(body[34:], 4)
	h, err := ReadV7ComplexHeader(v7El(t, 12, body))
	if err != nil {
		t.Fatal(err)
	}
	if h.TotLength != 159 || h.NumElems != 4 || h.SurfType != 0 || h.BoundElems != 0 {
		t.Fatalf("%+v", h)
	}

	// 18/19 carry surface/solid fields; boundelms stored +1
	body[36] = 3 // surftype
	body[37] = 1 // boundelms raw → 2
	h19, err := ReadV7ComplexHeader(v7El(t, 19, body))
	if err != nil {
		t.Fatal(err)
	}
	if h19.SurfType != 3 || h19.BoundElems != 2 || h19.TotLength != 159 {
		t.Fatalf("%+v", h19)
	}

	if _, err := ReadV7ComplexHeader(v7El(t, 3, body)); err == nil {
		t.Fatal("non-complex type must fail")
	}
	if _, err := ReadV7ComplexHeader(v7El(t, 12, make([]byte, 20))); err == nil {
		t.Fatal("short body must fail")
	}
}

// v7Hdr builds a complex-header element with the given type/tot/num.
func v7Hdr(t *testing.T, typ byte, tot, num uint16) V7Element {
	t.Helper()
	body := make([]byte, 40)
	binary.LittleEndian.PutUint16(body[32:], tot)
	binary.LittleEndian.PutUint16(body[34:], num)
	return v7El(t, typ, body)
}

func TestGroupV7ElementsNested(t *testing.T) {
	// chain12(2 children: line + shape14 with 1 child line) + trailing top-level line
	chain := v7Hdr(t, 12, 999, 2)
	inner := v7El(t, 3, make([]byte, 8))
	shape := v7Hdr(t, 14, 888, 1)
	innerChild := v7El(t, 3, make([]byte, 8))
	top := v7El(t, 3, make([]byte, 8))
	forest, err := GroupV7Elements([]V7Element{chain, inner, shape, innerChild, top})
	if err != nil {
		t.Fatal(err)
	}
	if len(forest) != 2 {
		t.Fatalf("top-level=%d", len(forest))
	}
	n := forest[0]
	if n.Element.Type != 12 || len(n.Children) != 2 {
		t.Fatalf("chain children=%d", len(n.Children))
	}
	if n.Children[0].Element.Type != 3 {
		t.Fatalf("child0=%d", n.Children[0].Element.Type)
	}
	sh := n.Children[1]
	if sh.Element.Type != 14 || len(sh.Children) != 1 || sh.Children[0].Element.Type != 3 {
		t.Fatalf("nested shape=%+v", sh)
	}
	if forest[1].Element.Type != 3 || len(forest[1].Children) != 0 {
		t.Fatalf("trailing=%+v", forest[1])
	}
	// subtree words = Σ size/2 (header body40 → words20 → 22; line body8 → 6)
	if w := n.subtreeWords(); w != 22+6+22+6 {
		t.Fatalf("subtree words=%d", w)
	}
}

func TestGroupV7ElementsTruncated(t *testing.T) {
	chain := v7Hdr(t, 12, 100, 3) // needs 3 children, only 1 follows
	if _, err := GroupV7Elements([]V7Element{chain, v7El(t, 3, make([]byte, 8))}); err == nil {
		t.Fatal("must fail on truncated group")
	}
}

func TestGroupV7ElementsSample(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	forest, err := GroupV7Elements(els)
	if err != nil {
		t.Fatal(err)
	}

	total, groups := 0, 0
	var first *V7Node
	var walk func(nodes []V7Node)
	walk = func(nodes []V7Node) {
		for i := range nodes {
			n := &nodes[i]
			total++
			if IsV7ComplexType(n.Element.Type) {
				groups++
				hdr, err := ReadV7ComplexHeader(n.Element)
				if err != nil {
					t.Fatalf("header @%d: %v", n.Element.Offset, err)
				}
				// span: header + whole subtree, in size/2 words == tot+19
				if w := n.subtreeWords(); w != int(hdr.TotLength)+19 {
					t.Fatalf("group @%d tot=%d subtree words=%d (want %d)",
						n.Element.Offset, hdr.TotLength, w, hdr.TotLength+19)
				}
				if first == nil {
					first = n
				}
			}
			walk(n.Children)
		}
	}
	walk(forest)

	if total != len(els) {
		t.Fatalf("conservation: walked %d of %d", total, len(els))
	}
	if groups != 19 {
		t.Fatalf("groups=%d (sample has 16 chains + 3 shapes)", groups)
	}
	// golden first group @13128: chain of [line, bspline curve, knot, poles]
	if first == nil || first.Element.Offset != 13128 {
		t.Fatalf("first group=%+v", first)
	}
	if len(first.Children) != 4 {
		t.Fatalf("children=%d", len(first.Children))
	}
	want := []byte{3, 27, 26, 21}
	for i, c := range first.Children {
		if c.Element.Type != want[i] {
			t.Fatalf("child %d type=%d want %d", i, c.Element.Type, want[i])
		}
	}
}

func TestV7AttrRegionSynthetic(t *testing.T) {
	body := make([]byte, 64)
	binary.LittleEndian.PutUint16(body[26:], 10)     // attrIndex → off=48
	binary.LittleEndian.PutUint16(body[28:], 0x0800) // properties: attributes
	for i := 48; i < 64; i++ {
		body[i] = byte(i)
	}
	el := V7Element{Type: 3, Words: uint16(len(body) / 2), Body: body}
	c := ParseV7Core(el)
	if !c.HasAttributes() || c.AttrIndex != 10 {
		t.Fatalf("%+v", c)
	}
	region := c.AttrRegion(el)
	if len(region) != 16 || region[0] != 48 || region[15] != 63 {
		t.Fatalf("region=%v", region)
	}

	// no attribute flag → nil
	binary.LittleEndian.PutUint16(body[28:], 0)
	if r := ParseV7Core(el).AttrRegion(el); r != nil {
		t.Fatalf("want nil, got %v", r)
	}
	// index past end → nil
	binary.LittleEndian.PutUint16(body[28:], 0x0800)
	binary.LittleEndian.PutUint16(body[26:], 1000)
	if r := ParseV7Core(el).AttrRegion(el); r != nil {
		t.Fatalf("want nil, got %v", r)
	}
}

func TestV7AttrRegionSample(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	attrCount := 0
	var golden V7Element
	for _, e := range els {
		c := ParseV7Core(e)
		if !c.HasAttributes() {
			if r := c.AttrRegion(e); r != nil {
				t.Fatalf("element @%d: region without flag", e.Offset)
			}
			continue
		}
		r := c.AttrRegion(e)
		if len(r) == 0 {
			t.Fatalf("element @%d: empty region", e.Offset)
		}
		attrCount++
		if e.Offset == 10546 {
			golden = e
		}
	}
	if attrCount < 10000 {
		t.Fatalf("attr elements=%d", attrCount)
	}
	// golden ellipse @10546: idx=30 → body88, 16 bytes, head = A951 delta record
	if golden.Body == nil {
		t.Fatal("golden element @10546 missing")
	}
	want := []byte{0x07, 0x10, 0xa9, 0x51, 0x04, 0x00, 0x9e, 0x2e, 0x0b, 0xdc, 0x00, 0x00, 0x00, 0x00, 0xf5, 0x23}
	got := ParseV7Core(golden).AttrRegion(golden)
	if !bytes.Equal(got, want) {
		t.Fatalf("golden region=%x want %x", got, want)
	}
}
