# OdDgFiler / OdDgFileFiler 序列化接口（Go bitstream 层的直接蓝本）

**证据**：E1 `DgFiler.h`（公开接口 + FilerType 枚举）；E2 vtable 转储  
`evidence/ghidra/out/TG_Db.vtables.txt`（`??_7OdDgFileFiler@@6B@ @180a29ed8`，  
Ghidra 从导出符号解析每个槽位）+ 反编译调用点交叉验证（见下表"实证"列）。

## 1. OdDgFileFiler vtable 槽位表（slot → 方法）

|  slot |          偏移 | 方法                                                                                                                 | 实证（反编译调用点）                                                                                                              |
| ----: | ----------: | ------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------- |
|    11 |        0x58 | `filerType() : FilerType`                                                                                          | 与 `GetElementDeletedByComplexHeader` ICF 合并；导出符号 `?filerType@OdDgFileFiler@@UEBA?AW4FilerType@…` 同址；调用点与 0/1/2/6/9 比较 ✅ |
|    12 |        0x60 | `database()`                                                                                                       |                                                                                                                         |
|    14 |        0x70 | `getController()`                                                                                                  |                                                                                                                         |
|    15 |        0x78 | `seek(pos, FilerSeekType)`                                                                                         | `FUN_1809e6c20` 用 +0x78 打开具名流 ✅                                                                                         |
|    16 |        0x80 | `tell() : ulong`                                                                                                   | `OdDgElement::dgnIn` 中取值当 flags ✅                                                                                       |
|    17 |        0x88 | `length()`                                                                                                         |                                                                                                                         |
|    18 |        0x90 | `rdBytes(void*, n)`                                                                                                |                                                                                                                         |
|    19 |        0x98 | `rdInt8`                                                                                                           |                                                                                                                         |
|    20 |        0xa0 | `rdUInt8`                                                                                                          |                                                                                                                         |
|    21 |        0xa8 | `rdInt16`                                                                                                          | ECell/头读取 2B ✅                                                                                                          |
|    22 |        0xb0 | `rdInt32`                                                                                                          | 头读取 4B ✅                                                                                                                |
|    23 |        0xb8 | `rdInt64`                                                                                                          | ID 循环 8B ✅                                                                                                              |
|    24 |        0xc0 | `rdDouble`                                                                                                         |                                                                                                                         |
|    25 |        0xc8 | `rdDouble`(重载/别名，18001f380)                                                                                        | ECell 矩阵 9×8B ✅；**与 slot24 区别未定**                                                                                       |
|    26 |        0xd0 | `rdDbHandle`                                                                                                       |                                                                                                                         |
| 27-30 |   0xd8-0xf0 | `rdHardOwnershipId / rdHardPointerId / rdSoftOwnershipId / rdSoftPointerId`（同址 18001f400，ICF）                      |                                                                                                                         |
| 31-32 |  0xf8-0x100 | `rdPoint2d`（Vector2d/Point2d 变体）                                                                                   |                                                                                                                         |
| 33-34 | 0x108-0x110 | `rdPoint3d`（Point3d/Vector3d 变体）                                                                                   | slot34=0x110：ECell 读 24B ✅                                                                                              |
| 35-36 | 0x118-0x120 | `rdPoint2d/rdPoint3d`（其余变体）                                                                                        |                                                                                                                         |
|    37 |       0x128 | `rdQuaternion`                                                                                                     |                                                                                                                         |
|    38 |       0x130 | `rdUnicodeString`                                                                                                  |                                                                                                                         |
|    39 |       0x138 | `rdAnsiString`                                                                                                     |                                                                                                                         |
| 40-58 | 0x140-0x1d0 | `wr*` 镜像（wrBytes/wrInt8/16/32/64/wrDouble/wrDbHandle/wr*Id/wrPoint2d/3d/wrQuaternion/wrUnicodeString/wrAnsiString） |                                                                                                                         |
|    59 |       0x1d8 | `rdAddress`                                                                                                        |                                                                                                                         |
|    60 |       0x1e0 | `wrAddress`                                                                                                        |                                                                                                                         |
|    61 |       0x1e8 | `rdFloat`                                                                                                          |                                                                                                                         |
|    62 |       0x1f0 | `wrFloat`                                                                                                          |                                                                                                                         |

> 说明：slot0-10 为 OdRxObject 基础（isA/queryX/desc/numRefs/clone/copyFrom/comparedTo/isEqualTo…）。  
> 多个槽位因 ICF（identical code folding）共享同一函数地址，表中以导出符号为准。

## 2. FilerType（E1 `DgFiler.h:51`）

```
kFileFiler=0  kCopyFiler=1  kUndoFiler=2  kIdXlateFiler=4
kDeepCloneFiler=6  kWblockCloneFiler=9  k2dTo3dFiler=10  k3dTo2dFiler=11
```

**Go 解析器只需实现 kFileFiler 语义**（无附加分支）。

## 3. 序列化方法族（E2 导出表，TG_Db）

- `OdDgElement::dgnIn(filer)` / `dgnInFields(filer)` / `dgnOut` / `dgnOutFields` — 元素级
- `CDGElementGeneral::dgnInHeader / dgnInLinkages(filer, size) / dgnInXAttributes` — 头/链接/扩展
- 22 个类实现 `dgnInFields`（`evidence/exports/TG_Db.tx.exports.txt` 过滤）
- 具体元素体解码器多数**未导出**（虚函数经 vtable 分发），需按调用图下钻

## 4. 元素体字段读取实例（可直接照抄为 Go struct tag）

`ECell<OdDgFiler3d>::dgnInFields @180010c10`（单元/块头元素体）：

```
u16 ×2            → raw+0x240, +0x242
Point3d(24B)      → raw+0x248        (slot 0x110)
Point3d(24B)      → raw+0x260
double ×9         → raw+0x278..0x2c0 (slot 0xc8)   ← 变换矩阵
double ×8         → raw+0x2c8..      （同批继续读至 ~0x2f4）
Point3d(24B)      → raw+0x2f8
if filerType==kUndo(2):
    u32 count = rdInt32; 循环 count: rdInt64→elementId 列表
```

`OdDgMultilineProfile::dgnInFields @1801e2cc0`：`double + u32×5`。  
`OdDgHLineSymbology::dgnInFields @1801e2d50`：`u32×5`。  
`ESharedCellInst::dgnInFields @1801f4c00`：`u32, u16, u16, Point3d?, Point3d?, …`（部分读）

## 5. Go 映射建议

```go
type Filer interface {   // 对应 OdDgFiler
    FilerType() FilerType
    RdInt8/16/32/64() …; RdDouble/Float(); RdPoint2d/3d()
    RdUnicodeString() (string, error); RdBytes(n int) ([]byte, error)
    RdDbHandle() (Handle, error); RdAddress() …
    Seek/Tell/Length()
}
// FileFiler: 基于 io.ReaderAt + 顺序游标；字符串编码按 DGN v8 约定（待 U6 确认 codepage）
```
