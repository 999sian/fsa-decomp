// TU 0x8023FBF0-0x80255F4C: player object (0x1250-byte Link actor) accessors and helpers.
// Small bodies originally from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

#define U8(p, o) (*(u8*)((char*)(p) + (o)))
#define U16(p, o) (*(u16*)((char*)(p) + (o)))
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

extern "C" {
extern char* lbl_8053AAF8;
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
void fn_8030B110(void*, s32, JGeometry::TVec3<f32>);
s32 fn_8022E438(s32);
s32 fn_8030AAF4(s32);
s32 fn_8030A308(void*, s32);
s32 fn_8030A3B0(void*, s32);
void SetField_0x98(void*, s32);
u8 fn_80243C64(char*);
void* SpatialRegistry_GetBase();
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
s32 fn_80240628(char* p) {
    s32 linked = S32(p, 0xd60);
    if (linked >= 0) {
        return linked;
    }
    return S32(p, 0x4);
}
u32 Player_GetLinkTargetIndex(char* p) { return S32(p, 0xd60); }
s32 fn_8024064C(char* p) { return fn_8022EA0C(S32(p, 0x4)); }
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
BOOL fn_802412E0(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 0xd || S32(p, 0x1240) == 0xe || S32(p, 0x1240) == 0x11 || S32(p, 0x1240) == 0x12 || S32(p, 0x1240) == 0x1a || S32(p, 0x1240) == 0x3c || S32(p, 0x1240) == 0x3b || S32(p, 0x1240) == 0x3a || S32(p, 0x1240) == 0x47) r = 1;
    return r;
}
BOOL fn_80241338(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 0x4 || S32(p, 0x1240) == 0x8 || S32(p, 0x1240) == 0x39 || S32(p, 0x1240) == 0x44 || S32(p, 0x1240) == 0x45 || S32(p, 0x1240) == 0x3d || S32(p, 0x1240) == 0x37) r = 1;
    return r;
}
BOOL fn_80241380(char* p) {
    BOOL r = 0;
    if (S32(p, 0x1240) == 0x0 || S32(p, 0x1240) == 0x2 || S32(p, 0x1240) == 0x3 || S32(p, 0x1240) == 0x4 || S32(p, 0x1240) == 0x8 || S32(p, 0x1240) == 0x4a || S32(p, 0x1240) == 0x4b) r = 1;
    return r;
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
void fn_80241E28(char* p, s32 a, const JGeometry::TVec3<f32>& v) {
    fn_8030B110(PTR(p, 0xbec), a, v);
}
char* fn_802422C4(char* p) { return (char*)PTR(p, 0xbf0) + 0x14; }
s32 fn_802426E0(char* p, s32 v) {
    if (S32(p, 0xd8c) != v) {
        return 0;
    }
    U8(p, 0xd90) = 1;
    return 1;
}
s32 fn_80243194(char* p) { return fn_8022E438(S32(p, 0x4)); }
s32 fn_8024322C(char* p) { return S32(p, 0xd08); }
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
void fn_80248DAC(char* p) { U8(p, 0x121e) = 0; }
void fn_80248DB8(char* p) {
    U8(p, 0x1217) = 0;
    S32(p, 0x1218) = 3;
}
void fn_80248DCC(char* p) { S32(p, 0x1238) = 0xb4; }
void fn_80248FF0(char* p) {
    void* base = SpatialRegistry_GetBase();
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
void fn_8024BB88(char* p) { U8(p, 0xced) = 1; }
s32 fn_8024BB94(char* p) {
    if (U8(p, 0xce8) != 0) {
        return S32(p, 0xcf4);
    }
    return 0;
}
u8 Player_GetField_0xce8(char* p) { return U8(p, 0xce8); }
BOOL fn_8024C35C(char* p) { return S32(p, 0x3b4) >= 8 ? 1 : 0; }
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
BOOL fn_8024CA0C(char* p, s32 v) { return S32(p, 0xd44) == v ? 1 : 0; }
s32 fn_8024D98C(char* p) {
    U8(p, 0x455) = 1;
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
u8 fn_8024EE0C(char* p) { return U8(p, 0x3d9); }
u8 fn_8024EE14(char* p) { return U8(p, 0x3d8); }
u16 fn_8024EE1C(char* p) { return U16(p, 0x3c4); }
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
u8 fn_8025196C(char* p, s32 i) { return (*(u8**)(p + 0xbf0))[i + 0x48]; }
void fn_80252BAC(char* p, const JGeometry::TVec3<f32>& v) { V3(p, 0x2e8) += v; }
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
} // extern "C"

#include "JSystem/JAudio/JASFakeMatchFSA.h"
