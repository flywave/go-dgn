# DGN v8 格式规范（V1 — 反编译整合版）

> 来源：ODA Teigha 25.4 `TG_Db.tx` 等模块的静态反编译（Ghidra 12.1.4，第1–27轮），
> 交叉验证：ODA 头文件(E1)、GDAL dgnlib/dgnv8 驱动(E3)、真实样例。
> 证据引用格式：`@地址` = TG_Db.tx 内 RVA（image base 0x180000000）；
> 文档引用见 `analysis/03-dgn/*.md`、反编译产物 `analysis/evidence/ghidra/out/`。
> 置信度：**观察**=反编译/汇编直证；**推断**=有据推断（标 [?]）；未知=U 编号。

---

## 1. 容器层

- **v8 文件 = OLE/CFB 复合文档**（魔数 `D0 CF 11 E0 A1 B1 1A E1`）。
  ODA 经 `oless.dll::openStructuredStorageEx` 打开（`FUN_1809ebdc0 @1809ebdc0`）。
- 版本探测：**先试 CFB，失败回落 v7 模块 `TG_Dgn7IO`**（impl 版本字段置7；>7 为 v8）
  —— `OdDgDatabase::readFile @180536190/180536180`。
- **流名**（UTF-16 rdata 簇 0xa2f820–0xa2f900，观察）：
  `Dgn~ULC`（主数据流，`szDgnULCStream`）、`Dgn~H`、`Dgn~Mf`、`Dgn~Mh`、`Dgn~Mix`、
  `Dgn~S`、`Oda~SH`（用途 [?]）；外加 OLE 标准流（SummaryInformation 等）。

## 2. Chunk 层

流内子节点按名称分流（`OdDgChunk::create @1809eab70`，名首字节 `'$'`=0x24）：

| 类 | 触发 | 对象 | 关键字段 |
|---|---|---|---|
| `OdDgElementChunk` | 名以 `$` 开头 | 72B | `[7]`=u32 偏移数组；+0x44/+0x45=标志字节 |
| `OdDgZipChunk` | 其余 | 56B | 压缩参数@+6 |

- chunk 裸缓冲：`vt+0x68`=数据指针，`vt+0x70`=长度（`OdDgProxyChunk::read @180568420` 直接 memcpy）。
- **ElementChunk 缓冲布局（观察 `@1809dbf20/@1809dc670`）**：
  ```
  offset 0: u32 count        # 待建偏移条目数
  offset 4: u32 flags        # bit0 → 对象+0x44, bit2 → +0x45
  offset 8…: 元素记录区（首条目预期=8，[?] 种子值来源 U7b 残留）
  ```
- **偏移索引 = 增量推导（非文件表）**：`off[0]=seed`；`off[i+1] = off[i] + u32@record(off_i + 8)*2 + 4`；
  终止：`u32@record(off)≠0` 或越界（ODA 接受部分计数）；一致性校验失败抛错5。

## 3. 元素记录布局

```
[36B 元素头][72B 显示头?][体…][linkage 区…]
```

### 3.1 元素头 SElementHeader（36B，文件序；`FUN_1808c5240 @1808c5240`）

| 偏移 | 宽 | 字段 | 语义 |
|---:|---:|---|---|
| 0 | u32 | A | [?]（目录停止条件：A≠0 终止偏移推导） |
| 4 | u16 | **type** | `OdDgElement::ElementTypes`（见 §5） |
| 6 | u16 | **flags** | bit12=显示头存在；bit13=复杂元素；bit14=附加4B |
| 8 | u32 | **B** | 条目/体尺寸字数：`总长 = B*2 + 4`（目录步进公式，观察） |
| 12 | u32 | C | implicit 显示头判定入参：`C*2+4`（观察） |
| 16 | u32 | **Sub** | 子类型（dispatch GroupSub 取低8位；type39 特判 ≠0x1c→0） |
| 20 | u64 | **ID** | 元素句柄/唯一 ID |
| 28 | u64 | Tail | [?] |

