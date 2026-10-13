// 18008e760 gx_sensorCheck

undefined8 gx_sensorCheck(longlong *param_1,longlong *param_2,longlong param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
                    /* 0x8e760  11  gx_sensorCheck */
  if (((param_1 != (longlong *)0x0) && (param_2 != (longlong *)0x0)) && (param_3 != 0)) {
    if ((((*(char *)((longlong)param_1 + 0xe) == '\x10') &&
         (*(char *)((longlong)param_1 + 0xf) == '\x01')) &&
        (((short)param_1[3] != 0 &&
         ((*(char *)((longlong)param_2 + 0xe) == '\x10' &&
          (*(char *)((longlong)param_2 + 0xf) == '\x01')))))) && ((short)param_2[3] != 0)) {
      if ((*param_1 != 0) && (*param_2 != 0)) {
        uVar1 = FUN_1800a88b0(*param_1,*param_2,param_4,param_3,
                              (((iRam0000000180159774 << 9 | uRam0000000180159770) << 0xb |
                               uRam0000000180159778) << 2 | uRam0000000180159764) * 2 |
                              uRam0000000180159768 | uRam0000000180159760,0);
        return uVar1;
      }
      FUN_180057ac0(&UNK_1800f0008);
      return 0x81;
    }
    FUN_180057ac0(&UNK_1800eff00,(int)*(char *)((longlong)param_1 + 0xe),
                  (int)*(char *)((longlong)param_1 + 0xf),(short)param_1[3]);
    FUN_180057ac0(&UNK_1800eff50,(int)*(char *)((longlong)param_2 + 0xe),
                  (int)*(char *)((longlong)param_2 + 0xf),(short)param_2[3]);
    FUN_180057ac0(&UNK_1800effa0);
  }
  return 0x81;
}

