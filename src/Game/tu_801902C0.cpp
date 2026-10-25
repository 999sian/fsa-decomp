#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry.h"
#include <dolphin/mtx.h>
#include "Game/ItemBase.h"

extern "C" double sin(double);
extern "C" double cos(double);

extern "C" f32 lbl_8053E214;

static inline void setRotX90(Mtx m) {
    f32 s = sin(lbl_8053E214);
    f32 c = cos(lbl_8053E214);
    m[0][0] = 1.0f;
    m[1][1] = c;
    m[1][2] = -s;
    m[2][1] = s;
    m[2][2] = c;
    m[0][1] = m[1][0] = m[0][2] = m[2][0] = 0.0f;
}

static inline f32 calcLayerOffset(f32 z, s32 a, s32 b) {
    if (z > 0.0f && a < 1) {
        a++;
        b--;
    }
    return (f32)(a * 0x400 + b * 0x80);
}

static inline f32 calcLayerOffset(f32 z, const u8* e) {
    s32 a = *(s32*)(e + 0x5c);
    s32 b = *(s32*)(e + 0x60);
    if (z > 0.0f && a < 1) {
        a++;
        b--;
    }
    return (f32)(a * 0x400 + b * 0x80);
}

static inline void setRotX(Mtx m, f32 angle) {
    f32 s = sin(angle);
    f32 c = cos(angle);
    m[0][0] = 1.0f;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = c;
    m[1][2] = -s;
    m[2][0] = 0.0f;
    m[2][1] = s;
    m[2][2] = c;
}

extern "C" void* lbl_8053AAF8;
extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void);
extern "C" u8 fn_80239D38(void);
extern "C" u8 lbl_80529DEC[];
extern "C" u8* lbl_8053AEC8;
extern "C" void* lbl_8053AB10;
extern "C" const char lbl_80467508[];
extern "C" void fn_8013ABCC(void* obj, Vec* pos, Mtx mtx);

static inline void drawAtScreenCenter(void* obj) {
    u8* o = fn_802D6A9C();
    Mtx m;
    PSMTXTrans(m, 0.5f * (*(f32*)(o + 0xcc) + *(f32*)(o + 0xd4)),
               0.5f * (*(f32*)(o + 0xd0) + *(f32*)(o + 0xd8)) + 1024.0f, 1024.0f);
    JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
    fn_8013ABCC(obj, &v, m);
}

extern "C" void* fn_801902C0(void) {
    return *(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x20);
}

