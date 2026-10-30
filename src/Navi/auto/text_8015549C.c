#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015549c-0x801554e0 (1 functions). split_file divides it into the game's real files.

extern s32 lbl_802FF4CC;
extern s32 lbl_802FF4D0;
extern s32 lbl_802FF4D4;
extern s32 lbl_802FF4D8;
extern s32 lbl_802FF4DC;
extern u8 lbl_802FF4E0;
extern u8 lbl_802FF4E1;
extern u8 lbl_802FF4C8;
extern u8 lbl_802FF4E2;
extern "C" void fn_8015549C(u32 param_1) {
    lbl_802FF4CC = 0;
    lbl_802FF4D0 = 0;
    lbl_802FF4D4 = 0;
    lbl_802FF4D8 = 0;
    lbl_802FF4DC = 0;
    lbl_802FF4E0 = 1;
    lbl_802FF4E1 = 3;
    lbl_802FF4C8 = 0;
    lbl_802FF4E2 = (param_1 & 2) > 0;
}
