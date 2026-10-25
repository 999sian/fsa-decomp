#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/SinitPoolChain.h"

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

    JGeometry::TVec2<f32>& point(s32 i) {
        if (i >= m2a8) {
            i = 0;
        }
        return m2ac[i];
    }
    void popPoint() {
        if (m2a8 >= 1) {
            s32 n = m2a8 - 1;
            for (s32 i = 0; i < n; i++) {
                m2ac[i].set(m2ac[i + 1]);
            }
            m2a8 = n;
        }
    }
    void pushPoint(const JGeometry::TVec2<f32>& p) {
        if (m2a8 < 16) {
            m2ac[m2a8].set(p);
            m2a8++;
        }
    }
};

extern const f32 lbl_8053F018;
extern const f32 lbl_8053F01C;
extern const f64 lbl_8053F020;
extern const f32 lbl_8053F028;
extern void* lbl_804A46F4[];
extern "C" void fn_801D0F40(void* p);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec2_f_Fv();
extern "C" u8 fn_801F320C(void* a, s32 x);
extern "C" u8 fn_801F329C(void* a, s32 x);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 c);
extern "C" void fn_801CD150(const JGeometry::TVec3<f32>* src, JGeometry::TVec3<f32>* dst);
extern "C" void fn_8022E114(int index, JGeometry::TVec3<f32>* a0);
extern const f32 lbl_8053F02C;
extern const f32 lbl_8053F030;
extern "C" u8 fn_801D0B44(void* this_);
extern "C" u16 fn_802265FC(JGeometry::TVec3<f32>* a, s32 room);
extern "C" const JGeometry::TVec3<f32>* fn_8023E578(s32 idx);
extern "C" const JGeometry::TVec3<f32>* fn_8023E724(s32 idx);
typedef u8 (*VirtFn)(void*, s32, void*);
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

