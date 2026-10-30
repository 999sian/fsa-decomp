#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e0c94-0x801e0cc4 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_801E0C94(u8* dst, u8* src, u32 n)
{
    u8* d;

    if (dst == NULL) {
        return;
    }
    if (n == 0) {
        return;
    }
    d = dst;
    do {
        u8 c = *src++;
        *d++ = c;
    } while (--n != 0);
}
