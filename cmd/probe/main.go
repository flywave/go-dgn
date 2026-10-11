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
	fmt.Printf("%s: DGN v8 (CFB) — %d streams:\n", p, len(f.Streams()))
	for _, s := range f.Streams() {
		fmt.Printf("  %-28s %10d  [%s]\n", s.Name, s.Size, s.Kind)
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
