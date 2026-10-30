#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/Inline.h"
#include "Game/TlwpDrawParam.h"
extern "C" u8 fn_8022F514(s32);
extern "C" void fn_802372F8(s32,s32,s32);
extern "C" void fn_80458508(void*,s32);
extern "C" void fn_80138B7C(void*);
extern "C" void fn_8022B17C();

struct SykyVec {
    f32 x, y, z;
    SykyVec& operator+=(const SykyVec& o) {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
};

struct SykySavedPlayers {
    u8 pad[0x26c];
    s32 movement[4];
    s32 mode[4];
};
struct SykyAfState { u8 pad[0x28]; u8 arr[4]; u8 flags; };
extern "C" void fn_80458880(void*, s32, s32);
extern const f32 lbl_8053E4A4;
extern const f32 lbl_8053E4A8;
extern void* lbl_8053AF80;
extern "C" void fn_801F02BC(void* p, f32 a, f32 b, const char* s, s32 x, s32 y, s32 z, s32 w, s32 v);
extern "C" u8 fn_8022F478(s32 i);
extern "C" s32 fn_8022F340(u32 p);
extern "C" void fn_8019E480(u8* p);
extern "C" void fn_8019E7A4(u8* p);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern const f32 lbl_8053E464;
extern const char lbl_80468494[];
extern s32 lbl_804C6330[];
extern u8 lbl_8053ABB8[4];
struct SykyVT { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual u8 v11(); virtual u8 v12(); };
extern void* lbl_8053AF10;
extern const f32 lbl_8053E460;
extern const f32 lbl_8053E46C;
extern const f32 lbl_8053E474;
extern const f32 lbl_8053E48C;
extern const f32 lbl_8053E490;
extern const f32 lbl_8053E494;
extern const f32 lbl_8053E498;
extern const f32 lbl_8053E49C;
extern const f32 lbl_8053E4A0;
extern "C" void fn_801F71A4(void* p, f32 a, f32 b, f32 c);
extern const f32 lbl_8053E4AC;
extern const f32 lbl_8053E4B0;
extern const f32 lbl_8053E4B4;
extern const f32 lbl_8053E4B8;
extern void* lbl_8053AED0;
extern "C" s32 fn_801A6108(s32 handle, JGeometry::TBox2<f32>* box, JGeometry::TVec2<f32>* ofs);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, s32 room, void* pos, s32 flags, s32 c, s32 d);
extern "C" s32 fn_8023AE34(JGeometry::TBox2<f32>* box, s32 room, JGeometry::TVec2<f32>* out);
extern "C" void fn_8043D874(void* mgr, s32 idx, s32 id, s32 flag);
extern "C" void fn_801F0D20(void* this_, s32 a);
extern "C" void fn_8019F3AC(u8* p);
extern "C" void fn_8019EE74(u8* p);
extern "C" void fn_8019EC04(u8* p);
extern const f32 lbl_8053E470;
extern const f32 lbl_8053E478;
extern const f32 lbl_8053E47C;
extern const f32 lbl_8053E480;
extern const f32 lbl_8053E484;
extern const f32 lbl_8053E488;
extern void* lbl_8053AAF8;
extern const f32 lbl_8053E468;
extern void* lbl_8053AB10;
extern "C" void fn_802F86CC(void* this_, Vec* pos, s32 a, s32 id, f32 x, f32 y, DrawRec* rec);
struct SykyObjVT { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual s32 v6(s32 kind, const char* name); };

