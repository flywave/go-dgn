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



/* ==== 1805fd4c0 FUN_1805fd4c0 ==== */

void FUN_1805fd4c0(longlong *param_1,longlong *param_2)

{
  (**(code **)(*param_1 + 0x658))();
  (**(code **)(*param_2 + 0x158))(param_2,(short)param_1[0x50]);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)((longlong)param_1 + 0x282));
  (**(code **)(*param_2 + 0x168))(param_2,param_1[0x51]);
  (**(code **)(*param_2 + 0x170))(param_2,param_1[0x52]);
                    /* WARNING: Could not recover jumptable at 0x0001805fd53e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x170))(param_2,param_1[0x53]);
  return;
}



