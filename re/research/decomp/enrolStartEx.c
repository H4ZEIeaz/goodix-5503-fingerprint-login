// 18008e410 enrolStartEx

undefined8 * enrolStartEx(int *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined *puVar6;
  uint uVar7;
  
                    /* 0x8e410  8  enrolStartEx */
  if (iRam000000018015977c != 1) {
    FUN_180057ac0(&UNK_1800efe48);
    return (undefined8 *)0x0;
  }
  uVar7 = (((iRam0000000180159774 << 9 | uRam0000000180159770) << 0xb | uRam0000000180159778) << 2 |
          uRam0000000180159764) * 2 | uRam0000000180159768 | uRam0000000180159760;
  puVar2 = (undefined8 *)FUN_1800abe00(0x20);
  puVar3 = (undefined8 *)FUN_1800abe00(8);
  plVar4 = (longlong *)FUN_1800abe00(8);
  if ((((puVar2 == (undefined8 *)0x0) || (puVar3 == (undefined8 *)0x0)) ||
      (plVar4 == (longlong *)0x0)) || (param_1 == (int *)0x0)) {
    puVar6 = &UNK_1800efe78;
  }
  else {
    FUN_1800abe40(puVar2,0,0x20);
    *(undefined4 *)(puVar2 + 1) = 8;
    *puVar2 = puVar3;
    if (0x32 < *param_1) {
      *param_1 = 0x32;
    }
    iVar1 = FUN_180090690(plVar4,*param_1,uVar7,0);
    if ((*plVar4 != 0) && (iVar1 == 0)) {
      *param_1 = *(int *)(*plVar4 + 0x20);
      FUN_180057ac0(&UNK_1800efeb8);
      *puVar3 = plVar4;
      uVar5 = FUN_180090680(*plVar4);
      FUN_180057ac0(&UNK_1800efed8,uVar5);
      return puVar2;
    }
    puVar6 = &UNK_1800efe98;
  }
  FUN_180057ac0(puVar6);
  FUN_1800abdf0(puVar2);
  FUN_1800abdf0(puVar3);
  FUN_1800abdf0(plVar4);
  return (undefined8 *)0x0;
}

