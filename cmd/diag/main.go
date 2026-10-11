package main

import (
	"encoding/binary"
	"fmt"
	"os"

	"github.com/flywave/go-dgn/dgn"
)

func main() {
	b, _ := os.ReadFile("sample.dgn")
	els, _ := dgn.ReadV7Elements(b)
	for _, e := range els {
		if e.Type == 3 && len(e.Body) == 104 {
			fmt.Printf("line body[104] first32: % x\n", e.Body[:32])
			fmt.Println("i32@0..7:", int32(binary.LittleEndian.Uint32(e.Body[0:])),
				int32(binary.LittleEndian.Uint32(e.Body[4:])),
				int32(binary.LittleEndian.Uint32(e.Body[8:])),
				int32(binary.LittleEndian.Uint32(e.Body[12:])))
			break
		}
	}
	for _, e := range els {
		if e.Type == 4 {
			fmt.Printf("linestring body[150] first40: % x\n", e.Body[:40])
			break
		}
	}
}
