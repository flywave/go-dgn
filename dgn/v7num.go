package dgn

import "math"

// V7Int32 decodes a 32-bit integer in DGN v7 word order: bytes hold two
// little-endian u16 halves with the high half first (GDAL dgnlib DGN_INT32).
// 16-bit fields in v7 stay plain little-endian (DGN_INT16).
func V7Int32(b []byte) int32 {
	return int32(V7Uint32(b))
}

// V7Uint32 decodes a 32-bit word in DGN v7 order, unsigned.
func V7Uint32(b []byte) uint32 {
	return uint32(b[2]) | uint32(b[3])<<8 | uint32(b[0])<<16 | uint32(b[1])<<24
}

// V7Double decodes a v7 double: VAX D-floating stored in DGN word order.
// Byte-exact port of GDAL CPLVaxToIEEEDouble (DGN2IEEEDouble).
func V7Double(b []byte) float64 {
	hi := V7Uint32(b[0:4])
	lo := V7Uint32(b[4:8])

	sign := hi & 0x80000000
	exponent := int32((hi >> 23) & 0xff)
	if exponent != 0 {
		exponent = exponent - 129 + 1023
	}

	rndbits := lo & 0x00000007
	lo >>= 3
	lo = (lo & 0x1fffffff) | (hi << 29)
	if rndbits != 0 {
		lo |= 0x00000001
	}

	hi = (hi >> 3) & 0x000fffff
	hi |= uint32(exponent) << 20
	hi |= sign

	return math.Float64frombits(uint64(hi)<<32 | uint64(lo))
}

// v7BBoxCoord decodes a header bounding-box word: stored offset-binary,
// true UOR = raw unsigned − 2^31 (GDAL DGNGetElementExtents convention).
func v7BBoxCoord(b []byte) int32 {
	return int32(int64(V7Uint32(b)) - 1<<31)
}

// V7PutInt32 encodes a 32-bit integer into DGN v7 word order (inverse of
// V7Int32; used by tests and writers).
func V7PutInt32(b []byte, v int32) {
	u := uint32(v)
	b[0] = byte(u >> 16)
	b[1] = byte(u >> 24)
	b[2] = byte(u)
	b[3] = byte(u >> 8)
}

// V7PutDouble encodes a float64 into a v7 double (VAX D in DGN word order);
// inverse of V7Double. Values with a VAX exponent below 1 (|v| < ~1e-38)
// and non-zero are not supported and encode as zero.
func V7PutDouble(b []byte, v float64) {
	bits := math.Float64bits(v)
	sign := uint32(bits>>63) << 31
	exponent := int32((bits >> 52) & 0x7ff)
	frac := bits & (1<<52 - 1)
	if exponent == 0 && frac == 0 {
		for i := range b {
			b[i] = 0
		}
		return
	}
	// IEEE → VAX: exponent bias shift (1023 → 129), mantissa 52 → 55 bits.
	vaxExp := uint32(exponent - 1023 + 129)
	frac55 := frac << 3
	hi := sign | vaxExp<<23 | uint32(frac55>>32)
	lo := uint32(frac55)
	V7PutInt32(b[0:4], int32(hi))
	V7PutInt32(b[4:8], int32(lo))
}
