// Player-state methods, 0x8028FBA0-0x802957CC.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JParticle/JPAEmitter.h"

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define U32(p, o) (*(u32*)((char*)(p) + (o)))
#define S32(p, o) (*(s32*)((char*)(p) + (o)))
#define F32(p, o) (*(f32*)((char*)(p) + (o)))
#define PTR(p, o) (*(char**)((char*)(p) + (o)))
#define VEC(p, o) (*(JGeometry::TVec3<f32>*)((char*)(p) + (o)))

#pragma auto_inline off

class Actor;

struct StageRec {
    u8 type;
    u8 pad1[9];
};

struct StageTbl {
    u8 pad0[0x60];
    StageRec recs[1];
};

extern "C" {
extern char* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern void* lbl_8053AC98;
extern const f32 lbl_805405A8;
extern const f32 lbl_805405AC;
extern const f32 lbl_805405B0;
extern const f32 lbl_805405B4;
extern const f32 lbl_805405B8;
extern const f32 lbl_805405BC;
extern const f32 lbl_805405C0;
extern const f32 lbl_805405C4;
extern const f32 lbl_805405C8;
extern const f32 lbl_805405CC;
extern const f32 lbl_805405D0;
extern const f32 lbl_805405D4;
extern const f32 lbl_805405D8;
extern const f32 lbl_805405DC;
extern const f32 lbl_805405E0;
extern const f32 lbl_805405E4;
extern const f32 lbl_805405E8;
extern const f32 lbl_805405EC;
extern const f32 lbl_805405F0;
extern const f32 lbl_805405F4;
extern const f32 lbl_805405F8;
extern const f32 lbl_805405FC;
extern const f32 lbl_80540600;
extern const f32 lbl_8054060C;
extern const f32 lbl_80540614;
extern const f32 lbl_80540618;
extern const f32 lbl_8054061C;
extern const f32 lbl_80540620;
extern const f32 lbl_80540644;
extern const f32 lbl_8054064C;
extern const f32 lbl_80540650;
extern const f32 lbl_80540654;
extern const f64 lbl_80540630;
extern const f64 lbl_80540638;

void* fn_8013CC50(s32, void*, s32, s32, s32, s32, void*, s32, f32);
void fn_801F349C(Actor*, u32, f32*);
Actor* fn_801F666C(void*, s32);
void* fn_801F856C(void);
void fn_80238244(s32);
BOOL fn_80240670(char*);
void fn_80241454(char*, u8);
int fn_80241E28(char*, s32, JGeometry::TVec3<f32>*);
BOOL fn_80240D64(char*);
void fn_80248604(char*);
s32 fn_8024189C(char*);
void fn_80248004(char*, s32, s32);
s32 fn_802486A0(const char*);
void fn_8024BAEC(char*);
s32 fn_8024EFA0(char*, u8);
void fn_8024F0E8(char*, s32);
bool fn_80251AEC(char*, s32);
int fn_8025F684(char*);
void fn_803037D4(s32, s32);
bool Player_IsLinked(char*);
bool fn_80290070(char*, s32, const JGeometry::TVec3<f32>*, const JGeometry::TVec3<f32>*, s32);
void* fn_802D6A9C(void);
void fn_80301D54(s32);
bool fn_80303750(s32);
bool fn_80301CD0(char*);
void fn_8030BD3C(void*, s32);
void fn_803037D4(s32, s32);
void fn_8045815C(void*, s32);
void fn_8029E508(void*, void*, s32, s32);
extern "C" void fn_8030C210(void* cam, JGeometry::TVec3<f32>* pos);
extern u8* lbl_8053AB10;
extern f32 lbl_80540640;
s32 fn_80241544(char*);

bool fn_8028FBA0(char* p) {
    JGeometry::TVec3<f32> position;
    position.x = F32(p, 0xcb0);
    position.y = F32(p, 0xcb4);
    position.z = F32(p, 0xcb8);
    if (U8(p, 0xcf2) == 0) {
        position.y -= lbl_805405A8;
    }
    if (fn_80290070(p, 0, &VEC(p, 0x8), &position, 5)) {
        U8(p, 0xbdc) = 0;
        return true;
    }
    return false;
}

bool fn_8028FC2C(char* p) {
    if (S32(p, 0xd28) < 8) {
        return fn_80290070(p, 0, &VEC(p, 0x8), &VEC(p, 0xcb0), 0x27);
    }
    s32 iVar4 = S32(fn_802D6A9C(), 0x4);
    s32 iVar5 = S32(fn_802D6A9C(), 0x8);
    s32 iVar6 = S32(fn_802D6A9C(), 0x14);
    void* iVar7 = fn_802D6A9C();
    StageTbl* tbl = (StageTbl*)(iVar6 + (s32)fn_802D6A9C());
    s32 cVar1 = tbl->recs[S32(iVar7, 0x18)].type;
    s32 iVar2 = S32(p, 0x3b4) - 7;
    if (iVar4 == 0 && iVar5 == 0) {
        JGeometry::TVec3<f32> v(lbl_805405AC, lbl_805405B0, lbl_805405B4);
        return fn_80290070(p, 0, &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 1 && iVar5 == 0 && cVar1 == 3) {
        JGeometry::TVec3<f32> v(lbl_805405B8, lbl_805405BC, lbl_805405B4);
        return fn_80290070(p, 0, &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 1 && iVar5 == 0 && cVar1 == 5 && iVar2 == 5) {
        JGeometry::TVec3<f32> v(lbl_805405C0, lbl_805405C4, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 1 && iVar5 == 0 && cVar1 == 5 && iVar2 == 6) {
        JGeometry::TVec3<f32> v(lbl_805405C8, lbl_805405CC, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 1 && iVar5 == 0 && cVar1 == 5 && iVar2 == 7) {
        JGeometry::TVec3<f32> v(lbl_805405D0, lbl_805405D4, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 1 && iVar5 == 0 && cVar1 == 6) {
        JGeometry::TVec3<f32> v(lbl_805405D8, lbl_805405DC, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 1 && iVar5 == 3) {
        JGeometry::TVec3<f32> v(lbl_805405E0, lbl_805405E4, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 2 && iVar5 == 0) {
        JGeometry::TVec3<f32> v(lbl_805405E8, lbl_805405E4, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 3 && iVar5 == 0) {
        JGeometry::TVec3<f32> v(lbl_805405EC, lbl_805405CC, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 5 && iVar5 == 0) {
        return fn_80290070(p, 0, &VEC(p, 0x8), &VEC(p, 0xcb0), 0x27);
    } else if (iVar4 == 6 && iVar5 == 0 && cVar1 == 3) {
        JGeometry::TVec3<f32> v(lbl_805405F0, lbl_805405F4, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 6 && iVar5 == 0 && cVar1 == 4) {
        JGeometry::TVec3<f32> v(lbl_805405F0, lbl_805405F4, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    } else if (iVar4 == 6 && iVar5 == 0 && cVar1 == 5) {
        JGeometry::TVec3<f32> v(lbl_805405F8, lbl_805405FC, lbl_805405B4);
        return fn_80290070(p, S32(p, 0xd28), &VEC(p, 0x8), &v, 0x27);
    }
    return false;
}

int fn_802DE93C(void);
extern "C" int fn_802DE93C(void);
extern "C" u8 fn_80240DAC(char*);
extern "C" u8 fn_80270A8C(char*);
extern "C" u8 fn_8025F448(char*);
extern "C" s32 fn_80240628(char*);
extern "C" u8 fn_8022C8EC(s32);
extern "C" u16 fn_8022461C(s32, s32);
extern "C" u8 fn_802265DC(f32*, int, int);
extern "C" bool fn_802684A4(char*, f32*, s32);
extern "C" void fn_80252BAC(char*, JGeometry::TVec3<f32>*);
extern "C" s32 Player_GetLinkTargetIndex(char*);
extern "C" u8 fn_8022D75C(s32);
extern "C" u8 fn_80240818(char*);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_8022D36C(s32);
extern "C" u8 fn_8025F590(char*);
extern "C" s32 fn_8025F55C(char*);
extern "C" void fn_8023105C(s32);
extern "C" void fn_8025FF70(char*);
extern "C" void fn_803049F0(s32, s32);
extern "C" void fn_80304B00(s32, s32);
extern "C" u8 fn_8025FCC8(char*);
extern "C" u8 fn_8022F478(s32);
extern "C" void fn_803020C8(s32, s32, s32, u8);
extern "C" void fn_80230E1C(s32, s32);
extern "C" void fn_80248FF0(char*);

inline void fn_80290070_warpTo(char* p, const JGeometry::TVec3<f32>* b) {
    S32(p, 0xce0) = S32(p, 0x3b4);
    VEC(p, 0xcc8) = VEC(p, 0x8);
    S32(p, 0x3b4) = 0;
    S32(p, 0xce4) = 0;
    VEC(p, 0x8) = *b;
    VEC(p, 0xcd4) = VEC(p, 0x8);
    VEC(p, 0xcbc) = VEC(p, 0xcd4);
    F32(p, 0x10) = lbl_805405B4;
}

// Inlined copies of fn_80290E90 / fn_80290D58, used by fn_80290070.
inline void fn_80290E90_inline(char* p) {
    if ((u8)fn_80240670(p) == 0) {
        fn_80301D54(S32(p, 0x4));
    }
    U8(p, 0x400) = 0;
    if (U8(lbl_8053AAF8, 0x7e) == 0 && (u8)fn_80240670(p) == 0) {
        if (S32(p, 0xce4) < 8) {
            fn_8045815C(lbl_8053AF80, 0);
        } else if (S32(p, 0xce4) == 8) {
            fn_8045815C(lbl_8053AF80, 1);
        }
    }
}

inline void fn_80290D58_inline(char* p) {
    if (!(u8)fn_80241E28(p, S32(p, 0xce0), &VEC(p, 0xcc8))) {
        VEC(p, 0xcbc) = VEC(p, 0x8);
        VEC(p, 0xd1c) = VEC(p, 0xcbc);
    }
    if (S32(p, 0xcf4) == 0x14 && S32(p, 0x3b4) >= 8) {
        S32(p, 0xbd8) = 0x258;
        U8(p, 0xbdc) = 1;
    }
    if ((u8)fn_80240D64(p)) {
        S32(p, 0x11f0) = 5;
    }
    U8(p, 0xce8) = 0;
    S32(p, 0xcf8) = S32(p, 0xcf4);
    S32(p, 0xcf4) = 0x29;
    S32(p, 0x468) = 0x3c;
    U8(p, 0xced) = 0;
    fn_80241454(p, 1);
    U8(p, 0x1216) = 0;
    fn_8024BAEC(p);
    fn_8030BD3C((void*)S32(p, 0xbec), S32(p, 0x4));
    if (fn_802486A0(p) != 4 && fn_802486A0(p) != 5) {
        fn_80248004(p, 5, 1);
    }
    fn_80248604(p);
    U8(p, 0xceb) = 0;
    U8(p, 0x400) = 0;
    U8(p, 0xcec) = 0;
}

#pragma opt_common_subs off
bool fn_80290070(char* p, s32 mode, const JGeometry::TVec3<f32>* a, const JGeometry::TVec3<f32>* b, s32 state) {
    JGeometry::TVec3<f32> dest;
    JGeometry::TVec3<f32> up;
    JGeometry::TVec3<f32> side;
    if (state == 0xc) {
        if ((u8)fn_802DE93C() || S32(p, 0x3b4) >= 8) {
            state = 0x26;
        }
    }
    dest = *b;
    if (state == 0x24) {
        if (U8(p, 0xce8) == 1 && !fn_80240DAC(p)) {
            return false;
        }
    } else if (U8(p, 0xce8) == 1) {
        return false;
    }
    if (U8(p, 0xcee) == 1) {
        return false;
    }
    if (U8(p, 0x1216) == 1) {
        return false;
    }
    if (S32(p, 0x1238) > 0) {
        return false;
    }
    if (state == 0x21 && S32(p, 0x3b4) >= 8) {
        fn_80290070_warpTo(p, b);
        fn_8030BD3C((void*)S32(p, 0xbec), S32(p, 0x4));
        fn_80290E90_inline(p);
        fn_80290D58_inline(p);
        return true;
    }
    if (fn_80270A8C(p)) {
        return false;
    }
    if (fn_8024189C(p) <= 0) {
        return false;
    }
    if (fn_8025F448(p)) {
        return false;
    }
    if (fn_8022C8EC(fn_80240628(p)) && mode >= 8 && fn_80303750(fn_80240628(p))) {
        return false;
    }
    U8(p, 0xcf1) = 0;
    if (state == 0x22) {
        if (mode != S32(p, 0x3b4)) {
            return false;
        }
        u16 kind = fn_8022461C((s32)b, mode);
        if (fn_802265DC((f32*)b, mode, 1) || kind == 3 || kind == 0xe || fn_802684A4(p, (f32*)b, mode)) {
            if (mode < 8) {
                F32(p, 0x8) = F32(p, 0x2c4);
                F32(p, 0xc) = F32(p, 0x2c8);
                F32(p, 0x10) = F32(p, 0x2cc);
            } else {
                F32(p, 0x8) = F32(p, 0xcbc);
                F32(p, 0xc) = F32(p, 0xcc0);
                F32(p, 0x10) = F32(p, 0xcc4);
            }
        } else {
            F32(p, 0x8) = b->x;
            F32(p, 0xc) = b->y;
            F32(p, 0x10) = b->z;
        }
        F32(p, 0x2c) = F32(p, 0x8);
        F32(p, 0x30) = F32(p, 0xc);
        F32(p, 0x34) = F32(p, 0x10);
        S32(p, 0x464) = 0x3c;
        return true;
    }
    if (state == 4 || (u32)(state - 7) <= 2 || state == 0x20 || state == 0x24) {
        if (!Player_IsLinked(p) && U8(p, 0x1216) == 1) {
            return false;
        }
        if (Player_IsLinked(p) && S32(p, 0x1238) > 0) {
            return false;
        }
        if (fn_80251AEC(p, 0x1e)) {
            const JGeometry::TVec3<f32>& d = ((JGeometry::TVec3<f32>&)*a) - VEC(p, 0x8);
            fn_80252BAC(p, (JGeometry::TVec3<f32>*)&d);
            if ((u8)fn_80240670(p)) {
                mode = S32(p, 0x3b4);
                state = 9;
                dest.x = F32(p, 0xd1c);
                dest.y = F32(p, 0xd20);
                dest.z = F32(p, 0xd24);
            }
        } else {
            return false;
        }
    } else if ((u32)(state - 0xc) <= 1 || state == 0x26) {
        if ((!Player_IsLinked(p) && U8(p, 0x1216) == 1) ||
            (Player_IsLinked(p) && !fn_8022D75C(Player_GetLinkTargetIndex(p)) && S32(p, 0x1238) > 0)) {
            return false;
        }
        if (mode != S32(p, 0x3b4)) {
            return false;
        }
        if (!fn_80251AEC(p, 0x32)) {
            return false;
        }
    } else if (state == 5) {
        if (fn_80251AEC(p, 0x20)) {
            U8(p, 0xcf1) = U8(p, 0xcf0);
            u16 kind = fn_8022461C((s32)&dest, mode);
            if (kind == 0 || (u16)(kind - 2) <= 1 || kind == 0x21) {
                U8(p, 0xcf0) = 0;
            } else {
                U8(p, 0xcf0) = 1;
            }
        } else {
            return false;
        }
    } else if (state == 6 || state == 0xb || state == 0x14 || state == 0x1f) {
        if (mode >= 8) {
            if (fn_80251AEC(p, 0x24)) {
                VEC(p, 0x8) = *a;
            } else {
                return false;
            }
        } else {
            if (fn_80251AEC(p, 0x22)) {
                VEC(p, 0x8) = *a;
            } else {
                return false;
            }
        }
    } else if (state == 0xe || state == 0x25) {
        if (fn_80251AEC(p, 0x26)) {
            VEC(p, 0x8) = *a;
        } else {
            return false;
        }
    } else if (state == 0xf) {
        if (!fn_80251AEC(p, 0x28)) {
            return false;
        }
    } else if (state == 0x27) {
        if (!fn_80251AEC(p, 0x30)) {
            return false;
        }
    } else if (state == 0xa) {
        if (S32(p, 0x3b4) == 8) {
            if (fn_80251AEC(p, 0x2a)) {
                U8(p, 0xcf1) = U8(p, 0xcf0);
                u16 kind = fn_8022461C((s32)&dest, mode);
                if (kind == 0 || kind == 2 || kind == 0x21) {
                    U8(p, 0xcf0) = 0;
                } else {
                    U8(p, 0xcf0) = 1;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else if (state == 0x11) {
        if (!fn_80240818(p)) {
            return false;
        }
    } else if (state == 0x13 || state == 0x16) {
        if (!(S32(p, 0x1240) == 0x4d && S32(p, 0x1244) == 0x4d)) {
            if (!fn_80251AEC(p, 0x4d)) {
                return false;
            }
        }
    } else if (state == 0x17 || state == 0x18) {
        if (fn_80251AEC(p, 0x1c)) {
            up.x = 0.0f;
            up.y = a->y - F32(p, 0xc);
            up.z = 0.0f;
            fn_80252BAC(p, &up);
        } else {
            return false;
        }
    } else if (state == 0x1d) {
        if (fn_80251AEC(p, 0x2c)) {
            VEC(p, 0x8) = *a;
        } else {
            return false;
        }
    } else if (state == 0x1e) {
        if (fn_80251AEC(p, 0x2e)) {
            VEC(p, 0x8) = *a;
        } else {
            return false;
        }
    } else {
        if (fn_80251AEC(p, 0x1c)) {
            side.x = a->x - F32(p, 0x8);
            side.y = 0.0f;
            side.z = 0.0f;
            fn_80252BAC(p, &side);
        } else {
            return false;
        }
    }
    if (state == 0x12) {
        VEC(p, 0xcd4) = *(JGeometry::TVec3<f32>*)fn_8023E724(Player_GetLinkTargetIndex(p));
        S32(p, 0xce4) = fn_8023DE58(Player_GetLinkTargetIndex(p));
    } else {
        VEC(p, 0xcd4) = dest;
        S32(p, 0xce4) = mode;
    }
    S32(p, 0xcf4) = state;
    VEC(p, 0xcc8) = VEC(p, 0x8);
    S32(p, 0xce0) = S32(p, 0x3b4);
    U8(p, 0xce8) = 1;
    if (S32(p, 0xce4) != 8) {
        U8(p, 0xcf2) = 0;
    }
    if (!Player_IsLinked(p)) {
        fn_8022D36C(S32(p, 0x4));
    }
    if (fn_8025F590(p) && S32(p, 0x3b4) == 8 && fn_8023DE58(S32(p, 0xd70)) < 8) {
        fn_8023105C(fn_8025F55C(p));
        fn_8025FF70(p);
    }
    if (S32(p, 0xce4) >= 8 && S32(p, 0xce4) != S32(p, 0x3b4)) {
        fn_803049F0(S32(p, 0x4), S32(p, 0xce4));
        fn_80304B00(S32(p, 0x4), S32(p, 0xce4));
        if (fn_8025F590(p) && !fn_8025FCC8(p) && !fn_8022F478(S32(p, 0xd70))) {
            fn_803049F0(S32(p, 0xd70), S32(p, 0xce4));
            fn_80304B00(S32(p, 0xd70), S32(p, 0xce4));
        }
    }
    state = -1;
    if (!(u8)fn_80240670(p)) {
        if (S32(p, 0xcf4) != 0xc && S32(p, 0xcf4) != 0xd && S32(p, 0xcf4) != 0x26 && S32(p, 0xcf4) != 0x22) {
            if (S32(p, 0xcf4) == 4 || (u32)(S32(p, 0xcf4) - 7) <= 2 || S32(p, 0xcf4) == 0x20 || S32(p, 0xcf4) == 0x24) {
                s32 cur = S32(p, 0x3b4);
                if (cur > 8 && S32(p, 0xce4) > 8) {
                    u8* base = (u8*)fn_802D6A9C() + 0x10000;
                    if (base[cur + 0x31df] != 0) {
                        s32 other = S32(p, 0xce4);
                        base = (u8*)fn_802D6A9C() + 0x10000;
                        if (base[other + 0x31df] != 0 && S32(p, 0xce4) != S32(p, 0x3b4)) {
                            state = 0;
                            goto notify;
                        }
                    }
                }
            }
            if (S32(p, 0xcf4) == 0x1e) {
                state = 2;
            } else if (S32(p, 0xcf4) == 0xf) {
                state = 2;
            } else if (S32(p, 0xcf4) == 0x27) {
                state = 1;
            } else if ((S32(p, 0xcf4) == 6 || S32(p, 0xcf4) == 0xb) && S32(p, 0xce0) > 8) {
                state = 2;
            } else if (S32(p, 0xcf4) == 0x13 || S32(p, 0xcf4) == 0x16) {
                if (S32(p, 0xce4) < 8) {
                    state = 0;
                }
            } else {
                state = 1;
            }
        }
    }
notify:
    if (state >= 0) {
        fn_803020C8(S32(p, 0x4), S32(p, 0xce0), S32(p, 0xce4), (u8)state);
    }
    if (fn_8025F590(p) && !fn_8022F478(S32(p, 0xd70))) {
        if (!fn_8025FCC8(p) && state >= 0) {
            fn_803020C8(S32(p, 0xd70), S32(p, 0xce0), S32(p, 0xce4), (u8)state);
        }
        if (S32(p, 0xce0) >= 8 && S32(p, 0xce4) < 8) {
            fn_80230E1C(S32(p, 0xd70), 0);
        }
    }
    S32(PTR(p, 0xbf0), 0xbc) = 0;
    U8(p, 0x1216) = 0;
    if (S32(p, 0x1244) != 0x1c) {
        S32(p, 0x48c) = 0;
        S32(p, 0xbc0) = 0;
    }
    if (S32(p, 0xcf4) == 0x1f) {
        fn_80248004(p, 5, 1);
    }
    fn_80248FF0(p);
    return true;
}
#pragma opt_common_subs reset
void fn_80290D58(char* p) {
    if (!(u8)fn_80241E28(p, S32(p, 0xce0), &VEC(p, 0xcc8))) {
        VEC(p, 0xcbc) = VEC(p, 0x8);
        VEC(p, 0xd1c) = VEC(p, 0xcbc);
    }
    if (S32(p, 0xcf4) == 0x14 && S32(p, 0x3b4) >= 8) {
        S32(p, 0xbd8) = 0x258;
        U8(p, 0xbdc) = 1;
    }
    if ((u8)fn_80240D64(p)) {
        S32(p, 0x11f0) = 5;
    }
    U8(p, 0xce8) = 0;
    S32(p, 0xcf8) = S32(p, 0xcf4);
    S32(p, 0xcf4) = 0x29;
    S32(p, 0x468) = 0x3c;
    U8(p, 0xced) = 0;
    fn_80241454(p, 1);
    U8(p, 0x1216) = 0;
    fn_8024BAEC(p);
    fn_8030BD3C((void*)S32(p, 0xbec), S32(p, 0x4));
    if (fn_802486A0(p) != 4 && fn_802486A0(p) != 5) {
        fn_80248004(p, 5, 1);
    }
    fn_80248604(p);
    U8(p, 0xceb) = 0;
    U8(p, 0x400) = 0;
    U8(p, 0xcec) = 0;
}

void fn_80290E90(char* p) {
    if ((u8)fn_80240670(p) == 0) {
        fn_80301D54(S32(p, 0x4));
    }
    U8(p, 0x400) = 0;
    if (U8(lbl_8053AAF8, 0x7e) == 0 && (u8)fn_80240670(p) == 0) {
        if (S32(p, 0xce4) < 8) {
            fn_8045815C(lbl_8053AF80, 0);
        } else if (S32(p, 0xce4) == 8) {
            fn_8045815C(lbl_8053AF80, 1);
        }
    }
}

void fn_80290F20(char* p) {
    char* emitter = PTR(p, 0x132c);
    if (emitter != NULL) {
        U32(emitter, 0xf4) |= 1;
        U32(emitter, 0x24) = 1;
        PTR(p, 0x132c) = NULL;
    }
    emitter = PTR(p, 0x135c);
    if (emitter != NULL) {
        U32(emitter, 0xf4) |= 1;
        U32(emitter, 0x24) = 1;
        PTR(p, 0x135c) = NULL;
    }
    if (fn_802486A0(p) != 4 && Player_IsLinked(p)) {
        fn_80238244(S32(p, 0x4));
    }
}

bool fn_802DE9A0(void);
s32 Player_GetLinkTargetIndex(char*);
s32 fn_80237774(s32);
void fn_80272160(char*, s32, char*, s32);
void fn_8027EDDC(char*);
void fn_8013CB44(void*, void*, s32, s32, s32);
extern s32 lbl_8046C228[];
extern const f32 lbl_80540604;
extern const f32 lbl_80540608;
extern const f32 lbl_80540610;
extern "C++" void JPAGetXYZRotateMtx(s16, s16, s16, f32 (*)[4]);
#pragma opt_lifetimes off
void fn_80290FC0(char* p) {
    s32 r;
    s32 mode;

    if (U8(p, 0x3fc) == 0x28) {
        if (S32(p, 0xcf4) == 0xc && fn_802DE9A0()) {
            fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x2aa, 0, 1, 0, 0, 1, lbl_80540600);
            fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x2a9, -1, 0, 0, 0, 1, lbl_80540600);
        } else if (S32(p, 0xcf4) == 0xd) {
            fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x45f, 0, 1, 0, 0, 1, lbl_80540600);
            fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x45e, -1, 0, 0, 0, 1, lbl_80540600);
            switch (S32(p, 0x4)) {
            case 0:
                fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x16b, 0, 1, 0, 0, 1, lbl_80540600);
                break;
            case 1:
                fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x16d, 0, 1, 0, 0, 1, lbl_80540600);
                break;
            case 2:
                fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x16a, 0, 1, 0, 0, 1, lbl_80540600);
                break;
            case 3:
                fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x16c, 0, 1, 0, 0, 1, lbl_80540600);
                break;
            }
            fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x16e, 0, 1, 0, 0, 1, lbl_80540600);
            fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x16f, 0, 1, 0, 0, 1, lbl_80540600);
        }
    }
    if (S32(p, 0xcf4) == 0xd) {
        if (U8(p, 0x3fc) < 0x82) {
            U8(p, 0x3fc)++;
            return;
        }
        if (!(u8)fn_80240670(p)) {
            fn_80272160(p, 2, p + 8, 0x11);
        }
        if (Player_IsLinked(p)) {
            r = fn_80237774(Player_GetLinkTargetIndex(p));
        } else {
            r = fn_8024189C(p);
        }
        mode = 0;
        if (r <= 0) {
            mode = 0x33;
        }
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, mode)) {
            S32(p, 0x3b4) = S32(p, 0xce4);
            VEC(p, 0x8) = VEC(p, 0xcd4);
            F32(p, 0x10) = lbl_805405B4;
        }
        return;
    }
    if (U8(p, 0x3fc) >= 0x3a) {
        if (U8(p, 0x3fb) == 0) {
            fn_8024F0E8(p, 0x1000a);
            if (S32(p, 0xcf4) == 0xc && fn_802DE9A0()) {
                fn_8024F0E8(p, 0x20031);
            }
            U8(p, 0x3fb) = 1;
            if (S32(p, 0xcf4) == 0xc && fn_802DE9A0() && PTR(p, 0x135c) == NULL) {
                switch (S32(p, 0x3dc)) {
                case 0:
                    PTR(p, 0x135c) = (char*)fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x248, 0, 0, 0, 0, 1, lbl_80540600);
                    break;
                case 1:
                    PTR(p, 0x135c) = (char*)fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x247, 0, 0, 0, 0, 1, lbl_80540600);
                    break;
                case 2:
                    PTR(p, 0x135c) = (char*)fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x246, 0, -1, 0, 0, 1, lbl_80540600);
                    break;
                case 3:
                    PTR(p, 0x135c) = (char*)fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x249, 0, 0, 0, 0, 1, lbl_80540600);
                    break;
                }
            }
            if (S32(p, 0xcf4) == 0xc && fn_802DE9A0() && PTR(p, 0x132c) == NULL) {
                switch (S32(p, 0x3dc)) {
                case 0:
                    PTR(p, 0x132c) = (char*)fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x244, 0, 0, 0, p + 0x1330, 1, lbl_80540600);
                    break;
                case 1:
                    PTR(p, 0x132c) = (char*)fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x243, 0, 0, 0, p + 0x1330, 1, lbl_80540600);
                    break;
                case 2:
                    PTR(p, 0x132c) = (char*)fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x242, 0, -1, 0, p + 0x1330, 1, lbl_80540600);
                    break;
                case 3:
                    PTR(p, 0x132c) = (char*)fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x245, 0, 0, 0, p + 0x1330, 1, lbl_80540600);
                    break;
                }
            }
            JGeometry::TVec3<f32> v = (VEC(p, 0xcd4) - VEC(p, 0x8)) * lbl_80540604;
            F32(p, 0x344) = v.x;
            F32(p, 0x348) = v.y;
            F32(p, 0x34c) = lbl_80540608;
        }
        if (U8(p, 0x3fc) < 0x3e) {
            U8(p, 0x3fd) = 0;
        } else if (U8(p, 0x3fc) < 0x42) {
            U8(p, 0x3fd) = 1;
        } else if (U8(p, 0x3fc) < 0x46) {
            U8(p, 0x3fd) = 2;
        } else if (U8(p, 0x3fc) < 0x4a) {
            U8(p, 0x3fd) = 3;
        }
        U8(p, 0x3fc)++;
        VEC(p, 0x8).add(VEC(p, 0x344));
        F32(p, 0x34c) -= lbl_8054060C;
        if (F32(p, 0x34c) < lbl_805405B4 && F32(p, 0x10) <= lbl_805405B4) {
            F32(p, 0x10) = lbl_805405B4;
            if (!(u8)fn_80240670(p) && (S32(p, 0xcf4) == 0xc || S32(p, 0xcf4) == 0xd || S32(p, 0xcf4) == 0x26)) {
                fn_80272160(p, 2, p + 8, 0x11);
            } else {
                fn_80272160(p, 0, p + 8, 0x11);
            }
            if (Player_IsLinked(p)) {
                r = fn_80237774(Player_GetLinkTargetIndex(p));
            } else {
                r = fn_8024189C(p);
            }
            mode = 0;
            if (r <= 0) {
                mode = 0x33;
            }
            U8(p, 0x124d) = 0;
            if (fn_80251AEC(p, mode)) {
                S32(p, 0x3b4) = S32(p, 0xce4);
                VEC(p, 0x8) = VEC(p, 0xcd4);
                F32(p, 0x10) = lbl_805405B4;
            }
        }
        if (PTR(p, 0x135c) != NULL) {
            switch (S32(p, 0x3dc)) {
            case 0:
            case 1:
            case 3:
                fn_8013CB44(PTR(p, 0x135c), p + 0x8, 0, 0, 1);
                break;
            case 2:
                fn_8013CB44(PTR(p, 0x135c), p + 0x8, 0, -1, 1);
                break;
            }
            ((JPABaseEmitter*)PTR(p, 0x135c))->setGlobalRotation(JGeometry::TVec3<s16>((s16)0, (s16)lbl_8046C228[S32(p, 0x3dc)], (s16)0));
        }
        if (PTR(p, 0x132c) != NULL) {
            F32(p, 0x1344) = F32(p, 0x8);
            F32(p, 0x1348) = F32(p, 0xc);
            F32(p, 0x134c) = F32(p, 0x10);
            if (S32(p, 0x3dc) == 2) {
                F32(p, 0x1348) -= lbl_80540610;
            } else if (S32(p, 0x3dc) == 3) {
                F32(p, 0x1348) += lbl_80540610;
            }
            F32(p, 0x1334) = F32(p, 0x1344);
            F32(p, 0x1338) = F32(p, 0x1348);
            F32(p, 0x133c) = F32(p, 0x134c);
            ((JPABaseEmitter*)PTR(p, 0x132c))->setGlobalRotation(JGeometry::TVec3<s16>((s16)0, (s16)lbl_8046C228[S32(p, 0x3dc)], (s16)0));
        }
    } else {
        fn_8027EDDC(p);
    }
}
#pragma opt_lifetimes reset
void fn_8029185C(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x10003);
    if (S32(p, 0xcf4) == 0xd) {
        fn_8024F0E8(p, 0x20067);
        U8(p, 0x3fc) = 0x28;
    } else if (S32(p, 0xcf4) == 0x26) {
        U8(p, 0x3fc) = 0x3a;
    }
    if (fn_802486A0(p) != 4 && fn_802486A0(p) != 5) {
        fn_80248004(p, 5, 1);
    }
    fn_8024BAEC(p);
}

