/* ==== 1800a3760 FUN_1800a3760 ==== */

void FUN_1800a3760(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x240));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x244));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x248));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x24a));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x250));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 600));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x260));
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  lVar2 = *param_2;
  if (iVar1 == 0xb) {
    uVar3 = *(undefined8 *)(param_1 + 0x280);
  }
  else {
    iVar1 = (**(code **)(lVar2 + 0x58))(param_2);
    lVar2 = *param_2;
    if (iVar1 == 10) {
      (**(code **)(lVar2 + 0x1c0))(param_2,param_1 + 0x288);
      goto LAB_1800a383f;
    }
    uVar3 = *(undefined8 *)(param_1 + 0x268);
  }
  (**(code **)(lVar2 + 0x170))(param_2,uVar3);
LAB_1800a383f:
                    /* WARNING: Could not recover jumptable at 0x0001800a3856. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x1a0))(param_2,param_1 + 0x270);
  return;
}



/* ==== 1800a3860 FUN_1800a3860 ==== */

void FUN_1800a3860(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x240));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x244));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x248));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x24a));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x250));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 600));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x260));
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 0xb) {
    (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x2a0));
  }
  else {
    iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
    lVar2 = param_1 + 0x2a8;
    if (iVar1 != 10) {
      lVar2 = param_1 + 0x268;
    }
    (**(code **)(*param_2 + 0x1c0))(param_2,lVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x0001800a3953. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 0x288);
  return;
}



/* ==== 1802750a0 FUN_1802750a0 ==== */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1802750a0(ECell<OdDgFiler3d> *param_1,longlong *param_2)

