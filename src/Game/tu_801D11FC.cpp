#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

struct fn_801D1974_obj {
    void* vtbl;
    u8 pad[0x2a8 - 4];
    s32 m2a8;
    JGeometry::TVec2<f32> m2ac[16];
    f32 m32c;
    f32 m330;
    f32 m334;
    s32 m338;
    s16 m33c;
};

extern const f32 lbl_8053F018;
extern const f32 lbl_8053F01C;
extern const f64 lbl_8053F020;
extern const f32 lbl_8053F028;
extern "C" u8 fn_801F320C(void* a, s32 x);
extern "C" u8 fn_801F329C(void* a, s32 x);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 c);
extern "C" void fn_801CD150(const JGeometry::TVec3<f32>* src, JGeometry::TVec3<f32>* dst);
extern "C" void fn_8022E114(int index, JGeometry::TVec3<f32>* a0);
extern "C" void fn_801D11FC(u8* this_)
{
    s16 cur;
    s16 lo;
    s16 hi;
    s16 target;
    f32 dHi;
    f32 dLo;
    f32 angle;

    angle = JMath::atanTable_.atan2_(*(f32*)(this_ + 0x264), *(f32*)(this_ + 0x268));
    cur = *(s16*)(this_ + 0x33c);
    hi = cur + 0x5b0;
    lo = cur - 0x5b0;
    target = (s16)(s32)(angle * lbl_8053F018);
    dHi = (f32)(s16)(target - hi);
    dLo = (f32)(s16)(target - lo);
    if (lbl_8053F01C * __fabsf(dHi) < lbl_8053F01C * __fabsf(dLo)) {
        *(s16*)(this_ + 0x33c) = hi;
    } else {
        *(s16*)(this_ + 0x33c) = lo;
    }
}

extern "C" s32 fn_801D183C(u8* this_, f32 radius) {
    s32 result = 0;
    JGeometry::TVec3<f32> v;
    JGeometry::TVec3<f32> tmp;
    JGeometry::TVec3<f32> pos;
    s32 idx;

    idx = *(s32*)(this_ + 0x338);
    if (idx >= 0 && idx < 4 && fn_801F320C(this_, idx)) {
        idx = *(s32*)(this_ + 0x338);
        fn_8022E114(idx, &pos);
        if (fn_801F329C(this_, idx)) {
            fn_801CD150(&pos, &tmp);
            v.x = tmp.x;
            v.y = tmp.y;
            v.z = tmp.z;
        } else {
            v.x = pos.x;
            v.y = pos.y;
            v.z = pos.z;
        }
        if (lbl_8053F028 == radius ||
            (v.x - *(f32*)(this_ + 0xc)) * (v.x - *(f32*)(this_ + 0xc)) + (v.y - *(f32*)(this_ + 0x10)) * (v.y - *(f32*)(this_ + 0x10)) <= radius * radius) {
            if (!fn_801CF888(this_, this_ + 0xc, &v, *(s32*)(this_ + 4))) {
                result = 1;
            }
        }
    }
    return result;
}

