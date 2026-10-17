#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014ef34-0x8014f024 (1 functions). split_file divides it into the game's real files.

extern f32 lbl_802940E8[];
extern f32 lbl_802942E8[];
extern u32 lbl_802D4A80[];
extern "C" u32 fn_8014EF34(u8 p1, u32 p2)
{
    u32 base;
    f32 v;
    f32 scale;

    if (p2 == 0xffffffff) {
        p2 = 0x40005622;
    }
    base = p2 >> 24;
    if (p1 != base) {
        if (base < p1) {
            scale = lbl_802940E8[(u8)p1 - base];
        } else {
            scale = lbl_802942E8[base - (u8)p1];
        }
        v = (f32)(p2 & 0xffffff) * scale;
    } else {
        v = (f32)(p2 & 0xffffff);
    }
    return (u32)(4096.0f * v / (f32)lbl_802D4A80[0]);
}
