#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800efc44-0x800f2894 (21 functions). split_file divides it into the game's real files.

extern void* lbl_80222428[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_8028C4BC[];
extern u8 lbl_802BB0FC[];
extern "C" s32 fn_8002185C(void);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" s64 OSGetTime(void);
extern "C" void fn_801E445C(const char* fmt, ...);
extern "C" void fn_800EFC44(void* buf);
extern u8 lbl_802B7CA0[];
extern char lbl_8028BFCC[];
extern char lbl_8028BFDC[];
extern char lbl_8028BFEC[];

struct SaveSlot_800F0C44 {
    u8 data[0x9c4];
};

struct SaveMgr_800F0C44 {
    u8 pad[0x258];
    SaveSlot_800F0C44 slots[1];
};
extern "C" s32 fn_800F0C44(void* param_1, s32 p, s32 idx) {
    s64* dst;
    p = idx * 0x9c4 + p;
    dst = (s64*)(p + 0x258);
    memcpy(dst, lbl_802B7CA0, 0x9b8);
    *dst = OSGetTime();
    fn_801E445C(lbl_8028BFCC, 0x9b8);
    return 0;
}

extern "C" s32 fn_800F0CB4(void* param_1, s32 p, s32 idx) {
    memcpy(lbl_802B7CA0, (void*)(idx * 0x9c4 + p + 0x258), 0x9b8);
    fn_801E445C(lbl_8028BFDC, 0x9b8);
    return 0;
}

extern "C" s32 fn_800F0D04(void* param_1, s32 p, s32 idx) {
    u8 buf[0x9b8];
    void* dst;
    p = idx * 0x9c4 + p;
    dst = (void*)(p + 0x258);
    fn_800EFC44(buf);
    memcpy(dst, buf, 0x9b8);
    fn_801E445C(lbl_8028BFEC, 0x9b8);
    return 0;
}

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
        *(u16*)(p + 0x412) |= 0x40;
    } else {
        *(u16*)(p + 0x412) |= 0x80;
    }
}

extern u8 lbl_802C5890[];
extern s32 lbl_802FF1F8;
extern s32 lbl_802FF1FC;
extern u8 lbl_802C5A18[];
extern "C" void fn_800F0F34(u8* p) {
    *(s32*)(p + 0xd0) = 0;
    *(s32*)(p + 0xd8) = 0;
    lbl_802C5890[0x0] = 0;
    lbl_802C5890[0x1] = 0;
    lbl_802C5890[0x2] = 0;
    lbl_802C5890[0x3] = 0;
    lbl_802C5890[0x4] = 0;
    lbl_802C5890[0x5] = 0;
    lbl_802C5890[0x6] = 0;
    lbl_802C5890[0x7] = 0;
    lbl_802C5890[0x8] = 0;
    lbl_802C5890[0x9] = 0;
    lbl_802C5890[0xa] = 0;
    lbl_802C5890[0xb] = 0;
    lbl_802C5890[0xc] = 0;
    lbl_802C5890[0xd] = 0;
    lbl_802C5890[0xe] = 0;
    lbl_802C5890[0xf] = 0;
    lbl_802C5890[0x10] = 0;
    lbl_802C5890[0x11] = 0;
    lbl_802C5890[0x12] = 0;
    lbl_802C5890[0x13] = 0;
    lbl_802FF1F8 = 0;
    lbl_802FF1FC = 0;
}

extern "C" u8 fn_800F26B0(u8* param_1, s32 param_2) {
    s32 v = *(s32*)(param_1 + 0xd8);
    s32 r = v % 5;
    s32 i;
    for (i = 0; i < 5; i++, param_1 += 8) {
        if (*(s32*)(param_1 + 0x8c) == param_2) {
            s32 t = v + (i - r);
            s32 q;
            if (i < r) {
                t += 5;
            }
            q = t / 10;
            return (u8)((q << 4) + (t - q * 10));
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

extern "C" u8 fn_800F2790(void* param_1, s16* param_2) {
    s16 sVar1 = param_2[0] - 0xe00;
    u8 uVar2 = lbl_802B7CA0[0x1419];
    s16 sVar2 = param_2[1] - 0x2c00;
    param_2[0] = sVar1;
    param_2[1] = sVar2;
    if (sVar1 < 0) {
        param_2[0] = 0;
    } else if (sVar1 >= 0x600) {
        param_2[0] = 0x5ff;
    }
    if (param_2[1] < 0) {
        param_2[1] = 0;
    } else if (param_2[1] >= 0x400) {
        param_2[1] = 0x3ff;
    }
    return (s32)param_2[0] / ((s16*)lbl_802C5A18)[uVar2 * 2] + ((s32)param_2[1] / ((s16*)lbl_802C5A18)[uVar2 * 2 + 1]) * 2;
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
