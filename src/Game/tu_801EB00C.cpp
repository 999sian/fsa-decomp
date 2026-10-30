#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry.h"

extern "C" void fn_801EE434(void*);
extern "C" void __dl__FPv(void*);
extern const float lbl_8053F69C;
extern const float lbl_8053F6A0;
extern const float lbl_8053F6A4;
extern const float lbl_8053F6A8;
extern const float lbl_8053F6AC;
extern const float lbl_8053F6B0;
extern const float lbl_8053F678;
extern "C" u16 fn_801CD664(s32);
extern const float lbl_8053F67C;
extern const float lbl_8053F698;
extern "C" char sincosTable___5JMath[];
extern "C" void* fn_8013CC50(void* mgr, f32* pos, u16 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801EB1F4(char* p, JGeometry::TVec3<f32>* a, JGeometry::TVec3<f32>* out);
extern "C" void fn_801EB00C(char* p, JGeometry::TVec3<f32>* a, JGeometry::TVec3<f32>* out) {
    extern int __float_epsilon[];
    extern const float lbl_8053F680;
    JGeometry::TVec3<f32> tmp;
    JGeometry::TVec3<f32> r;

    tmp.x = 0.0f;
    tmp.y = 0.0f;
    tmp.z = 0.0f;
    if (a->z <= *(f32*)(p + 0x14)) {
        f32 dx = a->x - *(f32*)(p + 0x0);
        f32 dy = a->y - *(f32*)(p + 0x4);
        f32 dxx = dx * dx;
        f32 dyy = dy * dy;
        f32 d2 = dxx + dyy;
        f32 dist = d2;
        if (d2 > 0.0f) {
            dist = __frsqrte(d2) * d2;
        }
        if (dist <= *(f32*)(p + 0x18)) {
            f32 t = 0.0f;
            if (*(f32*)(p + 0x18) != *(f32*)(p + 0x1c)) {
                t = (dist - *(f32*)(p + 0x18)) * (1.0f / (*(f32*)(p + 0x1c) - *(f32*)(p + 0x18)));
                if (t > 1.0f) {
                    t = 1.0f;
                } else if (t < 0.0f) {
                    t = 0.0f;
                }
            }
            f32 amt = t * (*(f32*)(p + 0x24) - *(f32*)(p + 0x20)) + *(f32*)(p + 0x20);
            f32 vx = *(f32*)(p + 0x0) - a->x;
            f32 vy = *(f32*)(p + 0x4) - a->y;
            f32 len2 = vx * vx + vy * vy;
            f32 inv = len2;
            if (len2 > lbl_8053F680 * *(f32*)__float_epsilon) {
                if (len2 > 0.0f) {
                    f32 y2 = (f32)__frsqrte(len2);
                    inv = (0.5f * y2) * (3.0f - len2 * (y2 * y2));
                }
                tmp.x = vx * inv;
                tmp.y = vy * inv;
            }
            f32 sc = dist >= amt ? amt : dist;
            tmp.x *= sc;
            tmp.y *= sc;
        }
    }
    fn_801EB1F4(p, a, &r);
    *out = tmp;
    *out += r;
}

extern "C" void fn_801EB1F4(char* p, JGeometry::TVec3<f32>* a, JGeometry::TVec3<f32>* out) {
    extern int __float_epsilon[];
    extern const float lbl_8053F680;
    extern const float lbl_8053F68C;
    extern void fn_801CD950(f32* value, f32 target, f32 step);

    out->zero();
    if (a->z <= *(f32*)(p + 0x14)) {
        f32 dx = a->x - *(f32*)(p + 0x0);
        f32 dy = a->y - *(f32*)(p + 0x4);
        f32 dxx = dx * dx;
        f32 dyy = dy * dy;
        f32 d2 = dxx + dyy;
        f32 rad = *(f32*)(p + 0x1c);
        if (d2 <= rad * rad) {
            s16 ang = *(s16*)(p + 0x30);
            u32 idx = (u32)(-(s32)ang) >> 2 & 0x3ff8;
            f32 s = *(f32*)(sincosTable___5JMath + idx);
            f32 c = *(f32*)(sincosTable___5JMath + idx + 4);
            f32 x = dx * c - dy * s;
            f32 y = dx * s + dy * c;
            f32 r2 = x * x + y * y;
            f32 len;
            if (r2 <= lbl_8053F680 * *(f32*)__float_epsilon) {
                x = 0.0f;
                y = lbl_8053F68C;
            } else {
                if (r2 <= 0.0f) {
                    len = r2;
                } else {
                    f32 y2 = (f32)__frsqrte(r2);
                    len = r2 * ((0.5f * y2) * (3.0f - r2 * (y2 * y2)));
                }
                fn_801CD950(&len, *(f32*)(p + 0x1c), *(f32*)(p + 0x28));
                if (r2 > lbl_8053F680 * *(f32*)__float_epsilon) {
                    if (r2 > 0.0f) {
                        f32 y2 = (f32)__frsqrte(r2);
                        r2 = (0.5f * y2) * (3.0f - r2 * (y2 * y2));
                    }
                    x *= r2;
                    y *= r2;
                }
                x *= len;
                y *= len;
            }
            x += *(f32*)(p + 0x0);
            y += *(f32*)(p + 0x4);
            JGeometry::TVec3<f32> pos;
            pos.x = x;
            pos.y = y;
            pos.z = a->z;
            out->sub(pos, *a);
            out->z = *(f32*)(p + 0x2c);
        }
    }
}

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void fn_8013CB44(void* obj, void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801CD950(f32* value, f32 target, f32 step);
extern const float lbl_8053F690;
extern const float lbl_8053F694;
extern "C" void fn_801EB418(char* p, JGeometry::TVec3<f32>* a) {
    f32 v[3];
    s32 i;
    void** slot;
    u8 flag;
    s32 off;
    bool del;
    s32 c;
    f32 ax;
    f32 ay;
    f32 az;

    *(f32*)(p + 0x0) = a->x;
    *(f32*)(p + 0x4) = a->y;
    *(f32*)(p + 0x8) = a->z;
    *(s16*)(p + 0x5e) += 0x16a;

    if (*(f32*)(p + 0x54) != *(f32*)(p + 0x58)) {
        f32 step = lbl_8053F690;
        if (*(f32*)(p + 0x54) > *(f32*)(p + 0x58)) {
            step = lbl_8053F694;
        }
        fn_801CD950((f32*)(p + 0x54), *(f32*)(p + 0x58), step);
    }

    c = 0;
    if (*(u8*)(p + 0x5c) != 0 && lbl_8053F678 == *(f32*)(p + 0x54)) {
        c = 1;
    }
    del = (u8)c;
    ax = a->x;
    ay = a->y;
    az = a->z;
    flag = (u8)(s32)*(f32*)(p + 0x54);
    off = 0;
    slot = (void**)p;
    for (i = 0; i < 7; i++, slot++) {
        s16 t = (s16)(*(s16*)(p + 0x5e) + off);
        u32 idx = (u32)(-(s32)t) >> 2 & 0x3ff8;
        f32* tbl = (f32*)((char*)sincosTable___5JMath + idx);
        f32 sn = tbl[0];
        f32 cs = tbl[1];
        v[2] = az;
        v[0] = ax + (lbl_8053F678 * cs - lbl_8053F698 * sn);
        v[1] = ay + (lbl_8053F678 * sn + lbl_8053F698 * cs);

        if (slot[13] != 0) {
            if (del) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), slot[13]);
                slot[13] = 0;
            } else {
                fn_8013CB44(slot[13], v, *(s32*)(p + 0xc), *(s32*)(p + 0x10), 1);
                *(u8*)((char*)slot[13] + 0xbb) = flag;
            }
        }
        if (i == 0) {
            if (*(void**)(p + 0x50) != 0) {
                if (del) {
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x50));
                    *(void**)(p + 0x50) = 0;
                } else {
                    fn_8013CB44(*(void**)(p + 0x50), v, *(s32*)(p + 0xc), *(s32*)(p + 0x10), 1);
                    *(u8*)((char*)*(void**)(p + 0x50) + 0xbb) = flag;
                }
            }
        }
        off += 0x1f70;
    }
}

