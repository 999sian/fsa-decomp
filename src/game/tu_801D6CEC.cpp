// Game TU 801D6CEC-801D7AFC (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_8021BD18(void* subObj, s32 arg);

extern "C" void fn_801D789C(void* child) {
    *(u8*)((char*)child + 0x0) = 0;
    *(s32*)((char*)child + 0x4) = 0;
    *(s32*)((char*)child + 0x8) = 0;
    fn_8021BD18((char*)child + 0xc, 2);
}
