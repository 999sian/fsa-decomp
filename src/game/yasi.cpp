// TU 0x802df458-0x802dfce8 (actor YASI).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802DF458_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9968[];

extern "C" void* fn_802DF458(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9968;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- VtableForward_802DF4B8.cpp ----
// YASI cluster, part 2/7. Virtual-call wrapper: invokes this object's
// own vtable slot 9 (byte offset 0x24) with no extra arguments.
// See [[reference_fsa_virtual_dispatch_codegen_trick]] for why this
// calls through a real `virtual` member rather than a manual cast.
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

extern "C" void fn_802DF4B8(void* this_) {
    ((ActorSlot9*)this_)->slot9();
}

// ---- Yasi_CanBeActiveHere_802DF4E4.cpp ----
// YASI cluster, part 3/7. A thin wrapper around the shared
// "can this actor be active here" gate fn_801F132C (see extab_801f132c.s),
// passing this actor's own +0x230 state block as the gate's per-instance
// scratch pointer.
extern "C" s32 fn_801F132C(void* this_, u32 param2, u32 param3, void* statePtr);

extern "C" s32 Yasi_CanBeActiveHere(void* this_, u32 param2, u32 param3) {
    return fn_801F132C(this_, param2, param3, (u32*)((char*)this_ + 0x230));
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
