#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013edb8-0x80140b80 (37 functions). split_file divides it into the game's real files.

extern s32 lbl_802FF388;
extern u8 lbl_802C6A80[];
extern u8 lbl_802C6980[];
extern u8 lbl_80293868[];
extern char lbl_80293C28[];
extern char lbl_80293C34[];
extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern "C" void fn_8013F620(s32, s32);
extern "C" void OSInitAlarm(void);
extern "C" void OSInitThreadQueue(void* queue);
extern "C" void OSRegisterResetFunction(void* info);
extern "C" void fn_801D1360(void);
extern "C" void fn_801404EC(void);
extern "C" void fn_8013EDB8(s32 idx);
extern "C" s32 fn_80140520(s32 idx);
extern "C" s32 fn_801406B0(s32 idx, s32 a, s32 b, void (*cb)(s32));
extern "C" s32 fn_8013F21C(s32 idx);
extern "C" void fn_8013F400(s32 idx, s32 r);
extern "C" void fn_801408CC(void* p);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" void fn_8013EDB8(s32 idx) {
    u8* b = lbl_802C6A80 + (idx << 8);
    if (*(s32*)(b + 0x20) != 0) {
        return;
    }
    if (b[5] != 0 || b[6] != 4) {
        *(s32*)(b + 0x20) = 1;
    } else {
        u8* p = *(u8**)(b + 0x14);
        *p = b[7] & 0x3a;
    }
}

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

extern "C" s32 fn_8013EEB0(s32 idx, s32 a, s32 b) {
    u8* p = lbl_802C6A80 + (idx << 8);
    if (*(s32*)(p + 0x1c) != 0) {
        return 2;
    }
    p[0] = 0;
    *(s32*)(p + 0x14) = a;
    *(s32*)(p + 0x1c) = b;
    return fn_801406B0(idx, 1, 3, fn_8013EDB8);
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
    return lbl_802FF388 = 1;
}

extern "C" void fn_8013F358(s32 idx, s32 r) {
    u8* base = lbl_802C6A80 + (idx << 8);
    u8* p = base + 0x40;
    if (r != 0 || (r = fn_8013EFA4(idx, *(s32*)(p + 0x10), (s32)fn_8013F400)) != 0) {
        *(s32*)(p + 0x2c) = 0;
        *(s32*)(p + 0x28) = 0;
        void (*cb)(s32, s32) = *(void (**)(s32, s32))(p + 0x14);
        if (cb != 0) {
            *(s32*)(p + 0x14) = 0;
            cb(idx, r);
        }
    }
    *(s32*)(base + 0x20) = r;
}

extern "C" void fn_8013F5A0(s32 idx, s32 param_2) {
    u8* s = lbl_802C6A80 + (idx << 8);
    u8* t = s + 0x40;
    void (*cb)(s32);
    if (param_2 == 0) {
        *(u8*)(*(u8**)(t + 0x10)) = 0;
        *(s32*)(t + 0x2c) = 0;
        *(s32*)(t + 0x28) = 0;
        cb = *(void (**)(s32))(t + 0x14);
        if (cb != 0) {
            *(s32*)(t + 0x14) = 0;
            cb(param_2);
        }
    } else {
        fn_801408CC(t + 0x18);
    }
    *(s32*)(s + 0x20) = param_2;
}

extern "C" void fn_80140060(s32 idx, s32 param_2) {
    u8* s = lbl_802C6A80 + (idx << 8);
    u8* t = s + 0x40;
    void (*cb)(s32);
    if (param_2 == 0) {
        *(u8*)(*(u8**)(t + 0x10)) = 0;
        *(s32*)(t + 0x2c) = 0;
        *(s32*)(t + 0x28) = 0;
        cb = *(void (**)(s32))(t + 0x14);
        if (cb != 0) {
            *(s32*)(t + 0x14) = 0;
            cb(param_2);
        }
    }
    *(s32*)(s + 0x20) = param_2;
}

extern "C" void fn_801400E0(s32 idx) {
    if (fn_8013F21C(idx) == 0) {
        fn_80140520(idx);
    }
}

extern "C" void fn_80140128(s32 idx) {
    u8* s = lbl_802C6A80 + (idx << 8);
    if (*(s32*)(s + 0x20) == 0) {
        memcpy(*(void**)(s + 0x18), s + 5, 4);
        *(u8*)(*(u8**)(s + 0x14)) = s[9] & 0x3a;
    }
}

extern "C" s32 fn_801401F4(s32 idx, s32 param_2, s32 param_3) {
    u8* s = lbl_802C6A80 + (idx << 8);
    s32 r;
    if (*(u32*)(s + 0x1c) != 0) {
        return 2;
    }
    s[0] = 0x14;
    *(s32*)(s + 0x18) = param_2;
    *(s32*)(s + 0x14) = param_3;
    *(void**)(s + 0x1c) = (void*)fn_801404EC;
    r = fn_801406B0(idx, 1, 5, fn_80140128);
    if (r == 0) {
        r = fn_80140520(idx);
    }
    return r;
}

extern "C" void fn_80140288(s32 idx) {
    u8* s = lbl_802C6A80 + (idx << 8);
    if (*(s32*)(s + 0x20) != 0) {
        return;
    }
    **(u8**)(s + 0x14) = s[5] & 0x3a;
}

extern "C" s32 fn_801402B8(s32 idx, void* param_2, s32 param_3, s32 param_4) {
    u8* s = lbl_802C6A80 + (idx << 8);
    if (*(u32*)(s + 0x1c) != 0) {
        return 2;
    }
    s[0] = 0x15;
    memcpy(s + 1, param_2, 4);
    *(void**)(s + 0x18) = param_2;
    *(s32*)(s + 0x14) = param_3;
    *(s32*)(s + 0x1c) = param_4;
    return fn_801406B0(idx, 5, 1, fn_80140288);
}

extern "C" s64 fn_80140724(s32 idx, s64 value)
{
    s32* p = (s32*)((u8*)lbl_802C6A80 + idx * 0x100);
    s64 prev;

    prev = *(s64*)&p[12];
    p[13] = (s32)value;
    p[12] = (s32)(value >> 32);
    return prev;
}

extern "C" void fn_80140824(u8* p)
{
    s32 idx;
    u8* base = (u8*)lbl_802C6A80;

    if (base + 0xa8 == p) {
        idx = 0;
    } else {
        base += 0x100;
        if (base + 0xa8 == p) {
            idx = 1;
        } else if (base + 0x1a8 == p) {
            idx = 2;
        } else {
            base += 0x100;
            if (base + 0x1a8 == p) {
                idx = 3;
            } else {
                fn_80007AB8(lbl_80293C28, 0xa9, lbl_80293C34);
                idx = -1;
            }
        }
    }
    fn_8013F620(idx, 0);
}

