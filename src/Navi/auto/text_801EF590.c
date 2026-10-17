#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801ef590-0x801ef724 (4 functions). split_file divides it into the game's real files.

extern "C" u8 lbl_802FA9B0[];
extern "C" int GetTRKConnected(void);
extern "C" u8 TRKAccessFile(u32 cmd, u32 handle, u32* length, u8* buf);
extern "C" void fn_801EF5A0(u8 v) {
    lbl_802FA9B0[0] = v;
}
