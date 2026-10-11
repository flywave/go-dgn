# DGN P0 元素体字段序列（第 6/10 轮，2D+3D）

**方法**（可复用到任意类型）：

1. `pseudoConstructor@OdDgXxx` → `*obj = OdDgObjectWithImpl<Pub,Impl>::vftable`、impl 用 `EXXX::vftable`
2. namespace-aware `DumpVtables`（`s.getName(true)`）dump `EXXX::vftable`
3. **impl 虚表 slot36（0x120）= `dgnInFields`**（实证：slot33=dgnInHeader `180115f00`，与  
   `OdDgElement::dgnInFields → impl->vt+0x120` 对齐）
4. 反编译 slot36 目标 → 按 filer 槽位顺序抄成读取序列

**filer 槽位→原语**（filer-api.md §1）：`0x58` filerType、`0x80` tell、`0x90` rdBytes、  
`0x98` rdInt8、`0xa8` rdInt16、`0xb0` rdInt32、`0xb8` rdInt64、`0xc0/0xc8` double 族、  
`0x100` rdPoint2d(16B)、`0x110` rdPoint3d(24B)

**产物**：`evidence/ghidra/out/TG_Db.bodies.c`（7 个解码器）、`TG_Db.evt5.txt`（虚表全量）

## 1. 解码器地址与读取序列（E2 观察级，字段语义后半为 [推断]）

|           类型 | 类             | 解码器                                               | 读取序列（按文件顺序）                                                                       |   体大小 |
| -----------: | ------------- | ------------------------------------------------- | --------------------------------------------------------------------------------- | ----: |
|       3 Line | ELine2D       | `1801dbfe0`                                       | Point2d(start), Point2d(end)                                                      |    32 |
| 4 LineString | ELineString2D | `1802e4480`→member(vt@180acf9f8)slot8 `1802e60c0` | **u32 count, u32 flags2, count×Point2d**(count>10000→`剩余字节>>4`)                   | 8+16n |
|      6 Shape | EShape2D      | `1801b9990` → 同一 reader + 置 u8@0x248=1,u8@0x24a=1 | 同 LineString 体                                                                    |    同上 |
|   7 TextNode | ETextNode2D   | `1800a3360`                                       | u32,u32, u16,u16, double×4, Point2d                                               |    60 |
|   15 Ellipse | EEllipse2D    | `1801d8de0`                                       | double×3(**primary,secondary,rotation**@impl 0x220/228/240)+Point2d@0x248（D63 证）, 自身 vt+0x630 后处理 |    40 |
|       16 Arc | EArc2D        | `180286670`                                       | double×5, Point2d, 自身 vt+0x650 后处理                                                |    56 |
| 17 Text | EText2D | `180292330`+`180297150` | **u32,u16,u16=L,f64×5,Point2d,u16=N,rdBytes(L),N×3×u8(越界→丢+seek尾),pad,10/11钩子** | ✅ ReadText |
| 17 Text3d | EText3D | `1802924c0` | u32,u16,u16=L,**f64×4**,Quaternion,Point3d,u16=N,rdBytes(L),**N×3属性表**,pad（D70 勘误：原漏 f64×4 且误称无 N×3 表） | ✅ ReadText3d |

> 3d 同族（ELine3D/ELineString3D…）方法同法提取，序列预期 Point3d 版本 [推断]。

## 2. 通用规则（对 Go 解析器直接有效）

1. **16-bit 对齐填充**：Text 解码器 `if tell()&1 !=0 → rdInt8` —— 体后奇数字节补 1 字节  
   [推断推广到所有元素体与 linkage 区边界，样例验证]  
   1b. **点数 sanity 规则**：`count>10000 → (length()-tell())>>4`（防脏数据；Go 侧同样实现）
2. **filerType 分叉**：`k2dTo3d(10)/k3dTo2d(11)` 触发坐标转换（读路径为 kFileFiler=0 时不可达）
3. 体后处理钩子（ellipse vt+0x630 / arc vt+0x650）= 派生量计算（如包围盒）[推断]，读路径可跳过
4. 字段名对照（Go struct）：起点/终点/原点/轴/角度 用 E1 头文件 `DgLine.h/DgArc.h/
   DgEllipse.h/DgText.h` 的 getter 语义对号入座（序列来自 E2，命名来自 E1）

