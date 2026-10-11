# DGN v7 格式（二期 · U4 移植）

**证据源**
- **E3（主规格）**：GDAL dgnlib 开源读取器
  `/Users/xuning/Work/flywave-gdal/external/libgdal/gdal/ogr/ogrsf_frmts/dgn/{dgnopen,dgnread,dgnwrite}.cpp, ogrdgnlayer.cpp, dgnlib.h, dgnlibp.h`、
  `gdal/port/cpl_vax.cpp`
- **真实样例**：`sample.dgn`（16.1MB 3D PCB，= Downloads/PCB (1).dgn 同哈希）、
  GDAL `gdal_data/seed_2d.dgn`、`external/libgdal/gdal/data/seed_{2d,3d}.dgn`
- E2（抽查用）：`TG_Dgn7IO.tx`（RTTI145类：`I_dgMicroStationTCB`、`OdDgConvertV7ToV8Thread`…）

## 1. 文件识别（D51）

```
cell library:  08 05 17 00
常规文件:      byte0 ∈ {0x08, 0xC8} && byte1=0x09 && byte2=0xFE && byte3=0x02
               byte0 bit6 = 3D 标志；level = byte0 & 0x3F
EOF 标记:      FF FF
```
- 魔数本身即**首个元素头**（type = 0x09 DesignFileHeader，level8；words=0x02FE→总长1536B）✓ 实测

## 2. 元素帧（D52，核心）

```
元素 = [4B 头][nWords*2 字节体]
  byte0: level = b0 & 0x3F   （高位=标志: bit7=complex成员, bit6=3D 见魔数）
  byte1: type  = b1 & 0x7F   （= OdDgElement::ElementTypes 同值；bit7=deleted）
  byte2..3: nWords = u16le
  总长 = nWords*2 + 4        ← 与 v8 的 B*2+4 公式同源
体起点即数据（如 LINE: i32 x@+4, y@+8, …）
```
- 帧级解析实测：**sample.dgn = 22,803 元素 / 18 类型**，首元素 type9 ✓；
  seed_2d/3d 通过；类型直方图自洽（LINE×5814、Arc×317、Ellipse×6、BSpline 21/26/27 各×~2520、
  AppData×8617…）
- **byte0 bit7 = 复杂组成员标志**（GDAL writer 建组时对子元素置位 `raw_data[0]|=0x80`）；
  sample 实测：图形类元素（line/arc/bspline/cell 子项）置位、66/34/5/10 等不置位、
  头自身置位与否混杂 —— **分组不靠 bit7，靠 numelems**（见 §9）

## 3. 与 v8 的关系（E3+E2 推断）

- 帧公式同构（words×2+4）；类型码同一枚举（E1 `DgElement.h`）
- E2 RTTI：`OdDgConvertV7ToV8Thread` → **v7 读入后转换为 v8 内存模型**（共享 E*/CDG* 类）
- TCB（`I_dgMicroStationTCB`）= v7 设计文件头内的 MicroStation 控制块（dgnlib `got_tcb`）

## 4. Go 落地（godgn）

- `dgn.Detect → KindV7/KindV7CellLib/KindV8/KindUnknown`
- `ParseV7Header` / `ReadV7Elements`（越界防护、EOF、完整遍历）
- 数值原语 `V7Int32/V7Uint32/V7Double/V7PutInt32/V7PutDouble`（`v7num.go`）
- 体读取 `ReadV7Line/MultiPoint/Arc/Ellipse/Text/TextNode/Cone`（`v7body.go`）
- TCB `ParseV7TCB` + `TransformPoint/ToMaster/TextMult`（`v7tcb.go`）
- 复杂组 `ReadV7ComplexHeader` + `GroupV7Elements`（`v7group.go`）
- 属性区 `V7Core.AttrRegion`；色表 `ReadV7ColorTable`（`v7attr.go`）
- Cell 族 `V7Rad50/ReadV7CellHeader/ReadV7CellLibrary`（`v7cell.go`）
- BSpline `ReadV7BSplineCurveHeader/ReadV7BSplineSurfaceHeader/ReadV7KnotWeights`（`v7bspline.go`）
- `cmd/probe`：v7 输出维度+元素数+类型直方图；v8 输出流清单
- 测试：真实样例（sample/seed）+ 合成字节级 + **python 镜像↔Go 逐位交叉验证**
  （数值 325 行 + 分组树 22803 节点 + Cell/BSpline/Knot 5266 行）；与 v8 路径互斥

## 5. v7 剩余路线

