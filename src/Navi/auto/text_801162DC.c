#include "dolphin/os/OSFastCast.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801162dc-0x801162f4 (1 functions). split_file divides it into the game's real files.

extern f32 lbl_802FEAB8[];
extern f32 lbl_80301468;
extern f32 lbl_802FF238;
extern "C" void fn_801162DC(void) {
    lbl_802FF238 = lbl_80301468 * lbl_802FEAB8[0];
}
