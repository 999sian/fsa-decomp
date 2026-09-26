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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
