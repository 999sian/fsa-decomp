#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80015d50-0x80016924 (21 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" BOOL fn_801BE5B4(void*);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_801BE764(void*);
extern "C" void fn_80016814(void*);
extern "C" s32 fn_801D703C(u8, void*, void*);
extern "C" void fn_801D7158(void*);
extern u8 lbl_80204FA8[];
extern "C" void fn_801D2BDC(void);
extern "C" void fn_801BE368(void*);
extern "C" void fn_801BE670(void*);
extern "C" void fn_801C027C(void);
extern "C" s32 fn_801C1594(void);
extern "C" void fn_801C0884(void*, void*, s32, void*, u32, s32, s32);
extern "C" void fn_801C0EEC(void*);
extern "C" void fn_800168D0(void);
extern u8 lbl_802A4560[];
extern u8 lbl_802A3560[];
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BE690(void*, void*);
extern "C" void fn_80015FE8(void*);
extern "C" void fn_8001606C(void*);
extern "C" void fn_80016540(void*);
extern "C" void fn_80016618(void*);
extern "C" void* fn_80015D50(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80015D8C(void* param_1) {
    u8* p = (u8*)param_1;
    fn_801D2BDC();
    p[0x1fa5] = 0;
    p[0x1fa6] = 2;
    *(s32*)(p + 0x1fac) = 0;
    *(s32*)(p + 0x1fa8) = 0;
    p[0x1fa4] = 0;
    fn_801BE368(p + 0x1fb0);
    fn_801BE670(p + 0x1fc8);
    fn_801C027C();
    s32 iVar1 = fn_801C1594();
    fn_801C0884(lbl_802A4560, (void*)fn_800168D0, 0, lbl_802A3560 + 0x1000, 0x1000, iVar1 + 1, 1);
    fn_801C0EEC(lbl_802A4560);
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

extern "C" BOOL fn_80016730(void* param_1) {
    u8 auStack_28[0x20];
    u32 iVar1;
    iVar1 = fn_801D703C(((u8*)param_1)[0x1fa4], lbl_80204FA8, auStack_28);
    if (iVar1 == 0) {
        fn_801D7158(auStack_28);
        return TRUE;
    } else {
        fn_80016814(param_1);
        return FALSE;
    }
}

