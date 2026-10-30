#define Vec SDKVec
#include "JSystem/JGeometry/Vec.h"
#undef Vec
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/ActorDrawRec.h"
#include "Game/HitRect.h"


static inline void bombSetRotation(Mtx m, f32 sx, f32 sy, f32 sz,
                                  f32 cx, f32 cy, f32 cz, f32 s) {
    f32 ss;
    f32 cs;
    f32 cc;
    ss = sx * sy;
    cc = cx * cz;
    cs = cx * sz;
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * __fmsubs(ss, cz, cs);
    m[1][1] = s * __fmadds(ss, sz, cc);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * __fmadds(cc, sy, sx * sz);
    m[1][2] = s * __fmsubs(cs, sy, sx * cz);
    m[2][2] = s * (cx * cy);
}
class BombDrawActor : public Actor {
public:
    virtual void drawTexture(void* texture, DrawRec* rec, int mode, f32 x, f32 y, f32 z);
};
class BombResourceMgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getResource(u32 type, const char* name);
};
extern const char lbl_80471FBC[];
extern const char lbl_80471FCC[];
extern const char* lbl_804AC558[];
extern const f32 lbl_805422EC;
extern const f32 lbl_805422F0;
extern const f32 lbl_805422F4;
extern const f32 lbl_805422F8;
extern const f32 lbl_805422FC;
extern const f32 lbl_80542300;
extern const f32 lbl_80542304;
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* res, DrawRec* rec);

extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void* lbl_8053AAF8;
extern "C" void fn_8034335C(Actor* a, s32 room, f32* pos);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 flag, f32 a, f32 b);
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern "C" u8 fn_8022D75C(s32 i);
extern "C" u8 fn_80234ECC(s32 i);
extern "C" u8 fn_8023ED8C(s32 i);
extern "C" s32 fn_8023ECF0(s32 i);
extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_8022F478(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" u8 fn_8022B7C4(s32 i);
extern "C" u8 fn_802349EC(s32 i);
extern "C" void fn_80238548(s32 i, s32 b, f32* p, s32 d);
extern "C" void fn_802F601C(void* obj, f32* pos, f32 a, f32 b, s32 c, s32 d);
extern "C" void* fn_8013CC50(s32 room, f32* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
extern "C" void fn_801F0E34(Actor* a, u32 code, u32 z);
extern "C" void fn_801EE434(void* obj);
extern "C" void fn_8043E398(void* mgr, Vec* lo, Vec* hi);
extern "C" void* lbl_8053AED0;
static inline void bombSetSoundArea(JGeometry::TVec3f lo, JGeometry::TVec3f hi) {
    JGeometry::TVec3f a(lo);
    JGeometry::TVec3f b(hi);
    fn_8043E398(lbl_8053AED0, (Vec*)&a, (Vec*)&b);
}
extern const f32 lbl_80542308;
extern const f32 lbl_8054230C;
static inline void bombScaleHitBox(u8* p, f32 sx, f32 sy) {
    ((JGeometry::TBox2<f32>*)(p + 0x60))->set(lbl_8054230C * sx, lbl_8054230C * sy, lbl_80542308 * sx, lbl_80542308 * sy);
}
extern "C" void fn_8030C210(void* cam, void* pos);
static inline void bombNotifyCamera(void* cam, const JGeometry::TVec3f& pos) {
    fn_8030C210(cam, (void*)&pos);
}
extern "C" void* lbl_8053AB10;

extern "C" void fn_80341CB0(s32 id, f32* pos) {
    Actor_CreateByID(fn_801F856C(), 0x42424D42, id, pos, 0x30000, -1, -1);
}

extern "C" void fn_801EF830(s32 idx, f32* pos, DrawRec* p3, u32 mask, void* p5, u32 p6, s32 p7);
extern const f32 lbl_805422E8;
extern "C" void fn_80341D08(Actor* this_, s32 id, f32 x, f32 y, f32 z, const void* args, u32 mask) {
    u8* p = (u8*)this_;
    if (*(s32*)(p+4) != 0) return;
    if (*(u32*)(p+0x138) == 0) fn_801EF830(*(s32*)(p+4), (f32*)(p+0xc), (DrawRec*)args, mask, 0, 0, id);
    UnkDrawRec rec;
    *(u32*)&rec.field_10 = -1;
    *(u32*)&rec.field_14 = -1;
    for (u8 i=0; i<0x10; ++i) rec.field_00[i]=i;
    *(u32*)&rec.field_10 = -1;
    *(u32*)&rec.field_14 = 0;
    rec.field_18=0;
    rec.field_1C=0; rec.field_1D=0; rec.field_1E=0;
    rec.field_1F=1; rec.field_20=1; rec.field_21=0;
    rec.field_22=0; rec.field_23=0; rec.field_24=0; rec.field_25=0;
    rec.field_26=1; rec.field_28=3; rec.field_2C=1; rec.field_2D=0;
    rec.field_2E=0; rec.field_30=-1; rec.field_34=0; rec.field_38=2;
    if (*(s32*)(p+0xd8)>0) {
        if(args) rec=*(const UnkDrawRec*)args;
        s32 b=*(s32*)(p+0xdc);
        s32 a=*(s32*)(p+0xd8);
        u8 color;
        s32 lim=b-25;
        if(a>lim || b<25) {
            color=rec.field_14;
            rec.field_14 = color + (b<25 ? a*150/b : (a-lim)*150/25);
        }
        if(((JGeometry::TVec3f*)(p+0x3c))->squared()>lbl_805422E8) rec.field_30=8;
    } else if (*(s32*)(p+0x238)>0) {
        if(args) rec=*(const UnkDrawRec*)args;
        rec.field_14 += *(s32*)(p+0x238)*150/15;
        if(((JGeometry::TVec3f*)(p+0x3c))->squared()>lbl_805422E8) rec.field_30=8;
    } else {
        if(args) rec=*(const UnkDrawRec*)args;
        else rec.field_30=*(s32*)(p+0x150);
        if(*(u32*)(p+0x138)) rec.field_18=*(u32*)(p+0x138);
    }
    JGeometry::TVec3f pos;
    pos=*(JGeometry::TVec3f*)(p+0xc);
    pos.x+=x; pos.y+=y; pos.z+=z;
    if(*(s32*)(p+4)<8) fn_802F745C(*(void**)((u8*)lbl_8053AB10+0x20),&pos,(void*)id,(DrawRec*)&rec);
}

extern "C" void fn_80342368(Actor* actor) {
    u8* p = (u8*)actor;
    if (*(s32*)(p + 0x230) == 2 || *(s32*)(p + 0x230) == 7) return;
    s32 n = *(s32*)(p + 0x234) / 60 + 1;
    f32 zero;
    f32 scaleX;
    f32 ss;
    f32 cz;
    f32 cs;
    f32 cc;
    f32 cx, cy, sx, sy, sz;
    f32 height;
    DrawRec rec;
    Mtx mtx;
    PSMTXIdentity(mtx);
    zero = lbl_805422EC;
    scaleX = *(f32*)(p + 0x254);
    JGeometry::TVec3f saved = *(JGeometry::TVec3f*)(p + 0xc);
    if (zero == scaleX) return;
    f32 scaleY, scaleZ;
    scaleZ = *(f32*)(p + 0x25c);
    scaleY = *(f32*)(p + 0x258);
    mtx[0][0] = scaleX;
    mtx[0][1] = zero;
    mtx[0][2] = zero;
    mtx[1][0] = zero;
    mtx[1][1] = scaleY;
    mtx[1][2] = zero;
    mtx[2][0] = zero;
    mtx[2][1] = zero;
    mtx[2][2] = scaleZ;
    rec.w18 = mtx;
    if (*(s32*)(p + 0x230) >= 5) {
        rec.b1d = 0;
        rec.b1c = 0;
    } else {
        rec.b1d = 1;
        rec.b1c = 1;
    }
    rec.b2d = 1;
    s32 mode = 7;
    if (*(s32*)(p + 0x230) == 3) mode = -1;
    *(f32*)(p + 0x10) += lbl_805422F0;
    if (0.0f != *(f32*)(p + 0x2c) && 0.0f != *(f32*)(p + 0x14) && *(s32*)(p + 0x24c) == 0) {
        height = (lbl_805422F4 * (-*(f32*)(p + 0x25c) / lbl_805422F8)) *
            (*(f32*)(p + 0x14) / *(f32*)(p + 0x2c)) -
            lbl_805422FC * ((*(f32*)(p + 0x2c) - *(f32*)(p + 0x14)) / *(f32*)(p + 0x2c));
    } else {
        height = lbl_80542300;
    }
    if (*(s32*)(p + 0x23c) == 1) ((u8*)&rec)[0x14] = 150;
    if (*(s32*)(p + 0x230) == 6 && n < 10) {
        void* texture = (*(BombResourceMgr**)((u8*)lbl_8053AAF8 + 0xa4))->getResource('TIMG', lbl_80471FBC);
        ((BombDrawActor*)actor)->drawTexture(texture, &rec, mode, 0.0f, height - lbl_805422F0, 0.0f);
    } else {
        void* texture = (*(BombResourceMgr**)((u8*)lbl_8053AAF8 + 0xa4))->getResource('TIMG', lbl_80471FCC);
        ((BombDrawActor*)actor)->drawTexture(texture, &rec, mode, 0.0f, height - lbl_805422F0, 0.0f);
    }
    *(JGeometry::TVec3f*)(p + 0xc) = saved;
    if (*(s32*)(p + 0x230) == 6 && n < 10) {
        mtx[0][3] = lbl_805422EC;
        mtx[1][3] = lbl_805422EC;
        mtx[2][3] = lbl_805422EC;
        sx = sin(lbl_805422EC);
        sy = sin(lbl_805422EC);
        sz = sin(lbl_805422EC);
        cx = cos(lbl_805422EC);
        cy = cos(lbl_805422EC);
        cz = cos(lbl_805422EC);
        cc = cx * cz;
        ss = sx * sy;
        cs = cx * sz;
        mtx[0][0] = lbl_80542304 * (cy * cz);
        mtx[1][0] = lbl_80542304 * (cy * sz);
        mtx[2][0] = lbl_80542304 * -sy;
        mtx[0][1] = lbl_80542304 * (ss * cz - cs);
        mtx[1][1] = lbl_80542304 * (ss * sz + cc);
        mtx[2][1] = lbl_80542304 * (sx * cy);
        mtx[0][2] = lbl_80542304 * (cc * sy + sx * sz);
        mtx[1][2] = lbl_80542304 * (cs * sy - sx * cz);
        mtx[2][2] = lbl_80542304 * (cx * cy);
        rec.w18 = mtx;
        rec.b2c = 0;
        void* res = fn_804030C4('TIMG', lbl_804AC558[n]);
        if (*(s32*)(p + 4) < 8) fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), p + 0xc, res, &rec);
    }
}

