// TU 0x8026fc20-0x8027e5bc: player-class methods (Link object, see tu_8023FBF0).
// A few small bodies originally from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define U16(p, o) (*(u16*)((char*)(p) + (o)))
#define S32(p, o) (*(s32*)((char*)(p) + (o)))
#define F32(p, o) (*(f32*)((char*)(p) + (o)))
#define PTR(p, o) (*(void**)((char*)(p) + (o)))

#pragma auto_inline off

extern "C" {
extern u8 lbl_80529DEC[];
extern void* lbl_8053AC98;
bool Player_IsLinked(char* p);
s32 Player_GetLinkTargetIndex(char* p);
s32 fn_8023A1A4(s32);
s32 fn_80237774(s32);
void fn_80238548(s32, s32, s32, s32);
void* fn_8013C824(void);
void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
void* fn_8013CC50(void* a, void* pos, s32 kind, s32 b, s32 c, s32 d, s32 e, s32 f, f32 scale);
s32 fn_80241864(char*);
s32 fn_80241544(char*);
bool fn_80241200(char*);
s32 fn_802486A0(char*);
s32 fn_80248778(char*);
s32 fn_80240888(char*);
BOOL fn_80270ABC(char*);
void fn_80251AEC(char*, s32);
void fn_8024F0E8(char*, s32);
void fn_80268B3C(char*);
void fn_802685D4(char*);
s32 fn_802D6A9C(void);
bool fn_802413F0(char*);
bool GetBusyLocked(char*);
void fn_802A20F0(void*, void*, s32, void*, s32, s32);
}

struct EmitterObj {
    u8 pad0[0x24];
    s32 m24;
    u8 pad28[0xf4 - 0x28];
    u32 mF4;
};

inline void killEmitter(char* p, s32 off) {
    EmitterObj* e = (EmitterObj*)PTR(p, off);
    if (e != NULL) {
        e->mF4 |= 1;
        e->m24 = 1;
        PTR(p, off) = NULL;
    }
}

#define DELETE_JPA(p, off) \
    if (PTR(p, off) != NULL) { \
        void* mgr = PTR((char*)fn_8013C824(), 0xc); \
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, PTR(p, off)); \
        PTR(p, off) = NULL; \
    }

inline void resetC74(char* p) {
    S32(p, 0xc74) = 0;
    ((s16*)(lbl_80529DEC + 0x1f4))[S32(p, 0x4)] = 0;
}

struct PlayerAreas {
    u8 pad0[0x5fc];
    f32 mBox[0x50][4];
    u8 padAFC[0xdb0 - 0xafc];
    s32 mId[0x50];
    u8 padEF0[0x1030 - 0xef0];
    s32 mOwner[0x50];
};

extern "C" {

s32 fn_8026FC20(char* p) {
    if (Player_IsLinked(p)) {
        return fn_8023A1A4(Player_GetLinkTargetIndex(p));
    }
    return S32(p, 0xbac);
}

// ---- Player_GetLinkedHandleOrInvalid.cpp ----
// The player-object "special-state" cluster: accessors/mutators on a
// shared set of fields. Player_HasAnyStatusFlagSet (the OR-of-3-flags combined
// predicate with a shared-tail accumulator) is kept separately as raw
// asm in Dolphin/os/extab_8026fce0.s - it matches the already-
// documented "default value, conditionally overridden, single merge
// point" idiom that has repeatedly failed natural-C++ promotion this
// session.

// Player_GetLinkedHandleOrInvalid(player) - if `player->0xb9c` is set, returns the handle
// stored at `player->0x3dc`; otherwise returns -1.
void* Player_GetLinkedHandleOrInvalid(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(u8*)(p + 0xb9c) != 0) {
		return *(void**)(p + 0x3dc);
	}
	return (void*)-1;
}

// Player_GetField_0xb9b(player) - trivial byte accessor for `player->0xb9b`.
u8 Player_GetField_0xb9b(void* thisPtr) {
	return *(u8*)((char*)thisPtr + 0xb9b);
}

}


extern "C" void fn_8026FC8C(char* p) {
    S32(p, 0xc9c) = 0;
    F32(p, 0xc84) = 1.0f;
    F32(p, 0xc88) = 1.0f;
    F32(p, 0xc8c) = 1.0f;
    S32(p, 0x468) = 10;
}

// ---- Player_CheckField_0xc9c.cpp ----
extern "C" {

// Player_CheckField_0xc9c(player) - returns whether `player->0xc9c` is nonzero.
BOOL Player_CheckField_0xc9c(void* thisPtr) {
	return *(s32*)((char*)thisPtr + 0xc9c) != 0;
}

// Player_GetModeSubPtr_0xb9a(player) - returns `player+0x5c0` if `player->0xb9a` is
// set, else `player+0x8`.
void* Player_GetModeSubPtr_0xb9a(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(u8*)(p + 0xb9a) != 0) {
		return p + 0x5c0;
	}
	return p + 0x8;
}

}

