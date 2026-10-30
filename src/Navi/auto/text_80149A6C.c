#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80149a6c-0x80149aec (1 functions). split_file divides it into the game's real files.

extern "C" u32* fn_80157334(void*, void*, u16, int, int (*)(int, int));
extern "C" int fn_80149A5C(int, int);
extern u16 lbl_802FF406;
extern u32* lbl_802FF440;
extern char lbl_802D75A8[];
extern char lbl_802E1BC8[];
extern "C" u32 fn_80149A6C(u16 param_1, u16* param_2) {
    char* p = lbl_802D75A8 + 0x10000;
    *(u16*)(p - 0x59dc) = param_1;
    lbl_802FF440 = fn_80157334(p - 0x59e0, lbl_802D75A8 + 0x4e00, lbl_802FF406, 0xc, fn_80149A5C);
    if (lbl_802FF440 != 0) {
        *param_2 = *(u16*)((char*)lbl_802FF440 + 6);
        return *lbl_802FF440;
    }
    return 0;
}