extern "C" void fn_8013ABCC(void* obj, Vec* pos, Mtx mtx);
extern "C" void fn_802F6CF4(void* obj, JGeometry::TVec3f* pos, void* res, DrawRec* rec);
extern "C" void fn_801902D0(u8* p) {
    struct ResMgr {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void* getRes(u32 type, const char* name);
    };
    f32 x;
    f32 y;
    f32 z;
    u8* cur;
    s32 i;
    cur = p;
    for (i = 0; i < 7; i++, cur += 0x60) {
        if (cur[0x64] != 0) {
            JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)(cur + 8);
            x = *(f32*)(cur + 0x20);
            y = *(f32*)(cur + 0x30);
            z = *(f32*)(cur + 0x40);
            Mtx m;
            Mtx r;
            f32 off = calcLayerOffset(z, *(s32*)(cur + 0x5c), *(s32*)(cur + 0x60));
            m[0][3] = 0.0f;
            m[1][3] = 0.0f;
            m[2][3] = 0.0f;
            PSMTXScale(m, 1.0f, 0.70710677f, 0.70710677f);
            PSMTXConcat(m, (MtxPtr)(cur + 0x14), m);
            r[0][3] = 0.0f;
            r[1][3] = 0.0f;
            r[2][3] = 0.0f;
            setRotX90(r);
            PSMTXConcat(m, r, m);
            m[0][3] = x;
            m[1][3] = y + off;
            m[2][3] = z + off;
            v.x = -v.x;
            fn_8013ABCC(*(void**)(cur + 0x44), &v, m);
        }
    }
    if (*(void**)(p + 0x2b4) != NULL && p[0x2c0] != 0) {
        JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
        Mtx m;
        PSMTXTrans(m, *(f32*)(p + 0x2a8), *(f32*)(p + 0x2ac), *(f32*)(p + 0x2b0));
        v.scale(10.24f);
        m[1][3] += 2048.0f;
        m[2][3] += 2048.0f;
        fn_8013ABCC(*(void**)(p + 0x2b8), &v, m);
        m[1][3] -= 2048.0f;
        m[2][3] -= 2048.0f;
        fn_8013ABCC(*(void**)(p + 0x2b4), &v, m);
    }
    if (*(void**)(p + 0x2d0) != NULL && p[0x2dc] != 0) {
        JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
        Mtx m;
        PSMTXTrans(m, *(f32*)(p + 0x2c4), *(f32*)(p + 0x2c8), *(f32*)(p + 0x2cc));
        if (!(*(s32*)(lbl_80529DEC + 0x118) == 9 && *(s32*)(lbl_80529DEC + 0x11c) == 3) &&
            !(*(s32*)(lbl_80529DEC + 0x118) == 8 && *(s32*)(lbl_80529DEC + 0x11c) == 2)) {
            m[1][3] += 1024.0f;
            m[2][3] += 1024.0f;
        }
        v.scale(10.24f);
        fn_8013ABCC(*(void**)(p + 0x2d0), &v, m);
    }
    if (*(void**)(p + 0x2ec) != NULL && p[0x2fc] != 0) {
        JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
        Mtx m;
        PSMTXTrans(m, *(f32*)(p + 0x2e0), *(f32*)(p + 0x2e4), *(f32*)(p + 0x2e8));
        m[1][3] -= 256.0f;
        m[2][3] -= 256.0f;
        v.scale(10.24f);
        fn_8013ABCC(*(void**)(p + 0x2ec), &v, m);
    }
    if (*(void**)(p + 0x30c) != NULL && p[0x31c] != 0) {
        JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
        Mtx m;
        PSMTXTrans(m, *(f32*)(p + 0x300), *(f32*)(p + 0x304), *(f32*)(p + 0x308));
        m[1][3] -= 256.0f;
        m[2][3] -= 256.0f;
        v.scale(10.24f);
        fn_8013ABCC(*(void**)(p + 0x30c), &v, m);
    }
    if (*(void**)(p + 0x32c) != NULL && p[0x33c] != 0) {
        JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
        Mtx m;
        PSMTXTrans(m, *(f32*)(p + 0x320), *(f32*)(p + 0x324), *(f32*)(p + 0x328));
        m[1][3] -= 256.0f;
        m[2][3] -= 256.0f;
        v.scale(10.24f);
        fn_8013ABCC(*(void**)(p + 0x32c), &v, m);
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x4a8); cur += 0x24, i++) {
        if (*(void**)(cur + 0x358) != NULL) {
            JGeometry::TVec3<f32> v;
            Mtx m;
            PSMTXTrans(m, *(f32*)(cur + 0x340), *(f32*)(cur + 0x344), *(f32*)(cur + 0x348));
            m[1][3] -= 256.0f;
            m[2][3] -= 256.0f;
            f32 s = 16.0f * *(f32*)(cur + 0x34c) / 10.0f;
            v.x = v.y = v.z = s;
            v.z = -s;
            fn_8013ABCC(*(void**)(cur + 0x358), &v, m);
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x5ec); cur += 0x28, i++) {
        if (*(void**)(cur + 0x4c0) != NULL) {
            JGeometry::TVec3<f32> v(1.0f, 0.7f, -1.0f);
            Mtx m;
            PSMTXTrans(m, *(f32*)(cur + 0x4ac), *(f32*)(cur + 0x4b0), *(f32*)(cur + 0x4b4));
            f32 s = sin(lbl_8053E214);
            f32 c = cos(lbl_8053E214);
            m[0][0] = 1.0f;
            m[1][1] = c;
            m[1][2] = -s;
            m[2][1] = s;
            m[2][2] = c;
            m[0][1] = m[1][0] = m[0][2] = m[2][0] = 0.0f;
            v.scale(1.5f);
            fn_8013ABCC(*(void**)(cur + 0x4c0), &v, m);
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x618); cur += 0x14, i++) {
        if (*(void**)(cur + 0x5fc) != NULL) {
            JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
            Mtx m;
            PSMTXTrans(m, *(f32*)(cur + 0x5f0), *(f32*)(cur + 0x5f4), *(f32*)(cur + 0x5f8));
            m[0][3] -= 256.0f;
            m[1][3] += 768.0f;
            m[2][3] += 1024.0f;
            v.scale(10.24f);
            fn_8013ABCC(*(void**)(cur + 0x5fc), &v, m);
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x79c); cur += 0x18, i++) {
        if (*(void**)(cur + 0x62c) != NULL) {
            JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
            Mtx m;
            DrawRec rec;
            PSMTXTrans(m, *(f32*)(cur + 0x61c), *(f32*)(cur + 0x620), *(f32*)(cur + 0x624));
            m[1][3] -= 1024.0f;
            m[2][3] -= 1024.0f;
            if (cur[0x628] != 0) {
                v.scale(0.33333334f);
            }
            JGeometry::TVec3<f32> pos;
            pos.x = *(f32*)(cur + 0x61c);
            pos.y = *(f32*)(cur + 0x620);
            pos.z = *(f32*)(cur + 0x624);
            if (cur[0x628] != 0) {
                pos.x -= 16.0f;
                pos.y -= 16.0f;
            } else {
                pos.x -= 48.0f;
                pos.y -= 48.0f;
            }
            *(s8*)&rec.b1c = -1;
            rec.b1d = -1;
            fn_8013ABCC(*(void**)(cur + 0x62c), &v, m);
            fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos,
                        (*(ResMgr**)((u8*)lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, lbl_80467508), &rec);
        }
    }
    if (*(void**)(p + 0x7ac) != NULL && p[0x7a8] != 0) {
        u8* o = fn_802D6A9C();
        Mtx m;
        PSMTXTrans(m, 0.5f * (*(f32*)(o + 0xcc) + *(f32*)(o + 0xd4)),
                   0.5f * (*(f32*)(o + 0xd0) + *(f32*)(o + 0xd8)) + 1024.0f, 1024.0f);
        fn_8013ABCC(*(void**)(p + 0x7ac), &JGeometry::TVec3<f32>(1.0f, 1.0f, -1.0f), m);
    }
    if (*(void**)(p + 0x7c4) != NULL && *(s32*)(p + 0x7bc) > 0 &&
        *(s32*)(p + 0x7bc) < *(s16*)(*(u8**)(p + 0x7c8) + 6)) {
        u8* o = fn_802D6A9C();
        Mtx m;
        PSMTXTrans(m, 0.5f * (*(f32*)(o + 0xcc) + *(f32*)(o + 0xd4)),
                   0.5f * (*(f32*)(o + 0xd0) + *(f32*)(o + 0xd8)) + 1024.0f, 1024.0f);
        fn_8013ABCC(*(void**)(p + 0x7c4), &JGeometry::TVec3<f32>(1.0f, 1.0f, -1.0f), m);
    }
    if (*(void**)(p + 0x7e0) != NULL && p[0x7ec] != 0) {
        JGeometry::TVec3<f32> v(1.0f, 1.0f, -1.0f);
        Mtx m;
        PSMTXTrans(m, *(f32*)(p + 0x7d0), *(f32*)(p + 0x7d4), *(f32*)(p + 0x7d8));
        fn_8013ABCC(*(void**)(p + 0x7e0), &v, m);
    }
}

