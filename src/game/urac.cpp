// TU 0x802e07c8-0x802e0ab4 (actor URAC).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802E07C8_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern void* lbl_804A9A70[];

extern "C" void* fn_802E07C8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9A70;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- stub_802e0828.cpp ----
// URAC cluster, part 2/4. fn_802E0828 - empty override (bare blr), no
// extab. Likely a "do nothing" draw() or similar no-op virtual.
extern "C" {

void fn_802E0828(void) {}

}

// ---- Urac_Part3of4_802E082C.cpp ----
// URAC cluster, part 3/4. Uses the per-room config family
// fn_802D6A9C/fn_802D77BC.



extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D77BC(void* record, u32 field4, u32 flag);

extern "C" void fn_802E082C(void* this_) {
    fn_802D77BC(fn_802D6A9C(), *(u32*)((char*)this_ + 0x4), 1);
}

// ---- VtableForward_802E0864.cpp ----
// URAC cluster, part 4/4. Virtual-call wrapper: invokes this object's
// own vtable slot 5 (byte offset 0x14) with no extra arguments.
// See [[reference_fsa_virtual_dispatch_codegen_trick]] for why this
// calls through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802E0864(void* this_) {
    ((ActorSlot5*)this_)->slot5();
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
