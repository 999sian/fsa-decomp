// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8015C828-8015DE10 (KETH). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// from src/Game/fn_8015C828_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A02B8[];

extern "C" void* fn_8015C828(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A02B8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/fn_8015C888.cpp
extern "C" s32 fn_802265DC(void* targetPos, void* arg1, s32 zero);

// fn_8015C888 - KETH's ("Keese") override of the base Actor vtable's
// slot 19 ("can I move this way" query, per
// project_fsa_actor_system_discovery.md and
// project_fsa_zlda_actor_progress.md, where it's called via a genuine
// virtual dispatch in update()). A thin forwarder: fn_802265DC(targetPos,
// arg1, 0) - not itself decompiled, but the fixed 0 second argument (vs
// whatever the base default passes) is consistent with Keese's erratic
// flight ignoring the normal terrain/ground movement constraint most
// grounded actors check.
extern "C" s32 fn_8015C888(void* this_, void* arg1, void* targetPos) {
    return fn_802265DC(targetPos, arg1, 0);
}

struct KethRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct KethGame { u8 pad[0xb4]; KethRandom rnd; };
extern KethGame* lbl_8053AAF8;

// KETH init (vtable slot 1)
extern "C" void fn_8015D844(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = 0.0f;
    *(f32*)(this_ + 0x84) = 0.0f;
    *(f32*)(this_ + 0x88) = 0.0f;
    *(f32*)(this_ + 0x8c) = 0.0f;
    *(u32*)(this_ + 0x260) = (*(u32*)(this_ + 0x90) >> 4) & 1;
    if (*(s32*)(this_ + 0x260) != 0) {
        *(f32*)(this_ + 0x60) = -12.0f;
        *(f32*)(this_ + 0x64) = -12.0f;
        *(f32*)(this_ + 0x68) = 12.0f;
        *(f32*)(this_ + 0x6c) = 12.0f;
        *(s32*)(this_ + 0xc0) = 2;
    }
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(u16*)(this_ + 0x25c) = 0;
    *(u8*)(this_ + 0x25e) = 0;
    if (*(u32*)(this_ + 0x90) & 0x100) {
        *(u8*)(this_ + 0x25e) = 1;
        *(u16*)(this_ + 0x25c) = 0x8000;
    }
    *(u32*)(this_ + 0x264) = *(u32*)(this_ + 0x90) & 0xf;
    if (*(s32*)(this_ + 0x264) == 3) {
        *(s32*)(this_ + 0x24c) = (s32)(1.99f * lbl_8053AAF8->rnd.get_ufloat_1());
        if (lbl_8053AAF8->rnd.get_ufloat_1() < 0.5f) {
            *(s32*)(this_ + 0x254) = -((s32)(512.0f * lbl_8053AAF8->rnd.get_ufloat_1()) + 0x200);
        } else {
            *(s32*)(this_ + 0x254) = (s32)(512.0f * lbl_8053AAF8->rnd.get_ufloat_1()) + 0x200;
        }
    }
    if (*(s32*)(this_ + 0x264) == 2) {
        KethGame* g = lbl_8053AAF8;
        *(f32*)(this_ + 0xc) += (f32)((s32)(9.0f * g->rnd.get_ufloat_1()) - 4);
        KethGame* g2 = lbl_8053AAF8;
        *(f32*)(this_ + 0x10) += (f32)((s32)(9.0f * g2->rnd.get_ufloat_1()) - 4);
        *(JGeometry::TVec3<f32>*)(this_ + 0x24) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    }
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(u32*)(this_ + 0xb0) = 0x31201;
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(f32*)(this_ + 0x27c) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(s32*)(this_ + 0x258) = 2;
    *(u16*)(this_ + 0x268) = 0;
    *(u16*)(this_ + 0x26a) = 0xffff;
    *(f32*)(this_ + 0x14) = 1.0f;
    if (*(u32*)(this_ + 0x90) >> 27) {
        *(u32*)(this_ + 0xb0) = 0;
    }
    if (*(s32*)(this_ + 0x264) == 4) {
        *(f32*)(this_ + 0x14) = 0.0f;
        *(s32*)(this_ + 0x230) = 3;
    } else {
        *(s32*)(this_ + 0x230) = 0;
    }
    *(f32*)(this_ + 0x280) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x14);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
