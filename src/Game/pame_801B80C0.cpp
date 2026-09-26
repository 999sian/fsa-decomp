// Game TU 801B80C0-801B9730 (PAME). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3B10[];

extern "C" void* fn_801B94C8(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3B10;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
