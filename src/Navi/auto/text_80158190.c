#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158190-0x801581ec (1 functions). split_file divides it into the game's real files.

extern "C" u32 __cvt_fp2unsigned(f64);
extern float lbl_80301A30;
extern f64 lbl_80301A38;
extern char lbl_802D4A80[];
extern "C" u32 fn_80158190(u32 x) {
    f32 a = lbl_80301A30 * (f32)x;
    return __cvt_fp2unsigned(a / (f32)*(u32*)lbl_802D4A80);
}
