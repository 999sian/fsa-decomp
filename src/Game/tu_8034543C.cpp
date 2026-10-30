#include "types.h"
#define Vec SDKVec
#include "JSystem/JGeometry/Vec.h"
#undef Vec
#include "Game/Actor.h"
#include "Game/ItemBase.h"
extern const f32 lbl_805423A0;
extern const f32 lbl_805423A4;
extern const f32 lbl_805423A8;
extern const char lbl_80471FF8[];
extern "C" void fn_801F06F0(void*, const char*, s32, DrawRec*, s32, f32, f32);
#include <math.h>


extern "C" s16 fn_8022461C(s32);
extern "C" char lbl_804AC658[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8034543C(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_804AC658;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8034549C(char* this_) {
    DrawRec param;
    f32 mtx[3][4];
    f32 cx; f32 ry; f32 sx; f32 sy; f32 sz; f32 cy; f32 sxsy; f32 cz;
    mtx[0][3] = lbl_805423A0;
    mtx[1][3] = lbl_805423A0;
    mtx[2][3] = lbl_805423A0;
    ry = *(u16*)(this_ + 0x252) / lbl_805423A4;
    sx = sin(lbl_805423A0);
    sy = sin(ry);
    sz = sin(lbl_805423A0);
    cx = cos(lbl_805423A0);
    cy = cos(ry);
    cz = cos(lbl_805423A0);
    param.w18 = &mtx;
    param.b21 = 1;
    *(s8*)&param.b1c = -1;
    param.b1d = -1;
    ((u8*)&param.w10)[3] = 200;
    f32 sc = lbl_805423A8;
    f32 cxsz;
    f32 cxcz;
    cxcz = cx * cz;
    sxsy = sx * sy;
    cxsz = cx * sz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    mtx[0][0] = sc * (cy * cz);
    mtx[1][0] = sc * (cy * sz);
    mtx[2][0] = sc * -sy;
    mtx[0][1] = sc * (sxsy * cz - cxsz);
    mtx[1][1] = sc * (sxsy * sz + cxcz);
    mtx[2][1] = sc * (sx * cy);
    mtx[0][2] = sc * (cxcz * sy + sxsz);
    mtx[1][2] = sc * (cxsz * sy - sxcz);
    mtx[2][2] = sc * (cx * cy);
    fn_801F06F0(this_, lbl_80471FF8, *(s32*)(this_ + 0x24c) + 0x283, &param, -1, sc, sc);
}

extern "C" void fn_801F71A4(f32* value, f32 target, f32 rate, f32 limit);
extern "C" u8 fn_801F2618(Actor* this_, Vec* push, s32 flag);
extern "C" u8 fn_802265DC(f32* pos, s32 room, s32 flag);
extern "C" s32 fn_80346330(u8* this_);
extern void* lbl_8053AAF8;
extern const f32 lbl_805423B8;
extern const f32 lbl_805423BC;
extern const f32 lbl_805423C0;
extern const f32 lbl_805423C4;
extern const f32 lbl_805423C8;
extern const f32 lbl_805423CC;
extern const f32 lbl_805423D0;
extern const f32 lbl_805423D4;
extern const f32 lbl_805423D8;
extern const f32 lbl_805423DC;
extern const f32 lbl_805423E0;
extern const f32 lbl_805423E4;
extern const f32 lbl_805423E8;
extern const f32 lbl_805423EC;
extern const f32 lbl_805423F0;
extern const f32 lbl_805423F4;
extern const f32 lbl_805423F8;
static inline f32 tuRandUnit() {
    u8* g = (u8*)lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    return *(f32*)&bits - lbl_805423A8;
}
static inline void tuSetSwimVel(u8* self, f32 speed) {
    *(f32*)(self + 0x3c) = speed * JMASinShort(*(u16*)(self + 0x250));
    *(f32*)(self + 0x40) = speed * JMACosShort(*(u16*)(self + 0x250));
}
extern "C" void fn_80345744(Actor* this_) {
    u8* self = (u8*)this_;
    fn_801F71A4((f32*)(self + 0x3c), *(f32*)(self + 0x254), lbl_805423B8, *(f32*)(self + 0x260));
    fn_801F71A4((f32*)(self + 0x40), *(f32*)(self + 0x258), lbl_805423B8, *(f32*)(self + 0x260));
    ((JGeometry::TVec3f*)(self + 0xc))->add(*(JGeometry::TVec3f*)(self + 0x3c));
    Vec push;
    push.x = push.y = push.z = lbl_805423A0;
    u8 hit = fn_801F2618((Actor*)self, &push, 0);
    switch (*(s32*)(self + 0x230)) {
    case 0: {
        *(f32*)(self + 0x260) = lbl_805423BC;
        f32 spread = lbl_805423C4;
        *(u16*)(self + 0x250) += (s32)(lbl_805423C0 - spread * tuRandUnit());
        f32 base = lbl_805423C8;
        f32 speed = base * tuRandUnit() + base;
        *(f32*)(self + 0x3c) = speed * JMASinShort(*(u16*)(self + 0x250));
        *(f32*)(self + 0x40) = speed * JMACosShort(*(u16*)(self + 0x250));
        *(s32*)(self + 0x238) = (s32)(lbl_805423CC * tuRandUnit()) + 0x41;
        *(s32*)(self + 0x230) = 1;
    }
    case 1:
        if (hit) {
            s32 i;
            s32 angle;
            JGeometry::TVec3f* pos;
            angle = *(u16*)(self + 0x250);
            f32 zero = lbl_805423A0;
            *(f32*)(self + 0x3c) = *(f32*)(self + 0x40) = *(f32*)(self + 0x44) = zero;
            pos = (JGeometry::TVec3f*)(self + 0xc);
            i = 0;
            angle += 0x4000;
            f32 x = *(f32*)(self + 0xc);
            f32 y = *(f32*)(self + 0x10);
            f32 z = *(f32*)(self + 0x14);
            for (; i < 15; i++) {
                *(f32*)(self + 0xc) = x;
                *(f32*)(self + 0x10) = y;
                *(f32*)(self + 0x14) = z;
                JGeometry::TVec3f d;
                d.x = zero;
                d.y = zero;
                d.x = lbl_805423D0 * JMASinShort(angle);
                d.y = lbl_805423D0 * JMACosShort(angle);
                d.z = zero;
                pos->add(d);
                if (!fn_802265DC((f32*)pos, *(s32*)(self + 0x4), 0)) {
                    break;
                }
                angle += 0x1000;
            }
            *(u16*)(self + 0x250) = angle;
            *(u16*)(self + 0x252) = *(u16*)(self + 0x250) + 0x4000;
            *(f32*)(self + 0xc) = x;
            *(f32*)(self + 0x10) = y;
            *(f32*)(self + 0x14) = z;
            f32 speed = lbl_805423C8 * tuRandUnit() + lbl_805423C8;
            *(f32*)(self + 0x3c) = speed * JMASinShort(*(u16*)(self + 0x250));
            *(f32*)(self + 0x40) = speed * JMACosShort(*(u16*)(self + 0x250));
        } else {
            *(u16*)(self + 0x252) = *(u16*)(self + 0x250) + 0x4000;
            if (fn_80346330(self)) {
                *(s32*)(self + 0x230) = 4;
            } else if (*(s32*)(self + 0x238) == 0) {
                if (tuRandUnit() < lbl_805423D4) {
                    *(s32*)(self + 0x230) = 2;
                } else if (tuRandUnit() < lbl_805423D8) {
                    *(s32*)(self + 0x230) = 0;
                }
            }
        }
        break;
    case 2:
        *(s32*)(self + 0x238) = (s32)(lbl_805423CC * tuRandUnit()) + 0x41;
        *(s32*)(self + 0x230) = 3;
    case 3:
        if (fn_80346330(self)) {
            *(s32*)(self + 0x230) = 4;
        } else if (*(s32*)(self + 0x238) == 0) {
            *(s32*)(self + 0x230) = 0;
        }
        break;
    case 4:
        if (fn_80346330(self)) {
            *(u16*)(self + 0x250) = *(u16*)(self + 0x268) + 0x8000;
            *(u16*)(self + 0x250) += (s32)(lbl_805423DC - lbl_805423C0 * tuRandUnit());
        }
        *(f32*)(self + 0x254) = lbl_805423E0 * JMASinShort(*(u16*)(self + 0x250));
        *(f32*)(self + 0x258) = lbl_805423E0 * JMACosShort(*(u16*)(self + 0x250));
        *(f32*)(self + 0x3c) = *(f32*)(self + 0x254);
        *(f32*)(self + 0x40) = *(f32*)(self + 0x258);
        *(f32*)(self + 0x44) = *(f32*)(self + 0x25c);
        *(s32*)(self + 0x234) = 0;
        *(s32*)(self + 0x238) = (s32)(lbl_805423E4 * tuRandUnit()) + 0x14;
        *(s32*)(self + 0x240) = 0;
        *(s32*)(self + 0x230) = 5;
    case 5:
        if (hit && *(s32*)(self + 0x234) == 0) {
            *(u16*)(self + 0x250) = *(u16*)(self + 0x268) + 0x8000;
            if (push.x != lbl_805423A0) {
                *(s32*)(self + 0x234) = (s32)(lbl_805423E8 * tuRandUnit()) + 8;
                if (*(s32*)(self + 0x244) == 0) {
                    *(s32*)(self + 0x240) = 1;
                    if (push.x > lbl_805423A0) {
                        if (*(u16*)(self + 0x250) >= 0x4000 && *(u16*)(self + 0x250) <= 0xc000) {
                            *(u16*)(self + 0x250) = (s32)(lbl_805423EC - lbl_805423C0 * tuRandUnit());
                        } else {
                            f32 range = lbl_805423C0;
                            *(u16*)(self + 0x250) = (s32)(range * tuRandUnit() + lbl_805423A8);
                        }
                    } else {
                        if (*(u16*)(self + 0x250) >= 0x4000 && *(u16*)(self + 0x250) <= 0xc000) {
                            *(u16*)(self + 0x250) = (s32)(lbl_805423C0 * tuRandUnit() + lbl_805423EC);
                        } else {
                            f32 range = lbl_805423C0;
                            *(u16*)(self + 0x250) = (s32)(lbl_805423A8 - range * tuRandUnit());
                        }
                    }
                } else {
                    *(u16*)(self + 0x250) = *(u16*)(self + 0x268);
                    *(s32*)(self + 0x234) = (s32)(lbl_805423E4 * tuRandUnit()) + 0x14;
                }
            } else if (push.y != lbl_805423A0) {
                *(s32*)(self + 0x234) = (s32)(lbl_805423E8 * tuRandUnit()) + 8;
                if (*(s32*)(self + 0x240) == 0) {
                    *(s32*)(self + 0x244) = 1;
                    if (push.y > lbl_805423A0) {
                        if (*(u16*)(self + 0x250) & 0x8000) {
                            *(u16*)(self + 0x250) = (s32)(lbl_805423F0 - lbl_805423DC * tuRandUnit());
                        } else {
                            *(u16*)(self + 0x250) = (s32)(lbl_805423DC * tuRandUnit() + lbl_805423DC);
                        }
                    } else {
                        if (*(u16*)(self + 0x250) & 0x8000) {
                            *(u16*)(self + 0x250) = (s32)(lbl_805423F4 - lbl_805423DC * tuRandUnit());
                        } else {
                            *(u16*)(self + 0x250) = (s32)(lbl_805423DC * tuRandUnit() + lbl_805423F8);
                        }
                    }
                } else {
                    *(u16*)(self + 0x250) = *(u16*)(self + 0x268);
                    *(s32*)(self + 0x234) = (s32)(lbl_805423E4 * tuRandUnit()) + 0x14;
                }
            }
            *(f32*)(self + 0x254) = lbl_805423E0 * JMASinShort(*(u16*)(self + 0x250));
            *(f32*)(self + 0x258) = lbl_805423E0 * JMACosShort(*(u16*)(self + 0x250));
            *(f32*)(self + 0x3c) = *(f32*)(self + 0x254);
            *(f32*)(self + 0x40) = *(f32*)(self + 0x258);
            *(f32*)(self + 0x44) = *(f32*)(self + 0x25c);
        } else {
            *(u16*)(self + 0x252) = *(u16*)(self + 0x250) + 0x4000;
            if (!hit && *(s32*)(self + 0x234) == 0) {
                *(s32*)(self + 0x240) = 0;
                *(s32*)(self + 0x244) = 0;
            }
            if (*(s32*)(self + 0x238) == 0 && *(s32*)(self + 0x234) == 0) {
                if (!fn_80346330(self)) {
                    *(f32*)(self + 0x254) = *(f32*)(self + 0x258) = *(f32*)(self + 0x25c) = lbl_805423A0;
                    *(s32*)(self + 0x230) = 0;
                } else {
                    *(s32*)(self + 0x230) = 4;
                }
            }
        }
        break;
    }
    if (*(s32*)(self + 0x234) > 0) {
        *(s32*)(self + 0x234) = *(s32*)(self + 0x234) - 1;
    }
    if (*(s32*)(self + 0x238) > 0) {
        *(s32*)(self + 0x238) = *(s32*)(self + 0x238) - 1;
    }
    if (*(s32*)(self + 0x23c) > 0) {
        *(s32*)(self + 0x23c) = *(s32*)(self + 0x23c) - 1;
    }
}

extern "C" void fn_801EEC98(void*, s32, u16*, s32*, f32*, s32*, s32, s32);
extern "C" u8 fn_80233E40(s32);
extern "C" u8 fn_8022B7C4(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" Vec* fn_8023E724(s32);
extern "C" s32 ClassifyBamAngleToQuadrant(u16);
extern const f32 lbl_805423A0;
extern const f32 lbl_805423FC;
extern const f64 lbl_80542400;
extern const f64 lbl_80542408;
extern const f64 lbl_80542410;
extern const f32 lbl_80542418;

static inline f64 sqrtStep(f64 tmpd, f32 mag) {
    return lbl_80542400 * tmpd * (lbl_80542408 - mag * (tmpd * tmpd));
}

static inline f32 tuSqrt(f32 mag) {
    if (mag > lbl_805423A0) {
        f64 tmpd = __frsqrte(mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        return mag * tmpd;
    } else if (mag < lbl_80542410) {
        return *(f32*)__float_nan;
    } else if (fpclassify(mag) == 1) {
        return *(f32*)__float_nan;
    } else {
        return mag;
    }
}
extern "C" s32 fn_80346330(u8* this_) {
    s32 i;
    s32 room;
    f32 dy;
    f32 dx;

    *(f32*)(this_ + 0x264) = lbl_805423A0;
    *(u16*)(this_ + 0x268) = 0;
    *(s32*)(this_ + 0x26c) = -1;
    *(s32*)(this_ + 0x270) = -1;
    fn_801EEC98(this_, *(s32*)(this_ + 0x198), (u16*)(this_ + 0x268), (s32*)(this_ + 0x26c), (f32*)(this_ + 0x264), (s32*)(this_ + 0x270), 0, 0);

    if (*(s32*)(this_ + 0x26c) >= 0 && *(f32*)(this_ + 0x264) < lbl_805423FC) {
        if (*(s32*)(this_ + 0x270) >= 0) {
            if (fn_80233E40(*(s32*)(this_ + 0x270)) == 1 || fn_8022B7C4(*(s32*)(this_ + 0x270)) == 1) {
                return 1;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        if (fn_8022CAF8(i) == 4 || fn_8022CAF8(i) == 5) {
            continue;
        }
        if (*(s32*)(this_ + 0x270) == i) {
            continue;
        }
        room = *(s32*)(this_ + 0x4);
        if (room != fn_8023DE58(i)) {
            continue;
        }
        if (fn_80233E40(i) != 1 && fn_8022B7C4(i) != 1) {
            continue;
        }
        dx = *(f32*)(this_ + 0xc) - fn_8023E724(i)->x;
        dy = *(f32*)(this_ + 0x10) - fn_8023E724(i)->y;

        if (tuSqrt(dx * dx + dy * dy) < lbl_805423FC) {
            f32 angle;
            *(f32*)(this_ + 0x264) = tuSqrt(dx * dx + dy * dy);
            angle = JMath::atanTable_.atan2_(-dx, -dy);
            angle *= lbl_80542418;
            *(s16*)(this_ + 0x268) = (s16)angle;
            *(s32*)(this_ + 0x270) = i;
            *(s32*)(this_ + 0x26c) = ClassifyBamAngleToQuadrant(*(u16*)(this_ + 0x268));
            return 1;
        }
    }
    return 0;
}

extern void* lbl_8053AAF8;
extern const f32 lbl_805423A8;
extern const f32 lbl_805423D0;
extern const f32 lbl_805423D4;
extern const f32 lbl_8054241C;
extern const f32 lbl_80542420;
extern const f32 lbl_80542424;
extern const f32 lbl_80542428;
extern "C" void fn_801F6758(void* pos, s32 room);
extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_802265FC(f32* pos, s32 room);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, u32 room, void* pos, u32 arg, s32 a, s32 b);

static inline f32 tuRandF() {
    u8* g = (u8*)lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    return *(f32*)&bits - lbl_805423A8;
}

static inline void tuSetVec(Vec* v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void tuSpawnFish(u8* self, f32 fx, f32 fy) {
    Vec pos;
    tuSetVec(&pos, fx + lbl_805423D0 * tuRandF(), fy + lbl_805423D0 * tuRandF(), lbl_805423A0);
    Actor_CreateByID(fn_801F856C(), 0x46495348, *(s32*)(self + 0x4), &pos, 0, -1, -1);
}

extern "C" s32 fn_803466C0(s32 param_1, s32 param_2, s32 param_3) {
    s32 r = (u16)fn_8022461C(param_3);
    if (r == 0xd || r == 0x3a) {
        return 0;
    }
    return 1;
}

#pragma opt_common_subs off
extern "C" void fn_80346704(Actor* this_) {
    u32 spawn = *(u32*)((u8*)this_ + 0x90);
    u16 tiles[713];
    register u8* self = (u8*)this_;
    u32 count;
    s32 room;
    s32 extra;
    s32 col;
    s32 n;
    s32 range;
    s32 w;
    s32 h;
    s32 v;
    s32 x;

    *(u32*)(self + 0x90) = spawn & 0xfff;
    extra = (spawn >> 12) & 0xff;
    range = (spawn >> 20) & 0xff;
    *(s32*)(self + 0x108) = 10000;
    *(f32*)(self + 0x60) = lbl_8054241C;
    *(f32*)(self + 0x64) = lbl_8054241C;
    *(f32*)(self + 0x68) = lbl_80542420;
    *(f32*)(self + 0x6c) = lbl_80542420;
    *(f32*)(self + 0x80) = lbl_8054241C;
    *(f32*)(self + 0x84) = lbl_8054241C;
    *(f32*)(self + 0x88) = lbl_80542420;
    *(f32*)(self + 0x8c) = lbl_80542420;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x244) = 0;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x234) = 0;
    *(s32*)(self + 0x238) = 0;
    *(s32*)(self + 0x23c) = 0;
    *(f32*)(self + 0x264) = lbl_805423A0;
    *(u16*)(self + 0x268) = 0;
    *(s32*)(self + 0x26c) = -1;
    *(s32*)(self + 0x270) = -1;
    fn_801F6758(self + 0xc, *(s32*)(self + 0x4));

    count = *(u32*)(self + 0x90);
    if (count != 0) {
        room = *(s32*)(self + 0x4);
        u8* mgr = fn_802D6A9C();
        f32* box;
        if (room < 8) {
            box = (f32*)(mgr + 0xcc);
        } else {
            box = (f32*)(mgr + 0xdc);
        }
        f32 x0 = box[0];
        f32 y0 = box[1];
        w = (s32)(box[2] - x0);
        h = (s32)(box[3] - y0);
        n = 0;
        x = 16;
        for (col = 1; x < w; col++, x += 16) {
            f32 fx = (f32)x + x0;
            v = col + 0x20;
            for (s32 y = 16; y < h; v += 0x20, y += 16) {
                f32 pos[2];
                pos[0] = fx;
                pos[1] = (f32)y + y0;
                s32 t = (u16)fn_802265FC(pos, *(s32*)(self + 0x4));
                if (t == 0xd || t == 0x3a) {
                    if (n >= 713) {
                        return;
                    }
                    tiles[n] = v;
                    n += 1;
                }
            }
        }
        if (n == 0) {
            return;
        }
        for (s32 k = 0; k < (s32)count;) {
            s32 idx = (s32)((f32)n * tuRandF());
            u16 t = tiles[idx];
            s32 num = extra + (s32)((f32)(range + 1) * tuRandF());
            if (!(tuRandF() > lbl_80542424 && (s32)count - k > num)) {
                num = 1;
            }
            f32 fx = (f32)((t & 0x1f) << 4) + x0;
            f32 fy = (f32)(((t >> 5) & 0x7ff) << 4) + y0;
            for (s32 j = 0; j < num; j++) {
                Vec pos;
                f32 ry = tuRandF();
                f32 rx = tuRandF();
                pos.z = lbl_805423A0;
                pos.y = lbl_805423D0 * ry + fy;
                pos.x = lbl_805423D0 * rx + fx;
                Actor_CreateByID(fn_801F856C(), 0x46495348, *(s32*)(self + 0x4), &pos, 0, -1, -1);
                k++;
            }
        }
    }

    *(s16*)(self + 0x250) = (s32)(lbl_80542428 * tuRandF());
    *(u16*)(self + 0x252) = *(u16*)(self + 0x250) + 0x4000;
    *(s32*)(self + 0x24c) = 0;
    *(s16*)(self + 0x250) = 0;
    *(f32*)(self + 0x25c) = lbl_805423A0;
    *(f32*)(self + 0x258) = lbl_805423A0;
    *(f32*)(self + 0x254) = lbl_805423A0;
    *(f32*)(self + 0x260) = lbl_805423D4;
    *(s32*)(self + 0x230) = 0;
}
#pragma opt_common_subs reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"

