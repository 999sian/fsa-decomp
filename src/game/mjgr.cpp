// TU 0x802e7db4-0x802e8dfc (actor MJGR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- EmptyHook_802E7DB4.cpp ----
// EmptyHook_802E7DB4 - actor @lbl_804A9FB0: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void EmptyHook_802E7DB4(void) {}

}

// ---- fn_802E8A64_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9FB0[];

extern "C" void* fn_802E8A64(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A9FB0;
        if (*(void**)(p + 0x230) != 0) {
            fn_801EE434(*(void**)(p + 0x230));
        }
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        if (*(void**)(p + 0x238) != 0) {
            fn_801EE434(*(void**)(p + 0x238));
        }
        if (*(void**)(p + 0x23c) != 0) {
            fn_801EE434(*(void**)(p + 0x23c));
        }
        if (*(void**)(p + 0x240) != 0) {
            fn_801EE434(*(void**)(p + 0x240));
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
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
