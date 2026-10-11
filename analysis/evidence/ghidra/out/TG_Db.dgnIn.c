/* ==== 180010c10 dgnInFields ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual enum OdResult __cdecl ECell<class OdDgFiler3d>::dgnInFields(class OdDgFiler *
   __ptr64) __ptr64 */

OdResult __thiscall ECell<OdDgFiler3d>::dgnInFields(ECell<OdDgFiler3d> *this,OdDgFiler *param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  OdDgDatabase *this_00;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 auStack_f8 [32];
  longlong local_d8;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
                    /* 0x10c10  7795
                       ?dgnInFields@?$ECell@VOdDgFiler3d@@@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z */
  local_28 = DAT_180fcd438 ^ (ulonglong)auStack_f8;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x240) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x242) = uVar1;
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_d0);
  *(undefined4 *)(this + 0x248) = local_d0;
  *(undefined4 *)(this + 0x24c) = uStack_cc;
  *(undefined4 *)(this + 0x250) = uStack_c8;
  *(undefined4 *)(this + 0x254) = uStack_c4;
  *(undefined8 *)(this + 600) = local_c0;
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_d0);
  *(ulonglong *)(this + 0x260) = CONCAT44(uStack_cc,local_d0);
  *(ulonglong *)(this + 0x268) = CONCAT44(uStack_c4,uStack_c8);
  *(undefined8 *)(this + 0x270) = local_c0;
  OdGeMatrix3d::OdGeMatrix3d((OdGeMatrix3d *)&local_a8);
  local_a8 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_a0 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  local_98 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  local_88 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_80 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  local_78 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  local_68 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_60 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x278) = local_a8;
  *(undefined8 *)(this + 0x280) = uStack_a0;
  *(undefined8 *)(this + 0x288) = local_98;
  *(undefined8 *)(this + 0x290) = uStack_90;
  *(undefined8 *)(this + 0x298) = local_88;
  *(undefined8 *)(this + 0x2a0) = uStack_80;
  *(undefined8 *)(this + 0x2a8) = local_78;
  *(undefined8 *)(this + 0x2b0) = uStack_70;
  *(undefined8 *)(this + 0x2b8) = local_68;
  *(undefined8 *)(this + 0x2c0) = uStack_60;
  *(undefined8 *)(this + 0x2c8) = uVar6;
  *(undefined4 *)(this + 0x2d0) = uStack_50;
  *(undefined4 *)(this + 0x2d4) = uStack_4c;
  *(undefined4 *)(this + 0x2d8) = local_48;
  *(undefined4 *)(this + 0x2dc) = uStack_44;
  *(undefined4 *)(this + 0x2e0) = uStack_40;
  *(undefined4 *)(this + 0x2e4) = uStack_3c;
  *(undefined4 *)(this + 0x2e8) = local_38;
  *(undefined4 *)(this + 0x2ec) = uStack_34;
  *(undefined4 *)(this + 0x2f0) = uStack_30;
  *(undefined4 *)(this + 0x2f4) = uStack_2c;
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_d0);
  *(undefined4 *)(this + 0x2f8) = local_d0;
  *(undefined4 *)(this + 0x2fc) = uStack_cc;
  *(undefined4 *)(this + 0x300) = uStack_c8;
  *(undefined4 *)(this + 0x304) = uStack_c4;
  *(undefined8 *)(this + 0x328) = 0xbff0000000000000;
  *(undefined8 *)(this + 0x308) = local_c0;
  iVar2 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (((iVar2 == 2) && (iVar2 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1), iVar2 == 1)) &&
     (lVar4 = FUN_180010890(this), lVar4 != 0)) {
    uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    uVar5 = (ulonglong)uVar3;
    FUN_18000d1e0(this + 0x220);
    *(undefined4 *)(*(longlong *)(this + 0x220) + -4) = 0;
    if (uVar3 != 0) {
      do {
        local_b8 = (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
        this_00 = (OdDgDatabase *)FUN_180010890(this);
        OdDgDatabase::getElementId(this_00,(OdDbHandle *)&local_d8);
        if (local_d8 != 0) {
          FUN_180013b80(this + 0x220,&local_d8);
        }
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  return 0;
}



/* ==== 180010f50 dgnInLinkages ==== */

/* public: virtual enum OdResult __cdecl ECell<class OdDgFiler3d>::dgnInLinkages(class OdDgFiler *
   __ptr64,unsigned __int64) __ptr64 */

OdResult __thiscall
ECell<OdDgFiler3d>::dgnInLinkages(ECell<OdDgFiler3d> *this,OdDgFiler *param_1,__uint64 param_2)

{
  OdResult OVar1;
  
                    /* 0x10f50  7819
                       ?dgnInLinkages@?$ECell@VOdDgFiler3d@@@@UEAA?AW4OdResult@@PEAVOdDgFiler@@_K@Z
                        */
  OVar1 = CDGElementGeneral::dgnInLinkages((CDGElementGeneral *)this,param_1,param_2);
  if (OVar1 == 0) {
    readAttributes(this);
  }
  return OVar1;
}



/* ==== 180010fa0 dgnInXAttributes ==== */

/* public: virtual enum OdResult __cdecl ECell<class OdDgFiler3d>::dgnInXAttributes(class OdDgFiler
   * __ptr64) __ptr64 */

OdResult __thiscall
ECell<OdDgFiler3d>::dgnInXAttributes(ECell<OdDgFiler3d> *this,OdDgFiler *param_1)

{
                    /* 0x10fa0  7823
                       ?dgnInXAttributes@?$ECell@VOdDgFiler3d@@@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z
                        */
  CDGElementGeneral::dgnInXAttributes((CDGElementGeneral *)this,param_1);
  initAnnotationScale(this);
  return 0;
}



/* ==== 18004c270 dgnInFields ==== */

/* public: void __cdecl OdDgDegreeOfFreedom::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgDegreeOfFreedom::dgnInFields(OdDgDegreeOfFreedom *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
                    /* 0x4c270  7803  ?dgnInFields@OdDgDegreeOfFreedom@@QEAAXPEAVOdDgFiler@@@Z */
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)this = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 4) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 8) = uVar2;
  return;
}



/* ==== 18010fb80 readFile ==== */

/* public: virtual class OdSmartPtr<class OdDgDatabase> __cdecl OdDgHostAppServices::readFile(class
   OdString const & __ptr64,enum Oda::FileShareMode,bool) __ptr64 */

OdString * __thiscall
OdDgHostAppServices::readFile
          (OdDgHostAppServices *this,OdString *param_1,FileShareMode param_2,bool param_3)

{
  ulonglong uVar1;
  undefined4 in_register_00000084;
  undefined7 in_register_00000089;
  bool in_stack_00000028;
  
                    /* 0x10fb80  17889
                       ?readFile@OdDgHostAppServices@@UEAA?AV?$OdSmartPtr@VOdDgDatabase@@@@AEBVOdString@@W4FileShareMode@Oda@@_N@Z
                        */
  (**(code **)(*(longlong *)this + 0x188))(this,param_1,0,CONCAT71(in_register_00000089,param_3),0);
  uVar1 = (**(code **)(*(longlong *)this + 0x150))(this);
  (**(code **)(**(longlong **)param_1 + 0x560))(*(longlong **)param_1,(uVar1 & 1) != 0);
  OdDgDatabase::readFile
            (*(OdDgDatabase **)param_1,(OdString *)CONCAT44(in_register_00000084,param_2),
             (FileShareMode)CONCAT71(in_register_00000089,param_3),in_stack_00000028);
  return param_1;
}



/* ==== 180115e80 dgnInHeader ==== */

/* public: virtual enum OdResult __cdecl CDGComplexGeneral::dgnInHeader(class OdDgFiler * __ptr64)
   __ptr64 */

OdResult __thiscall CDGComplexGeneral::dgnInHeader(CDGComplexGeneral *this,OdDgFiler *param_1)

{
  int iVar1;
  Bool BVar2;
  undefined1 local_res8 [8];
  
                    /* 0x115e80  7817
                       ?dgnInHeader@CDGComplexGeneral@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z */
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar1 == 6) {
    (**(code **)(*(longlong *)param_1 + 0xf0))(param_1,local_res8);
    if (*(longlong *)(this + 0x58) != 0) {
      FUN_1801d0e00(this,local_res8);
    }
  }
  (*(code *)**(undefined8 **)(this + 0xb0))(this + 0xb0,param_1);
  BVar2 = CDGElmHeader::IsComplexHeader((CDGElmHeader *)(this + 0xb0));
  if (BVar2 != 0) {
    (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  }
  return 0;
}



/* ==== 180115f00 dgnInHeader ==== */

/* public: virtual enum OdResult __cdecl CDGElementGeneral::dgnInHeader(class OdDgFiler * __ptr64)
   __ptr64 */

OdResult __thiscall CDGElementGeneral::dgnInHeader(CDGElementGeneral *this,OdDgFiler *param_1)

{
  int iVar1;
  undefined1 local_res8 [8];
  
                    /* 0x115f00  7818
                       ?dgnInHeader@CDGElementGeneral@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z */
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar1 == 6) {
    (**(code **)(*(longlong *)param_1 + 0xf0))(param_1,local_res8);
    if (*(longlong *)(this + 0x58) != 0) {
      FUN_1801d0e00(this,local_res8);
    }
  }
  (*(code *)**(undefined8 **)(this + 0xb0))(this + 0xb0,param_1);
  return 0;
}



/* ==== 180115f60 dgnInLinkages ==== */

/* public: virtual enum OdResult __cdecl CDGElementGeneral::dgnInLinkages(class OdDgFiler *
   __ptr64,unsigned __int64) __ptr64 */

OdResult __thiscall
CDGElementGeneral::dgnInLinkages(CDGElementGeneral *this,OdDgFiler *param_1,__uint64 param_2)

