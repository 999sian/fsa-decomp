#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80150490-0x8015085c (3 functions). split_file divides it into the game's real files.

extern "C" unsigned char lbl_802E3B10[];
extern "C" void fn_80150490(u32 param_1) {
    lbl_802E3B10[(u8)param_1 * 0xbc + 0x50] = 0;
}

extern "C" u32 fn_801504B0(u16* param_1, u16* param_2, u16* param_3, u16 param_4, u16* param_5, u16 param_6)
{
    s16 sVar2;

    if (param_4 != *param_3) {
        sVar2 = (s16)param_4 - (s16)*param_3;
        if (sVar2 >= 0x20 && sVar2 < 0xa0) {
            sVar2 = sVar2 >> 5;
            if (sVar2 < 5) {
                param_5[sVar2] |= param_6;
            }
            *param_2 = 1;
            *param_3 += sVar2 << 5;
            return 1;
        }
        if (sVar2 <= -0x20 && sVar2 > -0xa0) {
            sVar2 = -sVar2 >> 5;
            if (sVar2 < 5) {
                param_5[sVar2] |= param_6;
            }
            *param_2 = 0xffff;
            *param_3 -= sVar2 << 5;
            return 1;
        }
        if (param_4 == 0 && sVar2 > -0x20) {
            *param_3 = 0;
            *param_1 = 0;
        }
    }
    *param_2 = 0;
    return 0;
}