extern "C" void fn_80190DC8(u8* p) {
    u8* e3;
    s32 i;
    s32 t = *(s32*)(p + 4);
    u8* cur = p;
    for (i = 0; i < 7; i++, cur += 0x60) {
        u8* e = *(u8**)(cur + 0x48);
        if (e != NULL && cur[0x64] != 0) {
            *(f32*)(e + 8) = (f32)(t % *(s16*)(e + 6));
            f32 f = *(f32*)(cur + 0x50);
            if (f >= 0.0f) {
                if (f == 0.0f) {
                    *(f32*)(*(u8**)(cur + 0x4c) + 8) = 201.0f;
                } else if (f < 1.0f) {
                    *(f32*)(*(u8**)(cur + 0x4c) + 8) = 200.0f * f + 201.0f;
                } else {
                    *(s32*)(cur + 0x58) = *(s32*)(cur + 0x58) + 1;
                    *(f32*)(*(u8**)(cur + 0x4c) + 8) = (f32)(*(s32*)(cur + 0x58) % 200 + 401);
                }
            } else {
                s32 x = *(s32*)(cur + 0x54);
                if (x >= 0) {
                    *(f32*)(*(u8**)(cur + 0x4c) + 8) = (f32)x;
                }
            }
        }
    }
    u8* e2 = *(u8**)(p + 0x2bc);
    if (e2 != NULL && p[0x2c0] != 0) {
        *(f32*)(e2 + 8) = (f32)(t % *(s16*)(e2 + 6));
    }
    e2 = *(u8**)(p + 0x2d8);
    if (e2 != NULL && p[0x2dc] != 0) {
        *(f32*)(e2 + 8) = (f32)(t % *(s16*)(e2 + 6));
    }
    e2 = *(u8**)(p + 0x2f0);
    if (e2 != NULL && p[0x2fc] != 0) {
        *(f32*)(e2 + 8) = 121.0f * *(f32*)(p + 0x2f4);
    }
    e2 = *(u8**)(p + 0x310);
    if (e2 != NULL && p[0x31c] != 0) {
        *(f32*)(e2 + 8) = (f32)(s32)(37.0f * *(f32*)(p + 0x314));
    }
    e2 = *(u8**)(p + 0x330);
    if (e2 != NULL && p[0x33c] != 0) {
        if (*(f32*)(p + 0x334) < 1.0f) {
            *(f32*)(e2 + 8) = 121.0f * *(f32*)(p + 0x334);
            *(s32*)(p + 0x338) = 0;
        } else {
            *(f32*)(e2 + 8) = (f32)(*(s32*)(p + 0x338) % 120 + 121);
            *(s32*)(p + 0x338) = *(s32*)(p + 0x338) + 1;
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x4a8); i++, cur += 0x24) {
        e3 = *(u8**)(cur + 0x35c);
        if (e3 != NULL) {
            s32 v = (s32)((f32)t * *(f32*)(cur + 0x354));
            *(f32*)(e3 + 8) = (f32)(v % *(s16*)(e3 + 6));
            *(f32*)(*(u8**)(cur + 0x360) + 8) = (f32)(s32)(60.0f - 59.0f * *(f32*)(cur + 0x350));
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x5ec); i++, cur += 0x28) {
        e3 = *(u8**)(cur + 0x4c4);
        if (e3 != NULL) {
            *(f32*)(e3 + 8) = (f32)(t % *(s16*)(e3 + 6));
            *(f32*)(*(u8**)(cur + 0x4c8) + 8) = *(f32*)(cur + 0x4bc);
            u8* e4 = *(u8**)(cur + 0x4cc);
            *(f32*)(e4 + 8) = (f32)(t % *(s16*)(e4 + 6));
            *(f32*)(*(u8**)(cur + 0x4d0) + 8) = (f32)*(s32*)(cur + 0x4b8);
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x618); i++, cur += 0x14) {
        e3 = *(u8**)(cur + 0x600);
        if (e3 != NULL) {
            *(f32*)(e3 + 8) = (f32)(t % *(s16*)(e3 + 6));
        }
    }
    cur = p;
    for (i = 0; i < *(s32*)(p + 0x79c); i++, cur += 0x18) {
        e3 = *(u8**)(cur + 0x630);
        if (e3 != NULL) {
            *(f32*)(e3 + 8) = (f32)(t % *(s16*)(e3 + 6));
        }
    }
    u8* e5 = *(u8**)(p + 0x7b0);
    if (e5 != NULL && p[0x7a8] != 0) {
        *(f32*)(e5 + 8) = (f32)(t % *(s16*)(e5 + 6));
        if (*(s32*)(p + 0x7a4) > 0) {
            *(s32*)(p + 0x7a4) = *(s32*)(p + 0x7a4) - 1;
        } else if (*(s32*)(p + 0x7a0) < *(s16*)(*(u8**)(p + 0x7b4) + 6)) {
            *(s32*)(p + 0x7a0) = *(s32*)(p + 0x7a0) + 1;
        } else {
            *(s32*)(p + 0x7a0) = 0;
            u8* g = (u8*)lbl_8053AAF8;
            *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)(p + 0x7a4) = (s32)(120.0f * (*(f32*)&bits - 1.0f));
        }
        if (*(s32*)(p + 0x7a0) == 0) {
            *(f32*)(*(u8**)(p + 0x7b4) + 8) = (f32)*(s16*)(*(u8**)(p + 0x7b4) + 6);
        } else {
            *(f32*)(*(u8**)(p + 0x7b4) + 8) = (f32)(*(s32*)(p + 0x7a0) - 1);
        }
    }
    u8* e6 = *(u8**)(p + 0x7c8);
    if (e6 != NULL) {
        if (p[0x7c0] != 0 || (*(s32*)(p + 0x7bc) > 0 && *(s32*)(p + 0x7bc) < *(s16*)(e6 + 6))) {
            *(s32*)(p + 0x7bc) = *(s32*)(p + 0x7bc) + 1;
        }
        *(f32*)(e6 + 8) = (f32)*(s32*)(p + 0x7bc);
    }
    u8* e7 = *(u8**)(p + 0x7e4);
    if (e7 != NULL && p[0x7ec] != 0) {
        *(f32*)(e7 + 8) = (f32)*(s32*)(p + 0x7dc);
        *(f32*)(*(u8**)(p + 0x7e8) + 8) = (f32)*(s32*)(p + 0x7dc);
    }
}