extern "C" int fn_801EB648(void* param_1) {
    int result = 0;
    if ((unsigned char)(int)*(float*)((char*)param_1 + 0x54) != 0) {
        unsigned int* p = (unsigned int*)((char*)param_1 + 0x34);
        unsigned int v;
        v = p[0];
        if (v != 0) {
            result = 1;
        } else {
            p = (unsigned int*)((char*)p + 4);
            v = *(unsigned int*)((char*)p + 0x30);
            if (v != 0) {
                result = 1;
            } else {
                v = *(unsigned int*)((char*)p + 0x34);
                p = (unsigned int*)((char*)p + 4);
                if (v != 0) {
                    result = 1;
                } else {
                    v = *(unsigned int*)((char*)p + 0x34);
                    p = (unsigned int*)((char*)p + 4);
                    if (v != 0) {
                        result = 1;
                    } else {
                        v = *(unsigned int*)((char*)p + 0x34);
                        p = (unsigned int*)((char*)p + 4);
                        if (v != 0) {
                            result = 1;
                        } else {
                            v = *(unsigned int*)((char*)p + 0x34);
                            p = (unsigned int*)((char*)p + 4);
                            if (v != 0) {
                                result = 1;
                            } else {
                                v = *(unsigned int*)((char*)p + 0x34);
                                if (v != 0) {
                                    result = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

extern "C" void fn_801EB710(char* this_, void* mgr, f32* src) {
    s32 i;
    f32* base;
    s32 off;
    void** slot;
    f32 v[3];
    f32 scale;
    f32 z;
    f32 y;
    f32 x;
    f32 rot;
    x = src[0];
    y = src[1];
    z = src[2];
    *(f32*)(this_ + 0x0) = x;
    *(f32*)(this_ + 0x4) = y;
    *(f32*)(this_ + 0x8) = z;
    *(u8*)(this_ + 0x5c) = 0;
    u8 flag = (u8)(s32)*(f32*)(this_ + 0x54);
    rot = lbl_8053F678;
    scale = lbl_8053F698;
    base = (f32*)sincosTable___5JMath;
    slot = (void**)this_;
    off = 0;
    for (i = 0; i < 7; i++) {
        s16 t = (s16)(*(s16*)(this_ + 0x5e) + off);
        u32 idx = (u32)(-(s32)t) >> 2 & 0x3ff8;
        f32* tbl = (f32*)((char*)base + idx);
        f32 sn = tbl[0];
        f32 cs = tbl[1];
        v[0] = x + (rot * cs - scale * sn);
        v[1] = y + (rot * sn + scale * cs);
        v[2] = z;
        if (slot[13] == 0) {
            slot[13] = fn_8013CC50(mgr, v, (u16)(i + 0x233), *(s32*)(this_ + 0xc), *(s32*)(this_ + 0x10), 0, 0, 1, lbl_8053F67C);
            if (slot[13] != 0) {
                *(u8*)((char*)slot[13] + 0xbb) = flag;
            }
        }
        if (i == 0 && *(s32*)(this_ + 0x50) == 0) {
            *(void**)(this_ + 0x50) = fn_8013CC50(mgr, v, 0x23a, *(s32*)(this_ + 0xc), *(s32*)(this_ + 0x10), 0, 0, 1, lbl_8053F67C);
            if (*(s32*)(this_ + 0x50) != 0) {
                *(u8*)(*(char**)(this_ + 0x50) + 0xbb) = flag;
            }
        }
        slot++;
        off += 0x1f70;
    }
}

extern "C" char* dtor_801EB8CC(char* p, s16 freeFlag) {
    if (p != 0) {
        for (s32 i = 0; i < 7; i++) {
            fn_801EE434(*(void**)(p + 0x34 + i * 4));
        }
        fn_801EE434(*(void**)(p + 0x50));
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" char* fn_801EB950(char* p) {
    *(f32*)(p + 0x0) = lbl_8053F678;
    *(f32*)(p + 0x4) = lbl_8053F678;
    *(f32*)(p + 0x8) = lbl_8053F678;
    *(s32*)(p + 0xC) = 1;
    *(s32*)(p + 0x10) = 1;
    *(f32*)(p + 0x14) = lbl_8053F69C;
    *(f32*)(p + 0x18) = lbl_8053F6A0;
    *(f32*)(p + 0x1C) = lbl_8053F6A4;
    *(f32*)(p + 0x20) = lbl_8053F6A8;
    *(f32*)(p + 0x24) = lbl_8053F6AC;
    *(f32*)(p + 0x28) = lbl_8053F6B0;
    *(f32*)(p + 0x2C) = lbl_8053F6AC;
    *(s16*)(p + 0x30) = 0x600;
    *(s32*)(p + 0x50) = 0;
    *(f32*)(p + 0x54) = lbl_8053F678;
    *(f32*)(p + 0x58) = lbl_8053F678;
    *(u8*)(p + 0x5C) = 0;
    *(s16*)(p + 0x5E) = fn_801CD664(0x10000);
    *(s32*)(p + 0x34) = 0;
    *(s32*)(p + 0x38) = 0;
    *(s32*)(p + 0x3C) = 0;
    *(s32*)(p + 0x40) = 0;
    *(s32*)(p + 0x44) = 0;
    *(s32*)(p + 0x48) = 0;
    *(s32*)(p + 0x4C) = 0;
    return p;
}

extern "C" void fn_801EBA14(char* p) {
    *(s32*)(p + 0x0) = 1;
    *(s32*)(p + 0x4) = 1;
    *(f32*)(p + 0x8) = lbl_8053F69C;
    *(f32*)(p + 0xc) = lbl_8053F6A0;
    *(f32*)(p + 0x10) = lbl_8053F6A4;
    *(f32*)(p + 0x14) = lbl_8053F6A8;
    *(f32*)(p + 0x18) = lbl_8053F6AC;
    *(f32*)(p + 0x1c) = lbl_8053F6B0;
    *(f32*)(p + 0x20) = lbl_8053F6AC;
    *(s16*)(p + 0x24) = 0x600;
}

void __sinit_tu_801EB00C_cpp(void) {}

