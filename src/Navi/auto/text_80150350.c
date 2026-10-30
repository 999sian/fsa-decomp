#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80150350-0x80150388 (1 functions). split_file divides it into the game's real files.

extern void* lbl_802FF4B0;
void* memset(void* dst, int c, u32 n);
void DCFlushRangeNoSync(void* addr, u32 nBytes);
void fn_80150350(void) {
    memset(lbl_802FF4B0, 0, 0x100);
    DCFlushRangeNoSync(lbl_802FF4B0, 0x100);
}
