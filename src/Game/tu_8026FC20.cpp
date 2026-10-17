// TU 0x8026fc20-0x8027e5bc: player-class methods (Link object, see tu_8023FBF0).
// A few small bodies originally from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define U16(p, o) (*(u16*)((char*)(p) + (o)))
#define S16(p, o) (*(s16*)((char*)(p) + (o)))
#define S32(p, o) (*(s32*)((char*)(p) + (o)))
#define F32(p, o) (*(f32*)((char*)(p) + (o)))
#define PTR(p, o) (*(void**)((char*)(p) + (o)))

#pragma auto_inline off

struct Vec2f {
    f32 x, y;
};

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
void* fn_8013CC50(void* a, void* pos, s32 kind, s32 b, s32 c, s32 d, void* e, s32 f, f32 scale);
s32 Actor_CreateByID(void* mgr, u32 id, void* owner, void* pos, u32 param, s32 a, s32 b);
void* fn_801F856C(void);
void* fn_801F666C(void* mgr, s32 id);
bool fn_8025F418(char*);
void fn_80231194(s32);
extern char* lbl_8053AAF8;
bool fn_8025F448(void);
void fn_8025FEDC(char*);
void fn_8025F698(char*, s32);
void fn_8024EFF8(char*, s32);
void fn_802382D0(s32, s32);
s32 fn_802376D8(s32);
void fn_8027EB04(char*);

bool fn_802576CC(void*, void*, void*, void*);
bool fn_802575B8(void*, void*, void*, void*);
bool fn_802574CC(void*, void*, void*, void*);
bool fn_802570BC(void*, void*, void*, void*);
u8 fn_80256F44(void*, void*, void*, void*);
bool fn_802573E0(void*, void*, void*, void*);
u8 fn_802738F0(char*, JGeometry::TBox2<f32>*, f32*, s32, s32);
u8 fn_80273FB8(char*, const JGeometry::TBox2<f32>*, s32, f32*);
s32 fn_80241864(char*);
s32 fn_80241544(char*);
bool fn_80241200(char*);
s32 fn_802486A0(char*);
s32 fn_80248778(char*);
s32 fn_80240888(char*);
BOOL fn_80270ABC(char*);
u8 fn_80251AEC(char*, s32);
void fn_8024F0E8(char*, s32);
void fn_80268B3C(char*);
void fn_802685D4(char*);
char* fn_802D6A9C(void);
bool fn_802413F0(char*);
u8 fn_802412CC(char*);
u8 fn_802411D8(char*);
s32 fn_80247BD4(char*);
extern const f32 lbl_8046BB48[][3];
void fn_8024E46C(char*);
void fn_8024E3D8(char*);
void fn_8024E344(char*);
u8 Player_GetField_0xce8(char*);
void fn_8024B298(char*, s32, f32*);
u8 fn_80274238(char*, const JGeometry::TBox2<f32>*, s32, f32*, s32);
s32 fn_8024FF84(char*);
s32 fn_8024FF6C(char*);
bool fn_80250D30(char*);
bool fn_8024FEFC(char*);
extern const Vec2f lbl_8046BD68[];
extern const Vec2f lbl_8046BD48[];
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

