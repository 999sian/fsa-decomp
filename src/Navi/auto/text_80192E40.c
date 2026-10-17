#include "types.h"

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} NaviEntry12;

typedef struct {
    f32 v[9];
} NaviEntry36;

extern u32 lbl_802FF6B8;
extern NaviEntry12 lbl_80299AD0[];
extern "C" void fn_801937C8(void* e, s32 idx);
extern "C" void fn_801E10DC(void* p, s32 idx, NaviEntry12 tmp);
extern void* lbl_80299E10[];

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80192e40-0x80196184 (91 functions). split_file divides it into the game's real files.

extern void* lbl_80299E38[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80299A78[];
extern void* lbl_80299A8C[];
extern "C" void fn_801DF0BC(u32 a, u32 b);
extern "C" void fn_801969C8(u32 a);
extern "C" void fn_80194830(u32* a);
extern "C" void* fn_8015AA60(u32 size, u32 align);
extern u32 lbl_802FF6E0;
extern "C" void fn_80192E40(u32* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 0;
    p[16] = 0;
    p[17] = 0;
    p[18] = 0;
    *(u8*)(p + 19) = 0;
    p[20] = 4;
    *(u8*)(p + 21) = 0;
    p[22] = 4;
}

extern "C" void fn_80192EA8(u32* p, u32* src) {
    p[0] = (u32)src;
    p[1] = src[6];
    p[3] = src[7];
    p[5] = src[9];
    p[2] = 0;
    p[4] = 0;
    p[6] = 0;
    p[7] = src[6];
    p[9] = src[7];
    p[8] = 0;
    p[10] = 0;
    p[11] = p[1];
    p[12] = p[3];
    p[13] = p[5];
}

extern "C" void fn_80192F08(u32* p) {
    p[0] = 0;
    p[2] = 0;
    p[1] = 0;
    p[4] = 0;
    p[3] = 0;
    p[6] = 0;
    p[5] = 0;
    p[8] = 0;
    p[7] = 0;
    p[10] = 0;
    p[9] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[11] = p[1];
    p[12] = p[3];
    p[13] = p[5];
}

extern "C" void* fn_80192F60(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80192F9C(u32* p) {
    extern u32 lbl_802EE470[];
    u32 a = p[11];
    u32 b = p[12];
    u32 c = p[13];
    lbl_802EE470[67] = a;
    lbl_802EE470[68] = b;
    lbl_802EE470[69] = c;
}

extern "C" void fn_80192FC0(void* p) {
    *(s16*)p = 0;
    *(u32*)((u8*)p + 0x4) = 0;
    *(u32*)((u8*)p + 0x8) = 0;
}

extern "C" void* fn_80192FD4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80193604(f32* p, f32* out) {
    extern f32 lbl_802F0BC0[][2];
    s16 angle = *(s16*)(p + 2);
    f32 s = lbl_802F0BC0[(angle >> 5) & 0x7FF][0];
    f32 c = lbl_802F0BC0[(angle >> 5) & 0x7FF][1];
    f32 x = p[0];
    f32 y = p[1];
    f32 a = p[3] - 0.5f;
    f32 b = (p[4] - 0.5f) + y;
    out[0] = x * c;
    out[1] = y * s;
    out[2] = 0.5f + (a * c - s * b);
    out[3] = 0.0f;
    out[4] = -x * s;
    out[5] = y * c;
    out[6] = 0.5f + (-a * s - c * b);
    out[7] = 0.0f;
    out[8] = 0.0f;
    out[9] = 0.0f;
    out[10] = 1.0f;
    out[11] = 0.0f;
}

extern "C" void fn_801936B4(f32* p, f32* out) {
    extern f32 lbl_802F0BC0[][2];
    s16 angle = *(s16*)(p + 2);
    f32 s = lbl_802F0BC0[(angle >> 5) & 0x7FF][0];
    f32 c = lbl_802F0BC0[(angle >> 5) & 0x7FF][1];
    f32 x = p[0];
    f32 y = p[1];
    f32 a = p[3] - 0.5f;
    f32 b = (p[4] - 0.5f) + y;
    out[0] = x * c;
    out[1] = y * s;
    out[2] = 0.0f;
    out[3] = 0.5f + (a * c - s * b);
    out[4] = -x * s;
    out[5] = y * c;
    out[6] = 0.0f;
    out[7] = 0.5f + (-a * s - c * b);
    out[8] = 0.0f;
    out[9] = 0.0f;
    out[10] = 1.0f;
    out[11] = 0.0f;
}

extern "C" void fn_80193764(f32* a, f32* b) {
    a[0] *= b[0];
    a[1] *= b[1];
    a[2] *= b[2];
    a[4] *= b[0];
    a[5] *= b[1];
    a[6] *= b[2];
    a[8] *= b[0];
    a[9] *= b[1];
    a[10] *= b[2];
}

extern "C" void fn_801937C8(void* e, s32 idx) {
    f32* a = (f32*)e;
    f32* b = (f32*)idx;
    a[0] *= b[0];
    a[1] *= b[1];
    a[2] *= b[2];
    a[3] *= b[0];
    a[4] *= b[1];
    a[5] *= b[2];
    a[6] *= b[0];
    a[7] *= b[1];
    a[8] *= b[2];
}

extern "C" u32 fn_80193B74(u32* p, u32 n) {
    p[3] = (n + 0x1f) & ~0x1f;
    p[0] = (u32)fn_8015AA60(p[3], 0x20);
    p[1] = (u32)fn_8015AA60(p[3], 0x20);
    p[2] = 0;
    return 0;
}

extern "C" void fn_801DF0BC(u32 a, u32 b);
extern "C" void* memcpy(void* dst, const void* src, u32 n);
extern "C" void* fn_8015AA60(u32 size, u32 align);
extern "C" void fn_801BC250(void* p, u32 n);
extern "C" u32 fn_80193C2C(u32* p) {
    if (p[0] == p[1]) {
        p[1] = (u32)fn_8015AA60(p[3], 0x20);
        memcpy((void*)p[1], (void*)p[0], p[3]);
        fn_801BC250((void*)p[1], p[3]);
    }
    return 0;
}

extern "C" void fn_80193C94(u32* p, u32 a, u32 b) {
    p[3] = (b + 0x1f) & ~0x1f;
    p[0] = a;
    p[1] = p[0];
    p[2] = b;
}

extern "C" void fn_80193CB4(u32* p) {
    u32 a = p[0];
    fn_801DF0BC(a, p[2]);
}

extern "C" void fn_80193CE0(u32* p)
{
    extern u32 lbl_802FF6B0;
    extern u32 lbl_802FFA80;
    extern u8 lbl_802EE618[];
    extern u32 OSDisableInterrupts(void);
    extern void fn_801DFFF0(void*, u32, u32);
    u32 tmp = p[0];
    p[0] = p[1];
    p[1] = tmp;
    lbl_802FF6B0 = OSDisableInterrupts();
    fn_801DFFF0(lbl_802EE618, p[0], p[3]);
    lbl_802FFA80 = (u32)lbl_802EE618;
}

extern "C" u32 fn_80193D40(u32* p) {
    extern u32 lbl_802FF6B0;
    extern u32 lbl_802FFA80;
    extern u32 lbl_802EE618[];
    extern void fn_801E0034(void);
    extern void fn_801E0008(void);
    extern void OSRestoreInterrupts(u32);
    fn_801E0034();
    OSRestoreInterrupts(lbl_802FF6B0);
    p[2] = lbl_802EE618[2] - lbl_802EE618[0];
    fn_801E0008();
    lbl_802FFA80 = 0;
    return p[2];
}

extern "C" void fn_80193D9C(u32* p)
{
    extern u32 lbl_802FF6B0;
    extern u32 lbl_802FFA80;
    extern u8 lbl_802EE618[];
    extern u32 OSDisableInterrupts(void);
    extern void fn_801DFFF0(void*, u32, u32);
    u32 tmp = p[0];
    p[0] = p[1];
    p[1] = tmp;
    lbl_802FF6B0 = OSDisableInterrupts();
    fn_801DFFF0(lbl_802EE618, p[0], p[3]);
    lbl_802FFA80 = (u32)lbl_802EE618;
}

extern "C" u32 fn_80193DFC(u32* p) {
    extern u32 lbl_802FF6B0;
    extern u32 lbl_802FFA80;
    extern void OSRestoreInterrupts(u32);
    OSRestoreInterrupts(lbl_802FF6B0);
    lbl_802FFA80 = 0;
    return p[2];
}

extern "C" BOOL fn_80193E38(void);
extern "C" BOOL fn_80193E38(void)
{
    return TRUE;
}

extern "C" void* fn_80193E60(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299A78;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80193FFC(u32* p) {
    u32* q = (u32*)p[8];
    fn_801DF0BC(q[0], q[2]);
}

extern "C" void fn_80194028(void** p) {
    extern void* lbl_80299A64[];
    extern void* lbl_80299A78[];
    extern void* lbl_80299A8C[];
    void* a = lbl_80299A8C;
    void* b = lbl_80299A78;
    void* c = lbl_80299A64;
    p[0] = a;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[0] = b;
    p[4] = 0;
    p[8] = 0;
    p[9] = 0;
    p[0] = c;
    p[10] = 0;
    p[12] = 0;
    p[13] = (void*)-1;
    p[14] = 0;
    p[15] = 0;
}

extern "C" void* lbl_80299A64[];
extern "C" void* fn_80194084(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299A64;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A78;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299A8C;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801940F0(u32* p, u32* node) {
    u32 head = p[11];
    if (head == 0) {
        p[11] = (u32)node;
    } else {
        node[1] = head;
        p[11] = (u32)node;
    }
}

extern "C" void fn_80194110(u32* p) {
    extern u32 lbl_802FF6B0;
    extern u32 lbl_802FFA80;
    extern u8 lbl_802EE618[];
    extern u32 OSDisableInterrupts(void);
    extern void fn_801DFFF0(void*, u32, u32);
    u8* base = *(u8**)((u8*)p + 0x28);
    u32* q = *(u32**)(base + 0x20);
    u32 tmp = q[0];
    q[0] = q[1];
    q[1] = tmp;
    lbl_802FF6B0 = OSDisableInterrupts();
    fn_801DFFF0(lbl_802EE618, q[0], q[3]);
    lbl_802FFA80 = (u32)lbl_802EE618;
}

extern "C" u32 fn_80194174(u32* p) {
    extern u32 lbl_802FF6B0;
    extern u32 lbl_802FFA80;
    extern u32 lbl_802EE618[];
    extern void fn_801E0034(void);
    extern void fn_801E0008(void);
    extern void OSRestoreInterrupts(u32);
    u8* base = *(u8**)((u8*)p + 0x28);
    u32* q = *(u32**)(base + 0x20);
    fn_801E0034();
    OSRestoreInterrupts(lbl_802FF6B0);
    q[2] = lbl_802EE618[2] - lbl_802EE618[0];
    fn_801E0008();
    lbl_802FFA80 = 0;
    return q[2];
}

extern "C" s32 fn_801941D4(u32* p, u32* q) {
    s32 r = 0;
    s32 a = p[13];
    if (a == q[13]) {
        if (a >= 0) {
            return 1;
        }
    }
    return r;
}

extern "C" void fn_801941F8(u32* p) {
    u32* it;
    void* obj = (void*)p[12];
    (*(void (***)(void*))obj)[6](obj);
    fn_801DF0BC(*(u32*)p[8], ((u32*)p[8])[2]);
    it = (u32*)p[11];
    fn_801969C8(((u32*)p[11])[10]);
    for (; it != nullptr; it = (u32*)it[1]) {
        if (it[8] != 0) {
            fn_801DF0BC(*(u32*)it[8], ((u32*)it[8])[2]);
        }
        fn_80194830(it);
    }
    lbl_802FF6E0 = 0;
}

extern "C" void fn_8019428C(u32* p) {
    extern void* lbl_80299A2C[];
    p[0] = (u32)lbl_80299A8C;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[0] = (u32)lbl_80299A78;
    p[4] = 0;
    p[8] = 0;
    p[9] = 0;
    p[0] = (u32)lbl_80299A2C;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
}

extern "C" void* lbl_80299A2C[];
extern "C" void* fn_801942E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299A2C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A78;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299A8C;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" s32 fn_80194350(u8* p);
extern "C" void* fn_8015A90C(u32 size);
extern "C" void fn_80191E7C(u32* p);
extern "C" void fn_80191AE0(u32 a, u32 b);
extern "C" void fn_80191A60(u8* a, u32 b);
extern "C" void fn_80194BB0(u8* a);
extern "C" void fn_801C5DA8(u32 a, u8* b, u8* c);
extern u32 lbl_802FF6D0;
extern "C" int fn_801945C4(u8* p, u32 param_2) {
    u32* a;
    s32 r;
    s32 ret;
    *(u32*)(p + 0x34) = param_2;
    r = fn_80194350(p);
    a = (u32*)fn_8015A90C(0x10);
    if (a != 0) {
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        a[3] = 0;
    }
    *(u32**)(p + 0x20) = a;
    a = *(u32**)(p + 0x20);
    if (a == 0) {
        ret = 4;
    } else {
        a[3] = (r + 0x1f) & ~0x1f;
        a[0] = (u32)fn_8015AA60(a[3], 0x20);
        a[1] = (u32)fn_8015AA60(a[3], 0x20);
        a[2] = 0;
        ret = 0;
    }
    r = 0;
    if (ret != 0) {
        r = ret;
    }
    return r;
}

extern "C" void fn_801949C8(void) {
}

extern NaviEntry12 lbl_8029B128[];
extern u16 lbl_802EE628[];
extern u8 lbl_802EE470[];
extern "C" void fn_801949CC(s32 param_1, u8* p) {
    fn_801E10DC(p, param_1, lbl_8029B128[*(u32*)(p + 0xc)]);
}

extern "C" void fn_80194A2C(void) {
    lbl_802EE628[9] = 0xffff;
    lbl_802EE628[8] = 0xffff;
    lbl_802EE628[7] = 0xffff;
    lbl_802EE628[6] = 0xffff;
    lbl_802EE628[5] = 0xffff;
    lbl_802EE628[4] = 0xffff;
    lbl_802EE628[3] = 0xffff;
    lbl_802EE628[2] = 0xffff;
    lbl_802EE628[1] = 0xffff;
    lbl_802EE628[0] = 0xffff;
}

extern "C" void fn_80191EA0(u8* a, s32 b, s32 c);
extern "C" void fn_80194A68(u32 param_1, s32 param_2, s16 param_3) {
    *(volatile u8*)0xCC008000 = 0x20;
    *(volatile u16*)0xCC008000 = param_3;
    *(volatile u16*)0xCC008000 = (u16)(param_2 * 12) | 0xb000;
    *(volatile u8*)0xCC008000 = 0x28;
    *(volatile u16*)0xCC008000 = param_3;
    *(volatile u16*)0xCC008000 = (u16)(param_2 * 9 + 0x400) | 0x8000;
}

extern "C" void fn_80194AAC(u32 param_1, s32 param_2, s32 param_3) {
    fn_80191A60(*(u8**)(*(u8**)(lbl_802EE470 + 0x40) + 0x30), param_2 * 3);
    fn_80191EA0(lbl_802EE470, param_2, param_3);
}

extern "C" void fn_80194B58(u32 param_1, s32 param_2) {
    fn_80191A60(((u8*)lbl_802EE470[16])+0x30, param_2 * 3);
    fn_80191AE0(((u32*)lbl_802EE470[16])[12], param_2 * 3);
}

extern "C" void fn_801951A0(u32* p, u32 param_2, u32 param_3) {
    u8 buf[72];
    fn_801C5DA8(((u32*)lbl_802EE470[16])[12], (u8*)lbl_802EE470[65] + (u16)param_3 * 0x30, buf);
    if (lbl_802FF6D0 != 0) {
        fn_80194BB0(buf);
    }
    fn_80191A60(buf, param_2 * 3);
    ((void (*)(u32*, u32, u32, u8*))(*(u32**)p)[9])(p, param_2, param_3, buf);
}

extern "C" void fn_8019552C(u8* p) {
    u16 idx = *(u16*)(p + 4);
    NaviEntry12 tmp = lbl_80299AD0[lbl_802FF6B8];
    fn_801E10DC(p, 0, tmp);
}

extern "C" void fn_80195588(u8* p, s32 x, NaviEntry36* src, NaviEntry36* dst) {
    u16 idx = *(u16*)(p + 4);
    dst[idx] = src[idx];
    fn_801937C8(&dst[idx], x);
}

extern "C" void fn_801957E4(u8* p) {
    u16* list = *(u16**)(p + 0xc);
    u32 idx = lbl_802FF6B8;
    s32 count = *(u16*)(p + 8);
    NaviEntry12 tmp = lbl_80299AD0[idx];
    s32 i;
    for (i = 0; i < count; i++) {
        u16 v = list[0];
        if (v != 0xffff) {
            fn_801E10DC(p, i, tmp);
        }
        list++;
    }
}

extern "C" void fn_80195890(u8* p, s32 x, NaviEntry36* src, NaviEntry36* dst) {
    s32 i;
    for (i = 0; i < *(u16*)(p + 8); i++) {
        if (((u16*)*(void**)(p + 0xc))[i] != 0xffff) {
            dst[((u16*)*(void**)(p + 0xc))[i]] = src[((u16*)*(void**)(p + 0xc))[i]];
            fn_801937C8(&dst[((u16*)*(void**)(p + 0xc))[i]], x);
        }
    }
}

extern void* lbl_80299CF8[];
extern "C" void* fn_80195EB8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299CF8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E10;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299E38;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80195F24(void) { return 0x534D5942; }

extern "C" void fn_80195F30(void) {}

extern "C" u16 fn_80195F34(u8* p) { return *(u16*)(p + 4); }

extern void* lbl_80299D50[];
extern "C" void* fn_80195F3C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299D50;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E10;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299E38;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80195FA8(void) { return 0x534D4242; }

extern void* lbl_80299DA8[];
extern "C" void* fn_80195FB4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299DA8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E10;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299E38;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80196020(void) { return 0x534D4D43; }

extern "C" u16 fn_8019602C(u8* p) { return *(u16*)(p + 8); }

extern "C" u16 fn_80196034(u8* p, u16 idx) { return ((u16*)*(void**)(p + 0xC))[idx]; }

extern "C" void fn_80196044(void) {}

extern void* lbl_80299DF0[];
extern "C" void* fn_80196048(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299DF0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E38;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801960A4(void) { return 0x534D4D4C; }

extern "C" u16 fn_801960B0(u8* p) { return *(u16*)(p + 8); }

extern "C" u16 fn_801960B8(u8* p, u16 idx) { return ((u16*)*(void**)(p + 0xC))[idx]; }

extern void* lbl_80299E10[];
extern "C" void* fn_801960C8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299E10;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E38;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80196124(void) { return 0x534D4356; }

extern "C" void* fn_80196130(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299E38;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80196178(void) { return 0x534D5458; }

