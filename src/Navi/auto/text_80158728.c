#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158728-0x80158934 (4 functions). split_file divides it into the game's real files.

extern "C" u8 lbl_802EB890[];
extern "C" u32 lbl_802FF4F8;
extern "C" u32 lbl_802FF500;
extern "C" u32 lbl_802FF508;
extern "C" u32 lbl_802FF50C;
extern "C" u32 lbl_802FF510;

extern "C" void fn_80158728(void) {
    u8* base = lbl_802EB890;
    u32* p;
    u32 n;
    u32 i;

    lbl_802FF508 = 0;
    lbl_802FF50C = 0;
    lbl_802FF510 = (u32)(base + 0x508);
    p = (u32*)(base + 0x518);
    n = 1;
    i = 7;
    do {
        p[-4] = (u32)p;
        p[0] = (u32)(p + 4);
        p[4] = (u32)(p + 8);
        p[8] = (u32)(p + 12);
        p[12] = (u32)(p + 16);
        p[16] = (u32)(p + 20);
        p[20] = (u32)(p + 24);
        p[24] = (u32)(p + 28);
        p += 32;
        n += 8;
    } while (--i != 0);
    if (n < 0x40) {
        i = 0x40 - n;
        p = (u32*)(base + (n << 4) + 0x508);
        do {
            p[-4] = (u32)p;
            p += 4;
            n++;
        } while (--i != 0);
    }
    *(u32*)(base + (n << 4) + 0x4f8) = 0;
    lbl_802FF500 = lbl_802FF4F8;
}

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