extern "C" void fn_801914C4(u8* p) {
    bool f;
    u8* g = (u8*)lbl_8053AAF8;
    if (g[0x7f] != 0) {
        s32 x = (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb);
        f = x;
    } else {
        s32 x = (*(s32*)(g + 0x4c) == 7 || *(s32*)(g + 0x4c) == 8 || *(s32*)(g + 0x4c) == 9 || *(s32*)(g + 0x4c) == 0x16 || *(s32*)(g + 0x4c) == 0xa || *(s32*)(g + 0x4c) == 0xb || *(s32*)(g + 0x4c) == 0xc);
        f = x;
    }
    if (f) {
        fn_802D6A9C();
        if (fn_802DCD0C()) {
            goto end;
        }
    }
    g = (u8*)lbl_8053AAF8;
    if (g[0x94] != 0 || g[0x96] != 0) {
        goto end;
    }
    if (g[0x7f] != 0) {
        bool b;
        if (fn_80239D38()) {
            goto end;
        }
        g = (u8*)lbl_8053AAF8;
        if (*(s32*)(g + 0x4c) == 0xb) {
            b = true;
        } else {
            b = (g[0x88] == 2);
        }
        if (b) {
            goto end;
        }
    }
    if (lbl_80529DEC[0x240] == 0 && lbl_8053AEC8[0x5d] == 0) {
        p[0x64] = 0;
        p[0xc4] = 0;
        p[0x124] = 0;
        p[0x184] = 0;
        p[0x1e4] = 0;
        p[0x244] = 0;
        p[0x2a4] = 0;
        p[0x2c0] = 0;
        p[0x2dc] = 0;
        p[0x2fc] = 0;
        p[0x31c] = 0;
        p[0x33c] = 0;
        *(s32*)(p + 0x4a8) = 0;
        *(s32*)(p + 0x5ec) = 0;
        *(s32*)(p + 0x618) = 0;
        *(s32*)(p + 0x79c) = 0;
        p[0x7a8] = 0;
        p[0x7c0] = 0;
        p[0x7ec] = 0;
    }
end:
    *(s32*)(p + 4) = *(s32*)(p + 4) + 1;
}

