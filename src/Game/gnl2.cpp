// TU 0x802e2990-0x802e40a8 (actor GNL2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gol2_SetField_0x2f4.cpp ----
// GOL2 (vtable lbl_804A9C20, ctor fn_80201898) cluster, part 1/5 (8B,
// no extab - leaf). Trivial single-byte setter (this->0x2f4).
extern "C" {

void Gol2_SetField_0x2f4(void* thisPtr, u8 val) { *(u8*)((char*)thisPtr + 0x2f4) = val; }

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
extern "C" {
void fn_801EE434(void* h);
void __dt__5ActorFv(void* this_, int flag);
void __dl__FPv(void* p);
void fn_80457E54(void* p, s32 a);
}
extern void* __vt__4GNL2[];
extern void* lbl_8053AF80;

extern "C" void* fn_802E3A48(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4GNL2;
        char* p = this_;
        for (s32 i = 0; i < 4; i++, p += 4) {
            if (*(void**)(p + 0x2c8) != 0) {
                fn_801EE434(*(void**)(p + 0x2c8));
            }
            if (*(void**)(p + 0x2d8) != 0) {
                fn_801EE434(*(void**)(p + 0x2d8));
            }
        }
        if (*(void**)(this_ + 0x2e8) != 0) {
            fn_801EE434(*(void**)(this_ + 0x2e8));
        }
        if (*(void**)(this_ + 0x2ec) != 0) {
            fn_801EE434(*(void**)(this_ + 0x2ec));
        }
        if (*(s32*)(this_ + 0x238) != 5) {
            fn_80457E54(lbl_8053AF80, 0);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}


#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
class Gnl2ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const char lbl_8046F090[];
extern const char lbl_8046F0A4[];
extern "C" void fn_801F06F0(void* actor, const char* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, DrawRec* prm);

extern "C" void fn_802E2998(u8* this_) {
    if (*(s32*)(this_ + 0x230) <= 3) {
        f32 x = *(f32*)(this_ + 0xc);
        f32 y = *(f32*)(this_ + 0x10);
        f32 z = *(f32*)(this_ + 0x14);
        for (s32 i = 0; i < 4; i++) {
            *(JGeometry::TVec3<f32>*)(this_ + 0xc) = *(JGeometry::TVec3<f32>*)(this_ + 0x258 + i * 0xc);
            if (*(s32*)(this_ + 0x288 + i * 4) == 1) {
                fn_801F06F0(this_, lbl_8046F090, 0x25a, 0, 7, 1.0f, 1.0f);
            } else {
                fn_801F06F0(this_, lbl_8046F090, 0x25b, 0, 7, 1.0f, 1.0f);
            }
        }
        *(f32*)(this_ + 0xc) = x;
        *(f32*)(this_ + 0x10) = y;
        *(f32*)(this_ + 0x14) = z;
    }
    if (*(s32*)(this_ + 0x238) == 5) {
        DrawRec rec;
        *(s8*)&rec.b1d = -2;
        void* tex = (*(Gnl2ResMgr**)(lbl_8053AAF8 + 0xa4))->vf18('TIMG', lbl_8046F0A4);
        JGeometry::TVec3<f32> pos(80.0f + *(f32*)(this_ + 0xc), 48.0f + *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
        if (*(s32*)(this_ + 4) < 8) {
            fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, tex, &rec);
        }
    }
}

struct Gnl2Layout {
    f32 x[6][4];
    f32 y[6][4];
    f32 dx[6][4];
    f32 dy[6][4];
    u16 eff[6][4];
};
extern const Gnl2Layout lbl_8046EA10;
extern "C" s32 fn_80138A30(void* game);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 id);
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, s32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);

extern "C" void fn_802E3B2C(u8* this_) {
    const Gnl2Layout* t = &lbl_8046EA10;
    *(u32*)(this_ + 0x238) = *(u32*)(this_ + 0x90) & 0x1f;
    *(u32*)(this_ + 0x240) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    *(u32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> 7) & 1;
    *(s32*)(this_ + 0x23c) = fn_80138A30(lbl_8053AAF8);
    for (s32 k = 0; k < 4; k++) {
        *(void**)(this_ + 0x2c8 + k * 4) = 0;
        *(void**)(this_ + 0x2d8 + k * 4) = 0;
    }
    *(void**)(this_ + 0x2e8) = 0;
    *(void**)(this_ + 0x2ec) = 0;
    *(u8*)(this_ + 0x2f4) = 0xff;
    if (!fn_802D800C(fn_802D6A9C(), *(s32*)(this_ + 0x240))) {
        const f32 (*xs)[4] = t->x;
        const f32 (*ys)[4] = t->y;
        for (s32 i = 0; i < 4; i++) {
            f32* p = (f32*)(this_ + 0x258 + i * 0xc);
            p[0] = *(f32*)(this_ + 0xc) + xs[*(s32*)(this_ + 0x238)][i];
            p[1] = *(f32*)(this_ + 0x10) + ys[*(s32*)(this_ + 0x238)][i];
            p[2] = 0.0f;
            *(s32*)(this_ + 0x298 + i * 4) = 0;
            *(s32*)(this_ + 0x2a8 + i * 4) = 0;
            *(s32*)(this_ + 0x288 + i * 4) = 1;
            *(void**)(this_ + 0x2c8 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), p, 0x10a, 0, 0, 0, 0, 1, 1.0f);
        }
        if (*(s32*)(this_ + 0x238) != 5) {
            const u16 (*effs)[4] = t->eff;
            for (s32 i = 0; i < 4; i++) {
                *(u16*)(this_ + 0x2b8 + i * 2) = effs[*(s32*)(this_ + 0x238)][i];
                u16 eff = effs[*(s32*)(this_ + 0x238)][i];
                if (eff != 0) {
                    f32* p = (f32*)(this_ + 0x258 + i * 0xc);
                    JGeometry::TVec3<f32> pos(p[0] + t->dx[*(s32*)(this_ + 0x238)][i],
                                              p[1] + t->dy[*(s32*)(this_ + 0x238)][i], p[2]);
                    *(void**)(this_ + 0x2d8 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), &pos, eff, 1, 1, 0, 0, 1, 1.0f);
                }
            }
        }
        *(s32*)(this_ + 0x230) = 0;
        *(s32*)(this_ + 0x234) = 0;
        *(JGeometry::TVec3<f32>*)(this_ + 0x24c) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    } else {
        *(JGeometry::TVec3<f32>*)(this_ + 0x24c) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        *(s32*)(this_ + 0x230) = 5;
    }
    if (*(s32*)(this_ + 0x238) == 5) {
        JGeometry::TVec3<f32> a(80.0f + *(f32*)(this_ + 0xc), 48.0f + *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
        *(void**)(this_ + 0x2e8) = fn_8013CC50(*(u32*)(this_ + 4), &a, 0xc6, 0, 0, 0, 0, 1, 1.0f);
        JGeometry::TVec3<f32> b(80.0f + *(f32*)(this_ + 0xc), 48.0f + *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
        *(void**)(this_ + 0x2ec) = fn_8013CC50(*(u32*)(this_ + 4), &b, 0xc7, 0, 0, 0, 0, 1, 1.0f);
    }
    *(s32*)(this_ + 0x248) = 0;
    if (*(s32*)(this_ + 0x238) != 5) {
        fn_80457E54(lbl_8053AF80, 1);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
