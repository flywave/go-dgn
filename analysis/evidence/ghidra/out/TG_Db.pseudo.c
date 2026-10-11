/* ==== 1800a4b90 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl OdDgArc2d::pseudoConstructor(void) */

void __cdecl OdDgArc2d::pseudoConstructor(void)

{
  OdDgElement *this;
  _func_void *p_Var1;
  OdDgElement *pOVar2;
  OdRxClass *pOVar3;
  OdRxClass *pOVar4;
  undefined8 *in_RCX;
  OdDgElement *pOVar5;
  OdError_NotThatKindOfClass local_res18 [16];
  undefined1 local_38 [32];
  
                    /* 0xa4b90  16162  ?pseudoConstructor@OdDgArc2d@@SA?AVOdRxObjectPtr@@XZ */
  this = (OdDgElement *)odrxAlloc(0x278);
  if (this == (OdDgElement *)0x0) {
    p_Var1 = std::get_new_handler();
    if (p_Var1 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var1)();
  }
  pOVar2 = (OdDgElement *)0x0;
  pOVar5 = pOVar2;
  if (this != (OdDgElement *)0x0) {
    OdDgElement::OdDgElement(this,(OdDgElementImpl *)0x0);
    *(undefined ***)this = OdDgObjectWithImpl<OdDgArc2d,EArc2D>::vftable;
    FUN_180096790(this + 0x10);
    *(OdDgElement **)(this + 8) = this + 0x10;
    pOVar5 = this;
  }
  if (pOVar5 != (OdDgElement *)0x0) {
    pOVar2 = (OdDgElement *)(**(code **)(*(longlong *)pOVar5 + 8))(pOVar5,g_pDesc);
    if (pOVar2 == (OdDgElement *)0x0) {
      pOVar3 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*(longlong *)pOVar5 + 0x18))(pOVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res18,pOVar4,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5310);
    }
    (**(code **)(*(longlong *)pOVar5 + 0x28))(pOVar5);
  }
  *in_RCX = pOVar2;
  if (pOVar2 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)pOVar2 + 0x20))(pOVar2);
    (**(code **)(*(longlong *)pOVar2 + 0x28))(pOVar2);
  }
  return;
}



/* ==== 1800a8600 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl OdDgEllipse2d::pseudoConstructor(void) */

void __cdecl OdDgEllipse2d::pseudoConstructor(void)

{
  OdDgElement *this;
  _func_void *p_Var1;
  OdDgElement *pOVar2;
  OdRxClass *pOVar3;
  OdRxClass *pOVar4;
  undefined8 *in_RCX;
  OdDgElement *pOVar5;
  OdError_NotThatKindOfClass local_res18 [16];
  undefined1 local_38 [32];
  
                    /* 0xa8600  16434  ?pseudoConstructor@OdDgEllipse2d@@SA?AVOdRxObjectPtr@@XZ */
  this = (OdDgElement *)odrxAlloc(0x268);
  if (this == (OdDgElement *)0x0) {
    p_Var1 = std::get_new_handler();
    if (p_Var1 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var1)();
  }
  pOVar2 = (OdDgElement *)0x0;
  pOVar5 = pOVar2;
  if (this != (OdDgElement *)0x0) {
    OdDgElement::OdDgElement(this,(OdDgElementImpl *)0x0);
    *(undefined ***)this = OdDgObjectWithImpl<OdDgEllipse2d,EEllipse2D>::vftable;
    FUN_180096be0(this + 0x10);
    *(OdDgElement **)(this + 8) = this + 0x10;
    pOVar5 = this;
  }
  if (pOVar5 != (OdDgElement *)0x0) {
    pOVar2 = (OdDgElement *)(**(code **)(*(longlong *)pOVar5 + 8))(pOVar5,g_pDesc);
    if (pOVar2 == (OdDgElement *)0x0) {
      pOVar3 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*(longlong *)pOVar5 + 0x18))(pOVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res18,pOVar4,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5310);
    }
    (**(code **)(*(longlong *)pOVar5 + 0x28))(pOVar5);
  }
  *in_RCX = pOVar2;
  if (pOVar2 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)pOVar2 + 0x20))(pOVar2);
    (**(code **)(*(longlong *)pOVar2 + 0x28))(pOVar2);
  }
  return;
}



/* ==== 1800a9190 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl OdDgLine2d::pseudoConstructor(void) */

void __cdecl OdDgLine2d::pseudoConstructor(void)

