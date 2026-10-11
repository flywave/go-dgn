/* ==== 1803d8990 getPrimaryAxis ==== */

/* public: virtual double __cdecl OdDgArc2d::getPrimaryAxis(void)const __ptr64 */

double __thiscall OdDgArc2d::getPrimaryAxis(OdDgArc2d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x3d8990  12744  ?getPrimaryAxis@OdDgArc2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc2D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d89bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x620))(plVar1);
  return dVar2;
}



/* ==== 1803d89d0 getPrimaryAxis ==== */

/* public: virtual double __cdecl OdDgArc3d::getPrimaryAxis(void)const __ptr64 */

double __thiscall OdDgArc3d::getPrimaryAxis(OdDgArc3d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x3d89d0  12745  ?getPrimaryAxis@OdDgArc3d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d89ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x620))(plVar1);
  return dVar2;
}



/* ==== 1803d8d10 getSecondaryAxis ==== */

/* public: virtual double __cdecl OdDgArc3d::getSecondaryAxis(void)const __ptr64 */

double __thiscall OdDgArc3d::getSecondaryAxis(OdDgArc3d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x3d8d10  13175  ?getSecondaryAxis@OdDgArc3d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d8d3f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x630))(plVar1);
  return dVar2;
}



