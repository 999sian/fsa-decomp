#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80156b3c-0x80156b84 (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_801564BC(u8* a, u8 b, u8 c);
extern "C" u32 fn_80156B3C(u8* param_1)
{
    u32 uVar1;

    if ((*(u32*)(param_1 + 0x214) & 0x100) == 0) {
        uVar1 = *(u16*)(param_1 + 0x358);
    } else {
        *(u32*)(param_1 + 0x214) &= ~0x100;
        uVar1 = fn_801564BC(param_1 + 0x338, param_1[0x121], param_1[0x122]);
    }
    return uVar1;
}