{
  OdDgElement *this;
  _func_void *p_Var1;
  OdDgElement *pOVar2;
  OdRxClass *pOVar3;
  OdRxClass *pOVar4;
  undefined8 *in_RCX;
  OdDgElement *pOVar5;
  OdError_NotThatKindOfClass local_res18 [16];
  undefined1 local_38 [32];
  
                    /* 0xa9190  16576  ?pseudoConstructor@OdDgLine2d@@SA?AVOdRxObjectPtr@@XZ */
  this = (OdDgElement *)odrxAlloc(0x250);
  if (this == (OdDgElement *)0x0) {
    p_Var1 = std::get_new_handler();
    if (p_Var1 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var1)();
  }
  pOVar2 = (OdDgElement *)0x0;
  pOVar5 = pOVar2;
  if (this != (OdDgElement *)0x0) {
    OdDgElement::OdDgElement(this,(OdDgElementImpl *)0x0);
    *(undefined ***)this = OdDgObjectWithImpl<OdDgLine2d,ELine2D>::vftable;
    FUN_180096d80(this + 0x10);
    *(OdDgElement **)(this + 8) = this + 0x10;
    pOVar5 = this;
  }
  if (pOVar5 != (OdDgElement *)0x0) {
    pOVar2 = (OdDgElement *)(**(code **)(*(longlong *)pOVar5 + 8))(pOVar5,g_pDesc);
    if (pOVar2 == (OdDgElement *)0x0) {
      pOVar3 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*(longlong *)pOVar5 + 0x18))(pOVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res18,pOVar4,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5310);
    }
    (**(code **)(*(longlong *)pOVar5 + 0x28))(pOVar5);
  }
  *in_RCX = pOVar2;
  if (pOVar2 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)pOVar2 + 0x20))(pOVar2);
    (**(code **)(*(longlong *)pOVar2 + 0x28))(pOVar2);
  }
  return;
}



/* ==== 1800a92b0 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl OdDgLine3d::pseudoConstructor(void) */

void __cdecl OdDgLine3d::pseudoConstructor(void)

{
  OdDgElement *this;
  _func_void *p_Var1;
  OdDgElement *pOVar2;
  OdRxClass *pOVar3;
  OdRxClass *pOVar4;
  undefined8 *in_RCX;
  OdDgElement *pOVar5;
  OdError_NotThatKindOfClass local_res18 [16];
  undefined1 local_38 [32];
  
                    /* 0xa92b0  16577  ?pseudoConstructor@OdDgLine3d@@SA?AVOdRxObjectPtr@@XZ */
  this = (OdDgElement *)odrxAlloc(0x260);
  if (this == (OdDgElement *)0x0) {
    p_Var1 = std::get_new_handler();
    if (p_Var1 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var1)();
  }
  pOVar2 = (OdDgElement *)0x0;
  pOVar5 = pOVar2;
  if (this != (OdDgElement *)0x0) {
    OdDgElement::OdDgElement(this,(OdDgElementImpl *)0x0);
    *(undefined ***)this = OdDgObjectWithImpl<OdDgLine3d,ELine3D>::vftable;
    FUN_180096e20(this + 0x10);
    *(OdDgElement **)(this + 8) = this + 0x10;
    pOVar5 = this;
  }
  if (pOVar5 != (OdDgElement *)0x0) {
    pOVar2 = (OdDgElement *)(**(code **)(*(longlong *)pOVar5 + 8))(pOVar5,g_pDesc);
    if (pOVar2 == (OdDgElement *)0x0) {
      pOVar3 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*(longlong *)pOVar5 + 0x18))(pOVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res18,pOVar4,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5310);
    }
    (**(code **)(*(longlong *)pOVar5 + 0x28))(pOVar5);
  }
  *in_RCX = pOVar2;
  if (pOVar2 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)pOVar2 + 0x20))(pOVar2);
    (**(code **)(*(longlong *)pOVar2 + 0x28))(pOVar2);
  }
  return;
}



/* ==== 1800a93d0 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl OdDgLineString2d::pseudoConstructor(void) */

void __cdecl OdDgLineString2d::pseudoConstructor(void)

