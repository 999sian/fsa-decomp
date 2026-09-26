// tu_8011A0F8: .text 0x8011A0F8-0x8011A4BC
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8011A248_ctor.cpp

extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049DAD8[];

extern "C" void* fn_8011A248(void* this_) {
    Actor_ctor(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_8049DAD8;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(u8*)(p + 0x238) = 0;
    *(u8*)(p + 0x239) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
