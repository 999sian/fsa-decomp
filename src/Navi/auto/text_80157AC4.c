#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157ac4-0x80157b00 (1 functions). split_file divides it into the game's real files.

extern "C" unsigned char lbl_802FF4E8;
extern "C" char* lbl_802FF4BC;
extern "C" void fn_801533BC(void* p);
extern "C" void fn_80157AC4(int i) {
    char* p = lbl_802FF4BC + i * 0xf4;
    *(u8*)(p + 0xd4) = lbl_802FF4E8;
    fn_801533BC(p);
}