## 2b. Text 字符串规则（第12轮，U11b 解）

- **L = 第3个读取的 u16**（@0x440）= 字符串字节数：`resize(buf,L); rdBytes(buf,L)`
- **N = Point 后的 u16**（@0x442）：2D 随后读 **N×3 个 u8** 逐字符属性表（`FUN_180297150`：
  `avail<N×3` → N=0 并 seek 到尾）；**3D 代码无此表**（镜像实现）
- 尾部 `tell()&1 → rdInt8` 对齐；`filerType∈{10,11}` 转换钩子（读路径不可达）
- 字符编码 = rdBytes 原始字节 [codepage 待样例]

## 3. 未知

- ~~U11~~ **已解（第7轮，ShowAsm 实证）**：  
  `FUN_1802e4480`: `ADD RCX,0x220; CALL [vptr+0x40]`（rcx/rdx 直通=委托 member）；  
  member vtable = **180acf9f8**（pseudoCtor 汇编 `MOV [RDI+0x220],180acf9f8`）；  
  slot8 = **FUN_1802e60c0** = 点数组读取器：  
  `n=rdInt32; flags2=rdInt32→member[1]; n>10000→n=(length()-tell())>>4; ensure(n);
   member.vt+0x70() 分支：假→n×rdPoint2d(0x100) / 真→n×slot0xf8(带出参flag的 Point2d 变体,
   flag 置位时补写2×8B特殊常量); member finalize byte=1`  
  残留小项：slot14(`vt+0x70`) 分支语义、flags2 字段含义 [推断]
- **U11b**：Text 的字符串长度来源（`rdBytes` 长度取自缓冲既有长度，疑 Ghidra 原型错误）
- 3d 族序列未提取

## 4. 3D 判定（第 10 轮，E2 CONFIRMED）

- **3D 位 = 显示头结构 u16@8 的 bit11**（`CDGElementGeneral::get3dFormatFlag @18011b590`  
  与 `CDGDispHeader::get3dFormatFlag @1800112f0` 均读 disp+8 bit11）
- **无显示头 → get3dFormatFlag 返回 true**（ODA 的默认兜底）；  
  但 classmap 变体 record[4] 此时=0（按 ODA 自身路由走 2D 键）——镜像实现并记录该差异
- 显示头存在条件（entry.c L129-146）：`flags.bit12 || isImplicitDisplayHeader(type, C*2+4)`；  
  **implicit 规则**（`18081e4c0`）：仅 `type==35 && C*2+4 > 0x103`（size>259）
- ext 进 record[4] → `Key.Value∈{0=2D,1=3D}`（Group2D3D）

## 5. 3D 解码器（第 10 轮，impl 虚表 slot36）

|               类型 | 解码器                                                                 | 序列                                           |                    大小 | Go                   |
| ---------------: | ------------------------------------------------------------------- | -------------------------------------------- | --------------------: | -------------------- |
|         3 Line3d | `1801dc040`                                                         | Point3d×2                                    |                    48 | ✅ `ReadLine3d`       |
|     7 TextNode3d | `1800a3440`                                                         | u32×2,u16×2, **f64×3**, Quaternion(32B), Point3d    | 92（D70 勘误：原68B漏前导3双） | ✅ `ReadTextNode3d`   |
|     15 Ellipse3d | `1801d8e60`                                                         | **f64×2(primary,secondary)**, Quaternion, Point3d | 72（D63 勘误：原56B=awk漏读前2双） | ✅ `ReadEllipse3d`    |
|         16 Arc3d | `180286720`                                                         | **f64×4(start,sweep,primary,secondary)**, Quaternion, Point3d | 88（D56 勘误） | ✅ `ReadArc3d`        |
|   4 LineString3d | 共用入口 → member@+0x220 slot8=**`1802e63a0`**                          | u32 count, u32 flags, **count×Point3d(24B)** |                 8+24n | ✅ `ReadLineString3d` |
|        6 Shape3d | 同入口 → member slot8=1802e63a0，Shape 分支(0x70=18000acb0)带有效性flag/NaN填充 | 同 LineString3d（v1 视作一致，flag 语义样例核）           |                 8+24n | ✅ `ReadShape3d`      |
| 22 PointString2d | `1802e44a0`：member 2D 点列 + **count×2x2矩阵(4×double,32B)**            | 8+16n+32n                                    | ✅ `ReadPointString2d` |                      |
| 22 PointString3d | `1802e4620`：member 3D 点列(1802e63a0) + **count×Quaternion(32B)**     | 8+24n+32n                                    | ✅ `ReadPointString3d` |                      |

