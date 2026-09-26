// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80183544-80184040 (GDMN). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry.h"

// from src/Game/fn_80183C54_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" {
void fn_80183544(char* this_);
void fn_8018359C(u8* this_);
void fn_80183C18(void* this_);
void* fn_80183C54(void* this_, s16 freeFlag);
void fn_80183CC0(void* thisPtr);
void fn_80183CF8(char* this_);
void v02__5ActorFv();
void v05__5ActorFv();
void v07__5ActorFv();
void v08__5ActorFv();
void v09__5ActorFv();
void v10__5ActorFUlUl();
void v11__5ActorFv();
void v12__5ActorFv();
void v13__5ActorFv();
void v14__5ActorFv();
void v16__5ActorFv();
void v17__5ActorFiPf();
void v18__5ActorFiPf();
}

// GDMN vtable (Actor slots 0..18; the class itself is not reconstructed).
void* lbl_804A1790[] = {
    0,
    0,
    (void*)fn_80183C54,
    (void*)fn_80183CF8,
    (void*)v02__5ActorFv,
    (void*)fn_8018359C,
    (void*)fn_80183C18,
    (void*)v05__5ActorFv,
    (void*)fn_80183544,
    (void*)v07__5ActorFv,
    (void*)v08__5ActorFv,
    (void*)v09__5ActorFv,
    (void*)v10__5ActorFUlUl,
    (void*)v11__5ActorFv,
    (void*)v12__5ActorFv,
    (void*)v13__5ActorFv,
    (void*)v14__5ActorFv,
    (void*)fn_80183CC0,
    (void*)v16__5ActorFv,
    (void*)v17__5ActorFiPf,
    (void*)v18__5ActorFiPf,
};


// from src/Game/fn_80183C18.cpp
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void v04__5ActorFv(void* this_);



extern "C" void* fn_802D6A9C(void);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" void fn_801F71A4(f32* v, f32 a, f32 b, f32 c);
extern "C" void fn_801EEC98(void* this_, void* room, u16* a, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801F714C(void* shortPtr, s32 target, s32 divisor, s32 maxStep);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" u8* fn_8013CC50(u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern u8* lbl_8053AAF8;

// JMASinShort/JMACosShort without the template member call: going through
// TSinCosTable's inline members makes MWCC defer the caller to the end of .text.
static inline f32 gdmnSin(s16 v) {
    return JMath::sincosTable_.mTable[static_cast<u16>(v) >> (16U - 11)].first;
}
static inline f32 gdmnCos(s16 v) {
    return JMath::sincosTable_.mTable[static_cast<u16>(v) >> (16U - 11)].second;
}

struct GdmnVirt {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual u8 v34();
};

struct GdmnEmitter {
    u8 _0[0xb8];
    u8 mR, mG, mB;
    void setColor(u8 r, u8 g, u8 b) {
        mR = r;
        mG = g;
        mB = b;
    }
};

#define GDMN_TINT(E) \
    if ((((u8*)fn_802D6A9C()) + 0x10000)[0x31f2] == 1) { \
        ((GdmnEmitter*)(E))->setColor(this_[0x238], this_[0x239], this_[0x23a]); \
    }

static inline void gdmnFollow(u8* this_) {
    u8* e = *(u8**)(this_ + 0x270);
    if (e != 0) {
        *(f32*)(e + 0xa4) = *(f32*)(this_ + 0xc);
        *(f32*)(e + 0xa8) = *(f32*)(this_ + 0x10);
        *(f32*)(e + 0xac) = *(f32*)(this_ + 0x14);
        GDMN_TINT(*(u8**)(this_ + 0x270));
    }
}

static inline u8* gdmnSpawn(u8* this_, s32 id) {
    return fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, id, 0, 1, 0, 0, 1, 1.0f);
}

static inline void gdmnStop(u8* this_) {
    *(f32*)(this_ + 0x3c) = *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x44) =
        *(f32*)(this_ + 0x264) = *(f32*)(this_ + 0x268) = *(f32*)(this_ + 0x26c) = 0.0f;
}

static inline s32 gdmnRand(s32 n) {
    u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    u32 bits = (*seed >> 9) | 0x3f800000;
    return (f32)n * (*(f32*)&bits - 1.0f);
}


// from src/Game/Gdmn_StartTrigger.cpp
// GDMN's vtable-0x44 override. Identical shape to RIVR's own 0x44 override.
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);


extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8018330C(u32* out);

// GDMN draw (vtable slot 6)
extern "C" void fn_80183544(char* this_) {
    s32 s = *(s32*)(this_ + 0x230);
    if (s == 0 || s == 1) {
        return;
    }
    fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x254) + 0x155, 1.0f, 1.0f, 0, -1);
}

