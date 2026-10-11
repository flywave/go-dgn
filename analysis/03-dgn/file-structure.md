# DGN 文件级结构（v8 容器 + 读取管线）

**证据等级**：E1=头文件源码；E2=TG_Db.tx Ghidra 12.1.4 反编译（地址均在 `evidence/ghidra/out/`，  
program: `TG_Db_25.4_lic16.tx` sha256=7c3b7d5a…）；E3=公开知识交叉。

## 1. 结论表

| #  | 结论                                                                                                                          | 证据                                                                                                                                                                                                                                                                                                   | 置信度             |
| -- | --------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------- |
| F1 | **DGN v8 文件 = OLE/CFB 结构化存储容器**（多命名流）                                                                                       | E2 `FUN_1809ebdc0 @1809ebdc0` 调用 `openStructuredStorageEx(path,0,&storage)`；该符号由 `oless.dll` 导出（导出表：`openStructuredStorageEx/openStream/openStorage/getChildrenInfo/streamRead/…`）；oless.dll 内部含 DIFAT/FAT/MiniFAT/目录扇区完整实现（strings：`fatNextFreeSector`、`directoryGetStartSector`、`calcReqdSectors`） | 高（观察）           |
| F2 | **版本探测 = 先试 v8 容器，失败则回落 v7**                                                                                                | E2 `OdDgDatabase::readFile @180536190`：`FUN_1809e96b0` 返回 null → 加载模块 `TG_Dgn7IO`（OdDgn7IOModule vtable+0x88），并写 `(impl+0xbb4)=7`；否则走 v8 分支，且 `7 < (impl+0xbb4)` 触发 v8 后处理 `FUN_18058be10`                                                                                                           | 高（观察）           |
| F3 | v8 主数据在**一个具名流**中（符号 `szDgnULCStream`）                                                                                      | E2 `FUN_1809e6c20 @1809e6c20`：`file->vt+0x78(&s, &szDgnULCStream)`；打开失败抛错 0x1af                                                                                                                                                                                                                      | 中（流名字面值未定，见 U2） |
| F4 | v8 加载顺序（流内解析顺序，Go 解析器可按此分层）                                                                                                 | E2 `FUN_1809e6c20`：`OdDgDesignFileHeaderData::read(impl+0x548)` → `OdDgProxyChunk::read(+0xb90)` → `FUN_1805507b0(+0x4d0)` → `FUN_180550660(+0x4d8)` → `OdDgProxyChunk::read(+0xba0)` → `FUN_1809e5830(loader)` → `FUN_18058c130(impl)` → 收尾 `FUN_1809e68a0/…fa0/…bd0`                               | 中（各子函数内部待反编译）   |
| F5 | 读取完成后触发 `fire_dgnFileOpened` / `fire_initialDgnFileOpenComplete`，可选 `OdDgDatabaseRecoveryPE`                                | E2 `readFile @180536190/180536180`                                                                                                                                                                                                                                                                   | 高               |
| F6 | v7 路径完全隔离在 `TG_Dgn7IO.tx`；其内部含 `OdDgConvertV7ToV8Thread`、`I_dgMicroStationTCB/CIsffMicroStationTCB`（MicroStation TCB=老式控制块） | E2 RTTI（`evidence/exports/TG_Dgn7IO.tx.rtti.txt`）+ F2                                                                                                                                                                                                                                                | 高               |

## 2. 读取管线（反编译还原，v8）

