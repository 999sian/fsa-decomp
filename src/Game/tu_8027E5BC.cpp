#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
extern "C" const JGeometry::TVec3<f32> lbl_8046BF38[];

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define S32(p, o) (*(s32*)((char*)(p) + (o)))
#define F32(p, o) (*(f32*)((char*)(p) + (o)))
#define PTR(p, o) (*(void**)((char*)(p) + (o)))
#define VEC(p, o) (*(JGeometry::TVec3<f32>*)((char*)(p) + (o)))

#pragma auto_inline off

extern "C" {
extern const f32 lbl_80540360, lbl_80540364, lbl_80540368, lbl_8054036C;
extern const f32 lbl_80540390;
extern const f32 lbl_8054037C, lbl_80540384, lbl_80540398;
extern const f32 lbl_805403A4, lbl_805403AC, lbl_805403B4, lbl_80540404;
extern const f32 lbl_80540380;
extern const f32 lbl_805403B0, lbl_805403FC, lbl_80540400;
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
bool Player_IsLinked(char*);
s32 Player_GetLinkTargetIndex(char*);
u8 fn_80234ECC(s32);
bool fn_80250D30(char*);
u8 fn_80241230();
bool fn_802412A4(char*);
bool fn_8022D75C(s32);
s32 fn_80248970(char*);
bool Player_GetField_0x454(char*);
u8 fn_802341D0(s32);
s32 fn_802487FC(char*);
u8 fn_80241284(char*);
u8 fn_8022E438(s32, s32);
void fn_8022B860(s32, s32);
void fn_8024EFF8(char*, s32);
void fn_8013CB44(void*, void*, s32, s32, s32, s32);
s32 fn_80230CFC(s32);
s32 fn_80230B70(s32);
extern u32 lbl_8046C0B8[];
extern u32 lbl_8046C0C8[];
bool fn_80245FEC(char*);
bool fn_80245DB0(char*);
bool fn_80251AEC(char*, s32);
void fn_802416FC(char*, s32);
void fn_8024BAEC(char*);
void fn_8024E3D8(char*);
void fn_8024F0E8(char*, s32);
void fn_802685D4(char*);
void fn_80268B3C(char*);
void fn_80248604(char*);
void fn_8024D134(char*);
void fn_8027EB04(char*);
void* fn_801F856C();
void* fn_801F666C(void*, s32);
f32 fn_801080B8(void*);
void fn_80107360(void*);
void* fn_802D6A9C();
void* fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);
void fn_802BAA00(void*);
void fn_802D79E8(void*, s32, s32, f32, f32);
void fn_802F601C(void*, void*, s32, s32, f32, f32);
s32 fn_802486A0(char*);
s32 fn_8022F3DC(s32);
void fn_802384BC(s32);
u32 fn_8022461C(char*, s32);
bool fn_8022B244();
void* fn_8013C824();
void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
void fn_802BAA0C(void*, void*);
f32 fn_8022C82C(s32);
f32 fn_8022C76C(s32);
void fn_8024B298(char*, s32, void*);
s32 fn_802416C4(char*);
void* fn_80246B10(char*, s32);
u8 fn_80235580(s32);
s32 fn_80240888(char*);
s32 fn_80248778(char*);
JGeometry::TVec3<f32>* fn_8023E724(s32);
extern const f32 lbl_80540350, lbl_80540354, lbl_80540358;

extern const f32 lbl_80540348, lbl_8054034C;
extern const f32 lbl_80540368;
extern const f32 lbl_8054035C, lbl_805403A0;
extern const f32 lbl_80540388, lbl_8054038C, lbl_80540390, lbl_80540394, lbl_8054039C;
extern const JGeometry::TVec3<f32> lbl_8046BED8[];
bool fn_80245238(char*);
bool fn_80244FFC(char*);
f32 fn_80246F28(char*);
u8 Player_GetField_0xce8(char* p);
void fn_8027FA08(char*, f32*);
bool fn_80275D9C(char*);
f32 fn_8022C6AC(s32);
s32 fn_8023DE58(s32);
void fn_8027EEB4(char*);
void fn_80261480(char*);
void fn_8027E5BC(char* p, f32 f) {
    s32 area;
    if (!Player_GetField_0xce8(p)) {
        JGeometry::TVec3<f32> d;
        JGeometry::TVec3<f32> a(VEC(p, 0x3a4));
        a.sub(VEC(p, 0x398));
        d = a;
        f = f * PSVECMag(&d) * lbl_80540348;
    }
    if (F32(p, 0x3a4) > F32(p, 0x398)) {
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
        F32(p, 0x8) += f;
        if (F32(p, 0x8) > F32(p, 0x3a4)) {
            F32(p, 0x8) = F32(p, 0x3a4);
        }
    } else if (F32(p, 0x3a4) < F32(p, 0x398)) {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
        F32(p, 0x8) -= f;
        if (F32(p, 0x8) < F32(p, 0x3a4)) {
            F32(p, 0x8) = F32(p, 0x3a4);
        }
    }
    if (F32(p, 0x3a8) > F32(p, 0x39c)) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
        if (Player_GetField_0xce8(p) && (S32(p, 0xcf4) == 0x15 || S32(p, 0xcf4) == 0x23) && (area = S32(p, 0x3b4), *((u8*)fn_802D6A9C() + 0x10000 + area + 0x31df) != 0)) {
            F32(p, 0xc) += f * lbl_8054034C;
        } else {
            F32(p, 0xc) += f;
        }
        if (F32(p, 0xc) > F32(p, 0x3a8)) {
            F32(p, 0xc) = F32(p, 0x3a8);
        }
    } else if (F32(p, 0x3a8) < F32(p, 0x39c)) {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
        if (Player_GetField_0xce8(p) && (S32(p, 0xcf4) == 0x15 || S32(p, 0xcf4) == 0x23) && (area = S32(p, 0x3b4), *((u8*)fn_802D6A9C() + 0x10000 + area + 0x31df) != 0)) {
            F32(p, 0xc) -= f * lbl_8054034C;
        } else {
            F32(p, 0xc) -= f;
        }
        if (F32(p, 0xc) < F32(p, 0x3a8)) {
            F32(p, 0xc) = F32(p, 0x3a8);
        }
    }
}

void fn_8027E7E0(char* p) {
    s32 i;
    f32 minDist;
    if (S32(p, 0x11fc) >= 0) {
        if (!fn_80235580(S32(p, 0x11fc))) {
            s32 area = S32(p, 0x3b4);
            if (fn_8023DE58(S32(p, 0x11fc)) == area) {
                JGeometry::TVec3<f32> a(*fn_8023E724(S32(p, 0x11fc)));
                a.sub(VEC(p, 0x8));
                JGeometry::TVec3<f32> d;
                d = a;
                if (!(PSVECMag(&d) > lbl_80540350)) {
                    goto join;
                }
            }
        }
        S32(p, 0x11fc) = -1;
    }
join:
    if (S32(p, 0x11fc) >= 0) {
        JGeometry::TVec3<f32> a(*fn_8023E724(S32(p, 0x11fc)));
        a.sub(VEC(p, 0x8));
        JGeometry::TVec3<f32> d;
        d = a;
        minDist = PSVECMag(&d);
    } else {
        minDist = lbl_80540350;
    }
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            continue;
        }
        if (fn_802486A0(p) == 4 && fn_80248778(p) != fn_80240888(p)) {
            continue;
        }
        JGeometry::TVec3<f32> a(*fn_8023E724(i));
        a.sub(VEC(p, 0x8));
        JGeometry::TVec3<f32> d;
        d = a;
        if (PSVECMag(&d) < minDist - lbl_80540354) {
            S32(p, 0x11fc) = i;
            JGeometry::TVec3<f32> b(*fn_8023E724(i));
            b.sub(VEC(p, 0x8));
            JGeometry::TVec3<f32> e;
            e = b;
            minDist = PSVECMag(&e);
        }
    }
    if (S32(p, 0x11fc) < 0) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
        return;
    }
    JGeometry::TVec3<f32> a(*fn_8023E724(S32(p, 0x11fc)));
    a.sub(VEC(p, 0x8));
    JGeometry::TVec3<f32> d;
    d = a;
    s16 ang = (s16)(JMath::atanTable_.atan2_(d.y, d.x) * lbl_80540358);
    if (ang < -0x6000) {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    } else if (ang < -0x2000) {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    } else if (ang < 0x2000) {
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
    } else if (ang < 0x6000) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    } else {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    }
}

void fn_8027EB04(char* p) {
    if (!fn_80241230() && !fn_802412A4(p) && !U8(p, 0x1214)) {
        if (fn_802486A0(p) != 4 && Player_IsLinked(p)) {
            if (fn_8022D75C(Player_GetLinkTargetIndex(p))) {
                return;
            }
        }
        if (fn_802486A0(p) == 3 && fn_80248970(p) >= 2) {
            u32 base = S32(p, 0x3b4);
            u32 ofs = (u32)fn_802D6A9C() + 0x10000 + base;
            if (*(u8*)(ofs + 0x31df) != 0) {
                s32 v = lbl_8046C0B8[S32(p, 4)];
                S32(p, 0x3dc) = v;
                S32(p, 0x3e8) = v;
            } else {
                s32 v = lbl_8046C0C8[S32(p, 4)];
                S32(p, 0x3dc) = v;
                S32(p, 0x3e8) = v;
            }
            return;
        }
        if (Player_IsLinked(p) && fn_802486A0(p) != 5 && fn_802486A0(p) != 4) {
            S32(p, 0x3dc) = fn_80230CFC(Player_GetLinkTargetIndex(p));
            S32(p, 0x3e8) = fn_80230B70(Player_GetLinkTargetIndex(p));
            return;
        }
    }
    if (fn_80246B10(p, 2) != 0) {
        if (fn_80246B10(p, 8) != 0) {
            if (S32(p, 0x3dc) != 0 && S32(p, 0x3dc) != 3) {
                S32(p, 0x3dc) = 0;
            }
            S32(p, 0x3e8) = 6;
        } else if (fn_80246B10(p, 4) != 0) {
            if (S32(p, 0x3dc) != 0 && S32(p, 0x3dc) != 2) {
                S32(p, 0x3dc) = 0;
            }
            S32(p, 0x3e8) = 4;
        } else {
            S32(p, 0x3dc) = 0;
            S32(p, 0x3e8) = 0;
        }
    } else if (fn_80246B10(p, 1) != 0) {
        if (fn_80246B10(p, 8) != 0) {
            if (S32(p, 0x3dc) != 1 && S32(p, 0x3dc) != 3) {
                S32(p, 0x3dc) = 1;
            }
            S32(p, 0x3e8) = 7;
        } else if (fn_80246B10(p, 4) != 0) {
            if (S32(p, 0x3dc) != 1 && S32(p, 0x3dc) != 2) {
                S32(p, 0x3dc) = 1;
            }
            S32(p, 0x3e8) = 5;
        } else {
            S32(p, 0x3dc) = 1;
            S32(p, 0x3e8) = 1;
        }
    } else if (fn_80246B10(p, 8) != 0) {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    } else if (fn_80246B10(p, 4) != 0) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    }
}

