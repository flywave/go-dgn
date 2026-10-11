/* ==== 1800b8d40 rxInit ==== */

/* public: static void __cdecl OdDgTableElement::rxInit(void) */

void __cdecl OdDgTableElement::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb8d40  19282  ?rxInit@OdDgTableElement@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgTableElement");
  g_pDesc = newOdRxClass(local_res8,OdDgGraphicsElement::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x6a,3,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b8e20 rxInit ==== */

/* public: static void __cdecl OdDgTagElement::rxInit(void) */

void __cdecl OdDgTagElement::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb8e20  19306  ?rxInit@OdDgTagElement@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgTagElement");
  g_pDesc = newOdRxClass(local_res8,OdDgGraphicsElement::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x25,0,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b8f00 rxInit ==== */

/* public: static void __cdecl OdDgTerrain::rxInit(void) */

void __cdecl OdDgTerrain::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb8f00  19311  ?rxInit@OdDgTerrain@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgTerrain");
  g_pDesc = newOdRxClass(local_res8,OdDgGraphicsElement::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x6a,2,g_pDesc);
    return;
  }
  return;
}



