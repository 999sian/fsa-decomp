// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015765c-0x801576a8 (5 functions). split_file divides it into the game's real files.

#include "types.h"

extern "C" unsigned char lbl_802FF4E8;
extern "C" char* lbl_802FF4BC;
extern "C" void* lbl_802FF4C0;
extern "C" void fn_8015765C(u8 param_1) {
    lbl_802FF4E8 = param_1;
}

extern "C" unsigned char fn_80157664(void) {
    return lbl_802FF4E8;
}

extern "C" int fn_8015766C(int i) {
    return -(int)(*(unsigned char*)(lbl_802FF4BC + i * 0xf4 + 0xec) == 0);
}

extern "C" void fn_8015768C(void* p) {
    lbl_802FF4C0 = p;
}

extern "C" void fn_80157694(int i, int v) {
    *(int*)(lbl_802FF4BC + i * 0xf4 + 0x1c) = v;
}