{
  int *piVar1;
  CDGElementGeneral *pCVar2;
  longlong lVar3;
  double dVar4;
  ulong uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  char cVar12;
  short sVar13;
  ushort uVar14;
  undefined4 uVar15;
  int iVar16;
  OdRxClass *pOVar17;
  longlong *plVar18;
  undefined4 *puVar19;
  longlong *plVar20;
  OdGiAuxDataForDgDatabase *this_00;
  longlong *plVar21;
  undefined8 uVar22;
  OdString *pOVar23;
  OdDgGradientFill *pOVar24;
  OdRxClass *pOVar25;
  code *pcVar26;
  code *pcVar27;
  ulonglong uVar28;
  uint uVar29;
  uint uVar30;
  ulonglong uVar31;
  uint local_res20;
  ulonglong in_stack_fffffffffffffd78;
  code *local_278;
  char local_270;
  OdError_NotThatKindOfClass local_268 [8];
  code *local_260;
  OdError local_258 [8];
  longlong *local_250;
  code *local_248;
  code *local_240;
  longlong *local_238;
  longlong *local_230;
  code *local_228;
  undefined1 local_220 [16];
  longlong *local_210;
  longlong *local_200;
  longlong *local_1f8;
  longlong *local_1f0;
  OdError_InvalidIndex local_1e8 [8];
  OdError_InvalidIndex local_1e0 [8];
  OdError_InvalidIndex local_1d8 [8];
  OdError_InvalidIndex local_1d0 [8];
  longlong *local_1c8;
  OdString local_1c0 [8];
  OdError_InvalidIndex local_1b8 [8];
  OdError_InvalidIndex local_1b0 [8];
  OdError_InvalidIndex local_1a8 [8];
  OdError_InvalidIndex local_1a0 [8];
  OdError_InvalidIndex local_198 [8];
  longlong *local_190;
  OdString local_188 [8];
  OdError_InvalidIndex local_180 [8];
  longlong *local_178;
  longlong *local_170;
  longlong *local_168;
  longlong *local_160;
  longlong *local_158;
  OdError_InvalidIndex local_150 [8];
  OdError_InvalidIndex local_148 [8];
  OdError_InvalidIndex local_140 [8];
  OdError_InvalidIndex local_138 [8];
  OdError_InvalidIndex local_130 [8];
  OdError_InvalidIndex local_128 [8];
  OdError_InvalidIndex local_120 [8];
  OdError_InvalidIndex local_118 [8];
  OdError_InvalidIndex local_110 [8];
  OdError_InvalidIndex local_108 [8];
  undefined4 local_100;
  uint uStack_fc;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined4 local_d0;
  uint uStack_cc;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  OdDgGradientFill local_a0 [104];
  
                    /* 0x115f60  7820
                       ?dgnInLinkages@CDGElementGeneral@@UEAA?AW4OdResult@@PEAVOdDgFiler@@_K@Z */
  uVar30 = *(uint *)(this + 200);
  uVar29 = *(uint *)(this + 0xc4);
  if (uVar29 < uVar30) {
    OdError::OdError(local_258,5);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_258,(ThrowInfo *)&DAT_180de52b8);
  }
  if (uVar30 < uVar29) {
    uVar5 = (uVar29 - uVar30) * 2;
    local_240 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1800150c0(&local_240,uVar5);
    (**(code **)(*(longlong *)param_1 + 0x78))(param_1,(int)param_2 + uVar30 * 2 + 4,0);
    FUN_18000d0b0(&local_240);
    pcVar26 = (code *)0x0;
    if (*(int *)(local_240 + -4) != 0) {
      pcVar26 = local_240;
    }
    (**(code **)(*(longlong *)param_1 + 0x90))(param_1,pcVar26,uVar5);
    FUN_18000d0b0(&local_240);
    pcVar26 = local_240;
    pcVar27 = (code *)0x0;
    if (*(int *)(local_240 + -4) != 0) {
      pcVar27 = local_240;
    }
    OdDgLinkageData::readData((OdDgLinkageData *)(this + 0x20),(uchar *)pcVar27,uVar5);
    pcVar26 = pcVar26 + -0x10;
    LOCK();
    iVar16 = *(int *)pcVar26;
    *(int *)pcVar26 = *(int *)pcVar26 + -1;
    UNLOCK();
    if ((iVar16 == 1) && (pcVar26 != g_empty_array_buffer_exref)) {
      odrxFree();
    }
  }
  if ((longlong *)**(longlong **)(this + 0x20) == *(longlong **)(this + 0x20)) {
    *(undefined4 *)(this + 0x114) = 0;
    *(undefined8 *)(this + 0x1d0) = 0;
    *(undefined8 *)(this + 0x148) = 0x3ff0000000000000;
    local_100 = 0;
    uStack_f8 = 0x3ff0000000000000;
    uStack_f0 = 0x3ff0000000000000;
    uStack_e8 = 0;
    uStack_e0 = 0;
    *(ulonglong *)(this + 0x118) = (ulonglong)uStack_fc << 0x20;
    *(undefined8 *)(this + 0x120) = 0x3ff0000000000000;
    *(undefined4 *)(this + 0x128) = 0;
    *(undefined4 *)(this + 300) = 0x3ff00000;
    *(undefined4 *)(this + 0x130) = 0;
    *(undefined4 *)(this + 0x134) = 0;
    *(undefined8 *)(this + 0x138) = 0;
    *(undefined8 *)(this + 0x140) = 0;
    if (*(int *)(*(longlong *)(this + 0x108) + -4) != 0) {
      FUN_180114660();
    }
    this[0x158] = (CDGElementGeneral)0x0;
    *(undefined4 *)(this + 0x1c8) = 0;
    *(undefined4 *)(this + 0x15c) = 0x20000ff;
    *(undefined8 *)(this + 0x160) = 0;
    *(undefined8 *)(this + 0x168) = 0;
    *(undefined8 *)(this + 0x170) = 0;
    *(undefined8 *)(this + 0x188) = 0;
    *(undefined4 *)(this + 400) = 0;
    *(undefined4 *)(this + 0x178) = 0xffffffff;
  }
  else {
    *(undefined4 *)(this + 0x114) = 0;
    local_278 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1801cb730(this,0x56e9,&local_278);
    if (*(int *)(local_278 + -4) != 0) {
      LOCK();
      pcVar26 = local_278 + -0x10;
      iVar16 = *(int *)pcVar26;
      *(int *)pcVar26 = *(int *)pcVar26;
      UNLOCK();
      if (1 < iVar16) {
        in_stack_fffffffffffffd78 = CONCAT71((int7)(in_stack_fffffffffffffd78 >> 8),1);
        FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,in_stack_fffffffffffffd78);
      }
      local_210 = (longlong *)0x0;
      plVar20 = *(longlong **)local_278;
      plVar18 = local_210;
      if (plVar20 != (longlong *)0x0) {
        lVar3 = *plVar20;
        pOVar17 = OdDgInfiniteLineLinkage::desc();
        plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
        if (plVar18 == (longlong *)0x0) {
          pOVar17 = OdDgInfiniteLineLinkage::desc();
          pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)local_258,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_258,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_210 = plVar18;
      plVar20 = local_210;
      if (local_210 != (longlong *)0x0) {
        uVar15 = (**(code **)(*local_210 + 0x78))(local_210);
        *(undefined4 *)(this + 0x114) = uVar15;
        (**(code **)(*plVar20 + 0x28))(plVar20);
      }
    }
    *(undefined8 *)(this + 0x1d0) = 0;
    FUN_180114660(&local_278);
    FUN_1801cb730(this,0x56d4,&local_278);
    if (*(int *)(local_278 + -4) != 0) {
      LOCK();
      pcVar26 = local_278 + -0x10;
      iVar16 = *(int *)pcVar26;
      *(int *)pcVar26 = *(int *)pcVar26;
      UNLOCK();
      if (1 < iVar16) {
        in_stack_fffffffffffffd78 = CONCAT71((int7)(in_stack_fffffffffffffd78 >> 8),1);
        FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,in_stack_fffffffffffffd78);
      }
      local_200 = (longlong *)0x0;
      plVar20 = *(longlong **)local_278;
      plVar18 = local_200;
      if (plVar20 != (longlong *)0x0) {
        lVar3 = *plVar20;
        pOVar17 = OdDgThicknessLinkage::desc();
        plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
        if (plVar18 == (longlong *)0x0) {
          pOVar17 = OdDgThicknessLinkage::desc();
          pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)local_258,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_258,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_200 = plVar18;
      plVar20 = local_200;
      if (local_200 != (longlong *)0x0) {
        uVar22 = (**(code **)(*local_200 + 0x78))(local_200);
        *(undefined8 *)(this + 0x1d0) = uVar22;
        puVar19 = (undefined4 *)(**(code **)(*plVar20 + 0x88))(plVar20,&local_100);
        uVar15 = puVar19[1];
        uVar6 = puVar19[2];
        uVar7 = puVar19[3];
        *(undefined4 *)(this + 0x1d8) = *puVar19;
        *(undefined4 *)(this + 0x1dc) = uVar15;
        *(undefined4 *)(this + 0x1e0) = uVar6;
        *(undefined4 *)(this + 0x1e4) = uVar7;
        *(undefined8 *)(this + 0x1e8) = *(undefined8 *)(puVar19 + 4);
        (**(code **)(*plVar20 + 0x28))(plVar20);
      }
    }
    pCVar2 = this + 0x108;
    FUN_180114660(pCVar2);
    FUN_180114660(&local_278);
    FUN_1801cb730(this,0x7d28,&local_278);
    uVar29 = 0;
    bVar8 = false;
    uVar28 = 0;
    local_res20 = 0;
    uVar30 = *(uint *)(local_278 + -4);
    bVar9 = false;
    if (uVar30 != 0) {
      do {
        bVar8 = bVar9;
        if (uVar30 <= (uint)uVar28) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_1d0);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1d0,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pcVar26 = local_278 + -0x10;
        iVar16 = *(int *)pcVar26;
        *(int *)pcVar26 = *(int *)pcVar26;
        UNLOCK();
        if (1 < iVar16) {
          in_stack_fffffffffffffd78 = CONCAT71((int7)(in_stack_fffffffffffffd78 >> 8),1);
          FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,in_stack_fffffffffffffd78);
        }
        pcVar26 = local_278;
        pOVar17 = OdDgPatternLinkage::desc();
        plVar20 = (longlong *)(**(code **)(**(longlong **)(pcVar26 + uVar28 * 8) + 0x18))();
        cVar12 = (**(code **)(*plVar20 + 0x60))(plVar20,pOVar17);
        if (cVar12 != '\0') {
          if (*(uint *)(local_278 + -4) <= (uint)uVar28) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_1d8);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1d8,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pcVar26 = local_278 + -0x10;
          iVar16 = *(int *)pcVar26;
          *(int *)pcVar26 = *(int *)pcVar26;
          UNLOCK();
          if (1 < iVar16) {
            in_stack_fffffffffffffd78 = CONCAT71((int7)(in_stack_fffffffffffffd78 >> 8),1);
            FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,in_stack_fffffffffffffd78);
          }
          local_238 = (longlong *)0x0;
          plVar20 = *(longlong **)(local_278 + uVar28 * 8);
          plVar18 = local_238;
          if (plVar20 != (longlong *)0x0) {
            lVar3 = *plVar20;
            pOVar17 = OdDgPatternLinkage::desc();
            plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
            if (plVar18 == (longlong *)0x0) {
              pOVar17 = OdDgPatternLinkage::desc();
              pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
              OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                        ((OdError_NotThatKindOfClass *)local_258,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_258,(ThrowInfo *)&DAT_180de5310);
            }
          }
          local_238 = plVar18;
          plVar20 = local_238;
          (**(code **)(*local_238 + 0x78))(local_238,&local_250);
          if (local_250 != (longlong *)0x0) {
            iVar16 = (**(code **)(*(longlong *)param_1 + 0x58))();
            if (iVar16 == 2) {
              in_stack_fffffffffffffd78 = in_stack_fffffffffffffd78 & 0xffffffff00000000;
              this_00 = (OdGiAuxDataForDgDatabase *)
                        __RTDynamicCast(local_250,0,&OdDgHatchPattern::RTTI_Type_Descriptor,
                                        &OdDgHatchPatternAccessor::RTTI_Type_Descriptor,
                                        in_stack_fffffffffffffd78);
              if (this_00 != (OdGiAuxDataForDgDatabase *)0x0) {
                OdGiAuxDataForDgDatabase::setAnnotationScale(this_00,*(double *)(this + 0x100));
              }
            }
            iVar16 = (**(code **)(*local_250 + 0x58))();
            if (iVar16 == 2) {
              local_260 = g_empty_array_buffer_exref + 0x10;
              LOCK();
              *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
              UNLOCK();
              FUN_1801cb730(this,0x56d0);
              uVar28 = 0;
              if (*(int *)(local_260 + -4) != 0) {
                if (*(int *)(local_260 + -4) == 0) {
                  OdError_InvalidIndex::OdError_InvalidIndex(local_1e0);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(local_1e0,(ThrowInfo *)&DAT_180de5370);
                }
                do {
                  LOCK();
                  pcVar26 = local_260 + -0x10;
                  iVar16 = *(int *)pcVar26;
                  *(int *)pcVar26 = *(int *)pcVar26;
                  UNLOCK();
                  if (1 < iVar16) {
                    in_stack_fffffffffffffd78 = CONCAT71((int7)(in_stack_fffffffffffffd78 >> 8),1);
                    FUN_18000cd30(&local_260,*(undefined4 *)(local_260 + -8),0,0,
                                  in_stack_fffffffffffffd78);
                  }
                  pcVar26 = local_260;
                  pOVar17 = OdDgDepLinkageElementId::desc();
                  plVar20 = (longlong *)
                            (**(code **)(**(longlong **)(pcVar26 + uVar28 * 8) + 0x18))();
                  cVar12 = (**(code **)(*plVar20 + 0x60))(plVar20,pOVar17);
                  if (cVar12 != '\0') {
                    if (*(uint *)(local_260 + -4) <= (uint)uVar28) {
                      OdError_InvalidIndex::OdError_InvalidIndex(local_1e8);
                    /* WARNING: Subroutine does not return */
                      _CxxThrowException(local_1e8,(ThrowInfo *)&DAT_180de5370);
                    }
                    LOCK();
                    pcVar26 = local_260 + -0x10;
                    iVar16 = *(int *)pcVar26;
                    *(int *)pcVar26 = *(int *)pcVar26;
                    UNLOCK();
                    if (1 < iVar16) {
                      in_stack_fffffffffffffd78 = CONCAT71((int7)(in_stack_fffffffffffffd78 >> 8),1)
                      ;
                      FUN_18000cd30(&local_260,*(undefined4 *)(local_260 + -8),0,0,
                                    in_stack_fffffffffffffd78);
                    }
                    local_1f8 = (longlong *)0x0;
                    plVar20 = *(longlong **)(local_260 + uVar28 * 8);
                    plVar18 = local_1f8;
                    if (plVar20 != (longlong *)0x0) {
                      lVar3 = *plVar20;
                      pOVar17 = OdDgDepLinkageElementId::desc();
                      plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
                      if (plVar18 == (longlong *)0x0) {
                        pOVar17 = OdDgDepLinkageElementId::desc();
                        pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
                        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                                  ((OdError_NotThatKindOfClass *)local_258,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
                        _CxxThrowException(local_258,(ThrowInfo *)&DAT_180de5310);
                      }
                    }
                    local_1f8 = plVar18;
                    plVar20 = local_1f8;
                    sVar13 = (**(code **)(*local_1f8 + 0x78))(local_1f8);
                    if (((sVar13 == 0x2714) &&
                        (uVar14 = (**(code **)(*plVar20 + 0x88))(plVar20), uVar14 == uVar29)) &&
                       (iVar16 = (**(code **)(*plVar20 + 0xf0))(plVar20), plVar18 = local_250,
                       iVar16 != 0)) {
                      local_1f0 = (longlong *)0x0;
                      plVar21 = local_1f0;
                      if (local_250 != (longlong *)0x0) {
                        lVar3 = *local_250;
                        pOVar17 = OdDgSymbolHatchPattern::desc();
                        plVar21 = (longlong *)(**(code **)(lVar3 + 8))(plVar18,pOVar17);
                        if (plVar21 == (longlong *)0x0) {
                          pOVar17 = OdDgSymbolHatchPattern::desc();
                          pOVar25 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
                          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                                    (local_268,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
                          _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
                        }
                      }
                      local_1f0 = plVar21;
                      plVar18 = local_1f0;
                      lVar3 = *local_1f0;
                      uVar22 = (**(code **)(*plVar20 + 0xf8))(plVar20,0);
                      (**(code **)(lVar3 + 0x238))(plVar18,uVar22);
                      (**(code **)(*plVar18 + 0x28))(plVar18);
                    }
                    (**(code **)(*plVar20 + 0x28))(plVar20);
                  }
                  uVar30 = (uint)uVar28 + 1;
                  uVar28 = (ulonglong)uVar30;
                } while (uVar30 < *(uint *)(local_260 + -4));
              }
              uVar29 = uVar29 + 1;
              FUN_1800144b0(local_260 + -0x10);
              uVar28 = (ulonglong)local_res20;
              plVar20 = local_238;
            }
            else {
              iVar16 = (**(code **)(*local_250 + 0x58))();
              if (iVar16 == 3) {
                bVar8 = true;
              }
            }
            FUN_180122a80(pCVar2,&local_250);
          }
          if (local_250 != (longlong *)0x0) {
            (**(code **)(*local_250 + 0x28))();
            local_250 = (longlong *)0x0;
          }
          (**(code **)(*plVar20 + 0x28))(plVar20);
        }
        local_res20 = (int)uVar28 + 1;
        uVar28 = (ulonglong)local_res20;
        uVar30 = *(uint *)(local_278 + -4);
        bVar9 = bVar8;
      } while (local_res20 < uVar30);
    }
    this[0x110] = (CDGElementGeneral)0x0;
    if (bVar8) {
      local_248 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      FUN_180114660(&local_278);
      FUN_1801cb730(this,0x56d2,&local_278);
      uVar28 = 0;
      uVar30 = *(uint *)(local_278 + -4);
      if (uVar30 != 0) {
        do {
          if (uVar30 <= (uint)uVar28) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_1b8);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pcVar26 = local_278 + -0x10;
          iVar16 = *(int *)pcVar26;
          *(int *)pcVar26 = *(int *)pcVar26;
          UNLOCK();
          if (1 < iVar16) {
            FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
          }
          local_1c8 = (longlong *)0x0;
          plVar20 = *(longlong **)(local_278 + uVar28 * 8);
          plVar18 = local_1c8;
          if (plVar20 != (longlong *)0x0) {
            lVar3 = *plVar20;
            pOVar17 = OdDgStringLinkage::desc();
            plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
            if (plVar18 == (longlong *)0x0) {
              pOVar17 = OdDgStringLinkage::desc();
              pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
              OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_268,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
            }
          }
          local_1c8 = plVar18;
          plVar20 = local_1c8;
          if ((local_1c8 != (longlong *)0x0) &&
             (iVar16 = (**(code **)(*local_1c8 + 0x78))(local_1c8), iVar16 == 0x26)) {
            uVar22 = (**(code **)(*plVar20 + 0x88))(plVar20,local_1c0);
            FUN_18010fa30(&local_248,uVar22);
            OdString::~OdString(local_1c0);
          }
          if (plVar20 != (longlong *)0x0) {
            (**(code **)(*plVar20 + 0x28))(plVar20);
          }
          uVar29 = (uint)uVar28 + 1;
          uVar28 = (ulonglong)uVar29;
          uVar30 = *(uint *)(local_278 + -4);
        } while (uVar29 < uVar30);
      }
      pcVar26 = local_248 + -4;
      pcVar27 = local_248;
      if (*(uint *)pcVar26 != 0) {
        uVar31 = 0;
        uVar28 = 0;
        if (*(int *)(*(longlong *)pCVar2 + -4) != 0) {
          do {
            uVar30 = (uint)uVar28;
            if (*(uint *)(*(longlong *)pCVar2 + -4) <= uVar30) {
              OdError_InvalidIndex::OdError_InvalidIndex(local_1a0);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_1a0,(ThrowInfo *)&DAT_180de5370);
            }
            LOCK();
            piVar1 = (int *)(*(longlong *)pCVar2 + -0x10);
            iVar16 = *piVar1;
            *piVar1 = *piVar1;
            UNLOCK();
            if (1 < iVar16) {
              FUN_18000cd30(pCVar2,*(undefined4 *)(*(longlong *)pCVar2 + -8),0,0,1);
            }
            iVar16 = (**(code **)(**(longlong **)(*(longlong *)pCVar2 + uVar28 * 8) + 0x58))();
            pcVar27 = local_248;
            if (iVar16 == 3) {
              if (*(uint *)(*(longlong *)pCVar2 + -4) <= uVar30) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_1a8);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_1a8,(ThrowInfo *)&DAT_180de5370);
              }
              LOCK();
              piVar1 = (int *)(*(longlong *)pCVar2 + -0x10);
              iVar16 = *piVar1;
              *piVar1 = *piVar1;
              UNLOCK();
              if (1 < iVar16) {
                FUN_18000cd30(pCVar2,*(undefined4 *)(*(longlong *)pCVar2 + -8),0,0,1);
              }
              local_230 = (longlong *)0x0;
              plVar20 = *(longlong **)(*(longlong *)pCVar2 + uVar28 * 8);
              plVar18 = local_230;
              if (plVar20 != (longlong *)0x0) {
                lVar3 = *plVar20;
                pOVar17 = OdDgDWGHatchPattern::desc();
                plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
                if (plVar18 == (longlong *)0x0) {
                  pOVar17 = OdDgDWGHatchPattern::desc();
                  pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
                  OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_268,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
                }
              }
              local_230 = plVar18;
              if (*(uint *)pcVar26 <= (uint)uVar31) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_1b0);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_1b0,(ThrowInfo *)&DAT_180de5370);
              }
              LOCK();
              pcVar26 = local_248 + -0x10;
              iVar16 = *(int *)pcVar26;
              *(int *)pcVar26 = *(int *)pcVar26;
              UNLOCK();
              if (1 < iVar16) {
                FUN_18010dd70(&local_248,*(undefined4 *)(local_248 + -8),0,0,1);
              }
              plVar20 = local_230;
              pcVar27 = local_248;
              (**(code **)(*local_230 + 0x188))(local_230,local_248 + uVar31 * 8);
              uVar29 = (uint)uVar31 + 1;
              uVar31 = (ulonglong)uVar29;
              pcVar26 = pcVar27 + -4;
              if (*(uint *)pcVar26 <= uVar29) {
                if (plVar20 != (longlong *)0x0) {
                  (**(code **)(*plVar20 + 0x28))(plVar20);
                }
                break;
              }
              (**(code **)(*plVar20 + 0x28))(plVar20);
            }
            uVar28 = (ulonglong)(uVar30 + 1);
          } while (uVar30 + 1 < *(uint *)(*(longlong *)pCVar2 + -4));
        }
      }
      FUN_18010fc20(pcVar27 + -0x10);
    }
    *(undefined8 *)(this + 0x148) = 0x3ff0000000000000;
    uVar28 = 0;
    local_d0 = 0;
    uStack_c8 = 0x3ff0000000000000;
    uStack_c0 = 0x3ff0000000000000;
    uStack_b8 = 0;
    uStack_b0 = 0;
    *(ulonglong *)(this + 0x118) = (ulonglong)uStack_cc << 0x20;
    *(undefined8 *)(this + 0x120) = 0x3ff0000000000000;
    *(undefined4 *)(this + 0x128) = 0;
    *(undefined4 *)(this + 300) = 0x3ff00000;
    *(undefined4 *)(this + 0x130) = 0;
    *(undefined4 *)(this + 0x134) = 0;
    *(undefined8 *)(this + 0x138) = 0;
    *(undefined8 *)(this + 0x140) = 0;
    if (*(int *)(this + 0xbc) != 0x24) {
      local_228 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      (**(code **)(*(longlong *)this + 800))(this,this + 0x118,this + 0x148,local_220,&local_228);
      pcVar26 = local_228 + -0x10;
      LOCK();
      iVar16 = *(int *)pcVar26;
      *(int *)pcVar26 = *(int *)pcVar26 + -1;
      UNLOCK();
      if ((iVar16 == 1) && (pcVar26 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
    }
    this[0x158] = (CDGElementGeneral)0x0;
    *(undefined4 *)(this + 0x1c8) = 0;
    *(undefined4 *)(this + 0x15c) = 0x20000ff;
    *(undefined8 *)(this + 0x160) = 0;
    *(undefined8 *)(this + 0x168) = 0;
    *(undefined8 *)(this + 0x170) = 0;
    *(undefined8 *)(this + 0x188) = 0;
    *(undefined4 *)(this + 400) = 0;
    *(undefined4 *)(this + 0x178) = 0xffffffff;
    LOCK();
    pcVar26 = local_278 + -0x10;
    iVar16 = *(int *)pcVar26;
    *(int *)pcVar26 = *(int *)pcVar26;
    UNLOCK();
    if (1 < iVar16) {
      FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
    }
    uVar30 = *(uint *)(local_278 + -4);
    if (uVar30 != 0) {
      pcVar26 = local_278 + (ulonglong)uVar30 * 8;
      uVar29 = uVar30;
      do {
        uVar29 = uVar29 - 1;
        pcVar26 = pcVar26 + -8;
        if (*(longlong **)pcVar26 != (longlong *)0x0) {
          (**(code **)(**(longlong **)pcVar26 + 0x28))();
          *(longlong *)pcVar26 = 0;
        }
      } while (uVar29 != 0);
    }
    *(uint *)(local_278 + -4) = *(int *)(local_278 + -4) - uVar30;
    FUN_1801cb730(this,0x4f5a,&local_278);
    if (*(int *)(local_278 + -4) != 0) {
      if (*(int *)(local_278 + -4) == 0) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_180);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_180,(ThrowInfo *)&DAT_180de5370);
      }
      do {
        LOCK();
        pcVar26 = local_278 + -0x10;
        iVar16 = *(int *)pcVar26;
        *(int *)pcVar26 = *(int *)pcVar26;
        UNLOCK();
        if (1 < iVar16) {
          FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
        }
        pcVar26 = local_278;
        pOVar17 = OdDgMaterialLinkage::desc();
        plVar20 = (longlong *)(**(code **)(**(longlong **)(pcVar26 + uVar28 * 8) + 0x18))();
        cVar12 = (**(code **)(*plVar20 + 0x60))(plVar20,pOVar17);
        if (cVar12 != '\0') {
          if (*(int *)(local_278 + -4) == 0) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_198);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_198,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pcVar26 = local_278 + -0x10;
          iVar16 = *(int *)pcVar26;
          *(int *)pcVar26 = *(int *)pcVar26;
          UNLOCK();
          if (1 < iVar16) {
            FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
          }
          local_190 = (longlong *)0x0;
          plVar20 = *(longlong **)local_278;
          plVar18 = local_190;
          if (plVar20 != (longlong *)0x0) {
            lVar3 = *plVar20;
            pOVar17 = OdDgMaterialLinkage::desc();
            plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
            if (plVar18 == (longlong *)0x0) {
              pOVar17 = OdDgMaterialLinkage::desc();
              pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
              OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_268,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
            }
          }
          local_190 = plVar18;
          plVar20 = local_190;
          pOVar23 = (OdString *)(**(code **)(*local_190 + 0x80))(local_190,local_188);
          OdString::operator=((OdString *)(this + 0x180),pOVar23);
          OdString::~OdString(local_188);
          uVar14 = (**(code **)(*plVar20 + 0x90))(plVar20);
          *(uint *)(this + 0x188) = (uint)uVar14;
          (**(code **)(*plVar20 + 0x28))(plVar20);
          break;
        }
        uVar30 = (int)uVar28 + 1;
        uVar28 = (ulonglong)uVar30;
      } while (uVar30 < *(uint *)(local_278 + -4));
    }
    LOCK();
    pcVar26 = local_278 + -0x10;
    iVar16 = *(int *)pcVar26;
    *(int *)pcVar26 = *(int *)pcVar26;
    UNLOCK();
    if (1 < iVar16) {
      FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
    }
    uVar30 = *(uint *)(local_278 + -4);
    if (uVar30 != 0) {
      pcVar26 = local_278 + (ulonglong)uVar30 * 8;
      uVar29 = uVar30;
      do {
        uVar29 = uVar29 - 1;
        pcVar26 = pcVar26 + -8;
        if (*(longlong **)pcVar26 != (longlong *)0x0) {
          (**(code **)(**(longlong **)pcVar26 + 0x28))();
          *(longlong *)pcVar26 = 0;
        }
      } while (uVar29 != 0);
    }
    *(uint *)(local_278 + -4) = *(int *)(local_278 + -4) - uVar30;
    FUN_1801cb730(this,0x41,&local_278);
    bVar9 = false;
    bVar10 = false;
    bVar11 = false;
    local_270 = '\0';
    bVar8 = false;
    uVar28 = 0;
    uVar30 = *(uint *)(local_278 + -4);
    if (uVar30 != 0) {
      do {
        uVar29 = (uint)uVar28;
        if (uVar30 <= uVar29) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_108);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_108,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pcVar26 = local_278 + -0x10;
        iVar16 = *(int *)pcVar26;
        *(int *)pcVar26 = *(int *)pcVar26;
        UNLOCK();
        if (1 < iVar16) {
          FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
        }
        pcVar26 = local_278;
        pOVar17 = OdDgTransparencyLinkage::desc();
        plVar20 = (longlong *)(**(code **)(**(longlong **)(pcVar26 + uVar28 * 8) + 0x18))();
        cVar12 = (**(code **)(*plVar20 + 0x60))(plVar20,pOVar17);
        if (cVar12 == '\0') {
          if (*(uint *)(local_278 + -4) <= uVar29) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_110);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_110,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pcVar26 = local_278 + -0x10;
          iVar16 = *(int *)pcVar26;
          *(int *)pcVar26 = *(int *)pcVar26;
          UNLOCK();
          if (1 < iVar16) {
            FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
          }
          pcVar26 = local_278;
          pOVar17 = OdDgInternalMaterialLinkage::desc();
          plVar20 = (longlong *)(**(code **)(**(longlong **)(pcVar26 + uVar28 * 8) + 0x18))();
          cVar12 = (**(code **)(*plVar20 + 0x60))(plVar20,pOVar17);
          if (cVar12 == '\0') {
            if (*(uint *)(local_278 + -4) <= uVar29) {
              OdError_InvalidIndex::OdError_InvalidIndex(local_118);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_118,(ThrowInfo *)&DAT_180de5370);
            }
            LOCK();
            pcVar26 = local_278 + -0x10;
            iVar16 = *(int *)pcVar26;
            *(int *)pcVar26 = *(int *)pcVar26;
            UNLOCK();
            if (1 < iVar16) {
              FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
            }
            pcVar26 = local_278;
            pOVar17 = OdDgGradientFillLinkage::desc();
            plVar20 = (longlong *)(**(code **)(**(longlong **)(pcVar26 + uVar28 * 8) + 0x18))();
            cVar12 = (**(code **)(*plVar20 + 0x60))(plVar20,pOVar17);
            if (cVar12 == '\0') {
              if (*(uint *)(local_278 + -4) <= uVar29) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_120);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_120,(ThrowInfo *)&DAT_180de5370);
              }
              LOCK();
              pcVar26 = local_278 + -0x10;
              iVar16 = *(int *)pcVar26;
              *(int *)pcVar26 = *(int *)pcVar26;
              UNLOCK();
              if (1 < iVar16) {
                FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
              }
              pcVar26 = local_278;
              pOVar17 = OdDgFillColorLinkage::desc();
              plVar20 = (longlong *)(**(code **)(**(longlong **)(pcVar26 + uVar28 * 8) + 0x18))();
              cVar12 = (**(code **)(*plVar20 + 0x60))(plVar20,pOVar17);
              if (cVar12 == '\0') {
                if (*(uint *)(local_278 + -4) <= uVar29) {
                  OdError_InvalidIndex::OdError_InvalidIndex(local_128);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(local_128,(ThrowInfo *)&DAT_180de5370);
                }
                LOCK();
                pcVar26 = local_278 + -0x10;
                iVar16 = *(int *)pcVar26;
                *(int *)pcVar26 = *(int *)pcVar26;
                UNLOCK();
                if (1 < iVar16) {
                  FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
                }
                pcVar26 = local_278;
                pOVar17 = OdDgDisplayStyleLinkage::desc();
                plVar20 = (longlong *)(**(code **)(**(longlong **)(pcVar26 + uVar28 * 8) + 0x18))();
                cVar12 = (**(code **)(*plVar20 + 0x60))(plVar20,pOVar17);
                if (cVar12 != '\0') {
                  if (*(uint *)(local_278 + -4) <= uVar29) {
                    OdError_InvalidIndex::OdError_InvalidIndex(local_130);
                    /* WARNING: Subroutine does not return */
                    _CxxThrowException(local_130,(ThrowInfo *)&DAT_180de5370);
                  }
                  LOCK();
                  pcVar26 = local_278 + -0x10;
                  iVar16 = *(int *)pcVar26;
                  *(int *)pcVar26 = *(int *)pcVar26;
                  UNLOCK();
                  if (1 < iVar16) {
                    FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
                  }
                  local_158 = (longlong *)0x0;
                  plVar20 = *(longlong **)(local_278 + uVar28 * 8);
                  plVar18 = local_158;
                  if (plVar20 != (longlong *)0x0) {
                    lVar3 = *plVar20;
                    pOVar17 = OdDgDisplayStyleLinkage::desc();
                    plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
                    if (plVar18 == (longlong *)0x0) {
                      pOVar17 = OdDgDisplayStyleLinkage::desc();
                      pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
                      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                                (local_268,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
                      _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
                    }
                  }
                  local_158 = plVar18;
                  plVar20 = local_158;
                  uVar15 = (**(code **)(*local_158 + 0x80))(local_158);
                  *(undefined4 *)(this + 0x178) = uVar15;
                  (**(code **)(*plVar20 + 0x28))(plVar20);
                }
              }
              else if (!bVar9) {
                *(undefined4 *)(this + 0x18c) = 1;
                if (*(uint *)(local_278 + -4) <= uVar29) {
                  OdError_InvalidIndex::OdError_InvalidIndex(local_138);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(local_138,(ThrowInfo *)&DAT_180de5370);
                }
                LOCK();
                pcVar26 = local_278 + -0x10;
                iVar16 = *(int *)pcVar26;
                *(int *)pcVar26 = *(int *)pcVar26;
                UNLOCK();
                if (1 < iVar16) {
                  FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
                }
                local_160 = (longlong *)0x0;
                plVar20 = *(longlong **)(local_278 + uVar28 * 8);
                plVar18 = local_160;
                if (plVar20 != (longlong *)0x0) {
                  lVar3 = *plVar20;
                  pOVar17 = OdDgFillColorLinkage::desc();
                  plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
                  if (plVar18 == (longlong *)0x0) {
                    pOVar17 = OdDgFillColorLinkage::desc();
                    pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
                    OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                              (local_268,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
                    _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
                  }
                }
                local_160 = plVar18;
                plVar20 = local_160;
                uVar15 = (**(code **)(*local_160 + 0x78))(local_160);
                *(undefined4 *)(this + 400) = uVar15;
                bVar9 = true;
                (**(code **)(*plVar20 + 0x28))(plVar20);
              }
            }
            else if (!bVar9) {
              *(undefined4 *)(this + 0x18c) = 2;
              if (*(uint *)(local_278 + -4) <= uVar29) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_140);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_140,(ThrowInfo *)&DAT_180de5370);
              }
              LOCK();
              pcVar26 = local_278 + -0x10;
              iVar16 = *(int *)pcVar26;
              *(int *)pcVar26 = *(int *)pcVar26;
              UNLOCK();
              if (1 < iVar16) {
                FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
              }
              local_168 = (longlong *)0x0;
              plVar20 = *(longlong **)(local_278 + uVar28 * 8);
              plVar18 = local_168;
              if (plVar20 != (longlong *)0x0) {
                lVar3 = *plVar20;
                pOVar17 = OdDgGradientFillLinkage::desc();
                plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
                if (plVar18 == (longlong *)0x0) {
                  pOVar17 = OdDgGradientFillLinkage::desc();
                  pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
                  OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_268,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
                }
              }
              local_168 = plVar18;
              plVar20 = local_168;
              pOVar24 = (OdDgGradientFill *)(**(code **)(*local_168 + 0xf8))(local_168,local_a0);
              OdDgGradientFill::operator=((OdDgGradientFill *)(this + 0x198),pOVar24);
              OdDgGradientFill::~OdDgGradientFill(local_a0);
              bVar9 = true;
              (**(code **)(*plVar20 + 0x28))(plVar20);
            }
          }
          else {
            if (*(uint *)(local_278 + -4) <= uVar29) {
              OdError_InvalidIndex::OdError_InvalidIndex(local_148);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_148,(ThrowInfo *)&DAT_180de5370);
            }
            LOCK();
            pcVar26 = local_278 + -0x10;
            iVar16 = *(int *)pcVar26;
            *(int *)pcVar26 = *(int *)pcVar26;
            UNLOCK();
            if (1 < iVar16) {
              FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
            }
            local_170 = (longlong *)0x0;
            plVar20 = *(longlong **)(local_278 + uVar28 * 8);
            plVar18 = local_170;
            if (plVar20 != (longlong *)0x0) {
              lVar3 = *plVar20;
              pOVar17 = OdDgInternalMaterialLinkage::desc();
              plVar18 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
              if (plVar18 == (longlong *)0x0) {
                pOVar17 = OdDgInternalMaterialLinkage::desc();
                pOVar25 = (OdRxClass *)(**(code **)(*plVar20 + 0x18))(plVar20);
                OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_268,pOVar25,pOVar17);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
              }
            }
            local_170 = plVar18;
            plVar20 = local_170;
            iVar16 = (**(code **)(*local_170 + 0x88))(local_170);
            if (iVar16 == 0) {
              if (local_270 == '\0') {
                uVar22 = (**(code **)(*plVar20 + 0x78))(plVar20);
                *(undefined8 *)(this + 0x170) = uVar22;
                local_270 = '\x01';
              }
            }
            else if (iVar16 == 1) {
              if (!bVar11) {
                uVar22 = (**(code **)(*plVar20 + 0x78))(plVar20);
                *(undefined8 *)(this + 0x168) = uVar22;
                bVar11 = true;
              }
            }
            else if ((iVar16 == 2) && (!bVar10)) {
              uVar22 = (**(code **)(*plVar20 + 0x78))(plVar20);
              *(undefined8 *)(this + 0x160) = uVar22;
              bVar10 = true;
            }
            (**(code **)(*plVar20 + 0x28))(plVar20);
          }
        }
        else if (!bVar8) {
          if (*(uint *)(local_278 + -4) <= uVar29) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_150);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_150,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pcVar26 = local_278 + -0x10;
          iVar16 = *(int *)pcVar26;
          *(int *)pcVar26 = *(int *)pcVar26;
          UNLOCK();
          if (1 < iVar16) {
            FUN_18000cd30(&local_278,*(undefined4 *)(local_278 + -8),0,0,1);
          }
          plVar20 = *(longlong **)(local_278 + uVar28 * 8);
          if (plVar20 == (longlong *)0x0) {
            local_178 = (longlong *)0x0;
          }
          else {
            lVar3 = *plVar20;
            pOVar17 = OdDgTransparencyLinkage::desc();
            local_178 = (longlong *)(**(code **)(lVar3 + 8))(plVar20,pOVar17);
          }
          plVar20 = local_178;
          if (local_178 != (longlong *)0x0) {
            dVar4 = (double)(**(code **)(*local_178 + 0x78))(local_178);
            dVar4 = 1.0 - dVar4;
            if (0.0 <= dVar4) {
              if (dVar4 <= 1.0) {
                *(uint *)(this + 0x15c) = (int)(dVar4 * 255.0) & 0xffU | 0x2000000;
              }
              else {
                *(undefined4 *)(this + 0x15c) = 0x20000ff;
              }
            }
            else {
              *(undefined4 *)(this + 0x15c) = 0x2000000;
            }
            bVar8 = true;
          }
          if (plVar20 != (longlong *)0x0) {
            (**(code **)(*plVar20 + 0x28))(plVar20);
          }
        }
        uVar28 = (ulonglong)(uVar29 + 1);
        uVar30 = *(uint *)(local_278 + -4);
      } while (uVar29 + 1 < uVar30);
    }
    FUN_1800144b0(local_278 + -0x10);
  }
  return 0;
}