void fn_8027EDDC(char* p) {
    if (U8(p, 0x3fc) < 8) U8(p, 0x3fd) = 0;
    else if (U8(p, 0x3fc) < 16) U8(p, 0x3fd) = 1;
    else if (U8(p, 0x3fc) < 24) U8(p, 0x3fd) = 2;
    else if (U8(p, 0x3fc) < 30) U8(p, 0x3fd) = 3;
    else if (U8(p, 0x3fc) < 36) U8(p, 0x3fd) = 4;
    else if (U8(p, 0x3fc) < 42) U8(p, 0x3fd) = 5;
    else if (U8(p, 0x3fc) < 48) U8(p, 0x3fd) = 4;
    else U8(p, 0x3fd) = 3;
    U8(p, 0x3fc)++;
}

void fn_8027EE84(char* p) {
    U8(p, 0x3f8)++;
    if (U8(p, 0x3f8) >= 16) U8(p, 0x3f8) = 0;
    U8(p, 0x3f9) = (u32)U8(p, 0x3f8) >> 1;
}

void fn_8027EEB4(char* p) {
    if (Player_IsLinked(p)) {
        if (!fn_80234ECC(Player_GetLinkTargetIndex(p)) && fn_80250D30(p)) {
            fn_80251AEC(p, 0xd);
            return;
        }
    } else if (S32(p, 0x1240) == 3 || U8(PTR(p, 0xbf0), 0xb7) == 0) {
        goto block_c;
    }
    if (!(JMathInlineVEC::PSVECSquareMag(&VEC(p, 0x368)) <= lbl_8054035C * FLT_EPSILON) && S32(PTR(p, 0xbf0), 0xa0) == 0) {
        fn_80251AEC(p, 0);
        U8(p, 0x3f8) = 0;
        return;
    }
block_c:
    if (U8(PTR(p, 0xbf0), 0xb7) != 0 && fn_8022C6AC(S32(p, 4)) == lbl_80540360 && S32(PTR(p, 0xbf0), 0xa0) == 0) {
        U8(p, 0x3f8) = 0;
        return;
    }
    if (U8(PTR(p, 0xbf0), 0xb7) == 0) {
        f32 eps = lbl_8054035C * FLT_EPSILON;
        bool inX = false;
        bool inY = false;
        bool inZ = false;
        f32 d = F32(p, 0x8) - F32(p, 0x14);
        if (-eps <= d && d <= eps) {
            inX = true;
        }
        if (inX) {
            inX = false;
            d = F32(p, 0xc) - F32(p, 0x18);
            if (-eps <= d && d <= eps) {
                inX = true;
            }
            if (inX) {
                inY = true;
            }
        }
        if (inY) {
            inY = false;
            d = F32(p, 0x10) - F32(p, 0x1c);
            if (-eps <= d && d <= eps) {
                inY = true;
            }
            if (inY) {
                inZ = true;
            }
        }
        if (inZ && S32(PTR(p, 0xbf0), 0xa0) == 0 && U8(p, 0x434) == 0) {
            fn_80251AEC(p, 0);
            U8(p, 0x3f8) = 0;
            return;
        }
    }
    if (U8(PTR(p, 0xbf0), 0xb7) != 0) {
        if (U8(p, 0x3f8) % 3 == 0) {
            U8(p, 0x3f8) += 2;
        } else {
            U8(p, 0x3f8) += 1;
        }
    } else {
        U8(p, 0x3f8)++;
    }
    if (U8(p, 0x3f8) >= 0x18) {
        U8(p, 0x3f8) = 0;
        U8(p, 0x3f9) = U8(p, 0x3f8) / 3;
    }
}

void fn_8027F16C(char* p) {
    if (!Player_IsLinked(p) && !fn_80245FEC(p) && U8(p, 0x1201) != 1)
        fn_802416FC(p, 0x180);
}

void fn_8027F1C8(char* p) {
    JGeometry::TVec3<f32> pos;
    s32 state;
    s32 i;

    if ((U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 0x4))) && !Player_GetField_0x454(p)) {
        if (!fn_802341D0(S32(p, 0x4)) || Player_GetField_0xce8(p)) {
            if (PTR(p, 0x1388)) {
                void* mgr = fn_8013C824();
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)mgr + 0xc), PTR(p, 0x1388));
                PTR(p, 0x1388) = 0;
            }
        } else {
            pos.x = F32(p, 0x8);
            pos.y = F32(p, 0xc);
            pos.z = F32(p, 0x10);
            pos.z = lbl_80540360;
            switch (fn_802486A0(p)) {
            case 0:
                pos.x += lbl_80540364 * (f32)(fn_802487FC(p) - 1);
                break;
            case 1:
                pos.y += lbl_80540364 * (f32)(fn_802487FC(p) - 1);
                break;
            case 2:
                pos.x += lbl_80540364;
                pos.y += lbl_80540364;
                break;
            case 3:
                if (fn_80241284(p)) {
                    pos.x = F32(p, 0x11b4);
                    pos.y = F32(p, 0x11b8);
                    pos.z = F32(p, 0x11bc);
                } else {
                    switch (S32(p, 0x4)) {
                    case 0:
                        pos.y += lbl_80540368;
                        break;
                    case 1:
                        pos.x += lbl_80540368;
                        break;
                    case 2:
                        pos.x -= lbl_80540368;
                        break;
                    case 3:
                        pos.y -= lbl_80540368;
                        break;
                    }
                }
                break;
            }
            if (U8(p, 0x121d) == 0) {
                if (U8(lbl_8053AAF8, 0x7e) == 0) {
                    if (PTR(p, 0x1388)) {
                        ((void (*)(void*, void*, s32, s32, s32))fn_8013CB44)(PTR(p, 0x1388), &pos, 0, -1, 1);
                    } else {
                        switch (fn_802486A0(p)) {
                        case 0:
                            PTR(p, 0x1388) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x35e, 0, -1, 0, 0, 1, lbl_8054036C);
                            break;
                        case 1:
                            PTR(p, 0x1388) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x360, 0, -1, 0, 0, 1, lbl_8054036C);
                            break;
                        case 2:
                            PTR(p, 0x1388) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x35f, 0, -1, 0, 0, 1, lbl_8054036C);
                            break;
                        case 3:
                            PTR(p, 0x1388) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x361, 0, -1, 0, 0, 1, lbl_8054036C);
                            break;
                        }
                    }
                } else if (PTR(p, 0x1388)) {
                    void* mgr = fn_8013C824();
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)mgr + 0xc), PTR(p, 0x1388));
                    PTR(p, 0x1388) = 0;
                }
            } else {
                if (PTR(p, 0x1388)) {
                    void* mgr = fn_8013C824();
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)mgr + 0xc), PTR(p, 0x1388));
                    PTR(p, 0x1388) = 0;
                }
                switch (fn_802486A0(p)) {
                case 0:
                    PTR(p, 0x1388) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x35e, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1ba, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1bb, 0, -1, 0, 0, 1, lbl_8054036C);
                    break;
                case 1:
                    PTR(p, 0x1388) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x360, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1b8, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1b9, 0, -1, 0, 0, 1, lbl_8054036C);
                    break;
                case 2:
                    PTR(p, 0x1388) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x35f, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1b5, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1b6, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1b7, 0, -1, 0, 0, 1, lbl_8054036C);
                    break;
                case 3:
                    PTR(p, 0x1388) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x361, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1b2, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1b3, 0, -1, 0, 0, 1, lbl_8054036C);
                    fn_8013CC50(S32(p, 0x3b4), &pos, 0x1b4, 0, -1, 0, 0, 1, lbl_8054036C);
                    break;
                }
                for (i = 0; i < 4; i++) {
                    if (fn_8022E438(S32(p, 0x4), i)) {
                        fn_8022B860(i, 5);
                    }
                }
                U8(p, 0x121d) = 0;
                if (fn_802486A0(p) != 5 && fn_802486A0(p) != 4) {
                    fn_8024EFF8(p, 0x37);
                }
            }
        }
    }
}

extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 i);
extern "C" s32 fn_8022E8D4(s32 i);
extern "C" s32 fn_80248778(char* p);
extern const f32 lbl_8046BF98[][4][2];
extern const f32 lbl_8046C018[][4][2];
void fn_8027F854(char* p, JGeometry::TVec3<f32>* out, s32 i) {
    JGeometry::TVec3<f32>* v = fn_8023E724(i);
    out->x = v->x;
    out->y = v->y;
    out->z = v->z;
    switch (fn_802486A0(p)) {
    case 3:
        out->x += lbl_8046BF98[i][S32(p, 0x4)][0];
        out->y += lbl_8046BF98[i][S32(p, 0x4)][1];
        break;
    case 2:
        out->x += lbl_8046C018[i][S32(p, 0x4)][0];
        out->y += lbl_8046C018[i][S32(p, 0x4)][1];
        break;
    case 0:
        out->x += lbl_80540368 * (f32)(fn_80248778(p) - fn_8022E8D4(i));
        break;
    case 1:
        out->y += lbl_80540368 * (f32)(fn_80248778(p) - fn_8022E8D4(i));
        break;
    case 5:
        break;
    }
}

