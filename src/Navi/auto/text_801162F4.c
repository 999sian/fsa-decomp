#include "types.h"

extern f32 lbl_80301470;  // SDA label
extern f32 lbl_80301498;  // SDA label

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801162f4-0x8011695c (12 functions). split_file divides it into the game's real files.

extern "C" void memset(void);
extern "C" void fn_801162F4(void) {
    memset();
}

extern "C" f32 fn_80116314(f32* p, f32 target, f32 rate, f32 maxStep, f32 minStep) {
    f32 cur = *p;
    if (cur != target) {
        f32 negMin;
        f32 d = rate * (target - cur);
        if (d >= minStep || d <= (negMin = -minStep)) {
            if (d > maxStep) {
                d = maxStep;
            }
            if (d < -maxStep) {
                d = -maxStep;
            }
            *p += d;
        } else if (d > lbl_80301470) {
            if (d < minStep) {
                *p = cur + minStep;
                if (*p > target) {
                    *p = target;
                }
            }
        } else if (d > negMin) {
            *p = cur + negMin;
            if (*p < target) {
                *p = target;
            }
        }
    }
    f64 diff = __fabs(target - *p);
    return diff;
}

extern "C" int fn_801167D0(s16* p, s16 target, s16 step) {
    if (step != 0) {
        if (*p > target) {
            step = -step;
        }
        *p += step;
        if (step * (*p - target) >= 0) {
            *p = target;
            return 1;
        }
    } else if (*p == target) {
        return 1;
    }
    return 0;
}

extern "C" void fn_801168AC(void) {
    extern void* lbl_802FDC98;
    extern u8 lbl_802C5D58[];
    lbl_802FDC98 = lbl_802C5D58;
}

extern "C" void fn_8011691C(unsigned short* param_1, unsigned short param_2);
extern "C" void* fn_801168BC(unsigned short* param_1, unsigned short param_2) {
    fn_8011691C(param_1, param_2);
    return param_1;
}

extern "C" void fn_80116924(unsigned short* param_1, unsigned short param_2);
extern "C" void* fn_801168EC(unsigned short* param_1, unsigned short param_2) {
    fn_80116924(param_1, param_2);
    return param_1;
}

extern "C" void fn_8011691C(unsigned short* param_1, unsigned short param_2) {
    *param_1 = param_2;
}
extern "C" u8 lbl_802C5D58[];
extern "C" void* lbl_802FDC98;
extern "C" f32 lbl_80301470;
