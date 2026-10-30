#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8006d2d0-0x8006f1b4 (29 functions). split_file divides it into the game's real files.

extern void* lbl_80280910[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8006D320(void);
extern void* lbl_802473D8[];
extern "C" void fn_8006D2D0(void* p);
extern "C" void fn_8006D2D0(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_802473D8;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
}

extern "C" void fn_8006D300(void) {
    fn_8006D320();
}

extern "C" void fn_80041268(void*, void*, s32);
extern "C" void fn_8000E0F0(void*, void*, f32);
extern "C" void fn_8000EBB8(void*);
extern "C" void fn_80115914(f32*, void*);
extern "C" void fn_801C61AC(void*, f32, f32, f32);
extern "C" void fn_8000C950(void*, s32, s32, s32);
extern "C" void fn_801C5D74(void*, void*);
extern "C" BOOL fn_801E10A0(void*);
extern "C" BOOL fn_801E1070(void*);
extern "C" void fn_801E10DC(void*, void*);
extern u8 lbl_8029F8D8[];
extern f32 lbl_802BF784[];
extern "C" BOOL fn_8006D5A8(char* p) {
    if (p[0x26c] == 0) {
        p[0x26c]++;
    }
    return TRUE;
}

extern u8 lbl_802FC990;
extern "C" void fn_800636F4(void*, void*, s32);
extern char lbl_802B7CA0[];
extern "C" int fn_8006D760(void)
{
    fn_800636F4(&lbl_802FC990, lbl_802B7CA0 + 0x2200, 0x40);
    return 1;
}

extern "C" BOOL fn_8006D93C(u8* p) {
    fn_80041268(*(void**)(p + 0x24c), p + 0x180, 5);
    fn_8000E0F0(p + 0x254, *(u8**)(*(u8**)(p + 0x24c) + 4) + 0x58, *(f32*)(*(u8**)(p + 0x258) + 0x10));
    fn_8000EBB8(*(void**)(p + 0x24c));
    fn_8000E0F0(p + 0x260, *(u8**)(*(u8**)(p + 0x250) + 4) + 0x58, *(f32*)(*(u8**)(p + 0x264) + 0x10));
    fn_8000EBB8(*(void**)(p + 0x250));
    return TRUE;
}

extern "C" BOOL fn_8006D9C0(void);
extern "C" BOOL fn_8006D9C0(void)
{
    return TRUE;
}

extern "C" void fn_8006DAD4(void);
extern "C" void fn_8006D9C8(void) {
    fn_8006DAD4();
}

extern "C" void fn_800175B8(void*);
extern "C" int fn_800183AC(void*, void*, s32);
extern "C" int fn_8006DD20(void*);
extern void* lbl_8027F6DC[];
extern void* lbl_8027FCD0[];
extern void* lbl_8027FB48[];
#pragma push
#pragma dont_inline on
extern "C" int fn_8006D9E8(u8* p) {
    if ((*(u32*)(p + 0xf8) & 8) == 0) {
        if (p != nullptr) {
            fn_800175B8(p);
            *(void**)(p + 0x254) = lbl_8027F6DC;
            *(u32*)(p + 0x258) = 0;
            *(void**)(p + 0x254) = lbl_8027FCD0;
            *(u32*)(p + 0x25c) = 0;
            *(void**)(p + 0x260) = lbl_8027F6DC;
            *(u32*)(p + 0x264) = 0;
            *(void**)(p + 0x260) = lbl_8027FB48;
            *(u32*)(p + 0x268) = 0;
            *(u8*)(p + 0x295) = *(u32*)(p + 0xb0) >> 24;
            *(u8*)(p + 0x296) = *(u32*)(p + 0xb0) >> 16;
            *(u8*)(p + 0x298) = (*(u32*)(p + 0xb0) >> 12) & 0xf;
            *(u8*)(p + 0x294) = (*(u32*)(p + 0xb0) >> 8) & 0xf;
            *(u8*)(p + 0x297) = *(u32*)(p + 0xb0);
        }
        *(u32*)(p + 0xf8) |= 8;
    }
    if ((u8)fn_800183AC(p, (void*)fn_8006D9C8, 0x15a0)) {
        return fn_8006DD20(p);
    }
    return 5;
}
#pragma pop

extern "C" void fn_8006E190(u8* p) {
    f32 v[3];
    fn_80115914(v, p + 0x278);
    u8* q = *(u8**)(p + 0x250);
    *(f32*)(q + 0x18) = v[0];
    *(f32*)(q + 0x1c) = v[1];
    *(f32*)(q + 0x20) = v[2];
    fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130) + lbl_802BF784[0x6c / 4]);
    fn_8000C950(lbl_8029F8D8, *(s16*)(p + 0x13c), *(s16*)(p + 0x13e), *(s16*)(p + 0x140));
    fn_801C5D74(lbl_8029F8D8, *(u8**)(p + 0x250) + 0x24);
}

