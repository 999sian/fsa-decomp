#include "types.h"

#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Util.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void fn_801F0E34(void* self, u32 id, s32 b);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_8022F3DC(s32);
extern const f32 lbl_80542618;
extern const f32 lbl_80542604;
static JGeometry::TBox2f lbl_8050ADF8[4] = {
    JGeometry::TBox2f(-31.0f, -31.0f, 31.0f, -17.0f),
    JGeometry::TBox2f(-31.0f, 17.0f, 31.0f, 31.0f),
    JGeometry::TBox2f(-31.0f, -31.0f, -17.0f, 31.0f),
    JGeometry::TBox2f(17.0f, -31.0f, 31.0f, 17.0f),
};
static JGeometry::TBox2f lbl_8050AE38[10] = {
    JGeometry::TBox2f(-14.0f, -6.0f, 0.0f, 22.0f),
    JGeometry::TBox2f(0.0f, -22.0f, 14.0f, 6.0f),
    JGeometry::TBox2f(-14.0f, -22.0f, 0.0f, -8.0f),
    JGeometry::TBox2f(0.0f, -22.0f, 14.0f, 22.0f),
    JGeometry::TBox2f(-22.0f, -14.0f, 6.0f, 0.0f),
    JGeometry::TBox2f(-6.0f, 0.0f, 22.0f, 14.0f),
    JGeometry::TBox2f(-14.0f, 8.0f, 0.0f, 22.0f),
    JGeometry::TBox2f(0.0f, -22.0f, 14.0f, 22.0f),
    JGeometry::TBox2f(-14.0f, -22.0f, 0.0f, 22.0f),
    JGeometry::TBox2f(0.0f, -22.0f, 14.0f, -8.0f),
};

extern const f32 lbl_8054261C;
extern const f64 lbl_805425F8;
extern const f32 lbl_805425D8;
extern const f32 lbl_805425DC;
extern const f32 lbl_805425E0;
extern const f32 lbl_805425E4;
extern const f32 lbl_805425E8;
extern const f32 lbl_805425EC;
extern const f32 lbl_805425F0;
extern const f32 lbl_80542600;

struct Actor {
    ~Actor();
};

extern "C" void __dt__5ActorFv(Actor* self, s16 flag);
extern u8 lbl_804ACA00[];
void operator delete(void* p);

