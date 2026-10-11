/* ==== 18058e1b0 FUN_18058e1b0 ==== */

void FUN_18058e1b0(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  OdRxClass *pOVar5;
  OdError_NotThatKindOfClass local_res8 [8];
  longlong *local_res10;
  
  plVar1 = (longlong *)*param_2;
  local_res10 = param_2;
  if (*(longlong **)(param_1 + 0x28) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_1 + 0x28) + 0x28))();
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (plVar1 != (longlong *)0x0) {
    lVar3 = *plVar1;
    uVar2 = FUN_18004c160();
    lVar3 = (**(code **)(lVar3 + 8))(plVar1,uVar2);
    if (lVar3 == 0) {
      pOVar4 = (OdRxClass *)FUN_18004c160();
      pOVar5 = (OdRxClass *)(**(code **)(*plVar1 + 0x18))(plVar1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res8,pOVar5,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5310);
    }
    *(longlong *)(param_1 + 0x28) = lVar3;
  }
  if ((longlong *)*param_2 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_2 + 0x28))();
    *param_2 = 0;
  }
  return;
}



/* ==== 1809e4d70 FUN_1809e4d70 ==== */

void FUN_1809e4d70(longlong param_1,longlong *param_2,longlong *param_3,longlong *param_4,
                  char param_5)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  char cVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  char *pcVar9;
  OdAnsiString *pOVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong *plVar13;
  OdRxClass *pOVar14;
  OdString *pOVar15;
  OdString *pOVar16;
  OdString *pOVar17;
  int iVar18;
  uint uVar19;
  int local_res8;
  OdString *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  char *local_d8;
  longlong *local_d0;
  OdString local_c8 [8];
  long local_c0;
  OdString local_b8 [8];
  longlong *local_b0;
  longlong *local_a8;
  longlong *local_a0;
  longlong *local_98;
  OdString local_90 [8];
  long local_88;
  OdAnsiString local_80 [8];
  longlong *local_78;
  longlong *local_70;
  OdString local_68 [8];
  OdError_InvalidIndex local_60 [8];
  OdError local_58 [24];
  
  plVar13 = *(longlong **)(*(longlong *)(param_1 + 8) + 0x10);
  local_res18 = param_3;
  local_res20 = param_4;
  local_d0 = plVar13;
  if ((param_2 == (longlong *)0x0) || (param_4 == (longlong *)0x0)) {
    OdError::OdError(local_58,0x14);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_58,(ThrowInfo *)&DAT_180de52b8);
  }
  iVar18 = 0;
  uVar6 = (**(code **)(*param_2 + 0x80))(param_2);
  pcVar4 = g_empty_array_buffer_exref;
  local_res10 = (OdString *)(g_empty_array_buffer_exref + 0x10);
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  if (*(uint *)(pcVar4 + 8) < uVar6) {
    if (uVar6 == 0) {
      pOVar16 = (OdString *)(g_empty_array_buffer_exref + 0x10);
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      FUN_180075690();
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      local_res10 = pOVar16;
      FUN_180075690();
      pOVar16 = local_res10;
      goto LAB_1809e50ea;
    }
    if (uVar6 != *(uint *)(pcVar4 + 8)) {
      LOCK();
      iVar18 = *(int *)pcVar4;
      *(undefined4 *)pcVar4 = *(undefined4 *)pcVar4;
      UNLOCK();
      FUN_18069e1c0(&local_res10,uVar6,iVar18 < 2,1,1);
    }
  }
  uVar19 = 0;
  iVar18 = 0;
  pOVar16 = local_res10;
  if (uVar6 != 0) {
    iVar18 = 0;
    do {
      plVar13 = (longlong *)(**(code **)(*param_2 + 0x88))(param_2,&local_b0,uVar19);
      plVar13 = (longlong *)*plVar13;
      if (plVar13 == (longlong *)0x0) {
        local_a8 = (longlong *)0x0;
      }
      else {
        lVar3 = *plVar13;
        uVar12 = FUN_18004b540();
        local_a8 = (longlong *)(**(code **)(lVar3 + 8))(plVar13,uVar12);
      }
      plVar13 = local_a8;
      if (local_b0 != (longlong *)0x0) {
        (**(code **)(*local_b0 + 0x28))();
        local_b0 = (longlong *)0x0;
      }
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x58))(plVar13,local_b8);
        pcVar9 = OdString::operator_char_const____ptr64(local_b8);
        OdAnsiString::OdAnsiString((OdAnsiString *)&local_d8,pcVar9);
        pOVar10 = (OdAnsiString *)OdAnsiString::right((OdAnsiString *)&local_d8,(int)local_80);
        OdAnsiString::operator=((OdAnsiString *)&local_d8,pOVar10);
        OdAnsiString::~OdAnsiString(local_80);
        lVar7 = atol(local_d8);
        OdString::init(local_c8);
        local_c0 = lVar7;
        OdString::operator=(local_c8,local_b8);
        uVar2 = *(uint *)(pOVar16 + -4);
        pOVar17 = pOVar16 + -0x10;
        LOCK();
        iVar8 = *(int *)pOVar17;
        *(int *)pOVar17 = *(int *)pOVar17;
        UNLOCK();
        if ((iVar8 < 2) && (uVar2 != *(uint *)(local_res10 + -8))) {
LAB_1809e5075:
          pOVar16 = local_res10;
          pOVar17 = local_res10 + (ulonglong)uVar2 * 0x10;
          OdString::OdString(pOVar17,local_c8);
          *(long *)(pOVar17 + 8) = local_c0;
        }
        else {
          if (*(uint *)(pOVar16 + -4) == 0) {
LAB_1809e5056:
            FUN_18069e1c0(&local_res10,uVar2 + 1,iVar8 < 2,0,1);
            goto LAB_1809e5075;
          }
          LOCK();
          iVar1 = *(int *)pOVar17;
          *(int *)pOVar17 = *(int *)pOVar17;
          UNLOCK();
          if (1 < iVar1) {
            FUN_18069e1c0(&local_res10,*(undefined4 *)(local_res10 + -8),0,0,1);
          }
          if (((*(int *)(local_res10 + -4) == 0) || (local_c8 < local_res10)) ||
             (*(int *)(local_res10 + -4) == 0)) goto LAB_1809e5056;
          LOCK();
          pOVar16 = local_res10 + -0x10;
          iVar1 = *(int *)pOVar16;
          *(int *)pOVar16 = *(int *)pOVar16;
          UNLOCK();
          if (1 < iVar1) {
            FUN_18069e1c0(&local_res10,*(undefined4 *)(local_res10 + -8),0,0,1);
          }
          pOVar16 = (OdString *)0x0;
          if (*(uint *)(local_res10 + -4) != 0) {
            pOVar16 = local_res10;
          }
          if (pOVar16 + (ulonglong)*(uint *)(local_res10 + -4) * 0x10 <= local_c8)
          goto LAB_1809e5056;
          OdString::OdString(local_90,local_c8);
          local_88 = local_c0;
          FUN_18069e1c0(&local_res10,uVar2 + 1,iVar8 < 2,0,1);
          pOVar16 = local_res10;
          pOVar17 = local_res10 + (ulonglong)uVar2 * 0x10;
          OdString::OdString(pOVar17,local_90);
          *(long *)(pOVar17 + 8) = local_88;
          OdString::~OdString(local_90);
        }
        plVar13 = local_a8;
        *(int *)(pOVar16 + -4) = *(int *)(pOVar16 + -4) + 1;
        iVar8 = FUN_1806fd600(local_a8);
        iVar18 = iVar18 + iVar8;
        OdString::~OdString(local_c8);
        OdAnsiString::~OdAnsiString((OdAnsiString *)&local_d8);
        OdString::~OdString(local_b8);
      }
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
      }
      uVar19 = uVar19 + 1;
      plVar13 = local_d0;
      param_4 = local_res20;
      local_res8 = iVar18;
    } while (uVar19 < uVar6);
  }
