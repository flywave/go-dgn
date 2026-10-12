package main

import (
	"errors"
	"fmt"
	"os"

	"github.com/flywave/go-dgn/dgn"
)

func main() {
	if len(os.Args) < 2 {
		fmt.Println("usage: probe <file.dgn>...")
		os.Exit(2)
	}
	for _, p := range os.Args[1:] {
		switch {
		case detectV8(p):
			probeV8(p)
		default:
			probeV7(p)
		}
	}
}

func detectV8(p string) bool {
	f, err := dgn.Open(p)
	if err != nil {
		return false
	}
	_ = f
	return true
}

func probeV8(p string) {
	f, err := dgn.Open(p)
	if err != nil {
		fmt.Printf("%s: ERROR %v\n", p, err)
		return
	}
	doc, err := f.V8()
	if err != nil {
		fmt.Printf("%s: DGN v8 (CFB) — %d 流（文档解码失败: %v）:\n", p, len(f.Streams()), err)
		for _, s := range f.Streams() {
			fmt.Printf("  %-44s %10d  [%s]\n", s.Name, s.Size, s.Kind)
		}
		return
	}
	fmt.Printf("%s: DGN v8 — revision=%d, 模型 %d, 表级元素 %d, chunk %d\n",
		p, doc.Header.Revision, len(doc.Models), len(doc.Tables), len(doc.Chunks))
	for _, w := range doc.Warnings {
		fmt.Printf("  警告: %v\n", w)
	}
	for _, m := range doc.Models {
		kinds := map[string]int{}
		for _, el := range m.Elements {
			if b, ok := el.Body.(*dgn.Body); ok {
				kinds[fmt.Sprintf("%T", b.Value)]++
			} else {
				kinds["?"]++
			}
		}
		name := m.Name
		if m.Short != "" && m.Short != m.Name {
			name = fmt.Sprintf("%s (%s)", m.Name, m.Short)
		}
		fmt.Printf("  模型 #%06x %-32s 图形 %d 控制 %d %v\n",
			m.ID, name, len(m.Elements), len(m.Control), kinds)
	}
	for _, l := range doc.Levels {
		fmt.Printf("  层 num=%-3d id=%-3d %q\n", l.Number, l.EntryID, l.Name)
	}
	if doc.UorPerMaster != 0 {
		fmt.Printf("  分辨率 uorPerMaster=%g\n", doc.UorPerMaster)
	}
	for _, m := range doc.Models {
		for _, mesh := range doc.Meshes(m) {
			fmt.Printf("  网格 model=%q style=%d id=%d 点=%d 索引=%d\n",
				m.Name, mesh.Style, mesh.EntryID, len(mesh.Points), len(mesh.Ints))
		}
	}
	for _, v := range doc.Views {
		fmt.Printf("  视图 id=%-3d tile=[%.3g %.3g %.3g %.3g] rot0=%.4g\n",
			v.EntryID, v.Tile[0], v.Tile[1], v.Tile[2], v.Tile[3], v.Rotation[0])
	}
	for _, lm := range doc.ViewLevelMasks {
		fmt.Printf("  层掩码 view=%d bits=%d mask=%#016x\n", lm.ViewID, lm.BitCount, lm.Mask)
	}
	for path, ch := range doc.Chunks {
		fmt.Printf("  chunk %-44s 容量=%d 元素=%d space=%d heap=%d\n",
			path, ch.Capacity, len(ch.Elements), len(ch.Space), len(ch.Heap))
	}
}

func probeV7(p string) {
	b, err := os.ReadFile(p)
	if err != nil {
		fmt.Printf("%s: %v\n", p, err)
		return
	}
	h, err := dgn.ParseV7Header(b)
	if err != nil {
		if errors.Is(err, dgn.ErrNotV7) {
			fmt.Printf("%s: unknown format (首4字节 % x)\n", p, b[:min(4, len(b))])
		} else {
			fmt.Printf("%s: ERROR %v\n", p, err)
		}
		return
	}
	els, err := dgn.ReadV7Elements(b)
	if err != nil {
		fmt.Printf("%s: v7 解析中止: %v（已读元素见上）\n", p, err)
	}
	dim := "2D"
	if h.Is3D {
		dim = "3D"
	}
	hist := map[byte]int{}
	for _, e := range els {
		hist[e.Type]++
	}
	fmt.Printf("%s: DGN v7 (%s, level=%d) — 元素 %d 个, 类型 %d 种\n", p, dim, h.Level, len(els), len(hist))
	for t, n := range hist {
		fmt.Printf("  type %-3d x %d\n", t, n)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
