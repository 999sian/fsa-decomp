// TU 0x802e9428-0x802eb21c (actor ENDM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Endm_dtor_802E9428.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA0FC[];

extern "C" void* fn_802E9428(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA0FC;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Endm_EmptyHook.cpp ----
// Endm_EmptyHook - ENDM: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Endm_EmptyHook(void) {}

}

// fn_802E948C - ENDM: start a move towards target over n frames; returns 0
// (int->float constant 0x805412F0 is compiler-generated: the TU must own its
// .sdata2 before it can link.)
// when already there.
extern "C" u8 fn_802E948C(char* p, f32 target, s32 frames) {
    f32 cur = *(f32*)(p + 0x270);
    if (cur == target) {
        return 0;
    }
    f32 step = __fabsf(cur - target) / (f32)frames;
    if (cur < target) {
        *(f32*)(p + 0x278) = step;
    } else {
        *(f32*)(p + 0x278) = -step;
    }
    *(f32*)(p + 0x274) = target;
    return 1;
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
