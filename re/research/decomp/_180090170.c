
undefined8 FUN_180090170(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  
  if ((param_1 != (longlong *)0x0) && (*param_1 != 0)) {
    iVar2 = 0;
    if (0 < *(int *)(*param_1 + 0x20)) {
      lVar4 = 0x28;
      do {
        plVar1 = (longlong *)(*param_1 + lVar4);
        if ((plVar1 != (longlong *)0x0) && (lVar3 = *plVar1, lVar3 != 0)) {
          if (*(longlong *)(lVar3 + 8) != 0) {
            FUN_1800acaf0(lVar3 + 8);
          }
          *(undefined8 *)(*plVar1 + 8) = 0;
          if (*(longlong *)(*plVar1 + 0x10) != 0) {
            FUN_1800acaf0();
          }
          *(undefined8 *)(*plVar1 + 0x10) = 0;
          if (*(longlong *)(*plVar1 + 0x18) != 0) {
            FUN_1800acaf0();
          }
          *(undefined8 *)(*plVar1 + 0x18) = 0;
          if (*(longlong *)(*plVar1 + 0x20) != 0) {
            FUN_1800acaf0();
          }
          *(undefined8 *)(*plVar1 + 0x20) = 0;
          if (*(longlong *)(*plVar1 + 0xf8) != 0) {
            FUN_180082260();
          }
          *(undefined8 *)(*plVar1 + 0xf8) = 0;
          if (*(longlong *)(*plVar1 + 0x130) != 0) {
            FUN_1800acaf0();
          }
          *(undefined8 *)(*plVar1 + 0x130) = 0;
          if (*(longlong *)(*plVar1 + 0x158) != 0) {
            FUN_1800acaf0();
          }
          *(undefined8 *)(*plVar1 + 0x158) = 0;
          FUN_180082260(*plVar1);
          *plVar1 = 0;
        }
        iVar2 = iVar2 + 1;
        lVar4 = lVar4 + 8;
      } while (iVar2 < *(int *)(*param_1 + 0x20));
    }
    lVar4 = 0x8d10;
    lVar3 = 0x14;
    do {
      FUN_180090550(*param_1 + lVar4);
      lVar4 = lVar4 + 8;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    FUN_180082260(*param_1);
    *param_1 = 0;
    return 0;
  }
  return 0x80000002;
}