1. ~~元素体格式~~ ✅ LINE/multipoint（D54）+ ARC/ELLIPSE/TEXT/TEXT_NODE/CONE（D58）
2. ~~TCB / 换算~~ ✅ `ParseV7TCB`（D58）
3. ~~复杂组与 index~~ ✅ 分组语义+span 公式（D59）；元素帧顺序遍历=天然索引
4. ~~属性区提取 + A951 应用~~ ✅ `AttrRegion`（D59）+ `ReadV7LineF/MultiPointF`（D61，
   8419 元素逐位一致）；其余 linkage 类型=raw（U10b 按需）
5. ~~剩余类型体~~ ✅ Cell+Rad50/CellLibrary/BSpline 24/27/Knot/Weight（D60）、
   Boundary(25)/TagValue(37)/TagSet(66)/SharedCellDefn(34)（D61）——
   **E3 DGNProcessElement 分支清零**；PointString(22) GDAL 默认分支不解析（记档）；
   TextNode 字符串元素=小尾巴（GDAL 亦不读）
6. ~~TCB views[8]~~ ✅ **D87 关**（本地 dgnlib 源 L1538-1574 逐字段核验）；
   TEXT/CONE/TEXT_NODE 样例复核降级为锦上添花（源码双证已足，HOUSING 仍可选拷入）；
   **E3 权威源码位置**：`flywave-computevision/src/external/libgdal/gdal/ogr/ogrsf_frmts/dgn/`
   （dgnread.cpp/dgnwrite.cpp —— v7 [?] 优先查此处）

## 6. 字节序（D57 ★勘误：u32 非纯小端）

```
u16 = 纯小端（DGN_INT16：nWords、GG、properties、count… 均此序）
u32 = 半字交换（DGN_INT32 宏，dgnlibp.h:86）：
      字节 [b0 b1 b2 b3] → value = b2 | b3<<8 | b0<<16 | b1<<24
      即两个 LE u16 半字、高半字在前；0x12345678 → 文件字节 34 12 78 56
f64 = VAX D 浮点 + 同一半字交换（DGN2IEEEDouble = CPLVaxToIEEEDouble；
      Go V7Double = 字节级移植；锚点 1.0 → 80 40 00 00 00 00 00 00）
包围盒 = 偏移二进制：true UOR = uint32(V7Int32(raw)) − 2^31
```

**实证（真实样例 hexdump）**
- TCB@1112 = `00 00 64 00` → 100（配 units `in`/`th` → 100 thou/inch ✓；
  纯小端误读 = 6,553,600 ✗）
- TCB@1116 = `00 00 EC 09` → 2540 UOR/thou → 254,000 UOR/inch ✓ 自洽
- LINE 包围盒 5/5 = 顶点 min/max + 2^31（offset-binary 确认）
- **双实现交叉验证**：python 逐行镜像 GDAL C ↔ godgn Go，sample.dgn
  317 Arc + 6 Ellipse + 2 TCB = 325 行 **逐位一致**；分组树 22803 节点 **逐位一致**
- 旧测试仅验 count 未验坐标值 → 已补"LINE 顶点 ⊆ bbox"不变量回归

## 7. 类型体（body 偏移；均在 core+显示头 32B 之后。E3 dgnread L619-925）

