// TU 0x80329468-0x8032ab80 (actor GNLD).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gold_dtor_8032A8E0.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AB660[];

// GOLD cluster, part 5/6. Destructor - culls 3 handles (this+0x24c/0x250/
// 0x254) via the confirmed fn_801EE434, then the shared base dtor
// __dt__5ActorFv plus a conditional second-base dtor dtor_80084580.
extern "C" void* Gold_dtor(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AB660;
        fn_801EE434(*(void**)((char*)this_ + 0x24c));
        fn_801EE434(*(void**)((char*)this_ + 0x250));
        fn_801EE434(*(void**)((char*)this_ + 0x254));
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct GnldVBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual u8 v11();
};

extern "C" void detach__5ActorFv(void* this_);
extern const f32 lbl_80541D10;
extern const f32 lbl_80541D14;
extern const f32 lbl_80541D18;
extern const f32 lbl_80541D7C;

extern "C" void fn_8032A7B8(char* this_) {
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x238) = *(u32*)(this_ + 0x90) & 0xffff;
    *(s32*)(this_ + 0x234) = 0;
    *(f32*)(this_ + 0x244) = lbl_80541D10;
    *(f32*)(this_ + 0x248) = lbl_80541D18;
    *(s32*)(this_ + 0x240) = 0xb;
    *(s32*)(this_ + 0x23c) = (*(u32*)(this_ + 0x90) >> 20) & 0xf;
    switch ((*(u32*)(this_ + 0x90) >> 16) & 0xf) {
    default:
    case 0:
    case 5:
    case 6:
        *(s32*)(this_ + 0x230) = 0;
        break;
    case 1:
        *(s32*)(this_ + 0x230) = 1;
        break;
    case 2: {
        *(s32*)(this_ + 0x238) = 0;
        f32 b = lbl_80541D14;
        f32 a = lbl_80541D7C;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        *(s32*)(this_ + 0x230) = 3;
        break;
    }
    case 3:
        *(s32*)(this_ + 0x230) = 4;
        break;
    case 4:
    case 7:
        *(s32*)(this_ + 0x230) = 5;
        break;
    }
    s32 st = *(s32*)(this_ + 0x230);
    if ((st == 1 || st == 3 || st == 4) && ((GnldVBase*)this_)->v11()) {
        detach__5ActorFv(this_);
    }
}

struct GnldDrawKey {
    s32 a, b;
    GnldDrawKey() { a = -1; b = -1; }
};

struct GnldDrawParam {
    u8 map[16];      // 0x00
    GnldDrawKey key; // 0x10
    void* mtx;       // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    GnldDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        mtx = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};

class GnldResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

extern "C" void PSMTXIdentity(f32 m[3][4]);
extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, GnldDrawParam*);
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const char lbl_80471930[];

extern "C" void fn_80329468(char* this_) {
    if (*(s32*)(this_ + 0x230) == 3) {
        GnldDrawParam param; f32 m[3][4]; f32 z; f32 sc; f32 c; f32 z0; f32 y; f32 x;
        PSMTXIdentity(m);
        sc = *(f32*)(this_ + 0x248);
        z = lbl_80541D10;
        m[0][0] = sc;
        m[0][1] = z;
        m[0][2] = z;
        m[1][0] = z;
        m[1][1] = sc;
        m[1][2] = z;
        m[2][0] = z;
        m[2][1] = z;
        m[2][2] = sc;
        param.mtx = m;
        z0 = *(f32*)(this_ + 0x14);
        c = lbl_80541D14;
        y = c + *(f32*)(this_ + 0x10);
        x = c + *(f32*)(this_ + 0xc);
        f32 pos[3];
        pos[2] = z0;
        pos[0] = x;
        pos[1] = y;
        if (*(s32*)(this_ + 4) < 8) {
            void* res = (*(GnldResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x534f4220, lbl_80471930);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, 0x2a, lbl_80541D18, lbl_80541D18, &param);
        }
    }
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