/* 0x19660d/0x3c6ef35f LCG at lbl_8053AAF8+0xB4, mantissa read as [0,1) */
static inline f32 sykyRand01() {
    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *s = 0x19660du * *s + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - lbl_8053E460;
}
static inline f32 sykyRandFrom(void* __restrict game, int multiplier = 0x19660d) {
    unsigned int* base = (unsigned int*)game;
    base[45] = base[45] * multiplier + 0x3c6ef35f;
    u32 bits = (base[45] >> 9) | 0x3f800000;
    return *(f32*)&bits - lbl_8053E460;
}
extern const char lbl_80468480[];
static inline void sykyRotMtx(f32 m[3][4], f32 ax, f32 ay, f32 az, f32 s) {
    f32 sz, sy, sx, cz, cy, cx;
    sx = sin(ax); sy = sin(ay); sz = sin(az);
    cx = cos(ax); cy = cos(ay); cz = cos(az);
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    f32 sxcz, sxsz, cxsz, sxsy, cxcz;
    cxcz = cx * cz;
    sxsy = sx * sy;
    cxsz = cx * sz;
    sxsz = sx * sz;
    sxcz = sx * cz;
    m[0][1] = s * (sxsy * cz - cxsz);
    m[1][1] = s * (sxsy * sz + cxcz);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cxcz * sy + sxsz);
    m[1][2] = s * (cxsz * sy - sxcz);
    m[2][2] = s * (cx * cy);
}
#pragma opt_propagation off
extern "C" void fn_8019E37C(u8* p) {
    switch (*(s32*)(p + 0x268)) {
    case 0: {
        s32 i;
        fn_801F02BC(p, lbl_8053E460, lbl_8053E460, lbl_80468480, *(s32*)(p + 0x264) + 0x1ab, 0, 0, 0, 0);
        if (p[0x28c] != 0) {
            for (i = 0; i < 4; i++) {
                if (!fn_8022F478(i)) {
                    s32 idx = fn_8022F340(i);
                    ((SykyAfState*)lbl_8053AF10)->flags |= (u8)(1 << idx);
                    s32 off = idx + 0x28;
                    ((u8*)lbl_8053AF10)[off] = (u8)(10 - lbl_804C6330[idx]);
                }
            }
        }
        break;
    }
    case 1:
    case 2:
    case 4:
        fn_8019E480(p);
        break;
    case 3:
        fn_8019E7A4(p);
        break;
    }
}
#pragma opt_propagation reset
extern "C" void fn_8019E480(u8* self) {
    u8* p = self;
    DrawRec rec;
    f32 vec[3][4];
    s32 id = 0;
    vec[0][3] = lbl_8053E464;
    vec[1][3] = lbl_8053E464;
    vec[2][3] = lbl_8053E464;
    tlwpRotMtx(vec, lbl_8053E464, *(f32*)(p+0x294) / lbl_8053E468, lbl_8053E464, *(f32*)(p+0x290));
    rec.w18 = vec;
    switch (*(s32*)(p + 0x268)) {
    case 1: id = 9; break;
    case 2: id = 0x1d; break;
    case 4: id = 0xd; rec.w30 = 0x11; break;
    }
    *((u8*)&rec.w10 + 3) = (u8)*(f32*)(p + 0x298);
    id += *(s32*)(p + 0x264);
    if (*(s32*)(p + 4) < 8) {
        SykyObjVT* obj = *(SykyObjVT**)((u8*)lbl_8053AAF8 + 0xa4);
        s32 kind = obj->v6(0x534F4220, lbl_80468480);
        fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), (Vec*)(p + 0xc), kind, id, lbl_8053E460, lbl_8053E460, &rec);
    }
}

extern "C" void fn_8019E7A4(u8* p) {
    DrawRec rec;
    f32 vec[4][3];
    f32 zero = lbl_8053E464;
    vec[1][0] = zero;
    vec[2][1] = zero;
    vec[3][2] = zero;
    f32 s = *(f32*)(p + 0x290);
    vec[0][0] = s;
    vec[0][1] = zero;
    vec[0][2] = zero;
    vec[1][1] = zero;
    vec[1][2] = s;
    vec[2][0] = zero;
    vec[2][2] = zero;
    vec[3][0] = zero;
    vec[3][1] = s;
    rec.w18 = vec;
    fn_801F06F0(p, lbl_80468494, *(s32*)(p + 0x264) + 8, &rec, 0, lbl_8053E460, lbl_8053E460);
}

