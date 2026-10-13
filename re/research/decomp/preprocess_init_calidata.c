// 18008f280 preprocess_init_calidata

undefined8 preprocess_init_calidata(void)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  
                    /* 0x8f280  17  preprocess_init_calidata */
  FUN_180057ac0(&UNK_1800f0b28);
  uVar1 = uRam0000000180159774;
  if (uRam0000000180159770 != 0) {
    uVar4 = (ulonglong)uRam0000000180159774;
    uVar5 = 0;
    uVar6 = (ulonglong)uRam0000000180159770;
    do {
      uVar3 = uVar4;
      uVar2 = uVar5;
      if (uVar1 != 0) {
        do {
          *(undefined2 *)((ulonglong)uVar2 * 2 + 0x180159784) = 0x2000;
          *(undefined2 *)((ulonglong)uVar2 * 2 + 0x1801630a4) = 0;
          uVar3 = uVar3 - 1;
          uVar2 = uVar2 + 1;
        } while (uVar3 != 0);
      }
      uVar5 = uVar5 + uVar1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  uRam0000000180159780 = 0;
  FUN_180082250(0x18017fc08,0,0xa000);
  uRam0000000180189c08 = 0;
  return 0;
}

