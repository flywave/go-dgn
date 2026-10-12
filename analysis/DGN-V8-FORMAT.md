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
- **流名**（UTF-16 rdata 簇 0xa2f820–0xa2f900，观察；用途已由金样定性 D94；Mix/Mf/Mh 为 `OdDgChunk::create` 按名分派的专用子类 D99）：
  `Dgn~ULC`（主数据流，`szDgnULCStream`）、`Dgn~H`（设计头：**20B 未压缩前缀 =
  type9 头体的前 20 字节**（u16=1,u16=4,u32×4=0）+ 其余 zlib（20+1576=1596=0x63C，
  D100）；payload（解压后）@320=revision，与 OLE Revision Number 互证）、`Dgn~Mf`（根辅助表 276B：金样
  首 u32=0x110=272=len−4、余零，内部表布局 [?]）、`Dgn~Mh`（每模型一张 4.6KB 级模型表：
  金样首 u32 族 (2,8,0x66)/(1,0,0)/(2,8,9)，内部表布局 [?]）、`Dgn~Mix`（模型索引，见 §2.5）、
  `Dgn~S`（空闲图 0xFF）、`Oda~SH`（16B GUID）；外加 OLE 标准流（SummaryInformation 等）。
- **目录布局（金样观察）**：`Dgn-Md/#NNNNNN/` 每模型一个 storage（含 `Dgn~Mh`、
  `Dgn^G`(图形 `$` 块)、`Dgn^C`(控制)、`Dgn^GA`/`Dgn^CA`(属性镜像) 与 `^AH`(u32 代次)）；
  根级 `Dgn^Nm/`(文件级表元素) `Dgn^NmA/`(名字堆) `Dgn^Ix/`(索引)。
  Go 读取器按全路径遍历（`Dgn-Md/#000000/Dgn^G/$1`），**CFB v3 目录项
  start@116/size@120**（v3/v4 同偏移；早期读 120/124 会把全部 size 读成 0）。
- **解码顺序**：godgn 按 CFB 分配序单遍共享窗口解码（超集实现）；实证每流=独立
  zlib 单帧、写侧无跨块状态 ⇒ 任意序等价（D97；旧"必须按分配序"降级为兼容性选择）。

## 2. Chunk 层

流内子节点按名称分流（`OdDgChunk::create @1809eab70`，名首字节 `'$'`=0x24）：

| 类 | 触发 | 对象 | 关键字段 |
|---|---|---|---|
| `OdDgElementChunk` | 名以 `$` 开头 | 72B | `[7]`=u32 偏移数组；+0x44/+0x45=标志字节 |
| `OdDgZipChunk` | 其余 | 56B | 压缩参数@+6 |

- chunk 裸缓冲：`vt+0x68`=数据指针，`vt+0x70`=长度（`OdDgProxyChunk::read @180568420` 直接 memcpy）。
- **ElementChunk 流布局（金样+读写双证，D94/D96）**：
  ```
  [u32 count][u32 flags][u32 x][u32 y]   # 16B 头（prefixLen）
  [zlib 单帧 payload]                     # 解压后=纯记录区
  ```
  读侧：`FUN_1809ea120` 解压（`FUN_1809e80c0` 单次 `oda_z_uncompress`，头保留）后
  rdInt32×4；count→记录数、flags→obj+0x40（bit0→+0x44、bit1→+0x45，`FUN_1809dbf20`）、
  x→obj+0x44(u32)、y→obj+0x48；偏移种子=prefixLen（`FUN_1809dc670`）。
  写侧：空块初始化（`FUN_1809dcad0`）=[0][2][**nameSuffix**][0]；保存
  （`FUN_1809ea640`，vt+0xa0）=[count][2][0][count]+逐元素序列化+
  `FUN_1809e8470` 单次 `oda_z_compress`（无跨块字典/状态）。
  金样四族：[c][2][1][c] / [0][2][1][0] / [c][3][1][c] / [c][3][0][0]
  （flags=3 与 (0,0) 族疑旧版本写路径 [?]）。无 zlib 头的遗留形态：
  offset 8 起直接存记录（count/flags 同位）。
- **记录区（解压后）**：纯记录链，`off[0]=prefixLen`（解压视图下=0）；
  `off[i+1] = off[i] + u32@(off_i+8)*2 + 4`；
  终止：`u32@record(off)≠0`（尾部名字堆起点，如 "Master Model"）或越界；
  **4 字节空槽合法**（A=0,type=0,B=0，尾随零填充）。旧"首条目预期=8"仅适用未压缩形态。
