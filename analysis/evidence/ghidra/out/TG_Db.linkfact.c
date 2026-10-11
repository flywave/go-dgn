/* ==== 1808bf690 FUN_1808bf690 ==== */

undefined8 *
FUN_1808bf690(longlong *param_1,undefined8 *param_2,ushort param_3,undefined8 param_4,
             undefined4 param_5)

{
  char cVar1;
  undefined8 *puVar2;
  longlong lVar3;
  bool bVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  longlong *plVar8;
  OdRxClass *pOVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  longlong *local_18;
  longlong *local_10;
  
  puVar2 = (undefined8 *)*param_1;
  cVar1 = *(char *)((longlong)puVar2[1] + 0x19);
  puVar5 = puVar2;
  puVar11 = (undefined8 *)puVar2[1];
  while (cVar1 == '\0') {
    if (*(ushort *)(puVar11 + 4) < param_3) {
      puVar10 = (undefined8 *)puVar11[2];
      puVar11 = puVar5;
    }
    else {
      puVar10 = (undefined8 *)*puVar11;
    }
    puVar5 = puVar11;
    puVar11 = puVar10;
    cVar1 = *(char *)((longlong)puVar10 + 0x19);
  }
  plVar8 = (longlong *)0x0;
  if ((*(char *)((longlong)puVar5 + 0x19) != '\0') ||
     (bVar4 = true, param_3 < *(ushort *)(puVar5 + 4))) {
    bVar4 = false;
  }
  puVar11 = puVar2;
  if (bVar4) {
    puVar11 = puVar5;
  }
  if (puVar11 != puVar2) {
    plVar6 = (longlong *)(*(code *)puVar11[5])(&local_18,param_4,param_5);
    plVar6 = (longlong *)*plVar6;
    if (plVar6 != (longlong *)0x0) {
      (**(code **)(*plVar6 + 0x20))();
      plVar8 = plVar6;
    }
    if (local_18 != (longlong *)0x0) {
      (**(code **)(*local_18 + 0x28))();
    }
    if (plVar8 != (longlong *)0x0) goto LAB_1808bf790;
  }
  plVar6 = (longlong *)FUN_1801c50b0(&local_10,param_3,param_4,param_5);
  plVar6 = (longlong *)*plVar6;
  if (plVar6 != (longlong *)0x0) {
    lVar3 = *plVar6;
    pOVar7 = OdDgAttributeLinkage::desc();
    plVar8 = (longlong *)(**(code **)(lVar3 + 8))(plVar6,pOVar7);
    if (plVar8 == (longlong *)0x0) {
      pOVar7 = OdDgAttributeLinkage::desc();
      pOVar9 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_18,pOVar9,pOVar7);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_18,(ThrowInfo *)&DAT_180de5310);
    }
  }
  if (local_10 != (longlong *)0x0) {
    (**(code **)(*local_10 + 0x28))();
  }
LAB_1808bf790:
  *param_2 = plVar8;
  if (plVar8 != (longlong *)0x0) {
    (**(code **)(*plVar8 + 0x20))(plVar8);
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  return param_2;
}



/* ==== 1808bf800 FUN_1808bf800 ==== */

void FUN_1808bf800(void)

{
  OdError local_res8 [32];
  
  if (DAT_181020c48 != 0) {
    return;
  }
  OdError::OdError(local_res8,0xff);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
}



