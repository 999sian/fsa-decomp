#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157854-0x801578a4 (1 functions). split_file divides it into the game's real files.

extern u8* lbl_802FF4BC;
extern u8 lbl_802FF4E8;
struct Unk157854 {
    u8 pad0[0x24];
    u32 flags[(0xec - 0x24) / 4];
    u8 unkEC;
    u8 unkED;
    u8 unkEE;
    u8 padEF[0xf4 - 0xef];
};

extern "C" void fn_80157854(int i)
{
    Unk157854* p = &((Unk157854*)lbl_802FF4BC)[i];
    if (p->unkEC == 1 && lbl_802FF4E8 == 0) {
        p->unkEE = 1;
    }
    p = &((Unk157854*)lbl_802FF4BC)[i];
    p = (Unk157854*)((u8*)p + lbl_802FF4E8 * 4);
    p->flags[0] |= 0x20;
}
