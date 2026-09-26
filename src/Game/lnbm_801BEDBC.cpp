// Game TU 801BEDBC-801BF810 (LNBM). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A4188[];

extern "C" void* fn_801BF5A8(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4188;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