/* ==== 180117790 dgnInXAttributes ==== */

/* public: virtual enum OdResult __cdecl CDGElementGeneral::dgnInXAttributes(class OdDgFiler *
   __ptr64) __ptr64 */

OdResult __thiscall CDGElementGeneral::dgnInXAttributes(CDGElementGeneral *this,OdDgFiler *param_1)

{
  int iVar1;
  
                    /* 0x117790  7824
                       ?dgnInXAttributes@CDGElementGeneral@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z */
  if (param_1 != (OdDgFiler *)0x0) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
    if (iVar1 != 0) {
      (**(code **)(*(longlong *)this + 0x428))(this,1);
    }
  }
  return 0;
}



/* ==== 1801c5980 dgnIn ==== */

/* public: virtual void __cdecl OdDgElement::dgnIn(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgElement::dgnIn(OdDgElement *this,OdDgFiler *param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  OdDgElementId *this_00;
  OdDbHandle *pOVar5;
  ulonglong uVar6;
  undefined1 local_res8 [8];
  
                    /* 0x1c5980  7793  ?dgnIn@OdDgElement@@UEAAXPEAVOdDgFiler@@@Z */
  assertWriteEnabled(this,true,true);
  uVar2 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  iVar3 = (**(code **)(**(longlong **)(this + 8) + 0x108))(*(longlong **)(this + 8),param_1);
  iVar4 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar4 == 9) {
    lVar1 = **(longlong **)(this + 8);
    this_00 = (OdDgElementId *)(**(code **)(*(longlong *)this + 0x120))(this,local_res8);
    pOVar5 = OdDgElementId::getHandle(this_00);
    (**(code **)(lVar1 + 0x30))(*(undefined8 *)(this + 8),*(undefined8 *)pOVar5);
  }
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*(longlong *)this + 0x198))(this,param_1);
    if (iVar3 == 0) {
      uVar6 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
      if ((uVar6 & 1) != 0) {
        (**(code **)(*(longlong *)param_1 + 0x98))(param_1);
      }
                    /* WARNING: Could not recover jumptable at 0x0001801c5a51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(longlong **)(this + 8) + 0x180))(*(longlong **)(this + 8),param_1,uVar2);
      return;
    }
  }
  return;
}



/* ==== 1801c5a70 dgnInFields ==== */

/* public: virtual enum OdResult __cdecl OdDgElement::dgnInFields(class OdDgFiler * __ptr64) __ptr64
    */

OdResult __thiscall OdDgElement::dgnInFields(OdDgElement *this,OdDgFiler *param_1)

{
  OdResult OVar1;
  
                    /* 0x1c5a70  7804  ?dgnInFields@OdDgElement@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z
                        */
  assertWriteEnabled(this,true,true);
                    /* WARNING: Could not recover jumptable at 0x0001801c5aa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OVar1 = (**(code **)(**(longlong **)(this + 8) + 0x120))(*(longlong **)(this + 8),param_1);
  return OVar1;
}



/* ==== 1801e2cc0 dgnInFields ==== */

/* public: void __cdecl OdDgMultilineProfile::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgMultilineProfile::dgnInFields(OdDgMultilineProfile *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
                    /* 0x1e2cc0  7811  ?dgnInFields@OdDgMultilineProfile@@QEAAXPEAVOdDgFiler@@@Z */
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)this = uVar2;
  (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x10) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x14) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x18) = uVar1;
  return;
}



