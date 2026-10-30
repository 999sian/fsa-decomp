#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158934-0x801589d8 (1 functions). split_file divides it into the game's real files.

extern u8 lbl_802FF53C;
extern u32 lbl_802FF51C;
extern u32 lbl_802FF520;
extern u32 lbl_802FF524;
extern u32 lbl_802FF528;
extern u32 lbl_802FF52C;
extern void (*lbl_802FF518)(void);
extern "C" void fn_801CEC14(u32 start, u32 length);
extern "C" void OSEnableInterrupts(void);
extern "C" void OSDisableInterrupts(void);
extern "C" u32 OSGetTick(void);
extern "C" void fn_80158934(void)
{
    int x;
    int q;

    x = lbl_802FF53C;
    x += 1;
    q = x / 4;
    lbl_802FF53C = x - q * 4;
    fn_801CEC14(lbl_802FF51C + 0x80000000 + lbl_802FF53C * 0x280, 0x280);
    lbl_802FF52C = OSGetTick();
    if (lbl_802FF520 != 0) {
        if (lbl_802FF528 == 0) {
            lbl_802FF528 = 1;
            OSEnableInterrupts();
            lbl_802FF518();
            OSDisableInterrupts();
            lbl_802FF528 = 0;
        }
    } else {
        lbl_802FF524 = 1;
    }
}
