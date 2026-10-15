#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8000d404-0x80012630 (157 functions). split_file divides it into the game's real files.

extern "C" void fn_8000EAE0(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}
