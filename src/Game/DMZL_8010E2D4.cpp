#include "types.h"
#include "JSystem/JMath/JMath.h"
extern const f32 lbl_8053C580;
static inline f32 DMZLAngle(f32 x, f32 y) {
    f32 angle = JMath::atanTable_.atan2_(x,y);
    angle *= lbl_8053C580;
    return angle;
}
static inline s32 DMZLElapsed(void* manager,const char* table) {
    return *(s32*)((u8*)manager+8)-*(const s32*)(table+0x84);
}
#include "Game/SinitPoolChain.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"
static inline JGeometry::TVec3<f32> operator/(const JGeometry::TVec3<f32>& v, f32 divisor) {
JGeometry::TVec3<f32> copy(v);
return JGeometry::TVec3<f32>(copy.x/divisor,copy.y/divisor,copy.z/divisor);
}
static inline JGeometry::TVec3<f32> DMZLDivide(const JGeometry::TVec3<f32>& v, f32 divisor) {
JGeometry::TVec3<f32> copy(v);
return JGeometry::TVec3<f32>(copy.x/divisor,copy.y/divisor,copy.z/divisor);
}
static inline JGeometry::TVec3<f32> DMZLDelta(JGeometry::TVec3<f32>& dest,const JGeometry::TVec3<f32>& from,f32 divisor) {
JGeometry::TVec3<f32> diff=dest-from;
return DMZLDivide(diff,divisor);
}
static inline void DMZLVelocity(JGeometry::TVec3<f32>& out, JGeometry::TVec3<f32>& dest, const JGeometry::TVec3<f32>& from, f32 divisor) {
out=DMZLDivide(dest-from,divisor);
}
extern "C" void* lbl_8053AED0;
extern "C" void* lbl_8053AF80;
extern "C" void fn_8043A450(void*, s32, s32);
extern "C" void fn_80458FF0(void*, s32, s32, s32);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void*,s32,s32,s32,s32,s32,s32,s32);
extern "C" void fn_802D9FF4(void*,s32,s32);
extern "C" void fn_802DA8DC(void*);
extern "C" Vec* fn_8023E604(s32);
extern "C" s32 fn_8023CBC0(s32);
extern "C" void fn_80230498(s32,void*,u16,s32,s32,s32,s32);
extern const s32 lbl_8053C548[2];
extern const f32 lbl_8053C588;
extern const f32 lbl_8053C5A4;
extern const f32 lbl_8053C5A8;
extern const f32 lbl_8053C5AC;
extern const f32 lbl_8053C5B0;
extern const f32 lbl_8053C5B4;
extern const f32 lbl_8053C5B8;
extern const f32 lbl_8053C5BC;
extern const f32 lbl_8053C5C0;
extern const f32 lbl_8053C5C4;

extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void fn_80110210(u8*);
extern "C" void fn_80239914(void*, s32, s32);
extern "C" void fn_8022FF8C(s32, void*, s32, s32, s32, s32);
extern "C" u8 fn_80388CAC(s32, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);
extern "C" u8 fn_801D208C(void*);
extern "C" void fn_801EEC98(void*, s32, u16*, s32*, f32*, s32*, s32, s32);
extern "C" void fn_8022FEB8(void*, s32, s32, s32, s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8023F264(s32);
extern "C" u8 fn_8038AD24(s32, s32, s32, s32, void*, s32);
extern "C" s32 fn_80230CFC(s32);
extern "C" s32 fn_801CD354(s32);
extern "C" void fn_80230C6C(s32);
extern const f32 lbl_8053C5E8;
extern const f32 lbl_8053C5EC;
extern const f32 lbl_8053C564;
extern const f32 lbl_8053C5F0;
extern const f32 lbl_8053C5F4;
extern const f32 lbl_8053C5F8;


typedef f32 Mtx[3][4];
typedef struct MtxBox {
    Mtx m;
} MtxBox;
extern "C" void PSMTXTrans(Mtx m, f32 xT, f32 yT, f32 zT);
extern "C" void PSMTXConcat(const Mtx a, const Mtx b, Mtx ab);
extern "C" void PSMTXCopy(const Mtx src, Mtx dst);
extern const f32 lbl_8053C550;
extern const f32 lbl_8053C55C;
extern const f32 lbl_8053C5C8;
extern const f32 lbl_8053C5CC;
extern const f32 lbl_8053C5D0;
extern "C" void* fn_801902C0(void);
extern const f32 lbl_8053C554;
extern const f32 lbl_8053C570;
extern const f32 lbl_8053C58C;
extern const f32 lbl_8053C590;
extern const f32 lbl_8053C59C;
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_8013CC50(u32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void* fn_801C0D70(void);
extern "C" void fn_801C11A4(void);
extern "C" void fn_801C115C(void);
extern "C" void fn_80118454(void);
extern "C" void fn_80118384(void);
extern "C" void fn_801183BC(void);
extern "C" void fn_8022FE80(s32, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_8038BD08(s32, s32, s32, void*, s32);
extern "C" void fn_802D8050(void*, s32, s32, s32);

extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_8010DF78(void* this_);
extern "C" void fn_8010F7EC(u8*, s32);
extern "C" void fn_80110E9C(u8*);
extern "C" void fn_8011093C(void*);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_8010F4DC(u8* this_);
extern "C" void fn_8010E7E8(void*, s32);
extern "C" void fn_8010E2D4(void*, s32);
extern "C" void fn_8010F668(f32 m[3][4], f32 axis[3], f32 angle);
extern "C" void* fn_8011921C(void);
extern "C" void* fn_8011871C(void* list, void* it, u32 tag);
static inline void* DMZLFind(void* first, u32 tag) {
    return fn_8011871C(fn_8011921C(), first, tag);
}
static inline void* DMZLFindTag(u32 tag) {
    void* first = *(void**)((u8*)fn_8011921C() + 0x10);
    return fn_8011871C(fn_8011921C(), first, tag);
}
extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_8049D208[];
extern "C" char lbl_8049CC34[];
extern char lbl_8046464C[];
extern char lbl_80464660[];
extern const f32 lbl_8053C560;
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];

struct SwbmDrawParam {
    SwbmDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};
extern "C" void fn_801F02BC(void* this_, const char* name, s32 idx, SwbmDrawParam* prm, s32 a, s32 b, s32 c, f32 s0, f32 s1);

extern "C" void* fn_8010FA84(u8* this_) {
#if defined(VERSION_G4SP01)
    return *(void**)(this_ + 0x23c);
#else
    return *(void**)(this_ + 0x238);
#endif
}

extern char lbl_80464550[];
extern "C" void fn_8010F478(u8* this_, s32 param_2);
extern "C" void fn_8010FA8C(u8* this_) {
    void* a = fn_8011921C();
    s32 state = *(s32*)(this_ + 0x234);
    s32 v = *(s32*)((u8*)a + 8);
    switch (state) {
    case 0:
        a = fn_8011921C();
        if (*(s32*)((u8*)a + 4) == 0) {
            if (v == *(s32*)(lbl_80464550 + 0xc)) {
                fn_8010F478(this_, 3);
            } else if (v == *(s32*)(lbl_80464550 + 0x10)) {
                fn_8010F478(this_, 4);
            } else if (v == *(s32*)(lbl_80464550 + 0x14)) {
                fn_8010F478(this_, 5);
            } else if (v == *(s32*)(lbl_80464550 + 0x18)) {
                fn_8010F478(this_, 6);
            } else if (v == *(s32*)(lbl_80464550 + 0x1c)) {
                fn_8010F478(this_, 7);
            } else if (v == *(s32*)(lbl_80464550 + 0x20)) {
                fn_8010F478(this_, 8);
            } else if (v == *(s32*)(lbl_80464550 + 0x24)) {
                fn_8010F478(this_, 9);
            } else if (v == *(s32*)(lbl_80464550 + 0x28)) {
                fn_8010F478(this_, 0xa);
            } else if (v == *(s32*)(lbl_80464550 + 0x2c)) {
                fn_8010F478(this_, 0xb);
            } else if (v == *(s32*)(lbl_80464550 + 0x30)) {
                fn_8010F478(this_, 0xc);
            } else if (v == *(s32*)(lbl_80464550 + 0x34)) {
                fn_8010F478(this_, 0xd);
                fn_8010F478(this_, 0x25);
            }
        }
        break;
    case 1:
        a = fn_8011921C();
        if (*(s32*)((u8*)a + 4) == 1) {
            if (v == *(s32*)(lbl_80464550 + 0x38)) {
                fn_8010F478(this_, 0xe);
            } else if (v == *(s32*)(lbl_80464550 + 0x3c)) {
                fn_8010F478(this_, 0xf);
            } else if (v == *(s32*)(lbl_80464550 + 0x40)) {
                fn_8010F478(this_, 0x10);
            } else if (v == *(s32*)(lbl_80464550 + 0x44)) {
                fn_8010F478(this_, 0x11);
            } else if (v == *(s32*)(lbl_80464550 + 0x48)) {
                fn_8010F478(this_, 0x12);
            } else if (v == *(s32*)(lbl_80464550 + 0x4c)) {
                fn_8010F478(this_, 0x13);
            } else if (v == *(s32*)(lbl_80464550 + 0x50)) {
                fn_8010F478(this_, 0x14);
            } else if (v == *(s32*)(lbl_80464550 + 0x54)) {
                fn_8010F478(this_, 0x15);
            } else if (v == *(s32*)(lbl_80464550 + 0x58)) {
                fn_8010F478(this_, 0x16);
            } else if (v == *(s32*)(lbl_80464550 + 0x5c)) {
                fn_8010F478(this_, 0x17);
            } else if (v == *(s32*)(lbl_80464550 + 0x60)) {
                fn_8010F478(this_, 0x18);
            } else if (v == *(s32*)(lbl_80464550 + 0x64)) {
                fn_8010F478(this_, 0x19);
            } else if (v == *(s32*)(lbl_80464550 + 0x68)) {
                fn_8010F478(this_, 0x1a);
            } else if (v == *(s32*)(lbl_80464550 + 0x6c)) {
                fn_8010F478(this_, 0x1b);
            } else if (v == *(s32*)(lbl_80464550 + 0x70)) {
                fn_8010F478(this_, 0x1c);
            } else if (v == *(s32*)(lbl_80464550 + 0x74)) {
                fn_8010F478(this_, 0x1d);
            } else if (v == *(s32*)(lbl_80464550 + 0x78)) {
                fn_8010F478(this_, 0x1e);
            } else if (v == *(s32*)(lbl_80464550 + 0x7c)) {
                fn_8010F478(this_, 0x1f);
            } else if (v == *(s32*)(lbl_80464550 + 0x80)) {
                fn_8010F478(this_, 0x20);
            } else if (v == *(s32*)(lbl_80464550 + 0x84)) {
                fn_8010F478(this_, 0x21);
            } else if (v == *(s32*)(lbl_80464550 + 0x88)) {
                fn_8010F478(this_, 0x22);
            } else if (v == *(s32*)(lbl_80464550 + 0x8c)) {
                fn_8010F478(this_, 0x23);
            } else if (v == *(s32*)(lbl_80464550 + 0x94)) {
                fn_8010F478(this_, 0x3e);
            }
        }
        break;
    case 2:
        a = fn_8011921C();
        switch (*(s32*)((u8*)a + 4)) {
        case 0xf:
            if (v == *(s32*)(lbl_80464550 + 0x98)) {
                fn_8010F478(this_, 0x26);
            } else if (v == *(s32*)(lbl_80464550 + 0x9c)) {
                fn_8010F478(this_, 0x27);
            } else if (v == *(s32*)(lbl_80464550 + 0xa0)) {
                fn_8010F478(this_, 0x28);
            } else if (v == *(s32*)(lbl_80464550 + 0xa4)) {
                fn_8010F478(this_, 0x29);
            } else if (v == *(s32*)(lbl_80464550 + 0xa8)) {
                fn_8010F478(this_, 0x2a);
            } else if (v == *(s32*)(lbl_80464550 + 0xac)) {
                fn_8010F478(this_, 0x2b);
            } else if (v == *(s32*)(lbl_80464550 + 0xb0)) {
                fn_8010F478(this_, 0x2c);
            } else if (v == *(s32*)(lbl_80464550 + 0xb4)) {
                fn_8010F478(this_, 0x2d);
            } else if (v == *(s32*)(lbl_80464550 + 0xb8)) {
                fn_8010F478(this_, 0x2e);
            } else if (v == *(s32*)(lbl_80464550 + 0xbc)) {
                fn_8010F478(this_, 0x2f);
            }
            break;
        case 0xe:
            break;
        case 0xd:
            if (v == *(s32*)(lbl_80464550 + 0xc0)) {
                fn_8010F478(this_, 0x30);
            } else if (v == *(s32*)(lbl_80464550 + 0xc8)) {
                fn_8010F478(this_, 0x32);
            } else if (v == *(s32*)(lbl_80464550 + 0xcc)) {
                fn_8010F478(this_, 0x33);
            } else if (v == *(s32*)(lbl_80464550 + 0xd0)) {
                fn_8010F478(this_, 0x34);
            } else if (v == *(s32*)(lbl_80464550 + 0xd4)) {
                fn_8010F478(this_, 0x35);
            } else if (v == *(s32*)(lbl_80464550 + 0xd8)) {
                fn_8010F478(this_, 0x36);
            } else if (v == *(s32*)(lbl_80464550 + 0xdc)) {
                fn_8010F478(this_, 0x37);
            } else if (v == *(s32*)(lbl_80464550 + 0xe0)) {
                fn_8010F478(this_, 0x38);
            } else if (v == *(s32*)(lbl_80464550 + 0xe4)) {
                fn_8010F478(this_, 0x39);
            } else if (v == *(s32*)(lbl_80464550 + 0xe8)) {
                fn_8010F478(this_, 0x3a);
            } else if (v == *(s32*)(lbl_80464550 + 0xec)) {
                fn_8010F478(this_, 0x3b);
            } else if (v == *(s32*)(lbl_80464550 + 0xf0)) {
                fn_8010F478(this_, 0x3c);
            } else if (v == *(s32*)(lbl_80464550 + 0xf4)) {
                fn_8010F478(this_, 0x3d);
            }
            break;
        }
        break;
    }
}

extern "C" void fn_80110198(u8* this_) {
    fn_8010DF58(this_);
    if (this_[0x230] == 0) {
        if (*(s32*)(this_ + 0x2fc) >= 0x13) {
            fn_8010F7EC(this_, 0x21b);
        } else if (*(s32*)(this_ + 0x2fc) >= 0xf) {
            fn_8010F7EC(this_, 0x274);
        } else {
            fn_8010F7EC(this_, 0x9b);
        }
    }
}

extern "C" void fn_8030C210(void* p, void* q);
extern "C" u8* lbl_8053AB10;
extern "C" Vec* fn_8023E724(s32);
extern "C" s32 fn_801CD950(f32*, f32, f32);
extern const f32 lbl_8053C598;
extern const f32 lbl_8053C5D8;
extern const f32 lbl_8053C5DC;
extern const f32 lbl_8053C5E0;
extern const f32 lbl_8053C5E4;
extern const f32 lbl_8053C594;
extern const f32 lbl_8053C5A0;

static inline f32 DMZLShiftY(f32 y, const f32 offset) { y += offset; return y; }
static inline void DMZLSetBox(const f32 x0, const f32 y0, const f32 x1, const f32 y1, const f32 offset = lbl_8053C550, const f32 speed = lbl_8053C5D0) {
    u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
    if (obj[0x840] == 0) {
        obj[0x840] = 1;
        *(f32*)(obj + 0x844) = x0;
        *(f32*)(obj + 0x848) = y0;
        *(f32*)(obj + 0x84c) = x1;
        *(f32*)(obj + 0x850) = y1;
        *(f32*)(obj + 0x854) = offset;
        *(f32*)(obj + 0x1d4) = speed;
        *(f32*)(obj + 0x1d8) = speed;
    }
}
static inline void DMZLSetBoxAlt(const f32 x0, const f32 y0, const f32 x1, const f32 y1, const f32 offset = lbl_8053C550, const f32 speed = lbl_8053C5D0) {
    u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
    if (obj[0x7f5] == 0) {
        obj[0x7f4] = 1;
        *(s32*)(obj + 0x7f8) = 5;
        *(f32*)(obj + 0x808) = x0;
        *(f32*)(obj + 0x80c) = y0;
        *(f32*)(obj + 0x810) = x1;
        *(f32*)(obj + 0x814) = y1;
        obj[0x7f6] = 0;
    }
}

extern "C" void fn_80110210(u8* this_) {
    u8* obj;
    Vec tmp;
    f32 x;
    f32 sum;
    f32 f274;
    f32 d0;
    f32 d1;

    switch (*(s32*)(this_ + 0x238)) {
    case 38:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        break;
    case 39:
    case 40:
    case 41:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
        sum = *(f32*)(this_ + 0x10) + *(f32*)(this_ + 0x278);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        f274 = *(f32*)(this_ + 0x274);
        d0 = sum - f274;
        d1 = f274 + sum;
        x = *(f32*)(this_ + 0xc);
        if (obj[0x7f5] == 0) {
            obj[0x7f4] = 1;
            *(s32*)(obj + 0x7f8) = 5;
            *(f32*)(obj + 0x808) = x;
            *(f32*)(obj + 0x80c) = d0;
            *(f32*)(obj + 0x810) = x;
            *(f32*)(obj + 0x814) = d1;
            obj[0x7f6] = 0;
        }
        break;
    case 42:
    case 43:
    case 44:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
        sum = *(f32*)(this_ + 0x10) + *(f32*)(this_ + 0x278);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        f274 = *(f32*)(this_ + 0x274);
        d0 = sum - f274;
        d1 = f274 + sum;
        x = *(f32*)(this_ + 0xc);
        if (obj[0x7f5] == 0) {
            obj[0x7f4] = 1;
            *(s32*)(obj + 0x7f8) = 5;
            *(f32*)(obj + 0x808) = x;
            *(f32*)(obj + 0x80c) = d0;
            *(f32*)(obj + 0x810) = x;
            *(f32*)(obj + 0x814) = d1;
            obj[0x7f6] = 0;
        }
        break;
    case 45:
    case 46:
    case 47:
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        if (obj[0x7f4] == 0) {
            obj[0x7f5] = 1;
        }
        break;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
        f274 = *(f32*)(this_ + 0x274);
        sum = *(f32*)(this_ + 0x10);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        d0 = sum - f274;
        d1 = sum + f274;
        x = *(f32*)(this_ + 0xc);
        if (obj[0x840] == 0) {
            obj[0x840] = 1;
            *(f32*)(obj + 0x844) = x;
            *(f32*)(obj + 0x848) = d0;
            *(f32*)(obj + 0x84c) = x;
            *(f32*)(obj + 0x850) = d1;
            *(f32*)(obj + 0x854) = lbl_8053C550;
            *(f32*)(obj + 0x1d4) = lbl_8053C5D0;
            *(f32*)(obj + 0x1d8) = lbl_8053C5D0;
        }
        break;
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x17c) = 1;
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
        tmp = *(Vec*)(this_ + 0x24);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        sum = tmp.y + *(f32*)(this_ + 0x278);
        f274 = *(f32*)(this_ + 0x274);
        tmp.y = sum;
        if (obj[0x7f5] == 0) {
            obj[0x7f4] = 1;
            *(s32*)(obj + 0x7f8) = 5;
            *(f32*)(obj + 0x808) = tmp.x;
            *(f32*)(obj + 0x80c) = sum - f274;
            *(f32*)(obj + 0x810) = tmp.x;
            *(f32*)(obj + 0x814) = sum + f274;
            obj[0x7f6] = 0;
        }
        break;
    case 59:
    case 60:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        break;
    }
}

extern "C" void fn_80110454(u8* p) {
    switch (*(s32*)(p + 0x238)) {
    case 3: case 4: case 5: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *fn_8023E724(0);
        tmp.y = DMZLShiftY(tmp.y, lbl_8053C5D8);
        DMZLSetBox(tmp.x, tmp.y - 96.0f, tmp.x, 96.0f + tmp.y);
        break;
    }
    case 6: case 7: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *fn_8023E724(0);
        tmp.y = DMZLShiftY(tmp.y, *(f32*)(p + 0x278));
        DMZLSetBoxAlt(tmp.x, tmp.y - 96.0f, tmp.x, 96.0f + tmp.y);
        break;
    }
    case 8: case 9: case 10: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *fn_8023E724(0);
        fn_801CD950((f32*)(p + 0x278), lbl_8053C5D8, lbl_8053C550);
        tmp.y = DMZLShiftY(tmp.y, *(f32*)(p + 0x278));
        DMZLSetBoxAlt(tmp.x, tmp.y - 96.0f, tmp.x, 96.0f + tmp.y);
        break;
    }
    case 11: case 12: case 13:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x17d) = 1;

        break;
    case 14: case 15: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x17c) = 1;

        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *(Vec*)(p + 0x24);
        tmp.y += lbl_8053C5A0;
        DMZLSetBox(tmp.x, tmp.y - 180.0f, tmp.x, 180.0f + tmp.y);
        break;
    }
    case 16: case 17: case 18: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        DMZLSetBox(*(f32*)(p + 0x24), *(f32*)(p + 0x28) - 80.0f, *(f32*)(p + 0x24), 80.0f + *(f32*)(p + 0x28));
        break;
    }
    case 19: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        DMZLSetBox(*(f32*)(p + 0x2d0), *(f32*)(p + 0x2d4) - 80.0f, *(f32*)(p + 0x2d0), 80.0f + *(f32*)(p + 0x2d4));
        break;
    }
    case 20: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *(Vec*)(p + 0xc);
        tmp.y += lbl_8053C5E4;
        DMZLSetBox(tmp.x, tmp.y - 130.0f, tmp.x, 130.0f + tmp.y);
        break;
    }
    case 21: case 22: case 23: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *(Vec*)(p + 0xc);
        tmp.y += lbl_8053C5E4;
        DMZLSetBoxAlt(tmp.x, tmp.y - 130.0f, tmp.x, 130.0f + tmp.y);
        break;
    }
    case 24: case 25: case 26: case 27: case 28: {
        u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
        if (obj[0x179] == 0) {
            obj[0x17a] = 1;
            obj[0x179] = 0;
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        if (obj[0x840] == 0) {
            obj[0x840] = 1;
            f32 x = *(f32*)(p + 0xc);
            *(f32*)(obj + 0x84c) = x;
            *(f32*)(obj + 0x844) = x;
            f32 y = *(f32*)(p + 0x10);
            *(f32*)(obj + 0x850) = y;
            *(f32*)(obj + 0x848) = y;
            *(f32*)(obj + 0x854) = lbl_8053C550;
            *(f32*)(obj + 0x1d4) = lbl_8053C5D0;
            *(f32*)(obj + 0x1d8) = lbl_8053C5D0;
        }
        break;
    }
    }
}