| 类型 | 布局 |
|---|---|
| LINE(3) | 32: 2×Point（3D=12B/2D=8B, u32 半字序） |
| LINE_STRING(4)/SHAPE(6)/CURVE(11)/BSPLINE_POLE(21) | 32: **u16 count**(LE, ≥2), 34: count×Point；短元素钳制 `(size-38)/ps` |
| ELLIPSE(15) | 32/40: primary/secondary **f64**；2D: 48 rot(i32/360000), 52/60 origin **f64**；3D: 48..64 quat(4×i32, ÷2³¹=单位), 64/72/80 origin f64；恒 start=0, sweep=360 |
| ARC(16) | 32: start(i32/360000)；36: sweep **符号-幅值**（bit31=负号，raw0→360°）；40/48: 轴 f64(×scale→master)；2D: 56 rot, 60/68 origin f64；3D: 56..72 quat, 72/80/88 origin f64。**字段序与 U14 v8 定案一致**：start,sweep,primary,secondary,rotation/quat,origin |
| TEXT(17) | 32 font u8, 33 just u8, 34/38 length/heightMult i32（master = raw×scale×6/1000）；2D: 42 rot, 46/50 origin **i32**；3D: 42..58 quat[推断·同族模式], 58/62/66 origin i32；**54/70 = numChars u8**；56/72 = 字符串（FF,FD BOM→packed UTF-16 变体，否则 raw 字节，钳制越界） |
| TEXT_NODE(7) | 32/34 totlength/numelems u16, 36 node# u16, 38/39 maxLen/maxUsed u8, 40/41 font/just u8, 46/50 mult i32；2D: 54 rot, 58/62 origin i32；3D: 54..70 quat[推断], 70/74/78 origin i32。字符串在后续元素（GDAL 亦不读） |
| CONE(23) | **仅 3D**（2D 报错）：32 unk u16, 34/38/42/46 quat, 50/58/66 center1 **f64**, 74 radius1 f64(×scale), 82/90/98 center2 f64, 106 radius2 f64 |
| CELL_HEADER(2) | 32 tot u16, 34/36 名 2×Rad50, 38 class u16, 40..47 levels u16×4；2D: range@48/52/56/60(i32), trans4@64..76(i32/2³¹), origin@80/84 → 派生 xscale=√(a²+c²)/214748、rotation=acos±翻转；3D: range6@48..68, trans9@72..104, origin@108/112/116 |
| CELL_LIBRARY(1) | 无显示头：28/30 名 2×Rad50, 32 numwords, 34 自读 props, 36 dispsymb, 38 class, 40..47 levels, 48..65 desc 9×Rad50(27字符) |
| BSPLINE_CURVE_HDR(27) | 32 desc i32, 36 flags u8(order=low4+2, props=high4), 37 curvetype, 38 poles u16, 40 knots u16 |
| BSPLINE_SURF_HDR(24) | 32 desc, 36 uflags, 37 curvetype, 38/40/42 polesU/knotsU/ruleU, 44 vflags, 46/48/50 polesV/knotsV/ruleV, 52 bounds u16（GDAL ×556 笔误不复刻） |
| KNOT(26)/WEIGHT(28) | 数量=`(size−36−attr)/4`（attr 走属性区公式），值=body32 起 i32/(2³¹−1) float |
| BOUNDARY(25) | 32 number u16, 34 numverts **i16**(≤0 报错), 36.. UV 顶点 i32（z=0，A951 应用，无 TCB 变换）；逐顶点 guard `44+i*8≤bodyLen` |
| TAG_VALUE(37) | 64 tagSet **plain LE u32**（GDAL CPL_LSBPTR32 异常 [?]）, 68 index u16, 70 type u16, 146 length u16, 150 值（1=NUL 串 / 3=LE i32 / 4=VAX f64） |
| TAG_SET(66 lv24) | 40 count u16, 42 flags u16, 44 name NUL；defs 自 44+len+2：name NUL, id u16, prompt NUL, type u16, +5 零, 默认(1 串/3,5 LE i32/4 VAX/其他+4)；attr magic `03 10 2f 7d`→tagSetID（需 attr≥8B） |
| SHARED_CELL_DEFN(34) | 32 totlength u16（GDAL 只解此字段）；**160..176 = ASCII 名字**（样例实证 D85） |
| SHARED_CELL_REF(35) | **样例定案（D85，GDAL 默认分支）**：176B 固定；48..67 range6 半字交换 i32 UOR（3D cell-header 约定）；72/104/136 三个等比 scale 槽（i32sw，语义 [?]：i32/2³¹=0.5039 或 swapped f32=4.0）；160..176 ASCII 名字 → 交叉引用 type34 defn（样例 39/39 命中） |

- 角度单位：i32/360000 = 度；quat = i32/2³¹ ≈ 单位四元数（实测 ellipse quat 范数 1.000）
- sweep 符号-幅值实证：sample 317 弧中 65 个带符号位，全部 |deg|≤360
  （首弧 start=90° sweep=−90° prim=sec=635 = PCB 倒角）；two's-complement 解读会得荒谬值 → GDAL 正确
- 旧表勘误：ELLIPSE/ARC 起点=origin bbox 同源的猜测已废弃 —— origin 是
  **body 内显式 f64**，与 bbox 无关

## 8. TCB / DesignFileHeader（type9，D58）