inline void stopEmitter(char* p, s32 off) {
    if (PTR(p, off) != NULL) {
        ((EmitterObj*)PTR(p, off))->mF4 &= ~0x40;
        EmitterObj* e = (EmitterObj*)PTR(p, off);
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

inline bool isDying(char* p) {
    bool r;
    if (S32(p, 0x1244) == 0x33 || S32(p, 0x1240) == 0x33 || S32(p, 0x1240) == 0x34) {
        r = true;
    } else {
        r = false;
    }
    return r;
}

inline bool isDead(char* p) {
    bool r;
    if (U8(p, 0xd2d) != 0 || S32(p, 0x1244) == 0x34 || S32(p, 0x1240) == 0x34) {
        r = true;
    } else {
        r = false;
    }
    return r;
}

struct Vec3 {
    f32 x, y, z;
    void set(f32 ax, f32 ay, f32 az) {
        x = ax;
        y = ay;
        z = az;
    }
};

inline BOOL inBox2(const f32* box, f32 x, f32 y) {
    BOOL in = 0;
    if (x >= box[0] && y >= box[1] && x < box[2] && y < box[3]) {
        in = 1;
    }
    return in;
}

inline BOOL inRect(const JGeometry::TVec2<f32>& pt, f32 x0, f32 y0, f32 x1, f32 y1) {
    BOOL in = 0;
    if (pt.x >= x0 && pt.y >= y0 && pt.x < x1 && pt.y < y1) {
        in = 1;
    }
    return in;
}

struct PlayerAreas2 {
    u8 pad0[0xef0];
    s32 mId[0x50];
};

struct PlayerPos {
    u8 pad0[0x8];
    JGeometry::TVec3<f32> pos;
};

struct PlayerOfs {
    u8 pad0[0x8];
    JGeometry::TVec3<f32> pos;
    u8 pad14[0x12a4 - 0x14];
    JGeometry::TVec3<f32> ofs;
};

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
inline void clearCombo(char* p) {
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
f32 fn_80246F28(char*);
f32 fn_80247330(char*);
f32 fn_8024712C(char*);
inline void pushDir(char* p, s32 i) {
    U8(p, 0x11a8 + i) = U8(p, 0x11a4 + i);
    U8(p, 0x11a4 + i) = U8(p, 0x11a0 + i);
    U8(p, 0x11a0 + i) = U8(p, 0x119c + i);
    U8(p, 0x119c + i) = 1;
}
inline void decPos(char* p, s32 o) {
    if (S32(p, o) > 0) {
        S32(p, o)--;
    }
}
void fn_8026FD14(char* p) {
    if (fn_80246F28(p) > 0.0f) {
        if (S32(p, 0x11c8) >= 3) {
            S32(p, 0x11c4) = 3;
        } else if (S32(p, 0x11c4) > 0) {
            S32(p, 0x11c4)--;
        }
        S32(p, 0x11c8) = 0;
    } else {
        if (S32(p, 0x11c8) < 3) {
            S32(p, 0x11c8)++;
        }
        decPos(p, 0x11c4);
    }
    decPos(p, 0x11d4);
    decPos(p, 0x11cc);
    if (fn_80247330(p) > 0.0f && 0.0f == fn_8024712C(p)) {
        S32(p, 0x117c) = 60;
        if (S32(p, 0x1184) < S32(p, 0x1180) && S32(p, 0x1188) < S32(p, 0x1180)) {
            S32(p, 0x1184) = 0;
        }
    } else {
        decPos(p, 0x117c);
    }
    if (fn_80247330(p) < 0.0f && 0.0f == fn_8024712C(p)) {
        S32(p, 0x1180) = 60;
        if (S32(p, 0x1184) < S32(p, 0x117c) && S32(p, 0x1188) < S32(p, 0x117c)) {
            S32(p, 0x1184) = 0;
        }
    } else {
        decPos(p, 0x1180);
    }
    if (fn_8024712C(p) < 0.0f && 0.0f == fn_80247330(p)) {
        S32(p, 0x1184) = 60;
        if (S32(p, 0x117c) < S32(p, 0x1188) && S32(p, 0x1180) < S32(p, 0x1188)) {
            S32(p, 0x1184) = 0;
        }
    } else {
        decPos(p, 0x1184);
    }
    if (fn_8024712C(p) > 0.0f && 0.0f == fn_80247330(p)) {
        S32(p, 0x1188) = 60;
        if (S32(p, 0x117c) < S32(p, 0x1184) && S32(p, 0x1180) < S32(p, 0x1184)) {
            S32(p, 0x1184) = 0;
        }
    } else {
        decPos(p, 0x1188);
    }
    if (fn_80247330(p) <= 0.0f) {
        U8(p, 0x119c) = 0; U8(p, 0x11a0) = 0; U8(p, 0x11a4) = 0; U8(p, 0x11a8) = 0;
    }
    if (fn_80247330(p) >= 0.0f) {
        U8(p, 0x119d) = 0; U8(p, 0x11a1) = 0; U8(p, 0x11a5) = 0; U8(p, 0x11a9) = 0;
    }
    if (fn_8024712C(p) >= 0.0f) {
        U8(p, 0x119e) = 0; U8(p, 0x11a2) = 0; U8(p, 0x11a6) = 0; U8(p, 0x11aa) = 0;
    }
    if (fn_8024712C(p) <= 0.0f) {
        U8(p, 0x119f) = 0; U8(p, 0x11a3) = 0; U8(p, 0x11a7) = 0; U8(p, 0x11ab) = 0;
    }
    for (s32 i = 0; i < 4; i++) {
        decPos(p + i * 4, 0x118c);
    }
}
void fn_80270088(char* p) {
    if (fn_80246F28(p) > 0.0f) {
        if (U8(p, 0x119c) == 0 && U8(p, 0x119d) == 0 && U8(p, 0x119e) == 0 && U8(p, 0x119f) == 0) {
            S32(p, 0x1198) = 0;
            S32(p, 0x1194) = 0;
            S32(p, 0x1190) = 0;
            S32(p, 0x118c) = 0;
        }
    } else if (U8(p, 0x119c) == 1 || U8(p, 0x119d) == 1 || U8(p, 0x119e) == 1 || U8(p, 0x119f) == 1) {
        S32(p, 0x1198) = 0;
        S32(p, 0x1194) = 0;
        S32(p, 0x1190) = 0;
        S32(p, 0x118c) = 0;
    }
    S32(p, 0x1198) = S32(p, 0x1194);
    S32(p, 0x1194) = S32(p, 0x1190);
    S32(p, 0x1190) = S32(p, 0x118c);
    S32(p, 0x118c) = 0x3c;
    if (fn_80247330(p) > 0.0f) {
        pushDir(p, 0);
    }
    if (fn_80247330(p) < 0.0f) {
        pushDir(p, 1);
    }
    if (fn_8024712C(p) < 0.0f) {
        pushDir(p, 2);
    }
    if (fn_8024712C(p) > 0.0f) {
        pushDir(p, 3);
    }
}
void fn_8027023C(char* p) { clearCombo(p); }
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
void fn_80270360(char* p, s32 id) {
    if (S32(p, 0xc50) < 9999999) {
        S32(p, 0xc50) += 1;
    }
    char* a = (char*)fn_801F666C(fn_801F856C(), id);
    if (a == NULL) {
        return;
    }
    s32 kind;
    switch (S32(a, 0x1a0)) {
    case 'OKTA': kind = 0; break;
    case 'AMOS': kind = 1; break;
    case 'POOH': kind = 2; break;
    case 'BZBR': kind = 3; break;
    case 'DDRK': kind = 4; break;
    case 'DGTL': kind = 5; break;
    case 'HINO': kind = 6; break;
    case 'SLR1': kind = 7; break;
    case 'TKTA': kind = 8; break;
    case 'SLR2': kind = 7; break;
    case 'KETH': kind = 9; break;
    case 'BPOH': kind = 10; break;
    case 'MOZO': kind = 11; break;
    case 'Poon': kind = 12; break;
    default: kind = 13; break;
    }
    if (kind < 13) {
        s32* c = (s32*)(p + kind * 4);
        if (c[0xc1c / 4] < 9999999) {
            c[0xc1c / 4] += 1;
        }
    }
}
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
    if (isDying(p)) {
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
BOOL fn_80270ABC(char* p) {
    if (U8(p, 0xce8) == 1) {
        return 1;
    }
    if (U8(p, 0xcee) == 1) {
        return 1;
    }
    if (U8(p, 0x1216) != 0) {
        return 1;
    }
    if (U8(p, 0x1215) != 0) {
        return 1;
    }
    if (U8(p, 0xcf0) == 1) {
        return 1;
    }
    if (fn_802412CC(p) == 1) {
        return 1;
    }
    if (fn_802411D8(p) == 1) {
        return 1;
    }
    if (isDying(p)) {
        return 1;
    }
    if (isDead(p)) {
        return 1;
    }
    if (Player_IsLinked(p) && fn_802486A0(p) == 5) {
        return 1;
    }
    if (S32(p, 0x1240) == 1) {
        return 1;
    }
    if (S32(p, 0x1240) == 0x19 || S32(p, 0x1244) == 0x19) {
        return 1;
    }
    if (fn_80247BD4(p) > 0) {
        return 1;
    }
    if (S32(p, 0x468) > 0) {
        return 1;
    }
    return S32(p, 0x464) > 0;
}
inline BOOL isBusy(char* p) {
    if (fn_80241200(p)) {
        return 1;
    }
    if (fn_802486A0(p) == 4) {
        s32 v = fn_80248778(p);
        s32 w = fn_80240888(p);
        if (w != v) {
            return 1;
        }
    }
    return fn_80270ABC(p);
}
BOOL fn_80270C88(char* p) { return isBusy(p); }
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
inline void addLife(char* p, s32 n, u8 flag) {
    if (U8(p, 0xd35) != 0) {
        return;
    }
    if (U8(lbl_8053AAF8, 0x7f) == 0 && (U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 0x4)))) {
        if (S32(p, 0xbfc) <= 0 || isDying(p)) {
            return;
        }
    }
    s32 old = S32(p, 0xbfc);
    S32(p, 0xbfc) = old + 1;
    if (S32(p, 0xbfc) == old) {
        for (;;) {}
    }
    S32(p, 0xbfc) = old;
    if (Player_IsLinked(p)) {
        S32(p, 0xbfc) = fn_802376D8(Player_GetLinkTargetIndex(p));
    } else {
        S32(p, 0xbfc) += n;
    }
    if (S32(p, 0xbfc) > S32(p, 0xbf8)) {
        S32(p, 0xbfc) = S32(p, 0xbf8);
    }
    U8(p, 0xd35) = flag;
}
u8 fn_80236890(void);
u8 fn_8022E438(s32, s32);
s32 fn_802417CC(char*);
u8 fn_80243194(char*, s32);
void fn_802363DC(s32);
u8 fn_80239D38(void);
s32 fn_801F7A08(void*, s32);
u8 fn_80236B50(s32);
u8 fn_80236AB4(s32);
void fn_80236350(s32);
inline u8 isStage7() { return S32(lbl_8053AAF8, 0x4c) == 7; }
void fn_8027057C(char* p) {
    if (U8(lbl_8053AAF8, 0x7f) == 0 && (U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 0x4)))) {
        return;
    }
    if (U8(lbl_8053AAF8, 0x7e) != 0 && fn_80236890()) {
        return;
    }
    if (U8(p, 0xd2d) == 1) {
        return;
    }
    if (U8(p, 0xd2c) == 1) {
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0)) {
            addLife(p, fn_802417CC(p) - 4, 0);
            S32(p, 0x464) = 0xb4;
            U8(p, 0xd2c) = 0;
            *(JGeometry::TVec3<f32>*)(p + 0x8) = *(JGeometry::TVec3<f32>*)(p + 0xd10);
            S32(p, 0x3b4) = 0;
            U8(p, 0xcfc) = 0;
        }
    } else if (U8(p, 0xcfd) == 1 && F32(p, 0x10) <= 0.0f && F32(p, 0x1c) > 0.0f && U8(lbl_8053AAF8, 0x7e) != 0) {
        for (s32 i = 0; i < 4; i++) {
            if (fn_80243194(p, i)) {
                fn_802363DC(i);
            }
        }
    } else if (U8(p, 0xd35) == 1) {
        U8(p, 0x124d) = 0;
        if (fn_80251AEC(p, 0x34)) {
            U8(p, 0xcfc) = 0;
            U8(p, 0xd34) = 1;
        }
    } else if (isStage7() && U8(lbl_8053AAF8, 0x7f) != 0 && U8(lbl_8053AAF8, 0x7e) != 0 && !((u8(*)(char*))fn_8025F448)(p) &&
               !fn_80239D38() && S32(p, 0x494) > 0) {
        S32(p, 0x494)--;
        if (S32(p, 0x494) == 0) {
            if (fn_801F7A08(fn_801F856C(), 'TNGL') >= 0) {
                S32(p, 0x494) = 1;
            } else {
                U8(p, 0xcfc) = 0;
                for (s32 i = 0; i < 4; i++) {
                    if (fn_8022E438(S32(p, 0x4), i) && fn_80236B50(i) && !fn_80236AB4(i)) {
                        fn_80236350(i);
                    }
                }
            }
        }
    }
}
void fn_80270DDC(char* p, s32 n, u8 flag) {
    if (U8(p, 0xd35) != 0) {
        return;
    }
    if (U8(lbl_8053AAF8, 0x7f) == 0 && (U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 0x4)))) {
        if (S32(p, 0xbfc) <= 0 || isDying(p)) {
            return;
        }
    }
    s32 old = S32(p, 0xbfc);
    S32(p, 0xbfc) = old + 1;
    if (S32(p, 0xbfc) == old) {
        for (;;) {}
    }
    S32(p, 0xbfc) = old;
    if (Player_IsLinked(p)) {
        S32(p, 0xbfc) = fn_802376D8(Player_GetLinkTargetIndex(p));
    } else {
        S32(p, 0xbfc) += n;
    }
    if (S32(p, 0xbfc) > S32(p, 0xbf8)) {
        S32(p, 0xbfc) = S32(p, 0xbf8);
    }
    U8(p, 0xd35) = flag;
}
void fn_80270F00(char* p, s32 n) {
    S32(p, 0xbf8) += n;
    if (S32(p, 0xbf8) > 0x20) {
        S32(p, 0xbf8) = 0x20;
    }
    addLife(p, S32(p, 0xbf8), 0);
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
inline BOOL inBox(const f32* box, const f32* pt) {
    BOOL in = 0;
    f32 x = pt[0];
    f32 y;
    if (x >= box[0] && (y = pt[1]) >= box[1] && x < box[2] && y < box[3]) {
        in = 1;
    }
    return in;
}
bool fn_80272768(char* p, const f32* box, s32 room, s32 id) {
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    if (fn_8024FF84(p) >= 0 && id != fn_8024FF84(p)) {
        return 0;
    }
    if (!fn_80250D30(p)) {
        return 0;
    }
    f32 x = F32(p, 0x8);
    f32 y = F32(p, 0xc);
    x += lbl_8046BD68[S32(p, 0x3dc)].x;
    y += lbl_8046BD68[S32(p, 0x3dc)].y;
    BOOL in = inBox2(box, x, y);
    if (!(u8)in) {
        return 0;
    }
    if (S32(p, 0xd94) < 0) {
        S32(p, 0xd94) = id;
    }
    return 1;
}
bool fn_802728AC(char* p, const f32* box, s32 room, s32 id) {
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    if (fn_8024FF6C(p) >= 0 && id != fn_8024FF6C(p)) {
        return 0;
    }
    if (!fn_8024FEFC(p)) {
        return 0;
    }
    f32 x = F32(p, 0x8);
    f32 y = F32(p, 0xc);
    x += lbl_8046BD48[S32(p, 0x3dc)].x;
    y += lbl_8046BD48[S32(p, 0x3dc)].y;
    BOOL in = inBox2(box, x, y);
    if (!(u8)in) {
        return 0;
    }
    if (S32(p, 0xda4) < 0) {
        S32(p, 0xda4) = id;
    }
    return 1;
}
bool fn_802729F0(char* p, s32 id) {
    for (int i = 0; i < 0x48; i += 9) {
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
        if (S32(p, 0xef0) >= 0 && S32(p, 0xef0) == id) {
            return 1;
        }
        p += 4;
    }
    return 0;
}
BOOL fn_80272B4C(PlayerAreas* pa, const f32* pt) {
    for (int i = 0; i < 0x50; i++) {
        if (pa->mId[i] >= 0 && fn_802413F0((char*)pa) && pa->mOwner[i] == S32(pa, 0x3b4)) {
            if ((u8)inBox(pa->mBox[i], pt)) {
                return 1;
            }
        }
    }
    return 0;
}
BOOL fn_80272C20(char* p, const f32* box, s32 a, s32 b) {
    if (GetBusyLocked(p)) {
        return 0;
    }
    if (Player_GetField_0xce8(p)) {
        return 0;
    }
    if (U8(p, 0xcee) == 1) {
        return 0;
    }
    f32 x0 = box[0];
    f32 y0 = box[1];
    f32 x1 = box[2];
    f32 y1 = box[3];
    x0 -= 2.5f;
    y0 -= 2.5f;
    x1 += 2.5f;
    y1 += 2.5f;
    for (s32 i = 0; i < 8; i++) {
        JGeometry::TVec2<f32> pt;
        fn_8024B298(p, i, &pt.x);
        if (!(u8)inRect(pt, x0, y0, x1, y1)) {
            goto add;
        }
    }
    return 0;
add:
    PlayerAreas* pa = (PlayerAreas*)p;
    for (int j = 0; j < 0x50; j++) {
        if (pa->mId[j] < 0) {
            pa->mId[j] = b;
            pa->mOwner[j] = a;
            pa->mBox[j][0] = box[0];
            pa->mBox[j][1] = box[1];
            pa->mBox[j][2] = box[2];
            pa->mBox[j][3] = box[3];
            return 1;
        }
    }
    return 0;
}
inline f32* roomOffset(s32 room) {
    char* r = fn_802D6A9C();
    return room < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
}
u8 fn_80245938(char*);
u8 fn_8025F2CC(char*);
u8 fn_80251BFC(char*, s32);
bool fn_80272E98(char* p, const JGeometry::TBox2<f32>* box, s32 room) {
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    if (F32(p, 0x10) > 0.0f) {
        return 0;
    }
    if (!fn_80245938(p)) {
        return 0;
    }
    if (!fn_8025F2CC(p)) {
        return 0;
    }
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (!fn_80251BFC(p, 0x11)) {
        return 0;
    }
    JGeometry::TBox2<f32> b(*box);
    f32* o = roomOffset(room);
    JGeometry::TVec2<f32> n;
    n.x = -o[0];
    n.y = -o[1];
    b.addPos(n);
    JGeometry::TBox2<f32> m(*(JGeometry::TBox2<f32>*)(p + 0x4d0));
    f32* o2 = roomOffset(S32(p, 0x3b4));
    JGeometry::TVec2<f32> n2;
    n2.x = -o2[0];
    n2.y = -o2[1];
    m.addPos(n2);
    m.i.setMax(b.i);
    m.f.setMin(b.f);
    bool r = 0;
    if (m.f.x >= m.i.x && m.f.y >= m.i.y) {
        r = 1;
    }
    return r;
}
extern "C" u8 fn_8025F590(char*);
extern "C" u8 Player_GetField_0x454(char*);
inline bool boxHit(const JGeometry::TBox2<f32>& m, const JGeometry::TBox2<f32>& b) {
    JGeometry::TBox2<f32> c(m);
    c.i.setMax(b.i);
    c.f.setMin(b.f);
    bool r = 0;
    if (c.f.x >= c.i.x && c.f.y >= c.i.y) {
        r = 1;
    }
    return r;
}
bool fn_80273518(char* p, const JGeometry::TBox2<f32>* box, s32 room, f32* out) {
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (GetBusyLocked(p)) {
        return 0;
    }
    if (Player_GetField_0x454(p)) {
        return 0;
    }
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    JGeometry::TBox2<f32> b(*box);
    f32* o = roomOffset(room);
    JGeometry::TVec2<f32> n;
    n.x = -o[0];
    n.y = -o[1];
    b.addPos(n);
    if (room != S32(p, 0x3b4) && (S32(p, 0x3b4) != 8 || room >= 8)) {
        return 0;
    }
    if (U8(p, 0x459) != 0) {
        if (fn_8025F590(p)) {
            JGeometry::TBox2<f32> m(-8.0f, -8.0f, 8.0f, 8.0f);
            f32* o2 = roomOffset(S32(p, 0x3b4));
            m.addPos(-o2[0], -o2[1]);
            m.addPos(F32(p, 0x2f4), F32(p, 0x2f8));
            if (boxHit(m, b)) {
                out[0] = 0.5f * (m.i.x - m.f.x) + m.f.x;
                out[1] = 0.5f * (m.i.y - m.f.y) + m.f.y;
                return 1;
            }
        } else {
            char* obj = (char*)fn_801F666C(fn_801F856C(), S32(p, 0xd68));
            if (obj != NULL) {
                JGeometry::TBox2<f32> m(*(JGeometry::TBox2<f32>*)(obj + 0x60));
                f32* o2 = roomOffset(S32(p, 0x3b4));
                m.addPos(-o2[0], -o2[1]);
                m.addPos(F32(p, 0x2f4), F32(p, 0x2f8));
                if (boxHit(m, b)) {
                    out[0] = 0.5f * (m.i.x - m.f.x) + m.f.x;
                    out[1] = 0.5f * (m.i.y - m.f.y) + m.f.y;
                    (*(void (**)(char*))(*(char**)obj + 0x48))(obj);
                    return 1;
                }
            }
        }
    }
    return 0;
}
s32 fn_80241864(char*);
bool fn_802724E0(char* p, const JGeometry::TBox2<f32>* box, s32 room) {
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (room != S32(p, 0x3b4) && (S32(p, 0x3b4) >= 8 || room != 8)) {
        return 0;
    }
    if (F32(p, 0x10) > 0.0f) {
        return 0;
    }
    bool ok;
    if (isDying(p)) {
        ok = 0;
        if (fn_80241864(p) <= 0 && U8(p, 0xcfc) != 0) {
            ok = 1;
        }
        if (ok) {
            goto hit;
        }
    }
    if (!fn_80251BFC(p, 0x19)) {
        return 0;
    }
hit:
    JGeometry::TBox2<f32> b(*box);
    f32* o = roomOffset(room);
    JGeometry::TVec2<f32> n;
    n.x = -o[0];
    n.y = -o[1];
    b.addPos(n);
    JGeometry::TBox2<f32> m(*(JGeometry::TBox2<f32>*)(p + 0x4d0));
    f32* o2 = roomOffset(S32(p, 0x3b4));
    JGeometry::TVec2<f32> n2;
    n2.x = -o2[0];
    n2.y = -o2[1];
    m.addPos(n2);
    m.i.setMax(b.i);
    m.f.setMin(b.f);
    bool r = 0;
    if (m.f.x >= m.i.x && m.f.y >= m.i.y) {
        r = 1;
    }
    return r;
}
bool fn_80272224(char* p, const f32* box, s32 room, s32 dir, u8 fx, u8 snd) {
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    if (F32(p, 0x10) > 0.0f) {
        return 0;
    }
    if (U8(p, 0xb98) == 0) {
        return 0;
    }
    if (Player_IsLinked(p) && fn_802486A0(p) == 5) {
        return 0;
    }
    if (fn_80241200(p)) {
        return 0;
    }
    if (dir < 0) {
        return 0;
    }
    if (S32(p, 0x3ec) >= 0 && dir >= 0) {
        switch (S32(p, 0x3ec)) {
        case 0:
            if (dir != 1) return 0;
            break;
        case 1:
            if (dir != 0) return 0;
            break;
        case 2:
            if (dir != 3) return 0;
            break;
        case 3:
            if (dir != 2) return 0;
            break;
        }
    }
    JGeometry::TBox2<f32>* pb = (JGeometry::TBox2<f32>*)(p + 0x5ec);
    JGeometry::TBox2<f32> b(*pb);
    const JGeometry::TBox2<f32>* o = (const JGeometry::TBox2<f32>*)box;
    b.i.setMax(o->i);
    b.f.setMin(o->f);
    bool hit = 0;
    if (b.f.x >= b.i.x && b.f.y >= b.i.y) {
        hit = 1;
    }
    if (hit) {
        if (fx == 1 && S32(p, 0x3f4) <= 0) {
            JGeometry::TVec3<f32> v;
            v.x = 0.5f * (pb->i.x - pb->f.x) + pb->f.x;
            v.y = 0.5f * (pb->i.y - pb->f.y) + pb->f.y;
            v.z = F32(p, 0x10);
            fn_8013CC50(PTR(p, 0x3b4), &v, 0x117, 1, 1, 0, NULL, 1, 1.0f);
            fn_8013CC50(PTR(p, 0x3b4), &v, 0x118, 1, 1, 0, NULL, 1, 1.0f);
        }
        if (snd == 1 && S32(p, 0x3f4) <= 0) {
            fn_8024F0E8(p, 0x20003);
        }
        S32(p, 0x3f4) = 5;
        return 1;
    }
    return 0;
}
u8 Player_GetField_0x454(char*);
inline bool areaTail(char* p, const f32* box, f32 h) {
    char* base = (char*)PTR(p, 0x3b4);
    if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) == 0 && F32(p, 0x10) > h) {
        return 0;
    }
    if (U8(p, 0xcee) != 0) {
        return 0;
    }
    if (U8(p, 0x1216) != 0) {
        return 0;
    }
    if (U8(p, 0x1215) != 0) {
        return 0;
    }
    if (U8(p, 0xcf0) != 0) {
        return 0;
    }
    if (S32(p, 0x1238) > 0) {
        return 0;
    }
    if (!fn_802413F0(p)) {
        return 0;
    }
    JGeometry::TBox2<f32> b(*(JGeometry::TBox2<f32>*)(p + 0x4c0));
    const JGeometry::TBox2<f32>* o = (const JGeometry::TBox2<f32>*)box;
    b.i.setMax(o->i);
    b.f.setMin(o->f);
    bool r = 0;
    if (b.f.x >= b.i.x && b.f.y >= b.i.y) {
        r = 1;
    }
    return r;
}
inline bool areaCheck(char* p, const f32* box, s32 room, u8 force, f32 h) {
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    if (!force && isDying(p)) {
        return 0;
    }
    if (Player_GetField_0x454(p)) {
        return 0;
    }
    return areaTail(p, box, h);
}
inline BOOL areaTailB(char* p, const f32* box, f32 h) {
    char* base = (char*)PTR(p, 0x3b4);
    if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) == 0 && F32(p, 0x10) > h) {
        return 0;
    }
    if (U8(p, 0xcee) != 0) {
        return 0;
    }
    if (U8(p, 0x1216) != 0) {
        return 0;
    }
    if (U8(p, 0x1215) != 0) {
        return 0;
    }
    if (U8(p, 0xcf0) != 0) {
        return 0;
    }
    if (S32(p, 0x1238) > 0) {
        return 0;
    }
    if (!fn_802413F0(p)) {
        return 0;
    }
    JGeometry::TBox2<f32> b(*(JGeometry::TBox2<f32>*)(p + 0x4c0));
    const JGeometry::TBox2<f32>* o = (const JGeometry::TBox2<f32>*)box;
    b.i.setMax(o->i);
    b.f.setMin(o->f);
    BOOL r = 0;
    if (b.f.x >= b.i.x && b.f.y >= b.i.y) {
        r = 1;
    }
    return r;
}
inline BOOL areaCheckB(char* p, const f32* box, s32 room, u8 force, f32 h) {
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    if (!force && isDying(p)) {
        return 0;
    }
    if (Player_GetField_0x454(p)) {
        return 0;
    }
    return areaTailB(p, box, h);
}
bool fn_802730D8(char* p, const f32* box, s32 room, u8 force, f32 h) { return areaCheck(p, box, room, force, h); }
bool fn_802732C4(char* p, const f32* box, s32 room) {
    if ((u8)isBusy(p)) {
        return 0;
    }
    if (U8(p, 0x42c) != 0) {
        return 0;
    }
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    if (isDying(p)) {
        return 0;
    }
    if (Player_GetField_0x454(p)) {
        return 0;
    }
    return areaTail(p, box, 0.0f);
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
inline void setAround(JGeometry::TBox2<f32>* b, const JGeometry::TVec2<f32>& c, f32 r) {
    b->set(c.x - r, c.y - r, r + c.x, r + c.y);
}
inline bool boxOverlap(const JGeometry::TBox2<f32>& a, const JGeometry::TBox2<f32>* o) {
    JGeometry::TBox2<f32> b(a);
    b.i.setMax(o->i);
    b.f.setMin(o->f);
    bool r = 0;
    if (b.f.x >= b.i.x && b.f.y >= b.i.y) {
        r = 1;
    }
    return r;
}
u8 fn_802738F0(char* p, JGeometry::TBox2<f32>* box, f32* out, s32 a, s32 b) {
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (GetBusyLocked(p)) {
        return 0;
    }
    if (Player_GetField_0x454(p)) {
        return 0;
    }
    if (U8(p, 0x458) == 1) {
        JGeometry::TBox2<f32> body(*(JGeometry::TBox2<f32>*)(p + 0x4a0));
        f32* o = roomOffset(S32(p, 0x3b4));
        JGeometry::TVec2<f32> n;
        n.x = -o[0];
        n.y = -o[1];
        body.addPos(n);
        JGeometry::TBox2<f32> atk(*(JGeometry::TBox2<f32>*)(p + 0x4b0));
        f32* o2 = roomOffset(S32(p, 0x3b4));
        JGeometry::TVec2<f32> n2;
        n2.x = -o2[0];
        n2.y = -o2[1];
        atk.addPos(n2);
        if (boxOverlap(body, box)) {
            out[0] = (atk.f.x + (atk.i.x + (body.i.x + body.f.x))) / 4.0f;
            out[1] = (atk.f.y + (atk.i.y + (body.i.y + body.f.y))) / 4.0f;
            return 1;
        }
        if ((u8)a && boxOverlap(atk, box)) {
            if ((u8)b) {
                out[0] = (atk.f.x + (atk.i.x + (body.i.x + body.f.x))) / 4.0f;
                out[1] = (atk.f.y + (atk.i.y + (body.i.y + body.f.y))) / 4.0f;
                return 1;
            }
            out[0] = 0.5f * (atk.i.x - atk.f.x) + atk.f.x;
            out[1] = 0.5f * (atk.i.y - atk.f.y) + atk.f.y;
            return 1;
        }
    }
    return 0;
}
bool fn_80273C30(void* a, void* b, void* c, void* d) {
    if (((bool (*)(void*, void*, void*, void*))fn_80274238)(a, b, c, d)) {
        return 1;
    }
    if (fn_802576CC(a, b, c, d)) {
        return 1;
    }
    if (fn_802575B8(a, b, c, d)) {
        return 1;
    }
    if (fn_802574CC(a, b, c, d)) {
        return 1;
    }
    if (fn_802570BC(a, b, c, d)) {
        return 1;
    }
    return fn_80256F44(a, b, c, d) != 0;
}
bool fn_80273D44(void* a, void* b, void* c, void* d) {
    if (((bool (*)(void*, void*, void*, void*))fn_80274238)(a, b, c, d)) {
        return 1;
    }
    if (fn_802576CC(a, b, c, d)) {
        return 1;
    }
    if (fn_802575B8(a, b, c, d)) {
        return 1;
    }
    if (fn_802574CC(a, b, c, d)) {
        return 1;
    }
    if (fn_802573E0(a, b, c, d)) {
        return 1;
    }
    if (fn_802570BC(a, b, c, d)) {
        return 1;
    }
    return fn_80256F44(a, b, c, d) != 0;
}
inline u8 hitCheck8(char* p, const f32* box, s32 room) {
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    if (isDying(p)) {
        return 0;
    }
    if (Player_GetField_0x454(p)) {
        return 0;
    }
    return areaTail(p, box, 8.0f);
}
u8 fn_80273FB8(char* p, const JGeometry::TBox2<f32>* bx, s32 room, f32* out) {
    const f32* box = (const f32*)bx;
    U8(p, 0x492) = 0;
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    BOOL r = 0;
    if (fn_80247BD4(p) > 0) {
        r = areaCheckB(p, box, room, 0, 8.0f);
        if ((u8)r == 1) {
            out[0] = F32(p, 0x8);
            out[1] = F32(p, 0xc);
        }
        U8(p, 0x492) = 1;
    }
    if ((u8)r == 1) {
        f32* o = roomOffset(room);
        out[0] += o[0];
        out[1] += o[1];
    }
    return (u8)r;
}
u8 fn_80273E7C(char* p, const JGeometry::TBox2<f32>* box, s32 room, f32* out, s32 arg) {
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    JGeometry::TBox2<f32> b(*box);
    f32* o = roomOffset(room);
    JGeometry::TVec2<f32> n;
    n.x = -o[0];
    n.y = -o[1];
    b.addPos(n);
    u8 r = fn_802738F0(p, &b, out, arg, 0);
    if (r == 1) {
        f32* o2 = roomOffset(room);
        out[0] += o2[0];
        out[1] += o2[1];
    }
    return (u8)r;
}
u8 fn_80274238(char* p, const JGeometry::TBox2<f32>* box, s32 room, f32* out, s32 arg) {
    U8(p, 0x492) = 0;
    if (!fn_802413F0(p)) {
        return 0;
    }
    if (room != S32(p, 0x3b4)) {
        return 0;
    }
    JGeometry::TBox2<f32> b(*box);
    f32* o = roomOffset(room);
    JGeometry::TVec2<f32> n;
    n.x = -o[0];
    n.y = -o[1];
    b.addPos(n);
    u8 r = fn_802738F0(p, &b, out, arg, 1);
    if (r == 1) {
        f32* o2 = roomOffset(room);
        out[0] += o2[0];
        out[1] += o2[1];
    }
    if (!(u8)r) {
        r = fn_80273FB8(p, box, room, out);
    }
    return (u8)r;
}
u8 fn_8023434C(s32);
void fn_802765C0(char*);
inline bool isSolo(char* p) { return fn_802486A0(p) == 3 && !fn_8023434C(S32(p, 0x4)); }
void fn_80274728(char* p) {
    if (fn_802486A0(p) == 3 && !fn_8023434C(S32(p, 0x4))) {
        U8(p, 0x3fa)++;
    } else if (U8(p, 0x3fa) >= 0xe && U8(p, 0x3fa) < 0x25) {
        U8(p, 0x3fa) += 2;
        if (U8(p, 0x3fa) > 0x25) {
            U8(p, 0x3fa) = 0x25;
        }
    } else {
        U8(p, 0x3fa)++;
    }
    S16(p, 0x11c0) = 0;
    if (U8(p, 0x3fa) < 6) {
        U8(p, 0x3fb) = 8;
    } else if (U8(p, 0x3fa) < 8) {
        U8(p, 0x3fb) = 9;
    } else if (U8(p, 0x3fa) < 9) {
        U8(p, 0x3fb) = 10;
    } else if (U8(p, 0x3fa) < 10) {
        U8(p, 0x3fb) = 0;
    } else if (U8(p, 0x3fa) < 0x1f) {
        U8(p, 0x3fb) = ((U8(p, 0x3fa) - 10) / 3 + 1) & 7;
        S16(p, 0x11c0) = (U8(p, 0x3fa) - 10) * 0xaaa;
    } else if (U8(p, 0x3fa) < 0x21) {
        U8(p, 0x3fb) = ((U8(p, 0x3fa) - 10) / 3 + 1) & 7;
        S16(p, 0x11c0) = (U8(p, 0x3fa) - 10) * 0xaaa;
    } else {
        fn_802A20F0(lbl_8053AC98, p + 0x8, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
        S32(p, 0x11b0)++;
        s32 lim;
        if (fn_802486A0(p) == 3 && !fn_8023434C(S32(p, 0x4))) {
            lim = 6;
        } else {
            lim = 12;
        }
        if (S32(p, 0x11b0) < lim) {
            U8(p, 0x3fa) = 10;
            U8(p, 0x3fb) = 0;
        } else {
            U8(p, 0x3fb) = 11;
            fn_80251AEC(p, 0xc);
        }
        S16(p, 0x11c0) = 0;
    }
    switch (S32(p, 0x3dc)) {
    case 0:
        break;
    case 1:
        S16(p, 0x11c0) += 0x8000;
        break;
    case 2:
        S16(p, 0x11c0) += 0x4000;
        break;
    case 3:
        S16(p, 0x11c0) -= 0x4000;
        break;
    }
    fn_802765C0(p);
}
void fn_80274988(char* p) {
    U8(p, 0x3fa)++;
    S16(p, 0x11c0) = 0;
    if (fn_802486A0(p) == 3 && !fn_8023434C(S32(p, 0x4))) {
        if (U8(p, 0x3fa) < 3) {
            U8(p, 0x3fb) = 9;
            S16(p, 0x11c0) = -0x6000;
        } else if (U8(p, 0x3fa) < 7) {
            U8(p, 0x3fb) = 8;
            S16(p, 0x11c0) = -0x7000;
        } else if (U8(p, 0x3fa) < 8) {
            U8(p, 0x3fb) = 9;
            S16(p, 0x11c0) = -0x6000;
        } else if (U8(p, 0x3fa) < 9) {
            U8(p, 0x3fb) = 10;
            S16(p, 0x11c0) = -0x4000;
        } else if (U8(p, 0x3fa) < 10) {
            U8(p, 0x3fb) = 0;
            S16(p, 0x11c0) = -0x2000;
        } else if (U8(p, 0x3fa) < 0x1f) {
            U8(p, 0x3fb) = ((U8(p, 0x3fa) - 10) / 3 + 1) & 7;
            S16(p, 0x11c0) = (U8(p, 0x3fa) - 10) * 0xaaa;
        } else if (U8(p, 0x3fa) < 0x22) {
            U8(p, 0x3fb) = 11;
            S16(p, 0x11c0) = (U8(p, 0x3fa) - 10) * 0xaaa;
        } else {
            U8(p, 0x3fb) = 11;
            fn_802A20F0(lbl_8053AC98, p + 0x8, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
            fn_80251AEC(p, 0);
        }
    } else {
        if (U8(p, 0x3fa) < 3) {
            U8(p, 0x3fb) = 9;
            S16(p, 0x11c0) = -0x6000;
        } else if (U8(p, 0x3fa) < 7) {
            U8(p, 0x3fb) = 8;
            S16(p, 0x11c0) = -0x7000;
        } else if (U8(p, 0x3fa) < 8) {
            U8(p, 0x3fb) = 9;
            S16(p, 0x11c0) = -0x6000;
        } else if (U8(p, 0x3fa) < 9) {
            U8(p, 0x3fb) = 10;
            S16(p, 0x11c0) = -0x4000;
        } else if (U8(p, 0x3fa) < 10) {
            U8(p, 0x3fb) = 0;
            S16(p, 0x11c0) = -0x2000;
        } else if (U8(p, 0x3fa) < 0x18) {
            U8(p, 0x3fb) = ((U8(p, 0x3fa) - 10) / 2 + 1) & 7;
            S16(p, 0x11c0) = (U8(p, 0x3fa) - 10) * 0x1000;
        } else if (U8(p, 0x3fa) < 0x1a) {
            U8(p, 0x3fb) = 11;
            S16(p, 0x11c0) = (U8(p, 0x3fa) - 10) * 0x1000;
        } else {
            U8(p, 0x3fb) = 11;
            fn_802A20F0(lbl_8053AC98, p + 0x8, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
            fn_80251AEC(p, 0);
        }
    }
    switch (S32(p, 0x3dc)) {
    case 0:
        break;
    case 1:
        S16(p, 0x11c0) += 0x8000;
        break;
    case 2:
        S16(p, 0x11c0) += 0x4000;
        break;
    case 3:
        S16(p, 0x11c0) -= 0x4000;
        break;
    }
    char* base = (char*)PTR(p, 0x3b4);
    if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
        S16(p, 0x11c0) = -S16(p, 0x11c0);
    }
    fn_802765C0(p);
}
void fn_80276538(char* p) {
    setAround((JGeometry::TBox2<f32>*)(p + 0x4c0), *(JGeometry::TVec2<f32>*)(p + 0x8), 7.0f);
    JGeometry::TBox2<f32>* b = (JGeometry::TBox2<f32>*)(p + 0x4d0);
    b->set(-15.0f, -15.0f, 15.0f, 15.0f);
    b->addPos(*(JGeometry::TVec2<f32>*)(p + 0x8));
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
extern "C" {
void fn_802808E8(char*, f32);
u16 fn_8022461C(void*, void*);
void fn_8013CB44(void* h, void* pos, s32 a, s32 b, s32 c);
}
void fn_80277220(char* p) {
    F32(p, 0x358) = 0.0f;
    JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)(p + 0x350), (Vec*)(p + 8));
    if (F32(p, 0x10) <= 0.0f) {
        fn_802808E8(p, 1.5f);
    }
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) >= 20) {
        fn_80251AEC(p, 0);
    }
    fn_80268B3C(p);
    switch (S32(p, 0x45c)) {
    case 0:
        if (U8(p, 0x3fa) < 4) {
            U8(p, 0x3fb) = U8(p, 0x3fa);
        } else {
            U8(p, 0x3fb) = U8(p, 0x3fa) - 1;
        }
        if (U8(p, 0x3fb) >= 7) {
            U8(p, 0x3fb) = 6;
        }
        break;
    case 1:
        if (U8(p, 0x3fa) < 4) {
            U8(p, 0x3fb) = U8(p, 0x3fa);
        } else {
            U8(p, 0x3fb) = U8(p, 0x3fa) - 1;
        }
        if (U8(p, 0x3fb) >= 8) {
            U8(p, 0x3fb) = 7;
        }
        break;
    case 2:
        if (U8(p, 0x3fa) < 1) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) < 5) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) < 6) {
            U8(p, 0x3fb) = 2;
        } else {
            U8(p, 0x3fb) = 3;
        }
        break;
    case 3:
        if (U8(p, 0x3fa) < 2) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) < 4) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) < 13) {
            U8(p, 0x3fb) = 2;
        } else {
            U8(p, 0x3fb) = 3;
        }
        break;
    case 4:
        if (U8(p, 0x3fa) < 6) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) < 7) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) < 8) {
            U8(p, 0x3fb) = 2;
        } else if (U8(p, 0x3fa) < 9) {
            U8(p, 0x3fb) = 3;
        } else if (U8(p, 0x3fa) < 11) {
            U8(p, 0x3fb) = 4;
        } else {
            U8(p, 0x3fb) = 5;
        }
        break;
    }
    U8(p, 0x3fa)++;
    if (F32(p, 0x10) <= 0.0f) {
        if (fn_8022461C(p + 8, PTR(p, 0x3b4)) == 0x39) {
            if (PTR(p, 0x1370) == NULL) {
                PTR(p, 0x1370) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3d4, 0, -1, (s32)(p + 0x13a8), NULL, 1, 1.0f);
            } else {
                fn_8013CB44(PTR(p, 0x1370), p + 8, 0, -1, 1);
            }
            killEmitter(p, 0x136c);
        } else {
            if (PTR(p, 0x136c) == NULL) {
                PTR(p, 0x136c) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3d3, 0, -1, (s32)(p + 0x1398), NULL, 1, 1.0f);
            } else {
                fn_8013CB44(PTR(p, 0x136c), p + 8, 0, -1, 1);
            }
            killEmitter(p, 0x1370);
        }
    }
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
void fn_80277E18(char* p) {
    U8(p, 0x124d) = 1;
    S32(p, 0xd30) = 0;
    if (U8(p, 0xd35) == 0) {
        if (fn_80241544(p) <= 1) {
            fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x3ae, 1, 1, 0, 0, 1, 1.0f);
        } else {
            fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x3af, 1, 1, 0, 0, 1, 1.0f);
        }
    }
}
void fn_80277EBC(char* p) {
    DELETE_JPA(p, 0x1308);
    if (fn_8025F418(p)) {
        fn_80231194(S32(p, 0xd70));
    }
    S32(p, 0x494) = 0;
    U8(p, 0x498) = 0;
    U8(p, 0xcfc) = 0;
    S32(p, 0xd08) = -1;
    S32(p, 0xd0c) = 0;
    U8(p, 0xd34) = 0;
    U8(p, 0x499) = 0;
    U8(p, 0xba4) = 0;
    s32 id = S32(p, 0x49c);
    if (id >= 0) {
        char* a = (char*)fn_801F666C(fn_801F856C(), id);
        if (a != NULL) {
            U8(a, 0x11c) = 0;
        }
        S32(p, 0x49c) = -1;
    }
    if (S32(p, 0x1244) != 0x34) {
        U8(p, 0xd2d) = 0;
        U8(p, 0xc00) = 0;
    }
}
void fn_802790C0(char* p) {
    if (fn_8025F448() && !fn_8025F418(p)) {
        fn_8025FEDC(p);
    }
    fn_8025F698(p, 0);
    if (S32(p, 0xc64) < 99999999) {
        S32(p, 0xc64)++;
    }
    U8(p, 0x124d) = 1;
    S32(p, 0x464) = 0;
    S32(p, 0x494) = 0;
    U8(p, 0x498) = 1;
    U8(p, 0x458) = 0;
    U8(p, 0xcfd) = 0;
    S32(p, 0xd08) = -1;
    S32(p, 0xd0c) = 0;
    U8(p, 0xc00) = 1;
    fn_8024F0E8(p, 0x10005);
    fn_8024EFF8(p, 10);
    if (!Player_IsLinked(p)) {
        fn_802382D0(S32(p, 0x4), 0);
    }
    F32(p, 0x10) = 0.0f;
    U8(p, 0xba4) = 0;
}
void fn_802791AC(void) {}
void fn_8027966C(char* p) {
    S32(p, 0x464) = 0x3c;
    U8(p, 0x458) = 0;
    fn_8024F0E8(p, 0x10004);
    F32(p, 0x358) = 0.0f;
}
inline bool sameCount(char* p) {
    s32 v = fn_80248778(p);
    s32 w = fn_80240888(p);
    if (w == v) {
        return true;
    }
    return false;
}
void fn_802796B8(char* p) {
    if ((fn_802486A0(p) == 4 && sameCount(p)) || (fn_802486A0(p) != 4 && !Player_IsLinked(p))) {
        s32 t = S32(p, 0x11e4);
        if (t == 4 || t == 7) {
            fn_8024E46C(p);
        } else if (t == 5 || t == 8) {
            fn_8024E3D8(p);
        } else if (t == 6 || t == 9) {
            fn_8024E344(p);
        }
    }
    killEmitter(p, 0x132c);
    killEmitter(p, 0x135c);
    killEmitter(p, 0x136c);
    killEmitter(p, 0x1370);
}
void fn_80279F94(char* p) {
    DELETE_JPA(p, 0x1308);
    S32(p, 0x464) = 0x3c;
}
void fn_80279FE8(char* p) {
    U8(p, 0x3fc)++;
    if (U8(lbl_8053AAF8, 0x7f) != 0) {
        if (U8(p, 0x3fc) >= 0x78) {
            fn_80251AEC(p, 0);
        }
    } else {
        if (U8(p, 0x3fc) >= 0x5a) {
            fn_80251AEC(p, 0);
        }
    }
    U8(p, 0x3fd) = (U8(p, 0x3fc) / 6) % 4;
    fn_80268B3C(p);
    if (PTR(p, 0x1308) != NULL) {
        Vec3* v = (Vec3*)(p + 0x1320);
        v->set(F32(p, 0x8), F32(p, 0xc), 16.0f + F32(p, 0x10));
        Vec3* w = (Vec3*)(p + 0x1310);
        w->x = v->x;
        w->y = v->y;
        w->z = v->z;
    }
}
void fn_8027A0D4(char* p) {
    U8(p, 0x458) = 0;
    if (PTR(p, 0x1308) == NULL) {
        PTR(p, 0x1308) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x565, 0, -1, 0, p + 0x130c, 1, 0.5f);
    }
    Actor_CreateByID(fn_801F856C(), 'PEFF', PTR(p, 0x3b4), p + 0x8, (S32(p, 0x4) & 3) | 0x10, -1, -1);
    fn_8024F0E8(p, 0x2002a);
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
void fn_8027A908(char* p) {
    S32(p, 0xbf4) = 8;
    U8(p, 0x458) = 0;
    U8(p, 0xbb9) = 0;
    U8(p, 0xbba) = 0;
    F32(p, 0xbbc) = 3.0f;
    F32(p, 0x10) = 0.0f;
    fn_8027EB04(p);
    clearCombo(p);
    if (U8(p, 0x490) == 1) {
        fn_8024F0E8(p, 0x40075);
        fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x503, 1, 1, 0, 0, 1, 1.0f);
    } else {
        U8(p, 0x3fd) = 1;
    }
}
void fn_8027AA10(char* p) {
    DELETE_JPA(p, 0x12b8);
    DELETE_JPA(p, 0x12bc);
    DELETE_JPA(p, 0x1374);
    DELETE_JPA(p, 0x1378);
    U16(p, 0x11c0) = 0;
}
void fn_8027B304(char* p) {
    S32(p, 0xbf4) = 6;
    U8(p, 0x458) = 1;
    fn_8024F0E8(p, 0x10001);
    fn_8024F0E8(p, 0x20028);
    fn_8027EB04(p);
    clearCombo(p);
    S32(p, 0x11b0) = 0;
    if (PTR(p, 0x12bc) == NULL) {
        PTR(p, 0x12bc) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x26a, 0, 1, 0, NULL, 1, 1.0f);
    }
    if (PTR(p, 0x12b8) == NULL) {
        switch (S32(p, 0x4)) {
        case 0:
            PTR(p, 0x12b8) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x267, 0, -1, 0, NULL, 1, 1.0f);
            break;
        case 1:
            PTR(p, 0x12b8) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x269, 0, -1, 0, NULL, 1, 1.0f);
            break;
        case 2:
            PTR(p, 0x12b8) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x266, 0, -1, 0, NULL, 1, 1.0f);
            break;
        case 3:
            PTR(p, 0x12b8) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x268, 0, -1, 0, NULL, 1, 1.0f);
            break;
        }
    }
    PlayerOfs* po = (PlayerOfs*)p;
    *(JGeometry::TVec3<f32>*)(p + 0x11b4) = po->pos;
    switch (S32(p, 0x4)) {
    case 0: {
        char* base = (char*)PTR(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
            F32(p, 0x11b8) -= 4.0f;
        } else {
            F32(p, 0x11b8) += 16.0f;
        }
        break;
    }
    case 1:
        F32(p, 0x11b4) += 16.0f;
        break;
    case 2:
        F32(p, 0x11b4) -= 16.0f;
        break;
    case 3: {
        char* base = (char*)PTR(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
            F32(p, 0x11b8) += 4.0f;
        } else {
            F32(p, 0x11b8) -= 16.0f;
        }
        break;
    }
    }
    S16(p, 0x11c0) = 0;
}
void fn_8027BA2C(char* p) {
    switch (S32(p, 0x11ac)) {
    case 1: S32(p, 0xbf4) = 8; break;
    case 2: S32(p, 0xbf4) = 6; break;
    case 3: S32(p, 0xbf4) = 4; break;
    case 4: S32(p, 0xbf4) = 8; break;
    default: S32(p, 0xbf4) = 4; break;
    }
    U8(p, 0x458) = 1;
    fn_8027EB04(p);
    fn_8024F0E8(p, 0x10001);
    fn_8024F0E8(p, 0x20001);
    fn_8024F0E8(p, 0x2000e);
    clearCombo(p);
    PlayerOfs* po = (PlayerOfs*)p;
    *(JGeometry::TVec3<f32>*)(p + 0x11b4) = po->pos;
    switch (S32(p, 0x4)) {
    case 0: {
        char* base = (char*)PTR(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
            F32(p, 0x11b8) -= 4.0f;
        } else {
            F32(p, 0x11b8) += 16.0f;
        }
        break;
    }
    case 1:
        F32(p, 0x11b4) += 16.0f;
        break;
    case 2:
        F32(p, 0x11b4) -= 16.0f;
        break;
    case 3: {
        char* base = (char*)PTR(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
            F32(p, 0x11b8) += 4.0f;
        } else {
            F32(p, 0x11b8) -= 16.0f;
        }
        break;
    }
    }
    S16(p, 0x11c0) = 0;
    if (PTR(p, 0x12bc) == NULL) {
        PTR(p, 0x12bc) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x26a, 0, 1, 0, NULL, 1, 1.0f);
    }
}
inline void setOfs30c(char* p, f32 x, f32 y) {
    PlayerOfs* po = (PlayerOfs*)p;
    JGeometry::TVec3<f32>* v = (JGeometry::TVec3<f32>*)(p + 0x30c);
    v->x = x;
    v->y = y;
    v->z = 0.0f;
    *v += po->pos;
}
#define setBox(p, off, a, b, c, d_) { PlayerOfs* po_ = (PlayerOfs*)(p); ((JGeometry::TBox2<f32>*)((p) + (off)))->set(a, b, c, d_); }
extern "C" {
void* fn_80246D1C(char*, s32);
u8 fn_8022AF5C(void);
void fn_8043D67C(void*, s32, s32, s32);
extern void* lbl_8053AED0;
}
void fn_8027439C(char* p) {
    if (U8(p, 0x3fd) == 0) {
        U8(p, 0x3fa)++;
        if (U8(p, 0x3fa) <= 7) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) <= 14) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) <= 21) {
            U8(p, 0x3fb) = 2;
        } else if (U8(p, 0x3fa) <= 28) {
            U8(p, 0x3fb) = 3;
        } else if (U8(p, 0x3fa) <= 35) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) <= 42) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) <= 49) {
            U8(p, 0x3fb) = 2;
        } else if (U8(p, 0x3fa) <= 56) {
            U8(p, 0x3fb) = 3;
        } else {
            U8(p, 0x3fd) = 1;
            U8(p, 0x3fa) = 0;
            U8(p, 0x3fb) = 0;
            if (U8(p, 0x490) == 1) {
                fn_8043D67C(lbl_8053AED0, 400, S32(p, 4), 0);
                U8(p, 0x490) = 0;
            }
        }
    } else if (U8(p, 0x3fd) == 2) {
        U8(p, 0x3fa)++;
        if (U8(p, 0x3fa) <= 7) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) <= 14) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) <= 21) {
            U8(p, 0x3fb) = 2;
        } else if (U8(p, 0x3fa) <= 28) {
            U8(p, 0x3fb) = 3;
        } else if (U8(p, 0x3fa) <= 35) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) <= 42) {
            U8(p, 0x3fb) = 1;
        } else {
            U8(p, 0x3fd) = 1;
            U8(p, 0x3fa) = 0;
            U8(p, 0x3fb) = 0;
        }
    } else {
        void* q;
        if (S32(p, 0xbc0) > 0 || ((q = fn_80246D1C(p, 0x200)) != NULL && !fn_8022AF5C())) {
            U8(p, 0xbba) = 1;
        }
        if (U8(p, 0xbba) == 1) {
            U8(p, 0x3fa) += 2;
        } else {
            U8(p, 0x3fa)++;
        }
        if (U8(p, 0x3fa) >= 19) {
            U8(p, 0x3fb) = 0;
            U8(p, 0x3fa) = 0;
            if (U8(p, 0xbba) == 1) {
                F32(p, 0xbbc) = 4.0f;
            } else {
                F32(p, 0xbbc) = 3.0f;
            }
            U8(p, 0xbba) = 0;
        }
        if (U8(p, 0x3fa) < 7) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) < 12) {
            U8(p, 0x3fb) = 1;
        } else {
            U8(p, 0x3fb) = 2;
        }
        if (U8(p, 0x3fb) >= 1) {
            F32(p, 0xbbc) -= 0.2f;
            if (F32(p, 0xbbc) < 2.0f) {
                F32(p, 0xbbc) = 2.0f;
            }
        }
        if (F32(p, 0x10) > 0.0f) {
            if (F32(p, 0x34c) > 1.0f) {
                U8(p, 0x3fb) = 2;
            } else {
                U8(p, 0x3fb) = 0;
            }
        }
    }
    setBox(p, 0x4b0, po_->pos.x - 20.0f, po_->pos.y - 20.0f, 20.0f + po_->pos.x, 20.0f + po_->pos.y);
    setBox(p, 0x4a0, po_->pos.x - 12.0f, po_->pos.y - 12.0f, 12.0f + po_->pos.x, 12.0f + po_->pos.y);
    setOfs30c(p, 0.0f, 0.0f);
    S32(p, 0x3f0) = -1;
}
extern "C" {
u8 fn_80241230(char*);
u8 fn_80241284(char*);
u8 fn_80241338(char*);
u8 fn_802412E0(char*);
}
inline void hitR(char* p) {
    setBox(p, 0x5ec, 8.0f + po_->pos.x, po_->pos.y - 8.0f, 16.0f + po_->pos.x, 8.0f + po_->pos.y);
    S32(p, 0x3ec) = 0;
    U8(p, 0xb98) = 1;
}
inline void hitL(char* p) {
    setBox(p, 0x5ec, po_->pos.x - 16.0f, po_->pos.y - 8.0f, po_->pos.x - 8.0f, 8.0f + po_->pos.y);
    S32(p, 0x3ec) = 1;
    U8(p, 0xb98) = 1;
}
inline void hitD(char* p) {
    setBox(p, 0x5ec, po_->pos.x - 8.0f, 8.0f + po_->pos.y, 8.0f + po_->pos.x, 16.0f + po_->pos.y);
    S32(p, 0x3ec) = 2;
    U8(p, 0xb98) = 1;
}
inline void hitU(char* p) {
    setBox(p, 0x5ec, po_->pos.x - 8.0f, po_->pos.y - 16.0f, 8.0f + po_->pos.x, po_->pos.y - 8.0f);
    S32(p, 0x3ec) = 3;
    U8(p, 0xb98) = 1;
}
inline void hitAll(char* p) {
    setBox(p, 0x5ec, po_->pos.x - 15.0f, po_->pos.y - 15.0f, 15.0f + po_->pos.x, po_->pos.y - 15.0f);
    S32(p, 0x3ec) = -1;
    U8(p, 0xb98) = 1;
}
void fn_80276078(char* p) {
    U8(p, 0xb98) = 0;
    if (!fn_802413F0(p)) {
        return;
    }
    if (S32(p, 0x468) > 0) {
        hitAll(p);
    } else if (S32(p, 0x1240) == 0 || S32(p, 0x1240) == 2 || S32(p, 0x1240) == 3) {
        switch (S32(p, 0x3dc)) {
        case 0: hitR(p); break;
        case 1: hitL(p); break;
        case 2: hitD(p); break;
        case 3: hitU(p); break;
        }
    } else if (fn_80241284(p) || fn_80241230(p)) {
        hitAll(p);
    } else if (fn_80241338(p)) {
        switch (S32(p, 0x3dc)) {
        case 0: hitU(p); break;
        case 1: hitU(p); break;
        case 2: hitL(p); break;
        case 3: hitR(p); break;
        }
    } else if (fn_802412E0(p)) {
        switch (S32(p, 0x3dc)) {
        case 0: hitL(p); break;
        case 1: hitR(p); break;
        case 2: hitU(p); break;
        case 3: hitD(p); break;
        }
    }
}
extern "C" u8 fn_80246464(char*);
extern "C" void fn_80276E5C(char*);
inline void setOfs30c2(char* p, f32 x, f32 y) {
    PlayerOfs* po = (PlayerOfs*)p;
    JGeometry::TVec3<f32>* v = (JGeometry::TVec3<f32>*)(p + 0x30c);
    v->set(x, y, 0.0f);
    *v += po->pos;
}
inline void endState(char* p, u8 n) {
    if (U8(p, 0x3fa) >= n) {
        if (fn_80246464(p)) {
            fn_80251AEC(p, 8);
        } else {
            fn_80251AEC(p, 0);
        }
    } else {
        U8(p, 0x3fa)++;
    }
}
void fn_802756E4(char* p) {
    s32 ang = 0;
    switch (S32(p, 0x45c)) {
    case 0:
        if (U8(p, 0x3fa) < 4) {
            U8(p, 0x3fb) = U8(p, 0x3fa);
        } else {
            U8(p, 0x3fb) = U8(p, 0x3fa) - 1;
        }
        if (U8(p, 0x3fb) >= 7) {
            U8(p, 0x3fb) = 6;
        }
        endState(p, 7);
        switch (S32(p, 0x3dc)) {
        case 0: ang = (s16)(U8(p, 0x3fb) << 12) - 0x4000; break;
        case 1: ang = (s16)(-U8(p, 0x3fb) << 12) - 0x4000; break;
        case 2: ang = (s16)(-U8(p, 0x3fb) << 12) - 0x8000; break;
        case 3: ang = (s16)(-U8(p, 0x3fb) << 12); break;
        }
        break;
    case 1:
        if (U8(p, 0x3fa) < 4) {
            U8(p, 0x3fb) = U8(p, 0x3fa);
        } else {
            U8(p, 0x3fb) = U8(p, 0x3fa) - 1;
        }
        if (U8(p, 0x3fb) >= 8) {
            U8(p, 0x3fb) = 7;
        }
        endState(p, 8);
        switch (S32(p, 0x3dc)) {
        case 0: ang = (s16)(-U8(p, 0x3fb) << 12) + 0x4000; break;
        case 1: ang = (s16)(U8(p, 0x3fb) << 12) + 0x4000; break;
        case 2: ang = (s16)(U8(p, 0x3fb) << 12); break;
        case 3: ang = (s16)(U8(p, 0x3fb) << 12) - 0x8000; break;
        }
        break;
    case 2:
        if (U8(p, 0x3fa) < 1) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) < 5) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) < 6) {
            U8(p, 0x3fb) = 2;
        } else {
            U8(p, 0x3fb) = 3;
        }
        endState(p, 7);
        fn_80276E5C(p);
        break;
    case 3:
        if (U8(p, 0x3fa) < 2) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) < 4) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) < 13) {
            U8(p, 0x3fb) = 2;
        } else {
            U8(p, 0x3fb) = 3;
        }
        endState(p, 15);
        fn_80276E5C(p);
        break;
    case 4:
        if (U8(p, 0x3fa) < 6) {
            U8(p, 0x3fb) = 0;
        } else if (U8(p, 0x3fa) < 7) {
            U8(p, 0x3fb) = 1;
        } else if (U8(p, 0x3fa) < 8) {
            U8(p, 0x3fb) = 2;
        } else if (U8(p, 0x3fa) < 9) {
            U8(p, 0x3fb) = 3;
        } else if (U8(p, 0x3fa) < 11) {
            U8(p, 0x3fb) = 4;
        } else {
            U8(p, 0x3fb) = 5;
        }
        endState(p, 30);
        fn_80276E5C(p);
        break;
    }
    switch (S32(p, 0x45c)) {
    case 0:
    case 1:
        fn_80276E5C(p);
        s16 a2 = ang;
        if (a2 <= -0x7000) {
            setOfs30c2(p, -16.0f, 0.0f);
        } else if (a2 <= -0x5000) {
            setOfs30c2(p, -16.0f, -16.0f);
        } else if (a2 <= -0x3000) {
            setOfs30c2(p, 0.0f, -16.0f);
        } else if (a2 <= -0x1000) {
            setOfs30c2(p, 16.0f, -16.0f);
        } else if (a2 <= 0x1000) {
            setOfs30c2(p, 16.0f, 0.0f);
        } else if (a2 <= 0x3000) {
            setOfs30c2(p, 16.0f, 16.0f);
        } else if (a2 <= 0x5000) {
            setOfs30c2(p, 0.0f, 16.0f);
        } else if (a2 <= 0x7000) {
            setOfs30c2(p, -16.0f, 16.0f);
        } else {
            setOfs30c2(p, -16.0f, 0.0f);
        }
        break;
    case 2:
    case 3:
    case 4:
        fn_80276E5C(p);
        break;
    }
}
inline void faceLeft(char* p, s32 d) {
    setBox(p, 0x4b0, po_->pos.x - 32.0f, po_->pos.y - 8.0f, po_->pos.x - 16.0f, 8.0f + po_->pos.y);
    setBox(p, 0x4a0, po_->pos.x - 16.0f, po_->pos.y - 8.0f, 4.0f + po_->pos.x, 8.0f + po_->pos.y);
    setOfs30c(p, -16.0f, 0.0f);
    S32(p, 0x3f0) = d;
}
inline void faceRight(char* p, s32 d) {
    setBox(p, 0x4b0, 16.0f + po_->pos.x, po_->pos.y - 8.0f, 32.0f + po_->pos.x, 8.0f + po_->pos.y);
    setBox(p, 0x4a0, po_->pos.x - 4.0f, po_->pos.y - 8.0f, 16.0f + po_->pos.x, 8.0f + po_->pos.y);
    setOfs30c(p, 16.0f, 0.0f);
    S32(p, 0x3f0) = d;
}
inline void faceUp(char* p, s32 d) {
    setBox(p, 0x4b0, po_->pos.x - 8.0f, po_->pos.y - 32.0f, 8.0f + po_->pos.x, po_->pos.y - 16.0f);
    setBox(p, 0x4a0, po_->pos.x - 8.0f, po_->pos.y - 16.0f, 8.0f + po_->pos.x, 4.0f + po_->pos.y);
    setOfs30c(p, 0.0f, -16.0f);
    S32(p, 0x3f0) = d;
}
inline void faceDown(char* p, s32 d) {
    setBox(p, 0x4b0, po_->pos.x - 8.0f, 16.0f + po_->pos.y, 8.0f + po_->pos.x, 32.0f + po_->pos.y);
    setBox(p, 0x4a0, po_->pos.x - 8.0f, po_->pos.y - 4.0f, 8.0f + po_->pos.x, 16.0f + po_->pos.y);
    setOfs30c(p, 0.0f, 16.0f);
    S32(p, 0x3f0) = d;
}
void fn_802765C0(char* p) {
    s16 a = S16(p, 0x11c0);
    if (a < -0x7000) {
        faceLeft(p, 1);
    } else if (a < -0x5000) {
        setBox(p, 0x4b0, po_->pos.x - 24.0f, po_->pos.y - 24.0f, po_->pos.x - 8.0f, po_->pos.y - 8.0f);
        setBox(p, 0x4a0, po_->pos.x - 16.0f, po_->pos.y - 16.0f, po_->pos.x, po_->pos.y);
        setOfs30c(p, -16.0f, -16.0f);
        if (S32(p, 0x3f0) != 3 || S32(p, 0x3f0) != 1) {
            S32(p, 0x3f0) = 3;
        }
    } else if (a < -0x3000) {
        faceUp(p, 3);
    } else if (a < -0x1000) {
        setBox(p, 0x4b0, 8.0f + po_->pos.x, po_->pos.y - 24.0f, 24.0f + po_->pos.x, po_->pos.y - 8.0f);
        setBox(p, 0x4a0, po_->pos.x, po_->pos.y - 16.0f, 16.0f + po_->pos.x, po_->pos.y);
        setOfs30c(p, 16.0f, -16.0f);
        if (S32(p, 0x3f0) != 3 || S32(p, 0x3f0) != 0) {
            S32(p, 0x3f0) = 3;
        }
    } else if (a < 0x1000) {
        faceRight(p, 0);
    } else if (a < 0x3000) {
        setBox(p, 0x4b0, 8.0f + po_->pos.x, 8.0f + po_->pos.y, 24.0f + po_->pos.x, 24.0f + po_->pos.y);
        setBox(p, 0x4a0, po_->pos.x, po_->pos.y, 16.0f + po_->pos.x, 16.0f + po_->pos.y);
        setOfs30c(p, 16.0f, 16.0f);
        if (S32(p, 0x3f0) != 2 || S32(p, 0x3f0) != 0) {
            S32(p, 0x3f0) = 2;
        }
    } else if (a < 0x5000) {
        faceDown(p, 2);
    } else if (a < 0x7000) {
        setBox(p, 0x4b0, po_->pos.x - 24.0f, 8.0f + po_->pos.y, po_->pos.x - 8.0f, 24.0f + po_->pos.y);
        setBox(p, 0x4a0, po_->pos.x - 16.0f, po_->pos.y, po_->pos.x, 16.0f + po_->pos.y);
        setOfs30c(p, -16.0f, 16.0f);
        if (S32(p, 0x3f0) != 2 || S32(p, 0x3f0) != 1) {
            S32(p, 0x3f0) = 2;
        }
    } else {
        faceLeft(p, 1);
    }
}
void fn_80276BB8(char* p) {
    switch (S32(p, 0x3dc)) {
    case 0: faceLeft(p, 1); break;
    case 1: faceRight(p, 0); break;
    case 2: faceUp(p, 3); break;
    case 3: faceDown(p, 2); break;
    }
}
void fn_80276E5C(char* p) {
    switch (S32(p, 0x3dc)) {
    case 0: faceRight(p, 0); break;
    case 1: faceLeft(p, 1); break;
    case 2: faceDown(p, 2); break;
    case 3: faceUp(p, 3); break;
    }
}
void fn_80279CFC(char* p) {
    S32(p, 0x464) = 0x3c;
    U8(p, 0x458) = 0;
    s32 k = S32(p, 0x11e4);
    if (k == 7 || (u32)(k - 8) <= 1 || k == 0x1c) {
        if (PTR(p, 0x135c) == NULL) {
            switch (S32(p, 0x3dc)) {
            case 0:
                PTR(p, 0x135c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x248, 0, 0, 0, NULL, 1, 1.0f);
                break;
            case 1:
                PTR(p, 0x135c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x247, 0, 0, 0, NULL, 1, 1.0f);
                break;
            case 2:
                PTR(p, 0x135c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x246, 0, -1, 0, NULL, 1, 1.0f);
                break;
            case 3:
                PTR(p, 0x135c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x249, 0, 0, 0, NULL, 1, 1.0f);
                break;
            }
        }
        if (PTR(p, 0x132c) == NULL) {
            switch (S32(p, 0x3dc)) {
            case 0:
                PTR(p, 0x132c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x244, 0, 0, 0, p + 0x1330, 1, 1.0f);
                break;
            case 1:
                PTR(p, 0x132c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x243, 0, 0, 0, p + 0x1330, 1, 1.0f);
                break;
            case 2:
                PTR(p, 0x132c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x242, 0, -1, 0, p + 0x1330, 1, 1.0f);
                break;
            case 3:
                PTR(p, 0x132c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x245, 0, 0, 0, p + 0x1330, 1, 1.0f);
                break;
            }
        }
        fn_8024F0E8(p, 0x10014);
        fn_8024F0E8(p, 0x2004c);
    } else if (k == 3) {
        fn_8024F0E8(p, 0x10016);
        fn_8024F0E8(p, 0x2004d);
    } else {
        fn_8024F0E8(p, 0x10004);
    }
}
extern const Vec2f lbl_8046BCA8[];
u8 fn_8023EA28(s32);
u8 fn_802DEBF8(void);
u8 fn_802466B4(char*);
u8 fn_80243234(char*);
struct PlayerCombo {
    u8 pad0[0x117c];
    s32 mTimerA[4];
    s32 mTimerB[4];
    u8 mDir[4][4];
};
inline bool comboAllSet(char* p) {
    PlayerCombo* c = (PlayerCombo*)p;
    for (int i = 0; i < 4; i++) {
        if (!(c->mTimerA[i] > 0)) {
            return false;
        }
    }
    return true;
}
inline s32 comboDirCount(char* p) {
    PlayerCombo* c = (PlayerCombo*)p;
    for (int i = 0; i < 4; i++) {
        if (!(c->mTimerB[i] > 0)) {
            return i;
        }
        bool any = 0;
        for (int j = 0; j < 4; j++) {
            if (c->mDir[i][j] == 1) {
                any = 1;
            }
        }
        if (!any) {
            return i;
        }
    }
    return 4;
}
BOOL fn_80275D9C(char* p) {
    if (S32(p, 0xc9c) > 0) {
        return 0;
    }
    if (Player_IsLinked(p) && fn_802486A0(p) == 5) {
        return 0;
    }
    if (Player_IsLinked(p) && fn_8023EA28(Player_GetLinkTargetIndex(p)) && fn_802486A0(p) != 4) {
        return 0;
    }
    if (fn_802DEBF8()) {
        return 0;
    }
    if (fn_80241544(p) <= 0) {
        return 0;
    }
    if (fn_802466B4(p)) {
        if (comboAllSet(p)) {
            if (fn_80251AEC(p, 9)) {
                S32(p, 0x11ac) = 2;
                return 1;
            }
        } else {
            if (comboDirCount(p) >= 3) {
                if (fn_80251AEC(p, 9)) {
                    S32(p, 0x11ac) = 3;
                    return 1;
                }
            } else if (S32(p, 0x11d4) > 0) {
                if (fn_80251AEC(p, 9)) {
                    S32(p, 0x11ac) = 4;
                    return 1;
                }
            } else if (U8(PTR(p, 0xbf0), 0xb4) != 0) {
                if (fn_80243234(p)) {
                    if (fn_80251AEC(p, 7)) {
                        F32(p, 0x344) = lbl_8046BCA8[S32(p, 0x3dc)].x;
                        F32(p, 0x348) = lbl_8046BCA8[S32(p, 0x3dc)].y;
                        F32(p, 0x34c) = -4.0f;
                        return 1;
                    }
                } else if (fn_80251AEC(p, 5)) {
                    return 1;
                }
            } else if (fn_80251AEC(p, 4)) {
                return 1;
            }
        }
    }
    return 0;
}
void fn_802356B8(s32);

