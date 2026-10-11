/* ==== 180008680 GetProperties ==== */

/* public: virtual struct Dgn8::SElementProperties const __cdecl
   CDGDispHeader::GetProperties(void)const __ptr64 */

void __thiscall CDGDispHeader::GetProperties(CDGDispHeader *this)

{
  undefined2 *in_RDX;
  
                    /* 0x8680  4042
                       ?GetProperties@CDGDispHeader@@UEBA?BUSElementProperties@Dgn8@@XZ */
  if (*(longlong *)(this + 0x30) == 0) {
    *in_RDX = 0;
    return;
  }
  *in_RDX = *(undefined2 *)(*(longlong *)(this + 0x30) + 8);
  return;
}



/* ==== 18022f3b0 getLevelEntryId ==== */

/* public: virtual unsigned long __cdecl OdDgGraphicsElement::getLevelEntryId(void)const __ptr64 */

ulong __thiscall OdDgGraphicsElement::getLevelEntryId(OdDgGraphicsElement *this)

{
  ulong uVar1;
  
                    /* 0x22f3b0  11803  ?getLevelEntryId@OdDgGraphicsElement@@UEBAKXZ
                       0x22f3b0  11806  ?getLevelEntryId@OdDgReferenceAttachmentHeader@@UEBAKXZ */
                    /* WARNING: Could not recover jumptable at 0x00018022f3b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(longlong **)(this + 8) + 0xb0))();
  return uVar1;
}



/* ==== 18081e170 GetURL ==== */

/* public: virtual class OdString __cdecl CDGDispHeader::GetURL(void) __ptr64 */

void __thiscall CDGDispHeader::GetURL(CDGDispHeader *this)

{
  OdString *in_RDX;
  
                    /* 0x81e170  4059  ?GetURL@CDGDispHeader@@UEAA?AVOdString@@XZ
                       0x81e170  4060  ?GetURLTitle@CDGDispHeader@@UEAA?AVOdString@@XZ */
  OdString::OdString(in_RDX,"",0x2e);
  return;
}