/* ==== 1801e2d50 dgnInFields ==== */

/* public: void __cdecl OdDgHLineSymbology::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgHLineSymbology::dgnInFields(OdDgHLineSymbology *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  
                    /* 0x1e2d50  7806  ?dgnInFields@OdDgHLineSymbology@@QEAAXPEAVOdDgFiler@@@Z
                       0x1e2d50  7812  ?dgnInFields@OdDgMultilineSymbology@@QEAAXPEAVOdDgFiler@@@Z
                        */
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)this = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x10) = uVar1;
  return;
}



/* ==== 1801f4c00 dgnInFields ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual enum OdResult __cdecl ESharedCellInst::dgnInFields(class OdDgFiler * __ptr64)
   __ptr64 */

OdResult __thiscall ESharedCellInst::dgnInFields(ESharedCellInst *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined1 local_98 [128];
  ulonglong local_18;
  
                    /* 0x1f4c00  7799
                       ?dgnInFields@ESharedCellInst@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z */
  local_18 = DAT_180fcd438 ^ (ulonglong)auStack_e8;
  uVar5 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x220) = uVar5;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x224) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x226) = uVar4;
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_b0);
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_c8);
  *(undefined8 *)(this + 0x228) = local_b0;
  *(undefined8 *)(this + 0x230) = uStack_a8;
  *(undefined8 *)(this + 0x238) = local_a0;
  *(undefined4 *)(this + 0x240) = local_c8;
  *(undefined4 *)(this + 0x244) = uStack_c4;
  *(undefined4 *)(this + 0x248) = uStack_c0;
  *(undefined4 *)(this + 0x24c) = uStack_bc;
  *(undefined8 *)(this + 0x250) = local_b8;
  puVar6 = (undefined8 *)FUN_1801f6e10(local_98,param_1);
  uVar3 = puVar6[1];
  *(undefined8 *)(this + 600) = *puVar6;
  *(undefined8 *)(this + 0x260) = uVar3;
  uVar3 = puVar6[3];
  *(undefined8 *)(this + 0x268) = puVar6[2];
  *(undefined8 *)(this + 0x270) = uVar3;
  uVar3 = puVar6[5];
  *(undefined8 *)(this + 0x278) = puVar6[4];
  *(undefined8 *)(this + 0x280) = uVar3;
  uVar3 = puVar6[7];
  *(undefined8 *)(this + 0x288) = puVar6[6];
  *(undefined8 *)(this + 0x290) = uVar3;
  uVar3 = puVar6[9];
  *(undefined8 *)(this + 0x298) = puVar6[8];
  *(undefined8 *)(this + 0x2a0) = uVar3;
  uVar3 = puVar6[0xb];
  *(undefined8 *)(this + 0x2a8) = puVar6[10];
  *(undefined8 *)(this + 0x2b0) = uVar3;
  uVar5 = *(undefined4 *)((longlong)puVar6 + 100);
  uVar1 = *(undefined4 *)(puVar6 + 0xd);
  uVar2 = *(undefined4 *)((longlong)puVar6 + 0x6c);
  *(undefined4 *)(this + 0x2b8) = *(undefined4 *)(puVar6 + 0xc);
  *(undefined4 *)(this + 700) = uVar5;
  *(undefined4 *)(this + 0x2c0) = uVar1;
  *(undefined4 *)(this + 0x2c4) = uVar2;
  uVar5 = *(undefined4 *)((longlong)puVar6 + 0x74);
  uVar1 = *(undefined4 *)(puVar6 + 0xf);
  uVar2 = *(undefined4 *)((longlong)puVar6 + 0x7c);
  *(undefined4 *)(this + 0x2c8) = *(undefined4 *)(puVar6 + 0xe);
  *(undefined4 *)(this + 0x2cc) = uVar5;
  *(undefined4 *)(this + 0x2d0) = uVar1;
  *(undefined4 *)(this + 0x2d4) = uVar2;
  puVar6 = (undefined8 *)(**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_c8);
  uVar3 = puVar6[1];
  *(undefined8 *)(this + 0x2d8) = *puVar6;
  *(undefined8 *)(this + 0x2e0) = uVar3;
  *(undefined8 *)(this + 0x2e8) = puVar6[2];
  *(undefined8 *)(this + 0x2f0) = 0;
  return 0;
}



/* ==== 1802461c0 dgnIn ==== */

/* public: virtual void __cdecl OdDgBSplineKnots::dgnIn(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgBSplineKnots::dgnIn(OdDgBSplineKnots *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  longlong *plVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong *plVar9;
  OdDgElementId *this_00;
  OdDbHandle *pOVar10;
  longlong lVar11;
  undefined8 uVar12;
  __uint64 _Var13;
  OdRxClass *pOVar14;
  ulonglong uVar15;
  OdRxClass *pOVar16;
  code *pcVar17;
  code *local_res8;
  longlong local_res10;
  longlong *local_res18;
  longlong *local_res20;
  OdError_NotThatKindOfClass local_48 [16];
  
                    /* 0x2461c0  7792  ?dgnIn@OdDgBSplineKnots@@UEAAXPEAVOdDgFiler@@@Z */
  plVar9 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EBSplineKnots::RTTI_Type_Descriptor,0);
  uVar4 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  iVar5 = (**(code **)(*plVar9 + 0x108))(plVar9,param_1);
  iVar6 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar6 == 9) {
    lVar11 = *plVar9;
    this_00 = (OdDgElementId *)(**(code **)(*(longlong *)this + 0x120))(this,local_48);
    pOVar10 = OdDgElementId::getHandle(this_00);
    (**(code **)(lVar11 + 0x30))(plVar9,*(undefined8 *)pOVar10);
  }
  if (iVar5 == 0) {
    lVar11 = (**(code **)(*plVar9 + 0x458))(plVar9);
    iVar5 = *(int *)(lVar11 + 0x14);
    iVar6 = *(int *)(lVar11 + 0x18);
    iVar7 = (**(code **)(*(longlong *)param_1 + 0x88))(param_1);
    iVar8 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
    local_res8 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1800150c0(&local_res8,(iVar7 + (iVar5 - iVar6) * -2) - iVar8);
    uVar1 = *(undefined4 *)(local_res8 + -4);
    lVar11 = *(longlong *)param_1;
    uVar12 = FUN_18023d1f0(&local_res8);
    (**(code **)(lVar11 + 0x90))(param_1,uVar12,uVar1);
    uVar2 = *(uint *)(local_res8 + -4);
    _Var13 = FUN_18023d1f0(&local_res8);
    OdFlatMemStream::createNew(&local_res20,_Var13,(ulonglong)uVar2);
    plVar3 = local_res20;
    local_res10 = 0;
    lVar11 = local_res10;
    if (local_res20 != (longlong *)0x0) {
      lVar11 = *local_res20;
      pOVar14 = OdStreamBuf::desc();
      lVar11 = (**(code **)(lVar11 + 8))(plVar3,pOVar14);
      if (lVar11 == 0) {
        pOVar14 = OdStreamBuf::desc();
        pOVar16 = (OdRxClass *)(**(code **)(*plVar3 + 0x18))(plVar3);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_48,pOVar16,pOVar14);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_res10 = lVar11;
    FUN_1801c4f80(&local_res18,&local_res10);
    iVar5 = (**(code **)(*plVar9 + 0x120))(plVar9,local_res18);
    if (local_res18 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 0x28))();
      local_res18 = (longlong *)0x0;
    }
    if (local_res20 != (longlong *)0x0) {
      (**(code **)(*local_res20 + 0x28))();
      local_res20 = (longlong *)0x0;
    }
    pcVar17 = local_res8 + -0x10;
    LOCK();
    iVar6 = *(int *)pcVar17;
    *(int *)pcVar17 = *(int *)pcVar17 + -1;
    UNLOCK();
    if ((iVar6 == 1) && (pcVar17 != g_empty_array_buffer_exref)) {
      odrxFree();
    }
    if (iVar5 == 0) {
      uVar15 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
      if ((uVar15 & 1) != 0) {
        (**(code **)(*(longlong *)param_1 + 0x98))(param_1);
      }
      (**(code **)(*plVar9 + 0x180))(plVar9,param_1,uVar4);
    }
  }
  return;
}



