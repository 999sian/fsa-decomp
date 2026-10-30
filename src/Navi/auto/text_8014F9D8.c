#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014f9d8-0x8014fa84 (1 functions). split_file divides it into the game's real files.

extern u8 lbl_802E2BC0[];
void fn_8014F9D8(u32 param_1)
{
    u8 idx;
    s32 off;
    void (*cb)(s32, void*);

    if (param_1 != 0xffffffff) {
        idx = lbl_802E2BC0[0x908 + (param_1 & 0xff)];
        if (idx != 0xff) {
            off = idx * 0x24;
            if (*(u16*)(lbl_802E2BC0 + off + 0x1a) == ((param_1 >> 8) & 0xffff)) {
                cb = *(void (**)(s32, void*))(lbl_802E2BC0 + 0x94c);
                if (cb != NULL) {
                    cb(2, lbl_802E2BC0 + off + 0x18);
                }
                lbl_802E2BC0[off + 8] = 0;
                lbl_802E2BC0[0x908 + lbl_802E2BC0[off + 0xb]] = 0xff;
            }
        }
    }
}