- **偏移索引 = 增量推导（非文件表）**（同上；一致性校验失败抛错5）。
- **§2.4 Zip 块压缩语义（勘误版，D97 取代 D94 旧述）**：
  - **每条 zip 承载流 = 恰好 1 个完整 zlib 帧**（3 个 v8 金样共 27 流全部实证；
    Python `zlib.decompress` 全格式校验通过 ⇒ **adler32 全部有效**——旧"段尾 adler=0
    不可信/多段分段"为字节扫描分段器伪影）。
  - ODA 读侧 `FUN_1809e80c0` = 单次 `oda_z_uncompress`（-5 重试仅缓冲不足）；
    写侧 `FUN_1809e8470` = 单次 `oda_z_compress`，**无跨块字典/压缩状态**
    ⇒ **压缩字节与块间写序无关**。
  - 金样6种解码序（分配/逆分配/名字/尺寸/每流独立/每段独立）**全部字节一致**
    ⇒ 任何序均无损；跨段/跨流回引用在金样中不存在。
  - godgn `zipWindow` 共享窗口实现为**超集**（无回引用时字典闲置=独立解码）保持，
    以容忍未来可能出现的多段/回引用帧；`Dgn~H` 等流在 zlib 前有未压缩前缀（20B）。
  - 实现注记：`compress/zlib` 在 FDICT=0 时丢弃预设字典且内部 bufio 破坏定位 ——
    用 `flate.NewReaderDict` + `bytes.Reader`（实现 io.ByteReader 不被缓冲）。
- **§2.5 Dgn~Mix 模型索引（写侧 `FUN_1805cbed0` 全字段解，D98）**：
  文件信封 `[u32 magic=0xAA00BA11][u32 ver=4][u32 count][u32 0]`；每模型记录 =
  **lead16B**{u16 flags(bit0..bit3 自 CDGModel: +0x1224&1 / vt+0xf8 / +0x1224>>3&1 /
  +0x1420≠0)、u16 @impl+0x1202、u32 **modelNumber=@impl+0xb0**（模型序号，
  `FUN_1805cc340` 分配 max+1）、f64 **时间戳**（OdTimeStamp×1000 ms；金样
  1228805552000 → 2008-12-09T06:52:32Z）} + **名字头16B**{**u16 entrySize =
  0x20+短名字节+长名字节+extra字节**（金样 0x54/0x56/0x4a 即此值）、u16 短名长、
  u32 长名长（两个 u16 写）、u16 extra 尺寸、u16 @impl+0x12b0、u32 末槽（写侧
  25.4=字面0，金样非0=1/0x03e8ceb8/0x0022d850，疑旧版本 ID/hash，读侧未见消费
  [?]} + 短名UTF-16 + 长名UTF-16 + extra 尾块（金样16B，首 u32=0x40）。
  实例：attach="Model"+"Default Model"/"Model for 2d elements"（2 模型）；
  attach1="Default"+"Master Model"；odwriteex="Model"+"Master Model"（extra=0 无尾块）。

## 3. 元素记录布局

```
[36B 元素头][72B 显示头?][体…][linkage 区…]
```

### 3.1 元素头 SElementHeader（36B，文件序；`FUN_1808c5240 @1808c5240`）

| 偏移 | 宽 | 字段 | 语义 |
|---:|---:|---|---|
| 0 | u32 | A | [?]（目录停止条件：A≠0 终止偏移推导；A≠0 区段=尾部名字堆，如 "Master Model"） |
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
| 9 DesignFileHeader | 体=**0x63C 字节定长**（v8 `OdDgDesignFileHeaderData::read@180567a30` 汇编级+initialize+write 三方互证，D100；v8 存于 Dgn~H：前 20B 未压缩+zlib 余量） | 同 | 见下方 §7.0 字段偏移表 |
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
| 27 BSplineCurve | `u32×3`（复杂） | 同 | v8 读写双证（D99）：#1=impl+0x240 存储字段（round-trip，getter 待钉）；**#2 写时=极点元素(+0x250)槽+0x408 返回值**（金样 0x01620162≠极点数，槽覆盖/杂值 [?]）；**#3 写时=节点元素(+0x258)同槽返回值，金样=17=极点数**（D95 经验获写侧支持）；knot 26 = **全节点向量**（21=17+order4，非钳制）；order=knots−poles |
| 33 Dimension | 前缀188B → `n×48B 点(Pt3d+f64×2+u16×2+u32)` → 按点 u16 偏移 seek 读字符串 | 同 | wildcard 注册23子类；字符串=rdAnsi/rdUnicode+BOM |
| 36 Multiline | 前缀152B → `n×32B 段(f64+u32×6)` → `m×40B 顶点(Pt3d+u32+u16×2+u32×2)` → `k×32B 断点(u32×2+f64×3)` | 同 | 计数：u8/u16 见 linkages… |
| 95 TableEntry | 剩余 blob（长度=`B*2+4−off`，off∈{36,108}） | 同 | |
| 96 TableHeader | 按 variant（§4.1） | 同 | 复杂：行=子元素 |

### §7.0 type9 DesignFileHeader 体字段偏移表（D100，观察）

读取入口 `OdDgDesignFileHeaderData::read @180567a30`（Data 对象位于 header impl+**0x548**；
结构体 memset 大小 **0x648**）；写侧 `@180568570`（缓冲 0x63C）；默认值 `initialize @1805678b0`。
文件体长 **0x63C**（chunk 长度 ≥0x63C 时才读尾数组，老文件可截断）。
**结构偏移 vs 文件偏移**：+0x13C 处有 4B 对齐空洞 → u64 起文件偏移 = 结构偏移 − 4。

