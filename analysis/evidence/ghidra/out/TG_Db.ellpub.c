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



/* ==== 1802a0f70 getPrimaryAxis ==== */

/* public: virtual double __cdecl OdDgEllipse3d::getPrimaryAxis(void)const __ptr64 */

double __thiscall OdDgEllipse3d::getPrimaryAxis(OdDgEllipse3d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x2a0f70  12747  ?getPrimaryAxis@OdDgEllipse3d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse3D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802a0f9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x600))(plVar1);
  return dVar2;
}



/* ==== 1802a1270 getSecondaryAxis ==== */

/* public: virtual double __cdecl OdDgEllipse2d::getSecondaryAxis(void)const __ptr64 */

double __thiscall OdDgEllipse2d::getSecondaryAxis(OdDgEllipse2d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x2a1270  13176  ?getSecondaryAxis@OdDgEllipse2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse2D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802a129f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x610))(plVar1);
  return dVar2;
}



/* ==== 1802a12b0 getSecondaryAxis ==== */

/* public: virtual double __cdecl OdDgEllipse3d::getSecondaryAxis(void)const __ptr64 */

double __thiscall OdDgEllipse3d::getSecondaryAxis(OdDgEllipse3d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x2a12b0  13177  ?getSecondaryAxis@OdDgEllipse3d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse3D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802a12df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x610))(plVar1);
  return dVar2;
}



/* ==== 1802a1c90 setPrimaryAxis ==== */

/* public: virtual void __cdecl OdDgEllipse2d::setPrimaryAxis(double) __ptr64 */

void __thiscall OdDgEllipse2d::setPrimaryAxis(OdDgEllipse2d *this,double param_1)

{
  longlong *plVar1;
  undefined1 local_res8 [8];
  
                    /* 0x2a1c90  23197  ?setPrimaryAxis@OdDgEllipse2d@@UEAAXN@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse2D::RTTI_Type_Descriptor,0);
  (**(code **)(*(longlong *)this + 0x350))(this,1);
  (**(code **)(*plVar1 + 0x608))(plVar1,local_res8,SUB84(param_1,0));
  return;
}



/* ==== 1802a1d10 setPrimaryAxis ==== */

/* public: virtual void __cdecl OdDgEllipse3d::setPrimaryAxis(double) __ptr64 */

void __thiscall OdDgEllipse3d::setPrimaryAxis(OdDgEllipse3d *this,double param_1)

{
  longlong *plVar1;
  undefined1 local_res8 [8];
  
                    /* 0x2a1d10  23198  ?setPrimaryAxis@OdDgEllipse3d@@UEAAXN@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse3D::RTTI_Type_Descriptor,0);
  (**(code **)(*(longlong *)this + 0x350))(this,1);
  (**(code **)(*plVar1 + 0x608))(plVar1,local_res8,SUB84(param_1,0));
  return;
}



/* ==== 1802a1e80 setSecondaryAxis ==== */

/* public: virtual void __cdecl OdDgEllipse2d::setSecondaryAxis(double) __ptr64 */

void __thiscall OdDgEllipse2d::setSecondaryAxis(OdDgEllipse2d *this,double param_1)

{
  longlong *plVar1;
  undefined1 local_res8 [8];
  
                    /* 0x2a1e80  23560  ?setSecondaryAxis@OdDgEllipse2d@@UEAAXN@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse2D::RTTI_Type_Descriptor,0);
  (**(code **)(*(longlong *)this + 0x350))(this,1);
  (**(code **)(*plVar1 + 0x618))(plVar1,local_res8,SUB84(param_1,0));
  return;
}



/* ==== 1802a1f00 setSecondaryAxis ==== */

/* public: virtual void __cdecl OdDgEllipse3d::setSecondaryAxis(double) __ptr64 */

void __thiscall OdDgEllipse3d::setSecondaryAxis(OdDgEllipse3d *this,double param_1)

{
  longlong *plVar1;
  undefined1 local_res8 [8];
  
                    /* 0x2a1f00  23561  ?setSecondaryAxis@OdDgEllipse3d@@UEAAXN@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse3D::RTTI_Type_Descriptor,0);
  (**(code **)(*(longlong *)this + 0x350))(this,1);
  (**(code **)(*plVar1 + 0x618))(plVar1,local_res8,SUB84(param_1,0));
  return;
}



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



/* ==== 1803d8cd0 getSecondaryAxis ==== */

/* public: virtual double __cdecl OdDgArc2d::getSecondaryAxis(void)const __ptr64 */

double __thiscall OdDgArc2d::getSecondaryAxis(OdDgArc2d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x3d8cd0  13174  ?getSecondaryAxis@OdDgArc2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc2D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d8cff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x630))(plVar1);
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



/* ==== 1803d9920 setPrimaryAxis ==== */

/* public: virtual void __cdecl OdDgArc2d::setPrimaryAxis(double) __ptr64 */

void __thiscall OdDgArc2d::setPrimaryAxis(OdDgArc2d *this,double param_1)

{
  longlong *plVar1;
  undefined1 local_res8 [8];
  
                    /* 0x3d9920  23195  ?setPrimaryAxis@OdDgArc2d@@UEAAXN@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc2D::RTTI_Type_Descriptor,0);
  (**(code **)(*(longlong *)this + 0x350))(this,1);
  (**(code **)(*plVar1 + 0x628))(plVar1,local_res8,SUB84(param_1,0));
  return;
}



/* ==== 1803d99a0 setPrimaryAxis ==== */

/* public: virtual void __cdecl OdDgArc3d::setPrimaryAxis(double) __ptr64 */

void __thiscall OdDgArc3d::setPrimaryAxis(OdDgArc3d *this,double param_1)

{
  longlong *plVar1;
  undefined1 local_res8 [8];
  
                    /* 0x3d99a0  23196  ?setPrimaryAxis@OdDgArc3d@@UEAAXN@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
  (**(code **)(*(longlong *)this + 0x350))(this,1);
  (**(code **)(*plVar1 + 0x628))(plVar1,local_res8,SUB84(param_1,0));
  return;
}



/* ==== 1803d9b20 setSecondaryAxis ==== */

/* public: virtual void __cdecl OdDgArc2d::setSecondaryAxis(double) __ptr64 */

void __thiscall OdDgArc2d::setSecondaryAxis(OdDgArc2d *this,double param_1)

{
  longlong *plVar1;
  undefined1 local_res8 [8];
  
                    /* 0x3d9b20  23558  ?setSecondaryAxis@OdDgArc2d@@UEAAXN@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc2D::RTTI_Type_Descriptor,0);
  (**(code **)(*(longlong *)this + 0x350))(this,1);
  (**(code **)(*plVar1 + 0x638))(plVar1,local_res8,SUB84(param_1,0));
  return;
}



/* ==== 1803d9ba0 setSecondaryAxis ==== */

/* public: virtual void __cdecl OdDgArc3d::setSecondaryAxis(double) __ptr64 */

void __thiscall OdDgArc3d::setSecondaryAxis(OdDgArc3d *this,double param_1)

{
  longlong *plVar1;
  undefined1 local_res8 [8];
  
                    /* 0x3d9ba0  23559  ?setSecondaryAxis@OdDgArc3d@@UEAAXN@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
  (**(code **)(*(longlong *)this + 0x350))(this,1);
  (**(code **)(*plVar1 + 0x638))(plVar1,local_res8,SUB84(param_1,0));
  return;
}



