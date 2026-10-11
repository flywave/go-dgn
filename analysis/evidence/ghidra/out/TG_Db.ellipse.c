/* ==== 18016bfc0 FUN_18016bfc0 ==== */

undefined8 FUN_18016bfc0(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x220);
}



/* ==== 1801d7ac0 FUN_1801d7ac0 ==== */

undefined8 * FUN_1801d7ac0(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x268);
  uVar1 = *(undefined8 *)(param_1 + 0x270);
  *param_2 = *(undefined8 *)(param_1 + 0x260);
  param_2[1] = uVar2;
  param_2[2] = uVar1;
  return param_2;
}



/* ==== 1801d7b00 FUN_1801d7b00 ==== */

longlong FUN_1801d7b00(longlong param_1)

{
  return param_1 + 0x240;
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



/* ==== 1801d8e60 FUN_1801d8e60 ==== */

undefined8 FUN_1801d8e60(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_28 [32];
  
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x44] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x45] = lVar1;
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x128))(param_2,local_28);
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  uVar4 = puVar5[3];
  *(undefined4 *)(param_1 + 0x48) = *puVar5;
  *(undefined4 *)((longlong)param_1 + 0x244) = uVar2;
  *(undefined4 *)(param_1 + 0x49) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x24c) = uVar4;
  uVar2 = puVar5[5];
  uVar3 = puVar5[6];
  uVar4 = puVar5[7];
  *(undefined4 *)(param_1 + 0x4a) = puVar5[4];
  *(undefined4 *)((longlong)param_1 + 0x254) = uVar2;
  *(undefined4 *)(param_1 + 0x4b) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x25c) = uVar4;
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  uVar4 = puVar5[3];
  *(undefined4 *)(param_1 + 0x4c) = *puVar5;
  *(undefined4 *)((longlong)param_1 + 0x264) = uVar2;
  *(undefined4 *)(param_1 + 0x4d) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x26c) = uVar4;
  param_1[0x4e] = *(longlong *)(puVar5 + 4);
  (**(code **)(*param_1 + 0x630))(param_1);
  return 0;
}



