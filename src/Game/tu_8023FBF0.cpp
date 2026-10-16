// TU 0x8023FBF0-0x80255F4C: player object (0x1250-byte Link actor) accessors and helpers.
// Small bodies originally from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define U16(p, o) (*(u16*)((char*)(p) + (o)))
#define S16(p, o) (*(s16*)((char*)(p) + (o)))
#define S32(p, o) (*(s32*)((char*)(p) + (o)))
#define F32(p, o) (*(f32*)((char*)(p) + (o)))
#define PTR(p, o) (*(void**)((char*)(p) + (o)))
#define V3(p, o) (*(JGeometry::TVec3<f32>*)((char*)(p) + (o)))
#define STATE_OR2(p, o, a, b)          \
    s32 s = S32(p, o);                 \
    BOOL r = 0;                        \
    if (s == (a) || s == (b)) r = 1;   \
    return r
// Linked-player forwarders: if linked to another player (0xd60 >= 0), ask the global table.
#define FWD(addr, callee, off)                     \
    s32 fn_##addr(char* p) {                       \
        s32 linked = S32(p, 0xd60);                \
        if (linked >= 0) {                         \
            return fn_##callee(linked);            \
        }                                          \
        return S32(p, off);                        \
    }

// Game code is built without auto-inlining; only explicit inlines expand.
#pragma auto_inline off

inline s32 getDA4(char* p) {
    s32 v = S32(p, 0xda4);
    if (v < 0) return -1;
    return v;
}

extern "C" char* lbl_8053AAF8;

struct GameRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};

inline f32 gameRnd() { return ((GameRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1(); }

inline s32 playerIdx(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return linked;
    }
    return S32(p, 0x4);
}

typedef JGeometry::TVec3<f32> TrailPos;
struct PlayerTrail {
    u8 pad0[0x8];
    f32 x, y, z;
    u8 pad14[0x38 - 0x14];
    TrailPos pos[0x31];
    u8 onGround[0x31];
};

extern "C" bool fn_80251BFC(char*, s32);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);

inline char* getActor(s32 id) { return (char*)fn_801F666C(fn_801F856C(), id); }

inline bool changeState(char* p, s32 st, u8 flag) {
    if (!fn_80251BFC(p, st)) {
        return false;
    }
    S32(p, 0x1244) = st;
    U8(p, 0x124c) = 1;
    if (flag) {
        U8(p, 0x124d) = 1;
    }
    if (S32(p, 0xd60) < 0 && U8(p, 0xcfe) == 1 && S32(p, 0x1244) != 0) {
        U8(p, 0xcfe) = 0;
    }
    return true;
}

extern "C" bool fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);

