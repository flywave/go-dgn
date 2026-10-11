# 纯 Go 解析库设计（由格式分析驱动）

> **⇒ 编码级规格见 [`spec.md`](spec.md)（v1，第1–5轮收口产物，可直接开工）。**
> **⇒ 结构优化 + go-topo 桥设计见 [`topo-bridge.md`](topo-bridge.md)。**
> 本文保留架构背景与验收标准。

> 设计原则：只实现**文件格式事实**（见 `../03-dgn/*.md`、`../02-dwg/*.md`），  
> 不复刻 ODA 的类层次；每个模块必须能追溯到 findings.md 的结论 ID。

## 建议仓库布局

```
go-dgn/
├── dgn/                    # 第一阶段
│   ├── cfb/                # OLE 复合文档层（对应 F1；可评估 mscfb 依赖 vs 自研）
│   ├── filer/              # Filer 原语层（D6 槽位表 → Reader：RdInt16/32/64、
│   │                       #   RdPoint3d、RdUnicodeString、Handle）
│   ├── header/             # SElementHeader(36B, D7) + DisplayHeader(72B, D8) + DesignFileHeaderData
│   ├── element/            # 类型码(D3) → 元素体解码器
│   │   ├── line.go  linestring.go  shape.go  arc.go  text.go  cell.go …
│   │   └── registry.go     # type→decoder 注册表（对应 FUN_1809e5830 分发，U7）
│   ├── linkage/            # linkage/XAttribute 表（dgnInLinkages，待深挖）
│   ├── table/              # level/font/style/regapp/view/model 表（CDG* 表族）
│   └── version.go          # v7/v8 探测（F2）
├── dwg/                    # 第二阶段（对应 W1-W3）
│   ├── header.go           # AC10xx 魔数、section locator（TD_DbIO R18/R21/R24 类族）
│   ├── bitstream.go        # BS/BL/BD/MC/MS/H 位流编解码（待挖）
│   ├── objects.go          # 对象映射、类段
│   └── entities/
├── rvt/                    # 第三阶段（见 ../04-rvt）
└── internal/lex/           # 通用：LE 读取器、CRC/XOR、UTF16
```

## 关键接口草案

```go
// dgn/filer —— 直接对应 D6 槽位表
type Reader interface {
    FilerType() FilerType // 解析器恒为 kFileFiler=0
    RdInt8() int8; RdInt16() int16; RdInt32() int32; RdInt64() int64
    RdDouble() float64; RdFloat() float32
    RdPoint3d() (x, y, z float64)
    RdUnicodeString() (string, error); RdBytes(n int) ([]byte, error)
    RdDbHandle() (Handle, error); Tell() int64; Seek(int64) error
}

// dgn/element —— 类型码(D3)驱动
type Decoder interface {
    Type() uint8            // OdDgElement::ElementTypes
    DecodeBody(r filer.Reader, hdr *header.ElementHeader) (Element, error)
    DecodeLinkages(r filer.Reader, size uint64) ([]Linkage, error)
}
```

## 分层验收标准

| 层       | 验收                                                    | 依赖证据     |
| ------- | ----------------------------------------------------- | -------- |
| cfb     | 能列出任意 v8 .dgn 的全部流名/大小                                | F1（样例待补） |
| header  | 对样例逐字节比对 36B 头字段                                      | D7（样例待补） |
| element | LINE/LSHAPE/SHAPE/ARC/TEXT/CIRCLE 几何与 ODA JSON 导出示例一致 | D3/D5    |
| linkage | 常见 linkage（seed points、shared cell flags、attribute）解码 | 待挖       |
| table   | level/font/style 表全量字段                                | CDG* 表族  |

## 风险与顺序

1. **先补样例文件**（用户决策"先纯静态"→ 静态文档已就位，字节级验证需样例）
2. DGN v8 → DGN v7（TG_Dgn7IO）→ DWG（TD_DbIO）→ RVT（独立路线）
3. 未知项跟踪在 `../03-dgn/findings.md` U1-U7，实现到对应层前必须关闭
