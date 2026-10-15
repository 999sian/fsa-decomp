#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801497b0-0x801497c0 (1 functions). split_file divides it into the game's real files.

extern "C" int fn_801497B0(int param_1, int param_2) {
    return *(u16*)(param_1 + 4) - *(u16*)(param_2 + 4);
}
