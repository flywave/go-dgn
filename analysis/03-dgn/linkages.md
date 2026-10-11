# DGN Linkage / XAttribute 格式（第 5 轮收口）

**证据**：E2 `TG_Db.linkblob.c`（`OdDgLinkageData::readData @1808b4040` /
`writeData @1808b4820`）、`TG_Db.dgnIn.c`（`CDGElementGeneral::dgnInLinkages @180115f60` 头部）、
导出表（36 个 `readData@…XAttr*`）。

## 1. linkage 区在元素记录中的位置

`dgnInLinkages(this, filer, elemBase)`（`180115f60` L380-407）：

```
bodyWords  = *(this+200)        # 元素体已消费的 16-bit 字数 ← **= 头 C u32@12（D65）**
totalWords = *(this+0xc4)       # 元素总字数（含 linkage 区） ← **= 头 B u32@8（D65）**
if totalWords > bodyWords:
    off  = elemBase + bodyWords*2 + 4      # ← linkage 区起始 = C*2+4（4 字节前缀之后）
    size = (totalWords - bodyWords) * 2    # ← 区长（字节）= (B−C)*2
    filer->seek(off, 0); rdBytes(buf, size)
    OdDgLinkageData::readData(this+0x20, buf, size)   # 原始 blob → map<u16,item>
else:
    空 linkage → 重置默认值（颜色/线型/变换默认表，L417-446）
之后按 id 取出应用：FUN_1801cb730(this, 0x56e9, …)（如 0x56e9=渐变相关）
```

> **D65 字段定案**：`GetAttribSizeFromHeader @1800080f0 = (obj+0x14 − obj+0x18)*2 = (B−C)*2`
> 与 dgnInLinkages 的 `(totalWords−bodyWords)*2` 同构 ⇒ 映射成立；
> 元素总长 = **B*2+4**（D32：LINE 68B→B=32 独立吻合）；
> **勘误**：D64 曾标 "C=元素字数(size=C*2+4)" —— C 实为**属性区前字数**（隐式 disp
> 判定用的正是这个 C，行为不变）。
> **godgn**：`parse.go` 按 B/C 精确切分 linkage 区（ODA 语义：seek 独立于体解码进度；
> B/C 无效时回退 Rest+对齐）+ 区分测试（type27 体区46B 仅解码12B：旧路径丢首记录，新路径 3 条全对）。

## 2. linkage blob 记录格式（核心，readData 反编译）

blob 为**顺序 TLV 序列**，游标步进，越界即停（L40-57）：

```
p 处起：hdr32 = u32le(p)                          # 读 4 字节头（需余量≥4）
模式判定（谓词=首 u16 位域，第 6 轮已解 U9：`getUserDataFlag=bit12`、`getRemoteFlag=bit14`）：
  A: vtbl[6]==false              → len = 8                       # 固定 8B 记录
  B: vtbl[6]==true && vtbl[7]==false → len = (u8)(hdr32) *2 + 2  # count 字节模式
  C: vtbl[6]==true && vtbl[7]==true  → len = (2 << ((hdr32>>8)&0xf)) * (u8)(hdr32)
                                        # 指数模式：2<<(nibble) * count
  len==0 → 用剩余全长收尾
若 p+len > end → 返回（截断安全）
key/typeId = (vtbl[6] && (hdr32>>16)!=0) ? u16(hdr32>>16) : 0    # **类型 id = 头高 16 位**
整条记录（p..p+len）memcpy 为 item → 插入 std::map<u16 type, item>（同 id 覆盖/树插入）
```

**Go 直译**：
```go
type LinkageRec struct { TypeID uint16; Raw []byte }   // Raw 含 4B 头
func iterLinkageBlob(b []byte) []LinkageRec            // 三种长度模式 + 越界即停
```
- **U9 已解（E2 1808b4030/1808b4000/1808b3f60/1808b3fd0）**：
  `hdr16 = le16(p[0:2])`；`count = hdr16&0xff`；`nibble = (hdr16>>8)&0xf`；
  `userData = (hdr16>>12)&1`（0 → 模式A 8字节）；`remote = (hdr16>>14)&1`（1→C,0→B）；
  `typeID = le16(p[2:4])` 仅当 userData=1（否则强制 0）。
  Go 实现已落地：`dgn/linkage/blob.go`（测试覆盖 A/B/C、截断、count=0 余量收尾）

