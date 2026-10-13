// 18008e660 getQuality

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void getQuality(longlong *param_1,int *param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_58 [32];
  int iStack_38;
  undefined8 uStack_34;
  undefined8 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong uStack_18;
  
                    /* 0x8e660  10  getQuality */
  uStack_18 = _DAT_18012a308 ^ (ulonglong)auStack_58;
  iStack_38 = 0;
  uStack_34 = 0;
  uStack_2c = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uVar3 = (((iRam0000000180159774 << 9 | uRam0000000180159770) << 0xb | uRam0000000180159778) << 2 |
          uRam0000000180159764) * 2 | uRam0000000180159768 | uRam0000000180159760;
  if ((param_1 != (longlong *)0x0) && (lVar1 = *param_1, lVar1 != 0)) {
    iStack_38 = (int)(short)param_1[1];
    iVar2 = (int)*(short *)((longlong)param_1 + 10);
    uStack_20 = (undefined4)lVar1;
    uStack_1c = (undefined4)((ulonglong)lVar1 >> 0x20);
    uStack_34 = CONCAT44(iVar2,iVar2);
    uStack_2c = CONCAT44(1,iVar2 * iStack_38);
    if ((uRam0000000180159778 == 1) || (uRam0000000180159778 == 8)) {
      *param_2 = iVar2 * iStack_38;
    }
    else {
      *param_2 = 0;
    }
    FUN_180092430(&iStack_38,uVar3,param_2 + 1,param_2);
    *(char *)(param_1 + 5) = (char)param_2[1];
    *(char *)((longlong)param_1 + 0x29) = (char)*param_2;
  }
  FUN_180086a70(uStack_18 ^ (ulonglong)auStack_58);
  return;
}

