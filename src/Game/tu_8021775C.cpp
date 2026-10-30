#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry.h"


extern "C" void fn_801EE434(void*);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
extern const f32 lbl_8053FC38;

extern "C" int __float_epsilon[];
struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" void fn_8021775C(void** p, f32 t) {
    JGeometry::TVec3<f32> cur(*(JGeometry::TVec3<f32>*)((u8*)p[6] + 0x60c));
    JGeometry::TVec3<f32> target(*(JGeometry::TVec3<f32>*)((u8*)p[6] + 0x600));
    if (t < *(f32*)__float_epsilon) {
        cur.x = target.x;
    } else {
        cur.x = cur.x + (target.x - cur.x) * (1.0f / t);
    }
    f32 ty = target.y;
    if (t < *(f32*)__float_epsilon) {
        cur.y = ty;
    } else {
        cur.y = cur.y + (ty - cur.y) * (1.0f / t);
    }
    f32 tz = target.z;
    if (t < *(f32*)__float_epsilon) {
        cur.z = tz;
    } else {
        cur.z = cur.z + (tz - cur.z) * (1.0f / t);
    }
    fn_8013CB44(p[4], &cur, 1, 1, 1);
    fn_8013CB44(p[5], &cur, 1, 1, 1);
}

extern "C" void fn_80217874(char* this_, f32 t) {
    JGeometry::TVec3<f32>* pa = (JGeometry::TVec3<f32>*)(*(char**)(this_ + 0x18) + 0xc);
    JGeometry::TVec3<f32>* pb = (JGeometry::TVec3<f32>*)(*(char**)(this_ + 0x18) + 0x60c);
    JGeometry::TVec3<f32> a(*pa);
    JGeometry::TVec3<f32> b(*pb);
    if (t < *(f32*)__float_epsilon) {
        a.x = b.x;
    } else {
        a.x = (1.0f / t) * (b.x - a.x) + a.x;
    }
    f32 by = b.y;
    if (t < *(f32*)__float_epsilon) {
        a.y = by;
    } else {
        f32 inv = 1.0f / t;
        a.y = inv * (by - a.y) + a.y;
    }
    f32 bz = b.z;
    if (t < *(f32*)__float_epsilon) {
        a.z = bz;
    } else {
        a.z = (1.0f / t) * (bz - a.z) + a.z;
    }
    fn_8013CB44(*(void**)(this_ + 8), &a, 1, 1, 1);
    fn_8013CB44(*(void**)(this_ + 0xc), &a, 1, 1, 1);
}

extern "C" void fn_8021798C(void** p) {
    fn_8013CB44(p[0], (u8*)p[6] + 0xc, 1, 1, 1);
    fn_8013CB44(p[1], (u8*)p[6] + 0xc, 1, 1, 1);
}

extern "C" void fn_802179EC(void** p) {
    fn_801EE434(p[4]);
    fn_801EE434(p[5]);
    p[4] = 0;
    p[5] = 0;
}

extern "C" void fn_80217A30(void** p) {
    fn_801EE434(p[2]);
    fn_801EE434(p[3]);
    p[2] = 0;
    p[3] = 0;
}

extern "C" void* fn_8013CC50(u32, void*, u16, s32, f32, s32, s32, s32, s32);
extern "C" const f32 lbl_8053F0BC;
// Retail initialises this in __sinit before the JASPoolAllocObject pools (see the include at the end).
struct Vec3fArr {
    Vec3fArr(f32 a, f32 b, f32 c) {
        v[0] = a;
        v[1] = b;
        v[2] = c;
    }
    operator f32*() { return v; }
    f32 v[3];
};
static Vec3fArr lbl_804CD838(lbl_8053F0BC, lbl_8053F0BC, lbl_8053F0BC);

extern "C" void fn_80217A74(void** p)
{
    fn_801EE434(p[0]);
    fn_801EE434(p[1]);
    p[0] = 0;
    p[1] = 0;
}

struct Vec2F {
    f32 x;
    f32 y;
};

extern "C" void fn_80217AB8(u8* p) {
    u8* sub;
    void* obj;
    f32 y;
    f32 x;

    if (*(void**)(p + 0x10) == NULL) {
        sub = *(u8**)(p + 0x18);
        *(void**)(p + 0x10) = fn_8013CC50(*(u32*)(sub + 0x5fc), sub + 0x60c, 0x224, 1, 1.0f, 1, 0, 0, 1);
        obj = *(void**)(p + 0x10);
        if (obj != NULL) {
            *(f32*)((u8*)obj + 0x98) = lbl_804CD838[0];
            *(f32*)((u8*)obj + 0x9c) = lbl_804CD838[1];
            *(f32*)((u8*)obj + 0xa0) = lbl_804CD838[2];
            y = lbl_804CD838[1];
            x = lbl_804CD838[0];
            *(f32*)((u8*)obj + 0xb0) = x;
            *(f32*)((u8*)obj + 0xb4) = y;
        }
    }
    if (*(void**)(p + 0x14) == NULL) {
        sub = *(u8**)(p + 0x18);
        *(void**)(p + 0x14) = fn_8013CC50(*(u32*)(sub + 0x5fc), sub + 0x60c, 0x225, 1, 1.0f, 1, 0, 0, 1);
        obj = *(void**)(p + 0x14);
        if (obj != NULL) {
            *(f32*)((u8*)obj + 0x98) = lbl_804CD838[0];
            *(f32*)((u8*)obj + 0x9c) = lbl_804CD838[1];
            *(f32*)((u8*)obj + 0xa0) = lbl_804CD838[2];
            y = lbl_804CD838[1];
            x = lbl_804CD838[0];
            *(f32*)((u8*)obj + 0xb0) = x;
            *(f32*)((u8*)obj + 0xb4) = y;
        }
    }
}

