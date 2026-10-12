package cfbtest

import (
	"encoding/binary"
	"sort"
	"unicode/utf16"
)

const (
	sectFree = 0xFFFFFFFF
	sectEnd  = 0xFFFFFFFE
	sectFat  = 0xFFFFFFFD

	sectorSize   = 512
	miniSize     = 64
	miniCutoff   = 4096
	entriesPerS  = sectorSize / 128
	fatEntPerSec = sectorSize / 4
)

// node is one directory entry: a stream ([]byte value) or a storage (map).
type node struct {
	name     string
	typ      byte // 1 storage, 2 stream
	data     []byte
	children []*node
	index    uint32 // directory entry index (root = 0)
	right    uint32 // next sibling index
	start    uint32 // first regular-FAT sector or miniFAT index
}

func (n *node) childIndex() uint32 {
	if len(n.children) == 0 {
		return sectFree
	}
	return n.children[0].index
}

func buildTree(spec map[string]interface{}) []*node {
	names := make([]string, 0, len(spec))
	for n := range spec {
		names = append(names, n)
	}
	sort.Strings(names)
	out := make([]*node, 0, len(names))
	for _, n := range names {
		switch v := spec[n].(type) {
		case []byte:
			out = append(out, &node{name: n, typ: 2, data: v})
		case map[string]interface{}:
			out = append(out, &node{name: n, typ: 1, children: buildTree(v)})
		default:
			panic("cfbtest: value must be []byte or map")
		}
	}
	return out
}

// chainLinks assigns pre-order directory indices and returns all nodes.
// Siblings are chained through `right`; a parent points at its first child
// through `child`.
// assignIndexes numbers nodes pre-order and flattens the tree. Sibling
// right-chains are wired afterwards by linkSiblings (indexes must exist
// first).
func assignIndexes(nodes []*node, next uint32, out *[]*node) uint32 {
	for _, n := range nodes {
		n.index = next
		next++
		*out = append(*out, n)
		next = assignIndexes(n.children, next, out)
	}
	return next
}

func linkSiblings(nodes []*node) {
	for i, n := range nodes {
		if i+1 < len(nodes) {
			n.right = nodes[i+1].index
		}
		linkSiblings(n.children)
	}
}

// Write builds a CFB v3 container from a flat name→stream map (root only).
func Write(streams map[string][]byte) []byte {
	spec := make(map[string]interface{}, len(streams))
	for k, v := range streams {
		spec[k] = v
	}
	return WriteTree(spec)
}