{
  OdDgElement *this;
  _func_void *p_Var1;
  OdDgElement *pOVar2;
  OdRxClass *pOVar3;
  OdRxClass *pOVar4;
  undefined8 *in_RCX;
  OdDgElement *pOVar5;
  OdDgElement *local_res18 [2];
  undefined1 local_38 [32];
  
                    /* 0xa93d0  16580  ?pseudoConstructor@OdDgLineString2d@@SA?AVOdRxObjectPtr@@XZ
                        */
  this = (OdDgElement *)odrxAlloc(600);
  if (this == (OdDgElement *)0x0) {
    p_Var1 = std::get_new_handler();
    if (p_Var1 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var1)();
  }
  pOVar2 = (OdDgElement *)0x0;
  pOVar5 = pOVar2;
  if (this != (OdDgElement *)0x0) {
    OdDgElement::OdDgElement(this,(OdDgElementImpl *)0x0);
    *(undefined ***)this = OdDgObjectWithImpl<OdDgLineString2d,ELineString2D>::vftable;
    pOVar5 = this + 0x10;
    local_res18[0] = pOVar5;
    FUN_180096ed0(pOVar5);
    *(undefined ***)pOVar5 = ELineString2D::vftable;
    *(undefined ***)(this + 0x230) = ELineString2D::vftable;
    *(undefined4 *)(this + 0xcc) = 4;
    *(OdDgElement **)(this + 8) = pOVar5;
    pOVar5 = this;
  }
  if (pOVar5 != (OdDgElement *)0x0) {
    pOVar2 = (OdDgElement *)(**(code **)(*(longlong *)pOVar5 + 8))(pOVar5,g_pDesc);
    if (pOVar2 == (OdDgElement *)0x0) {
      pOVar3 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*(longlong *)pOVar5 + 0x18))(pOVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res18,pOVar4,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5310);
    }
    (**(code **)(*(longlong *)pOVar5 + 0x28))(pOVar5);
  }
  *in_RCX = pOVar2;
  if (pOVar2 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)pOVar2 + 0x20))(pOVar2);
    (**(code **)(*(longlong *)pOVar2 + 0x28))(pOVar2);
  }
  return;
}



/* ==== 1800ab960 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl OdDgShape2d::pseudoConstructor(void) */

void __cdecl OdDgShape2d::pseudoConstructor(void)

{
  OdDgElement *this;
  _func_void *p_Var1;
  OdDgElement *pOVar2;
  OdRxClass *pOVar3;
  OdRxClass *pOVar4;
  undefined8 *in_RCX;
  OdDgElement *pOVar5;
  OdError_NotThatKindOfClass local_res18 [16];
  undefined1 local_38 [32];
  
                    /* 0xab960  16805  ?pseudoConstructor@OdDgShape2d@@SA?AVOdRxObjectPtr@@XZ */
  this = (OdDgElement *)odrxAlloc(0x270);
  if (this == (OdDgElement *)0x0) {
    p_Var1 = std::get_new_handler();
    if (p_Var1 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var1)();
  }
  pOVar2 = (OdDgElement *)0x0;
  pOVar5 = pOVar2;
  if (this != (OdDgElement *)0x0) {
    OdDgElement::OdDgElement(this,(OdDgElementImpl *)0x0);
    *(undefined ***)this = OdDgObjectWithImpl<OdDgShape2d,EShape2D>::vftable;
    FUN_180097260(this + 0x10);
    *(OdDgElement **)(this + 8) = this + 0x10;
    pOVar5 = this;
  }
  if (pOVar5 != (OdDgElement *)0x0) {
    pOVar2 = (OdDgElement *)(**(code **)(*(longlong *)pOVar5 + 8))(pOVar5,g_pDesc);
    if (pOVar2 == (OdDgElement *)0x0) {
      pOVar3 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*(longlong *)pOVar5 + 0x18))(pOVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res18,pOVar4,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5310);
    }
    (**(code **)(*(longlong *)pOVar5 + 0x28))(pOVar5);
  }
  *in_RCX = pOVar2;
  if (pOVar2 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)pOVar2 + 0x20))(pOVar2);
    (**(code **)(*(longlong *)pOVar2 + 0x28))(pOVar2);
  }
  return;
}



/* ==== 1800ac4a0 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl OdDgText2d::pseudoConstructor(void) */

void __cdecl OdDgText2d::pseudoConstructor(void)

