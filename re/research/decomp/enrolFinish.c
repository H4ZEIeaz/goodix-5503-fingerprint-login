// 18008e320 enrolFinish

undefined8 enrolFinish(undefined8 *param_1)

{
  undefined8 uVar1;
  
                    /* 0x8e320  5  enrolFinish */
  FUN_180057ac0(&UNK_1800f01f8);
  if (param_1 == (undefined8 *)0x0) {
    FUN_180057ac0(&UNK_1800f0208);
    return 0x81;
  }
  uVar1 = *(undefined8 *)*param_1;
  FUN_180090170(uVar1);
  FUN_1800abdf0(uVar1);
  FUN_1800abdf0(*param_1);
  *param_1 = 0;
  FUN_1800abdf0(param_1);
  return 0;
}

