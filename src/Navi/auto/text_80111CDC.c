#include "types.h"

extern u8 lbl_802C5BFC[];
extern u8 lbl_802BB0FC[];
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80111cdc-0x80114664 (28 functions). split_file divides it into the game's real files.

extern void* lbl_8028F648[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80111E64(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80111EE0(void);
extern "C" void fn_80111EA0(void) {
    fn_80111EE0();
}

extern "C" void fn_80111FE0(void);
extern "C" void fn_80111EC0(void) {
    fn_80111FE0();
}

extern "C" s32 fn_801E10A0(void*);
extern "C" s32 fn_801E1070(void*);
extern "C" void fn_801E10DC(void*, void*);
extern "C" f32 lbl_803013C0;
extern "C" BOOL fn_80112488(u8* p, u32* src, void* arg) {
    if (fn_801E10A0(p + 0x264) != 0) {
        if (fn_801E1070(p + 0x264) != 0) {
            *(s8*)(p + 0x300) = -1;
            fn_801E10DC(p, arg);
        }
        *(u32*)(p + 0x264) = src[0];
        *(u32*)(p + 0x268) = src[1];
        *(u32*)(p + 0x26c) = src[2];
        p[0x300] = 0;
        *(s16*)(p + 0x304) = 0;
        *(s16*)(p + 0x306) = 0;
        *(s16*)(p + 0x308) = 0;
        *(s16*)(p + 0x30a) = 0;
        *(f32*)(p + 0x30c) = 0.0f;
        *(f32*)(p + 0x310) = 0.0f;
        fn_801E10DC(p, arg);
    }
    return TRUE;
}

extern "C" void fn_8011217C(void);
extern "C" void fn_80114118(void) {
    fn_8011217C();
}

extern u8 lbl_802B7CA0[];
extern u8 lbl_802C5BFC[];
extern u8 lbl_8029FDB4[];
extern "C" void fn_80159C6C(void*, s32);
extern "C" void fn_800127A0(void*);
extern "C" s32 fn_80114138(u8* p) {
    s32 i;
    *(s32*)(lbl_802B7CA0 + 0x13e4) = 0;
    fn_80159C6C(*(void**)(p + 0x2d0), 0);
    *(void**)(p + 0x2d0) = 0;
    *(void**)(p + 0x2d4) = 0;
    for (i = 0; i < 8; i++) {
        fn_80159C6C(*(void**)(p + 0x2d8), 0);
        *(void**)(p + 0x2d8) = 0;
        p += 4;
    }
    u8* s = lbl_802C5BFC;
    s8 b = *(s8*)(s + 4);
    if (b >= 0) {
        if (--*(s32*)(s + 8) == 0) {
            fn_800127A0(lbl_8029FDB4 + 4);
            *(s8*)(s + 4) = -1;
        }
    }
    return 1;
}

extern "C" BOOL fn_801123B4(u8* p);
extern "C" void fn_801143FC(u8* p) {
    fn_801123B4(p);
}

extern "C" BOOL fn_8011441C(void);
extern "C" BOOL fn_8011441C(void)
{
    return TRUE;
}

extern "C" void fn_801145CC(f32* out, u8* obj) {
    out[0] = *(f32*)(obj + 0x414);
    out[1] = *(f32*)(obj + 0x418);
    out[2] = *(f32*)(obj + 0x41c);
}

extern u8 lbl_8028F1E0[];
extern u8 lbl_80301398;
extern "C" void fn_801145E8(void* out, s32 idx) {
    u8* tbl = &lbl_80301398;
    s32 off = tbl[idx] * 0x18;
    u32* src = (u32*)(lbl_8028F1E0 + off);
    u32 a = src[0];
    u32 b = src[1];
    ((u32*)out)[0] = a;
    ((u32*)out)[1] = b;
    ((u32*)out)[2] = src[2];
}

extern "C" void* fn_8011461C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F648;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
