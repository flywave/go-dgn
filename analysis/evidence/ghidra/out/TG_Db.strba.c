/* ==== 1800545f0 FUN_1800545f0 ==== */

OdString * FUN_1800545f0(OdDgDimStackedLocation *param_1,OdString *param_2)

{
  uint uVar1;
  int iVar2;
  ToolType TVar3;
  ulonglong uVar4;
  code *pcVar5;
  short *psVar6;
  code *pcVar7;
  ulonglong uVar8;
  code *local_res8;
  char *local_res18;
  OdString local_res20 [8];
  OdError_InvalidIndex local_28 [16];
  
  TVar3 = OdDgDimStackedLocation::dimensionType(param_1);
  local_res18 = (char *)((ulonglong)TVar3 + *(longlong *)(param_1 + 0x10) + 8);
  uVar1 = *(uint *)(local_res18 + -4);
  if (uVar1 == 0) {
    OdString::init(param_2);
  }
  else {
    if ((*local_res18 != -1) || ((byte)local_res18[1] < 0xf1)) {
      OdString::OdString(param_2,local_res18,uVar1,0x2e);
      return param_2;
    }
    if (((uVar1 < 5) || (local_res18[2] != '\x01')) || (local_res18[3] != '\0')) {
      local_res18 = local_res18 + 2;
      uVar4 = (ulonglong)(uVar1 - 2 >> 1);
      uVar8 = uVar4;
      if (uVar1 - 2 >> 1 != 0) {
        psVar6 = (short *)(local_res18 + (uVar4 - 1) * 2);
        do {
          if (*psVar6 != 0) break;
          uVar8 = (ulonglong)((int)uVar8 - 1);
          uVar4 = uVar4 - 1;
          psVar6 = psVar6 + -1;
        } while (0 < (longlong)uVar4);
      }
      FUN_1800544a0(local_res20,&local_res18,uVar8);
      OdString::OdString(param_2,local_res20);
      OdString::~OdString(local_res20);
      return param_2;
    }
    local_res8 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    OdCharMapper::multiByteToWideChar
              (0,local_res18 + 4,uVar1 - 4,
               (OdArray<unsigned_short,OdMemoryAllocator<unsigned_short>_> *)&local_res8);
    uVar1 = *(uint *)(local_res8 + -4) - 1;
    if (*(uint *)(local_res8 + -4) <= uVar1) {
      OdError_InvalidIndex::OdError_InvalidIndex(local_28);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_180de5370);
    }
    FUN_1800381e0(&local_res8);
    iVar2 = *(int *)(local_res8 + -4);
    pcVar7 = (code *)0x0;
    pcVar5 = pcVar7;
    if (iVar2 != 0) {
      pcVar5 = local_res8;
    }
    if (*(short *)(pcVar5 + (ulonglong)uVar1 * 2) == 0) {
      FUN_1800381e0(&local_res8);
      if (*(int *)(local_res8 + -4) != 0) {
        pcVar7 = local_res8;
      }
      OdString::OdString(param_2,(ushort *)pcVar7);
      pcVar5 = local_res8 + -0x10;
      LOCK();
      iVar2 = *(int *)pcVar5;
      *(int *)pcVar5 = *(int *)pcVar5 + -1;
      UNLOCK();
      if ((iVar2 == 1) && (pcVar5 != g_empty_array_buffer_exref)) {
        odrxFree();
        return param_2;
      }
    }
    else {
      FUN_1800381e0(&local_res8);
      if (*(int *)(local_res8 + -4) != 0) {
        pcVar7 = local_res8;
      }
      OdString::OdString(param_2,(ushort *)pcVar7,iVar2);
      pcVar5 = local_res8 + -0x10;
      LOCK();
      iVar2 = *(int *)pcVar5;
      *(int *)pcVar5 = *(int *)pcVar5 + -1;
      UNLOCK();
      if ((iVar2 == 1) && (pcVar5 != g_empty_array_buffer_exref)) {
        odrxFree();
        return param_2;
      }
    }
  }
  return param_2;
}



/* ==== 1808adc60 FUN_1808adc60 ==== */

void FUN_1808adc60(OdDgDimStackedLocation *param_1,undefined4 *param_2,ToolType param_3)

{
  ToolType TVar1;
  ToolType TVar2;
  OdDgDimStackedLocation *this;
  OdError local_res20 [8];
  
  TVar1 = OdDgDimStackedLocation::dimensionType(param_1);
  if (TVar1 < param_3) {
    this = param_1 + 0x18;
    (**(code **)(*(longlong *)(param_1 + 0x18) + 0x68))(this,*param_2);
    TVar1 = OdDgDimStackedLocation::dimensionType(this);
    TVar2 = OdDgDimStackedLocation::dimensionType(this);
    FUN_1808adac0(param_1,(ulonglong)TVar1 + (longlong)param_2,param_3 - TVar2);
    return;
  }
  OdError::OdError(local_res20,5);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
}



