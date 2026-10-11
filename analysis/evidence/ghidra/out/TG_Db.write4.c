/* ==== 1803b6380 FUN_1803b6380 ==== */

undefined8 FUN_1803b6380(longlong param_1,longlong *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x240) = uVar2;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x244) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x246) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x248) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x24a) = uVar1;
  return 0;
}



/* ==== 1803b6400 FUN_1803b6400 ==== */

void FUN_1803b6400(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  OdDgElementId *this;
  longlong *plVar5;
  OdRxClass *pOVar6;
  longlong *plVar7;
  ulonglong uVar8;
  OdRxClass *pOVar9;
  uint uVar10;
  longlong *local_res8 [2];
  longlong *local_res18;
  longlong *local_res20;
  undefined1 local_48 [16];
  
  uVar10 = 0;
  bVar2 = false;
  (**(code **)(*param_1 + 0x1e8))(param_1,local_res8);
  do {
    cVar3 = (**(code **)(*local_res8[0] + 0x60))();
    if (cVar3 != '\0') {
LAB_1803b655f:
      if (local_res8[0] != (longlong *)0x0) {
        (**(code **)(*local_res8[0] + 0x28))();
      }
      if (bVar2) {
        iVar4 = (uVar10 >> 1) - 1;
      }
      else {
        iVar4 = (int)param_1[0x48];
      }
      (**(code **)(*param_2 + 0x160))(param_2,iVar4);
      (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)((longlong)param_1 + 0x244));
      (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)((longlong)param_1 + 0x246));
      (**(code **)(*param_2 + 0x158))(param_2,(short)param_1[0x49]);
                    /* WARNING: Could not recover jumptable at 0x0001803b65ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)((longlong)param_1 + 0x24a));
      return;
    }
    this = (OdDgElementId *)(**(code **)(*local_res8[0] + 0x68))(local_res8[0],local_48);
    plVar5 = (longlong *)OdDgElementId::openObject(this,(OpenMode)&local_res18,false);
    local_res20 = (longlong *)0x0;
    plVar5 = (longlong *)*plVar5;
    plVar7 = local_res20;
    if (plVar5 != (longlong *)0x0) {
      lVar1 = *plVar5;
      pOVar6 = OdDgGraphicsElement::desc();
      plVar7 = (longlong *)(**(code **)(lVar1 + 8))(plVar5,pOVar6);
      if (plVar7 == (longlong *)0x0) {
        pOVar6 = OdDgGraphicsElement::desc();
        pOVar9 = (OdRxClass *)(**(code **)(*plVar5 + 0x18))(plVar5);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_res20,pOVar9,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_res20 = plVar7;
    plVar5 = local_res20;
    if (local_res18 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 0x28))();
      local_res18 = (longlong *)0x0;
    }
    if (plVar5 != (longlong *)0x0) {
      uVar8 = (**(code **)(*plVar5 + 0x430))(plVar5);
      if ((uVar8 & 0xfffffffd) != 0) {
        bVar2 = true;
        (**(code **)(*plVar5 + 0x28))(plVar5);
        goto LAB_1803b655f;
      }
      uVar10 = uVar10 + 1;
      plVar7 = (longlong *)
               __RTDynamicCast(plVar5[1],0,&OdDgElementImpl::RTTI_Type_Descriptor,
                               &CDGComplexGeneral::RTTI_Type_Descriptor,0);
      if (plVar7 != (longlong *)0x0) {
        iVar4 = (**(code **)(*plVar5 + 0x100))(plVar5);
        if (iVar4 != 0x1b) {
          iVar4 = (**(code **)(*plVar7 + 0x648))(plVar7,1);
          uVar10 = uVar10 + iVar4;
        }
      }
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
    (**(code **)(*local_res8[0] + 0x70))(local_res8[0],1);
  } while( true );
}