void fn_802804E0(char* p) {
    f32 speed;
    JGeometry::TVec3<f32> a;
    JGeometry::TVec3<f32> step;
    bool linked = Player_IsLinked(p);
    if (fn_802486A0(p) == 4 && fn_80248778(p) == fn_80240888(p)) {
        linked = false;
    }
    if (linked) {
        fn_8027FA08(p, (f32*)&a);
        step = a - VEC(p, 0x8);
        step.z = lbl_80540360;
        speed = step.length();
        if (speed >= lbl_80540388) {
            step.normalize();
            step.scale(lbl_80540388);
            VEC(p, 0x8) += step;
        } else {
            F32(p, 0x8) = a.x;
            F32(p, 0xc) = a.y;
            F32(p, 0x10) = a.z;
        }
        if (U8(p, 0x3ff) == 0) {
            if (fn_80245238(p)) {
                U8(p, 0x3ff) = 1;
                fn_8024F0E8(p, 0x20039);
            }
        } else {
            U8(p, 0x3ff)++;
            if (U8(p, 0x3ff) >= 0x21) {
                U8(p, 0x3ff) = 0;
            }
        }
        return;
    }
    if (fn_80246B10(p, 0x40)) {
        return;
    }
    speed = PSVECMag((Vec*)(p + 0x344));
    if (S32(p, 0x430) > 0) {
        speed -= lbl_8054038C;
        if (speed < lbl_80540360) {
            speed = lbl_80540360;
        }
    } else if (U8(p, 0x3ff) == 0) {
        if (fn_80245238(p)) {
            U8(p, 0x3ff) = 1;
            fn_8024F0E8(p, 0x20039);
        } else if (fn_80244FFC(p)) {
            speed -= lbl_8054038C;
            if (speed < lbl_80540390) {
                speed = lbl_80540390;
            }
        } else if (fn_80246F28(p) > lbl_80540360) {
            speed -= lbl_8054038C;
            if (speed < lbl_8054036C) {
                speed = lbl_8054036C;
            }
        } else {
            speed -= lbl_8054038C;
            if (speed < lbl_80540360) {
                speed = lbl_80540360;
            }
        }
    } else {
        u8 st = U8(p, 0x3ff);
        if (st >= 10) {
            if (st == 10) {
                F32(p, 0x410) = lbl_80540394;
                speed = lbl_8054036C;
            } else if (st < 16) {
                speed += lbl_8054039C;
            } else {
                speed -= lbl_8054038C;
                if (speed < lbl_80540390) {
                    speed = lbl_80540390;
                }
            }
        }
        if (U8(p, 0x3ff) >= 0x21) {
            U8(p, 0x3ff) = 0;
        } else {
            U8(p, 0x3ff)++;
        }
    }
    const JGeometry::TVec3<f32>& direction = lbl_8046BED8[S32(p, 0x3e8)];
    {
        f32 x = direction.x;
        f32 y = direction.y;
        F32(p, 0x344) = x;
        f32 z = direction.z;
        F32(p, 0x348) = y;
        F32(p, 0x34c) = z;
    }
    VEC(p, 0x344).scale(speed);
    VEC(p, 0x8) += VEC(p, 0x344);
}

void fn_802808E8(char* p, f32 f) {
    JGeometry::TVec3<f32> tmp;
    f32 a = f;
    f32 b = f;
    if (U8(p, 0x1216) != 0) {
        return;
    }
    if (JMathInlineVEC::PSVECSquareMag(&VEC(p, 0x35c)) <= lbl_8054035C * FLT_EPSILON) {
    } else {
        a = lbl_80540360;
        b = a;
    }
    if (U8(p, 0x3c1)) {
        a = lbl_80540360;
    }
    if (U8(p, 0x3c2)) {
        b = lbl_80540360;
    }
    u32 kind = fn_8022461C(p + 8, S32(p, 0x3b4));
    if ((u16)(kind - 0x2c) <= 2 || (u16)kind == 0x2f) {
        b *= lbl_8054037C;
    }
    if (((bool (*)())fn_8022B244)() && fn_802416C4(p) == 5) {
        a *= lbl_805403A0;
        b *= lbl_805403A0;
    }
    F32(p, 0x38c) = a;
    F32(p, 0x390) = b;
    if (a * a + b * b <= lbl_8054035C * FLT_EPSILON) {
        return;
    }
    if (U8(PTR(p, 0xbf0), 0xb7)) {
        return;
    }
    if (fn_80246B10(p, 0x40)) {
        F32(p, 0x368) = lbl_80540360;
        F32(p, 0x36c) = lbl_80540360;
        return;
    }
    F32(p, 0x8) += a * fn_8022C82C(S32(p, 0x4));
    s32 area = S32(p, 0x3b4);
    if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + area + 0x31df) != 0) {
        if (fn_8022C76C(S32(p, 0x4)) > lbl_80540360) {
            s32 i;
            for (i = 0; i < 8; i++) {
                fn_8024B298(p, i, &tmp);
                tmp.y += b * -fn_8022C76C(S32(p, 0x4));
                if ((u16)fn_8022461C((char*)&tmp, S32(p, 0x3b4)) != 2) {
                    F32(p, 0xc) += b * -fn_8022C76C(S32(p, 0x4));
                    return;
                }
            }
            F32(p, 0x36c) = lbl_80540360;
            return;
        }
    }
    F32(p, 0xc) += b * -fn_8022C76C(S32(p, 0x4));
}

extern const f32 lbl_8054035C, lbl_80540378, lbl_805403A8;
bool fn_80250D30(char*);
bool fn_80240B5C(char*);
bool fn_80270A8C(char*);
bool Player_GetField_0x454(char*);
void fn_80280B30(char* p) {
    if (fn_80250D30(p) || fn_80240B5C(p)) {
        F32(p, 0x368) = lbl_80540360;
        F32(p, 0x36c) = lbl_80540360;
        F32(p, 0x370) = lbl_80540360;
        return;
    }
    if (Player_GetField_0xce8(p) || Player_GetField_0x454(p) || fn_80270A8C(p)) {
        return;
    }
    if (U8(PTR(p, 0xbf0), 0xb7) != 0) {
        if (!(F32(p, 0x10) <= lbl_80540360)) {
            if (!fn_80246B10(p, 0x40)) {
                f32 before = PSVECMag((JGeometry::TVec3<f32>*)(p + 0x368));
                F32(p, 0x368) += lbl_805403A4 * (F32(p, 0x38c) * fn_8022C82C(S32(p, 0x4)));
                F32(p, 0x36c) += lbl_805403A4 * (F32(p, 0x390) * -fn_8022C76C(S32(p, 0x4)));
                if (PSVECMag((JGeometry::TVec3<f32>*)(p + 0x368)) < before) {
                    fn_8024F0E8(p, 0x20059);
                }
            }
        } else {
            F32(p, 0x368) = lbl_80540360;
            F32(p, 0x36c) = lbl_80540360;
        }
        F32(p, 0x370) = lbl_80540360;
        f32 t = PSVECMag((JGeometry::TVec3<f32>*)(p + 0x368));
        t -= lbl_805403A8;
        if (t < lbl_80540360) {
            t = lbl_80540360;
        } else if (!(t >= lbl_80540378)) {
            t = lbl_80540378;
        }
        if (VEC(p, 0x368).squared() > JGeometry::TUtilf::epsilon()) {
            VEC(p, 0x368).normalize();
            VEC(p, 0x368).scale(t);
            F32(p, 0x8) += F32(p, 0x368);
            F32(p, 0xc) += F32(p, 0x36c);
            return;
        }
    }
    if ((u16)fn_8022461C(p + 0x14, 0) == 3) {
        return;
    }
    F32(p, 0x368) = lbl_80540360;
    F32(p, 0x36c) = lbl_80540360;
    F32(p, 0x370) = lbl_80540360;
}

void fn_80280DD8(char* p) {
    void* emitter = PTR(p, 0x1350);
    if (emitter != NULL) {
        S32(emitter, 0xf4) |= 1;
        S32(emitter, 0x24) = 1;
        PTR(p, 0x1350) = NULL;
    }
    U8(p, 0x484) = 0;
    VEC(p, 8).sub(VEC(p, 8), VEC(p, 0x474));
    F32(p, 0x474) = lbl_80540360;
    F32(p, 0x478) = lbl_80540360;
    F32(p, 0x47c) = lbl_80540360;
    S32(p, 0x464) = 60;
}

s32 fn_80246D1C(char*, s32);
void fn_8013CB44(void*, void*, s32, s32, s32, s32);
void fn_80280E44(char* param_1) {
    if (U8(param_1, 0x484) == 0) {
        if (S32(param_1, 0x470) > 0) {
            S32(param_1, 0x470) -= 1;
        }
    } else {
        S32(param_1, 0x46c) = 0;
        if (S32(param_1, 0x480) > 0) {
            S32(param_1, 0x480) -= 1;
        }
        if (S32(param_1, 0x480) <= 0 && fn_80251AEC(param_1, 0)) {
            fn_8024E3D8(param_1);
        }
    }
    fn_80268B3C(param_1);
    if (PTR(param_1, 0x1350) != 0) {
        fn_8013CB44(PTR(param_1, 0x1350), param_1 + 8, 0, 1, 1, 0);
    }
}

void fn_802810E4(char* p) {
    U8(p, 0x458) = 0;
    fn_8013CC50(S32(p, 0x3b4), p + 8, 0x289, 0, 1, 0, 0, 1, lbl_8054036C);
    if (PTR(p, 0x1350) == NULL)
        PTR(p, 0x1350) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x28a, 0, 1, 0, 0, 1, lbl_8054036C);
    if (!Player_IsLinked(p)) fn_8024E3D8(p);
    S32(p, 0x46c) = 300;
    U8(p, 0x484) = 0;
    S32(p, 0x470) = 0;
    F32(p, 0x474) = lbl_80540360;
    F32(p, 0x478) = lbl_80540360;
    F32(p, 0x47c) = lbl_80540360;
    fn_8024F0E8(p, 0x2003b);
}

