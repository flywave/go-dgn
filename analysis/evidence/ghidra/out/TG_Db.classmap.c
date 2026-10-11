/* ==== 1809e0b60 FUN_1809e0b60 ==== */

undefined8 * FUN_1809e0b60(longlong *param_1,undefined8 *param_2,ushort param_3,byte param_4)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  undefined8 *puVar8;
  uint uVar9;
  
  lVar2 = *param_1;
  if (((uint)param_3 < *(uint *)(lVar2 + -4)) &&
     (param_4 < *(byte *)(lVar2 + (ulonglong)(uint)param_3 * 0x10))) {
    plVar7 = *(longlong **)
              (*(longlong *)(lVar2 + 8 + (ulonglong)param_3 * 0x10) + (ulonglong)param_4 * 8);
  }
  else {
    puVar8 = (undefined8 *)param_1[1];
    uVar9 = (uint)param_3 << 0x10 | (uint)param_4;
    cVar1 = *(char *)((longlong)puVar8[1] + 0x19);
    puVar4 = puVar8;
    puVar6 = (undefined8 *)puVar8[1];
    while (cVar1 == '\0') {
      if (*(uint *)(puVar6 + 4) < uVar9) {
        puVar5 = (undefined8 *)puVar6[2];
        puVar6 = puVar4;
      }
      else {
        puVar5 = (undefined8 *)*puVar6;
      }
      puVar4 = puVar6;
      puVar6 = puVar5;
      cVar1 = *(char *)((longlong)puVar5 + 0x19);
    }
    if ((*(char *)((longlong)puVar4 + 0x19) == '\0') && (*(uint *)(puVar4 + 4) <= uVar9)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      puVar8 = puVar4;
    }
    if (puVar8 == (undefined8 *)param_1[1]) goto LAB_1809e0c0a;
    plVar7 = (longlong *)puVar8[5];
  }
  if (plVar7 != (longlong *)0x0) {
    (**(code **)(*plVar7 + 0x58))(plVar7,param_2);
    return param_2;
  }
LAB_1809e0c0a:
  *param_2 = 0;
  return param_2;
}