#pragma opt_propagation off
void fn_80291910(char* p) {
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
    }
    if (S32(p, 0xce4) != S32(p, 0xce0) && !(u8)fn_80240670(p) && fn_80303750(S32(p, 0x4))) {
        return;
    }
    if (U8(p, 0x3fc) < 0x3c) {
        return;
    }
    if (U8(p, 0x3fc) == 0x3c) {
        if (S32(p, 0xce0) == 8) {
            JGeometry::TVec3<f32> position;
            position.x = F32(p, 0x8);
            position.y = F32(p, 0xc);
            position.z = F32(p, 0x10);
            position.y += lbl_80540614;
            position.z += lbl_805405A8;
            fn_8013CC50(S32(p, 0x3b4), &position, 0x17d, 1, 0, 0, NULL, 1, lbl_80540600);
            fn_8024F0E8(p, 0x20020);
        }
        fn_8024F0E8(p, 0x2002f);
        fn_8024F0E8(p, 0x20021);
        fn_80241454(p, 1);
    }
    VEC(p, 0x8).add(VEC(p, 0x344));
        F32(p, 0x34c) -= lbl_8054060C;
        if (F32(p, 0x34c) < lbl_80540618) {
            F32(p, 0x34c) = lbl_80540618;
        }
        if (F32(p, 0x34c) < lbl_805405B4 && F32(p, 0x10) <= lbl_805405B4) {
            F32(p, 0x10) = lbl_805405B4;
            U8(p, 0x124d) = 0;
            bool result;
            if (fn_8024189C(p) <= 0) {
                result = fn_80251AEC(p, 0x33);
            } else if (U8(p, 0xcf0) == 1) {
                result = fn_80251AEC(p, 0x3e);
            } else {
                result = fn_80251AEC(p, 0);
            }
            if ((u8)result == 1) {
                S32(p, 0x3dc) = 2;
                S32(p, 0x3e8) = 2;
            }
            return;
        }
    U8(p, 0x3fc)++;
    s32 state = (U8(p, 0x3fc) >> 2) & 3;
    if (state == 0) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    } else if (state == 1) {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    } else if (state == 2) {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    } else {
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
    }
}
#pragma opt_propagation reset
void fn_80291B64(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805405B4;
    F32(p, 0x348) = lbl_805405B4;
    F32(p, 0x34c) = lbl_8054061C;
}

