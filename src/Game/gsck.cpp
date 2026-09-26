// TU 0x802f4aec-0x802f5040 (actor GSCK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gsck_dtor_802F4AEC.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA800[];

extern "C" void* fn_802F4AEC(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA800;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Gsck_EmptyHook.cpp ----
// Gsck_EmptyHook - GSCK: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Gsck_EmptyHook(void) {}

}

// ---- VtableForward_802F4DE8.cpp ----
// fn_802F4DE8 - GSCK: setParams. Zeroes this->0x230, then calls own
// virtual slot 5 (byte offset 0x14, draw/notify passthrough). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802F4DE8(void* this_) {
    *(u32*)((char*)this_ + 0x230) = 0;
    ((ActorSlot5*)this_)->slot5();
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