extern "C" void fn_8043E398(void* mgr, Vec* lo, Vec* hi);
extern "C" void fn_802397B4(void* box, u32 room, s32 h);
extern "C" int fn_801F3D94(Actor* a, s32 b);
extern "C" s32 fn_801A4D1C(s32 h, HitBox* box, JGeometry::TVec2<f32>* pos);
extern "C" s32 fn_801A6108(s32 h, HitBox* box, JGeometry::TVec2<f32>* pos);
extern "C" s32 fn_801A4F5C(s32 h, HitBox* box, JGeometry::TVec2<f32>* pos);
extern "C" s32 fn_801A46FC(s32 h, HitBox* box, JGeometry::TVec2<f32>* pos);
extern "C" u8 fn_801F305C(Actor* a);
extern "C" void fn_801F3604(Actor* a);
extern "C" void fn_80458FF0(void* mgr, u32 id, s32 a, s32 b);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 a, s32 b);
extern "C" void fn_801F2B7C(Actor* a, s32 b, s32 c, s32 d);
extern "C" void fn_801F2B20(Actor* a, s32 b);
extern "C" u8* fn_8020D58C(void);
extern "C" void fn_8020D7D0(void* entry, s32 h);
extern "C" void fn_8013CB44(void* emitter, void* pos, s32 a, s32 b, s32 c);
extern "C" void fn_8030C210(void* cam, void* pos);
extern "C" void* lbl_8053AED0;
extern "C" u8* lbl_8053AF80;
extern const f32 lbl_80542308;
extern const f32 lbl_8054230C;
extern const f32 lbl_80542310;
extern const f32 lbl_80542314;
extern const f32 lbl_80542318;
extern const f32 lbl_8054231C;
extern const f32 lbl_80542320;
extern const f32 lbl_80542324;
extern const f32 lbl_80542328;
extern const f32 lbl_8054232C;
extern const f32 lbl_80542330;
extern const f32 lbl_80542334;
extern const f32 lbl_80542338;
extern const f32 lbl_8054233C;
extern "C" void fn_80342850(Actor* a) {
    u8* p = (u8*)a;
    HitBox box;
    JGeometry::TVec2<f32> xy;
    box.set(*(HitBox*)(p + 0x60));
    xy.set(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    box.addPos(xy);
    *(s32*)(p + 0x108) = 10000;
    if (*(s32*)(p + 0x230) == 4) {
        ((JGeometry::TVec3f*)(p + 0xc))->add(*(JGeometry::TVec3f*)(p + 0x3c));
    }
    if (*(s32*)(p + 0x234) > 0) {
        *(s32*)(p + 0x234) = *(s32*)(p + 0x234) - 1;
    }
    if (*(s32*)(p + 0x230) != 2) {
        JGeometry::TVec3f lo = *(JGeometry::TVec3f*)(p + 0xc);
        JGeometry::TVec3f hi = *(JGeometry::TVec3f*)(p + 0xc);
        lo.x += *(f32*)(p + 0x60);
        lo.y += *(f32*)(p + 0x64);
        hi.x += *(f32*)(p + 0x68);
        hi.y += *(f32*)(p + 0x6c);
        bombSetSoundArea(lo, hi);
    }
    if (*(s32*)(p + 0x230) == 6 && *(s32*)(p + 0x234) > 0) {
        fn_802397B4(&box, *(u32*)(p + 4), *(s32*)(p + 0x198));
        if (*(s32*)(p + 0x238) > 0) {
            *(s32*)(p + 0x238) = *(s32*)(p + 0x238) - 1;
        }
        if (fn_801F3D94(a, 0) == 0 && *(s32*)(p + 0x238) <= 0) {
            *(u32*)(p + 0xb0) = 0x41304;
            s32 n0 = fn_801A4D1C(*(s32*)(p + 0x198), &box, &xy);
            s32 n1 = fn_801A6108(*(s32*)(p + 0x198), &box, &xy);
            s32 n2 = fn_801A4F5C(*(s32*)(p + 0x198), &box, &xy);
            s32 n3 = fn_801A46FC(*(s32*)(p + 0x198), &box, &xy);
            if (fn_801F305C(a) || n0 > 0 || n1 > 0 || n2 > 0 || n3 > 0) {
                *(s32*)(p + 0x234) -= 60;
                *(s32*)(p + 0x238) = 15;
                return;
            }
            *(u32*)(p + 0xb0) = 0;
        }
    } else if (*(s32*)(p + 0x230) == 5) {
        s32 k = (15 - *(s32*)(p + 0x234)) / 15;
        HitBox r(*(f32*)(p + 0x60) * k, *(f32*)(p + 0x64) * k, *(f32*)(p + 0x68) * k, *(f32*)(p + 0x6c) * k);
        fn_802397B4(&r, *(u32*)(p + 4), *(s32*)(p + 0x198));
    }
    switch (*(u32*)(p + 0x230)) {
    case 0: {
        f32 lo = lbl_8054230C;
        f32 hi = lbl_80542308;
        f32 one = lbl_805422F8;
        *(f32*)(p + 0x254) += one / (f32)*(s32*)(p + 0x244);
        *(f32*)(p + 0x258) = *(f32*)(p + 0x254);
        *(f32*)(p + 0x25c) = *(f32*)(p + 0x254);
        ((HitBox*)(p + 0x60))->set(lo * *(f32*)(p + 0x254), lo * *(f32*)(p + 0x258),
                                   hi * *(f32*)(p + 0x254), hi * *(f32*)(p + 0x258));
        if (*(f32*)(p + 0x254) >= one) {
            *(f32*)(p + 0x254) = one;
            *(f32*)(p + 0x258) = one;
            *(f32*)(p + 0x25c) = one;
            *(f32*)(p + 0x60) = lbl_80542310;
            *(f32*)(p + 0x64) = lbl_80542310;
            *(f32*)(p + 0x68) = lbl_80542314;
            *(f32*)(p + 0x6c) = lbl_80542314;
            *(s32*)(p + 0x234) = 8;
            *(s32*)(p + 0x230) = 1;
        }
        *(HitBox*)(p + 0x80) = *(HitBox*)(p + 0x60);
        *(HitBox*)(p + 0x70) = *(HitBox*)(p + 0x60);
        break;
    }
    case 1:
        if (*(s32*)(p + 0x234) <= 0) {
            *(f32*)(p + 0x44) = lbl_80542318;
            *(s32*)(p + 0x230) = 4;
        }
        break;
    case 2:
        if ((u8)a->v11() == 1 || a->v13() == 0) {
            if (*(s32*)(p + 0x24c) == 1 && *(s32*)((u8*)fn_802D6A9C() + 4) == 1 &&
                *(s32*)((u8*)fn_802D6A9C() + 8) == 0) {
                fn_801F3604(a);
            }
            *(s32*)(p + 0x230) = 4;
            *(u32*)(p + 0x250) = *(u32*)(lbl_8053AF80 + 0x58);
        }
        break;
    case 3:
        break;
    case 4:
        if (*(f32*)(p + 0x14) <= 0.0f) {
            fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 4), 0, lbl_8054231C, 0.0f);
            JGeometry::TVec3f v = *(JGeometry::TVec3f*)(p + 0xc);
            v.y += lbl_80542320;
            fn_8013CC50(*(s32*)(p + 4), (f32*)&v, 0x3cf, 0, -1, 0, 0, 1, lbl_80542324);
            fn_801F0E34(a, 0x3000f, 0);
            if (*(u8*)(p + 0x261) == 1) {
                fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
            }
            *(f32*)(p + 0x44) = 0.0f;
            *(s32*)(p + 0x234) = 15;
            if (*(s32*)(p + 0x248) == 0) {
                fn_8043D67C(lbl_8053AED0, 0x1a8, 0, 0);
            } else if (*(s32*)(p + 0x248) == 1) {
                fn_8043D67C(lbl_8053AED0, 0x1c1, 0, 0);
            }
            *(s32*)(p + 0x230) = 5;
        } else {
            *(f32*)(p + 0x44) -= lbl_80542328;
            if (*(s32*)(p + 0x24c) != 2) {
                fn_801F2B7C(a, 1, -1, 2);
                fn_801F2B20(a, 0);
            }
        }
        break;
    case 5:
        if (*(s32*)(p + 0x234) <= 0) {
            *(s32*)(p + 0x234) = 600;
            JGeometry::TVec3f v = *(JGeometry::TVec3f*)(p + 0xc);
            v.y -= lbl_8054232C;
            if (*(void**)(p + 0x264) == NULL) {
                *(void**)(p + 0x264) = fn_8013CC50(*(s32*)(p + 4), (f32*)&v, 0x39, 1, 1, 0, 0, 1, lbl_805422E8);
            }
            if (*(void**)(p + 0x268) == NULL) {
                *(void**)(p + 0x268) = fn_8013CC50(*(s32*)(p + 4), (f32*)&v, 0x3a, 1, 1, 0, 0, 1, lbl_805422E8);
            }
            *(f32*)(p + 0x254) = lbl_805422F8;
            *(f32*)(p + 0x258) = lbl_805422F8;
            *(f32*)(p + 0x25c) = lbl_805422F8;
            *(s32*)(p + 0x230) = 6;
        } else {
            fn_801F2B7C(a, 1, -1, 2);
            fn_801F2B20(a, 0);
            s32 t = *(s32*)(p + 0x234);
            if (t > 10) {
                *(f32*)(p + 0x254) = lbl_805422F8 * (lbl_805422E8 + lbl_80542328 * (15 - t) / lbl_80542330);
                *(f32*)(p + 0x258) = lbl_805422F8 * (lbl_805422E8 - lbl_80542328 * (15 - *(s32*)(p + 0x234)) / lbl_80542330);
                *(f32*)(p + 0x25c) = lbl_805422F8 * (lbl_805422E8 - lbl_80542328 * (15 - *(s32*)(p + 0x234)) / lbl_80542330);
            } else if (t > 0) {
                *(f32*)(p + 0x254) = lbl_805422F8 * (lbl_805422E8 + lbl_80542328 * t / lbl_805422F0);
                *(f32*)(p + 0x258) = lbl_805422F8 * (lbl_805422E8 - lbl_80542328 * *(s32*)(p + 0x234) / lbl_805422F0);
                *(f32*)(p + 0x25c) = lbl_805422F8 * (lbl_805422E8 - lbl_80542328 * *(s32*)(p + 0x234) / lbl_805422F0);
            }
        }
        break;
    case 6: {
        s32 room = *(s32*)(p + 0x198);
        u8* g = fn_8020D58C();
        fn_8020D7D0(g + 4 + g[0] * 0x784, room);
        fn_801F0E34(a, 0x50026, 0);
        if (*(s32*)(p + 0x234) <= 0) {
            fn_801EE434(*(void**)(p + 0x264));
            fn_801EE434(*(void**)(p + 0x268));
            fn_8034335C(a, *(s32*)(p + 4), (f32*)(p + 0xc));
            *(s32*)(p + 0x230) = 7;
            *(s32*)(p + 0x234) = 3;
        } else {
            JGeometry::TVec3f v;
            v = JGeometry::TVec3f(lbl_8054233C + *(f32*)(p + 0xc),
                                  *(f32*)(p + 0x10) - (lbl_80542334 + lbl_8054231C * *(s32*)(p + 0x234) / lbl_80542338),
                                  *(f32*)(p + 0x14));
            if (*(void**)(p + 0x264) != NULL) {
                fn_8013CB44(*(void**)(p + 0x264), &v, 1, 1, 1);
            }
            if (*(void**)(p + 0x268) != NULL) {
                fn_8013CB44(*(void**)(p + 0x268), &v, 1, 1, 1);
            }
        }
        break;
    }
    case 7: {
        f32 nx;
        f32 ny;
        ny = -*(f32*)(p + 0x10);
        nx = -*(f32*)(p + 0xc);
        *(HitBox*)(p + 0x60) = *(HitBox*)((u8*)fn_802D6A9C() + 0xcc);
        *(f32*)(p + 0x60) += nx;
        *(f32*)(p + 0x64) += ny;
        *(f32*)(p + 0x68) += nx;
        *(f32*)(p + 0x6c) += ny;
        fn_801F2B20(a, 5);
        if (*(s32*)(p + 0x234) <= 0) {
            if (*(s32*)(p + 0x24c) == 1 && *(s32*)((u8*)fn_802D6A9C() + 4) == 1 &&
                *(s32*)((u8*)fn_802D6A9C() + 8) == 0) {
                a->detach();
            } else {
                *(u8*)(p + 0x11c) = 0;
            }
        }
        break;
    }
    }
    if (*(s32*)(p + 0x230) != 2) {
        bombNotifyCamera(*(void**)((u8*)lbl_8053AB10 + 0x24),
                         JGeometry::TVec3f(*(f32*)(p + 0xc), *(f32*)(p + 0x10) - *(f32*)(p + 0x14), 0.0f));
    }
    if (*(s32*)(p + 0x234) < 300 && *(s32*)(p + 0x230) == 6) {
        *(s32*)(p + 0x240) += 1;
        if (*(s32*)(p + 0x234) < 120 && (*(s32*)(p + 0x240) & 1)) {
            *(s32*)(p + 0x240) += 1;
        }
        *(s32*)(p + 0x240) &= 7;
        if (*(s32*)(p + 0x240) == 0) {
            *(s32*)(p + 0x23c) ^= 1;
        }
    }
}

