#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80148088-0x8014810c (1 functions). split_file divides it into the game's real files.

extern "C" void fn_8014E9C4(void* p);
extern u8 lbl_802D5CA8[];
typedef void (*NaviFn)(s32, s32, s32, s32, s32);
extern "C" void fn_80148088(s32 idx)
{
    u8* obj = lbl_802D5CA8 + idx * 100;
    u8 state = obj[0x8];

    if (state >= 1 && state < 3) {
        if (state == 2) {
            fn_8014E9C4(*(void**)(obj + 0x48));
        }
        obj[0x8] = 3;
        NaviFn fn = *(NaviFn*)(obj + 0xc);
        fn(0, 0, 0, 0, *(s32*)(obj + 0x4c));
        return;
    }
}
