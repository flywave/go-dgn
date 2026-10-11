package dgn

import (
	"encoding/binary"
	"fmt"
)

// IsV7ComplexType reports whether the type is a complex-group header
// (GDAL DGNST_COMPLEX_HEADER set: chain/shape/surface/solid).
func IsV7ComplexType(t byte) bool {
	return t == 12 || t == 14 || t == 18 || t == 19
}

// V7ComplexHeader is the prefix of types 12/14/18/19.
// TotLength: group span in words excluding the first 19 words of the
// header (span_words = TotLength + 19 = Σ size/2 over the whole group).
type V7ComplexHeader struct {
	TotLength  uint16
	NumElems   uint16
	SurfType   byte // 18/19 only
	BoundElems byte // 18/19 only (stored +1)
}

// ReadV7ComplexHeader decodes a complex header element (GDAL dgnread
// L818-830 / L927-941).
func ReadV7ComplexHeader(el V7Element) (V7ComplexHeader, error) {
	var h V7ComplexHeader
	if !IsV7ComplexType(el.Type) {
		return h, fmt.Errorf("dgn/v7: type %d is not a complex header", el.Type)
	}
	need := 36
	if el.Type == 18 || el.Type == 19 {
		need = 38
	}
	if len(el.Body) < need {
		return h, fmt.Errorf("dgn/v7: complex header body %d < %d", len(el.Body), need)
	}
	h.TotLength = binary.LittleEndian.Uint16(el.Body[32:])
	h.NumElems = binary.LittleEndian.Uint16(el.Body[34:])
	if need == 38 {
		h.SurfType = el.Body[36]
		h.BoundElems = el.Body[37] + 1
	}
	return h, nil
}

// V7Node is an element together with its subtree when it is a complex
// header (children = the following NumElems elements, each recursively
// consuming its own subtree — GDAL/OGR ogrdgnlayer.cpp L730 semantics).
type V7Node struct {
	Element  V7Element
	Children []V7Node
}

func (n V7Node) subtreeWords() int {
	w := n.Element.Size() / 2
	for i := range n.Children {
		w += n.Children[i].subtreeWords()
	}
	return w
}

// GroupV7Elements nests children under complex headers in a single forward
// pass over the flat element list. Non-header elements are top-level nodes.
func GroupV7Elements(els []V7Element) ([]V7Node, error) {
	i := 0
	var build func() (V7Node, error)
	build = func() (V7Node, error) {
		if i >= len(els) {
			return V7Node{}, fmt.Errorf("dgn/v7: unexpected end of elements")
		}
		el := els[i]
		i++
		node := V7Node{Element: el}
		if !IsV7ComplexType(el.Type) {
			return node, nil
		}
		hdr, err := ReadV7ComplexHeader(el)
		if err != nil {
			return node, err
		}
		for k := 0; k < int(hdr.NumElems); k++ {
			if i >= len(els) {
				return node, fmt.Errorf("dgn/v7: complex group @%d needs %d children, only %d elements left",
					el.Offset, hdr.NumElems, len(els)-(i))
			}
			child, err := build()
			if err != nil {
				return node, err
			}
			node.Children = append(node.Children, child)
		}
		return node, nil
	}
	out := make([]V7Node, 0, len(els))
	for i < len(els) {
		n, err := build()
		if err != nil {
			return nil, err
		}
		out = append(out, n)
	}
	return out, nil
}
