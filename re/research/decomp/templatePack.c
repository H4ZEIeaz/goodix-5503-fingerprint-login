// 18008ee40 templatePack

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void templatePack(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStack_48 [32];
  undefined8 uStack_28;
  undefined4 auStack_20 [2];
  ulonglong uStack_18;
  
                    /* 0x8ee40  27  templatePack */
  uStack_18 = _DAT_18012a308 ^ (ulonglong)auStack_48;
  uStack_28 = 0;
  auStack_20[0] = 0;
  FUN_180057ac0(&UNK_1800f0438);
  if (((param_1 == (longlong *)0x0) || (param_2 == 0)) || (lVar1 = *param_1, lVar1 == 0)) {
    FUN_180057ac0(&UNK_1800f0448);
  }
  else {
    auStack_20[0] = FUN_1800a57c0(lVar1);
    iVar2 = FUN_1800a4570(&uStack_28,param_2,auStack_20,lVar1);
    if (iVar2 != 0) {
      FUN_180057ac0(&UNK_1800f0470,iVar2);
    }
  }
  FUN_180086a70(uStack_18 ^ (ulonglong)auStack_48);
  return;
}

