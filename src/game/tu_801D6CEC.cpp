// Game TU 801D6CEC-801D7AFC (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" {
extern f32 lbl_8053F150;
}
extern "C" void fn_8021BD18(void* subObj, s32 arg);

extern "C" void fn_801D76B4(void* thisPtr)
{
    char* t = (char*)thisPtr;
    *(s32*)(t + 0x0) = -1;
    f32 c = lbl_8053F150;
    *(s32*)(t + 0x4) = -1;
    *(s32*)(t + 0x8) = -1;
    *(s32*)(t + 0xc) = -1;
    *(s32*)(t + 0x10) = -1;
    *(s32*)(t + 0x14) = -1;
    *(s32*)(t + 0x18) = -1;
    *(s32*)(t + 0x1c) = -1;
    *(s32*)(t + 0x20) = -1;
    *(s32*)(t + 0x24) = -1;
    *(s32*)(t + 0x28) = -1;
    *(s32*)(t + 0x2c) = -1;
    *(s32*)(t + 0x30) = -1;
    *(s32*)(t + 0x34) = -1;
    *(s32*)(t + 0x38) = -1;
    *(s32*)(t + 0x3c) = -1;
    *(s32*)(t + 0x40) = 0;
    *(s32*)(t + 0x44) = 0;
    *(f32*)(t + 0x48) = c;
    *(f32*)(t + 0x4c) = c;
    *(f32*)(t + 0x50) = c;
    *(s16*)(t + 0x54) = 0;
    *(s16*)(t + 0x56) = 0;
    *(s8*)(t + 0x58) = 0;
    *(f32*)(t + 0x5c) = c;
    *(f32*)(t + 0x60) = c;
    *(s32*)(t + 0x64) = 0;
}

extern "C" void fn_801D789C(void* child) {
    *(u8*)((char*)child + 0x0) = 0;
    *(s32*)((char*)child + 0x4) = 0;
    *(s32*)((char*)child + 0x8) = 0;
    fn_8021BD18((char*)child + 0xc, 2);
}