inline s32 countSharing(const char* p) {
    s32 linked;
    s32 c;
    s32 i;
    s32 me;
    c = 0;
    me = S32(p, 0x4);
    for (i = 0; i < 4; i++) {
        if (i == me) {
            c++;
        } else if (fn_8022F514(i)) {
            if ((linked = S32(p, 0xd60)) >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                linked = S32(p, 0x4);
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}

inline s32 countSharingH(const char* p) {
    s32 i;
    s32 c;
    s32 linked;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            if ((linked = S32(p, 0xd60)) >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                linked = S32(p, 0x4);
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}

extern "C" char* fn_802D6A9C(void);

inline f32* roomOffset(s32 room) {
    char* r = fn_802D6A9C();
    return room < 8 ? (f32*)(r + 0xcc) : (f32*)(r + 0xdc);
}

inline void setOff(JGeometry::TVec3<f32>* v, const JGeometry::TVec3<f32>* src, f32 dx, f32 dy) {
    v->x = src->x;
    v->y = src->y;
    v->z = src->z;
    v->x += dx;
    v->y += dy;
}

inline bool isIdleState(char* p) {
    return S32(p, 0x1240) == 0x0 || S32(p, 0x1240) == 0x2 || S32(p, 0x1240) == 0x3 || S32(p, 0x1240) == 0x4 ||
           S32(p, 0x1240) == 0x8 || S32(p, 0x1240) == 0x4a || S32(p, 0x1240) == 0x4b;
}

inline bool isBusyState(char* p) {
    return S32(p, 0x1240) == 1 || (U16(p, 0x3c4) >= 0x1bf && U16(p, 0x3c4) < 0x1c6);
}

inline bool isShrinking(char* p) {
    bool r = false;
    if (S32(p, 0x1240) == 0x49 || S32(p, 0x1244) == 0x49) {
        r = true;
    }
    return r;
}

inline bool inOtherRoom(char* p) {
    bool r = false;
    if (U8(p, 0xce8) != 0 && S32(p, 0x3b4) != 8) {
        r = true;
    }
    return r;
}

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);

#define DELETE_JPA(p, off) \
    if (PTR(p, off) != NULL) { \
        void* mgr = PTR((char*)fn_8013C824(), 0xc); \
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, PTR(p, off)); \
        PTR(p, off) = NULL; \
    }

extern "C" s32 fn_8022CAF8(s32);

inline s32 getMode(char* p) {
    if (countSharing(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
inline s32 getModeH(const char* p) {
    if (countSharingH(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}

inline u8 btn(char* p, s32 i) { return (*(u8**)(p + 0xbf0))[i + 0x48]; }

extern "C" char* lbl_8053AED0;
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023725C(s32);

inline BOOL setItem(char* p, s32 a, s32 b) {
    S32(p, 0xc10) = a;
    if (S32(p, 0xc10) == 0) {
        S32(p, 0xc14) = 0;
    } else if (S32(p, 0xc10) != 0) {
        if (b < 2 || S32(p, 0xc10) != 2) {
            S32(p, 0xc14) = b;
            U8(lbl_8053AED0, 0x255) |= (u8)(1 << S32(p, 0x4));
        }
    }
    if (S32(p, 0xc10) != 0) {
        U8(lbl_8053AED0, 0x255) |= (u8)(1 << S32(p, 0x4));
        if (U8(lbl_8053AAF8, 0x7f) == 0 && S32(p, 0x464) < 0x3c) {
            S32(p, 0x464) = 0x3c;
        }
    }
    return 1;
}

inline s32 getItem(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_802373EC(linked);
    }
    return S32(p, 0xc10);
}

inline s32 getItemLevel(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8023725C(linked);
    }
    if (S32(p, 0xc10) == 0) {
        return 0;
    }
    return S32(p, 0xc14);
}

inline void resetTrail(char* p) {
    PlayerTrail* t = (PlayerTrail*)p;
    for (int i = 0; i < 0x31; i++) {
        t->pos[i].x = t->x;
        t->pos[i].y = t->y;
        t->pos[i].z = t->z;
        if (t->z > 0.0f) {
            t->onGround[i] = 1;
        } else {
            t->onGround[i] = 0;
        }
    }
}

extern "C" {
extern char* lbl_8053AAF8;
extern void* lbl_8053AF80;
bool fn_8022AF5C(void);
bool fn_8023EFEC(s32);
bool fn_8023EA28(s32);
bool fn_80270C88(char*);
void fn_80248004(char*, s32, s32);
bool fn_80236890(void);
bool fn_802D7804(char*, s32, s32);
bool fn_8028FBA0(char*);
f32* fn_80238430(s32);
bool fn_8026E5F8(char*, JGeometry::TVec2<f32>*);
void fn_80458880(void*, u32, s32);
s32 fn_8040305C(void*);
void* fn_804033D4(s32);
char* fn_802D6A9C(void);
s32 Actor_CreateByID(void* mgr, u32 id, void* owner, void* pos, u32 param, s32 a, s32 b);
void fn_8024D134(char*);
s32 fn_8022CAF8(s32);
bool fn_8025F500(char*);
void* fn_801F856C(void);
s32 fn_801F78F4(void*, u32, s32);
void fn_802C1778(void*);
void fn_802C1674(void*);
f32* fn_8023E724(s32);
void fn_802362C4(s32);
bool fn_80236B50(s32);
bool fn_80251BFC(char*, s32);
void fn_80272160(char*, s32, void*, s32);
bool fn_80239D38(void);
bool fn_8022F514(s32);
bool fn_8022C1D8(s32);
void fn_80237524(s32);
bool fn_80270A8C(char*);
void fn_8024B2E0(char*);
void fn_8024E694(char*, s32, s32);
bool fn_8030381C(s32);
void fn_803037D4(s32, s32);
void fn_80458F04(void*, s32);
extern void* lbl_8053AB10;
void fn_8030AE84(void*, f32*);
void fn_8030C2A8(void*, const JGeometry::TVec3<f32>*);
void fn_8030B084(void*, s32, JGeometry::TVec3<f32>);
s32 fn_8023697C(s32);
s32 fn_8022F3DC(s32);
void fn_8023619C(s32);
void fn_802702C4(char*);
extern void* lbl_8053AD30;
u8 fn_8023BD70(s32);
s32 fn_8022EA0C(s32);
s32 fn_8027218C(char*);
u8 fn_80236D14(s32);
u8 fn_80236E3C(s32);
s32 fn_80237060(s32);
s32 fn_802375B0(s32);
s32 fn_80237810(s32);
s32 fn_802376D8(s32);
s32 fn_80234004(s32);
s32 fn_802373EC(s32);
s32 fn_80237774(s32);
s32 fn_80236100(s32);
s32 fn_80236228(s32);
s32 fn_80237488(s32);
s32 fn_8023BEA8(s32);
s32 fn_8023C36C(s32);
u8 fn_8030B110(void*, s32, JGeometry::TVec3<f32>);
u8 fn_8022E438(s32, s32);
s32 fn_8030AAF4(s32);
s32 fn_8030A308(void*, s32);
s32 fn_8030A3B0(void*, s32);
void SetField_0x98(void*, s32);
u8 fn_80243C64(char*);
void* fn_801F856C();
extern char* lbl_8053AED0;
extern f32 lbl_80540038;
s32 fn_8023725C(s32);
void fn_8023764C(s32, s32);
s32 fn_80230E1C(s32, u8);
u8 fn_8025F448(char*);
u8 fn_8024F63C(char*);
u8 fn_80250D30(char*);
u8 fn_802729F0(char*, s32);
u8 fn_8024FEBC(char*);
s32 fn_8024FF6C(char*);
u8 fn_8024FE78(char*);
u8 fn_8024FEFC(char*);
void* fn_801F666C(void*, s32);
void fn_8026942C(void*, s32, void*);
s32 fn_8026947C(void*);

// ---- BODY ----
void fn_8023FBF0(char* p) {
    if (U8(p, 0x42c) != 0) {
        U8(p, 0x42d) = 1;
    }
}
u8 fn_8023FC08(char* p) { return U8(p, 0x42c); }
void fn_8023FC10(char* p, s32 v) {
    if (S32(p, 0xca8) < v) {
        S32(p, 0xca8) = v;
    }
}
void* fn_8023FC24(char* p) { return PTR(p, 0xbec); }
s32 fn_8023FC2C(char* p) {
    if (U8(p, 0xd2d) == 1) {
        return 0;
    }
    if (U8(p, 0x498) == 0) {
        return 0;
    }
    return S32(p, 0x494);
}
u8 fn_8023FF50(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8023BD70(linked);
    }
    return U8(p, 0x1202);
}
u8 fn_8023FF88(char* p) { return U8(p, 0x1200); }
void fn_8023FF90(char* p, const f32* v) {
    F32(p, 0xc90) = v[0];
    F32(p, 0xc94) = v[1];
    F32(p, 0xc98) = v[2];
}
BOOL fn_8023FFAC(char* p) { return F32(p, 0xc8c) < 1.0f; }
inline s32 countSharing2(char* p) {
    s32 c = 0;
    s32 i = c;
    s32 linked;
    s32 me;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            linked = S32(p, 0xd60);
            if (linked >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                me = S32(p, 0x4);
                if (me == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
inline s32 countSharing3(char* p) {
    s32 me;
    s32 linked;
    s32 c;
    s32 i;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            if ((linked = S32(p, 0xd60)) >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                me = S32(p, 0x4);
                if (me == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
inline s32 getMode3(char* p) {
    if (countSharing3(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
inline s32 getMode2(char* p) {
    if (countSharing2(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
inline s32 linkRank2(char* p) {
    s32 l;
    s32 c;
    s32 i;
    if (S32(p, 0xd60) < 0) {
        return 0;
    }
    c = 0;
    for (i = 0; i < S32(p, 0x4); i++) {
        l = S32(p, 0xd60);
        if (l == fn_8022F3DC(i)) {
            c++;
        }
    }
    return c + 1;
}
inline s32 linkIdx(char* p) { return S32(p, 0xd60) >= 0 ? fn_80234004(S32(p, 0xd60)) : S32(p, 0x1224); }
inline BOOL isLinkOwner(char* p) {
    u8 bit = 1 << S32(p, 0x4);
    if (!(U8(lbl_8053AAF8, 0x82) & bit) && S32(p, 0xd60) < 0) {
        return 1;
    }
    if (getMode2(p) == 4) {
        s32 v = linkIdx(p);
        return v != linkRank2(p);
    }
    return ((u32)S32(p, 0xd60) >> 31) ^ 1;
}
s32 fn_80236630(s32);
s32 fn_802366CC(s32);
s32 fn_80236768(s32);
s32 fn_8023FFC4(char* p) {
    if ((u8)isLinkOwner(p)) {
        return fn_80236630(fn_8022EA0C(S32(p, 0x4)));
    }
    if (U8(p, 0xbe8)) {
        return S32(p, 0xbe4);
    }
    return 0;
}
s32 fn_8024018C(char* p) {
    if ((u8)isLinkOwner(p)) {
        return fn_802366CC(fn_8022EA0C(S32(p, 0x4)));
    }
    if (U8(p, 0x42c)) {
        return S32(p, 0xbe0);
    }
    return 0;
}
s32 fn_80240354(char* p) {
    if ((u8)isLinkOwner(p)) {
        return fn_80236768(fn_8022EA0C(S32(p, 0x4)));
    }
    if (U8(p, 0xbdc)) {
        return S32(p, 0xbd8);
    }
    return 0;
}
inline s32 cnt2(char* p) {
    s32 linked;
    s32 c;
    s32 i;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            if ((linked = S32(p, 0xd60)) >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                linked = S32(p, 0x4);
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
void fn_8024051C(char* p) {
    s32 mode;
    if (cnt2(p) <= 1) {
        mode = 5;
    } else if (S32(p, 0xd60) >= 0) {
        mode = fn_8022CAF8(S32(p, 0xd60));
    } else {
        mode = S32(p, 0x120c);
    }
    if (mode != 4 && U8(p, 0x1215) == 0) {
        U8(p, 0x43e) = 1;
    }
}
s32 fn_80240628(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return linked;
    }
    return S32(p, 0x4);
}
u32 Player_GetLinkTargetIndex(char* p) { return S32(p, 0xd60); }
s32 fn_8024064C(const char* p) { return fn_8022EA0C(*(const s32*)(p + 4)); }
inline s32 linkRank(char* p) {
    s32 n;
    s32 linked = S32(p, 0xd60);
    if (linked < 0) {
        return 0;
    }
    n = S32(p, 0x4);
    s32 c = 0;
    for (int i = 0; i < n; i++) {
        if (linked == fn_8022F3DC(i)) {
            c++;
        }
    }
    return c + 1;
}
BOOL fn_80240670(char* p) {
    u8 bit = 1 << S32(p, 0x4);
    if (!(U8(lbl_8053AAF8, 0x82) & bit) && S32(p, 0xd60) < 0) {
        return 1;
    }
    if (getMode(p) == 4) {
        s32 v = linkIdx(p);
        return v != linkRank(p);
    }
    return ((u32)S32(p, 0xd60) >> 31) ^ 1;
}
BOOL Player_IsLinked(char* p) { return ((u32)S32(p, 0xd60) >> 31) ^ 1; }
BOOL fn_80240818(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 0x49 || S32(p, 0x1244) == 0x49) {
        r = 1;
    }
    return r;
}
s32 ClaimField_0x11f4(char* p, s32 val) {
    if (S32(p, 0x11f4) <= 0) {
        S32(p, 0x11f4) = val;
        return 1;
    } else {
        return 0;
    }
}
u8 GetField_0x436(char* p) { return U8(p, 0x436); }
void* GetPtrField_0x4(char* p) { return PTR(p, 0x4); }
u8 GetField_0xcfe(char* p) { return U8(p, 0xcfe); }
void IncrementField_0x1224(char* p) { S32(p, 0x1224) += 1; }
FWD(80240888, 80234004, 0x1224)
u8 fn_802408C0(char* p) { return U8(p, 0x1217); }
void fn_802408C8(char* p, s32 a, const JGeometry::TVec3<f32>& v) {
    if (S32(p, 0xd60) >= 0) {
        return;
    }
    if (fn_8030B110(PTR(p, 0xbec), a, v) && !fn_80270A8C(p) && U8(p, 0xce8) == 0) {
        fn_80248004(p, 5, 0);
        if (getMode3(p) == 5) {
            PlayerTrail* t = (PlayerTrail*)p;
            for (int i = 0; i < 0x31; i++) {
                t->pos[i].x = v.x;
                t->pos[i].y = v.y;
                t->pos[i].z = v.z;
                t->pos[i].z = 0.0f;
                t->onGround[i] = 0;
            }
            U8(p, 0x1216) = 1;
        }
    }
}
u8 fn_80233EDC(s32);
bool fn_80240B84(char* p) {
    if ((u8)isLinkOwner(p)) {
        return fn_80233EDC(fn_8022EA0C(S32(p, 0x4)));
    }
    bool r = 0;
    if (S32(p, 0x1240) == 0x1b || S32(p, 0x1244) == 0x1b) {
        r = 1;
    }
    return r;
}
u8 fn_80240AD4(char* p) {
    if (U8(p, 0xce8) != 0) {
        return 0;
    }
    return U8(p, 0x1216);
}
u8 fn_80240AF0(char* p) { return U8(p, 0x1215); }
u8 fn_80240AF8(char* p) { return U8(p, 0x1214); }
BOOL fn_80240B00(char* p) { STATE_OR2(p, 0x1240, 0xf, 0x10); }
BOOL fn_80240B20(char* p) { return S32(p, 0x1240) == 0x11 ? 1 : 0; }
BOOL fn_80240B34(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 0x51 && S32(p, 0x46c) >= 0xd2) {
        r = 1;
    }
    return r;
}
BOOL fn_80240B5C(char* p) { return S32(p, 0x1240) == 0x51 ? 1 : 0; }
BOOL fn_80240B70(char* p) { return S32(p, 0x1240) == 0x50 ? 1 : 0; }
BOOL fn_80240D50(char* p) { return S32(p, 0x1240) == 0x4f ? 1 : 0; }
BOOL fn_80240D64(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 0x4c || S32(p, 0x1240) == 0x4d || S32(p, 0x1240) == 0x4e) r = 1;
    return r;
}
BOOL fn_80240D8C(char* p) { STATE_OR2(p, 0x1244, 0x38, 0x13); }
BOOL fn_80240DAC(char* p) { STATE_OR2(p, 0x1240, 0x38, 0x13); }
bool fn_80240DCC(char* p) {
    bool r = true;
    if (!isShrinking(p)) {
        bool a = false;
        bool b = false;
        if (inOtherRoom(p)) {
            if (!fn_802D7804(fn_802D6A9C(), S32(p, 0x3b4), 1)) {
                b = true;
            }
        }
        if (b) {
            bool c = true;
            s32 room = S32(p, 0xce4);
            if (room != 8 && !fn_802D7804(fn_802D6A9C(), room, 1)) {
                c = false;
            }
            if (c) {
                a = true;
            }
        }
        if (!a) {
            r = false;
        }
    }
    return r;
}
BOOL fn_80240ED4(char* p) { STATE_OR2(p, 0x1240, 0x1e, 0x32); }
BOOL fn_80240EF4(char* p) { STATE_OR2(p, 0x1240, 0x42, 0x43); }
BOOL fn_80240F14(char* p) { return S32(p, 0x1240) == 0x41 ? 1 : 0; }
BOOL fn_8024119C(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 0xc && S32(p, 0x11e4) != 0xc) {
        r = 1;
    }
    return r;
}
BOOL fn_802411C4(char* p) { return S32(p, 0x1240) == 0xc ? 1 : 0; }
BOOL fn_802411D8(char* p) { return S32(p, 0x1240) == 0xa ? 1 : 0; }
BOOL fn_802411EC(char* p) { return S32(p, 0x1240) == 0x1 ? 1 : 0; }
BOOL fn_80241200(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 1 || (U16(p, 0x3c4) >= 0x1bf && U16(p, 0x3c4) < 0x1c6)) {
        r = 1;
    }
    return r;
}
BOOL fn_80241230(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 0xb || S32(p, 0x1244) == 0xb) {
        r = 1;
    }
    return r;
}
BOOL fn_80241258(char* p) { return fn_8027218C(p) == 4 ? 1 : 0; }
BOOL fn_80241284(char* p) { STATE_OR2(p, 0x1240, 0x9, 0xa); }
BOOL fn_802412A4(char* p) { STATE_OR2(p, 0x1240, 0x4a, 0x4b); }
u8 fn_802412C4(char* p) { return U8(p, 0x458); }
u8 fn_802412CC(char* p) { return U8(p, 0x460); }
void fn_802412D4(char* p) { U8(p, 0xcaf) = 1; }
bool fn_802412E0(char* p) {
    return S32(p, 0x1240) == 0xd || S32(p, 0x1240) == 0xe || S32(p, 0x1240) == 0x11 || S32(p, 0x1240) == 0x12 || S32(p, 0x1240) == 0x1a || S32(p, 0x1240) == 0x3c || S32(p, 0x1240) == 0x3b || S32(p, 0x1240) == 0x3a || S32(p, 0x1240) == 0x47;
}
bool fn_80241338(char* p) {
    return S32(p, 0x1240) == 0x4 || S32(p, 0x1240) == 0x8 || S32(p, 0x1240) == 0x39 || S32(p, 0x1240) == 0x44 || S32(p, 0x1240) == 0x45 || S32(p, 0x1240) == 0x3d || S32(p, 0x1240) == 0x37;
}
bool fn_80241380(char* p) {
    return S32(p, 0x1240) == 0x0 || S32(p, 0x1240) == 0x2 || S32(p, 0x1240) == 0x3 || S32(p, 0x1240) == 0x4 || S32(p, 0x1240) == 0x8 || S32(p, 0x1240) == 0x4a || S32(p, 0x1240) == 0x4b;
}
BOOL fn_802413C8(char* p) { STATE_OR2(p, 0x1240, 0x8, 0x37); }
u8 Player_GetField_0x454(char* p) { return U8(p, 0x454); }
BOOL fn_802413F0(char* p) {
    if (U8(p, 0xc80) == 0) return 0;
    if (U8(p, 0xcee) != 0) return 0;
    if (U8(p, 0x1215) != 0) return 0;
    if (U8(p, 0xca0) == 0) return 0;
    return U8(p, 0xce9) != 0;
}
void fn_80241454(char* p, u8 v) { U8(p, 0xc80) = v; }
char* fn_8024145C(char* p) {
    if (U8(p, 0xd64) == 1) {
        return p + 0x2f4;
    }
    return p + 0x8;
}
BOOL fn_80241478(char* p) { return S32(p, 0x1240) == 0xe ? 1 : 0; }
void fn_8024148C(char* p) { U8(p, 0xb7b) = 1; }
u8 fn_80241498(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_80236D14(linked);
    }
    return U8(p, 0xb7b);
}
void fn_802414D0(char* p) { U8(p, 0xb7a) = 1; }
u8 fn_802414DC(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_80236E3C(linked);
    }
    return U8(p, 0xb7a);
}
s32 fn_80241514(char* p, s32 v) {
    S32(p, 0xc18) = v;
    if (U8(lbl_8053AAF8, 0x7f) == 0 && S32(p, 0x464) < 0x3c) {
        S32(p, 0x464) = 0x3c;
    }
    return 1;
}
FWD(80241544, 80237060, 0xc18)
s32 fn_8024157C(char* p, s32 v) {
    if (S32(p, 0xc10) == 0 || (v >= 2 && S32(p, 0xc10) == 2)) {
        return 0;
    }
    S32(p, 0xc14) = v;
    U8(lbl_8053AED0, 0x255) |= (u8)(1 << S32(p, 0x4));
    return 1;
}
s32 fn_802415CC(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8023725C(linked);
    }
    if (S32(p, 0xc10) == 0) {
        return 0;
    }
    return S32(p, 0xc14);
}
FWD(802416C4, 802373EC, 0xc10)
FWD(80241794, 802375B0, 0xc08)
FWD(802417CC, 80237810, 0xbf8)
BOOL fn_80241618(char* p, s32 a, s32 b) { return setItem(p, a, b); }
void fn_802416FC(char* p, s32 n) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        fn_80237524(linked);
        return;
    }
    if (U8(lbl_8053AAF8, 0x7f) == 0) {
        if (S32(p, 0xbfc) <= 0 || fn_80270A8C(p)) {
            return;
        }
    }
    S32(p, 0xc08) += n;
    if (S32(p, 0xc08) > 0x180) {
        S32(p, 0xc08) = 0x180;
    }
}
void fn_80241804(char* p, s32 v) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        fn_8023764C(linked, v);
    } else if (v < 0) {
        S32(p, 0xbfc) = 0;
    } else if (v >= S32(p, 0xbf8)) {
        S32(p, 0xbfc) = S32(p, 0xbf8);
    } else {
        S32(p, 0xbfc) = v;
    }
}
FWD(80241864, 802376D8, 0xbfc)
s32 fn_8024189C(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_80237774(linked);
    }
    if (U8(p, 0xc00) != 0) {
        return 0;
    } else {
        return S32(p, 0xbfc);
    }
}
FWD(802418E8, 80236100, 0xc04)
s32 fn_80241920(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_80236228(linked);
    }
    s32 val = S32(p, 0xc04);
    u32 mask = ((u32)val >> 31) - 1;
    return val & mask;
}
u8 fn_802349EC(s32);
u8 fn_80241964(char* p) {
    if (countSharing3(p) <= 1) {
        return 1;
    }
    if (getMode2(p) == 4) {
        return 1;
    }
    for (s32 i = 0; i < 4; i++) {
        if (i != S32(p, 0x4) && fn_8022E438(S32(p, 0x4), i) && !fn_802349EC(i)) {
            return 0;
        }
    }
    return 1;
}
void fn_80241B44(char* p, f32* out) {
    if (S32(p, 0x3b4) < 8) {
        char* r = (char*)PTR(lbl_8053AB10, 0x24);
        out[0] = F32(r, 0x164);
        out[1] = F32(r, 0x168);
        out[2] = F32(r, 0x16c);
        out[3] = F32(r, 0x170);
    } else {
        fn_8030AE84(PTR(p, 0xbec), out);
    }
}
void fn_80241DD0(char* p, s32 room, const JGeometry::TVec3<f32>& v) {
    if (room < 8) {
        fn_8030C2A8(PTR(lbl_8053AB10, 0x24), &v);
    } else {
        fn_8030B084(PTR(p, 0xbec), room, v);
    }
}
void fn_80241E28(char* p, s32 a, const JGeometry::TVec3<f32>& v) {
    fn_8030B110(PTR(p, 0xbec), a, v);
}
char* fn_802422C4(char* p) { return (char*)PTR(p, 0xbf0) + 0x14; }
void fn_80242560(char* p) {
    if (fn_8025F500(p) && S32(p, 0xd6c) == 'KEY0') {
        void* a = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
        if (a != NULL) {
            fn_802C1778(a);
        }
    }
    s32 id = -1;
    for (;;) {
        id = fn_801F78F4(fn_801F856C(), 'KEY0', id);
        if (id < 0) {
            break;
        }
        void* a = getActor(id);
        if (a != NULL) {
            fn_802C1674(a);
            fn_802C1778(a);
        }
    }
    S32(p, 0x3b0) = 3;
}
BOOL fn_80242624(char* p, const JGeometry::TVec3<f32>& v) {
    if (changeState(p, 0x4d, 1)) {
        F32(p, 0x374) = v.x;
        F32(p, 0x378) = v.y;
        F32(p, 0x37c) = v.z;
        return 1;
    }
    return 0;
}
s32 fn_802426E0(char* p, s32 v) {
    if (S32(p, 0xd8c) != v) {
        return 0;
    }
    U8(p, 0xd90) = 1;
    return 1;
}
BOOL fn_80242704(char* p, s32 v) {
    if ((u8)isLinkOwner(p)) {
        return 0;
    }
    if (fn_8025F448(p)) {
        return 0;
    }
    if (changeState(p, 0x4c, 1)) {
        S32(p, 0xd8c) = v;
        return 1;
    }
    return 0;
}
void fn_80242BC0(char* p) {
    if (U8(p, 0x454) != 0) {
        return;
    }
    if (S32(p, 0xbd8) > 0) {
        S32(p, 0xbd8)--;
        if (S32(p, 0xbd8) > 0 && S32(p, 0xbd8) % 60 == 0 && fn_8030381C(S32(p, 0x4))) {
            fn_803037D4(S32(p, 0x4), 2);
        }
    }
    if (S32(p, 0xd60) < 0 && U8(p, 0xbdc) != 0 && S32(p, 0xbd8) <= 0 && S32(p, 0x3b4) >= 8) {
        fn_8028FBA0(p);
    }
    if (S32(p, 0x3b4) < 8 && S32(p, 0xbd8) > 0) {
        S32(p, 0xbd8) = 0;
    }
}
void fn_80242CB0(char* p) {
    if (U8(p, 0x43e) != 1) {
        return;
    }
    if (!isIdleState(p) && S32(p, 0x1240) != 0x12) {
        return;
    }
    if (isBusyState(p)) {
        return;
    }
    if (S32(p, 0xd60) < 0) {
        U8(p, 0x43e) = 0;
        return;
    }
    f32* v = fn_80238430(S32(p, 0xd60));
    JGeometry::TVec2<f32> pos;
    pos.x = v[0];
    pos.y = v[1];
    if (fn_8026E5F8(p, &pos)) {
        U8(p, 0x43e) = 0;
    }
}
u8 fn_80243194(char* p, s32 i) { return fn_8022E438(S32(p, 0x4), i); }
BOOL fn_802431B8(char* p) {
    for (int i = 0; i < 4; i++) {
        if (fn_8023697C(i) >= 0 && ((u8(*)(s32, s32))fn_8022E438)(fn_8023697C(i), S32(p, 0x4))) {
            return 1;
        }
    }
    return 0;
}
s32 fn_8024322C(char* p) { return S32(p, 0xd08); }
u32 fn_80309A78(void*, s32, u32);
u32 fn_80309A54(void*, s32, u32);
u8 fn_8022B244(void);
u32 fn_80309D24(void*, s32, u32);
u32 fn_80309D6C(void*, s32, u32);
f32 fn_80309D90(void*, s32);
f32 fn_80309F20(void*, s32);
f32 fn_80309FCC(void*, s32);
inline bool padActive(char* p) {
    bool ok;
    if (U8(p, 0xc80) == 0) {
        ok = false;
    } else if (U8(p, 0xcee) != 0) {
        ok = false;
    } else if (U8(p, 0x1215) != 0) {
        ok = false;
    } else if (U8(p, 0xca0) == 0) {
        ok = false;
    } else if (U8(p, 0xce9) == 0) {
        ok = false;
    } else {
        ok = true;
    }
    if (!ok) {
        return false;
    }
    if ((getMode2(p) == 4 && linkIdx(p) != linkRank2(p)) || U8(p, 0x11ea) == 0) {
        return false;
    }
    return true;
}
#define PADF(fn, mask) fn(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec)), mask)
BOOL fn_80244FFC(char* p) {
    if (!padActive(p)) {
        return 0;
    }
    if (PADF(fn_80309D24, 0x100)) {
        return 1;
    }
    return PADF(fn_80309D24, 0x20) != 0;
}
BOOL fn_80245238(char* p) {
    if (!padActive(p)) {
        return 0;
    }
    if (PADF(fn_80309D6C, 0x100)) {
        return 1;
    }
    if (PADF(fn_80309D6C, 0x20)) {
        return 1;
    }
    s32 room = S32(p, 0x3b4);
    if (U8(fn_802D6A9C(), room + 0x131df) != 0 && PADF(fn_80309D6C, 0x200)) {
        return 1;
    }
    return 0;
}
#define PAD_GATED(addr, fn, mask) \
    BOOL fn_##addr(char* p) { \
        if (!padActive(p)) { \
            return 0; \
        } \
        if (U8(p, 0x456) != 0) { \
            return 0; \
        } \
        if (S32(p, 0x11f0) > 0) { \
            return 0; \
        } \
        return PADF(fn, mask) != 0; \
    }
#define PAD_GATED2(addr, fn, mask) \
    BOOL fn_##addr(char* p) { \
        if (!padActive(p)) { \
            return 0; \
        } \
        if (fn_8022B244()) { \
            return 0; \
        } \
        if (U8(p, 0x456) != 0) { \
            return 0; \
        } \
        if (S32(p, 0x11f0) > 0) { \
            return 0; \
        } \
        return PADF(fn, mask) != 0; \
    }
BOOL fn_802454C0(char* p) {
    bool ok;
    bool ok2;
    if (U8(p, 0xc80) == 0) {
        ok = false;
    } else if (U8(p, 0xcee) != 0) {
        ok = false;
    } else if (U8(p, 0x1215) != 0) {
        ok = false;
    } else if (U8(p, 0xca0) == 0) {
        ok = false;
    } else if (U8(p, 0xce9) == 0) {
        ok = false;
    } else {
        ok = true;
    }
    if (!ok) {
        ok2 = false;
    } else {
        s32 mode;
        s32 e;
        s32 i;
        s32 c;
        s32 d;
        c = 0;
        for (i = c; i < 4; i++) {
            if (i == S32(p, 0x4)) {
                c++;
            } else if (fn_8022F514(i)) {
                d = S32(p, 0xd60);
                if (d >= 0) {
                    if (d == fn_8022F3DC(i)) {
                        c++;
                    }
                } else {
                    e = S32(p, 0x4);
                    if (e == fn_8022F3DC(i)) {
                        c++;
                    }
                }
            } else if (i == S32(p, 0xd60)) {
                c++;
            }
        }
        if (c <= 1) {
            mode = 5;
        } else if (S32(p, 0xd60) >= 0) {
            mode = fn_8022CAF8(S32(p, 0xd60));
        } else {
            mode = S32(p, 0x120c);
        }
        if ((mode == 4 && linkIdx(p) != linkRank2(p)) || U8(p, 0x11ea) == 0) {
            ok2 = false;
        } else {
            ok2 = true;
        }
    }
    if (!ok2) {
        return 0;
    }
    if (U8(p, 0x456) != 0) {
        return 0;
    }
    if (S32(p, 0x11f0) > 0) {
        return 0;
    }
    return PADF(fn_80309A54, 0x20) != 0;
}
PAD_GATED(802456FC, fn_80309D24, 0x20)
PAD_GATED(80245938, fn_80309D6C, 0x20)
inline s32 countSharingB(char* p) {
    s32 c;
    s32 i;
    s32 linked;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            if ((linked = S32(p, 0xd60)) >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                linked = S32(p, 0x4);
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
inline s32 getModeB(char* p) {
    if (countSharingB(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
inline bool padActive3(char* p) {
    bool ok;
    if (U8(p, 0xc80) == 0) {
        ok = false;
    } else if (U8(p, 0xcee) != 0) {
        ok = false;
    } else if (U8(p, 0x1215) != 0) {
        ok = false;
    } else if (U8(p, 0xca0) == 0) {
        ok = false;
    } else if (U8(p, 0xce9) == 0) {
        ok = false;
    } else {
        ok = true;
    }
    if (!ok) {
        return false;
    }
    if ((getModeB(p) == 4 && linkIdx(p) != linkRank2(p)) || U8(p, 0x11ea) == 0) {
        return false;
    }
    return true;
}
inline s32 countSharingC(char* p) {
    s32 c;
    s32 i;
    s32 linked;
    s32 me;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            linked = S32(p, 0xd60);
            if (linked >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                me = S32(p, 0x4);
                s32 other = fn_8022F3DC(i);
                if (me == other) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
inline s32 getModeC(char* p) {
    if (countSharingC(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
inline bool padActiveC(char* p) {
    bool ok;
    if (U8(p, 0xc80) == 0) {
        ok = false;
    } else if (U8(p, 0xcee) != 0) {
        ok = false;
    } else if (U8(p, 0x1215) != 0) {
        ok = false;
    } else if (U8(p, 0xca0) == 0) {
        ok = false;
    } else if (U8(p, 0xce9) == 0) {
        ok = false;
    } else {
        ok = true;
    }
    if (!ok) {
        return false;
    }
    if ((getModeC(p) == 4 && linkIdx(p) != linkRank2(p)) || U8(p, 0x11ea) == 0) {
        return false;
    }
    return true;
}
BOOL fn_80245B74(char* p) {
    if (!padActiveC(p)) {
        return 0;
    }
    if (U8(p, 0x456) != 0) {
        return 0;
    }
    if (S32(p, 0x11f0) > 0) {
        return 0;
    }
    return PADF(fn_80309A78, 0x100) != 0;
}
PAD_GATED(80245DB0, fn_80309D6C, 0x100)
PAD_GATED(80245FEC, fn_80309D24, 0x100)
PAD_GATED(80246228, fn_80309D6C, 0x100)
inline s32 countSharing4(char* p) {
    s32 c;
    s32 i;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            s32 linked = S32(p, 0xd60);
            if (linked >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                s32 me = S32(p, 0x4);
                if (me == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
inline s32 getMode4(char* p) {
    if (countSharing4(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
inline bool padActive4(char* p) {
    bool ok;
    if (U8(p, 0xc80) == 0) {
        ok = false;
    } else if (U8(p, 0xcee) != 0) {
        ok = false;
    } else if (U8(p, 0x1215) != 0) {
        ok = false;
    } else if (U8(p, 0xca0) == 0) {
        ok = false;
    } else if (U8(p, 0xce9) == 0) {
        ok = false;
    } else {
        ok = true;
    }
    if (!ok) {
        return false;
    }
    if ((getMode4(p) == 4 && linkIdx(p) != linkRank2(p)) || U8(p, 0x11ea) == 0) {
        return false;
    }
    return true;
}
inline s32 countSharing5(char* p, s32& me) {
    s32 c;
    s32 i;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            s32 linked = S32(p, 0xd60);
            if (linked >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                me = S32(p, 0x4);
                if (me == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
inline s32 getMode5(char* p, s32& me) {
    if (countSharing5(p, me) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
inline bool padActive5(char* p) {
    bool ok;
    s32 v;
    if (U8(p, 0xc80) == 0) {
        ok = false;
    } else if (U8(p, 0xcee) != 0) {
        ok = false;
    } else if (U8(p, 0x1215) != 0) {
        ok = false;
    } else if (U8(p, 0xca0) == 0) {
        ok = false;
    } else if (U8(p, 0xce9) == 0) {
        ok = false;
    } else {
        ok = true;
    }
    if (!ok) {
        return false;
    }
    if ((getMode5(p, v) == 4 && (v = linkIdx(p)) != linkRank2(p)) || U8(p, 0x11ea) == 0) {
        return false;
    }
    return true;
}
BOOL fn_80246464(char* p) {
    if (!padActive5(p)) {
        return 0;
    }
    if (fn_8022B244()) {
        return 0;
    }
    if (U8(p, 0x456) != 0) {
        return 0;
    }
    if (S32(p, 0x11f0) > 0) {
        return 0;
    }
    return PADF(fn_80309D24, 0x200) != 0;
}
BOOL fn_802466B4(char* p) {
    if (!padActive5(p)) {
        return 0;
    }
    if (fn_8022B244()) {
        return 0;
    }
    if (U8(p, 0x456) != 0) {
        return 0;
    }
    if (S32(p, 0x11f0) > 0) {
        return 0;
    }
    return PADF(fn_80309D6C, 0x200) != 0;
}
#define PAD_BTN(addr, fn) \
    u32 fn_##addr(char* p, u32 mask) { \
        return !padActive(p) ? 0 : fn(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec)), mask); \
    }
#define PAD_AXIS(addr, fn) \
    f32 fn_##addr(char* p) { \
        return !padActive(p) ? 0.0f : fn(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec))); \
    }
u32 fn_80246904(char* p, u32 mask) {
    return !padActive5(p) ? 0 : fn_80309A78(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec)), mask);
}
u32 fn_80246B10(char* p, u32 mask) {
    return !padActive5(p) ? 0 : fn_80309D24(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec)), mask);
}
u32 fn_80246D1C(char* p, u32 mask) {
    return !padActive5(p) ? 0 : fn_80309D6C(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec)), mask);
}
inline s32 countSharing6(char* p) {
    s32 c;
    s32 i;
    s32 me;
    s32 linked;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            if ((linked = S32(p, 0xd60)) >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                s32 me = S32(p, 0x4);
                if (me == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
inline s32 getMode6(char* p) {
    if (countSharing6(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
inline bool padActive6(char* p) {
    bool ok;
    if (U8(p, 0xc80) == 0) {
        ok = false;
    } else if (U8(p, 0xcee) != 0) {
        ok = false;
    } else if (U8(p, 0x1215) != 0) {
        ok = false;
    } else if (U8(p, 0xca0) == 0) {
        ok = false;
    } else if (U8(p, 0xce9) == 0) {
        ok = false;
    } else {
        ok = true;
    }
    if (!ok) {
        return false;
    }
    if ((getMode6(p) == 4 && linkIdx(p) != linkRank2(p)) || U8(p, 0x11ea) == 0) {
        return false;
    }
    return true;
}
f32 fn_80246F28(char* p) {
    return !padActive6(p) ? 0.0f : fn_80309D90(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec)));
}
PAD_AXIS(8024712C, fn_80309F20)
PAD_AXIS(80247330, fn_80309FCC)
s32 fn_80247534(char* p) { return fn_8030A308(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec))); }
s32 fn_80247564(char* p) { return fn_8030A3B0(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec))); }
s32 fn_80247594(char* p, s32 amount) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_80237488(linked);
    }
    if (U8(p, 0x1201) == 1) {
        return 1;
    }
    s32 pool = S32(p, 0xc08);
    if (pool >= amount) {
        S32(p, 0xc08) = pool - amount;
        U8(p, 0x1201) = 1;
        return 1;
    }
    if (pool > 0) {
        S32(p, 0xc08) = 0;
        U8(p, 0x1201) = 1;
        return 1;
    }
    U8(p, 0x1202) = 1;
    return 0;
}
FWD(80247B9C, 8023BEA8, 0xbc0)
FWD(80247BD4, 8023C36C, 0x48c)
void fn_80247F0C(char* p) {
    if (S32(p, 0xc9c) > 0) {
        S32(p, 0xc9c)--;
        return;
    }
    if (F32(p, 0xc8c) < 1.0f) {
        F32(p, 0xc8c) += lbl_80540038;
        if (F32(p, 0xc8c) >= 1.0f) {
            F32(p, 0xc8c) = 1.0f;
        }
    }
}
void fn_80247F58(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0 && fn_80236B50(linked)) {
        if (fn_80251BFC(p, 0x33)) {
            fn_80272160(p, 0, p + 0x8, 0x12);
        }
    } else if (fn_80239D38() && U8(p, 0xd34) == 0 && fn_80251BFC(p, 0x33)) {
        fn_80272160(p, 0, p + 0x8, 0x12);
    }
}
void fn_80248604(char* p) {
    if (U8(p, 0x1216) != 0) {
        return;
    }
    if (U8(p, 0x454) != 0) {
        fn_8024B2E0(p);
        return;
    }
    resetTrail(p);
}
BOOL fn_8024DA64(char* p, s32 anim, u8 flag) {
    if (S32(p, 0x1240) != 0) {
        return 0;
    }
    if (anim == 0xe8 && getMode2(p) == 4) {
        s32 v = linkIdx(p);
        if (v != linkRank2(p)) {
            S16(p, 0x450) = 0x1c5;
            goto done;
        }
    }
    if (anim >= 0) {
        S16(p, 0x450) = anim;
    }
done:
    U8(p, 0xca2) = flag;
    U8(p, 0x456) = 1;
    return 1;
}
s32 fn_802486A0(const char* p) {
    if (countSharing(p) <= 1) {
        return 5;
    }
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_8022CAF8(linked);
    }
    return S32(p, 0x120c);
}
s32 fn_80248778(const char* p) {
    s32 n;
    s32 linked = *(const s32*)(p + 0xd60);
    if (linked < 0) {
        return 0;
    }
    n = *(const s32*)(p + 0x4);
    s32 c = 0;
    for (int i = 0; i < n; i++) {
        if (linked == fn_8022F3DC(i)) {
            c++;
        }
    }
    return c + 1;
}
s32 fn_802487FC(const char* p) {
    if (getModeH(p) == 4) {
        return 1;
    }
    return countSharingH(p);
}
s32 fn_80248970(const char* p) {
    s32 c;
    s32 i;
    s32 linked;
    c = 0;
    for (i = 0; i < 4; i++) {
        if (i == S32(p, 0x4)) {
            c++;
        } else if (fn_8022F514(i)) {
            if ((linked = S32(p, 0xd60)) >= 0) {
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            } else {
                linked = S32(p, 0x4);
                if (linked == fn_8022F3DC(i)) {
                    c++;
                }
            }
        } else if (i == S32(p, 0xd60)) {
            c++;
        }
    }
    return c;
}
extern "C" u32 fn_802265FC(JGeometry::TVec2<f32>*, s32);
extern "C" u32 fn_80226998(JGeometry::TVec2<f32>*, s32);
inline bool inRoomBox(const f32* r, const JGeometry::TVec2<f32>& v) {
    bool in = 0;
    f32 x = v.x;
    f32 y;
    if (x >= r[0] && (y = v.y) >= r[1] && x < r[2] && y < r[3]) {
        in = 1;
    }
    return in;
}
bool fn_80248A24(char* p) {
    bool edge = 0;
    JGeometry::TVec2<f32> v;
    v.x = F32(p, 0x8);
    v.y = F32(p, 0xc);
    while (true) {
        v.y += 8.0f;
        if (!inRoomBox(roomOffset(S32(p, 0x3b4)), v)) {
            v.y = roomOffset(S32(p, 0x3b4))[3] - 24.0f;
            edge = 1;
            break;
        }
        fn_802265FC(&v, S32(p, 0x3b4));
        if ((u16)fn_80226998(&v, S32(p, 0x3b4)) == 0x231) {
            break;
        }
    }
    v.y += 24.0f;
    if (fn_8026E5F8(p, &v)) {
        U8(p, 0x43f) = 1;
        if (edge == 1) {
            U8(p, 0x440) = 1;
        }
        return 1;
    }
    return 0;
}
bool fn_80248B9C(char* p) {
    bool edge = 0;
    JGeometry::TVec2<f32> v;
    v.x = F32(p, 0x8);
    v.y = F32(p, 0xc);
    do {
        v.y += 8.0f;
        if (!inRoomBox(roomOffset(S32(p, 0x3b4)), v)) {
            return 0;
        }
    } while ((u16)fn_802265FC(&v, S32(p, 0x3b4)) != 0x3e);
    while (true) {
        v.y += 8.0f;
        if (!inRoomBox(roomOffset(S32(p, 0x3b4)), v)) {
            v.y = roomOffset(S32(p, 0x3b4))[3] - 24.0f;
            edge = 1;
            break;
        }
        if ((u16)fn_80226998(&v, S32(p, 0x3b4)) == 0x231) {
            break;
        }
    }
    v.y += 24.0f;
    if (fn_8026E5F8(p, &v)) {
        U8(p, 0x43f) = 1;
        if (edge == 1) {
            U8(p, 0x440) = 1;
        }
        F32(p, 0x444) = 0.0f;
        return 1;
    }
    return 0;
}
void fn_80248DAC(char* p) { U8(p, 0x121e) = 0; }
void fn_80248DB8(char* p) {
    U8(p, 0x1217) = 0;
    S32(p, 0x1218) = 3;
}
void fn_80248DCC(char* p) { S32(p, 0x1238) = 0xb4; }
void fn_80248DD8(char* p) {
    U8(p, 0x1214) = 1;
    if (S32(p, 0xd60) >= 0) {
        U8(p, 0x1215) = 1;
        f32* v = fn_8023E724(S32(p, 0xd60));
        F32(p, 0x8) = v[0];
        F32(p, 0xc) = v[1];
        F32(p, 0x10) = v[2];
        changeState(p, 3, 0);
    }
    S32(p, 0x1224) = 0;
    U8(p, 0x1217) = 0;
}
void fn_80248E94(char* p, u8 on) {
    if (on != 1 && U8(p, 0x121e) != 1 && S32(p, 0xbac) <= 0 && (on != 0 || !fn_8022AF5C())) {
        if (on == 1) {
            for (s32 i = 0; i < 4; i++) {
                if (((u8(*)(s32, s32))fn_8022E438)(S32(p, 0x4), i) && fn_8023EFEC(i)) {
                    return;
                }
            }
        }
        for (s32 i = 0; i < 4; i++) {
            if (((u8(*)(s32, s32))fn_8022E438)(S32(p, 0x4), i) && fn_8023EA28(i)) {
                return;
            }
        }
        U8(p, 0x1214) = on;
        if (U8(p, 0x1214) == 0) {
            U8(p, 0x1215) = 0;
        } else {
            changeState(p, 3, 0);
        }
        U8(p, 0x1217) = 0;
    }
}
void fn_80248FF0(char* p) {
    void* base = fn_801F856C();
    char* found = (char*)fn_801F666C(base, S32(p, 0x1230));
    if (found != 0) {
        U8(found, 0x11c) = 0;
        S32(p, 0x1230) = -1;
    } else if (U8(p, 0x121f) == 1) {
        U8(p, 0x121f) = 0;
        if (S32(p, 0x11f0) < 5) {
            S32(p, 0x11f0) = 5;
        }
    }
}
u8 GetBusyLocked(char* p) { return U8(p, 0x121f); }
void ClearBusyLocked(char* p) {
    if (U8(p, 0x121f) != 1) return;
    U8(p, 0x121f) = 0;
    if (S32(p, 0x11f0) >= 5) return;
    S32(p, 0x11f0) = 5;
}
void SetBusyLocked(char* p) { U8(p, 0x121f) = 1; }
bool fn_8024AFF8(char* p) {
    if (U8(p, 0xce8) == 1) {
        return 0;
    }
    if (S32(p, 0x1240) == 0x49) {
        U8(p, 0x124d) = 0;
        if (!fn_80251BFC(p, 0)) {
            return 0;
        }
        u8 bit = 1 << S32(p, 0x4);
    if (!(U8(lbl_8053AAF8, 0x82) & bit) && S32(p, 0xd60) < 0) {
            S32(p, 0x1244) = 1;
        } else if (U8(p, 0x434) != 0) {
            if (S32(p, 0x1240) == 2) {
                return 0;
            }
            S32(p, 0x1244) = 2;
        } else {
            S32(p, 0x1244) = 0;
        }
        U8(p, 0x124c) = 1;
        if (S32(p, 0xd60) < 0 && U8(p, 0xcfe) == 1 && S32(p, 0x1244) != 0) {
            U8(p, 0xcfe) = 0;
        }
        return 1;
    }
    return 0;
}
bool fn_8024B108(char* p, s32 a) {
    if (fn_80270C88(p)) {
        return 0;
    }
    if (changeState(p, 0x49, 1)) {
        S32(p, 0x1178) = a;
        char* act = getActor(S32(p, 0x1230));
        if (act != NULL) {
            U8(act, 0x11c) = 0;
            S32(p, 0x1230) = -1;
        } else if (U8(p, 0x121f) == 1) {
            U8(p, 0x121f) = 0;
            if (S32(p, 0x11f0) < 5) {
                S32(p, 0x11f0) = 5;
            }
        }
        fn_80248004(p, 4, 0);
        DELETE_JPA(p, 0x1388);
        return 1;
    }
    return 0;
}
BOOL fn_8024B24C(char* p) {
    char* sub = (char*)PTR(p, 0xbf0);
    BOOL r = 0;
    if (U8(sub, 0x98) != 0 || U8(sub, 0x99) != 0) {
        r = 1;
    }
    return r;
}
void fn_8024B274(char* p, s32 v) { SetField_0x98(PTR(p, 0xbf0), v); }
void fn_8024B298(char* p, s32 idx, void* out) { fn_8026942C(PTR(p, 0xbf0), idx, out); }
s32 fn_8024B2BC(char* p) { return fn_8026947C(PTR(p, 0xbf0)); }
void fn_8024B9E8(PlayerTrail* t) {
    if (U8(t, 0x1216) != 0) {
        return;
    }
    for (int i = 0x30; i > 0; i--) {
        t->pos[i] = t->pos[i - 1];
        t->onGround[i] = t->onGround[i - 1];
    }
    t->pos[0] = *(JGeometry::TVec3<f32>*)&t->x;
    t->onGround[0] = U8(PTR(t, 0xbf0), 0xb4);
}
void fn_8024BAEC(char* p) {
    if (U8(p, 0x1216) != 0) {
        return;
    }
    if (U8(p, 0x454) != 0) {
        fn_8024B2E0(p);
        return;
    }
    PlayerTrail* t = (PlayerTrail*)p;
    for (int i = 0; i < 0x31; i++) {
        t->pos[i].x = t->x;
        t->pos[i].y = t->y;
        t->pos[i].z = t->z;
        if (t->z > 0.0f) {
            t->onGround[i] = true;
        } else {
            t->onGround[i] = false;
        }
    }
}
void fn_8024BB88(char* p) { U8(p, 0xced) = 1; }
s32 fn_8024BB94(char* p) {
    if (U8(p, 0xce8) != 0) {
        return S32(p, 0xcf4);
    }
    return 0;
}
u8 fn_8023A51C(s32);
s32 fn_8023DE58(s32);
JGeometry::TVec3<f32>* fn_8023A478(s32);
inline s32 getRoom(char* p) { return S32(p, 0x3b4); }
void fn_8024BBB8(char* p) {
    if (fn_80270C88(p)) {
        return;
    }
    if (S32(p, 0x1240) == 0x3f || S32(p, 0x1240) == 0xc) {
        return;
    }
    if (U8(p, 0xb9a) == 0 && U8(p, 0xcf0) == 0 && S32(p, 0x1240) != 0x3c && S32(p, 0x1244) != 0x3c) {
        for (s32 i = 0; i < 4; i++) {
            if (!fn_8022E438(S32(p, 0x4), i) && fn_8023A51C(i) && getRoom(p) == fn_8023DE58(i)) {
                f32 range = 50.0f;
                if (fn_8022B244()) {
                    range = 80.0f;
                } else if (fn_8023725C(i) >= 2) {
                    range *= 2.0f;
                }
                JGeometry::TVec3<f32> e;
                JGeometry::TVec3<f32> d(*fn_8023A478(i));
                d -= V3(p, 0x8);
                e = d;
                if (JGeometry::TUtil<f32>::sqrt(e.x * e.x + e.y * e.y) < range) {
                    changeState(p, 0x3f, 1);
                    break;
                }
            }
        }
    }
    U8(p, 0xb9d) = 0;
}
u8 Player_GetField_0xce8(char* p) { return U8(p, 0xce8); }
BOOL fn_8024C35C(char* p) { return S32(p, 0x3b4) >= 8 ? 1 : 0; }
JGeometry::TVec3<f32>* fn_8024C378(char* p) {
    if (S32(p, 0x3b4) == 8) {
        char* r = fn_802D6A9C();
        f32 x = F32(r, 0xcc);
        f32 y = F32(r, 0xd0);
        f32* o = roomOffset(S32(p, 0x3b4));
        JGeometry::TVec3<f32>* v = (JGeometry::TVec3<f32>*)(p + 0x1268);
        v->x = F32(p, 0x8);
        v->y = F32(p, 0xc);
        v->z = F32(p, 0x10);
        v->x += x - o[0];
        v->y += y - o[1];
        return v;
    }
    return (JGeometry::TVec3<f32>*)(p + 0x8);
}
BOOL fn_8024C448(char* p) { return ((u32)S32(p, 0xd40) >> 31) ^ 1; }
u8 fn_8024C458(char* p) { return U8(p, 0xd4c); }
s32 fn_8024C460(char* p, s32 v) {
    if (U8(p, 0xd4c) == 0) return 1;
    if (S32(p, 0xd44) != v) return 1;
    S32(p, 0xd44) = -1;
    S32(p, 0xd3c) = -1;
    U8(p, 0xd4c) = 0;
    U8(p, 0xd4d) = 0;
    if (S32(p, 0xd74) < 3) {
        S32(p, 0xd74) = 3;
    }
    S32(p, 0xd50) = 0x14;
    return 1;
}
BOOL fn_8024C4C4(char* p, s32 id) {
    if (U8(p, 0xd4c) == 1) {
        return 0;
    }
    U8(p, 0xd4c) = 1;
    S32(p, 0xd44) = id;
    U8(p, 0xd4d) = 1;
    char* a = getActor(id);
    if (a == NULL || F32(a, 0xc) < F32(p, 0x8)) {
        Actor_CreateByID(fn_801F856C(), 'PEFF', PTR(p, 0x3b4), p + 0x8, (S32(p, 0x4) & 3) | 0x18, -1, -1);
    } else {
        Actor_CreateByID(fn_801F856C(), 'PEFF', PTR(p, 0x3b4), p + 0x8, (S32(p, 0x4) & 3) | 0x1c, -1, -1);
    }
    return 1;
}
BOOL fn_8024C828(char* p, s32 a) {
    if ((u8)isLinkOwner(p)) {
        return 0;
    }
    if (U8(p, 0x1216) == 1) {
        return 0;
    }
    if (U8(p, 0xd4c) == 1) {
        return 0;
    }
    return S32(p, 0xd44) == a ? 1 : 0;
}
BOOL fn_8024CA0C(char* p, s32 v) { return S32(p, 0xd44) == v ? 1 : 0; }
void fn_8024CA20(char* p) {
    if (S32(p, 0xd50) > 0) {
        S32(p, 0xd50)--;
    }
    if (U8(p, 0xd4d) == 0) {
        if (S32(p, 0xd3c) < 0) {
            S32(p, 0xd44) = -1;
            U8(p, 0xd4c) = 0;
        } else if (S32(p, 0xd44) < 0) {
            if (U8(p, 0xd4e) == 0 || fn_8022C1D8(S32(p, 0x4))) {
                S32(p, 0xd44) = S32(p, 0xd3c);
            }
        }
    }
    S32(p, 0xd40) = S32(p, 0xd3c);
    S32(p, 0xd3c) = -1;
}
BOOL fn_8024D058(char* p, u8 on) {
    if (on) {
        U8(p, 0x454) = 0;
        if (U8(p, 0x1216) == 0) {
            if (U8(p, 0x454) != 0) {
                fn_8024B2E0(p);
            } else {
                resetTrail(p);
            }
        }
    } else {
        fn_8024B2E0(p);
        U8(p, 0x454) = 0;
    }
    S32(p, 0xd74) = 10;
    S32(p, 0x11f0) = 10;
    fn_8024D134(p);
    return 1;
}
s32 fn_8024D98C(char* p) {
    U8(p, 0x455) = 1;
    return 1;
}
BOOL fn_8024D99C(char* p, const JGeometry::TVec3<f32>& v, u8 f) {
    *(JGeometry::TVec3<f32>*)(p + 0x32c) = v;
    U16(p, 0x452)++;
    if (U16(p, 0x452) >= 0x18) {
        U16(p, 0x452) = 0;
    }
    if (S32(p, 0x3dc) == 0) {
        U16(p, 0x450) = 0;
    } else if (S32(p, 0x3dc) == 1) {
        U16(p, 0x450) = 8;
    } else if (S32(p, 0x3dc) == 2) {
        U16(p, 0x450) = 0x10;
    } else {
        U16(p, 0x450) = 0x18;
    }
    U16(p, 0x450) += (u8)(U16(p, 0x452) / 3);
    U8(p, 0xca2) = f;
    fn_8024B2E0(p);
    return 1;
}
BOOL fn_8024DC00(char* p, const JGeometry::TVec3<f32>& v, s32 frame, u8 a, u8 b, u8 c, u8 check) {
    *(JGeometry::TVec3<f32>*)(p + 0x32c) = v;
    if (frame >= 0) {
        U16(p, 0x450) = frame;
    }
    U8(p, 0xca2) = a;
    U8(p, 0xca3) = b;
    U8(p, 0xca4) = c;
    if (check == 1) {
        JGeometry::TVec3<f32> d;
        JGeometry::TVec3<f32> t(*(JGeometry::TVec3<f32>*)(p + 0x8));
        t -= v;
        d = t;
        if (PSVECMag((Vec*)&d) >= 0.1f) {
            fn_8024B2E0(p);
        }
    }
    if (frame != 0xc3) {
        U8(p, 0xcfe) = 0;
    }
    return 1;
}
char* fn_8024E018(char* p) { return p + 0x2b8; }
void fn_8024E020(char* p, const f32* v) {
    F32(p, 0x2b8) = v[0];
    F32(p, 0x2bc) = v[1];
    F32(p, 0x2c0) = v[2];
}
s32 fn_8024E03C(char* p) {
    if (S32(p, 0x48c) > 0) {
        S32(p, 0x48c) = 1;
        return 1;
    }
    return 0;
}
BOOL fn_8024E060(char* p) {
    if (U8(p, 0x454) != 0) {
        return 0;
    }
    if (U8(p, 0xce8) == 1) {
        return 0;
    }
    return U8(p, 0x1216) != 1;
}
void fn_8024E344(char* p) {
    if (S32(p, 0x3b4) < 8) {
        fn_8024E694(p, (s32)(20.0f * gameRnd()) + 0x32, 0);
    } else {
        fn_8024E694(p, 0x32, 0);
    }
}
void fn_8024E3D8(char* p) {
    if (S32(p, 0x3b4) < 8) {
        fn_8024E694(p, (s32)(10.0f * gameRnd()) + 0x14, 0);
    } else {
        fn_8024E694(p, 0x14, 0);
    }
}
void fn_8024E46C(char* p) {
    if (S32(p, 0x3b4) < 8) {
        fn_8024E694(p, (s32)(5.0f * gameRnd()) + 5, 0);
    } else {
        fn_8024E694(p, 5, 0);
    }
}
void fn_8024E500(char* p) {
    if ((U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 0x4))) && getItem(p) != 0) {
        s32 idx = S32(p, 0x4);
        s32 item = getItem(p);
        s32 lvl = getItemLevel(p);
        Actor_CreateByID(fn_801F856C(), 'LSTI', PTR(p, 0x3b4), p + 0x8, item | ((lvl << 22) | (idx << 17)), -1, -1);
        setItem(p, 0, 1);
    }
}
void fn_8024ECCC(char* p, s32 n) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        fn_8023619C(linked);
        return;
    }
    if (S32(p, 0xc04) > 9999) {
        for (;;) {}
    }
    S32(p, 0xc04) += n;
    if (S32(p, 0xc04) > 9999) {
        S32(p, 0xc04) = 9999;
    } else if (S32(p, 0xc04) < -5000) {
        S32(p, 0xc04) = -5000;
    }
    if (n == 1) {
        fn_802702C4(p);
    }
}
void fn_8024ED4C(char* p, s32 n) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        fn_802362C4(linked);
        return;
    }
    s32 old = S32(p, 0xc04);
    if (old > 9999) {
        for (;;) {}
    }
    S32(p, 0xc04) = old + 1;
    if (S32(p, 0xc04) == old) {
        for (;;) {}
    }
    S32(p, 0xc04) = old;
    if (n >= 0) {
        S32(p, 0xc04) += n;
        if (S32(p, 0xc04) > 9999) {
            S32(p, 0xc04) = 9999;
        }
    } else {
        s32 cur = S32(p, 0xc04);
        if (cur < 0) {
            return;
        }
        if (cur + n >= 0) {
            S32(p, 0xc04) = cur + n;
        } else {
            S32(p, 0xc04) = 0;
        }
    }
    if (n == 1) {
        fn_802702C4(p);
    }
}
u8 fn_8024EE0C(char* p) { return U8(p, 0x3d9); }
u8 fn_8024EE14(char* p) { return U8(p, 0x3d8); }
u16 fn_8024EE1C(char* p) { return U16(p, 0x3c4); }
extern u8 lbl_8053ACD8[4];
s32 fn_8023E10C(s32);
s32 fn_8023DE58(s32);
JGeometry::TVec3<f32>* fn_8023E214(s32);
void fn_80402FBC(s32, JGeometry::TVec3<f32>);
void fn_8024EE24(char* p) {
    if (S32(p, 0xd60) < 0) {
        if (S32(p, 0x11dc) > 0) {
            S32(p, 0x11dc)--;
            if (S32(p, 0x11dc) < 0x60) {
                if (U8(p, 0x11e0) == 0 && (S32(p, 0x11dc) & 0x10) == 0) {
                    lbl_8053ACD8[S32(p, 0x4)] = 1;
                } else {
                    lbl_8053ACD8[S32(p, 0x4)] = 0;
                }
                if ((S32(p, 0x11dc) & 0x1f) == 0xf) {
                    if ((u8)fn_8030A308(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec))) && fn_8030381C(S32(p, 0x4))) {
                        fn_803037D4(S32(p, 0x4), 5);
                    } else {
                        if (S32(p, 0x3b4) >= 8) {
                            fn_8030381C(S32(p, 0x4));
                        }
                        fn_80458880(lbl_8053AF80, 9, (s8)S32(p, 0x4));
                    }
                }
            }
            if (fn_8023E10C(fn_8022EA0C(S32(p, 0x4))) < 8) {
                s32 idx = S32(p, 0x4);
                fn_80402FBC(idx, *fn_8023E214(fn_8022EA0C(idx)));
            }
        } else if (fn_8023DE58(fn_8022EA0C(S32(p, 0x4))) < 8) {
            lbl_8053ACD8[S32(p, 0x4)] = 1;
        } else {
            lbl_8053ACD8[S32(p, 0x4)] = 0;
        }
    }
}
s32 fn_8024EFA0(char* p, u8 v) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return fn_80230E1C(linked, v);
    }
    if (S32(p, 0x11dc) == 0) {
        S32(p, 0x11dc) = 0x70;
        U8(p, 0x11e0) = v;
        return 1;
    }
    return 0;
}
void fn_8024EFF8(char* p, u32 se) {
    if ((u8)fn_8030A308(lbl_8053AD30, fn_8030AAF4(S32(p, 0x11ec))) && fn_8030381C(S32(p, 0x4))) {
        if (se == 4) {
            fn_803037D4(S32(p, 0x4), 4);
            return;
        }
        if (se == 9) {
            fn_803037D4(S32(p, 0x4), 5);
            return;
        }
        if (se == 5) {
            fn_803037D4(S32(p, 0x4), 6);
            return;
        }
    }
    if (S32(p, 0x3b4) >= 8 && fn_8030381C(S32(p, 0x4)) && se == 3) {
        fn_803037D4(S32(p, 0x4), 0xf);
        return;
    }
    fn_80458880(lbl_8053AF80, se, (s8)S32(p, 0x4));
}
void fn_8024F54C(char* p, s32 id) {
    if (S32(p, 0x3b4) >= 8 && fn_8030381C(playerIdx(p)) && id == 0x1000002) {
        fn_803037D4(playerIdx(p), 0x10);
    } else {
        fn_80458F04(lbl_8053AF80, id);
    }
}
u8 fn_8024F5E4(char* p) {
    if (!fn_8025F448(p) && S32(p, 0x1240) == 0x19) {
        return 1;
    }
    return 0;
}
u8 fn_8024F630(char* p) { return U8(PTR(p, 0xbf0), 0xb4); }
u8 fn_8024FE78(char* p) {
    if (fn_8024F63C(p)) {
        return fn_80243C64(p);
    }
    return 0;
}
u8 fn_8024FEBC(char* p) {
    if (S32(p, 0x1240) == 0x1a && fn_80243C64(p)) {
        return 1;
    }
    return 0;
}
u8 fn_8024FEFC(char* p) {
    u8 r = 0;
    if (fn_8024FEBC(p) || fn_8024FE78(p)) {
        r = 1;
    }
    return r;
}
s32 fn_8024FF54(char* p) { s32 v = S32(p, 0xdac);
    if (v < 0) return -1;
    return v; }
