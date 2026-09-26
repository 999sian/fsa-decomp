// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80184D64-80187144 (WNWN). Remaining functions are not yet decompiled.
#include "types.h"

extern const f32 lbl_8053DF40;
extern const f32 lbl_8053DF44;
extern const f32 lbl_8053DF54;
extern const f32 lbl_8053DF60;
extern const f32 lbl_8053DFD0;
extern const f32 lbl_8053DFD4;
extern const f32 lbl_8053DFD8;

// from src/Game/fn_80184D64_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A18E0[];

extern "C" void* fn_80184D64(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A18E0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct WnwnVec {
    f32 x, y, z;
};

struct Wnwn {
    u8 pad0[0xc];
    WnwnVec pos;          // 0x0c
    u8 pad18[0x274 - 0x18];
    s16 ang[10];          // 0x274
    u8 pad288[0x294 - 0x288];
    WnwnVec trail[10];    // 0x294
    WnwnVec trail2[10];   // 0x30c
    WnwnVec home;         // 0x384
};

struct WnwnRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053DF40;
    }
};
struct WnwnGame { u8 pad[0xb4]; WnwnRandom rnd; };
extern WnwnGame* lbl_8053AAF8;
extern "C" u16 fn_801F6874(s32 dir);

extern "C" void fn_80186D24(char* this_) {
    f32 b = lbl_8053DF60;
    f32 a = lbl_8053DFD0;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(f32*)(this_ + 0x70) = lbl_8053DFD4;
    *(f32*)(this_ + 0x74) = lbl_8053DFD4;
    *(f32*)(this_ + 0x78) = lbl_8053DF54;
    *(f32*)(this_ + 0x7c) = lbl_8053DF54;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x98) = (s32)(lbl_8053DFD8 * lbl_8053AAF8->rnd.get_ufloat_1());
    *(s16*)(this_ + 0x272) = fn_801F6874(*(s32*)(this_ + 0x98));
    *(s32*)(this_ + 0x264) = (*(s32*)(this_ + 0x98) << 1) + *(s32*)(this_ + 0x24c);
    *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0x290) = lbl_8053DF44;
    Wnwn* w = (Wnwn*)this_;
    w->home.x = w->pos.x;
    w->home.y = w->pos.y;
    w->home.z = w->pos.z;
    *(u16*)(this_ + 0x270) = 0xffff;
    for (s32 i = 0; i < 10; i++) {
        w->trail[i].x = w->pos.x;
        w->trail[i].y = w->pos.y;
        w->trail[i].z = w->pos.z;
        w->trail2[i].x = w->pos.x;
        w->trail2[i].y = w->pos.y;
        w->trail2[i].z = w->pos.z;
        w->ang[i] = 0;
    }
    *(f32*)(this_ + 0x26c) = lbl_8053DF44;
    *(s32*)(this_ + 0x268) = 3;
    *(s32*)(this_ + 0x260) = -1;
    *(s32*)(this_ + 0x118) = 4;
    *(u32*)(this_ + 0xb0) = 0x0a040004;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