{
  OdDgElement *this;
  _func_void *p_Var1;
  OdDgElement *pOVar2;
  OdRxClass *pOVar3;
  OdRxClass *pOVar4;
  undefined8 *in_RCX;
  OdDgElement *pOVar5;
  OdError_NotThatKindOfClass local_res18 [16];
  undefined1 local_38 [32];
  
                    /* 0xac4a0  16891  ?pseudoConstructor@OdDgText2d@@SA?AVOdRxObjectPtr@@XZ */
  this = (OdDgElement *)odrxAlloc(0x468);
  if (this == (OdDgElement *)0x0) {
    p_Var1 = std::get_new_handler();
    if (p_Var1 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var1)();
  }
  pOVar2 = (OdDgElement *)0x0;
  pOVar5 = pOVar2;
  if (this != (OdDgElement *)0x0) {
    OdDgElement::OdDgElement(this,(OdDgElementImpl *)0x0);
    *(undefined ***)this = OdDgObjectWithImpl<OdDgText2d,EText2D>::vftable;
    *(undefined ***)(this + 0x10) = OdDgObjectWithImpl<OdDgText2d,EText2D>::vftable;
    *(undefined ***)(this + 0x18) = OdDgObjectWithImpl<OdDgText2d,EText2D>::vftable;
    FUN_18028fca0(this + 0x20);
    *(OdDgElement **)(this + 8) = this + 0x20;
    pOVar5 = this;
  }
  if (pOVar5 != (OdDgElement *)0x0) {
    pOVar2 = (OdDgElement *)(**(code **)(*(longlong *)pOVar5 + 8))(pOVar5,g_pDesc);
    if (pOVar2 == (OdDgElement *)0x0) {
      pOVar3 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*(longlong *)pOVar5 + 0x18))(pOVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res18,pOVar4,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5310);
    }
    (**(code **)(*(longlong *)pOVar5 + 0x28))(pOVar5);
  }
  *in_RCX = pOVar2;
  if (pOVar2 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)pOVar2 + 0x20))(pOVar2);
    (**(code **)(*(longlong *)pOVar2 + 0x28))(pOVar2);
  }
  return;
}



/* ==== 1800ac700 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl OdDgTextNode2d::pseudoConstructor(void) */

void __cdecl OdDgTextNode2d::pseudoConstructor(void)

{
  OdDgElement *this;
  _func_void *p_Var1;
  OdDgElement *pOVar2;
  OdRxClass *pOVar3;
  OdRxClass *pOVar4;
  undefined8 *in_RCX;
  OdDgElement *pOVar5;
  OdError_NotThatKindOfClass local_res18 [16];
  undefined1 local_38 [32];
  
                    /* 0xac700  16898  ?pseudoConstructor@OdDgTextNode2d@@SA?AVOdRxObjectPtr@@XZ */
  this = (OdDgElement *)odrxAlloc(0x478);
  if (this == (OdDgElement *)0x0) {
    p_Var1 = std::get_new_handler();
    if (p_Var1 == (_func_void *)0x0) {
      FUN_1800044e0(local_38);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var1)();
  }
  pOVar2 = (OdDgElement *)0x0;
  pOVar5 = pOVar2;
  if (this != (OdDgElement *)0x0) {
    OdDgElement::OdDgElement(this,(OdDgElementImpl *)0x0);
    *(undefined ***)this = OdDgObjectWithImpl<OdDgTextNode2d,ETextNode2D>::vftable;
    *(undefined ***)(this + 0x10) = OdDgObjectWithImpl<OdDgTextNode2d,ETextNode2D>::vftable;
    *(undefined ***)(this + 0x18) = OdDgObjectWithImpl<OdDgTextNode2d,ETextNode2D>::vftable;
    FUN_1802015a0(this + 0x20);
    *(OdDgElement **)(this + 8) = this + 0x20;
    pOVar5 = this;
  }
  if (pOVar5 != (OdDgElement *)0x0) {
    pOVar2 = (OdDgElement *)(**(code **)(*(longlong *)pOVar5 + 8))(pOVar5,g_pDesc);
    if (pOVar2 == (OdDgElement *)0x0) {
      pOVar3 = desc();
      pOVar4 = (OdRxClass *)(**(code **)(*(longlong *)pOVar5 + 0x18))(pOVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res18,pOVar4,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5310);
    }
    (**(code **)(*(longlong *)pOVar5 + 0x28))(pOVar5);
  }
  *in_RCX = pOVar2;
  if (pOVar2 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)pOVar2 + 0x20))(pOVar2);
    (**(code **)(*(longlong *)pOVar2 + 0x28))(pOVar2);
  }
  return;
}