**U12 判定链（第11轮）**：2D/3D 分流不在读取器内部，而在 **member 对象的虚表 slot8**：  
2D member(180acf9f8/180ad0740/180ad2ef8) → `1802e60c0`(16B 点)；  
3D member(180ad0088/180ad0df8/180ad35a8) → **`1802e63a0`(24B 点，line67 stride24 实证)**；  
而 member 虚表 slot14(0x70) 区分 LineString 族(18000acc0→普通读)与 Shape 族(18000acb0→带 flag+NaN 填充)。  
`rdPoint2d(bool&) @18001f580` = slot24 rdDouble×2（各带 flag），**位宽 16B**。

> 原语增量：**slot37(0x128)=rdQuaternion（4×double,32B）**、slot34(0x110)=rdPoint3d(24B)。  
> 2D 的 "f64×4 旋转" 在 3D 中以 Quaternion 编码（TextNode 对照可见）。  
> 注意：2D Arc 的5×double 与 3D quat+pt 的字段语义对应（start/sweep 去向）[推断待核]。

## 6. P1 第一批（第13轮：实体族）

| 类型 | 解码器 | 序列 | 大小 | Go |
|---:|---|---|---:|---|
| 18 Surface | `1803b6380`（与 Solid 共用） | u32, u16×4（**复杂元素**，[33]=CDGComplexGeneral::dgnInHeader，几何在子元素） | 12 | ✅ `ReadSurface` |
| 19 Solid | 同上 | u32, u16×4 | 12 | ✅ `ReadSolid` |
| 23 Cone | `180222180` | u16×4, **Quaternion**, Point3d, **f64**, Point3d, **f64**（推断: 轴向+双端点/半径） | 104 | ✅ `ReadCone` |

- 注册键：18/19/23 **不在 Group2D3D** → `GroupNone, Value0`（P1 新增 `pn()` 注册路径）
- 实证：Solid/Surface 复杂头 [33]=`180115e80`(CDGComplexGeneral::dgnInHeader) —— 与 directory 跨度规则(C4)衔接
- Cone 字段语义（H4×u16、R1/R2 命名）= [推断]，E1 `DgCone.h` getter 对照待样例

## 7. P1 第二批（第14轮：BSpline 族）

| 类型 | 解码器 | 序列 | Go |
|---:|---|---|---|
| 21 Poles2d/3d | `1800a2e60`/`1800a30d0` | 同 LineString：u32 count, u32 flags, count×Point2d(16B)/Point3d(24B) | ✅ 复用 `ReadLineString(3d)` |
| 26 Knots | `180280d10` | **n=(length()-tell())>>3 → n×f64（剩余全读）** | ✅ `ReadBSplineArray` |
| 28 Weights | `1802ebb60` | 同上（剩余全读 f64；含 COW 数组噪声，语义忽略） | ✅ 同上 |
| 27 Curve | `1803b8690` | filerType==2(undo)特殊；否则 **u32×3**（+默认 u16=1,double=-1）；**复杂元素** | ✅ `ReadBSplineCurve` |
| 24 Surface | `1803e9bc0` | filerType==2 特殊；否则 **u32×10**；**复杂元素** | ✅ `ReadBSplineSurface` |
| 25 Boundary | `1801db560` | u32×2（后续结构未展开） | ⬜ 待办 |

