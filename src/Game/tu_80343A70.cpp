#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#define I7(p,o) (*(s32*)((char*)(p)+(o)))
#define F7(p,o) (*(f32*)((char*)(p)+(o)))
#define B7(p,o) (*(u8*)((char*)(p)+(o)))
#define H7(p,o) (*(u16*)((char*)(p)+(o)))
#define V7(p,o) (*(JGeometry::TVec3<f32>*)((char*)(p)+(o)))
#include "Game/ItemBase.h"

struct Tu80343Random {
    u32 seed;
    f32 get_ufloat_1() {
        union {
            f32 f;
            u32 s;
        } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct Tu80343Game {
    u8 pad[0xb4];
    Tu80343Random rnd;
};
extern Tu80343Game* lbl_8053AAF8;

struct Tu80343Vec3 {
    f32 x, y, z;
};


extern "C" char __vt__4BEEE[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* mgr, u32 kind, s32 room, void* pos, s32 n);
extern "C" void v07__5ActorFv(void* this_);
extern "C" Actor* fn_80343A70(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4BEEE;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_80343AD0(char* this_) {
    u32 n;
    s32 t = *(s32*)(this_ + 0x274);
    if (t == 1) {
        n = 3;
    } else if (t == 2) {
        n = 1;
    }
    fn_801F8544(fn_801F856C(), 'RUPY', *(s32*)(this_ + 4), this_ + 0xc, n | 0x261e00);
    v07__5ActorFv(this_);
}

extern "C" f32 lbl_80542350;
extern "C" f32 lbl_80542354;
extern "C" f32 lbl_80542358;
extern "C" char lbl_80471FE0[];
extern "C" void fn_801F06F0(void* this_, const char* tbl, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_80343B48(char* this_) {
    DrawRec rec;
    rec.b1d = -1;
    rec.b1c = 1;
    if (*(s32*)(this_ + 0x274) == 2) {
        rec.b20 = 0;
        if (*(s32*)(this_ + 0x230) != 0) {
            f32 zero = lbl_80542350;
            char* p = this_;
            for (s32 i = 0; i < 7; i++) {
                Tu80343Vec3 a = *(Tu80343Vec3*)(p + 0x2a4);
                Tu80343Vec3 b = *(Tu80343Vec3*)(this_ + 0x2a4);
                Tu80343Vec3 sum;
                sum.x = a.x + b.x;
                sum.y = a.y + b.y;
                sum.z = a.z + b.z;
                *(Tu80343Vec3*)(this_ + 0xc) = sum;
                if (*(f32*)(this_ + 0x14) <= zero) {
                    *(f32*)(this_ + 0x14) = lbl_80542354;
                }
                fn_801F06F0(this_, lbl_80471FE0, *(s32*)(this_ + 0x240) + *(s32*)(this_ + 0x254) + 0x1cc, &rec, 1, lbl_80542358, lbl_80542358);
                p += 0xc;
            }
            *(Tu80343Vec3*)(this_ + 0xc) = *(Tu80343Vec3*)(this_ + 0x2a4);
            if (*(s32*)(this_ + 0x274) == 2 && *(f32*)(this_ + 0x14) <= zero) {
                *(f32*)(this_ + 0x14) = lbl_80542354;
            }
        }
    }
}

extern "C" void fn_803450AC(char* this_) {
    s32 n;
    char* p;
    char* q;
    Tu80343Game* g;

    *(s32*)(this_ + 0x270) = *(s32*)(this_ + 0x90) & 1;
    *(s32*)(this_ + 0x108) = 1;
    *(f32*)(this_ + 0x2ac) = 0.0f;
    *(f32*)(this_ + 0x2a8) = 0.0f;
    *(f32*)(this_ + 0x2a4) = 0.0f;
    *(f32*)(this_ + 0x300) = 0.0f;
    *(f32*)(this_ + 0x2fc) = 0.0f;
    *(f32*)(this_ + 0x2f8) = 0.0f;
    *(f32*)(this_ + 0x354) = 0.0f;
    *(f32*)(this_ + 0x350) = 0.0f;
    *(f32*)(this_ + 0x34c) = 0.0f;
    p = this_;
    q = this_;
    n = 7;
    do {
        *(f32*)(p + 0x278) = 2.0f + lbl_8053AAF8->rnd.get_ufloat_1();
        *(s32*)(p + 0x254) = 0;
        *(s16*)(q + 0x294) = 0;
        p += 4;
        q += 2;
    } while (--n != 0);
    *(f32*)(this_ + 0x278) = 1.5f + 0.5f * lbl_8053AAF8->rnd.get_ufloat_1();
    *(f32*)(this_ + 0x2a4) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2a8) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2ac) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = -1;
    *(s32*)(this_ + 0x24c) = -1;
    *(s32*)(this_ + 0x250) = 0;
    *(s16*)(this_ + 0x2a2) = 0;
    *(s32*)(this_ + 0x248) = -1;
    *(s32*)(this_ + 0x274) = 0;
    *(u8*)(this_ + 0x234) = 0;
    *(f32*)(this_ + 0x60) = -4.0f;
    *(f32*)(this_ + 0x64) = -4.0f;
    *(f32*)(this_ + 0x68) = 4.0f;
    *(f32*)(this_ + 0x6c) = 4.0f;
    *(s32*)(this_ + 0x230) = 0;
    *(u8*)(this_ + 0x194) = 1;
}

