package dgn

type ChunkIndex struct {
	Flags   uint32
	Offsets []uint32
}

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
		if size < 12 || uint64(pos)+uint64(size) > uint64(len(chunk)) {
			break
		}
		idx.Offsets = append(idx.Offsets, pos)
		pos += size
	}
	return idx
}