```
body1108: subunits_per_master i32(半字序)   body1112: uor_per_subunit i32
body1116..17: master_units 2×char           body1118..19: sub_units 2×char
body1210: bit0x40 → 3D（与魔数 bit6 同源）
body1236/1244/1252: 全局原点 f64(VAX) → ÷(uor×sub) = master 单位
scale = 1/(uor_per_subunit × subunits_per_master)   // UOR → master
换算（GDAL DGNTransformPoint）: master = uor × scale − origin
文本倍率: master = raw_i32 × scale × 6/1000（V7TCB.TextMult）
首个 TCB 生效（GDAL got_tcb 锁存；sample 有 2 个，第 2 个 2D/零单位被忽略）
views[8]×118B @body42（flags u16+levels8B+origin i32×3→scale−origin+delta i32×3→×scale
  +9×VAX 矩阵+conversion VAX+activez u32）—— **✅ 已解析（D62）**，
  python↔Go 逐位一致；非首 TCB 的 views 用自身 scale（首 TCB 恒与 GDAL 同）
```
**实测 sample.dgn**：3D、2540 UOR/thou、100 thou/inch、单位 in/th、原点 0、
scale=1/254000 → `TransformPoint{254000,508000,-254000} = {1,2,-1}` inch ✓ 测试绿
**文档级入口（D62）**：`ParseV7Document` = 首元素 TCB（magic byte1=0x09 保证）+
分组森林 + `Extents()`（GDAL extent 类型集 bbox 并集 → master）；
sample 金样 extents = [−27.45, −0.40, −7.58]..[0.75, 19.56, 0.04] inch ✓
seed_2d/3d 文档测试 ✓（TCB dim ↔ 魔数 bit6 互证）

## 9. 复杂组 / 属性区 / 色表（D59）

**复杂组头**（body32 起；E3 dgnread L818-830/L927-941）
```
type12/14 (chain/shape): u16 totlength@32, u16 numelems@34
type18/19 (surface/solid): 同上 + u8 surftype@36, u8 boundelms@37(存储值+1)
```
**分组语义（OGR ogrdgnlayer.cpp:730）**
```
子元素 = 头之后顺序 numelems 个原始元素（不看 bit7！）
子元素若本身是复头 → 递归吞并其子树（OGR 递归 depth<20，Go 不设上限）
bit7 = "组成员"标志（writer 建组时置位），仅语义标注非分组依据
span 公式（19/19 组实证）：totlength + 19 = Σ (size/2)，对组内全部元素（含头）
  = dgnlib.h "words excluding the first 19 words" 注释；6 个带属性头(hdr 30w)同样吻合
sample：19 个复头（16 chain + 3 shape），最大组 437 子元素？——无（那是误扫）；
  实测每组 num=4 或 8；嵌套复头无实例 → 合成测试覆盖递归
交叉验证：python(OGR 语义) ↔ Go `GroupV7Elements` 分组树 22803 节点逐位一致
```
**属性区（E3 DGNParseCore L1289-1310）**
```
attrIndex = u16le @body26（GG@24 与 properties@28 之间）
region = body[attrIndex*2+28 :]，len = size − attrIndex*2 − 28
仅 properties&0x0800 时有效；越界 → 空
sample：11648 个带属性元素；金样 ellipse@10546：idx=30 → body88，16B
  = 07 10 a9 51 04 00 9e 2e 0b dc 00 00 00 00 f5 23（A951 delta 头）
A951（9080 个 region 含 A9 51）：deltaLength=u16×2, deltaStart=+6,
  每顶点 i16 dx/dy → x += dx/32767.0 —— **✅ 已应用（D61）**：
  `ReadV7LineF/ReadV7MultiPointF`（V7PointF 浮点 API），8419 元素
  python↔Go 逐位一致；LINE/multipoint/boundary 生效，arc/ellipse 不用（GDAL 同）
```
**色表（type5 level=1，E3 DGNParseColorTable L1319-1344）**
```
screen_flag u16@body32；entry255 = body34:37（先存！）；entries 0..254 = body37:802
需 body ≥802；level≠1 的 type5 = 普通 group data（sample 即 level2，正确拒读）
```

**验证（真实16MB）**：5814 LINE（含 bbox 包含不变量）✓、36 LineString ✓、
317 Arc + 6 Ellipse 与 python-GDAL 镜像逐位一致 ✓、TCB 单位/换算 ✓、
复组 span 公式 19/19 ✓、分组树逐位一致 ✓、属性区 11648 个 + 金样 ✓、disp-hdr 集合 ✓
**坐标 = RAW i32（半字序，UOR）**，真实单位经 **TCB 换算**（§8）
**类型普查金样（D86）**：`TestSampleV7TypeCensus` 锁定 sample.dgn 全部 22803 元素的
逐类型直方图（18 型）+ 帧首尾相接 + FF/FF 终止符 —— 帧解析回归的最强防线；
样例中 CONTROL(8)×1、CELL_DEFINITION(10)×1 走默认分支（GDAL 亦不解析，记档即闭环）

**未覆盖**：TEXT/CONE/TEXT_NODE 无样例（HOUSING.DGN 被 TCC 拦、seed 无几何）→ 合成字节级
测试 + **本地 dgnlib 源码双证（D87）**；A951 应用/§5.5 剩余类型体已闭环（D61/D60/D87）
