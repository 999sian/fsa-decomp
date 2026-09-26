// TRAP actor. TU 801643C4-8016545C.
// Functions: dtor, move check (TODO), draw (slot 6, TODO), update (slot 3, TODO), init (slot 1).
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A04D8[];

struct TrapRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct TrapGame { u8 pad[0xb4]; TrapRandom rnd; };
extern TrapGame* lbl_8053AAF8;

// TRAP destructor
extern "C" void* fn_801643C4(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A04D8;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// TRAP init (vtable slot 1)
extern "C" void fn_801650AC(char* this_) {
    *(f32*)(this_ + 0x60) = -6.0f;
    *(f32*)(this_ + 0x64) = -6.0f;
    *(f32*)(this_ + 0x68) = 6.0f;
    *(f32*)(this_ + 0x6c) = 6.0f;
    *(f32*)(this_ + 0x80) = -3.0f;
    *(f32*)(this_ + 0x84) = -3.0f;
    *(f32*)(this_ + 0x88) = 3.0f;
    *(f32*)(this_ + 0x8c) = 3.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(u32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 4) & 1;
    if (*(s32*)(this_ + 0x254) != 0) {
        *(f32*)(this_ + 0x60) = -12.0f;
        *(f32*)(this_ + 0x64) = -12.0f;
        *(f32*)(this_ + 0x68) = 12.0f;
        *(f32*)(this_ + 0x6c) = 12.0f;
    }
    *(u32*)(this_ + 0x98) = *(u32*)(this_ + 0x90) & 3;
    *(u32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    *(s32*)(this_ + 0x260) = 0;
    if (*(s32*)(this_ + 0x258) != 0) {
        *(s32*)(this_ + 0x260) = (s32)(3.0f * lbl_8053AAF8->rnd.get_ufloat_1());
    }
    *(f32*)(this_ + 0x274) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x27c) = *(f32*)(this_ + 0x14);
    *(u8*)(this_ + 0x264) = 0;
    if (*(u32*)(this_ + 0x90) & 4) {
        *(u8*)(this_ + 0x264) = 1;
    }
    *(s32*)(this_ + 0xb8) = 2;
    *(s32*)(this_ + 0x230) = 0;
    if (*(s32*)(this_ + 0x25c) != 0) {
        *(s32*)(this_ + 0x230) = 3;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
