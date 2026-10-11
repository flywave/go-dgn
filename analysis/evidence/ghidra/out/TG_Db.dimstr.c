/* ==== 18025f040 FUN_18025f040 ==== */

OdString * FUN_18025f040(longlong param_1,OdString *param_2,longlong *param_3,undefined8 param_4)

{
  code cVar1;
  int iVar2;
  OdAnsiString *pOVar3;
  OdString *pOVar4;
  uint uVar5;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  undefined2 local_res18 [4];
  code *local_res20;
  char *local_50;
  OdAnsiString local_48 [8];
  OdError_InvalidIndex local_40 [8];
  
  pcVar8 = (code *)0x0;
  (**(code **)(*param_3 + 0x138))(param_3,&local_50,0xffffffff,param_4,0);
  OdString::OdString(param_2,(OdAnsiString *)&local_50);
  iVar2 = *(int *)(local_50 + -0xc);
  if (2 < iVar2) {
    if ((*local_50 == -1) && (local_50[1] == -2)) {
      if ((local_50[2] == '\x01') && (iVar2 == 3)) {
        pOVar3 = (OdAnsiString *)(**(code **)(*param_3 + 0x138))(param_3,local_48,0xffffffff);
        OdString::operator=(param_2,pOVar3);
        OdAnsiString::~OdAnsiString(local_48);
      }
      else {
        (**(code **)(*param_3 + 0x78))(param_3,1 - iVar2,1);
        pOVar4 = (OdString *)(**(code **)(*param_3 + 0x130))(param_3,local_48,0xffffffff);
        OdString::operator=(param_2,pOVar4);
        OdString::~OdString((OdString *)local_48);
      }
    }
    else if (*(uint *)(param_1 + 0x260) < 0x100) {
      local_res20 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      local_res18[0] = 0;
      FUN_180260550(&local_res20,*(int *)(local_50 + -0xc) + 1,local_res18,param_4,1);
      pcVar6 = pcVar8;
      pcVar7 = pcVar8;
      if (0 < *(int *)(local_50 + -0xc)) {
        do {
          cVar1 = pcVar7[(longlong)local_50];
          if (*(uint *)(local_res20 + -4) <= (uint)pcVar6) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_40);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_40,(ThrowInfo *)&DAT_180de5370);
          }
          FUN_1800381e0(&local_res20);
          *(ushort *)(local_res20 + (longlong)pcVar6 * 2) = (ushort)(byte)cVar1;
          uVar5 = (uint)pcVar6 + 1;
          pcVar6 = (code *)(ulonglong)uVar5;
          pcVar7 = pcVar7 + 1;
        } while ((int)uVar5 < *(int *)(local_50 + -0xc));
      }
      FUN_1800381e0(&local_res20);
      pcVar6 = local_res20;
      if (*(int *)(local_res20 + -4) != 0) {
        pcVar8 = local_res20;
      }
      OdString::operator=(param_2,(ushort *)pcVar8);
      pcVar6 = pcVar6 + -0x10;
      LOCK();
      iVar2 = *(int *)pcVar6;
      *(int *)pcVar6 = *(int *)pcVar6 + -1;
      UNLOCK();
      if ((iVar2 == 1) && (pcVar6 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
    }
  }
  OdAnsiString::~OdAnsiString((OdAnsiString *)&local_50);
  return param_2;
}



