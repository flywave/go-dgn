/* ==== 1809dbf20 FUN_1809dbf20 ==== */

Error * FUN_1809dbf20(longlong *param_1,Error *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  int local_res18;
  Error local_res20 [8];
  
  FUN_1809e80c0();
  piVar3 = (int *)Dgn8::Error::Error(local_res20,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",
                                     0x134);
  if (*piVar3 == local_res18) {
    uVar1 = (**(code **)(*param_1 + 0x70))(param_1);
    if (3 < uVar1) {
      puVar4 = (uint *)(**(code **)(*param_1 + 200))(param_1);
      uVar1 = *puVar4;
      uVar2 = puVar4[1];
      *(byte *)((longlong)param_1 + 0x44) = (byte)uVar2 & 1;
      *(byte *)((longlong)param_1 + 0x45) = (byte)(uVar2 >> 2) & 1;
      if ((uVar1 != 0) && (uVar2 = (**(code **)(*param_1 + 0x70))(param_1), uVar1 < uVar2)) {
        FUN_1809dc670(param_1,(int)param_1[6],uVar1);
      }
    }
    Dgn8::Error::Error(param_2,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
    return param_2;
  }
  *(int *)param_2 = local_res18;
  return param_2;
}



/* ==== 1809e3c80 FUN_1809e3c80 ==== */

Error * FUN_1809e3c80(longlong *param_1,Error *param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  OdString *pOVar6;
  OdRxClass *this;
  undefined8 uVar7;
  OdString local_res20 [8];
  
  if (*param_3 != 0) {
    pOVar6 = (OdString *)(**(code **)(*param_1 + 0x58))(param_1,local_res20);
    bVar3 = true;
    if ((*(longlong *)(*(longlong *)pOVar6 + 0x10) == 0) &&
       (*(longlong *)(*(longlong *)pOVar6 + 0x18) != 0)) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (bVar4) {
      OdString::syncUnicode(pOVar6);
    }
    OdString::~OdString(local_res20);
    this = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
    pOVar6 = (OdString *)OdRxClass::name(this);
    if ((*(longlong *)(*(longlong *)pOVar6 + 0x10) != 0) ||
       (*(longlong *)(*(longlong *)pOVar6 + 0x18) == 0)) {
      bVar3 = false;
    }
    if (bVar3) {
      OdString::syncUnicode(pOVar6);
    }
    OdString::~OdString(local_res20);
    lVar1 = *param_1;
    uVar5 = (**(code **)(*(longlong *)*param_3 + 0x58))();
    (**(code **)(lVar1 + 0xd0))(param_1,local_res20,uVar5);
    plVar2 = (longlong *)*param_3;
    lVar1 = *plVar2;
    uVar5 = (**(code **)(*param_1 + 0x70))(param_1);
    uVar7 = (**(code **)(*param_1 + 200))(param_1);
    (**(code **)(lVar1 + 0x68))(plVar2,uVar7,uVar5);
    Dgn8::Error::Error(param_2,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
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



