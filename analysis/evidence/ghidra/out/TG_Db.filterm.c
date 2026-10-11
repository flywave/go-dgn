/* ==== 1808ae520 FUN_1808ae520 ==== */

void FUN_1808ae520(OdDgDimStackedLocation *param_1,undefined4 *param_2,ToolType param_3)

{
  ToolType TVar1;
  ToolType TVar2;
  OdDgDimStackedLocation *this;
  OdError local_res20 [8];
  
  TVar1 = OdDgDimStackedLocation::dimensionType(param_1);
  if (TVar1 < param_3) {
    this = param_1 + 0x20;
    (**(code **)(*(longlong *)(param_1 + 0x20) + 0x68))(this,*param_2);
    TVar1 = OdDgDimStackedLocation::dimensionType(this);
    TVar2 = OdDgDimStackedLocation::dimensionType(this);
    FUN_1808ae0b0(param_1,(ulonglong)TVar1 + (longlong)param_2,param_3 - TVar2);
    return;
  }
  OdError::OdError(local_res20,5);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
}



