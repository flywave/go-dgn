package dgn

type ChunkIndex struct {
	Flags   uint32
	Offsets []uint32
}

// BuildChunkIndex derives the element-record offset array of an
// uncompressed element chunk ([u32 count][u32 flags][records…]) by the
// incremental rule (D31): off[0]=8, off[i+1]=off[i]+u32@(off_i+8)*2+4; the
// walk stops at a non-zero leading u32 (start of the trailing heap) or at
// the buffer end. Empty slots are legal 4-byte records (type 0, B=0), so
// the minimum span is 4 — real ODA files carry them.
func BuildChunkIndex(chunk []byte) ChunkIndex {
	var idx ChunkIndex
	if len(chunk) < 8 {
		return idx
	}
	count := leU32(chunk[0:4])
	idx.Flags = leU32(chunk[4:8])
	pos := uint32(8)
	for i := uint32(0); i < count; i++ {
		if pos+12 > uint32(len(chunk)) {
			break
		}
		if leU32(chunk[pos:]) != 0 {
			break
		}
		size := leU32(chunk[pos+8:])*2 + 4
		if size < 4 || uint64(pos)+uint64(size) > uint64(len(chunk)) {
			break
		}
		idx.Offsets = append(idx.Offsets, pos)
		pos += size
	}
	return idx
}
