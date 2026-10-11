/* ==== 18000ea60 createObject ==== */

/* public: static class OdSmartPtr<class OdDgEllipse2d> __cdecl OdDgEllipse2d::createObject(void) */

void __cdecl OdDgEllipse2d::createObject(void)

{
  OdRxClass *pOVar1;
  longlong *plVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *in_RCX;
  OdError local_res10 [8];
  longlong *local_res18;
  
                    /* 0xea60  5974
                       ?createObject@OdDgEllipse2d@@SA?AV?$OdSmartPtr@VOdDgEllipse2d@@@@XZ */
  pOVar1 = desc();
  if (pOVar1 == (OdRxClass *)0x0) {
    OdError::OdError(local_res10,0xff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de52b8);
  }
  pOVar1 = desc();
  plVar2 = (longlong *)(**(code **)(*(longlong *)pOVar1 + 0x58))(pOVar1,&local_res18);
  *in_RCX = 0;
  plVar2 = (longlong *)*plVar2;
  if (plVar2 != (longlong *)0x0) {
    lVar3 = *plVar2;
    pOVar1 = desc();
    lVar3 = (**(code **)(lVar3 + 8))(plVar2,pOVar1);
    if (lVar3 == 0) {
      pOVar1 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res10,pOVar4,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de5310);
    }
    *in_RCX = lVar3;
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  return;
}



/* ==== 18000ff00 createObject ==== */

/* public: static class OdSmartPtr<class OdDgShape2d> __cdecl OdDgShape2d::createObject(void) */

void __cdecl OdDgShape2d::createObject(void)

{
  OdRxClass *pOVar1;
  longlong *plVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *in_RCX;
  OdError local_res10 [8];
  longlong *local_res18;
  
                    /* 0xff00  6370  ?createObject@OdDgShape2d@@SA?AV?$OdSmartPtr@VOdDgShape2d@@@@XZ
                        */
  pOVar1 = desc();
  if (pOVar1 == (OdRxClass *)0x0) {
    OdError::OdError(local_res10,0xff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de52b8);
  }
  pOVar1 = desc();
  plVar2 = (longlong *)(**(code **)(*(longlong *)pOVar1 + 0x58))(pOVar1,&local_res18);
  *in_RCX = 0;
  plVar2 = (longlong *)*plVar2;
  if (plVar2 != (longlong *)0x0) {
    lVar3 = *plVar2;
    pOVar1 = desc();
    lVar3 = (**(code **)(lVar3 + 8))(plVar2,pOVar1);
    if (lVar3 == 0) {
      pOVar1 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res10,pOVar4,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de5310);
    }
    *in_RCX = lVar3;
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  return;
}



/* ==== 180038a50 createObject ==== */

/* public: static class OdSmartPtr<class OdDgArc2d> __cdecl OdDgArc2d::createObject(void) */

void __cdecl OdDgArc2d::createObject(void)

{
  OdRxClass *pOVar1;
  longlong *plVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *in_RCX;
  OdError local_res10 [8];
  longlong *local_res18;
  
                    /* 0x38a50  5689  ?createObject@OdDgArc2d@@SA?AV?$OdSmartPtr@VOdDgArc2d@@@@XZ */
  pOVar1 = desc();
  if (pOVar1 == (OdRxClass *)0x0) {
    OdError::OdError(local_res10,0xff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de52b8);
  }
  pOVar1 = desc();
  plVar2 = (longlong *)(**(code **)(*(longlong *)pOVar1 + 0x58))(pOVar1,&local_res18);
  *in_RCX = 0;
  plVar2 = (longlong *)*plVar2;
  if (plVar2 != (longlong *)0x0) {
    lVar3 = *plVar2;
    pOVar1 = desc();
    lVar3 = (**(code **)(lVar3 + 8))(plVar2,pOVar1);
    if (lVar3 == 0) {
      pOVar1 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res10,pOVar4,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de5310);
    }
    *in_RCX = lVar3;
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  return;
}