extern "C" s32 fn_801D12CC(u8* this_) {
    s32 ret = 0;
    s32 idx;
    s32 n;
    s32 i;
    s32 kind;
    f32 dx;
    f32 dy;
    f32 k;
    f32 px;
    f32 py;
    f32 sx;
    f32 sy;
    f32 tx;
    f32 ty;
    JGeometry::TVec3<f32> v;
    JGeometry::TVec3<f32> p;
    JGeometry::TVec3<f32> tmp;
    JGeometry::TVec3<f32> pos;
    JGeometry::TVec2<f32> q1;
    JGeometry::TVec2<f32> q2;

    if (*(s32*)(this_ + 0x338) >= 0 && fn_801D0B44(this_)) {
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
        p.x = v.x;
        p.y = v.y;
        p.z = lbl_8053F028;
        if ((*(VirtFn**)this_)[19](this_, *(s32*)(this_ + 4), &p)) {
            kind = (u16)fn_802265FC(&v, *(s32*)(this_ + 4));
            if (kind < 0x2c) {
                if (kind < 0x27) {
                    *(s32*)(this_ + 0x2a8) = 0;
                    return 0;
                }
            } else {
                ret = 1;
                if (!fn_801CF888(this_, this_ + 0xc, &v, *(s32*)(this_ + 4))) {
                    *(s32*)(this_ + 0x2a8) = 0;
                    *(f32*)(this_ + 0x32c) = v.x;
                    *(f32*)(this_ + 0x330) = v.y;
                    *(f32*)(this_ + 0x334) = lbl_8053F028;
                    goto clear;
                }
            }
        }

        dx = *(f32*)(this_ + 0x32c) - *(f32*)(this_ + 0xc);
        dy = *(f32*)(this_ + 0x330) - *(f32*)(this_ + 0x10);
        k = lbl_8053F02C + *(f32*)(this_ + 0x258);
        if (*(s32*)(this_ + 0x2a8) >= 1 && dx * dx + dy * dy <= k * k) {
            n = *(s32*)(this_ + 0x2a8) - 1;
            for (i = 0; i < n; i++) {
                ((JGeometry::TVec2<f32>*)(this_ + 0x2ac))[i].x = ((JGeometry::TVec2<f32>*)(this_ + 0x2ac))[i + 1].x;
                ((JGeometry::TVec2<f32>*)(this_ + 0x2ac))[i].y = ((JGeometry::TVec2<f32>*)(this_ + 0x2ac))[i + 1].y;
            }
            *(s32*)(this_ + 0x2a8) = n;
        }

        {
            u8 flagA;
            u8 flagB;

            flagA = 0;
            flagB = 0;
            n = *(s32*)(this_ + 0x2a8);
            if (n == 0) {
                flagB = 1;
            } else {
                q1.x = *(f32*)(this_ + 0x2ac);
                q1.y = *(f32*)(this_ + 0x2b0);
                if (fn_801CF888(this_, &q1, &v, *(s32*)(this_ + 4))) {
                    flagB = 1;
                } else {
                    dx = v.x - q1.x;
                    dy = v.y - q1.y;
                    if (dx * dx + dy * dy >= lbl_8053F030) {
                        flagA = 1;
                        if (*(s32*)(this_ + 0x2a8) >= 2) {
                            q2.x = *(f32*)(this_ + 0x2ac);
                            q2.y = *(f32*)(this_ + 0x2b0);
                            if (!fn_801CF888(this_, &q2, &v, *(s32*)(this_ + 4))) {
                                if (*(s32*)(this_ + 0x2a8) > 0) {
                                    *(s32*)(this_ + 0x2a8) = *(s32*)(this_ + 0x2a8) - 1;
                                }
                            }
                        }
                    }
                }
            }

            if (flagA || flagB) {
                if (!flagA && *(s32*)(this_ + 0x2a8) >= 0x10) {
                    *(s32*)(this_ + 0x2a8) = 0;
                    return 0;
                }
                if (flagB && *(s32*)(this_ + 0x24c) > 2) {
                    sy = fn_8023E578(*(s32*)(this_ + 0x338))->y;
                    ty = fn_8023E724(*(s32*)(this_ + 0x338))->y;
                    py = v.y - (ty - sy);
                    sx = fn_8023E578(*(s32*)(this_ + 0x338))->x;
                    tx = fn_8023E724(*(s32*)(this_ + 0x338))->x;
                    px = v.x - (tx - sx);
                    if (*(s32*)(this_ + 0x2a8) < 0x10) {
                        ((JGeometry::TVec2<f32>*)(this_ + 0x2ac))[*(s32*)(this_ + 0x2a8)].x = px;
                        ((JGeometry::TVec2<f32>*)(this_ + 0x2ac))[*(s32*)(this_ + 0x2a8)].y = py;
                        *(s32*)(this_ + 0x2a8) = *(s32*)(this_ + 0x2a8) + 1;
                    }
                } else {
                    if (*(s32*)(this_ + 0x2a8) < 0x10) {
                        ((JGeometry::TVec2<f32>*)(this_ + 0x2ac))[*(s32*)(this_ + 0x2a8)].x = v.x;
                        ((JGeometry::TVec2<f32>*)(this_ + 0x2ac))[*(s32*)(this_ + 0x2a8)].y = v.y;
                        *(s32*)(this_ + 0x2a8) = *(s32*)(this_ + 0x2a8) + 1;
                    }
                }
            }
        }

        *(f32*)(this_ + 0x32c) = *(f32*)(this_ + 0x2ac);
        *(f32*)(this_ + 0x330) = *(f32*)(this_ + 0x2b0);
        *(f32*)(this_ + 0x334) = lbl_8053F028;
    }

clear:
    if (!ret) {
        *(s32*)(this_ + 0x2a8) = 0;
    }
    return ret;
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

extern "C" fn_801D1974_obj* fn_801D1974(fn_801D1974_obj* p)
{
    fn_801D0F40(p);
    p->vtbl = lbl_804A46F4;
    p->m2a8 = 0;
    __construct_array(p->m2ac, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 0x10);
    p->m32c = lbl_8053F028;
    p->m330 = lbl_8053F028;
    p->m334 = lbl_8053F028;
    p->m338 = -1;
    p->m33c = 0;
    return p;
}

