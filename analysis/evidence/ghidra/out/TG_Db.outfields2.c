/* ==== 180011210 FUN_180011210 ==== */

undefined8 FUN_180011210(longlong *param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(**(code **)(*param_1 + 0x18))();
  if ((((*(uint *)((longlong)param_1 + 0xc6c) >> 2 & 1) != 0) || ((*pbVar1 & 1) == 0)) &&
     (((*(uint *)((longlong)param_1 + 0xc6c) >> 3 & 1) != 0 || ((*pbVar1 >> 1 & 1) == 0)))) {
    return 1;
  }
  return 0;
}



/* ==== 180011258 FUN_180011258 ==== */

void FUN_180011258(longlong param_1,OdGeEllipArc3d *param_2,OdGePoint3d *param_3,OdGiArcType param_4
                  )

{
  OdGiBaseVectorizer::ellipArc((OdGiBaseVectorizer *)(param_1 + -0xa8),param_2,param_3,param_4);
  return;
}



/* ==== 1800a3540 FUN_1800a3540 ==== */

OdResult FUN_1800a3540(CDGElementGeneral *param_1,OdDgFiler *param_2,__uint64 param_3)

{
  OdResult OVar1;
  
  OVar1 = CDGElementGeneral::dgnInLinkages(param_1,param_2,param_3);
  if (OVar1 == 0) {
    (**(code **)(*(longlong *)param_1 + 0x6b0))(param_1);
    FUN_1800a40b0(param_1);
    (**(code **)(*(longlong *)param_1 + 0x6a0))(param_1);
    (**(code **)(*(longlong *)param_1 + 0x690))(param_1);
    OVar1 = 0;
  }
  return OVar1;
}



/* ==== 1800a35a0 FUN_1800a35a0 ==== */

OdResult FUN_1800a35a0(CDGElementGeneral *param_1,OdDgFiler *param_2,__uint64 param_3)

{
  OdResult OVar1;
  
  OVar1 = CDGElementGeneral::dgnInLinkages(param_1,param_2,param_3);
  if (OVar1 == 0) {
    (**(code **)(*(longlong *)param_1 + 0x6b0))(param_1);
    FUN_1800a44e0(param_1);
    (**(code **)(*(longlong *)param_1 + 0x6a0))(param_1);
    (**(code **)(*(longlong *)param_1 + 0x690))(param_1);
    OVar1 = 0;
  }
  return OVar1;
}



/* ==== 1801dc0b0 FUN_1801dc0b0 ==== */

void FUN_1801dc0b0(longlong param_1,longlong *param_2)

{
  (**(code **)(*param_2 + 0x1a0))(param_2,param_1 + 0x220);
                    /* WARNING: Could not recover jumptable at 0x0001801dc0ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x1a0))(param_2,param_1 + 0x230);
  return;
}



/* ==== 1801dc100 FUN_1801dc100 ==== */

void FUN_1801dc100(longlong param_1,longlong *param_2)

{
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 0x220);
                    /* WARNING: Could not recover jumptable at 0x0001801dc13a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 0x238);
  return;
}



/* ==== 1801dc150 FUN_1801dc150 ==== */

void FUN_1801dc150(CDGElementGeneral *param_1,CDGElementGeneral *param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_2 + 0x228);
  *(undefined8 *)(param_1 + 0x220) = *(undefined8 *)(param_2 + 0x220);
  *(undefined8 *)(param_1 + 0x228) = uVar1;
  uVar1 = *(undefined8 *)(param_2 + 0x238);
  *(undefined8 *)(param_1 + 0x230) = *(undefined8 *)(param_2 + 0x230);
  *(undefined8 *)(param_1 + 0x238) = uVar1;
  CDGElementGeneral::directCopyFrom(param_1,param_2);
  return;
}



/* ==== 180222290 FUN_180222290 ==== */

void FUN_180222290(longlong param_1,longlong *param_2)