extern "C" void fn_8011093C(void* this_) {
    JGeometry::TBox2<f32> box;
    JGeometry::TVec3<f32> argPos;
    JGeometry::TVec3<f32> pos;
    JGeometry::TBox2<f32> box2;
    f32 dist;
    s32 out;
    s32 quad;
    u16 angle;
    s32 i;
    s32 result;
    u8* p = (u8*)this_;
    box.set(*(JGeometry::TBox2<f32>*)(p + 0x60));
    box.addPos(*(JGeometry::TVec2<f32>*)(p + 0xc));
    if (p[0x231]) fn_80239914(&box, *(s32*)(p + 4), *(s32*)(p + 0x198));
    fn_80110210(p);
    switch (*(u32*)(p + 0x238)) {
    case 2:
        fn_8022FF8C(*(s32*)(p + 0x23c), &box, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x23c), *(s32*)(p + 0x198))) {
            *(s32*)(p + 0x23c) = -1;
            switch (*(s32*)(p + 0x234)) {
            case 0: case 1: fn_8010E7E8(p, 0x3d); break;
            case 2: fn_8010E2D4(p, 0x3d); break;
            case 3: break;
            }
            *(s32*)(p + 0x238) = 0x3d;
        }
        break;
    case 13:
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 14:
        fn_801CD950((f32*)(p + 0x14), lbl_8053C554, lbl_8053C5E8);
        fn_801CD950((f32*)(p + 0x274), lbl_8053C5EC, lbl_8053C564);
        if (fn_801D208C(p + 0x2f4)) {
            fn_801D22DC(p + 0x2f4, 0x13, 2, 0);
            fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        }
        break;
    case 19:
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 25:
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 26:
        if (fn_801CD950((f32*)(p + 0x14), *(f32*)(p + 0x2c), lbl_8053C5F0) == 0 && *(s32*)(p + 0x2fc) == 0x13) {
            fn_801D22DC(p + 0x2f4, 0x17, 0, 0);
            fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        }
        if (fn_801D208C(p + 0x2f4) && *(s32*)(p + 0x2fc) == 0x17) {
            fn_801D22DC(p + 0x2f4, 0x19, 0, 0);
            fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        }
        break;
    case 28:
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 29:
        fn_801CD950((f32*)(p + 0x278), lbl_8053C5F4, lbl_8053C5F8);
        fn_801CD950((f32*)(p + 0x274), lbl_8053C594, lbl_8053C560);
        break;
    case 41:
        fn_801CD950((f32*)(p + 0xc), lbl_8053C59C + *(f32*)(p + 0x24), lbl_8053C58C);
        break;
    case 1:
        fn_801EEC98(p, *(s32*)(p + 0x198), &angle, &quad, &dist, &out, 0, 2);
        s32 value = quad;
        if (value >= 0 && !(dist > lbl_8053C5E0) && value >= 0) {
            *(s32*)(p + 0x98) = value;
            s32 anim = value + 6;
            if (anim != *(s32*)(p + 0x2fc)) {
                fn_801D22DC(p + 0x2f4, anim, 2, 0);
                fn_801D1F14(p + 0x2f4, lbl_8053C55C);
            }
        }
        box2.set(*(JGeometry::TBox2<f32>*)(p + 0x60));
        box2.addPos(*(JGeometry::TVec2<f32>*)(p + 0xc));
        fn_8022FEB8(&box2, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        result = fn_8022FD8C(*(void**)(p + 0x198));
        if (result < 0 || result >= 4) { result = -1; goto checked; }
        if (!fn_802300EC(result)) { result = -1; goto checked; }
        if (!fn_8023F264(result)) { result = -1; goto checked; }
        pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
        pos.y += lbl_8053C570;
        s32 handle = *(s32*)(p + 0x198);
        s32 room = *(s32*)(p + 4);
        argPos = pos;
        if (!fn_8038AD24(result, 0x2d2, handle, room, &argPos, 0x20)) { result = -1; goto checked; }
        *(s32*)(p + 0x23c) = result;
        s32 anim2 = fn_801CD354(fn_80230CFC(*(s32*)(p + 0x23c))) + 6;
        fn_801D22DC(p + 0x2f4, anim2, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        for (i = 0; i < 4; i++) fn_80230C6C(i);
    checked:
        if (result >= 0) {
            switch (*(s32*)(p + 0x234)) {
            case 0: case 1: fn_8010E7E8(p, 2); break;
            case 2: fn_8010E2D4(p, 2); break;
            case 3: break;
            }
            *(s32*)(p + 0x238) = 2;
        }
        break;
    case 62:
        break;
    }
}

