#include "dolphin/os/OSFastCast.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bb444-0x801bbf2c (15 functions). split_file divides it into the game's real files.

extern "C" void OSCreateAlarm(u32* p) {
    p[0] = 0;
    p[1] = 0;
}

extern u32 lbl_802FE960;
extern "C" u32 fn_801BBE40(u32 param_1) {
    u32 old = lbl_802FE960;
    lbl_802FE960 = param_1;
    return old;
}

