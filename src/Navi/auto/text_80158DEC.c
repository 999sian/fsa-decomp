#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158dec-0x80158e18 (1 functions). split_file divides it into the game's real files.

extern void (*lbl_802FF4EC[])(void);
extern "C" void fn_80158DEC(void)
{
    ((void (*)(void))((void **)lbl_802FF4EC)[1])();
}