void fn_80291B8C(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) >= 0x3c) {
        F32(p, 0x10) += lbl_8054061C;
        if (F32(p, 0x10) > lbl_80540620) {
            if (S32(p, 0x3b4) < 8) {
                VEC(p, 0xcb0) = VEC(p, 0x8);
            }
            U8(p, 0x124d) = 0;
            if (fn_80251AEC(p, 0x2b)) {
                fn_80241454(p, 0);
                S32(p, 0x3b4) = S32(p, 0xce4);
                VEC(p, 0x8) = VEC(p, 0xcd4);
                F32(p, 0x10) = lbl_805405B4;
                fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
            }
        }
    }
    s32 state = (U8(p, 0x3fc) >> 2) & 3;
    if (state == 0) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    } else if (state == 1) {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    } else if (state == 2) {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    } else {
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
    }
}

void fn_80291CB8(char* p) {
    U8(p, 0x124d) = 1;
    F32(p, 0x10) = lbl_805405B4;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x2002e);
    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
}

void fn_80291D28(char* p) {
    if (!fn_80301CD0(PTR(p, 0x4))) {
        if (S32(p, 0xce4) < 8) {
            if (S32(p, 0x430) > 0) {
                S32(p, 0x430) = S32(p, 0x430) - 1;
            }
            U8(p, 0x3fb) = 3;
            if (S32(p, 0x430) <= 0x5a) {
                if (S32(p, 0x430) == 0x5a) {
                    fn_80241454(p, 1);
                } else if (S32(p, 0x430) > 0x54) {
                    U8(p, 0x3f9) = (0x5a - S32(p, 0x430)) / 2;
                } else {
                    U8(p, 0x3f9) = ((0x54 - S32(p, 0x430)) / 6 & 3) + 3;
                }
            }
            if (S32(p, 0x430) == 0) {
                U8(p, 0x124d) = 0;
                S32(p, 0x44c) = 5;
                fn_80251AEC(p, 0x4a);
            }
        } else if (U8(p, 0x3f8) < 0x3c) {
            U8(p, 0x3f8)++;
        } else {
            U8(p, 0x124d) = 0;
            fn_80251AEC(p, 0);
        }
    }
}

