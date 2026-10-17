#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013edb8-0x80140b80 (37 functions). split_file divides it into the game's real files.

extern s32 lbl_802FF388;
extern u8 lbl_802C6A80[];
extern u8 lbl_802C6980[];
extern u8 lbl_80293868[];
extern "C" void OSInitAlarm(void);
extern "C" void OSInitThreadQueue(void* queue);
extern "C" void OSRegisterResetFunction(void* info);
extern "C" void fn_801D1360(void);
extern "C" void fn_801404EC(void);
extern "C" void fn_8013EDB8(void);
extern "C" s32 fn_80140520(s32 idx);
extern "C" s32 fn_801406B0(s32 idx, s32 a, s32 b, void (*cb)(void));
extern "C" s32 fn_8013F21C(s32 idx);
extern "C" void fn_801408CC(void* p);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
void fn_8013EE0C(void)
{
    s32 i = 0;
    u32 ticks = *(u32*)0x800000F8 / 500000;
    u8* p = lbl_802C6A80;
    u8* q = lbl_802C6980;
    do {
        *(u32*)(p + 0x34) = (ticks * 0x3c) >> 3;
        *(u32*)(p + 0x30) = 0;
        OSInitThreadQueue(p + 0x24);
        i++;
        *(u8**)(p + 0xf8) = q;
        p += 0x100;
        q += 0x40;
    } while (i < 4);
    OSInitAlarm();
    fn_801D1360();
    lbl_802FF388 = 0;
    OSRegisterResetFunction(lbl_80293868);
}

extern "C" s32 fn_8013EF14(s32 idx, s32 param_2) {
    u8* s = lbl_802C6A80 + (idx << 8);
    s32 r;
    if (*(u32*)(s + 0x1c) != 0) {
        return 2;
    }
    s[0] = 0;
    *(s32*)(s + 0x14) = param_2;
    *(void**)(s + 0x1c) = (void*)fn_801404EC;
    r = fn_801406B0(idx, 1, 3, fn_8013EDB8);
    if (r == 0) {
        r = fn_80140520(idx);
    }
    return r;
}

extern "C" s32 fn_8013EFA4(s32 idx, s32 param_2, s32 param_3) {
    u8* s = lbl_802C6A80 + (idx << 8);
    if (*(u32*)(s + 0x1c) != 0) {
        return 2;
    }
    s[0] = 0xff;
    *(s32*)(s + 0x14) = param_2;
    *(s32*)(s + 0x1c) = param_3;
    return fn_801406B0(idx, 1, 3, fn_8013EDB8);
}

extern "C" s32 fn_8013F008(s32 idx, s32 param_2) {
    u8* s = lbl_802C6A80 + (idx << 8);
    s32 r;
    if (*(u32*)(s + 0x1c) != 0) {
        return 2;
    }
    s[0] = 0xff;
    *(s32*)(s + 0x14) = param_2;
    *(void**)(s + 0x1c) = (void*)fn_801404EC;
    r = fn_801406B0(idx, 1, 3, fn_8013EDB8);
    if (r == 0) {
        r = fn_80140520(idx);
    }
    return r;
}

extern "C" s32 fn_8013F098(void) {
    lbl_802FF388 = 1;
    return 1;
}

