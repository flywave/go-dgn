/* ==== 1800aa8b0 pseudoConstructor ==== */

/* public: static class OdRxObjectPtr __cdecl
   OdDgRasterAttachmentComponentGeo::pseudoConstructor(void) */

void __cdecl OdDgRasterAttachmentComponentGeo::pseudoConstructor(void)

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
  
                    /* 0xaa8b0  16734
                       ?pseudoConstructor@OdDgRasterAttachmentComponentGeo@@SA?AVOdRxObjectPtr@@XZ
                        */
  this = (OdDgElement *)odrxAlloc(0x2c8);
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
    *(undefined ***)this =
         OdDgObjectWithImpl<OdDgRasterAttachmentComponentGeo,ERasterRefCompGeo>::vftable;
    FUN_1800970f0(this + 0x10);
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