s32 fn_8024FF6C(char* p) { return getDA4(p); }
s32 fn_8024FF84(char* p) { s32 v = S32(p, 0xd94);
    if (v < 0) return -1;
    return v; }
void fn_8024FF9C(char* p, s32 v) {
    if (S32(p, 0xd94) == v) {
        S32(p, 0xd94) = -1;
    }
}
void fn_8024FFB4(char* p, s32 v) {
    if (S32(p, 0xd94) < 0) {
        S32(p, 0xd94) = v;
    }
}
u8 fn_8024FFC8(char* p, s32 v) {
    if (fn_8024FEFC(p) && v == getDA4(p)) {
        return 1;
    }
    return 0;
}
u8 fn_80250030(char* p, s32 v) {
    if (fn_80250D30(p) && fn_802729F0(p, v)) {
        return 1;
    }
    return 0;
}
BOOL fn_802517E4(char* p) { return S32(p, 0x1240) == 0x1a; }
BOOL fn_802517F8(char* p, u8 all) {
    char* s = (char*)PTR(p, 0xbf0);
    if (U8(s, 0x49) == 1) {
        return 1;
    }
    if (U8(s, 0x48) == 1) {
        return 1;
    }
    if (all == 1 && U8(s, 0x4c) == 1) {
        return 1;
    }
    if (all == 1 && U8(s, 0x4d) == 1) {
        return 1;
    }
    if (all == 1 && U8(s, 0x4e) == 1) {
        return 1;
    }
    if (all == 1 && U8(s, 0x4f) == 1) {
        return 1;
    }
    return 0;
}
BOOL fn_802518AC(char* p, u8 v) {
    char* s = (char*)PTR(p, 0xbf0);
    if (U8(s, 0x4a) == 1) return 1;
    if (v == 1 && U8(s, 0x4c) == 1) return 1;
    if (v == 1 && U8(s, 0x4d) == 1) return 1;
    return 0;
}
BOOL fn_8025190C(char* p, u8 v) {
    char* s = (char*)PTR(p, 0xbf0);
    if (U8(s, 0x4b) == 1) return 1;
    if (v == 1 && U8(s, 0x4e) == 1) return 1;
    if (v == 1 && U8(s, 0x4f) == 1) return 1;
    return 0;
}
u8 fn_8025196C(char* p, s32 i) { return btn(p, i); }
bool fn_8025197C(char* p, u8 all) {
    char* s = (char*)PTR(p, 0xbf0);
    for (s32 i = 0; i < 8; i++) {
        if (!all && i >= 4) {
            return 0;
        }
        if (U8(s, 0xb4) == 1 && (i == 2 || i == 4 || i == 5)) {
            continue;
        }
        if (U8(s, 0x48 + i) == 1) {
            return 1;
        }
    }
    return 0;
}
bool fn_80251AEC(char* p, s32 st) {
    if (!fn_80251BFC(p, st)) {
        return 0;
    }
    if (!(U8(lbl_8053AAF8, 0x82) & (u8)(1 << S32(p, 0x4))) && S32(p, 0xd60) < 0 && st == 0) {
        S32(p, 0x1244) = 1;
    } else if (U8(p, 0x434) != 0 && st == 0) {
        if (S32(p, 0x1240) == 2) {
            return 0;
        }
        S32(p, 0x1244) = 2;
    } else {
        S32(p, 0x1244) = st;
    }
    U8(p, 0x124c) = 1;
    if (st != 0 && st != 2 && st != 3) {
        U8(p, 0x124d) = 1;
    }
    if (S32(p, 0xd60) < 0 && U8(p, 0xcfe) == 1 && S32(p, 0x1244) != 0) {
        U8(p, 0xcfe) = 0;
    }
    return 1;
}
bool fn_80251BFC(char* p, s32 st) {
    if (U8(p, 0x124d) == 1) {
        return 0;
    }
    if (U8(p, 0x124c) == 1 && S32(p, 0x1244) != 0 && !(S32(p, 0x1244) == 2 || S32(p, 0x1244) == 3)) {
        return 0;
    }
    if (U8(p, 0x124c) == 1 && S32(p, 0x1244) == 2 && (st == 0 || st == 3)) {
        return 0;
    }
    s32 next = S32(p, 0x1244);
    if (next == 1 && st != 0) {
        return 0;
    }
    if (U8(p, 0xcee) == 1) {
        return 0;
    }
    if (S32(p, 0xd60) >= 0 && U8(p, 0xce8) == 0 && U8(p, 0x1214) != 0 && st != 3) {
        return 0;
    }
    if (U8(p, 0x1215) != 0 && st != 3) {
        return 0;
    }
    if (S32(p, 0x1240) == st) {
        return 0;
    }
    if (next == st) {
        return 0;
    }
    if (U8(lbl_8053AAF8, 0x7e) != 0 && fn_80236890()) {
        return 0;
    }
    return 1;
}
void fn_80252BAC(char* p, const JGeometry::TVec3<f32>& v) { V3(p, 0x2e8) += v; }
void fn_80252BD0(PlayerTrail* t, const JGeometry::TVec3<f32>& v) {
    V3(t, 0x2dc) += v;
    U8(t, 0x435) = 1;
    for (int i = 0; i < 0x31; i++) {
        t->pos[i] += V3(t, 0x2dc);
    }
}
// Same body as fn_8024B9E8; inlined twice here.
inline void shiftTrail(PlayerTrail* t) {
    if (U8(t, 0x1216) != 0) {
        return;
    }
    for (int i = 0x30; i > 0; i--) {
        t->pos[i] = t->pos[i - 1];
        t->onGround[i] = t->onGround[i - 1];
    }
    t->pos[0] = *(JGeometry::TVec3<f32>*)&t->x;
    t->onGround[0] = U8(PTR(t, 0xbf0), 0xb4);
}
void fn_80252CF0(PlayerTrail* t, const JGeometry::TVec3<f32>& v) {
    V3(t, 0x2dc) += v;
    shiftTrail(t);
    shiftTrail(t);
}
void fn_80252F14(char* p, const JGeometry::TVec3<f32>& v) {
    V3(p, 0x2d0) += v;
    U8(p, 0x434) = 1;
}
void Fairy_SetField_0xd28(char* p, u32 v) { S32(p, 0xd28) = v; }
void* Fairy_GetField_0x11b4Ptr(char* p) { return p + 0x11b4; }
void Fairy_SetSubField_0x29c(char* p, u32 v) { S32(PTR(p, 0xbec), 0x29c) = v; }
void Fairy_SetSubField_0x298(char* p, u32 v) { S32(PTR(p, 0xbec), 0x298) = v; }
u32 Fairy_GetSubField_0x294(char* p) { return S32(PTR(p, 0xbec), 0x294); }
u32 Fairy_GetSubField_0x290(char* p) { return S32(PTR(p, 0xbec), 0x290); }
void fn_80252F80(char* p, const JGeometry::TVec3<f32>& pos, s32 a, s32 b, u8 c) {
    V3(p, 0x2c4) = pos;
    S32(p, 0x3e0) = a;
    S32(p, 0xd00) = b;
    if (b == 1) {
        U8(p, 0xcfe) = 1;
    } else {
        U8(p, 0xcfe) = 0;
    }
    U8(p, 0xd04) = c;
}
void EmptyHook_80252FBC(void) {}
struct PlayerKills { u8 pad[0xc1c]; s32 m[13]; };
inline void initItemState(char* p) {
    S32(p, 0xc10) = S32(fn_802D6A9C(), 0x48);
    S32(p, 0xc14) = S32(fn_802D6A9C(), 0x4c);
    S32(p, 0xc18) = 1;
    U8(p, 0xb7a) = 0;
    U8(p, 0xb7b) = 0;
    if (U8(lbl_8053AAF8, 0x7f) != 0) {
        if (S32(p, 0xd60) >= 0) {
            S32(p, 0xbf8) = 0x10;
        } else {
            S32(p, 0xbf8) = fn_8040305C(fn_804033D4(S32(p, 0x4))) * 4;
        }
    } else {
        S32(p, 0xbf8) = fn_8040305C(fn_804033D4(S32(p, 0x4))) * 4;
    }
    if (U8(lbl_8053AAF8, 0x7f) != 0) {
        F32(p, 0xb90) = 0.0f;
    } else {
        F32(p, 0xb90) = 85.333336f;
    }
    S32(p, 0xc08) = 0x180;
    S32(p, 0xc0c) = 0x180;
    S32(p, 0xbfc) = S32(p, 0xbf8) - 4;
}
void fn_802544B0(char* p) {
    initItemState(p);
    if (U8(lbl_8053AAF8, 0x7f) != 0) {
        if (S32(p, 0xd60) >= 0) {
            S32(p, 0xc04) = 0;
        } else {
            S32(p, 0xc04) = 0;
        }
    } else {
        S32(p, 0xc04) = 0;
    }
    for (int i = 0; i < 13; i++) {
        ((PlayerKills*)p)->m[i] = 0;
    }
    S32(p, 0xc50) = 0;
    S32(p, 0xc54) = 0;
    S32(p, 0xc58) = 0;
    S32(p, 0xc5c) = 0;
    S32(p, 0xc60) = 0;
    S32(p, 0xc64) = 0;
    S32(p, 0xc68) = 0;
    S32(p, 0xc6c) = 0;
    S32(p, 0xc70) = 0;
    S32(p, 0xc74) = 0;
    S32(p, 0xc78) = 0;
    S32(p, 0xc7c) = 0;
}
void fn_80254660(char* p) { initItemState(p); }
extern u8 lbl_804B20F8[];
void fn_8045787C(char*, s32);
char* fn_80255AC0(char* p, s16 del) {
    if (p) {
        PTR(p, 0x8) = lbl_804B20F8;
        PTR(p, 0x18) = lbl_804B20F8 + 0x24;
        fn_8045787C(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
} // extern "C"

#include "JSystem/JAudio/JASFakeMatchFSA.h"
