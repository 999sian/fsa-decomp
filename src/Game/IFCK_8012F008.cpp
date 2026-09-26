// IFCK_8012F008: .text 0x8012F008-0x8012F3E4 (actor IFCK)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/Ifck_ctor_8012F178.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E950[];

extern "C" void* fn_8012F178(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E950;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s16*)((char*)this_ + 0x234) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
