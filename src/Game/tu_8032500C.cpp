#define Vec SDKVec
#define PSMTXIdentity SDK_PSMTXIdentity
#include "JSystem/JGeometry/Vec.h"
#undef PSMTXIdentity
#undef Vec
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Box.h"


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
extern const f32 lbl_80541BC8;
extern const f64 lbl_80541BD8;
extern const f32 lbl_80541BE0;
extern const f32 lbl_80541BE4;
extern const f32 lbl_80541BE8;
extern const f32 lbl_80541BEC;
extern const f32 lbl_80541BF0;
static inline void turtleReflect(Actor* a) {
    u8* p = (u8*)a;
    if (*(f32*)(p + 0x234) > 0.0f) {
        if (a->field_3C.x > 0.0f) a->field_3C.x = -a->field_3C.x;
        else *(f32*)(p + 0x234) = -*(f32*)(p + 0x234);
    } else {
        if (a->field_3C.x > 0.0f) *(f32*)(p + 0x234) = -*(f32*)(p + 0x234);
        else a->field_3C.x = -a->field_3C.x;
    }
}
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
    JGeometry::TVec3f stepX;
    JGeometry::TVec3f stepY;
    JGeometry::TVec3f stepVertical;
    JGeometry::TVec3f stepHorizontal;
    s32 room = a->field_04;
    u8* flags = (u8*)fn_802D6A9C() + 0x10000;
    if (flags[room + 0x31df] == 0) {
        *(JGeometry::TVec3f*)&a->field_0C += *(JGeometry::TVec3f*)&a->field_3C;
        if (fn_801F2618(a, out, 0) != 1) return;
        if (0.0f != out[0]) {
            if (p[0x275] != 0) {
                a->field_3C.x *= lbl_80541BD8;
                a->field_3C.y = -a->field_3C.x;
                p[0x275] = 0;
            } else {
                a->field_3C.x = -a->field_3C.x;
            }
        } else {
            if (p[0x275] != 0) {
                a->field_3C.y *= lbl_80541BD8;
                a->field_3C.x = a->field_3C.y;
                p[0x275] = 0;
            } else {
                a->field_3C.y = -a->field_3C.y;
            }
        }
        return;
    }
    if (p[0x276] == 1) {
        if (*(s32*)(p + 0x260) != 1) return;
        stepX.set(a->field_3C.x, 0.0f, 0.0f);
        *(JGeometry::TVec3f*)&a->field_0C += stepX;
        if (fn_801F2618(a, 0, 0)) {
            turtleReflect(a);
            a->field_3C.y = 0.0f;
            p[0x276] = 0;
        }
        if (p[0x276] == 1) {
            a->field_3C.y += *(f32*)(p + 0x234);
            stepY.set(0.0f, a->field_3C.y, 0.0f);
            *(JGeometry::TVec3f*)&a->field_0C += stepY;
            if (fn_801F2618(a, 0, 0)) {
                a->field_3C.y = 0.0f;
                p[0x277] = 0;
                return;
            }
            if (*(s32*)(p + 0x24c) <= 0 && p[0x277] == 0) {
                if (a->field_3C.x < 0.0f) {
                    if (*(f32*)(p + 0x234) > 0.0f) a->field_3C.x = -a->field_3C.x;
                    a->field_3C.y = lbl_80541BE0;
                    if (*(s32*)(p + 0x270) == 1) *(f32*)(p + 0x234) = lbl_80541BE4;
                    else *(f32*)(p + 0x234) = lbl_80541BE8;
                } else {
                    if (*(f32*)(p + 0x234) < 0.0f) a->field_3C.x = -a->field_3C.x;
                    a->field_3C.y = 0.0f;
                    if (*(s32*)(p + 0x270) == 1) *(f32*)(p + 0x234) = lbl_80541BEC;
                    else *(f32*)(p + 0x234) = lbl_80541BF0;
                }
                p[0x276] = 0;
            }
        }
    } else {
        if (*(s32*)(p + 0x260) != 1) return;
        stepVertical.set(0.0f, a->field_3C.x, 0.0f);
        *(JGeometry::TVec3f*)&a->field_0C += stepVertical;
        if (fn_801F2618(a, 0, 0)) {
            turtleReflect(a);
            a->field_3C.y = 0.0f;
            p[0x276] = 1;
        }
        if (p[0x276] == 0) {
            a->field_3C.y += *(f32*)(p + 0x234);
            stepHorizontal.set(a->field_3C.y, 0.0f, 0.0f);
            *(JGeometry::TVec3f*)&a->field_0C += stepHorizontal;
            if (fn_801F2618(a, 0, 0)) {
                a->field_3C.y = 0.0f;
                return;
            }
            if (a->field_3C.x < 0.0f) {
                if (*(f32*)(p + 0x234) > 0.0f) a->field_3C.x = -a->field_3C.x;
                a->field_3C.y = 0.0f;
                if (*(s32*)(p + 0x270) == 1) *(f32*)(p + 0x234) = lbl_80541BE4;
                else *(f32*)(p + 0x234) = lbl_80541BE8;
            } else {
                if (*(f32*)(p + 0x234) < 0.0f) a->field_3C.x = -a->field_3C.x;
                a->field_3C.y = 0.0f;
                if (*(s32*)(p + 0x270) == 1) *(f32*)(p + 0x234) = lbl_80541BEC;
                else *(f32*)(p + 0x234) = lbl_80541BF0;
            }
            p[0x276] = 1;
        }
    }
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, s32 a, f32* b, s32 d, s32 e);
extern "C" u16 fn_8022461C(s32 a, s32 b);
extern "C" u16 fn_80226850(s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void* lbl_8053AC98;
extern "C" void fn_8029EDB8(void*, void*, s32, s32, void*);
extern "C" u8 fn_8022F9E4(s32 a, s32 b, s32 c, s32 d);
extern "C" u8 fn_8023F264(s32 a);
extern "C" u8 fn_80239C00(s32 a, f32* b, s32 c);
extern "C" s32 fn_801A4F5C(s32 a, f32* b, f32* c);
extern "C" u8 fn_801F305C(Actor* a);
extern "C" void* fn_8023E7B0(s32 a);
extern "C" s32 fn_8023DE58(s32 a);
extern "C" void fn_802D79E8(void* a, s32 b, s32 c, f32 d, f32 e);
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern "C" u8 fn_801F2B7C(Actor* a, s32 b, s32 c, s32 d);
extern "C" void fn_801F2B20(Actor* a, s32 b);
extern "C" void fn_801F0E34(Actor* a, s32 b, s32 c);
extern "C" void fn_80236074(s32 a, s32 b, s32 c);
extern "C" void fn_8013CC50(u32 a, Vec* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void* lbl_8053AAF8;
extern "C" u32 lbl_804AB440[];
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" JMathSinCos sincosTable___5JMath[];

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

extern "C" char lbl_80471870[];
extern "C" void fn_801F06F0(Actor* a, void* p2, s32 id, DrawRec* rec, s32 p5, f32 f6, f32 f7);
extern "C" void fn_803075AC(void* h, s32 room, void* pos, s32 id, s32 sign, s32 two, s32 minus1, s32 p7, s32 u, s32 zero);
extern "C" s32 fn_8023CB24(s32 a);
extern "C" s32 fn_8023CA88(s32 a);
extern "C" void PSMTXIdentity(f32 m[12]);
extern "C" double sin(double);
extern "C" double cos(double);
#pragma opt_propagation off
extern "C" void fn_80325754(Actor* a) {
    s32 flag;
    u8* p = (u8*)a;
    s32 mode;
    DrawRec rec;
    f32 m[12];
    f32 ang;
    f32 sn;
    f32 cs;

    flag = 0;
    mode = 7;
    if (*(f32*)(p + 0x14) == 0.0f && (s32)fn_8022461C((s32)(p + 0xc), *(s32*)(p + 4)) == 0x39) {
        mode = 0;
    }
    PSMTXIdentity(m);
    ang = *(f32*)(p + 0x27c);
    sn = sin(ang);
    cs = cos(ang);
    m[5] = 1.0f;
    m[0] = cs;
    m[2] = sn;
    m[8] = -sn;
    m[10] = cs;
    m[1] = m[4] = m[6] = m[9] = 0.0f;
    rec.w18 = m;
    rec.b1d = 1;
    rec.b1c = 1;
    if (*(s32*)(p + 0x230) == 0) {
        rec.b1d = 0;
        rec.b1c = 0;
    }
    if (*(u8*)(p + 0xc4) != 0) {
        rec.b20 = 0;
        rec.b1d = fn_8023CB24(*(s32*)(p + 0xc8)) + 1;
        rec.b1c = fn_8023CA88(*(s32*)(p + 0xc8));
        flag = 1;
        mode = -1;
    }
    if (*(s32*)(p + 0x230) != 3) {
        fn_801F06F0((Actor*)p, lbl_80471870, *(s32*)(p + 0x250) + 0x8c, &rec, mode, 1.0f, 1.0f);
    }
    if (*(s32*)(p + 0x230) != 3) {
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x250) + 0x8c, 0, 2, -1, 0, 0, 0);
    } else {
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x250) + 0xe8, 0, 2, -1, flag, 0, 0);
    }
}
#pragma opt_propagation reset
extern "C" void fn_80325A30(Actor* a) {
    s32* w = (s32*)a;
    f32* f = (f32*)a;
    u8* b = (u8*)a;
    s32 i;

    if (w[0x8c] == 1) {
        if (fn_8022F9E4(w[0x9b], w[0x66], 0, 0) == 1) {
            w[0x8c] = 2;
        }
    } else {
        JGeometry::TBox2<f32> box(*(JGeometry::TVec2<f32>*)(f + 0x18), *(JGeometry::TVec2<f32>*)(f + 0x1a));
        JGeometry::TVec2<f32> p2(f[3], f[4]);
        box.addPos(p2);

        if (b[0xc4] != 0) {
            f32* v;
            w[0x98] = 0;
            v = (f32*)fn_8023E7B0(w[0x32]);
            f[3] = v[0];
            f[4] = v[1];
            f[5] = v[2];
            w[1] = fn_8023DE58(w[0x32]);
            w[0x99] = w[0x32];
        } else {
            fn_8032506C(a);
        }

        if (b[0x278] == 1 && w[0x8c] != 3) {
            w[0x8f] = 300;
        }

        switch (w[0x8c]) {
        case 0:
            f[0xf] = 0.0f;
            f[0x10] = 0.0f;
            f[0x11] = 0.0f;
            f[5] = 0.0f;
            for (i = 0; i < 4; i++) {
                if (fn_8023F264(i) && fn_80239C00(i, (f32*)&box, w[1]) && fn_8022F9E4(i, w[0x66], 1, 0)) {
                    w[0x96] = 0;
                    w[0x8c] = 2;
                }
            }
            break;
        case 2: {
            s32 room = w[1];
            u8* base = (u8*)fn_802D6A9C() + 0x10000;
            if (base[room + 0x31df] == 0) {
                if (b[0xc4] == 0) {
                    if (w[0x98] == 0) {
                        w[0x92] = 30;
                        w[0x98] = 1;
                    }
                    if (w[0x98] == 1) {
                        f[0x11] += -0.15f;
                    }
                }
                if (f[5] < 0.0f && f[0x11] < 0.0f) {
                    f[5] = 0.0f;
                }
                if (f[5] == 0.0f && w[0x92] <= 0) {
                    s32 n;
                    s32 mask;
                    if (((u8*)lbl_8053AAF8)[0x7f] == 0 || (w[0x24] & 0xf) == 4 || (w[0x24] & 0xf) == 3) {
                        mask = fn_801F2B7C(a, w[0x45], -1, 1);
                    } else {
                        mask = fn_801F2B7C(a, 0, -1, 1);
                    }
                    if (mask > 0) {
                        for (n = 0; n < 4; n++) {
                            if ((mask >> n) & 1) {
                                fn_80236074(n, 100, 0);
                            }
                        }
                    }
                    fn_801F2B20(a, 5);
                }
            } else if (b[0xc4] == 0) {
                if (w[0x98] == 0) {
                    w[0x92] = 10;
                    f[4] = f[4] - f[5];
                    f[5] = 0.0f;
                    f[0x11] = 0.0f;
                    w[0x98] = 1;
                }
                if (b[0x276] == 1) {
                    if (f[0x8d] > 0.0f) {
                        f[0x9f] = 0.0f;
                    } else {
                        f[0x9f] = 3.14159265f;
                    }
                } else {
                    if (f[0x8d] > 0.0f) {
                        f[0x9f] = 4.71238898f;
                    } else {
                        f[0x9f] = 1.57079633f;
                    }
                }
                if (w[0x92] <= 0) {
                    s32 j;
                    s32 mask;
                    if (((u8*)lbl_8053AAF8)[0x7f] == 0 || (w[0x24] & 0xf) == 4 || (w[0x24] & 0xf) == 3) {
                        mask = fn_801F2B7C(a, w[0x45], -1, 1);
                    } else {
                        mask = fn_801F2B7C(a, 0, -1, 1);
                    }
                    if (mask > 0) {
                        for (j = 0; j < 4; j++) {
                            if ((mask >> j) & 1) {
                                fn_80236074(j, 100, 0);
                            }
                        }
                    }
                }
                fn_801F2B20(a, 5);
            }
            break;
        }
        case 3: {
            s32 j;
            s32 mask;
            f[0xf] = 0.0f;
            f[0x10] = 0.0f;
            f[0x11] = 0.0f;
            if (((u8*)lbl_8053AAF8)[0x7f] == 0 || (w[0x24] & 0xf) == 4 || (w[0x24] & 0xf) == 3) {
                mask = fn_801F2B7C(a, w[0x45], -1, 1);
            } else {
                mask = fn_801F2B7C(a, 0, -1, 1);
            }
            fn_801F2B20(a, 5);
            if (mask > 0) {
                for (j = 0; j < 4; j++) {
                    if ((mask >> j) & 1) {
                        fn_80236074(j, 100, 0);
                    }
                }
            }
            if (w[0x8e] == 0) {
                w[0x94] += 1;
                if (w[0x94] > 8) {
                    b[0x11c] = 0;
                }
                w[0x8e] = lbl_804AB440[w[0x94]];
            }
            break;
        }
        }

        if (b[0xc4] == 0 && w[0x8c] != 3 && (w[0x8c] == 0 || w[0x8c] == 2)) {
            u8 hit = 0;
            f32 out2[3];
            if (fn_801A4F5C(w[0x66], (f32*)&box, (f32*)&p2) != 0) {
                hit = 1;
            }
            if (w[0x92] <= 0 && fn_801F305C(a)) {
                hit = 2;
            }
            if (hit != 0 || w[0x42] == 0) {
                ((ItemBase*)a)->v19();
                fn_8029EDB8(lbl_8053AC98, &a->field_0C, 0, w[1], out2);
                w[0x8c] = 3;
            }
        }

        {
            s32 seq[4] = {0, 3, 2, 1};
            if (w[0x8c] != 0 && b[0xc4] == 0 && w[0x8c] != 3 && w[0x8f] % 4 == 0) {
                if (w[0x8f] > 100) {
                    w[0x94] ^= 1;
                } else {
                    w[0x96] = (w[0x96] + 1) % 4;
                    w[0x94] = seq[w[0x96]];
                }
            }
        }
        if (w[0x8c] != 3 && w[0x8f] == 0) {
            f32 out[3];
            ((ItemBase*)a)->v19();
            fn_8029EDB8(lbl_8053AC98, &a->field_0C, 0, w[1], out);
            w[0x8c] = 3;
        }
        if (w[0x8c] != 0 && b[0xc4] == 0) {
            if (w[0x8e] > 0) {
                w[0x8e]--;
            }
            if (w[0x8f] > 0) {
                w[0x8f]--;
            }
            if (w[0x90] > 0) {
                w[0x90]--;
            }
            if (w[0x91] > 0) {
                w[0x91]--;
            }
            if (w[0x92] > 0) {
                w[0x92]--;
            }
            if (w[0x93] > 0) {
                w[0x93]--;
            }
        }
    }
}
#pragma dont_inline reset
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
        s32 ang;
        *(s32*)(p + 0x23c) = 300;
        *(s32*)(p + 0x248) = 120;
        *(s32*)(p + 0x230) = 2;
        *(u32*)(p + 0xb0) = 0x73308;
        ang = (s32)(65536.0f * rand01());
        a->field_3C.x = k * sincosTable___5JMath[(u16)ang >> 5].sin;
        a->field_3C.y = k * sincosTable___5JMath[(u16)ang >> 5].cos;
        a->field_3C.z = 0.0f;
        *(u8*)(p + 0x275) = 0;
        break;
    }
    case 3: {
        s32 r;
        *(s32*)(p + 0x23c) = 300;
        *(s32*)(p + 0x24c) = 10;
        *(s32*)(p + 0x230) = 2;
        *(u32*)(p + 0xb0) = 0x73308;
        r = (s32)(2.0f * rand01());
        *(u8*)(p + 0x277) = 0;
        if (r != 0) {
            a->field_3C.x = k;
        } else {
            a->field_3C.x = -k;
        }
        a->field_3C.y = 0.0f;
        a->field_3C.z = 0.0f;
        *(u8*)(p + 0x275) = 0;
        break;
    }
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

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" char lbl_805089F8[];
extern "C" void fn_8032686C(void) {
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

