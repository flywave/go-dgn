# DGN v8 元素目录与类型分发（第 3 轮，U7 主体已解）

**证据**：E2 Ghidra 反编译 `evidence/ghidra/out/`：
`TG_Db.dirload.c`(FUN_1809d94d0)、`TG_Db.resolver.c`(FUN_1809d9c80)、
`TG_Db.entry.c`(FUN_1809df950)、`TG_Db.dispatch.c`(FUN_1809dc0c0)。

## 1. 结论表

| # | 结论 | 证据 | 置信度 |
|---|---|---|---|
| C1 | **目录 = u32 偏移数组**：容器字段 `param_1[7]`（OdArray<u32>），条目数 = 数组长；元素绝对位置 = `container->vt+200()（基址）+ offset_i` | `FUN_1809d94d0 @1809d94d0` L84-104；`FUN_1809d9c80 @1809d9c80` L243-252（`seek(offset,0)` 后读头） | 观察 |
| C2 | 每条目先解析 **SElementHeader(36B)**（与 `FUN_1808c5240` 布局一致：type@+4、flags@+8、id@+24） | dirload L96-103(local_d0/local_c8 结构与 type/flags 位判断) | 观察 |
| C3 | **flags(u16@+8) 位语义**：bit12=显示头存在（跳过 0x48=72B DisplayHeader）；bit13=复杂元素（其后含子元素计数）；bit14=附加 4B 跳过 | resolver.c L254-261、L287-293；dirload L118-124 | 观察 |
| C4 | **复杂元素的条目跨越**：size/count 字段位于 `elem_pos+0x24`（36）或 `elem_pos+0x6c`（108，当 bit12&&type!=100）；`next = i + *count` | dirload L118-124 | 观察（字段=条目跨度数，推断） |
| C5 | **类型→类 = 表驱动**：`odDgnClassMap()` 全局映射，键=(type, variant)，查询 `FUN_1809e0b60(map,out,type&0xffff,variant)` | `FUN_1809dc0c0 @1809dc0c0` L37-157 | 观察 |
| C6 | **variant 取值分三组**（switch on type）：<br>· A 组 {2,3,4,6,7,11,13,15,16,17,21,22,27,87} → variant=`(param_2[4]!=0)`（2d/3d 维度标志）<br>· B 组 {5,33,39,42,91,95,96,105} → variant=`param_2[1]&0xff`（子类型字节；39 且 subtype≠0x1c 时强制 0）<br>· 其余 → variant=0 | dispatch.c L34-157 | 观察（param_2 各字段与头字段的精确对应待核 → U7c） |
| C7 | **查表失败的四路代理回退**：`complex? × graphics?` → `OdDgProxyElement / OdDgProxyGraphicsElement / OdDgComplexProxyElement / OdDgComplexProxyGraphicsElement` | dispatch.c L158-191 | 观察 |
| C8 | 建对象后：`OdDgDatabase::addOdDgElement` → impl cast 为 `CDGElementGeneral` → 存 id → graphics 判定 → `vt+0x450/0x470` 后置初始化 | dispatch.c L192-251 | 观察 |
| C9 | **工厂函数 `FUN_1809df950`**：建 `OdDgFileFiler` → `FUN_1808c5240` 读 36B 头（输出到 param_5）→ 需要时 `FUN_1808c5150` 读 72B 显示头 → 特例直接 `createObject`：**KMLPlacemark2d/3d、AnnotationCellHeader2d/3d、AssocRegion2d/3d、Ole2Frame2d/3d** → 否则走 C5 映射 | entry.c L111-114、L32(区域)、L334-680 | 观察 |
| C10 | **按类型的目录级过滤规则**（分类扫描 FUN_1809d9c80）：<br>· 跳过：type ∈ {5,9,96,97}（部分路径）<br>· type=66(ApplicationData)：bit12→+72、bit14→+4 后读 **u16 magic** ∈ {0x583b,0x5842,0x56e6,0x571a} 才保留<br>· type=95(TableEntry)：subtype 条件 `(x-1)&0xfffffff7==0`（x∈{1,…}）<br>· type=107(ExtraNonGraphics)：扫描 24B 步长的 XAttribute 表，magic id ∈ {0x58750001,0x58660000,0x56ec0000}；0x56ec0000 → `OdDgExtendedElementTypeXAttribute`，其值 ∈ {0x6b0002,0x58e40005,0x58ec0015,…} 决定去留 | resolver.c L265-418 | 观察（规则含义部分[推断]） |
| C11 | 复杂/子元素递归：`CDGComplexGeneral::addElementResolver`；保存侧按子迭代器递归（见 load-pipeline L7） | 180113a00 | 观察 |
| C12 | 源码路径线索（错误报告携带）：`C:\B\1\_\_\Dgn\source\DgDefsInternal.h` → ODA 上游"Dgn"遗留源码树存在此文件（仅文件名记录，未获取内容） | dirload L82、dispatch L253 | 观察 |

