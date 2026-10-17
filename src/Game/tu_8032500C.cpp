#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804AB464[];
struct TVec3fAdd {
    f32 x, y, z;
    TVec3fAdd& operator+=(const TVec3fAdd& o) {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
};
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u8 fn_801F2618(Actor* a, f32* out, u32 c);
extern "C" void* fn_802D6A9C(void);
extern "C" Actor* fn_8032500C(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AB464;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8032506C(Actor* a) {
    u8* p = (u8*)a;
    f32 out[3];
    u8 r;

    if (((u8*)fn_802D6A9C())[a->field_04 + 0x131df] == 0) {
        a->field_0C.x += a->field_3C.x;
        a->field_0C.y += a->field_3C.y;
        a->field_0C.z += a->field_3C.z;
        r = fn_801F2618(a, out, 0);
        if (r == 1) {
            if (out[0] != 0.0f) {
                if (p[0x275] != 0) {
                    a->field_3C.x = a->field_3C.x * 0.5;
                    a->field_3C.y = -a->field_3C.x;
                    p[0x275] = 0;
                } else {
                    a->field_3C.x = -a->field_3C.x;
                }
            }
        }
    }
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, s32 a, f32* b, s32 d, s32 e);
extern "C" u16 fn_8022461C(s32 a, s32 b);
extern "C" u16 fn_80226850(s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* a, s32 b, s32 c, f32 d, f32 e);
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern "C" u8 fn_801F2B7C(Actor* a, s32 b, s32 c, s32 d);
extern "C" void fn_801F2B20(Actor* a, s32 b);
extern "C" void fn_801F0E34(Actor* a, s32 b, s32 c);
extern "C" void fn_80236074(s32 a, s32 b, s32 c);
extern "C" void fn_8013CC50(u32 a, Vec* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void* lbl_8053AAF8;
extern "C" u32 lbl_804AB440[];
extern "C" u8 sincosTable___5JMath[];

static inline f32 rand01() {
    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *s = *s * 0x19660du + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - 1.0f;
}
extern "C" u32 fn_80325548(Actor* a, s32 b, s32 c) {
    s32 region = a->field_198;
    u8* base = static_cast<u8*>(fn_8020D58C());
    if (fn_8020D6AC(base + base[1] * 0x784 + 4, b, reinterpret_cast<f32*>(c), region, 0) != 0) {
        return 1;
    }
    s32 kind = fn_8022461C(c, b);
    s32 sub = fn_80226850(c, b);
    if (kind == 0x20) {
        return 1;
    }
    if (sub == 0x230 || sub == 0x231) {
        return 0;
    }
    if (kind != 0x0 && kind != 0x4 && kind != 0x5 && kind != 0x6 && kind != 0x7 && kind != 0x2 &&
        kind != 0x50 && kind != 0xe && kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 &&
        kind != 0x2a && kind != 0x2b && kind != 0x2c && kind != 0x2d && kind != 0x2e && kind != 0x2f &&
        kind != 0xd && kind != 0x39 && kind != 0x3a && kind != 0x3b && kind != 0x4c && kind != 0x4d &&
        kind != 0x4e && kind != 0x4f && kind != 0x24) {
        if (sub == 0x3a) {
            return 0;
        }
        if (kind == 0x25) {
            return static_cast<u8*>(fn_802D6A9C())[0x171] == 0;
        }
        if (kind == 0x26) {
            return static_cast<u8*>(fn_802D6A9C())[0x171] == 1;
        }
        if (kind != 0x22 || static_cast<u8*>(fn_802D6A9C())[0x170] == 1) {
            return 1;
        }
    }
    return 0;
}

extern "C" void* lbl_8053AC98;
extern "C" void fn_8029EDB8(void*, void*, s32, s32, void*);
extern "C" void fn_803261B0(u8* p) {
    struct VObj {
        virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
        virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
        virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
        virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
        virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
        virtual void v50(); virtual void v54();
    };
    u8 buf[8];
    ((VObj*)p)->v4C();
    fn_8029EDB8(lbl_8053AC98, p + 0xc, 0, *(s32*)(p + 0x4), buf);
    *(s32*)(p + 0x230) = 3;
}

extern "C" void fn_80326208(Actor* a) {
    s32 bits;
    s32 i;
    s32 sVar;

    a->field_3C.x = 0.0f;
    a->field_3C.y = 0.0f;
    a->field_3C.z = 0.0f;
    a->field_0C.z = 0.0f;
    a->field_B0 = 0;
    a->field_60 = -16.0f;
    a->field_64 = -16.0f;
    a->field_68 = 16.0f;
    a->field_6C = 16.0f;
    fn_802D79E8(fn_802D6A9C(), a->field_04, 0, 4.0f, 0.0f);
    fn_80134DE4(lbl_8053AAF8, 1, 0);
    if (((u8*)lbl_8053AAF8)[0x7f] == 0 || ((s32)a->field_90 & 0xf) == 4 || ((s32)a->field_90 & 0xf) == 3) {
        bits = fn_801F2B7C(a, a->field_114, -1, 1);
    } else {
        bits = fn_801F2B7C(a, 0, -1, 1);
    }
    *(s32*)((u8*)a + 0x250) = 0;
    *(u32*)((u8*)a + 0x238) = lbl_804AB440[*(s32*)((u8*)a + 0x250)];
    fn_801F2B20(a, 5);
    if (bits > 0) {
        i = 0;
        do {
            if (((bits >> i) & 1) != 0) {
                fn_80236074(i, 100, 0);
            }
            i++;
        } while (i < 4);
    }
    fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x59, 1, 1, 0, 0, 1);
    fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x5a, 1, 1, 0, 0, 1);
    fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x5b, 1, 1, 0, 0, 1);
    fn_801F0E34(a, 0x30001, 0);
    sVar = (u16)fn_8022461C(reinterpret_cast<s32>(&a->field_0C), a->field_04);
    if (sVar == 0x39 || sVar == 0xd || sVar == 0x3b) {
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4f3, -1, 1, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4f4, 0, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4f5, 0, 0, 0, 0, 1);
        fn_8013CC50(a->field_04, &a->field_0C, 1.0f, 0x4f6, 0, 0, 0, 0, 1);
        fn_801F0E34(a, 0x30022, 0);
    }
}

