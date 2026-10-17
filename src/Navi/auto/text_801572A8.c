#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801572a8-0x80157334 (2 functions). split_file divides it into the game's real files.

extern volatile u32 lbl_802FE120;
extern "C" u16 fn_801572A8(void) {
    lbl_802FE120 = lbl_802FE120 * 0xA8351D63;
    return (lbl_802FE120 >> 6) & 0xFFFF;
}
