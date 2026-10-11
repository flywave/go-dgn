# 交叉验证：GDAL DGNv8 驱动 vs go-dgn（第27轮）

**方法**：GDAL 的 v8 驱动（`ogrsf_frmts/dwg/ogrdgnv8layer.cpp` 2418L + `ogrteigha.cpp`）
**本身基于 ODA API**（OdaCommon/DgDatabase/ExDgnServices 头）——它消费哪些 getter =
独立第三方对**字段语义**的确认/反证（E3 二级源，与我们的 E2 反编译互证）。

## 1. 确认项（✅ 我们的字段语义推断被 GDAL 用法印证）

| 我们的解码器/字段 [推断] | GDAL getter 用法 | 判定 |
|---|---|---|
| Line = {Start, End} Point | `getStartPoint`×2, `getEndPoint`×2 | ✅ 确认 |
| **Arc2d = 5×double + origin**：primary, secondary, rotation, **startAngle, sweepAngle** | `getPrimaryAxis` `getSecondaryAxis` `getRotation` `getSweepAngle` `getStartParam` `getOrigin` | ✅ **确认（此前"start/sweep 去向"悬案关闭）** |
| Ellipse = 3×double + origin | `getPrimaryAxis` `getSecondaryAxis` `getRotation` `getOrigin` | ✅ 确认（4语义字段=3dbl+pt） |
| LineString/Shape = count + 点列 | `getNumPoints/getPoint/getVerticesCount/getVertexAt` | ✅ 确认 |
| **linkage TypeID（=PrimaryIds）** | `getLinkages` + **`getPrimaryId`** | ✅ 确认（16位 typeID 语义） |
| Text = 长度+串+样式字段 | `getText` `getHeightMultiplier` `getJustification` `getFontEntryId` | ✅ 语义覆盖一致 |
| Shape hole 标志（ODA 读取器置1） | `getHoleFlag`×3 | ✅ 与 ODA 行为一致（读态非文件态） |
| 模块地图/ODA 装载（01-oda-inventory） | `ogrteigha.cpp` 同款 odrxDynamicLinker 初始化 | ✅ 一致 |

## 2. 反证/待决项 ⚠

| 项 | 观察 | 处置 |
|---|---|---|
| **Arc3d = Quaternion+Point3d（仅7 doubles）** | GDAL 另读 `getStartPoint/getEndPoint` —— 3D 弧可能为**端点制**（角参数在别处/由端点派生） | **U14**：3D 弧 start/sweep 存储位置待核（样例或 getter 反编译） |
| Cell P1/P2/P3+matrix 命名 | GDAL: `getOrigin`×3 + `getRotation` —— 与我们 [推断] 命名方向一致但未逐点对应 | 样例核时对齐 |

## 3. 结论

- **无发现与 Go 实现冲突的字节级差异**；语义层7项确认、0项反证、1项待决(U14)
- GDAL v8 驱动不解析底层字节（走 ODA API），故 byte-level 仍以我们 E2 为准——
  交叉验证价值在**字段命名/语义**与 linkage typeID 语义 ✓
- 同时复核 v7 侧：dgnlib（独立实现）与我们 v7 帧/core/体的对照已在 D51-D54 完成
