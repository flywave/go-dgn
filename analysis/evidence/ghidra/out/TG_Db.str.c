/* ==== 18001f0d0 rdAnsiString ==== */

/* public: virtual class OdAnsiString __cdecl OdDgFileFiler::rdAnsiString(long) __ptr64 */

OdAnsiString * __thiscall OdDgFileFiler::rdAnsiString(OdDgFileFiler *this,long param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char *pcVar6;
  undefined4 in_register_00000014;
  OdAnsiString *this_00;
  int in_R8D;
  char local_res18 [8];
  char local_res20 [8];
  
                    /* 0x1f0d0  17816  ?rdAnsiString@OdDgFileFiler@@UEAA?AVOdAnsiString@@J@Z */
  this_00 = (OdAnsiString *)CONCAT44(in_register_00000014,param_1);
  OdAnsiString::init(this_00);
  if (in_R8D < 1) {
    if (in_R8D < 0) {
      FUN_1800150c0(this + 0x10,0);
      if (*(uint *)(*(longlong *)(this + 0x10) + -8) < 0x200) {
        LOCK();
        piVar1 = (int *)(*(longlong *)(this + 0x10) + -0x10);
        iVar2 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        FUN_18000ca40(this + 0x10,0x200,iVar2 < 2,1,1);
      }
      do {
        cVar5 = (**(code **)(*(longlong *)this + 0xa0))(this);
        uVar3 = *(uint *)(*(longlong *)(this + 0x10) + -4);
        LOCK();
        piVar1 = (int *)(*(longlong *)(this + 0x10) + -0x10);
        iVar2 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if ((iVar2 < 2) && (uVar3 != *(uint *)(*(longlong *)(this + 0x10) + -8))) {
LAB_18001f27c:
          *(char *)((ulonglong)uVar3 + *(longlong *)(this + 0x10)) = cVar5;
        }
        else {
          if (*(int *)(*(longlong *)(this + 0x10) + -4) != 0) {
            FUN_18000d0b0(this + 0x10);
            if ((*(int *)(*(char **)(this + 0x10) + -4) == 0) ||
               (*(char **)(this + 0x10) <= local_res18)) goto LAB_18001f1e9;
LAB_18001f260:
            FUN_18000ca40(this + 0x10,uVar3 + 1,iVar2 < 2,0,1);
            goto LAB_18001f27c;
          }
LAB_18001f1e9:
          if (*(int *)(*(longlong *)(this + 0x10) + -4) == 0) goto LAB_18001f260;
          FUN_18000d0b0(this + 0x10);
          uVar4 = *(uint *)(*(char **)(this + 0x10) + -4);
          pcVar6 = (char *)0x0;
          if (uVar4 != 0) {
            pcVar6 = *(char **)(this + 0x10);
          }
          if (pcVar6 + uVar4 <= local_res18) goto LAB_18001f260;
          local_res20[0] = cVar5;
          FUN_18000ca40(this + 0x10,uVar3 + 1,iVar2 < 2,0,1);
          memmove((void *)((ulonglong)uVar3 + *(longlong *)(this + 0x10)),local_res20,1);
        }
        *(int *)(*(longlong *)(this + 0x10) + -4) = *(int *)(*(longlong *)(this + 0x10) + -4) + 1;
      } while (cVar5 != '\0');
      FUN_18000d0b0(this + 0x10);
      pcVar6 = (char *)0x0;
      if (*(int *)(*(char **)(this + 0x10) + -4) != 0) {
        pcVar6 = *(char **)(this + 0x10);
      }
      OdAnsiString::operator=(this_00,pcVar6);
    }
  }
  else {
    pcVar6 = OdAnsiString::getBuffer(this_00,in_R8D + 1);
    pcVar6[in_R8D] = '\0';
    (**(code **)(*(longlong *)this + 0x90))(this,pcVar6,in_R8D);
    OdAnsiString::releaseBuffer(this_00,-1);
  }
  return this_00;
}



/* ==== 18001f9b0 rdUnicodeString ==== */

/* public: virtual class OdString __cdecl OdDgFileFiler::rdUnicodeString(long) __ptr64 */

OdString * __thiscall OdDgFileFiler::rdUnicodeString(OdDgFileFiler *this,long param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  undefined4 in_register_00000014;
  OdString *this_00;
  ushort *puVar3;
  int iVar4;
  int in_R8D;
  undefined8 in_R9;
  ushort *puVar5;
  longlong local_res20;
  undefined4 uVar6;
  
                    /* 0x1f9b0  17836  ?rdUnicodeString@OdDgFileFiler@@UEAA?AVOdString@@J@Z */
  this_00 = (OdString *)CONCAT44(in_register_00000014,param_1);
  puVar5 = (ushort *)0x0;
  OdString::init(this_00);
  uVar6 = 1;
  if (in_R8D < 1) {
    if (in_R8D < 0) {
      OdString::allocBeforeWrite(this_00,0x200);
      *(undefined4 *)(*(longlong *)this_00 + 4) = 0;
      uVar2 = (**(code **)(*(longlong *)this + 0xa8))(this);
      while (uVar2 != 0) {
        OdString::operator+=(this_00,uVar2);
        uVar2 = (**(code **)(*(longlong *)this + 0xa8))(this);
      }
    }
  }
  else {
    FUN_1800150c0(this + 0x10,in_R8D);
    uVar1 = *(undefined4 *)(*(longlong *)(this + 0x10) + -4);
    FUN_18000d0b0(this + 0x10);
    puVar3 = puVar5;
    if (*(int *)(*(ushort **)(this + 0x10) + -2) != 0) {
      puVar3 = *(ushort **)(this + 0x10);
    }
    (**(code **)(*(longlong *)this + 0x90))(this,puVar3,uVar1,in_R9,uVar6);
    FUN_18000d0b0(this + 0x10);
    puVar3 = puVar5;
    if (*(int *)(*(ushort **)(this + 0x10) + -2) != 0) {
      puVar3 = *(ushort **)(this + 0x10);
    }
    iVar4 = in_R8D >> 1;
    OdString::init((OdString *)&local_res20);
    if (iVar4 == -1) {
      OdString::operator=((OdString *)&local_res20,puVar3);
      if ((*(longlong *)(local_res20 + 0x10) == 0) && (*(longlong *)(local_res20 + 0x18) != 0)) {
        puVar5 = (ushort *)0x1;
      }
      if ((char)puVar5 != '\0') {
        OdString::syncUnicode((OdString *)&local_res20);
      }
    }
    else {
      puVar5 = OdString::getBuffer((OdString *)&local_res20,iVar4);
      memcpy(puVar5,puVar3,(longlong)iVar4 * 2);
      OdString::releaseBuffer((OdString *)&local_res20,iVar4);
    }
    OdString::operator=(this_00,(OdString *)&local_res20);
    OdString::~OdString((OdString *)&local_res20);
    OdString::releaseBuffer(this_00,-1);
  }
  return this_00;
}



