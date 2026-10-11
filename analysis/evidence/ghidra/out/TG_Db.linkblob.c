/* ==== 1808b4040 readData ==== */

/* public: void __cdecl OdDgLinkageData::readData(unsigned char const * __ptr64,unsigned long)
   __ptr64 */

void __thiscall OdDgLinkageData::readData(OdDgLinkageData *this,uchar *param_1,ulong param_2)

{
  code *pcVar1;
  uchar *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  char cVar6;
  short sVar7;
  undefined8 *puVar8;
  code *_Dst;
  short sVar9;
  uint uVar10;
  code *local_res8;
  undefined **local_78;
  undefined4 local_70;
  OdDgLinkageData *local_68;
  undefined8 *local_60;
  short local_58;
  code *local_50;
  undefined8 *local_48;
  uint uStack_40;
  
                    /* 0x8b4040  17859  ?readData@OdDgLinkageData@@QEAAXPEBEK@Z */
  lVar4 = *(longlong *)this;
  FUN_1800022b0(this,this,*(undefined8 *)(lVar4 + 8));
  *(longlong *)(lVar4 + 8) = lVar4;
  *(longlong *)lVar4 = lVar4;
  *(longlong *)(lVar4 + 0x10) = lVar4;
  *(undefined8 *)(this + 8) = 0;
  if ((param_2 != 0) && (param_1 != (uchar *)0x0)) {
    local_78 = OdDgAttributeLinkageHeader::vftable;
    puVar2 = param_1 + param_2;
    for (; (param_1 < puVar2 && (param_1 + 4 <= puVar2)); param_1 = param_1 + uVar10) {
      local_70 = *(undefined4 *)param_1;
      cVar6 = (*(code *)local_78[6])(&local_78);
      if (cVar6 == '\0') {
        uVar10 = 8;
      }
      else {
        cVar6 = (*(code *)local_78[7])(&local_78);
        if (cVar6 == '\0') {
          uVar10 = (uint)((ushort)local_70 & 0xff) * 2 + 2;
        }
        else {
          uVar10 = (2 << ((byte)((uint)local_70 >> 8) & 0xf)) * (uint)((ushort)local_70 & 0xff);
        }
      }
      if (puVar2 < param_1 + uVar10) {
        return;
      }
      if ((uVar10 != 0) || (uVar10 = (int)puVar2 - (int)param_1, uVar10 != 0)) {
        cVar6 = (*(code *)local_78[6])(&local_78);
        sVar9 = 0;
        if ((cVar6 != '\0') && (sVar7 = (short)((uint)local_70 >> 0x10), sVar7 != 0)) {
          sVar9 = sVar7;
        }
        local_res8 = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
        UNLOCK();
        FUN_1800150c0(&local_res8,uVar10);
        FUN_18000d0b0(&local_res8);
        pcVar1 = local_res8;
        _Dst = (code *)0x0;
        if (*(int *)(local_res8 + -4) != 0) {
          _Dst = local_res8;
        }
        memcpy(_Dst,param_1,(ulonglong)uVar10);
        local_50 = pcVar1;
        pcVar1 = pcVar1 + -0x10;
        LOCK();
        *(int *)pcVar1 = *(int *)pcVar1 + 1;
        UNLOCK();
        LOCK();
        iVar3 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        local_58 = sVar9;
        if ((iVar3 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
          odrxFree(pcVar1);
        }
        uVar5 = *(undefined8 *)this;
        local_60 = (undefined8 *)0x0;
        local_68 = this;
        local_60 = (undefined8 *)FUN_18013c7c0(0x30);
        *(short *)(local_60 + 4) = local_58;
        local_60[5] = local_res8;
        LOCK();
        *(int *)pcVar1 = *(int *)pcVar1 + 1;
        UNLOCK();
        *local_60 = uVar5;
        local_60[1] = uVar5;
        local_60[2] = uVar5;
        *(undefined2 *)(local_60 + 3) = 0;
        local_48 = *(undefined8 **)(*(longlong *)this + 8);
        uStack_40 = 0;
        if (*(char *)((longlong)local_48 + 0x19) == '\0') {
          puVar8 = local_48;
          do {
            local_48 = puVar8;
            if (*(ushort *)(local_48 + 4) <= *(ushort *)(local_60 + 4)) {
              puVar8 = (undefined8 *)local_48[2];
            }
            else {
              puVar8 = (undefined8 *)*local_48;
            }
            uStack_40 = (uint)(*(ushort *)(local_48 + 4) > *(ushort *)(local_60 + 4));
          } while (*(char *)((longlong)puVar8 + 0x19) == '\0');
        }
        if (*(longlong *)(this + 8) == 0x555555555555555) {
                    /* WARNING: Subroutine does not return */
          FUN_18012f430();
        }
        local_60 = (undefined8 *)0x0;
        FUN_18012f1d0(this,&local_48);
        LOCK();
        iVar3 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if ((iVar3 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
          odrxFree(pcVar1);
        }
      }
    }
  }
  return;
}



/* ==== 1808b4820 writeData ==== */

/* public: void __cdecl OdDgLinkageData::writeData(class OdBinaryData & __ptr64,bool)const __ptr64
    */

void __thiscall OdDgLinkageData::writeData(OdDgLinkageData *this,OdBinaryData *param_1,bool param_2)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  uint *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  ushort uVar10;
  uint *puVar11;
  uint *puVar12;
  longlong lVar13;
  
                    /* 0x8b4820  25914  ?writeData@OdDgLinkageData@@QEBAXAEAVOdBinaryData@@_N@Z */
  FUN_1800150c0(param_1,0);
  puVar5 = *(undefined8 **)this;
  puVar6 = (undefined8 *)*puVar5;
  while (puVar6 != puVar5) {
    puVar7 = (uint *)puVar6[5];
    pcVar1 = (code *)(puVar7 + -4);
    LOCK();
    *(uint *)pcVar1 = *(uint *)pcVar1 + 1;
    UNLOCK();
    uVar3 = *(uint *)(*(longlong *)param_1 + -4);
    uVar4 = puVar7[-1];
    FUN_1800150c0(param_1,uVar4 + uVar3);
    if (param_2) {
      puVar11 = (uint *)0x0;
      if (puVar7[-1] != 0) {
        puVar11 = puVar7;
      }
      uVar10 = (ushort)*puVar11;
      if ((uVar10 >> 0xd & 1) != 0) {
        puVar12 = (uint *)0x0;
        if (puVar7[-1] != 0) {
          puVar12 = puVar7;
        }
        *puVar12 = *puVar11 & 0xffff0000 | (uint)(uVar10 & 0xdfff);
      }
    }
    puVar11 = (uint *)0x0;
    if (puVar7[-1] != 0) {
      puVar11 = puVar7;
    }
    FUN_18000d0b0(param_1);
    lVar13 = 0;
    if (*(int *)(*(longlong *)param_1 + -4) != 0) {
      lVar13 = *(longlong *)param_1;
    }
    memcpy((void *)(lVar13 + (ulonglong)uVar3),puVar11,(ulonglong)uVar4);
    LOCK();
    uVar3 = *(uint *)pcVar1;
    *(uint *)pcVar1 = *(uint *)pcVar1 - 1;
    UNLOCK();
    if ((uVar3 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
      odrxFree(pcVar1);
    }
    puVar8 = (undefined8 *)puVar6[2];
    if (*(char *)((longlong)puVar8 + 0x19) == '\0') {
      cVar2 = *(char *)((longlong)*puVar8 + 0x19);
      puVar6 = puVar8;
      puVar8 = (undefined8 *)*puVar8;
      while (cVar2 == '\0') {
        cVar2 = *(char *)((longlong)*puVar8 + 0x19);
        puVar6 = puVar8;
        puVar8 = (undefined8 *)*puVar8;
      }
    }
    else {
      cVar2 = *(char *)((longlong)puVar6[1] + 0x19);
      puVar9 = (undefined8 *)puVar6[1];
      puVar8 = puVar6;
      while ((puVar6 = puVar9, cVar2 == '\0' && (puVar8 == (undefined8 *)puVar6[2]))) {
        cVar2 = *(char *)((longlong)puVar6[1] + 0x19);
        puVar9 = (undefined8 *)puVar6[1];
        puVar8 = puVar6;
      }
    }
  }
  return;
}