{
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x220));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x222));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x224));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x226));
  (**(code **)(*param_2 + 0x1c0))(param_2,param_1 + 0x228);
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 0x248);
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x260));
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 0x268);
                    /* WARNING: Could not recover jumptable at 0x000180222351. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x280));
  return;
}



/* ==== 180222360 FUN_180222360 ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_180222360(CDGElementGeneral *param_1,longlong *param_2)

{
  longlong lVar1;
  double dVar2;
  bool bVar3;
  longlong *plVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  OdGeMatrix3d *pOVar9;
  longlong *plVar10;
  OdRxClass *pOVar11;
  OdDgDatabase *pOVar12;
  OdDbHandle *pOVar13;
  CDGElementGeneral *pCVar14;
  OdGeVector3d *pOVar15;
  undefined8 uVar16;
  undefined4 *puVar17;
  OdRxClass *pOVar18;
  code *pcVar19;
  code *pcVar20;
  CDGElementGeneral *pCVar21;
  uint uVar22;
  CDGElementGeneral *pCVar23;
  ulonglong uVar24;
  uint uVar25;
  CDGElementGeneral *pCVar27;
  double *pdVar28;
  uint uVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  undefined4 uVar34;
  undefined1 auStack_878 [32];
  CDGElementGeneral *local_858;
  undefined8 *local_850;
  CDGElementGeneral **local_848;
  CDGElementGeneral **local_840;
  undefined8 local_838;
  char local_828;
  uint local_824;
  CDGElementGeneral *local_820;
  CDGElementGeneral *local_818;
  uint local_810;
  CDGElementGeneral *local_808;
  uint local_800 [2];
  CDGElementGeneral *local_7f8;
  longlong *local_7f0;
  uint local_7e8 [2];
  longlong *local_7e0;
  longlong local_7d8;
  CDGElementGeneral *local_7d0;
  double local_7c8;
  double dStack_7c0;
  double local_7b8;
  int local_7b0;
  int local_7ac;
  CDGElementGeneral *local_7a8;
  double local_7a0;
  double local_798;
  double local_790;
  double local_788;
  double local_780;
  double local_778;
  longlong *local_770;
  CDGElementGeneral *local_768;
  CDGElementGeneral *local_760;
  longlong local_758;
  double local_750;
  double dStack_748;
  double local_740;
  undefined1 local_738 [8];
  code *local_730;
  CDGElementGeneral *local_728;
  undefined8 uStack_720;
  undefined8 local_718;
  undefined8 local_710;
  undefined8 uStack_708;
  undefined8 local_700;
  undefined8 local_6f8;
  undefined8 uStack_6f0;
  undefined8 local_6e8;
  OdError local_6e0 [8];
  code *local_6d8;
  OdError_InvalidIndex local_6d0 [8];
  undefined8 local_6c8;
  longlong local_6c0;
  double local_6b8;
  double dStack_6b0;
  double local_6a8;
  double local_6a0;
  double dStack_698;
  double local_690;
  CDGElementGeneral *local_688;
  undefined4 local_680;
  undefined8 local_678;
  CDGElementGeneral *pCStack_670;
  code *local_668;
  CDGElementGeneral *local_658;
  undefined8 uStack_650;
  undefined8 local_648;
  undefined8 local_638;
  undefined8 uStack_630;
  undefined8 local_628;
  undefined8 local_618;
  undefined8 uStack_610;
  undefined8 local_608;
  undefined4 local_5f8;
  undefined4 uStack_5f4;
  undefined4 uStack_5f0;
  undefined4 uStack_5ec;
  double local_5e8;
  undefined4 local_5d8;
  undefined4 uStack_5d4;
  undefined4 uStack_5d0;
  undefined4 uStack_5cc;
  double local_5c8;
  CDGElementGeneral *local_5b8;
  undefined8 uStack_5b0;
  OdGeMatrix3d local_5a8 [128];
  OdGeMatrix3d local_528 [128];
  OdGeMatrix3d local_4a8 [128];
  OdGeMatrix3d local_428 [128];
  OdGeMatrix3d local_3a8 [128];
  undefined1 local_328 [256];
  undefined1 local_228 [128];
  undefined1 local_1a8 [128];
  undefined1 local_128 [128];
  ulonglong local_a8;
  CDGElementGeneral *pCVar26;
  
  if (param_2 == (longlong *)0x0) {
    return;
  }
  local_a8 = DAT_180fcd438 ^ (ulonglong)auStack_878;
  local_7c8 = 0.0;
  dStack_7c0 = 0.0;
  local_7b8 = 0.0;
  local_750 = *(double *)kZAxis_exref;
  dStack_748 = *(double *)(kZAxis_exref + 8);
  local_740 = *(double *)(kZAxis_exref + 0x10);
  local_7f8 = param_1 + 0x228;
  local_820 = param_1;
  pOVar9 = (OdGeMatrix3d *)FUN_1801fcca0(local_7f8,local_328);
  pOVar9 = (OdGeMatrix3d *)OdGeMatrix3d::transpose(pOVar9);
  OdGeVector3d::transformBy((OdGeVector3d *)&local_750,pOVar9);
  OdGeVector3d::perpVector((OdGeVector3d *)&local_750);
  local_778 = local_750 * local_798 - dStack_748 * local_7a0;
  local_780 = local_7a0 * local_740 - local_790 * local_750;
  local_788 = local_790 * dStack_748 - local_798 * local_740;
  OdGeVector3d::normalize((OdGeVector3d *)&local_7a0,(OdGeTol *)gTol_exref);
  OdGeVector3d::normalize((OdGeVector3d *)&local_788,(OdGeTol *)gTol_exref);
  local_7b8 = local_7a0 * local_780 - local_798 * local_788;
  dStack_7c0 = local_790 * local_788 - local_7a0 * local_778;
  local_7c8 = local_798 * local_778 - local_790 * local_780;
  OdGeVector3d::normalize((OdGeVector3d *)&local_7c8,(OdGeTol *)gTol_exref);
  cVar5 = (**(code **)(*(longlong *)param_1 + 0x630))(param_1);
  if ((cVar5 == '\0') || (iVar7 = (**(code **)(*param_2 + 0x58))(param_2), iVar7 == 7)) {
    plVar10 = (longlong *)(**(code **)(*param_2 + 0xa8))(param_2);
    (**(code **)(*plVar10 + 0x88))
              (plVar10,param_1 + 0x248,*(undefined8 *)(param_1 + 0x260),&local_7c8);
    return;
  }
  pCVar14 = param_1 + 0x248;
  local_808 = pCVar14;
  dVar30 = (double)FUN_1808b5b50(param_2,0);
  dVar31 = *(double *)(param_1 + 0x260);
  uVar8 = 0;
  uVar34 = 0x3ff00000;
  pCVar27 = (CDGElementGeneral *)0x0;
  bVar6 = false;
  if ((dVar31 == 0.0) || (dVar31 < dVar30)) {
LAB_1802225ca:
    iVar7 = (**(code **)(*param_2 + 0x58))(param_2);
    if (iVar7 != 5) {
      if ((1e-10 < dVar30) || (bVar3 = true, dVar30 < -1e-10)) {
        bVar3 = bVar6;
      }
      uVar29 = 4;
      if (!bVar3) goto LAB_1802225f8;
    }
    uVar29 = 0x28;
  }
  else {
    if ((1e-10 < dVar30) || (bVar3 = true, dVar30 < -1e-10)) {
      bVar3 = bVar6;
    }
    if (bVar3) goto LAB_1802225ca;
    dVar31 = acos(1.0 - dVar30 / dVar31);
    dVar31 = ceil(3.141592653589793 / dVar31);
    uVar29 = (int)dVar31 + 1;
  }
LAB_1802225f8:
  local_818 = (CDGElementGeneral *)(g_empty_array_buffer_exref + 0x10);
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  local_668 = g_empty_array_buffer_exref + 0x10;
  local_6d8 = g_empty_array_buffer_exref;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  local_810 = uVar29 + 1;
  FUN_180177de0(&local_818,local_810);
  pCVar23 = pCVar27;
  pCVar26 = pCVar27;
  do {
    dVar31 = (double)(longlong)pCVar26 * (6.283185307179586 / (double)uVar29);
    dVar32 = sin(dVar31);
    dVar30 = dVar32 * local_778;
    dVar2 = dVar32 * local_780;
    dVar32 = dVar32 * local_788;
    dVar33 = cos(dVar31);
    dVar31 = *(double *)(param_1 + 0x260);
    local_6a8 = (local_790 * dVar33 + dVar30) * dVar31 + *(double *)(param_1 + 600);
    dStack_6b0 = (local_798 * dVar33 + dVar2) * dVar31 + *(double *)(param_1 + 0x250);
    local_6b8 = (dVar32 + local_7a0 * dVar33) * dVar31 + *(double *)pCVar14;
    if (*(uint *)(local_818 + -4) <= (uint)pCVar26) {
      OdError_InvalidIndex::OdError_InvalidIndex(local_6d0);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_6d0,(ThrowInfo *)&DAT_180de5370);
    }
    FUN_180018080(&local_818);
    *(double *)(pCVar23 + (longlong)local_818) = local_6b8;
    *(double *)(pCVar23 + (longlong)local_818 + 8) = dStack_6b0;
    *(double *)(pCVar23 + 0x10 + (longlong)local_818) = local_6a8;
    uVar25 = (uint)pCVar26 + 1;
    pCVar26 = (CDGElementGeneral *)(ulonglong)uVar25;
    pCVar23 = pCVar23 + 0x18;
  } while (uVar25 <= uVar29);
  uVar25 = uVar25 & 0xffffff00;
  local_7d0 = (CDGElementGeneral *)(g_empty_array_buffer_exref + 0x10);
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  local_824 = uVar25;
  plVar10 = (longlong *)(**(code **)(*param_2 + 0x68))(param_2);
  local_7e0 = plVar10;
  local_758 = (**(code **)(*plVar10 + 0x158))(plVar10);
  if ((((local_758 != 0) && (iVar7 = (**(code **)(*param_2 + 0x58))(param_2), iVar7 != 7)) &&
      (iVar7 = (**(code **)(*param_2 + 0x58))(param_2), iVar7 != 5)) &&
     (iVar7 = (**(code **)(*param_2 + 0x58))(param_2), iVar7 != 2)) {
    local_760 = (CDGElementGeneral *)0x0;
    OdDgElementId::openObject((OdDgElementId *)&local_758,(OpenMode)&local_7f0,false);
    pCVar23 = pCVar27;
    if (local_7f0 != (longlong *)0x0) {
      pOVar11 = OdDgMaterialTableRecord::desc();
      plVar10 = (longlong *)(**(code **)(*local_7f0 + 0x18))();
      cVar5 = (**(code **)(*plVar10 + 0x60))(plVar10,pOVar11);
      plVar4 = local_7f0;
      plVar10 = local_7e0;
      if ((cVar5 != '\0') && (local_7f0 != (longlong *)0x0)) {
        lVar1 = *local_7f0;
        pOVar11 = OdDgMaterialTableRecord::desc();
        pCVar23 = (CDGElementGeneral *)(**(code **)(lVar1 + 8))(plVar4,pOVar11);
        if (pCVar23 == (CDGElementGeneral *)0x0) {
          pOVar11 = OdDgMaterialTableRecord::desc();
          pOVar18 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_7f8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_7f8,(ThrowInfo *)&DAT_180de5310);
        }
        local_760 = pCVar23;
        cVar5 = (**(code **)((longlong)*(double *)pCVar23 + 0x4f0))(pCVar23);
        plVar10 = local_7e0;
        if (cVar5 != '\0') {
          CDGElementGeneral::getModelId(param_1);
          if (local_7d8 == 0) {
            if (*(longlong *)(param_1 + 0x58) == 0) {
LAB_1802228bf:
              pOVar12 = *(OdDgDatabase **)(param_1 + 0x68);
            }
            else {
              local_6c0 = *(longlong *)(param_1 + 0x58);
              pOVar12 = OdDgElementId::database((OdDgElementId *)&local_6c0);
              if (pOVar12 == (OdDgDatabase *)0x0) {
LAB_1802228ac:
                bVar3 = bVar6;
              }
              else {
                local_6c8 = *(undefined8 *)(param_1 + 0x58);
                pOVar13 = OdDgElementId::getHandle((OdDgElementId *)&local_6c8);
                bVar3 = true;
                if (*(longlong *)pOVar13 == 0) goto LAB_1802228ac;
              }
              if (!bVar3) goto LAB_1802228bf;
              pOVar12 = OdDgElementId::database((OdDgElementId *)(param_1 + 0x58));
            }
            if (pOVar12 != (OdDgDatabase *)0x0) {
              plVar10 = (longlong *)OdDgDatabase::getActiveModelId(pOVar12);
              local_7d8 = *plVar10;
            }
          }
          local_768 = (CDGElementGeneral *)0x0;
          pCVar14 = pCVar27;
          if (local_7d8 != 0) {
            plVar10 = (longlong *)
                      OdDgElementId::openObject
                                ((OdDgElementId *)&local_7d8,(OpenMode)&local_770,false);
            plVar10 = (longlong *)*plVar10;
            pCVar26 = local_768;
            if (plVar10 != (longlong *)0x0) {
              lVar1 = *plVar10;
              pOVar11 = OdDgModel::desc();
              pCVar14 = (CDGElementGeneral *)(**(code **)(lVar1 + 8))(plVar10,pOVar11);
              pCVar26 = pCVar14;
              if (pCVar14 == (CDGElementGeneral *)0x0) {
                pOVar11 = OdDgModel::desc();
                pOVar18 = (OdRxClass *)(**(code **)(*plVar10 + 0x18))(plVar10);
                OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                          ((OdError_NotThatKindOfClass *)&local_7f8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(&local_7f8,(ThrowInfo *)&DAT_180de5310);
              }
            }
            local_768 = pCVar26;
            if (local_770 != (longlong *)0x0) {
              (**(code **)(*local_770 + 0x28))();
              local_770 = (longlong *)0x0;
            }
          }
          pCVar26 = local_7f8;
          local_728 = *(CDGElementGeneral **)kZAxis_exref;
          uStack_720 = *(undefined8 *)(kZAxis_exref + 8);
          local_718 = *(undefined8 *)(kZAxis_exref + 0x10);
          local_6f8 = *(undefined8 *)kXAxis_exref;
          uStack_6f0 = *(undefined8 *)(kXAxis_exref + 8);
          local_6e8 = *(undefined8 *)(kXAxis_exref + 0x10);
          local_710 = *(undefined8 *)kYAxis_exref;
          uStack_708 = *(undefined8 *)(kYAxis_exref + 8);
          local_700 = *(undefined8 *)(kYAxis_exref + 0x10);
          pOVar9 = (OdGeMatrix3d *)FUN_1801fcca0(local_7f8,local_228);
          OdGeMatrix3d::transpose(pOVar9);
          pOVar15 = OdGeVector3d::transformBy((OdGeVector3d *)&local_728,local_528);
          local_728 = *(CDGElementGeneral **)pOVar15;
          uStack_720 = *(undefined8 *)(pOVar15 + 8);
          local_718 = *(undefined8 *)(pOVar15 + 0x10);
          pOVar9 = (OdGeMatrix3d *)FUN_1801fcca0(pCVar26,local_1a8);
          OdGeMatrix3d::transpose(pOVar9);
          pOVar15 = OdGeVector3d::transformBy((OdGeVector3d *)&local_6f8,local_4a8);
          local_6f8 = *(undefined8 *)pOVar15;
          uStack_6f0 = *(undefined8 *)(pOVar15 + 8);
          local_6e8 = *(undefined8 *)(pOVar15 + 0x10);
          pOVar9 = (OdGeMatrix3d *)FUN_1801fcca0(pCVar26,local_128);
          OdGeMatrix3d::transpose(pOVar9);
          pOVar15 = OdGeVector3d::transformBy((OdGeVector3d *)&local_710,local_428);
          local_710 = *(undefined8 *)pOVar15;
          uStack_708 = *(undefined8 *)(pOVar15 + 8);
          local_700 = *(undefined8 *)(pOVar15 + 0x10);
          local_5b8 = (CDGElementGeneral *)0x100000001;
          uStack_5b0 = 0x100000001;
          OdGeMatrix3d::OdGeMatrix3d(local_5a8);
          cVar5 = (**(code **)(**(longlong **)(pCVar23 + 8) + 0x718))();
          if (cVar5 != '\0') {
            plVar10 = (longlong *)(**(code **)(*param_2 + 0xa8))(param_2);
            (**(code **)(*plVar10 + 0x60))(plVar10,local_3a8);
            dVar31 = OdGeMatrix3d::scale(local_3a8);
            uVar8 = SUB84(dVar31,0);
            uVar34 = (undefined4)((ulonglong)dVar31 >> 0x20);
          }
          local_658 = local_728;
          uStack_650 = uStack_720;
          local_648 = local_718;
          local_638 = local_710;
          uStack_630 = uStack_708;
          local_628 = local_700;
          local_618 = local_6f8;
          uStack_610 = uStack_6f0;
          local_608 = local_6e8;
          local_5f8 = *(undefined4 *)local_808;
          uStack_5f4 = *(undefined4 *)(local_808 + 4);
          uStack_5f0 = *(undefined4 *)(local_808 + 8);
          uStack_5ec = *(undefined4 *)(local_808 + 0xc);
          local_5e8 = *(double *)(local_808 + 0x10);
          local_7a8 = pCVar14;
          local_5d8 = local_5f8;
          uStack_5d4 = uStack_5f4;
          uStack_5d0 = uStack_5f0;
          uStack_5cc = uStack_5ec;
          local_5c8 = local_5e8;
          if (pCVar14 != (CDGElementGeneral *)0x0) {
            (**(code **)((longlong)*(double *)pCVar14 + 0x20))(pCVar14);
          }
          local_838 = CONCAT44(uVar34,uVar8);
          local_840 = &local_5b8;
          local_848 = &local_658;
          local_850 = &local_638;
          local_858 = (CDGElementGeneral *)&local_618;
          cVar5 = (**(code **)((longlong)*(double *)pCVar23 + 0x4e8))
                            (pCVar23,&local_7a8,&local_5d8,&local_5f8);
          if (cVar5 != '\0') {
            (**(code **)(*local_7e0 + 0xb8))(local_7e0,&local_5b8);
            if ((int)local_5b8 == 0x32) {
              local_824 = CONCAT31(local_824._1_3_,1);
            }
            else {
              local_824 = local_824 & 0xff;
              if ((int)local_5b8 == 0x35) {
                local_824 = 1;
              }
            }
          }
          plVar10 = local_7e0;
          if (pCVar14 != (CDGElementGeneral *)0x0) {
            (**(code **)((longlong)*(double *)pCVar14 + 0x28))(pCVar14);
            local_768 = (CDGElementGeneral *)0x0;
            plVar10 = local_7e0;
          }
        }
      }
    }
    if (local_7f0 != (longlong *)0x0) {
      (**(code **)(*local_7f0 + 0x28))(local_7f0);
      local_7f0 = (longlong *)0x0;
    }
    pCVar14 = local_808;
    uVar25 = local_824;
    if (pCVar23 != (CDGElementGeneral *)0x0) {
      (**(code **)((longlong)*(double *)pCVar23 + 0x28))(pCVar23);
      local_760 = (CDGElementGeneral *)0x0;
      pCVar14 = local_808;
      uVar25 = local_824;
    }
  }
  iVar7 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar7 == 5) {
    plVar10 = (longlong *)(**(code **)(*param_2 + 0xa8))();
    (**(code **)(*plVar10 + 0x88))(plVar10,pCVar14,*(double *)(local_820 + 0x260),&local_7c8);
    goto LAB_1802231c7;
  }
  bVar6 = false;
  local_828 = '\0';
  iVar7 = (**(code **)(*param_2 + 0x58))(param_2);
  if ((iVar7 == 3) || (iVar7 = (**(code **)(*param_2 + 0x58))(param_2), iVar7 == 4)) {
    local_828 = '\x01';
    bVar6 = true;
  }
  (**(code **)(*plVar10 + 0x120))(plVar10);
  if (bVar6) {
    (**(code **)(*plVar10 + 0x80))(plVar10,1);
  }
  if (((char)uVar25 == '\0') || (uVar29 < 3)) {
    local_6a0 = local_750;
    dStack_698 = dStack_748;
    local_690 = local_740;
    bVar6 = OdGeVector3d::isZeroLength((OdGeVector3d *)&local_6a0,(OdGeTol *)gTol_exref);
    if (bVar6) {
      OdGeVector3d::normalize((OdGeVector3d *)&local_6a0,(OdGeTol *)gTol_exref);
    }
    plVar10 = (longlong *)(**(code **)(*param_2 + 0xa8))(param_2);
    pdVar28 = &local_6a0;
  }
  else {
    uVar16 = (**(code **)(*param_2 + 0x68))(param_2);
    uVar8 = (**(code **)(*param_2 + 0x58))(param_2);
    local_848 = &local_7d0;
    local_850 = (undefined8 *)CONCAT71(local_850._1_7_,1);
    local_858 = (CDGElementGeneral *)((ulonglong)local_858 & 0xffffffffffffff00);
    cVar5 = FUN_180662fe0(&local_758,&local_818,uVar8,uVar16);
    if (cVar5 != '\0') {
      local_808 = (CDGElementGeneral *)(g_empty_array_buffer_exref + 0x10);
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      local_7b0 = uVar29 + 1;
      FUN_18018c6a0(&local_808,&local_7b0);
      pCVar14 = pCVar27;
      do {
        local_7ac = (int)pCVar14;
        FUN_18018c6a0(&local_808);
        uVar25 = (int)pCVar14 + 1;
        pCVar14 = (CDGElementGeneral *)(ulonglong)uVar25;
      } while (uVar25 <= uVar29);
      local_688 = (CDGElementGeneral *)0x0;
      local_680 = 0;
      local_678 = 0;
      pCStack_670 = (CDGElementGeneral *)0x0;
      FUN_180018080(&local_7d0);
      pcVar19 = g_empty_array_buffer_exref;
      pCStack_670 = pCVar27;
      if (*(int *)(local_7d0 + -4) != 0) {
        pCStack_670 = local_7d0;
      }
      local_820 = (CDGElementGeneral *)(g_empty_array_buffer_exref + 0x10);
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      if (local_828 != '\0') {
        uVar29 = *(uint *)(local_818 + -4);
        uVar25 = *(uint *)(pcVar19 + 0xc);
        uVar22 = uVar29 - uVar25;
        uVar24 = (ulonglong)uVar22;
        local_824 = uVar29;
        if ((int)uVar22 < 1) {
          if ((int)uVar22 < 0) {
            LOCK();
            iVar7 = *(int *)pcVar19;
            *(undefined4 *)pcVar19 = *(undefined4 *)pcVar19;
            UNLOCK();
            if (1 < iVar7) {
              local_810 = *(uint *)(pcVar19 + 4);
              if ((int)local_810 < 1) {
                uVar25 = *(int *)(pcVar19 + 0xc) + -(*(int *)(pcVar19 + 0xc) * local_810) / 100;
                uVar24 = (ulonglong)uVar25;
                if (uVar25 < uVar29) {
                  uVar24 = (ulonglong)uVar29;
                }
              }
              else {
                uVar24 = (ulonglong)((((uVar29 - 1) + local_810) / local_810) * local_810);
              }
              local_7e8[0] = uVar29;
              if ((uVar24 * 0x18 + 0x10 <= uVar24) ||
                 (puVar17 = (undefined4 *)odrxAlloc(), puVar17 == (undefined4 *)0x0)) {
                OdError::OdError((OdError *)&local_7f8,9);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(&local_7f8,(ThrowInfo *)&DAT_180de52b8);
              }
              *puVar17 = 0;
              LOCK();
              *puVar17 = 1;
              UNLOCK();
              puVar17[1] = local_810;
              puVar17[2] = (int)uVar24;
              puVar17[3] = 0;
              pcVar20 = (code *)local_7e8;
              if (*(uint *)(pcVar19 + 0xc) < uVar29) {
                pcVar20 = pcVar19 + 0xc;
              }
              uVar29 = *(uint *)pcVar20;
              pCVar14 = (CDGElementGeneral *)(puVar17 + 4);
              local_7e8[0] = uVar29;
              memcpy(pCVar14,pcVar19 + 0x10,(ulonglong)uVar29 * 0x18);
              puVar17[3] = uVar29;
              LOCK();
              iVar7 = *(int *)pcVar19;
              *(int *)pcVar19 = *(int *)pcVar19 + -1;
              UNLOCK();
              local_820 = pCVar14;
              if ((iVar7 == 1) && (pcVar19 != g_empty_array_buffer_exref)) goto LAB_180222e6c;
            }
          }
        }
        else {
          if (((CDGElementGeneral *)&local_7c8 < local_820) ||
             (local_820 + (ulonglong)uVar25 * 0x18 < (CDGElementGeneral *)&local_7c8)) {
            local_738[0] = 1;
          }
          else {
            local_738[0] = 0;
          }
          local_730 = (code *)0x0;
          FUN_180191b60(local_738,&local_820,uVar29);
          if (uVar22 != 0) {
            pCVar14 = local_820 + uVar24 * 0x18 + (ulonglong)uVar25 * 0x18;
            do {
              *(double *)(pCVar14 + -0x18) = local_7c8;
              *(double *)(pCVar14 + -0x10) = dStack_7c0;
              *(double *)(pCVar14 + -8) = local_7b8;
              uVar29 = (int)uVar24 - 1;
              uVar24 = (ulonglong)uVar29;
              pCVar14 = pCVar14 + -0x18;
            } while (uVar29 != 0);
          }
          if (local_730 != (code *)0x0) {
            LOCK();
            iVar7 = *(int *)local_730;
            *(int *)local_730 = *(int *)local_730 + -1;
            UNLOCK();
            if ((iVar7 == 1) && (pcVar19 = local_730, local_730 != g_empty_array_buffer_exref)) {
LAB_180222e6c:
              odrxFree(pcVar19);
            }
          }
        }
        pCVar23 = local_820;
        *(uint *)(local_820 + -4) = local_824;
        pCVar14 = local_820 + -0x10;
        LOCK();
        iVar7 = *(int *)pCVar14;
        *(int *)pCVar14 = *(int *)pCVar14;
        UNLOCK();
        if (1 < iVar7) {
          local_800[0] = *(uint *)(local_820 + -8);
          uVar29 = *(uint *)(local_820 + -0xc);
          if ((int)uVar29 < 1) {
            uVar25 = *(int *)(local_820 + -4) + -(*(int *)(local_820 + -4) * uVar29) / 100;
            uVar24 = (ulonglong)uVar25;
            if (uVar25 < local_800[0]) {
              uVar24 = (ulonglong)local_800[0];
            }
          }
          else {
            uVar24 = (ulonglong)((((local_800[0] - 1) + uVar29) / uVar29) * uVar29);
          }
          if ((uVar24 * 0x18 + 0x10 <= uVar24) ||
             (puVar17 = (undefined4 *)odrxAlloc(), puVar17 == (undefined4 *)0x0)) {
            OdError::OdError(local_6e0,9);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_6e0,(ThrowInfo *)&DAT_180de52b8);
          }
          *puVar17 = 0;
          LOCK();
          *puVar17 = 1;
          UNLOCK();
          puVar17[1] = uVar29;
          puVar17[2] = (int)uVar24;
          puVar17[3] = 0;
          pCVar26 = pCVar23 + -4;
          pCVar21 = (CDGElementGeneral *)local_800;
          if (*(uint *)pCVar26 < local_800[0]) {
            pCVar21 = pCVar26;
          }
          uVar29 = *(uint *)pCVar21;
          pCVar26 = (CDGElementGeneral *)(puVar17 + 4);
          local_800[0] = uVar29;
          memcpy(pCVar26,pCVar23,(ulonglong)uVar29 * 0x18);
          puVar17[3] = uVar29;
          LOCK();
          iVar7 = *(int *)pCVar14;
          *(int *)pCVar14 = *(int *)pCVar14 + -1;
          UNLOCK();
          local_820 = pCVar26;
          if ((iVar7 == 1) && (pCVar14 != (CDGElementGeneral *)g_empty_array_buffer_exref)) {
            odrxFree(pCVar14);
          }
        }
        local_688 = pCVar27;
        if (*(int *)(local_820 + -4) != 0) {
          local_688 = local_820;
        }
      }
      pCVar14 = local_820;
      plVar10 = (longlong *)(**(code **)(*param_2 + 0xa8))(param_2);
      FUN_18016f6d0(&local_808);
      iVar7 = *(int *)(local_808 + -4);
      pCVar23 = pCVar27;
      if (iVar7 != 0) {
        pCVar23 = local_808;
      }
      FUN_180018080(&local_818);
      if (*(int *)(local_818 + -4) != 0) {
        pCVar27 = local_818;
      }
      local_840 = &local_688;
      local_848 = (CDGElementGeneral **)0x0;
      local_850 = (undefined8 *)0x0;
      local_858 = pCVar23;
      (**(code **)(*plVar10 + 200))(plVar10,*(int *)(local_818 + -4),pCVar27,iVar7);
      pCVar14 = pCVar14 + -0x10;
      LOCK();
      iVar7 = *(int *)pCVar14;
      *(int *)pCVar14 = *(int *)pCVar14 + -1;
      UNLOCK();
      if ((iVar7 == 1) && (pCVar14 != (CDGElementGeneral *)g_empty_array_buffer_exref)) {
        odrxFree();
      }
      pCVar14 = local_808 + -0x10;
      LOCK();
      iVar7 = *(int *)pCVar14;
      *(int *)pCVar14 = *(int *)pCVar14 + -1;
      UNLOCK();
      if ((iVar7 == 1) && (pCVar14 != (CDGElementGeneral *)g_empty_array_buffer_exref)) {
        odrxFree();
      }
      goto LAB_1802231c7;
    }
    plVar10 = (longlong *)(**(code **)(*param_2 + 0xa8))(param_2);
    pdVar28 = &local_7c8;
  }
  if (*(int *)(local_818 + -4) != 0) {
    pCVar27 = local_818;
  }
  (**(code **)(*plVar10 + 0xa8))(plVar10,local_810,pCVar27,pdVar28);
LAB_1802231c7:
  pCVar14 = local_7d0 + -0x10;
  LOCK();
  iVar7 = *(int *)pCVar14;
  *(int *)pCVar14 = *(int *)pCVar14 + -1;
  UNLOCK();
  if ((iVar7 == 1) && (pCVar14 != (CDGElementGeneral *)g_empty_array_buffer_exref)) {
    odrxFree();
  }
  LOCK();
  iVar7 = *(int *)local_6d8;
  *(int *)local_6d8 = *(int *)local_6d8 + -1;
  UNLOCK();
  if ((iVar7 == 1) && (local_6d8 != g_empty_array_buffer_exref)) {
    odrxFree();
  }
  pCVar14 = local_818 + -0x10;
  LOCK();
  iVar7 = *(int *)pCVar14;
  *(int *)pCVar14 = *(int *)pCVar14 + -1;
  UNLOCK();
  if ((iVar7 == 1) && (pCVar14 != (CDGElementGeneral *)g_empty_array_buffer_exref)) {
    odrxFree();
  }
  return;
}



/* ==== 180292680 FUN_180292680 ==== */

