/* ==== 1802a0f30 getPrimaryAxis ==== */

/* public: virtual double __cdecl OdDgEllipse2d::getPrimaryAxis(void)const __ptr64 */

double __thiscall OdDgEllipse2d::getPrimaryAxis(OdDgEllipse2d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x2a0f30  12746  ?getPrimaryAxis@OdDgEllipse2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse2D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802a0f5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x600))(plVar1);
  return dVar2;
}



/* ==== 1802a0ff0 getRotationAngle ==== */

/* public: virtual double __cdecl OdDgEllipse2d::getRotationAngle(void)const __ptr64 */

double __thiscall OdDgEllipse2d::getRotationAngle(OdDgEllipse2d *this)

{
  longlong *plVar1;
  double *pdVar2;
  
                    /* 0x2a0ff0  13077  ?getRotationAngle@OdDgEllipse2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse2D::RTTI_Type_Descriptor,0);
  pdVar2 = (double *)(**(code **)(*plVar1 + 0x638))(plVar1);
  return *pdVar2;
}