/* ==== 180275010 dgnInFields ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual enum OdResult __cdecl OdDgAssocRegion3dImpl::dgnInFields(class OdDgFiler *
   __ptr64) __ptr64 */

OdResult __thiscall
OdDgAssocRegion3dImpl::dgnInFields(OdDgAssocRegion3dImpl *this,OdDgFiler *param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  OdDgDatabase *this_00;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined1 auStack_f8 [32];
  longlong lStack_d8;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong uStack_28;
  
  uStack_28 = DAT_180fcd438 ^ (ulonglong)auStack_f8;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x240) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x242) = uVar1;
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&uStack_d0);
  *(undefined4 *)(this + 0x248) = uStack_d0;
  *(undefined4 *)(this + 0x24c) = uStack_cc;
  *(undefined4 *)(this + 0x250) = uStack_c8;
  *(undefined4 *)(this + 0x254) = uStack_c4;
  *(undefined8 *)(this + 600) = uStack_c0;
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&uStack_d0);
  *(ulonglong *)(this + 0x260) = CONCAT44(uStack_cc,uStack_d0);
  *(ulonglong *)(this + 0x268) = CONCAT44(uStack_c4,uStack_c8);
  *(undefined8 *)(this + 0x270) = uStack_c0;
  OdGeMatrix3d::OdGeMatrix3d((OdGeMatrix3d *)&uStack_a8);
  uStack_a8 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_a0 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_98 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_88 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_80 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_78 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_68 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uStack_60 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x278) = uStack_a8;
  *(undefined8 *)(this + 0x280) = uStack_a0;
  *(undefined8 *)(this + 0x288) = uStack_98;
  *(undefined8 *)(this + 0x290) = uStack_90;
  *(undefined8 *)(this + 0x298) = uStack_88;
  *(undefined8 *)(this + 0x2a0) = uStack_80;
  *(undefined8 *)(this + 0x2a8) = uStack_78;
  *(undefined8 *)(this + 0x2b0) = uStack_70;
  *(undefined8 *)(this + 0x2b8) = uStack_68;
  *(undefined8 *)(this + 0x2c0) = uStack_60;
  *(undefined8 *)(this + 0x2c8) = uVar6;
  *(undefined4 *)(this + 0x2d0) = uStack_50;
  *(undefined4 *)(this + 0x2d4) = uStack_4c;
  *(undefined4 *)(this + 0x2d8) = uStack_48;
  *(undefined4 *)(this + 0x2dc) = uStack_44;
  *(undefined4 *)(this + 0x2e0) = uStack_40;
  *(undefined4 *)(this + 0x2e4) = uStack_3c;
  *(undefined4 *)(this + 0x2e8) = uStack_38;
  *(undefined4 *)(this + 0x2ec) = uStack_34;
  *(undefined4 *)(this + 0x2f0) = uStack_30;
  *(undefined4 *)(this + 0x2f4) = uStack_2c;
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&uStack_d0);
  *(undefined4 *)(this + 0x2f8) = uStack_d0;
  *(undefined4 *)(this + 0x2fc) = uStack_cc;
  *(undefined4 *)(this + 0x300) = uStack_c8;
  *(undefined4 *)(this + 0x304) = uStack_c4;
  *(undefined8 *)(this + 0x328) = 0xbff0000000000000;
  *(undefined8 *)(this + 0x308) = uStack_c0;
  iVar2 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (((iVar2 == 2) && (iVar2 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1), iVar2 == 1)) &&
     (lVar4 = FUN_180010890(this), lVar4 != 0)) {
    uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    uVar5 = (ulonglong)uVar3;
    FUN_18000d1e0(this + 0x220);
    *(undefined4 *)(*(longlong *)(this + 0x220) + -4) = 0;
    if (uVar3 != 0) {
      do {
        uStack_b8 = (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
        this_00 = (OdDgDatabase *)FUN_180010890(this);
        OdDgDatabase::getElementId(this_00,(OdDbHandle *)&lStack_d8);
        if (lStack_d8 != 0) {
          FUN_180013b80(this + 0x220,&lStack_d8);
        }
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  return 0;
}



/* ==== 180275060 dgnInLinkages ==== */

/* public: virtual enum OdResult __cdecl OdDgAssocRegion3dImpl::dgnInLinkages(class OdDgFiler *
   __ptr64,unsigned __int64) __ptr64 */

OdResult __thiscall
OdDgAssocRegion3dImpl::dgnInLinkages
          (OdDgAssocRegion3dImpl *this,OdDgFiler *param_1,__uint64 param_2)

{
  OdResult OVar1;
  
                    /* 0x275060  7822
                       ?dgnInLinkages@OdDgAssocRegion3dImpl@@UEAA?AW4OdResult@@PEAVOdDgFiler@@_K@Z
                        */
  OVar1 = CDGElementGeneral::dgnInLinkages((CDGElementGeneral *)this,param_1,param_2);
  if (OVar1 == 0) {
    ECell<OdDgFiler3d>::readAttributes((ECell<OdDgFiler3d> *)this);
  }
  (**(code **)(*(longlong *)(this + 0x3c8) + 0x60))(this + 0x3c8,this);
  return OVar1;
}



/* ==== 18038c1b0 dgnInFields ==== */

/* public: void __cdecl OdDgHLineSettings::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgHLineSettings::dgnInFields(OdDgHLineSettings *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  
                    /* 0x38c1b0  7805  ?dgnInFields@OdDgHLineSettings@@QEAAXPEAVOdDgFiler@@@Z */
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)this = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x10) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x14) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x18) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x24) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x28) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x30) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x34) = uVar1;
  return;
}



/* ==== 18038c2a0 dgnInFields ==== */

/* public: void __cdecl OdDgSmartSolidSettings::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgSmartSolidSettings::dgnInFields(OdDgSmartSolidSettings *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
                    /* 0x38c2a0  7814  ?dgnInFields@OdDgSmartSolidSettings@@QEAAXPEAVOdDgFiler@@@Z
                        */
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)this = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x10) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x14) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x18) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1c) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x20) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x28) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2c) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x30) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x38) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3c) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x40) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x48) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4c) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x50) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x58) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5c) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x60) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x68) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x70) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x74) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x78) = uVar2;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x80) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x88) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x8c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x90) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x94) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x98) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x9c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa4) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xa8) = uVar2;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xb0) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xb8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xbc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc4) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 200) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xd0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xd4) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xd8) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xe0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xe4) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xe8) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xf0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xf4) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xf8) = uVar2;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x100) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x108) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x10c) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x110) = uVar2;
  return;
}



/* ==== 18038c660 dgnInFields ==== */

/* public: void __cdecl OdDgToolSettings3D::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgToolSettings3D::dgnInFields(OdDgToolSettings3D *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  OdDgToolSettings3D *pOVar3;
  undefined8 uVar4;
  
                    /* 0x38c660  7815  ?dgnInFields@OdDgToolSettings3D@@QEAAXPEAVOdDgFiler@@@Z */
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)this = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x10) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x14) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x18) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x24) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x28) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x30) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x34) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x38) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x40) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x44) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x48) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x50) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x54) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x58) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x60) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x68) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x70) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x74) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x78) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x80) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x84) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x88) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x90) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x94) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x98) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xa8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xb0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xb4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xb8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 200) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xd0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xd4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xd8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xe0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xe4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xe8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xec) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xf0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xf8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xfc) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x100) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x108) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x10c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x110) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x118) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x11c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x120) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x128) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 300) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x130) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x134) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x138) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x140) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x144) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x148) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x14c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x150) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x158) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x15c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x160) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x168) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x16c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x170) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x178) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x17c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x180) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x184) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x188) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 400) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x194) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x198) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x19c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x1a0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1a8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1ac) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x1b0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1b8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1bc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1c0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1c4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x1c8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1d0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1d4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x1d8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1e0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1e4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x1e8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1f0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 500) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1f8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1fc) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x200) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x208) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x20c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x210) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x218) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x21c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x220) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x228) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x22c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x230) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x234) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x238) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x240) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x244) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x248) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x250) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x254) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 600) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x260) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x264) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x268) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x26c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x270) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x278) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x27c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x280) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x288) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x28c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x290) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x298) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x29c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x2a0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2a8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2ac) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x2b0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2b8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 700) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2c0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2c4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x2c8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2d0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2d4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2d8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2dc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2e0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2e4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2e8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2ec) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2f0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2f4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2f8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2fc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x300) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x304) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x308) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x30c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x310) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x314) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x318) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x31c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 800) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x324) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x328) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x330) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x334) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x338) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x340) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x344) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x348) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x350) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x354) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x358) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x35c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x360) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x364) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x368) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x370) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x374) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x378) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x37c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x380) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x388) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x38c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x390) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x394) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x398) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3a0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3a4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x3a8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3b0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3b4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x3b8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3c0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3c4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x3c8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3d0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3d4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x3d8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3e0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3e4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 1000) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3ec) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x3f0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3f8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3fc) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x400) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x408) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x40c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x410) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x418) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x420) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x424) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x428) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x430) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x438) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x43c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x440) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x444) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x448) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x450) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x454) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x458) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x45c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x460) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x468) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x46c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x470) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x478) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x47c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x480) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x488) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x48c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x490) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x494) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x498) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4a0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4a4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x4a8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4b0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4b4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x4b8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4c0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4c4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x4c8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4d0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4d4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4d8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4dc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4e0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4e4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x4e8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4f0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4f4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4f8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4fc) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x500) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x508) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x50c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x510) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x514) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x518) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x520) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x524) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x528) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x530) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x534) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x538) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x540) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x544) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x548) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x54c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x550) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x558) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x55c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x560) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x568) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x56c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x570) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x574) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x578) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x580) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x584) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x588) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x590) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x594) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x598) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x59c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x5a0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5a8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5ac) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x5b0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5b8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5bc) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x5c0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5c8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5cc) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x5d0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5d8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5dc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5e0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5e4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x5e8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5f0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5f4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x5f8) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x600) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x604) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x608) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x610) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x614) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x618) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x620) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x624) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x628) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x62c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x630) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x638) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x63c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x640) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x648) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x64c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x650) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x658) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x65c) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x660) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x668) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x670) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x678) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x680) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x688) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x68c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x690) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x694) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x698) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x6a0) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x6a8) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x6b0) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x6b8) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x6c0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6c8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6cc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6d0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6d4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6d8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6dc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6e0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x6e4) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x6e8) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x6f0) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x6f8) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x700) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x708) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x70c) = uVar1;
  pOVar3 = this + 0x710;
  lVar2 = 8;
  do {
    uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
    *(undefined8 *)pOVar3 = uVar4;
    pOVar3 = pOVar3 + 8;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x750) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x754) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x758) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x760) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x768) = uVar4;
  OdDgSmartSolidSettings::dgnInFields((OdDgSmartSolidSettings *)(this + 0x770),param_1);
  pOVar3 = this + 0x888;
  lVar2 = 0x2e;
  do {
    uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
    *(undefined8 *)pOVar3 = uVar4;
    pOVar3 = pOVar3 + 8;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



/* ==== 18038e240 dgnInFields ==== */

/* public: void __cdecl OdDgToolSettings::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgToolSettings::dgnInFields(OdDgToolSettings *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  OdDgToolSettings *pOVar2;
  longlong lVar3;
  undefined8 uVar4;
  
                    /* 0x38e240  7816  ?dgnInFields@OdDgToolSettings@@QEAAXPEAVOdDgFiler@@@Z */
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)this = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x10) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x14) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x18) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x1c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x20) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x24) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x28) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x2c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x30) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x34) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x38) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x3c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x40) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x44) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x48) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x4c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x50) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x54) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x58) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x5c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x60) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 100) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x68) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x70) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x78) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x80) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x88) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x8c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x90) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x94) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x98) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x9c) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xac) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xb0) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xb4) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xb8) = uVar1;
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0xc0) = uVar4;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 200) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xcc) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xd0) = uVar1;
  lVar3 = 0x27;
  pOVar2 = this + 0xd8;
  do {
    uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
    *(undefined8 *)pOVar2 = uVar4;
    pOVar2 = pOVar2 + 8;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return;
}



/* ==== 1803af910 dgnInFields ==== */

/* public: virtual enum OdResult __cdecl ERasterReference::dgnInFields(class OdDgFiler * __ptr64)
   __ptr64 */

OdResult __thiscall ERasterReference::dgnInFields(ERasterReference *this,OdDgFiler *param_1)

