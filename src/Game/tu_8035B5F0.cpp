#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern u32 lbl_804AD3A0[48];
extern const f32 lbl_805428E8;
extern const f32 lbl_805428EC;
extern u32 *lbl_804AD460[];
extern "C" void fn_8035BE00(u8 *param_1) {
  f32 v = *(f32 *)(param_1 + 0x254);
  if (v > lbl_805428E8) {
    *(f32 *)(param_1 + 0x254) = v - lbl_805428EC;
  }
}

extern "C" void fn_8035BE20(void) {
}

u32 fn_8035C15C(u8 *param_1, s32 param_2) {
  if (*(s32 *)(param_1 + 0x244) == 0) {
    u8 *base = (u8 *)lbl_804AD460[param_2];
    if (*(s32 *)(base + *(s32 *)(param_1 + 0x24c) * 8) < 0) {
      return 1;
    }
    *(u32 *)(param_1 + 0x244) = *(u32 *)(base + *(s32 *)(param_1 + 0x24c) * 8 + 4);
    *(u32 *)(param_1 + 0x248) = *(u32 *)(base + *(s32 *)(param_1 + 0x24c) * 8);
    *(s32 *)(param_1 + 0x24c) = *(s32 *)(param_1 + 0x24c) + 1;
  }
  return 0;
}

void fn_8035C1C4(u8 *param_1, s32 param_2, u32 param_3) {
  *(u32 *)(param_1 + 0x250) = param_3;
  *(u32 *)(param_1 + 0x244) = 0;
  *(u32 *)(param_1 + 0x24c) = 0;
  if (*(s32 *)(param_1 + 0x244) != 0) {
    return;
  }
  {
    u8 *base = (u8 *)lbl_804AD460[param_2];
    if (*(s32 *)(base + *(s32 *)(param_1 + 0x24c) * 8) < 0) {
      return;
    }
    *(u32 *)(param_1 + 0x244) = *(u32 *)(base + *(s32 *)(param_1 + 0x24c) * 8 + 4);
    *(u32 *)(param_1 + 0x248) = *(u32 *)(base + *(s32 *)(param_1 + 0x24c) * 8);
    *(s32 *)(param_1 + 0x24c) = *(s32 *)(param_1 + 0x24c) + 1;
  }
}

void fn_8035C650(void) {
  u32 *src = lbl_804AD3A0;
  u32 *dst = lbl_804AD3A0 + 24;
  for (s32 i = 0; i < 24; i++) {
    dst[i] = src[i];
  }
}
