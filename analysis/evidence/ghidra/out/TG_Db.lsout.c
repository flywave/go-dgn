/* ==== 1802e8fa0 FUN_1802e8fa0 ==== */

void FUN_1802e8fa0(longlong param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  OdError_InvalidIndex local_res8 [8];
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + -4);
  (**(code **)(*param_2 + 0x160))(param_2,uVar1);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 8));
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x10) + -4) <= uVar2) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x1a0))
                (param_2,(ulonglong)uVar2 * 0x10 + *(longlong *)(param_1 + 0x10));
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}