{
  longlong lVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  OdRxClass *pOVar8;
  OdRxClass *pOVar9;
  undefined8 uVar10;
  longlong *local_res8;
  longlong *local_res10;
  undefined1 local_38 [32];
  
                    /* 0x3af910  7798
                       ?dgnInFields@ERasterReference@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z */
  uVar2 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x240) = uVar2;
  uVar2 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x242) = uVar2;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x244) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x248) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x24c) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x250) = uVar3;
  iVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(double *)(this + 600) = (double)iVar4;
  iVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(double *)(this + 0x260) = (double)iVar4;
  puVar5 = (undefined8 *)(**(code **)(*(longlong *)param_1 + 0x110))(param_1,local_38);
  uVar10 = puVar5[1];
  *(undefined8 *)(this + 0x268) = *puVar5;
  *(undefined8 *)(this + 0x270) = uVar10;
  *(undefined8 *)(this + 0x278) = puVar5[2];
  uVar10 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x280) = uVar10;
  uVar10 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x288) = uVar10;
  uVar10 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x290) = uVar10;
  uVar10 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x298) = uVar10;
  if (*(short *)(this + 0x240) == 0) {
    uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    *(undefined4 *)(this + 0x2a0) = uVar3;
    uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    *(undefined4 *)(this + 0x2a4) = uVar3;
  }
  iVar4 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar4 == 2) {
    _updateAllChildren(this);
  }
  else {
    _removeAllChildren(this);
  }
  FUN_1803aed20(&local_res8);
  local_res8[3] = *(longlong *)(this + 0x58);
  plVar6 = (longlong *)(**(code **)(*(longlong *)param_1 + 0x70))(param_1);
  local_res10 = (longlong *)0x0;
  plVar7 = local_res10;
  if (plVar6 != (longlong *)0x0) {
    lVar1 = *plVar6;
    uVar10 = FUN_18004b620();
    plVar7 = (longlong *)(**(code **)(lVar1 + 8))(plVar6,uVar10);
    if (plVar7 == (longlong *)0x0) {
      pOVar8 = (OdRxClass *)FUN_18004b620();
      pOVar9 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res10,pOVar9,pOVar8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_res10 = plVar7;
  plVar7 = local_res10;
  if (local_res10 != (longlong *)0x0) {
    FUN_1809e53c0(local_res10,local_res8);
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  (**(code **)(*local_res8 + 0x28))(local_res8);
  iVar4 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar4 == 0) {
    this[0x2a8] = (ERasterReference)0x0;
  }
  return 0;
}



/* ==== 1803afb70 dgnInLinkages ==== */

/* public: virtual enum OdResult __cdecl ERasterReference::dgnInLinkages(class OdDgFiler *
   __ptr64,unsigned __int64) __ptr64 */

OdResult __thiscall
ERasterReference::dgnInLinkages(ERasterReference *this,OdDgFiler *param_1,__uint64 param_2)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  OdResult OVar6;
  OdString *pOVar7;
  short *psVar8;
  longlong lVar9;
  longlong local_res20;
  OdString local_28 [16];
  
                    /* 0x3afb70  7821
                       ?dgnInLinkages@ERasterReference@@UEAA?AW4OdResult@@PEAVOdDgFiler@@_K@Z */
  OVar6 = CDGElementGeneral::dgnInLinkages((CDGElementGeneral *)this,param_1,param_2);
  if (OVar6 == 0) {
    (**(code **)(*(longlong *)this + 0x690))(this,&local_res20);
    bVar5 = true;
    bVar4 = false;
    if ((*(longlong *)(local_res20 + 0x10) != 0) ||
       (bVar3 = bVar5, *(longlong *)(local_res20 + 0x18) == 0)) {
      bVar3 = bVar4;
    }
    if (bVar3) {
      OdString::syncUnicode((OdString *)&local_res20);
    }
    lVar9 = *(longlong *)(local_res20 + 0x10);
    if ((*(longlong *)(*(longlong *)(this + 0x2d8) + 0x10) != 0) ||
       (bVar3 = bVar5, *(longlong *)(*(longlong *)(this + 0x2d8) + 0x18) == 0)) {
      bVar3 = bVar4;
    }
    if (bVar3) {
      OdString::syncUnicode((OdString *)(this + 0x2d8));
    }
    psVar8 = *(short **)(*(longlong *)(this + 0x2d8) + 0x10);
    lVar9 = lVar9 - (longlong)psVar8;
    do {
      sVar1 = *psVar8;
      sVar2 = *(short *)((longlong)psVar8 + lVar9);
      if (sVar1 != sVar2) break;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    if ((sVar1 != sVar2) && (*(longlong **)(this + 0x2b0) != (longlong *)0x0)) {
      this[0x2d4] = (ERasterReference)0x0;
      (**(code **)(**(longlong **)(this + 0x2b0) + 0x28))();
      *(undefined8 *)(this + 0x2b0) = 0;
      if (*(longlong **)(this + 0x2b8) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(this + 0x2b8) + 0x28))();
      }
      *(undefined2 *)(this + 0x2c0) = 0;
      *(undefined4 *)(this + 0x2c4) = 0x7fffffff;
      *(undefined4 *)(this + 0x2c8) = 0x7fffffff;
      *(undefined4 *)(this + 0x2cc) = 0x80000000;
      *(undefined4 *)(this + 0x2d0) = 0x80000000;
    }
    OdString::operator=((OdString *)(this + 0x2d8),(OdString *)&local_res20);
    *(undefined2 *)(this + 0x2d4) = 0;
    pOVar7 = (OdString *)(**(code **)(*(longlong *)this + 0x6a0))(this,local_28);
    OdString::operator=((OdString *)&local_res20,pOVar7);
    OdString::~OdString(local_28);
    if ((*(longlong *)(local_res20 + 0x10) != 0) ||
       (bVar3 = bVar5, *(longlong *)(local_res20 + 0x18) == 0)) {
      bVar3 = bVar4;
    }
    if (bVar3) {
      OdString::syncUnicode((OdString *)&local_res20);
    }
    lVar9 = *(longlong *)(local_res20 + 0x10);
    if ((*(longlong *)(*(longlong *)(this + 0x2e0) + 0x10) != 0) ||
       (*(longlong *)(*(longlong *)(this + 0x2e0) + 0x18) == 0)) {
      bVar5 = false;
    }
    if (bVar5) {
      OdString::syncUnicode((OdString *)(this + 0x2e0));
    }
    psVar8 = *(short **)(*(longlong *)(this + 0x2e0) + 0x10);
    lVar9 = lVar9 - (longlong)psVar8;
    do {
      sVar1 = *psVar8;
      sVar2 = *(short *)((longlong)psVar8 + lVar9);
      if (sVar1 != sVar2) break;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    if ((sVar1 != sVar2) && (*(longlong **)(this + 0x2b0) != (longlong *)0x0)) {
      this[0x2d4] = (ERasterReference)0x0;
      (**(code **)(**(longlong **)(this + 0x2b0) + 0x28))();
      *(undefined8 *)(this + 0x2b0) = 0;
      if (*(longlong **)(this + 0x2b8) != (longlong *)0x0) {
        (**(code **)(**(longlong **)(this + 0x2b8) + 0x28))();
      }
      *(undefined2 *)(this + 0x2c0) = 0;
      *(undefined4 *)(this + 0x2c4) = 0x7fffffff;
      *(undefined4 *)(this + 0x2c8) = 0x7fffffff;
      *(undefined4 *)(this + 0x2cc) = 0x80000000;
      *(undefined4 *)(this + 0x2d0) = 0x80000000;
    }
    OdString::operator=((OdString *)(this + 0x2e0),(OdString *)&local_res20);
    *(undefined2 *)(this + 0x2d4) = 0;
    OdString::~OdString((OdString *)&local_res20);
  }
  return OVar6;
}



/* ==== 1804beb90 dgnInXAttributes ==== */

OdResult __thiscall CDGElementGeneral::dgnInXAttributes(CDGElementGeneral *this,OdDgFiler *param_1)

{
  int iVar1;
  
  if (param_1 != (OdDgFiler *)0x0) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
    if (iVar1 != 0) {
      (**(code **)(*(longlong *)this + 0x428))(this,1);
    }
  }
  return 0;
}



/* ==== 180536180 readFile ==== */

/* public: void __cdecl OdDgDatabase::readFile(class OdSmartPtr<class OdStreamBuf> & __ptr64,enum
   Oda::FileShareMode,bool) __ptr64 */

void __thiscall
OdDgDatabase::readFile
          (OdDgDatabase *this,OdSmartPtr<OdStreamBuf> *param_1,FileShareMode param_2,bool param_3)

{
  longlong lVar1;
  byte bVar2;
  char cVar3;
  longlong *plVar4;
  OdRxDynamicLinker *pOVar5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  OdDgRxEventImpl *pOVar8;
  OdRxClass *pOVar9;
  undefined4 in_register_00000084;
  longlong *plStackX_8;
  undefined1 auStackX_20 [8];
  longlong *plStack_48;
  longlong *plStack_40;
  longlong *plStack_38;
  longlong *plStack_30;
  OdDgRxEventImpl *apOStack_28 [2];
  
                    /* 0x536180  17887
                       ?readFile@OdDgDatabase@@QEAAXAEAV?$OdSmartPtr@VOdStreamBuf@@@@W4FileShareMode@Oda@@_N@Z
                        */
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0x519) = 1;
  *(bool *)(*(longlong *)(this + 0x10) + 0x51a) = param_3;
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0x51b) = 0;
  plVar4 = (longlong *)
           FUN_1806232f0(*(undefined8 *)(this + 0x10),param_1,CONCAT44(in_register_00000084,param_2)
                        );
  bVar2 = (**(code **)(*plVar4 + 0x150))(plVar4);
  if ((bVar2 & 1) == 0) {
    (**(code **)(*(longlong *)this + 0x560))(this,0);
  }
  else {
    (**(code **)(*(longlong *)this + 0x560))(this,1);
    *(undefined1 *)(*(longlong *)(this + 0x10) + 0xd10) = 1;
  }
  FUN_1809e9810(&plStackX_8,param_1,bVar2 & 1,param_3);
  if (plStackX_8 == (longlong *)0x0) {
    (**(code **)(*(longlong *)this + 0x560))(this,0);
    *(undefined1 *)(*(longlong *)(this + 0x10) + 0xd10) = 0;
    OdString::OdString((OdString *)&plStack_40,(ushort *)L"TG_Dgn7IO");
    pOVar5 = odrxDynamicLinker();
    plVar4 = (longlong *)(**(code **)(*(longlong *)pOVar5 + 0x88))(pOVar5,&plStack_48,&plStack_40,1)
    ;
    plStack_38 = (longlong *)0x0;
    plVar4 = (longlong *)*plVar4;
    plVar6 = plStack_38;
    if (plVar4 != (longlong *)0x0) {
      lVar1 = *plVar4;
      pOVar7 = OdDgn7IOModule::desc();
      plVar6 = (longlong *)(**(code **)(lVar1 + 8))(plVar4,pOVar7);
      if (plVar6 == (longlong *)0x0) {
        pOVar7 = OdDgn7IOModule::desc();
        pOVar9 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&plStack_38,pOVar9,pOVar7);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&plStack_38,(ThrowInfo *)&DAT_180de5310);
      }
    }
    plStack_38 = plVar6;
    plVar4 = plStack_38;
    if (plStack_48 != (longlong *)0x0) {
      (**(code **)(*plStack_48 + 0x28))();
      plStack_48 = (longlong *)0x0;
    }
    OdString::~OdString((OdString *)&plStack_40);
    if (plVar4 == (longlong *)0x0) {
      OdString::OdString((OdString *)&plStack_30,(ushort *)L"TG_Dgn7IO");
      OdError_FileNotFound::OdError_FileNotFound
                ((OdError_FileNotFound *)apOStack_28,(OdString *)&plStack_30);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(apOStack_28,(ThrowInfo *)&DAT_180de5488);
    }
    (**(code **)(*plVar4 + 0x80))(plVar4,this,param_1);
    *(undefined4 *)(*(longlong *)(this + 0x10) + 0xbb4) = 7;
    *(undefined4 *)(*(longlong *)(this + 0x10) + 3000) = 0;
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  else {
    FUN_18052f4e0(&plStack_40,this);
    plVar4 = plStack_40;
    FUN_1809e6c20(plStack_40,plStackX_8,0);
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  if (*(longlong *)(*(longlong *)(this + 0x10) + 0x4a8) != 0) {
    FUN_180634060();
    FUN_18062b250(*(undefined8 *)(this + 0x10));
    FUN_18062c9e0(*(longlong *)(this + 0x10),this,
                  *(undefined1 *)(*(longlong *)(this + 0x10) + 0xd10),0);
    if ((*(char *)(*(longlong *)(this + 0x10) + 0xd10) != '\0') &&
       (7 < *(uint *)(*(longlong *)(this + 0x10) + 0xbb4))) {
      FUN_18058be10();
    }
    plVar4 = *(longlong **)(this + 0x10);
    if (((char)plVar4[0x1a2] == '\0') ||
       (cVar3 = (**(code **)(*plVar4 + 0x2e0))(plVar4,3), cVar3 == '\0')) {
      (**(code **)(**(longlong **)(this + 0x10) + 0x2d8))(*(longlong **)(this + 0x10),auStackX_20,3)
      ;
    }
    plVar4 = (longlong *)odDgRxEvent();
    apOStack_28[0] = (OdDgRxEventImpl *)0x0;
    plVar4 = (longlong *)*plVar4;
    pOVar8 = apOStack_28[0];
    if (plVar4 != (longlong *)0x0) {
      lVar1 = *plVar4;
      pOVar7 = OdDgRxEventImpl::desc();
      pOVar8 = (OdDgRxEventImpl *)(**(code **)(lVar1 + 8))(plVar4,pOVar7);
      if (pOVar8 == (OdDgRxEventImpl *)0x0) {
        pOVar7 = OdDgRxEventImpl::desc();
        pOVar9 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)apOStack_28,pOVar9,pOVar7);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(apOStack_28,(ThrowInfo *)&DAT_180de5310);
      }
    }
    apOStack_28[0] = pOVar8;
    pOVar8 = apOStack_28[0];
    if (plStack_40 != (longlong *)0x0) {
      (**(code **)(*plStack_40 + 0x28))();
      plStack_40 = (longlong *)0x0;
    }
    if (pOVar8 != (OdDgRxEventImpl *)0x0) {
      OdDgRxEventImpl::fire_initialDgnFileOpenComplete(pOVar8,this);
    }
    plVar4 = (longlong *)(**(code **)(*(longlong *)this + 8))(this,OdDgDatabaseRecoveryPE::g_pDesc);
    plStack_30 = plVar4;
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 0x58))(plVar4,this);
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    if (pOVar8 != (OdDgRxEventImpl *)0x0) {
      (**(code **)(*(longlong *)pOVar8 + 0x28))(pOVar8);
    }
  }
  (**(code **)(*(longlong *)this + 0x560))(this,0);
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0xd10) = 0;
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0x519) = 0;
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0x51a) = 0;
  if (plStackX_8 != (longlong *)0x0) {
    (**(code **)(*plStackX_8 + 0x28))();
  }
  return;
}



/* ==== 180536190 readFile ==== */

/* public: void __cdecl OdDgDatabase::readFile(class OdString const & __ptr64,enum
   Oda::FileShareMode,bool) __ptr64 */

void __thiscall
OdDgDatabase::readFile(OdDgDatabase *this,OdString *param_1,FileShareMode param_2,bool param_3)

