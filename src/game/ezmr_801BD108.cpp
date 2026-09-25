// Game TU 801BD108-801BD8C0 (EZMR). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3F90[];

extern "C" void* fn_801BD640(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3F90;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    *(u8*)((char*)this_ + 0x2ec) = 0;
    *(s32*)((char*)this_ + 0x2f0) = 0;
    *(s32*)((char*)this_ + 0x2f4) = 0;
    *(s16*)((char*)this_ + 0x2f8) = 0;
    *(s16*)((char*)this_ + 0x2fa) = 0;
    *(s16*)((char*)this_ + 0x2fc) = 0;
    return this_;
}
