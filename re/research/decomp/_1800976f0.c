
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800976f0(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4,
                  int *param_5)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  uint uVar7;
  int *piVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  int iVar13;
  undefined1 auStack_428 [32];
  char *pcStack_408;
  int *piStack_400;
  int *piStack_3f8;
  int *piStack_3f0;
  undefined4 uStack_3e8;
  undefined8 uStack_3e0;
  longlong lStack_3d8;
  longlong lStack_3d0;
  longlong lStack_3c8;
  undefined8 uStack_3c0;
  int iStack_3b8;
  int aiStack_3b4 [3];
  undefined8 uStack_3a8;
  undefined8 uStack_3a0;
  undefined8 uStack_398;
  undefined8 uStack_390;
  undefined8 uStack_388;
  undefined8 uStack_380;
  int aiStack_378 [64];
  uint auStack_278 [64];
  uint auStack_178 [64];
  char acStack_78 [32];
  ulonglong uStack_58;
  ulonglong uVar8;
  
  uStack_58 = _DAT_18012a308 ^ (ulonglong)auStack_428;
  lVar3 = *(longlong *)(param_2 + 0xf8);
  iVar13 = 0;
  uStack_390 = _UNK_1800f0fc0;
  uStack_388 = _UNK_1800f0fc8;
  *param_5 = 0;
  plVar12 = (longlong *)(param_1 + 0x28);
  uStack_380 = 0x100;
  lStack_3d8 = lVar3;
  lStack_3d0 = param_2;
  lStack_3c8 = param_4;
  uStack_3c0 = param_3;
  if (0 < *(int *)(param_1 + 0x1c) + -1) {
    do {
      iVar6 = 0;
      lVar2 = *plVar12;
      FUN_1800abeb0(aiStack_378,0xffffffff,0xf8);
      FUN_1800abeb0(auStack_278,0,0xf8);
      FUN_1800abeb0(auStack_178,0,0xf8);
      FUN_1800c0720(lVar2,lStack_3d0,aiStack_378);
      uVar5 = 0;
      piVar9 = aiStack_378 + 1;
      uVar8 = uVar5;
      uVar10 = uVar5;
      do {
        uVar11 = uVar10;
        if (-1 < aiStack_378[(int)uVar8 * 2]) {
          iVar1 = *piVar9;
          lVar4 = (longlong)aiStack_378[(int)uVar8 * 2] * 0x38;
          iVar6 = iVar6 + 1;
          uVar11 = uVar10 + 8;
          *(uint *)((longlong)auStack_178 + uVar10) =
               (uint)*(ushort *)((longlong)iVar1 * 0x38 + 2 + lVar3);
          *(uint *)((longlong)auStack_178 + uVar10 + 4) =
               (uint)*(ushort *)((longlong)iVar1 * 0x38 + 4 + lVar3);
          *(uint *)((longlong)auStack_278 + uVar10) =
               (uint)*(ushort *)(lVar4 + 2 + *(longlong *)(lVar2 + 0xf8));
          *(uint *)((longlong)auStack_278 + uVar10 + 4) =
               (uint)*(ushort *)(lVar4 + 4 + *(longlong *)(lVar2 + 0xf8));
        }
        uVar7 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar7;
        piVar9 = piVar9 + 2;
        uVar10 = uVar11;
      } while ((int)uVar7 < 0x1f);
      if (iVar6 < 5) {
        *(undefined4 *)((ulonglong)*(uint *)(param_1 + 0x24) * 0x1c + 0x1b8 + param_1) = 0xffffffff;
        FUN_1800abe60((ulonglong)*(uint *)(param_1 + 0x24) * 0x1c + 0x1bc + param_1,&uStack_390,0x18
                     );
      }
      else {
        acStack_78[1] = '\0';
        acStack_78[2] = '\0';
        acStack_78[3] = '\0';
        acStack_78[4] = '\0';
        acStack_78[5] = '\0';
        acStack_78[6] = '\0';
        acStack_78[7] = '\0';
        acStack_78[8] = '\0';
        acStack_78[9] = '\0';
        acStack_78[10] = '\0';
        acStack_78[0xb] = '\0';
        acStack_78[0xc] = '\0';
        acStack_78[0xd] = '\0';
        acStack_78[0xe] = '\0';
        acStack_78[0xf] = '\0';
        acStack_78[0x10] = '\0';
        acStack_78[0x11] = '\0';
        acStack_78[0x12] = '\0';
        acStack_78[0x13] = '\0';
        acStack_78[0x14] = '\0';
        acStack_78[0x15] = '\0';
        acStack_78[0x16] = '\0';
        acStack_78[0x17] = '\0';
        acStack_78[0x18] = '\0';
        uStack_3a8 = _UNK_1800f0fc0;
        uStack_3a0 = _UNK_1800f0fc8;
        acStack_78[0x19] = '\0';
        acStack_78[0x1a] = '\0';
        acStack_78[0x1b] = '\0';
        acStack_78[0x1c] = '\0';
        acStack_78[0x1d] = '\0';
        acStack_78[0x1e] = '\0';
        piStack_400 = aiStack_3b4 + 1;
        pcStack_408 = acStack_78;
        uStack_398 = 0x100;
        acStack_78[0] = '\0';
        aiStack_3b4[1] = 0;
        FUN_1800c02b0(auStack_178,auStack_278,iVar6,&uStack_3a8);
        lVar3 = 0;
        do {
          if (acStack_78[lVar3] != '\0') {
            uVar5 = (ulonglong)((int)uVar5 + 1);
          }
          lVar3 = lVar3 + 1;
        } while (lVar3 < 0x1f);
        aiStack_3b4[0] = 0;
        iStack_3b8 = 0;
        iVar6 = (int)uVar5;
        if (4 < iVar6) {
          uStack_3e0 = 0;
          uStack_3e8 = 0;
          piStack_3f0 = &iStack_3b8;
          piStack_3f8 = aiStack_3b4;
          piStack_400 = (int *)0x0;
          pcStack_408 = (char *)0x0;
          FUN_1800ba280(lStack_3d0,lVar2,&uStack_3a8,uStack_3c0);
        }
        if ((((iVar6 < 7) || (aiStack_3b4[0] < 0xd1)) || (iStack_3b8 < 0x41)) &&
           ((iVar6 < 0xb && ((aiStack_3b4[0] < 0xd8 || (iVar6 < 6)))))) {
          *(undefined4 *)((ulonglong)*(uint *)(param_1 + 0x24) * 0x1c + 0x1b8 + param_1) =
               0xffffffff;
          FUN_1800abe60((ulonglong)*(uint *)(param_1 + 0x24) * 0x1c + 0x1bc + param_1,&uStack_390,
                        0x18);
          lVar3 = lStack_3d8;
        }
        else {
          *(int *)((ulonglong)*(uint *)(param_1 + 0x24) * 0x1c + 0x1b8 + param_1) = iVar6;
          FUN_1800abe60((ulonglong)*(uint *)(param_1 + 0x24) * 0x1c + 0x1bc + param_1,&uStack_3a8,
                        0x18);
          *(int *)(lStack_3c8 + (longlong)*param_5 * 4) = iVar13;
          *param_5 = *param_5 + 1;
          lVar3 = lStack_3d8;
        }
      }
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
      iVar13 = iVar13 + 1;
      plVar12 = plVar12 + 1;
    } while (iVar13 < *(int *)(param_1 + 0x1c) + -1);
  }
  FUN_180086a70(uStack_58 ^ (ulonglong)auStack_428);
  return;
}

