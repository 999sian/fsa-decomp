#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801572a8-0x80157334 (2 functions). split_file divides it into the game's real files.

extern volatile u32 lbl_802FE120;
extern "C" u16 fn_801572A8(void) {
    lbl_802FE120 = lbl_802FE120 * 0xA8351D63;
    return (lbl_802FE120 >> 6) & 0xFFFF;
}

extern s16 lbl_80294EF8[];
extern "C" int fn_801572C8(int a) {
    u32 i = a & 0xFFF;
    s16* t = lbl_80294EF8;
    if (i < 0x400) {
        return t[i];
    }
    if (i < 0x800) {
        return t[0x3FF - (i & 0x3FF)];
    }
    if (i < 0xC00) {
        return -t[i & 0x3FF];
    }
    return -t[0x3FF - (i & 0x3FF)];
}