**语义要点**
- Knots/Weights **吃掉 body 剩余全部字节** ⇒ 此类元素的 linkage 区为空（与 ODA bodyWords
  追踪行为一致——若文件带 linkage 也会被吃掉，镜像之）
- Curve/Surface 为**复杂元素**（[33]=CDGComplexGeneral::dgnInHeader），几何子元素
  （Poles/Knots/Weights）挂在其下，由 directory 跨度规则(C4)覆盖
- 27 在 Group2D3D（两维同序列）；24/26/28 在 GroupNone
- BSplineBoundary(25) 未展开 → 下轮或样例联调时补

## 8. P1 第三批（第15轮：Cell 单元头）

| 类型 | 解码器 | 序列（ASM 点数定案，Ghidra 伪码有丢读已弃用） | 大小 | Go |
|---:|---|---|---:|---|
| 2 CellHeader3d | `ECell3D::dgnInFields @180010c10` | u16×2, **3×Point3d, 9×f64(3×3矩阵)**, [+undo 分支跳过] | 148 | ✅ `ReadCellHeader3d` |
| 2 CellHeader2d | `ECell2D @1800109d0` | u16×2, **3×Point2d, 4×f64(2×2矩阵)** | 84 | ✅ `ReadCellHeader2d` |
| 1 LibraryCellHeader | 未提取（GroupNone） | — | — | ⬜ Proxy |

- 复杂元素 [33]=`CDGComplexGeneral::dgnInHeader` —— 单元内容为子条目（C4 跨度覆盖）
- ASM 调用点计数法（`ShowAsm`+awk 统计槽位调用）解决了伪码丢读问题——**记为标准流程**：
  复杂序列以 ASM 点数为准，伪码仅辅助字段命名
- 字段语义（P1/P2/P3=原点/缩放/旋转点，M=变换矩阵）[推断，E1 `DgCellHeader.h` 对照待样例]
- undo(kUndoFiler=2) 分支的 id 列表读取在 kFileFiler 不可达（与既有 filerType 规则一致）

## 9. P1 第四批（第16轮：ComplexString/Shape）

| 类型 | 解码器 | 序列 | 大小 | Go |
|---:|---|---|---:|---|
| 12 ComplexString | `EComplexString/EComplexShape 共用 18045e4b0` | **u32×1**（4B） | 4 | ✅ `ReadComplexElement` |
| 14 ComplexShape | 同上 | u32×1 | 4 | ✅ 同上 |

- 链路：`dgnInFields → u32 → vt+0x650 = CDGComplexGeneral::restoreIdListForUndo`
  —— **filerType≠2(kUndo) 直接 return**：kFileFiler 不读任何 id（child id 列表仅 undo 路径；
  count+count×i64）→ 镜像 filerType 规则
- 复杂元素（[33]=CDGComplexGeneral::dgnInHeader）：**子几何 = 独立目录条目**（C4 跨度），
  与 Curve/Surface 同构（小体 + 子条目）
- ASM+槽位链（vtable[202]=`restoreIdListForUndo`）再次验证流程有效性

## 10. P1 第五批（第17轮：Dimension 族 + Multiline — 已定位，全文提取排队）

### Dimension(33) 族
- **23 个工具类共享同一解码器**：`EDimension/EDimNote/EDimSizeArrow/…/EDimLabelLine`
  的 vtable slot36 全部 = **`180257e60`**；[33]=`180115f00`（**非复杂**，元素普通头）
- 注册语义：type33 ∈ **GroupSub**（variant=工具子类型 u8），23 个 subtype → 同一解码器
  → Go 侧需 **wildcard 注册**（按 (type,group) 匹配任意 Value）——基础设施待加
- **骨架（固定前缀，已读）**：`i64, u32, u32, f64, u32, u8×5+(含循环界 byte@0x23f),
  u16, f64×2, u32×4, u16, u32, u16, f64×9, u32×2, quat, …`，
  后段：`filerType==2` undo 分支(seek/rdBytes) + **循环(byte@0x23f 次, 每元 0x50B 结构)** +
  6× `FUN_18025f040` 子读取器（工具文本项族）
