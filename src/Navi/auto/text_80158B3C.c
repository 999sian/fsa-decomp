#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158b3c-0x80158b68 (1 functions). split_file divides it into the game's real files.

extern u8 lbl_802FF53C;
extern u32 lbl_802FF51C;
extern "C" int fn_80158B3C(void)
{
    int x = lbl_802FF53C;
    int q;
    u8 m;
    x += 2;
    q = x / 4;
    m = x - q * 4;
    return lbl_802FF51C + m * 0x280;
}
