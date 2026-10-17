#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80148ab4-0x80148af8 (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_80148AB4(u32 param_1, u32 param_2)
{
    u32 x;

    if (param_2 & 1) {
        x = ((param_1 + 0xd) / 7) << 2;
        x = x & ~7;
        return (x + 0x1f) & ~0x1f;
    }
    x = param_1 << 1;
    return (x + 0x1f) & ~0x1f;
}
