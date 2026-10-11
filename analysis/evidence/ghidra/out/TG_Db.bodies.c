/* ==== 1800a3360 FUN_1800a3360 ==== */

undefined8 FUN_1800a3360(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x240) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x244) = uVar3;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x248) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x24a) = uVar2;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x250) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 600) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x260) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x268) = uVar1;
  (**(code **)(*param_2 + 0x100))(param_2,&local_18);
  *(undefined8 *)(param_1 + 0x270) = local_18;
  *(undefined8 *)(param_1 + 0x278) = uStack_10;
  return 0;
}



/* ==== 1801b9990 FUN_1801b9990 ==== */

void FUN_1801b9990(longlong param_1)

{
  FUN_1802e4480();
  *(undefined1 *)(param_1 + 0x248) = 1;
  *(undefined1 *)(param_1 + 0x24a) = 1;
  return;
}



/* ==== 1801d8de0 FUN_1801d8de0 ==== */

undefined8 FUN_1801d8de0(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_18 [16];
  
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x44] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x45] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x48] = lVar1;
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x100))(param_2,local_18);
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  uVar4 = puVar5[3];
  *(undefined4 *)(param_1 + 0x49) = *puVar5;
  *(undefined4 *)((longlong)param_1 + 0x24c) = uVar2;
  *(undefined4 *)(param_1 + 0x4a) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x254) = uVar4;
  (**(code **)(*param_1 + 0x630))(param_1);
  return 0;
}



/* ==== 1801dbfe0 FUN_1801dbfe0 ==== */

undefined8 FUN_1801dbfe0(longlong param_1,longlong *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined1 local_18 [16];
  
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x100))(param_2,local_18);
  uVar1 = puVar5[1];
  uVar2 = puVar5[2];
  uVar3 = puVar5[3];
  *(undefined4 *)(param_1 + 0x220) = *puVar5;
  *(undefined4 *)(param_1 + 0x224) = uVar1;
  *(undefined4 *)(param_1 + 0x228) = uVar2;
  *(undefined4 *)(param_1 + 0x22c) = uVar3;
  puVar6 = (undefined8 *)(**(code **)(*param_2 + 0x100))(param_2,local_18);
  uVar4 = puVar6[1];
  *(undefined8 *)(param_1 + 0x230) = *puVar6;
  *(undefined8 *)(param_1 + 0x238) = uVar4;
  return 0;
}



/* ==== 180286670 FUN_180286670 ==== */

undefined8 FUN_180286670(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_18 [16];
  
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x44] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x45] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x46] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x47] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x4a] = lVar1;
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x100))(param_2,local_18);
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  uVar4 = puVar5[3];
  *(undefined4 *)(param_1 + 0x4b) = *puVar5;
  *(undefined4 *)((longlong)param_1 + 0x25c) = uVar2;
  *(undefined4 *)(param_1 + 0x4c) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x264) = uVar4;
  (**(code **)(*param_1 + 0x650))(param_1);
  return 0;
}



/* ==== 180292330 FUN_180292330 ==== */

undefined8 FUN_180292330(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x220) = uVar3;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x224) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x440) = uVar2;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x228) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x230) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x238) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x240) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x3c8) = uVar1;
  (**(code **)(*param_2 + 0x100))(param_2,&local_18);
  *(undefined4 *)(param_1 + 0x3d0) = local_18;
  *(undefined4 *)(param_1 + 0x3d4) = uStack_14;
  *(undefined4 *)(param_1 + 0x3d8) = uStack_10;
  *(undefined4 *)(param_1 + 0x3dc) = uStack_c;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x442) = uVar2;
  FUN_1800150c0(param_1 + 0x308);
  uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x308) + -4);
  FUN_18000d0b0(param_1 + 0x308);
  lVar6 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x308) + -4) != 0) {
    lVar6 = *(longlong *)(param_1 + 0x308);
  }
  (**(code **)(*param_2 + 0x90))(param_2,lVar6,uVar3);
  FUN_180297150(param_1,param_2);
  uVar5 = (**(code **)(*param_2 + 0x80))(param_2);
  if ((uVar5 & 1) != 0) {
    (**(code **)(*param_2 + 0x98))(param_2);
  }
  iVar4 = (**(code **)(*param_2 + 0x58))(param_2);
  if ((iVar4 != 10) && (iVar4 = (**(code **)(*param_2 + 0x58))(param_2), iVar4 != 0xb)) {
    return 0;
  }
  FUN_18021f1b0(param_1);
  return 0;
}



/* ==== 1802e4480 FUN_1802e4480 ==== */

undefined8 FUN_1802e4480(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0x220) + 0x40))();
  return 0;
}



