// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801589e8-0x80158a50 (1 functions). split_file divides it into the game's real files.
#include "types.h"

extern u32 lbl_802FF520;
extern u32 lbl_802FF524;
extern u32 lbl_802FF528;
extern void (*lbl_802FF518)(void);
extern "C" BOOL OSEnableInterrupts(void);
extern "C" BOOL OSDisableInterrupts(void);
extern "C" void fn_801589E8(void) {
    lbl_802FF520 = 1;
    if (lbl_802FF524 != 0) {
        lbl_802FF524 = 0;
        if (lbl_802FF528 == 0) {
            lbl_802FF528 = 1;
            OSEnableInterrupts();
            lbl_802FF518();
            OSDisableInterrupts();
            lbl_802FF528 = 0;
        }
    }
}