## 2. 修正后的读取模型

```
container(vt+200 基址) ── u32 offset[count]（字段 param_1[7]）
for i in 0..count:
    pos = base + offset[i]
    hdr = SElementHeader@pos            # 36B
    variant = A组:is3d | B组:subtype | 0
    cls = odDgnClassMap[type][variant]  # 表驱动
        └ null → 4 路 Proxy 回退 (C7)
    dispHdr? bit12 → +72B 显示头 (C3)
    body  = FUN_1809df950  (dgnInFields 虚分发, 见 load-pipeline L5)
    linkages/xattrs 后缀 (bit13/size, C4)
    complex: next = i + count_field     # 条目跨度
```

## 3. 对 Go 的映射

- `element/registry.go`：`map[TypeVariant]Decoder`，三组 variant 规则照抄 C6；
  未命中 → 4 个 proxy decoder（原始字节透传，仍可保 id/level/flags）。
- 目录层：`type Dir []uint32` + base；复杂元素跨度计算（C4）。
- 过滤规则 C10 属于 ODA 内部建表策略，**Go 读取器可不实现**（除非要复刻其内存对象集）。

## 4. dispatch 入参记录布局（第 4 轮，U7c 已解）

**证据**：`TG_Db.entry.c` L146-180（`FUN_1809df950` 构建记录后调 `FUN_1809dc0c0`）；
`param_5` = SElementHeader 内存结构（40B，字段见 element-header.md）。

```
record（= dispatch 的 param_2，栈上 48B+）：
  [0]  type     = *(int*)(hdr+4)              # 即 mem@4（文件 type 宽化）
  [1]  subtype  = *(hdr+0x14)                 # mem@20（默认）
                 特例：type==33  → byte at obj+0x89（标注数据内）
                        type==91  → short at obj+0x24
                        type==95  → *(hdr+0x14)，0 则回退 param_1[8] 缓存
                        type==105 → uint at obj+0x70
  [2..3] id(u64)= *(hdr+0x18)                 # mem@24
  [4]  ext/bit  = displayHeader.u16 的 bit11（读了显示头才置位）→ 组A variant
  [5]  complex  = flags(u16@mem+8) bit13      → Proxy 回退的 complex 维
  [6]  graphics = flags bit12                 → Proxy 回退的 graphics 维
  [8]  database = OdDgDatabase*
  [10] class    = 0（dispatch 输出：解析出的 OdRxClass）
旁证：type∈{96,95} 时 param_1[8] 缓存 = *(hdr+0x14)；hdr+0x10 字段为
     "invalid header" 修复源（=hdr+0x0c 拷贝），并参与 group-B 的 subtype 分支。
组A variant（记录[4]）语义=[推断] 与 3D/扩展显示相关，待样例核（U5 续）。
```

**callers（U7b 的外围）**：`FUN_1805cfb90 / FUN_1805d0330` 为薄包装：
`FUN_1809d94d0(container, out=Db+0x1490 / +0x1498, Db, db)` —— 目录扫描结果写入
数据库的两个 id 集合（对应 graphics / non-graphics 两路？[推断]）。

## 5. 剩余未知

- **U7b**：offset 数组（count+u32[]）本身从文件何处读取（填充 `container[7]` 的代码未定位；
  线索：container 极可能是 OdDgChunk，追 `chunk->vt+0x88`（createFromStream 绑定流）实现：
  `FUN_1809e8690 / FUN_1809e0ab0` 两套 impl）
- **U5(续)**：DisplayHeader 72B 字段语义 + record[4]（bit11）的确切含义
