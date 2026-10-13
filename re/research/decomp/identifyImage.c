// 18008e870 identifyImage

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void identifyImage(longlong *param_1,undefined8 param_2,longlong *param_3,uint param_4,uint *param_5
                  ,int *param_6,uint *param_7,undefined4 param_8,byte param_9,ulonglong param_10)

{
  int iVar1;
  longlong lVar2;
  undefined *puVar3;
  uint uVar4;
  undefined1 auStack_e8 [32];
  uint uStack_c8;
  undefined8 uStack_c0;
  undefined1 *puStack_b8;
  undefined8 uStack_b0;
  ulonglong uStack_a8;
  undefined8 uStack_a0;
  int iStack_98;
  undefined8 uStack_94;
  int iStack_8c;
  int iStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  ulonglong uStack_70;
  undefined1 auStack_68 [8];
  undefined4 uStack_60;
  ulonglong uStack_40;
  
                    /* 0x8e870  12  identifyImage */
  uStack_40 = _DAT_18012a308 ^ (ulonglong)auStack_e8;
  uStack_70 = param_10;
  iStack_98 = 0;
  uStack_94 = 0;
  iStack_8c = 0;
  iStack_88 = 0;
  uStack_84 = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  iStack_78 = 0;
  lRam0000000180153e88 = 0;
  if ((((param_1 == (longlong *)0x0) || (param_3 == (longlong *)0x0)) || (param_5 == (uint *)0x0))
     || ((param_6 == (int *)0x0 || (param_7 == (uint *)0x0)))) {
    puVar3 = &UNK_1800f0228;
  }
  else {
    *param_6 = 0;
    *param_5 = 0xffffffff;
    if (*param_1 == 0) {
      puVar3 = &UNK_1800f0238;
    }
    else {
      if (((*(char *)((longlong)param_1 + 0xe) != '\b') ||
          (*(char *)((longlong)param_1 + 0xf) != '\x01')) || ((short)param_1[3] == 0)) {
        FUN_180057ac0(&UNK_1800f0250,(int)*(char *)((longlong)param_1 + 0xe),
                      (int)*(char *)((longlong)param_1 + 0xf),(short)param_1[3]);
        goto code_r0x00018008ebdc;
      }
      if ((longlong *)*param_3 == (longlong *)0x0) {
        puVar3 = &UNK_1800f0270;
      }
      else if (*(longlong *)*param_3 == 0) {
        puVar3 = &UNK_1800f0298;
      }
      else {
        if (param_4 != 0) {
          iStack_98 = (int)(short)param_1[1];
          uStack_94 = (ulonglong)(uint)(int)*(short *)((longlong)param_1 + 10);
          iStack_8c = *(short *)((longlong)param_1 + 10) * iStack_98;
          iStack_88 = 1;
          lVar2 = FUN_1800abe00((longlong)iStack_8c);
          uStack_80 = (undefined4)lVar2;
          uStack_7c = (undefined4)((ulonglong)lVar2 >> 0x20);
          if (lVar2 == 0) {
            FUN_180057ac0(&UNK_1800f02e0);
          }
          else {
            uStack_94 = CONCAT44(iStack_88 * (int)uStack_94,(int)uStack_94);
            FUN_1800abe20(lVar2,*param_1,
                          (longlong)
                          ((int)*(short *)((longlong)param_1 + 10) * (int)(short)param_1[1]));
            uStack_a0 = 0;
            param_7[1] = (uint)*(byte *)(param_1 + 5);
            *param_7 = (uint)*(byte *)((longlong)param_1 + 0x29);
            uStack_c0 = *(undefined8 *)*param_3;
            uStack_a8 = uStack_70;
            puStack_b8 = (undefined1 *)0x0;
            uStack_c8 = 1;
            uStack_b0 = param_2;
            iVar1 = FUN_180095d00(0x180153e80,&iStack_98,param_7[1]);
            if (iVar1 == 0) {
              uVar4 = 0;
              if (param_4 != 0) {
                do {
                  lVar2 = *(longlong *)*param_3;
                  if (lVar2 == 0) {
                    FUN_180057ac0(&UNK_1800f0310,uVar4);
                    FUN_1800abdf0(CONCAT44(uStack_7c,uStack_80));
                    goto code_r0x00018008ebdc;
                  }
                  uStack_b0 = 0;
                  puStack_b8 = auStack_68;
                  uStack_c0 = 0x180153e90;
                  uStack_60 = 0xffffffff;
                  uStack_c8 = (uint)param_9;
                  iVar1 = FUN_18009dab0(&iStack_78,uRam0000000180153e80,lVar2,param_8);
                  if (iVar1 != 0) {
                    FUN_180057ac0(&UNK_1800f0328,iVar1);
                    FUN_1800abdf0(CONCAT44(uStack_7c,uStack_80));
                    goto code_r0x00018008ebdc;
                  }
                  uStack_c0 = CONCAT44(uStack_c0._4_4_,uStack_60);
                  uStack_c8 = *(uint *)(lVar2 + 0x1c);
                  FUN_180057ac0(&UNK_1800f0350,uVar4,iStack_78,*(undefined4 *)(lVar2 + 0x20));
                  uStack_70 = uStack_70 & 0xffffffff00000000;
                  uStack_74 = 0;
                  FUN_1800a27d0(lVar2,&uStack_70,&uStack_74);
                  FUN_180057ac0(&UNK_1800f0398,uStack_70 & 0xffffffff,uStack_74);
                  if (0 < iStack_78) {
                    *param_6 = iStack_78;
                    lRam0000000180153e88 = lVar2;
                    *param_5 = uVar4;
                    FUN_1800abdf0(CONCAT44(uStack_7c,uStack_80));
                    goto code_r0x00018008ebdc;
                  }
                  uVar4 = uVar4 + 1;
                  param_3 = param_3 + 1;
                } while (uVar4 < param_4);
              }
              FUN_1800abdf0(CONCAT44(uStack_7c,uStack_80));
              *param_6 = iStack_78;
              *param_5 = 0xffffffff;
            }
            else {
              FUN_180057ac0(&UNK_1800f00f8,iVar1);
              FUN_1800abdf0(CONCAT44(uStack_7c,uStack_80));
            }
          }
          goto code_r0x00018008ebdc;
        }
        puVar3 = &UNK_1800f02d0;
      }
    }
  }
  FUN_180057ac0(puVar3);
code_r0x00018008ebdc:
  FUN_180086a70(uStack_40 ^ (ulonglong)auStack_e8);
  return;
}