extern "C" f32 lbl_8053E218;
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void fn_8019169C(u8* param_1) {
    f32 fzero = lbl_8053E218;
    *(u8*)(param_1 + 0x64) = 0;
    *(f32*)(param_1 + 0x50) = fzero;
    *(s32*)(param_1 + 0x58) = 0;
    *(u8*)(param_1 + 0xc4) = 0;
    *(f32*)(param_1 + 0xb0) = fzero;
    *(s32*)(param_1 + 0xb8) = 0;
    *(u8*)(param_1 + 0x124) = 0;
    *(f32*)(param_1 + 0x110) = fzero;
    *(s32*)(param_1 + 0x118) = 0;
    *(u8*)(param_1 + 0x184) = 0;
    *(f32*)(param_1 + 0x170) = fzero;
    *(s32*)(param_1 + 0x178) = 0;
    *(u8*)(param_1 + 0x1e4) = 0;
    *(f32*)(param_1 + 0x1d0) = fzero;
    *(s32*)(param_1 + 0x1d8) = 0;
    *(u8*)(param_1 + 0x244) = 0;
    *(f32*)(param_1 + 0x230) = fzero;
    *(s32*)(param_1 + 0x238) = 0;
    *(u8*)(param_1 + 0x2a4) = 0;
    *(f32*)(param_1 + 0x290) = fzero;
    *(s32*)(param_1 + 0x298) = 0;
    *(u8*)(param_1 + 0x2c0) = 0;
    *(u8*)(param_1 + 0x2dc) = 0;
    *(u8*)(param_1 + 0x2fc) = 0;
    *(u8*)(param_1 + 0x31c) = 0;
    *(u8*)(param_1 + 0x33c) = 0;
    *(s32*)(param_1 + 0x338) = 0;
    *(s32*)(param_1 + 0x4a8) = 0;
    *(s32*)(param_1 + 0x5ec) = 0;
    *(s32*)(param_1 + 0x618) = 0;
    *(s32*)(param_1 + 0x79c) = 0;
    *(u8*)(param_1 + 0x7a8) = 0;
    *(s32*)(param_1 + 0x7a4) = 300;
    *(s32*)(param_1 + 0x7a0) = 0;
    *(u8*)(param_1 + 0x7c0) = 0;
    *(s32*)(param_1 + 0x7bc) = 0;
    *(u8*)(param_1 + 0x7ec) = 0;
    *(s32*)(param_1 + 4) = 0;
}

