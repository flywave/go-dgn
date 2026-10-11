/* ==== 1808b3f60 getLinkageDataSize ==== */

/* public: virtual unsigned long __cdecl OdDgAttributeLinkageHeader::getLinkageDataSize(void)const
   __ptr64 */

ulong __thiscall OdDgAttributeLinkageHeader::getLinkageDataSize(OdDgAttributeLinkageHeader *this)

{
  char cVar1;
  
                    /* 0x8b3f60  11977  ?getLinkageDataSize@OdDgAttributeLinkageHeader@@UEBAKXZ */
  cVar1 = (**(code **)(*(longlong *)this + 0x30))();
  if (cVar1 == '\0') {
    return 8;
  }
  cVar1 = (**(code **)(*(longlong *)this + 0x38))(this);
  if (cVar1 != '\0') {
    return (2 << ((byte)(*(ushort *)(this + 8) >> 8) & 0xf)) * (*(ushort *)(this + 8) & 0xff);
  }
  return (uint)(byte)*(undefined2 *)(this + 8) * 2 + 2;
}



/* ==== 1808b3fd0 getPrimaryId ==== */

/* public: virtual enum OdDgAttributeLinkage::PrimaryIds __cdecl
   OdDgAttributeLinkageHeader::getPrimaryId(void)const __ptr64 */

PrimaryIds __thiscall OdDgAttributeLinkageHeader::getPrimaryId(OdDgAttributeLinkageHeader *this)

{
  char cVar1;
  PrimaryIds PVar2;
  
                    /* 0x8b3fd0  12751
                       ?getPrimaryId@OdDgAttributeLinkageHeader@@UEBA?AW4PrimaryIds@OdDgAttributeLinkage@@XZ
                        */
  cVar1 = (**(code **)(*(longlong *)this + 0x30))();
  if ((cVar1 == '\0') || (PVar2 = (PrimaryIds)*(ushort *)(this + 10), *(ushort *)(this + 10) == 0))
  {
    PVar2 = 0;
  }
  return PVar2;
}



/* ==== 1808b4000 getRemoteFlag ==== */

/* public: virtual bool __cdecl OdDgAttributeLinkageHeader::getRemoteFlag(void)const __ptr64 */

bool __thiscall OdDgAttributeLinkageHeader::getRemoteFlag(OdDgAttributeLinkageHeader *this)

{
                    /* 0x8b4000  12969  ?getRemoteFlag@OdDgAttributeLinkageHeader@@UEBA_NXZ */
  return (bool)((byte)((ushort)*(undefined2 *)(this + 8) >> 0xe) & 1);
}



/* ==== 1808b4030 getUserDataFlag ==== */

/* public: virtual bool __cdecl OdDgAttributeLinkageHeader::getUserDataFlag(void)const __ptr64 */

bool __thiscall OdDgAttributeLinkageHeader::getUserDataFlag(OdDgAttributeLinkageHeader *this)

{
                    /* 0x8b4030  14225  ?getUserDataFlag@OdDgAttributeLinkageHeader@@UEBA_NXZ */
  return (bool)((byte)((ushort)*(undefined2 *)(this + 8) >> 0xc) & 1);
}