void fn_802811C0(char* p) {
    void* emitter = PTR(p, 0x132c);
    if (emitter != NULL) {
        S32(emitter, 0xf4) |= 1;
        S32(emitter, 0x24) = 1;
        PTR(p, 0x132c) = NULL;
    }
    emitter = PTR(p, 0x135c);
    if (emitter != NULL) {
        S32(emitter, 0xf4) |= 1;
        S32(emitter, 0x24) = 1;
        PTR(p, 0x135c) = NULL;
    }
    s32 actorId = S32(p, 0xb28);
    if (actorId >= 0) {
        void* actor = fn_801F666C(fn_801F856C(), actorId);
        if (actor != NULL) fn_802BAA00(actor);
        S32(p, 0xb28) = -1;
    }
}

void fn_8028126C(char* p) {
    s32 actorId;
    s32 prevState = S32(p, 0x3dc);
    if (F32(p, 0x10) <= lbl_80540360 && F32(p, 0x34c) <= lbl_80540360) {
        F32(p, 0x34c) = lbl_80540360;
        fn_8027EB04(p);
    }
    JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)(p + 0x344), (Vec*)(p + 8));
    switch (S32(p, 0x3dc)) {
    case 0:
        F32(p, 0x344) = lbl_805403B0;
        F32(p, 0x348) = lbl_80540360;
        F32(p, 0x34c) = lbl_80540360;
        break;
    case 1:
        F32(p, 0x344) = lbl_805403B4;
        F32(p, 0x348) = lbl_80540360;
        F32(p, 0x34c) = lbl_80540360;
        break;
    case 2:
        F32(p, 0x344) = lbl_80540360;
        F32(p, 0x348) = lbl_805403B0;
        F32(p, 0x34c) = lbl_80540360;
        break;
    case 3:
        F32(p, 0x344) = lbl_80540360;
        F32(p, 0x348) = lbl_805403B4;
        F32(p, 0x34c) = lbl_80540360;
        break;
    }
    S32(p, 0x408)++;
    if (S32(p, 0x408) < 300) {
        if ((u16)fn_8022461C(p + 8, S32(p, 0x3b4)) == 0x39) {
            fn_80251AEC(p, 0);
        }
    } else {
        F32(p, 0x34c) -= lbl_80540398;
        F32(p, 0x10) += F32(p, 0x34c);
        if (F32(p, 0x10) <= 0.0f) {
            F32(p, 0x34c) = 0.0f;
        }
    }
    actorId = S32(p, 0xb28);
    if (actorId >= 0) {
        void* actor = fn_801F666C(fn_801F856C(), actorId);
        if (actor != NULL) {
            fn_802BAA0C(actor, p + 0x4c0);
        }
    }
    fn_80268B3C(p);
    U8(p, 0x3f8)++;
    if (U8(p, 0x3f8) >= 0x10) {
        U8(p, 0x3f8) = 0;
    }
    U8(p, 0x3f9) = (u32)U8(p, 0x3f8) >> 1;
    if (prevState != S32(p, 0x3dc)) {
        char* e = (char*)PTR(p, 0x135c);
        if (e != NULL) {
            S32(e, 0xf4) |= 1;
            S32(e, 0x24) = 1;
            PTR(p, 0x135c) = NULL;
        }
        if (PTR(p, 0x135c) == NULL) {
            switch (S32(p, 0x3dc)) {
            case 0:
                PTR(p, 0x135c) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x248, 0, 0, 0, 0, 1, lbl_8054036C);
                break;
            case 1:
                PTR(p, 0x135c) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x247, 0, 0, 0, 0, 1, lbl_8054036C);
                break;
            case 2:
                PTR(p, 0x135c) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x246, 0, -1, 0, 0, 1, lbl_8054036C);
                break;
            case 3:
                PTR(p, 0x135c) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x249, 0, 0, 0, 0, 1, lbl_8054036C);
                break;
            }
        }
        if (PTR(p, 0x132c) != NULL) {
            void* mgr = fn_8013C824();
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)mgr + 0xc), PTR(p, 0x132c));
            PTR(p, 0x132c) = NULL;
        }
        if (PTR(p, 0x132c) == NULL) {
            switch (S32(p, 0x3dc)) {
            case 0:
                PTR(p, 0x132c) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x244, 0, 0, 0, (s32)(p + 0x1330), 1, lbl_8054036C);
                break;
            case 1:
                PTR(p, 0x132c) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x243, 0, 0, 0, (s32)(p + 0x1330), 1, lbl_8054036C);
                break;
            case 2:
                PTR(p, 0x132c) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x242, 0, -1, 0, (s32)(p + 0x1330), 1, lbl_8054036C);
                break;
            case 3:
                PTR(p, 0x132c) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x245, 0, 0, 0, (s32)(p + 0x1330), 1, lbl_8054036C);
                break;
            }
        }
    }
    if (PTR(p, 0x135c) != NULL) {
        switch (S32(p, 0x3dc)) {
        case 0:
        case 1:
        case 3:
            ((void (*)(void*, void*, s32, s32, s32))fn_8013CB44)(PTR(p, 0x135c), p + 8, 0, 0, 1);
            break;
        case 2:
            ((void (*)(void*, void*, s32, s32, s32))fn_8013CB44)(PTR(p, 0x135c), p + 8, 0, -1, 1);
            break;
        }
    }
    if (PTR(p, 0x132c) != NULL) {
        F32(p, 0x1344) = F32(p, 0x8);
        F32(p, 0x1348) = F32(p, 0xc);
        F32(p, 0x134c) = F32(p, 0x10);
        if (S32(p, 0x3dc) == 2) {
            F32(p, 0x1348) -= lbl_80540380;
        } else if (S32(p, 0x3dc) == 3) {
            F32(p, 0x1348) += lbl_80540380;
        }
        F32(p, 0x1334) = F32(p, 0x1344);
        F32(p, 0x1338) = F32(p, 0x1348);
        F32(p, 0x133c) = F32(p, 0x134c);
    }
}

void fn_80281A18(char* p) {
    U8(p, 0x11d8) = 0;
    S32(p, 0x11d4) = 10;
    VEC(p, 0x368).set(F32(p, 0x344), F32(p, 0x348), lbl_80540360);
    void* emitter = PTR(p, 0x1354);
    if (emitter != NULL) {
        S32(emitter, 0xf4) |= 1;
        S32(emitter, 0x24) = 1;
        PTR(p, 0x1354) = NULL;
    }
    emitter = PTR(p, 0x1358);
    if (emitter != NULL) {
        S32(emitter, 0xf4) |= 1;
        S32(emitter, 0x24) = 1;
        PTR(p, 0x1358) = NULL;
    }
}

bool fn_802466B4(char*);
bool fn_802DEBF8();
void fn_80281A90(char* p) {
    s32 area;
    s32 base;
    if (U8(p, 0x3fa) >= 5) {
        if (fn_802466B4(p)) {
            if (!fn_802DEBF8() && fn_80251AEC(p, 9)) {
                S32(p, 0x11ac) = 4;
            }
        }
    }
    F32(p, 0x8) += F32(p, 0x344);
    F32(p, 0x8) += fn_8022C82C(S32(p, 0x4));
    area = S32(p, 0x3b4);
    base = (s32)fn_802D6A9C();
    if (*((u8*)(base + 0x10000 + area + 0x31df)) == 0 || (u16)fn_8022461C(p + 8, S32(p, 0x3b4)) != 2) {
        F32(p, 0xc) += F32(p, 0x348);
        F32(p, 0xc) -= fn_8022C76C(S32(p, 0x4));
    }
    F32(p, 0x368) = lbl_80540360;
    F32(p, 0x36c) = lbl_80540360;
    F32(p, 0x370) = lbl_80540360;
    {
        u8 v = U8(p, 0x3fa);
        if (v < 4) {
            U8(p, 0x3fb) = 0;
        } else if (v < 8) {
            U8(p, 0x3fb) = 1;
        } else if (v < 11) {
            U8(p, 0x3fb) = 2;
        } else if (v < 14) {
            U8(p, 0x3fb) = 3;
        } else if (v < 17) {
            U8(p, 0x3fb) = 4;
        } else if (v < 20) {
            U8(p, 0x3fb) = 5;
        } else {
            U8(p, 0x3fb) = 5;
            fn_80251AEC(p, 0);
        }
    }
    U8(p, 0x3fa)++;
    fn_80268B3C(p);
    if (F32(p, 0x10) <= lbl_80540360) {
        if ((u16)fn_8022461C(p + 8, S32(p, 0x3b4)) == 0x39) {
            if (PTR(p, 0x1358) == 0) {
                PTR(p, 0x1358) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x3d4, 0, -1, (s32)(p + 0x13a8), 0, 1, lbl_8054036C);
            } else {
                ((void (*)(void*, void*, s32, s32, s32))fn_8013CB44)(PTR(p, 0x1358), p + 8, 0, -1, 1);
            }
            char* e = (char*)PTR(p, 0x1354);
            if (e != 0) {
                S32(e, 0xf4) |= 1;
                S32(e, 0x24) = 1;
                PTR(p, 0x1354) = 0;
            }
        } else {
            if (PTR(p, 0x1354) == 0) {
                PTR(p, 0x1354) = fn_8013CC50(S32(p, 0x3b4), p + 8, 0x3d3, 0, -1, (s32)(p + 0x1398), 0, 1, lbl_8054036C);
            } else {
                ((void (*)(void*, void*, s32, s32, s32))fn_8013CB44)(PTR(p, 0x1354), p + 8, 0, -1, 1);
            }
            char* e = (char*)PTR(p, 0x1358);
            if (e != 0) {
                S32(e, 0xf4) |= 1;
                S32(e, 0x24) = 1;
                PTR(p, 0x1358) = 0;
            }
        }
    }
}

extern const f32 lbl_8046BE78[];
u8 fn_80240670(char*);
void* fn_80246B10(char*, s32);
s32 fn_80230CFC(s32);
s32 Player_GetLinkTargetIndex(char*);
void fn_80281D50(char* p) {
    U8(p, 0x458) = 0;
    if ((u8)fn_80240670(p)) {
        s32 idx = fn_80230CFC(Player_GetLinkTargetIndex(p));
        S32(p, 0x3dc) = idx;
        S32(p, 0x3e8) = idx;
    } else if (fn_80246B10(p, 2)) {
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
    } else if (fn_80246B10(p, 1)) {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    } else if (fn_80246B10(p, 8)) {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    } else if (fn_80246B10(p, 4)) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    }
    {
        const f32* v = &lbl_8046BE78[S32(p, 0x3dc) * 3];
        F32(p, 0x344) = v[0];
        F32(p, 0x348) = v[1];
        F32(p, 0x34c) = v[2];
    }
    fn_8024F0E8(p, 0x1000c);
    F32(p, 0x368) = lbl_80540360;
    F32(p, 0x36c) = lbl_80540360;
    F32(p, 0x370) = lbl_80540360;
    U8(p, 0x11d8) = 0;
}

