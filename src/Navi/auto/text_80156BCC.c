#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80156bcc-0x80156c14 (1 functions). split_file divides it into the game's real files.

u16 fn_801564BC(u8 *param_1, u8 *param_2, u8 param_3, u8 param_4);
u16 fn_80156BCC(u8 *param_1)
{
    u32 flags = *(u32 *)(param_1 + 0x214);

    if ((flags & 0x400) == 0) {
        return *(u16 *)(param_1 + 0x3a0);
    }
    *(u32 *)(param_1 + 0x214) = flags & ~0x400;
    return fn_801564BC(param_1, param_1 + 0x380, param_1[0x121], param_1[0x122]);
}
