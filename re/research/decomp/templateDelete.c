// 18008ed60 templateDelete

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void templateDelete(longlong *param_1)

{
  undefined1 auStack_38 [32];
  longlong lStack_18;
  ulonglong uStack_10;
  
                    /* 0x8ed60  25  templateDelete */
  uStack_10 = _DAT_18012a308 ^ (ulonglong)auStack_38;
  lStack_18 = 0;
  FUN_180057ac0(&UNK_1800f0530);
  if ((param_1 != (longlong *)0x0) && (*param_1 != 0)) {
    lStack_18 = *param_1;
    FUN_180090170(&lStack_18);
    FUN_1800abdf0(param_1);
    FUN_180086a70(uStack_10 ^ (ulonglong)auStack_38);
    return;
  }
  FUN_180057ac0(&UNK_1800f0540);
  FUN_180086a70(uStack_10 ^ (ulonglong)auStack_38);
  return;
}

