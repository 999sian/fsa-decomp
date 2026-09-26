// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A8194-801A908C (HBB2). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"
#include <math.h>

static inline f64 sqrtStep(f64 tmpd, f32 mag) {
    return tmpd * 0.5 * (3.0 - mag * (tmpd * tmpd));
}
static inline f32 dolsqrtfull(f32 mag) {
    if (mag > 0.0f) {
        f64 tmpd = __frsqrte(mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        return mag * tmpd;
    } else if (mag < 0.0) {
        return NAN;
    } else if (fpclassify(mag) == 1) {
        return NAN;
    } else {
        return mag;
    }
}
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

// from src/Game/fn_801A8194_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* __vt__4HBB2[];

extern "C" void* fn_801A8194(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4HBB2;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct Hbb2Vec { f32 x, y, z; };
struct Hbb2 { u8 pad0[0xc]; Hbb2Vec pos; u8 pad18[0x27c - 0x18]; Hbb2Vec prev; Hbb2Vec prev2; Hbb2Vec trail[40]; };


extern const char lbl_80468518[];
extern "C" void fn_801F02BC(void* actor, const char* file, s32 idx, f32 sx, f32 sy, DrawRec* rec, s32 a, s32 b, s32 c);

struct Hbb2Mtx {
    Hbb2Mtx() {
        m[0][3] = 0.0f;
        m[1][3] = 0.0f;
        m[2][3] = 0.0f;
    }
    void setScale(f32 s) {
        m[0][0] = s;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = s;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = s;
    }
    f32 m[3][4];
};

struct Hbb2VT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 check();
};

// HBB2 draw: body plus a fading trail of 39 afterimages.
extern "C" void fn_801A81F4(char* this_) {
    DrawRec rec;
    Hbb2Mtx mtx;
    if (*(s32*)(this_ + 0x258) == 0 && (*(u32*)(this_ + 0x90) >> 27) != 0) {
        if (!((Hbb2VT*)this_)->check()) {
            return;
        }
    }
    rec.ids[4] = 3;
    rec.b1d = 2;
    mtx.setScale(*(f32*)(this_ + 0x26c));
    rec.w18 = &mtx;
    fn_801F02BC(this_, lbl_80468518, *(s32*)(this_ + 0x260) + 0x155, 1.0f, 1.0f, &rec, 7, 0, 0);
    f32 sx, sy, sz;
    f32 scale = *(f32*)(this_ + 0x26c);
    f32 alpha = *(f32*)(this_ + 0x274);
    s32 frame = *(s32*)(this_ + 0x260);
    Hbb2* h = (Hbb2*)this_;
    rec.ids[4] = 5;
    rec.b1d = 1;
    sx = h->pos.x;
    sy = h->pos.y;
    sz = h->pos.z;
    for (s32 i = 1; i < 40; i++) {
        if (h->trail[i].z) {
            scale *= 0.95f;
            if (scale < 0.5f) {
                scale = 0.5f;
            }
            alpha -= 2.0f;
            if (alpha < 0.0f) {
                alpha = 0.0f;
            }
            ((u8*)&rec.w10)[3] = (s32)alpha;
            mtx.setScale(scale);
            rec.w18 = &mtx;
            if (--frame < 0) {
                frame = 2;
            }
            h->pos.x = h->trail[i].x;
            h->pos.y = h->trail[i].y;
            h->pos.z = h->trail[i].z;
            fn_801F02BC(this_, lbl_80468518, frame + 0x155, 1.0f, 1.0f, &rec, 7, 0, 0);
        }
    }
    h->pos.x = sx;
    h->pos.y = sy;
    h->pos.z = sz;
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* mgr);
extern "C" void fn_801EEC98(void* self, s32 room, u16* ang, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" Hbb2Vec* fn_8023E724(s32 idx);
extern "C" u8 fn_801F2B7C(void* self, s32 a, s32 holder, s32 b);
extern "C" void fn_801F71A4(f32* v, f32 target, f32 rate, f32 step);
extern "C" s32 fn_801F3D94(void* self, s32 a);
extern "C" s32 fn_801F285C(void* self, s32 a, s32 b, s32 c, s32 idx);
extern "C" s32 fn_80138A30(void* game);
extern "C" s32 fn_8022CAF8(s32 player);
extern "C" u8 fn_801F2FAC(void* self);
extern "C" void fn_801F0E34(void* self, u32 se, s32 b);
extern "C" void* fn_801F856C(void);
extern "C" void fn_801F8544(void* mgr, u32 tag, s32 room, Hbb2Vec* pos, s32 flags);
extern void* lbl_8053AAF8;

struct Hbb2VT2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void kill();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 check();
};

static inline f32 hbbSin(s16 v) { return JMath::sincosTable_.mTable[static_cast<u16>(v) >> (16U - 11)].first; }
static inline f32 hbbCos(s16 v) { return JMath::sincosTable_.mTable[static_cast<u16>(v) >> (16U - 11)].second; }

// HBB2 update.
extern "C" void fn_801A8554(char* this_) {
    Hbb2* h = (Hbb2*)this_;
    s32 i;
    s32 player = -1;
    if (*(s32*)(this_ + 0x258) == 0 && (*(u32*)(this_ + 0x90) >> 27) != 0) {
        if (!((Hbb2VT2*)this_)->check()) {
            return;
        }
        *(s32*)(this_ + 0x258) = 1;
    }
    if (fn_802DCD0C(fn_802D6A9C())) {
        if (*(s32*)(this_ + 0x25c) == 1) {
            *(u8*)(this_ + 0x11c) = 0;
            return;
        }
    } else {
        *(s32*)(this_ + 0x25c) = 1;
    }
    fn_801EEC98(this_, *(s32*)(this_ + 0x198), 0, 0, 0, &player, 0, 1);
    if (*(s32*)(this_ + 0x230) == 1 && *(s32*)(this_ + 0x238) == 0) {
        *(JGeometry::TVec3f*)&h->trail[0] = *(JGeometry::TVec3f*)&h->pos;
        for (i = 39; i > 0; i--) {
            h->trail[i].x = h->trail[i - 1].x;
            h->trail[i].y = h->trail[i - 1].y;
            h->trail[i].z = h->trail[i - 1].z;
        }
        *(s32*)(this_ + 0x238) = 3;
    }
    if (*(s32*)(this_ + 0x264) > 0) {
        f32 sx = h->pos.x;
        f32 sy = h->pos.y;
        f32 sz = h->pos.z;
        *(f32*)(this_ + 0x60) = -2.0f;
        *(f32*)(this_ + 0x64) = -2.0f;
        *(f32*)(this_ + 0x68) = 2.0f;
        *(f32*)(this_ + 0x6c) = 2.0f;
        for (i = 39; i > 0; i--) {
            if (player >= 0) {
                f32 dx = fn_8023E724(player)->x - h->trail[i].x;
                f32 dy = fn_8023E724(player)->y - (h->trail[i].y - h->trail[i].z);
                Hbb2Vec* pp = fn_8023E724(player);
                h->prev2.x = pp->x;
                h->prev2.y = pp->y;
                h->prev2.z = pp->z;
                if (dolsqrtfull(dx * dx + dy * dy) < 16.0f) {
                    f32 ty = h->trail[i].y;
                    h->pos.x = h->trail[i].x;
                    h->pos.y = ty;
                    h->pos.z = 0.0f;
                    fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 5);
                }
            }
        }
        *(f32*)(this_ + 0x60) = -10.0f;
        *(f32*)(this_ + 0x64) = -10.0f;
        *(f32*)(this_ + 0x68) = 10.0f;
        *(f32*)(this_ + 0x6c) = 10.0f;
        h->pos.x = sx;
        h->pos.y = sy;
        h->pos.z = sz;
    }
    if (*(s32*)(this_ + 0x230) == 2) {
        fn_801F71A4((f32*)(this_ + 0x274), 0.0f, 0.3f, 5.0f);
    }
    if (fn_801F3D94(this_, 0) != 0) {
        return;
    }
    if (*(s32*)(this_ + 0x264) > 0) {
        for (i = 0; i < 4; i++) {
            s32 pl = fn_801F285C(this_, 0, 0, 1, i);
            if (pl >= 0
                && (fn_80138A30(lbl_8053AAF8) > 1 || fn_8022CAF8(pl) == 1 || fn_8022CAF8(pl) == 0)
                && fn_801F2FAC(this_)) {
                *(s32*)(this_ + 0x264) -= 10000 - *(s32*)(this_ + 0x108);
                if (*(s32*)(this_ + 0x264) <= 0) {
                    fn_801F0E34(this_, 0x40003, 0);
                    *(s32*)(this_ + 0x264) = 0;
                    *(s32*)(this_ + 0x230) = 2;
                } else {
                    fn_801F0E34(this_, 0x40002, 0);
                    *(s32*)(this_ + 0x230) = 0;
                }
                return;
            }
        }
    }
    if (*(s32*)(this_ + 0x264) > 0 && *(s32*)(this_ + 0x230) != 0) {
        fn_801F71A4(&h->pos.x, h->prev.x, 1.0f, *(f32*)(this_ + 0x278));
        fn_801F71A4(&h->pos.y, h->prev.y, 1.0f, *(f32*)(this_ + 0x278));
        fn_801F71A4((f32*)(this_ + 0x278), 10.0f, 0.3f, 1.0f);
    }
    fn_801F71A4(&h->pos.z, h->prev.z, 0.3f, 1.0f);
    h->prev.z = 16.0f;
    fn_801F2B7C(this_, -100, -1, 1);
    fn_801F0E34(this_, 0x400ec, 0);
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        fn_801F0E34(this_, 0x4000f, 0);
        fn_801F0E34(this_, 0x400a9, 0);
        if (player >= 0) {
            fn_801EEC98(this_, *(s32*)(this_ + 0x198), (u16*)(this_ + 0x268), 0, 0, 0, player, 2);
            *(u16*)(this_ + 0x268) += 0x8000;
        }
        *(s32*)(this_ + 0x230) = 1;
        // fallthrough
    case 1:
        if (player >= 0) {
            h->prev.x = *(f32*)(this_ + 0x270) * hbbSin(*(u16*)(this_ + 0x268)) + fn_8023E724(player)->x;
            f32 py = fn_8023E724(player)->y;
            h->prev.y = *(f32*)(this_ + 0x270) * hbbCos(*(u16*)(this_ + 0x268)) + py;
        } else {
            h->prev.x = *(f32*)(this_ + 0x270) * hbbSin(*(u16*)(this_ + 0x268)) + h->prev2.x;
            h->prev.y = *(f32*)(this_ + 0x270) * hbbCos(*(u16*)(this_ + 0x268)) + h->prev2.y;
        }
        h->prev.y += 16.0f;
        *(u16*)(this_ + 0x268) += 0x200;
        if (*(s32*)(this_ + 0x234) <= 0) {
            (*(s32*)(this_ + 0x260))++;
            if (*(s32*)(this_ + 0x260) > 2) {
                *(s32*)(this_ + 0x260) = 0;
            }
            *(s32*)(this_ + 0x234) = 6;
        }
        break;
    case 2:
        if (*(f32*)(this_ + 0x274) < 1.0f) {
            for (i = 0; i < 40; i++) {
                fn_801F8544(fn_801F856C(), 'RUPY', *(s32*)(this_ + 0x4), &h->trail[i], 0);
            }
            ((Hbb2VT2*)this_)->kill();
        }
        break;
    }
    for (i = 0; i < 3; i++) {
        s32* t = (s32*)(this_ + i * 4);
        if (t[0x234 / 4] > 0) {
            t[0x234 / 4]--;
        }
    }
}