#pragma opt_common_subs off
extern "C" void fn_8019E910(u8* p) {
    switch (*(s32*)(p + 0x268)) {
    case 0:
        fn_8019F3AC(p);
        break;
    case 1:
    case 2:
        fn_8019EE74(p);
        break;
    case 3:
        fn_8019EC04(p);
        break;
    case 4:
        fn_801F71A4(p + 0x3c, *(f32*)(p + 0x2a0), lbl_8053E46C, lbl_8053E460);
        fn_801F71A4(p + 0x40, *(f32*)(p + 0x2a4), lbl_8053E46C, lbl_8053E460);
        JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), (Vec*)(p + 0x3c), (Vec*)(p + 0xc));
        if (!(*(s32*)(p + 0x198) & 1)) {
            *(f32*)(p + 0x294) += lbl_8053E470;
        } else {
            *(f32*)(p + 0x294) -= lbl_8053E470;
        }
        switch (*(s32*)(p + 0x230)) {
        case 11:
            *(f32*)(p + 0x2a0) = lbl_8053E474 - lbl_8053E478 * sykyRandFrom(lbl_8053AAF8);
            *(f32*)(p + 0x2a4) = lbl_8053E474 - lbl_8053E478 * sykyRandFrom(lbl_8053AAF8);
            *(f32*)(p + 0x44) = lbl_8053E47C + lbl_8053E480 * sykyRandFrom(lbl_8053AAF8);
            *(f32*)(p + 0x290) = lbl_8053E484 + lbl_8053E46C * sykyRandFrom(lbl_8053AAF8);
            *(s32*)(p + 0x230) = 0xc;
            break;
        case 12:
            *(f32*)(p + 0x44) -= lbl_8053E460;
            if (*(f32*)(p + 0x14) <= lbl_8053E464) {
                *(f32*)(p + 0x14) = lbl_8053E464;
                *(f32*)(p + 0x44) = lbl_8053E474 + lbl_8053E488 * sykyRandFrom(lbl_8053AAF8);
                *(s32*)(p + 0x230) = 0xd;
            }
            break;
        case 13:
            *(f32*)(p + 0x44) -= lbl_8053E460;
            if (*(f32*)(p + 0x14) <= lbl_8053E464) {
                *(f32*)(p + 0x14) = lbl_8053E464;
                *(u8*)(p + 0x11c) = 0;
            }
            break;
        }
        fn_801F71A4(p + 0x298, lbl_8053E460, lbl_8053E46C, lbl_8053E480);
        if (*(f32*)(p + 0x298) < lbl_8053E460) {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    }
}
#pragma opt_common_subs reset
extern "C" void fn_8019EC04(u8* p) {
    fn_801F71A4(p + 0x3c, *(f32*)(p + 0x2a0), lbl_8053E46C, lbl_8053E460);
    fn_801F71A4(p + 0x40, *(f32*)(p + 0x2a4), lbl_8053E46C, lbl_8053E460);
    *(s32*)(p + 0x108) = 10000;
    JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), (Vec*)(p + 0x3c), (Vec*)(p + 0xc));
    if (*(s32*)(p + 0x98) == 0) {
        if (*(f32*)(p + 0xc) > lbl_8053E48C) {
            p[0x11c] = 0;
        }
    } else {
        if (*(f32*)(p + 0xc) < lbl_8053E490) {
            p[0x11c] = 0;
        }
    }
    switch (*(s32*)(p + 0x230)) {
    case 14:
        *(f32*)(p + 0x2a0) = lbl_8053E494;
        if (*(s32*)(p + 0x98) != 0) {
            *(f32*)(p + 0x2a0) = lbl_8053E498;
        }
        *(f32*)(p + 0x29c) = *(f32*)(p + 0x10);
        if (*(s32*)(p + 0x238) == 0) {
            *(s32*)(p + 0x238) = 4;
            *(s32*)(p + 0x264) += 1;
            *(s32*)(p + 0x264) &= 1;
        }
        break;
    case 15:
        fn_801F71A4(p + 0x290, lbl_8053E460, lbl_8053E49C, lbl_8053E4A0);
        fn_801F71A4(p + 0x10, *(f32*)(p + 0x29c), lbl_8053E46C, lbl_8053E474);
        if (*(s32*)(p + 0x238) == 0) {
            *(s32*)(p + 0x238) = 2;
            *(s32*)(p + 0x264) += 1;
            *(s32*)(p + 0x264) &= 1;
        }
        if ((f32)__fabs(*(f32*)(p + 0x10) - *(f32*)(p + 0x29c)) < lbl_8053E4A0) {
            *(f32*)(p + 0x290) = lbl_8053E460;
            *(s32*)(p + 0x230) = 0xe;
        }
        break;
    }
    if (*(s32*)(p + 0x238) > 0) {
        *(s32*)(p + 0x238) -= 1;
    }
    if (*(s32*)(p + 0x23c) > 0) {
        *(s32*)(p + 0x23c) -= 1;
    }
    u8* q = (u8*)((u32)p + 8);
    if (*(s32*)(p + 0x240) > 0) {
        *(s32*)(q + 0x238) = *(s32*)(p + 0x240) - 1;
    }
    if (*(s32*)(q + 0x23c) > 0) {
        *(s32*)(q + 0x23c) -= 1;
    }
}

extern "C" void fn_8019EE04(u8* p) {
    if (*(s32*)(p + 0x268) == 3 && *(s32*)(p + 0x230) != 0xf) {
        *(f32*)(p + 0x290) = lbl_8053E4A4;
        *(f32*)(p + 0x10) -= lbl_8053E4A8;
        fn_80458880(lbl_8053AF80, 6, -1);
        *(s32*)(p + 0x230) = 0xf;
    }
}

