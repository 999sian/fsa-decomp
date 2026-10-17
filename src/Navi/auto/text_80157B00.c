#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157b00-0x80157c54 (5 functions). split_file divides it into the game's real files.

extern u8* lbl_802FF4BC;
extern u8 lbl_802FF4E8;
extern "C" void fn_80157B00(int idx)
{
    u8* p = lbl_802FF4BC + idx * 0xf4;
    p += lbl_802FF4E8 * 4;
    *(u32*)(p + 0x24) |= 0x40;
}
