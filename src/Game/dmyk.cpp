// TU 0x802f3b74-0x802f3f7c (actor DMYK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Dmyk_dtor_802F3B74.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA6A0[];

extern "C" void* fn_802F3B74(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA6A0;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Dmyk_EmptyHook.cpp ----
// Dmyk_EmptyHook - DMYK: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Dmyk_EmptyHook(void) {}

}

// ---- Dmyk_ConditionalVtableCall_802F3BD8.cpp ----
extern "C" u8 fn_80388EEC(void* handle);

// fn_802F3BD8 - DMYK: conditional virtual-call wrapper. If
// fn_80388EEC(this->0x238) is truthy, calls own virtual slot 9 (byte
// offset 0x24). See [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this calls through a real `virtual` member rather than a
// manual cast.
struct ActorSlot9 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void slot9();
};

extern "C" void fn_802F3BD8(void* this_) {
    void* handle = *(void**)((char*)this_ + 0x238);
    if ((u8)fn_80388EEC(handle) != 0) {
        ((ActorSlot9*)this_)->slot9();
    }
}

// ---- fn_802F3C24.cpp ----
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);

extern "C" void fn_802F3C24(void* this_) {
    char* p = (char*)this_;
    s32 id = *(s32*)(p + 0x23c);
    if (id >= 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            *(u8*)((char*)found + 0x11c) = 0;
        }
        *(s32*)(p + 0x23c) = -1;
    }
    *(u8*)(p + 0x11c) = 0;
}

// fn_802F3C8C - DMYK: setParams(). Unpacks the spawn params; when the two
// nibbles match, spawns a "PEFF" effect actor and registers it with
// fn_8038BD08 together with a copy of the actor position.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8038BD08(s32 a, s32 b, u32 owner, JGeometry::TVec3<f32>* pos, s32 kind);

extern "C" void fn_802F3C8C(void* this_) {
    char* p = (char*)this_;
    *(u32*)(p + 0x230) = *(u32*)(p + 0x90) & 0xFFF;
    *(u32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 12) & 0xF;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 16) & 0xF;
    *(s32*)(p + 0x23c) = -1;
    s32 a = *(s32*)(p + 0x234);
    if (a == *(s32*)(p + 0x238)) {
        *(s32*)(p + 0x23c) = Actor_CreateByID(fn_801F856C(), 0x50454646, *(u32*)(p + 0x4), p + 0xc,
                                         (a & 3) | 0x24, -1, -1);
        u32 owner = *(u32*)(p + 0x4);
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
        fn_8038BD08(*(s32*)(p + 0x238), *(s32*)(p + 0x230), owner, &pos, 0x21);
    } else {
        *(u8*)(p + 0x11c) = 0;
    }
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JAudio/JASFakeMatchFSA.h"
