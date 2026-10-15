#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011c5b4-0x8011f1f4 (28 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8015D29C(void*, int);
extern char lbl_80290778[];
extern u32 lbl_802FF2F4;
extern void* lbl_802C6170;
extern "C" void* fn_801E6578(void* param_1, void* param_2);
extern "C" void* fn_8015A90C(u32 size);
extern "C" void fn_80166B58(void* param_1, void* param_2);
extern "C" void fn_80166C84(void* param_1, void* param_2);
extern "C" s64 OSGetTime(void);
extern "C" void fn_8011EA30(s64 param_1) {
    if (param_1 > 0) {
        s64 time1 = OSGetTime();
        s64 time2 = OSGetTime();
        s64 elapsed = time2 - time1;
        s32 clock_speed = *(u32*)0x800000f8 >> 2;
        s64 quotient = elapsed / (s64)clock_speed;
        s64 divisor = param_1;
        
        if ((quotient ^ 0x8000000000000000) < (divisor ^ 0x8000000000000000)) {
            if ((quotient ^ 0x8000000000000000) - (divisor ^ 0x8000000000000000) < (elapsed < param_1 ? 1 : 0)) {
                return;
            }
        }
    }
}

extern "C" u32 fn_8011EBB4(u32 param_1) {
    u32 old = lbl_802FF2F4;
    lbl_802FF2F4 = param_1;
    return old;
}

extern "C" void fn_8011F174(void* param_1, u32 param_2, u16 param_3, u32 param_4, u32 param_5) {
    *(u32*)param_1 = param_2;
    *(u32*)((u8*)param_1 + 4) = param_5;
    *(u16*)((u8*)param_1 + 12) = 1;
    *(u16*)((u8*)param_1 + 14) = param_3;
    *(u8*)((u8*)param_1 + 16) = 0;
}

extern "C" void* fn_8011F194(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80290778;
        fn_8015D29C(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}
