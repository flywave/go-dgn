# DGN 元素头（SElementHeader）字节布局

**证据**：E2 反编译 `CDGElmHeader::dgnInFields @1808b3a20` → 调 `FUN_1808c5240 @1808c5240`  
（原始头读取）；`CDGDispHeader::dgnInFields @18081e3a0` 提供字段语义反证。  
读取原语映射见 `filer-api.md`（vtable slot）。

## 1. 文件层读取序列（FUN_1808c5240，kFileFiler 路径）

| 顺序 | 原语(slot)                                 | 宽度 | **文件偏移** | 语义（D64 定案/未定）                                                                                  |
| -: | ---------------------------------------- | -: | ---------- | ------------------------------------------------------------------------------------------------ |
|  1 | rdInt32 (0xb0)                           |  4 | 0          | [?] A 字段                                                                                            |
|  2 | rdInt16 (0xa8→存 int)                     |  2 | 4          | ✅ **element type**（DispHeader 判 `*(int*)(obj+0xc)` ↔ 存储于 obj+12）                                       |
|  3 | rdInt16 (0xa8→存 u16)                     |  2 | 6          | ✅ **flag**（bit12=display/bit13=complex/bit14=extra4；DispHeader 判 `u16(obj+0x10)`，存储因 type 展宽后有 pad）       |
|  4 | rdInt32 (0xb0)                           |  4 | 8          | [?] B 字段                                                                                            |
|  5 | rdInt32 (0xb0)                           |  4 | 12         | ✅ **C = 元素字数**（obj+0x18；size=C*2+4；type35 隐式显示头 `C*2≥0x100` 用它）                                    |
|  6 | rdInt32 (0xb0)                           |  4 | 16         | ✅ **Sub = level entry id**（`SetElementLevelID` 写 obj+0x1c=Sub；D64）                                    |
|  7 | rdInt64 (0xb8)                           |  8 | 20         | [?] ID/handle（clone 时 kCopy/kWblock 路径清零）                                                          |
|  8 | slot 0xc8（按 rdDouble 读，raw 8B）          |  8 | 28         | [?] Tail                                                                                             |

> ⚠️ 勘误（D64）：旧表 "内存字段" 列用 obj−8 推算文件偏移，自第 3 行起因 type 展宽/对齐 padding **错位 +2**；
> 上表已按读取宽度累计重排（0,4,6,8,12,16,20,28）。文件侧合计 **36 字节**（内存40字节）。

## 2. 按 filer 类型的行为分叉（对 Go 解析器=只关心 kFileFiler=0）

E1 `DgFiler.h:51` `OdDgFiler::FilerType`：`kFileFiler=0, kCopyFiler=1, kUndoFiler=2,
kIdXlateFiler=4, kDeepCloneFiler=6, kWblockCloneFiler=9, k2dTo3d=10, k3dTo2d=11`

- `CDGElmHeader::dgnInFields`：`filerType==1(kCopy) || ==9(kWblockClone)` → raw+24 清零（clone 不搬 ID）
- `CDGElementGeneral::dgnInHeader @180115f00`：`filerType==6(kDeepClone)` → 先 rdAddress/8B 搬 ID
- `ECell<OdDgFiler3d>::dgnInFields @180010c10`：`filerType==2(kUndo)` → 额外读 ID 列表（rdInt32 计数 + 循环 8B ID）
- `OdDgElement::dgnIn @1801c5980`：`filerType==9(kWblockClone)` → 写回 handle
- **kFileFiler=0：无附加分支 = 纯文件布局** ✅

## 3. 元素通用读取骨架（OdDgElement::dgnIn @1801c5980）

```
filerType = filer.vt(0x58)
impl.dgnInHeader(filer)            # → CDGElementGeneral::dgnInHeader → FUN_1808c5240(raw header)
if filerType==9: impl.writeHandle(elementId)
result = impl.vt(0x108)            # dgnInFields(元素体)
if result==0:
    element.vt(0x198)(filer)       # 后处理/校验
    if filer.vt(0x80)(): filer.vt(0x98)()
    impl.vt(0x180)(filer, type)    # → dgnInLinkages(filer, size)（间接跳转，Ghidra 未恢复跳表）
```

- 复杂元素：`CDGComplexGeneral::dgnInHeader @180115e80` 在读完头后  
  `if IsComplexHeader: filer.vt(0xb0)` 再读一个 u32（**子元素计数或长度，未定**）。

## 4. 显示头（CDGDispHeader；D64 语义定案）

`CDGDispHeader::dgnInFields @18081e3a0`：

