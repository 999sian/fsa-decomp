// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80115d98-0x801162dc (5 functions). split_file divides it into the game's real files.

#include "types.h"

u32 lbl_802FF228;
u32 lbl_802FF22C;
u32 lbl_802FF230;

extern u32 lbl_802FF228;
extern u32 lbl_802FF22C;
extern u32 lbl_802FF230;
extern "C" f64 fn_801E9FA0(void);
s16 fn_80115D98(f64 a)
{
    f32 f;
    s32 v;

    f = (f32)((f64 (*)(f64, f64))fn_801E9FA0)(a, 6.283185958862305);
    v = (s32)(10430.4f * f);
    if (v < -0x8000) {
        v += 0x10000;
    } else if (v > 0x7fff) {
        v -= 0x10000;
    }
    return (s16)v;
}

extern "C" u32 lbl_802FF228;
extern "C" u32 lbl_802FF22C;
extern "C" u32 lbl_802FF230;
extern "C" void fn_80116054(u32 param_1, u32 param_2, u32 param_3)
{
    lbl_802FF228 = param_1;
    lbl_802FF22C = param_2;
    lbl_802FF230 = param_3;
}
