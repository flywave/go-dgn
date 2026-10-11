/* ==== 1803af910 dgnInFields ==== */

/* public: virtual enum OdResult __cdecl ERasterReference::dgnInFields(class OdDgFiler * __ptr64)
   __ptr64 */

OdResult __thiscall ERasterReference::dgnInFields(ERasterReference *this,OdDgFiler *param_1)

{
  longlong lVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  OdRxClass *pOVar8;
  OdRxClass *pOVar9;
  undefined8 uVar10;
  longlong *local_res8;
  longlong *local_res10;
  undefined1 local_38 [32];
  
                    /* 0x3af910  7798
                       ?dgnInFields@ERasterReference@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z */
  uVar2 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x240) = uVar2;
  uVar2 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x242) = uVar2;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x244) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x248) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x24c) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x250) = uVar3;
  iVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(double *)(this + 600) = (double)iVar4;
  iVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(double *)(this + 0x260) = (double)iVar4;
  puVar5 = (undefined8 *)(**(code **)(*(longlong *)param_1 + 0x110))(param_1,local_38);
  uVar10 = puVar5[1];
  *(undefined8 *)(this + 0x268) = *puVar5;
  *(undefined8 *)(this + 0x270) = uVar10;
  *(undefined8 *)(this + 0x278) = puVar5[2];
  uVar10 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x280) = uVar10;
  uVar10 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x288) = uVar10;
  uVar10 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x290) = uVar10;
  uVar10 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x298) = uVar10;
  if (*(short *)(this + 0x240) == 0) {
    uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    *(undefined4 *)(this + 0x2a0) = uVar3;
    uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    *(undefined4 *)(this + 0x2a4) = uVar3;
  }
  iVar4 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar4 == 2) {
    _updateAllChildren(this);
  }
  else {
    _removeAllChildren(this);
  }
  FUN_1803aed20(&local_res8);
  local_res8[3] = *(longlong *)(this + 0x58);
  plVar6 = (longlong *)(**(code **)(*(longlong *)param_1 + 0x70))(param_1);
  local_res10 = (longlong *)0x0;
  plVar7 = local_res10;
  if (plVar6 != (longlong *)0x0) {
    lVar1 = *plVar6;
    uVar10 = FUN_18004b620();
    plVar7 = (longlong *)(**(code **)(lVar1 + 8))(plVar6,uVar10);
    if (plVar7 == (longlong *)0x0) {
      pOVar8 = (OdRxClass *)FUN_18004b620();
      pOVar9 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res10,pOVar9,pOVar8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_res10 = plVar7;
  plVar7 = local_res10;
  if (local_res10 != (longlong *)0x0) {
    FUN_1809e53c0(local_res10,local_res8);
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  (**(code **)(*local_res8 + 0x28))(local_res8);
  iVar4 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar4 == 0) {
    this[0x2a8] = (ERasterReference)0x0;
  }
  return 0;
}