extern "C" void fn_8019EE74(u8* self) {
    int multiplier;
    u32 id;
    u8* p = self;
    s32 i;
    JGeometry::TBox2<f32> box;
    JGeometry::TVec2<f32> ofs;
    box.set(*(JGeometry::TBox2<f32>*)(p + 0x60));
    ofs.set(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    box.addPos(*(JGeometry::TVec2<f32>*)(p + 0xc));
    fn_801F71A4(p + 0x3c, *(f32*)(p + 0x2a0), lbl_8053E46C, lbl_8053E460);
    fn_801F71A4(p + 0x40, *(f32*)(p + 0x2a4), lbl_8053E46C, lbl_8053E460);
    JMathInlineVEC::PSVECAdd((Vec*)(p + 0xc), (Vec*)(p + 0x3c), (Vec*)(p + 0xc));
    switch (*(s32*)(p + 0x230)) {
    case 9:
        *(s32*)(p + 0x238) = (s32)(lbl_8053E4AC * sykyRandFrom(lbl_8053AAF8)) + 0x3c;
        *(s32*)(p + 0x23c) = (s32)(lbl_8053E4B0 * sykyRandFrom(lbl_8053AAF8)) + 0x50;
        *(f32*)(p + 0x2a0) = lbl_8053E494;
        if (*(s32*)(p + 0x98) != 0) {
            *(f32*)(p + 0x2a0) = lbl_8053E498;
        }
        *(s32*)(p + 0x230) = 10;
        /* fallthrough */
    case 10:
        *(s32*)(p + 0xb0) = 3;
        if (*(s32*)(p + 0x240) == 1) {
            *(u8*)(p + 0x11c) = 0;
            break;
        }
        if (*(s32*)(p + 0x240) == 0 && fn_801A6108(*(s32*)(p + 0x198), &box, &ofs)) {
            *(s32*)(p + 0xb0) = 7;
            *(s32*)(p + 0x248) = fn_8023AE34(&box, *(s32*)(p + 0x4), &ofs);
            if (*(s32*)(p + 0x268) == 1) {
                fn_8043D874(lbl_8053AED0, *(s32*)(p + 0x248), 0x12c, 0);
                multiplier = 0x19660d;
                id = 0x53594B59;
                for (i = 0; i < 20; i++) {
                    Vec pos;
                    pos.x = *(f32*)(p + 0xc);
                    pos.y = *(f32*)(p + 0x10);
                    pos.z = *(f32*)(p + 0x14);
                    pos.x = pos.x + (lbl_8053E4B4 - lbl_8053E4A8 * sykyRandFrom(lbl_8053AAF8, multiplier));
                    pos.y = pos.y + (lbl_8053E4B4 - lbl_8053E4A8 * sykyRandFrom(lbl_8053AAF8, multiplier));
                    Actor_CreateByID(fn_801F856C(), id, *(s32*)(p + 0x4), &pos, 4, -1, -1);
                }
            } else {
                fn_8043D874(lbl_8053AED0, *(s32*)(p + 0x248), 0x14, 0);
            }
            *(s32*)(p + 0x240) = 2;
            fn_801F0D20(p, 4);
            return;
        }
        if (*(s32*)(p + 0x268) == 1 && *(s32*)(p + 0x23c) != 0) {
            if (*(s32*)(p + 0x23c) == 1) {
                if (sykyRandFrom(lbl_8053AAF8) < lbl_8053E4B8) {
                    *(s32*)(p + 0x98) ^= 1;
                    *(f32*)(p + 0x2a0) = lbl_8053E494;
                    if (*(s32*)(p + 0x98) != 0) {
                        *(f32*)(p + 0x2a0) = lbl_8053E498;
                    }
                }
            }
        } else {
            if (*(s32*)(p + 0x98) == 0) {
                if (*(f32*)(p + 0xc) > lbl_8053E48C) {
                    *(u8*)(p + 0x11c) = 0;
                }
            } else {
                if (*(f32*)(p + 0xc) < lbl_8053E490) {
                    *(u8*)(p + 0x11c) = 0;
                }
            }
        }
        break;
    }
    if (*(s32*)(p + 0x238) == 0) {
        *(s32*)(p + 0x264) += 1;
        *(s32*)(p + 0x264) &= 3;
        if (*(s32*)(p + 0x264) == 0) {
            *(s32*)(p + 0x238) = (s32)(lbl_8053E4AC * sykyRandFrom(lbl_8053AAF8)) + 0x3c;
        } else {
            *(s32*)(p + 0x238) = 2;
        }
    }
    if (*(s32*)(p + 0x238) > 0) {
        *(s32*)(p + 0x238) -= 1;
    }
    if (*(s32*)(p + 0x23c) > 0) {
        *(s32*)(p + 0x23c) -= 1;
    }
    if (*(s32*)(p + 0x240) > 0) {
        *(s32*)(p + 0x240) -= 1;
    }
    if (*(s32*)(p + 0x244) > 0) {
        *(s32*)(p + 0x244) -= 1;
    }
}

extern "C" void fn_80239914(void*,s32,s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_8022FEB8(void*,s32,s32,s32,s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8038AD24(s32,s32,s32,s32,void*,s32);
extern "C" void fn_801EE8F4(void*,void*,f32*,s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" void fn_8038470C(s32,s32);
extern "C" u8 fn_80388CAC(s32,s32);
extern "C" void fn_80230534(s32);
extern "C" void fn_80458FF0(void*,s32,s32,s32);
extern "C" void fn_8022B194();
extern "C" u8 fn_8023F264(s32);
extern "C" void* fn_802D6A9C();
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023725C(s32);
extern "C" s32 fn_801F68E0(void*);
extern "C" void fn_80230C6C(s32);
extern "C" u8* fn_801F666C(void*,s32);
extern "C" void fn_8022FE80(s32,s32,s32,s32,s32);
extern "C" u8 fn_80384C58(s32,s32);
extern "C" void fn_801F6884(void*);
extern const s32 lbl_804A2B08[];
extern const f32 lbl_8053E4BC;
extern const f32 lbl_8053E4C4;
static inline u16 sykyFacingAngle(const f32 x, const f32 y) {
    f32 radians=JMath::atanTable_.atan2_(x,y);
    return (u16)(s32)(radians*lbl_8053E4C4);
}

extern const f32 lbl_8053E4BC;
extern const f32 lbl_8053E4C0;
extern const f32 lbl_8053E4C4;
extern const f32 lbl_8053E4C8;
extern const f32 lbl_8053E4CC;
extern const f32 lbl_8053E4D0;
extern const f32 lbl_8053E4D4;
extern const f32 lbl_8053E4D8;
extern const f32 lbl_8053E4DC;
#pragma opt_common_subs off
extern "C" void fn_8019F3AC(u8* p) {
 JGeometry::TVec3<f32> marker,spawn,saved;
 JGeometry::TBox2<f32> box,camera;
 JGeometry::TVec3<f32> copy0,copy1,copy4,copy6;
 JGeometry::TVec3<f32> dir0,dir1,dir2,dir6;
 f32 dist0,dist1,dist2,dist6;
 int direction,id,count;
 marker=(*(JGeometry::TVec3<f32>*)(p+0xc));
 spawn.x=*(f32*)(p+0xc);spawn.y=*(f32*)(p+0x10);spawn.z=*(f32*)(p+0x14);
 saved=(*(JGeometry::TVec3<f32>*)(p+0xc));
 marker.y-=lbl_8053E4BC;
 box.set(*(JGeometry::TBox2<f32>*)(p+0x60));
 box.addPos(*(JGeometry::TVec2<f32>*)&spawn);
 fn_80239914(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)));
 box=*(JGeometry::TBox2<f32>*)(p+0x70);
 box.addPos(*(JGeometry::TVec2<f32>*)(p+0xc));
 switch((*(s32*)(p+0x230))){
 case 0:{
   int different=0;
   for(int i=0;i<4;i++){s32 room=(*(s32*)(p+4));if(room!=fn_8023DE58(i)){different=1;break;}}
   if(different){
     fn_8022FEB8(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)),1,0);
     (*(s32*)(p+0x250))=fn_8022FD8C((*(s32*)(p+0x198)));
     if((*(s32*)(p+0x250))<0 || !fn_802300EC((*(s32*)(p+0x250))))break;
     s32 handle=(*(s32*)(p+0x198));s32 room=(*(s32*)(p+4));copy0=marker;
     if(!fn_8038AD24((*(s32*)(p+0x250)),0x342,handle,room,&copy0,0))break;
     fn_801EE8F4(p,&dir0,&dist0,(*(s32*)(p+0x250))+1);
     if(dist0<lbl_8053E4C0){
  u16 a=sykyFacingAngle(-dir0.x,-dir0.y);
  if(a<0x2000 || a>=0xe000)(*(s32*)(p+0x98))=3;
  else if(a>=0x2000 && a<0x6000)(*(s32*)(p+0x98))=1;
  else if(a>=0x6000 && a<=0xa000)(*(s32*)(p+0x98))=2;
  else (*(s32*)(p+0x98))=0;
}
     (*(s32*)(p+0x230))=8;
   }else{
     fn_8022FEB8(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)),1,0);
     (*(s32*)(p+0x250))=fn_8022FD8C((*(s32*)(p+0x198)));
     if((*(s32*)(p+0x250))<0)break;
     s32 handle=(*(s32*)(p+0x198));s32 room=(*(s32*)(p+4));copy1=marker;
     if(!fn_8038AD24((*(s32*)(p+0x250)),0x334,handle,room,&copy1,0))break;
     fn_801EE8F4(p,&dir1,&dist1,(*(s32*)(p+0x250))+1);
     if(dist1<lbl_8053E4C0){
  u16 a=sykyFacingAngle(-dir1.x,-dir1.y);
  if(a<0x2000 || a>=0xe000)(*(s32*)(p+0x98))=3;
  else if(a>=0x2000 && a<0x6000)(*(s32*)(p+0x98))=1;
  else if(a>=0x6000 && a<=0xa000)(*(s32*)(p+0x98))=2;
  else (*(s32*)(p+0x98))=0;
}
     (*(s32*)(p+0x230))=1;
   }
 }break;
 case 1:
   fn_8022FEB8(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)),1,0);
   if(fn_803865B8((*(s32*)(p+0x250)))){
     switch(fn_8037EFB4((*(s32*)(p+0x250)))){
       case 0:fn_8038470C((*(s32*)(p+0x250)),0x335);(*(s32*)(p+0x230))=2;break;
       case 1:fn_8038470C((*(s32*)(p+0x250)),0x336);(*(s32*)(p+0x230))=8;break;
     }
   }break;
 case 2:
   fn_8022FEB8(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)),1,0);
   if(fn_80388CAC((*(s32*)(p+0x250)),(*(s32*)(p+0x198)))){
     fn_80230534(0);fn_801F0D20(p,0x3a);
     fn_80458FF0(lbl_8053AF80,0x1000007,1,0);fn_8022B194();
     (*(s32*)(p+0x98))=2;(*(s32*)(p+0x24c))=0;(*(s32*)(p+0x250))=0;(*(s32*)(p+0x254))=0;(*(s32*)(p+0x258))=0;(*(s32*)(p+0x25c))=0;(*(s32*)(p+0x260))=0;
     (*(s32*)(p+0x23c))=120;(*(s32*)(p+0x240))=0;(*(s32*)(p+0x244))=0;
     fn_801EE8F4(p,&dir2,&dist2,2);
     if(dist2<lbl_8053E4C0){
  u16 a=sykyFacingAngle(-dir2.x,-dir2.y);
  if(a<0x2000 || a>=0xe000)(*(s32*)(p+0x98))=3;
  else if(a>=0x2000 && a<0x6000)(*(s32*)(p+0x98))=1;
  else if(a>=0x6000 && a<=0xa000)(*(s32*)(p+0x98))=2;
  else (*(s32*)(p+0x98))=0;
}
     (*(u8*)(p+0x28c))=1;(*(s32*)(p+0x230))=3;
   }break;
 case 3:{
   spawn.x=*(f32*)(p+0xc);spawn.y=*(f32*)(p+0x10);spawn.z=*(f32*)(p+0x14);
   (*(f32*)(p+0xc))=lbl_8053E4C8;(*(f32*)(p+0x10))=lbl_8053E4CC;
   box=*(JGeometry::TBox2<f32>*)(p+0x70);box.addPos(*(JGeometry::TVec2<f32>*)(p+0xc));
   fn_80239914(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)));
   (*(JGeometry::TVec3<f32>*)(p+0xc)).set(spawn);
   int active=0;
   for(int i=0;i<4;i++)if(fn_8023F264(i) && fn_8023DE58(i)<8)active=1;
   if(!active){
     u8* mgr=(u8*)fn_802D6A9C();
     camera=*(JGeometry::TBox2<f32>*)(mgr+0xcc);
     u8* c=*(u8**)((u8*)lbl_8053AB10+0x24);
     if(c[0x7f5]==0){
       c[0x7f4]=1;*(s32*)(c+0x7f8)=5;
       *(f32*)(c+0x808)=camera.i.x;*(f32*)(c+0x80c)=camera.i.y;
       *(f32*)(c+0x810)=camera.f.x;*(f32*)(c+0x814)=camera.f.y;
       c[0x7f6]=0;
     }
     if((*(s32*)(p+0x260))==0){
       for(int i=0;i<4;i++){((SykySavedPlayers*)p)->movement[i]=fn_802373EC(i);((SykySavedPlayers*)p)->mode[i]=fn_8023725C(i);fn_802372F8(i,4,1);}
       (*(s32*)(p+0x260))=1;
     }
   }
   count=0;
   for(int i=0;i<4;i++){
     if(lbl_804C6330[fn_8022F340(i)]>=10)lbl_8053ABB8[i]=1;
     if(lbl_8053ABB8[i]==1 || fn_8022F514(i))count++;
   }
   if(count>=4){
     (*(s32*)(p+0x25c))++;
     if((*(s32*)(p+0x25c))>70){
       (*(s32*)(p+0x2ac))=-1;
       if(!fn_801F68E0(fn_801F856C()))break;
       for(int i=0;i<4;i++)fn_80230C6C(i);
       fn_801F0D20(p,0x3b);fn_80458508(lbl_8053AF80,0);
       (*(s32*)(p+0x98))=2;(*(s32*)(p+0x24c))=0;(*(s32*)(p+0x250))=0;(*(s32*)(p+0x254))=0;(*(s32*)(p+0x258))=0;(*(s32*)(p+0x25c))=0;
       (*(s32*)(p+0x23c))=0;(*(s32*)(p+0x240))=0;(*(s32*)(p+0x244))=0;(*(u8*)(p+0x28c))=0;(*(s32*)(p+0x230))=4;break;
     }
   }
   if((*(s32*)(p+0x258))==0){
     count=0;for(int i=0;i<4;i++)if(lbl_804C6330[i]>=5||fn_8022F514(i))count++;
     if(count>=4){fn_801F0D20(p,0x3f);fn_80458508(lbl_8053AF80,1);(*(s32*)(p+0x258))=1;}
   }
   if((*(s32*)(p+0x23c))==0){
     if(sykyRand01()<lbl_8053E484){spawn.x=lbl_8053E48C;direction=1;}
     else{spawn.x=lbl_8053E490;direction=0;}
     spawn.y=lbl_8053E4D0;
     id=Actor_CreateByID(fn_801F856C(),0x53594B59,0,&spawn,1,-1,-1);
     if(id>=0){u8* obj=fn_801F666C(fn_801F856C(),id);if(obj)*(s32*)(obj+0x98)=direction;}
     (*(s32*)(p+0x23c))=120;
   }
   if((*(s32*)(p+0x240))==0){
     spawn.x=lbl_8053E48C;spawn.y=lbl_8053E4D4;
     id=Actor_CreateByID(fn_801F856C(),0x53594B59,0,&spawn,2,-1,-1);
     if(id>=0){u8* obj=fn_801F666C(fn_801F856C(),id);if(obj)*(s32*)(obj+0x98)=1;}
     (*(s32*)(p+0x240))=60;(*(s32*)(p+0x250))++;
     if((*(s32*)(p+0x250))>=3){(*(s32*)(p+0x250))=0;(*(s32*)(p+0x240))=(s32)(lbl_8053E4D8*sykyRand01())+90;}
   }
   if((*(s32*)(p+0x244))==0){
     spawn.x=lbl_8053E490;spawn.y=lbl_8053E4DC;
     id=Actor_CreateByID(fn_801F856C(),0x53594B59,0,&spawn,3,-1,-1);
     if(id>=0){u8* obj=fn_801F666C(fn_801F856C(),id);if(obj)*(s32*)(obj+0x98)=0;}
     (*(s32*)(p+0x244))=100;(*(s32*)(p+0x254))++;
     if((*(s32*)(p+0x254))>=3)(*(s32*)(p+0x254))=0;
   }
 }break;
 case 4:
   (*(s32*)(p+0x24c))++;
   if((*(s32*)(p+0x24c))>50){
     (*(s32*)(p+0x24c))=51;
     if((*(s32*)(p+0x2ac))<0){for(int i=0;i<4;i++)if(!fn_8022F478(i)){(*(s32*)(p+0x2ac))=i;break;}}
     fn_8022FE80((*(s32*)(p+0x2ac)),fn_8023DE58((*(s32*)(p+0x2ac))),(*(s32*)(p+0x198)),0,0);
     if((*(s32*)(p+0x2ac))==fn_8022FD8C((*(s32*)(p+0x198)))){
       s32 player=(*(s32*)(p+0x2ac));s32 handle=(*(s32*)(p+0x198));s32 room=(*(s32*)(p+4));copy4=marker;
       fn_8038AD24(player,0x337,handle,room,&copy4,2);(*(s32*)(p+0x230))=5;
     }
   }break;
 case 5:
   fn_8022FE80((*(s32*)(p+0x2ac)),fn_8023DE58((*(s32*)(p+0x2ac))),(*(s32*)(p+0x198)),0,0);
   if(fn_803865B8((*(s32*)(p+0x2ac))) && fn_80384C58((*(s32*)(p+0x2ac)),(*(s32*)(p+0x198)))){
     fn_801F6884(fn_801F856C());
     for(int i=0;i<4;i++)if(!fn_8022F514(i))fn_802372F8(i,((SykySavedPlayers*)p)->movement[i],((SykySavedPlayers*)p)->mode[i]);
     fn_80138B7C(lbl_8053AAF8);((Actor*)p)->v10(0xff,1);fn_8022B17C();(*(s32*)(p+0x230))=6;
   }break;
 case 6:{
   fn_8022FEB8(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)),1,0);
   (*(s32*)(p+0x250))=fn_8022FD8C((*(s32*)(p+0x198)));
   if((*(s32*)(p+0x250))<0 || !fn_802300EC((*(s32*)(p+0x250))))break;
   s32 handle=(*(s32*)(p+0x198));s32 room=(*(s32*)(p+4));copy6=marker;
   if(!fn_8038AD24((*(s32*)(p+0x250)),0x338,handle,room,&copy6,0))break;
   fn_801EE8F4(p,&dir6,&dist6,(*(s32*)(p+0x250))+1);
   if(dist6<lbl_8053E4C0){
  u16 a=sykyFacingAngle(-dir6.x,-dir6.y);
  if(a<0x2000 || a>=0xe000)(*(s32*)(p+0x98))=3;
  else if(a>=0x2000 && a<0x6000)(*(s32*)(p+0x98))=1;
  else if(a>=0x6000 && a<=0xa000)(*(s32*)(p+0x98))=2;
  else (*(s32*)(p+0x98))=0;
}
   (*(s32*)(p+0x230))=7;
 }break;
 case 7:
   fn_8022FEB8(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)),1,0);
   if(fn_80388CAC((*(s32*)(p+0x250)),(*(s32*)(p+0x198)))){(*(s32*)(p+0x98))=2;(*(s32*)(p+0x230))=6;}break;
 case 8:
   fn_8022FEB8(&box,(*(s32*)(p+4)),(*(s32*)(p+0x198)),1,0);
   if(fn_80388CAC((*(s32*)(p+0x250)),(*(s32*)(p+0x198))))(*(s32*)(p+0x230))=0;break;
 }
 for(int i=0;i<4;i++)if(((s32*)(p+0x238))[i]>0)((s32*)(p+0x238))[i]--;
 if((*(s32*)(p+0x238))==0){
   (*(s32*)(p+0x264))=lbl_804A2B08[(*(s32*)(p+0x248))];(*(s32*)(p+0x238))=15;(*(s32*)(p+0x248))++;(*(s32*)(p+0x248))&=3;
 }
}
#pragma opt_common_subs reset
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_8022B17C(void);
extern "C" void fn_80138B7C(void* p);
extern "C" void fn_80458508(void* p, s32 x);
extern "C" u8 fn_8022F514(s32 i);
extern "C" void fn_802372F8(s32 i, s32 a, s32 b);
extern void* lbl_804A2B18[];
extern void* lbl_8053AAF8;
extern "C" void* fn_801A024C(u8* this_, s16 freeFlag) {
    s32 i;
    u8* cur;
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2B18;
        if (*(s32*)(this_ + 0x268) == 0) {
            s32 state = *(s32*)(this_ + 0x230);
            if (state == 3 || state == 4) {
                fn_8022B17C();
                if (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 9) {
                    fn_80138B7C(lbl_8053AAF8);
                    fn_80458508(lbl_8053AF80, 0);
                }
                for (i = 0, cur = this_; i < 4; i++, cur += 4) {
                    if (fn_8022F514(i) == 0) {
                        fn_802372F8(i, *(s32*)(cur + 0x26c), *(s32*)(cur + 0x27c));
                    }
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern const f32 lbl_8053E4E0;
extern const f32 lbl_8053E4B4;
extern const f32 lbl_8053E4E4;
extern const f32 lbl_8053E47C;
extern const f32 lbl_8053E4E8;
extern "C" void fn_801A033C(u8* p) {
    *(f32*)(p + 0x60) = lbl_8053E4E0;
    *(f32*)(p + 0x64) = lbl_8053E4E0;
    *(f32*)(p + 0x68) = lbl_8053E4B4;
    *(f32*)(p + 0x6c) = lbl_8053E4B4;
    *(f32*)(p + 0x80) = lbl_8053E4E0;
    *(f32*)(p + 0x84) = lbl_8053E4E0;
    *(f32*)(p + 0x88) = lbl_8053E4B4;
    *(f32*)(p + 0x8c) = lbl_8053E4B4;
    *(f32*)(p + 0x70) = lbl_8053E4E4;
    *(f32*)(p + 0x74) = lbl_8053E4E4;
    *(f32*)(p + 0x78) = lbl_8053E47C;
    *(f32*)(p + 0x7c) = lbl_8053E47C;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x98) = 2;
    *(s32*)(p + 0x264) = 0;
    *(f32*)(p + 0x290) = lbl_8053E460;
    *(f32*)(p + 0x294) = lbl_8053E464;
    *(f32*)(p + 0x298) = lbl_8053E4E8;
    p[0x28c] = 0;
    *(f32*)(p + 0x2a8) = lbl_8053E464;
    *(f32*)(p + 0x2a4) = lbl_8053E464;
    *(f32*)(p + 0x2a0) = lbl_8053E464;
    *(f32*)(p + 0x44) = lbl_8053E464;
    *(f32*)(p + 0x40) = lbl_8053E464;
    *(f32*)(p + 0x3c) = lbl_8053E464;
    *(f32*)(p + 0x29c) = *(f32*)(p + 0x10);
    *(s32*)(p + 0x268) = *(u32*)(p + 0x90) & 0xf;
    switch (*(s32*)(p + 0x268)) {
    case 0:
        lbl_8053ABB8[0] = 0;
        lbl_804C6330[0] = 0;
        lbl_8053ABB8[1] = 0;
        lbl_804C6330[1] = 0;
        lbl_8053ABB8[2] = 0;
        lbl_804C6330[2] = 0;
        lbl_8053ABB8[3] = 0;
        lbl_804C6330[3] = 0;
        *(s32*)(p + 0xb0) = 0xa040004;
        if (((SykyVT*)p)->v11()) {
            *(s32*)(p + 0x230) = 6;
        } else {
            *(s32*)(p + 0x230) = 0;
        }
        break;
    case 1:
    case 2:
        *(s32*)(p + 0x230) = 9;
        break;
    case 3:
        *(s32*)(p + 0x108) = 10000;
        *(s32*)(p + 0xb0) = 0xf;
        *(s32*)(p + 0x230) = 0xe;
        break;
    case 4:
        *(s32*)(p + 0x230) = 0xb;
        break;
    }
}