void fn_80281E84(char* p) {
    F32(p, 0xc84) = lbl_8054036C;
    F32(p, 0xc88) = lbl_8054036C;
    F32(p, 0xc8c) = lbl_8054036C;
}

extern const f32 lbl_805403B8, lbl_805403BC, lbl_805403C0;
bool fn_802517F8(char*, s32);
bool fn_802518AC(char*, s32);
void fn_80281E98(char* p) {
    if (U8(p, 0x3fc) != 0) {
        U8(p, 0x3fc)--;
    } else {
        F32(p, 0x348) -= lbl_805403B8;
        if (F32(p, 0x348) <= lbl_805403AC) {
            F32(p, 0x348) = lbl_805403AC;
        }
        if (F32(p, 0x344) > lbl_80540360) {
            F32(p, 0x344) += lbl_805403B8;
            if (F32(p, 0x344) > lbl_805403BC || fn_802517F8(p, 0)) {
                F32(p, 0x344) = lbl_805403AC;
                F32(p, 0x348) = lbl_80540380;
                F32(p, 0x34c) = lbl_80540360;
                U8(p, 0x3fc) = 10;
                U8(p, 0x3fa)++;
            }
        } else {
            F32(p, 0x344) -= lbl_805403B8;
            if (F32(p, 0x344) < lbl_805403C0 || fn_802517F8(p, 0)) {
                F32(p, 0x344) = lbl_8054036C;
                F32(p, 0x348) = lbl_80540380;
                F32(p, 0x34c) = lbl_80540360;
                U8(p, 0x3fc) = 10;
                U8(p, 0x3fa)++;
            }
        }
    }
    if (U8(p, 0x3fc) == 0) {
        VEC(p, 8).add(VEC(p, 8), VEC(p, 0x344));
    }
    if ((U8(p, 0x3fa) >= 2 && F32(p, 0x348) <= lbl_80540360) || U8(p, 0x3fd) == 1 || fn_802518AC(p, 0)) {
        U8(p, 0x3fd) = 1;
        F32(p, 0x344) = lbl_80540360;
        F32(p, 0x348) = lbl_80540360;
        F32(p, 0x34c) = lbl_80540360;
        F32(p, 0x10) = lbl_80540360;
        if (F32(p, 0xc8c) >= lbl_8054036C) {
            fn_80251AEC(p, 0);
        }
    } else {
        F32(p, 0xc84) = lbl_8054036C;
        F32(p, 0xc88) = lbl_8054036C;
        F32(p, 0xc8c) = lbl_8054037C;
    }
    fn_802685D4(p);
}

void fn_80282094(char* p) {
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805403AC;
    F32(p, 0x348) = lbl_80540380;
    F32(p, 0x34c) = lbl_80540360;
    fn_802D79E8(fn_802D6A9C(), S32(p, 0x3b4), 0, lbl_80540384, lbl_80540360);
    fn_802F601C(PTR(lbl_8053AB10, 0x20), p + 0xcb0, 1, 0, lbl_8054036C, lbl_805403B4);
    U8(p, 0x3fc) = 20;
}

void fn_8028211C(char* p) {
    if (U8(p, 0xce8) == 1 && (S32(p, 0xcf4) == 0x13 || S32(p, 0xcf4) == 0x16))
        U8(p, 0xce8) = 0;
    U8(p, 0xcea) = 0;
    if (S32(p, 0x3b4) < 8) fn_8024BAEC(p);
}

void fn_8028286C(char* p) {
    F32(p, 0x344) = F32(p, 0x374);
    F32(p, 0x348) = F32(p, 0x378);
    F32(p, 0x34c) = F32(p, 0x37c);
    F32(p, 0x380) = lbl_80540360;
    F32(p, 0x384) = lbl_80540360;
    F32(p, 0x388) = lbl_80540360;
    U8(p, 0x458) = 0;
    S32(p, 0x394) = 0;
    U8(p, 0xcea) = 0;
}

void fn_802828A8(char* p) {
    s32 area;
    void* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd8c));
    if (actor != NULL) {
        area = S32(p, 0x3b4);
        if (U8(fn_802D6A9C(), 0x131df + area) != 0) {
            f32 speed = -fn_801080B8(actor);
            F32(p, 0x374) = lbl_80540360;
            F32(p, 0x378) = speed;
            F32(p, 0x37c) = lbl_80540360;
        } else {
            f32 speed = fn_801080B8(actor);
            F32(p, 0x374) = lbl_80540360;
            F32(p, 0x378) = lbl_80540360;
            F32(p, 0x37c) = speed;
        }
    }
    S32(p, 0xd8c) = -1;
    U8(p, 0xd90) = 0;
}

void fn_80282958(char* p) {
    void* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd8c));
    if (actor != NULL) {
        F32(p, 8) = F32(actor, 0xc);
        F32(p, 0xc) = F32(actor, 0x10);
        F32(p, 0x10) = F32(actor, 0x14);
        F32(p, 0xc) -= lbl_80540368;
    }
    F32(p, 0x10) = lbl_80540360;
    if (fn_80245DB0(p) || U8(p, 0xd90) == 1) {
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x4d)) {
            if (actor != NULL) fn_80107360(actor);
            fn_802685D4(p);
        }
    }
    fn_8024BAEC(p);
}

void fn_80282A24(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    void* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd8c));
    if (actor != NULL) {
        F32(p, 8) = F32(actor, 0xc);
        F32(p, 0xc) = F32(actor, 0x10);
        F32(p, 0x10) = F32(actor, 0x14);
        F32(p, 0xc) -= lbl_80540368;
    }
    F32(p, 0x10) = lbl_80540360;
    U8(p, 0xd90) = 0;
}

void fn_80282AA8(char* p) {
    s32 st = S32(p, 0x1244);
    if (st == 15) return;
    if (st == 16) return;
    S32(p, 0xbe4) = 0;
    U8(p, 0xbe8) = 0;
}

u8 fn_8023F264(s32);
u8 fn_80243194(char*, s32);
s32 fn_8022CAF8(s32);
void fn_8023E080(s32, s32);
void fn_80282E6C(char* p) {
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_80540360;
    F32(p, 0x348) = lbl_80540360;
    F32(p, 0x34c) = lbl_80540360;
    F32(p, 0x414) = lbl_80540360;
    F32(p, 0x418) = lbl_80540360;
    F32(p, 0x41c) = lbl_80540360;
    U8(p, 0x3ff) = 0;
    F32(p, 0x410) = lbl_80540360;
    U8(p, 0x402) = 0;
    F32(p, 0x10) = lbl_80540360;
    s32 state = S32(p, 0x1248);
    if (state != 0x1b && state != 0x3 && state != 0x1d) {
        fn_8024F0E8(p, 0x2003a);
    }
    if (Player_IsLinked(p)) {
        s32 target = fn_80230CFC(Player_GetLinkTargetIndex(p));
        S32(p, 0x3e8) = target;
        S32(p, 0x3dc) = target;
    }
    if (U8(p, 0xbe8) == 0) {
        S32(p, 0xbe4) = 0x258;
        U8(p, 0xbe8) = 1;
    }
    if (!fn_80240670(p) && S32(p, 0x1248) != 0xf && S32(p, 0x1248) != 0x10) {
        if (S32(p, 0x1248) == 0x27) {
            S32(p, 0xd28) = 0;
        } else {
            S32(p, 0xd28) = S32(p, 0x3b4);
        }
        s32 i = 0;
        do {
            if (fn_8023F264(i) && fn_80243194(p, i) && fn_8022CAF8(i) != 4) {
                fn_8023E080(i, S32(p, 0xd28));
            }
            i++;
        } while (i < 4);
    }
}

void fn_80282FC8(char* p) {
    U8(p, 0x42c) = 0;
    S32(p, 0x430) = 0;
    U8(p, 0x42d) = 0;
    U8(p, 0x400) = 0;
}

void fn_80283848(char* p) {
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_80540360;
    F32(p, 0x348) = lbl_80540360;
    F32(p, 0x34c) = lbl_80540360;
    F32(p, 0x414) = lbl_80540360;
    F32(p, 0x418) = lbl_80540360;
    F32(p, 0x41c) = lbl_80540360;
    U8(p, 0x3ff) = 0;
    U8(p, 0x400) = 0;
    U8(p, 0x401) = 0;
    F32(p, 0x410) = lbl_80540360;
    U8(p, 0x42c) = 0;
    S32(p, 0xbe0) = 0;
    U8(p, 0x42d) = 0;
    S32(p, 0x430) = 0;
    if (S32(p, 0x44c) == 0 && S32(p, 0x1248) != 0x1b &&
        S32(p, 0x1248) != 3 && S32(p, 0x1248) != 0x1d) {
        fn_8013CC50(S32(p, 0x3b4), p + 8, 0x15b, 0, 1, 0, 0, 1, lbl_8054036C);
        fn_8013CC50(S32(p, 0x3b4), p + 8, 0x15c, -1, 0, 0, 0, 1, lbl_8054036C);
        fn_8024F0E8(p, 0x2003a);
        S32(p, 0x44c) = 5;
    }
}

void fn_80283944(void) {
}