void fn_80291E44(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3f9) = 0;
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
    if (S32(p, 0xce4) < 8) {
        fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x15b, 0, 1, 0, NULL, 1, lbl_80540600);
        fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x15c, -1, 0, 0, NULL, 1, lbl_80540600);
        fn_8024F0E8(p, 0x20041);
        fn_8024F0E8(p, 0x1000f);
        S32(p, 0x430) = 0x5c;
    }
}

extern "C" void Actor_CreateByID(void*, u32, s32, void*, u32, s32, s32);
extern "C" const f64 lbl_80540628;
void fn_80291F10(char* p) {
    U8(p, 0x3f8) = U8(p, 0x3f8) + 1;
    if (U8(p, 0x3f8) == 4 || U8(p, 0x3f8) == 8) {
        u32 room = U32(p, 0x4);
        Actor_CreateByID(fn_801F856C(), 0x50454646, S32(p, 0x3b4), p + 0x8, (room & 3) | 0xc, -1, room);
    }
    u8 t = U8(p, 0x3f8);
    if (t <= 4) {
        U8(p, 0x3f9) = 0;
    } else if (t < 0x13) {
        U8(p, 0x3f9) = 1;
    } else if (t < 0x17) {
        U8(p, 0x3f9) = 2;
    } else if (t < 0x1b) {
        U8(p, 0x3f9) = 3;
    } else if (t < 0x1f) {
        U8(p, 0x3f9) = 4;
    } else if (t < 0x23) {
        U8(p, 0x3f9) = 5;
    } else if (t < 0x27) {
        U8(p, 0x3f9) = 2;
    } else if (t < 0x2b) {
        U8(p, 0x3f9) = 3;
    } else if (t < 0x2f) {
        U8(p, 0x3f9) = 4;
    } else if (t < 0x33) {
        U8(p, 0x3f9) = 5;
    } else if (t < 0x37) {
        U8(p, 0x3f9) = 2;
    } else if (t < 0x3b) {
        U8(p, 0x3f9) = 3;
    } else if (t < 0x3f) {
        U8(p, 0x3f9) = 4;
    } else if (t < 0x43) {
        U8(p, 0x3f9) = 5;
    }
    if (U8(p, 0x3f8) < 0x43) {
        F32(p, 0xc) = F32(p, 0xc) - lbl_80540628;
    } else {
        U8(p, 0x3f8) = 0x43;
        if (!fn_80301CD0(PTR(p, 0x4))) {
            U8(p, 0x124d) = 0;
            if (fn_80251AEC(p, 0x31)) {
                S32(p, 0x3b4) = S32(p, 0xce4);
                VEC(p, 0x8) = VEC(p, 0xcd4);
                fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
            }
        }
    }
}

void fn_80292124(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    S32(p, 0x3dc) = 3;
    S32(p, 0x3e8) = 3;
    if ((u8)fn_80240670(p) == 0 && S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
}

void fn_80292198(char* p) {
  U8(p, 0x3f8) = U8(p, 0x3f8) + 1;
  if (U8(p, 0x3f8) >= 0x18) {
    U8(p, 0x3f8) = 0;
  }
  U8(p, 0x3f9) = U8(p, 0x3f8) / 6;
  if (U8(p, 0x3fc) == 2) {
    fn_80241454(p, 1);
  }
  if (U8(p, 0x3fc) < 0x3c) {
    U8(p, 0x3fc) = U8(p, 0x3fc) + 1;
  }
  if (S32(p, 0xce4) != S32(p, 0xce0) && (u8)fn_80240670(p) == 0 && fn_80303750(S32(p, 0x4))) {
    return;
  }
  if (U8(p, 0x3fc) >= 0x3c) {
    if (U8(p, 0x3fb) == 0) {
      if (U8(p, 0x400) != 0) {
        U8(p, 0x400) = U8(p, 0x400) - 1;
      } else {
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x4a) && S32(p, 0xce4) >= 8) {
          fn_803037D4(S32(p, 0x4), 0xd);
        }
      }
    } else {
      U8(p, 0x3fb) = 0;
      U8(p, 0x400) = 8;
    }
  }
}

void fn_802922D0(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fb) = 1;
    U8(p, 0x3f9) = 0;
}

void fn_802922EC(char* p) {
  U8(p, 0x3f8) = U8(p, 0x3f8) + 1;
  if (U8(p, 0x3f8) < 0x7) {
    U8(p, 0x3f9) = 4;
  } else if (U8(p, 0x3f8) < 0xd) {
    U8(p, 0x3f9) = 5;
  } else if (U8(p, 0x3f8) < 0x13) {
    U8(p, 0x3f9) = 6;
  } else if (U8(p, 0x3f8) < 0x22) {
    U8(p, 0x3f9) = 7;
  } else if (U8(p, 0x3f8) < 0x28) {
    U8(p, 0x3f9) = 4;
  } else if (U8(p, 0x3f8) < 0x2e) {
    U8(p, 0x3f9) = 5;
  } else if (U8(p, 0x3f8) < 0x34) {
    U8(p, 0x3f9) = 6;
  } else if (U8(p, 0x3f8) < 0x43) {
    U8(p, 0x3f9) = 7;
  }
  if (U8(p, 0x3f8) < 0x43) {
    F32(p, 0xc) = F32(p, 0xc) - lbl_80540630;
  } else {
    U8(p, 0x124d) = 0;
    if (fn_80251AEC(p, 0x29)) {
      fn_80241454(p, 0);
      if (S32(p, 0x3b4) < 8) {
        VEC(p, 0xcb0) = VEC(p, 0x8);
      }
      S32(p, 0x3b4) = S32(p, 0xce4);
      VEC(p, 0x8) = VEC(p, 0xcd4);
      fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
    }
  }
}

