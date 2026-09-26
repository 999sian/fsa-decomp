// TU 0x8026fc20-0x8027e5bc: player-class methods (Link object, see tu_8023FBF0).
// A few small bodies originally from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define U16(p, o) (*(u16*)((char*)(p) + (o)))
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
void fn_80251AEC(char*, s32);
void fn_8024F0E8(char*, s32);
void fn_80268B3C(char*);
void fn_802685D4(char*);
char* fn_802D6A9C(void);
bool fn_802413F0(char*);
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

struct PlayerAreas2 {
    u8 pad0[0xef0];
    s32 mId[0x50];
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
BOOL fn_80270C88(char* p) {
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
    BOOL in = inBox2(box, F32(p, 0x8) + lbl_8046BD68[S32(p, 0x3dc)].x, F32(p, 0xc) + lbl_8046BD68[S32(p, 0x3dc)].y);
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
    BOOL in = inBox2(box, F32(p, 0x8) + lbl_8046BD48[S32(p, 0x3dc)].x, F32(p, 0xc) + lbl_8046BD48[S32(p, 0x3dc)].y);
    if (!(u8)in) {
        return 0;
    }
    if (S32(p, 0xda4) < 0) {
        S32(p, 0xda4) = id;
    }
    return 1;
}
bool fn_802729F0(char* p, s32 id) {
    for (int i = 0; i < 0x50; i++) {
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
inline f32* roomOffset(s32 room) {
    char* r = fn_802D6A9C();
    return room < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
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
void fn_8027C6B8(char* p) { U8(p, 0x436) = 0; }
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
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