OdResult FUN_180292680(CDGElementGeneral *param_1,OdDgFiler *param_2,__uint64 param_3)

{
  OdResult OVar1;
  
  OVar1 = CDGElementGeneral::dgnInLinkages(param_1,param_2,param_3);
  if (OVar1 == 0) {
    (**(code **)(*(longlong *)param_1 + 0x620))(param_1);
    (**(code **)(*(longlong *)param_1 + 0x6e0))(param_1);
    (**(code **)(*(longlong *)param_1 + 0x608))(param_1);
    (**(code **)(*(longlong *)param_1 + 0x600))(param_1);
    OVar1 = 0;
  }
  return OVar1;
}



/* ==== 1802926e0 FUN_1802926e0 ==== */

void FUN_1802926e0(longlong param_1,longlong *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  code *pcVar7;
  uint uVar8;
  code *pcVar9;
  undefined8 uVar10;
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
  *(short *)(param_1 + 0x440) = (short)*(undefined4 *)(*(longlong *)(param_1 + 0x248) + 4) * 2 + 2;
  *(short *)(param_1 + 0x442) = (short)*(undefined4 *)(*(longlong *)(param_1 + 0x300) + -4);
  local_res8 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  if (*(int *)(*(longlong *)(param_1 + 0x308) + -4) != 0) {
    FUN_18021f1b0(param_1);
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
  lVar5 = *param_2;
  if (iVar4 == 0xb) {
    uVar10 = *(undefined8 *)(param_1 + 0x3e0);
  }
  else {
    iVar4 = (**(code **)(lVar5 + 0x58))(param_2);
    lVar5 = *param_2;
    if (iVar4 == 10) {
      (**(code **)(lVar5 + 0x1c0))(param_2,param_1 + 1000);
      goto LAB_180292856;
    }
    uVar10 = *(undefined8 *)(param_1 + 0x3c8);
  }
  (**(code **)(lVar5 + 0x170))(param_2,uVar10);
LAB_180292856:
  (**(code **)(*param_2 + 0x1a0))(param_2,param_1 + 0x3d0);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x442));
  uVar2 = *(undefined4 *)(pcVar1 + -4);
  FUN_18000d0b0(&local_res8);
  pcVar1 = local_res8;
  pcVar7 = pcVar9;
  if (*(int *)(local_res8 + -4) != 0) {
    pcVar7 = local_res8;
  }
  (**(code **)(*param_2 + 0x140))(param_2,pcVar7,uVar2);
  if (*(short *)(param_1 + 0x442) != 0) {
    do {
      uVar8 = (uint)pcVar9;
      if (*(uint *)(*(longlong *)(param_1 + 0x300) + -4) <= uVar8) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res20);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5370);
      }
      lVar5 = (longlong)pcVar9 * 3;
      (**(code **)(*param_2 + 0x150))
                (param_2,*(undefined1 *)(lVar5 + *(longlong *)(param_1 + 0x300)));
      if (*(uint *)(*(longlong *)(param_1 + 0x300) + -4) <= uVar8) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res18);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x150))
                (param_2,*(undefined1 *)(*(longlong *)(param_1 + 0x300) + 1 + lVar5));
      if (*(uint *)(*(longlong *)(param_1 + 0x300) + -4) <= uVar8) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res10);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x150))
                (param_2,*(undefined1 *)(*(longlong *)(param_1 + 0x300) + 2 + lVar5));
      pcVar9 = (code *)(ulonglong)(uVar8 + 1);
    } while (uVar8 + 1 < (uint)*(ushort *)(param_1 + 0x442));
  }
  uVar6 = (**(code **)(*param_2 + 0x80))(param_2);
  if ((uVar6 & 1) != 0) {
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



/* ==== 18045e500 FUN_18045e500 ==== */

void FUN_18045e500(longlong *param_1,longlong *param_2)

{
  (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x48]);
                    /* WARNING: Could not recover jumptable at 0x00018045e535. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x658))(param_1,param_2);
  return;
}



