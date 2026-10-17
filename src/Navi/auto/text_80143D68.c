#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80143d68-0x8014408c (4 functions). split_file divides it into the game's real files.

extern "C" u32 lbl_802D46C0[][16];
extern "C" void fn_80143F98(u32 t, u8 a, u8 b) {
    if (a == 0xff) {
        a = 8;
    }
    *(u32*)((u8*)lbl_802D46C0 + a * 0x40 + b * 4) = ((t << 3) * 0x600) / 240;
}

extern "C" u32 fn_80143FE0(u8* p) {
    u32 a = p[0x122];
    if (a == 0xff) {
        a = 8;
    }
    return *(u32*)((u8*)lbl_802D46C0 + a * 0x40 + p[0x123] * 4);
}

extern "C" void fn_80144014(u8* p) {
    u64 flags = *(u64*)(p + 0x114);
    if (flags & 0x20000) {
        return;
    }
    if (p[0x131] == 1) {
        if (!(flags & 0x1000)) {
            *(u32*)(p + 0x13c) = 0;
        } else {
            *(u32*)(p + 0x13c) = *(u32*)(p + 0x134);
        }
    } else {
        *(u32*)(p + 0x13c) = *(u32*)(p + 0x134);
    }
    *(u32*)(p + 0x138) = p[0x130] << 16;
}
#include "dolphin/types.h"

extern "C" u32 lbl_802D46C0[][16];
