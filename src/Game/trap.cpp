// TRAP actor. TU 801643C4-8016545C.
// Functions: dtor, move check (TODO), draw (slot 6, TODO), update (slot 3, TODO), init (slot 1).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
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
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* slot, s32 room, void* pos, u32 id, const void* ext);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u8* fn_802D6A9C(void);
extern const char lbl_804662A8[];

// TRAP move check: can the trap move onto pos?
extern "C" u8 fn_80164424(char* this_, s32 room, void* pos) {
    u32 id = *(u32*)(this_ + 0x198);
    u8* mgr = fn_8020D58C();
    if (fn_8020D6AC(mgr + 4 + mgr[1] * 0x784, room, pos, id, lbl_804662A8) == 1) {
        return 1;
    }
    if (*(s32*)(this_ + 0x24C) == 0) {
        s32 kind = fn_8022461C(pos, room);
        if (kind != 0 && kind != 4 && kind != 5 && kind != 6 && kind != 7 && kind != 2 && kind != 3 && kind != 0x50 && kind != 0xE && kind != 0xC && kind != 0x27 && kind != 0x28 && kind != 0x29 && kind != 0x2A && kind != 0x2B && kind != 0x2C && kind != 0x2D && kind != 0x2E && kind != 0x2F && kind != 0x20 && kind != 0xD && kind != 0x39 && kind != 0x3A && kind != 0x3B && kind != 0x4C && kind != 0x4D && kind != 0x4E && kind != 0x4F && kind != 0x24) {
            if ((u32)(kind - 0x10) <= 2 || kind == 0x13) {
                *(s32*)(this_ + 0x24C) = 0x78;
                return 0;
            }
            if (kind == 0x25) {
                return fn_802D6A9C()[0x171] == 0;
            }
            if (kind == 0x26) {
                return fn_802D6A9C()[0x171] == 1;
            }
            if (kind != 0x22 || fn_802D6A9C()[0x170] == 1) {
                return 1;
            }
        }
    } else {
        *(s32*)(this_ + 0x24C) = *(s32*)(this_ + 0x24C) - 1;
    }
    return 0;
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
