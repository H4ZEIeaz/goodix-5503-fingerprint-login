// 18008eef0 templateStudy

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void templateStudy(undefined4 *param_1)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined4 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  ulonglong uStack_10;
  
                    /* 0x8eef0  28  templateStudy */
  uStack_10 = _DAT_18012a308 ^ (ulonglong)auStack_48;
  if (param_1 == (undefined4 *)0x0) {
    FUN_180057ac0(&UNK_1800f0228);
    uRam0000000000000000 = 0;
    FUN_180090550(0x180153e80);
    FUN_180086a70(uStack_10 ^ (ulonglong)auStack_48);
    return;
  }
  uStack_18 = 0;
  uStack_14 = 0xffffffff;
  if (lRam0000000180153e88 != 0) {
    uStack_28 = 1;
    iVar1 = FUN_1800a0520(lRam0000000180153e88,uRam0000000180153e80,0x180153e90,&uStack_18);
    if (iVar1 != 0) {
      FUN_180057ac0(&UNK_1800f03c0,iVar1,uStack_18,uStack_14);
      *param_1 = uStack_18;
      FUN_180090550(0x180153e80);
      goto code_r0x00018008efda;
    }
  }
  *param_1 = uStack_18;
  FUN_180057ac0(&UNK_1800f0400,uStack_18,uStack_14);
  FUN_180090550(0x180153e80);
code_r0x00018008efda:
  FUN_180086a70(uStack_10 ^ (ulonglong)auStack_48);
  return;
}

