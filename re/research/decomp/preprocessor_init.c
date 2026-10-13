// 18008fcb0 preprocessor_init

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void preprocessor_init(longlong param_1)

{
  uint uVar1;
  undefined1 auStack_98 [32];
  uint uStack_78;
  undefined8 uStack_70;
  uint uStack_68;
  undefined1 *puStack_60;
  undefined1 *puStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  longlong lStack_28;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  ulonglong uStack_18;
  
                    /* 0x8fcb0  24  preprocessor_init */
  uStack_18 = _DAT_18012a308 ^ (ulonglong)auStack_98;
  lStack_28 = 0;
  FUN_180057ac0(&UNK_1800f0880);
  if (param_1 != 0) {
    if (iRam000000018015977c == 1) {
      uVar1 = (((iRam0000000180159774 << 9 | uRam0000000180159770) << 0xb | uRam0000000180159778) <<
               2 | uRam0000000180159764) * 2 | uRam0000000180159768 | uRam0000000180159760;
      FUN_180057ac0(&UNK_1800f08c0,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x24),
                    *(undefined8 *)(param_1 + 0x18));
      FUN_180057ac0(&UNK_1800f08e8);
      FUN_180057ac0(&UNK_1800f0910,uRam0000000180159760,uRam0000000180159764,uRam0000000180159768);
      FUN_180057ac0(&UNK_1800f0960,uRam000000018015976c);
      FUN_180057ac0(&UNK_1800f0988,uRam0000000180159770,iRam0000000180159774);
      uRam0000000180189c0c = 0;
      if (*(longlong *)(param_1 + 0x18) != 0) {
        uStack_38 = 0;
        uStack_40 = 0;
        uStack_48 = 0;
        uStack_50 = 0;
        puStack_58 = auStack_20;
        puStack_60 = auStack_1c;
        uStack_68 = uRam000000018015976c;
        uStack_70 = 0x180189c0c;
        uStack_78 = uVar1;
        FUN_1800aee90(&lStack_28,*(longlong *)(param_1 + 0x18),
                      *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x28) * 2,0x180159780);
        if (lStack_28 != 0) {
          FUN_1800acaf0(&lStack_28);
        }
      }
      uStack_68 = (uint)uRam00000001801640a4;
      uStack_78 = (uint)uRam000000018015a784;
      uStack_70 = CONCAT44(uStack_70._4_4_,(uint)uRam00000001801632a4);
      FUN_180057ac0(&UNK_1800f06f0,uRam0000000180189c0c,uRam0000000180159780,uRam0000000180159984);
    }
    else {
      FUN_180057ac0(&UNK_1800f08a0);
    }
  }
  FUN_180086a70(uStack_18 ^ (ulonglong)auStack_98);
  return;
}