/* ==== 1800425a0 createObject ==== */

/* public: static class OdSmartPtr<class OdDgLineString2d> __cdecl
   OdDgLineString2d::createObject(void) */

void __cdecl OdDgLineString2d::createObject(void)

{
  OdRxClass *pOVar1;
  longlong *plVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *in_RCX;
  OdError local_res10 [8];
  longlong *local_res18;
  
                    /* 0x425a0  6132
                       ?createObject@OdDgLineString2d@@SA?AV?$OdSmartPtr@VOdDgLineString2d@@@@XZ */
  pOVar1 = desc();
  if (pOVar1 == (OdRxClass *)0x0) {
    OdError::OdError(local_res10,0xff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de52b8);
  }
  pOVar1 = desc();
  plVar2 = (longlong *)(**(code **)(*(longlong *)pOVar1 + 0x58))(pOVar1,&local_res18);
  *in_RCX = 0;
  plVar2 = (longlong *)*plVar2;
  if (plVar2 != (longlong *)0x0) {
    lVar3 = *plVar2;
    pOVar1 = desc();
    lVar3 = (**(code **)(lVar3 + 8))(plVar2,pOVar1);
    if (lVar3 == 0) {
      pOVar1 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res10,pOVar4,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de5310);
    }
    *in_RCX = lVar3;
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  return;
}



/* ==== 180048ad0 createObject ==== */

/* public: static class OdSmartPtr<class OdDgText2d> __cdecl OdDgText2d::createObject(void) */

void __cdecl OdDgText2d::createObject(void)

{
  OdRxClass *pOVar1;
  longlong *plVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *in_RCX;
  OdError local_res10 [8];
  longlong *local_res18;
  
                    /* 0x48ad0  6458  ?createObject@OdDgText2d@@SA?AV?$OdSmartPtr@VOdDgText2d@@@@XZ
                        */
  pOVar1 = desc();
  if (pOVar1 == (OdRxClass *)0x0) {
    OdError::OdError(local_res10,0xff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de52b8);
  }
  pOVar1 = desc();
  plVar2 = (longlong *)(**(code **)(*(longlong *)pOVar1 + 0x58))(pOVar1,&local_res18);
  *in_RCX = 0;
  plVar2 = (longlong *)*plVar2;
  if (plVar2 != (longlong *)0x0) {
    lVar3 = *plVar2;
    pOVar1 = desc();
    lVar3 = (**(code **)(lVar3 + 8))(plVar2,pOVar1);
    if (lVar3 == 0) {
      pOVar1 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res10,pOVar4,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de5310);
    }
    *in_RCX = lVar3;
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  return;
}



/* ==== 18015de00 createObject ==== */

/* public: static class OdSmartPtr<class OdDgLine2d> __cdecl OdDgLine2d::createObject(void) */

void __cdecl OdDgLine2d::createObject(void)

{
  OdRxClass *pOVar1;
  longlong *plVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *in_RCX;
  OdError local_res10 [8];
  longlong *local_res18;
  
                    /* 0x15de00  6128  ?createObject@OdDgLine2d@@SA?AV?$OdSmartPtr@VOdDgLine2d@@@@XZ
                        */
  pOVar1 = desc();
  if (pOVar1 == (OdRxClass *)0x0) {
    OdError::OdError(local_res10,0xff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de52b8);
  }
  pOVar1 = desc();
  plVar2 = (longlong *)(**(code **)(*(longlong *)pOVar1 + 0x58))(pOVar1,&local_res18);
  *in_RCX = 0;
  plVar2 = (longlong *)*plVar2;
  if (plVar2 != (longlong *)0x0) {
    lVar3 = *plVar2;
    pOVar1 = desc();
    lVar3 = (**(code **)(lVar3 + 8))(plVar2,pOVar1);
    if (lVar3 == 0) {
      pOVar1 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res10,pOVar4,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de5310);
    }
    *in_RCX = lVar3;
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
  }
  return;
}



