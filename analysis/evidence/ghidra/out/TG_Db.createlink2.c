/* ==== 1801c50b0 FUN_1801c50b0 ==== */

longlong * FUN_1801c50b0(longlong *param_1,undefined2 param_2,undefined4 *param_3,ToolType param_4)

{
  code *pcVar1;
  ToolType TVar2;
  ToolType TVar3;
  longlong *plVar4;
  _func_void *p_Var5;
  OdRxClass *pOVar6;
  longlong lVar7;
  OdRxClass *pOVar8;
  OdDgAttributeLinkageHeader *this;
  OdDgDimStackedLocation *pOVar9;
  void *_Dst;
  longlong *local_48;
  longlong *local_40;
  undefined1 local_38 [32];
  
  plVar4 = (longlong *)odrxAlloc(0x30);
  if (plVar4 == (longlong *)0x0) {
    p_Var5 = std::get_new_handler();
    if (p_Var5 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var5)();
  }
  local_48 = plVar4;
  if (plVar4 != (longlong *)0x0) {
    *plVar4 = (longlong)OdRxObjectImpl<OdDgProxyLinkage,OdDgProxyLinkage>::vftable;
    *(undefined4 *)(plVar4 + 1) = 0xffffffff;
    *(undefined4 *)(plVar4 + 1) = 0;
    LOCK();
    *(undefined4 *)(plVar4 + 1) = 1;
    UNLOCK();
    *plVar4 = (longlong)OdDgProxyLinkageImpl::vftable;
    *(undefined2 *)(plVar4 + 2) = param_2;
    pcVar1 = g_empty_array_buffer_exref;
    plVar4[3] = (longlong)(g_empty_array_buffer_exref + 0x10);
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + 1;
    UNLOCK();
    this = (OdDgAttributeLinkageHeader *)(plVar4 + 4);
    OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(this);
    if (param_3 != (undefined4 *)0x0) {
      TVar2 = OdDgDimStackedLocation::dimensionType((OdDgDimStackedLocation *)this);
      if (TVar2 < param_4) {
        pOVar9 = (OdDgDimStackedLocation *)(plVar4 + 4);
        (**(code **)(plVar4[4] + 0x68))(pOVar9,*param_3);
        TVar2 = OdDgDimStackedLocation::dimensionType(pOVar9);
        FUN_1800150c0(plVar4 + 3,param_4 - TVar2);
        pOVar9 = (OdDgDimStackedLocation *)(plVar4 + 3);
        FUN_18000d0b0();
        _Dst = (void *)0x0;
        if (*(int *)(plVar4[3] + -4) != 0) {
          _Dst = (void *)plVar4[3];
        }
        TVar3 = OdDgDimStackedLocation::dimensionType(pOVar9);
        memcpy(_Dst,(void *)((ulonglong)TVar3 + (longlong)param_3),(ulonglong)(param_4 - TVar2));
      }
    }
  }
  *param_1 = 0;
  local_40 = plVar4;
  if (plVar4 != (longlong *)0x0) {
    lVar7 = *plVar4;
    pOVar6 = OdDgProxyLinkage::desc();
    lVar7 = (**(code **)(lVar7 + 8))(plVar4,pOVar6);
    if (lVar7 == 0) {
      pOVar6 = OdDgProxyLinkage::desc();
      pOVar8 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_48,pOVar8,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_48,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar7;
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  return param_1;
}



