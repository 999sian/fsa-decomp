// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801555fc-0x80155784 (3 functions). split_file divides it into the game's real files.
#include "types.h"

extern u32 lbl_802EB5D0[][16];

#pragma fp_contract off
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

extern "C" void fn_801555FC(f32* m, f32* v, f32* out)
{
    out[0] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[9];
    out[1] = m[3] * v[0] + m[4] * v[1] + m[5] * v[2] + m[10];
    out[2] = m[6] * v[0] + m[7] * v[1] + m[8] * v[2] + m[11];
}

extern "C" void fn_801556A8(f32* v)
{
    f32 len = sqrtf_inl(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    v[0] /= len;
    v[1] /= len;
    v[2] /= len;
}

extern "C" void fn_8015575C(u8 a, u8 b, u32 bits)
{
    u32* p = &lbl_802EB5D0[b][a];
    u32 v = *p;
    *p = v | bits;
}
