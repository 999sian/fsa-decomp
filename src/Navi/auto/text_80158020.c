#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158020-0x801580c4 (1 functions). split_file divides it into the game's real files.

extern "C" u8* lbl_802FF4BC;

static inline u32 fn_80158020_calc(s32 idx) {
    u32 t = *(u32*)(lbl_802FF4BC + idx * 0xf4 + 0x20);
    u32 lo = t & 0xf;
    u32 r = ((t - *(u32*)(lbl_802FF4BC + idx * 0xf4 + 0x78) * 2) >> 4) * 14;
    if (lo >= 2) {
        r = lo + r - 2;
    }
    return r;
}

extern "C" u32 fn_80158020(s32 idx) {
    u8* p = lbl_802FF4BC + idx * 0xf4;
    u8* q;
    u32 t;
    u32 lo;
    u32 r;
    if (p[0xec] != 2) {
        return 0;
    }
    switch (p[0x90]) {
    case 0:
    case 1:
    case 4:
    case 5:
        q = lbl_802FF4BC + idx * 0xf4;
        t = *(u32*)(q + 0x20);
        r = ((t - *(u32*)(q + 0x78) * 2) >> 4) * 14;
        lo = t & 0xf;
        if (lo >= 2) {
            r += lo - 2;
        }
        return r;
    case 3:
        return *(u32*)(p + 0x20) - *(u32*)(p + 0x78);
    case 2:
        return *(u32*)(p + 0x20) - (*(u32*)(p + 0x78) >> 1);
    }
}
