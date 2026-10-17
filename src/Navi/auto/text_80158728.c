#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158728-0x80158934 (4 functions). split_file divides it into the game's real files.

extern "C" u8 lbl_802EB890[];
extern "C" u32 lbl_802FF4F8;
extern "C" u32 lbl_802FF500;
extern "C" u32 lbl_802FF508;
extern "C" u32 lbl_802FF50C;
extern "C" u32 lbl_802FF510;

extern "C" void fn_801587EC(void)
{
}

extern "C" u8 lbl_802EBD98[];
extern "C" u32 fn_801588FC(u32 param_1, u32* param_2) {
    if (param_2 != NULL) {
        *param_2 = *(u32*)(lbl_802EBD98 + 0x8 + (param_1 & 0xff) * 0x10);
    }
    return *(u32*)(lbl_802EBD98 + 0x4 + (param_1 & 0xff) * 0x10);
}

