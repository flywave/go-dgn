package dgn

import (
	"encoding/binary"
	"fmt"
)

// V7ColorTable is DGNT_GROUP_DATA(5) at level 1 (GDAL DGN_GDL_COLOR_TABLE);
// other levels of type 5 parse as plain core only.
type V7ColorTable struct {
	ScreenFlag uint16
	Colors     [256][3]byte
}

// ReadV7ColorTable decodes the color table (GDAL DGNParseColorTable).
// File layout stores entry 255 first: screen_flag@body32, entry255@body34,
// entries 0..254@body37.
func ReadV7ColorTable(el V7Element) (V7ColorTable, error) {
	var ct V7ColorTable
	if el.Type != 5 || el.Level != 1 {
		return ct, fmt.Errorf("dgn/v7: not a color table (type %d level %d)", el.Type, el.Level)
	}
	if len(el.Body) < 802 {
		return ct, fmt.Errorf("dgn/v7: color table body %d < 802", len(el.Body))
	}
	ct.ScreenFlag = binary.LittleEndian.Uint16(el.Body[32:])
	copy(ct.Colors[255][:], el.Body[34:37])
	for i := 0; i < 255; i++ {
		copy(ct.Colors[i][:], el.Body[37+i*3:40+i*3])
	}
	return ct, nil
}