extern "C" void fn_801186B0(void*,s32);
extern const f32 lbl_8053C558;
extern const f32 lbl_8053C574;
extern const f32 lbl_8053C578;
extern const f32 lbl_8053C57C;
extern const f32 lbl_8053C580;
extern const f32 lbl_8053C584;
extern "C" void fn_80110E9C(u8* this_) {
JGeometry::TVec3<f32>* v;
s32 j;
s32 i;
JGeometry::TBox2<f32> box;
JGeometry::TVec3<f32> argPos,pos;
JGeometry::TBox2<f32> box2;
JGeometry::TVec3<f32> a,b,c,d,e,f,g;
f32 dist;
s32 out,quad;
u16 angle;
f32 zero,dz;
f32 sine,speed;
s32 result,kind;
register u8* p=this_;
box.set(*(const JGeometry::TBox2<f32>*)(p+0x60));box.addPos(*(JGeometry::TVec2<f32>*)(p+0xc));
if(*(s32*)(p+0x238)==1 || *(s32*)(p+0x238)==2)fn_80239914(&box,*(s32*)(p+4),*(s32*)(p+0x198));
fn_80110454(p);
switch(*(u32*)(p+0x238)){
case 1:
fn_80458FF0(lbl_8053AF80,0x100000e,0,0);
if(*(s32*)(p+0x234)==1){fn_801186B0(fn_8011921C(),1);break;}
if(*(s32*)(p+0x234)==0){fn_801186B0(fn_8011921C(),0);break;}
kind=0;
if(*(s32*)(p+0x234)!=1){
fn_801EEC98(p,*(s32*)(p+0x198),&angle,&quad,&dist,&out,0,2);
s32 value=quad;
if(value>=0 && !(dist>lbl_8053C5E0) && value>=0){*(s32*)(p+0x98)=value;s32 n=value+6;if(n!=*(s32*)(p+0x2fc)){fn_801D22DC(p+0x2f4,n,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}}
}else{kind=1;}
s32 effect=lbl_8053C548[*(s32*)(p+0x234)];
box2.set(*(JGeometry::TBox2<f32>*)(p+0x60));box2.addPos(*(JGeometry::TVec2<f32>*)(p+0xc));
fn_8022FEB8(&box2,*(s32*)(p+4),*(s32*)(p+0x198),1,kind);
result=fn_8022FD8C(*(void**)(p+0x198));
if(result<0 || result>=4){result=-1;goto checked;}
if(!fn_802300EC(result)){result=-1;goto checked;}
if(!fn_8023F264(result)){result=-1;goto checked;}
pos=*(JGeometry::TVec3<f32>*)(p+0xc);pos.y+=lbl_8053C570;
s32 handle=*(s32*)(p+0x198),room=*(s32*)(p+4);argPos=pos;
if(!fn_8038AD24(result,effect,handle,room,&argPos,0x20)){result=-1;goto checked;}
*(s32*)(p+0x23c)=result;
s32 anim2=fn_801CD354(fn_80230CFC(*(s32*)(p+0x23c)))+6;
fn_801D22DC(p+0x2f4,anim2,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);
for(i=0;i<4;i++)fn_80230C6C(i);
checked:if(result>=0){switch (*(s32*)(p+0x234)) {case 0: case 1: fn_8010E7E8(p,2);break;case 2:fn_8010E2D4(p,2);break;case 3:break;} *(s32*)(p+0x238)=2;}break;
case 2:
fn_8022FF8C(*(s32*)(p+0x23c),&box,*(s32*)(p+4),*(s32*)(p+0x198),1,0);
if(fn_80388CAC(*(s32*)(p+0x23c),*(s32*)(p+0x198))){
*(s32*)(p+0x23c)=-1;
switch(*(s32*)(p+0x234)){
case 0:switch (*(s32*)(p+0x234)) {case 0: case 1: fn_8010E7E8(p,13);break;case 2:fn_8010E2D4(p,13);break;case 3:break;} *(s32*)(p+0x238)=13; switch (*(s32*)(p+0x234)) {case 0: case 1: fn_8010E7E8(p,62);break;case 2:fn_8010E2D4(p,62);break;case 3:break;} *(s32*)(p+0x238)=62; break;
case 1:break;
default:switch (*(s32*)(p+0x234)) {case 0: case 1: fn_8010E7E8(p,1);break;case 2:fn_8010E2D4(p,1);break;case 3:break;} *(s32*)(p+0x238)=1;break;
}}break;
case 4:*(f32*)(p+0x324)=lbl_8053C550;
if(fn_801CD950((f32*)(p+0x10),fn_8023E724(0)->y-lbl_8053C554,lbl_8053C558)==0){fn_801D22DC(p+0x2f4,2,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);*(f32*)(p+0x324)=lbl_8053C550;}break;
case 5:fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);if(fn_803865B8(0)){fn_80388EEC(0);fn_8011921C();fn_801183BC();}break;
case 7:fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);if(fn_803865B8(0)){fn_80388EEC(0);fn_8011921C();fn_801183BC();}break;
case 9:fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);if(fn_803865B8(0)){fn_80388EEC(0);fn_8011921C();fn_801183BC();}break;
case 11:fn_801CD950((f32*)(p+0x10),fn_8023E724(0)->y-lbl_8053C5B0,lbl_8053C558);j=0;v=&a;for(;j<4;j++){*v=*(JGeometry::TVec3<f32>*)fn_8023E724(j);if(v->y <= *(f32*)(p+0x2e0)){v->y=*(f32*)(p+0x2e0);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,0x3f,255,-128,-128,1);}else{*v+=*(JGeometry::TVec3<f32>*)(p+0x2e8);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,*(s32*)(p+0x33c),255,-128,-128,1);}}break;
case 12:fn_801CD950((f32*)(p+0x10),fn_8023E724(0)->y-lbl_8053C5B0,lbl_8053C558);j=0;v=&b;for(;j<4;j++){*v=*(JGeometry::TVec3<f32>*)fn_8023E724(j);if(v->y <= *(f32*)(p+0x2e0)){v->y=*(f32*)(p+0x2e0);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,0x3f,255,-128,-128,1);}else{*v+=*(JGeometry::TVec3<f32>*)(p+0x2e8);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,*(s32*)(p+0x33c),255,-128,-128,1);}}break;
case 14:if(*(s32*)((u8*)fn_8011921C()+8)>=30){j=0;v=&c;for(;j<4;j++){*v=*(JGeometry::TVec3<f32>*)fn_8023E724(j);if(v->y <= *(f32*)(p+0x2e0)){v->y=*(f32*)(p+0x2e0);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,0x3f,255,-128,-128,1);}else{*v+=*(JGeometry::TVec3<f32>*)(p+0x2e8);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,*(s32*)(p+0x33c),255,-128,-128,1);}}*(JGeometry::TVec3<f32>*)(p+0xc)+=*(JGeometry::TVec3<f32>*)(p+0x2e8);}break;
case 15:j=0;v=&d;for(;j<4;j++){*v=*(JGeometry::TVec3<f32>*)fn_8023E724(j);if(v->y <= *(f32*)(p+0x2e0)){v->y=*(f32*)(p+0x2e0);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,0x3f,255,-128,-128,1);}else{*v+=*(JGeometry::TVec3<f32>*)(p+0x2e8);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,*(s32*)(p+0x33c),255,-128,-128,1);}}*(JGeometry::TVec3<f32>*)(p+0xc)+=*(JGeometry::TVec3<f32>*)(p+0x2e8);break;
case 16:j=0;v=&e;for(;j<4;j++){*v=*(JGeometry::TVec3<f32>*)fn_8023E724(j);if(v->y <= *(f32*)(p+0x2e0)){v->y=*(f32*)(p+0x2e0);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,0x3f,255,-128,-128,1);}else{*v+=*(JGeometry::TVec3<f32>*)(p+0x2e8);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,*(s32*)(p+0x33c),255,-128,-128,1);}}*(JGeometry::TVec3<f32>*)(p+0xc)+=*(JGeometry::TVec3<f32>*)(p+0x2e8);if(*(f32*)(p+0x10)<=*(f32*)(p+0x28)){*(f32*)(p+0x10)=*(f32*)(p+0x28);fn_801D22DC(p+0x2f4,2,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}break;
case 17:fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);if(fn_803865B8(0)){fn_80388EEC(0);fn_8011921C();fn_801183BC();}break;
case 18:j=0;v=&f;for(;j<4;j++){*v=*(JGeometry::TVec3<f32>*)fn_8023E724(j);if(v->y >= *(f32*)(p+0x2e0)){v->y=*(f32*)(p+0x2e0);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,0x3f,255,-128,-128,1);}else{*v+=*(JGeometry::TVec3<f32>*)(p+0x2e8);((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,v,*(s32*)(p+0x33c),255,-128,-128,1);}}break;
case 21:if(fn_801D208C(p+0x2f4)){fn_801D22DC(p+0x2f4,19,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}break;
case 26:fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);if(fn_803865B8(0)){fn_80388EEC(0);fn_8011921C();fn_801183BC();fn_80458FF0(lbl_8053AF80,0x100001f,1,0);}break;
case 31:fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);if(fn_803865B8(0)){fn_80388EEC(0);fn_8011921C();fn_801183BC();}break;
case 32:switch(*(s32*)(p+0x260)){case 0:case 90:case 110:case 130:
switch(*(s32*)(p+0x2fc)){case 9:case 11:case 13:fn_801D22DC(p+0x2f4,10,0,0);break;default:fn_801D22DC(p+0x2f4,11,0,0);break;}
fn_801D1F14(p+0x2f4,lbl_8053C55C);break;}
++*(s32*)(p+0x260);break;
case 33:s32 elapsed=DMZLElapsed(fn_8011921C(),lbl_80464550);f32 t=elapsed;dz=lbl_8053C560-lbl_8053C564*t;zero=lbl_8053C55C;
for(s32 j=0;j<4;j++){g=*(JGeometry::TVec3<f32>*)fn_8023E724(j);g.z+=dz;if(g.z<=zero)g.z=zero;else g.y+=lbl_8053C560;((void(*)(s32,void*,s32,s32,s32,s32,s32))fn_80230498)(j,&g,0x3f,255,-128,-128,1);}break;
case 35:
*(f32*)(p+0x268)+=lbl_8053C578;
fn_801CD950((f32*)(p+0x26c),lbl_8053C560,lbl_8053C57C);
s16 ang=DMZLAngle(*(f32*)(p+0x27c)-*(f32*)(p+0xc),*(f32*)(p+0x280)-*(f32*)(p+0x10));
sine=JMASSin(ang);speed=*(f32*)(p+0x26c);*(f32*)(p+0x3c)=speed*sine;
*(f32*)(p+0x40)=*(f32*)(p+0x26c)*JMASCos(ang);
s32 x=fn_801CD950((f32*)(p+0xc),*(f32*)(p+0x27c),*(f32*)(p+0x3c));
s32 y=fn_801CD950((f32*)(p+0x10),*(f32*)(p+0x280),*(f32*)(p+0x40));
fn_801CD950((f32*)(p+0x270),lbl_8053C57C,lbl_8053C584);
bool done;
if(x==0 && y==0)done=true;else done=false;
if(done){switch (*(s32*)(p+0x234)) {case 0: case 1: fn_8010E7E8(p,36);break;case 2:fn_8010E2D4(p,36);break;case 3:break;} *(s32*)(p+0x238)=36;}break;
case 36:fn_801CD950((f32*)(p+0x270),lbl_8053C55C,lbl_8053C574);break;
case 62:p[0x11d]=0;break;
}}

