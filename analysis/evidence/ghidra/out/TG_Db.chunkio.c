/* ==== 180568420 read ==== */

/* public: void __cdecl OdDgProxyChunk::read(class OdDgChunk * __ptr64) __ptr64 */

void __thiscall OdDgProxyChunk::read(OdDgProxyChunk *this,OdDgChunk *param_1)

{
  uint uVar1;
  void *_Src;
  void *_Dst;
  OdError local_res10 [8];
  
                    /* 0x568420  17842  ?read@OdDgProxyChunk@@QEAAXPEAVOdDgChunk@@@Z */
  if (param_1 != (OdDgChunk *)0x0) {
    uVar1 = (**(code **)(*(longlong *)param_1 + 0x70))(param_1);
    FUN_1800150c0(this,uVar1);
    FUN_18000d0b0(this);
    _Dst = (void *)0x0;
    if (*(int *)((longlong)*(void **)this + -4) != 0) {
      _Dst = *(void **)this;
    }
    _Src = (void *)(**(code **)(*(longlong *)param_1 + 0x68))(param_1);
    memcpy(_Dst,_Src,(ulonglong)uVar1);
    return;
  }
  OdError::OdError(local_res10,5);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res10,(ThrowInfo *)&DAT_180de52b8);
}



/* ==== 1809eab70 create ==== */

/* public: static class OdSmartPtr<class OdDgChunk> __cdecl OdDgChunk::create(class OdString const &
   __ptr64) */

OdString * __cdecl OdDgChunk::create(OdString *param_1)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  OdRxClass *pOVar4;
  longlong lVar5;
  undefined8 uVar6;
  OdRxClass *pOVar7;
  OdString *in_RDX;
  longlong *local_res10;
  longlong *local_res18;
  
                    /* 0x9eab70  5572
                       ?create@OdDgChunk@@SA?AV?$OdSmartPtr@VOdDgChunk@@@@AEBVOdString@@@Z */
  bVar1 = false;
  *(undefined8 *)param_1 = 0;
  lVar5 = *(longlong *)in_RDX;
  if ((*(int *)(lVar5 + 4) == 0) &&
     ((*(longlong *)(lVar5 + 0x18) == 0 || (*(int *)(*(longlong *)(lVar5 + 0x18) + -0xc) == 0)))) {
    bVar1 = true;
  }
  if (bVar1) {
    plVar3 = (longlong *)FUN_1809e4060(&local_res18);
    plVar3 = (longlong *)*plVar3;
    if (*(longlong **)param_1 != (longlong *)0x0) {
      (**(code **)(**(longlong **)param_1 + 0x28))();
      *(undefined8 *)param_1 = 0;
    }
    if (plVar3 != (longlong *)0x0) {
      lVar5 = *plVar3;
      pOVar4 = desc();
      lVar5 = (**(code **)(lVar5 + 8))(plVar3,pOVar4);
      if (lVar5 == 0) {
        pOVar4 = desc();
        pOVar7 = (OdRxClass *)(**(code **)(*plVar3 + 0x18))(plVar3);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_res10,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
      }
      *(longlong *)param_1 = lVar5;
    }
    if (local_res18 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 0x28))();
    }
    return param_1;
  }
  iVar2 = FUN_18010dcc0();
  if (iVar2 == 0) {
    plVar3 = (longlong *)FUN_1809e8690(&local_res18);
    plVar3 = (longlong *)*plVar3;
    if (*(longlong **)param_1 != (longlong *)0x0) {
      (**(code **)(**(longlong **)param_1 + 0x28))();
      *(undefined8 *)param_1 = 0;
    }
    if (plVar3 != (longlong *)0x0) {
      lVar5 = *plVar3;
      pOVar4 = desc();
      lVar5 = (**(code **)(lVar5 + 8))(plVar3,pOVar4);
      if (lVar5 == 0) {
        pOVar4 = desc();
        pOVar7 = (OdRxClass *)(**(code **)(*plVar3 + 0x18))(plVar3);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_res10,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
      }
      *(longlong *)param_1 = lVar5;
    }
    if (local_res18 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 0x28))();
    }
    return param_1;
  }
  iVar2 = FUN_18010dcc0();
  if (iVar2 != 0) {
    iVar2 = FUN_18010dcc0();
    if (iVar2 == 0) {
      uVar6 = FUN_1809e8690(&local_res10);
      FUN_1809eaae0(param_1,uVar6);
      if (local_res10 != (longlong *)0x0) {
        (**(code **)(*local_res10 + 0x28))();
      }
      return param_1;
    }
    iVar2 = FUN_18010dcc0();
    if (iVar2 != 0) {
      if ((*(longlong *)(*(longlong *)in_RDX + 0x10) != 0) ||
         (bVar1 = true, *(longlong *)(*(longlong *)in_RDX + 0x18) == 0)) {
        bVar1 = false;
      }
      if (bVar1) {
        OdString::syncUnicode(in_RDX);
      }
      if (**(short **)(*(longlong *)in_RDX + 0x10) != 0x24) {
        uVar6 = FUN_1809e4060(&local_res10);
        FUN_1809eaae0(param_1,uVar6);
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 0x28))();
        }
        return param_1;
      }
      uVar6 = FUN_1809e0ab0();
      FUN_1809eaae0(param_1,uVar6);
      if (local_res10 != (longlong *)0x0) {
        (**(code **)(*local_res10 + 0x28))();
      }
      return param_1;
    }
    uVar6 = FUN_1809e8690(&local_res10);
    FUN_1809eaae0(param_1,uVar6);
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x28))();
    }
    return param_1;
  }
  uVar6 = FUN_1809e8690(&local_res10);
  FUN_1809eaae0(param_1,uVar6);
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x28))();
  }
  return param_1;
}



/* ==== 1809eae90 createFromStream ==== */

/* public: static class OdSmartPtr<class OdDgChunk> __cdecl OdDgChunk::createFromStream(class
   OdSmartPtr<class OdDgOle2Stream>,bool) */

OdString * __cdecl
OdDgChunk::createFromStream
          (OdString *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  OdString local_res20 [8];
  undefined4 uVar2;
  longlong *local_20;
  
                    /* 0x9eae90  5608
                       ?createFromStream@OdDgChunk@@SA?AV?$OdSmartPtr@VOdDgChunk@@@@V?$OdSmartPtr@VOdDgOle2Stream@@@@_N@Z
                        */
  plVar1 = (longlong *)*param_2;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x60))(plVar1,local_res20,param_3,param_4,0);
    create(param_1);
    uVar2 = 1;
    OdString::~OdString(local_res20);
    plVar1 = *(longlong **)param_1;
    if (plVar1 != (longlong *)0x0) {
      local_20 = (longlong *)*param_2;
      if ((char)param_3 == '\0') {
        if (local_20 != (longlong *)0x0) {
          (**(code **)(*local_20 + 0x20))();
        }
        (**(code **)(*plVar1 + 0x88))(plVar1,local_res20,&local_20,param_4,uVar2);
      }
      else {
        if (local_20 != (longlong *)0x0) {
          (**(code **)(*local_20 + 0x20))();
        }
        (**(code **)(*plVar1 + 0x90))(plVar1,local_res20,&local_20);
      }
    }
    if ((longlong *)*param_2 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*param_2 + 0x28))();
      *param_2 = 0;
    }
    return param_1;
  }
  OdError::OdError((OdError *)local_res20,0x14);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
}



