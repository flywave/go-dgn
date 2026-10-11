/* ==== 1809dbff0 FUN_1809dbff0 ==== */

int * FUN_1809dbff0(longlong *param_1,int *param_2,longlong *param_3)

{
  int *piVar1;
  int local_res20 [2];
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)*param_3;
  if (local_18[0] != (longlong *)0x0) {
    (**(code **)(*local_18[0] + 0x20))();
  }
  FUN_1809e3c80(param_1,local_res20,local_18);
  piVar1 = (int *)Dgn8::Error::Error((Error *)local_18,0,
                                     "C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
  if (*piVar1 != local_res20[0]) {
    *param_2 = local_res20[0];
    if ((longlong *)*param_3 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*param_3 + 0x28))();
      *param_3 = 0;
    }
    return param_2;
  }
  piVar1 = (int *)(**(code **)(*param_1 + 0x98))(param_1,local_18);
  local_res20[0] = *piVar1;
  *param_2 = local_res20[0];
  if ((longlong *)*param_3 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_3 + 0x28))();
    *param_3 = 0;
  }
  return param_2;
}



/* ==== 1809e3dd0 FUN_1809e3dd0 ==== */

Error * FUN_1809e3dd0(longlong *param_1,Error *param_2,longlong *param_3)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  longlong *plVar4;
  undefined4 uVar5;
  OdString *pOVar6;
  OdRxClass *this;
  undefined8 uVar7;
  OdString local_res20 [8];
  longlong *local_38;
  longlong **local_30;
  
  local_38 = (longlong *)*param_3;
  if (local_38 != (longlong *)0x0) {
    (**(code **)(*local_38 + 0x20))(local_38);
  }
  local_30 = &local_38;
  if (local_38 != (longlong *)0x0) {
    pOVar6 = (OdString *)(**(code **)(*param_1 + 0x58))(param_1,local_res20);
    bVar2 = true;
    if ((*(longlong *)(*(longlong *)pOVar6 + 0x10) == 0) &&
       (*(longlong *)(*(longlong *)pOVar6 + 0x18) != 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      OdString::syncUnicode(pOVar6);
    }
    OdString::~OdString(local_res20);
    this = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
    pOVar6 = (OdString *)OdRxClass::name(this);
    if ((*(longlong *)(*(longlong *)pOVar6 + 0x10) != 0) ||
       (*(longlong *)(*(longlong *)pOVar6 + 0x18) == 0)) {
      bVar2 = false;
    }
    if (bVar2) {
      OdString::syncUnicode(pOVar6);
    }
    OdString::~OdString(local_res20);
    lVar1 = *param_1;
    uVar5 = (**(code **)(*local_38 + 0x58))();
    (**(code **)(lVar1 + 0xd0))(param_1,local_res20,uVar5);
    plVar4 = local_38;
    lVar1 = *local_38;
    uVar5 = (**(code **)(*param_1 + 0x70))(param_1);
    uVar7 = (**(code **)(*param_1 + 200))(param_1);
    (**(code **)(lVar1 + 0x68))(plVar4,uVar7,uVar5);
    Dgn8::Error::Error(param_2,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x28))();
      local_38 = (longlong *)0x0;
    }
    if ((longlong *)*param_3 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*param_3 + 0x28))();
      *param_3 = 0;
    }
    return param_2;
  }
  OdError::OdError((OdError *)local_res20,5);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
}



