// 18008edf0 templateGetPackedSize

undefined4 templateGetPackedSize(longlong *param_1)

{
  undefined4 uVar1;
  
                    /* 0x8edf0  26  templateGetPackedSize */
  FUN_180057ac0(&UNK_1800f0498);
  if ((param_1 != (longlong *)0x0) && (*param_1 != 0)) {
    uVar1 = FUN_1800a57c0();
    FUN_180057ac0(&UNK_1800f04b0,uVar1);
    return uVar1;
  }
  return 0;
}

