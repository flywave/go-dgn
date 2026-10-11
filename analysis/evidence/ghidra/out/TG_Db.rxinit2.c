/* ==== 1800b7020 rxInit ==== */

/* public: static void __cdecl OdDgMeshTriangleGrid::rxInit(void) */

void __cdecl OdDgMeshTriangleGrid::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb7020  18905  ?rxInit@OdDgMeshTriangleGrid@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgMeshTriangleGrid");
  g_pDesc = newOdRxClass(local_res8,OdDgMesh::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x69,5,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b7100 rxInit ==== */

/* public: static void __cdecl OdDgMeshTriangleList::rxInit(void) */

void __cdecl OdDgMeshTriangleList::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb7100  18906  ?rxInit@OdDgMeshTriangleList@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgMeshTriangleList");
  g_pDesc = newOdRxClass(local_res8,OdDgMesh::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x69,3,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b71e0 rxInit ==== */

/* public: static void __cdecl OdDgMultiVertex2d::rxInit(void) */

void __cdecl OdDgMultiVertex2d::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb71e0  18932  ?rxInit@OdDgMultiVertex2d@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgMultiVertex2d");
  g_pDesc = newOdRxClass(local_res8,OdDgCurveElement2d::g_pDesc,OdDgElementId::OdDgElementId,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0xffff,0xff,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b72c0 rxInit ==== */

/* public: static void __cdecl OdDgMultiVertex3d::rxInit(void) */

void __cdecl OdDgMultiVertex3d::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb72c0  18933  ?rxInit@OdDgMultiVertex3d@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgMultiVertex3d");
  g_pDesc = newOdRxClass(local_res8,OdDgCurveElement3d::g_pDesc,OdDgElementId::OdDgElementId,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0xffff,0xff,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b73a0 rxInit ==== */

/* public: static void __cdecl OdDgMultiline::rxInit(void) */

void __cdecl OdDgMultiline::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb73a0  18934  ?rxInit@OdDgMultiline@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgMultiline");
  g_pDesc = newOdRxClass(local_res8,OdDgGraphicsElement::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x24,0,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b7480 rxInit ==== */

/* public: static void __cdecl OdDgOle2Frame2d::rxInit(void) */

void __cdecl OdDgOle2Frame2d::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb7480  18967  ?rxInit@OdDgOle2Frame2d@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgOle2Frame2d");
  g_pDesc = newOdRxClass(local_res8,OdDgCellHeader2d::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,2,9,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b7560 rxInit ==== */

/* public: static void __cdecl OdDgOle2Frame3d::rxInit(void) */

void __cdecl OdDgOle2Frame3d::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb7560  18968  ?rxInit@OdDgOle2Frame3d@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgOle2Frame3d");
  g_pDesc = newOdRxClass(local_res8,OdDgCellHeader3d::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,2,10,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b7640 rxInit ==== */

/* public: static void __cdecl OdDgPointString2d::rxInit(void) */

void __cdecl OdDgPointString2d::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb7640  18997  ?rxInit@OdDgPointString2d@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgPointString2d");
  g_pDesc = newOdRxClass(local_res8,OdDgMultiVertex2d::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x16,0,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b7720 rxInit ==== */

/* public: static void __cdecl OdDgPointString3d::rxInit(void) */

void __cdecl OdDgPointString3d::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb7720  18998  ?rxInit@OdDgPointString3d@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgPointString3d");
  g_pDesc = newOdRxClass(local_res8,OdDgMultiVertex3d::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,3,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x16,1,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b7800 rxInit ==== */

/* public: static void __cdecl OdDgRasterAttachmentComponent::rxInit(void) */

void __cdecl OdDgRasterAttachmentComponent::rxInit(void)

{
  OdRxClass *pOVar1;
  OdDgnClassMap *pOVar2;
  OdString local_res8 [32];
  
                    /* 0xb7800  19085  ?rxInit@OdDgRasterAttachmentComponent@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgRasterAttachmentComponent");
  pOVar1 = OdDgElement::desc();
  g_pDesc = newOdRxClass(local_res8,pOVar1,OdDgElementId::OdDgElementId,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar2 = odDgnClassMap();
    FUN_180137ee0(pOVar2,0xffff,0xff,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b78e0 rxInit ==== */

/* public: static void __cdecl OdDgRasterAttachmentComponentBinary::rxInit(void) */

void __cdecl OdDgRasterAttachmentComponentBinary::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb78e0  19086  ?rxInit@OdDgRasterAttachmentComponentBinary@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgRasterAttachmentComponentBinary");
  g_pDesc = newOdRxClass(local_res8,OdDgRasterAttachmentComponent::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x5b,1,g_pDesc);
    return;
  }
  return;
}



/* ==== 1800b7c20 rxInit ==== */

/* public: static void __cdecl OdDgRasterAttachmentComponentGeo::rxInit(void) */

void __cdecl OdDgRasterAttachmentComponentGeo::rxInit(void)

{
  OdDgnClassMap *pOVar1;
  OdString local_res8 [32];
  
                    /* 0xb7c20  19090  ?rxInit@OdDgRasterAttachmentComponentGeo@@SAXXZ */
  if (g_pDesc != (OdRxClass *)0x0) {
    OdError::OdError((OdError *)local_res8,0x13a);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de52b8);
  }
  OdString::OdString(local_res8,(ushort *)L"OdDgRasterAttachmentComponentGeo");
  g_pDesc = newOdRxClass(local_res8,OdDgRasterAttachmentComponent::g_pDesc,pseudoConstructor,0,0,0,
                         (OdString *)kEmpty_exref,(OdString *)kEmpty_exref,
                         (_func_void_OdRxClass_ptr_OdString_ptr_int *)0x0,0,
                         (_func_void_OdRxMemberCollectionBuilder_ptr_void_ptr *)0x0,(void *)0x0);
  OdString::~OdString(local_res8);
  if (g_pDesc != (OdRxClass *)0x0) {
    pOVar1 = odDgnClassMap();
    FUN_180137ee0(pOVar1,0x5b,7,g_pDesc);
    return;
  }
  return;
}



