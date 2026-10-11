/* ==== 1803d8d90 getStartAngle ==== */

/* public: virtual double __cdecl OdDgArc3d::getStartAngle(void)const __ptr64 */

double __thiscall OdDgArc3d::getStartAngle(OdDgArc3d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x3d8d90  13482  ?getStartAngle@OdDgArc3d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d8dbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x600))(plVar1);
  return dVar2;
}



/* ==== 1803d8ea0 getStartPoint ==== */

/* public: virtual enum OdResult __cdecl OdDgArc3d::getStartPoint(class OdGePoint3d & __ptr64)const
   __ptr64 */

OdResult __thiscall OdDgArc3d::getStartPoint(OdDgArc3d *this,OdGePoint3d *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  OdGeEllipArc3d local_res8 [32];
  
                    /* 0x3d8ea0  13499
                       ?getStartPoint@OdDgArc3d@@UEBA?AW4OdResult@@AEAVOdGePoint3d@@@Z */
  (**(code **)(*(longlong *)this + 0x750))(this,local_res8);
  puVar2 = (undefined8 *)OdGeEllipArc3d::startPoint(local_res8);
  uVar1 = puVar2[1];
  *(undefined8 *)param_1 = *puVar2;
  *(undefined8 *)(param_1 + 8) = uVar1;
  *(undefined8 *)(param_1 + 0x10) = puVar2[2];
  OdGeEntity3d::~OdGeEntity3d((OdGeEntity3d *)local_res8);
  return 0;
}



/* ==== 1803d8f30 getSweepAngle ==== */

/* public: virtual double __cdecl OdDgArc3d::getSweepAngle(void)const __ptr64 */

double __thiscall OdDgArc3d::getSweepAngle(OdDgArc3d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x3d8f30  13632  ?getSweepAngle@OdDgArc3d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d8f5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x610))(plVar1);
  return dVar2;
}