// ---- Player_HasAnyStatusFlagSet_8026FCE0.cpp ----
// Player_HasAnyStatusFlagSet(player) - returns true if ANY of the three flags
// `player->0xb9a`/`0xb9c`/`0xb9d` is set, false only if all three are
// clear.
//
// A plain bare `return a || b || c;` with `bool` return type matches
// retail exactly on the first attempt - the CAED4-family recipe
// (see project_fsa_phase4_kickoff.md) generalizes cleanly to a 3-term
// OR-chain of independent byte flags, not just 2-term chains.
extern "C" bool Player_HasAnyStatusFlagSet(void* player) {
	char* p = (char*)player;
	return *(u8*)(p + 0xb9a) || *(u8*)(p + 0xb9c) || *(u8*)(p + 0xb9d);
}


extern "C" {
void fn_8027023C(char* p) {
    S32(p, 0x117c) = 0;
    S32(p, 0x1180) = 0;
    S32(p, 0x1184) = 0;
    S32(p, 0x1188) = 0;
    S32(p, 0x118c) = 0;
    S32(p, 0x1190) = 0;
    S32(p, 0x1194) = 0;
    S32(p, 0x1198) = 0;
    for (int i = 0; i < 4; i++) {
        U8(p, 0x119c + i) = 0;
        U8(p, 0x11a0 + i) = 0;
        U8(p, 0x11a4 + i) = 0;
        U8(p, 0x11a8 + i) = 0;
    }
}
void fn_802702A4(char* p) {
    if (S32(p, 0xc7c) < 99999999) {
        S32(p, 0xc7c)++;
    }
}
void fn_802702C4(char* p) {
    if (S32(p, 0xc78) < 99999999) {
        S32(p, 0xc78)++;
    }
}
void fn_802702EC(char* p);
s32 fn_802702E4(char* p) { return S32(p, 0xc74); }
void fn_802702EC(char* p) { resetC74(p); }
s32 fn_80270310(char* p) { return S32(p, 0xc70); }
void fn_80270318(char* p) {
    S32(p, 0xc74)++;
    if (S32(p, 0xc74) >= 9999) {
        S32(p, 0xc74) = 9999;
    }
    if (S32(p, 0xc70) < S32(p, 0xc74)) {
        S32(p, 0xc70) = S32(p, 0xc74);
    }
}
s32 fn_80270350(char* p) { return S32(p, 0xc64); }
s32 fn_80270358(char* p) { return S32(p, 0xc50); }
void fn_802708D0(char* p) {
    U8(p, 0xd2d) = 1;
    S32(p, 0xd30) = 0;
    U8(p, 0xcfc) = 0;
}
void fn_802708E8(char* p) {
    U8(p, 0xd2d) = 1;
    S32(p, 0xd30) = 0;
    U8(p, 0xcfc) = 0;
    DELETE_JPA(p, 0x1308);
}
void fn_80270948(char* p, const JGeometry::TVec3<f32>* pos) {
    BOOL r;
    if (S32(p, 0x1244) == 0x33 || S32(p, 0x1240) == 0x33 || S32(p, 0x1240) == 0x34) {
        r = 1;
    } else {
        r = 0;
    }
    if ((u8)r) {
        if (U8(p, 0xd2c) != 1) {
            if (pos == NULL) {
                *(JGeometry::TVec3<f32>*)(p + 0xd10) = *(JGeometry::TVec3<f32>*)(p + 0x8);
            } else {
                *(JGeometry::TVec3<f32>*)(p + 0xd10) = *pos;
            }
            U8(p, 0xd2c) = 1;
        }
    }
}
void fn_802709C8(char* p) {
    fn_802A20F0(lbl_8053AC98, p + 0x30c, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
}
BOOL fn_80270A04(char* p) {
    BOOL r = 0;
    if (fn_80241864(p) <= 0 && U8(p, 0xcfc) != 0) {
        r = 1;
    }
    return r;
}
BOOL fn_80270A58(char* p) {
    if (U8(p, 0xd2d) != 0 || S32(p, 0x1244) == 0x34 || S32(p, 0x1240) == 0x34) {
        return 1;
    }
    return 0;
}
}

// ---- stub_80270a8c.cpp ----
// fn_80270A8C - the sub-checker delegate for fn_80236B50 in the
// "per-player capability predicate" family. Returns true if
// playerObj->0x1244 == 0x33(51) OR playerObj->0x1240 == 0x33 OR
// playerObj->0x1240 == 0x34(52).
extern "C" s32 fn_80270A8C(void* playerObj) {
	if (*(s32*)((char*)playerObj + 0x1244) == 0x33 ||
	    *(s32*)((char*)playerObj + 0x1240) == 0x33 ||
	    *(s32*)((char*)playerObj + 0x1240) == 0x34) {
		return 1;
	}
	return 0;
}

extern "C" {
BOOL fn_80270C88(char* p) {
    if (fn_80241200(p)) {
        return 1;
    }
    if (fn_802486A0(p) == 4) {
        if (fn_80248778(p) != fn_80240888(p)) {
            return 1;
        }
    }
    return fn_80270ABC(p);
}
void fn_80270D08(char* p) {
    if (S32(p, 0x464) > 0) {
        S32(p, 0x464)--;
    }
    if (S32(p, 0x468) > 0) {
        S32(p, 0x468)--;
    }
}
void fn_80270D34(char* p, s32 n) {
    if (Player_IsLinked(p)) {
        S32(p, 0xbfc) = fn_80237774(Player_GetLinkTargetIndex(p));
    } else {
        S32(p, 0xbfc) -= n;
    }
    if (S32(p, 0xbfc) <= 0) {
        S32(p, 0xbfc) = 0;
        fn_80251AEC(p, 0x33);
    }
    if (n > 0) {
        resetC74(p);
    }
}
void fn_80271038(char* p, s32 a) { fn_80238548(S32(p, 0x4), 0, a, 0xf); }
void fn_80271068(char* p, s32 a) { fn_80238548(S32(p, 0x4), 0, a, 0xe); }
void fn_80271098(char* p, s32 a) { fn_80238548(S32(p, 0x4), 0, a, 0xd); }
void fn_80272160(char* p, s32 a, s32 b, s32 c) { fn_80238548(S32(p, 0x4), a, b, c); }
s32 fn_80272184(void) { return 4; }
s32 fn_8027218C(char* p) {
    if (S32(p, 0x1240) != 4) {
        return 0;
    }
    return S32(p, 0x45c);
}
s32 fn_802721A8(char* p) {
    U8(p, 0xcae) = 1;
    if (U8(p, 0x492) == 1) {
        return 4;
    }
    if (S32(p, 0xbf4) <= 0) {
        return 0;
    }
    if (fn_80241544(p) >= 2) {
        return S32(p, 0xbf4) + 2;
    }
    return S32(p, 0xbf4);
}
void fn_8027221C(char* p, s32 v) { S32(p, 0xbf4) = v; }
inline BOOL inBox(const f32* box, const JGeometry::TVec2<f32>& pt) {
    BOOL in = 0;
    if (pt.x >= box[0] && pt.y >= box[1] && pt.x < box[2] && pt.y < box[3]) {
        in = 1;
    }
    return in;
}
BOOL fn_80272B4C(PlayerAreas* pa, const JGeometry::TVec2<f32>& pt) {
    for (int i = 0; i < 0x50; i++) {
        if (pa->mId[i] >= 0 && fn_802413F0((char*)pa) && pa->mOwner[i] == S32(pa, 0x3b4)) {
            if ((u8)inBox(pa->mBox[i], pt)) {
                return 1;
            }
        }
    }
    return 0;
}
BOOL fn_80272DCC(char* p, const f32* box, s32 a, s32 b) {
    if (GetBusyLocked(p)) {
        return 0;
    }
    PlayerAreas* pa = (PlayerAreas*)p;
    for (int i = 0; i < 0x50; i++) {
        if (pa->mId[i] < 0) {
            pa->mId[i] = b;
            pa->mOwner[i] = a;
            pa->mBox[i][0] = box[0];
            pa->mBox[i][1] = box[1];
            pa->mBox[i][2] = box[2];
            pa->mBox[i][3] = box[3];
            return 1;
        }
    }
    return 0;
}
}

extern "C" {
inline void setBoxAround(char* p, f32 r, f32 x, f32 y) {
    F32(p, 0x4c0) = x - r;
    F32(p, 0x4c4) = y - r;
    F32(p, 0x4c8) = r + x;
    F32(p, 0x4cc) = r + y;
}
void fn_80276538(char* p) {
    setBoxAround(p, 7.0f, F32(p, 0x8), F32(p, 0xc));
    F32(p, 0x4d0) = -15.0f;
    F32(p, 0x4d4) = -15.0f;
    F32(p, 0x4d8) = 15.0f;
    F32(p, 0x4dc) = 15.0f;
    F32(p, 0x4d0) += F32(p, 0x8);
    F32(p, 0x4d4) += F32(p, 0xc);
    F32(p, 0x4d8) += F32(p, 0x8);
    F32(p, 0x4dc) += F32(p, 0xc);
}
void fn_80277100(void) {}
void fn_80277104(char* p) {
    if (U8(p, 0x3fa) < 2) {
        U8(p, 0x3fb) = 0;
    } else if (U8(p, 0x3fa) < 6) {
        U8(p, 0x3fb) = 1;
    } else if (U8(p, 0x3fa) < 10) {
        U8(p, 0x3fb) = 2;
    } else {
        U8(p, 0x3fb) = 3;
    }
    if (U8(p, 0x3fa) >= 14) {
        if (U8(p, 0xcad) != 0) {
            fn_80251AEC(p, 8);
        } else {
            fn_80251AEC(p, 0);
        }
    } else {
        U8(p, 0x3fa)++;
    }
    fn_80268B3C(p);
}
void fn_802771BC(char* p) { U8(p, 0x458) = 0; }
void fn_802771C8(char* p) {
    U8(p, 0xd5c) = 0;
    killEmitter(p, 0x136c);
    killEmitter(p, 0x1370);
}
void fn_80277580(char* p) {
    if (S32(p, 0x1248) != 4) {
        S32(p, 0x45c) = 0;
        U8(p, 0x3fa) = 7;
    } else if (U8(p, 0x439) >= 7) {
        U8(p, 0x3fa) = 7;
    } else {
        U8(p, 0x3fa) = U8(p, 0x439);
    }
    U8(p, 0x458) = 0;
}
void fn_802775C8(char* p) {
    killEmitter(p, 0x137c);
    killEmitter(p, 0x1380);
}
void fn_8027761C(char* p) {
    if (U8(p, 0x3fc) >= 0x18) {
        U8(p, 0x3fd) = 3;
        fn_80251AEC(p, 0xf);
    } else {
        U8(p, 0x3fd) = (U8(p, 0x3fc) >> 1) % 3;
    }
    U8(p, 0x3fc)++;
    fn_80268B3C(p);
}
void fn_8027769C(char* p) {
    U8(p, 0x458) = 0;
    if (PTR(p, 0x137c) == NULL) {
        PTR(p, 0x137c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x285, 0, -1, 0, 0, 1, 1.0f);
    }
    if (PTR(p, 0x1380) == NULL) {
        PTR(p, 0x1380) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x286, 0, 3, 0, 0, 1, 1.0f);
    }
    fn_8024F0E8(p, 0x10013);
}
void fn_8027774C(char* p) {
    S32(p, 0x464) = 0xb4;
    U8(p, 0xd2d) = 0;
    S32(p, 0xd30) = 0;
    U8(p, 0xd35) = 0;
    U8(p, 0xc00) = 0;
}
void fn_802791AC(void) {}
void fn_8027966C(char* p) {
    S32(p, 0x464) = 0x3c;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x10004);
    F32(p, 0x358) = 0.0f;
}
void fn_80279F94(char* p) {
    DELETE_JPA(p, 0x1308);
    S32(p, 0x464) = 0x3c;
}
void fn_8027A178(char* p) {
    killEmitter(p, 0x1374);
    killEmitter(p, 0x1378);
    U16(p, 0x11c0) = 0;
    U8(p, 0xbb9) = 0;
    U8(p, 0xbd4) = 0;
    U8(p, 0xbba) = 0;
}
void fn_8027B5F0(char* p) {
    U16(p, 0x11c0) = 0;
    S32(p, 0x11ac) = 0;
    DELETE_JPA(p, 0x12bc);
}
void fn_8027C6B8(char* p) { U8(p, 0x436) = 0; }
void fn_8027CAA8(char* p) {
    U8(p, 0x458) = 0;
    U8(p, 0x436) = 1;
    char* base = (char*)PTR(p, 0x3b4);
    if (*(u8*)(fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
        F32(p, 0x348) = 0.0f;
    }
    S32(p, 0xbf4) = 8;
    fn_8024F0E8(p, 0x1000b);
}
void fn_8027CB24(char* p) {
    if (S32(p, 0x1244) != 0xf) {
        F32(p, 0x10) = 0.0f;
    }
    U8(p, 0x436) = 0;
}
void fn_8027CB44(char* p) {
    if (U8(p, 0x3fa) < 0xf) {
        U8(p, 0x3fa)++;
    } else {
        fn_80251AEC(p, 0);
    }
    U8(p, 0x3fb) = 2;
    fn_802685D4(p);
}
void fn_8027CB9C(char* p) {
    U8(p, 0x458) = 0;
    U8(p, 0x436) = 1;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