extern "C" BOOL fn_8006E244(u8* p, u32* src, void* arg) {
    if (fn_801E10A0(p + 0x2a0) != 0) {
        if (fn_801E1070(p + 0x2a0) != 0) {
            p[0x299] = -1;
            fn_801E10DC(p, arg);
        }
        u32 b = src[0];
        u32 a = src[1];
        *(u32*)(p + 0x2a0) = b;
        *(u32*)(p + 0x2a4) = a;
        *(u32*)(p + 0x2a8) = src[2];
        p[0x299] = 0;
        fn_801E10DC(p, arg);
    }
    return TRUE;
}

extern "C" int fn_8006D9E8(u8* p);
extern "C" void fn_8006EA60(u8* p) {
    fn_8006D9E8(p);
}

extern u8 lbl_802C2E44[];
extern u8 lbl_8029FDB4[];
extern "C" void fn_800127A0(void* p);
extern "C" s32 fn_8006EA80(u8* p) {
    s8 b = (s8)lbl_802C2E44[4];
    if (b >= 0) {
        if (--*(s32*)&lbl_802C2E44[8] == 0) {
            fn_800127A0(lbl_8029FDB4 + 4);
            *(s8*)&lbl_802C2E44[4] = -1;
        }
    }
    u8* q = *(u8**)(p + 0x26c);
    if (q != NULL) {
        *(u32*)(q + 0xf4) |= 1;
        *(s32*)(q + 0x24) = 1;
        *(u8**)(p + 0x26c) = NULL;
    }
    return 1;
}

extern "C" void fn_8006DEC4(void);
extern "C" void fn_8006EC94(void) {
    fn_8006DEC4();
}

extern "C" BOOL fn_8006ECB4(void);
extern "C" BOOL fn_8006ECB4(void)
{
    return TRUE;
}

extern "C" u8 lbl_802C2E50[];
extern "C" u8 lbl_802FF188;
extern "C" u8 lbl_802FF189;
extern "C" u8 lbl_802FF18A;
extern "C" u8 lbl_802FF18B;
extern "C" f32 lbl_803004B0;
extern "C" void fn_8006ECBC(void) {
    int i;
    lbl_802FF188 = 0;
    lbl_802FF189 = 0;
    lbl_802FF18A = 0;
    lbl_802FF18B = 0;
    for (i = 0; i < 256; i++) {
        *(u8*)(lbl_802C2E50 + i * 0x20 + 0x1d) = 0;
        *(s32*)(lbl_802C2E50 + i * 0x20 + 0x18) = 0;
        *(f32*)(lbl_802C2E50 + i * 0x20 + 0x0) = lbl_803004B0;
        *(f32*)(lbl_802C2E50 + i * 0x20 + 0x4) = lbl_803004B0;
        *(f32*)(lbl_802C2E50 + i * 0x20 + 0x8) = lbl_803004B0;
    }
}

extern "C" u8 lbl_802BB0FC[];
extern "C" void fn_8008D938(void* p);
extern "C" void fn_800181AC(s32 a, u32 b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" void fn_8006F0F4(void) {
    f32 b[3];
    f32 a[3];
    if (*(s32*)(lbl_802BB0FC + 0x44) == 0xc) {
        fn_8008D938(a);
        b[0] = a[0];
        b[1] = a[1];
        b[2] = a[2];
        fn_800181AC(0x10, 0x1000080, b, 0, 0, -1, 0, 0);
    }
}

extern "C" void* fn_8006F16C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80280910;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
