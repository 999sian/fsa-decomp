#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80141ea4-0x80142140 (3 functions). split_file divides it into the game's real files.

extern void* lbl_802FF3AC;
extern void* lbl_802FF3A8;
extern u8 lbl_802C6E80[];
extern "C" void fn_8014208C(u32 param_1, u32 param_2, u32 param_3)
{
    u8* base = lbl_802C6E80;
    int* p;
    u32 key = param_1 & 0x7fffffff;
    u32 idx;

    for (p = (int*)lbl_802FF3AC; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == key) {
            idx = (param_1 & 0x80000000) | *((u8*)p + 9);
            goto found;
        }
    }
    for (p = (int*)lbl_802FF3A8; p != 0; p = (int*)p[0]) {
        if ((u32)p[3] == key) {
            idx = (param_1 & 0x80000000) | *((u8*)p + 9);
            goto found;
        }
    }
    idx = -1;
found:
    if (idx == 0xffffffff) {
        return;
    }
    if (!(idx & 0x80000000)) {
        *(u32*)(base + idx * 0x1868 + 0x151c) = param_2;
        *(u32*)(base + idx * 0x1868 + 0x1520) = param_3;
        return;
    }
    idx &= 0x7fffffff;
    *(u8*)(base + idx * 0x1868 + 0x22da) |= 0x10;
    *(u32*)(base + idx * 0x1868 + 0x22d0) = param_2;
    *(u32*)(base + idx * 0x1868 + 0x22d4) = param_3;
}
