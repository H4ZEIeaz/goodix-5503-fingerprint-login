// 18008e580 getAlgorithmVersion

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void getAlgorithmVersion(longlong param_1)

{
  undefined8 uVar1;
  undefined1 auStack_38 [32];
  longlong lStack_18;
  ulonglong uStack_10;
  
                    /* 0x8e580  9  getAlgorithmVersion */
  uStack_10 = _DAT_18012a308 ^ (ulonglong)auStack_38;
  lStack_18 = 0;
  if (param_1 == 0) {
    FUN_180086a70(uStack_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180090690(&lStack_18,0x32,
                (((iRam0000000180159774 << 9 | uRam0000000180159770) << 0xb | uRam0000000180159778)
                 << 2 | uRam0000000180159764) * 2 | uRam0000000180159768 | uRam0000000180159760);
  if (lStack_18 == 0) {
    FUN_180086a70(uStack_10 ^ (ulonglong)auStack_38);
    return;
  }
  uVar1 = FUN_180090680();
  FUN_1800abef0(param_1,uVar1);
  FUN_180090170(&lStack_18);
  FUN_180086a70(uStack_10 ^ (ulonglong)auStack_38);
  return;
}

