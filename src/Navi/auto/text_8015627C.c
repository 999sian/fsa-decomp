#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015627c-0x80156318 (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_80157100(u32 param_1);
#pragma use_lmw_stmw off
extern "C" void fn_8015627C(u8* p, u32 a, u32 b, u32 flags, u32 c) {
    u8 n;
    if ((u8)flags == 0) {
        p[0x22] = 0;
    }
    n = p[0x22];
    if (n < 4) {
        p[0x22] = n + 1;
        if (c != 0) {
            flags |= 0x10;
        } else {
            a = fn_80157100(a);
        }
        p[n << 3] = a;
        *(u8*)(p + (n << 3) + 1) = flags;
        *(u32*)(p + (n << 3) + 4) = b;
    }
}
#pragma use_lmw_stmw reset
