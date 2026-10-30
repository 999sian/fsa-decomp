#include "Dolphin/os.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158c9c-0x80158ce8 (1 functions). split_file divides it into the game's real files.

extern u32 lbl_802FF52C;
u32 fn_80158C9C(void)
{
	return OSGetTick() - lbl_802FF52C;
}