### 3.2 显示头（72B，`FUN_1808c5150`）

- **存在条件**：`flags.bit12 ‖ isImplicitDisplayHeader(type, C*2+4)`（`@18081e4c0`：
  仅 `type==35 && C*2+4 > 259`）—— entry.c 实证。
- 布局：`u32,u32, u16@8, u16, u32×3, u64×6`（读取序）。
- **3D 标志 = u16@8 的 bit11**（`CDGElementGeneral/CDGDispHeader::get3dFormatFlag`
  `@18011b590/@1800112f0` 观察级 CONFIRMED）；**无显示头时 get3dFormat 返回 true**（ODA 兜底，
  但 classmap 变体此时=0 → 按2D 路由——记录该差异）。

### 3.3 复杂元素

- 子元素 = **独立目录条目**；跨度：`count = u32@(记录+36)`，若 `flags.bit12 && type≠100`
  则 `u32@(记录+108)`；`下一同级 = i + 1 + count`（观察+部分推断）。
- 复杂体头示例：Curve=u32×3、BSplineSurface=u32×10、Solid/Surface=u32+u16×4、
  ComplexString/Shape=u32×1、Cell=u16×2+3×Pt3d+9×f64(3D)/…(2D)。

### 3.4 对齐与 filerType

- 体结束后若游标奇数 → 补读 1B（16-bit 对齐，Text 实证，[?] 全局适用）
- `OdDgFiler::FilerType`（E1 `DgFiler.h:51`）：kFile=0,kCopy=1,kUndo=2,kIdXlate=4,
  kDeepClone=6,kWblock=9,k2dTo3d=10,k3dTo2d=11。**解析器仅 kFileFiler=0 路径**；
  kUndo(2) 分支读 id 列表（count+count×i64）——文件路径跳过（多处实证）。

---

## 4. 分发（type → 类）

- 记录键：`{type, Group, Value}`，三组（`dgn/dispatch.go` 与 E2 entry/dispatch.c 一致）：
  - **Group2D3D** = {2,3,4,6,7,11,13,15,16,17,21,22,27,87}，Value = **显示头 bit11**（0=2D,1=3D）
  - **GroupSub** = {5,33,39,42,91,95,96,105}，Value = `Sub&0xff`（39: ≠0x1c→0）
  - 其余 GroupNone Value=0
- ODA 侧 = `odDgnClassMap()` 密集表[type][variant]+慢速 map（`@1809e0b60`）；
  注册函数 `FUN_180137ee0(map,type,variant,desc)`（rxInit 立即数实证）。
- **miss → 四路 Proxy 回退**（complex×graphics → Proxy/ProxyGraphics/ComplexProxy/…）。
- 特例直构8类（工厂 `1809df950`）：KMLPlacemark/AnnotationCellHeader/AssocRegion/Ole2Frame ×2d3d。

### 4.1 type96 表注册（rxInit 立即数，观察）

`1=Level`（体 u16×2+i64+f64×2=28B）、`6=MultilineStyle`（u16×2）、
`2/3/5/10=Font/Text/DimStyle/RegApp`（体=剩余 blob）；
ModelTable/SharedCellDef/OdDgTable 注册 `(0xffff,0xff)` = 不入表→Proxy。

---

## 5. 元素类型码（E1 `DgElement.h:135`，v7/v8 同值）

0 Undefined,1 LibraryCell,2 CellHeader,3 Line,4 LineString,5 GroupData,6 Shape,
7 TextNode,8 Digitizer,9 DesignFileHeader,10 LevelSymbology,11 Curve,12 ComplexString,
13 Conic,14 ComplexShape,15 Ellipse,16 Arc,17 Text,18 Surface,19 Solid,21 BSplinePoles,
22 PointString,23 Cone,24 BSplineSurface,25 Boundary,26 Knots,27 BSplineCurve,28 Weights,
33 Dimension,34 SharedCellDef,35 SharedCellRef,36 Multiline,37 Tag,38/39 DgnStore,
66 AppData,87-94 Raster,95 TableEntry,96 TableHeader,97 ViewGroup,98 View,99 LevelMask,
100 RefAttach,101-103 Matrix,105 Mesh,106/107 Extra,108 RefOverride,110/111 NamedGroup,127 EOF
（缺号语义未知）

