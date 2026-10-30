#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014ac44-0x8014ace4 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_801573CC(u32* p);
extern "C" void fn_8014AC44(u8* obj, u32* data, u8 idx) {
    u32 len;
    s32 v;
    len = data[0] >> 16;
    *(u32*)(obj + idx * 4 + 0x188) = len;
    fn_801573CC((u32*)(obj + idx * 4 + 0x188));
    *(u32*)(obj + idx * 4 + 0x170) = (data[0] & 0xff00) << 8;
    v = (s8)data[1] << 16;
    *(s32*)(obj + idx * 4 + 0x180) = *(s32*)(obj + idx * 4 + 0x170) + v;
    if (*(u32*)(obj + idx * 4 + 0x188) != 0) {
        *(s32*)(obj + idx * 4 + 0x178) = v / (s32)len;
    } else {
        *(s32*)(obj + idx * 4 + 0x178) = v;
    }
    *(u32*)(obj + 0x114) |= 0x2000;
}
