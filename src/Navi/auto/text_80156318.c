#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80156318-0x801564bc (3 functions). split_file divides it into the game's real files.

extern u8 lbl_802E5090[];
extern u8 lbl_802E5110[];
extern "C" void fn_80156434(u32 param_1, u32 param_2, u8 param_3)
{
    u8* p;
    u32 idx;

    idx = param_2 & 0xff;
    if (idx != 0xff) {
        p = lbl_802E5090 + idx * 0x10;
        p = p + (param_1 & 0xff);
        *p = param_3;
        return;
    }
    p = lbl_802E5110 + (param_1 & 0xff);
    *p = param_3;
}

extern "C" u8 fn_80156478(u32 param_1, u32 param_2)
{
    u8 *p;

    if ((param_2 & 0xff) != 0xff) {
        p = lbl_802E5090 + ((param_2 & 0xff) << 4);
        return *(u8 *)((u32)p + (param_1 & 0xff));
    }
    return *(u8 *)((u32)lbl_802E5110 + (param_1 & 0xff));
}

