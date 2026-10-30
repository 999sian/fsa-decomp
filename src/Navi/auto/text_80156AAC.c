#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80156aac-0x80156af4 (1 functions). split_file divides it into the game's real files.

u16 fn_801564BC(int param_1, void *param_2, u8 param_3, u8 param_4);
u16 fn_801564BC(u8 *param_1, u8 *param_2, u8 param_3, u8 param_4);
u16 fn_80156AAC(u8 *param_1)
{
    if ((*(u32 *)(param_1 + 0x214) & 0x20) == 0) {
        return *(u16 *)(param_1 + 0x2ec);
    }
    *(u32 *)(param_1 + 0x214) &= ~0x20;
    return fn_801564BC(param_1, param_1 + 0x2cc, param_1[0x121], param_1[0x122]);
}
