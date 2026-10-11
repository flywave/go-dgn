/* ==== 1801fa9f0 FUN_1801fa9f0 ==== */

undefined8 FUN_1801fa9f0(longlong *param_1,longlong *param_2)

{
  code *pcVar1;
  ushort uVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined2 uVar9;
  short sVar10;
  undefined4 uVar11;
  int iVar12;
  undefined8 uVar13;
  undefined4 *puVar14;
  OdString *pOVar15;
  ulonglong uVar16;
  code *pcVar17;
  code *pcVar18;
  code *local_res8;
  code *local_res10;
  OdString local_res18 [8];
  OdError_InvalidIndex local_res20 [8];
  OdString local_d8 [8];
  undefined1 local_d0 [24];
  undefined1 local_b8 [24];
  undefined1 local_a0 [24];
  undefined1 local_88 [24];
  undefined1 local_70 [48];
  
  uVar13 = (**(code **)(*param_2 + 0x110))(param_2,local_d0);
  FUN_1808b4d00(param_1 + 0x44,uVar13);
  uVar13 = (**(code **)(*param_2 + 0x110))(param_2,local_b8);
  FUN_1808b4ce0(param_1 + 0x44,uVar13);
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x4a) = uVar9;
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x252) = uVar9;
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x254) = uVar11;
  puVar14 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_a0);
  uVar11 = puVar14[1];
  uVar6 = puVar14[2];
  uVar7 = puVar14[3];
  *(undefined4 *)(param_1 + 0x4b) = *puVar14;
  *(undefined4 *)((longlong)param_1 + 0x25c) = uVar11;
  *(undefined4 *)(param_1 + 0x4c) = uVar6;
  *(undefined4 *)((longlong)param_1 + 0x264) = uVar7;
  param_1[0x4d] = *(longlong *)(puVar14 + 4);
  puVar14 = (undefined4 *)(**(code **)(*param_2 + 0x120))(param_2,local_88);
  uVar11 = puVar14[1];
  uVar6 = puVar14[2];
  uVar7 = puVar14[3];
  *(undefined4 *)(param_1 + 0x4e) = *puVar14;
  *(undefined4 *)((longlong)param_1 + 0x274) = uVar11;
  *(undefined4 *)(param_1 + 0x4f) = uVar6;
  *(undefined4 *)((longlong)param_1 + 0x27c) = uVar7;
  param_1[0x50] = *(longlong *)(puVar14 + 4);
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x51) = uVar9;
  sVar10 = (**(code **)(*param_2 + 0xa8))(param_2);
  FUN_1801ff610(param_1,(int)sVar10);
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x28c) = uVar9;
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x28e) = uVar9;
  lVar5 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x52] = lVar5;
  lVar5 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x53] = lVar5;
  lVar5 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x54] = lVar5;
  lVar5 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x55] = lVar5;
  lVar5 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x56] = lVar5;
  iVar12 = (**(code **)(*param_1 + 0x440))(param_1);
  pcVar17 = (code *)0x0;
  if (iVar12 == 1) {
    puVar14 = (undefined4 *)(**(code **)(*param_2 + 0x128))(param_2,local_70);
    uVar11 = puVar14[1];
    uVar6 = puVar14[2];
    uVar7 = puVar14[3];
    *(undefined4 *)(param_1 + 0x57) = *puVar14;
    *(undefined4 *)((longlong)param_1 + 700) = uVar11;
    *(undefined4 *)(param_1 + 0x58) = uVar6;
    *(undefined4 *)((longlong)param_1 + 0x2c4) = uVar7;
    lVar5 = *(longlong *)(puVar14 + 6);
    param_1[0x59] = *(longlong *)(puVar14 + 4);
    param_1[0x5a] = lVar5;
  }
  else {
    lVar5 = (**(code **)(*param_2 + 200))(param_2);
    param_1[0x57] = lVar5;
    param_1[0x58] = 0;
    param_1[0x59] = 0;
    param_1[0x5a] = 0;
    (**(code **)(*param_2 + 200))(param_2);
    (**(code **)(*param_2 + 200))(param_2);
    (**(code **)(*param_2 + 200))(param_2);
  }
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x5b) = uVar11;
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x2dc) = uVar11;
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x5c) = uVar11;
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x2e4) = uVar11;
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x5d) = uVar9;
  uVar8 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x2ea) = uVar8;
  uVar8 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x2eb) = uVar8;
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x2ec) = uVar11;
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x5e) = uVar9;
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x2f2) = uVar9;
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x2f4) = uVar11;
  sVar10 = *(short *)((longlong)param_1 + 0x28a);
  if (sVar10 == 1) {
    OdString::init(local_res18);
    local_res8 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1800150c0(&local_res8,*(ushort *)(param_1 + 0x5e) + 1);
    FUN_18000d0b0(&local_res8);
    if (*(int *)(local_res8 + -4) != 0) {
      pcVar17 = local_res8;
    }
    (**(code **)(*param_2 + 0x90))(param_2,pcVar17,(short)param_1[0x5e]);
    uVar2 = *(ushort *)(param_1 + 0x5e);
    if (*(uint *)(local_res8 + -4) <= (uint)uVar2) {
      OdError_InvalidIndex::OdError_InvalidIndex(local_res20);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5370);
    }
    FUN_18000d0b0(&local_res8);
    local_res8[(uint)uVar2] = (code)0x0;
    pOVar15 = (OdString *)FUN_1808b7790(local_d8,&local_res8);
    OdString::operator=(local_res18,pOVar15);
    OdString::~OdString(local_d8);
    FUN_1801ffa70(param_1,local_res18);
    pcVar17 = local_res8 + -0x10;
    LOCK();
    iVar12 = *(int *)pcVar17;
    *(int *)pcVar17 = *(int *)pcVar17 + -1;
    UNLOCK();
    if ((iVar12 == 1) && (pcVar17 != g_empty_array_buffer_exref)) {
      odrxFree();
    }
    OdString::~OdString(local_res18);
  }
  else if (sVar10 == 2) {
    uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
    if (*(short *)((longlong)param_1 + 0x28a) != 2) {
      OdError::OdError((OdError *)local_res20,5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
    }
    *(undefined2 *)(param_1 + 0x5f) = uVar9;
  }
  else if (sVar10 == 3) {
    uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
    if (*(short *)((longlong)param_1 + 0x28a) != 3) {
      OdError::OdError((OdError *)local_res20,5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
    }
    *(undefined4 *)(param_1 + 0x5f) = uVar11;
  }
  else if (sVar10 == 4) {
    lVar5 = (**(code **)(*param_2 + 200))(param_2);
    if (*(short *)((longlong)param_1 + 0x28a) != 4) {
      OdError::OdError((OdError *)local_res20,5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
    }
    param_1[0x5f] = lVar5;
  }
  else {
    if (sVar10 != 5) {
      OdError::OdError((OdError *)local_res20,0x53);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
    }
    local_res10 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1800150c0(&local_res10,(short)param_1[0x5e]);
    uVar11 = *(undefined4 *)(local_res10 + -4);
    FUN_18000d0b0(&local_res10);
    pcVar1 = local_res10;
    pcVar18 = pcVar17;
    if (*(int *)(local_res10 + -4) != 0) {
      pcVar18 = local_res10;
    }
    (**(code **)(*param_2 + 0x90))(param_2,pcVar18,uVar11);
    if (*(short *)((longlong)param_1 + 0x28a) != 5) {
      OdError::OdError((OdError *)local_res20,5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
    }
    plVar4 = (longlong *)param_1[0x5f];
    FUN_1800150c0(plVar4,*(undefined4 *)(pcVar1 + -4));
    uVar3 = *(uint *)(*plVar4 + -4);
    if (uVar3 != 0) {
      pcVar18 = pcVar17;
      if (*(int *)(pcVar1 + -4) != 0) {
        pcVar18 = pcVar1;
      }
      FUN_18000d0b0(plVar4);
      if (*(int *)((code *)*plVar4 + -4) != 0) {
        pcVar17 = (code *)*plVar4;
      }
      memcpy(pcVar17,pcVar18,(ulonglong)uVar3);
    }
    *(short *)(param_1 + 0x5e) = (short)*(undefined4 *)(*plVar4 + -4);
    pcVar1 = pcVar1 + -0x10;
    LOCK();
    iVar12 = *(int *)pcVar1;
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if ((iVar12 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
      odrxFree();
    }
  }
  uVar16 = (**(code **)(*param_2 + 0x80))(param_2);
  if ((uVar16 & 1) != 0) {
    (**(code **)(*param_2 + 0xa0))(param_2);
  }
  return 0;
}



/* ==== 1801fb0b0 FUN_1801fb0b0 ==== */

/* WARNING: Removing unreachable block (ram,0x0001801fb584) */
/* WARNING: Removing unreachable block (ram,0x0001801fb565) */
/* WARNING: Removing unreachable block (ram,0x0001801fb527) */

void FUN_1801fb0b0(longlong param_1,longlong *param_2)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  code *_Dst;
  code *pcVar8;
  code *pcVar9;
  uint uVar10;
  code *pcVar11;
  code *local_res8;
  code *local_res10;
  OdError local_res18 [16];
  undefined1 local_78 [24];
  undefined1 local_60 [32];
  
  local_res10 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  uVar10 = (uint)*(ushort *)(param_1 + 0x2f0);
  if (*(short *)(param_1 + 0x28a) == 1) {
    FUN_1801fce90(param_1,&local_res10);
    uVar10 = *(uint *)(local_res10 + -4);
  }
  pcVar8 = local_res10;
  lVar5 = *param_2;
  uVar7 = FUN_1808b4ca0(param_1 + 0x220,local_78);
  (**(code **)(lVar5 + 0x1a8))(param_2,uVar7);
  lVar5 = *param_2;
  uVar7 = FUN_1808b4c80(param_1 + 0x220,local_60);
  (**(code **)(lVar5 + 0x1a8))(param_2,uVar7);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x250));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x252));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x254));
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 600);
  (**(code **)(*param_2 + 0x1b8))(param_2,param_1 + 0x270);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x288));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x28a));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x28c));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x28e));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x290));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x298));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x2a0));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x2a8));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x2b0));
  (**(code **)(*param_2 + 0x1c0))(param_2,param_1 + 0x2b8);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2d8));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2dc));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2e0));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2e4));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x2e8));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)(param_1 + 0x2ea));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)(param_1 + 0x2eb));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2ec));
  (**(code **)(*param_2 + 0x158))(param_2,uVar10 & 0xffff);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x2f2));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2f4));
  sVar2 = *(short *)(param_1 + 0x28a);
  if (sVar2 == 1) {
    uVar4 = *(undefined4 *)(pcVar8 + -4);
    FUN_18000d0b0(&local_res10);
    pcVar8 = local_res10;
    pcVar11 = (code *)0x0;
    if (*(int *)(local_res10 + -4) != 0) {
      pcVar11 = local_res10;
    }
    (**(code **)(*param_2 + 0x140))(param_2,pcVar11,uVar4);
  }
  else if (sVar2 == 2) {
    (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x2f8));
  }
  else if (sVar2 == 3) {
    (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2f8));
  }
  else if (sVar2 == 4) {
    (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x2f8));
  }
  else if (sVar2 == 5) {
    local_res8 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    if (*(short *)(param_1 + 0x28a) != 5) {
      OdError::OdError(local_res18,5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de52b8);
    }
    plVar6 = *(longlong **)(param_1 + 0x2f8);
    FUN_1800150c0(&local_res8,*(undefined4 *)(*plVar6 + -4));
    pcVar11 = (code *)0x0;
    pcVar8 = local_res8;
    if (*(int *)(*plVar6 + -4) != 0) {
      uVar3 = *(uint *)(local_res8 + -4);
      FUN_18000d0b0(plVar6);
      pcVar9 = pcVar11;
      if (*(int *)((code *)*plVar6 + -4) != 0) {
        pcVar9 = (code *)*plVar6;
      }
      FUN_18000d0b0(&local_res8);
      pcVar8 = local_res8;
      _Dst = pcVar11;
      if (*(int *)(local_res8 + -4) != 0) {
        _Dst = local_res8;
      }
      memcpy(_Dst,pcVar9,(ulonglong)uVar3);
    }
    uVar4 = *(undefined4 *)(pcVar8 + -4);
    FUN_18000d0b0(&local_res8);
    pcVar9 = local_res8;
    if (*(int *)(local_res8 + -4) != 0) {
      pcVar11 = local_res8;
    }
    (**(code **)(*param_2 + 0x140))(param_2,pcVar11,uVar4);
    pcVar9 = pcVar9 + -0x10;
    LOCK();
    iVar1 = *(int *)pcVar9;
    *(int *)pcVar9 = *(int *)pcVar9 + -1;
    UNLOCK();
    pcVar8 = local_res10;
    if ((iVar1 == 1) && (pcVar9 != g_empty_array_buffer_exref)) {
      odrxFree();
      pcVar8 = local_res10;
    }
  }
  if ((uVar10 & 1) != 0) {
    (**(code **)(*param_2 + 0x150))(param_2,0);
  }
  pcVar8 = pcVar8 + -0x10;
  LOCK();
  iVar1 = *(int *)pcVar8;
  *(int *)pcVar8 = *(int *)pcVar8 + -1;
  UNLOCK();
  if ((iVar1 == 1) && (pcVar8 != g_empty_array_buffer_exref)) {
    odrxFree();
  }
  return;
}



