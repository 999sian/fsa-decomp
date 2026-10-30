// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80147560-0x80147610 (1 functions). split_file divides it into the game's real files.
#include "dolphin/types.h"

extern u32 lbl_802D52F4[];
extern u32 lbl_802D5334[];
extern u8 lbl_802D5354[][2];
extern u8 lbl_802FF3CC[];
extern u8 lbl_802FF3BC[];
extern "C" void fn_80158D4C(void);
extern "C" void fn_80158D14(void);
extern "C" void fn_80157F78(u8, u32, u32);
extern "C" void fn_80147560(u8 ch, u32 a, u32 b) {
    fn_80158D4C();
    lbl_802D52F4[ch] = 0;
    lbl_802D5334[ch] = 0;
    lbl_802FF3CC[ch] = 0xff;
    lbl_802FF3BC[ch] = 0xff;
    lbl_802D5354[ch][1] = 0;
    lbl_802D5354[ch][0] = 0;
    fn_80157F78(ch, a, b);
    fn_80158D14();
}
