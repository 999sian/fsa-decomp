// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801555fc-0x80155784 (3 functions). split_file divides it into the game's real files.
#include "types.h"

extern u32 lbl_802EB5D0[][16];

static inline f32 sqrtf_inl(f32 x)
{
    static const double _half = .5;
    static const double _three = 3.0;
    volatile f32 y;
    if (x > 0.0f) {
        double guess = __frsqrte((double)x);
        guess = _half * guess * (_three - guess * guess * x);
        guess = _half * guess * (_three - guess * guess * x);
        guess = _half * guess * (_three - guess * guess * x);
        y = (f32)(x * guess);
        return y;
    }
    return x;
}
