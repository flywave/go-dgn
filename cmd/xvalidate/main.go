// Command xvalidate cross-validates the Go v8 reader against the ezdgn
// Rust reference on the disputed fields: header Tail@28 semantics (model
// id vs timestamp), model header (Mh) fields, Mix index ids, per-type
// histograms, and raw bytes of selected elements.
package main

import (
	"encoding/binary"
	"fmt"
	"math"
	"os"
	"sort"
	"strings"

	"github.com/flywave/go-dgn/dgn"
)

func main() {
	for _, p := range os.Args[1:] {
		run(p)
	}
}

func run(p string) {
	f, err := dgn.Open(p)
	if err != nil {
		fmt.Printf("%s: OPEN ERROR %v\n", p, err)
		return
	}
	doc, err := f.V8()
	if err != nil {
		fmt.Printf("%s: V8 ERROR %v\n", p, err)
		return
	}
	fmt.Printf("== %s\n", p)
	for _, mi := range doc.Index {
		fmt.Printf("  mix: short=%q long=%q modelNumber=%d timestampMS=%.3f (u64=%#016x)\n",
			mi.Short, mi.Long, mi.ModelNumber, mi.TimestampMS, math.Float64bits(mi.TimestampMS))
	}
	for _, m := range doc.Models {
		fmt.Printf("  model %q (storage id=%#x)\n", m.Name, m.ID)
		if len(m.Header) >= 0xe8 {
			fmt.Printf("    mh[:0x30]=% x\n", m.Header[:0x30])
			for _, off := range []int{0x18, 0x1c} {
				v := binary.LittleEndian.Uint64(m.Header[off:])
				fmt.Printf("    mh[%#x]: u64=%#016x f64=%.6g\n", off, v, math.Float64frombits(v))
			}
			for _, off := range []int{0xc8, 0xcc} {
				gx := math.Float64frombits(binary.LittleEndian.Uint64(m.Header[off:]))
				gy := math.Float64frombits(binary.LittleEndian.Uint64(m.Header[off+8:]))
				gz := math.Float64frombits(binary.LittleEndian.Uint64(m.Header[off+16:]))
				upm := math.Float64frombits(binary.LittleEndian.Uint64(m.Header[off+24:]))
				fmt.Printf("    mh[%#x] origin=[%g %g %g] uorpm=%g\n", off, gx, gy, gz, upm)
			}
		} else {
			fmt.Printf("    mh: only %d bytes\n", len(m.Header))
		}
		// Mh scan: locate type-66 objects inside the model header stream
		// and read the ezdgn-ledger offsets (global origin @0xc8, uor @0xe0).
		for i := 0; i+8 <= len(m.Header); i++ {
			if binary.LittleEndian.Uint16(m.Header[i+4:]) != 66 {
				continue
			}
			if i+0x100 > len(m.Header) {
				break
			}
			obj := m.Header[i:]
			gx := math.Float64frombits(binary.LittleEndian.Uint64(obj[0xc8:]))
			gy := math.Float64frombits(binary.LittleEndian.Uint64(obj[0xd0:]))
			gz := math.Float64frombits(binary.LittleEndian.Uint64(obj[0xd8:]))
			upm := math.Float64frombits(binary.LittleEndian.Uint64(obj[0xe0:]))
			tw := binary.LittleEndian.Uint32(obj[0x00:])
			fmt.Printf("    mh-obj@%d: typeword=%#08x origin@0xc8=[%g %g %g] uorpm@0xe0=%g\n",
				i, tw, gx, gy, gz, upm)
			break
		}
	}
	// Per graphical chunk: tail distribution, type histogram, raw dumps.
	for path, ch := range doc.Chunks {
		if !strings.Contains(path, "Dgn^G") {
			continue
		}
		distinct := map[uint64]int{}
		types := map[uint32]int{}
		for _, el := range ch.Elements {
			distinct[el.Entry.Header.Tail]++
			types[uint32(el.Record.Type)]++
		}
		fmt.Printf("  chunk %s: elements=%d distinct-tail=%d\n", path, len(ch.Elements), len(distinct))
		keys := sortedByCount(distinct)
		for i, k := range keys {
			if i >= 3 {
				fmt.Printf("      ... %d more distinct tails\n", len(keys)-3)
				break
			}
			fmt.Printf("      tail=%#016x n=%d f64=%.6g int64=%d\n", k, distinct[k], math.Float64frombits(k), int64(k))
		}
		tkeys := sortedTypes(types)
		fmt.Printf("    types:")
		for _, t := range tkeys {
			fmt.Printf(" %d×%d", t, types[t])
		}
		fmt.Println()
		// Body-type routing for the interesting raw types.
		for _, el := range ch.Elements {
			switch el.Record.Type {
			case 4, 6, 11, 21, 27:
				inner := any(el.Body)
				if b, ok := el.Body.(*dgn.Body); ok {
					inner = b.Value
				}
				fmt.Printf("      route: type=%d flags=%#04x -> %T\n",
					el.Record.Type, el.Entry.Header.Flag, inner)
			}
		}
		for _, el := range ch.Elements {
			if el.Record.Type == 2 {
				raw := rawAt(ch, el)
				fmt.Printf("    type-2 raw[:0x40]=% x\n", clip(raw, 0x40))
				if len(raw) >= 0xB8 {
					fmt.Printf("    type-2 raw[0x68:0xB8]=% x\n", raw[0x68:0xB8])
				}
				break
			}
		}
		for _, el := range ch.Elements {
			if el.Record.Type == 36 {
				raw := rawAt(ch, el)
				b := binary.LittleEndian.Uint32(raw[8:])
				c := binary.LittleEndian.Uint32(raw[12:])
				primary := int(b)*2 + 4 - int(b-c)*2
				body := raw[0x68:]
				fmt.Printf("    type-36: B=%#x C=%#x primary=%d body[:0x20]=% x\n", b, c, primary, clip(body, 0x20))
				if len(body) >= 0x14 {
					f0 := math.Float64frombits(binary.LittleEndian.Uint64(body[0:]))
					f1 := math.Float64frombits(binary.LittleEndian.Uint64(body[8:]))
					w := binary.LittleEndian.Uint32(body[16:])
					m := binary.LittleEndian.Uint16(body[20:])
					fmt.Printf("    type-36 multiline-hypothesis: f64x2=[%g %g] u32=%#x verts=%d\n", f0, f1, w, m)
				}
				break
			}
		}
		for _, el := range ch.Elements {
			if el.Record.Type == 33 {
				raw := rawAt(ch, el)
				fmt.Printf("    type-33 size=%d raw[0x60:0xE0]=% x\n", len(raw), clip(raw[0x60:], 0x80))
				break
			}
		}
	}
}

func rawAt(ch *dgn.V8Chunk, el dgn.Parsed) []byte {
	if el.Entry.Pos < 0 || int(el.Entry.Pos) >= len(ch.Space) {
		return nil
	}
	return ch.Space[el.Entry.Pos:]
}

func clip(b []byte, n int) []byte {
	if len(b) > n {
		return b[:n]
	}
	return b
}

func sortedByCount(m map[uint64]int) []uint64 {
	keys := make([]uint64, 0, len(m))
	for k := range m {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool { return m[keys[i]] > m[keys[j]] })
	return keys
}

func sortedTypes(m map[uint32]int) []uint32 {
	keys := make([]uint32, 0, len(m))
	for k := range m {
		keys = append(keys, k)
	}
	sort.Slice(keys, func(i, j int) bool { return keys[i] < keys[j] })
	return keys
}