- 解码器共 **997 行**（历史最大）

### 第18轮：Dimension 结构化提取（前 430 行已读）

**A. 固定前缀 = 200B**（行116-181，kFileFiler 顺序读，无分支；**D72 勘误：u16 后有 helper FUN_1808c52e0=rdInt32×3，原188B 漏记**）
```
i64, u32, u32, f64, u32,        # 8+4+4+8+4
u8×6,                           # 行126-136；末位 u8@0x23f = 文本项计数 N
u16, f64×2, u32×4, u16, u32, u16,   # 行138-157（含文本项相对偏移 u16）
f64×9,                          # 行159-175（8+1 矩阵数据）
u32×2, Quaternion               # 行177-181
```
**B. 内存后处理（182-329，零 filer 读取）**：矩阵拷贝+奇异修复 → `FUN_180260700(items, N)`
   建文本项数组 → do-loop 填充（数据源=前缀字段 [未完全映射 → U13a]）
**C. 文本项循环（333-654，seek 随机访问模型）**：
```
base = tell()（元素数据基址）
for i in 0..N-1:
    off = item[i].vt+0x60()          # 相对偏移 u16
    if off == -1 → skip
    seek(base + off, abs)             # ← 跳转读取
    if item.vt+0xa0() != 0:
        FUN_18025f040 → 文本串        # rdAnsiString(0x138) 或 rdUnicodeString(0x130)
                                       # + seek(1-i,rel) 1字节模式调整
收尾: seek(base); if tell&1 → rdInt8; [disp.bit11 决定 2d/3d 矩阵拷贝]; vt+0x880
```
**D. kUndo(=2) 分支**（345-354, 425 附近条件）：rdBytes/seek 组合 —— 读路径跳过

**结论**：Dimension = **前缀200B + 按项偏移跳转的长度前缀字符串**
（`rdAnsiString/rdUnicodeString` 原语，非手拼长度）；linkage 定位不受影响
（bodyWords 来自头部 size 字段而非 filer 游标）。

### 第19轮：U13 闭合（Dimension 落码）

- **逐点读取器 `FUN_1802a37b0`（37行，全读序列）**：
  `DimensionPoint = Point3d(24B) + f64×2(16B) + u16×2(4B) + u32(4B) = **48B**`
  [推断映射: D1/D2= elevation/rotation 等；Off=u16 文本相对偏移；Flag/Flags 语义待样例]
- **N = 第4个 u8**（存 @0x23f，行132）—— 修正此前"第6个"之误
- **顺序模型定稿**：`前缀188B → 内存矩阵修复 → N×48B 点 → 按点 Off 跳转读文本串 → seek(base)+pad`
- **串模式（dimstr.c）**：先 `rdAnsiString`；若内容为 `FF,FE,…` 前缀 → 回绕改读
  `rdUnicodeString`（BOM 检测）；否则按 codepage 逐字节拓宽（field@0x260<0x100 分支）
- **Go 落码**：`ReadDimension`（前缀+N点+Rest 排空）+ **wildcard 注册**
  （dispatch 新增 `RegisterWildcard(type,group)`——GroupSub 单解码器覆盖全 23 子类）

**剩余（U13b）**：文本串体（rdAnsi/rdUnicode 的长度前缀格式未反编译）与 type33 的
linkage 区位置（v1 已将 Rest 排空规避误解析）；行460-997 尾段仅 undo/收尾，文件路径已闭合

### Multiline(36)
- 解码器 `EMultiLine::vftable[36] = 1801707e0`（401 行，[33]=普通头）
- 骨架：`u32, u16, u8×4, u16, rdInt8×2, f64×2, i64, f64, u32×18, f64×4, u32, Point3d,
  u32, u16×2, u32×2 …` + **顶点循环**（每顶点0x50B 分配）
- 同样 → 排队专属子轮次；当前 Proxy

