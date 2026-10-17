#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80015d50-0x80016924 (21 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" BOOL fn_801BE5B4(void*);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_801BE764(void*);
extern "C" void* fn_80015D50(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80016170(void* param_1) {
    u8* p = (u8*)param_1;
    if (fn_801BE5B4(p + 0x1fb0)) {
        *(s32*)(p + 0x1fa8) = 3;
        fn_801BE47C(p + 0x1fb0);
        fn_801BE764(p + 0x1fc8);
    }
}

extern "C" void fn_80016244(void* param_1) {
    u8* p = (u8*)param_1;
    if (fn_801BE5B4(p + 0x1fb0)) {
        *(s32*)(p + 0x1fa8) = 1;
        fn_801BE47C(p + 0x1fb0);
        fn_801BE764(p + 0x1fc8);
    }
}

extern "C" void fn_801BE47C(void*);
extern "C" BOOL fn_801BE5B4(void*);
extern "C" s32 fn_800164D0(void* param_1) {
    u8* p = (u8*)param_1;
    s32 result = 0;
    if (fn_801BE5B4(p + 0x1fb0)) {
        if (*(s32*)(p + 0x1fac) == 5) {
            *(s32*)(p + 0x1fac) = 2;
            result = 1;
        } else {
            result = 2;
        }
        fn_801BE47C(p + 0x1fb0);
    }
    return result;
}

extern "C" void fn_801D647C(u8);
extern "C" void fn_80016618(void* param_1) {
    u8* p = (u8*)param_1;
    fn_801D647C(p[0x1fa4]);
    *(s32*)(p + 0x1fac) = 0;
}

