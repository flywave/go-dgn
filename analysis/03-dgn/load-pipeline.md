# DGN 加载与单元素解码管线（第 2 轮）

**证据**：E2 Ghidra 反编译（program `TG_Db_25.4_lic16.tx`），  
产物 `evidence/ghidra/out/TG_Db.{loop,chunk,chunkio,eloop,struct}.c`；  
xref/offset 扫描 `evidence/ghidra/out/calls-0x188.txt`。

## 1. 本轮结论

| #  | 结论                                                                                                                                                                                                                      | 证据地址                                                                                                                                                                                                                   | 置信度 |
| -- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --- |
| L1 | **CFB 存储的子节点按"名称+数字后缀"枚举，逐个作为 `OdDgChunk` 处理**                                                                                                                                                                          | `FUN_1809e4d70 @1809e4d70`：`storage->vt+0x80`(计数)/`+0x88`(按索引取子)/`+0x58`(取名) → `atol(name.right())` → 排序 `FUN_1809e49d0` → 二次遍历 `OdDgChunk::desc()` 查询 → `loader->vt+0x408/0x410(chunk)`                               | 观察  |
| L2 | **chunk 实现按名称分流**：名首字符 `'$'`(0x24) 选用特殊实现                                                                                                                                                                               | `OdDgChunk::create @1809eab70`：`if (**(short**)(name+0x10) != 0x24 → FUN_1809e8690 else FUN_1809e0ab0`                                                                                                                 | 观察  |
| L3 | chunk 暴露裸字节缓冲：`vt+0x68`=数据指针、`vt+0x70`=长度；`OdDgProxyChunk::read` 直接 memcpy                                                                                                                                              | `180568420`                                                                                                                                                                                                            | 观察  |
| L4 | chunk 可由 **`OdDgOle2Stream`** 构造：`createFromStream` → `stream->vt+0x60(取名)` → `create(name)` → `chunk->vt+0x88/0x90(绑定流)`                                                                                               | `1809eae90`                                                                                                                                                                                                            | 观察  |
| L5 | **单元素解码路径**：元素字节先落入 `OdMemoryStream`，再包 `OdDgFileFiler`，然后 `element->vt+0x188(filer)`(= dgnIn，OdDgElement vtable slot49 → 0x188)                                                                                        | `FUN_1809e18e0 @1809e18e0`：`OdDgFileFiler::createObject(&memStream,0)` → `filer->vt+0x78(0,0)` seek0 → `param_2->vt+0x188(filer)` → 收尾 `vt+0x198`(slot51=dgnInFields)                                                  | 观察  |
| L6 | **单元素回写路径（对称，用于反推布局顺序）**：`impl->vt+0x110(filer)` → `element->vt+0x1a0` → `impl->vt+0x188(filer)` → 记录长度差 → `impl->vt+0x118(pos,len)`；**EDimension 有校验和特殊分支**（`FUN_18025b460/180255090/180267910` + `calculateCheckSum`） | `FUN_1809e2b40 @1809e2b40`                                                                                                                                                                                             | 观察  |
| L7 | **递归保存（complex/子元素）**：取子元素迭代器 `[0xc]hasNext/[0xd]next/[0xe]advance` → `openObject` → 递归 → `filer->vt+0x140`(wrBytes) 写出，随后 `vt+0x98` flush                                                                              | `FUN_1809e3730 @1809e3730`                                                                                                                                                                                             | 观察  |
| L8 | 载入后的**分拣阶段**：按类型把元素塞入各表                                                                                                                                                                                                 | `FUN_18058c130 @18058c130`：判 `type==0x22(34 共享单元定义)/0x6b(107)/0x42(66)` → `SharedCellDefinitionTable/TagDefinitionSetTable/LevelTable/FontTable/ColorBookTable/PrintStyleTable/LinkSetTable/ElementTemplateTable::add` | 观察  |
| L9 | OdDgElement 虚表关键槽位：**49=dgnIn(0x188) 50=dgnOut(0x190) 51=dgnInFields(0x198) 52=dgnOutFields(0x1a0)**（共256槽）                                                                                                             | `evidence/ghidra/out/TG_Db.vtables.txt`（`??_7OdDgElement@@6B@`）                                                                                                                                                        | 观察  |

> 方法注：`+0x188` 全程序 137 处调用（`calls-0x188.txt`），其中 loader 区  
> `1809e18e0/1809e2b40/1809e3730` 三个即上述路径；其余多为 impl/其他类同偏移假阳性。

## 2. 综合后的 v8 读取模型（更新 file-structure.md §2）

```
CFB (oless.dll)
└─ 子节点(名=…+数字, 或 '$'前缀) ── OdDgChunk { bytes[vt+0x68], len[vt+0x70] }
    └─ 元素目录条目(OdDgElementResolver: chunkId, entryId, type, name, modelId)
        └─ 解码(按需): MemoryStream → OdDgFileFiler(kFileFiler=0)
            ├─ dgnIn → dgnInHeader → SElementHeader(36B)
            ├─ dgnInFields(按 type 的虚函数, E*/CDG* impl)
            ├─ dgnInLinkages(filer, size)
            └─ dgnInXAttributes
```

- **惰性加载迹象**（推断，置信度中）：`OdDgElementResolver` 携带 chunkId/entryId/type/name，  
  单元素路径独立于批量循环存在 → v8 可能只建目录、体数据按 `openObject` 拉取。  
  完整的"目录格式"与"是否全量预读"仍为 **U7（更新）**。

## 3. 对 Go 库的直接含义

1. `dgn/filer` 只需实现 **kFileFiler**；解码单元 = "一段 bytes"（非整文件游标）。
2. Chunk 层接口：`Name() / Bytes() []byte`；`'$'` 分支与数字排序属于容器语义。
3. 回写路径(L6/L7)给出了**字段写出顺序**，可与读入顺序互证（下一步做对照表）。
4. EDimension 校验和：Go 写路径才需要，读路径可先忽略（记录为 U8）。

## 4. 未知更新

- **U7(改)**：元素目录（directory）在哪个流/chunk、条目定长/变长格式？  
  线索：`OdDgElementResolver::{setChunkId,setElementEntryId,setElementType,setElementName,setModelId}`（E2 导出）
- **U3(收窄)**：`FUN_1809e6c20` 子读取顺序已知，剩各子块内部布局
- **U8(新)**：EDimension 写回校验和算法（读路径可暂缓）