void fn_80292454(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    S32(p, 0x3dc) = 3;
    S32(p, 0x3e8) = 3;
    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
}

void fn_802924AC(char* p) {
    U8(p, 0x3f8)++;
    if (U8(p, 0x3f8) >= 0x18) {
        U8(p, 0x3f8) = 0;
    }
    U8(p, 0x3f9) = U8(p, 0x3f8) / 6;
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
    }
    if ((S32(p, 0xce4) == S32(p, 0xce0) || (u8)fn_80240670(p) || !(u8)fn_80303750(S32(p, 0x4))) && U8(p, 0x3fc) >= 0x3c) {
        if (U8(p, 0x3fc) >= 0x5c) {
            U8(p, 0x124d) = 0;
            if ((u8)fn_80251AEC(p, 0x4b)) {
                if (S32(p, 0xce4) >= 8) {
                    fn_803037D4(S32(p, 0x4), 0xd);
                } else {
                    return;
                }
            }
        } else {
            F32(p, 0xc) = F32(p, 0xc) + lbl_80540638;
            U8(p, 0x3fc)++;
        }
    }
}

void fn_802925C4(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
}

void fn_802925E4(char* p) {
  if (U8(p, 0x3f8) < 0x8) {
    U8(p, 0x3f9) = 0;
  } else if (U8(p, 0x3f8) < 0xe) {
    U8(p, 0x3f9) = 1;
  } else if (U8(p, 0x3f8) < 0x14) {
    U8(p, 0x3f9) = 2;
  } else if (U8(p, 0x3f8) < 0x1a) {
    U8(p, 0x3f9) = 3;
  } else if (U8(p, 0x3f8) < 0x1e) {
    U8(p, 0x3f9) = 4;
  } else if (U8(p, 0x3f8) < 0x22) {
    U8(p, 0x3f9) = 5;
  } else if (U8(p, 0x3f8) < 0x26) {
    U8(p, 0x3f9) = 6;
  } else if (U8(p, 0x3f8) < 0x2a) {
    U8(p, 0x3f9) = 7;
  } else if (U8(p, 0x3f8) < 0x2e) {
    U8(p, 0x3f9) = 8;
  } else if (U8(p, 0x3f8) < 0x30) {
    U8(p, 0x3f9) = 9;
  } else if (U8(p, 0x3f8) < 0x32) {
    U8(p, 0x3f9) = 10;
  } else {
    U8(p, 0x3f9) = 0xb;
    U8(p, 0x124d) = 0;
    if (fn_80251AEC(p, 0x27)) {
      fn_8013CC50(S32(p, 0x3b4), p + 8, 0x15b, 0, 1, 0, 0, 1, lbl_80540600);
      fn_8013CC50(S32(p, 0x3b4), p + 8, 0x15c, -1, 0, 0, 0, 1, lbl_80540600);
      if (S32(p, 0x3b4) < 8) {
        VEC(p, 0xcb0) = VEC(p, 0x8);
      }
      S32(p, 0x3b4) = S32(p, 0xce4);
      VEC(p, 0x8) = VEC(p, 0xcd4);
      fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
    }
  }
  U8(p, 0x3f8)++;
}

void fn_802927B0(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fb) = 0;
    fn_8024F0E8(p, 0x20060);
    fn_8013CC50(S32(p, 0x3b4), p + 0x8, 0x547, -1, 0, 0, NULL, 1, lbl_80540600);
}

void fn_80292820(char* p) {
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
    }
    if (S32(p, 0xce4) == S32(p, 0xce0) || (u8)fn_80240670(p) || !(u8)fn_80303750(S32(p, 0x4))) {
        if (U8(p, 0x3fc) >= 0x3c) {
            U8(p, 0x124d) = 0;
            bool r;
            if (fn_8024189C(p) <= 0) {
                r = fn_80251AEC(p, 0x33);
            } else if (U8(p, 0xcf0) == 1) {
                r = fn_80251AEC(p, 0x3e);
            } else if ((u8)fn_8025F684(p)) {
                r = fn_80251AEC(p, 0x12);
            } else {
                r = fn_80251AEC(p, 0);
            }
            if (r) {
                fn_803037D4(S32(p, 0x4), 0xd);
            }
        }
    }
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
}

void fn_80292944(char* p) {
    fn_80241454(p, 1);
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
    if ((u8)fn_8025F684(p)) {
        s32 actorId = S32(p, 0xd68);
        if (actorId >= 0) {
            Actor* actor = fn_801F666C(fn_801F856C(), actorId);
            fn_802D6A9C();
            if (actor != NULL) {
                fn_801F349C(actor, U32(p, 0x3b4), (f32*)(p + 0x2f4));
            }
        }
    }
}

void fn_802929FC(char* p) {
    if (S32(p, 0x3b4) < 8) {
        JGeometry::TVec3<f32> pos = VEC(p, 0x8);
        pos.y -= lbl_80540640;
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &pos);
    }
    if (U8(p, 0x3fc) == 0x3c) {
        if (S32(p, 0xcf4) != 0x1e && S32(p, 0xcf4) != 0x1f) {
            fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x546, 1, 1, 0, NULL, 1, lbl_80540600);
            switch (S32(p, 0x4)) {
            case 0:
                fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x14e, 1, 1, 0, NULL, 1, lbl_80540600);
                fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x14f, 1, 1, 0, NULL, 1, lbl_80540600);
                if (fn_80241544(p) >= 2) {
                    fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x151, 1, 1, 0, NULL, 1, lbl_80540600);
                } else {
                    fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x150, 1, 1, 0, NULL, 1, lbl_80540600);
                }
                break;
            case 1:
                fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x157, 1, 1, 0, NULL, 1, lbl_80540600);
                fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x158, 1, 1, 0, NULL, 1, lbl_80540600);
                if (fn_80241544(p) >= 2) {
                    fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x15a, 1, 1, 0, NULL, 1, lbl_80540600);
                } else {
                    fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x159, 1, 1, 0, NULL, 1, lbl_80540600);
                }
                break;
            case 2:
                fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x14a, 1, 1, 0, NULL, 1, lbl_80540600);
                fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x14b, 1, 1, 0, NULL, 1, lbl_80540600);
                if (fn_80241544(p) >= 2) {
                    fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x14d, 1, 1, 0, NULL, 1, lbl_80540600);
                } else {
                    fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x14c, 1, 1, 0, NULL, 1, lbl_80540600);
                }
                break;
            case 3:
                fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x153, 1, 1, 0, NULL, 1, lbl_80540600);
                fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x154, 1, 1, 0, NULL, 1, lbl_80540600);
                if (fn_80241544(p) >= 2) {
                    fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x156, 1, 1, 0, NULL, 1, lbl_80540600);
                } else {
                    fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x155, 1, 1, 0, NULL, 1, lbl_80540600);
                }
                break;
            }
            fn_8013CC50(S32(p, 0xce0), p + 0xcc8, 0x152, 1, 1, 0, NULL, 1, lbl_80540600);
        }
        U8(p, 0x3fd) = 0;
        fn_80241454(p, 0);
    } else if (U8(p, 0x3fc) >= 0x76) {
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x25)) {
            if (S32(p, 0x3b4) < 8) {
                VEC(p, 0xcb0) = VEC(p, 0x8);
            }
            S32(p, 0x3b4) = S32(p, 0xce4);
            VEC(p, 0x8) = VEC(p, 0xcd4);
            fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
        }
    }
    U8(p, 0x3fc)++;
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
}

void fn_80292E90(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fd) = 1;
    fn_8024F0E8(p, 0x2000c);
}

extern "C" void fn_80292ECC(char* p) {
    if (S32(p, 0x3b4) < 8) {
        JGeometry::TVec3<f32> pos = VEC(p, 8);
        pos.y -= lbl_80540640;
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &pos);
    }
    if (U8(p, 0x3fc) < 0x3c) U8(p, 0x3fc)++;
    if ((S32(p, 0xce4) == S32(p, 0xce0) || (u8)fn_80240670(p) || !fn_80303750(S32(p, 4))) &&
        U8(p, 0x3fc) >= 0x3c) {
        if (U8(p, 0x3fc) == 0x3c) {
            if (S32(p, 0xce0) >= 8) {
                fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x545, 1, 1, 0, 0, 1, lbl_80540600);
                switch (S32(p, 4)) {
                case 0:
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x140, 1, 1, 0, 0, 1, lbl_80540600);
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x141, 1, 1, 0, 0, 1, lbl_80540600);
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x142, 1, 1, 0, 0, 1, lbl_80540600);
                    break;
                case 1:
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x147, 1, 1, 0, 0, 1, lbl_80540600);
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x148, 1, 1, 0, 0, 1, lbl_80540600);
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x149, 1, 1, 0, 0, 1, lbl_80540600);
                    break;
                case 2:
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x13d, 1, 1, 0, 0, 1, lbl_80540600);
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x13e, 1, 1, 0, 0, 1, lbl_80540600);
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x13f, 1, 1, 0, 0, 1, lbl_80540600);
                    break;
                case 3:
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x144, 1, 1, 0, 0, 1, lbl_80540600);
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x145, 1, 1, 0, 0, 1, lbl_80540600);
                    fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x146, 1, 1, 0, 0, 1, lbl_80540600);
                    break;
                }
                fn_8013CC50(S32(p, 0xce4), p + 0xcd4, 0x143, 1, 1, 0, 0, 1, lbl_80540600);
                fn_8024F0E8(p, 0x20020);
            }
            fn_8024F0E8(p, 0x2002f);
            fn_8024F0E8(p, 0x20021);
        }
        U8(p, 0x3fc)++;
        if (U8(p, 0x3fc) >= 0xab) {
            F32(p, 0x10) = lbl_805405B4;
            U8(p, 0x124d) = 0;
            if ((u8)fn_8025F684(p)) fn_80251AEC(p, 0x12);
            else fn_80251AEC(p, 0);
            S32(p, 0x3dc) = 2;
            S32(p, 0x3e8) = 2;
            fn_80241454(p, 1);
        }
    }
    F32(p, 0x2f4) = F32(p, 8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
}