s32 fn_80303750(s32);
void fn_8030BD3C(void*, s32);
void fn_80290E90(char*);
void fn_80290D58(char*);
s32 fn_8024189C(char*);
s32 fn_80138A30(void*);
void fn_80283948(char* p) {
    if (U8(p, 0xce8) == 1) {
        S32(p, 0x3b4) = S32(p, 0xce4);
        VEC(p, 0x8) = VEC(p, 0xcd4);
        if (S32(p, 0xce4) != S32(p, 0xce0) && !Player_IsLinked(p)) {
            if ((u8)fn_80303750(S32(p, 0x4))) {
                return;
            }
        }
        fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
        fn_80290E90(p);
        fn_80290D58(p);
    }
    if (fn_8024189C(p) <= 0) {
        U8(p, 0x124d) = 0;
        fn_80251AEC(p, 0x33);
    } else if (S32(p, 0x1178) == 2) {
        U8(p, 0x3fc) += 1;
        if (U8(p, 0x3fc) >= 0x24) {
            U8(p, 0x3fc) = 0;
        }
        if (U8(p, 0x3fc) < 6) {
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) < 0xc) {
            U8(p, 0x3fd) = 1;
        } else if (U8(p, 0x3fc) < 0x12) {
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) < 0x18) {
            U8(p, 0x3fd) = 2;
        } else if (U8(p, 0x3fc) < 0x1e) {
            U8(p, 0x3fd) = 3;
        } else {
            U8(p, 0x3fd) = 2;
        }
    } else {
        if ((u32)fn_80246D1C(p, 0xf) != 0) {
            U8(p, 0x3fc) += 1;
            U8(p, 0x3fa) = 0;
            U8(p, 0x3f8) = 0;
            U8(p, 0x3f9) += 1;
            if (S32(p, 0x1178) == 1) {
                if (fn_80138A30(lbl_8053AAF8) <= 1) {
                    if (U8(p, 0x3fc) >= 0xf) {
                        U8(p, 0x124d) = 0;
                        fn_80251AEC(p, 0);
                    }
                } else if (U8(p, 0x3fc) >= 0x1e) {
                    U8(p, 0x124d) = 0;
                    fn_80251AEC(p, 0);
                }
            }
        } else {
            U8(p, 0x3fa) += 1;
            if (U8(p, 0x3fa) >= 0x14) {
                U8(p, 0x3fa) = 0;
                if (U8(p, 0x3fc) != 0) {
                    U8(p, 0x3fc) -= 1;
                }
            }
        }
        if (S32(p, 0x1178) == 0) {
            if (U8(p, 0x3fc) < 4) {
                U8(p, 0x3f8) += 1;
                if (U8(p, 0x3f8) >= 5) {
                    U8(p, 0x3f8) = 0;
                    U8(p, 0x3f9) += 1;
                }
                U8(p, 0x3fd) = 0;
            } else {
                U8(p, 0x3f8) += 1;
                if (U8(p, 0x3f8) >= 6) {
                    U8(p, 0x3f8) = 0;
                    U8(p, 0x3f9) += 1;
                }
                if ((U8(p, 0x3f9) & 3) == 1) {
                    U8(p, 0x3fd) = 1;
                } else if ((U8(p, 0x3f9) & 3) == 3) {
                    U8(p, 0x3fd) = 2;
                } else {
                    U8(p, 0x3fd) = 0;
                }
            }
        } else if (U8(p, 0x3fc) < 4) {
            U8(p, 0x3f8) += 1;
            if (U8(p, 0x3f8) >= 5) {
                U8(p, 0x3f8) = 0;
                U8(p, 0x3f9) += 1;
            }
            U8(p, 0x3fd) = U8(p, 0x3f9) & 1;
        } else {
            U8(p, 0x3f8) += 1;
            if (U8(p, 0x3f8) >= 6) {
                U8(p, 0x3f8) = 0;
                U8(p, 0x3f9) += 1;
            }
            if ((U8(p, 0x3f9) & 3) == 1) {
                U8(p, 0x3fd) = 3;
            } else if ((U8(p, 0x3f9) & 3) == 3) {
                U8(p, 0x3fd) = 4;
            } else {
                U8(p, 0x3fd) = 2;
            }
        }
        fn_8027EB04(p);
    }
}

void fn_80283CEC(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

void fn_80283D00(char* p) { fn_8027EB04(p); }

void fn_80283D20(char* p) { U8(p, 0x458) = 0; }

void fn_80283D2C(char* p) {
    if (U8(p, 0x440) != 0) {
        F32(p, 0x2c4) = F32(p, 0x8);
        F32(p, 0x2c8) = F32(p, 0xc);
        F32(p, 0x2cc) = F32(p, (int)0x10);
    }
    if (S32(p, 0xcf4) != 0x24) {
        U8(p, 0xce8) = 0;
        if (U8(p, 0x43f) == 0) {
            if (fn_802486A0(p) != 4 && !Player_IsLinked(p)) {
                register s32 id;
                register s32 i = 0;
                id = S32(p, 0x4);
                do {
                    s32 found = fn_8022F3DC(i);
                    if (found == id) {
                        fn_802384BC(i);
                    }
                    i += 1;
                } while (i < 4);
            }
            if ((u16)fn_8022461C(p + 0x8, S32(p, 0x3b4)) == 0xd) {
                fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x3d0, 0, -1, 0, 0, 1, lbl_80540390);
            }
        } else if (S32(p, 0x1244) != 0x1b) {
            U8(p, 0x43f) = 0;
            U8(p, 0x440) = 0;
            F32(p, 0x444) = lbl_80540360;
        } else {
            F32(p, 0x444) = F32(p, 0x34c);
        }
    }
    U8(p, 0x441) = 0;
    fn_8024BAEC(p);
}

extern const f32 lbl_80540364, lbl_805403D4, lbl_805403DC, lbl_805403F8;
void fn_80134DE4(void*, s32, s32);
void fn_80283E70(char* p) {
    if (F32(p, 0x10) >= lbl_80540360) {
        VEC(p, 8).add(VEC(p, 8), VEC(p, 0x344));
    }
    if (U8(p, 0x43f) || U8(p, 0x441)) {
        if (F32(p, 0x34c) >= lbl_805403DC) {
            F32(p, 0x34c) -= lbl_805403F8;
            if (F32(p, 0x34c) < lbl_805403DC) {
                F32(p, 0x34c) = lbl_805403DC;
            }
        }
    } else {
        F32(p, 0x34c) -= lbl_80540398;
    }
    if (!(F32(p, 0x10) > lbl_80540360)) {
        if ((U8(p, 0x43f) || U8(p, 0x441)) && F32(p, 0xc) < F32(p, 0x328)) {
            F32(p, 0xc) += F32(p, 0x328) - F32(p, 0xc);
            F32(p, 0x10) = lbl_80540364;
        } else {
            F32(p, 0x10) = lbl_80540360;
            s32 flag = 0;
            if (U8(p, 0xcad) == 1) {
                flag = 8;
            }
            U8(p, 0x124d) = 0;
            if (fn_80251AEC(p, flag) && U8(p, 0x43f)) {
                JGeometry::TVec3<f32> pos = VEC(p, 8);
                pos.y += lbl_805403D4;
                void* a = fn_8013CC50(S32(p, 0x3b4), &pos, 0x4f3, -1, 0, 0, 0, 1, lbl_8054036C);
                void* b = fn_8013CC50(S32(p, 0x3b4), &pos, 0x4f4, 0, 0, 0, 0, 1, lbl_8054036C);
                void* c = fn_8013CC50(S32(p, 0x3b4), &pos, 0x4f5, 0, 0, 0, 0, 1, lbl_8054036C);
                void* d = fn_8013CC50(S32(p, 0x3b4), &pos, 0x4f6, 0, 0, 0, 0, 1, lbl_8054036C);
                if (!U8(p, 0x440)) {
                    F32(a, 0x98) = lbl_8054037C;
                    F32(a, 0x9c) = lbl_8054037C;
                    F32(a, 0xa0) = lbl_8054037C;
                    F32(a, 0xb0) = lbl_8054037C;
                    F32(a, 0xb4) = lbl_8054037C;
                    F32(b, 0x98) = lbl_8054037C;
                    F32(b, 0x9c) = lbl_8054037C;
                    F32(b, 0xa0) = lbl_8054037C;
                    F32(b, 0xb0) = lbl_8054037C;
                    F32(b, 0xb4) = lbl_8054037C;
                    F32(c, 0x98) = lbl_8054037C;
                    F32(c, 0x9c) = lbl_8054037C;
                    F32(c, 0xa0) = lbl_8054037C;
                    F32(c, 0xb0) = lbl_8054037C;
                    F32(c, 0xb4) = lbl_8054037C;
                    F32(d, 0x98) = lbl_8054037C;
                    F32(d, 0x9c) = lbl_8054037C;
                    F32(d, 0xa0) = lbl_8054037C;
                    F32(d, 0xb0) = lbl_8054037C;
                    F32(d, 0xb4) = lbl_8054037C;
                }
                fn_80134DE4(lbl_8053AAF8, 1, 0);
            }
        }
    }
    if (U8(p, 0x440) && F32(p, 0x34c) < lbl_80540360) {
        fn_8024F0E8(p, 0x1000d);
        fn_8024F0E8(p, 0x2003e);
    }
}

void fn_8028414C(char* p) {
    U8(p, 0x458) = 0;
    U8(p, 0xce8) = 1;
    if (!U8(p, 0x43f)) {
        U8(p, 0x124d) = 1;
    }
    F32(p, 0x318) = F32(p, 8);
    F32(p, 0x31c) = F32(p, 0xc);
    F32(p, 0x320) = F32(p, 0x10);
    f32 dx = F32(p, 0x324) - F32(p, 8);
    f32 dy = F32(p, 0x328) - F32(p, 0xc);
    if (U8(p, 0x43f) || U8(p, 0x441)) {
        F32(p, 0x10) = lbl_80540360;
        F32(p, 0xc) += dy;
        F32(p, 0x10) += dy;
        F32(p, 0x344) = lbl_80540360;
        F32(p, 0x348) = lbl_80540360;
        if (U8(p, 0x43f) && S32(p, 0x1248) == 0x1b) {
            F32(p, 0x34c) = F32(p, 0x444);
        } else {
            F32(p, 0x34c) = lbl_805403B0;
        }
    } else {
        F32(p, 0x10) = lbl_80540360;
        F32(p, 0x344) = dx / lbl_805403FC;
        F32(p, 0x348) = dy / lbl_805403FC;
        F32(p, 0x34c) = lbl_80540400;
    }
    if (S32(p, 0x1248) != 0x1b) {
        if (!U8(p, 0x440)) {
            fn_8024F0E8(p, 0x10002);
        }
        fn_8024F0E8(p, 0x20008);
    }
}

void fn_80284290(void) {
}

