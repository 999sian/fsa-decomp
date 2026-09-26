// TU 0x802eb21c-0x802ec1d4 (actor TKRA).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Tkra_dtor_802EB21C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA178[];

extern "C" void* fn_802EB21C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA178;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// fn_802EB27C - TKRA: releases every linked actor that is in state 3;
// returns whether any was found.
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 fn_801597B8(void* a);
extern "C" void fn_801597C0(void* a);
struct TkraObj {
    u8 pad[0x24c];
    s32 ids[4];
};
extern "C" u8 fn_802EB27C(TkraObj* p) {
    u8 found = 0;
    for (s32 i = 0; i < 4; i++) {
        s32 v = p->ids[i];
        if (v >= 0) {
            void* a = fn_801F666C(fn_801F856C(), v);
            v = (s32)a;
            if (v != 0 && fn_801597B8((void*)v) == 3) {
                fn_801597C0((void*)v);
                found = 1;
            }
        }
    }
    return found;
}

// ---- Tkra_EmptyHook.cpp ----
// Tkra_EmptyHook - TKRA: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Tkra_EmptyHook(void) {}

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
