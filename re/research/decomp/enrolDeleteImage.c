// 18008e2a0 enrolDeleteImage

undefined8 enrolDeleteImage(longlong *param_1)

{
  longlong *plVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
                    /* 0x8e2a0  4  enrolDeleteImage */
  FUN_180057ac0(&UNK_1800f01a8);
  if ((((param_1 != (longlong *)0x0) && ((longlong *)*param_1 != (longlong *)0x0)) &&
      (plVar1 = *(longlong **)*param_1, plVar1 != (longlong *)0x0)) && (*plVar1 != 0)) {
    FUN_180090470();
    if (0 < *(short *)((longlong)param_1 + 10)) {
      sVar2 = *(short *)((longlong)param_1 + 10) + -1;
      *(short *)((longlong)param_1 + 10) = sVar2;
      iVar3 = (sVar2 * 100) / (int)(short)param_1[1];
      iVar4 = 100;
      if (iVar3 < 100) {
        iVar4 = iVar3;
      }
      *(int *)((longlong)param_1 + 0xc) = iVar4;
    }
    return 0;
  }
  FUN_180057ac0(&UNK_1800f0028);
  return 0x81;
}

