/* ==== 1800f95c0 rxInit ==== */

/* public: static void __cdecl OdDgNoteLinkage::rxInit(void) */

void __cdecl OdDgNoteLinkage::rxInit(void)

{
  OdString local_res8 [32];
  
                    /* 0xf95c0  18952  ?rxInit@OdDgNoteLinkage@@SAXXZ */
  if (g_pDesc == (OdRxClass *)0x0) {
    OdString::OdString(local_res8,(ushort *)L"OdDgNoteLinkage");
    g_pDesc = newOdRxClass(local_res8,OdDgAttributeLinkage::g_pDesc,pseudoConstructor,0,0,0,
                           (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                           (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                           (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
    OdString::~OdString(local_res8);
    return;
  }
  OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
}



/* ==== 1800fe190 rxInit ==== */

/* public: static void __cdecl OdDgSeedPointsLinkage::rxInit(void) */

void __cdecl OdDgSeedPointsLinkage::rxInit(void)

{
  OdString local_res8 [32];
  
                    /* 0xfe190  19200  ?rxInit@OdDgSeedPointsLinkage@@SAXXZ */
  if (g_pDesc == (OdRxClass *)0x0) {
    OdString::OdString(local_res8,(ushort *)L"OdDgSeedPointsLinkage");
    g_pDesc = newOdRxClass(local_res8,OdDgAttributeLinkage::g_pDesc,pseudoConstructor,0,0,0,
                           (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                           (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                           (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
    OdString::~OdString(local_res8);
    return;
  }
  OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
}