extern "C" void** fn_80191744(void** param_1, s16 param_2) {
    if (param_1 != NULL) {
        if (param_1[499] != NULL) {
            void* obj = param_1[499];
            if (obj != NULL) {
                ((void (**)(void*, int))(*(void***)((u8*)obj + 8)))[12](obj, 1);
            }
        }
        if (param_1[0x1ee] != NULL) {
            void* obj = param_1[0x1ee];
            if (obj != NULL) {
                ((void (**)(void*, int))(*(void***)((u8*)obj + 8)))[12](obj, 1);
            }
        }
        destroy__7JKRHeapFv(*param_1);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80191E00(void);
extern "C" void fn_80191E04(void);
extern "C" void fn_80191E08(void);
extern "C" void fn_80191E0C(void);
extern "C" void fn_80191E10(void);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* create__12JKRSolidHeapFUlP7JKRHeapb(u32 size, void* parent, bool errorFlag);
extern "C" void becomeCurrentHeap__7JKRHeapFv(void* heap);
extern "C" void adjustSize__12JKRSolidHeapFv(void* heap);
extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__14WaveControllerFlll(void* self, s32 a, s32 b, s32 c);
extern "C" int sprintf(char* s, const char* format, ...);
extern "C" void fn_8016A3BC(void* archive, const void* a, const void* b, const void* c, const void* d, const void* e, u32 f, void* heap, void* p0, void* p1, const void* g, void* p2, void* h);
extern "C" const char lbl_80467508[];
extern "C" void* fn_801917E0(u8* param_1, void* param_2) {
    u8* arc;
    const char* str;
    char nameA[32];
    char nameB[32];
    char nameC[32];

    str = lbl_80467508;
    __construct_array(param_1 + 0x8, (void*)fn_80191E10, 0, 0x60, 7);
    __construct_array(param_1 + 0x340, (void*)fn_80191E0C, 0, 0x24, 10);
    __construct_array(param_1 + 0x4ac, (void*)fn_80191E08, 0, 0x28, 8);
    __construct_array(param_1 + 0x5f0, (void*)fn_80191E04, 0, 0x14, 2);
    __construct_array(param_1 + 0x61c, (void*)fn_80191E00, 0, 0x18, 0x10);
    *(void**)param_1 = create__12JKRSolidHeapFUlP7JKRHeapb(-1, param_2, false);
    becomeCurrentHeap__7JKRHeapFv(*(void**)param_1);

    arc = lbl_80529DEC;
    {
        u8* elem = param_1;
        for (s32 i = 0; i < 7; i++) {
            sprintf(nameA, str + 0x10, i + 1);
            sprintf(nameB, str + 0x20, i + 1);
            sprintf(nameC, str + 0x30, i + 1);
            if (((void* (*)(void*, u32, const char*))(*(void***)*(void**)(arc + 0x10))[6])(*(void**)(arc + 0x10), 0x4a334420, nameA) == 0) {
                sprintf(nameA, str + 0x40);
                sprintf(nameB, str + 0x50);
                sprintf(nameC, str + 0x60);
            }
            fn_8016A3BC(*(void**)(arc + 0x10), nameA, nameB, 0, nameC, 0, 0x20240000, *(void**)param_1, elem + 0x44, elem + 0x48, 0, elem + 0x4c, 0);
            elem += 0x60;
        }
    }

    fn_8016A3BC(*(void**)(arc + 0x10), str + 0x70, str + 0x7c, 0, 0, 0, 0x20240000, *(void**)param_1, param_1 + 0x2b4, param_1 + 0x2bc, 0, 0, 0);
    fn_8016A3BC(*(void**)(arc + 0x10), str + 0x88, 0, 0, 0, 0, 0x20240000, *(void**)param_1, param_1 + 0x2b8, 0, 0, 0, 0);
    fn_8016A3BC(*(void**)(arc + 0x10), str + 0x94, str + 0xa0, 0, 0, 0, 0x20240000, *(void**)param_1, param_1 + 0x2d0, param_1 + 0x2d8, 0, 0, 0);
    fn_8016A3BC(*(void**)(arc + 0x10), str + 0xac, str + 0xbc, 0, 0, 0, 0x240000, *(void**)param_1, param_1 + 0x2ec, param_1 + 0x2f0, 0, 0, 0);
    fn_8016A3BC(*(void**)(arc + 0x10), str + 0xcc, str + 0xe0, 0, 0, 0, 0x240000, *(void**)param_1, param_1 + 0x30c, param_1 + 0x310, 0, 0, 0);
    fn_8016A3BC(*(void**)(arc + 0x10), str + 0xf4, str + 0x104, 0, 0, 0, 0x240000, *(void**)param_1, param_1 + 0x32c, param_1 + 0x330, 0, 0, 0);

    {
        u8* elem = param_1;
        for (s32 i = 0; i < 10; i++) {
            fn_8016A3BC(*(void**)(arc + 0x10), str + 0x114, str + 0x120, 0, str + 0x12c, 0, 0x240000, *(void**)param_1, elem + 0x358, elem + 0x35c, 0, elem + 0x360, 0);
            elem += 0x24;
        }
    }

    {
        u8* elem = param_1;
        for (s32 i = 0; i < 8; i++) {
            fn_8016A3BC(*(void**)(arc + 0x14), str + 0x138, str + 0x14c, str + 0x160, str + 0x178, str + 0x18c, 0x20240000, *(void**)param_1, elem + 0x4c0, elem + 0x4c4, elem + 0x4c8, elem + 0x4cc, elem + 0x4d0);
            elem += 0x28;
        }
    }

    {
        u8* elem = param_1;
        for (s32 i = 0; i < 2; i++) {
            fn_8016A3BC(*(void**)(arc + 0x14), str + 0x1a4, str + 0x1b4, 0, 0, 0, 0x01240000, *(void**)param_1, elem + 0x5fc, elem + 0x600, 0, 0, 0);
            elem += 0x14;
        }
    }

    {
        u8* elem = param_1;
        for (s32 i = 0; i < 16; i++) {
            fn_8016A3BC(*(void**)(arc + 0x10), str + 0x1c4, str + 0x1d4, 0, 0, 0, 0x240000, *(void**)param_1, elem + 0x62c, elem + 0x630, 0, 0, 0);
            elem += 0x18;
        }
    }

    fn_8016A3BC(*(void**)(arc + 0x10), str + 0x1e4, str + 0x1f8, 0, str + 0x20c, 0, 0x240000, *(void**)param_1, param_1 + 0x7ac, param_1 + 0x7b0, 0, param_1 + 0x7b4, 0);
    fn_8016A3BC(*(void**)(arc + 0x10), str + 0x220, 0, 0, str + 0x234, 0, 0x10220000, *(void**)param_1, param_1 + 0x7c4, 0, 0, param_1 + 0x7c8, 0);
    fn_8016A3BC(*(void**)(arc + 0x10), str + 0x248, str + 0x258, 0, str + 0x268, 0, 0x10240000, *(void**)param_1, param_1 + 0x7e0, param_1 + 0x7e4, 0, param_1 + 0x7e8, 0);

    adjustSize__12JKRSolidHeapFv(*(void**)param_1);
    becomeCurrentHeap__7JKRHeapFv(param_2);

    {
        void* wc;
        wc = __nw__FUl(0x5c);
        if (wc != 0) {
            __ct__14WaveControllerFlll(wc, 0, 0, 8);
        }
        *(void**)(param_1 + 0x7b8) = wc;
        wc = __nw__FUl(0x5c);
        if (wc != 0) {
            __ct__14WaveControllerFlll(wc, 0, 0, 8);
        }
        *(void**)(param_1 + 0x7cc) = wc;
    }
    return param_1;
}

extern "C" void fn_80191E00(void) {}

extern "C" void fn_80191E04(void) {}

extern "C" void fn_80191E08(void) {}

extern "C" void fn_80191E0C(void) {}

extern "C" void fn_80191E10(void) {}

void __sinit_tu_801902C0_cpp(void) {}

