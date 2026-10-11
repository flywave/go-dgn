/* ==== 1802e9040 FUN_1802e9040 ==== */

void FUN_1802e9040(longlong param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  OdError_InvalidIndex local_res8 [8];
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + -4);
  (**(code **)(*param_2 + 0x160))(param_2,uVar1);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 8));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x10) + -4) <= (uint)uVar3) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x1a8))(param_2,*(longlong *)(param_1 + 0x10) + uVar3 * 0x18);
      uVar2 = (uint)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



