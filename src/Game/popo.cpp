// POPO (Poppo?) actor. TU 80172170-80172894.
// Functions: dtor, draw (slot 6), update (slot 3, not yet decompiled), init (slot 1).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);
extern void* lbl_804A0868[];

struct PopoRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct PopoGame { u8 pad[0xb4]; PopoRandom rnd; };
extern PopoGame* lbl_8053AAF8;

// POPO destructor
extern "C" void* fn_80172170(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0868;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// POPO draw (vtable slot 6)
extern "C" void fn_801721D0(char* this_) {
    fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x24c) + 0x99, 1.0f, 1.0f, 0, 0);
}

// POPO init (vtable slot 1)
extern "C" void fn_80172530(char* this_) {
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 0xff;
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
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x250) = 0.0f;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(u32*)(this_ + 0xb0) = 0x11101;
    PopoGame* g = lbl_8053AAF8;
    *(s32*)(this_ + 0x240) = (s32)(1.99f * g->rnd.get_ufloat_1());
    PopoGame* g2 = lbl_8053AAF8;
    *(s32*)(this_ + 0x238) = (s32)(10.0f * g2->rnd.get_ufloat_1()) + 10;
    if (*(u32*)(this_ + 0x90) == 1) {
        *(u32*)(this_ + 0xb0) = 0;
    }
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