extern "C" void fn_80111CC0(u8* this_) {
    fn_8010DF78(this_);
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
    case 1:
        fn_80110E9C(this_);
        break;
    case 2:
        fn_8011093C(this_);
        break;
    case 3:
        break;
    }
    fn_801D1C18(this_ + 0x2f4);
    fn_801D1C18(this_ + 0x32c);
    if (this_[0x230] != 0) {
        fn_8010F4DC(this_);
    }
}

#pragma opt_propagation off
extern "C" void fn_80111D44(void* param) {
    u8* this_=(u8*)param;
    u32 tag;
    u8* list;
    u8** it;
    u8* elem;
    s32 idx;
    list = (u8*)fn_8011921C();
    it = (u8**)fn_8011871C(list, *(void**)(list + 0x10), 0x444d474c);
    if (it != *(u8***)((u8*)fn_8011921C() + 0x14)) {
        *(JGeometry::TVec3<f32>*)(this_ + 0x27c) = *(JGeometry::TVec3<f32>*)(*it + 0xc);
    }
    void* first = *(void**)((u8*)fn_8011921C() + 0x10);
    tag = 0x444d0000;
    void* registry = fn_8011921C();
    it = (u8**)fn_8011871C(registry, first, tag + 0x4d44);
    if (it != *(u8***)((u8*)fn_8011921C() + 0x14)) {
        do {
            elem = *it;
            idx = *(s32*)(elem + 0x234);
            if (idx < 6) {
                *(JGeometry::TVec3<f32>*)(this_ + 0x288 + idx * 12) = *(JGeometry::TVec3<f32>*)(elem + 0xc);
                it++;
            }
        } while (it != *(u8***)((u8*)fn_8011921C() + 0x14));
    }
    *(JGeometry::TVec3<f32>*)(this_ + 0x2d0) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
}
#pragma opt_propagation reset
extern "C" void fn_8010DF98(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void*, s32);
extern "C" char lbl_8049D1A0[];
extern "C" void* lbl_80539EF8;
extern "C" const f32 lbl_8053C55C;
extern "C" void fn_80111E38(u8* this_) {
    fn_8010DF98(this_);
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xff;
    *(u32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    *(u32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 17) & 0x1f;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    fn_801D2608(this_ + 0x2f4, lbl_8049D1A0, 0x1a);
    fn_801D22DC(this_ + 0x2f4, 8, 2, 0);
    fn_801D1F14(this_ + 0x2f4, lbl_8053C55C);
    fn_801D2608(this_ + 0x32c, (void*)&lbl_80539EF8, 2);
    fn_801D22DC(this_ + 0x32c, 0, 2, 0);
    fn_801D1F14(this_ + 0x32c, lbl_8053C55C);
    if (*(s32*)(this_ + 0x234) == 2) {
        if (fn_802D800C(fn_802D6A9C(), *(s32*)(this_ + 0x250))) {
            switch (*(s32*)(this_ + 0x234)) {
            case 0:
            case 1:
                fn_8010E7E8(this_, 0x3d);
                break;
            case 2:
                fn_8010E2D4(this_, 0x3d);
                break;
            case 3:
            default:
                break;
            }
            *(s32*)(this_ + 0x238) = 0x3d;
        } else {
            this_[0x11d] = 0;
        }
    }
}

extern "C" void* fn_80111F74(char* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_8049D208;
        fn_801EE434(*(void**)(p + 0x364));
        *(s32*)(p + 0x364) = 0;
        fn_801EE434(*(void**)(p + 0x368));
        *(s32*)(p + 0x368) = 0;
        fn_801EE434(*(void**)(p + 0x36c));
        *(s32*)(p + 0x36c) = 0;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x370 + i * 4));
            *(s32*)(p + 0x370 + i * 4) = 0;
            if (i < 2) {
                fn_801EE434(*(void**)(p + 0x380 + i * 4));
                *(s32*)(p + 0x380 + i * 4) = 0;
            }
        }
        if (p + 0x32c != 0) {
            if (p + 0x350 != 0) {
                *(void**)(p + 0x350) = lbl_8049CC34;
            }
        }
        if (p + 0x2f4 != 0) {
            if (p + 0x318 != 0) {
                *(void**)(p + 0x318) = lbl_8049CC34;
            }
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_8010E074(void* this_);
extern "C" void fn_801D267C(void* this_);
extern const f32 lbl_8053C55C;
extern const f32 lbl_8053C5FC;
extern const f32 lbl_8053C598;
extern void __construct_array(void* p, void* ctor, void* dtor, s32 size, s32 count);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
extern "C" void __construct_array(void*, void*, void*, long, long);
extern "C" void* fn_80112070(u8* this_) {
    fn_8010E074(this_);
    *(void**)this_ = lbl_8049D208;
    this_[0x230] = 0;
    this_[0x231] = 0;
    *(s32*)(this_ + 0x234) = 4;
    *(s32*)(this_ + 0x238) = 1;
    *(s32*)(this_ + 0x23c) = -1;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = -1;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(f32*)(this_ + 0x268) = lbl_8053C55C;
    *(f32*)(this_ + 0x26c) = lbl_8053C55C;
    *(f32*)(this_ + 0x270) = lbl_8053C5FC;
    *(f32*)(this_ + 0x274) = lbl_8053C598;
    *(f32*)(this_ + 0x278) = lbl_8053C55C;
    __construct_array(this_ + 0x288, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 7);
    fn_801D267C(this_ + 0x2f4);
    fn_801D267C(this_ + 0x32c);
    *(s32*)(this_ + 0x364) = 0;
    *(s32*)(this_ + 0x368) = 0;
    *(s32*)(this_ + 0x36c) = 0;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(this_ + 0x370 + i * 4) = 0;
        if (i < 2) {
            *(s32*)(this_ + 0x380 + i * 4) = 0;
        }
    }
    return this_;
}

