/* ==== 1800112f0 get3dFormatFlag ==== */

/* public: bool __cdecl CDGDispHeader::get3dFormatFlag(void)const __ptr64 */

bool __thiscall CDGDispHeader::get3dFormatFlag(CDGDispHeader *this)

{
                    /* 0x112f0  8917  ?get3dFormatFlag@CDGDispHeader@@QEBA_NXZ */
  if (*(longlong *)(this + 0x30) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0x30) + 8) >> 0xb) & 1);
  }
  return true;
}



/* ==== 18011b590 get3dFormatFlag ==== */

/* public: virtual bool __cdecl CDGElementGeneral::get3dFormatFlag(void)const __ptr64 */

bool __thiscall CDGElementGeneral::get3dFormatFlag(CDGElementGeneral *this)

{
                    /* 0x11b590  8918  ?get3dFormatFlag@CDGElementGeneral@@UEBA_NXZ */
  if (*(longlong *)(this + 0xe0) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0xe0) + 8) >> 0xb) & 1);
  }
  return true;
}



/* ==== 1802c2550 get3dFormatFlag ==== */

/* public: virtual bool __cdecl OdDgGraphicsElement::get3dFormatFlag(void)const __ptr64 */

bool __thiscall OdDgGraphicsElement::get3dFormatFlag(OdDgGraphicsElement *this)

{
  bool bVar1;
  longlong *plVar2;
  
                    /* 0x2c2550  8919  ?get3dFormatFlag@OdDgGraphicsElement@@UEBA_NXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802c257f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = (bool)(**(code **)(*plVar2 + 0x580))(plVar2);
  return bVar1;
}



/* ==== 18081e4c0 isImplicitDisplayHeader ==== */

/* public: static bool __cdecl CDGDispHeader::isImplicitDisplayHeader(enum
   OdDgElement::ElementTypes,unsigned long) */

bool __cdecl CDGDispHeader::isImplicitDisplayHeader(ElementTypes param_1,ulong param_2)

{
  bool bVar1;
  
                    /* 0x81e4c0  15461
                       ?isImplicitDisplayHeader@CDGDispHeader@@SA_NW4ElementTypes@OdDgElement@@K@Z
                        */
  bVar1 = false;
  if (param_1 == 0x23) {
    bVar1 = false;
    if (0x47 < param_2 - 0xbc) {
      bVar1 = true;
    }
  }
  return bVar1;
}



