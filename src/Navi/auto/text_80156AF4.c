#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80156af4-0x80156b3c (1 functions). split_file divides it into the game's real files.

u16 fn_801564BC(u8 *, u8 *, u8, u8);
u16 fn_80156AF4(u8 *param_1)
{
    if ((*(u32 *)(param_1 + 0x214) & 0x40) == 0) {
        return *(u16 *)(param_1 + 0x310);
    }
    *(u32 *)(param_1 + 0x214) &= ~0x40;
    return fn_801564BC(param_1, param_1 + 0x2f0, param_1[0x121], param_1[0x122]);
}
