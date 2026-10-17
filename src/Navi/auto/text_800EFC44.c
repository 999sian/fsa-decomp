#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800efc44-0x800f2894 (21 functions). split_file divides it into the game's real files.

extern void* lbl_80222428[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_8028C4BC[];
extern u8 lbl_802BB0FC[];
extern "C" s32 fn_8002185C(void);
extern "C" s32 fn_800F0D64(u8* p) {
    s32 n = 0;
    u32 s = 0;
    u32 m = 3;
    s32 i;
    for (i = 0; i < 2; i++) {
        if (*(u32*)(p + 0x3f0) & (m << s)) n++;
        s += 2;
        if (*(u32*)(p + 0x3f0) & (m << s)) n++;
        s += 2;
        if (*(u32*)(p + 0x3f0) & (m << s)) n++;
        s += 2;
        if (*(u32*)(p + 0x3f0) & (m << s)) n++;
        s += 2;
        if (*(u32*)(p + 0x3f0) & (m << s)) n++;
        s += 2;
        if (*(u32*)(p + 0x3f0) & (m << s)) n++;
        s += 2;
    }
    return n;
}

extern "C" s32 fn_800F0E14(u8* p, u32 idx) {
    u32 v = (*(u32*)(p + 0x3f0) >> (idx * 2)) & 3;
    u32 bit = 1;
    s32 n = 0;
    if (v & bit) {
        n = 1;
        bit <<= 1;
        if (v & bit) {
            n++;
        }
    }
    return n;
}

extern "C" u16 fn_800F0E58(u8* p) {
    if (lbl_802BB0FC[0xee] != 0) {
        return *(u16*)(p + 0x412) & 0x100;
    }
    if (fn_8002185C() <= 1) {
        return *(u16*)(p + 0x412) & 0x40;
    }
    return *(u16*)(p + 0x412) & 0x80;
}

extern "C" void fn_800F0EC0(u8* p) {
    if (lbl_802BB0FC[0xee] != 0) {
        *(u16*)(p + 0x412) |= 0x100;
        return;
    }
    if (fn_8002185C() <= 1) {
        *(u16*)(p + 0x412) |= 0x80;
    } else {
        *(u16*)(p + 0x412) |= 0x40;
    }
}

extern "C" u8 fn_800F26B0(u8* param_1, s32 param_2) {
    s32 v = *(s32*)(param_1 + 0xd8);
    s32 r = v % 5;
    s32 i;
    for (i = 0; i < 5; i++, param_1 += 8) {
        if (*(s32*)(param_1 + 0x8c) == param_2) {
            s32 t = v + (i - r);
            if (i < r) {
                t += 5;
            }
            return (u8)(((t / 10) << 4) + (t - (t / 10) * 10));
        }
    }
    return 0;
}

extern "C" u8 fn_800F2750(u8* param_1, s32 param_2) {
    s32 v = *(s32*)(param_1 + 0xd8);
    s32 r = v % 5;
    s32 t = v + (param_2 - r);
    if (param_2 < r) {
        t += 5;
    }
    return t;
}

extern "C" void* fn_800F2838(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028C4BC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
