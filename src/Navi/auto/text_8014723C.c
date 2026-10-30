#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014723c-0x8014725c (1 functions). split_file divides it into the game's real files.

extern u16 lbl_802D45C0[];
extern "C" u16 fn_8014723C(u32 param_1, u32 param_2) {
    u32 base = (u32)lbl_802D45C0 + (param_1 & 0xff) * 32;
    return *(u16*)(base + (param_2 & 0xff) * 2);
}
