package le

import (
	"encoding/binary"
	"errors"
	"math"
)

var ErrTruncated = errors.New("le: read beyond end of buffer")

type Reader struct {
	buf []byte
	off int
	err error
}

func New(b []byte) *Reader { return &Reader{buf: b} }

func (r *Reader) Err() error     { return r.err }
func (r *Reader) Tell() int      { return r.off }
func (r *Reader) Remaining() int { return len(r.buf) - r.off }
func (r *Reader) Seek(off int) error {
	if r.err != nil {
		return r.err
	}
	if off < 0 || off > len(r.buf) {
		r.err = ErrTruncated
		return r.err
	}
	r.off = off
	return nil
}

func (r *Reader) take(n int) []byte {
	if r.err != nil {
		return nil
	}
	if n < 0 || r.off+n > len(r.buf) {
		r.err = ErrTruncated
		return nil
	}
	b := r.buf[r.off : r.off+n]
	r.off += n
	return b
}

func (r *Reader) U8() uint8 {
	b := r.take(1)
	if b == nil {
		return 0
	}
	return b[0]
}

func (r *Reader) I8() int8 { return int8(r.U8()) }

func (r *Reader) U16() uint16 {
	b := r.take(2)
	if b == nil {
		return 0
	}
	return binary.LittleEndian.Uint16(b)
}

func (r *Reader) I16() int16 { return int16(r.U16()) }

func (r *Reader) U32() uint32 {
	b := r.take(4)
	if b == nil {
		return 0
	}
	return binary.LittleEndian.Uint32(b)
}

func (r *Reader) I32() int32 { return int32(r.U32()) }

func (r *Reader) U64() uint64 {
	b := r.take(8)
	if b == nil {
		return 0
	}
	return binary.LittleEndian.Uint64(b)
}

func (r *Reader) I64() int64 { return int64(r.U64()) }

func (r *Reader) F32() float32 {
	b := r.take(4)
	if b == nil {
		return 0
	}
	return math.Float32frombits(binary.LittleEndian.Uint32(b))
}

func (r *Reader) F64() float64 {
	b := r.take(8)
	if b == nil {
		return 0
	}
	return math.Float64frombits(binary.LittleEndian.Uint64(b))
}

func (r *Reader) Bytes(n int) []byte {
	if n == 0 {
		return []byte{}
	}
	return r.take(n)
}

func (r *Reader) Rest() []byte {
	if r.err != nil {
		return nil
	}
	b := r.buf[r.off:]
	r.off = len(r.buf)
	return b
}
