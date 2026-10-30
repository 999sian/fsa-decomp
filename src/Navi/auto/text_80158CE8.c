#include "types.h"
#include "dolphin/os.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158ce8-0x80158d14 (1 functions). split_file divides it into the game's real files.

extern "C" u32 lbl_802FF538;
extern "C" u16 lbl_802FF534;
extern "C" void fn_80158CE8(void) {
    lbl_802FF538 = OSDisableInterrupts();
    lbl_802FF534 = 1;
    return;
}