| 结构+ | 文件+ | 宽×数量 | 名称 | initialize 默认 |
|---:|---:|---|---|---|
| 0x000 | 0x000 | u16 | （字 A） | 1 |
| 0x002 | 0x002 | u16 | （字 B） | 4（与字 A 合成 u32=0x40001） |
| 0x004 | 0x004 | u32×4 | [?] | 0 |
| 0x014 | 0x014 | **u8×16** | [?] | 0 |
| 0x024 | 0x024 | **u8×256** | [?] | 0 |
| 0x124 | 0x124 | u32 | defaultModelIs3D | 0 |
| 0x128 | 0x128 | u32 | **version** | 8 |
| 0x12C | 0x12C | u32 | **subVersion** | 0x68 |
| 0x130 | 0x130 | u32 | **format** | 2 |
| 0x134 | 0x134 | u32 | **highestModelId** | 0xFFFFFFFF |
| 0x138 | 0x138 | u32 | **defaultModelID** | 0 |
| 0x140 | **0x13C** | **u64** | **highestUniqueId** | 0 |
| 0x148 | 0x144 | **f64** | **lastSaveTime**（ms；NaN/Inf→0；Oda~SH 哈希用 /1000） | now() |
| 0x150 | 0x14C | u32 | **nextGraphicGroup** | 0 |
| 0x154 | 0x150 | u32 | **nextTextNode** | 1 |
| 0x158 | 0x154 | u32 | [?] | 0 |
| 0x15C..0x31F | 0x158 | **u32×113** | [?] | 0 |
| 0x320..0x328 | 0x31C | u32×3 | [?] | 0 |
| 0x32C | 0x328 | u32 | **originalFormat** | 2 |
| 0x330 | 0x32C | u32 | **modelSpecificDigitalSignatures** | 0 |
| 0x334 | 0x330 | u32 | **fileWideDigitalSignatures** | 0 |
| 0x338 | 0x334 | u32 | **primaryApplicationID** | 0 |
| 0x33C..0x63B | 0x338 | **u32×193** | [?]（条件读） | 0 |
| 0x640 | —（体外） | u32 | Oda~SH 派生值（按 lastSaveTime/1000 字节和索引） | — |

金样互证：Dgn~H 未压缩前缀 20B = 体头 20B（01 00 04 00 + 16B 零）✓；
attach 体 20+1576=1596=0x63C ✓。读取语义：slot0x98=read(buf,n)、slot0x90=readInt8（汇编实证，
伪代码曾误型为 int64 数组）。

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
| §1 | `dgn.Open/OpenBytes`、`dgn/streams.go`、`internal/cfb`（全路径遍历 + v3 偏移 + 分配序 Start） |
| §2 | `dgn/v8zip.go`（zipWindow 共享窗口=超集，金样单帧即可）、`dgn/v8chunk.go`（ParseV8Chunk/ParseElements）、`dgn.BuildChunkIndex`（未压缩遗留） |
| §2.5 | `dgn/v8file.go`（parseMixIndex） |
| §3 | `dgn/{header,parse,dir}.go`（ParseHeader/Display/ParseAll/Walk） |
| §4 | `dgn/dispatch.go`（Key/ps/pn/p0/p3/RegisterWildcard） |
| §6 | `internal/le` + `filer-api.md` |
| §7 | `dgn/element/*`（24 解码器 + ReadDString） |
| §8 | `dgn/linkage`、`dgn/xattr` |
| §9 文档层 | `dgn/v8file.go`（File.V8 → V8Document/V8Model/Tables/Aux/Raw） |
| scene | `dgn/scene_build.go` SceneV8（含 v8 B 样条组装 assembleV8BSplines） |
| v7 | `dgn/v7.go/v7body.go`（帧/core/LINE/multipoint） |

## 10. 已知未知（实现护栏）

~~U1 流用途~~ ✅D94 · U5 头字段A/Tail、disp u16@10 · U8 写回校验和（金样 adler 实测全部有效 D97，
写回校验语义仍属 U8） · U10b 逐 linkage payload ·
U13b Dimension 串接线 · ~~U15 `$` 块前缀双 u32~~ ✅D96（4×u32 头；残差=(0,0)+flags3 写路径） ·
~~U16 Mix 信封~~ ✅D98（残差=名字头末槽 u32） · **U17(收窄)** type27 #2/#3=极点/节点元素槽读出、
C=极点数 ✅（#2 值杂、#1 getter 待钉） ·
Dgn~Mh/Mf 表内部布局（金样字节观察 D99，逐字段仍 [?]；~~Dgn~H~~ ✅=type9 头体 D100） ·
~~滑窗写序=分配序近似~~ ✅D97 改判：**每块独立压缩，写序无语义**（godgn 共享窗口=超集保留） ·
~~v8 真样例固化~~ ✅ 金样 v8_attach{,1}.dgn+odwriteex.dgn（D94/D95/D97）。
注意：25.4 写侧 adler 槽位有效（D97）；"段尾 adler=0"为旧分段器伪影。
