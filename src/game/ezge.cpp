// TU 0x8021d26c-0x8021d734 (actor EZGE).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- Fbge_ctor_8021D4CC.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A6660[];

extern "C" void* fn_8021D4CC(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A6660;
    *(s16*)((char*)this_ + 0x2a8) = 120;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
