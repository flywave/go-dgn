package dgn

import (
	"bytes"
	"compress/flate"
	"errors"
	"fmt"
	"io"
)

// errNoZipSegment reports a validated zlib header that inflates to zero
// bytes — legal for empty chunks (odwriteex writes [0][2][1][0] blocks
// whose frame decompresses to nothing, D96).
var errNoZipSegment = errors.New("dgn/v8: no zlib segment decoded")

// Zip-chunk decompression semantics (D97 erratum over the original D94
// reading, settled against three golden files plus the ODA read/write chains):
//
//   - ODA 25.4 (odwriteex golden): every zip-bearing stream is exactly ONE
//     self-contained zlib frame with a VALID adler32; the writer compresses
//     each chunk independently (`oda_z_compress`, no cross-chunk state) and
//     the reader inflates with a single `oda_z_uncompress`.
//   - The older attach-family writer in the golden set is not that clean:
//     several streams only decode with history from previously decoded
//     streams (back-references beyond their own frame) and some frames
//     carry mismatched adlers. This implementation therefore keeps a shared
//     32 KiB sliding window across streams in allocation order as a
//     tolerant superset — with no back-references (ODA 25.4 files) the
//     dictionary simply stays idle and decoding is per-stream.
//   - Checksums are never enforced: valid for self-contained frames,
//     mismatched in some legacy frames.
//
// Segment boundaries are decided by the deflate decoder itself (a 0x78 byte
// inside compressed data is not a frame header). The 2-byte zlib framing
// header is validated here and the payload is handed to the raw-deflate
// reader: compress/zlib ignores a preset dictionary unless the FDICT flag
// is set (ODA never sets it), and its internal bufio wrapper would also
// destroy exact input-position tracking.

const zipWindowLen = 32768

type zipWindow struct {
	buf []byte // last ≤32 KiB of decompressed output
}

func (w *zipWindow) dict() []byte {
	if len(w.buf) == 0 {
		return nil
	}
	return w.buf
}

func (w *zipWindow) append(p []byte) {
	w.buf = append(w.buf, p...)
	if len(w.buf) > zipWindowLen {
		w.buf = w.buf[len(w.buf)-zipWindowLen:]
	}
}

func zlibHeaderAt(b []byte, off int) bool {
	return off+2 <= len(b) && b[off] == 0x78 && (int(b[off])<<8|int(b[off+1]))%31 == 0
}

// findZipHeader locates the first zlib framing header within the first
// maxScan bytes.
func findZipHeader(b []byte, from, maxScan int) int {
	end := len(b)
	if maxScan > 0 && from+maxScan < end {
		end = from + maxScan
	}
	for off := from; off+2 <= end; off++ {
		if zlibHeaderAt(b, off) {
			return off
		}
	}
	return -1
}

// inflateZip decodes every zlib segment in body, carrying the sliding window
// across segments (idle for self-contained ODA 25.4 frames, see the package
// comment). Bogus trailing adler32 values are skipped, not checked.
func (w *zipWindow) inflateZip(body []byte) (out []byte, segs int, err error) {
	pos := 0
	for pos+2 <= len(body) {
		if !zlibHeaderAt(body, pos) {
			pos++
			continue
		}
		// bytes.Reader implements io.ByteReader, so compress/flate consumes
		// it directly without buffering and br.Len() stays exact.
		br := bytes.NewReader(body[pos+2:])
		var fr io.Reader
		if d := w.dict(); d != nil {
			fr = flate.NewReaderDict(br, d)
		} else {
			fr = flate.NewReader(br)
		}
		seg, _ := io.ReadAll(fr)
		consumed := len(body) - (pos + 2) - br.Len()
		if len(seg) > 0 {
			out = append(out, seg...)
			w.append(seg)
			segs++
		}
		if len(seg) == 0 {
			// Undecodable from this position: give up on this header.
			pos += 2
			continue
		}
		// Stream end (+ 4B adler32 slot, present or truncated).
		next := pos + 2 + consumed + 4
		if next <= pos || next > len(body) {
			next = len(body)
		}
		pos = next
	}
	if segs == 0 {
		return nil, 0, errNoZipSegment
	}
	return out, segs, nil
}

// DecodeZipStream decodes a whole zip-chunk stream: optional uncompressed
// prefix, then the zlib-segmented payload. The prefix is preserved (Dgn~H
// carries a 20-byte header ahead of its payload).
func (w *zipWindow) DecodeZipStream(raw []byte) (prefix, payload []byte, err error) {
	off := findZipHeader(raw, 0, 64)
	if off < 0 {
		return raw, nil, fmt.Errorf("dgn/v8: no zlib header in stream")
	}
	payload, _, err = w.inflateZip(raw[off:])
	if err != nil {
		return nil, nil, err
	}
	return raw[:off], payload, nil
}