void fn_80284294(char* p) {
    if (U8(p, 0x3fc) < 10) {
        F32(p, 0xc8c) = lbl_805403A4 * (10 - U8(p, 0x3fc)) + lbl_8054037C;
    } else {
        F32(p, 0xc8c) = lbl_8054037C;
        U8(p, 0x124d) = 0;
        fn_80251AEC(p, 0);
    }
    U8(p, 0x3fc)++;
    fn_80268B3C(p);
}

void fn_80284328(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0xc84) = lbl_8054036C;
    F32(p, 0xc88) = lbl_8054036C;
    F32(p, 0xc8c) = lbl_8054036C;
}

void fn_8028434C(char* p) {
    f32 d = lbl_80540404;
    f32 c = lbl_80540398;
    VEC(p, 8).add(VEC(p, 0x344));
    F32(p, 0x34c) -= c;
    if (F32(p, 0x34c) < d) F32(p, 0x34c) = d;
    if (F32(p, 0x34c) < lbl_80540360 && F32(p, 0x10) <= lbl_80540360) {
        F32(p, 0x10) = lbl_80540360;
        U8(p, 0x124d) = 0;
        if (!(U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 4))) && !Player_IsLinked(p))
            fn_80251AEC(p, 0);
        else
            fn_80251AEC(p, 12);
    }
}

void fn_80284430(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_80540360;
    F32(p, 0x348) = lbl_80540360;
    F32(p, 0x34c) = lbl_80540384;
    fn_8024F0E8(p, 0x2002f);
}

void fn_8028447C(char* p) {
    VEC(p, 0x318) = VEC(p, 8);
    F32(p, 0x2c) = F32(p, 8);
    F32(p, 0x30) = F32(p, 0xc);
    F32(p, 0x34) = F32(p, 0x10);
    S32(p, 0x3bc) = S32(p, 0x3b4);
    U8(p, 0x43e) = 0;
    fn_80248604(p);
    U8(p, 0x3fe) = 0;
    S32(p, 0x1220) = 5;
    fn_8024D134(p);
}

void fn_802848F0(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0xce8) = 0;
    U8(p, 0x458) = 0;
    if (U8(p, 0x43f) == 0) F32(p, 0x10) = lbl_80540360;
    if (S32(p, 0x1248) == 0x4a) U8(p, 0x3fd) = 1;
    else if (S32(p, 0x1248) == 0x4b) U8(p, 0x3fd) = 2;
    else if (S32(p, 0x1248) == 0xb) U8(p, 0x3fd) = 3;
    else U8(p, 0x3fd) = 0;
    U8(p, 0x3fe) = 0;
}

void fn_8028496C(char* p) { S32(p, 0xda4) = -1; }

extern "C" JGeometry::TVec3<f32> lbl_8046BDA8[];
extern "C" const f32 lbl_805403B8;
extern "C" u8 fn_802265DC(f32* b, int a, int c);
extern "C" s32 fn_8024FF84(char*);
extern "C" s32 fn_802684A4(char*, f32*, s32);
extern "C" bool fn_8024F63C(char*);
extern "C" s32 fn_8024FF6C(char*);
extern "C" bool fn_802456FC(char*);
extern "C" bool fn_8024FEFC(char*);
extern "C" s32 fn_80246D1C(char*, s32);
void fn_80284978(char* p) {
    JGeometry::TVec3<f32> tmp;
    JGeometry::TVec3<f32> tmp2;
    JGeometry::TVec3<f32> d;
    JGeometry::TVec3<f32> d2;
    JGeometry::TVec3<f32> a;
    JGeometry::TVec3<f32> a2;
    u32 kind;
    bool moved;
    char* tbl = (char*)lbl_8046BDA8;
    JGeometry::TVec3<f32>* src = (JGeometry::TVec3<f32>*)(tbl + 0x70) + S32(p, 0x3dc);
    JGeometry::TVec3<f32>* src2 = (JGeometry::TVec3<f32>*)(tbl + 0xa0) + S32(p, 0x3dc);
    tmp.x = src->x;
    tmp.y = src->y;
    tmp.z = src->z;
    tmp2.x = src2->x;
    tmp2.y = src2->y;
    tmp2.z = src2->z;
    tmp.add(VEC(p, 0x8));
    tmp2.add(VEC(p, 0x8));
    kind = fn_8022461C((char*)&tmp, S32(p, 0x3b4));
    if (!fn_802265DC((f32*)&tmp, S32(p, 0x3b4), 1) || (u16)kind == 0xe || (u16)kind == 0x39 || (u16)kind == 0xd) {
        if (!fn_802684A4(p, (f32*)&tmp, S32(p, 0x3b4)) && !fn_8024F63C(p)) {
            fn_80251AEC(p, 0);
            goto tail;
        }
    }
    if (!fn_802265DC((f32*)&tmp2, S32(p, 0x3b4), 1) || fn_802684A4(p, (f32*)&tmp2, S32(p, 0x3b4))) {
        fn_80251AEC(p, 0);
        goto tail;
    }
    if (fn_8024FF84(p) >= 0) {
        char* actor = (char*)fn_801F666C(fn_801F856C(), fn_8024FF84(p));
        if (actor != 0) {
            a = VEC(actor, 0xc);
            a.sub(VEC(actor, 0x18));
            d = a;
            if (PSVECMag(&d) >= lbl_805403B8) {
                fn_80251AEC(p, 0xe);
                return;
            }
        }
    }
    moved = false;
    if (S32(p, 0xda4) >= 0) {
        char* actor = (char*)fn_801F666C(fn_801F856C(), fn_8024FF6C(p));
        if (actor != 0) {
            a2 = VEC(actor, 0xc);
            a2.sub(VEC(actor, 0x18));
            d2 = a2;
            if (PSVECMag(&d2) >= lbl_805403B8) {
                moved = true;
                VEC(p, 0x8).add(VEC(actor, 0x3c));
            } else if (!fn_802456FC(p)) {
                fn_80251AEC(p, 0);
            } else if (fn_802456FC(p) && fn_80246D1C(p, ((s32*)(tbl + 0x60))[S32(p, 0x3dc)])) {
                fn_80251AEC(p, 0xd);
            }
        } else {
            S32(p, 0xda4) = -1;
            if (fn_802456FC(p) && fn_80246D1C(p, ((s32*)(tbl + 0x60))[S32(p, 0x3dc)])) {
                fn_80251AEC(p, 0xd);
            }
        }
    } else if (!fn_802456FC(p)) {
        fn_80251AEC(p, 0);
    } else if (fn_802456FC(p) && fn_80246D1C(p, ((s32*)(tbl + 0x60))[S32(p, 0x3dc)])) {
        fn_80251AEC(p, 0xd);
    }
    if (fn_8024FEFC(p) || moved) {
        U8(p, 0x3f8) += 1;
        if (U8(p, 0x3f8) == 0x10) {
            fn_8024F0E8(p, 0x10012);
        } else if (U8(p, 0x3f8) >= 0x40) {
            U8(p, 0x3f8) = 0;
        }
        if (U8(p, 0x3f8) >= 0x20) {
            U8(p, 0x3f9) = (U8(p, 0x3f8) - 0x20) / 8;
        } else {
            U8(p, 0x3f9) = (U8(p, 0x3f8) >> 3) & 0x1f;
        }
    } else {
        U8(p, 0x3f8) = 0;
        U8(p, 0x3f9) = 0;
    }
tail:
    fn_80268B3C(p);
}

void fn_80284DD0(char* p) {
    U8(p, 0x458) = 0;
    S32(p, 0xda4) = -1;
}

void fn_80284DE4(char* p) {
    S32(p, 0xd94) = -1;
    S32(p, 0xd9c) = -1;
    S32(p, 0xd98) = 0;
    S32(p, 0x1170) = 60;
}

void fn_80285068(char* p) { U8(p, 0x458) = 0; }

void fn_80285074(char* p) {
    if (S32(p, 0x1244) == 14) return;
    S32(p, 0xd94) = -1;
    S32(p, 0xd9c) = -1;
    S32(p, 0xd98) = 0;
}

extern JGeometry::TVec3<f32> lbl_8046BDA8[];
extern u8 lbl_8046C098[];
extern const f32 lbl_805403B8, lbl_80540378;
u8 fn_802265DC(f32* b, int a, int c);
s32 fn_8024FF84(char*);
s32 fn_802684A4(char*, f32*, s32);
bool fn_80250090(char*);
extern JGeometry::TVec3<f32> lbl_8046BDA8[];
extern u8 lbl_8046C098[];
extern const f32 lbl_805403B8, lbl_80540378;
u8 fn_802265DC(f32* b, int a, int c);
void* fn_801F856C();
void* fn_801F666C(void*, s32);
s32 fn_8024FF84(char*);
s32 fn_802684A4(char*, f32*, s32);
bool fn_80250090(char*);
void* fn_80246B10(char*, s32);
bool fn_80275D9C(char*);
void fn_8027EB04(char*);
void fn_80261480(char*);
void fn_8024F0E8(char*, s32);
void fn_80268B3C(char*);
void fn_80285098(char* p) {
    s32 mode;
    s32 kind;
    JGeometry::TVec3<f32> tmp;
    JGeometry::TVec3<f32> d;
    JGeometry::TVec3<f32> a;
    JGeometry::TVec3<f32>* src = &lbl_8046BDA8[S32(p, 0x3dc)];
    tmp.x = src->x;
    tmp.y = src->y;
    tmp.z = src->z;
    tmp.add(VEC(p, 0x8));
    kind = fn_8022461C(p, S32(p, 0x3b4));
    if (fn_802265DC((f32*)&tmp, S32(p, 0x3b4), 1) && (u16)kind != 0xe && (u16)kind != 0x39) {
        if ((u16)kind == 0xd && !fn_802684A4(p, (f32*)&tmp, S32(p, 0x3b4)) && !fn_80250090(p)) {
            fn_80251AEC(p, 0);
            goto tail;
        }
    }
    {
        s32 id = fn_8024FF84(p);
        char* actor = (char*)fn_801F666C(fn_801F856C(), id);
        if (actor != 0) {
            a = VEC(actor, 0xc);
            a.sub(VEC(actor, 0x18));
            d = a;
            if (PSVECMag(&d) >= lbl_805403B8) {
                fn_80251AEC(p, 0xe);
                goto tail;
            }
        }
    }
    S32(p, 0xd94) = -1;
    fn_80275D9C(p);
    if (fn_80246B10(p, 0x40) == 0) {
        mode = S32(p, 0x3dc);
        if (mode != 0) {
            if (mode == 1) {
                F32(p, 0x8) += lbl_80540378 * fn_8022C82C(S32(p, 0x4));
            }
        } else {
            F32(p, 0xc) += lbl_80540378 * -fn_8022C76C(S32(p, 0x4));
        }
    }
    mode = S32(p, 0x3dc);
    fn_8027EB04(p);
    if (mode != S32(p, 0x3dc) || S32(S32(p, 0xbf0), 0xa0) == 0) {
        fn_80251AEC(p, 0);
        S32(p, 0xd9c) = -1;
        S32(p, 0xd98) = 0;
        S32(S32(p, 0xbf0), 0xa0) = 0;
        S32(S32(p, 0xbf0), 0xa4) = 0;
    }
    fn_80261480(p);
    U8(p, 0x3f8) += 1;
    if (U8(p, 0x3f8) >= 0x80) {
        U8(p, 0x3f8) = 0;
    }
    if (U8(p, 0x3f8) >= 0x40) {
        U8(p, 0x3f9) = lbl_8046C098[S32(p, 0x3dc) * 8 + ((U8(p, 0x3f8) - 0x40) >> 3)];
    } else {
        U8(p, 0x3f9) = lbl_8046C098[S32(p, 0x3dc) * 8 + ((U8(p, 0x3f8) >> 3) & 0x1f)];
    }
    if (U8(p, 0x3f8) == 0x10) {
        fn_8024F0E8(p, 0x10012);
    }
tail:
    fn_80268B3C(p);
}

