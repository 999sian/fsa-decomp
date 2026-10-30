#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158d14-0x80158d4c (1 functions). split_file divides it into the game's real files.

extern u16 lbl_802FF534;
extern u32 lbl_802FF538;
void OSRestoreInterrupts(u32 level);
void fn_80158D14(void) {
    lbl_802FF534--;
    if (lbl_802FF534 == 0) {
        OSRestoreInterrupts(lbl_802FF538);
    }
}
