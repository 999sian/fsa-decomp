#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157a54-0x80157ac4 (5 functions). split_file divides it into the game's real files.

extern "C" u8* lbl_802FF4BC;
extern "C" void fn_80157A54(int idx, u32 a, u32 b)
{
    *(u32*)(lbl_802FF4BC + idx * 0xf4 + 0x94) = a;
    *(u32*)(lbl_802FF4BC + idx * 0xf4 + 0x98) = b;
}

extern "C" u8 fn_80157A74(int idx)
{
    return *(lbl_802FF4BC + idx * 0xf4 + 0x9c);
}

extern "C" u8 fn_80157A88(int idx)
{
    return *(lbl_802FF4BC + idx * 0xf4 + 0x90);
}

extern "C" u16 fn_80157A9C(int idx)
{
    return *(u16*)(lbl_802FF4BC + idx * 0xf4 + 0x70);
}

extern "C" void fn_80157AB0(int idx, u8 v)
{
    *(lbl_802FF4BC + idx * 0xf4 + 0xa0) = v;
}

