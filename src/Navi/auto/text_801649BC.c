#include "dolphin/os/OSFastCast.h"
typedef void (*VirtualMethod0)(void*, s16);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801649bc-0x801655bc (8 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80166C08(void*, int);
extern "C" void fn_80164484(void* buf);
extern "C" u8 fn_80164728(void* buf, s32 p);
extern "C" void fn_801645A8(void* buf, s32 p);
extern "C" s32 fn_80164ACC(void* buf, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, s32 p8);
typedef void (*VirtualMethod0)(void*, s16);
extern "C" void* fn_801649BC(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern u8 lbl_802FE390;
extern "C" u8 fn_801655B4(void) {
    return lbl_802FE390;
}