// WriteTree builds a CFB v3 container. Values are []byte (stream) or
// map[string]interface{} (storage, recursive).
func WriteTree(spec map[string]interface{}) []byte {
	top := buildTree(spec)
	var items []*node
	assignIndexes(top, 1, &items)
	linkSiblings(top)

	nEntries := 1 + len(items)
	nDir := uint32((nEntries + entriesPerS - 1) / entriesPerS)
	dirStart := uint32(1)
	next := uint32(1) + nDir

	var miniBytes []byte
	for _, n := range items {
		if n.typ != 2 || len(n.data) >= miniCutoff {
			continue
		}
		n.start = uint32(len(miniBytes)) / uint32(miniSize)
		miniBytes = append(miniBytes, n.data...)
		if pad := (miniSize - len(n.data)%miniSize) % miniSize; pad > 0 {
			miniBytes = append(miniBytes, make([]byte, pad)...)
		}
	}
	miniSectCount := (len(miniBytes) + miniSize - 1) / miniSize

	for _, n := range items {
		if n.typ != 2 || len(n.data) < miniCutoff {
			continue
		}
		n.start = next
		next += uint32((len(n.data) + sectorSize - 1) / sectorSize)
	}

	nMiniFatSect := uint32(0)
	miniFatStart := uint32(sectEnd)
	if miniSectCount > 0 {
		nMiniFatSect = uint32((miniSectCount + fatEntPerSec - 1) / fatEntPerSec)
		miniFatStart = next
		next += nMiniFatSect
	}
	miniContStart := uint32(sectEnd)
	if miniSectCount > 0 {
		miniContStart = next
		next += uint32((len(miniBytes) + sectorSize - 1) / sectorSize)
	}
	total := next
	if total > fatEntPerSec {
		panic("cfbtest: fixture exceeds one FAT sector")
	}

	fat := make([]uint32, total)
	for i := range fat {
		fat[i] = sectFree
	}
	fat[0] = sectFat
	for s := uint32(0); s < nDir; s++ {
		fat[dirStart+s] = sectEnd
		if s+1 < nDir {
			fat[dirStart+s] = dirStart + s + 1
		}
	}
	for _, n := range items {
		if n.typ != 2 || len(n.data) < miniCutoff {
			continue
		}
		nSec := uint32((len(n.data) + sectorSize - 1) / sectorSize)
		for s := uint32(0); s < nSec; s++ {
			fat[n.start+s] = sectEnd
			if s+1 < nSec {
				fat[n.start+s] = n.start + s + 1
			}
		}
	}
	for s := uint32(0); s < nMiniFatSect; s++ {
		fat[int(miniFatStart+s)] = sectEnd
		if s+1 < nMiniFatSect {
			fat[int(miniFatStart+s)] = miniFatStart + s + 1
		}
	}
	if miniSectCount > 0 {
		n := uint32((len(miniBytes) + sectorSize - 1) / sectorSize)
		for s := uint32(0); s < n; s++ {
			fat[int(miniContStart+s)] = sectEnd
			if s+1 < n {
				fat[int(miniContStart+s)] = miniContStart + s + 1
			}
		}
	}

	miniFat := make([]uint32, miniSectCount)
	for i := range miniFat {
		miniFat[i] = sectFree
	}
	for _, n := range items {
		if n.typ != 2 || len(n.data) >= miniCutoff {
			continue
		}
		nMini := (len(n.data) + miniSize - 1) / miniSize
		for s := 0; s < nMini; s++ {
			id := int(n.start) + s
			miniFat[id] = sectEnd
			if s+1 < nMini {
				miniFat[id] = uint32(id + 1)
			}
		}
	}

	dir := make([]byte, nDir*sectorSize)
	rootChild := uint32(sectFree)
	if len(items) > 0 {
		rootChild = top[0].index
	}
	writeDirEntry(dir[0:], "Root Entry", 5, sectFree, sectFree, rootChild, miniContStart, uint64(len(miniBytes)))
	for _, n := range items {
		start, size := uint32(sectFree), uint64(0)
		if n.typ == 2 {
			start, size = n.start, uint64(len(n.data))
		}
		writeDirEntry(dir[int(n.index)*128:], n.name, n.typ, sectFree, n.right, n.childIndex(), start, size)
	}

	header := make([]byte, sectorSize)
	copy(header[0:], []byte{0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1})
	binary.LittleEndian.PutUint16(header[24:], 0x003E)
	binary.LittleEndian.PutUint16(header[26:], 3)
	binary.LittleEndian.PutUint16(header[28:], 0xFFFE)
	binary.LittleEndian.PutUint16(header[30:], 9)
	binary.LittleEndian.PutUint16(header[32:], 6)
	binary.LittleEndian.PutUint32(header[44:], 1)
	binary.LittleEndian.PutUint32(header[48:], dirStart)
	binary.LittleEndian.PutUint32(header[56:], miniCutoff)
	binary.LittleEndian.PutUint32(header[60:], miniFatStart)
	binary.LittleEndian.PutUint32(header[64:], nMiniFatSect)
	binary.LittleEndian.PutUint32(header[68:], sectEnd)
	for i := 0; i < 109; i++ {
		binary.LittleEndian.PutUint32(header[76+4*i:], sectFree)
	}
	binary.LittleEndian.PutUint32(header[76:], 0)

	out := make([]byte, 0, int(total+1)*sectorSize)
	out = append(out, header...)
	fatSec := make([]byte, sectorSize)
	for i, v := range fat {
		binary.LittleEndian.PutUint32(fatSec[4*i:], v)
	}
	out = append(out, fatSec...)
	out = append(out, dir...)
	for _, n := range items {
		if n.typ != 2 || len(n.data) < miniCutoff {
			continue
		}
		out = append(out, n.data...)
		if pad := (sectorSize - len(n.data)%sectorSize) % sectorSize; pad > 0 {
			out = append(out, make([]byte, pad)...)
		}
	}
	if nMiniFatSect > 0 {
		ms := make([]byte, nMiniFatSect*sectorSize)
		for i, v := range miniFat {
			binary.LittleEndian.PutUint32(ms[4*i:], v)
		}
		out = append(out, ms...)
	}
	if miniSectCount > 0 {
		out = append(out, miniBytes...)
		if pad := (sectorSize - len(miniBytes)%sectorSize) % sectorSize; pad > 0 {
			out = append(out, make([]byte, pad)...)
		}
	}
	return out
}

func writeDirEntry(b []byte, name string, typ byte, left, right, child, start uint32, size uint64) {
	u := utf16.Encode([]rune(name))
	for i, r := range u {
		binary.LittleEndian.PutUint16(b[2*i:], r)
	}
	binary.LittleEndian.PutUint16(b[2*len(u):], 0)
	binary.LittleEndian.PutUint16(b[64:], uint16((len(u)+1)*2))
	b[66] = typ
	b[67] = 1
	binary.LittleEndian.PutUint32(b[68:], left)
	binary.LittleEndian.PutUint32(b[72:], right)
	binary.LittleEndian.PutUint32(b[76:], child)
	// CFB v3/v4 both keep ObjectStartSector@116 and StreamSize@120.
	binary.LittleEndian.PutUint32(b[116:], start)
	binary.LittleEndian.PutUint64(b[120:], size)
}