{
  char cVar1;
  int iVar2;
  OdRxDynamicLinker *pOVar3;
  longlong *plVar4;
  OdRxClass *pOVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 uVar8;
  OdDgRxEventImpl *pOVar9;
  OdRxClass *pOVar10;
  bool bVar11;
  longlong *local_res8;
  undefined1 local_res20 [8];
  longlong *local_68;
  longlong *local_60;
  longlong *local_58;
  longlong *local_50;
  OdDgRxEventImpl *local_48 [2];
  
                    /* 0x536190  17888
                       ?readFile@OdDgDatabase@@QEAAXAEBVOdString@@W4FileShareMode@Oda@@_N@Z */
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0x519) = 1;
  *(bool *)(*(longlong *)(this + 0x10) + 0x51a) = param_3;
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0x51b) = 0;
  OdString::operator=((OdString *)(*(longlong *)(this + 0x10) + 0xd40),param_1);
  bVar11 = *(int *)(*(longlong *)(this + 0x10) + 0xcdc) == 1;
  if (!bVar11) goto LAB_1805362cd;
  OdString::OdString((OdString *)&local_60,(ushort *)L"ThreadPool");
  pOVar3 = odrxDynamicLinker();
  plVar4 = (longlong *)(**(code **)(*(longlong *)pOVar3 + 0x88))(pOVar3,&local_68,&local_60,1);
  local_58 = (longlong *)0x0;
  plVar4 = (longlong *)*plVar4;
  plVar6 = local_58;
  if (plVar4 != (longlong *)0x0) {
    lVar7 = *plVar4;
    pOVar5 = OdRxThreadPoolService::desc();
    plVar6 = (longlong *)(**(code **)(lVar7 + 8))(plVar4,pOVar5);
    if (plVar6 == (longlong *)0x0) {
      pOVar5 = OdRxThreadPoolService::desc();
      pOVar10 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_50,pOVar10,pOVar5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_50,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_58 = plVar6;
  plVar4 = local_58;
  if (local_68 != (longlong *)0x0) {
    (**(code **)(*local_68 + 0x28))();
    local_68 = (longlong *)0x0;
  }
  OdString::~OdString((OdString *)&local_60);
  if ((plVar4 == (longlong *)0x0) ||
     (lVar7 = FUN_1806232f0(*(undefined8 *)(this + 0x10)), lVar7 == 0)) {
LAB_1805362bb:
    bVar11 = false;
  }
  else {
    plVar6 = (longlong *)FUN_1806232f0(*(undefined8 *)(this + 0x10));
    iVar2 = (**(code **)(*plVar6 + 0x158))(plVar6,1);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*plVar4 + 0x80))(plVar4);
    }
    if (iVar2 == 1) goto LAB_1805362bb;
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
LAB_1805362cd:
  *(bool *)(*(longlong *)(this + 0x10) + 0xd10) = bVar11;
  if ((*(char *)(*(longlong *)(this + 0x10) + 0xd10) != '\0') || (param_3)) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  FUN_1809e96b0(&local_res8,param_1,0,uVar8,param_3);
  if (local_res8 == (longlong *)0x0) {
    param_3 = false;
    OdString::OdString((OdString *)&local_68,(ushort *)L"TG_Dgn7IO");
    pOVar3 = odrxDynamicLinker();
    plVar4 = (longlong *)(**(code **)(*(longlong *)pOVar3 + 0x88))(pOVar3,&local_60,&local_68,1);
    local_50 = (longlong *)0x0;
    plVar4 = (longlong *)*plVar4;
    plVar6 = local_50;
    if (plVar4 != (longlong *)0x0) {
      lVar7 = *plVar4;
      pOVar5 = OdDgn7IOModule::desc();
      plVar6 = (longlong *)(**(code **)(lVar7 + 8))(plVar4,pOVar5);
      if (plVar6 == (longlong *)0x0) {
        pOVar5 = OdDgn7IOModule::desc();
        pOVar10 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_50,pOVar10,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_50,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_50 = plVar6;
    plVar4 = local_50;
    if (local_60 != (longlong *)0x0) {
      (**(code **)(*local_60 + 0x28))();
      local_60 = (longlong *)0x0;
    }
    OdString::~OdString((OdString *)&local_68);
    if (plVar4 == (longlong *)0x0) {
      OdString::OdString((OdString *)&local_58,(ushort *)L"TG_Dgn7IO");
      OdError_FileNotFound::OdError_FileNotFound
                ((OdError_FileNotFound *)local_48,(OdString *)&local_58);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5488);
    }
    uVar8 = OdString::OdString((OdString *)local_48,param_1);
    (**(code **)(*plVar4 + 0x88))(plVar4,this,uVar8);
    *(undefined4 *)(*(longlong *)(this + 0x10) + 0xbb4) = 7;
    *(undefined4 *)(*(longlong *)(this + 0x10) + 3000) = 0;
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  else {
    FUN_18052f4e0(&local_50,this);
    plVar4 = local_50;
    FUN_1809e6c20(local_50,local_res8,param_3);
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  if (*(longlong *)(*(longlong *)(this + 0x10) + 0x4a8) != 0) {
    plVar4 = (longlong *)odDgRxEvent();
    local_48[0] = (OdDgRxEventImpl *)0x0;
    plVar4 = (longlong *)*plVar4;
    pOVar9 = local_48[0];
    if (plVar4 != (longlong *)0x0) {
      lVar7 = *plVar4;
      pOVar5 = OdDgRxEventImpl::desc();
      pOVar9 = (OdDgRxEventImpl *)(**(code **)(lVar7 + 8))(plVar4,pOVar5);
      if (pOVar9 == (OdDgRxEventImpl *)0x0) {
        pOVar5 = OdDgRxEventImpl::desc();
        pOVar10 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)local_48,pOVar10,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_48[0] = pOVar9;
    pOVar9 = local_48[0];
    if (local_60 != (longlong *)0x0) {
      (**(code **)(*local_60 + 0x28))();
      local_60 = (longlong *)0x0;
    }
    if (pOVar9 != (OdDgRxEventImpl *)0x0) {
      OdDgRxEventImpl::fire_dgnFileOpened(pOVar9,this,param_1);
      (**(code **)(*(longlong *)pOVar9 + 0x28))(pOVar9);
    }
    FUN_180634060(*(undefined8 *)(this + 0x10));
    FUN_18062b250(*(undefined8 *)(this + 0x10));
    FUN_18062c9e0(*(longlong *)(this + 0x10),this,
                  *(undefined1 *)(*(longlong *)(this + 0x10) + 0xd10),param_3);
    if ((*(char *)(*(longlong *)(this + 0x10) + 0xd10) != '\0') &&
       (7 < *(uint *)(*(longlong *)(this + 0x10) + 0xbb4))) {
      FUN_18058be10();
    }
    plVar4 = *(longlong **)(this + 0x10);
    if (((char)plVar4[0x1a2] == '\0') ||
       (cVar1 = (**(code **)(*plVar4 + 0x2e0))(plVar4,3), cVar1 == '\0')) {
      (**(code **)(**(longlong **)(this + 0x10) + 0x2d8))(*(longlong **)(this + 0x10),local_res20,3)
      ;
    }
    plVar4 = (longlong *)odDgRxEvent();
    local_48[0] = (OdDgRxEventImpl *)0x0;
    plVar4 = (longlong *)*plVar4;
    pOVar9 = local_48[0];
    if (plVar4 != (longlong *)0x0) {
      lVar7 = *plVar4;
      pOVar5 = OdDgRxEventImpl::desc();
      pOVar9 = (OdDgRxEventImpl *)(**(code **)(lVar7 + 8))(plVar4,pOVar5);
      if (pOVar9 == (OdDgRxEventImpl *)0x0) {
        pOVar5 = OdDgRxEventImpl::desc();
        pOVar10 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)local_48,pOVar10,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_48[0] = pOVar9;
    pOVar9 = local_48[0];
    if (local_60 != (longlong *)0x0) {
      (**(code **)(*local_60 + 0x28))();
      local_60 = (longlong *)0x0;
    }
    if (pOVar9 != (OdDgRxEventImpl *)0x0) {
      OdDgRxEventImpl::fire_initialDgnFileOpenComplete(pOVar9,this);
    }
    plVar4 = (longlong *)(**(code **)(*(longlong *)this + 8))(this,OdDgDatabaseRecoveryPE::g_pDesc);
    local_50 = plVar4;
    if ((param_3 == false) && (plVar4 != (longlong *)0x0)) {
      (**(code **)(*plVar4 + 0x58))(plVar4,this);
    }
    if (plVar4 != (longlong *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    if (pOVar9 != (OdDgRxEventImpl *)0x0) {
      (**(code **)(*(longlong *)pOVar9 + 0x28))(pOVar9);
    }
  }
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0xd10) = 0;
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0x519) = 0;
  *(undefined1 *)(*(longlong *)(this + 0x10) + 0x51a) = 0;
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x28))();
  }
  return;
}



/* ==== 1805c5b50 dgnInFields ==== */

/* public: void __cdecl OdDgCompoundLineStyleComponentInfo::dgnInFields(class OdDgFiler * __ptr64)
   __ptr64 */

void __thiscall
OdDgCompoundLineStyleComponentInfo::dgnInFields
          (OdDgCompoundLineStyleComponentInfo *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  OdDgCompoundLineStyleComponentInfo *pOVar3;
  undefined8 uVar4;
  
                    /* 0x5c5b50  7801
                       ?dgnInFields@OdDgCompoundLineStyleComponentInfo@@QEAAXPEAVOdDgFiler@@@Z */
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)this = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 4) = uVar1;
  pOVar3 = this + 8;
  lVar2 = 4;
  do {
    uVar1 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    *(undefined4 *)pOVar3 = uVar1;
    pOVar3 = pOVar3 + 4;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar4 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x18) = uVar4;
  pOVar3 = this + 0x20;
  lVar2 = 3;
  do {
    uVar4 = (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
    *(undefined8 *)pOVar3 = uVar4;
    pOVar3 = pOVar3 + 8;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



/* ==== 1805c5c00 dgnInFields ==== */

/* public: virtual void __cdecl OdDgCompoundLineStyleResource::dgnInFields(class OdDgFiler *
   __ptr64,unsigned long) __ptr64 */

void __thiscall
OdDgCompoundLineStyleResource::dgnInFields
          (OdDgCompoundLineStyleResource *this,OdDgFiler *param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  OdDgCompoundLineStyleResource *pOVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  OdError_InvalidIndex local_res8 [8];
  ulonglong uVar12;
  
                    /* 0x5c5c00  7802
                       ?dgnInFields@OdDgCompoundLineStyleResource@@UEAAXPEAVOdDgFiler@@K@Z */
  iVar2 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  (**(code **)(*(longlong *)param_1 + 0x90))(param_1,this + 8,0x80);
  uVar6 = (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
  *(undefined8 *)(this + 0x88) = uVar6;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x90) = uVar3;
  pOVar8 = this + 0x94;
  lVar11 = 8;
  do {
    uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    *(undefined4 *)pOVar8 = uVar3;
    pOVar8 = pOVar8 + 4;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  pOVar8 = this + 0xb8;
  uVar12 = 0;
  lVar11 = *(longlong *)pOVar8;
  uVar10 = *(uint *)(lVar11 + -4);
  uVar9 = uVar4 - uVar10;
  if ((int)uVar9 < 1) {
    if ((int)uVar9 < 0) {
      LOCK();
      piVar1 = (int *)(lVar11 + -0x10);
      iVar5 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar5) {
        FUN_1802f5200(pOVar8,uVar4,0,0,1);
      }
    }
    goto LAB_1805c5d5f;
  }
  LOCK();
  piVar1 = (int *)(lVar11 + -0x10);
  iVar5 = *piVar1;
  *piVar1 = *piVar1;
  UNLOCK();
  if (iVar5 < 2) {
    if (*(uint *)(*(longlong *)pOVar8 + -8) < uVar9 + uVar10) {
      uVar6 = CONCAT71((int7)((ulonglong)lVar11 >> 8),1);
      goto LAB_1805c5ce2;
    }
  }
  else {
    uVar6 = 0;
LAB_1805c5ce2:
    FUN_1802f5200(pOVar8,uVar9 + uVar10,uVar6,0,1);
  }
  if (uVar9 != 0) {
    puVar7 = (undefined8 *)
             ((ulonglong)uVar10 * 0x40 + 0x18 + *(longlong *)pOVar8 + (ulonglong)uVar9 * 0x40);
    do {
      puVar7[-0xb] = 0;
      puVar7[-8] = 0;
      puVar7[-4] = 0;
      puVar7[-10] = 0;
      puVar7[-9] = 0;
      puVar7[-7] = 0;
      puVar7[-6] = 0;
      puVar7[-5] = 0;
      uVar9 = uVar9 - 1;
      puVar7 = puVar7 + -8;
    } while (uVar9 != 0);
  }
LAB_1805c5d5f:
  *(uint *)(*(longlong *)pOVar8 + -4) = uVar4;
  if (uVar4 != 0) {
    do {
      if (*(uint *)(*(longlong *)pOVar8 + -4) <= (uint)uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*(longlong *)pOVar8 + -0x10);
      iVar5 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar5) {
        FUN_1802f5200(pOVar8,*(undefined4 *)(*(longlong *)pOVar8 + -8),0,0,1);
      }
      OdDgCompoundLineStyleComponentInfo::dgnInFields
                ((OdDgCompoundLineStyleComponentInfo *)(uVar12 * 0x40 + *(longlong *)pOVar8),param_1
                );
      uVar10 = (uint)uVar12 + 1;
      uVar12 = (ulonglong)uVar10;
    } while (uVar10 < uVar4);
  }
  iVar5 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  if (iVar5 != param_2 + iVar2) {
    (**(code **)(*(longlong *)param_1 + 0x78))(param_1,param_2 + iVar2,0);
  }
  return;
}



/* ==== 1805c5e10 dgnInFields ==== */

/* public: virtual void __cdecl OdDgLineCodeResource::dgnInFields(class OdDgFiler * __ptr64,unsigned
   long) __ptr64 */

void __thiscall
OdDgLineCodeResource::dgnInFields(OdDgLineCodeResource *this,OdDgFiler *param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  OdDgLineCodeResource *pOVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar13;
  OdError_InvalidIndex local_res8 [8];
  ulonglong uVar12;
  
                    /* 0x5c5e10  7807  ?dgnInFields@OdDgLineCodeResource@@UEAAXPEAVOdDgFiler@@K@Z */
  iVar2 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  (**(code **)(*(longlong *)param_1 + 0x90))(param_1,this + 8,0x80);
  uVar6 = (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
  *(undefined8 *)(this + 0x88) = uVar6;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x90) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x94) = uVar3;
  uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x98) = uVar6;
  pOVar8 = this + 0xa0;
  lVar11 = 5;
  do {
    uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
    *(undefined8 *)pOVar8 = uVar6;
    pOVar8 = pOVar8 + 8;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 200) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xcc) = uVar3;
  uVar3 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xd0) = uVar3;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  pOVar8 = this + 0xd8;
  uVar13 = 0;
  lVar11 = *(longlong *)pOVar8;
  uVar10 = *(uint *)(lVar11 + -4);
  uVar9 = uVar4 - uVar10;
  uVar12 = (ulonglong)uVar9;
  if ((int)uVar9 < 1) {
    if ((int)uVar9 < 0) {
      LOCK();
      piVar1 = (int *)(lVar11 + -0x10);
      iVar5 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar5) {
        FUN_1802e3e00(pOVar8,uVar4,0,0,1);
      }
    }
    goto LAB_1805c5fc6;
  }
  LOCK();
  piVar1 = (int *)(lVar11 + -0x10);
  iVar5 = *piVar1;
  *piVar1 = *piVar1;
  UNLOCK();
  if (iVar5 < 2) {
    if (*(uint *)(*(longlong *)pOVar8 + -8) < uVar9 + uVar10) {
      uVar6 = CONCAT71((int7)((ulonglong)lVar11 >> 8),1);
      goto LAB_1805c5f4d;
    }
  }
  else {
    uVar6 = 0;
LAB_1805c5f4d:
    FUN_1802e3e00(pOVar8,uVar9 + uVar10,uVar6,0,1);
  }
  if (uVar9 != 0) {
    puVar7 = (undefined8 *)((ulonglong)uVar10 * 0x30 + *(longlong *)pOVar8 + 0x10 + uVar12 * 0x30);
    do {
      puVar7[-8] = 0;
      puVar7[-7] = 0;
      puVar7[-6] = 0;
      puVar7[-3] = 0;
      puVar7[-5] = 0;
      puVar7[-4] = 0;
      uVar10 = (int)uVar12 - 1;
      uVar12 = (ulonglong)uVar10;
      puVar7 = puVar7 + -6;
    } while (uVar10 != 0);
  }
