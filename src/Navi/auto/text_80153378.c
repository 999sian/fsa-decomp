#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80153378-0x801533bc (1 functions). split_file divides it into the game's real files.

extern "C" void* lbl_802FF4C0;
extern "C" s32 fn_80153378(u8* param_1, s32 param_2)
{
    if (lbl_802FF4C0 == NULL) {
        return 0;
    }
    return ((s32 (*)(s32, s32))lbl_802FF4C0)(param_2, *(s32*)(param_1 + 0x18));
}
