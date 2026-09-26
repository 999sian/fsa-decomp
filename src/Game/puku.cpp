// PUKU actor. TU 8017B140-8017C01C.
// Functions: dtor, draw (slot 6, TODO), update (slot 3, TODO), tile check, init (slot 1).
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" u16 fn_8022461C(void* pos);
extern void* lbl_804A11B8[];

struct PukuRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct PukuGame { u8 pad[0xb4]; PukuRandom rnd; };
extern PukuGame* lbl_8053AAF8;

// PUKU destructor
extern "C" void* fn_8017B140(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A11B8;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// PUKU: can it move onto the tile at pos? (tile types 0x3b, 0, 2, 3 block)
extern "C" BOOL fn_8017BBA8(void* this_, void* arg1, void* pos) {
    s32 t = (u16)fn_8022461C(pos);
    BOOL ret;
    if (t != 0x3b && t != 0 && t != 2 && t != 3) {
        ret = TRUE;
    } else {
        ret = FALSE;
    }
    return ret;
}

// PUKU init (vtable slot 1)
extern "C" void fn_8017BBFC(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(u32*)(this_ + 0x258) = *(u32*)(this_ + 0x90) & 1;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s16*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x260) = 8.0f * (f32)((*(u32*)(this_ + 0x90) >> 8) & 0xff);
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x270) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x274) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x278) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x98) = (s32)(1.99f * lbl_8053AAF8->rnd.get_ufloat_1());
    if (*(s32*)(this_ + 0x258) == 1) {
        *(s32*)(this_ + 0x254) = (s32)(1.99f * lbl_8053AAF8->rnd.get_ufloat_1());
        *(s32*)(this_ + 0x114) = 4;
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -16.0f;
        *(f32*)(this_ + 0x68) = 16.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        *(f32*)(this_ + 0x80) = -16.0f;
        *(f32*)(this_ + 0x84) = -10.0f;
        *(f32*)(this_ + 0x88) = 16.0f;
        *(f32*)(this_ + 0x8c) = 10.0f;
    }
    *(s32*)(this_ + 0x230) = 0;
    if ((*(u32*)(this_ + 0x90) >> 4) & 0xff) {
        if (*(f32*)(this_ + 0x260) == 0.0f) {
            *(f32*)(this_ + 0x260) = 16.0f;
        }
        *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
        *(s32*)(this_ + 0x98) = *(s32*)(this_ + 0x98) - 1;
        *(u32*)(this_ + 0x98) = *(u32*)(this_ + 0x98) & 3;
        *(s32*)(this_ + 0x230) = 4;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