```
OdDgDatabase::readFile(filename, FileShareMode, bool)          @180536190
 ├─ impl+0x519=1(read中)  impl+0x51a=bool  impl+0xd10=?(partial)
 ├─ [可选] ThreadPool 模块判定
 ├─ FUN_1809e96b0(&ctrl, filename, …)                    # 尝试 v8
 │    ├─ odrxAlloc OdDgFile；FUN_1809d83c0 构造(OdDgBaseBlock vtable, OdString name)
 │    ├─ FUN_1809ebdc0: openStructuredStorageEx(path,0,&storage)
 │    │     └─ 失败 → 返回 null（→ 转 v7）
 │    ├─ OdDgFile::vt+0xb0(ctrl, storage, flag…)
 │    └─ (可选) FUN_1809e9cb0
 ├─ v8 分支: FUN_18052f4e0(创建 loader) + FUN_1809e6c20(loader, file, flag)
 │    ├─ file->vt+0x78(&s, szDgnULCStream)   # 打开主数据流
 │    ├─ DesignFileHeaderData::read / ProxyChunk::read ×2 / +0x4d0 / +0x4d8 / …
 │    └─ 后处理 & 版本字段 (impl+0xbb4) 判定
 └─ v7 分支: odrxDynamicLinker::loadModule("TG_Dgn7IO")
      ├─ OdDgn7IOModule::vt+0x80/0x88 (db, stream|filename)
      └─ impl+0xbb4 = 7
```

**文件版本字段**：`OdDgDatabase 内部 impl+0xbb4`，7=v7，>7=v8（观察自 readFile 判定）。  
公开对应物：`OdDgDatabase::getOriginalFileVersion`（E2 导出）。

## 3. 容器（CFB）证据细节

- `oless.dll`（ODA 自带结构化存储实现，57KB 级）导出完整 CFB API：  
  `openStructuredStorageEx, openStream, openStorage, createStream, createStorage,
   streamRead, streamWrite, getChildrenInfo, getStorageInfo, getStreamInfo,
   getStorageFromRoot, closeStructuredStorage, …`
- oless 内部符号：`calcReqdSectors, directoryGetStartSector, fatAddFatToFreeSectors,
  fatNextFreeSector, fatRecoverMiniFatFreeSectors` → **标准 MS CFB（非私有容器）**
- E3 交叉：公开资料称 DGN v8 基于 MS Structured Storage —— 与 E2 一致。

**Go 实现含义**：直接复用成熟 CFB 解析（如 `github.com/richardlehane/mscfb` 或自写  
sector/directory 层），业务层只需处理 DGN 流内容。

## 4. 未知（详见 findings.md）

- U1: CFB 内**全部流名清单**及各自用途（仅确认1个主数据流符号）
- U2: `szDgnULCStream` 的字面值（UTF-16 扫描候选 `Dgn~ULC`/`DgnULC`，未在流上下文中验证）
- U3: `FUN_1809e6c20` 内各子调用的具体子结构布局
- U4: v7 探测（TG_Dgn7IO 内的文件头识别）尚未反编译

## 5. CFB 流名与 Chunk 类（第 5 轮补充）

**流名（UTF-16 字面量，rdata 簇 0xa2f820–0xa2f900，E2 二进制扫描）**：
`Dgn~H`、`Dgn~Mf`、`Dgn~Mh`、`Dgn~Mix`、`Dgn~S`、`Oda~SH`、`Dgn~ULC`
（`Dgn~ULC` = readFile 主路径 `szDgnULCStream` 打开的流；其余用途[推断]：H=Header、
SH=Summary/Header、Mf/Mh/Mix=模型族流，待样例核 → U1 收窄为"用途确认"）

**Chunk 类（`OdDgChunk::create` 分流，E2 1809e0ab0/1809e8690）**：
| 类 | 对象大小 | 触发条件 | 关键字段 |
|---|---|---|---|
| `OdDgElementChunk` | 0x48=72B | 子节点名以 `'$'`(0x24) 开头 | `[7]`=u32 偏移数组（空表初始化）、+0x44=u16 |
| `OdDgZipChunk` | 0x38=56B | 其余名 | +6=压缩参数(param_3) |
> 目录 offset 数组位于 **OdDgElementChunk[7]**（推翻此前泛称 container）；
> 其从流填充的绑定函数（`chunk->vt+0x88` 实现）仍未定位 → **U7b**（线索：RTTI TD `u_OdDgElementChunk_180a935b0`）
