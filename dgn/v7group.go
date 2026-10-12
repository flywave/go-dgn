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
// Cell-type headers (2/34) group by SPAN instead of numelems: children are
// the following elements until Σ(size/2) == TotLength + 19 (the §9 formula,
// verified 223/223 cell headers + 115/115 shared defns on sample.dgn; GDAL
// does not group cells at all). A misaligned span degrades to childless.
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
		if IsV7ComplexType(el.Type) {
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
		if el.Type == 2 || el.Type == 34 {
			if kids, ok := v7CellSpanChildren(els, i-1); ok {
				for k := 0; k < kids; k++ {
					child, err := build()
					if err != nil {
						return node, err
					}
					node.Children = append(node.Children, child)
				}
			}
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

// v7CellSpanChildren returns the DIRECT child count of the cell-type header
// (2/34) at index hidx, validating the group span Σ(size/2) == TotLength+19
// (verified 223/223 cell headers + 115/115 shared defns on sample.dgn; GDAL
// does not group cells at all). Descends into nested groups so each direct
// child counts once. ok=false on misalignment → header treated childless.
func v7CellSpanChildren(els []V7Element, hidx int) (n int, ok bool) {
	el := els[hidx]
	if len(el.Body) < 34 {
		return 0, false
	}
	span := int(binary.LittleEndian.Uint16(el.Body[32:])) + 19
	acc := int(el.Words) + 2
	pos := hidx + 1
	for pos < len(els) && acc < span {
		sub, words, ok := v7GroupExtent(els, pos)
		if !ok {
			return 0, false
		}
		acc += words
		pos += sub
		n++
	}
	if acc != span {
		return 0, false
	}
	return n, true
}

// v7GroupExtent returns the element count and Σ(size/2) words of the group
// starting at index i (the element itself plus descendants). A complex or
// cell header with a broken group declaration degrades to childless (the
// following elements belong to the caller's group).
func v7GroupExtent(els []V7Element, i int) (n, words int, ok bool) {
	if i >= len(els) {
		return 0, 0, false
	}
	el := els[i]
	words = int(el.Words) + 2
	n = 1
	appendSub := func() bool {
		cn, cw, cok := v7GroupExtent(els, i+n)
		if !cok {
			return false
		}
		n += cn
		words += cw
		return true
	}
	if IsV7ComplexType(el.Type) {
		hdr, err := ReadV7ComplexHeader(el)
		if err != nil {
			return n, words, true
		}
		for k := 0; k < int(hdr.NumElems); k++ {
			if !appendSub() {
				return 0, 0, false
			}
		}
		return n, words, true
	}
	if (el.Type == 2 || el.Type == 34) && len(el.Body) >= 34 {
		span := int(binary.LittleEndian.Uint16(el.Body[32:])) + 19
		for i+n < len(els) && words < span {
			if !appendSub() {
				return 0, 0, false
			}
		}
		if words != span {
			return 1, int(el.Words) + 2, true // misaligned → childless
		}
	}
	return n, words, true
}
