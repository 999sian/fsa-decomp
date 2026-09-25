// RNBW_80129B0C: .text 0x80129B0C-0x8012A5EC (actor RNBW)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/Rnbw_ctor_8012A364.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E610[];

extern "C" void* fn_8012A364(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E610;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = -1;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(s32*)((char*)this_ + 0x240) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x248) = 0;
    *(s32*)((char*)this_ + 0x24c) = 0;
    return this_;
}