{
  double dVar1;
  undefined1 auVar2 [16];
  double dVar3;
  undefined4 uVar4;
  bool bVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  OdRxClass *pOVar9;
  OdGiDrawable *pOVar10;
  OdGeMatrix3d *pOVar11;
  undefined8 *puVar12;
  OdDbHandle *pOVar13;
  OdRxClass *pOVar14;
  ECell<OdDgFiler3d> *pEVar15;
  longlong lVar16;
  uint uVar17;
  ulonglong uVar18;
  undefined4 uVar19;
  undefined1 auStack_1138 [32];
  longlong *local_1118;
  undefined1 local_1110 [16];
  double local_1100;
  double local_10f8;
  undefined8 uStack_10f0;
  double local_10e8;
  undefined8 uStack_10e0;
  undefined8 local_10d8;
  double dStack_10d0;
  longlong local_10c8;
  undefined8 local_10c0;
  undefined8 uStack_10b8;
  undefined8 local_10b0;
  double local_10a8;
  double dStack_10a0;
  double local_1098;
  undefined8 uStack_1090;
  undefined8 local_1088;
  double dStack_1080;
  undefined **local_1078 [12];
  undefined8 local_1018;
  undefined8 uStack_1010;
  undefined8 local_1008;
  undefined8 uStack_1000;
  undefined8 local_ff8;
  undefined8 uStack_ff0;
  undefined8 local_fe8;
  undefined8 uStack_fe0;
  undefined8 local_fd8;
  undefined8 uStack_fd0;
  undefined8 local_fc8;
  undefined8 uStack_fc0;
  undefined8 local_fb8;
  undefined8 uStack_fb0;
  undefined8 local_fa8;
  undefined8 uStack_fa0;
  OdGeMatrix3d local_f98 [8];
  undefined8 auStack_f90 [15];
  OdGeMatrix3d local_f18 [128];
  OdGeVector3d local_e98 [128];
  OdGeMatrix3d local_e18 [128];
  undefined **local_d98;
  undefined **local_d90;
  undefined **local_d88;
  undefined **local_cf0;
  undefined **local_ce8;
  undefined **local_ce0;
  undefined **local_cd8;
  ulonglong local_48;
  
  local_48 = DAT_180fcd438 ^ (ulonglong)auStack_1138;
  ECell<OdDgFiler3d>::_updateClassBitMap(param_1);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x240));
  (**(code **)(*param_2 + 0x158))(param_2);
  lVar7 = FUN_180010890(param_1);
  if (lVar7 != 0) {
    lVar7 = FUN_180010890(param_1);
    if ((*(longlong *)(lVar7 + 0x10) != 0) &&
       (*(char *)(*(longlong *)(lVar7 + 0x10) + 0xd10) != '\0')) {
      (**(code **)(*param_2 + 0x1a0))(param_2,param_1 + 0x248);
      pEVar15 = param_1 + 600;
      goto LAB_18027568a;
    }
  }
  OdGeMatrix3d::OdGeMatrix3d(local_f18);
  OdGeMatrix3d::OdGeMatrix3d(local_f98);
  local_10f8 = 1e+20;
  uStack_10f0 = 1e+20;
  local_10e8 = 1e+20;
  uStack_10e0._0_4_ = 0x78b58c40;
  uStack_10e0._4_4_ = 0xc415af1d;
  local_10d8._0_4_ = 0x78b58c40;
  local_10d8._4_4_ = 0xc415af1d;
  dStack_10d0 = -1e+20;
  iVar6 = 0;
  lVar7 = 0;
  do {
    lVar16 = lVar7 + 1;
    if (iVar6 < 2) {
      lVar16 = lVar7;
    }
    *(undefined8 *)(local_f98 + lVar16 * 0x20) = *(undefined8 *)(param_1 + lVar7 * 0x18 + 0x268);
    lVar16 = lVar7 + 1;
    if (iVar6 < 2) {
      lVar16 = lVar7;
    }
    auStack_f90[lVar16 * 4] = *(undefined8 *)(param_1 + lVar7 * 0x18 + 0x270);
    lVar16 = lVar7 + 1;
    if (iVar6 < 2) {
      lVar16 = lVar7;
    }
    auStack_f90[lVar16 * 4 + 2] = *(undefined8 *)(param_1 + lVar7 * 0x18 + 0x278);
    iVar6 = iVar6 + 1;
    lVar7 = lVar7 + 1;
  } while (iVar6 < 3);
  local_10c8 = *(longlong *)(param_1 + 0x58);
  iVar6 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar6 == 0) {
    if ((local_10c8 != 0) &&
       (dVar1 = OdGeMatrix2d::det((OdGeMatrix2d *)(param_1 + 0x268)),
       1e-06 <= ABS(dVar1) && ABS(dVar1) != 1e-06)) {
      plVar8 = (longlong *)
               OdDgElementId::openObject((OdDgElementId *)&local_10c8,(OpenMode)&local_1118,false);
      pOVar10 = (OdGiDrawable *)0x0;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = local_1110._8_8_;
      local_1110 = auVar2 << 0x40;
      plVar8 = (longlong *)*plVar8;
      if (plVar8 != (longlong *)0x0) {
        lVar7 = *plVar8;
        pOVar9 = OdDgGraphicsElement::desc();
        pOVar10 = (OdGiDrawable *)(**(code **)(lVar7 + 8))(plVar8,pOVar9);
        if (pOVar10 == (OdGiDrawable *)0x0) {
          pOVar9 = OdDgGraphicsElement::desc();
          pOVar14 = (OdRxClass *)(**(code **)(*plVar8 + 0x18))(plVar8);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)local_1110,pOVar14,pOVar9);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1110,(ThrowInfo *)&DAT_180de5310);
        }
        local_1110._0_8_ = pOVar10;
      }
      if (local_1118 != (longlong *)0x0) {
        (**(code **)(*local_1118 + 0x28))();
        local_1118 = (longlong *)0x0;
      }
      local_10c0 = *(undefined8 *)(param_1 + 0x2b0);
      uStack_10b8 = *(undefined8 *)(param_1 + 0x2b8);
      local_10b0 = 0;
      pOVar11 = (OdGeMatrix3d *)OdGeMatrix3d::translation(local_e98);
      puVar12 = (undefined8 *)OdGeMatrix3d::operator*(pOVar11,local_e18);
      local_10a8 = 1e+20;
      dStack_10a0 = 1e+20;
      local_1098 = 1e+20;
      uStack_1090 = 0xc415af1d78b58c40;
      local_1088 = 0xc415af1d78b58c40;
      dStack_1080 = -1e+20;
      OdGiExtCalc::OdGiExtCalc((OdGiExtCalc *)&local_d98);
      local_d98 = OdStaticRxObject<OdGiExtCalc>::vftable;
      local_d90 = OdStaticRxObject<OdGiExtCalc>::vftable;
      local_d88 = OdStaticRxObject<OdGiExtCalc>::vftable;
      local_cf0 = OdStaticRxObject<OdGiExtCalc>::vftable;
      local_ce8 = OdStaticRxObject<OdGiExtCalc>::vftable;
      local_ce0 = OdStaticRxObject<OdGiExtCalc>::vftable;
      local_cd8 = OdStaticRxObject<OdGiExtCalc>::vftable;
      OdGiContextForDgDatabase::OdGiContextForDgDatabase((OdGiContextForDgDatabase *)local_1078);
      local_1078[0] = OdStaticRxObject<OdGiContextForDgDatabase>::vftable;
      local_1118 = (longlong *)FUN_180010890(param_1);
      if (local_1118 != (longlong *)0x0) {
        (**(code **)(*local_1118 + 0x20))(local_1118);
      }
      OdGiContextForDgDatabase::setDatabase((OdGiContextForDgDatabase *)local_1078,&local_1118,0);
      OdGiExtCalc::setContext((OdGiExtCalc *)&local_d98,(OdGiContext *)local_1078);
      local_1018 = *puVar12;
      uStack_1010 = puVar12[1];
      local_1008 = puVar12[2];
      uStack_1000 = puVar12[3];
      local_ff8 = puVar12[4];
      uStack_ff0 = puVar12[5];
      local_fe8 = puVar12[6];
      uStack_fe0 = puVar12[7];
      local_fd8 = puVar12[8];
      uStack_fd0 = puVar12[9];
      local_fc8 = puVar12[10];
      uStack_fc0 = puVar12[0xb];
      local_fb8 = puVar12[0xc];
      uStack_fb0 = puVar12[0xd];
      local_fa8 = puVar12[0xe];
      uStack_fa0 = puVar12[0xf];
      pOVar11 = OdGeMatrix3d::invert((OdGeMatrix3d *)&local_1018);
      local_1018 = *(undefined8 *)pOVar11;
      uStack_1010 = *(undefined8 *)(pOVar11 + 8);
      local_1008 = *(undefined8 *)(pOVar11 + 0x10);
      uStack_1000 = *(undefined8 *)(pOVar11 + 0x18);
      local_ff8 = *(undefined8 *)(pOVar11 + 0x20);
      uStack_ff0 = *(undefined8 *)(pOVar11 + 0x28);
      local_fe8 = *(undefined8 *)(pOVar11 + 0x30);
      uStack_fe0 = *(undefined8 *)(pOVar11 + 0x38);
      local_fd8 = *(undefined8 *)(pOVar11 + 0x40);
      uStack_fd0 = *(undefined8 *)(pOVar11 + 0x48);
      local_fc8 = *(undefined8 *)(pOVar11 + 0x50);
      uStack_fc0 = *(undefined8 *)(pOVar11 + 0x58);
      local_fb8 = *(undefined8 *)(pOVar11 + 0x60);
      uStack_fb0 = *(undefined8 *)(pOVar11 + 0x68);
      local_fa8 = *(undefined8 *)(pOVar11 + 0x70);
      uStack_fa0 = *(undefined8 *)(pOVar11 + 0x78);
      OdGiBaseVectorizer::pushModelTransform
                ((OdGiBaseVectorizer *)&local_d90,(OdGeMatrix3d *)&local_1018);
      OdGiExtCalc::draw((OdGiExtCalc *)&local_d90,pOVar10);
      OdGiBaseVectorizer::popModelTransform((OdGiBaseVectorizer *)&local_d90);
      OdGiExtCalc::getExtents((OdGiExtCalc *)&local_d98,(OdGeExtents3d *)&local_10a8);
      OdGiContextForDgDatabase::~OdGiContextForDgDatabase((OdGiContextForDgDatabase *)local_1078);
      OdGiExtCalc::~OdGiExtCalc((OdGiExtCalc *)&local_d98);
      local_10f8 = local_10a8;
      uStack_10f0 = dStack_10a0;
      local_10e8 = local_1098;
      uStack_10e0._0_4_ = (undefined4)uStack_1090;
      uStack_10e0._4_4_ = uStack_1090._4_4_;
      local_10d8._0_4_ = (undefined4)local_1088;
      local_10d8._4_4_ = local_1088._4_4_;
      dStack_10d0 = dStack_1080;
      if (pOVar10 != (OdGiDrawable *)0x0) {
        (**(code **)(*(longlong *)pOVar10 + 0x28))(pOVar10);
      }
      goto LAB_180275649;
    }
    ECell<OdDgFiler3d>::GetGeomExtents(param_1,(OdGeExtents3d *)&local_10f8);
    dVar3 = (double)CONCAT44(local_10d8._4_4_,(undefined4)local_10d8);
    dVar1 = (double)CONCAT44(uStack_10e0._4_4_,(undefined4)uStack_10e0);
    local_1110._8_4_ = (undefined4)local_10d8;
    local_1110._0_8_ = dVar1;
    local_1110._12_4_ = local_10d8._4_4_;
    local_1100 = dStack_10d0;
    if (((dVar1 < local_10f8) || (local_1110._8_8_ < uStack_10f0)) || (dStack_10d0 < local_10e8)) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    uVar19 = (undefined4)local_10d8;
    if (bVar5) {
      local_10f8 = local_10f8 - *(double *)(param_1 + 0x2b0);
      uStack_10f0 = uStack_10f0 - *(double *)(param_1 + 0x2b8);
      local_10e8 = local_10e8 - 0.0;
      uStack_10e0 = dVar1 - *(double *)(param_1 + 0x2b0);
      local_10d8 = local_1110._8_8_ - *(double *)(param_1 + 0x2b8);
      dStack_10d0 = dStack_10d0 + 0.0;
      bVar5 = OdGeMatrix3d::inverse(local_f98,local_f18,0.001);
      if (bVar5) {
        OdGeExtents3d::transformBy((OdGeExtents3d *)&local_10f8,local_f18);
      }
      goto LAB_180275649;
    }
  }
  else {
    local_1110 = *(undefined1 (*) [16])(param_1 + 0x248);
    local_1100 = 0.0;
    FUN_1800178a0(&local_10f8,local_1110);
    local_1110 = *(undefined1 (*) [16])(param_1 + 600);
    local_1100 = 0.0;
    FUN_1800178a0(&local_10f8,local_1110);
LAB_180275649:
    uVar19 = (undefined4)local_10d8;
    dVar1 = uStack_10e0;
    dVar3 = local_10d8;
  }
  local_10d8._4_4_ = (undefined4)((ulonglong)dVar3 >> 0x20);
  uVar4 = local_10d8._4_4_;
  local_1100 = dStack_10d0;
  local_1110._8_4_ = (undefined4)uStack_10f0;
  local_1110._0_8_ = local_10f8;
  local_1110._12_4_ = uStack_10f0._4_4_;
  uStack_10e0 = dVar1;
  local_10d8 = dVar3;
  (**(code **)(*param_2 + 0x1a0))(param_2,local_1110);
  local_1110._12_4_ = uVar4;
  local_1110._8_4_ = uVar19;
  local_1110._0_8_ = dVar1;
  pEVar15 = (ECell<OdDgFiler3d> *)local_1110;