// HBB2 init (vtable slot 1)
extern "C" void fn_801A8CB8(char* this_) {
    *(f32*)(this_ + 0x60) = -10.0f;
    *(f32*)(this_ + 0x64) = -10.0f;
    *(f32*)(this_ + 0x68) = 10.0f;
    *(f32*)(this_ + 0x6c) = 10.0f;
    *(f32*)(this_ + 0x80) = 0.0f;
    *(f32*)(this_ + 0x84) = 0.0f;
    *(f32*)(this_ + 0x88) = 0.0f;
    *(f32*)(this_ + 0x8c) = 0.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(f32*)(this_ + 0x270) = 72.0f;
    *(u8*)(this_ + 0x11e) = 1;
    *(f32*)(this_ + 0x26c) = 1.2f;
    *(f32*)(this_ + 0x274) = 255.0f;
    Hbb2* h = (Hbb2*)this_;
    h->prev.x = h->pos.x;
    h->prev.y = h->pos.y;
    h->prev.z = h->pos.z;
    h->prev2.x = h->pos.x;
    h->prev2.y = h->pos.y;
    h->prev2.z = h->pos.z;
    for (int i = 0; i < 40; i++) {
        h->trail[i].x = h->pos.x;
        h->trail[i].y = h->pos.y;
        h->trail[i].z = h->pos.z;
    }
    *(s16*)(this_ + 0x268) = 0;
    *(s32*)(this_ + 0x190) = 0;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(s32*)(this_ + 0x264) = *(s32*)(this_ + 0x108);
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
