#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801ef590-0x801ef724 (4 functions). split_file divides it into the game's real files.

extern "C" u8 lbl_802FA9B0[];
extern "C" int GetTRKConnected(void);
extern "C" u8 TRKAccessFile(u32 cmd, u32 handle, u32* length, u8* buf);
extern "C" u8 fn_801EF590(void) {
    return lbl_802FA9B0[0];
}

extern "C" void fn_801EF5A0(u8 v) {
    lbl_802FA9B0[0] = v;
}

extern "C" u8 fn_801EF590(void);
#pragma dont_inline on
extern "C" int fn_801EF5AC(u32 handle, u8* buf, u32* count) {
    u32 len;
    u8 r;
    if (!fn_801EF590()) {
        return 1;
    }
    if (GetTRKConnected() == 0) {
        return 1;
    }
    len = *count;
    r = TRKAccessFile(0xd0, 1, &len, buf);
    *count = len;
    switch (r) {
    case 0:
        return 0;
    case 2:
        return 2;
    case 1:
    default:
        return 1;
    }
}

extern "C" int fn_801EF668(u32 handle, u8* buf, u32* count) {
    u32 len;
    u8 r;
    if (!fn_801EF590()) {
        return 1;
    }
    if (GetTRKConnected() == 0) {
        return 1;
    }
    len = *count;
    r = TRKAccessFile(0xd1, 0, &len, buf);
    *count = len;
    switch (r) {
    case 0:
        return 0;
    case 2:
        return 2;
    case 1:
    default:
        return 1;
    }
}
#pragma dont_inline reset
