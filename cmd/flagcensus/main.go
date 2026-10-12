// flagcensus prints the flag-word histogram per element type for v8 DGNs,
// verifying the bit13 (complex head) / bit14 (complex child) semantics.
package main

import (
	"fmt"
	"os"

	"github.com/flywave/go-dgn/dgn"
)

func main() {
	for _, p := range os.Args[1:] {
		f, err := dgn.Open(p)
		if err != nil {
			fmt.Printf("=== %s: %v\n", p, err)
			continue
		}
		doc, err := f.V8()
		if err != nil {
			fmt.Printf("=== %s: %v\n", p, err)
			continue
		}
		type key struct {
			typ  uint16
			flag uint16
		}
		census := map[key]int{}
		for _, m := range doc.Models {
			for _, el := range m.Elements {
				census[key{el.Record.Type, el.Entry.Header.Flag & 0x6000}]++
			}
		}
		fmt.Printf("=== %s\n", p)
		for k, n := range census {
			fmt.Printf("  type=%-3d bits13/14=%#04x  x%d\n", k.typ, k.flag, n)
		}
	}
}
