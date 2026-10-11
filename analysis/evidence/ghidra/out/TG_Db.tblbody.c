/* ==== 1801f07b0 FUN_1801f07b0 ==== */

undefined8 FUN_1801f07b0(longlong *param_1,longlong *param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  (**(code **)(*param_1 + 0x650))();
  iVar1 = (**(code **)(*param_2 + 0x88))(param_2);
  iVar2 = (**(code **)(*param_2 + 0x80))(param_2);
  FUN_1800150c0(param_1 + 0x48);
  FUN_18000d0b0(param_1 + 0x48);
  lVar3 = 0;
  if (*(int *)(param_1[0x48] + -4) != 0) {
    lVar3 = param_1[0x48];
  }
  (**(code **)(*param_2 + 0x90))(param_2,lVar3,iVar1 - iVar2);
  return 0;
}



/* ==== 180559830 FUN_180559830 ==== */

undefined8 FUN_180559830(longlong *param_1,longlong *param_2)

{
  undefined2 uVar1;
  longlong lVar2;
  
  (**(code **)(*param_1 + 0x650))();
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x4a) = uVar1;
  lVar2 = 5;
  do {
    (**(code **)(*param_2 + 0xa8))(param_2);
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return 0;
}



/* ==== 1805fd430 FUN_1805fd430 ==== */

undefined8 FUN_1805fd430(longlong *param_1,longlong *param_2)

{
  undefined2 uVar1;
  longlong lVar2;
  
  (**(code **)(*param_1 + 0x650))();
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x50) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x282) = uVar1;
  lVar2 = (**(code **)(*param_2 + 0xb8))(param_2);
  param_1[0x51] = lVar2;
  lVar2 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x52] = lVar2;
  lVar2 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x53] = lVar2;
  return 0;
}