LAB_1809e50ea:
  if (*(int *)(pOVar16 + -4) == 0) {
    pOVar17 = (OdString *)0x0;
    uVar6 = 0;
  }
  else {
    LOCK();
    pOVar16 = pOVar16 + -0x10;
    iVar8 = *(int *)pOVar16;
    *(int *)pOVar16 = *(int *)pOVar16;
    UNLOCK();
    if (1 < iVar8) {
      FUN_18069e1c0(&local_res10,*(undefined4 *)(local_res10 + -8),0,0,1);
    }
    uVar6 = *(uint *)(local_res10 + -4);
    pOVar17 = (OdString *)0x0;
    if (uVar6 != 0) {
      pOVar17 = local_res10;
    }
    pOVar17 = pOVar17 + (ulonglong)uVar6 * 0x10;
    pOVar16 = local_res10;
  }
  if (uVar6 == 0) {
    pOVar15 = (OdString *)0x0;
  }
  else {
    LOCK();
    pOVar16 = pOVar16 + -0x10;
    iVar8 = *(int *)pOVar16;
    *(int *)pOVar16 = *(int *)pOVar16;
    UNLOCK();
    if (1 < iVar8) {
      FUN_18069e1c0(&local_res10,*(undefined4 *)(local_res10 + -8),0,0,1);
    }
    pOVar15 = (OdString *)0x0;
    pOVar16 = local_res10;
    if (*(int *)(local_res10 + -4) != 0) {
      pOVar15 = local_res10;
    }
  }
  FUN_1809e49d0(pOVar15,pOVar17,(longlong)pOVar17 - (longlong)pOVar15 >> 4,(undefined1)local_res8);
  if ((char)plVar13[0x1a2] != '\0') {
    plVar11 = (longlong *)FUN_1809e1c20(plVar13 + 0x1a4);
    iVar8 = *(int *)(*plVar11 + -4);
    uVar12 = FUN_1809e1c20(plVar13 + 0x1a4);
    FUN_1809e6ee0(uVar12,iVar8 + iVar18);
  }
  uVar6 = 0;
  if (*(int *)(pOVar16 + -4) != 0) {
    do {
      if (*(uint *)(pOVar16 + -4) <= uVar6) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_60);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_60,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      pOVar16 = pOVar16 + -0x10;
      iVar18 = *(int *)pOVar16;
      *(int *)pOVar16 = *(int *)pOVar16;
      UNLOCK();
      if (1 < iVar18) {
        FUN_18069e1c0(&local_res10,*(undefined4 *)(local_res10 + -8),0,0,1);
      }
      pOVar16 = local_res10;
      plVar13 = (longlong *)(**(code **)(*param_2 + 0x90))(param_2,&local_a0);
      plVar13 = (longlong *)*plVar13;
      if (plVar13 == (longlong *)0x0) {
        local_78 = (longlong *)0x0;
      }
      else {
        lVar3 = *plVar13;
        uVar12 = FUN_18004b540();
        local_78 = (longlong *)(**(code **)(lVar3 + 8))(plVar13,uVar12);
      }
      plVar13 = local_78;
      if (local_a0 != (longlong *)0x0) {
        (**(code **)(*local_a0 + 0x28))();
        local_a0 = (longlong *)0x0;
      }
      plVar11 = local_res18;
      if (plVar13 != (longlong *)0x0) {
        if (local_res18 != (longlong *)0x0) {
          (**(code **)(*plVar13 + 0x58))(plVar13,local_68);
          plVar11 = (longlong *)(**(code **)(*plVar11 + 0x90))(plVar11,&local_98);
          plVar11 = (longlong *)*plVar11;
          if (plVar11 == (longlong *)0x0) {
            local_70 = (longlong *)0x0;
          }
          else {
            lVar3 = *plVar11;
            pOVar14 = OdDgChunk::desc();
            local_70 = (longlong *)(**(code **)(lVar3 + 8))(plVar11,pOVar14);
          }
          plVar11 = local_70;
          if (local_98 != (longlong *)0x0) {
            (**(code **)(*local_98 + 0x28))();
            local_98 = (longlong *)0x0;
          }
          OdString::~OdString(local_68);
          local_d0 = plVar11;
          if (plVar11 != (longlong *)0x0) {
            (**(code **)(*plVar11 + 0x20))(plVar11);
          }
          (**(code **)(*plVar13 + 0xa8))(plVar13,&local_d0);
          if (plVar11 != (longlong *)0x0) {
            (**(code **)(*plVar11 + 0x28))(plVar11);
          }
        }
        if (param_5 == '\0') {
          (**(code **)(*param_4 + 0x408))(param_4,plVar13);
        }
        else {
          (**(code **)(*param_4 + 0x410))();
        }
        cVar5 = (**(code **)(*plVar13 + 0xe8))(plVar13);
        if (cVar5 != '\0') {
          (**(code **)(*plVar13 + 0x28))(plVar13);
          break;
        }
      }
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(pOVar16 + -4));
  }
  FUN_180075690(pOVar16 + -0x10);
  return;
}