void fn_8028537C(char* p) { U8(p, 0x458) = 0; }

void fn_80285388(void) {
}

void fn_8028538C(char* p) {
    JGeometry::TVec3<f32> tmp;
    fn_8027FA08(p, (f32*)&tmp);
    if (lbl_80540360 == tmp.z && lbl_80540360 != F32(p, 0x10) && U8(p, 0x434) == 0) {
        F32(p, 0x10) = lbl_80540360;
    }
    if (Player_IsLinked(p) && U8(p, 0x1215) != 0) {
        S32(p, 0x3b4) = fn_8023DE58(Player_GetLinkTargetIndex(p));
        VEC(p, 0x8) = *fn_8023E724(Player_GetLinkTargetIndex(p));
        return;
    }
    fn_80275D9C(p);
    if (fn_802486A0(p) == 5 && U8(PTR(p, 0xbf0), 0xb4) != 0) {
        fn_802808E8(p, lbl_80540378);
    } else if (S32(p, 0x122c) <= 0) {
        JGeometry::TVec3<f32> tmp2;
        JGeometry::TVec3<f32> dir;
        fn_8027FA08(p, (f32*)&tmp2);
        dir = tmp2 - VEC(p, 0x8);
        dir.z = lbl_80540360;
        if (dir.length() <= lbl_8054037C) {
            dir.normalize();
            dir.scale(lbl_8054037C);
            VEC(p, 0x8) += dir;
        } else {
            VEC(p, 0x8) = tmp2;
            if (fn_802486A0(p) == 5) {
                if (!Player_IsLinked(p)) {
                    fn_80251AEC(p, 0);
                }
            } else if (fn_8022C6AC(S32(p, 0x4)) == lbl_80540360) {
                fn_80251AEC(p, 0);
            } else {
                fn_80251AEC(p, 2);
            }
        }
    }
    fn_8027EB04(p);
    fn_8027EEB4(p);
    fn_80261480(p);
    fn_80268B3C(p);
}

void fn_80285668(char* p) {
    if (S32(p, 0x1248) == 2) {
        U8(p, 0x3f8) = U8(p, 0x437);
        U8(p, 0x3f9) = U8(p, 0x438);
    }
    U8(p, 0x458) = 0;
}

bool fn_80275D9C(char*);
void fn_8027FA08(char*, f32*);
u32 fn_8022C5EC(s32, s32);
u32 fn_8022C52C(s32, s32);
f32 fn_8022C6AC(s32);
f32 fn_8022CFE8(s32);
s32 fn_8023DE58(s32);
void fn_802808E8(char*, f32);
void fn_8027EEB4(char*);
void fn_80261480(char*);
s32 fn_80240888(char*);
s32 fn_80248778(char*);
f32 fn_80246F28(char*);
void fn_8027E7E0(char*);
extern const f32 lbl_80540378;
void fn_80285690(char* p) {
    f32 pos[2];
    if (!fn_80275D9C(p) && Player_IsLinked(p)) {
        s32 linkIdx;
        fn_8027FA08(p, pos);
        if (fn_8022C5EC(Player_GetLinkTargetIndex(p), 0x40)) {
            fn_80251AEC(p, 3);
        } else if (fn_8022C52C(Player_GetLinkTargetIndex(p), 0x40) && fn_8022C6AC(S32(p, 4)) != lbl_80540360) {
            fn_80251AEC(p, 3);
        } else if (fn_8022C6AC(Player_GetLinkTargetIndex(p)) == lbl_80540360 && fn_8022CFE8(S32(p, 4)) > lbl_80540360) {
            s32 idx;
            linkIdx = S32(p, 0x3b4);
            idx = fn_8023DE58(Player_GetLinkTargetIndex(p));
            if (idx == linkIdx) {
                fn_80251AEC(p, 3);
            }
        }
    }
    fn_802808E8(p, lbl_80540378);
    fn_8027EB04(p);
    fn_8027EEB4(p);
    fn_80261480(p);
    fn_80268B3C(p);
}

void fn_802857C8(char* p) {
    if (S32(p, 0x1248) == 3) {
        U8(p, 0x3f8) = U8(p, 0x437);
        U8(p, 0x3f9) = U8(p, 0x438);
    }
    U8(p, 0x458) = 0;
}

void fn_8027E7E0(char*);
u8 fn_8023EA28(s32);
u8 fn_802300EC(s32);
u8 fn_8023B0F4(s32, void*, s32, f32, s32);
s32 Actor_CreateByID(void*, u32, u32, void*, u32, s32, s32);
void fn_802857F0(char* p) {
    f32 zero = 0.0f;
    if (F32(p, 0x10) > zero && !U8(p, 0x434)) {
        F32(p, 0x10) = zero;
    }
    u16 state = (u16)fn_8022461C(p + 8, S32(p, 0x3b4));
    if (state == 3 || state == 0xe || state == 0x3a) {
        fn_8013CC50(S32(p, 0x3b4), p + 8, 0x503, 1, 1, 0, 0, 1, lbl_8054036C);
        S32(p, 0x3b4) = 0;
        F32(p, 8) = F32(p, 0x2c4);
        F32(p, 0xc) = F32(p, 0x2c8);
        F32(p, 0x10) = F32(p, 0x2cc);
        fn_8013CC50(S32(p, 0x3b4), p + 8, 0x503, 1, 1, 0, 0, 1, lbl_8054036C);
    }
    fn_8027E7E0(p);
    fn_80268B3C(p);
    for (s32 i = 0; i < 4; i++) {
        if (i != S32(p, 4) && (U8(lbl_8053AAF8, 0x82) & (u8)(1 << i)) && !fn_8023EA28(i) && fn_802300EC(i) && fn_8023B0F4(i, p + 0x4c0, S32(p, 0x3b4), lbl_8054036C, 0) && S32(p, 0xd60) < 0) {
            S32(p, 0xd60) = i;
            if (fn_80251AEC(p, 0)) {
                S32(p, 0x11ec) = i;
                void* mgr = fn_801F856C();
                Actor_CreateByID(mgr, 0x54534e4f, S32(p, 0x3b4), p + 8, i & 3, -1, S32(p, 4));
                return;
            }
            S32(p, 0xd60) = -1;
        }
    }
}

void fn_802859B8(char* p) { U8(p, 0x458) = 0; }

void fn_802859C4(char* p) {
    if (lbl_80540360 != F32(p, 0x10) && U8(p, 0x434) == 0) {
        F32(p, 0x10) = lbl_80540360;
    }
    if (!fn_80275D9C(p)) {
        if (Player_IsLinked(p)) {
            if (fn_802486A0(p) == 4 && fn_80248778(p) != fn_80240888(p)) {
                if (fn_80246F28(p) != lbl_80540360) {
                    fn_80251AEC(p, 2);
                }
            } else {
                if (fn_8022C5EC(Player_GetLinkTargetIndex(p), 0x40)) {
                    fn_80251AEC(p, 3);
                } else {
                    if (fn_8022C6AC(S32(p, 4)) != lbl_80540360) {
                        fn_80251AEC(p, 3);
                    } else {
                        if (fn_8022C6AC(Player_GetLinkTargetIndex(p)) == lbl_80540360 && fn_8022CFE8(S32(p, 4)) > lbl_80540360) {
                            s32 target = S32(p, 0x3b4);
                            s32 linkIdx = fn_8023DE58(Player_GetLinkTargetIndex(p));
                            if (linkIdx == target) {
                                fn_80251AEC(p, 3);
                            }
                        }
                    }
                }
            }
        } else {
            if (fn_802486A0(p) == 3) {
                if (fn_80246F28(p) != lbl_80540360) {
                    if (fn_80246B10(p, 0x40)) {
                        fn_80251AEC(p, 3);
                    } else {
                        fn_80251AEC(p, 2);
                    }
                } else if (fn_8022CFE8(S32(p, 4)) != lbl_80540360) {
                    fn_80251AEC(p, 3);
                }
            } else if (fn_80246F28(p) != lbl_80540360) {
                fn_80251AEC(p, 2);
            }
        }
    }
    if (fn_802486A0(p) == 4 && fn_80248778(p) != fn_80240888(p)) {
        fn_8027E7E0(p);
    } else {
        fn_8027EB04(p);
        if (U8(p, 0x434) != 0) {
            fn_80251AEC(p, 2);
        }
    }
    fn_80261480(p);
    fn_80268B3C(p);
}

void fn_80285C28(char* p) { U8(p, 0x458) = 0; }
}