extern "C" void fn_8010E2D4(void* this_, s32 param) {
    u8* p = (u8*)this_;
    switch ((u32)param) {
    case 0:
    case 1:
    case 2:
        fn_801C0D70();
        fn_801C11A4();
        break;
    case 3:
    case 4: {
        u8* q = (u8*)fn_8011921C();
        q[2] = 1;
        *(f32*)(p + 0x274) = lbl_8053C594;
        *(f32*)(p + 0x278) = lbl_8053C554;
        break;
    }
    case 5:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C550, 0x4d3, 0, 0, 0, 0, 1);
    case 6:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C550, 0x4d4, 0, 0, 0, 0, 1);
    case 7:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C550, 0x4d5, 0, 0, 0, 0, 1);
    case 8:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C550, 0x4d6, 0, 0, 0, 0, 1);
    case 9:
    case 10:
        fn_801F0E34(p, 0x30079, 0);
        break;
    case 11:
        p[0x11d] = 1;
        *(u16*)fn_801C0D70() |= 0x800;
        break;
    case 12:
    case 13: {
        Vec v;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        v.x = lbl_8053C55C;
        v.y = lbl_8053C570;
        v.z = lbl_8053C55C;
        if (fn_8038BD08(0, 0x2d4, *(s32*)(p + 4), &v, 0x4002)) {
            fn_8011921C();
            fn_80118454();
        }
        break;
    }
    case 14:
        fn_801D22DC(p + 0x2f4, 0xf, 0, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 15:
    case 16:
        fn_801D22DC(p + 0x2f4, 0x15, 0, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 17:
        fn_801D22DC(p + 0x2f4, 0x14, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        fn_801C0D70();
        fn_801C115C();
        break;
    case 18:
    case 19: {
        Vec v;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        v.x = lbl_8053C55C;
        v.y = lbl_8053C570;
        v.z = lbl_8053C55C;
        if (fn_8038BD08(0, 0x2d3, *(s32*)(p + 4), &v, 0x4002)) {
            fn_8011921C();
            fn_80118454();
        }
        break;
    }
    case 20:
        fn_801D22DC(p + 0x2f4, 0x13, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        *(u16*)fn_801C0D70() &= ~0x400;
        fn_8011921C();
        fn_80118384();
        *(s32*)(p + 0x264) = 0;
        break;
    case 21:
    case 22: {
        u8* q;
        *(f32*)(p + 0x274) = lbl_8053C598;
        fn_802D8050(fn_802D6A9C(), *(s32*)(p + 0x254), 1, 0xff);
        q = (u8*)fn_8011921C();
        q[2] = 1;
        fn_8011921C();
        fn_80118454();
        break;
    }
    case 23:
        fn_801D22DC(p + 0x2f4, 0x14, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        fn_8011921C();
        fn_801183BC();
        break;
    case 24:
    case 25: {
        Vec v;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        fn_8022FD8C(*(void**)(p + 0x198));
        v.x = lbl_8053C55C;
        v.y = lbl_8053C55C;
        v.z = lbl_8053C55C;
        fn_8038BD08(0, 0x2d1, *(s32*)(p + 4), &v, 0x22);
        fn_8011921C();
        fn_80118454();
        break;
    }
    case 26:
        fn_801D22DC(p + 0x2f4, 0x13, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        *(u16*)fn_801C0D70() &= ~0x1000;
        break;
    case 27:
    case 28: {
        Vec v;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        v.x = lbl_8053C55C;
        v.y = lbl_8053C570;
        v.z = lbl_8053C55C;
        if (fn_8038BD08(0, 0x2d5, *(s32*)(p + 4), &v, 0x4002)) {
            fn_8011921C();
            fn_80118454();
        }
        break;
    }
    case 29:
        *(s32*)(p + 0x24c) = 0;
        *(f32*)(p + 0x274) = lbl_8053C598;
        *(f32*)(p + 0x278) = lbl_8053C590;
        fn_801D22DC(p + 0x2f4, 0xd, 0, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 30:
    case 31:
        fn_801D22DC(p + 0x2f4, 0x12, 0, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 32:
    case 33:
    case 34:
        ((Actor*)this_)->v10(0xff, 1);
        break;
    case 35:
        fn_801D22DC(p + 0x2f4, 0x8, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 36:
    case 37:
        fn_801D22DC(p + 0x2f4, 0x0, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        *(f32*)(p + 0x324) = lbl_8053C58C;
        break;
    case 38:
    case 39:
    case 40:
        fn_801D22DC(p + 0x2f4, 0x8, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        *(f32*)(p + 0x324) = lbl_8053C550;
        break;
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
        p[0x231] = 1;
        fn_802D8050(fn_802D6A9C(), *(s32*)(p + 0x250), 1, 0xff);
        *(f32*)(p + 0xc) = lbl_8053C59C + *(f32*)(p + 0x24);
        break;
    }
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
extern "C" void fn_8010E7E8(void* this_, s32 state) {
u8* p=(u8*)this_;
JGeometry::TVec3<f32> dest3;
JGeometry::TVec3<f32> from4;
JGeometry::TVec3<f32> pos5;
JGeometry::TVec3<f32> pos6;
JGeometry::TVec3<f32> dest7;
JGeometry::TVec3<f32> from8;
JGeometry::TVec3<f32> dest10;
JGeometry::TVec3<f32> v0;
JGeometry::TVec3<f32> v1;
JGeometry::TVec3<f32> v2;
JGeometry::TVec3<f32> v9;
JGeometry::TVec3<f32> v11;
JGeometry::TVec3<f32> v14;
JGeometry::TVec3<f32> pos12;
JGeometry::TVec3<f32> pos13;
switch(state) {
case 3:{{u8* mgr=(u8*)fn_8011921C();mgr[2]=1;}fn_8043A450(lbl_8053AED0,0,3);}break;
case 4:{fn_801D22DC(p+0x2f4,2,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}break;
case 5:{fn_801D22DC(p+0x2f4,8,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);fn_8022FD8C(*(void**)(p+0x198));{v0.set(lbl_8053C55C,lbl_8053C570,lbl_8053C55C);fn_8038BD08(0,lbl_8053C548[*(s32*)(p+0x234)],*(s32*)(p+4),&v0,0x4022);}fn_8011921C();fn_80118454();}break;
case 6:{*(f32*)(p+0x278)=lbl_8053C5A0;}break;
case 7:{fn_801D22DC(p+0x2f4,14,0,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);*(f32*)(p+0x324)=lbl_8053C58C;fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);fn_8022FD8C(*(void**)(p+0x198));{v1.set(lbl_8053C55C,lbl_8053C5A4,lbl_8053C55C);fn_8038BD08(0,0x233,*(s32*)(p+4),&v1,0x4022);}fn_8011921C();fn_80118454();}break;
case 8:{fn_801D22DC(p+0x2f4,12,0,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);*(f32*)(p+0x324)=lbl_8053C58C;*(f32*)(p+0x278)=lbl_8053C5A8;}break;
case 9:{fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);fn_8022FD8C(*(void**)(p+0x198));{v2.set(lbl_8053C55C,lbl_8053C570,lbl_8053C55C);fn_8038BD08(0,0x234,*(s32*)(p+4),&v2,0x4022);}fn_8011921C();fn_80118454();}break;
case 10:{fn_801D22DC(p+0x2f4,13,0,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);*(f32*)(p+0x324)=lbl_8053C58C;}break;
case 11:{fn_801D22DC(p+0x2f4,3,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);((JGeometry::TVec3<f32>*)(p+0x2e8))->set(lbl_8053C55C,lbl_8053C5AC,lbl_8053C55C);{Vec* v=fn_8023E724(0);*(f32*)(p+0x2dc)=v->x;*(f32*)(p+0x2e0)=v->y;*(f32*)(p+0x2e4)=v->z;}*(f32*)(p+0x2e0)-=lbl_8053C5B0;}break;
case 12:{fn_80119998(fn_80119DD0(),90,0,2,0,0,60,0);}break;
case 13:{fn_802D9FF4(fn_802D6A9C(),*(s32*)(p+0x244),*(s32*)(p+0x248));fn_802DA8DC(fn_802D6A9C());}break;
case 14:{{u8* mgr=(u8*)fn_8011921C();mgr[2]=1;}{JGeometry::setTVec3f((f32*)((Vec*)(p+0x24)),&dest3.x);JGeometry::setTVec3f((f32*)(fn_8023E724(0)),&from4.x);from4.y+=lbl_8053C5B4;dest3.y+=lbl_8053C588;for(s32 i=0;i<4;i++){u16 a=fn_8023CBC0(i);fn_80230498(i,&from4,a,255,-128,-128,1);}{pos5=from4;pos5.y-=lbl_8053C588;((JGeometry::TVec3<f32>*)(p+0xc))->set(pos5);} fn_801D22DC(p+0x2f4,3,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C); *(f32*)(p+0x324)=lbl_8053C58C;*(JGeometry::TVec3<f32>*)(p+0x2dc)=dest3;*(JGeometry::TVec3<f32>*)(p+0x2e8)=DMZLDivide(dest3-from4,lbl_8053C5B8); fn_801D22DC(p+0x32c,0,2,0);fn_801D1F14(p+0x32c,lbl_8053C55C);}}break;
case 16:{{JGeometry::setTVec3f((f32*)(fn_8023E604(0)),&pos6.x);pos6.y-=lbl_8053C5B4;((JGeometry::TVec3<f32>*)(p+0xc))->set(pos6);}fn_801D22DC(p+0x2f4,3,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);*(f32*)(p+0x324)=lbl_8053C58C;{JGeometry::setTVec3f((f32*)((Vec*)(p+0x24)),&dest7.x);JGeometry::setTVec3f((f32*)(fn_8023E604(0)),&from8.x);dest7.y+=lbl_8053C588;from8.y-=lbl_8053C588;for(s32 i=0;i<4;i++){u16 a=fn_8023CBC0(i);fn_80230498(i,&from8,a,255,-128,-128,1);}*(JGeometry::TVec3<f32>*)(p+0x2dc)=dest7;*(JGeometry::TVec3<f32>*)(p+0x2e8)=DMZLDivide(dest7-from8,lbl_8053C5BC);fn_801D22DC(p+0x32c,0,2,0);fn_801D1F14(p+0x32c,lbl_8053C55C);}}break;
case 17:{fn_801D22DC(p+0x2f4,8,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);*(f32*)(p+0x324)=lbl_8053C550;fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);fn_8022FD8C(*(void**)(p+0x198));{v9.set(lbl_8053C55C,lbl_8053C570,lbl_8053C55C);fn_8038BD08(0,0x4b0,*(s32*)(p+4),&v9,0x4022);}fn_8011921C();fn_80118454();}break;
case 18:{{JGeometry::setTVec3f((f32*)((Vec*)(p+0xc)),&dest10.x);dest10.y+=lbl_8053C5C0;JGeometry::TVec3<f32>* from=(JGeometry::TVec3<f32>*)fn_8023E724(0);*(JGeometry::TVec3<f32>*)(p+0x2dc)=dest10;*(JGeometry::TVec3<f32>*)(p+0x2e8)=DMZLDivide(dest10-*from,lbl_8053C5C4);fn_801D22DC(p+0x32c,0,2,0);fn_801D1F14(p+0x32c,lbl_8053C55C);}}break;
case 19:{fn_8011921C();fn_801183BC();fn_801D22DC(p+0x2f4,15,0,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);{u8* mgr=(u8*)fn_8011921C();mgr[2]=1;}fn_80458FF0(lbl_8053AF80,0x100001b,0,0);}break;
case 21:{*(void**)(p+0x364)=((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,0x309,0,0,0,0,1);*(void**)(p+0x368)=((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,0x30a,0,0,0,0,1);((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,0x2e1,0,0,0,0,1);((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,0x2e2,0,0,0,0,1);((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,0x2e3,0,0,0,0,1);*(void**)(p+0x36c)=((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,0x2ea,0,0,0,0,1);fn_801D22DC(p+0x2f4,21,0,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}break;
case 22:{fn_801D22DC(p+0x2f4,20,2,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}break;
case 23:{{u8* e=*(u8**)(p+868);if(e){*(u32*)(e+0xf4)|=1;*(s32*)(e+0x24)=1;*(void**)(p+868)=0;}}{u8* e=*(u8**)(p+872);if(e){*(u32*)(e+0xf4)|=1;*(s32*)(e+0x24)=1;*(void**)(p+872)=0;}}{u8* e=*(u8**)(p+876);if(e){*(u32*)(e+0xf4)|=1;*(s32*)(e+0x24)=1;*(void**)(p+876)=0;}}fn_801D22DC(p+0x2f4,24,0,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}break;
case 25:{fn_801D22DC(p+0x2f4,22,0,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}break;
case 26:{fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);fn_8022FD8C(*(void**)(p+0x198));{v11.set(lbl_8053C55C,lbl_8053C570,lbl_8053C55C);fn_8038BD08(0,0x239,*(s32*)(p+4),&v11,0x4022);}fn_8011921C();fn_80118454();}break;
case 28:{{JGeometry::setTVec3f((f32*)((Vec*)(p+0xc)),&pos12.x);pos12.y+=lbl_8053C590;((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),&pos12,lbl_8053C550,0x33b,0,0,0,0,1);}fn_801F0E34(p,0x400b5,0);fn_801D22DC(p+0x2f4,13,0,0);fn_801D1F14(p+0x2f4,lbl_8053C55C);}break;
case 30:{{JGeometry::setTVec3f((f32*)((Vec*)(p+0xc)),&pos13.x);pos13.y+=lbl_8053C590;((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),&pos13,lbl_8053C550,0x33b,0,0,0,0,1);}fn_801F0E34(p,0x400b5,0);}break;
case 31:{fn_8022FE80(0,*(s32*)(p+4),*(s32*)(p+0x198),1,0);fn_8022FD8C(*(void**)(p+0x198));{v14.set(lbl_8053C55C,lbl_8053C570,lbl_8053C55C);fn_8038BD08(0,0x4b1,*(s32*)(p+4),&v14,0x4022);}fn_8011921C();fn_80118454();}break;
case 33:{fn_80458FF0(lbl_8053AF80,0x100002b,1,0);fn_801F0E34(p,0x40071,0);((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,193,0,0,0,0,1);((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,194,0,0,0,0,1);((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,195,0,0,0,0,1);((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),p+0xc,lbl_8053C550,196,0,0,0,0,1);{JGeometry::TBox2<f32> box;{u8* q=(u8*)fn_802D6A9C();*(u32*)&box.i.x=*(u32*)(q+0xcc);*(u32*)&box.i.y=*(u32*)(q+0xd0);*(u32*)&box.f.x=*(u32*)(q+0xd4);*(u32*)&box.f.y=*(u32*)(q+0xd8);}JGeometry::TVec3<f32> pos;pos.x=lbl_8053C58C*(box.i.x-box.f.x)+box.f.x;pos.y=lbl_8053C58C*(box.i.y-box.f.y)+box.f.y;pos.z=lbl_8053C55C;((void*(*)(u32,void*,f32,s32,s32,s32,s32,s32,s32))fn_8013CC50)(*(u32*)(p+4),&pos,lbl_8053C550,0xc5,0,0,0,0,1);}}break;
case 34:{p[0x230]=1;}break;
case 62:default:break;
}}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
extern "C" void fn_8010F478(u8* this_, s32 param_2) {
    switch (*(s32*)(this_ + 0x234)) {
    case 3:
    default:
        break;
    case 0:
    case 1:
        fn_8010E7E8(this_, param_2);
        break;
    case 2:
        fn_8010E2D4(this_, param_2);
        break;
    }
    *(s32*)(this_ + 0x238) = param_2;
}

extern "C" void fn_8010F4DC(u8* this_) {
    Mtx m1;
    Mtx m2;
    Vec v1;
    Vec v2;
    u8* e;
    s32 n;
    f32 z;

    *(f32*)(this_ + 0x268) = *(f32*)(this_ + 0x268) + lbl_8053C5C8;
    PSMTXTrans(m1, *(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
    v1.y = lbl_8053C55C;
    v1.z = lbl_8053C55C;
    v1.x = lbl_8053C550;
    fn_8010F668(m1, (f32*)&v1, lbl_8053C5CC);
    m2[2][3] = lbl_8053C55C;
    m2[1][3] = lbl_8053C55C;
    m2[0][3] = lbl_8053C55C;
    m2[2][2] = lbl_8053C55C;
    m2[1][2] = lbl_8053C55C;
    m2[0][2] = lbl_8053C55C;
    m2[2][1] = lbl_8053C55C;
    m2[1][1] = lbl_8053C55C;
    m2[0][1] = lbl_8053C55C;
    m2[2][0] = lbl_8053C55C;
    m2[1][0] = lbl_8053C55C;
    m2[0][0] = lbl_8053C55C;
    v2.x = lbl_8053C55C;
    v2.y = lbl_8053C55C;
    v2.z = lbl_8053C550;
    fn_8010F668(m2, (f32*)&v2, *(f32*)(this_ + 0x268));
    PSMTXConcat(m1, m2, m1);

    n = *(s32*)(this_ + 0x240) + 1;
    *(s32*)(this_ + 0x240) = n;
    if (*(s32*)(this_ + 0x240) >= 0xc8) {
        *(s32*)(this_ + 0x240) = 0;
    }
    n = *(s32*)(this_ + 0x240);
    z = *(f32*)(this_ + 0x270);
    e = (u8*)fn_801902C0();
    if (*(u32*)(e + 0x284) != 0 && e[0x2a4] == 0) {
        e[0x2a4] = 1;
        *(f32*)(e + 0x248) = z;
        *(f32*)(e + 0x24c) = z;
        *(f32*)(e + 0x250) = z;
        {
            f64* d = (f64*)(e + 0x254);
            f64* s = (f64*)m1;
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
            d[3] = s[3];
            d[4] = s[4];
            d[5] = s[5];
        }
        *(f32*)(e + 0x290) = lbl_8053C5D0;
        *(s32*)(e + 0x294) = n;
        *(s32*)(e + 0x29c) = 0;
        *(s32*)(e + 0x2a0) = 1;
    }
}

extern const f32 lbl_8053C58C;
extern const f32 lbl_8053C5B4;
extern const f32 lbl_8053C5D4;
extern int __float_epsilon[];
extern "C" f64 sin(f64);
extern "C" f64 cos(f64);
void fn_8010F668(f32 m[3][4], f32 axis[3], f32 angle) {
    Vec v;
    f32 len2;
    f32 inv;
    f32 y;
    len2 = JMathInlineVEC::PSVECSquareMag((const Vec*)axis);

    if (len2 <= lbl_8053C5B4 * *(f32*)__float_epsilon) {
        v.z = lbl_8053C55C;
        v.y = lbl_8053C55C;
        v.x = lbl_8053C55C;
    } else {
        if (len2 <= lbl_8053C55C) {
            inv = len2;
        } else {
            y = __frsqrte(len2);
            inv = lbl_8053C58C * y * (lbl_8053C5D4 - (len2 * (y * y)));
        }
        JMathInlineVEC::PSVECScale((const Vec*)axis, &v, inv);
    }

    f32 s = sin(angle);
    f32 c = cos(angle);
    f32 t = lbl_8053C550 - c;
    f32 x = v.x;
    f32 yy = v.y;
    f32 z = v.z;

    m[0][0] = t * (x * x) + c;
    m[0][1] = t * x * yy - s * z;
    m[0][2] = t * x * z + s * yy;
    m[1][0] = t * x * yy + s * z;
    m[1][1] = t * (yy * yy) + c;
    m[1][2] = t * yy * z - s * x;
    m[2][0] = t * x * z - s * yy;
    m[2][1] = t * yy * z + s * x;
    m[2][2] = t * (z * z) + c;
}

extern "C" void fn_8010F7EC(u8* this_, s32 param) {
    SwbmDrawParam prm;
    Mtx m;
    prm.reset();
    prm.m4D = *(u32*)(this_ + 0x24c);
    if (*(s32*)(this_ + 0x238) == 0x2f) {
        *(s32*)(this_ + 0x264) += 0x258;
        if (*(s32*)(this_ + 0x264) >= 0x10000) {
            *(s32*)(this_ + 0x264) -= 0x10000;
        }
        f32 zero = lbl_8053C55C;
        f32 s = sincosTable___5JMath[(u16)*(s32*)(this_ + 0x264) >> 5].sin;
        m[0][0] = lbl_8053C550;
        m[0][1] = zero;
        m[0][2] = zero;
        m[0][3] = zero;
        m[1][0] = zero;
        m[1][1] = lbl_8053C550;
        m[1][2] = zero;
        m[1][3] = zero;
        m[2][0] = zero;
        m[2][1] = zero;
        m[2][2] = lbl_8053C550;
        m[2][3] = lbl_8053C560 * s;
        prm.mMtx = m;
    }
    if (param == 0x21b) {
        fn_801F02BC(this_, lbl_8046464C, param + *(s32*)(this_ + 0x304), &prm, 0x407, 0, 0, lbl_8053C550, lbl_8053C550);
    } else {
        fn_801F02BC(this_, lbl_80464660, param + *(s32*)(this_ + 0x304), &prm, 0x407, 0, 0, lbl_8053C550, lbl_8053C550);
    }
}

extern "C" void fn_8010F9F0(u8* p) {
    switch (*(s32*)(p + 0x234)) {
    case 0:
    case 1:
        fn_8010E7E8(p, 0x31);
        break;
    case 2:
        fn_8010E2D4(p, 0x31);
        break;
    case 3:
        break;
    }
    *(s32*)(p + 0x238) = 0x31;
}

extern "C" s32 fn_8010FA54(u8* this_) {
#if defined(VERSION_G4SP01)
    switch (*(s32*)(this_ + 0x23c)) {
#else
    switch (*(s32*)(this_ + 0x238)) {
#endif
    case 47:
    case 61:
    case 62:
        return 1;
    }
    return 0;
}
