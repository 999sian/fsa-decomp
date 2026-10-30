// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801432c0-0x80143368 (1 functions). split_file divides it into the game's real files.
#include "types.h"

extern void* lbl_802FF390;
extern "C" void* fn_801428B4(u8 param_1);
extern "C" void fn_80142ACC(void* param_1, void* param_2);

extern "C" void fn_801432C0(void)
{
    u32 i;
    void* p;

    if (*(int*)((int)lbl_802FF390 + 0x14e4) == 0) {
        for (i = 0; i < 0x40; i++) {
            p = fn_801428B4(i);
            if (p != 0) {
                fn_80142ACC((u8*)lbl_802FF390 + 0x14e8, p);
            }
        }
    } else {
        for (i = 0; i < 0x40; i++) {
            p = fn_801428B4(i);
            if (p != 0) {
                fn_80142ACC((u8*)lbl_802FF390 + 0x14e8 + ((u8*)*(int*)((int)lbl_802FF390 + 0x14e4))[i] * 0x38, p);
            }
        }
    }
}
