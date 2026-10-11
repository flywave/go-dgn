/* ==== 1800a3440 FUN_1800a3440 ==== */

undefined8 FUN_1800a3440(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
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
  (**(code **)(*param_2 + 0x128))(param_2,&local_28);
  *(undefined4 *)(param_1 + 0x268) = local_28;
  *(undefined4 *)(param_1 + 0x26c) = uStack_24;
  *(undefined4 *)(param_1 + 0x270) = uStack_20;
  *(undefined4 *)(param_1 + 0x274) = uStack_1c;
  *(undefined4 *)(param_1 + 0x278) = local_18;
  *(undefined4 *)(param_1 + 0x27c) = uStack_14;
  *(undefined4 *)(param_1 + 0x280) = uStack_10;
  *(undefined4 *)(param_1 + 0x284) = uStack_c;
  (**(code **)(*param_2 + 0x110))(param_2,&local_28);
  *(ulonglong *)(param_1 + 0x288) = CONCAT44(uStack_24,local_28);
  *(ulonglong *)(param_1 + 0x290) = CONCAT44(uStack_1c,uStack_20);
  *(ulonglong *)(param_1 + 0x298) = CONCAT44(uStack_14,local_18);
  return 0;
}



/* ==== 1802924c0 FUN_1802924c0 ==== */

undefined8 FUN_1802924c0(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x220) = uVar3;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x224) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x460) = uVar2;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x228) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x230) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x238) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x240) = uVar1;
  (**(code **)(*param_2 + 0x128))(param_2,&local_28);
  *(undefined4 *)(param_1 + 0x3c8) = local_28;
  *(undefined4 *)(param_1 + 0x3cc) = uStack_24;
  *(undefined4 *)(param_1 + 0x3d0) = uStack_20;
  *(undefined4 *)(param_1 + 0x3d4) = uStack_1c;
  *(undefined4 *)(param_1 + 0x3d8) = local_18;
  *(undefined4 *)(param_1 + 0x3dc) = uStack_14;
  *(undefined4 *)(param_1 + 0x3e0) = uStack_10;
  *(undefined4 *)(param_1 + 0x3e4) = uStack_c;
  (**(code **)(*param_2 + 0x110))(param_2,&local_28);
  *(undefined4 *)(param_1 + 1000) = local_28;
  *(undefined4 *)(param_1 + 0x3ec) = uStack_24;
  *(undefined4 *)(param_1 + 0x3f0) = uStack_20;
  *(undefined4 *)(param_1 + 0x3f4) = uStack_1c;
  *(ulonglong *)(param_1 + 0x3f8) = CONCAT44(uStack_14,local_18);
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x462) = uVar2;
  FUN_1800150c0(param_1 + 0x308);
  uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x308) + -4);
  FUN_18000d0b0(param_1 + 0x308);
  lVar6 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x308) + -4) != 0) {
    lVar6 = *(longlong *)(param_1 + 0x308);
  }
  (**(code **)(*param_2 + 0x90))(param_2,lVar6,uVar3);
  FUN_180297380(param_1,param_2);
  uVar5 = (**(code **)(*param_2 + 0x80))(param_2);
  if ((uVar5 & 1) != 0) {
    (**(code **)(*param_2 + 0x98))(param_2);
  }
  iVar4 = (**(code **)(*param_2 + 0x58))(param_2);
  if ((iVar4 != 10) && (iVar4 = (**(code **)(*param_2 + 0x58))(param_2), iVar4 != 0xb)) {
    return 0;
  }
  FUN_18021f680(param_1);
  return 0;
}