LAB_18027568a:
  (**(code **)(*param_2 + 0x1a0))(param_2,pEVar15);
  iVar6 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar6 == 10) {
    local_1008 = *(undefined8 *)(kIdentity_exref + 0x10);
    local_fe8 = *(undefined8 *)(kIdentity_exref + 0x30);
    local_fd8 = *(undefined8 *)(kIdentity_exref + 0x40);
    uStack_fd0 = *(undefined8 *)(kIdentity_exref + 0x48);
    local_fc8 = *(undefined8 *)(kIdentity_exref + 0x50);
    uStack_fc0 = *(undefined8 *)(kIdentity_exref + 0x58);
    local_fa8 = *(undefined8 *)(kIdentity_exref + 0x70);
    local_1018 = *(undefined8 *)(param_1 + 0x268);
    uStack_1010 = *(undefined8 *)(param_1 + 0x270);
    uStack_1000 = *(undefined8 *)(param_1 + 0x278);
    local_ff8 = *(undefined8 *)(param_1 + 0x280);
    uStack_ff0 = *(undefined8 *)(param_1 + 0x288);
    uStack_fe0 = *(undefined8 *)(param_1 + 0x290);
    local_fb8 = *(undefined8 *)(param_1 + 0x298);
    uStack_fb0 = *(undefined8 *)(param_1 + 0x2a0);
    uStack_fa0 = *(undefined8 *)(param_1 + 0x2a8);
    FUN_180280850(param_2,&local_1018);
  }
  else {
    (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x268));
    (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x270));
    (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x280));
    (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x288));
  }
  (**(code **)(*param_2 + 0x1a0))(param_2,param_1 + 0x2b0);
  iVar6 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar6 == 2) {
    (**(code **)(*param_2 + 0x160))(param_2,param_1[0x308] != (ECell<OdDgFiler3d>)0x0);
    if (param_1[0x308] != (ECell<OdDgFiler3d>)0x0) {
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(*(longlong *)(param_1 + 0x220) + -4));
      uVar18 = 0;
      if (*(int *)(*(longlong *)(param_1 + 0x220) + -4) != 0) {
        do {
          uVar17 = *(uint *)(*(longlong *)(param_1 + 0x220) + -4);
          if (uVar17 <= (uint)uVar18) {
            OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)&local_1118);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(&local_1118,(ThrowInfo *)&DAT_180de5370);
          }
          lVar7 = 0;
          if (uVar17 != 0) {
            lVar7 = *(longlong *)(param_1 + 0x220);
          }
          local_1110._0_8_ = *(undefined8 *)(lVar7 + uVar18 * 8);
          lVar7 = *param_2;
          pOVar13 = OdDgElementId::getHandle((OdDgElementId *)local_1110);
          (**(code **)(lVar7 + 0x168))(param_2,*(undefined8 *)pOVar13);
          uVar17 = (uint)uVar18 + 1;
          uVar18 = (ulonglong)uVar17;
        } while (uVar17 < *(uint *)(*(longlong *)(param_1 + 0x220) + -4));
      }
    }
  }
  return;
}



