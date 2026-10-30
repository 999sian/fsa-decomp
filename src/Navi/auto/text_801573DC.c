#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801573dc-0x80157424 (1 functions). split_file divides it into the game's real files.

u32 fn_80143FE0(u32 param_1);
void fn_801573DC(u32 *param_1, u32 param_2)
{
    u32 uVar1;
    uVar1 = fn_80143FE0(param_2);
    *param_1 = (*param_1 << 16) / uVar1 * 1000 >> 5;
}
