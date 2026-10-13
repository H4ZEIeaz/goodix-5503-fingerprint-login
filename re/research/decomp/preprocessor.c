// 18008fa30 preprocessor

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void preprocessor(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 longlong *param_5,undefined4 *param_6,char param_7)

{
  undefined4 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 auStack_a8 [32];
  uint uStack_88;
  undefined8 uStack_80;
  undefined4 uStack_78;
  undefined4 *puStack_70;
  undefined4 *puStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  longlong lStack_38;
  ulonglong uStack_30;
  
                    /* 0x8fa30  21  preprocessor */
  uStack_30 = _DAT_18012a308 ^ (ulonglong)auStack_a8;
  uVar3 = 0;
  lStack_38 = 0;
  if ((param_1 == (undefined8 *)0x0) || (param_5 == (longlong *)0x0)) {
    FUN_180057ac0(&UNK_1800f09e8,param_1,param_5);
  }
  else if (iRam000000018015977c == 1) {
    if (iRam0000000180189c0c == 1) {
      uStack_48 = 0;
      puStack_68 = param_6;
      uRam000000018017fc04 = 0;
      if (param_7 == '\x01') {
        uRam000000018017fc04 = 2;
      }
      puVar1 = param_6 + 1;
      uStack_78 = uRam000000018015976c;
      uStack_80 = 0x180189c0c;
      uStack_88 = (((iRam0000000180159774 << 9 | uRam0000000180159770) << 0xb | uRam0000000180159778
                   ) << 2 | uRam0000000180159764) * 2 | uRam0000000180159768 | uRam0000000180159760;
      puStack_70 = puVar1;
      uStack_60 = param_2;
      uStack_58 = param_3;
      uStack_50 = param_4;
      FUN_1800aee90(&lStack_38,*param_1,*(undefined4 *)((longlong)param_1 + 0x14),0x180159780);
      FUN_180057ac0(&UNK_1800f0a30,*puVar1,*param_6);
      *(undefined1 *)(param_5 + 5) = *(undefined1 *)puVar1;
      *(undefined1 *)((longlong)param_5 + 0x29) = *(undefined1 *)param_6;
      if (lStack_38 != 0) {
        lVar2 = *(longlong *)(lStack_38 + 0x18);
        uVar5 = uVar3;
        if (*(int *)((longlong)param_5 + 0x14) != 0) {
          do {
            uVar4 = (int)uVar5 + 1;
            *(undefined1 *)(uVar3 + *param_5) = *(undefined1 *)(uVar3 + lVar2);
            uVar3 = uVar3 + 1;
            uVar5 = (ulonglong)uVar4;
          } while (uVar4 < *(uint *)((longlong)param_5 + 0x14));
        }
        FUN_1800acaf0(&lStack_38);
      }
    }
    else {
      FUN_180057ac0(&UNK_1800f0a10);
    }
  }
  else {
    FUN_180057ac0(&UNK_1800f08a0);
  }
  FUN_180086a70(uStack_30 ^ (ulonglong)auStack_a8);
  return;
}

