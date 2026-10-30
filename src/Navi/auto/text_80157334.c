#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157334-0x801573cc (1 functions). split_file divides it into the game's real files.

extern "C" void* fn_80157334(void* ctx, u8* base, s32 count, s32 size, s32 (*cmp)(void*, void*)) {
    s32 hi;
    s32 lo;
    s32 idx;
    s32 mid;
    u8* elem;
    s32 res;

    if (count != 0) {
        lo = 1;
        hi = count;
        do {
            mid = (lo + hi) >> 1;
            idx = mid - 1;
            elem = base + size * idx;
            res = cmp(ctx, elem);
            if (res == 0) {
                return elem;
            }
            if (res < 0) {
                hi = idx;
            } else {
                lo = mid + 1;
            }
        } while (lo <= hi);
    }
    return 0;
}