extern "C" {
void fn_8027FA08(char*, JGeometry::TVec3<f32>*);
f32 PSVECMag(const Vec*);
u8 fn_80241284(char*);
s32 fn_80237810(s32);
s32 fn_8024189C(char*);
extern const Vec2f lbl_8046BD88[];
}
void fn_8027B648(char* p) {
    fn_80274988(p);
    if (fn_802486A0(p) == 3 && !fn_8023434C(S32(p, 0x4)) && U8(p, 0x3fa) >= 11 && U8(p, 0x3fa) < 35) {
        JGeometry::TVec3<f32> t;
        fn_8027FA08(p, &t);
        JGeometry::TVec3<f32>& pos = *(JGeometry::TVec3<f32>*)(p + 8);
        JGeometry::TVec3<f32> d = t - pos;
        d.z = 0.0f;
        if (PSVECMag((Vec*)&d) >= 6.0f) {
            d.normalize();
            d.scale(6.0f);
            pos += d;
        } else {
            pos.set(t);
        }
    }
    fn_802A20F0(lbl_8053AC98, p + 0x30c, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
    fn_80268B3C(p);
    if (U8(p, 0x3fa) == 10) {
        s32 dir = S32(p, 0x3dc);
        if (S32(p, 0xb38) < 0) {
            if (fn_80241284(p) && S32(p, 0x11ac) == 1 && fn_80241544(p) >= 2) {
                goto create;
            }
            if (Player_IsLinked(p)) {
                s32 m = fn_80237810(Player_GetLinkTargetIndex(p));
                if (fn_80237774(Player_GetLinkTargetIndex(p)) >= m) {
                    goto create;
                }
                goto skip;
            } else {
                s32 m = fn_802417CC(p);
                if (fn_8024189C(p) < m) {
                    goto skip;
                }
            }
        create:
            JGeometry::TVec3<f32> v;
            v.x = F32(p, 0x8);
            v.y = F32(p, 0xc);
            v.z = F32(p, 0x10);
            v.x += lbl_8046BD88[dir].x;
            v.y += lbl_8046BD88[dir].y;
            if (fn_80241284(p) && S32(p, 0x11ac) == 1) {
                s32 no = S32(p, 0x4);
                S32(p, 0xb38) = Actor_CreateByID(fn_801F856C(), 'SWBM', PTR(p, 0x3b4), &v,
                                                 ((dir & 3) << 4) | 0x100 | (no & 3), -1, no);
            } else {
                s32 no = S32(p, 0x4);
                S32(p, 0xb38) = Actor_CreateByID(fn_801F856C(), 'SWBM', PTR(p, 0x3b4), &v,
                                                 ((dir & 3) << 4) | (no & 3), -1, no);
            }
            if (S32(p, 0xb38) >= 0) {
                S32(p, 0xb6c) = S32(p, 0x3b4);
            }
        }
    }
skip:
    if (PTR(p, 0x12bc) != NULL) {
        JGeometry::TVec3<f32> v(*(JGeometry::TVec3<f32>*)(p + 8));
        v.x += 20.0f * JMASCos(S16(p, 0x11c0));
        v.y += 20.0f * JMASSin(S16(p, 0x11c0));
        fn_8013CB44(PTR(p, 0x12bc), &v, 0, 1, 1);
    }
}
void fn_8027BC90(char* p) {
    stopEmitter(p, 0x1274);
    stopEmitter(p, 0x128c);
    killEmitter(p, 0x12b0);
    killEmitter(p, 0x12b4);
    killEmitter(p, 0x12b8);
    s32 id = S32(p, 0x12c0);
    if (id >= 0) {
        char* a = (char*)fn_801F666C(fn_801F856C(), id);
        if (a != NULL) {
            U8(a, 0x11c) = 0;
        }
        S32(p, 0x12c0) = -1;
    }
    if (S32(p, 0x1244) != 0xf) {
        F32(p, 0x10) = 0.0f;
    }
    if (U8(p, 0xcae) == 1) {
        for (s32 i = 0; i < 4; i++) {
            if (i != S32(p, 0x4) && fn_8022E438(S32(p, 0x4), i)) {
                fn_802356B8(i);
            }
        }
    }
    if (U8(p, 0xcae) == 1 || U8(p, 0xcaf) == 1 || (S32(p, 0x1244) != 0x38 && S32(p, 0x1244) != 0x37)) {
        U8(p, 0xcad) = 0;
        U8(p, 0x403) = 0;
    }
    U8(p, 0xcae) = 0;
    U8(p, 0xcaf) = 0;
    S32(p, 0x40c) = 0;
}
void fn_8027C4FC(char* p) {
    S32(p, 0xbf4) = 2;
    U8(p, 0x458) = 1;
    U8(p, 0xcae) = 0;
    U8(p, 0xcaf) = 0;
    if (U8(p, 0xcad) == 0) {
        U8(p, 0xcad) = 1;
        U8(p, 0x403) = 0;
    }
    F32(p, 0x344) = 0.0f;
    F32(p, 0x348) = 0.0f;
    F32(p, 0x34c) = 0.0f;
    if (U8(p, 0x403) < 0x30) {
        if (PTR(p, 0x12b0) == NULL) {
            PTR(p, 0x12b0) = fn_8013CC50(PTR(p, 0x3b4), p + 0x8, 0x26f, 0, 1, 0, 0, 1, 1.0f);
        }
    } else if (PTR(p, 0x12b4) == NULL) {
        if (fn_80241544(p) == 2) {
            if (S32(p, 0x3dc) == 0 || S32(p, 0x3dc) == 1) {
                PTR(p, 0x12b4) = fn_8013CC50(PTR(p, 0x3b4), p + 0x12a4, 0x271, 0, -1, 0, 0, 1, 1.0f);
            } else {
                PTR(p, 0x12b4) = fn_8013CC50(PTR(p, 0x3b4), p + 0x12a4, 0x273, 0, -1, 0, 0, 1, 1.0f);
            }
        } else {
            if (S32(p, 0x3dc) == 0 || S32(p, 0x3dc) == 1) {
                PTR(p, 0x12b4) = fn_8013CC50(PTR(p, 0x3b4), p + 0x12a4, 0x270, 0, -1, 0, 0, 1, 1.0f);
            } else {
                PTR(p, 0x12b4) = fn_8013CC50(PTR(p, 0x3b4), p + 0x12a4, 0x272, 0, -1, 0, 0, 1, 1.0f);
            }
        }
    }
    U8(p, 0x404) = 0;
    S32(p, 0x40c) = 0;
}
void fn_8027C6B8(char* p) { U8(p, 0x436) = 0; }
extern "C" {
f32 fn_8022C76C(s32);
u8 fn_80246464(char*);
}
struct RoomRect { f32 x0, y0, x1, y1; };
inline bool rectIn(const RoomRect& r, const JGeometry::TVec2<f32>& v) {
    bool in = 0;
    if (v.x >= r.x0 && v.y >= r.y0 && v.x < r.x1 && v.y < r.y1) {
        in = 1;
    }
    return in;
}
inline void stopVel(char* p) {
    ((JGeometry::TVec3<f32>*)(p + 0x368))->set(F32(p, 0x344), F32(p, 0x348), 0.0f);
    F32(p, 0x344) = 0.0f;
    F32(p, 0x348) = 0.0f;
    F32(p, 0x34c) = 0.0f;
}
inline void landVel(char* p) {
    if (fn_80246464(p)) {
        if (fn_80251AEC(p, 8)) {
            stopVel(p);
        }
    } else {
        if (fn_80251AEC(p, 0)) {
            stopVel(p);
        }
    }
}
extern "C" {
void* fn_80246B10(char*, s32);
void fn_80274CB8(char*);
u8 fn_8022486C(void*, void*);
s8 fn_8024EE0C(char*);
s8 fn_8024EE14(char*);
extern u8* lbl_8053AB10;
extern const JGeometry::TVec3<f32> lbl_8046BBA8[];
}
void fn_8027BE74(char* p) {
    U8(p, 0x404)++;
    JGeometry::TVec3<f32>* vel = (JGeometry::TVec3<f32>*)(p + 0x344);
    if (!vel->isZero() || F32(p, 0x10) > 0.0f) {
        JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)vel, (Vec*)(p + 8));
        F32(p, 0x34c) -= 0.25f;
        if (F32(p, 0x10) <= 0.0f) {
            F32(p, 0x10) = 0.0f;
            stopVel(p);
            U8(p, 0x43d) = 3;
        }
        if (U8(p, 0x403) < 0xa8) {
            fn_80276E5C(p);
        } else {
            fn_80276BB8(p);
        }
        fn_80274CB8(p);
        fn_80268B3C(p);
    } else {
        if (U8(p, 0x43d) != 0) {
            U8(p, 0x43d)--;
        } else if (fn_80246B10(p, 0x20) != NULL) {
            if (0.0f == fn_80246F28(p) && U8(PTR(p, 0xbf0), 0xb7) != 0) {
                F32(p, 0x344) = F32(p, 0x368);
                F32(p, 0x348) = F32(p, 0x36c);
            } else {
                F32(p, 0x344) = 2.5f * fn_80247330(p);
                F32(p, 0x348) = 2.5f * -fn_8024712C(p);
            }
            F32(p, 0x34c) = 1.5f;
            fn_8024F0E8(p, 0x10002);
        } else {
            fn_802808E8(p, 1.125f);
        }
        fn_80275D9C(p);
        fn_80274CB8(p);
        fn_80268B3C(p);
        if (U8(p, 0x403) < 0xa8 && ((u8*)PTR(p, 0xbf0) + S32(p, 0x3dc))[0x48] != 0 && fn_80251AEC(p, 0x37)) {
            *(Vec*)(p + 0x350) = ((const Vec*)lbl_8046BBA8)[S32(p, 0x3dc)];
            fn_802A20F0(lbl_8053AC98, p + 0x30c, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
            if (fn_8022486C(p + 0x30c, PTR(p, 0x3b4))) {
                fn_8024F0E8(p, 0x20062);
            } else {
                fn_8024F0E8(p, 0x20061);
            }
        }
    }
    if (PTR(p, 0x12b0) != NULL) {
        JGeometry::TVec3<f32> v(*(JGeometry::TVec3<f32>*)(p + 8));
        switch (S32(p, 0x3dc)) {
        case 0:
            v.x += (U8(p, 0x403) * 14) / 48 + 6;
            break;
        case 1:
            v.x -= (U8(p, 0x403) * 14) / 48 + 6;
            break;
        case 2:
            v.x += 4.0f;
            v.y += (U8(p, 0x403) * 14) / 48 + 2;
            break;
        case 3:
            v.x -= 4.0f;
            v.y -= (U8(p, 0x403) * 14) / 48 + 7;
            break;
        }
        fn_8013CB44(PTR(p, 0x12b0), &v, 0, 1, 1);
    }
    if (PTR(p, 0x12b4) != NULL) {
        JGeometry::TVec3<f32> v(*(JGeometry::TVec3<f32>*)(p + 8));
        if (U8(p, 0x403) < 0xa8) {
            switch (S32(p, 0x3dc)) {
            case 0:
                v.x += 13.0f;
                break;
            case 1:
                v.x -= 13.0f;
                break;
            case 2:
                v.x += 4.0f;
                v.y += 9.0f;
                break;
            case 3:
                v.x -= 4.0f;
                v.y -= 14.0f;
                break;
            }
        } else {
            switch (S32(p, 0x3dc)) {
            case 0:
                v.x -= 19.0f;
                break;
            case 1:
                v.x += 17.0f;
                break;
            case 2:
                v.x += 2.0f;
                v.y -= 17.0f;
                break;
            case 3:
                v.x -= 5.0f;
                v.y += 11.0f;
                break;
            }
        }
        s32 a = fn_8024EE0C(p);
        fn_8013CB44(PTR(p, 0x12b4), &v, fn_8024EE14(p), a - 1, 0);
    }
    if (PTR(p, 0x12b8) != NULL) {
        s32 a = fn_8024EE0C(p);
        fn_8013CB44(PTR(p, 0x12b8), p + 8, fn_8024EE14(p), a - 1, 0);
    }
    if (S32(p, 0x40c) < 30) {
        S32(p, 0x40c)++;
    } else {
        char* g = *(char**)(lbl_8053AB10 + 0x24);
        if (U8(g, 0x7f4) == 0) {
            U8(g, 0x7f5) = 1;
        }
    }
    if ((U8(p, 0xcae) == 1 || U8(p, 0xcaf) == 1) && fn_80251AEC(p, 0)) {
        U8(p, 0x403) = 0;
    }
}
void fn_8027C6C4(char* p) {
    F32(p, 0x34c) -= 0.25f;
    if (F32(p, 0x34c) < -8.0f) {
        F32(p, 0x34c) = -8.0f;
    }
    char* base = (char*)PTR(p, 0x3b4);
    if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
        F32(p, 0x8) += F32(p, 0x344);
        F32(p, 0xc) -= F32(p, 0x34c);
        F32(p, 0x10) = 0.5f;
        RoomRect r = *(RoomRect*)roomOffset(S32(p, 0x3b4));
        r.x0 -= -16.0f;
        r.y0 -= -16.0f;
        r.x1 += -16.0f;
        r.y1 += -16.0f;
        if (F32(p, 0x34c) < 0.0f) {
            if (U8(PTR(p, 0xbf0), 0x4a) != 0 || !rectIn(r, *(JGeometry::TVec2<f32>*)(p + 8))) {
                F32(p, 0x10) = 0.0f;
            }
        }
    } else {
        JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)(p + 0x344), (Vec*)(p + 8));
        if (F32(p, 0x34c) < 0.0f && F32(p, 0x10) <= 0.0f) {
            F32(p, 0x10) = 0.0f;
        }
    }
    if (U8(p, 0x3fa) < 6) {
        U8(p, 0x3fb) = 0;
    } else if (U8(p, 0x3fa) < 7) {
        U8(p, 0x458) = 1;
        U8(p, 0x3fb) = 1;
    } else if (U8(p, 0x3fa) < 8) {
        U8(p, 0x3fb) = 2;
    } else if (U8(p, 0x3fa) < 9) {
        U8(p, 0x3fb) = 3;
    } else if (U8(p, 0x3fa) < 11) {
        U8(p, 0x3fb) = 4;
    } else {
        U8(p, 0x3fb) = 5;
    }
    if (U8(p, 0x3fa) >= 15) {
        char* base2 = (char*)PTR(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base2 + 0x31df) != 0 && fn_8022C76C(S32(p, 0x4)) != 0.0f) {
            JGeometry::TVec3<f32> v;
            fn_8024B298(p, 2, &v.x);
            v.y += 2.0f;
            if (fn_8022461C(&v, PTR(p, 0x3b4)) != 2) {
                landVel(p);
            }
        }
        if (F32(p, 0x34c) < 0.0f && F32(p, 0x10) <= 0.0f) {
            landVel(p);
        }
    } else {
        U8(p, 0x3fa)++;
    }
    fn_80276E5C(p);
    fn_802685D4(p);
}
extern "C" u8 fn_80234B24(s32);
inline bool anyBtn(char* p) {
    u8* s = (u8*)PTR(p, 0xbf0);
    for (s32 i = 0; i < 8; i++) {
        if (s[0xb4] == 1 && (i == 2 || i == 4 || i == 5)) {
            continue;
        }
        if (s[i + 0x48] == 1) {
            return 1;
        }
    }
    return 0;
}
void fn_802791B0(char* p) {
    if (U8(p, 0x3fc) == 0) {
        JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)(p + 0x350), (Vec*)(p + 8));
        if (F32(p, 0x10) < 0.0f) {
            F32(p, 0x10) = 0.0f;
        }
        F32(p, 0x358) -= 0.25f;
        if (F32(p, 0x358) < -4.0f) {
            F32(p, 0x358) = -4.0f;
        }
        U8(p, 0x11e9) = 1;
        RoomRect r = *(RoomRect*)roomOffset(S32(p, 0x3b4));
        r.x0 -= -16.0f;
        r.y0 -= -16.0f;
        r.x1 += -16.0f;
        r.y1 += -16.0f;
        if (!anyBtn(p) && rectIn(r, *(JGeometry::TVec2<f32>*)(p + 8)) &&
            (!Player_IsLinked(p) || fn_802486A0(p) == 4 || fn_80234B24(Player_GetLinkTargetIndex(p)))) {
            goto end;
        }
        if (U8(p, 0x3fa) >= 20) {
            if (fn_8024189C(p) <= 0) {
                fn_80251AEC(p, 0x33);
            } else {
                JGeometry::TVec3<f32>& v = *(JGeometry::TVec3<f32>*)(p + 0x344);
                v.x = F32(p, 0x350);
                v.y = F32(p, 0x354);
                v.z = F32(p, 0x358);
                v.z = 0.0f;
                v.normalize();
                v.scale(-2.0f);
                v.z = 4.0f;
                U8(p, 0x3fc)++;
            }
        }
    } else {
        JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)(p + 0x344), (Vec*)(p + 8));
        if (F32(p, 0x10) < 0.0f && F32(p, 0x34c) < 0.0f) {
            F32(p, 0x10) = 0.0f;
            stopVel(p);
            fn_80251AEC(p, 0);
        } else if (F32(p, 0x34c) >= -4.0f) {
            F32(p, 0x34c) -= 0.25f;
            if (F32(p, 0x34c) < -4.0f) {
                F32(p, 0x34c) = -4.0f;
            }
        }
    }
