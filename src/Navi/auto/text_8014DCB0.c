#include "types.h"

extern u32* lbl_802FF46C;

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014dcb0-0x8014def0 (4 functions). split_file divides it into the game's real files.

extern "C" u32 fn_8014DCB0(u8* param_1)
{
    *(u32*)(param_1 + 0xfc) = *(u32*)(param_1 + 0xf8);
    return *(u32*)(*(u32*)(param_1 + 0xf8) + 8);
}
