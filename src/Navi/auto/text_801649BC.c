#include "dolphin/os/OSFastCast.h"
typedef void (*VirtualMethod0)(void*, s16);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801649bc-0x801655bc (8 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80166C08(void*, int);
extern "C" void fn_80164484(void* buf);
extern "C" s32 fn_801C806C(void* param_1, void* param_2, u32 param_3, u32 param_4, s32 param_5);
extern "C" s32 fn_801CBA20(void);
extern "C" void DCInvalidateRange(void* addr, u32 nBytes);
extern u8 lbl_802FE390;
extern u32 lbl_802FF600;
extern u32 lbl_802FF604;
extern u32 lbl_802FF614;
extern u32 lbl_802FF618;
extern u32 lbl_802FF61C;
extern u32 lbl_802FF620;
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

extern "C" s32 fn_80164A10(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7, s32 p8) {
    u8 buf[288];
    fn_80164484(buf);
    if (fn_80164728(buf, p0) == 0) {
        fn_801645A8(buf, -1);
        return 0;
    } else {
        s32 result = fn_80164ACC(buf, p1, p2, p3, p4, p5, p6, p7, p8);
        fn_801645A8(buf, -1);
        return result;
    }
}

extern "C" void* fn_801653D4(void) {
    u32 n;
    u32 len;
    void* base;
    s32 result;

    base = (void*)lbl_802FF600;
    n = lbl_802FF604 - (u32)base;
    lbl_802FF61C = lbl_802FF604 - 0x19;
    if (lbl_802FF618 < n) {
        n = lbl_802FF618;
    }
    len = n;
    do {
        result = fn_801C806C((void*)(lbl_802FF620 + 0x5c), base, len, lbl_802FF614, 2);
        if (result >= 0) {
            break;
        }
        if (result == -3 || !lbl_802FE390) {
            return NULL;
        }
        fn_801CBA20();
    } while (TRUE);
    DCInvalidateRange(base, n);
    lbl_802FF614 += n;
    lbl_802FF618 -= n;
    return base;
}

extern u8 lbl_802FE390;
extern "C" u8 fn_801655B4(void) {
    return lbl_802FE390;
}

