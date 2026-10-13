// 18008e390 enrolGetTemplate

undefined8 enrolGetTemplate(longlong *param_1,undefined8 *param_2)

{
                    /* 0x8e390  6  enrolGetTemplate */
  FUN_180057ac0(&UNK_1800f01c0);
  if ((param_1 != (longlong *)0x0) && ((undefined8 *)*param_1 != (undefined8 *)0x0)) {
    *param_2 = *(undefined8 *)*param_1;
    return 0;
  }
  FUN_180057ac0(&UNK_1800f01d8);
  return 0x81;
}

