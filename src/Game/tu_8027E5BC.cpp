#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define S32(p, o) (*(s32*)((char*)(p) + (o)))
#define F32(p, o) (*(f32*)((char*)(p) + (o)))
#define PTR(p, o) (*(void**)((char*)(p) + (o)))
#define VEC(p, o) (*(JGeometry::TVec3<f32>*)((char*)(p) + (o)))

#pragma auto_inline off

extern "C" {
extern const f32 lbl_80540360, lbl_80540368, lbl_8054036C;
extern const f32 lbl_8054037C, lbl_80540384, lbl_80540398;
extern const f32 lbl_805403A4, lbl_805403AC, lbl_805403B4, lbl_80540404;
extern const f32 lbl_80540380;
extern const f32 lbl_805403B0, lbl_805403FC, lbl_80540400;
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
bool Player_IsLinked(char*);
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

void fn_8027F16C(char* p) {
    if (!Player_IsLinked(p) && !fn_80245FEC(p) && U8(p, 0x1201) != 1)
        fn_802416FC(p, 0x180);
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
        if (*((u8*)fn_802D6A9C() + 0x10000 + area + 0x31df) != 0) {
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

void fn_80283CEC(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

void fn_80283D00(char* p) { fn_8027EB04(p); }

void fn_80283D20(char* p) { U8(p, 0x458) = 0; }

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
    VEC(p, 8).add(VEC(p, 8), VEC(p, 0x344));
    F32(p, 0x34c) = F32(p, 0x34c) - lbl_80540398;
    if (F32(p, 0x34c) < lbl_80540404) F32(p, 0x34c) = lbl_80540404;
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

void fn_8028537C(char* p) { U8(p, 0x458) = 0; }

void fn_80285388(void) {
}

void fn_80285668(char* p) {
    if (S32(p, 0x1248) == 2) {
        U8(p, 0x3f8) = U8(p, 0x437);
        U8(p, 0x3f9) = U8(p, 0x438);
    }
    U8(p, 0x458) = 0;
}

void fn_802857C8(char* p) {
    if (S32(p, 0x1248) == 3) {
        U8(p, 0x3f8) = U8(p, 0x437);
        U8(p, 0x3f9) = U8(p, 0x438);
    }
    U8(p, 0x458) = 0;
}

void fn_802859B8(char* p) { U8(p, 0x458) = 0; }

void fn_80285C28(char* p) { U8(p, 0x458) = 0; }
}