/* ==== 1802758d0 dgnOutFields ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual void __cdecl ECell3D::dgnOutFields(class OdDgFiler * __ptr64)const __ptr64 */

void __thiscall ECell3D::dgnOutFields(ECell3D *this,OdDgFiler *param_1)

{
  uint uVar1;
  double dVar2;
  OdDgElement *pOVar3;
  bool bVar4;
  char cVar5;
  ulong uVar6;
  undefined4 uVar7;
  int iVar8;
  longlong lVar9;
  OdRxClass *pOVar10;
  longlong *plVar11;
  longlong *plVar12;
  OdDgElementId *this_00;
  OdDgDgnStoreComponent *pOVar13;
  void *pvVar14;
  longlong *plVar15;
  OdDgFiler *pOVar16;
  OdGeMatrix3d *this_01;
  OdGiDrawable *pOVar17;
  double *pdVar18;
  OdDbHandle *pOVar19;
  OdRxClass *pOVar20;
  code *pcVar21;
  ulonglong uVar22;
  code *pcVar23;
  uint uVar24;
  ulong uVar26;
  undefined1 auStack_328 [32];
  undefined4 local_308;
  undefined1 local_2f8 [8];
  code *local_2f0;
  OdDgFiler *local_2e8;
  longlong *local_2e0;
  longlong *local_2d8;
  longlong *local_2d0;
  ulong local_2c8;
  undefined8 local_2c0;
  longlong *local_2b8;
  longlong *local_2b0;
  double local_2a8;
  double dStack_2a0;
  double local_298;
  double dStack_290;
  double local_288;
  double dStack_280;
  OdDgElement *local_278;
  OdDgDgnStoreComponent *local_270;
  longlong local_268;
  longlong *local_260;
  longlong *local_258;
  undefined1 local_250 [8];
  double local_248;
  double dStack_240;
  double local_238;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  OdGeMatrix3d local_1c8 [128];
  OdGeVector3d local_148 [128];
  OdGeMatrix3d local_c8 [128];
  ulonglong local_48;
  ulonglong uVar25;
  
                    /* 0x2758d0  7829  ?dgnOutFields@ECell3D@@UEBAXPEAVOdDgFiler@@@Z */
  local_48 = DAT_180fcd438 ^ (ulonglong)auStack_328;
  local_2e8 = param_1;
  ECell<OdDgFiler3d>::_updateClassBitMap((ECell<OdDgFiler3d> *)this);
  (**(code **)(*(longlong *)param_1 + 0x158))(param_1,*(undefined2 *)(this + 0x240));
  (**(code **)(*(longlong *)param_1 + 0x158))(param_1,*(undefined2 *)(this + 0x242));
  lVar9 = FUN_180010890(this);
  plVar15 = (longlong *)0x0;
  if (lVar9 != 0) {
    lVar9 = FUN_180010890(this);
    if ((*(longlong *)(lVar9 + 0x10) != 0) &&
       (*(char *)(*(longlong *)(lVar9 + 0x10) + 0xd10) != '\0')) {
      (**(code **)(*(longlong *)param_1 + 0x1a8))(param_1,this + 0x248);
      (**(code **)(*(longlong *)param_1 + 0x1a8))(param_1,this + 0x260);
      goto LAB_18027602a;
    }
  }
  OdGeMatrix3d::OdGeMatrix3d(local_1c8);
  local_2a8 = 1e+20;
  dStack_2a0 = 1e+20;
  local_298 = 1e+20;
  dStack_290 = -1e+20;
  local_288 = -1e+20;
  dStack_280 = -1e+20;
  local_2c0 = *(undefined8 *)(this + 0x58);
  OdDgElementId::openObject((OdDgElementId *)&local_2c0,(OpenMode)&local_278,false);
  local_2b0 = (longlong *)0x0;
  bVar4 = isCellHeaderElement(local_278);
  pOVar3 = local_278;
  plVar11 = plVar15;
  if ((bVar4) && (local_278 != (OdDgElement *)0x0)) {
    lVar9 = *(longlong *)local_278;
    pOVar10 = OdDgCellHeader3d::desc();
    plVar11 = (longlong *)(**(code **)(lVar9 + 8))(pOVar3,pOVar10);
    if (plVar11 == (longlong *)0x0) {
      pOVar10 = OdDgCellHeader3d::desc();
      pOVar20 = (OdRxClass *)(**(code **)(*(longlong *)pOVar3 + 0x18))(pOVar3);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_2e8,pOVar20,pOVar10);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_2e8,(ThrowInfo *)&DAT_180de5310);
    }
    local_2b0 = plVar11;
    local_260 = plVar11;
    (**(code **)(*plVar11 + 0x20))(plVar11);
    lVar9 = *plVar11;
    pOVar10 = OdDgBRepEntityPE::desc();
    plVar12 = (longlong *)(**(code **)(lVar9 + 8))(plVar11,pOVar10);
    local_2d8 = plVar12;
    if (plVar12 == (longlong *)0x0) {
      pOVar10 = OdDgBRepEntityPE::desc();
      pOVar20 = (OdRxClass *)(**(code **)(*plVar11 + 0x18))(plVar11);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_2e8,pOVar20,pOVar10);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_2e8,(ThrowInfo *)&DAT_180de5310);
    }
    local_258 = plVar12;
    (**(code **)(*plVar11 + 0x28))(plVar11);
    iVar8 = (**(code **)(*plVar12 + 0x58))(plVar12,plVar11);
    if (iVar8 != 0) {
      local_2c8 = 0;
      local_2b8 = (longlong *)0x0;
      local_2f0 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      (**(code **)(*(longlong *)this + 0x1e8))(this,&local_2d0,1,1);
      cVar5 = (**(code **)(*local_2d0 + 0x60))();
      plVar11 = local_2b8;
      if (cVar5 == '\0') {
        do {
          uVar26 = (ulong)plVar15;
          this_00 = (OdDgElementId *)(**(code **)(*local_2d0 + 0x68))(local_2d0,local_250);
          OdDgElementId::openObject(this_00,(OpenMode)&local_2e0,true);
          iVar8 = (**(code **)(*local_2e0 + 0x100))();
          plVar12 = local_2e0;
          if (iVar8 == 0x26) {
            if ((uVar26 == 0) && (plVar11 != local_2e0)) {
              if (plVar11 != (longlong *)0x0) {
                (**(code **)(*plVar11 + 0x28))(plVar11);
              }
              local_2b8 = plVar12;
              plVar11 = plVar12;
              if (plVar12 != (longlong *)0x0) {
                (**(code **)(*plVar12 + 0x20))(plVar12);
              }
            }
            plVar15 = local_2e0;
            local_270 = (OdDgDgnStoreComponent *)0x0;
            pOVar13 = local_270;
            if (local_2e0 != (longlong *)0x0) {
              lVar9 = *local_2e0;
              pOVar10 = OdDgDgnStoreComponent::desc();
              pOVar13 = (OdDgDgnStoreComponent *)(**(code **)(lVar9 + 8))(plVar15,pOVar10);
              if (pOVar13 == (OdDgDgnStoreComponent *)0x0) {
                pOVar10 = OdDgDgnStoreComponent::desc();
                pOVar20 = (OdRxClass *)(**(code **)(*plVar15 + 0x18))(plVar15);
                OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                          ((OdError_NotThatKindOfClass *)&local_2e8,pOVar20,pOVar10);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(&local_2e8,(ThrowInfo *)&DAT_180de5310);
              }
            }
            local_270 = pOVar13;
            pOVar13 = local_270;
            OdDgDgnStoreComponent::setSequenceNumber(local_270,uVar26);
            pvVar14 = OdDgDgnStoreComponent::getDataPtr(pOVar13);
            uVar24 = 0;
            uVar6 = OdDgDgnStoreComponent::getDataSize(pOVar13);
            if (uVar6 != 0) {
              do {
                pcVar23 = (code *)((ulonglong)uVar24 + (longlong)pvVar14);
                uVar1 = *(uint *)(local_2f0 + -4);
                LOCK();
                pcVar21 = local_2f0 + -0x10;
                iVar8 = *(int *)pcVar21;
                *(int *)pcVar21 = *(int *)pcVar21;
                UNLOCK();
                if ((iVar8 < 2) && (uVar1 != *(uint *)(local_2f0 + -8))) {
LAB_180275c81:
                  local_2f0[uVar1] = *pcVar23;
                }
                else {
                  if (*(int *)(local_2f0 + -4) == 0) {
LAB_180275c60:
                    local_308 = CONCAT31(local_308._1_3_,1);
                    FUN_18000ca40(&local_2f0,uVar1 + 1,iVar8 < 2,0);
                    goto LAB_180275c81;
                  }
                  FUN_18000d0b0(&local_2f0);
                  if (((*(int *)(local_2f0 + -4) == 0) || (pcVar23 < local_2f0)) ||
                     (*(int *)(local_2f0 + -4) == 0)) goto LAB_180275c60;
                  FUN_18000d0b0();
                  pcVar21 = (code *)0x0;
                  if (*(uint *)(local_2f0 + -4) != 0) {
                    pcVar21 = local_2f0;
                  }
                  if (pcVar21 + *(uint *)(local_2f0 + -4) <= pcVar23) goto LAB_180275c60;
                  local_2f8[0] = *pcVar23;
                  local_308 = CONCAT31(local_308._1_3_,1);
                  FUN_18000ca40(&local_2f0,uVar1 + 1,iVar8 < 2,0);
                  memmove(local_2f0 + uVar1,local_2f8,1);
                }
                pOVar13 = local_270;
                *(int *)(local_2f0 + -4) = *(int *)(local_2f0 + -4) + 1;
                uVar24 = uVar24 + 1;
                uVar6 = OdDgDgnStoreComponent::getDataSize(local_270);
                plVar11 = local_2b8;
                param_1 = local_2e8;
                uVar26 = local_2c8;
              } while (uVar24 < uVar6);
            }
            local_2c8 = uVar26 + 1;
            plVar15 = (longlong *)(ulonglong)local_2c8;
            if (pOVar13 != (OdDgDgnStoreComponent *)0x0) {
              (**(code **)(*(longlong *)pOVar13 + 0x28))(pOVar13);
            }
          }
          if (local_2e0 != (longlong *)0x0) {
            (**(code **)(*local_2e0 + 0x28))();
            local_2e0 = (longlong *)0x0;
          }
          (**(code **)(*local_2d0 + 0x70))(local_2d0,1);
          cVar5 = (**(code **)(*local_2d0 + 0x60))();
        } while (cVar5 == '\0');
        plVar12 = local_2d8;
        if (((int)plVar15 != 0) && (plVar11 != (longlong *)0x0)) {
          local_308 = 0;
          lVar9 = __RTDynamicCast(plVar11[1],0,&OdDgElementImpl::RTTI_Type_Descriptor,
                                  &EDgnStoreComponent::RTTI_Type_Descriptor);
          plVar12 = local_2d8;
          if (lVar9 != 0) {
            *(int *)(lVar9 + 0x220) = (int)plVar15 + -1;
            *(undefined4 *)(lVar9 + 0x234) = *(undefined4 *)(local_2f0 + -4);
            *(undefined4 *)(lVar9 + 0x22c) = 0x42526570;
            *(undefined4 *)(lVar9 + 0x228) = 0x64537472;
            uVar7 = FUN_1803c0780(&local_2f0);
            *(undefined4 *)(lVar9 + 0x230) = uVar7;
            plVar12 = local_2d8;
          }
        }
      }
      if (local_2d0 != (longlong *)0x0) {
        (**(code **)(*local_2d0 + 0x28))();
        local_2d0 = (longlong *)0x0;
      }
      pcVar21 = local_2f0 + -0x10;
      LOCK();
      iVar8 = *(int *)pcVar21;
      *(int *)pcVar21 = *(int *)pcVar21 + -1;
      UNLOCK();
      if ((iVar8 == 1) && (pcVar21 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
      plVar11 = local_2b0;
      if (local_2b8 != (longlong *)0x0) {
        (**(code **)(*local_2b8 + 0x28))();
        plVar11 = local_2b0;
      }
    }
    (**(code **)(*plVar12 + 0x28))(plVar12);
  }
  bVar4 = true;
  local_268 = *(longlong *)(this + 0x58);
  iVar8 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar8 == 0) {
    if ((local_268 == 0) ||
       (dVar2 = OdGeMatrix3d::det((OdGeMatrix3d *)(this + 0x278)),
       ABS(dVar2) < 1e-06 || ABS(dVar2) == 1e-06)) {
      ECell<OdDgFiler3d>::GetGeomExtents((ECell<OdDgFiler3d> *)this,(OdGeExtents3d *)&local_2a8);
      local_248 = dStack_290;
      dStack_240 = local_288;
      local_238 = dStack_280;
      if ((dStack_290 < local_2a8) || ((local_288 < dStack_2a0 || (dStack_280 < local_298)))) {
        bVar4 = false;
      }
      if (bVar4) {
        local_2a8 = local_2a8 - *(double *)(this + 0x2f8);
        dStack_2a0 = dStack_2a0 - *(double *)(this + 0x300);
        local_298 = local_298 - *(double *)(this + 0x308);
        dStack_290 = dStack_290 - *(double *)(this + 0x2f8);
        local_288 = local_288 - *(double *)(this + 0x300);
        dStack_280 = dStack_280 - *(double *)(this + 0x308);
        bVar4 = OdGeMatrix3d::inverse((OdGeMatrix3d *)(this + 0x278),local_1c8,0.001);
        if (bVar4) {
          OdGeExtents3d::transformBy((OdGeExtents3d *)&local_2a8,local_1c8);
        }
      }
    }
    else {
      plVar15 = (longlong *)
                OdDgElementId::openObject((OdDgElementId *)&local_268,(OpenMode)&local_2d8,false);
      local_2e8 = (OdDgFiler *)0x0;
      plVar15 = (longlong *)*plVar15;
      pOVar16 = local_2e8;
      if (plVar15 != (longlong *)0x0) {
        lVar9 = *plVar15;
        pOVar10 = OdDgGraphicsElement::desc();
        pOVar16 = (OdDgFiler *)(**(code **)(lVar9 + 8))(plVar15,pOVar10);
        if (pOVar16 == (OdDgFiler *)0x0) {
          pOVar10 = OdDgGraphicsElement::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar15 + 0x18))(plVar15);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2c0,pOVar20,pOVar10);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2c0,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2e8 = pOVar16;
      pOVar16 = local_2e8;
      if (local_2d8 != (longlong *)0x0) {
        (**(code **)(*local_2d8 + 0x28))();
        local_2d8 = (longlong *)0x0;
      }
      this_01 = (OdGeMatrix3d *)OdGeMatrix3d::translation(local_148);
      pOVar17 = (OdGiDrawable *)OdGeMatrix3d::operator*(this_01,local_c8);
      pdVar18 = (double *)
                ECell<OdDgFiler3d>::getExtentsForRange
                          ((ECell<OdDgFiler3d> *)this,(OdGeMatrix3d *)&local_248,pOVar17);
      local_2a8 = *pdVar18;
      dStack_2a0 = pdVar18[1];
      local_298 = pdVar18[2];
      dStack_290 = pdVar18[3];
      local_288 = pdVar18[4];
      dStack_280 = pdVar18[5];
      if (pOVar16 != (OdDgFiler *)0x0) {
        (**(code **)(*(longlong *)pOVar16 + 0x28))(pOVar16);
      }
    }
  }
  else {
    FUN_1800178a0(&local_2a8,this + 0x248);
    FUN_1800178a0(&local_2a8,this + 0x260);
  }
  (**(code **)(*(longlong *)param_1 + 0x1a8))(param_1,&local_2a8);
  (**(code **)(*(longlong *)param_1 + 0x1a8))(param_1,&dStack_290);
  if (plVar11 != (longlong *)0x0) {
    (**(code **)(*plVar11 + 0x28))(plVar11);
  }
  if (local_278 != (OdDgElement *)0x0) {
    (**(code **)(*(longlong *)local_278 + 0x28))();
  }
