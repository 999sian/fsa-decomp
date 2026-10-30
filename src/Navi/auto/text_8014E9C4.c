#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014e9c4-0x8014ea44 (1 functions). split_file divides it into the game's real files.

extern "C" int fn_8015766C(int i);
extern "C" void fn_80157854(int i);
extern "C" void fn_8014E4C8(u8* p);
extern u8* lbl_802FF3E0;
extern "C" void fn_8014E9C4(u32 param_1) {
    u32 idx = param_1;
    if (idx != 0xffffffff) {
        if (fn_8015766C(idx) != 0) {
            fn_80157854(idx);
        }
        *(u32*)(lbl_802FF3E0 + idx * 0x404 + 0xf4) = idx;
        fn_8014E4C8(lbl_802FF3E0 + idx * 0x404);
        lbl_802FF3E0[idx * 0x404 + 0x11c] = 0;
    }
}