end:
    if (U8(p, 0x3fa) < 20) {
        U8(p, 0x3fa)++;
    }
    if (U8(p, 0x3fa) < 10) {
        U8(p, 0x3fd) = 0;
    } else if (U8(p, 0x3fa) < 14) {
        U8(p, 0x3fd) = 1;
    } else {
        U8(p, 0x3fd) = 2;
    }
    fn_80268B3C(p);
}
extern "C++" void JPAGetXYZRotateMtx(s16, s16, s16, f32 (*)[4]);
extern "C" const s32 lbl_8046BC98[];
inline void groundDustFx(char* p) {
    if (F32(p, 0x10) <= 0.0f) {
        if (fn_8022461C(p + 8, PTR(p, 0x3b4)) == 0x39) {
            if (PTR(p, 0x1370) == NULL) {
                PTR(p, 0x1370) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3d4, 0, -1, (s32)(p + 0x13a8), NULL, 1, 1.0f);
            } else {
                fn_8013CB44(PTR(p, 0x1370), p + 8, 0, -1, 1);
            }
            killEmitter(p, 0x136c);
        } else {
            if (PTR(p, 0x136c) == NULL) {
                PTR(p, 0x136c) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3d3, 0, -1, (s32)(p + 0x1398), NULL, 1, 1.0f);
            } else {
                fn_8013CB44(PTR(p, 0x136c), p + 8, 0, -1, 1);
            }
            killEmitter(p, 0x1370);
        }
    }
}
inline void landState(char* p) {
    if (U8(p, 0x3fa) >= 20 && F32(p, 0x10) <= 0.0f) {
        if (fn_8024189C(p) <= 0) {
            fn_80251AEC(p, 0x33);
        } else if (S32(p, 0x1248) == 0x4a || S32(p, 0x1248) == 0x4b) {
            fn_80251AEC(p, S32(p, 0x1248));
        } else {
            fn_80251AEC(p, 0);
        }
    }
}
void fn_80279824(char* p) {
    JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)(p + 0x350), (Vec*)(p + 8));
    if (F32(p, 0x10) < 0.0f) {
        F32(p, 0x10) = 0.0f;
    }
    if (F32(p, 0x358) >= -4.0f) {
        F32(p, 0x358) -= 0.25f;
        if (F32(p, 0x358) < -4.0f) {
            F32(p, 0x358) = -4.0f;
        }
    }
    U8(p, 0x3fa)++;
    if (U8(p, 0x3fa) < 10) {
        if (S32(p, 0x488) > 0) {
            U8(p, 0x3fd) = 0;
        } else {
            U8(p, 0x3fd) = 1;
        }
    } else if (U8(p, 0x3fa) < 14) {
        U8(p, 0x3fd) = 2;
    } else {
        U8(p, 0x3fd) = 3;
    }
    if (S32(p, 0x11e4) == 3) {
        U8(p, 0x11e9) = 1;
        RoomRect r = *(RoomRect*)roomOffset(S32(p, 0x3b4));
        r.x0 -= -16.0f;
        r.y0 -= -16.0f;
        r.x1 += -16.0f;
        // TODO: target keeps the (unused) room rect on the stack
        landState(p);
    } else {
        if (F32(p, 0x10) <= 0.0f) {
            fn_802808E8(p, 1.5f);
        }
        landState(p);
    }
    if (PTR(p, 0x135c) != NULL) {
        switch (S32(p, 0x3dc)) {
        case 0:
        case 1:
        case 3:
            fn_8013CB44(PTR(p, 0x135c), p + 8, 0, 0, 1);
            break;
        case 2:
            fn_8013CB44(PTR(p, 0x135c), p + 8, 0, -1, 1);
            break;
        }
        JPAGetXYZRotateMtx(0, lbl_8046BC98[S32(p, 0x3dc)], 0, (f32(*)[4])((char*)PTR(p, 0x135c) + 0x68));
    }
    if (PTR(p, 0x132c) != NULL) {
        F32(p, 0x1344) = F32(p, 0x8);
        F32(p, 0x1348) = F32(p, 0xc);
        F32(p, 0x134c) = F32(p, 0x10);
        if (S32(p, 0x3dc) == 2) {
            F32(p, 0x1348) -= 3.0f;
        } else if (S32(p, 0x3dc) == 3) {
            F32(p, 0x1348) += 3.0f;
        }
        F32(p, 0x1334) = F32(p, 0x1344);
        F32(p, 0x1338) = F32(p, 0x1348);
        F32(p, 0x133c) = F32(p, 0x134c);
        JPAGetXYZRotateMtx(0, lbl_8046BC98[S32(p, 0x3dc)], 0, (f32(*)[4])((char*)PTR(p, 0x132c) + 0x68));
    }
    groundDustFx(p);
    if (S32(p, 0x11e4) == 0x17 || S32(p, 0x11e4) == 0x19) {
        fn_802685D4(p);
    } else {
        fn_80268B3C(p);
    }
}
extern "C" {
u8 fn_8024B24C(char*);
void fn_802D79E8(void* mgr, s32 a, s32 b, f32 x, f32 y);
void fn_80134DE4(void* game, s32 a, s32 b);
void fn_802F601C(void*, void*, s32, s32, f32, f32);
extern const JGeometry::TVec3<f32> lbl_8046BB78[];
}
inline void quake(void* pos, s32 room) {
    if (room < 8) {
        fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), pos, 1, 0, 1.0f, 1.0f);
    }
}
void fn_8027CC90(char* p) {
    JGeometry::TVec3<f32>* vel = (JGeometry::TVec3<f32>*)(p + 0x344);
    if ((!vel->isZero() || F32(p, 0x10) > 0.0f) && U8(p, 0x3fa) >= 11) {
        F32(p, 0x34c) -= 0.25f;
        if (F32(p, 0x34c) < -6.5f) {
            F32(p, 0x34c) = -6.5f;
        }
        char* base = (char*)PTR(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
            F32(p, 0x8) += F32(p, 0x344);
            F32(p, 0xc) -= F32(p, 0x34c);
            F32(p, 0x10) = 0.5f;
            RoomRect r = *(RoomRect*)roomOffset(S32(p, 0x3b4));
            r.x0 -= -16.0f;
            r.y0 -= -16.0f;
            r.x1 += -16.0f;
            r.y1 += -16.0f;
            if (F32(p, 0x34c) < 0.0f) {
                if (U8(PTR(p, 0xbf0), 0x4a) != 0 || !rectIn(r, *(JGeometry::TVec2<f32>*)(p + 8))) {
                    stopVel(p);
                    F32(p, 0x10) = 0.0f;
                }
            }
        } else {
            JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)(p + 0x344), (Vec*)(p + 8));
            if (F32(p, 0x34c) < 0.0f && F32(p, 0x10) <= 0.0f) {
                F32(p, 0x10) = 0.0f;
                stopVel(p);
            }
        }
    }
    if (U8(p, 0x3fa) < 2) {
        U8(p, 0x3fb) = 0;
        U8(p, 0x3fa)++;
    } else if (U8(p, 0x3fa) < 10) {
        U8(p, 0x3fb) = 1;
        U8(p, 0x3fa)++;
    } else if (U8(p, 0x3fa) < 11) {
        U8(p, 0x3fb) = 0;
        U8(p, 0x3fa)++;
    } else if (U8(p, 0x3fa) < 12) {
        U8(p, 0x3fb) = 2;
        char* base = (char*)PTR(p, 0x3b4);
        if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
            S32(p, 0xbf4) = 10;
            U8(p, 0x458) = 1;
        }
        if (F32(p, 0x10) <= 0.0f) {
            u16 g = fn_8022461C(p + 8, PTR(p, 0x3b4));
            if ((g == 3 || g == 14) && !fn_8024B24C(p)) {
                fn_80251AEC(p, 0);
            } else {
                U8(p, 0x458) = 1;
                S32(p, 0xbf4) = 10;
                fn_802D79E8(fn_802D6A9C(), S32(p, 0x3b4), 0, 4.0f, 0.0f);
                fn_80134DE4(lbl_8053AAF8, 1, 0);
                void* pp = p + 8;
                if (S32(p, 0x3b4) < 8) {
                    fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), pp, 1, 0, 1.0f, 1.0f);
                }
                fn_8024F0E8(p, 0x20024);
                fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x23d, 0, 0, 0, NULL, 1, 1.0f);
                fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x23e, 0, 0, 0, NULL, 1, 1.0f);
                fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x23f, 0, 0, 0, NULL, 1, 1.0f);
                if (g == 0x39 || g == 13) {
                    fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3d0, 0, 0, 0, NULL, 1, 1.0f);
                    s32 no = S32(p, 0x4);
                    Actor_CreateByID(fn_801F856C(), 'PEFF', PTR(p, 0x3b4), p + 0x5c0, (no & 3) | 0x2c, -1, no);
                } else {
                    fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3cf, 0, 0, 0, NULL, 1, 1.0f);
                }
                Actor_CreateByID(fn_801F856C(), 'PEFF', PTR(p, 0x3b4), p + 0x8, (S32(p, 0x4) & 3) | 0x14, -1, -1);
                U8(p, 0x3fa)++;
            }
        }
    } else if (U8(p, 0x3fa) < 20) {
        U8(p, 0x3fb) = 2;
        U8(p, 0x3fa)++;
    } else {
        U8(p, 0x3fb) = 2;
        fn_80251AEC(p, 6);
    }
    PlayerOfs* po = (PlayerOfs*)p;
    po->ofs.set(lbl_8046BB78[S32(p, 0x3dc)]);
    po->ofs += po->pos;
    if (PTR(p, 0x1274) != NULL) {
        F32(p, 0x127c) = F32(p, 0x12a4);
        F32(p, 0x1280) = F32(p, 0x12a8);
        F32(p, 0x1284) = F32(p, 0x12ac);
    }
    if (PTR(p, 0x128c) != NULL) {
        F32(p, 0x1294) = F32(p, 0x12a4);
        F32(p, 0x1298) = F32(p, 0x12a8);
        F32(p, 0x129c) = F32(p, 0x12ac);
    }
    s32 id = S32(p, 0x12c0);
    if (id >= 0) {
        char* a = (char*)fn_801F666C(fn_801F856C(), id);
        if (a != NULL) {
            *(JGeometry::TVec3<f32>*)(a + 0xc) = ((PlayerOfs*)p)->ofs;
        }
    }
    setBox(p, 0x4b0, po_->pos.x - 20.0f, po_->pos.y - 20.0f, 20.0f + po_->pos.x, 20.0f + po_->pos.y);
    setBox(p, 0x4a0, po_->pos.x - 12.0f, po_->pos.y - 12.0f, 12.0f + po_->pos.x, 12.0f + po_->pos.y);
    setOfs30c(p, 0.0f, 0.0f);
    S32(p, 0x3f0) = -1;
    fn_802685D4(p);
}
inline void spawnDeathFx(char* p) {
    if (fn_80241544(p) <= 1) {
        fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3b0, 1, 1, 0, NULL, 1, 1.0f);
        fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3b1, 1, 1, 0, NULL, 1, 1.0f);
    } else {
        fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3b2, 1, 1, 0, NULL, 1, 1.0f);
        fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3b3, 1, 1, 0, NULL, 1, 1.0f);
    }
    fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3a7, 1, 1, 0, NULL, 1, 1.0f);
    fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3a8, 1, 1, 0, NULL, 1, 1.0f);
    fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3a9, 1, 1, 0, NULL, 1, 1.0f);
    fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3aa, 1, 1, 0, NULL, 1, 1.0f);
    fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3ab, 1, 1, 0, NULL, 1, 1.0f);
    Actor_CreateByID(fn_801F856C(), 'TNGL', PTR(p, 0x3b4), p + 8, 1, -1, S32(p, 0x4));
}
inline void reviveLife(char* p) {
    if (S32(p, 0xd30) == 420) {
        U8(p, 0xc00) = 0;
        if (fn_8024189C(p) <= 0) {
            addLife(p, fn_802417CC(p) - 4, 0);
        }
    }
}
void fn_8027776C(char* p) {
    if (U8(lbl_8053AAF8, 0x7e) == 0) {
        char* a = (char*)fn_801F666C(fn_801F856C(), fn_801F7A08(fn_801F856C(), 'TNGL'));
        if (a != NULL) {
            if (a == NULL) {
                return;
            }
            if (U8(a, 0x251) == 0) {
                return;
            }
        }
        if (S32(p, 0xd30) < 60) {
            S32(p, 0xd30) = 60;
            S32(p, 0x3dc) = 2;
            S32(p, 0x3e8) = 2;
            spawnDeathFx(p);
        }
        reviveLife(p);
        if (S32(p, 0xd30) >= 480) {
            U8(p, 0x124d) = 0;
            fn_80251AEC(p, 0);
        } else {
            S32(p, 0xd30)++;
        }
    } else {
        if (S32(p, 0xd30) == 60) {
            S32(p, 0xd30)++;
            S32(p, 0x3dc) = 2;
            S32(p, 0x3e8) = 2;
            spawnDeathFx(p);
        }
        reviveLife(p);
        if (S32(p, 0xd30) >= 480) {
            if (!Player_IsLinked(p) || (Player_IsLinked(p) && !fn_80236B50(Player_GetLinkTargetIndex(p)))) {
                U8(p, 0x124d) = 0;
                fn_80251AEC(p, 0);
            }
        } else {
            S32(p, 0xd30)++;
        }
    }
}
extern "C" {
void fn_80230BF4(s32, s32);
void fn_80230C6C(s32);
u8 fn_8025196C(char*, s32);
extern const JGeometry::TVec3<f32> lbl_8046BC38[];
}
void fn_8027A1E0(char* p) {
    s32 oldDir = S32(p, 0x3dc);
    fn_8027439C(p);
    if (F32(p, 0x10) <= 0.0f && (U8(p, 0x3fd) == 1 || U8(p, 0x3fd) == 2)) {
        fn_8027EB04(p);
    }
    if (U8(p, 0x3fd) == 1) {
        JGeometry::TVec3<f32> v;
        v.set(lbl_8046BC38[S32(p, 0x3e8)]);
        v.scale(F32(p, 0xbbc));
        if (F32(p, 0x10) > 0.0f) {
            v.scale(0.7f);
        }
        *(JGeometry::TVec3<f32>*)(p + 8) += v;
        if (F32(p, 0x10) <= 0.0f) {
            fn_8024F0E8(p, 0x40076);
            if (fn_80246D1C(p, 0x100) != NULL) {
                F32(p, 0x34c) = 2.0f;
                fn_8024F0E8(p, 0x2004a);
            }
        }
        if (F32(p, 0x10) > 0.0f || F32(p, 0x34c) > 0.0f) {
            F32(p, 0x34c) -= 0.1f;
            F32(p, 0x10) += F32(p, 0x34c);
            if (F32(p, 0x10) < 0.0f) {
                F32(p, 0x34c) = 0.0f;
                F32(p, 0x10) = 0.0f;
                U8(p, 0x3fb) = 0;
                U8(p, 0x3fa) = 6;
            }
        }
        if (fn_8022461C(p + 8, PTR(p, 0x3b4)) == 0x39) {
            if (PTR(p, 0x1378) != NULL && oldDir != S32(p, 0x3dc)) {
                EmitterObj* e = (EmitterObj*)PTR(p, 0x1378);
                e->mF4 |= 1;
                e->m24 = 1;
                PTR(p, 0x1378) = NULL;
            }
            if (PTR(p, 0x1378) == NULL) {
                if (S32(p, 0x3dc) == 0 || S32(p, 0x3dc) == 1) {
                    PTR(p, 0x1378) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x250, 0, -1, (s32)(p + 0x13a8), NULL, 1, 1.0f);
                } else {
                    PTR(p, 0x1378) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x251, 0, -1, (s32)(p + 0x13a8), NULL, 1, 1.0f);
                }
            } else {
                fn_8013CB44(PTR(p, 0x1378), p + 8, 0, -1, 1);
            }
            killEmitter(p, 0x1374);
        } else {
            if (PTR(p, 0x1374) != NULL && oldDir != S32(p, 0x3dc)) {
                EmitterObj* e = (EmitterObj*)PTR(p, 0x1374);
                e->mF4 |= 1;
                e->m24 = 1;
                PTR(p, 0x1374) = NULL;
            }
            if (PTR(p, 0x1374) == NULL) {
                if (S32(p, 0x3dc) == 0 || S32(p, 0x3dc) == 1) {
                    PTR(p, 0x1374) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x24e, 0, -1, (s32)(p + 0x1398), NULL, 1, 1.0f);
                } else {
                    PTR(p, 0x1374) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x24f, 0, -1, (s32)(p + 0x1398), NULL, 1, 1.0f);
                }
            } else {
                fn_8013CB44(PTR(p, 0x1374), p + 8, 0, -1, 1);
            }
            killEmitter(p, 0x1378);
        }
        U8(p, 0xbb9) = 1;
        setBox(p, 0xbc4, po_->pos.x - 20.0f, po_->pos.y - 20.0f, 20.0f + po_->pos.x, 20.0f + po_->pos.y);
        fn_802A20F0(lbl_8053AC98, p + 0x30c, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
    }
    fn_802685D4(p);
    if (U8(p, 0x3fd) == 1) {
        for (s32 i = 0; i < 8; i++) {
            JGeometry::TVec3<f32> v;
            fn_8024B298(p, i, &v.x);
            v.sub(v, *(JGeometry::TVec3<f32>*)(p + 8));
            v.scale(2.0f, v);
            v.add(v, *(JGeometry::TVec3<f32>*)(p + 8));
            fn_802A20F0(lbl_8053AC98, &v, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
        }
        if (F32(p, 0x10) <= 0.0f && fn_8025196C(p, S32(p, 0x3dc))) {
            if (fn_8022AF5C()) {
                U8(p, 0x3fd) = 2;
                U8(p, 0x3fa) = 0;
                U8(p, 0x3fb) = 0;
                fn_8024F0E8(p, 0x20010);
                if (0.0f != F32(p, 0x348)) {
                    fn_802D79E8(fn_802D6A9C(), S32(p, 0x3b4), 0, 4.0f, 0.0f);
                } else {
                    fn_802D79E8(fn_802D6A9C(), S32(p, 0x3b4), 0, 0.0f, 4.0f);
                }
                switch (S32(p, 0x3dc)) {
                case 0:
                    ((JGeometry::TVec3<f32>*)(p + 0x344))->set(-2.5f, 0.0f, 2.0f);
                    break;
                case 1:
                    ((JGeometry::TVec3<f32>*)(p + 0x344))->set(2.5f, 0.0f, 2.0f);
                    break;
                case 2:
                    ((JGeometry::TVec3<f32>*)(p + 0x344))->set(0.0f, -2.5f, 2.0f);
                    break;
                case 3:
                    ((JGeometry::TVec3<f32>*)(p + 0x344))->set(0.0f, 2.5f, 2.0f);
                    break;
                }
            } else {
                s32 d = S32(p, 0x3dc);
                for (s32 i = 0; i < 4; i++) {
                    if (fn_80243194(p, i)) {
                        switch (d) {
                        case 0: fn_80230BF4(i, 1); break;
                        case 1: fn_80230BF4(i, 0); break;
                        case 2: fn_80230BF4(i, 3); break;
                        case 3: fn_80230BF4(i, 2); break;
                        }
                    }
                }
            }
        }
    } else if (U8(p, 0x3fd) == 2) {
        F32(p, 0x34c) -= 0.25f;
        if (F32(p, 0x34c) < -4.0f) {
            F32(p, 0x34c) = -4.0f;
        }
        JMathInlineVEC::PSVECAdd((Vec*)(p + 8), (Vec*)(p + 0x344), (Vec*)(p + 8));
        if (F32(p, 0x10) < 0.0f && F32(p, 0x34c) < 0.0f) {
            F32(p, 0x344) = 0.0f;
            F32(p, 0x348) = 0.0f;
            F32(p, 0x34c) = 0.0f;
            F32(p, 0x10) = 0.0f;
        }
    }
    if (fn_8025F418(p)) {
        fn_80230C6C(S32(p, 0xd70));
    }
}
extern "C" {
u8 fn_802265DC(const JGeometry::TVec3<f32>&, void*, s32);
f32 fn_8022C82C(s32);
extern const JGeometry::TVec3<f32> lbl_8046BBD8[];
}
inline bool wallAt(char* p, f32 x, f32 y) {
    JGeometry::TVec3<f32> t;
    t.set(x, y, F32(p, 0x11bc));
    return fn_802265DC(t, PTR(p, 0x3b4), 1);
}
inline void addPos(char* p, const JGeometry::TVec3<f32>& a) {
    JGeometry::TVec3<f32> v;
    v.set(a);
    *(JGeometry::TVec3<f32>*)(p + 8) += v;
}
inline void moveToward(char* p) {
    JGeometry::TVec3<f32> t;
    fn_8027FA08(p, &t);
    JGeometry::TVec3<f32>& pos = *(JGeometry::TVec3<f32>*)(p + 8);
    JGeometry::TVec3<f32> d = t - pos;
    d.z = 0.0f;
    if (PSVECMag((Vec*)&d) >= 6.0f) {
        d.normalize();
        d.scale(6.0f);
        pos += d;
    } else {
        pos.set(t);
    }
}
void fn_8027AAD0(char* p) {
    fn_80274728(p);
    fn_8027EB04(p);
    if (fn_802486A0(p) == 3 && !fn_8023434C(S32(p, 0x4))) {
        if (fn_8022C82C(S32(p, 0x4)) > 0.0f) {
            if (!fn_802265DC(JGeometry::TVec3<f32>(24.0f + F32(p, 0x11b4), F32(p, 0x11b8) - 24.0f, F32(p, 0x11bc)), PTR(p, 0x3b4), 1) &&
                !fn_802265DC(JGeometry::TVec3<f32>(24.0f + F32(p, 0x11b4), F32(p, 0x11b8), F32(p, 0x11bc)), PTR(p, 0x3b4), 1) &&
                !fn_802265DC(JGeometry::TVec3<f32>(24.0f + F32(p, 0x11b4), 24.0f + F32(p, 0x11b8), F32(p, 0x11bc)), PTR(p, 0x3b4), 1)) {
                F32(p, 0x11b4) += 2.0f;
            }
        } else if (fn_8022C82C(S32(p, 0x4)) < 0.0f) {
            if (!fn_802265DC(JGeometry::TVec3<f32>(F32(p, 0x11b4) - 24.0f, F32(p, 0x11b8) - 24.0f, F32(p, 0x11bc)), PTR(p, 0x3b4), 1) &&
                !fn_802265DC(JGeometry::TVec3<f32>(F32(p, 0x11b4) - 24.0f, F32(p, 0x11b8), F32(p, 0x11bc)), PTR(p, 0x3b4), 1) &&
                !fn_802265DC(JGeometry::TVec3<f32>(F32(p, 0x11b4) - 24.0f, 24.0f + F32(p, 0x11b8), F32(p, 0x11bc)), PTR(p, 0x3b4), 1)) {
                F32(p, 0x11b4) -= 2.0f;
            }
        }
        if (fn_8022C76C(S32(p, 0x4)) < 0.0f) {
            if (!fn_802265DC(JGeometry::TVec3<f32>(24.0f + F32(p, 0x11b4), 24.0f + F32(p, 0x11b8), F32(p, 0x11bc)), PTR(p, 0x3b4), 1) &&
                !fn_802265DC(JGeometry::TVec3<f32>(F32(p, 0x11b4), 24.0f + F32(p, 0x11b8), F32(p, 0x11bc)), PTR(p, 0x3b4), 1) &&
                !fn_802265DC(JGeometry::TVec3<f32>(F32(p, 0x11b4) - 24.0f, 24.0f + F32(p, 0x11b8), F32(p, 0x11bc)), PTR(p, 0x3b4), 1)) {
                F32(p, 0x11b8) += 2.0f;
            }
        } else if (fn_8022C76C(S32(p, 0x4)) > 0.0f) {
            if (!fn_802265DC(JGeometry::TVec3<f32>(24.0f + F32(p, 0x11b4), F32(p, 0x11b8) - 24.0f, F32(p, 0x11bc)), PTR(p, 0x3b4), 1) &&
                !fn_802265DC(JGeometry::TVec3<f32>(F32(p, 0x11b4), F32(p, 0x11b8) - 24.0f, F32(p, 0x11bc)), PTR(p, 0x3b4), 1) &&
                !fn_802265DC(JGeometry::TVec3<f32>(F32(p, 0x11b4) - 24.0f, F32(p, 0x11b8) - 24.0f, F32(p, 0x11bc)), PTR(p, 0x3b4), 1)) {
                F32(p, 0x11b8) -= 2.0f;
            }
        }
        if (U8(p, 0x3fa) >= 11) {
            JGeometry::TVec3<f32> t;
            fn_8027FA08(p, &t);
            JGeometry::TVec3<f32>& pos = *(JGeometry::TVec3<f32>*)(p + 8);
            JGeometry::TVec3<f32> d = t - pos;
            d.z = 0.0f;
            if (PSVECMag((Vec*)&d) >= 6.0f) {
                d.normalize();
                d.scale(6.0f);
                pos += d;
            } else {
                pos.set(t);
            }
        }
    } else {
        addPos(p, lbl_8046BBD8[S32(p, 0x3e8)]);
    }
    fn_802A20F0(lbl_8053AC98, p + 0x30c, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
    fn_802A20F0(lbl_8053AC98, p + 0x30c, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
    fn_80268B3C(p);
    for (s32 i = 0; i < 8; i++) {
        JGeometry::TVec3<f32> v;
        fn_8024B298(p, i, &v.x);
        v.sub(v, *(JGeometry::TVec3<f32>*)(p + 8));
        v.scale(2.0f, v);
        v.add(v, *(JGeometry::TVec3<f32>*)(p + 8));
        fn_802A20F0(lbl_8053AC98, &v, S32(p, 0x4), PTR(p, 0x3b4), 0, 1);
    }
    fn_8024F0E8(p, 0x20029);
    if (PTR(p, 0x12b8) != NULL) {
        s32 a = fn_8024EE0C(p);
        fn_8013CB44(PTR(p, 0x12b8), p + 8, fn_8024EE14(p), a - 1, 0);
    }
    if (PTR(p, 0x12bc) != NULL) {
        JGeometry::TVec3<f32> w(*(JGeometry::TVec3<f32>*)(p + 8));
        w.x += 20.0f * JMASCos(S16(p, 0x11c0));
        w.y += 20.0f * JMASSin(S16(p, 0x11c0));
        s32 a = fn_8024EE0C(p);
        fn_8013CB44(PTR(p, 0x12bc), &w, fn_8024EE14(p), a + 1, 0);
    }
    if (fn_8022461C(p + 8, PTR(p, 0x3b4)) == 0x39) {
        if (PTR(p, 0x1378) == NULL) {
            PTR(p, 0x1378) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3d4, 0, -1, (s32)(p + 0x13a8), NULL, 1, 1.0f);
        } else {
            fn_8013CB44(PTR(p, 0x1378), p + 8, 0, -1, 1);
        }
        killEmitter(p, 0x1374);
    } else {
        if (PTR(p, 0x1374) == NULL) {
            PTR(p, 0x1374) = fn_8013CC50(PTR(p, 0x3b4), p + 8, 0x3d3, 0, -1, (s32)(p + 0x1398), NULL, 1, 1.0f);
        } else {
            fn_8013CB44(PTR(p, 0x1374), p + 8, 0, -1, 1);
        }
        killEmitter(p, 0x1378);
    }
}
void fn_8027CAA8(char* p) {
    U8(p, 0x458) = 0;
    U8(p, 0x436) = 1;
    char* base = (char*)PTR(p, 0x3b4);
    if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
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
void fn_8027CBB0(char* p) {
    F32(p, 0x10) = 0.0f;
    U8(p, 0x460) = 0;
    U8(p, 0x436) = 0;
    stopEmitter(p, 0x1274);
    stopEmitter(p, 0x128c);
    s32 id = S32(p, 0x12c0);
    if (id >= 0) {
        char* a = (char*)fn_801F666C(fn_801F856C(), id);
        if (a != NULL) {
            U8(a, 0x11c) = 0;
        }
        S32(p, 0x12c0) = -1;
    }
}
}

extern "C" {
inline s32 comboFreeSlot(char* p) {
    if (S32(p, 0x118c) <= 0) {
        return 0;
    }
    if (S32(p, 0x1190) <= 0) {
        return 1;
    }
    if (S32(p, 0x1194) <= 0) {
        return 2;
    }
    if (S32(p, 0x1198) <= 0) {
        return 3;
    }
    return 4;
}
void fn_8027D320(char* p) {
    U8(p, 0x458) = 0;
    U8(p, 0x460) = 1;
    U8(p, 0x436) = 1;
    F32(p, 0x344) = 0.0f;
    F32(p, 0x348) = 0.0f;
    F32(p, 0x34c) = -4.0f;
    char* base = (char*)PTR(p, 0x3b4);
    if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0 && F32(p, 0x10) < 0.5f) {
        F32(p, 0x10) = 0.5f;
    }
    fn_8024F0E8(p, 0x10001);
    fn_8024F0E8(p, 0x20001);
    fn_8024F0E8(p, 0x2000e);
    PlayerOfs* po = (PlayerOfs*)p;
    const f32* o = lbl_8046BB48[S32(p, 0x3dc)];
    po->ofs.x = o[0];
    po->ofs.y = o[1];
    po->ofs.z = o[2];
    po->ofs += po->pos;
    if (PTR(p, 0x1274) == NULL) {
        PTR(p, 0x1274) = fn_8013CC50(PTR(p, 0x3b4), p + 0x12a4, 0xcb, 0, -1, 0, p + 0x1278, 1, 1.0f);
        if (PTR(p, 0x1274) != NULL) {
            ((EmitterObj*)PTR(p, 0x1274))->mF4 |= 0x40;
        }
    }
    if (PTR(p, 0x128c) == NULL) {
        PTR(p, 0x128c) = fn_8013CC50(PTR(p, 0x3b4), p + 0x12a4, 0xcc, 0, -1, 0, p + 0x1290, 1, 1.0f);
        if (PTR(p, 0x128c) != NULL) {
            ((EmitterObj*)PTR(p, 0x128c))->mF4 |= 0x40;
        }
    }
    S32(p, 0x12c0) = Actor_CreateByID(fn_801F856C(), 'PEFF', PTR(p, 0x3b4), p + 0x12a4, (S32(p, 0x4) & 3) | 8, -1, -1);
}
void fn_8027D4F4(char* p) {
    if (comboFreeSlot(p) >= 4) {
        clearCombo(p);
    }
    if (S32(p, 0x45c) == 0 || S32(p, 0x45c) == 1 || S32(p, 0x45c) == 2) {
        S32(p, 0x11cc) = 0x14;
        S32(p, 0x11d0) = S32(p, 0x3dc);
        return;
    }
    S32(p, 0x11cc) = 0;
}
inline s32 comboDirCount2(char* p) {
    PlayerCombo* c = (PlayerCombo*)p;
    for (int i = 0; i < 4; i++) {
        if (!(c->mTimerB[i] > 0)) {
            return i;
        }
        bool any = 0;
        u8* d = c->mDir[i];
        for (int j = 0; j < 4; j++) {
            if (d[j] == 1) {
                any = 1;
            }
        }
        if (!any) {
            return i;
        }
    }
    return 4;
}
void fn_8027DEA0(char* p) {
    bool full = 0;
    if (comboDirCount2(p) >= 3) {
        full = 1;
        clearCombo(p);
    } else {
        fn_80270088(p);
    }
    if (!(fn_802486A0(p) == 3 && !fn_8023434C(S32(p, 0x4))) && (full == 1 || S32(p, 0x11c4) > 0)) {
        S32(p, 0x45c) = 4;
        fn_8027EB04(p);
        if (S32(p, 0x3dc) == 0) {
            ((JGeometry::TVec3<f32>*)(p + 0x344))->set(4.0f, 0.0f, 1.0f);
        } else if (S32(p, 0x3dc) == 1) {
            ((JGeometry::TVec3<f32>*)(p + 0x344))->set(-4.0f, 0.0f, 1.0f);
        } else if (S32(p, 0x3dc) == 2) {
            ((JGeometry::TVec3<f32>*)(p + 0x344))->set(0.0f, 4.0f, 1.0f);
        } else {
            ((JGeometry::TVec3<f32>*)(p + 0x344))->set(0.0f, -4.0f, 1.0f);
        }
        F32(p, 0x10) = 0.0f;
    } else if (!(fn_802486A0(p) == 3 && !fn_8023434C(S32(p, 0x4))) && S32(p, 0x11cc) > 0 &&
               ((S32(p, 0x11d0) == 0 && fn_80247330(p) < 0.0f) || (S32(p, 0x11d0) == 1 && fn_80247330(p) > 0.0f) ||
                (S32(p, 0x11d0) == 2 && fn_8024712C(p) > 0.0f) || (S32(p, 0x11d0) == 3 && fn_8024712C(p) < 0.0f))) {
        S32(p, 0x45c) = 3;
    } else if (comboDirCount2(p) == 0) {
        if (comboFreeSlot(p) <= 2) {
            S32(p, 0x45c) = 2;
        } else if (comboFreeSlot(p) == 3) {
            S32(p, 0x45c) = 0;
        } else {
            S32(p, 0x45c) = 1;
        }
    } else {
        if (comboFreeSlot(p) <= 2) {
            S32(p, 0x45c) = 0;
        } else {
            S32(p, 0x45c) = 1;
        }
    }
    if (S32(p, 0x45c) == 4) {
        U8(p, 0x458) = 0;
        S32(p, 0xbf4) = 8;
        fn_8024F0E8(p, 0x1000b);
    } else {
        U8(p, 0x458) = 1;
        S32(p, 0xbf4) = 4;
        fn_8024F0E8(p, 0x10000);
    }
    fn_8024F0E8(p, 0x20000);
    S32(p, 0x3f0) = S32(p, 0x3dc);
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
