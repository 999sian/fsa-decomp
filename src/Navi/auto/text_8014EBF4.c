#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014ebf4-0x8014ef34 (5 functions). split_file divides it into the game's real files.

extern "C" u8 lbl_802E2480[1600];
extern "C" u8 lbl_802E2400[128];
extern "C" BOOL fn_8014EBF4(u8* p) {
    u32 v = *(u32*)(p + 0xf4);
    u32 a;
    u32 b;
    u8 lo;
    u8* q;

    if (v != 0xffffffff) {
        a = p[0x121];
        if (a != 0xff) {
            b = p[0x122];
            lo = (u8)v;
            if (b == 0xff) {
                q = lbl_802E2480 + lo;
                if (*q == lo) {
                    return TRUE;
                }
            } else {
                q = lbl_802E2400 + (b << 4);
                q = q + a;
                if (lo == *q) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

extern "C" void fn_8014EC70(u8* p) {
    u32 v = *(u32*)(p + 0xf4);
    u32 a;
    u32 b;
    u8 lo;
    u8* q;

    if (v == 0xffffffff) {
        return;
    }
    a = p[0x121];
    if (a == 0xff) {
        return;
    }
    b = p[0x122];
    lo = (u8)v;
    if (b == 0xff) {
        q = (u8*)((u32)lbl_802E2480 + lo);
        *q = lo;
        return;
    }
    q = lbl_802E2400 + (b << 4);
    *(q + a) = lo;
}