extern "C" void fn_8034335C(Actor* p, s32 room, f32* pos) {
    u8 flags[4];
    s32 i;

    fn_802D79E8(fn_802D6A9C(), room, 0, 1.0f, 0.0f);
    fn_80134DE4(lbl_8053AAF8, 3, 0);
    flags[0] = 0;
    flags[1] = 0;
    flags[2] = 0;
    flags[3] = 0;
    for (i = 0; i < 4; i++) {
        if (fn_8022D75C(i) == 1 && fn_80234ECC(i) == 0) {
            flags[i] = 1;
            if (fn_8023ED8C(i) == 1) {
                flags[fn_8023ECF0(i)] = 1;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (fn_8023F264(i) != 0 && fn_8022F478(i) == 0) {
            if (fn_8023DE58(i) < 8) {
                if (fn_80230188(i) == 0 && fn_8022B7C4(i) == 0 && fn_802349EC(i) == 0 && flags[i] == 0) {
                    fn_80238548(i, 0x20, pos, 0x13);
                }
            }
        }
    }
    if (room < 8) {
        fn_802F601C(*(void**)((u8*)lbl_8053AB10 + 0x20), pos, 1.0f, 1.0f, 6, 0);
    }
    fn_8013CC50(room, pos, 0x33, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x34, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x35, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x36, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x37, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x38, 1, 1, 0, 0, 1, 1.0f);
    fn_801F0E34(p, 0x30001, 0);
}

extern "C" void fn_803435F8(Actor* p) {
    *(u32*)((u8*)p + 0x244) = *(u32*)((u8*)p + 0x90) & 0xfff;
    *(u32*)((u8*)p + 0x118) = 0x80;
    *(u32*)((u8*)p + 0x230) = 0;
    *(u32*)((u8*)p + 0x23c) = 0;
    *(u32*)((u8*)p + 0x240) = 0;
    *(u32*)((u8*)p + 0x234) = 0;
    *(u8*)((u8*)p + 0x260) = 0;
    *(u32*)((u8*)p + 0x238) = 0;
    *(u32*)((u8*)p + 0x248) = (*(u32*)((u8*)p + 0x90) >> 12) & 3;
    *(u32*)((u8*)p + 0x24c) = (*(u32*)((u8*)p + 0x90) >> 16) & 0xf;
    *(u8*)((u8*)p + 0x261) = 0;
    *(u32*)((u8*)p + 0x250) = 0x100000d;
    *(u32*)((u8*)p + 0x108) = 10000;
    *(f32*)((u8*)p + 0x80) = -24.0f;
    *(f32*)((u8*)p + 0x84) = -24.0f;
    *(f32*)((u8*)p + 0x88) = 24.0f;
    *(f32*)((u8*)p + 0x8c) = 24.0f;
    *(f32*)((u8*)p + 0x60) = -24.0f;
    *(f32*)((u8*)p + 0x64) = -24.0f;
    *(f32*)((u8*)p + 0x68) = 24.0f;
    *(f32*)((u8*)p + 0x6c) = 24.0f;
    *(f32*)((u8*)p + 0x70) = -24.0f;
    *(f32*)((u8*)p + 0x74) = -24.0f;
    *(f32*)((u8*)p + 0x78) = 24.0f;
    *(f32*)((u8*)p + 0x7c) = 24.0f;
    *(f32*)((u8*)p + 0x254) = 0.75f;
    *(f32*)((u8*)p + 0x258) = 0.75f;
    *(f32*)((u8*)p + 0x25c) = 0.75f;
    switch (*(u32*)((u8*)p + 0x24c)) {
    case 0:
        *(f32*)((u8*)p + 0x80) = 0.0f;
        *(f32*)((u8*)p + 0x84) = 0.0f;
        *(f32*)((u8*)p + 0x88) = 0.0f;
        *(f32*)((u8*)p + 0x8c) = 0.0f;
        *(f32*)((u8*)p + 0x60) = 0.0f;
        *(f32*)((u8*)p + 0x64) = 0.0f;
        *(f32*)((u8*)p + 0x68) = 0.0f;
        *(f32*)((u8*)p + 0x6c) = 0.0f;
        *(f32*)((u8*)p + 0x70) = 0.0f;
        *(f32*)((u8*)p + 0x74) = 0.0f;
        *(f32*)((u8*)p + 0x78) = 0.0f;
        *(f32*)((u8*)p + 0x7c) = 0.0f;
        *(f32*)((u8*)p + 0x25c) = 0.0f;
        *(f32*)((u8*)p + 0x258) = 0.0f;
        *(f32*)((u8*)p + 0x254) = 0.0f;
        break;
    case 1:
        *(f32*)((u8*)p + 0x14) = 400.0f;
        *(u32*)((u8*)p + 0x230) = 2;
        if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
            *(u8*)((u8*)p + 0x261) = 1;
        }
        break;
    case 2:
        *(u32*)((u8*)p + 0x230) = 3;
        if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
            *(u8*)((u8*)p + 0x261) = 1;
        }
        break;
    case 3:
        fn_8034335C(p, *(u32*)((u8*)p + 0x4), (f32*)((u8*)p + 0xc));
        *(u32*)((u8*)p + 0x230) = 7;
        *(u32*)((u8*)p + 0x234) = 3;
        break;
    }
    *(u32*)((u8*)p + 0x264) = 0;
    *(u32*)((u8*)p + 0x268) = 0;
}

extern "C" char lbl_804AC588[];
extern "C" void fn_801EE434(void* obj);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dt__5ActorFv(Actor* self, s32 flag);
extern "C" Actor* fn_803437B0(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AC588;
        fn_801EE434(*(void**)((u8*)p + 0x264));
        fn_801EE434(*(void**)((u8*)p + 0x268));
        if (((u8*)p)[0x261] == 1) {
            s32 kind = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
            if (kind != 9 && kind != 0xb) {
                fn_80138B7C(lbl_8053AAF8);
            }
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

void fn_8034384C(void) {
}

