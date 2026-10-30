#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014d134-0x8014d1d8 (1 functions). split_file divides it into the game's real files.

extern u8* lbl_802FF450;
extern "C" void fn_8014D134(u8* param_1) {
    u8* cur;
    u8* prev;
    u8* tmp;

    cur = lbl_802FF450;
    prev = 0;
    while (cur != 0 && *(u64*)(cur + 0x98) < *(u64*)(param_1 + 0x98)) {
        prev = cur;
        cur = *(u8**)(cur + 0x44);
    }
    if (cur == 0) {
        if (prev == 0) {
            lbl_802FF450 = param_1;
            *(u8**)(param_1 + 0x44) = 0;
            *(u8**)(param_1 + 0x48) = 0;
        } else {
            *(u8**)(prev + 0x44) = param_1;
            *(u8**)(param_1 + 0x48) = prev;
            *(u8**)(param_1 + 0x44) = 0;
        }
    } else {
        *(u8**)(param_1 + 0x44) = cur;
        tmp = *(u8**)(cur + 0x48);
        *(u8**)(param_1 + 0x48) = tmp;
        if (tmp != 0) {
            *(u8**)(*(u8**)(cur + 0x48) + 0x44) = param_1;
        } else {
            lbl_802FF450 = param_1;
        }
        *(u8**)(cur + 0x48) = param_1;
    }
}