### 提取顺序建议
`180257e60`(Dimension) → `1801707e0`(Multiline) → Table(95/96) → Boundary(25) → LibraryCell(1)

## 11. P1 第六批（第20轮：Multiline(36) 落码 — 最后大件闭合）

**完整序列（kFileFiler，`EMultiLine::dgnInFields @1801707e0` + 尾钩 `FUN_180174080`）**
```
前缀 152B:  f64×2, u32, u16(顶点数M), u8×4([1]=段数N, [3]=断点数K),
            u16, i8×3(定长循环), i8, f64, i64, f64, u32×18, f64×3
N × 32B 段:  f64 + u32×6                    (bound = u8@U8[1])
M × 40B 顶点: Point3d + u32 + u16×2 + u32×2  (bound = u16@0x234)
K × 32B 断点: u32×2 + f64×3                  (bound = u8@0x239，FUN_174080 无条件循环)
[内存后处理循环 ×2（零读取）]
```
- 修正点：行60-65 的 do-while 实为 **固定3次**（lVar21=3 递减），非"读到0"
- type36 ∈ GroupNone → `pn(36)` 注册；`ReadMultiline` 含三段越界防护
- 字段语义（M1/M2/W[18]/Selector 等）[推断，E1 `DgMultiline.h` 对照待样例]

## 12. 收尾批次（第21轮：U13b 串格式 + 余量清单）

**U13b 解（D46）— `rdAnsiString @18001f0d0` 两模式**
- `maxLen < 0`（Text/Dimension 使用 -1）：**读到 NUL 终止**（`do rdUInt8 while !=0`）
- `maxLen > 0`：定长 `rdBytes(maxLen)`
- `rdUnicodeString(-1)` 同构（UTF-16 码元直到 0x0000）
- **Go 落码 `ReadDString`**：peek 2 字节 → `FF,FE` → UTF-16(NUL 终止, 跳 BOM)；
  否则 ANSI(NUL 终止) —— 即 dimstr.c 的 BOM 检测模型

**余量（诚实清单，均已有定位）**
| 项 | 状态 | 说明 |
|---|---|---|
| Boundary(25) | u32×2 已读；**尾循环读取方式未核**（疑 helper 内读）→ Proxy | 下轮补1读 |
| Table(95/96) | OdDgTableElementImpl vtable 已知；slot36 未取 | 小件 |
| LibraryCell(1) | rtti 无独立 impl（疑复用 ECell 或弃用类型）→ Proxy | 待考证 |
| Dimension 文本串 | `ReadDString` 已备；按 Off 跳转读取逻辑待接入（U13b-接线） | 小件 |

## 13. 收官批次（第22轮：真实样例 + Boundary/TableEntry）

| 项 | 结果 |
|---|---|
| **真实样例** | 发现 GDAL `seed_2d.dgn/seed_3d.dgn`（多副本）→ 验明为 **DGN v7**（magic 08 09 fe 02 / c8 09 fe 02） |
| **v7 拒绝路径实测** | ✅ `TestRealV7SeedsRejected`：两枚真实文件均正确返回 `ErrUnsupportedV7`（**首个真实文件级测试**） |
| Boundary(25) | ✅ `u32, u32(=count), count×Point2d`（尾读 slot0x100 定位）→ `ReadBSplineBoundary` |
| TableEntry(95) | ✅ 体=**按头部 B 字段的剩余 blob**（`need=B*2+4-off`，off∈{0x24,0x6c} 同 C4 规则；filerType≠0 委托 vt+0x600）→ `ReadTableEntry`(Rest) |
| TableHeader(96) | ⬜ impl 类未现身（pseudoCtor 被 ICF 合并至 0x180003500 百符号共享块；ObjectWithImpl 对缺失）→ **线索已录，Proxy 兜底** |
| LibraryCell(1) | ⬜ rtti/functions 零命中（疑复用 ECell 或弃用）→ Proxy |

## 14. 二期首批（第23轮：表族 type96 —— 注册映射全解）