LAB_18027602a:
  iVar8 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar8 == 0xb) {
    OdGeMatrix2d::OdGeMatrix2d((OdGeMatrix2d *)&local_218);
    local_218 = *(undefined8 *)(this + 0x278);
    local_210 = *(undefined8 *)(this + 0x280);
    local_208 = *(undefined8 *)(this + 0x290);
    uStack_200 = *(undefined8 *)(this + 0x298);
    local_1f8 = *(undefined8 *)(this + 0x2a0);
    local_1f0 = *(undefined8 *)(this + 0x2b0);
    uStack_1e8 = *(undefined8 *)(this + 0x2b8);
    local_1e0 = *(undefined8 *)(this + 0x2c0);
    local_1d8 = *(undefined8 *)(this + 0x2d0);
    (**(code **)(*(longlong *)param_1 + 0x170))(param_1);
    (**(code **)(*(longlong *)param_1 + 0x170))(param_1,(int)local_210);
    (**(code **)(*(longlong *)param_1 + 0x170))(param_1,(int)uStack_200);
    (**(code **)(*(longlong *)param_1 + 0x170))(param_1,(int)local_1f8);
  }
  else {
    FUN_180280850(param_1,this + 0x278);
  }
  (**(code **)(*(longlong *)param_1 + 0x1a8))(param_1,this + 0x2f8);
  iVar8 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (((iVar8 == 2) &&
      ((**(code **)(*(longlong *)param_1 + 0x160))(param_1,this[0x358] != (ECell3D)0x0),
      this[0x358] != (ECell3D)0x0)) &&
     ((**(code **)(*(longlong *)param_1 + 0x160))
                (param_1,*(undefined4 *)(*(longlong *)(this + 0x220) + -4)), uVar25 = 0,
     *(int *)(*(longlong *)(this + 0x220) + -4) != 0)) {
    do {
      uVar24 = *(uint *)(*(ulonglong *)(this + 0x220) - 4);
      if (uVar24 <= (uint)uVar25) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)&local_2b0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_2b0,(ThrowInfo *)&DAT_180de5370);
      }
      uVar22 = 0;
      if (uVar24 != 0) {
        uVar22 = *(ulonglong *)(this + 0x220);
      }
      local_2c0 = *(undefined8 *)(uVar22 + uVar25 * 8);
      lVar9 = *(longlong *)param_1;
      pOVar19 = OdDgElementId::getHandle((OdDgElementId *)&local_2c0);
      (**(code **)(lVar9 + 0x168))(param_1,*(undefined8 *)pOVar19);
      uVar24 = (uint)uVar25 + 1;
      uVar25 = (ulonglong)uVar24;
    } while (uVar24 < *(uint *)(*(longlong *)(this + 0x220) + -4));
  }
  return;
}