void fn_802932BC(char* p) {
    U8(p, 0x124d) = 1;
    F32(p, 0x10) = lbl_805405B4;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805405B4;
    F32(p, 0x348) = lbl_80540644;
    F32(p, 0x34c) = lbl_8054061C;
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
    if ((u8)fn_8025F684(p)) {
        s32 actorId = S32(p, 0xd68);
        if (actorId >= 0) {
            Actor* actor = fn_801F666C(fn_801F856C(), actorId);
            fn_802D6A9C();
            if (actor != NULL) {
                fn_801F349C(actor, U32(p, 0x3b4), (f32*)(p + 0x2f4));
            }
        }
    }
    if (S32(p, 0xcf4) == 0x1f) {
        U8(p, 0x3fc) = 0x32;
    }
}

extern "C" void fn_8030C210(void* cam, JGeometry::TVec3<f32>* pos);
extern u8* lbl_8053AB10;
extern f32 lbl_80540640;
void fn_80293398(char* p) {
    if (S32(p, 0x3b4) < 8) {
        JGeometry::TVec3<f32> pos = VEC(p, 0x8);
        pos.y -= lbl_80540640;
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &pos);
    }
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) >= 0x3c || S32(p, 0xcf4) == 0x1f) {
        F32(p, 0x10) += lbl_8054061C;
        if (F32(p, 0x10) > lbl_80540620) {
            if (S32(p, 0x3b4) < 8) {
                VEC(p, 0xcb0) = VEC(p, 0x8);
            }
            U8(p, 0x124d) = 0;
            if (fn_80251AEC(p, 0x23)) {
                fn_80241454(p, 0);
                S32(p, 0x3b4) = S32(p, 0xce4);
                VEC(p, 0x8) = VEC(p, 0xcd4);
                F32(p, 0x10) = lbl_805405B4;
                fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
            }
        }
    }
    s32 state = (U8(p, 0x3fc) >> 2) & 3;
    if (state == 0) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    } else if (state == 1) {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    } else if (state == 2) {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    } else {
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
    }
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
}

void fn_80293534(char* p) {
    U8(p, 0x124d) = 1;
    F32(p, 0x10) = lbl_805405B4;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x2002e);
    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
}

extern "C" void fn_802935A4(char* self)
{
	if (*(s32*)(self + 0x3b4) < 8) {
		JGeometry::TVec3<f32> vec = VEC(self, 0x8);
		vec.y -= lbl_80540640;
		fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &vec);
	}
	if (*(u8*)(self + 0x3fc) < 0x3c) {
		*(u8*)(self + 0x3fc) += 1;
	}
	if (*(s32*)(self + 0xce4) != *(s32*)(self + 0xce0) && !(u8)fn_80240670(self) && (u8)fn_80303750(*(s32*)(self + 0x4))) {
		return;
	}
	if (*(u8*)(self + 0x3fc) < 0x3c) {
		return;
	}
	*(u8*)(self + 0x124d) = 0;
	bool r;
	if (fn_8024189C(self) <= 0) {
		r = fn_80251AEC(self, 0x33);
	} else if (*(u8*)(self + 0xcf0) == 1) {
		r = fn_80251AEC(self, 0x3e);
	} else if ((u8)fn_8025F684(self)) {
		r = fn_80251AEC(self, 0x12);
	} else {
		r = fn_80251AEC(self, 0);
	}
	if (r) {
		if (*(s32*)(self + 0x3b4) < 8) {
			JGeometry::TVec3<f32> pos;
			pos.x = *(f32*)(self + 0x8);
			pos.y = *(f32*)(self + 0xc);
			pos.z = *(f32*)(self + 0x10);
			pos.y += lbl_80540614;
			pos.z += lbl_805405A8;
			fn_8013CC50(*(s32*)(self + 0x3b4), &pos, 0x17d, 1, 0, 0, 0, 1, lbl_80540600);
			fn_8024F0E8(self, 0x20020);
			fn_8024F0E8(self, 0x20021);
		} else {
			fn_803037D4(*(s32*)(self + 0x4), 0xd);
		}
	}
}

void fn_80293760(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

void fn_80293774(char* p) {
    if (U8(p, 0x3fc) == 0x3c) {
        if (S32(p, 0xcf4) != 0x1d) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::TVec3<f32> pos;
                pos.x = F32(p, 0x8);
                pos.y = F32(p, 0xc);
                pos.z = F32(p, 0x10);
                pos.y += lbl_80540614;
                pos.z += lbl_805405A8;
                fn_8013CC50(S32(p, 0x3b4), &pos, 0x17d, 1, 0, 0, NULL, 1, lbl_80540600);
            } else {
                if (S32(p, 0xce4) < 8) {
                    fn_8024EFA0(p, 0);
                }
            }
        }
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fc) >= 0x76) {
        if (S32(p, 0x3b4) < 8) {
            VEC(p, 0xcb0) = VEC(p, 0x8);
        }
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x21)) {
            S32(p, 0x3b4) = S32(p, 0xce4);
            VEC(p, 0x8) = VEC(p, 0xcd4);
            fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
        }
    }
    U8(p, 0x3fc)++;
}

void fn_802938B8(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fd) = 1;
    if (S32(p, 0xcf4) != 0x1d) {
        fn_8024F0E8(p, 0x2000c);
    }
}

s32 Player_GetLinkTargetIndex(char*);
s32 fn_80237774(s32);
#pragma opt_propagation off
void fn_80293900(char* p) {
  s32 r;
  if (U8(p, 0x3fc) < 0x3c) {
    if ((u8)fn_80240670(p)) {
      U8(p, 0x3fc) = 0x3c;
    } else {
      U8(p, 0x3fc)++;
    }
  }
  if (!(u8)fn_80240670(p)) {
    if (S32(p, 0x3b4) != 0 && S32(p, 0xce4) != S32(p, 0xce0) && (u8)fn_80303750(S32(p, 0x4))) {
      return;
    }
    if (U8(p, 0x3fc) < 0x3c) {
      return;
    }
  }
  if (U8(p, 0x3fc) == 0x3c) {
    if (S32(p, 0x3b4) < 8) {
      fn_8024F0E8(p, 0x20021);
    } else {
      fn_803037D4(S32(p, 0x4), 0xd);
    }
  }
  U8(p, 0x3fc)++;
  fn_80241454(p, 1);
  {
    f32 z;
    f32 c1;
    f32 c2;
    f32 c3;
    f32 t;
    t = F32(p, 0x10);
    c1 = lbl_8054061C;
    z = lbl_805405B4;
    c2 = t - c1;
    F32(p, 0x10) = c2;
    c3 = F32(p, 0x10);
    if (c3 <= z) {
      F32(p, 0x10) = z;
      U8(p, 0x124d) = 0;
      if (Player_IsLinked(p)) {
        r = fn_80237774(Player_GetLinkTargetIndex(p));
      } else {
        r = fn_8024189C(p);
      }
      if (r <= 0) {
        fn_80251AEC(p, 0x33);
      } else if ((u8)fn_8025F684(p)) {
        if (fn_80251AEC(p, 0x12) && S32(p, 0xcf4) == 9) {
          S32(p, 0x464) = 0xb4;
        }
      } else {
        if (fn_80251AEC(p, 0) && S32(p, 0xcf4) == 9) {
          S32(p, 0x464) = 0xb4;
        }
      }
    }
  }
  if (((U8(p, 0x3fc) >> 2) & 3) == 0) {
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
  } else if (((U8(p, 0x3fc) >> 2) & 3) == 1) {
    S32(p, 0x3dc) = 1;
    S32(p, 0x3e8) = 1;
  } else if (((U8(p, 0x3fc) >> 2) & 3) == 2) {
    S32(p, 0x3dc) = 3;
    S32(p, 0x3e8) = 3;
  } else {
    S32(p, 0x3dc) = 0;
    S32(p, 0x3e8) = 0;
  }
}
#pragma opt_propagation reset
void fn_80293B1C(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

s32 fn_8024064C(char*);
u8 fn_8022D75C(s32);
void* fn_8023E724(s32);
s32 fn_8023DE58(s32);
u16 fn_8022461C(s32, s32);
u8 fn_802265DC(f32*, int, int);
bool fn_802684A4(char*, f32*, s32);
bool fn_802DEABC();
void fn_80272160(char*, s32, char*, s32);
void fn_8027EDDC(char*);
void fn_80293B30(char* p) {
    if (U8(p, 0x3fc) < 0x3a) {
        goto tail;
    }
    U8(p, 0x3fc) = 0x3a;
    U8(p, 0x3fd) = 0;
    U8(p, 0x3fb) = 1;
    fn_80241454(p, 0);
    if (fn_80301CD0(PTR(p, 0x4))) {
        goto tail;
    }
    if ((u8)fn_80240670(p)) {
        if (fn_8022D75C(fn_8024064C(p))) {
            return;
        }
        if (S32(p, 0xcf4) == 0x12) {
            VEC(p, 0xcd4) = *(JGeometry::TVec3<f32>*)fn_8023E724(fn_8024064C(p));
            S32(p, 0xce4) = fn_8023DE58(fn_8024064C(p));
        }
    }
    if (S32(p, 0x3b4) < 8) {
        VEC(p, 0xcb0) = VEC(p, 0x8);
    }
    U8(p, 0x124d) = 0;
        if (!fn_80251AEC(p, 0x1f)) {
            goto tail;
        }
    if ((u8)fn_80241E28(p, S32(p, 0xce4), (JGeometry::TVec3<f32>*)(p + 0xcd4))) {
        if (fn_802486A0(p) == 5 && Player_IsLinked(p)) {
            f32* v = (f32*)fn_8023E724(Player_GetLinkTargetIndex(p));
            F32(p, 0xcd4) = v[0];
            F32(p, 0xcd8) = v[1];
            F32(p, 0xcdc) = v[2];
        }
        u16 mode = fn_8022461C((s32)(p + 0xcd4), S32(p, 0xce4));
        if (fn_802265DC((f32*)(p + 0xcd4), S32(p, 0xce4), 1) || mode == 3 || mode == 0xe || fn_802684A4(p, (f32*)(p + 0xcd4), S32(p, 0xce4))) {
                if (S32(p, 0xce4) < 8) {
                    F32(p, 0xcd4) = F32(p, 0x2c4);
                    F32(p, 0xcd8) = F32(p, 0x2c8);
                    F32(p, 0xcdc) = F32(p, 0x2cc);
                } else {
                    F32(p, 0xcd4) = F32(p, 0xcbc);
                    F32(p, 0xcd8) = F32(p, 0xcc0);
                    F32(p, 0xcdc) = F32(p, 0xcc4);
                }
        }
    }
    S32(p, 0x3b4) = S32(p, 0xce4);
    VEC(p, 0x8) = VEC(p, 0xcd4);
    if (fn_802DEABC() && S32(p, 0x3b4) <= 8 && (S32(p, 0xcf4) == 9 || S32(p, 0xcf4) == 0x12)) {
        if (!(u8)fn_80240670(p)) fn_80272160(p, 2, p + 8, 0x11);
    } else if (S32(p, 0x3b4) > 8 && (S32(p, 0xcf4) == 9 || S32(p, 0xcf4) == 0x12)) {
        if (!(u8)fn_80240670(p)) fn_80272160(p, 2, p + 8, 0x11);
    }
    if (S32(p, 0xcf4) == 9) {
        F32(p, 0x10) = lbl_805405B4;
    } else if (S32(p, 0xcf4) == 0x24) {
        F32(p, 0x10) = lbl_80540620;
    } else {
        s32 r30 = S32(p, 0x3b4);
        u8* base = (u8*)fn_802D6A9C() + 0x10000;
        if (base[r30 + 0x31df]) {
            F32(p, 0x10) = lbl_805405B4;
        } else if (S32(p, 0xce4) >= 8) {
            F32(p, 0x10) = lbl_80540620;
        } else {
            F32(p, 0x10) = lbl_805405B4;
        }
    }
    fn_8030BD3C((void*)S32(p, 0xbec), S32(p, 0x4));
tail:
    fn_8027EDDC(p);
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) = F32(p, 0x2fc) + lbl_805405A8;
}

