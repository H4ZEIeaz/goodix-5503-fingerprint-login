// 18008dfd0 enrolAddImage

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void enrolAddImage(longlong *param_1,longlong *param_2,undefined8 param_3,undefined8 param_4,
                  uint *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  undefined1 auStack_d8 [32];
  undefined4 uStack_b8;
  longlong lStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  int iStack_80;
  undefined8 uStack_7c;
  int iStack_74;
  int iStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint auStack_60 [2];
  ulonglong uStack_58;
  
                    /* 0x8dfd0  3  enrolAddImage */
  uStack_58 = _DAT_18012a308 ^ (ulonglong)auStack_d8;
  uStack_7c = 0;
  iStack_74 = 0;
  iStack_70 = 0;
  iStack_80 = 0;
  uStack_88 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  if (((((param_1 == (longlong *)0x0) || ((longlong *)*param_1 == (longlong *)0x0)) ||
       (plVar1 = *(longlong **)*param_1, plVar1 == (longlong *)0x0)) ||
      ((lVar2 = *plVar1, lVar2 == 0 || (param_2 == (longlong *)0x0)))) || (param_5 == (uint *)0x0))
  {
    FUN_180057ac0(&UNK_1800f0028);
  }
  else if (((*(char *)((longlong)param_2 + 0xe) == '\b') &&
           (*(char *)((longlong)param_2 + 0xf) == '\x01')) && ((short)param_2[3] != 0)) {
    if (*param_2 == 0) {
      FUN_180057ac0(&UNK_1800f00b0);
    }
    else {
      iStack_80 = (int)(short)param_2[1];
      uStack_7c = (ulonglong)(uint)(int)*(short *)((longlong)param_2 + 10);
      iStack_74 = *(short *)((longlong)param_2 + 10) * iStack_80;
      iStack_70 = 1;
      lVar6 = FUN_1800abe00((longlong)iStack_74);
      uStack_68 = (undefined4)lVar6;
      uStack_64 = (undefined4)((ulonglong)lVar6 >> 0x20);
      if (lVar6 == 0) {
        FUN_180057ac0(&UNK_1800f00d8);
      }
      else {
        uStack_7c = CONCAT44(iStack_70 * (int)uStack_7c,(int)uStack_7c);
        FUN_1800abe20(lVar6,*param_2,(longlong)iStack_74);
        param_5[1] = (uint)*(byte *)(param_2 + 5);
        *param_5 = (uint)*(byte *)((longlong)param_2 + 0x29);
        if (*(short *)((longlong)param_1 + 10) < (short)param_1[1]) {
          uStack_90 = 0;
          uStack_a8 = 0;
          uStack_b8 = 0;
          auStack_60[0] = 0;
          lStack_b0 = lVar2;
          uStack_a0 = param_3;
          uStack_98 = param_4;
          iVar3 = FUN_180095d00(&uStack_88,&iStack_80,param_5[1]);
          if (iVar3 != 0) {
            FUN_180057ac0(&UNK_1800f00f8,iVar3);
            FUN_1800abdf0(CONCAT44(uStack_64,uStack_68));
            goto DAT_18008e17d;
          }
          iVar3 = FUN_180097d90(auStack_60,uStack_88,lVar2,(undefined4 *)((longlong)param_2 + 0x1c))
          ;
          if (iVar3 != 0) {
            FUN_180057ac0(&UNK_1800f0118,iVar3);
            FUN_180057ac0(&UNK_1800f0150,&UNK_1800f0140,iVar3,
                          *(undefined4 *)((longlong)param_2 + 0x1c));
            FUN_180090550(&uStack_88);
            FUN_1800abdf0(CONCAT44(uStack_64,uStack_68));
            goto DAT_18008e17d;
          }
          *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + 1;
          *(uint *)(param_1 + 2) = 100 - (auStack_60[0] >> 0x18);
          *(uint *)((longlong)param_1 + 0x14) = 100 - (auStack_60[0] & 0xff);
          FUN_180090550(&uStack_88);
        }
        FUN_1800abdf0(CONCAT44(uStack_64,uStack_68));
        iVar4 = *(short *)((longlong)param_1 + 10) * 100;
        iVar5 = iVar4 / (int)(short)param_1[1];
        iVar3 = 100;
        if (iVar5 < 100) {
          iVar3 = iVar5;
        }
        *(int *)((longlong)param_1 + 0xc) = iVar3;
        if (iVar3 == 100) {
          FUN_180057ac0(&UNK_1800f0190,
                        (longlong)iVar4 % (longlong)(int)(short)param_1[1] & 0xffffffff);
        }
      }
    }
  }
  else {
    FUN_180057ac0(&UNK_1800f0048,(int)*(char *)((longlong)param_2 + 0xe),
                  (int)*(char *)((longlong)param_2 + 0xf),(short)param_2[3]);
    FUN_180057ac0(&UNK_1800f0088);
  }
DAT_18008e17d:
  FUN_180086a70(uStack_58 ^ (ulonglong)auStack_d8);
  return;
}

