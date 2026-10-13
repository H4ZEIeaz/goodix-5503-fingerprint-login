// 18008fc50 preprocessor_get_CalibParam

undefined8 preprocessor_get_CalibParam(undefined8 *param_1,undefined4 *param_2)

{
                    /* 0x8fc50  23  preprocessor_get_CalibParam */
  FUN_180057ac0(&UNK_1800f09c8);
  if ((param_1 != (undefined8 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    *param_1 = 0x180159780;
    *param_2 = 0x3048c;
    return 0;
  }
  return 0x80;
}

