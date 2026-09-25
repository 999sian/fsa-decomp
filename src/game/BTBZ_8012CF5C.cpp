// BTBZ_8012CF5C: .text 0x8012CF5C-0x8012DAC0 (actor BTBZ)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/Btbz_ctor_8012D848.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E7F0[];

extern "C" void* fn_8012D848(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E7F0;
    *(u8*)((char*)this_ + 0x230) = 0;
    *(u8*)((char*)this_ + 0x231) = 0;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
