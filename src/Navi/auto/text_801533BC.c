// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801533bc-0x80153460 (1 functions). split_file divides it into the game's real files.
#include "types.h"

extern "C" char lbl_802E3B10[];
extern "C" void fn_80153460(int param_1);

extern "C" void fn_801533BC(int param_1, u8 param_2)
{
    int *slot;

    if (*(u8 *)(param_1 + 0xec) != 0) {
        fn_80153460(param_1);
        *(u32 *)(param_1 + 0x24) |= 0x20;
    }
    *(u8 *)(param_1 + 0xed) = 0;
    slot = (int *)(lbl_802E3B10 + (u8)param_2 * 0xbc + 0x48);
    *(int *)(param_1 + 0xc) = *slot;
    if (*slot != 0) {
        *(int *)(*(int *)(param_1 + 0xc) + 0x10) = param_1;
    }
    *(int *)(param_1 + 0x10) = 0;
    *slot = param_1;
    *(u8 *)(param_1 + 0xee) = 0;
    *(u8 *)(param_1 + 0xec) = 1;
    *(u8 *)(param_1 + 0xef) = param_2;
}
