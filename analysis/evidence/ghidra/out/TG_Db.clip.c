/* ==== 18043a0c0 FUN_18043a0c0 ==== */

undefined8 FUN_18043a0c0(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  plVar1 = (longlong *)(param_1 + 0x2f0);
  FUN_18000d0b0(plVar1);
  *(undefined4 *)(*plVar1 + -4) = 0;
  iVar3 = (**(code **)(*param_2 + 0x88))(param_2);
  iVar4 = (**(code **)(*param_2 + 0x80))(param_2);
  FUN_1800150c0(plVar1,iVar3 - iVar4);
  FUN_18000d0b0(plVar1);
  lVar2 = *param_2;
  lVar5 = 0;
  if (*(int *)(*plVar1 + -4) != 0) {
    lVar5 = *plVar1;
  }
  iVar3 = (**(code **)(lVar2 + 0x80))(param_2);
  iVar4 = (**(code **)(lVar2 + 0x88))(param_2);
  (**(code **)(lVar2 + 0x90))(param_2,lVar5,iVar4 - iVar3);
  return 0;
}



/* ==== 18043a1f0 FUN_18043a1f0 ==== */

void FUN_18043a1f0(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x2f0) + -4) != 0) {
    lVar1 = *(longlong *)(param_1 + 0x2f0);
  }
                    /* WARNING: Could not recover jumptable at 0x00018043a20d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x140))(param_2,lVar1);
  return;
}



