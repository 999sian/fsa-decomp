// BARI_8011EEEC: .text 0x8011EEEC-0x8011FFB8 (actor BARI)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/Bari_ctor_8011FD28.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049DEE8[];

extern "C" void* fn_8011FD28(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049DEE8;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(u8*)((char*)this_ + 0x240) = 0;
    *(u8*)((char*)this_ + 0x241) = 0;
    *(s32*)((char*)this_ + 0x250) = 0;
    *(s32*)((char*)this_ + 0x254) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x248) = 0;
    *(s32*)((char*)this_ + 0x24c) = 0;
    return this_;
}
