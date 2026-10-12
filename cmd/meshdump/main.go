// meshdump analyzes real v8 DGN samples: per-mesh (105) Matrix children
// with FaceLoops index-layout validation, SharedCell(34/35) fields, and
// Solid/Surface(18/19) adjacency — evidence for pinning the D109/D110
// residuals (see analysis/03-dgn/findings.md).
package main

import (
	"fmt"
	"os"

	"github.com/flywave/go-dgn/dgn"
	"github.com/flywave/go-dgn/dgn/element"
)

func main() {
	for _, p := range os.Args[1:] {
		fmt.Printf("=== %s\n", p)
		f, err := dgn.Open(p)
		if err != nil {
			fmt.Printf("  open: %v\n", err)
			continue
		}
		doc, err := f.V8()
		if err != nil {
			fmt.Printf("  v8: %v\n", err)
			continue
		}
		for _, m := range doc.Models {
			dumpModel(m)
		}
	}
}

func dumpModel(m *dgn.V8Model) {
	els := append(append([]dgn.Parsed{}, m.Elements...), m.Control...)
	if len(els) == 0 {
		return
	}
	fmt.Printf("--- model %q (%d elements)\n", m.Name, len(m.Elements))
	isMatrix := func(t uint16) bool { return t == 101 || t == 102 || t == 103 }
	for i, el := range els {
		switch el.Record.Type {
		case 105:
			dumpMesh(els, i, isMatrix)
		case 18, 19:
			fmt.Printf("  [%d] type %d id=%d complex=%v — next:", i, el.Record.Type, el.Record.ID, el.Record.Complex)
			for j := i + 1; j < len(els) && j <= i+4; j++ {
				fmt.Printf(" t%d(cx=%v)", els[j].Record.Type, els[j].Record.Complex)
			}
			fmt.Println()
			// raw flag words of the head and its followers (Entry.Header)
			fmt.Printf("      head flag=%#x", el.Entry.Header.Flag)
			for j := i + 1; j < len(els) && j <= i+4; j++ {
				fmt.Printf(" f%#x", els[j].Entry.Header.Flag)
			}
			fmt.Println()
		case 34, 35:
			dumpSharedCell(i, el)
			fmt.Printf("      complex=%v\n", el.Record.Complex)
		}
	}
}

// dumpMesh prints one mesh's Matrix child run and validates the pinned
// face layout: 101 headers carry IndexFamily (even=double data, odd=index
// table; 2=positions stride 3) and SizeOfRow (values per entry); odd-family
// 102 streams are zero-terminated 1-based vertex-index face lists whose
// sign bit marks edge visibility.
func dumpMesh(els []dgn.Parsed, i int, isMatrix func(uint16) bool) {
	el := els[i]
	fmt.Printf("  [%d] MESH id=%d style=%d", i, el.Record.ID, el.Record.Subtype&0xff)
	if b, ok := el.Body.(*dgn.Body); ok {
		if mh, ok := b.Value.(*element.MeshHeader); ok {
			fmt.Printf(" A=%d", mh.A)
		}
	}
	fmt.Println()

	type hdr struct {
		row    uint32
		family uint32
	}
	headers := map[uint32]hdr{} // family → its 101 header
	type block struct {
		family uint32
		ints   []int32
		dbl    []float64
	}
	var blocks []block
	family := uint32(0)
	for j := i + 1; j < len(els); j++ {
		c := els[j]
		if !isMatrix(c.Record.Type) {
			break
		}
		b, ok := c.Body.(*dgn.Body)
		if !ok {
			continue
		}
		switch v := b.Value.(type) {
		case *element.MatrixHeader:
			family = v.IndexFamily
			headers[family] = hdr{row: v.SizeOfRow, family: family}
			fmt.Printf("      101 id=%d struct=%d row=%d tag=%d family=%d indexedBy=%d\n",
				c.Record.ID, v.SizeOfStruct, v.SizeOfRow, v.Tag, v.IndexFamily, v.IndexedBy)
		case *element.MatrixDoubleData:
			r := uint32(1)
			if h, ok := headers[family]; ok {
				r = h.row
			}
			fmt.Printf("      103(fam=%d,row=%d) id=%d count=%d d=%d,%d,%d vals=%d → %d entries\n",
				family, r, c.Record.ID, v.Count, v.D1, v.D2, v.D3, len(v.Values), len(v.Values)/int(r))
			blocks = append(blocks, block{family: family, dbl: v.Values})
		case *element.MatrixIntData:
			fmt.Printf("      102(fam=%d) id=%d count=%d d=%d,%d,%d vals=%d\n",
				family, c.Record.ID, v.Count, v.D1, v.D2, v.D3, len(v.Values))
			blocks = append(blocks, block{family: family, ints: v.Values})
		}
	}

	entries := map[uint32]int{} // even family → entry count
	for _, bl := range blocks {
		if bl.ints != nil {
			continue
		}
		if h, ok := headers[bl.family]; ok && h.row > 0 {
			entries[bl.family] = len(bl.dbl) / int(h.row)
		}
	}
	for _, bl := range blocks {
		if bl.ints == nil {
			continue
		}
		n, ok := entries[bl.family+1]
		if !ok {
			fmt.Printf("      fam=%d: no paired double family %d\n", bl.family, bl.family+1)
			continue
		}
		validateFaces(bl.ints, n, bl.family)
	}
}

func dumpSharedCell(i int, el dgn.Parsed) {
	b, ok := el.Body.(*dgn.Body)
	if !ok {
		fmt.Printf("  [%d] type %d id=%d (no body)\n", i, el.Record.Type, el.Record.ID)
		return
	}
	switch v := b.Value.(type) {
	case *element.SharedCellInst:
		fmt.Printf("  [%d] SHARED-CELL-INST id=%d A=%d B=%d C=%d\n", i, el.Record.ID, v.A, v.B, v.C)
		fmt.Printf("      origin1=%v origin2=%v mat=%v origin3=%v\n",
			v.Origin1, v.Origin2, v.Mat, v.Origin3)
	case *element.SharedCellDef:
		fmt.Printf("  [%d] SHARED-CELL-DEF id=%d flag=%d,%d w=%d\n", i, el.Record.ID, v.Flag1, v.Flag2, v.W)
		fmt.Printf("      origin1=%v origin2=%v mat=%v origin3=%v\n",
			v.Origin1, v.Origin2, v.Mat, v.Origin3)
	}
}

// validateFaces parses the zero-terminated 1-based face-list layout and
// reports consistency against n entries (max valid index = n).
func validateFaces(ints []int32, n int, family uint32) {
	var faces [][]int32
	cur := []int32{}
	for _, v := range ints {
		if v == 0 {
			if len(cur) > 0 {
				faces = append(faces, cur)
			}
			cur = []int32{}
			continue
		}
		idx := v
		if idx < 0 {
			idx = -idx
		}
		if int(idx) < 1 || int(idx) > n {
			fmt.Printf("      fam=%d: reject (1-based index %d ∉ [1,%d])\n", family, idx, n)
			return
		}
		cur = append(cur, idx)
	}
	if len(cur) > 0 {
		faces = append(faces, cur)
	}
	if len(faces) == 0 {
		fmt.Printf("      fam=%d: reject (no faces)\n", family)
		return
	}
	sizes := map[int]int{}
	for _, f := range faces {
		sizes[len(f)]++
	}
	neg := 0
	for _, v := range ints {
		if v < 0 {
			neg++
		}
	}
	fmt.Printf("      fam=%d: ACCEPT %d faces sizes=%v negFlags=%d (1-based, n=%d)\n",
		family, len(faces), sizes, neg, n)
}