**注册函数**：`FUN_180137ee0(map, type, variant, desc)`，从9个表类 `rxInit` 提取立即数：

| (96, variant) | 表类 | 解码器 | 序列 | Go |
|---:|---|---|---|---|
| **1** | LevelTable | `1805fd430` | u16×2, i64, f64×2（28B） | ✅ `ReadTableLevelHeader` |
| **2** | FontTable | `1801f07b0`（共享） | 剩余 blob 全读 | ✅ `ReadTableBlob` |
| **3** | TextStyleTable | 同上 | 同上 | ✅ 同上 |
| **5** | DimStyleTable | 同上 | 同上 | ✅ 同上 |
| **6** | MultilineStyleTable | `180559830` | u16(id)+**5×u16 保留**（12B，D72 勘误：原"u16×2/4B"） | ✅ `ReadTableMLStyleHeader` |
| **10** | RegAppTable | `1801f07b0` | 同上 | ✅ `ReadTableBlob` |
| — | ModelTable/SharedCellDef/OdDgTable | 注册 `(0xffff,0xff)` = **不入表** | — | → Proxy ✓ |

- 表头均为**复杂元素**（[33]=CDGComplexGeneral）→ 行数据=子条目（C4 跨度）
- `ps(type, variant, fn)` 精确键注册落地；测试含 **Sub=0 → Proxy 负向用例**
- 新工具 `DumpDgnClassMap.java`（静态区为零故改走 rxInit 注册侧——方法论入档：
  **注册映射 = rxInit 立即数**）
- 95 TableEntry 已注册（前轮）→ **type95/96 表族读取路径闭环**

## 14. 第28-29轮：U14 关闭（Arc 字段序定案）

- **ASM 计数**：Arc3d = `4×rdDouble + Quaternion + Point3d + hook(0x650)` = **88B**
  （此前 bodies3d 的 awk 漏了十进制槽位 200 → 已勘误）
- **getter 四连证（EArc3D impl 字段直读）**：
  `getStartAngle→0x220 · getSweepAngle→0x228 · getPrimaryAxis→0x230 · getSecondaryAxis→0x238`
  ⇒ **文件读取序 = [start, sweep, primary, secondary] + rotation(quat) + origin**
- **Arc2d 同构**：5 double 同序（+rotation@0x250）+ origin
- Go 已修正：`Arc{Start,Sweep,Primary,Secondary,Rotation,Origin}`、
  `Arc3d{Start,Sweep,Primary,Secondary,Rotation(quat),Origin}` + 测试重写 ✅
- hook `vt+0x650=@1802872b0` 仅置标志位（非角度计算）→ 角度=文件直读，**无派生**
- ~~**遗留 [?]：Ellipse 字段文件序**~~ ✅ **第35轮 D63 关闭（getter 全程四连证）**：
  公开 API→RTDynamicCast→impl 槽位→字段直读 ——
  getPrimaryAxis→vt+0x600→impl+0x220 · getSecondaryAxis→+0x610→0x228 ·
  **getRotationAngle**(2D 实名)→+0x638→0x240（FUN_1801d7b00 返回字段地址，调用方解引用）·
  getRotation3d→FUN_1801d7ae0 读 0x240..0x260（含**十进制 600=0x258 槽位**陷阱，同 U14 勘误病）·
  getOrigin3d→+0x638→0x260；fields `1801d8de0/1801d8e60` 存储序与偏移对齐 ⇒
  **Ellipse2d = primary, secondary, rotation, origin（40B，godgn 现序正确 ✓）**、
  **Ellipse3d = f64×2 + Quaternion + Pt3d = 72B**（勘误：旧 bodies3d 表 56B 漏读前2双，
  Go `ReadEllipse3d` 已补 primary/secondary + 测试重写）；
  Arc 交叉复核 getStartAngle→+0x600→0x220 ✓ 与 D56 吻合
  （证据 `TG_Db.{ellipse,ellpub,ellpub2,ellrot}.c`）
- GDAL 交叉验证表中 "Arc2d 悬案" 更新为：**起/扫角在文件序最前两位**（修正记录）