**writeData @1808b4820**（同文件 L138-230）为对称写出，验证长度公式用。

## 3. 类型化解码层

- **XAttribute**：blob 内 id 命中 XAttribute 类 → `readData@OdDgXxxXAttribute(this, bytes, len)`
  共 36 个导出（Acs/BinXML/ColorBook/Terrain×N/SectionClip/String/Template/…，
  `evidence/exports/TG_Db.tx.exports.txt` 过滤 `readData@…XAttr`）；另有
  `OdDgExtendedElementTypeXAttribute`（type107 扩展类型，见 directory.md C10）。
- **普通 linkage**（OdDgAttributeLinkage 家族，`element-types`/`cast@OdDg*Linkage` 清单 40+ 类）
  的字段解码位于 `dgnInLinkages` 主体（`180115f60`，1070 行，L469+ 逐 id 分支）——
  **首批实现建议**：先做 blob 迭代 + 未识别 id 原样保留，再按需下钻单个 id 的字段布局。
- 公开 API 对照（E1 `DgAttributeLinkage.h`）：`OdDgElement::getLinkages/getXAttributes/getStringLinkage`。

## 4. 未知

- ~~U9~~ ✅ 位域已解（见 §2；Go 已实现）
- **U10**：各 linkage type id → 字段布局的逐个映射（从 `180115f60` 各 case 展开，按需做）

## 5. U10 主体（第24轮：ID 表 + 架构定性）

**架构定性（E1+E2 交叉）**
- **泛型存储 = raw 持有**：`linkage.Iter` 的 `Rec.Raw` 即完整记录（含4B头）——对象层
  `OdDgAttributeLinkageHeader` 的 accessor（`getPrimaryId/getLinkageDataSize/bit12/bit14`，
  D25/U9 已解）直接在 raw 上位运算，**无需集中字段解析**
- **`dgnInLinkages` 大级联（1070L 中的 L447-1346）= 属性应用层**：7 个特判 ID 取出后
  配合 desc() 把 Pattern/Thickness/Material/Gradient/Display… 应用到元素符号状态
  （读库复现渲染态用，v1 解析器可选实现）
- **7 特判 ID ↔ E1 枚举交叉吻合**：`0x56e9=kInfiniteLine, 0x56d4=kThickness,
  0x7d28=kHatch, 0x56d0=kDependency, 0x56d2=kString, 0x4f5a=kExternalMaterial,
  0x41=kFillStyle`（proximity 猜测的 Transparency 被枚举纠正——以 E1 为准）

**ID 表（Go 已落码）**
- `dgn/linkage.PrimaryIDs`：**42 个 PrimaryIds**（E1 `DgAttributeLinkage.h:60-107` 全量：
  DMRS/DB族/SeedPoints/Note/SharedCellFlags/Dimension/Sheet族/…）
- `dgn/xattr.TypeIDs`：**53 个 XAttribute 32-bit 类型**（E1 `DgXAttribute.h` 逐类 `kType`
  自动提取——与 linkage 16位 ID 是**两套命名空间**，DGN 实证 0x56ec0000 式）
- 测试：关键 ID 抽查 + 负向

**U10b 第一批已解（D88）**：39 项 oddgSetLinkageHandler 黄金表 + 11 类 payload 定案（SeedPoints/Thickness/InfiniteLine/SharedCellFlags/SheetScale/DoubleArray/String/ByteArray/AssocRegion/FillStyle 族分发器/Note）→ godgn `dgn/linkage/payload.go`；- **U10b 第二批已解（D89）**：handler 层 39/39 全定性（HandlerNames 表）；DBLinkage 族
  （10 ID+DBType 枚举）/BitMask（byte@4==6→TextWhiteSpace）/Dependency（variant 选择器）/DMRS 记档
- **U10b 第三批已解（D90）**：类委托型 Impl 读取器 12 个解码器落地
  （TextAnnotation/RefAttachPath/SheetModelEx/Xml/FilterMember/BoundaryClip/
  LStyleMod/SheetModel/Ole/TextIndentation/DimTextStyle/Material）；
  **U10b 收口：35 typed + 4 documented-raw（DMRS/Dimension/Hatch/Brep）**
——候选路径：各 OdDg*Linkage 的 getter 反解或级联内逐 case；按需逐个下钻
