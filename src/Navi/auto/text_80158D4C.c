#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158d4c-0x80158d84 (1 functions). split_file divides it into the game's real files.

extern "C" u16 lbl_802FF534;
extern "C" u32 lbl_802FF538;
extern "C" u32 OSDisableInterrupts(void);
extern "C" void fn_80158D4C(void)
{
    u16 count = lbl_802FF534;

    lbl_802FF534 = count + 1;
    if (count == 0) {
        lbl_802FF538 = OSDisableInterrupts();
    }
}