---

## 6. filer 原语（`OdDgFileFiler` 虚表，观察）

slot/offset→原语：`0x58` filerType、`0x78` seek(abs/rel)、`0x80` tell、`0x88` length、
`0x90` rdBytes、`0x98` rdInt8、`0xa0` rdUInt8、`0xa8` **rdInt16**、`0xb0` **rdInt32**、
`0xb8` **rdInt64**、`0xc0/0xc8` rdDouble（0xc8 带 flag 出参）、`0xd0-0xe8` rd*Id 四式、
`0xf8` rdPoint2d(带flag)、`0x100` rdPoint2d(16B)、`0x108/0x110` **rdPoint3d(24B)**、
`0x120/0x128` rdPoint 变体、`0x128` **rdQuaternion(32B=4×f64)**、
`0x130` **rdUnicodeString**、`0x138` **rdAnsiString**、`0x1d8/0x1e0` rd/wrAddress、
`0x1e8/0x1f0` rd/wrFloat。
- **字符串**：`maxLen<0` → NUL 终止字节串；UTF-16 BOM(`FF FE`) → 回绕按 Unicode(NUL 终止)；
  codepage 拓宽分支（dimstr/text 实证）。

---

## 7. 元素体序列（观察级，全部经 slot36/ASM 提取）

| type | 2D | 3D | 备注 |
|---:|---|---|---|
| 3 Line | Pt2d×2 (32B) | Pt3d×2 (48B) | |
| 4 LineString | `u32 count, u32 flags, n×Pt2d` | `n×Pt3d(24B)` | count>10000→`(剩余)>>4` 钳制；成员虚表 slot8 分流 16/24B（`1802e60c0/1802e63a0`） |
| 6 Shape | 同4 + 读取器置 hole 标志 | 同4-3D | slot14 分支=flag+NaN 填充族 |
| 7 TextNode | `u32×2,u16×2, f64×4, Pt2d` | `u32×2,u16×2, f64×3, Quaternion, Pt3d`(92B) | D70 勘误：3D 前导 f64×3（原68B错） |
| 12/14 ComplexStr/Shape | `u32×1`（4B） | 同 | 子元素走目录；`vt+0x650→restoreIdListForUndo` 文件路径空操作 |
| 15 Ellipse | `f64×3(primary,secondary,rotation), Pt2d` | `f64×2(primary,secondary), Quaternion, Pt3d`(72B) | **D63 getter 四连证**：getPrimaryAxis→vt+0x600→impl+0x220、getSecondaryAxis→+0x610→0x228、getRotationAngle→+0x638→0x240、getOrigin3d→+0x638→0x260；fields=`1801d8de0/1801d8e60` |
| 16 Arc | `f64×5(start,sweep,primary,secondary,rotation), Pt2d` | `f64×4(start,sweep,primary,secondary), Quaternion, Pt3d`(88B) | **D56 getter 四连证**（getStartAngle→+0x600→0x220…）；hook+0x650 仅置标志 |
| 17 Text | `u32,u16, u16 L, f64×5, Pt2d, u16 N, bytes[L], N×3 u8, pad` | `u32,u16, u16 L, **f64×4**, Quaternion, Pt3d, u16 N, bytes[L], **N×3 u8**, pad` | **D70：3D 有 N×3 表（D37勘误）+ 前导 f64×4**；L=NUL前定长；N 表越界→丢+seek尾 |
| 18/19 Surf/Solid | `u32 + u16×4`（12B，复杂） | 同 | 几何=子元素 |
| 21 Poles | 同4 点列 | 同 | |
| 22 PointString | 点列 + `n×(4×f64 矩阵)` | 点列 + `n×Quaternion` | |
| 23 Cone | — | `u16×4, Quaternion, Pt3d, f64, Pt3d, f64`（104B） | 字段名 [?] |
| 24 BSplineSurf | `u32×10`（复杂） | 同 | |
| 25 Boundary | `u32, u32(count), n×Pt2d` | 同 | |
| 26/28 Knots/Weights | **剩余全读 f64**（`(len-tell)>>3` 个） | 同 | 吃掉 linkage 区（ODA 同行为） |
| 27 BSplineCurve | `u32×3`（复杂） | 同 | |
| 33 Dimension | 前缀188B → `n×48B 点(Pt3d+f64×2+u16×2+u32)` → 按点 u16 偏移 seek 读字符串 | 同 | wildcard 注册23子类；字符串=rdAnsi/rdUnicode+BOM |
| 36 Multiline | 前缀152B → `n×32B 段(f64+u32×6)` → `m×40B 顶点(Pt3d+u32+u16×2+u32×2)` → `k×32B 断点(u32×2+f64×3)` | 同 | 计数：u8/u16 见 linkages… |
| 95 TableEntry | 剩余 blob（长度=`B*2+4−off`，off∈{36,108}） | 同 | |
| 96 TableHeader | 按 variant（§4.1） | 同 | 复杂：行=子元素 |

