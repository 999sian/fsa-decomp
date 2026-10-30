#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80156944-0x8015698c (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_801564BC(u8* self, u8* p, u8 a, u8 b);
extern "C" u32 fn_80156944(u8* p) {
    if (!(*(u32*)(p + 0x214) & 1)) {
        return *(u16*)(p + 0x238);
    }
    *(u32*)(p + 0x214) &= ~1;
    return fn_801564BC(p, p + 0x218, p[0x121], p[0x122]);
}
