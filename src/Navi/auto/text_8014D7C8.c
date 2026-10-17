#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014d7c8-0x8014d95c (3 functions). split_file divides it into the game's real files.

extern u32* lbl_802FF46C;
extern u8* lbl_802FF3E0;
extern u32 lbl_802FF45C;
extern u32 lbl_802FF44C;
extern u32 lbl_802FF450;
extern u32 lbl_802FF458;
extern u8 lbl_802D4A80[];
extern "C" void fn_8014D7C8(void)
{
    u32 i;
    u32 off;

    lbl_802FF45C = 0;
    off = 0;
    lbl_802FF44C = 0;
    lbl_802FF450 = 0;
    lbl_802FF458 = 0;
    for (i = 0; i < lbl_802D4A80[0x210]; i++) {
        *(u32*)(lbl_802FF3E0 + off + 0x34) = 0;
        *(u32*)(lbl_802FF3E0 + off + 0x4c) = 2;
        *(u16*)(lbl_802FF3E0 + off + 0xaa) = 0;
        off += 0x404;
    }
}

extern "C" u32* fn_8014D928(u32 param_1)
{
    u32* p;

    for (p = lbl_802FF46C; p != 0; p = (u32*)*p) {
        if (p[2] == param_1) {
            return p;
        }
        if (p[2] > param_1) {
            break;
        }
    }
    return 0;
}