通用规则：体解码后 `tell()&1 → rdInt8` 对齐；`k2dTo3d/k3dTo2d(10/11)` 分支读路径不可达。

---

## 8. Linkage 区

- **定位**：`off = 记录起点 + bodyWords*2 + 4`，`size = (totalWords − bodyWords)*2`
  （totalWords 来自头部尺寸字段；`dgnInLinkages @180115f60`）。
- **blob = TLV 序列**（`OdDgLinkageData::readData @1808b4040`），头4B：
  `u16 h=le16(p)`：`count=h&0xff`、`nibble=(h>>8)&0xf`、**userData=bit12**、**remote=bit14**；
  `typeID=le16(p+2)`（仅 userData=1，否则0）
  - 模式A（!userData）：`len=8`；B（userData,!remote）：`len=count*2+2`；
    C（userData&&remote）：`len=(2<<nibble)*count`；计算 len=0 → 余量收尾；越界→停
- 存储：`map[typeID]raw`；对象层=raw 持有+位运算访问器（无集中解析）。
- **ID 表**：E1 `DgAttributeLinkage.h:60-107` `PrimaryIds` 42项（0x56E9 kInfiniteLine、
  0x56DA kSeedPoints、0x56EA kSharedCellFlags、0x4F5A kExternalMaterial、0x41 kFillStyle…）——
  Go `dgn/linkage.PrimaryIDs`。XAttribute 为**独立32位命名空间**（`dgn/xattr.TypeIDs` 53项）。
- `dgnInLinkages` 大级联=7特判ID的**属性应用层**（解析库可选）。

---

## 9. 与 Go（godgn）映射

| 规范节 | 包 |
|---|---|
| §1 | `dgn.Open/OpenBytes`（ErrUnsupportedV7）、`dgn/streams.go` |
| §2 | `dgn.BuildChunkIndex`、`cfb` |
| §3 | `dgn/{header,parse,dir}.go`（ParseHeader/Display/ParseAll/Walk） |
| §4 | `dgn/dispatch.go`（Key/ps/pn/p0/p3/RegisterWildcard） |
| §6 | `internal/le` + `filer-api.md` |
| §7 | `dgn/element/*`（24 解码器 + ReadDString） |
| §8 | `dgn/linkage`、`dgn/xattr` |
| v7 | `dgn/v7.go/v7body.go`（帧/core/LINE/multipoint） |

## 10. 已知未知（实现护栏）

U1 种子值/流用途[?] · U5 头字段A/C/Tail 与显示头语义 · U8 写回校验和 · U10b 逐 linkage payload ·
U13b Dimension 串接线 · **U14 Arc3d start/sweep**（GDAL 端点制暗示）· v8 真样例固化（40+ [?] 项） ·
LibraryCell(1)/TableHeader(96 impl) 零星考证。
