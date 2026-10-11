/* ==== 1809df950 FUN_1809df950 ==== */

undefined8 *
FUN_1809df950(longlong *param_1,undefined8 *param_2,uint param_3,OdDgDatabase *param_4,
             longlong param_5,longlong param_6)

{
  uint uVar1;
  OdDgDatabase *this;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  OdDgCellHeaderType OVar7;
  longlong lVar8;
  OdRxClass *pOVar9;
  code *pcVar10;
  OdDgElementId *this_00;
  OdDbHandle *pOVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  OdDgHostAppServices *pOVar14;
  longlong *plVar15;
  ulonglong uVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  ECell3D *this_01;
  OdRxClass *pOVar21;
  code *pcVar22;
  code *pcVar23;
  longlong *local_res8;
  undefined2 local_res18 [4];
  OdDgDatabase *local_res20;
  longlong *local_188;
  code *local_180;
  code *local_178;
  longlong *local_170;
  code *local_168;
  code *local_160;
  code *local_158;
  longlong *local_150;
  code *local_148;
  longlong *local_140;
  code *local_138;
  longlong *local_130;
  longlong *local_128;
  code *local_120;
  undefined4 local_118;
  longlong *local_110;
  OdString local_108 [8];
  code *local_100;
  longlong *local_f8;
  longlong *local_f0;
  OdError_NotThatKindOfClass local_e8 [8];
  undefined1 local_e0 [8];
  OdError_NotThatKindOfClass local_d8 [8];
  OdError_NotThatKindOfClass local_d0 [8];
  int local_c8;
  uint local_c4;
  undefined8 local_c0;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  OdDgDatabase *local_a8;
  code *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined1 local_50;
  
  local_118 = 0;
  local_160 = (code *)0x0;
  local_res8 = param_1;
  local_res20 = param_4;
  lVar8 = (**(code **)(*param_1 + 200))();
  pcVar22 = (code *)(lVar8 + (ulonglong)param_3);
  local_100 = pcVar22;
  iVar4 = (**(code **)(*param_1 + 0x70))(param_1);
  param_3 = iVar4 - param_3;
  if (param_3 < 0x24) {
    *param_2 = 0;
    return param_2;
  }
  OdFlatMemStream::createNew(&local_128,(__uint64)pcVar22,(ulonglong)param_3);
  plVar17 = local_128;
  local_120 = (code *)0x0;
  pcVar10 = local_120;
  if (local_128 != (longlong *)0x0) {
    lVar8 = *local_128;
    pOVar9 = OdStreamBuf::desc();
    pcVar10 = (code *)(**(code **)(lVar8 + 8))(plVar17,pOVar9);
    if (pcVar10 == (code *)0x0) {
      pOVar9 = OdStreamBuf::desc();
      pOVar21 = (OdRxClass *)(**(code **)(*plVar17 + 0x18))(plVar17);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res8,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_120 = pcVar10;
  OdDgFileFiler::createObject(&local_170,&local_120,param_4);
  uVar5 = (**(code **)(*local_170 + 0x80))();
  local_f8 = (longlong *)(ulonglong)uVar5;
  FUN_1808c5240(param_5,local_170);
  uVar5 = *(int *)(param_5 + 0xc) * 2 + 4;
  local_188 = (longlong *)CONCAT44(local_188._4_4_,uVar5);
  if (param_3 < uVar5) {
    *param_2 = 0;
    if (local_170 != (longlong *)0x0) {
      (**(code **)(*local_170 + 0x28))();
      local_170 = (longlong *)0x0;
    }
    if (local_128 == (longlong *)0x0) {
      return param_2;
    }
    (**(code **)(*local_128 + 0x28))();
    return param_2;
  }
  bVar2 = (bool)((byte)(*(ushort *)(param_5 + 8) >> 0xc) & 1);
  if ((*(ushort *)(param_5 + 8) >> 0xc & 1) == 0) {
    bVar2 = CDGDispHeader::isImplicitDisplayHeader
                      (*(ElementTypes *)(param_5 + 4),*(int *)(param_5 + 0x10) * 2 + 4);
  }
  local_b8 = 0;
  if (bVar2 != false) {
    local_98 = 0;
    local_90 = 0;
    local_88 = 1;
    local_80 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_58 = 0;
    local_50 = 1;
    FUN_1808c5150(&local_98,local_170);
    local_b8 = (ushort)local_90 >> 0xb & 1;
  }
  this = local_res20;
  if (*(int *)(param_5 + 4) == 0x60) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_5 + 0x14);
  }
  else if (*(int *)(param_5 + 4) != 0x5f) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  local_c8 = *(int *)(param_5 + 4);
  if (local_c8 == 0x21) {
    local_c4 = (uint)(byte)pcVar22[0x89];
  }
  else if (local_c8 == 0x5b) {
    local_c4 = (uint)*(short *)(pcVar22 + 0x24);
  }
  else if (local_c8 == 0x5f) {
    local_c4 = *(uint *)(param_5 + 0x14);
    if (local_c4 == 0) {
      local_c4 = *(uint *)(param_1 + 8);
    }
  }
  else if (local_c8 == 0x69) {
    local_c4 = *(uint *)(pcVar22 + 0x70);
  }
  else {
    local_c4 = *(uint *)(param_5 + 0x14);
  }
  local_c0 = *(undefined8 *)(param_5 + 0x18);
  local_b4 = (uint)((*(ushort *)(param_5 + 8) >> 0xd & 1) != 0);
  local_b0 = (uint)(((byte)(*(ushort *)(param_5 + 8) >> 0xc) & 1) != 0);
  local_a8 = local_res20;
  local_a0 = (code *)0x0;
  FUN_1809dc0c0(local_e0,&local_c8,param_6 != 0);
  pcVar10 = local_a0;
  pcVar23 = (code *)0x0;
  if (local_a0 != (code *)0x0) {
    local_160 = local_a0;
    (**(code **)(*(longlong *)local_a0 + 0x20))();
    pcVar23 = pcVar10;
  }
  if (*(int *)(param_5 + 0x10) == 0) {
    OdString::init((OdString *)&local_180);
    this_00 = (OdDgElementId *)(**(code **)(*(longlong *)pcVar23 + 0x120))(pcVar23,&local_150);
    pOVar11 = OdDgElementId::getHandle(this_00);
    uVar12 = OdDbHandle::ascii(pOVar11);
    pOVar9 = (OdRxClass *)(**(code **)(*(longlong *)pcVar23 + 0x18))(pcVar23);
    uVar13 = OdRxClass::name(pOVar9);
    uVar12 = FUN_1802c8af0(uVar12);
    uVar13 = FUN_1802c8af0(uVar13);
    OdString::format((OdString *)&local_180,
                     (ushort *)L"Dgn element %ls<%ls> has invalid header data",uVar13,uVar12);
    OdString::~OdString((OdString *)&local_110);
    OdString::~OdString(local_108);
    pOVar14 = OdDgDatabase::appServices(this);
    (**(code **)(*(longlong *)pOVar14 + 200))(pOVar14,&local_180);
    *(undefined4 *)(param_5 + 0x10) = *(undefined4 *)(param_5 + 0xc);
    OdString::~OdString((OdString *)&local_180);
    param_1 = local_res8;
  }
  uVar1 = *(int *)(param_5 + 0x10) * 2 + 4;
  if (uVar5 < uVar1) {
    uVar1 = uVar5;
  }
  local_f0 = (longlong *)(ulonglong)uVar1;
  uVar5 = uVar5 - uVar1;
  local_128[3] = (longlong)pcVar22;
  local_128[2] = (longlong)local_f0;
  local_128[1] = 0;
  plVar17 = *(longlong **)(pcVar23 + 8);
  iVar4 = (**(code **)(*plVar17 + 0x108))(plVar17,local_170);
  local_178 = (code *)CONCAT44(local_178._4_4_,iVar4);
  if (iVar4 == 0) {
    iVar4 = (**(code **)(*plVar17 + 0x120))(plVar17,local_170);
    local_178 = (code *)CONCAT44(local_178._4_4_,iVar4);
    if (((iVar4 == 0) && (*(int *)(param_5 + 4) == 0x21)) &&
       (cVar3 = FUN_180255090(pcVar22,(ulonglong)local_188 & 0xffffffff,uVar5,local_res18),
       cVar3 != '\0')) {
      FUN_180265570(plVar17,local_res18[0]);
    }
  }
  plVar15 = (longlong *)(**(code **)(*param_1 + 0xb0))(param_1,&local_148);
  plVar15 = (longlong *)*plVar15;
  if (plVar15 == (longlong *)0x0) {
    local_188 = (longlong *)0x0;
  }
  else {
    lVar8 = *plVar15;
    uVar12 = FUN_18004c170();
    local_188 = (longlong *)(**(code **)(lVar8 + 8))(plVar15,uVar12);
  }
  plVar15 = local_188;
  if (local_148 != (code *)0x0) {
    (**(code **)(*(longlong *)local_148 + 0x28))();
    local_148 = (code *)0x0;
  }
  if ((int)local_178 == 0) {
    uVar16 = (**(code **)(*local_170 + 0x80))();
    if ((uVar16 & 1) != 0) {
      (**(code **)(*local_170 + 0x98))();
    }
    if (uVar5 != 0) {
      local_128[3] = (longlong)pcVar22;
      local_128[2] = (ulonglong)uVar5 + (longlong)local_f0;
      local_128[1] = (longlong)local_f0;
      (**(code **)(*plVar17 + 0x180))(plVar17,local_170,local_f8);
      uVar16 = (**(code **)(*local_170 + 0x80))();
      if ((uVar16 & 1) != 0) {
        (**(code **)(*local_170 + 0x98))();
      }
    }
    if (plVar15 != (longlong *)0x0) {
      pOVar11 = OdDgElementId::getHandle((OdDgElementId *)(plVar17 + 0xb));
      local_178 = *(code **)pOVar11;
      uVar12 = FUN_1809ea9f0(plVar15,&local_168,&local_178);
      FUN_180128d60(plVar17,uVar12);
      (**(code **)(*plVar17 + 0x198))(plVar17,0);
    }
    *(ushort *)(plVar17 + 9) = *(ushort *)(plVar17 + 9) & 0xfffb;
    (**(code **)(*plVar17 + 0x18))(plVar17,0);
    (**(code **)(*plVar17 + 8))(plVar17,0);
    *(uint *)plVar17[0xb] = *(uint *)plVar17[0xb] | 0x40000000;
    *(uint *)plVar17[0xb] = *(uint *)plVar17[0xb] & 0xdfffffff;
  }
  lVar8 = *(longlong *)pcVar23;
  pOVar9 = OdDgCellHeader3d::desc();
  plVar17 = (longlong *)(**(code **)(lVar8 + 8))(pcVar23,pOVar9);
  lVar8 = *(longlong *)pcVar23;
  local_140 = plVar17;
  pOVar9 = OdDgCellHeader2d::desc();
  plVar18 = (longlong *)(**(code **)(lVar8 + 8))(pcVar23,pOVar9);
  lVar8 = *(longlong *)pcVar23;
  local_130 = plVar18;
  pOVar9 = OdDgApplicationData::desc();
  plVar19 = (longlong *)(**(code **)(lVar8 + 8))(pcVar23,pOVar9);
  lVar8 = *(longlong *)pcVar23;
  local_f8 = plVar19;
  pOVar9 = OdDgTagDefinitionSet::desc();
  plVar20 = (longlong *)(**(code **)(lVar8 + 8))(pcVar23,pOVar9);
  local_f0 = plVar20;
  if (plVar20 != (longlong *)0x0) {
    if ((*(ushort *)(param_5 + 8) >> 0xd & 1) == 0) {
      uVar6 = 0;
    }
    else {
      pcVar22 = local_100 + 0x24;
      if (((*(ushort *)(param_5 + 8) >> 0xc & 1) != 0) && (*(int *)(param_5 + 4) != 100)) {
        pcVar22 = local_100 + 0x6c;
      }
      uVar6 = *(undefined4 *)pcVar22;
    }
    FUN_1809debf0(local_res8,&local_168,plVar20,&local_188,uVar6);
    pcVar22 = local_168;
    if ((local_168 != (code *)0x0) && (pcVar23 != local_168)) {
      (**(code **)(*(longlong *)pcVar23 + 0x28))(pcVar23);
      local_160 = pcVar22;
      (**(code **)(*(longlong *)pcVar22 + 0x20))(pcVar22);
      pcVar23 = pcVar22;
    }
    if (pcVar22 != (code *)0x0) {
      (**(code **)(*(longlong *)pcVar22 + 0x28))(pcVar22);
    }
    goto LAB_1809e07e7;
  }
  if (plVar17 != (longlong *)0x0) {
    local_178 = (code *)0x0;
    local_118 = 0x7e;
    this_01 = (ECell3D *)
              __RTDynamicCast(plVar17[1],0,&OdDgElementImpl::RTTI_Type_Descriptor,
                              &ECell3D::RTTI_Type_Descriptor,0);
    local_148 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1801cb730(this_01,0xb01e,&local_148);
    iVar4 = *(int *)(local_148 + -4);
    FUN_1800144b0(local_148 + -0x10);
    if (iVar4 == 0) {
      OVar7 = ECell3D::getCellType(this_01);
      plVar17 = local_140;
      if (OVar7 == 0) {
        cVar3 = (**(code **)(*(longlong *)this_01 + 0x728))(this_01);
        if (cVar3 == '\0') {
          if (((byte)this_01[0x242] & 1) == 0) {
            bVar2 = ECell<OdDgFiler3d>::isKMLPlacemark((ECell<OdDgFiler3d> *)this_01);
            plVar17 = local_140;
            if (bVar2) {
              OdDgKMLPlacemark3d::createObject();
              plVar17 = local_140;
              pcVar10 = local_168;
              cVar3 = FUN_1809e18e0(local_res8,local_168,local_140,&local_188);
              pcVar22 = local_178;
              if ((cVar3 != '\0') && (pcVar10 != (code *)0x0)) {
                lVar8 = *(longlong *)pcVar10;
                pOVar9 = OdDgElement::desc();
                pcVar22 = (code *)(**(code **)(lVar8 + 8))(pcVar10,pOVar9);
                if (pcVar22 == (code *)0x0) {
                  pOVar9 = OdDgElement::desc();
                  pOVar21 = (OdRxClass *)(**(code **)(*(longlong *)pcVar10 + 0x18))(pcVar10);
                  OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                            ((OdError_NotThatKindOfClass *)&local_res8,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5310);
                }
              }
              local_178 = pcVar22;
              pcVar22 = local_178;
              if (pcVar10 != (code *)0x0) {
                (**(code **)(*(longlong *)pcVar10 + 0x28))(pcVar10);
              }
            }
            else {
              FUN_1809dda00(local_res8,&local_120,local_140,&local_188);
              pcVar10 = local_120;
              pcVar22 = local_178;
              if (local_120 != (code *)0x0) {
                local_178 = local_120;
                (**(code **)(*(longlong *)local_120 + 0x20))();
                pcVar22 = pcVar10;
              }
              if (local_120 != (code *)0x0) {
                (**(code **)(*(longlong *)local_120 + 0x28))();
              }
            }
          }
          else {
            OdDgAnnotationCellHeader3d::createObject();
            plVar17 = local_140;
            pcVar10 = local_168;
            cVar3 = FUN_1809e18e0(local_res8,local_168,local_140,&local_188);
            pcVar22 = local_178;
            if ((cVar3 != '\0') && (pcVar10 != (code *)0x0)) {
              lVar8 = *(longlong *)pcVar10;
              pOVar9 = OdDgElement::desc();
              pcVar22 = (code *)(**(code **)(lVar8 + 8))(pcVar10,pOVar9);
              if (pcVar22 == (code *)0x0) {
                pOVar9 = OdDgElement::desc();
                pOVar21 = (OdRxClass *)(**(code **)(*(longlong *)pcVar10 + 0x18))(pcVar10);
                OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                          ((OdError_NotThatKindOfClass *)&local_150,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(&local_150,(ThrowInfo *)&DAT_180de5310);
              }
            }
            local_178 = pcVar22;
            pcVar22 = local_178;
            if (pcVar10 != (code *)0x0) {
              (**(code **)(*(longlong *)pcVar10 + 0x28))(pcVar10);
            }
          }
        }
        else {
          OdDgAssocRegion3d::createObject();
          plVar17 = local_140;
          pcVar10 = local_168;
          cVar3 = FUN_1809e18e0(local_res8,local_168,local_140,&local_188);
          pcVar22 = local_178;
          if ((cVar3 != '\0') && (pcVar10 != (code *)0x0)) {
            lVar8 = *(longlong *)pcVar10;
            pOVar9 = OdDgElement::desc();
            pcVar22 = (code *)(**(code **)(lVar8 + 8))(pcVar10,pOVar9);
            if (pcVar22 == (code *)0x0) {
              pOVar9 = OdDgElement::desc();
              pOVar21 = (OdRxClass *)(**(code **)(*(longlong *)pcVar10 + 0x18))(pcVar10);
              OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                        ((OdError_NotThatKindOfClass *)&local_110,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(&local_110,(ThrowInfo *)&DAT_180de5310);
            }
          }
          local_178 = pcVar22;
          pcVar22 = local_178;
          if (pcVar10 != (code *)0x0) {
            (**(code **)(*(longlong *)pcVar10 + 0x28))(pcVar10);
          }
        }
      }
      else {
        FUN_1809dde50(local_res8,&local_180,local_140,&local_188);
        pcVar10 = local_180;
        pcVar22 = local_178;
        if (local_180 != (code *)0x0) {
          local_178 = local_180;
          (**(code **)(*(longlong *)local_180 + 0x20))();
          pcVar22 = pcVar10;
        }
        if (local_180 != (code *)0x0) {
          (**(code **)(*(longlong *)local_180 + 0x28))();
        }
      }
    }
    else {
      OdDgOle2Frame3d::createObject();
      plVar17 = local_140;
      pcVar10 = local_168;
      cVar3 = FUN_1809e18e0(local_res8,local_168,local_140,&local_188);
      pcVar22 = local_178;
      if ((cVar3 != '\0') && (pcVar10 != (code *)0x0)) {
        lVar8 = *(longlong *)pcVar10;
        pOVar9 = OdDgElement::desc();
        pcVar22 = (code *)(**(code **)(lVar8 + 8))(pcVar10,pOVar9);
        if (pcVar22 == (code *)0x0) {
          pOVar9 = OdDgElement::desc();
          pOVar21 = (OdRxClass *)(**(code **)(*(longlong *)pcVar10 + 0x18))(pcVar10);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)local_108,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_108,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_178 = pcVar22;
      pcVar22 = local_178;
      if (pcVar10 != (code *)0x0) {
        (**(code **)(*(longlong *)pcVar10 + 0x28))(pcVar10);
      }
    }
    pcVar23 = local_160;
    if ((pcVar22 != (code *)0x0) && (local_160 != pcVar22)) {
      (**(code **)(*(longlong *)local_160 + 0x28))(local_160);
      local_160 = pcVar22;
      (**(code **)(*(longlong *)pcVar22 + 0x20))(pcVar22);
      pcVar23 = pcVar22;
    }
    plVar19 = local_f8;
    plVar20 = local_f0;
    plVar18 = local_130;
    plVar15 = local_188;
    if (pcVar22 != (code *)0x0) {
      (**(code **)(*(longlong *)pcVar22 + 0x28))(pcVar22);
      plVar19 = local_f8;
      plVar20 = local_f0;
      plVar18 = local_130;
      plVar15 = local_188;
    }
    goto LAB_1809e07e7;
  }
  if (plVar18 == (longlong *)0x0) {
    if (plVar19 == (longlong *)0x0) {
      iVar4 = (**(code **)(*(longlong *)pcVar23 + 0x100))(pcVar23);
      if (iVar4 == 0x6a) {
        FUN_1809ddff0(local_res8,&local_180,pcVar23,&local_188);
        pcVar22 = local_180;
        if ((local_180 != (code *)0x0) && (pcVar23 != local_180)) {
          (**(code **)(*(longlong *)pcVar23 + 0x28))(pcVar23);
          local_160 = pcVar22;
          pcVar23 = pcVar22;
          if (pcVar22 != (code *)0x0) {
            (**(code **)(*(longlong *)pcVar22 + 0x20))(pcVar22);
          }
        }
        if (local_180 != (code *)0x0) {
          (**(code **)(*(longlong *)local_180 + 0x28))(local_180);
        }
      }
      else {
        iVar4 = (**(code **)(*(longlong *)pcVar23 + 0x100))(pcVar23);
        if (iVar4 == 0x6b) {
          FUN_1809de570(local_res8,&local_180,pcVar23,&local_188);
          pcVar22 = local_180;
          if ((local_180 != (code *)0x0) && (pcVar23 != local_180)) {
            (**(code **)(*(longlong *)pcVar23 + 0x28))(pcVar23);
            local_160 = pcVar22;
            pcVar23 = pcVar22;
            if (pcVar22 != (code *)0x0) {
              (**(code **)(*(longlong *)pcVar22 + 0x20))(pcVar22);
            }
          }
          if (local_180 != (code *)0x0) {
            (**(code **)(*(longlong *)local_180 + 0x28))(local_180);
          }
        }
      }
    }
    else {
      FUN_1809dd030(local_res8,&local_180,plVar19,&local_188);
      pcVar22 = local_180;
      if ((local_180 != (code *)0x0) && (pcVar23 != local_180)) {
        (**(code **)(*(longlong *)pcVar23 + 0x28))(pcVar23);
        local_160 = pcVar22;
        pcVar23 = pcVar22;
        if (pcVar22 != (code *)0x0) {
          (**(code **)(*(longlong *)pcVar22 + 0x20))(pcVar22);
        }
      }
      if (local_180 != (code *)0x0) {
        (**(code **)(*(longlong *)local_180 + 0x28))(local_180);
      }
    }
    goto LAB_1809e07e7;
  }
  local_158 = (code *)0x0;
  local_118 = 0xbe;
  plVar17 = (longlong *)
            __RTDynamicCast(plVar18[1],0,&OdDgElementImpl::RTTI_Type_Descriptor,
                            &ECell2D::RTTI_Type_Descriptor,0);
  local_100 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  FUN_1801cb730(plVar17,0xb01e,&local_100);
  iVar4 = *(int *)(local_100 + -4);
  FUN_1800144b0(local_100 + -0x10);
  if (iVar4 == 0) {
    cVar3 = (**(code **)(*plVar17 + 0x730))(plVar17);
    if (cVar3 == '\0') {
      if ((*(byte *)((longlong)plVar17 + 0x242) & 1) == 0) {
        local_138 = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
        UNLOCK();
        uVar12 = FUN_180010890(plVar17);
        FUN_1801cc8b0(plVar17,0x56ec0000,&local_138,uVar12);
        if (*(int *)(local_138 + -4) == 0) {
          FUN_1800144b0(local_138 + -0x10);
        }
        else {
          LOCK();
          pcVar22 = local_138 + -0x10;
          iVar4 = *(int *)pcVar22;
          *(int *)pcVar22 = *(int *)pcVar22;
          UNLOCK();
          if (1 < iVar4) {
            FUN_18000cd30(&local_138,*(undefined4 *)(local_138 + -8),0,0,1);
          }
          local_168 = (code *)0x0;
          plVar17 = *(longlong **)local_138;
          pcVar22 = local_168;
          if (plVar17 != (longlong *)0x0) {
            lVar8 = *plVar17;
            pOVar9 = OdDgExtendedElementTypeXAttribute::desc();
            pcVar22 = (code *)(**(code **)(lVar8 + 8))(plVar17,pOVar9);
            if (pcVar22 == (code *)0x0) {
              pOVar9 = OdDgExtendedElementTypeXAttribute::desc();
              pOVar21 = (OdRxClass *)(**(code **)(*plVar17 + 0x18))(plVar17);
              OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                        ((OdError_NotThatKindOfClass *)local_108,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_108,(ThrowInfo *)&DAT_180de5310);
            }
          }
          local_168 = pcVar22;
          pcVar22 = local_168;
          iVar4 = (**(code **)(*(longlong *)local_168 + 0x80))(local_168);
          (**(code **)(*(longlong *)pcVar22 + 0x28))(pcVar22);
          FUN_1800144b0(local_138 + -0x10);
          if (iVar4 == 0x6e0000) {
            OdDgKMLPlacemark2d::createObject();
            plVar18 = local_130;
            cVar3 = FUN_1809e18e0(local_res8,local_110,local_130,&local_188);
            pcVar22 = local_158;
            if ((cVar3 != '\0') && (local_110 != (longlong *)0x0)) {
              lVar8 = *local_110;
              pOVar9 = OdDgElement::desc();
              pcVar22 = (code *)(**(code **)(lVar8 + 8))(local_110,pOVar9);
              if (pcVar22 == (code *)0x0) {
                pOVar9 = OdDgElement::desc();
                pOVar21 = (OdRxClass *)(**(code **)(*local_110 + 0x18))(local_110);
                OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                          ((OdError_NotThatKindOfClass *)&local_res8,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5310);
              }
            }
            local_158 = pcVar22;
            pcVar22 = local_158;
            if (local_110 != (longlong *)0x0) {
              (**(code **)(*local_110 + 0x28))(local_110);
            }
            goto LAB_1809e0655;
          }
        }
        plVar18 = local_130;
        FUN_1809dd5b0(local_res8,&local_148,local_130,&local_188);
        pcVar10 = local_148;
        pcVar22 = local_158;
        if (local_148 != (code *)0x0) {
          local_158 = local_148;
          (**(code **)(*(longlong *)local_148 + 0x20))();
          pcVar22 = pcVar10;
        }
        if (local_148 != (code *)0x0) {
          (**(code **)(*(longlong *)local_148 + 0x28))();
        }
      }
      else {
        OdDgAnnotationCellHeader2d::createObject();
        plVar18 = local_130;
        cVar3 = FUN_1809e18e0(local_res8,local_150,local_130,&local_188);
        pcVar22 = local_158;
        if ((cVar3 != '\0') && (local_150 != (longlong *)0x0)) {
          lVar8 = *local_150;
          pOVar9 = OdDgElement::desc();
          pcVar22 = (code *)(**(code **)(lVar8 + 8))(local_150,pOVar9);
          if (pcVar22 == (code *)0x0) {
            pOVar9 = OdDgElement::desc();
            pOVar21 = (OdRxClass *)(**(code **)(*local_150 + 0x18))(local_150);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_e8,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_e8,(ThrowInfo *)&DAT_180de5310);
          }
        }
        local_158 = pcVar22;
        pcVar22 = local_158;
        if (local_150 != (longlong *)0x0) {
          (**(code **)(*local_150 + 0x28))(local_150);
        }
      }
    }
    else {
      OdDgAssocRegion2d::createObject();
      plVar18 = local_130;
      cVar3 = FUN_1809e18e0(local_res8,local_150,local_130,&local_188);
      pcVar22 = local_158;
      if ((cVar3 != '\0') && (local_150 != (longlong *)0x0)) {
        lVar8 = *local_150;
        pOVar9 = OdDgElement::desc();
        pcVar22 = (code *)(**(code **)(lVar8 + 8))(local_150,pOVar9);
        if (pcVar22 == (code *)0x0) {
          pOVar9 = OdDgElement::desc();
          pOVar21 = (OdRxClass *)(**(code **)(*local_150 + 0x18))(local_150);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_d0,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_d0,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_158 = pcVar22;
      pcVar22 = local_158;
      if (local_150 != (longlong *)0x0) {
        (**(code **)(*local_150 + 0x28))(local_150);
      }
    }
  }
  else {
    OdDgOle2Frame2d::createObject();
    plVar18 = local_130;
    cVar3 = FUN_1809e18e0(local_res8,local_150,local_130,&local_188);
    pcVar22 = local_158;
    if ((cVar3 != '\0') && (local_150 != (longlong *)0x0)) {
      lVar8 = *local_150;
      pOVar9 = OdDgElement::desc();
      pcVar22 = (code *)(**(code **)(lVar8 + 8))(local_150,pOVar9);
      if (pcVar22 == (code *)0x0) {
        pOVar9 = OdDgElement::desc();
        pOVar21 = (OdRxClass *)(**(code **)(*local_150 + 0x18))(local_150);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_d8,pOVar21,pOVar9);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_d8,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_158 = pcVar22;
    pcVar22 = local_158;
    if (local_150 != (longlong *)0x0) {
      (**(code **)(*local_150 + 0x28))(local_150);
    }
  }
LAB_1809e0655:
  pcVar23 = local_160;
  if ((pcVar22 != (code *)0x0) && (local_160 != pcVar22)) {
    (**(code **)(*(longlong *)local_160 + 0x28))(local_160);
    local_160 = pcVar22;
    (**(code **)(*(longlong *)pcVar22 + 0x20))(pcVar22);
    pcVar23 = pcVar22;
  }
  plVar17 = local_140;
  plVar19 = local_f8;
  plVar20 = local_f0;
  plVar15 = local_188;
  if (pcVar22 != (code *)0x0) {
    (**(code **)(*(longlong *)pcVar22 + 0x28))(pcVar22);
    plVar17 = local_140;
    plVar19 = local_f8;
    plVar20 = local_f0;
    plVar15 = local_188;
  }
LAB_1809e07e7:
  *param_2 = pcVar23;
  if (pcVar23 != (code *)0x0) {
    (**(code **)(*(longlong *)pcVar23 + 0x20))(pcVar23);
  }
  if (plVar20 != (longlong *)0x0) {
    (**(code **)(*plVar20 + 0x28))(plVar20);
  }
  if (plVar19 != (longlong *)0x0) {
    (**(code **)(*plVar19 + 0x28))(plVar19);
  }
  if (plVar18 != (longlong *)0x0) {
    (**(code **)(*plVar18 + 0x28))(plVar18);
  }
  if (plVar17 != (longlong *)0x0) {
    (**(code **)(*plVar17 + 0x28))(plVar17);
  }
  if (plVar15 != (longlong *)0x0) {
    (**(code **)(*plVar15 + 0x28))(plVar15);
  }
  if (local_a0 != (code *)0x0) {
    (**(code **)(*(longlong *)local_a0 + 0x28))();
  }
  if (local_170 != (longlong *)0x0) {
    (**(code **)(*local_170 + 0x28))();
    local_170 = (longlong *)0x0;
  }
  if (local_128 != (longlong *)0x0) {
    (**(code **)(*local_128 + 0x28))();
    local_128 = (longlong *)0x0;
  }
  if (pcVar23 != (code *)0x0) {
    (**(code **)(*(longlong *)pcVar23 + 0x28))(pcVar23);
  }
  return param_2;
}



