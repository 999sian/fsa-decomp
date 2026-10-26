#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/SinitPoolChain.h"

// Trail of up to 16 points (count at +0x2a8 of fn_801D1974_obj).
struct PointTrail {
    s32 count;
    JGeometry::TVec2<f32> pts[16];

    JGeometry::TVec2<f32>& get(s32 i) {
        if (count <= i) {
            i = 0;
        }
        return pts[i];
    }
    void removeFront() {
        if (count >= 1) {
            s32 n = count - 1;
            for (s32 i = 0; i < n; i++) {
                s32 j = i + 1;
                pts[i].x = pts[j].x;
                pts[i].y = pts[j].y;
            }
            count = n;
        }
    }
    void add(const JGeometry::TVec2<f32>& p) {
        if (count < 16) {
            pts[count].x = p.x;
            pts[count].y = p.y;
            count++;
        }
    }
};

struct fn_801D1974_obj {
    void* vtbl;
    u8 pad04[0xc - 4];
    JGeometry::TVec3<f32> m00c;
    u8 pad[0x2a8 - 0x18];
    s32 m2a8;
    JGeometry::TVec2<f32> m2ac[16];
    f32 m32c;
    f32 m330;
    f32 m334;
    s32 m338;
    s16 m33c;

    PointTrail& trail() { return *(PointTrail*)&m2a8; }
    JGeometry::TVec2<f32>& pointAt(s32 i) { return m2ac[i]; }
    s32 pointIndex(s32 i) {
        if (m2a8 <= i) i = 0;
        return i;
    }
    JGeometry::TVec2<f32>& point(s32 i) {
        return m2ac[pointIndex(i)];
    }
    void popPoint() {
        if (m2a8 >= 1) {
            int n = m2a8 - 1;
            for (int i = 0; i < n; i++) {
                int j = i + 1;
                trail().pts[i].x = m2ac[j].x;
                trail().pts[i].y = m2ac[j].y;
            }
            m2a8 = n;
        }
    }
    void pushPoint(const JGeometry::TVec2<f32>& p) {
        if (m2a8 < 16) {
            m2ac[m2a8].x = p.x;
            m2ac[m2a8].y = p.y;
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
#pragma opt_propagation off
extern "C" void fn_801D11FC(u8* this_)
{
    s16 lo;
    s16 hi;
    s16 target;
    s16 cur;
    f32 angle;
    f32 dLo;
    f32 dHi;
    f32 scale;

    angle = JMath::atanTable_.atan2_(*(f32*)(this_ + 0x264), *(f32*)(this_ + 0x268));
    target = (s16)(s32)(angle * lbl_8053F018);
    cur = *(s16*)(this_ + 0x33c);
    hi = cur + 0x5b0;
    lo = cur - 0x5b0;
    dHi = (f32)(s16)(target - hi);
    dLo = (f32)(s16)(target - lo);
    scale = lbl_8053F01C;
    if (scale * __fabsf(dHi) < scale * __fabsf(dLo)) *(s16*)(this_ + 0x33c) = hi;
    else *(s16*)(this_ + 0x33c) = lo;
}
#pragma opt_propagation reset
extern "C" s32 fn_801D12CC(fn_801D1974_obj* this_) {
    fn_801D1974_obj* object = this_;
    s32 ret;
    s32 lost;
    u8 far_;
    s32 i;
    s32 n;
    s32 j;
    PointTrail* trail;
    fn_801D1974_obj* from;
    JGeometry::TVec3<f32> v;
    JGeometry::TVec3<f32> p;
    JGeometry::TVec3<f32> tmp;
    JGeometry::TVec3<f32> pos;

    ret = 0;
    if (object->m338 >= 0 && ((u8 (*)(void*, s32))fn_801D0B44)(object, object->m338)) {
        lost = object->m338;
        fn_8022E114(lost, &pos);
        if (fn_801F329C(object, lost)) {
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
        if ((u8)((Actor*)object)->v17(*(s32*)((u8*)object + 4), (f32*)&p)) {
            s32 kind = fn_802265FC(&v, *(s32*)((u8*)object + 4));
            if (kind >= 0x2c || kind < 0x27) {
                object->m2a8 = 0;
                return 0;
            }
        }
        ret = 1;
        if (!fn_801CF888(object, &object->m00c, &v, *(s32*)((u8*)object + 4))) {
            object->m2a8 = 0;
            ((JGeometry::TVec3<f32>*)&object->m32c)->set(v.x, v.y, lbl_8053F028);
        } else {
            if (object->m2a8 >= 1) {
                f32 dy;
                f32 dx;
                dx = object->m32c - object->m00c.x;
                dy = object->m330 - object->m00c.y;
                f32 r = lbl_8053F02C + *(f32*)((u8*)object + 0x258);
                f32 dx2 = dx * dx;
                f32 dy2 = dy * dy;
                if (dx2 + dy2 <= r * r) {
                    if (object->m2a8 >= 1) {
                        n = object->m2a8 - 1;
                        for (i = 0; i < n; i++) {
                            j = i + 1;
                            from = (fn_801D1974_obj*)((u8*)object + j * 8);
                            object->trail().pts[i].x = from->m2ac[0].x;
                            object->trail().pts[i].y = from->m2ac[0].y;
                        }
                        object->m2a8 = n;
                    }
                }
            }
            far_ = 0;
            lost = 0;
            if (object->m2a8 == 0) {
                lost = 1;
            } else {
                JGeometry::TVec2<f32> q1 = object->m2ac[object->pointIndex(object->m2a8 - 1)];
                if (fn_801CF888(object, &q1, &v, *(s32*)((u8*)object + 4))) {
                    lost = 1;
                } else {
                    f32 ex = v.x - q1.x;
                    f32 ey = v.y - q1.y;
                    if (ex * ex + ey * ey >= lbl_8053F030) {
                        far_ = 1;
                        if (object->m2a8 >= 2) {
                            JGeometry::TVec2<f32> q2 = object->m2ac[object->pointIndex(object->m2a8 - 2)];
                            if (!fn_801CF888(object, &q2, &v, *(s32*)((u8*)object + 4))) {
                                if (object->m2a8 > 0) {
                                    object->m2a8--;
                                }
                            }
                        }
                    }
                }
            }
            if (far_ || (u8)lost) {
                if (object->m2a8 >= 0x10) {
                    object->m2a8 = 0;
                    return 0;
                }
                if ((u8)lost && *(s32*)((u8*)object + 0x24c) > 2) {
                    f32 y = v.y - (fn_8023E724(object->m338)->y - fn_8023E578(object->m338)->y);
                    f32 x = v.x - (fn_8023E724(object->m338)->x - fn_8023E578(object->m338)->x);
                    object->pushPoint(JGeometry::TVec2<f32>(x, y));
                } else {
                    object->pushPoint(*(JGeometry::TVec2<f32>*)&v);
                }
            }
            ((JGeometry::TVec3<f32>*)&object->m32c)->set(object->m2ac[object->pointIndex(0)].x, object->m2ac[object->pointIndex(0)].y, lbl_8053F028);
        }
    }
    if (!(u8)ret) {
        object->m2a8 = 0;
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