extern "C" void fn_80217BC8(void** p) {
    if (p[2] == 0) {
        u8* obj = (u8*)p[6];
        p[2] = fn_8013CC50(*(u32*)(obj + 4), obj + 0xc, 0x22f, 1, lbl_8053FC38, 1, 0, 0, 1);
        u8* r = (u8*)p[2];
        if (r != 0) {
            f32* tbl = lbl_804CD838;
            *(f32*)(r + 0x98) = tbl[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            f32 y = tbl[1];
            *(f32*)(r + 0xb0) = tbl[0];
            *(f32*)(r + 0xb4) = y;
        }
    }
    if (p[3] == 0) {
        u8* obj = (u8*)p[6];
        p[3] = fn_8013CC50(*(u32*)(obj + 4), obj + 0xc, 0x230, 1, lbl_8053FC38, 1, 0, 0, 1);
        u8* r = (u8*)p[3];
        if (r != 0) {
            f32* tbl = lbl_804CD838;
            *(f32*)(r + 0x98) = tbl[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            f32 y = tbl[1];
            *(f32*)(r + 0xb0) = tbl[0];
            *(f32*)(r + 0xb4) = y;
        }
    }
}

extern "C" void fn_80217CD8(void** p) {
    if (p[0] == 0) {
        u32 base = (u32)p[6];
        p[0] = fn_8013CC50(*(u32*)(base + 4), (u8*)(base + 0xc), 0x228, 1, lbl_8053FC38, 1, 0, 0, 1);
        u8* r = (u8*)p[0];
        if (r != 0) {
            f32* tbl = lbl_804CD838;
            *(f32*)(r + 0x98) = tbl[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            f32 y = tbl[1];
            *(f32*)(r + 0xb0) = tbl[0];
            *(f32*)(r + 0xb4) = y;
        }
    }
    if (p[1] == 0) {
        u32 base = (u32)p[6];
        p[1] = fn_8013CC50(*(u32*)(base + 4), (u8*)(base + 0xc), 0x229, 1, lbl_8053FC38, 1, 0, 0, 1);
        u8* r = (u8*)p[1];
        if (r != 0) {
            f32* tbl = lbl_804CD838;
            *(f32*)(r + 0x98) = tbl[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            f32 y = tbl[1];
            *(f32*)(r + 0xb0) = tbl[0];
            *(f32*)(r + 0xb4) = y;
        }
    }
}

extern "C" void fn_80217DE8(const u8* p) {
    u8* sub = *(u8* const*)(p + 0x18) + 0xc;
    u8* r = (u8*)fn_8013CC50(*(u32*)(*(u8* const*)(p + 0x18) + 4), sub, 0x231, 1, lbl_8053FC38, 1, 0, 0, 1);
    sub = *(u8* const*)(p + 0x18) + 0xc;
    u8* r2 = (u8*)fn_8013CC50(*(u32*)(*(u8* const*)(p + 0x18) + 4), sub, 0x232, 1, lbl_8053FC38, 1, 0, 0, 1);
    if (r != 0) {
        *(f32*)(r + 0x98) = lbl_804CD838[0];
        *(f32*)(r + 0x9c) = lbl_804CD838[1];
        *(f32*)(r + 0xa0) = lbl_804CD838[2];
        f32 y = lbl_804CD838[1];
        *(f32*)(r + 0xb0) = lbl_804CD838[0];
        *(f32*)(r + 0xb4) = y;
    }
    if (r2 != 0) {
        *(f32*)(r2 + 0x98) = lbl_804CD838[0];
        *(f32*)(r2 + 0x9c) = lbl_804CD838[1];
        *(f32*)(r2 + 0xa0) = lbl_804CD838[2];
        f32 y = lbl_804CD838[1];
        *(f32*)(r2 + 0xb0) = lbl_804CD838[0];
        *(f32*)(r2 + 0xb4) = y;
    }
}

extern "C" void* fn_8013CC50(u32, void*, u16, s32, f32, s32, s32, s32, s32);
extern u16 lbl_8046A5A0[];
extern const f32 lbl_8053FC38;
#pragma opt_loop_invariants on
#pragma opt_common_subs off
extern "C" void fn_80217ED4(u8* self) {
    f32* tbl;
    u8* pos;
    const u16* ids;
    u8* obj;
    s32 i;
    i = 0;
    obj = *(u8**)(self + 0x18);
    ids = lbl_8046A5A0;
    pos = obj + 0xc;
    tbl = lbl_804CD838;
    do {
        s32 id = *ids;
        u8* r = (u8*)((void* (*)(u32, void*, s32, s32, s32, s32, s32, s32, f32))fn_8013CC50)(*(u32*)(obj + 4), pos, id, 1, 1, 0, 0, 1, lbl_8053FC38);
        if (r != 0) {
            *(f32*)(r + 0x98) = lbl_804CD838[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            f32 y = tbl[1];
            *(f32*)(r + 0xb0) = lbl_804CD838[0];
            *(f32*)(r + 0xb4) = y;
        }
        i++;
        ids++;
    } while (i < 6);
}
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset
extern "C" void** dtor_80217F80(void** p, s16 flag) {
    if (p != 0) {
        fn_801EE434(p[0]);
        fn_801EE434(p[1]);
        p[0] = 0;
        p[1] = 0;
        fn_801EE434(p[2]);
        fn_801EE434(p[3]);
        p[2] = 0;
        p[3] = 0;
        fn_801EE434(p[4]);
        fn_801EE434(p[5]);
        p[4] = 0;
        p[5] = 0;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_80218020(void** p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
}

#include "Game/SinitPoolChain.h"

void fn_80218044(void) {}

