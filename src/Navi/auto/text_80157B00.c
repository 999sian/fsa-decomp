#include "dolphin/types.h"
#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157b00-0x80157c54 (5 functions). split_file divides it into the game's real files.

extern u8* lbl_802FF4BC;
extern u8 lbl_802FF4E8;
extern "C" void fn_80157B00(int idx)
{
    u8* p = lbl_802FF4BC + idx * 0xf4;
    p += lbl_802FF4E8 * 4;
    *(u32*)(p + 0x24) |= 0x40;
}

extern "C" void fn_80157B28(int i, u16 val)
{
    u8* p = lbl_802FF4BC + i * 0xf4;
    u8 cur;
    if (val >= 0x4000) {
        val = 0x3fff;
    }
    cur = p[0xe4];
    if (cur != 0xff && *(u32*)(p + cur * 4 + 0x38) == ((u32)val << 4)) {
        return;
    }
    *(u32*)(p + lbl_802FF4E8 * 4 + 0x38) = (u32)val << 4;
    *(u32*)(p + lbl_802FF4E8 * 4 + 0x24) |= 8;
    p[0xe4] = lbl_802FF4E8;
}

extern u16 lbl_802FE128[4];
extern u16 lbl_802FE130[4];
extern "C" void fn_80157BA0(int i, u8 idx)
{
    u8* p = lbl_802FF4BC + i * 0xf4;
    *(u16*)(p + 0xcc) = lbl_802FE128[idx];
    *(u32*)(p + 0x24) |= 0x100;
}

extern "C" void fn_80157BCC(int i, u8 idx)
{
    u8* p = lbl_802FF4BC + i * 0xf4;
    *(u16*)(p + 0xce) = lbl_802FE130[idx];
    *(u32*)(p + 0x24) |= 0x80;
}

extern "C" void fn_80157BF8(int i, u8 flag)
{
    int off = i * 0xf4;
    if (flag == 0) {
        *(u32*)(lbl_802FF4BC + off + 0xf0) |= 0x80000000;
        *(u16*)(lbl_802FF4BC + off + 0xd0) = 0x10;
        *(u16*)(lbl_802FF4BC + off + 0xd2) = 0x10;
    } else {
        *(u32*)(lbl_802FF4BC + off + 0xf0) &= 0x7fffffff;
    }
}

