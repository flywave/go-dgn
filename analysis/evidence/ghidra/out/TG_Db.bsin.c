/* ==== 180280d10 FUN_180280d10 ==== */

undefined8 FUN_180280d10(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 uVar8;
  OdError_InvalidIndex local_res8 [8];
  
  iVar2 = (**(code **)(*param_2 + 0x88))(param_2);
  iVar3 = (**(code **)(*param_2 + 0x80))(param_2);
  uVar7 = (uint)(iVar2 - iVar3) >> 3;
  FUN_180015300(param_1 + 0x220,uVar7);
  uVar4 = 0;
  uVar6 = uVar4;
  if ((uint)(iVar2 - iVar3) >> 3 != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x220) + -4) <= (uint)uVar6) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18000d1e0(param_1 + 0x220);
      lVar1 = *(longlong *)(param_1 + 0x220);
      uVar8 = (**(code **)(*param_2 + 200))(param_2);
      *(undefined8 *)(lVar1 + uVar4) = uVar8;
      uVar5 = (uint)uVar6 + 1;
      uVar4 = uVar4 + 8;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < uVar7);
  }
  return 0;
}



/* ==== 1803e9bc0 FUN_1803e9bc0 ==== */

undefined8 FUN_1803e9bc0(longlong param_1,longlong *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 2) {
    FUN_1803ed520(param_1,param_2);
    return 0;
  }
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x260) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x264) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x268) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x26c) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x270) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x274) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x278) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x27c) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x280) = uVar2;
  return 0;
}



