/* ==== 1808c5330 FUN_1808c5330 ==== */

void FUN_1808c5330(undefined4 *param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  ushort uVar3;
  
  (**(code **)(*param_2 + 0x160))(param_2,*param_1);
  (**(code **)(*param_2 + 0x160))(param_2,param_1[1]);
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  lVar2 = *param_2;
  if (iVar1 == 0xb) {
    uVar3 = *(ushort *)(param_1 + 2) & 0xf7ff;
  }
  else {
    iVar1 = (**(code **)(lVar2 + 0x58))(param_2);
    if (iVar1 == 10) {
      (**(code **)(*param_2 + 0x158))(param_2,*(ushort *)(param_1 + 2) | 0x800);
      goto LAB_1808c53af;
    }
    lVar2 = *param_2;
    uVar3 = *(ushort *)(param_1 + 2);
  }
  (**(code **)(lVar2 + 0x158))(param_2,uVar3);
LAB_1808c53af:
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)((longlong)param_1 + 10));
  (**(code **)(*param_2 + 0x160))(param_2,param_1[3]);
  (**(code **)(*param_2 + 0x160))(param_2,param_1[4]);
  (**(code **)(*param_2 + 0x160))(param_2,param_1[5]);
  (**(code **)(*param_2 + 0x168))(param_2,*(undefined8 *)(param_1 + 6));
  (**(code **)(*param_2 + 0x168))(param_2,*(undefined8 *)(param_1 + 8));
  (**(code **)(*param_2 + 0x168))(param_2,*(undefined8 *)(param_1 + 10));
  (**(code **)(*param_2 + 0x168))(param_2,*(undefined8 *)(param_1 + 0xc));
  (**(code **)(*param_2 + 0x168))(param_2,*(undefined8 *)(param_1 + 0xe));
                    /* WARNING: Could not recover jumptable at 0x0001808c5450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x168))(param_2,*(undefined8 *)(param_1 + 0x10));
  return;
}



/* ==== 1808c5460 FUN_1808c5460 ==== */

void FUN_1808c5460(undefined4 *param_1,longlong *param_2)

{
  (**(code **)(*param_2 + 0x160))(param_2,*param_1);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 1));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 2));
  (**(code **)(*param_2 + 0x160))(param_2,param_1[3]);
  (**(code **)(*param_2 + 0x160))(param_2,param_1[4]);
  (**(code **)(*param_2 + 0x160))(param_2,param_1[5]);
  (**(code **)(*param_2 + 0x168))(param_2,*(undefined8 *)(param_1 + 6));
                    /* WARNING: Could not recover jumptable at 0x0001808c54f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 8));
  return;
}



