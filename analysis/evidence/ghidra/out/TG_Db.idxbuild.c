/* ==== 1809dc670 FUN_1809dc670 ==== */

void FUN_1809dc670(longlong *param_1,int param_2,uint param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  __uint64 _Var5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  longlong *plVar8;
  OdRxClass *pOVar9;
  ulonglong uVar10;
  uint uVar11;
  int local_res8 [2];
  uint local_res18 [2];
  int local_res20 [2];
  int local_78;
  uint local_74;
  longlong *local_70;
  longlong *local_68;
  OdError_InvalidIndex local_60 [8];
  OdError_InvalidIndex local_58 [8];
  OdError_InvalidIndex local_50 [8];
  OdError_InvalidIndex local_48 [8];
  undefined1 local_40 [8];
  
  uVar1 = *(uint *)(param_1[7] + -4);
  local_res8[0] = 0;
  local_res18[0] = param_3;
  local_74 = uVar1;
  FUN_18048f790(param_1 + 7,uVar1 + param_3,local_res8);
  uVar3 = (**(code **)(*param_1 + 0x70))(param_1);
  _Var5 = (**(code **)(*param_1 + 200))(param_1);
  plVar6 = (longlong *)OdFlatMemStream::createNew(&local_70,_Var5,(ulonglong)uVar3);
  local_68 = (longlong *)0x0;
  plVar6 = (longlong *)*plVar6;
  plVar8 = local_68;
  if (plVar6 != (longlong *)0x0) {
    lVar2 = *plVar6;
    pOVar7 = OdStreamBuf::desc();
    plVar8 = (longlong *)(**(code **)(lVar2 + 8))(plVar6,pOVar7);
    if (plVar8 == (longlong *)0x0) {
      pOVar7 = OdStreamBuf::desc();
      pOVar9 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res8,pOVar9,pOVar7);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_68 = plVar8;
  plVar6 = local_68;
  if (local_70 != (longlong *)0x0) {
    (**(code **)(*local_70 + 0x28))();
    local_70 = (longlong *)0x0;
  }
  if (uVar1 != 0) {
    uVar3 = uVar1 - 1;
    if (*(uint *)(param_1[7] + -4) <= uVar3) {
      OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_res8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
    }
    FUN_18016f6d0(param_1 + 7);
    (**(code **)(*plVar6 + 0x88))(plVar6,*(undefined4 *)(param_1[7] + (ulonglong)uVar3 * 4),0);
    (**(code **)(*plVar6 + 0x98))(plVar6,local_res8,4);
    (**(code **)(*plVar6 + 0x88))(plVar6,4,1);
    (**(code **)(*plVar6 + 0x98))(plVar6,local_res8,4);
    local_res8[0] = local_res8[0] * 2 + 4;
    (**(code **)(*plVar6 + 0x88))(plVar6,8,1);
    (**(code **)(*plVar6 + 0x98))(plVar6,local_res20,8);
    if (*(uint *)(param_1[7] + -4) <= uVar3) {
      OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_res20);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5370);
    }
    FUN_18016f6d0(param_1 + 7);
    if (param_2 != local_res8[0] + *(int *)(param_1[7] + (ulonglong)uVar3 * 4)) {
      OdError::OdError((OdError *)local_res8,5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
    }
  }
  if (*(uint *)(param_1[7] + -4) <= uVar1) {
    OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_res8);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
  }
  FUN_18016f6d0(param_1 + 7);
  *(int *)(param_1[7] + (ulonglong)uVar1 * 4) = param_2;
  uVar3 = 1;
  if (1 < param_3) {
    do {
      uVar11 = uVar1 + 1;
      uVar10 = (ulonglong)uVar1;
      if (*(uint *)(param_1[7] + -4) <= uVar1) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_48);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18016f6d0(param_1 + 7);
      (**(code **)(*plVar6 + 0x88))(plVar6,*(undefined4 *)(param_1[7] + uVar10 * 4),0);
      (**(code **)(*plVar6 + 0x98))(plVar6,&local_78,4);
      (**(code **)(*plVar6 + 0x88))(plVar6,4,1);
      (**(code **)(*plVar6 + 0x98))(plVar6,local_res20,4);
      local_res8[0] = local_res20[0] * 2 + 4;
      (**(code **)(*plVar6 + 0x88))(plVar6,8,1);
      (**(code **)(*plVar6 + 0x98))(plVar6,local_40);
      if (local_78 != 0) {
LAB_1809dc9a0:
        if (uVar3 < local_res18[0]) {
          local_res18[0] = 0;
          FUN_18048f790(param_1 + 7,(local_74 - 1) + uVar3,local_res18);
        }
        break;
      }
      if (*(uint *)(param_1[7] + -4) <= uVar1) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_50);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_50,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18016f6d0(param_1 + 7);
      lVar2 = param_1[7];
      uVar4 = (**(code **)(*param_1 + 0x70))(param_1);
      if (uVar4 <= (uint)(local_res8[0] + *(int *)(lVar2 + uVar10 * 4))) goto LAB_1809dc9a0;
      if (*(uint *)(param_1[7] + -4) <= uVar1) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_58);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_58,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18016f6d0(param_1 + 7);
      lVar2 = param_1[7];
      if (*(uint *)(lVar2 + -4) <= uVar11) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_60);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_60,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18016f6d0(param_1 + 7);
      *(int *)(param_1[7] + (ulonglong)uVar11 * 4) = local_res8[0] + *(int *)(lVar2 + uVar10 * 4);
      uVar3 = uVar3 + 1;
      uVar1 = uVar11;
    } while (uVar3 < local_res18[0]);
  }
  if (plVar6 != (longlong *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  return;
}



