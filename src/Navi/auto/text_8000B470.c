#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8000b470-0x8000b48c (1 functions). split_file divides it into the game's real files.

extern u32 lbl_802FEB68;
extern u32 lbl_802FEB6C;
extern "C" void fn_8000B470(void) {
    lbl_802FEB6C = *(u32*)0x800000F8 >> 2;
    lbl_802FEB68 = 0;
}