extern "C" Actor* fn_8034EDDC(Actor* self, s16 flag) {
    if (self != 0) {
        *(u8**)self = lbl_804ACA00;
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" void fn_801F06F0(u8* self, const char* tbl, s32 idx, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_80307AC8(u32 x, u32 y, void* v, s32 idx, int p6, u32 u, int minus1);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" char lbl_80472228[];
static inline f32 enemyDrawSin(f32 x) { return sin(x); }
static inline f32 enemyDrawCos(f32 x) { return cos(x); }
static inline void enemyDrawRot(f32 m[3][4], f32 ax, f32 ay, f32 az, f32 s) {
    f32 cx;
    f32 sx = enemyDrawSin(ax);
    f32 sy = enemyDrawSin(ay);
    f32 sz = enemyDrawSin(az);
    cx = enemyDrawCos(ax);
    f32 cy = enemyDrawCos(ay);
    f32 cz = enemyDrawCos(az);
    f32 cc = cx * cz;
    f32 ss = sx * sy;
    f32 cs = cx * sz;
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (ss * cz - cs);
    m[1][1] = s * (ss * sz + cc);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cc * sy + sx * sz);
    m[1][2] = s * (cs * sy - sx * cz);
    m[2][2] = s * (cx * cy);
}
extern "C" void fn_8034EE3C(u8* self) {
    s32 mode = 0xff;
    int t;
    int v;

    if (*(s32*)(self + 0x230) == 4) {
        return;
    }
    if (*(u8*)(self + 0x282) == 1) {
        t = *(s32*)(self + 0x24c);
        if (t % 40 < 20) {
            return;
        }
    }
        if (*(s32*)(self + 0x254) > 0) {
            return;
        }
        if (*(f32*)(self + 0x28c) <= lbl_805425D8) {
            return;
        }
    v = *(s32*)(self + 0x250);
        if (v > 120) {
            if (*(s32*)(self + 4) < 8) {
                int q = v % 40;
                if (q > 20) {
                    f32 range;
                    f32 center;
                    f32 f = q;
                    center = 20.0f;
                    range = 255.0f;
                    mode = (s32)(range * ((f - center) / center));
                } else {
                    f32 f = q;
                    f32 center = 20.0f;
                    f32 range = 255.0f;
                    mode = (s32)(range * ((center - f) / center));
                }
            } else if (v % 40 < 20) {
                return;
            }
        }

    DrawRec rec;
    f32 mtx[3][4];
    PSMTXIdentity(mtx);
    ((u8*)&rec)[0x13] = (u8)mode;
    rec.b20 = 0;

    if (*(s32*)(self + 0x258) == 0xb) {
        f32 d = lbl_805425E4 * *(f32*)(self + 0x28c);
        mtx[0][0] = d;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = d;
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = d;
    } else if (*(s32*)(self + 0x258) == 0x11) {
        mtx[0][0] = -*(f32*)(self + 0x28c);
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = *(f32*)(self + 0x28c);
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = *(f32*)(self + 0x28c);
    } else if (*(s32*)(self + 0x258) == 0x13) {
        f32 ca;
        f32 ab;
        f32 cc;
        f32 b;
        f32 s;
        f32 a = JMath::sincosTable_.mTable[0].first;
        s = *(f32*)(self + 0x28c);
        b = JMath::sincosTable_.mTable[1536].first;
        f32 c = JMath::sincosTable_.mTable[0].second;
        f32 d = JMath::sincosTable_.mTable[1536].second;
        f32 aa = a * a;
        cc = c * c;
        ab = a * b;
        ca = c * a;
        mtx[0][0] = s * (d * c);
        mtx[1][0] = s * (d * a);
        mtx[2][0] = s * -b;
        mtx[0][1] = s * (ab * c - ca);
        mtx[1][1] = s * (ab * a + cc);
        mtx[2][1] = s * (d * a);
        mtx[0][2] = s * (cc * b + aa);
        mtx[1][2] = s * (ca * b - ca);
        mtx[2][2] = s * (d * c);
    } else if (*(s32*)(self + 0x258) == 5) {
        f32 scale;
        f32 ang = lbl_805425E8 * (lbl_805425EC * (lbl_805425F0 - (scale = *(f32*)(self + 0x28c))));
        enemyDrawRot(mtx, lbl_805425D8, ang, lbl_805425D8, scale);
    } else {
        mtx[0][0] = *(f32*)(self + 0x28c);
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = *(f32*)(self + 0x28c);
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = *(f32*)(self + 0x28c);
    }

    rec.w18 = mtx;
    rec.b21 = 1;
    if ((*(s32*)(self + 0x258) <= 4 && *(s32*)(self + 0x268) == 2 &&
         (*(s32*)(self + 0x230) == 1 || *(s32*)(self + 0x230) == 3 || *(s32*)(self + 0x230) == 6)) ||
        (*(s32*)(self + 0x268) == 3 && (((*(s32*)(self + 0x230) == 1 || *(s32*)(self + 0x230) == 3) &&
         *(s32*)(self + 0x244) > 0) || *(s32*)(self + 0x230) == 5))) {
        ((s8*)&rec)[0x1c] = -1;
    } else {
        ((s8*)&rec)[0x1c] = 0;
    }
    rec.b1d = -3;
    if (*(s32*)(self + 0x258) == 0xb) {
        rec.b1d = -4;
    }

    fn_801F06F0(self, lbl_80472228, *(s32*)(self + 0x240) + 0x14, &rec, -1, lbl_805425F0, lbl_805425F0);
    fn_80307AC8(*(u32*)(self + 0x198), *(u32*)(self + 4), self + 0xc, *(s32*)(self + 0x240) + 0x14, 0, 0, -1);
}

extern "C" void fn_8034F43C(char* p) {
    if (*(s32*)(p + 0x230) == 4) {
        *(s32*)(p + 0x230) = 4;
    }
}

extern "C" void fn_8035001C(u8* self, u32 kind) {
    switch (kind) {
    case 0: {
        f32 x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * x;
        *(f32*)(self + 0x40) = lbl_805425D8;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 1: {
        f32 x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * -x;
        *(f32*)(self + 0x40) = lbl_805425D8;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 2: {
        f32 x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_805425D8;
        *(f32*)(self + 0x40) = lbl_80542600 * x;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 3: {
        f32 x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_805425D8;
        *(f32*)(self + 0x40) = lbl_80542600 * -x;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 4: {
        f32 x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * x;
        *(f32*)(self + 0x40) = lbl_80542600 * x;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 5: {
        f32 y = (f32)*(s32*)(self + 0x260);
        f32 x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * -x;
        *(f32*)(self + 0x40) = lbl_80542600 * y;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 6: {
        f32 y = (f32)*(s32*)(self + 0x260);
        f32 x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * x;
        *(f32*)(self + 0x40) = lbl_80542600 * -y;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    case 7: {
        f32 x = (f32)*(s32*)(self + 0x260);
        *(f32*)(self + 0x3c) = lbl_80542600 * -x;
        *(f32*)(self + 0x40) = lbl_80542600 * -x;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
    default:
        *(f32*)(self + 0x3c) = lbl_805425D8;
        *(f32*)(self + 0x40) = lbl_805425D8;
        *(f32*)(self + 0x44) = lbl_805425D8;
        break;
    }
}

extern "C" u32 fn_8013CC50(u32 owner, void* pos, u16 id, s32 a, f32 f, s32 b, s32 c, s32 d, s32 e);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 id, s32 kind, void* pos, s32 a, s32 b, s32 c);
extern const f32 lbl_805425F0;
extern const f32 lbl_805425D8;
extern "C" void fn_803511F0(u8* self);
extern "C" double sqrt(double);
extern const f32 lbl_80542608;
extern const f32 lbl_805425E8;
extern "C" s16 fn_8022461C(s32);
extern "C" s32 fn_80350274(s32 param_1, s32 param_2, s32 param_3) {
    s32 r = (u16)fn_8022461C(param_3);
    if (r == 0x3a || r == 3 || (u32)(r - 0xd) <= 1 || r == 0x3b) {
        return 0;
    }
    return 1;
}

extern "C" s32 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" s32 fn_803502CC(u8* self) {
    f32 s0 = *(f32*)(self + 0x80);
    f32 s1 = *(f32*)(self + 0x84);
    f32 s2 = *(f32*)(self + 0x88);
    f32 s3 = *(f32*)(self + 0x8c);
    s32 i;
    f32* p;
    s32 j;

    if (*(s32*)(self + 0x258) == 4) {
        p = (f32*)lbl_8050ADF8;
        for (i = 0; i < 4; i++) {
            *(f32*)(self + 0x80) = p[0];
            *(f32*)(self + 0x84) = p[1];
            *(f32*)(self + 0x88) = p[2];
            *(f32*)(self + 0x8c) = p[3];
            if (*(s32*)(self + 0x268) == 0 || *(s32*)(self + 0x268) == 1) {
                *(f32*)(self + 0x8c) = *(f32*)(self + 0x8c) - lbl_80542604;
            } else {
                *(f32*)(self + 0x84) = *(f32*)(self + 0x84) + *(f32*)(self + 0x290);
                *(f32*)(self + 0x8c) = *(f32*)(self + 0x8c) + *(f32*)(self + 0x290);
            }
            if ((u8)fn_801F2618(self, 0, 0) == 1) {
                *(f32*)(self + 0x80) = s0;
                *(f32*)(self + 0x84) = s1;
                *(f32*)(self + 0x88) = s2;
                *(f32*)(self + 0x8c) = s3;
                return 1;
            }
            p += 4;
        }
    } else if (*(s32*)(self + 0x258) >= 0x10 && *(s32*)(self + 0x258) <= 0x14) {
        j = 0;
        for (i = 0; i < 2; i++) {
            p = (f32*)((u8*)lbl_8050AE38 + (*(s32*)(self + 0x258) - 0x10) * 0x20 + j);
            *(f32*)(self + 0x80) = p[0];
            *(f32*)(self + 0x84) = p[1];
            *(f32*)(self + 0x88) = p[2];
            *(f32*)(self + 0x8c) = p[3];
            if (*(s32*)(self + 0x268) == 0 || *(s32*)(self + 0x268) == 1) {
                *(f32*)(self + 0x8c) = *(f32*)(self + 0x8c) - lbl_80542604;
            } else {
                *(f32*)(self + 0x84) = *(f32*)(self + 0x84) + *(f32*)(self + 0x290);
                *(f32*)(self + 0x8c) = *(f32*)(self + 0x8c) + *(f32*)(self + 0x290);
            }
            if ((u8)fn_801F2618(self, 0, 0) == 1) {
                *(f32*)(self + 0x80) = s0;
                *(f32*)(self + 0x84) = s1;
                *(f32*)(self + 0x88) = s2;
                *(f32*)(self + 0x8c) = s3;
                return 1;
            }
            j += 0x10;
        }
    } else {
        return fn_801F2618(self, 0, 0);
    }
    *(f32*)(self + 0x80) = s0;
    *(f32*)(self + 0x84) = s1;
    *(f32*)(self + 0x88) = s2;
    *(f32*)(self + 0x8c) = s3;
    return 0;
}

extern "C" s32 fn_80350530(u8* self) {
    s32 prev = *(s32*)(self + 0x270);
    s32 i;
    *(s32*)(self + 0x270) = 0;
    for (i = 0; i < 4; i++) {
        f32 x;
        f32 y;
        f32 r2;
        f32* p;
        f32 dx;
        f32 dy;
        f32 dx2;
        f32 dy2;
        if (fn_8022F514(i) == 1 && fn_8022CAF8(i) == 5) {
            continue;
        }
        x = *(f32*)(self + 0xc);
        y = *(f32*)(self + 0x10);
        r2 = lbl_80542618;
        if (prev != 0) {
            r2 = lbl_8054261C + (f32)*(s32*)(self + 0x260);
            r2 = r2 * r2;
        }
        p = (f32*)fn_8023E724(i);
        dx = x - p[0];
        dy = y - p[1];
        dx2 = dx * dx;
        dy2 = dy * dy;
        if (dx2 + dy2 < r2) {
            if (lbl_805425D8 == ((f32*)fn_8023E724(i))[2]) {
                if (prev == 0) {
                    fn_801F0E34(self, 0x30009, 0);
                    *(s32*)(self + 0x27c) = 0;
                    *(s32*)(self + 0x274) = i;
                    if (fn_8022F514(i) == 1) {
                        *(s32*)(self + 0x274) = fn_8022F3DC(i);
                    }
                }
                *(s32*)(self + 0x270) = 1;
                return *(s32*)(self + 0x244) <= 0 ? *(s32*)(self + 0x268) : -1;
            }
        }
    }
    *(s32*)(self + 0x27c) = 0;
    *(s32*)(self + 0x274) = -1;
    *(s32*)(self + 0x244) = 0;
    return -1;
}

extern const f32 lbl_80542614;
extern const f32 lbl_80542620;
extern u8 lbl_8053AD40;
static f32 lbl_8050AED8[8];

extern "C" s32 fn_803506E0(u8* self) {
    const f32* tbl;
    s32 bit;
    s32 j;
    s32 flags;
    s32 i;
    s32 m;
    f32 x;
    f32 y;
    f32 r2;
    f32 dx;
    f32 dy;
    f32 dx2;
    f32 dy2;
    f32* p;
    s32 idx;

    if (!*(s8*)&lbl_8053AD40) {
        lbl_8050AED8[0] = 32.0f;
        lbl_8050AED8[1] = 0.0f;
        lbl_8050AED8[2] = -32.0f;
        lbl_8050AED8[3] = 0.0f;
        lbl_8050AED8[4] = 0.0f;
        lbl_8050AED8[5] = 32.0f;
        lbl_8050AED8[6] = 0.0f;
        lbl_8050AED8[7] = -32.0f;
        lbl_8053AD40 = 1;
    }

    flags = *(s32*)(self + 0x270);
    *(s32*)(self + 0x270) = 0;
    for (i = 0; i < 4; i++) {
        if (fn_8022F514(i) == 1 && fn_8022CAF8(i) == 5) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            bit = 1 << j;
            x = lbl_8050AED8[j*2];
            y = lbl_8050AED8[j*2+1];
            x += *(f32*)(self + 0xc);
            y += *(f32*)(self + 0x10);
            r2 = lbl_80542618;
            m = flags & bit;
            if (m != 0) {
                r2 = lbl_8054261C + (f32)*(s32*)(self + 0x260);
                r2 = r2 * r2;
            }
            p = (f32*)fn_8023E724(i);
            dx = x - p[0];
            dy = y - p[1];
            dx2 = dx * dx;
            dy2 = dy * dy;
            if (dx2 + dy2 < r2) {
                if (0.0f == ((f32*)fn_8023E724(i))[2]) {
                    if (m == 0) {
                        fn_801F0E34(self, 0x30009, 0);
                    }
                    *(s32*)(self + 0x270) |= bit;
                }
            }
        }
    }

    flags = *(s32*)(self + 0x270);
    if ((flags & 1) && ((flags >> 1) & 1)) flags &= 12;
    if (((flags >> 2) & 1) && ((flags >> 3) & 1)) flags &= 3;
    if (flags == 1) {
        *(s32*)(self + 0x268) = 0;
    } else if (flags == 2) {
        *(s32*)(self + 0x268) = 1;
    } else if (flags == 4) {
        *(s32*)(self + 0x268) = 2;
    } else if (flags == 8) {
        *(s32*)(self + 0x268) = 3;
    } else if (flags == 5) {
        *(s32*)(self + 0x268) = 4;
    } else if (flags == 6) {
        *(s32*)(self + 0x268) = 5;
    } else if (flags == 9) {
        *(s32*)(self + 0x268) = 6;
    } else if (flags == 10) {
        *(s32*)(self + 0x268) = 7;
    } else {
        *(s32*)(self + 0x268) = -1;
    }
    return *(s32*)(self + 0x268);
}

extern const f32 lbl_80542610;
extern const f32 lbl_80542624;
extern "C" s32 fn_80351020(u8* this_, s32 player);
extern "C" u8 fn_80230188(s32 i);
extern "C" s32 fn_8022CCAC(s32 i);
extern "C" u8 fn_8022F478(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" s32 fn_8022CAF8(s32 i);
extern "C" u8 fn_80235580(s32 i);
extern "C" s32 fn_80350974(u8* self) {
    s32 cnt = 0;
    s32 flag = 0;
    s32 i;
    s32 k;
    s32 st;
    s32 r;
    Vec tmp;

    self[0x283] = 0;
    self[0x284] = 0;
    self[0x285] = 0;
    self[0x286] = 0;
    if (*(s32*)(self + 0x230) == 7) {
        return 0;
    }
    tmp.z = lbl_805425D8;
    tmp.y = lbl_805425D8;
    tmp.x = lbl_805425D8;

    for (i = 0; i < 4; i++) {
        if (*(s32*)(self + 0x258) == 4) {
            f32 sv3 = *(f32*)(self + 0x8c);
            f32 sv2 = *(f32*)(self + 0x88);
            f32 sv1 = *(f32*)(self + 0x84);
            f32 sv0 = *(f32*)(self + 0x80);
            f32* p = (f32*)lbl_8050ADF8;
            for (k = 0; k < 4; k++, p += 4) {
                *(f32*)(self + 0x80) = p[0];
                *(f32*)(self + 0x84) = p[1];
                *(f32*)(self + 0x88) = p[2];
                *(f32*)(self + 0x8c) = p[3];
                r = fn_80351020(self, i);
                self[i + 0x283] = r;
                if ((u8)r == 1 && *(f32*)((u8*)fn_8023E724(i) + 8) > lbl_805425D8) {
                    cnt++;
                }
            }
            *(f32*)(self + 0x80) = sv0;
            *(f32*)(self + 0x84) = sv1;
            *(f32*)(self + 0x88) = sv2;
            *(f32*)(self + 0x8c) = sv3;
        } else if (*(s32*)(self + 0x258) >= 0x10 && *(s32*)(self + 0x258) <= 0x14) {
            f32 sv3 = *(f32*)(self + 0x8c);
            f32 sv2 = *(f32*)(self + 0x88);
            f32 sv1 = *(f32*)(self + 0x84);
            f32 sv0 = *(f32*)(self + 0x80);
            f32* p = (f32*)((u8*)lbl_8050AE38 + (*(s32*)(self + 0x258) - 0x10) * 0x20);
            for (k = 0; k < 2; k++, p += 4) {
                *(f32*)(self + 0x80) = p[0];
                *(f32*)(self + 0x84) = p[1];
                *(f32*)(self + 0x88) = p[2];
                *(f32*)(self + 0x8c) = p[3];
                r = fn_80351020(self, i);
                self[i + 0x283] = r;
                if ((u8)r == 1 && *(f32*)((u8*)fn_8023E724(i) + 8) > lbl_805425D8) {
                    cnt++;
                }
            }
            *(f32*)(self + 0x80) = sv0;
            *(f32*)(self + 0x84) = sv1;
            *(f32*)(self + 0x88) = sv2;
            *(f32*)(self + 0x8c) = sv3;
        } else if (*(s32*)(self + 0x258) >= 6 && *(s32*)(self + 0x258) <= 9) {
            r = fn_80351020(self, i);
            self[i + 0x283] = r;
            if (i == *(s32*)(self + 0x258) - 6) {
                self[0x280] = r;
            }
        } else {
            r = fn_80351020(self, i);
            self[i + 0x283] = r;
            if ((u8)r == 1 && *(f32*)((u8*)fn_8023E724(i) + 8) > lbl_805425D8) {
                cnt++;
            }
        }
    }

    st = *(s32*)(self + 0x230);
    if (*(s32*)(self + 0x258) >= 6 && *(s32*)(self + 0x258) <= 9) {
        tmp = *(Vec*)(self + 0x3c);
    } else if (st == 1 || st == 3) {
        tmp = *(Vec*)(self + 0x3c);
    } else if (*(s32*)(self + 0x258) == 5) {
        if (st == 5) {
            tmp.y = lbl_80542610;
        } else if (st == 6) {
            tmp.y = lbl_80542624;
        }
    } else if (*(s32*)(self + 0x258) == 0xc && PSVECMag((Vec*)(self + 0x3c)) > lbl_805425D8) {
        tmp = *(Vec*)(self + 0x3c);
    } else {
        if (st == 5) {
            tmp.y = lbl_80542610;
        } else if (st == 6) {
            tmp.y = lbl_80542624;
        }
    }

    for (k = 0; k < 4; k++) {
        if (self[k + 0x283] == 1) {
            if ((u8)fn_80230188(k) != 1) {
                if ((u8)fn_8022CCAC(k) == 1) {
                    flag = 1;
                }
            }
        }
    }

    if (*(s32*)(self + 0x258) == 5 && cnt == 0) {
        f32 dx = *(f32*)(self + 0xc) - *(f32*)(self + 0x24);
        f32 dy = *(f32*)(self + 0x10) - *(f32*)(self + 0x28);
        if (dx * dx + dy * dy > lbl_8054261C) {
            *(s32*)(self + 0x250) += 1;
            if (*(s32*)(self + 0x250) > 0xf0) {
                s32 room = *(s32*)(self + 4);
                if (room < 8) {
                    fn_8013CC50(room, self + 0xc, lbl_805425E8, 0x503, 1, 0, 0, 0, 1);
                } else {
                    Actor_CreateByID(fn_801F856C(), 0x4b4d5249, room, self + 0xc, 0x83, -1, -1);
                    *(f32*)(self + 0x28c) = lbl_805425F0;
                }
            }
        } else {
            *(s32*)(self + 0x250) = 0;
        }
    } else {
        *(s32*)(self + 0x250) = 0;
    }
    self[0x288] = flag;

    for (k = 0; k < 4; k++) {
        if (self[k + 0x283] == 1 && *(f32*)((u8*)fn_8023E724(k) + 8) > lbl_805425D8 && self[0x288] == 0 &&
            PSVECSquareMag(&tmp) > *(f32*)__float_epsilon * lbl_80542614) {
            if ((u8)fn_8022F478(k) != 0) {
                if (self[fn_8022F3DC(k) + 0x283] == 1) {
                    if (fn_8022CAF8(k) != 5 && fn_8022CAF8(k) != 4) {
                        fn_80235580(k);
                    }
                }
            }
        }
    }
    return cnt;
}

extern const f32 lbl_80542628;
extern const f32 lbl_8054262C;
extern "C" s32 fn_8023DE58(s32 player);
extern "C" void fn_8022E088(s32 player, s32 idx, JGeometry::TVec3<f32>* out);
extern "C" void fn_8022DF48(s32 player);
extern const f32 lbl_80542600;
extern const f32 lbl_80542604;
static inline f32 tu8034_sqrtf(f32 x) { // same shape as JGeometry::TUtilf::sqrt, on this file's literals
    if (x <= lbl_805425D8) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = lbl_80542600 * y * (lbl_80542604 - (x * (y * y)));
    return x * y;
}
extern "C" s32 fn_80351020(u8* this_, s32 player) {
    s32 room = *(s32*)(this_ + 4);
    if (room != fn_8023DE58(player)) {
        return 0;
    }
    f32 scale = lbl_80542628;
    f32 margin = lbl_8054262C;
    f32 zero = 0.0f;
    for (s32 i = 0; i < 8; i++) {
        JGeometry::TVec3f pt;
        fn_8022E088(player, i, &pt);
        pt -= *(JGeometry::TVec3f*)(this_ + 0xc);
        pt.z = zero;
        f32 ang = JMath::atanTable_.atan2_(pt.y, pt.x);
        s32 idx = (s32)(ang * scale);
        f32 len = JGeometry::TUtilf::sqrt(pt.x * pt.x + pt.y * pt.y);
        u8* sc = (u8*)&JMath::sincosTable_ + ((idx >> 2) & 0x3ff8);
        pt.x = *(f32*)(sc + 4) * len;
        pt.y = *(f32*)sc * len;
        pt.z = zero;
        f32 x0 = *(f32*)(this_ + 0x80) - margin;
        f32 y0 = *(f32*)(this_ + 0x84) - margin;
        f32 x1 = *(f32*)(this_ + 0x88) + margin;
        f32 y1 = *(f32*)(this_ + 0x8c) + margin;
        u8 in = 0;
        if (pt.x >= x0 && pt.y >= y0 && pt.x < x1 && pt.y < y1) {
            in = 1;
        }
        if (in) {
            fn_8022DF48(player);
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_803511F0(u8* self) {
    fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x97, 0, lbl_805425F0, -3, 0, 0, 1);
    fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x98, 0, lbl_805425F0, -3, 0, 0, 1);
    *(s32*)(self + 0x258) = 0xb;
    self[0x282] = 0;
    *(s32*)(self + 0x24c) = 0;
    *(s32*)(self + 0x230) = 7;
    *(s32*)(self + 0x240) = 0xb;
    *(s32*)(self + 0x248) = 0xa;
    *(s32*)(self + 0x274) = -1;
    *(s32*)(self + 0x268) = *(s32*)(self + 0x264);
    f32 dx = *(f32*)(self + 0xc) - *(f32*)(self + 0x24);
    f32 dy = *(f32*)(self + 0x10) - *(f32*)(self + 0x28);
    f32 dx2 = dx * dx;
    f32 dy2 = dy * dy;
    if (tu8034_sqrtf(dx2 + dy2) > lbl_80542608) {
        *(JGeometry::TVec3f*)(self + 0xc) = *(JGeometry::TVec3f*)(self + 0x24);
        s32 kind = *(s32*)(self + 4);
        if (kind >= 8) {
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249, kind, self + 0xc, 0x83, -1, -1);
            *(f32*)(self + 0x28c) = lbl_805425F0;
        } else {
            fn_8013CC50(kind, self + 0xc, 0x503, 1, lbl_805425E8, 0, 0, 0, 1);
            fn_801F0E34(self, 0x30003, 0);
        }
    } else {
        *(JGeometry::TVec3f*)(self + 0xc) = *(JGeometry::TVec3f*)(self + 0x24);
    }
    if (*(s32*)(self + 4) < 8) {
        *(f32*)(self + 0x28c) = lbl_805425D8;
    }
}

extern "C" u32 fn_8013CC50(u32 owner, void* pos, u16 id, s32 a, f32 f, s32 b, s32 c, s32 d, s32 e);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 id, s32 kind, void* pos, s32 a, s32 b, s32 c);
extern "C" void fn_801F0E34(void* self, u32 id, s32 b);
extern "C" void fn_803513C0(u8* self) {
    s32 kind = *(s32*)(self + 4);
    if (kind >= 8) {
        if (kind >= 8) {
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249, kind, self + 0xc, 0x83, -1, -1);
            *(f32*)(self + 0x28c) = 1.0f;
        } else {
            fn_8013CC50(kind, self + 0xc, 0x503, 1, 2.0f, 0, 0, 0, 1);
            fn_801F0E34(self, 0x30003, 0);
        }
    } else {
        fn_8013CC50(kind, self + 0xc, 0x459, 0, 1.0f, -3, 0, 0, 1);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x45a, 0, 1.0f, -3, 0, 0, 1);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, 0x45b, 0, 1.0f, -3, 0, 0, 1);
        fn_801F0E34(self, 0x30065, 0);
    }
    *(s32*)(self + 0x254) = 0x1e;
    *(s32*)(self + 0x258) = 0xc;
    *(s32*)(self + 0x230) = 0;
    *(s32*)(self + 0x240) = 0xa;
}

extern const f32 lbl_80542630;
extern const f32 lbl_80542634;
extern const f32 lbl_80542638;
extern const f32 lbl_8054263C;
extern const f32 lbl_80542640;
extern const f32 lbl_80542644;
extern const f32 lbl_80542648;
extern const f32 lbl_8054264C;
extern const f32 lbl_80542650;
extern const f32 lbl_80542654;
extern const f32 lbl_80542658;
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern void* lbl_8053AAF8;
extern "C" void fn_8035151C(u8* self) {
    s32 st;
    s32 i;
    s32 j;
    s32 room;
    u8 flags[4];
    s32 list[4];
    s32 count;
    f32 fv;
    u32 bits;

    *(s32*)(self + 0x258) = (*(u32*)(self + 0x90) & 0xf) + ((*(u32*)(self + 0x90) >> 12) & 0xf0);
    *(s32*)(self + 0x260) = (*(u32*)(self + 0x90) >> 4) & 0xf;
    *(s32*)(self + 0x264) = (*(u32*)(self + 0x90) >> 8) & 0xf;
    *(s32*)(self + 0x25c) = (*(u32*)(self + 0x90) >> 12) & 0xf;
    *(s32*)(self + 0x268) = *(s32*)(self + 0x264);
    *(s32*)(self + 0x26c) = 0;
    *(s32*)(self + 0x244) = 0;
    *(s32*)(self + 0x248) = 10;
    *(s32*)(self + 0x254) = 0;
    *(s32*)(self + 0x240) = *(s32*)(self + 0x258);
    *(u8*)(self + 0x287) = (*(u32*)(self + 0x90) >> 24) & 1;
    *(s32*)(self + 0x230) = 0;
    *(s32*)(self + 0x270) = 0;
    *(u8*)(self + 0x280) = 0;
    *(u8*)(self + 0x281) = 1;
    *(s32*)(self + 0x274) = -1;
    *(s32*)(self + 0x27c) = 0;
    *(s32*)(self + 0x250) = 0;
    *(s32*)(self + 0x24c) = 0;
    *(u8*)(self + 0x282) = 0;
    *(u8*)(self + 0x288) = 0;
    *(f32*)(self + 0x290) = lbl_805425D8;
    *(f32*)(self + 0x29c) = lbl_805425D8;
    *(f32*)(self + 0x298) = lbl_805425D8;
    *(f32*)(self + 0x294) = lbl_805425D8;
    *(u8*)(self + 0x283) = 0;
    *(u8*)(self + 0x284) = 0;
    *(u8*)(self + 0x285) = 0;
    *(u8*)(self + 0x286) = 0;
    *(JGeometry::TVec3<f32>*)(self + 0x234) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(f32*)(self + 0x23c) = *(f32*)(self + 0x14);

    switch (*(s32*)(self + 0x258)) {
    case 0:
    case 4:
        *(f32*)(self + 0x80) = lbl_80542630;
        *(f32*)(self + 0x84) = lbl_80542630;
        *(f32*)(self + 0x88) = lbl_80542634;
        *(f32*)(self + 0x8c) = lbl_80542634;
        break;
    case 1:
        *(f32*)(self + 0x80) = lbl_80542638;
        *(f32*)(self + 0x84) = lbl_80542638;
        *(f32*)(self + 0x88) = lbl_8054263C;
        *(f32*)(self + 0x8c) = lbl_8054263C;
        break;
    case 2:
        *(f32*)(self + 0x80) = lbl_80542638;
        *(f32*)(self + 0x84) = lbl_80542630;
        *(f32*)(self + 0x88) = lbl_8054263C;
        *(f32*)(self + 0x8c) = lbl_80542634;
        break;
    case 3:
        *(f32*)(self + 0x80) = lbl_80542630;
        *(f32*)(self + 0x84) = lbl_80542638;
        *(f32*)(self + 0x88) = lbl_80542634;
        *(f32*)(self + 0x8c) = lbl_8054263C;
        break;
    case 5:
        *(f32*)(self + 0x80) = lbl_80542640;
        *(f32*)(self + 0x84) = lbl_80542640;
        *(f32*)(self + 0x88) = lbl_80542644;
        *(f32*)(self + 0x8c) = lbl_80542644;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        *(f32*)(self + 0x80) = lbl_80542648;
        *(f32*)(self + 0x84) = lbl_80542648;
        *(f32*)(self + 0x88) = lbl_8054264C;
        *(f32*)(self + 0x8c) = lbl_8054264C;
        break;
    case 10:
        *(f32*)(self + 0x80) = lbl_80542648;
        *(f32*)(self + 0x84) = lbl_80542648;
        *(f32*)(self + 0x88) = lbl_8054264C;
        *(f32*)(self + 0x8c) = lbl_8054264C;
        flags[0] = 1;
        flags[1] = 1;
        flags[2] = 1;
        flags[3] = 1;
        count = 0;
        i = -1;
        while (count < 4) {
            i = fn_801F78F4(fn_801F856C(), 0x4f424c46, i);
            if (i < 0) {
                break;
            }
            if (i != *(s32*)(self + 0x198)) {
                u8* e = fn_801F666C(fn_801F856C(), i);
                if (e != 0 && *(s32*)(self + 4) == *(s32*)(e + 4)) {
                    st = *(s32*)(e + 0x258);
                    if (st >= 6 && st <= 9 && flags[st - 6] == 1) {
                        flags[st - 6] = 0;
                        count++;
                    }
                }
            }
        }
        {
            u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
            *seed = *seed * 0x19660d + 0x3c6ef35f;
            bits = (*seed >> 9) | 0x3f800000;
            fv = *(f32*)&bits;
        }
        if (count == 0) {
            st = (s32)(lbl_80542650 * (fv - lbl_805425F0)) + 6;
            *(s32*)(self + 0x258) = st;
        } else {
            count = 0;
            for (j = 0; j < 4; j++) {
                if (flags[j] == 1) {
                    list[count] = j;
                    count++;
                }
            }
            st = list[(s32)(count * (fv - lbl_805425F0))] + 6;
            *(s32*)(self + 0x258) = st;
        }
        break;
    case 11:
        *(f32*)(self + 0x80) = lbl_80542654;
        *(f32*)(self + 0x84) = lbl_80542654;
        *(f32*)(self + 0x88) = lbl_80542658;
        *(f32*)(self + 0x8c) = lbl_80542658;
        *(f32*)(self + 0x60) = lbl_80542654;
        *(f32*)(self + 0x64) = lbl_80542654;
        *(f32*)(self + 0x68) = lbl_80542658;
        *(f32*)(self + 0x6c) = lbl_80542658;
        *(s32*)(self + 0x230) = 7;
        break;
    case 12:
        *(f32*)(self + 0x80) = lbl_80542654;
        *(f32*)(self + 0x84) = lbl_80542654;
        *(f32*)(self + 0x88) = lbl_80542658;
        *(f32*)(self + 0x8c) = lbl_80542658;
        *(f32*)(self + 0x60) = lbl_80542654;
        *(f32*)(self + 0x64) = lbl_80542654;
        *(f32*)(self + 0x68) = lbl_80542658;
        *(f32*)(self + 0x6c) = lbl_80542658;
        *(s32*)(self + 0x240) = 10;
        room = *(s32*)(self + 4);
        if (room < 8) {
            fn_8013CC50(room, 0, lbl_805425E8, 0x503, 1, 0, 0, 0, 1);
            fn_801F0E34(self, 0x30003, 0);
        } else {
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249, room, (f32*)(self + 0xc), 0x83, -1, -1);
            *(f32*)(self + 0x28c) = lbl_805425F0;
        }
        break;
    case 13:
    case 14:
    case 15:
        fn_8013CC50(*(s32*)(self + 4), 0, lbl_805425F0, 0x459, 0, -3, 0, 0, 1);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_805425F0, 0x45a, 0, -3, 0, 0, 1);
        fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_805425F0, 0x45b, 0, -3, 0, 0, 1);
        fn_801F0E34(self, 0x30065, 0);
        *(s32*)(self + 0x254) = 0x1e;
        *(s32*)(self + 0x258) = 0xc;
        *(s32*)(self + 0x230) = 0;
        *(s32*)(self + 0x240) = 10;
        break;
    case 16:
    case 17:
        *(f32*)(self + 0x80) = lbl_80542638;
        *(f32*)(self + 0x84) = lbl_80542654;
        *(f32*)(self + 0x88) = lbl_8054263C;
        *(f32*)(self + 0x8c) = lbl_80542658;
        *(s32*)(self + 0x240) = *(s32*)(self + 0x258) - 3;
        break;
    case 18:
    case 19:
        *(f32*)(self + 0x80) = lbl_80542654;
        *(f32*)(self + 0x84) = lbl_80542638;
        *(f32*)(self + 0x88) = lbl_80542658;
        *(f32*)(self + 0x8c) = lbl_8054263C;
        *(s32*)(self + 0x240) = *(s32*)(self + 0x258) - 3;
        break;
    case 20:
        *(f32*)(self + 0x80) = lbl_80542638;
        *(f32*)(self + 0x84) = lbl_80542654;
        *(f32*)(self + 0x88) = lbl_8054263C;
        *(f32*)(self + 0x8c) = lbl_80542658;
        *(s32*)(self + 0x240) = 0xe;
        *(f32*)(self + 0x28c) = lbl_805425F0;
        if (*(s32*)(self + 0x25c) == 2) {
            *(s32*)(self + 0x230) = 4;
            *(f32*)(self + 0x28c) = lbl_805425D8;
        }
        break;
    }
}

extern "C" const f32 lbl_80542630;
extern "C" const f32 lbl_80542634;
extern "C" const f32 lbl_8054265C;
extern "C" const f32 lbl_80542660;
extern "C" const f32 lbl_80542664;
extern "C" const f32 lbl_80542668;
extern "C" const f32 lbl_8054266C;
extern "C" const f32 lbl_80542670;
extern "C" const f32 lbl_80542674;
extern "C" const f32 lbl_80542678;
extern "C" const f32 lbl_8054267C;
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" const f32 lbl_8054261C;
extern "C" const f32 lbl_805425D8;
#include "JSystem/JAudio/JASFakeMatchFSA.h"