void fn_80293E8C(char* p) {
    U8(p, 0x124d) = 1;
    F32(p, 0x10) = lbl_805405B4;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x10003);
    fn_8024F0E8(p, 0x2002d);
    s32 cur = S32(p, 0x3b4);
    if (cur > 8 && S32(p, 0xce4) > 8) {
        if (U8((char*)fn_802D6A9C() + 0x10000, cur + 0x31df) != 0) {
            s32 other = S32(p, 0xce4);
            if (U8((char*)fn_802D6A9C() + 0x10000, other + 0x31df) != 0 && S32(p, 0xce4) != S32(p, 0x3b4)) {
                U8(p, 0x3fc) = 0x3a;
            }
        }
    }
    F32(p, 0x2f4) = F32(p, 0x8);
    F32(p, 0x2f8) = F32(p, 0xc);
    F32(p, 0x2fc) = F32(p, 0x10);
    F32(p, 0x2fc) += lbl_805405A8;
    if (S32(p, 0xcf4) == 0x24 && S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
    if (fn_802486A0(p) != 4) {
        if (fn_802486A0(p) != 5) {
            fn_80248004(p, 5, 1);
        }
        fn_8024BAEC(p);
    }
}

extern "C" const f32 lbl_80540648;
extern "C" void fn_8027E5BC(char*, f32);
extern "C" void fn_80268B3C(char*);
extern "C" void fn_8026152C(char*, s32);
extern "C" void fn_8027EE84(char*);
extern "C" void fn_80265D8C(char*);
extern "C" void fn_80293FE4(char* p) {
    if (U8(p, 0x3fc) < 0x1e) {
        U8(p, 0x3fc)++;
        return;
    }
    if (S32(p, 0xce4) != S32(p, 0xce0) && !(u8)fn_80240670(p) && fn_80303750(S32(p, 4))) {
        return;
    }
    if (U8(p, 0x3fc) == 0x1e) {
        if (F32(p, 0x3a8) > F32(p, 0x39c)) {
            if (S32(p, 0x3b4) < 8) {
                if (U8(p, 0xceb) == 0) fn_8024F0E8(p, 0x2001b);
                fn_8024F0E8(p, 0x20021);
            } else {
                fn_803037D4(S32(p, 4), 0xd);
            }
        } else {
            if (S32(p, 0x3b4) < 8) {
                if (U8(p, 0xceb) == 0) fn_8024F0E8(p, 0x20019);
                fn_8024F0E8(p, 0x20021);
            } else {
                fn_803037D4(S32(p, 4), 0xd);
            }
        }
    }
    if (S32(p, 0xcf4) == 3) fn_80265D8C(p);
    U8(p, 0x3fc)++;
    fn_80241454(p, 1);
    fn_8027E5BC(p, lbl_80540648);
    if ((VEC(p, 0x3a4) - VEC(p, 8)).isZero() || U8(p, 0x3fc) >= 0x50) {
        U8(p, 0x124d) = 0;
        if (fn_8024189C(p) <= 0) {
            fn_80251AEC(p, 0x33);
        } else if (U8(p, 0xceb) == 1) {
            s32 idx = S32(p, 0x3b4);
            u8* base = (u8*)fn_802D6A9C() + 0x10000;
            if (base[idx + 0x31df] != 0) fn_80251AEC(p, 0x4b);
            else fn_80251AEC(p, 0x4a);
        } else if (U8(p, 0xcec) == 1) {
            fn_80251AEC(p, 0xb);
        } else if ((u8)fn_8025F684(p)) {
            fn_80251AEC(p, 0x12);
        } else {
            fn_80251AEC(p, 0);
        }
    }
    if (S32(p, 0xcf4) == 0x15 || S32(p, 0xcf4) == 0x23) {
        s32 idx = S32(p, 0x3b4);
        u8* base = (u8*)fn_802D6A9C() + 0x10000;
        if (base[idx + 0x31df] != 0) goto animate;
    }
    fn_80268B3C(p);
animate:
    if (U8(p, 0xceb) == 1) {
        U8(p, 0x3f8)++;
        if (U8(p, 0x3f8) >= 0x18) {
            U8(p, 0x3f8) = 0;
        }
        U8(p, 0x3f9) = U8(p, 0x3f8) / 6;
    } else if (U8(p, 0xcec) == 1) {
        U8(p, 0x3f8)++;
        if (U8(p, 0x3f8) >= 0x13) {
            U8(p, 0x3f8) = 0;
        }
        if (U8(p, 0x3f8) < 7) {
            U8(p, 0x3f9) = 0;
        } else if (U8(p, 0x3f8) < 0xc) {
            U8(p, 0x3f9) = 1;
        } else {
            U8(p, 0x3f9) = 2;
        }
    } else if ((u8)fn_8025F684(p)) {
        fn_8026152C(p, 0);
    } else {
        fn_8027EE84(p);
    }
}

void fn_80294374(char* p) {
    F32(p, 0x398) = F32(p, 0x8);
    F32(p, 0x39c) = F32(p, 0xc);
    F32(p, 0x3a0) = F32(p, 0x10);
    F32(p, 0x3a0) = lbl_805405B4;
    F32(p, 0x3a4) = F32(p, 0x8);
    F32(p, 0x3a8) = F32(p, 0xc);
    F32(p, 0x3ac) = F32(p, 0x10);
    F32(p, 0x3ac) = lbl_805405B4;
    U8(p, 0x124d) = 1;
    const s32 state = S32(p, 0xcf4);
    if (state == 0x15) {
        s32 cur = S32(p, 0x3b4);
        u8* base = (u8*)fn_802D6A9C() + 0x10000;
        if (base[cur + 0x31df] != 0) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::TVec3<f32> v(0.0f, lbl_8054064C, 0.0f);
                VEC(p, 0x398).add(v);
                F32(p, 0xc) -= lbl_80540650;
                S32(p, 0x3dc) = 2;
                S32(p, 0x3e8) = 2;
            } else {
                JGeometry::TVec3<f32> v(0.0f, lbl_80540650, 0.0f);
                VEC(p, 0x398).add(v);
                F32(p, 0xc) += lbl_80540650;
                S32(p, 0x3dc) = 3;
                S32(p, 0x3e8) = 3;
            }
        } else if (S32(p, 0x3b4) < 8) {
            JGeometry::TVec3<f32> v(0.0f, lbl_805405F4, 0.0f);
            VEC(p, 0x3a4).add(v);
            S32(p, 0x3dc) = 2;
            S32(p, 0x3e8) = 2;
        } else if (S32(p, 0xce0) < 8) {
            JGeometry::TVec3<f32> v(0.0f, lbl_80540654, 0.0f);
            VEC(p, 0x3a4).add(v);
            S32(p, 0x3dc) = 3;
            S32(p, 0x3e8) = 3;
        } else {
            JGeometry::TVec3<f32> v(0.0f, lbl_805405F4, 0.0f);
            VEC(p, 0x3a4).add(v);
            S32(p, 0x3dc) = 2;
            S32(p, 0x3e8) = 2;
        }
    } else if (state == 0x23) {
        s32 cur = S32(p, 0x3b4);
        u8* base = (u8*)fn_802D6A9C() + 0x10000;
        if (base[cur + 0x31df] != 0) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::TVec3<f32> v(0.0f, lbl_80540650, 0.0f);
                VEC(p, 0x398).add(v);
                F32(p, 0xc) += lbl_80540650;
                S32(p, 0x3dc) = 3;
                S32(p, 0x3e8) = 3;
            } else {
                JGeometry::TVec3<f32> v(0.0f, lbl_8054064C, 0.0f);
                VEC(p, 0x398).add(v);
                F32(p, 0xc) -= lbl_80540650;
                S32(p, 0x3dc) = 2;
                S32(p, 0x3e8) = 2;
            }
        } else if (S32(p, 0x3b4) < 8) {
            JGeometry::TVec3<f32> v(0.0f, lbl_80540654, 0.0f);
            VEC(p, 0x3a4).add(v);
            S32(p, 0x3dc) = 3;
            S32(p, 0x3e8) = 3;
        } else if (S32(p, 0xce0) < 8) {
            JGeometry::TVec3<f32> v(0.0f, lbl_805405F4, 0.0f);
            VEC(p, 0x3a4).add(v);
            S32(p, 0x3dc) = 2;
            S32(p, 0x3e8) = 2;
        } else {
            JGeometry::TVec3<f32> v(0.0f, lbl_80540654, 0.0f);
            VEC(p, 0x3a4).add(v);
            S32(p, 0x3dc) = 3;
            S32(p, 0x3e8) = 3;
        }
    } else if (state == 0 || state == 3) {
        JGeometry::TVec3<f32> v(0.0f, lbl_80540654, 0.0f);
        VEC(p, 0x3a4).add(v);
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    } else if (state == 0x17) {
        JGeometry::TVec3<f32> v(lbl_805405F4, lbl_805405B4, lbl_805405B4);
        VEC(p, 0x3a4).add(v);
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
    } else if (state == 0x18) {
        JGeometry::TVec3<f32> v(lbl_80540654, lbl_805405B4, lbl_805405B4);
        VEC(p, 0x3a4).add(v);
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    } else {
        JGeometry::TVec3<f32> v(lbl_805405B4, lbl_805405F4, lbl_805405B4);
        VEC(p, 0x3a4).add(v);
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    }
    U8(p, 0x458) = 0;
    if (S32(p, 0xcf4) == 1) {
        fn_8029E508(lbl_8053AC98, p + 0x8, S32(p, 0x4), S32(p, 0x3b4));
    }
    if (S32(p, 0xcf4) == 3) U8(p, 0xca0) = 0;
    else U8(p, 0xca0) = 0xff;
}

