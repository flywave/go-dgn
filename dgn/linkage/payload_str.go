package linkage

import (
	"encoding/binary"
	"fmt"
)

// String/blob linkage payload decoders (U10b, D88/D90): double array,
// string, byte array, note, XML and filter member.

// DoubleArray is kDoubleArray(0x56D5), handler FUN_1808acfc0:
// u32 header, u32 value, u32 count, count×f64 (degenerate→0).
type DoubleArray struct {
	Header, Value, Count uint32
	Values               []float64
}

func decodeDoubleArray(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	val, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	count, err := le32(raw, 8)
	if err != nil {
		return nil, err
	}
	d := &DoubleArray{Header: hdr, Value: val, Count: count}
	for i := uint32(0); i < count; i++ {
		o := 12 + int(i)*8
		if o+8 > len(raw) {
			return d, fmt.Errorf("linkage: double array truncated at %d", o)
		}
		d.Values = append(d.Values, f64d(raw[o:]))
	}
	return d, nil
}

// String is kString(0x56D2), handler FUN_1800481a0:
// u32 header, u32 id, u32 len, bytes[len] (raw; FF F1 BOM → wide variant,
// kept raw here).
type String struct {
	Header, ID, Len uint32
	Data            []byte
}

func decodeString(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	id, err := le32(raw, 4)
	if err != nil {
		return nil, err
	}
	n, err := le32(raw, 8)
	if err != nil {
		return nil, err
	}
	s := &String{Header: hdr, ID: id, Len: n}
	end := 12 + int(n)
	if end > len(raw) {
		end = len(raw)
	}
	if 12 <= len(raw) {
		s.Data = append([]byte(nil), raw[12:end]...)
	}
	return s, nil
}

// ByteArray is kByteArray(0x5751), handler FUN_1808adc60:
// u32 count + count raw bytes (rest of the record).
type ByteArray struct {
	Count uint32
	Data  []byte
}

func decodeByteArray(raw []byte) (any, error) {
	count, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	b := &ByteArray{Count: count}
	end := 4 + int(count)
	if end > len(raw) {
		end = len(raw)
	}
	b.Data = append([]byte(nil), raw[4:end]...)
	return b, nil
}

// Note is kNoteLinkage(0x562E), handler FUN_1808340b0: fixed 32-byte record
// (u32 header + 7×u32) where payload bytes 8..11 spell ASCII "Note".
type Note struct {
	Fields [8]uint32
	IsNote bool
}

func decodeNote(raw []byte) (any, error) {
	if len(raw) < 32 {
		return nil, nil // handler rejects non-0x20 sizes
	}
	n := &Note{}
	for i := 0; i < 8; i++ {
		n.Fields[i] = binary.LittleEndian.Uint32(raw[i*4:])
	}
	n.IsNote = raw[8] == 'N' && raw[9] == 'o' && raw[10] == 't' && raw[11] == 'e'
	return n, nil
}

// XML is kXmlLinkage(0x56E3), reader FUN_1808d3970:
// u32 header, 6×u32 (skipped metadata), u32 len1, bytes[len1],
// u32 len2, bytes[len2].
type XML struct {
	Header uint32
	Meta   [6]uint32
	Parts  [][]byte
}

func decodeXML(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 32 {
		return nil, fmt.Errorf("linkage: xml too short (%d)", len(raw))
	}
	x := &XML{Header: hdr}
	for i := 0; i < 6; i++ {
		x.Meta[i] = binary.LittleEndian.Uint32(raw[4+i*4:])
	}
	off := 28
	for p := 0; p < 2; p++ {
		n, err := le32(raw, off)
		if err != nil {
			return x, nil // second part optional
		}
		off += 4
		end := off + int(n)
		if end > len(raw) {
			end = len(raw)
		}
		x.Parts = append(x.Parts, append([]byte(nil), raw[off:end]...))
		off = end
	}
	return x, nil
}

// FilterMember is kFilterMember(0x56DD), reader FUN_1808ae0b0 (payload
// after the header word): u32 x, u16 a, u16 b, u32 len1, u32 len2, u32 y,
// bytes[len1], bytes[len2].
type FilterMember struct {
	Header     uint32
	X          uint32
	A, B       uint16
	Y          uint32
	Str1, Str2 []byte
}

func decodeFilterMember(raw []byte) (any, error) {
	hdr, err := le32(raw, 0)
	if err != nil {
		return nil, err
	}
	if len(raw) < 24 {
		return nil, fmt.Errorf("linkage: filter member too short (%d)", len(raw))
	}
	f := &FilterMember{
		Header: hdr,
		X:      binary.LittleEndian.Uint32(raw[4:]),
		A:      binary.LittleEndian.Uint16(raw[8:]),
		B:      binary.LittleEndian.Uint16(raw[10:]),
	}
	off := 12
	n1, err := le32(raw, off)
	if err != nil {
		return f, nil
	}
	off += 4
	n2, err := le32(raw, off)
	if err != nil {
		return f, nil
	}
	off += 4
	if y, err := le32(raw, off); err == nil {
		f.Y = y
		off += 4
	}
	end := off + int(n1)
	if end > len(raw) {
		end = len(raw)
	}
	f.Str1 = append([]byte(nil), raw[off:end]...)
	off = end
	end = off + int(n2)
	if end > len(raw) {
		end = len(raw)
	}
	f.Str2 = append([]byte(nil), raw[off:end]...)
	return f, nil
}
