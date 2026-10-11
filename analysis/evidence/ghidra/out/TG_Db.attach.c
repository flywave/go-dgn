/* ==== 1809e4130 FUN_1809e4130 ==== */

Error * FUN_1809e4130(longlong *param_1,Error *param_2,uint param_3,void *param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  longlong lVar4;
  ulonglong _Size;
  uint uVar5;
  Error local_res18 [8];
  
  uVar1 = param_5;
  _Size = (ulonglong)param_5;
  uVar5 = param_3 + param_5;
  uVar2 = (**(code **)(*param_1 + 0x70))();
  if (uVar2 < uVar5) {
    (**(code **)(*param_1 + 0xd0))(param_1,&param_5,uVar5);
    puVar3 = (uint *)Dgn8::Error::Error(local_res18,0,
                                        "C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
    if (*puVar3 != param_5) {
      *(uint *)param_2 = param_5;
      return param_2;
    }
  }
  if ((param_4 != (void *)0x0) && (uVar1 != 0)) {
    lVar4 = (**(code **)(*param_1 + 200))(param_1);
    memcpy((void *)(lVar4 + (ulonglong)param_3),param_4,_Size);
  }
  Dgn8::Error::Error(param_2,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
  return param_2;
}



/* ==== 1809e4200 FUN_1809e4200 ==== */

void FUN_1809e4200(longlong *param_1,uint param_2,longlong *param_3,int param_4)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 local_res10 [8];
  
  uVar2 = (**(code **)(*param_1 + 0x70))();
  if (uVar2 < param_2 + param_4) {
    (**(code **)(*param_1 + 0xd0))(param_1,local_res10,param_2 + param_4);
  }
  if (param_4 != 0) {
    lVar1 = *param_3;
    lVar3 = (**(code **)(*param_1 + 200))(param_1);
    (**(code **)(lVar1 + 0x98))(param_3,lVar3 + (ulonglong)param_2,param_4);
  }
  return;
}