LAB_1805c5fc6:
  *(uint *)(*(longlong *)pOVar8 + -4) = uVar4;
  if (uVar4 != 0) {
    do {
      if (*(uint *)(*(longlong *)pOVar8 + -4) <= (uint)uVar13) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*(longlong *)pOVar8 + -0x10);
      iVar5 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar5) {
        FUN_1802e3e00(pOVar8,*(undefined4 *)(*(longlong *)pOVar8 + -8),0,0,1);
      }
      OdDgLineCodeResourceStrokeData::dgnInFields
                ((OdDgLineCodeResourceStrokeData *)(uVar13 * 0x30 + *(longlong *)pOVar8),param_1);
      uVar10 = (uint)uVar13 + 1;
      uVar13 = (ulonglong)uVar10;
    } while (uVar10 < uVar4);
  }
  iVar5 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  if (iVar5 != param_2 + iVar2) {
    (**(code **)(*(longlong *)param_1 + 0x78))(param_1,param_2 + iVar2,0);
  }
  return;
}



/* ==== 1805c6070 dgnInFields ==== */

/* public: void __cdecl OdDgLineCodeResourceStrokeData::dgnInFields(class OdDgFiler * __ptr64)
   __ptr64 */

void __thiscall
OdDgLineCodeResourceStrokeData::dgnInFields(OdDgLineCodeResourceStrokeData *this,OdDgFiler *param_1)

{
  OdDgLineCodeResourceStrokeData OVar1;
  undefined4 uVar2;
  OdDgLineCodeResourceStrokeData *pOVar3;
  longlong lVar4;
  undefined8 uVar5;
  
                    /* 0x5c6070  7808
                       ?dgnInFields@OdDgLineCodeResourceStrokeData@@QEAAXPEAVOdDgFiler@@@Z */
  uVar5 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)this = uVar5;
  uVar5 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 8) = uVar5;
  uVar5 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x10) = uVar5;
  pOVar3 = this + 0x18;
  lVar4 = 5;
  do {
    uVar2 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    *(undefined4 *)pOVar3 = uVar2;
    pOVar3 = pOVar3 + 4;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  OVar1 = (OdDgLineCodeResourceStrokeData)(**(code **)(*(longlong *)param_1 + 0x98))(param_1);
  this[0x2c] = OVar1;
  OVar1 = (OdDgLineCodeResourceStrokeData)(**(code **)(*(longlong *)param_1 + 0x98))(param_1);
  this[0x2d] = OVar1;
  OVar1 = (OdDgLineCodeResourceStrokeData)(**(code **)(*(longlong *)param_1 + 0x98))(param_1);
  this[0x2e] = OVar1;
  OVar1 = (OdDgLineCodeResourceStrokeData)(**(code **)(*(longlong *)param_1 + 0x98))(param_1);
  this[0x2f] = OVar1;
  return;
}



/* ==== 1805c6140 dgnInFields ==== */

/* public: virtual void __cdecl OdDgLinePointResource::dgnInFields(class OdDgFiler *
   __ptr64,unsigned long) __ptr64 */

void __thiscall
OdDgLinePointResource::dgnInFields(OdDgLinePointResource *this,OdDgFiler *param_1,ulong param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar12;
  OdDgLinePointResource *pOVar13;
  OdError_InvalidIndex local_res8 [8];
  ulonglong uVar11;
  
                    /* 0x5c6140  7809  ?dgnInFields@OdDgLinePointResource@@UEAAXPEAVOdDgFiler@@K@Z
                        */
  iVar3 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  (**(code **)(*(longlong *)param_1 + 0x90))(param_1,this + 8,0x80);
  uVar7 = (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
  *(undefined8 *)(this + 0x88) = uVar7;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x90) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x94) = uVar4;
  uVar7 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x98) = uVar7;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa0) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa4) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xa8) = uVar4;
  uVar5 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  pOVar13 = this + 0xb0;
  uVar12 = 0;
  lVar2 = *(longlong *)pOVar13;
  uVar10 = *(uint *)(lVar2 + -4);
  uVar9 = uVar5 - uVar10;
  uVar11 = (ulonglong)uVar9;
  if ((int)uVar9 < 1) {
    if ((int)uVar9 < 0) {
      LOCK();
      piVar1 = (int *)(lVar2 + -0x10);
      iVar6 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar6) {
        FUN_180185060(pOVar13,uVar5,0,0,1);
      }
    }
    goto LAB_1805c62ec;
  }
  LOCK();
  piVar1 = (int *)(lVar2 + -0x10);
  iVar6 = *piVar1;
  *piVar1 = *piVar1;
  UNLOCK();
  if (iVar6 < 2) {
    if (*(uint *)(*(longlong *)pOVar13 + -8) < uVar9 + uVar10) {
      uVar7 = CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
      goto LAB_1805c6253;
    }
  }
  else {
    uVar7 = 0;
LAB_1805c6253:
    FUN_180185060(pOVar13,uVar9 + uVar10,uVar7,0,1);
  }
  if (uVar9 != 0) {
    puVar8 = (undefined8 *)((ulonglong)uVar10 * 0x60 + *(longlong *)pOVar13 + 8 + uVar11 * 0x60);
    do {
      puVar8[-0xd] = 0;
      puVar8[-0xc] = 0;
      puVar8[-0xb] = 0;
      puVar8[-10] = 0;
      puVar8[-6] = 0;
      puVar8[-2] = 0;
      puVar8[-9] = 0;
      puVar8[-8] = 0;
      puVar8[-7] = 0;
      puVar8[-5] = 0;
      puVar8[-4] = 0;
      puVar8[-3] = 0;
      uVar10 = (int)uVar11 - 1;
      uVar11 = (ulonglong)uVar10;
      puVar8 = puVar8 + -0xc;
    } while (uVar10 != 0);
  }
LAB_1805c62ec:
  *(uint *)(*(longlong *)pOVar13 + -4) = uVar5;
  if (uVar5 != 0) {
    do {
      if (*(uint *)(*(longlong *)pOVar13 + -4) <= (uint)uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*(longlong *)pOVar13 + -0x10);
      iVar6 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar6) {
        FUN_180185060(pOVar13,*(undefined4 *)(*(longlong *)pOVar13 + -8),0,0,1);
      }
      OdDgLinePointResourceSymInfo::dgnInFields
                ((OdDgLinePointResourceSymInfo *)(uVar12 * 0x60 + *(longlong *)pOVar13),param_1);
      uVar10 = (uint)uVar12 + 1;
      uVar12 = (ulonglong)uVar10;
    } while (uVar10 < uVar5);
  }
  iVar6 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  if (iVar6 != param_2 + iVar3) {
    (**(code **)(*(longlong *)param_1 + 0x78))(param_1,param_2 + iVar3,0);
  }
  return;
}



/* ==== 1805c63a0 dgnInFields ==== */

/* public: void __cdecl OdDgLinePointResourceSymInfo::dgnInFields(class OdDgFiler * __ptr64) __ptr64
    */

void __thiscall
OdDgLinePointResourceSymInfo::dgnInFields(OdDgLinePointResourceSymInfo *this,OdDgFiler *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  OdDgLinePointResourceSymInfo *pOVar5;
  undefined8 uVar6;
  
                    /* 0x5c63a0  7810
                       ?dgnInFields@OdDgLinePointResourceSymInfo@@QEAAXPEAVOdDgFiler@@@Z */
  uVar2 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)this = uVar2;
  uVar2 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 4) = uVar2;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 8) = uVar1;
  uVar1 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 10) = uVar1;
  uVar2 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0xc) = uVar2;
  uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x10) = uVar6;
  uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  lVar4 = 3;
  *(undefined8 *)(this + 0x18) = uVar6;
  lVar3 = 3;
  pOVar5 = this + 0x20;
  do {
    uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
    *(undefined8 *)pOVar5 = uVar6;
    pOVar5 = pOVar5 + 8;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(undefined8 *)(this + 0x38) = uVar6;
  pOVar5 = this + 0x40;
  do {
    uVar6 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
    *(undefined8 *)pOVar5 = uVar6;
    pOVar5 = pOVar5 + 8;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



/* ==== 1805c6d30 dgnInFields ==== */

/* public: virtual void __cdecl OdDgPointSymbolResource::dgnInFields(class OdDgFiler *
   __ptr64,unsigned long) __ptr64 */

void __thiscall
OdDgPointSymbolResource::dgnInFields(OdDgPointSymbolResource *this,OdDgFiler *param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  OdDgPointSymbolResource *pOVar9;
  longlong lVar10;
  uint uVar11;
  double dVar12;
  undefined1 local_38 [32];
  
                    /* 0x5c6d30  7813  ?dgnInFields@OdDgPointSymbolResource@@UEAAXPEAVOdDgFiler@@K@Z
                        */
  iVar4 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  uVar11 = param_2 + iVar4;
  (**(code **)(*(longlong *)param_1 + 0x90))(param_1,this + 8,0x80);
  uVar7 = (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
  *(undefined8 *)(this + 0x88) = uVar7;
  uVar5 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x90) = uVar5;
  uVar5 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x94) = uVar5;
  puVar8 = (undefined4 *)(**(code **)(*(longlong *)param_1 + 0x110))(param_1,local_38);
  uVar5 = puVar8[1];
  uVar1 = puVar8[2];
  uVar2 = puVar8[3];
  *(undefined4 *)(this + 0x98) = *puVar8;
  *(undefined4 *)(this + 0x9c) = uVar5;
  *(undefined4 *)(this + 0xa0) = uVar1;
  *(undefined4 *)(this + 0xa4) = uVar2;
  *(undefined8 *)(this + 0xa8) = *(undefined8 *)(puVar8 + 4);
  puVar8 = (undefined4 *)(**(code **)(*(longlong *)param_1 + 0x110))(param_1,local_38);
  uVar5 = puVar8[1];
  uVar1 = puVar8[2];
  uVar2 = puVar8[3];
  *(undefined4 *)(this + 0xb0) = *puVar8;
  *(undefined4 *)(this + 0xb4) = uVar5;
  *(undefined4 *)(this + 0xb8) = uVar1;
  *(undefined4 *)(this + 0xbc) = uVar2;
  *(undefined8 *)(this + 0xc0) = *(undefined8 *)(puVar8 + 4);
  puVar8 = (undefined4 *)(**(code **)(*(longlong *)param_1 + 0x110))(param_1,local_38);
  uVar5 = puVar8[1];
  uVar1 = puVar8[2];
  uVar2 = puVar8[3];
  *(undefined4 *)(this + 200) = *puVar8;
  *(undefined4 *)(this + 0xcc) = uVar5;
  *(undefined4 *)(this + 0xd0) = uVar1;
  *(undefined4 *)(this + 0xd4) = uVar2;
  *(undefined8 *)(this + 0xd8) = *(undefined8 *)(puVar8 + 4);
  dVar12 = (double)(**(code **)(*(longlong *)param_1 + 200))(param_1);
  *(double *)(this + 0xe0) = dVar12;
  if ((1e-10 < dVar12) || (bVar3 = true, dVar12 < -1e-10)) {
    bVar3 = false;
  }
  if (bVar3) {
    *(undefined8 *)(this + 0xe0) = 0x3ff0000000000000;
  }
  pOVar9 = this + 0xe8;
  lVar10 = 0xc;
  do {
    uVar7 = (**(code **)(*(longlong *)param_1 + 200))(param_1);
    *(undefined8 *)pOVar9 = uVar7;
    pOVar9 = pOVar9 + 8;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  uVar5 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x148) = uVar5;
  iVar4 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  if (iVar4 == 0) {
    uVar6 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
    if (uVar11 < uVar6) {
      (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
    }
  }
  else {
    FUN_1800150c0(this + 0x150,iVar4);
    FUN_18000d0b0(this + 0x150);
    lVar10 = 0;
    if (*(int *)(*(longlong *)(this + 0x150) + -4) != 0) {
      lVar10 = *(longlong *)(this + 0x150);
    }
    (**(code **)(*(longlong *)param_1 + 0x90))(param_1,lVar10,iVar4);
  }
  uVar6 = (**(code **)(*(longlong *)param_1 + 0x80))(param_1);
  if (uVar6 != uVar11) {
    (**(code **)(*(longlong *)param_1 + 0x78))(param_1,uVar11,0);
  }
  return;
}



/* ==== 1805d9200 dgnIn ==== */

/* public: virtual void __cdecl OdDgModel::dgnIn(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall OdDgModel::dgnIn(OdDgModel *this,OdDgFiler *param_1)

{
  longlong *plVar1;
  
                    /* 0x5d9200  7794  ?dgnIn@OdDgModel@@UEAAXPEAVOdDgFiler@@@Z */
  OdDgElement::assertWriteEnabled((OdDgElement *)this,true,true);
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGModel::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001805d9250. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar1 + 1000))(plVar1,param_1);
  return;
}



/* ==== 18081e3a0 dgnInFields ==== */

/* public: virtual void __cdecl CDGDispHeader::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall CDGDispHeader::dgnInFields(CDGDispHeader *this,OdDgFiler *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
                    /* 0x81e3a0  7796  ?dgnInFields@CDGDispHeader@@UEAAXPEAVOdDgFiler@@@Z */
  CDGElmHeader::dgnInFields((CDGElmHeader *)this,param_1);
  if ((((*(ushort *)(this + 0x10) >> 0xc & 1) == 0) || (*(int *)(this + 0xc) == 100)) &&
     ((*(int *)(this + 0xc) != 0x23 || (*(int *)(this + 0x18) * 2 - 0xb8U < 0x48)))) {
    if (*(longlong *)(this + 0x30) != 0) {
      FUN_18013c820(*(longlong *)(this + 0x30),0x50);
      *(undefined8 *)(this + 0x30) = 0;
    }
    return;
  }
  if (*(longlong *)(this + 0x30) == 0) {
    puVar1 = (undefined8 *)FUN_18013c7c0();
    puVar2 = (undefined8 *)0x0;
    if (puVar1 != (undefined8 *)0x0) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 1;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1[8] = 0;
      *(undefined1 *)(puVar1 + 9) = 1;
      puVar2 = puVar1;
    }
    *(undefined8 **)(this + 0x30) = puVar2;
  }
  FUN_1808c5150(*(undefined8 *)(this + 0x30),param_1);
  this[0x38] = (CDGDispHeader)0x0;
  return;
}



/* ==== 1808b3a20 dgnInFields ==== */

/* public: virtual void __cdecl CDGElmHeader::dgnInFields(class OdDgFiler * __ptr64) __ptr64 */

void __thiscall CDGElmHeader::dgnInFields(CDGElmHeader *this,OdDgFiler *param_1)

{
  int iVar1;
  
                    /* 0x8b3a20  7797  ?dgnInFields@CDGElmHeader@@UEAAXPEAVOdDgFiler@@@Z */
  FUN_1808c5240(this + 8);
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if ((iVar1 != 1) && (iVar1 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1), iVar1 != 9)) {
    return;
  }
  *(undefined8 *)(this + 0x20) = 0;
  return;
}