extern int __float_epsilon[];
extern const f32 lbl_80540648;
void fn_8027E5BC(char*, f32);
void fn_80265D68(char*);
void fn_80268B3C(char*);
void fn_8026152C(char*, s32);
void fn_8027EE84(char*);
void fn_802948C0(char* p) {
    fn_8027E5BC(p, lbl_80540648);
    U8(p, 0x3fc)++;
    if ((VEC(p, 0x3a4) - VEC(p, 0x8)).isZero() || U8(p, 0x3fc) >= 0x32) {
        if (S32(p, 0x3b4) < 8) {
            VEC(p, 0xcb0) = VEC(p, 0x8);
        }
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x1d)) {
            fn_80241454(p, 0);
            S32(p, 0x3b4) = S32(p, 0xce4);
            VEC(p, 0x8) = VEC(p, 0xcd4);
            fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
        }
    } else if (S32(p, 0xcf4) == 2) {
        fn_80265D68(p);
    }
    if (S32(p, 0xcf4) == 2) {
        fn_80268B3C(p);
    }
    if (U8(p, 0xceb) == 1) {
        U8(p, 0x3f8)++;
        if (U8(p, 0x3f8) >= 0x18) {
            U8(p, 0x3f8) = 0;
        }
        U8(p, 0x3f9) = U8(p, 0x3f8) / 6;
    } else if (U8(p, 0xcec) == 1) {
        U8(p, 0x3f8)++;
        if (U8(p, 0x3f8) >= 0x13) {
            U8(p, 0x3f8) = 0;
        }
        if (U8(p, 0x3f8) < 7) {
            U8(p, 0x3f9) = 0;
        } else if (U8(p, 0x3f8) < 0xc) {
            U8(p, 0x3f9) = 1;
        } else {
            U8(p, 0x3f9) = 2;
        }
    } else if ((u8)fn_8025F684(p)) {
        fn_8026152C(p, 0);
    } else {
        fn_8027EE84(p);
    }
}

void fn_80294ADC(char* p) {
    s32 idx;
    s32 st;

    if (S32(p, 0x1248) == 0x4a || S32(p, 0x1248) == 0x4b) {
        U8(p, 0xceb) = 1;
        U8(p, 0xcec) = 0;
    } else if (S32(p, 0x1248) == 0xb) {
        U8(p, 0xceb) = 0;
        U8(p, 0xcec) = 1;
    } else {
        U8(p, 0xceb) = 0;
        U8(p, 0xcec) = 0;
    }
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x10) = 0.0f;
    F32(p, 0x398) = F32(p, 0x8);
    F32(p, 0x39c) = F32(p, 0xc);
    F32(p, 0x3a0) = F32(p, 0x10);
    F32(p, 0x3a0) = 0.0f;
    F32(p, 0x3a4) = F32(p, 0x8);
    F32(p, 0x3a8) = F32(p, 0xc);
    F32(p, 0x3ac) = F32(p, 0x10);
    F32(p, 0x3ac) = 0.0f;

    st = S32(p, 0xcf4);
    if (st == 0x15) {
        idx = S32(p, 0x3b4);
        u8* base = (u8*)fn_802D6A9C() + 0x10000;
        if (base[idx + 0x31df] != 0) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::TVec3<f32> t(0.0f, lbl_8054064C, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 3;
                S32(p, 0x3e8) = 3;
                fn_8024F0E8(p, 0x20018);
            } else {
                JGeometry::TVec3<f32> t(0.0f, lbl_80540650, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 2;
                S32(p, 0x3e8) = 2;
                fn_8024F0E8(p, 0x2001a);
            }
        } else {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::TVec3<f32> t(0.0f, lbl_80540654, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 3;
                S32(p, 0x3e8) = 3;
                fn_8024F0E8(p, 0x20018);
            } else if (S32(p, 0xce4) < 8) {
                JGeometry::TVec3<f32> t(0.0f, lbl_805405F4, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 2;
                S32(p, 0x3e8) = 2;
                fn_8024F0E8(p, 0x2001a);
            } else {
                JGeometry::TVec3<f32> t(0.0f, lbl_80540654, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 3;
                S32(p, 0x3e8) = 3;
                fn_8024F0E8(p, 0x20018);
            }
        }
    } else if (st == 0x23) {
        idx = S32(p, 0x3b4);
        u8* base = (u8*)fn_802D6A9C() + 0x10000;
        if (base[idx + 0x31df] != 0) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::TVec3<f32> t(0.0f, lbl_80540650, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 2;
                S32(p, 0x3e8) = 2;
                fn_8024F0E8(p, 0x2001a);
            } else {
                JGeometry::TVec3<f32> t(0.0f, lbl_8054064C, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 3;
                S32(p, 0x3e8) = 3;
                fn_8024F0E8(p, 0x20018);
            }
        } else {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::TVec3<f32> t(0.0f, lbl_805405F4, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 2;
                S32(p, 0x3e8) = 2;
                fn_8024F0E8(p, 0x2001a);
            } else if (S32(p, 0xce4) < 8) {
                JGeometry::TVec3<f32> t(0.0f, lbl_80540654, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 3;
                S32(p, 0x3e8) = 3;
                fn_8024F0E8(p, 0x20018);
            } else {
                JGeometry::TVec3<f32> t(0.0f, lbl_805405F4, 0.0f);
                VEC(p, 0x3a4) += t;
                S32(p, 0x3dc) = 2;
                S32(p, 0x3e8) = 2;
                fn_8024F0E8(p, 0x2001a);
            }
        }
    } else if (st == 0x17) {
        JGeometry::TVec3<f32> t(lbl_805405F4, 0.0f, 0.0f);
        VEC(p, 0x3a4) += t;
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
        if (U8(p, 0xceb) == 0) {
            fn_8024F0E8(p, 0x2001a);
        }
    } else if (st == 0x18) {
        JGeometry::TVec3<f32> t(lbl_80540654, 0.0f, 0.0f);
        VEC(p, 0x3a4) += t;
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
        if (U8(p, 0xceb) == 0) {
            fn_8024F0E8(p, 0x2001a);
        }
    } else if (st == 1 || st == 2) {
        JGeometry::TVec3<f32> t(0.0f, lbl_805405F4, 0.0f);
        VEC(p, 0x3a4) += t;
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
        if (U8(p, 0xceb) == 0) {
            fn_8024F0E8(p, 0x2001a);
        }
    } else {
        JGeometry::TVec3<f32> t(0.0f, lbl_80540654, 0.0f);
        VEC(p, 0x3a4) += t;
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
        if (U8(p, 0xceb) == 0) {
            fn_8024F0E8(p, 0x20018);
        }
    }

    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
    U8(p, 0xca0) = 0xff;
}

void fn_8029513C(char* p) {
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
        return;
    }
    fn_80241454(p, 1);
    if (S32(p, 0xce4) != S32(p, 0xce0) && (u8)fn_80240670(p) == 0 &&
        fn_80303750(S32(p, 0x4))) {
        return;
    }
    F32(p, 0x34c) -= lbl_8054060C;
    if (F32(p, 0x34c) < lbl_80540618) {
        F32(p, 0x34c) = lbl_80540618;
    }
    VEC(p, 0x8) += VEC(p, 0x344);
    if (F32(p, 0x10) < lbl_805405B4) {
        F32(p, 0x10) = lbl_805405B4;
        U8(p, 0x124d) = 0;
        if (fn_8024189C(p) <= 0) {
            fn_80251AEC(p, 0x33);
        } else {
            fn_80251AEC(p, 0);
        }
    }
}

void fn_80295240(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805405B4;
    F32(p, 0x348) = lbl_80540644;
    F32(p, 0x34c) = lbl_805405B4;
}

void fn_80295268(char* p) {
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) >= 0xa) {
        F32(p, 0x10) += lbl_8054061C;
        if (F32(p, 0x10) > lbl_80540620) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::setTVec3f((f32*)(p + 0x8), (f32*)(p + 0xcb0));
            }
            U8(p, 0x124d) = 0;
            if (fn_80251AEC(p, 0x2f)) {
                fn_80241454(p, 0);
                S32(p, 0x3b4) = S32(p, 0xce4);
                JGeometry::setTVec3f((f32*)(p + 0xcd4), (f32*)(p + 0x8));
                fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
            }
        }
    }
}

void fn_80295334(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    if (S32(p, 0x3b4) >= 8 && S32(p, 0xce4) < 8) {
        fn_8024EFA0(p, 0);
    }
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
    F32(p, 0x10) = lbl_805405B4;
}

void fn_803037D4(s32, s32);
void fn_802953A0(char* p) {
    if (U8(p, 0x3fc) < 0x3c) {
        U8(p, 0x3fc)++;
        return;
    }
    if (S32(p, 0xce4) != S32(p, 0xce0) && (u8)fn_80240670(p) == 0 && fn_80303750(S32(p, 0x4))) {
        return;
    }
    if (U8(p, 0x3fc) < 0x3c) {
        return;
    }
    F32(p, 0x34c) -= 0.25f;
    if (F32(p, 0x34c) < -4.0f) {
        F32(p, 0x34c) = -4.0f;
    }
    VEC(p, 0x8) += VEC(p, 0x344);
    if (F32(p, 0x10) < 0.0f) {
        F32(p, 0x10) = 0.0f;
    U8(p, 0x124d) = 0;
    bool r;
    if (fn_8024189C(p) <= 0) {
        r = fn_80251AEC(p, 0x33);
    } else {
        r = fn_80251AEC(p, 0);
    }
    if (r) {
        fn_803037D4(S32(p, 0x4), 0xd);
    }
    }
}

void fn_802954B8(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805405B4;
    F32(p, 0x348) = lbl_805405B4;
    F32(p, 0x34c) = lbl_805405B4;
}

void fn_802954DC(char* p) {
    if (U8(p, 0x3fc) >= 0x3c) {
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x2d)) {
            if (S32(p, 0x3b4) < 8) {
                JGeometry::setTVec3f((f32*)(p + 0x8), (f32*)(p + 0xcb0));
            }
            S32(p, 0x3b4) = S32(p, 0xce4);
            JGeometry::setTVec3f((f32*)(p + 0xcd4), (f32*)(p + 0x8));
            F32(p, 0x10) = lbl_80540620;
            fn_8030BD3C(PTR(p, 0xbec), S32(p, 0x4));
        }
    } else {
        U8(p, 0x3fc)++;
    }
}

void fn_80295584(char* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0x3fd) = 1;
    S32(p, 0x3dc) = 2;
    S32(p, 0x3e8) = 2;
}

void fn_802955A8(void)
{
}

}
