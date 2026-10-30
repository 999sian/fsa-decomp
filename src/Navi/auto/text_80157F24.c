#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157f24-0x80157f50 (1 functions). split_file divides it into the game's real files.

extern "C" char* lbl_802FF4BC;
extern "C" void fn_80153460(void* p);
extern "C" void fn_80157F24(int i) {
    char* base = lbl_802FF4BC;
    fn_80153460(base + i * 0xf4);
}
