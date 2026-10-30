#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014f024-0x8014f078 (1 functions). split_file divides it into the game's real files.

extern "C" float fn_801EA228(float, float);
extern "C" u32 __cvt_fp2unsigned(f64);
extern float lbl_80301980;
extern float lbl_80301978;
extern float lbl_8030197C;
extern "C" u32 fn_8014F024(s32 x) {
    return __cvt_fp2unsigned(1000.0f * fn_801EA228(2.0f, (float)x * lbl_80301980));
}
