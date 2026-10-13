// 18008f000 templateUnPack

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void templateUnPack(longlong param_1,int param_2,undefined8 param_3,longlong *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStack_68 [32];
  longlong lStack_48;
  undefined8 uStack_40;
  int aiStack_38 [2];
  ulonglong uStack_30;
  
                    /* 0x8f000  29  templateUnPack */
  uStack_30 = _DAT_18012a308 ^ (ulonglong)auStack_68;
  uStack_40 = 0;
  lStack_48 = 0;
  aiStack_38[0] = param_2;
  FUN_180057ac0(&UNK_1800f04d0);
  if (((param_1 != 0) && (param_4 != (longlong *)0x0)) && (param_2 != 0)) {
    puVar2 = (undefined8 *)FUN_1800abe00(8);
    if (puVar2 == (undefined8 *)0x0) {
      FUN_180057ac0(&UNK_1800f04f0);
    }
    else {
      lStack_48 = param_1;
      iVar1 = FUN_1800a32f0(&lStack_48,aiStack_38,&uStack_40,param_3);
      if (iVar1 == 0) {
        *puVar2 = uStack_40;
        FUN_180057ac0(&UNK_1800f0518);
        *param_4 = (longlong)puVar2;
      }
      else {
        FUN_1800abdf0(puVar2);
      }
    }
  }
  FUN_180086a70(uStack_30 ^ (ulonglong)auStack_68);
  return;
}

