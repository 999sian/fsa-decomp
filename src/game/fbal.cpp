// TU 0x802201d8-0x802205e0 (actor FBAL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Fbal_ctor_80220378.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D30B8(void* this_);
extern void* lbl_804A6828[];

extern "C" void* fn_80220378(void* this_) {
    fn_801D30B8(this_);
    *(void**)this_ = lbl_804A6828;
    *(s32*)((char*)this_ + 0x2ac) = 0;
    return this_;
}