/* ==== 1802929e0 FUN_1802929e0 ==== */

void FUN_1802929e0(longlong param_1,longlong *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  code *pcVar7;
  uint uVar8;
  code *pcVar9;
  code *local_res8;
  OdError_InvalidIndex local_res10 [8];
  OdError_InvalidIndex local_res18 [8];
  OdError_InvalidIndex local_res20 [8];
  
  pcVar9 = (code *)0x0;
  if ((*(longlong *)(*(longlong *)(param_1 + 0x248) + 0x10) != 0) ||
     (bVar3 = true, *(longlong *)(*(longlong *)(param_1 + 0x248) + 0x18) == 0)) {
    bVar3 = false;
  }
  if (bVar3) {
    OdString::syncUnicode((OdString *)(param_1 + 0x248));
  }
  *(short *)(param_1 + 0x460) = (short)*(undefined4 *)(*(longlong *)(param_1 + 0x248) + 4) * 2 + 2;
  *(short *)(param_1 + 0x462) = (short)*(undefined4 *)(*(longlong *)(param_1 + 0x300) + -4);
  local_res8 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  if (*(int *)(*(longlong *)(param_1 + 0x308) + -4) != 0) {
    FUN_18021f680(param_1);
  }
  FUN_1802961f0(param_1,&local_res8);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x220));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x224));
  pcVar1 = local_res8;
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(local_res8 + -4));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x228));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x230));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x238));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x240));
  iVar4 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar4 == 0xb) {
    (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x400));
  }
  else {
    iVar4 = (**(code **)(*param_2 + 0x58))(param_2);
    lVar6 = param_1 + 0x408;
    if (iVar4 != 10) {
      lVar6 = param_1 + 0x3c8;
    }
    (**(code **)(*param_2 + 0x1c0))(param_2,lVar6);
  }
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 1000);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x462));
  uVar2 = *(undefined4 *)(pcVar1 + -4);
  FUN_18000d0b0(&local_res8);
  pcVar1 = local_res8;
  pcVar7 = pcVar9;
  if (*(int *)(local_res8 + -4) != 0) {
    pcVar7 = local_res8;
  }
  (**(code **)(*param_2 + 0x140))(param_2,pcVar7,uVar2);
  if (*(short *)(param_1 + 0x462) != 0) {
    do {
      uVar8 = (uint)pcVar9;
      if (*(uint *)(*(longlong *)(param_1 + 0x300) + -4) <= uVar8) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res20);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5370);
      }
      lVar6 = (longlong)pcVar9 * 3;
      (**(code **)(*param_2 + 0x150))
                (param_2,*(undefined1 *)(lVar6 + *(longlong *)(param_1 + 0x300)));
      if (*(uint *)(*(longlong *)(param_1 + 0x300) + -4) <= uVar8) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res18);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x150))
                (param_2,*(undefined1 *)(*(longlong *)(param_1 + 0x300) + 1 + lVar6));
      if (*(uint *)(*(longlong *)(param_1 + 0x300) + -4) <= uVar8) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res10);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x150))
                (param_2,*(undefined1 *)(*(longlong *)(param_1 + 0x300) + 2 + lVar6));
      pcVar9 = (code *)(ulonglong)(uVar8 + 1);
    } while (uVar8 + 1 < (uint)*(ushort *)(param_1 + 0x462));
  }
  uVar5 = (**(code **)(*param_2 + 0x80))(param_2);
  if ((uVar5 & 1) != 0) {
    (**(code **)(*param_2 + 0x148))(param_2,0);
  }
  pcVar1 = pcVar1 + -0x10;
  LOCK();
  iVar4 = *(int *)pcVar1;
  *(int *)pcVar1 = *(int *)pcVar1 + -1;
  UNLOCK();
  if ((iVar4 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
    odrxFree();
  }
  return;
}



/* ==== 1802e4710 FUN_1802e4710 ==== */

void FUN_1802e4710(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001802e471a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x220) + 0x48))();
  return;
}



