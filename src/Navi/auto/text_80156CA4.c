// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80156ca4-0x80156d60 (1 functions). split_file divides it into the game's real files.
#include "types.h"

extern u32 lbl_802EB5D0[];
extern u32 lbl_80294EB0[];
extern u8 lbl_802D5824[];
extern "C" u32 fn_801564BC(u32 unk, void* p);
extern "C" u32 fn_80156CA4(u8 p1, u8 p2, u8 p3, u8 p4)
{
    u32 mask = lbl_80294EB0[p2];
    u32* flags = &lbl_802EB5D0[p4 * 16 + p3];
    u32 set = (mask & *flags) != 0;

    if (set) {
        *flags &= ~mask;
    }
    if (!set) {
        return *(u16*)&lbl_802D5824[p1 * 0x90 + p2 * 0x24 + 0x20];
    }
    return fn_801564BC(0, &lbl_802D5824[p1 * 0x90 + p2 * 0x24]);
}