1. 先复用 `CDGElmHeader::dgnInFields`（36B 头）
2. **是否读显示头（decompile 原文为准）**：
   `skip = (flag.bit12==0 || type==100) && (type!=35 || C*2 < 0x100)`
   即 **读 disp ⟺ ¬skip**：
   - type≠100 且 bit12=1 → 读
   - type=35 且 C*2≥256 → 读（bit12 无关，隐式）
   - **type=100（参照附件头 XREF）→ 永不读**（勘误：旧表 "`&& type!=100`" 系转录笔误，
     旧文"type=100/35 专用"对 100 反了；`dir.go` 早有 `&& type!=100` 旁证；
     godgn `parse.go` 已按此修正 + 测试）
3. 分配 disp 结构并 `FUN_1808c5150(obj+0x30, filer)` 读 **72B**，随后 `is3dFlagUndefined=0`：

| 文件偏移 | 原语 | 语义（CDGDispHeader getter 链，证据 `TG_Db.disphdr.c`） |
|---|---|---|
| 0 | i32 | **GraphicsGroup**（GetGraphicsGroup；无 disp→0xFFFFFFFF） |
| 4 | i32 | **Priority**（getPriority） |
| 8 | u16 | **Properties/flags**（GetProperties 整字返回）：bits0-3=**class**、bit7=**invisible**、bit11=**3D format**（=parse.go ext 来源）、bit12=**viewIndependent**、bit13=**nonPlanar**、bit14=**notSnappable**、bit15=**hbit** |
| 10 | u16 | **[?] 未命名** |
| 12 | i32 | **LineStyle**（GetLineStyle；无 disp→0x7FFFFFFF） |
| 16 | u32 | **LineWeight**（GetLineWeight；默认 1，见 dgnInFields 分配默认值） |
| 20 | u32 | **Color**（GetColor；默认 0，无 disp→0xFFFFFFFF） |
| 24..72 | i64×6 | **Range**（GetRange→`SIntRange3D`：**min.xyz + extent.xyz**；`FUN_1808bd8b0`：bb.max=min+extent —— 后三为**尺寸**非 max（D66）；有 disp 无 buf 时 GetBoundingBox 报错） |
| +72 | u8 | 结构外标志（is3dFlagUndefined 初值 1，读成功后清 0；get3dFormatFlag 无 disp 时默认 true） |

- **getHeaderDataSize = 36 或 108**（有 disp）；**getFieldDataSize = (C*2+4) − 前缀 = 纯体字节**（D66 再证 C 语义）
- **IsDispHeaderPresent(CDGElmHeader) = bit12 && type≠100**（不含 type35 隐式 —— 隐式仅在 dgnInFields 判定内，D66）
- GetURL/GetURLTitle = 空串 stub（不在 72B 内）
- 默认分配值：GG=0、priority=0、props=0、lineStyle=0、**weight=1**、color=0、range=0

## 5. 头字段语义（D64 部分定案）与待办

- ~~✅ `B u32@8`~~ → **= 总字数**（size=B*2+4；D32 LINE 68B→B=32 + D65 `GetAttribSizeFromHeader`；D65）
- ~~✅ `C u32@12`~~ → **= 属性区前字数**（body 止于 C*2+4；attrib=(B−C)*2；
  隐式显示头判定 `C*2≥0x100` 用它 —— 勘误 D64 "C=元素字数"标签，行为不变）（D65）
- ✅ `Flag u16@6` bit12/13/14（既有）
- ~~✅ `Sub u32@16` = **level entry id**~~（`SetElementLevelID` 写 obj+0x1c=Sub；
  元素侧 `CDGElementGeneral::GetLevelID` 缓存 +0xcc，`SetLevelID`→header 槽 0x40 转发）（D64）
- ✅ `Tail@28` = **f64 时间戳**（OdTimeStamp packedValue×1000；`FUN_1808c4f00`，ctor 默认同公式；
  rdDouble 读法成因 ✓）（D66）
- ✅ `ID u64@20` = element unique id（`SetElementUniqueID`→obj+0x20）（D64/66）
- ✅ `Flag u16@6` bit10=nonModel、bit11=locked、bit12/13/14（GetNonModel/GetLocked D66）
- ✅ `GetElementDeletedByComplexHeader` = **恒 0 stub**（v8 无逐元素删除位，D66）
- [?] `A u32@0`（ctor 置 0，无 getter 命中）、显示头 u16@10（所有具名 getter 未触碰）
- ~~[ ] `CDGElmHeader::GetHeaderPtr/GetAttribSizeFromHeader`~~ ✅ attrib 已由 B/C 定位（D65）
- [ ] 用真实 v8 样例文件验证（当前无样例；36/72 字节布局已有反编译直证）
