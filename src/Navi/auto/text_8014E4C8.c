// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
#include "types.h"

// .text 0x8014e4c8-0x8014e5ac (1 functions). split_file divides it into the game's real files.

extern u8 lbl_802E2AC0[];
extern u8 lbl_802FF476;
extern u8 lbl_802FF477;
extern u8 lbl_802FF478;
extern u8 lbl_802FF479;
void fn_8014D3BC(void* p, s32 x);
void fn_8014DE10(void* p);

void fn_8014E4C8(u8* p)
{
    u8 idx;
    u8* e;

    fn_8014D3BC(p, 2);
    fn_8014DE10(p);
    *(u32*)(p + 0x34) = 0;
    p[0x10c] = 0;
    idx = *(u32*)(p + 0xf4);
    e = lbl_802E2AC0 + idx * 4;
    if (*(u16*)(e + 2) == 0) {
        *(u16*)(e + 2) = 1;
        if (lbl_802FF479 == 0xff) {
            e[1] = 0xff;
            e[0] = 0xff;
            lbl_802FF479 = idx;
            lbl_802FF478 = idx;
        } else {
            e[1] = 0xff;
            e[0] = lbl_802FF478;
            lbl_802E2AC0[lbl_802FF478 * 4 + 1] = idx;
        }
        if (p[0x11d] == 0) {
            lbl_802FF476--;
        } else {
            lbl_802FF477--;
        }
    }
    *(u32*)(p + 0xf4) = -1;
}
