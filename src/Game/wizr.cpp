// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801769D8-80179150 (WIZR). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"

// from src/Game/fn_80178D24.cpp
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);

extern "C" void fn_80178D24(void* this_) {
    char* p = (char*)this_;
    u16 kind = *(u16*)(p + 0x94);
    if (kind == 0 || (u16)(kind - 4) <= 1 || (u16)(kind - 1) <= 1 || kind == 3) {
        s32 id = *(s32*)(p + 0x268);
        if (id >= 0) {
            void* base = fn_801F856C();
            void* found = fn_801F666C(base, id);
            if (found != 0) {
                *(s32*)(p + 0x268) = -1;
                *(s32*)((char*)found + 0x108) = 0;
            }
        }
    }
    *(s32*)(p + 0x238) = 0;
    *(char*)(p + 0x2e4) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x230) = 8;
}

// from src/Game/fn_80178DD0_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* table, s32 index);
extern void* lbl_804A0EDC[];

extern "C" void* fn_80178DD0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0EDC;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x300));
        fn_801EE434(*(void**)(p + 0x304));
        fn_801EE434(*(void**)(p + 0x308));
        u16 state = *(u16*)(p + 0x94);
        if (state == 0 || (u16)(state - 4) <= 1 || (u16)(state - 1) <= 1 || state == 3) {
            s32 idx = *(s32*)(p + 0x268);
            if (idx >= 0) {
                void* table = fn_801F856C();
                void* found = fn_801F666C(table, idx);
                if (found != 0) {
                    *(s32*)(p + 0x268) = -1;
                    *(s32*)((char*)found + 0x108) = 0;
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// Small (inline-style) accessors.
extern "C" void fn_80178EB8(char* this_, const f32* src) {
    f32* dst = (f32*)(this_ + 0xa4);
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
}
extern "C" void fn_80178ED4(s16* v, s16 x, s16 y, s16 z) { v[0] = x; v[1] = y; v[2] = z; }
extern "C" void fn_80178EE4(char* this_, const f32* src) {
    f32* dst = (f32*)(this_ + 0x18);
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
}
extern "C" void fn_80178F00(f32* v, f32 x, f32 y, f32 z) { v[0] = x; v[1] = y; v[2] = z; }
extern "C" void fn_80178F10(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern u8 lbl_80466854[];
extern const f32 lbl_8053DBB0;

extern "C" void fn_801769D8(char* p) {
    u16 kind = *(u16*)(p + 0x94);
    if (kind == 0x14 || (u16)(kind - 0x15) <= 2 || kind == 0x1e || kind == 0x1f) {
        return;
    }
    if (*(s32*)(p + 0x230) != 1 && *(s32*)(p + 0x230) != 0) {
        DrawRec rec;
        kind = *(u16*)(p + 0x94);
        if (kind == 10 || kind == 11) {
            return;
        }
        ((u8*)&rec.w10)[3] = (s32)*(f32*)(p + 0x2d0);
        if (*(u8*)(p + 0x234) == 1) {
            rec.w30 = 0x11;
        }
        fn_801F06F0(p, lbl_80466854, *(s32*)(p + 0x260) + 0xe9, &rec, 0, lbl_8053DBB0, lbl_8053DBB0);
    }
}

extern "C" s32 fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern const f32 lbl_8053DBE8;
extern const f32 lbl_8053DBEC;
extern const f32 lbl_8053DBB4;
extern const f32 lbl_8053DBC4;
extern const f32 lbl_8053DC10;
extern const f32 lbl_8053DC14;
extern const f32 lbl_8053DC18;
extern const f32 lbl_8053DBDC;
extern const f32 lbl_8053DBB8;
extern const f32 lbl_8053DBF4;
extern void* lbl_8053AAF8;
extern "C" void fn_801788B4(char* this_) {
    u32 spawn = *(u32*)(this_ + 0x90);
    *(s32*)(this_ + 0x2c8) = (spawn >> 22) & 0x1f;
    *(u16*)(this_ + 0x94) = (u8)*(u32*)(this_ + 0x90);
    *(f32*)(this_ + 0x60) = lbl_8053DBE8;
    *(f32*)(this_ + 0x64) = lbl_8053DBE8;
    *(f32*)(this_ + 0x68) = lbl_8053DBEC;
    *(f32*)(this_ + 0x6c) = lbl_8053DBEC;
    *(f32*)(this_ + 0x80) = lbl_8053DBE8;
    *(f32*)(this_ + 0x84) = lbl_8053DBE8;
    *(f32*)(this_ + 0x88) = lbl_8053DBEC;
    *(f32*)(this_ + 0x8c) = lbl_8053DBEC;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x270) = -1;
    *(s32*)(this_ + 0x274) = -1;
    *(s32*)(this_ + 0x278) = -1;
    *(s32*)(this_ + 0x27c) = -1;
    *(s32*)(this_ + 0x280) = -1;
    *(s32*)(this_ + 0x284) = -1;
    *(s32*)(this_ + 0x288) = -1;
    *(s32*)(this_ + 0x28c) = -1;
    *(s32*)(this_ + 0x290) = -1;
    *(s32*)(this_ + 0x294) = -1;
    *(s32*)(this_ + 0x298) = -1;
    *(s32*)(this_ + 0x29c) = -1;
    *(s32*)(this_ + 0x2a0) = -1;
    *(s32*)(this_ + 0x2a4) = -1;
    *(s32*)(this_ + 0x2a8) = -1;
    *(s32*)(this_ + 0x2ac) = -1;
    *(s32*)(this_ + 0x2b0) = -1;
    *(s32*)(this_ + 0x2b4) = -1;
    *(s32*)(this_ + 0x2b8) = -1;
    *(s32*)(this_ + 0x2bc) = -1;
    *(s32*)(this_ + 0x300) = 0;
    *(s32*)(this_ + 0x304) = 0;
    *(s32*)(this_ + 0x308) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(u8*)(this_ + 0x2e4) = 0;
    *(f32*)(this_ + 0x2d0) = lbl_8053DBB4;
    *(f32*)(this_ + 0x2d4) = lbl_8053DBB4;
    *(f32*)(this_ + 0x2d8) = lbl_8053DBC4;
    *(s32*)(this_ + 0x268) = -1;
    *(s32*)(this_ + 0x26c) = -1;
    *(f32*)(this_ + 0x2e0) = lbl_8053DBB4;
    *(u16*)(this_ + 0x2cc) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(u8*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x2c0) = 0;
    *(s32*)(this_ + 0x2c4) = 0xc8;
    *(f32*)(this_ + 0x2dc) = lbl_8053DBB0;
    *(f32*)(this_ + 0x2f0) = lbl_8053DBB4;
    *(f32*)(this_ + 0x2ec) = lbl_8053DBB4;
    *(f32*)(this_ + 0x2e8) = lbl_8053DBB4;
    *(f32*)(this_ + 0x44) = lbl_8053DBB4;
    *(f32*)(this_ + 0x40) = lbl_8053DBB4;
    *(f32*)(this_ + 0x3c) = lbl_8053DBB4;
    *(f32*)(this_ + 0x2f4) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2f8) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2fc) = *(f32*)(this_ + 0x14);
    *(u8*)(this_ + 0x2e5) = 0;

    switch (*(u16*)(this_ + 0x94)) {
    default: {
        char* rng = (char*)lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(this_ + 0x250) = (s32)(lbl_8053DC10 * (*(f32*)&bits - lbl_8053DBB0));
        *(s32*)(this_ + 0x250) &= 3;
        if ((*(u32*)(this_ + 0x90) >> 27) != 0 && (*(s32(**)(void*))(*(char**)this_ + 0x34))(this_) == 0) {
            *(u8*)(this_ + 0x1a8) = 0;
            *(u8*)(this_ + 0x2e5) = 1;
            *(s32*)(this_ + 0x230) = 0;
            break;
        }
    }
    case 10:
    case 11:
        *(u8*)(this_ + 0x1a8) = 0;
        *(f32*)(this_ + 0x60) = lbl_8053DC14;
        *(f32*)(this_ + 0x64) = lbl_8053DC14;
        *(f32*)(this_ + 0x68) = lbl_8053DC18;
        *(f32*)(this_ + 0x6c) = lbl_8053DC18;
        *(f32*)(this_ + 0x80) = lbl_8053DBDC;
        *(f32*)(this_ + 0x84) = lbl_8053DBDC;
        *(f32*)(this_ + 0x88) = lbl_8053DBB8;
        *(f32*)(this_ + 0x8c) = lbl_8053DBB8;
        *(s32*)(this_ + 0x108) = 0x2710;
        *(s32*)(this_ + 0x238) = 10;
        *(s32*)(this_ + 0x23c) = 10;
        *(s32*)(this_ + 0x240) = 0xc8;
        *(f32*)(this_ + 0x14) = lbl_8053DBEC;
        *(s32*)(this_ + 0x230) = 0xc;
        break;
    case 20:
        *(f32*)(this_ + 0x2dc) = lbl_8053DBF4;
        *(s32*)(this_ + 0x300) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, *(f32*)(this_ + 0x2dc), 0x506, 0, 1, 0, 0, 1);
        *(s32*)(this_ + 0x304) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, *(f32*)(this_ + 0x2dc), 0x507, 0, 1, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053DBB0, 0x508, 0, 1, 0, 0, 1);
        *(u8*)(this_ + 0x1a8) = 0;
        *(s32*)(this_ + 0x238) = 10;
        *(s32*)(this_ + 0x108) = 0x2710;
        *(s32*)(this_ + 0x230) = 0xd;
        break;
    case 22:
        *(f32*)(this_ + 0x2dc) = lbl_8053DBF4;
        *(s32*)(this_ + 0x300) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, *(f32*)(this_ + 0x2dc), 0x506, 0, 1, 0, 0, 1);
        *(s32*)(this_ + 0x304) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, *(f32*)(this_ + 0x2dc), 0x507, 0, 1, 0, 0, 1);
        fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_8053DBB0, 0x508, 0, 1, 0, 0, 1);
        *(u8*)(this_ + 0x1a8) = 0;
        *(s32*)(this_ + 0x238) = 0x1e;
        *(s32*)(this_ + 0x108) = 0x2710;
        *(s32*)(this_ + 0x230) = 0xf;
        break;
    case 23:
        *(s32*)(this_ + 0x300) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, *(f32*)(this_ + 0x2dc), 0x50d, 1, 1, 0, 0, 1);
        *(s32*)(this_ + 0x304) = fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, *(f32*)(this_ + 0x2dc), 0x50e, 1, 1, 0, 0, 1);
        *(u8*)(this_ + 0x1a8) = 0;
        *(s32*)(this_ + 0x23c) = 0x28;
        *(s32*)(this_ + 0x108) = 0x2710;
        *(s32*)(this_ + 0x230) = 0x10;
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
