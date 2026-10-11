/* ==== 180297150 FUN_180297150 ==== */

void FUN_180297150(longlong param_1,longlong *param_2)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  OdError_InvalidIndex local_res8 [16];
  OdError_InvalidIndex local_res18 [8];
  OdError_InvalidIndex local_res20 [8];
  
  if (*(short *)(param_1 + 0x442) != 0) {
    iVar6 = (**(code **)(*param_2 + 0x88))(param_2);
    iVar7 = (**(code **)(*param_2 + 0x80))(param_2);
    if ((uint)(iVar6 - iVar7) < (uint)*(ushort *)(param_1 + 0x442) * 3) {
      *(undefined2 *)(param_1 + 0x442) = 0;
                    /* WARNING: Could not recover jumptable at 0x000180297310. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_2 + 0x78))(param_2,0,2);
      return;
    }
    plVar2 = (longlong *)(param_1 + 0x300);
    FUN_1802981d0(plVar2);
    uVar8 = 0;
    if (*(short *)(param_1 + 0x442) != 0) {
      do {
        if (*(uint *)(*plVar2 + -4) <= uVar8) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_res20);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar1 = (int *)(*plVar2 + -0x10);
        iVar6 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if (1 < iVar6) {
          FUN_1802921b0(plVar2,*(undefined4 *)(*plVar2 + -8),0,0,1);
        }
        lVar3 = *plVar2;
        lVar4 = (ulonglong)uVar8 * 3;
        uVar5 = (**(code **)(*param_2 + 0xa0))(param_2);
        *(undefined1 *)(lVar3 + lVar4) = uVar5;
        if (*(uint *)(*plVar2 + -4) <= uVar8) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_res18);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar1 = (int *)(*plVar2 + -0x10);
        iVar6 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if (1 < iVar6) {
          FUN_1802921b0(plVar2,*(undefined4 *)(*plVar2 + -8),0,0,1);
        }
        lVar3 = *plVar2;
        uVar5 = (**(code **)(*param_2 + 0xa0))(param_2);
        *(undefined1 *)(lVar3 + 1 + lVar4) = uVar5;
        if (*(uint *)(*plVar2 + -4) <= uVar8) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar1 = (int *)(*plVar2 + -0x10);
        iVar6 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if (1 < iVar6) {
          FUN_1802921b0(plVar2,*(undefined4 *)(*plVar2 + -8),0,0,1);
        }
        lVar3 = *plVar2;
        uVar5 = (**(code **)(*param_2 + 0xa0))(param_2);
        *(undefined1 *)(lVar3 + 2 + lVar4) = uVar5;
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(ushort *)(param_1 + 0x442));
    }
  }
  return;
}