extern "C" void fn_8018359C(u8* this_) {
    u16 ang = 0;
    f32 dist = 0.0f;
    s32 player = -1;
    if (fn_801F3D94(this_, 1)) {
        gdmnFollow(this_);
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (*(s32*)(this_ + 0x258) != 0 && fn_801F305C(this_)) {
        gdmnFollow(this_);
        fn_801F2618(this_, 0, 0);
        return;
    }
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x264), 0.3f, 1.0f);
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x268), 0.3f, 1.0f);
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    fn_80212AF0(fn_80212AC0(), this_ + 0xc);
    fn_801EEC98(this_, *(void**)(this_ + 0x198), &ang, 0, &dist, &player, 0, 0);
    if (*(s32*)(this_ + 0x258) != 0) {
        fn_801F2B7C(this_, -100, -1, 1);
    }
    fn_801F2618(this_, 0, 0);
    switch (*(u32*)(this_ + 0x230)) {
    case 0:
        if (*(s32*)(this_ + 0x25c) == 1) {
            if (((GdmnVirt*)this_)->v34()) {
                *(s32*)(this_ + 0x230) = 2;
            }
            break;
        }
        *(s32*)(this_ + 0x240) = gdmnRand(30) + 30;
        *(s32*)(this_ + 0x230) = 1;
    case 1:
        if (*(s32*)(this_ + 0x240) != 0) {
            break;
        }
        if (dist > 64.0f) {
            break;
        }
        *(s32*)(this_ + 0x230) = 2;
    case 2:
        fn_801F0E34(this_, 0x40097, 0);
        *(s32*)(this_ + 0xb8) = 1;
        if (*(u8**)(this_ + 0x270) == 0) {
            u8* e = gdmnSpawn(this_, 0x1da);
            GDMN_TINT(e);
            *(u8**)(this_ + 0x270) = gdmnSpawn(this_, 0x1db);
            GDMN_TINT(*(u8**)(this_ + 0x270));
        }
        gdmnStop(this_);
        *(s32*)(this_ + 0x23c) = 8;
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x254) = 2;
        *(s32*)(this_ + 0x230) = 3;
    case 3:
        if (*(s32*)(this_ + 0x23c) != 0) {
            break;
        }
        gdmnFollow(this_);
        *(s32*)(this_ + 0x230) = 4;
    case 4:
        *(u32*)(this_ + 0xb0) = 0x11101;
        *(s32*)(this_ + 0x23c) = 8;
        *(s32*)(this_ + 0x240) = 200;
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x254) = 0;
        *(s32*)(this_ + 0x258) = 1;
        *(s32*)(this_ + 0x230) = 5;
    case 5:
        gdmnFollow(this_);
        fn_801F714C(this_ + 0x260, ang, 1, 0x200);
        *(f32*)(this_ + 0x264) = 0.7f * gdmnSin(*(u16*)(this_ + 0x260));
        *(f32*)(this_ + 0x268) = 0.7f * gdmnCos(*(u16*)(this_ + 0x260));
        if (*(s32*)(this_ + 0x23c) == 0) {
            *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x254) + 1;
            *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x254) & 1;
            *(s32*)(this_ + 0x23c) = 8;
        }
        if (*(s32*)(this_ + 0x240) != 0) {
            break;
        }
        *(s32*)(this_ + 0x230) = 6;
    case 6:
        if (*(u8**)(this_ + 0x270) != 0) {
            u8* e = gdmnSpawn(this_, 0x1da);
            GDMN_TINT(e);
            u8* old = *(u8**)(this_ + 0x270);
            *(u32*)(old + 0xf4) |= 1;
            *(s32*)(old + 0x24) = 1;
            *(u8**)(this_ + 0x270) = 0;
        }
        *(u32*)(this_ + 0xb0) = 0x1000;
        gdmnStop(this_);
        *(s32*)(this_ + 0x258) = 0;
        *(s32*)(this_ + 0x23c) = 8;
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x254) = 2;
        *(s32*)(this_ + 0x230) = 7;
    case 7:
        if (*(s32*)(this_ + 0x23c) != 0) {
            break;
        }
        *(s32*)(this_ + 0x230) = 0;
        break;
    }
    if (*(s32*)(this_ + 0x23c) > 0) {
        *(s32*)(this_ + 0x23c) -= 1;
    }
    if (*(s32*)(this_ + 0x240) > 0) {
        *(s32*)(this_ + 0x240) -= 1;
    }
    if (*(s32*)(this_ + 0x244) > 0) {
        *(s32*)(this_ + 0x244) -= 1;
    }
}

// fn_80183C18(this) - sibling of fn_8018316C (see that file's banner
// and project_fsa_80212af0_callers_closed.md) - another class's
// vtable-slot-0x18 override doing the identical "repel from RUSA
// zones, then chain to the generic slot-0x18 default" pattern.
extern "C" void fn_80183C18(void* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, (char*)this_ + 0xc);
    v04__5ActorFv(this_);
}

extern "C" void* fn_80183C54(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1790;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x270));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80183CC0(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(s32*)(p + 0x258) != 0) return;
	if (*(s32*)(p + 0x230) == 5) return;
	*(u32*)(p + 0xb0) = 0x11101;
	*(u32*)(p + 0x254) = 0;
	*(u32*)(p + 0x230) = 4;
}

// GDMN init (vtable slot 1)
extern "C" void fn_80183CF8(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(u8*)(this_ + 0x238) = 0;
    *(u8*)(this_ + 0x239) = 0;
    *(u8*)(this_ + 0x23a) = 0;
    if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
        u8 c[4];
        fn_8018330C((u32*)c);
        *(u8*)(this_ + 0x234) = c[0];
        *(u8*)(this_ + 0x235) = c[1];
        *(u8*)(this_ + 0x236) = c[2];
        *(u8*)(this_ + 0x237) = c[3];
        *(u8*)(this_ + 0x238) = *(u32*)(this_ + 0x234) >> 24;
        *(u8*)(this_ + 0x239) = *(u32*)(this_ + 0x234) >> 16;
        *(u8*)(this_ + 0x23a) = *(u32*)(this_ + 0x234) >> 8;
    }
    *(u32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 8) & 1;
    *(u8*)(this_ + 0x195) = 1;
    *(s32*)(this_ + 0x254) = 2;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(s32*)(this_ + 0x258) = 0;
    *(s16*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