extern "C" void fn_8023061C(s32 a, s32 b);
extern "C" u8 fn_8022F9E4(s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_803264C0(Actor* a) {
    u8* p = (u8*)a;
    f32 k = 2.5f;
    *(s32*)(p + 0x26c) = (a->field_90 >> 16) & 3;
    a->field_60 = -8.0f;
    a->field_64 = -8.0f;
    a->field_68 = 8.0f;
    a->field_6C = 8.0f;
    *(f32*)(p + 0x80) = -7.0f;
    *(f32*)(p + 0x84) = -4.0f;
    a->field_88 = 7.0f;
    a->field_8C = 7.0f;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    a->field_108 = 2;
    a->field_118 = 2;
    a->field_114 = 2;
    *(f32*)(p + 0x280) = 1.0f;
    *(f32*)(p + 0x27c) = 0.0f;
    *(u8*)(p + 0x278) = (a->field_90 >> 4) & 1;
    *(s32*)(p + 0x268) = 0;
    *(u32*)(p + 0xb0) = 0x53308;
    *(s32*)(p + 0x270) = (a->field_90 >> 8) & 0xf;
    a->field_90 = a->field_90 & 0xf;
    *(s32*)(p + 0x264) = -1;
    *(u8*)(p + 0x274) = 0;
    *(u8*)(p + 0x275) = 1;
    *(u8*)(p + 0x277) = 1;
    *(f32*)(p + 0x234) = 0.3f;
    *(u8*)(p + 0x276) = 1;
    if (*(s32*)(p + 0x270) == 1) {
        k = 1.25f;
    }
    switch (a->field_90 & 0xf) {
    case 0:
        a->field_3C.x = 0.0f;
        a->field_3C.y = 0.0f;
        a->field_3C.z = 0.0f;
        *(s32*)(p + 0x23c) = 300;
        *(s32*)(p + 0x230) = 0;
        *(u32*)(p + 0xb0) = 0x73308;
        break;
    case 1:
        *(s32*)(p + 0x23c) = 300;
        *(s32*)(p + 0x248) = 10;
        *(s32*)(p + 0x230) = 2;
        *(u32*)(p + 0xb0) = 0x73308;
        break;
    case 2:
        *(s32*)(p + 0x23c) = 300;
        *(s32*)(p + 0x248) = 10;
        *(s32*)(p + 0x230) = 2;
        *(u32*)(p + 0xb0) = 0x73308;
        *(u8*)(p + 0x275) = 0;
        break;
    case 4: {
        s32 t;
        u8* sc;
        *(s32*)(p + 0x23c) = 300;
        *(s32*)(p + 0x248) = 120;
        *(s32*)(p + 0x230) = 2;
        *(u32*)(p + 0xb0) = 0x73308;
        t = ((s32)(65536.0f * rand01()) >> 2) & 0x3ff8;
        sc = sincosTable___5JMath + t;
        a->field_3C.x = k * *(f32*)sc;
        a->field_3C.y = k * *(f32*)(sc + 4);
        a->field_3C.z = 0.0f;
        *(u8*)(p + 0x275) = 0;
        break;
    }
    case 3:
        *(s32*)(p + 0x23c) = 300;
        *(s32*)(p + 0x24c) = 10;
        *(s32*)(p + 0x230) = 2;
        *(u32*)(p + 0xb0) = 0x73308;
        *(u8*)(p + 0x277) = 0;
        if ((s32)(2.0f * rand01()) == 0) {
            a->field_3C.x = k;
        } else {
            a->field_3C.x = -k;
        }
        a->field_3C.y = 0.0f;
        a->field_3C.z = 0.0f;
        *(u8*)(p + 0x275) = 0;
        break;
    case 5:
        *(s32*)(p + 0x23c) = 300;
        a->field_90 = 0;
        *(s32*)(p + 0x230) = 2;
        *(u32*)(p + 0xb0) = 0x73308;
        fn_8023061C(*(s32*)(p + 0x26c), 0);
        if (fn_8022F9E4(*(s32*)(p + 0x26c), a->field_198, 0, 0) == 1) {
            *(s32*)(p + 0x230) = 2;
        } else {
            *(s32*)(p + 0x230) = 1;
        }
        break;
    }
}

void fn_8032686C(void) {
}

