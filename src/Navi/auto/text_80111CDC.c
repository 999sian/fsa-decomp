#include "types.h"

extern u8 lbl_802C5BFC[];
extern u8 lbl_802C5B90[];
extern void* lbl_8028F39C[];
extern void* lbl_8028F4EC[];
extern u8 lbl_802FF20C;
extern u8 lbl_802FF20D;
extern u8 lbl_802FF20E;
extern s32 lbl_802FF208;
extern "C" f32 lbl_803013C0;
extern "C" s32 fn_800137B8(void*, s32, s32);
extern u8 lbl_802BB0FC[];
extern "C" void fn_80114010(void);
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80111cdc-0x80114664 (28 functions). split_file divides it into the game's real files.

struct StateObj_80112488;
typedef BOOL (StateObj_80112488::*StateFunc_80112488)(int);
struct StateObj_80112488 {
    u8 pad[0x264];
    StateFunc_80112488 m_func;
    u8 pad2[0x90];
    s8 m_state;
    u8 pad3[3];
    s16 m_unk304[4];
    f32 m_unk30c[2];
};
extern void* lbl_8028F648[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80111E64(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" s32 fn_80111EE0(u8* p);
extern "C" void fn_80111EA0(u8* p) {
    fn_80111EE0(p);
}

extern "C" void fn_80111FE0(void);
extern "C" void fn_80111EC0(void) {
    fn_80111FE0();
}

extern "C" s32 fn_80111EE0(u8* p) {
    s32 i;
    f32 zero = lbl_803013C0;
    u8* base = lbl_802C5B90;
    u8* a = base;
    u8* b = base + 0x24;
    u8* c = base + 0x3c;
    u8* d = base + 0x54;
    *(f32*)(base + 0x0) = zero;
    *(f32*)(a + 0x4) = zero;
    *(f32*)(a + 0x8) = zero;
    *(f32*)(a + 0xc) = zero;
    *(f32*)(a + 0x10) = zero;
    *(f32*)(a + 0x14) = zero;
    *(f32*)(base + 0x24) = zero;
    *(f32*)(b + 0x4) = zero;
    *(f32*)(b + 0x8) = zero;
    lbl_802FF208 = 0;
    lbl_802FF20C = 0;
    lbl_802FF20E = 0;
    *(f32*)(base + 0x3c) = zero;
    *(f32*)(c + 0x4) = zero;
    *(f32*)(c + 0x8) = zero;
    *(f32*)(base + 0x54) = zero;
    *(f32*)(d + 0x4) = zero;
    *(f32*)(d + 0x8) = zero;
    *(s32*)(p + 0x240) = fn_800137B8(lbl_8028F39C[lbl_802FF20D], 0, 0);
    for (i = 0; i < 8; i++) {
        *(s32*)(p + 0x244 + i * 4) = fn_800137B8(lbl_8028F4EC[i], 0, 0);
    }
    return 2;
}

#pragma dont_inline on
extern "C" BOOL fn_801123B4(u8* p) {
    if (lbl_802C5BFC[0x74] != 0) {
        *(f32*)(p + 0xc8) = *(f32*)(lbl_802C5BFC + 0x24);
        *(f32*)(p + 0xcc) = *(f32*)(lbl_802C5BFC + 0x28);
        *(f32*)(p + 0xd0) = *(f32*)(lbl_802C5BFC + 0x2c);
        *(f32*)(p + 0xd8) = *(f32*)(lbl_802C5BFC + 0xc);
        *(f32*)(p + 0xdc) = *(f32*)(lbl_802C5BFC + 0x10);
        *(f32*)(p + 0xe0) = *(f32*)(lbl_802C5BFC + 0x14);
        *(f32*)(p + 0xe4) = *(f32*)(lbl_802C5BFC + 0x18);
        *(f32*)(p + 0xe8) = *(f32*)(lbl_802C5BFC + 0x1c);
        *(f32*)(p + 0xec) = *(f32*)(lbl_802C5BFC + 0x20);
        *(s16*)(p + 0xfc) = *(s16*)(lbl_802C5BFC + 0x6c);
    }
    if (lbl_802C5BFC[0x76] != 0) {
        *(f32*)(lbl_802BB0FC + 0x408) = *(f32*)(lbl_802C5BFC + 0x3c);
        *(f32*)(lbl_802BB0FC + 0x40c) = *(f32*)(lbl_802C5BFC + 0x40);
        *(f32*)(lbl_802BB0FC + 0x410) = *(f32*)(lbl_802C5BFC + 0x44);
        *(f32*)(lbl_802BB0FC + 0x414) = *(f32*)(lbl_802C5BFC + 0x48);
        *(f32*)(lbl_802BB0FC + 0x418) = *(f32*)(lbl_802C5BFC + 0x4c);
        *(f32*)(lbl_802BB0FC + 0x41c) = *(f32*)(lbl_802C5BFC + 0x50);
    }
    fn_80114010();
    return 1;
}
#pragma dont_inline reset

extern "C" s32 fn_801E10A0(void*);
extern "C" s32 fn_801E1070(void*);
extern "C" void fn_801E10DC(void*, void*);
extern "C" f32 lbl_803013C0;
extern "C" BOOL fn_80112488(StateObj_80112488* self, StateFunc_80112488* func, int arg) {
    if (fn_801E10A0(&self->m_func) != 0) {
        if (fn_801E1070(&self->m_func) != 0) {
            self->m_state = -1;
            (self->*self->m_func)(arg);
        }
        self->m_func = *func;
        self->m_state = 0;
        self->m_unk304[0] = 0;
        self->m_unk304[1] = 0;
        self->m_unk304[2] = 0;
        self->m_unk304[3] = 0;
        self->m_unk30c[0] = 0.0f;
        self->m_unk30c[1] = 0.0f;
        (self->*self->m_func)(arg);
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
extern "C" void fn_80114010(void);
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
