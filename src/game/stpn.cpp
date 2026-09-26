// TU 0x802ed140-0x802ed538 (actor STPN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- STPN (stop/pause items) ----
// Walks the actor list of the spatial registry and releases every "ITMS"
// actor, then clears the pause state (fn_80134FBC / fn_80458658).
struct StpnActorList {
    u8 pad0[8];
    void* actors[(0x1008 - 8) / 4];
    s32 count; // 0x1008
};
extern "C" StpnActorList* fn_801F856C();
extern "C" void fn_802AC09C(void* actor);
extern "C" void fn_80134FBC(void* obj, s32 on);
extern "C" void fn_80458658(void* obj, s32 on);
extern "C" void dtor_801F593C(void* this_, int how);
extern void* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern void* lbl_804AA2D8[];

static inline void stpnRelease() {
    s32 n = fn_801F856C()->count;
    for (s32 i = 0; i < n; i++) {
        void* a = fn_801F856C()->actors[i];
        if (a != 0 && *(u32*)((char*)a + 0x1a0) == 0x49544d53) {
            fn_802AC09C(a);
        }
    }
    fn_80134FBC(lbl_8053AAF8, 0);
    fn_80458658(lbl_8053AF80, 0);
}

// NONMATCHING (99.3%): retail puts n in r31 and the byte offset in r30.
extern "C" void fn_802ED140(void* this_) {
    s32 n = fn_801F856C()->count;
    for (s32 i = 0; i < n; i++) {
        void* a = fn_801F856C()->actors[i];
        if (a != 0 && *(u32*)((char*)a + 0x1a0) == 0x49544d53) {
            fn_802AC09C(a);
        }
    }
    fn_80134FBC(lbl_8053AAF8, 0);
    fn_80458658(lbl_8053AF80, 0);
    *(u8*)((char*)this_ + 0x11c) = 0;
}

// ---- Stpn_EmptyHook1.cpp ----
// Stpn_EmptyHook1 / Stpn_EmptyHook2 - STPN: 2 empty no-op overrides (0x4 each, leaf, no extab needed)
extern "C" {

void Stpn_EmptyHook1(void) {}

void Stpn_EmptyHook2(void) {}

}

extern "C" void* fn_802ED1F4(void* this_, s16 how) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AA2D8;
        stpnRelease();
        *(u8*)((char*)this_ + 0x11c) = 0;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802ED2BC(void* this_) {
    if (*((u8*)lbl_8053AAF8 + 0x7e) == 0) {
        *(s32*)((char*)this_ + 0x230) = 100;
        fn_80134FBC(lbl_8053AAF8, 1);
        fn_80458658(lbl_8053AF80, 1);
    } else {
        *(u8*)((char*)this_ + 0x11c) = 0;
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
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
