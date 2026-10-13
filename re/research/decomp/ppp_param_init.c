// 18008f0e0 ppp_param_init

undefined8 ppp_param_init(int param_1)

{
  longlong lVar1;
  
                    /* 0x8f0e0  15  ppp_param_init */
  if (0xb < (ulonglong)(longlong)param_1) {
    FUN_180057ac0(&UNK_1800f0838);
    return 0x81;
  }
  lVar1 = (longlong)param_1 * 0x20;
  uRam000000018015977c = 1;
  uRam0000000180159760 = *(undefined4 *)(&UNK_1800f0574 + lVar1);
  uRam0000000180159764 = *(undefined4 *)(&UNK_1800f0578 + lVar1);
  uRam0000000180159768 = *(undefined4 *)(&UNK_1800f057c + lVar1);
  uRam000000018015976c = *(undefined4 *)(&UNK_1800f0580 + lVar1);
  uRam0000000180159770 = *(undefined4 *)(&UNK_1800f0584 + lVar1);
  uRam0000000180159774 = *(undefined4 *)(&UNK_1800f0588 + lVar1);
  uRam0000000180159778 = *(undefined4 *)(&UNK_1800f058c + lVar1);
  FUN_180057ac0(&UNK_1800f0868,param_1);
  return 0;
}

