// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80184040-80184D64 (FAGN). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_80184040_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A1888[];

extern "C" void* fn_80184040(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1888;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/fn_80184A14.cpp
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801F5790(void* this_);

// fn_80184A14(this) - sibling of fn_8018316C (see that file's banner
// and project_fsa_80212af0_callers_closed.md) - a third class's
// vtable-slot-0x18 override doing the identical "repel from RUSA
// zones, then chain to the generic slot-0x18 default" pattern.
extern "C" void fn_80184A14(void* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, (char*)this_ + 0xc);
    fn_801F5790(this_);
}
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);

// FAGN draw (vtable slot 6)
extern "C" void fn_801840A0(char* this_) {
    fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x24c) + 0x145, 1.0f, 1.0f, 0, 7);
}

struct FagnRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct FagnGame { u8 pad[0xb4]; FagnRandom rnd; };
extern FagnGame* lbl_8053AAF8;

// FAGN init (vtable slot 1)
extern "C" void fn_80184A50(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x98) = (s32)(3.99f * lbl_8053AAF8->rnd.get_ufloat_1());
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x98) * 4;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0xb8) = 1;
    *(u8*)(this_ + 0x195) = 1;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x250) = 1.0f;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
