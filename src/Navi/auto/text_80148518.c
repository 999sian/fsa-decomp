#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80148518-0x8014854c (1 functions). split_file divides it into the game's real files.

extern u32 lbl_802FF3DC;
extern "C" u32 lbl_802FF3DC;
extern "C" void fn_80148518(u8 *param_1, u8 *param_2)
{
    if (lbl_802FF3DC & 1) {
        *param_1 = 0x40;
        *param_2 = 0;
    } else if (!(lbl_802FF3DC & 2)) {
        *param_2 = 0;
    }
}
