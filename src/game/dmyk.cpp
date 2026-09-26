// TU 0x802f3b74-0x802f3f7c (actor DMYK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Dmyk_dtor_802F3B74.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA6A0[];

extern "C" void* fn_802F3B74(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA6A0;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
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
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);

extern "C" void fn_802F3C24(void* this_) {
    char* p = (char*)this_;
    s32 id = *(s32*)(p + 0x23c);
    if (id >= 0) {
        void* base = SpatialRegistry_GetBase();
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
struct DmykVec { f32 x, y, z; };
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F9484(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8038BD08(s32 a, s32 b, u32 owner, DmykVec* pos, s32 kind);

extern "C" void fn_802F3C8C(void* this_) {
    char* p = (char*)this_;
    *(u32*)(p + 0x230) = *(u32*)(p + 0x90) & 0xFFF;
    *(u32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 12) & 0xF;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 16) & 0xF;
    *(s32*)(p + 0x23c) = -1;
    s32 a = *(s32*)(p + 0x234);
    if (a == *(s32*)(p + 0x238)) {
        *(s32*)(p + 0x23c) = fn_801F9484(fn_801F856C(), 0x50454646, *(u32*)(p + 0x4), p + 0xc,
                                         (a & 3) | 0x24, -1, -1);
        // NONMATCHING: retail copies the position with psq_l/psq_st + lfs/stfs
        // (JGeometry::TVec3<f32> inline-asm copy); plain struct copy uses GPRs.
        DmykVec pos = *(DmykVec*)(p + 0xc);
        fn_8038BD08(*(s32*)(p + 0x238), *(s32*)(p + 0x230), *(u32*)(p + 0x4), &pos, 0x21);
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
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
