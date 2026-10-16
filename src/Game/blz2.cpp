// TU 0x802e4c74-0x802e5c44 (actor BLZ2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"

// NONMATCHING (91%): retail computes x before y; this computes y first.
// fn_802E4C74 - BLZ2: true if any of the four probe points around pos lies
// on a blocking tile.
struct Blz2Vec {
    f32 x, y, z;
    Blz2Vec() {}
    Blz2Vec(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
};
extern const f32 lbl_8046F148[4];
extern const f32 lbl_8046F188[4];
extern "C" u32 fn_80226850(Blz2Vec* pos, u32 room);
extern "C" u8 fn_801EE3C0(u16 tile);
extern "C" u8 fn_802E4C74(char* p, Blz2Vec* pos) {
    u8 hit = 0;
    for (s32 i = 0; i < 4; i++) {
        f32 x = pos->x + lbl_8046F148[i];
        f32 y = pos->y + lbl_8046F188[i];
        Blz2Vec q(x, y, pos->z);
        if (fn_801EE3C0(fn_80226850(&q, *(u32*)(p + 0x4))) == 1) {
            hit = 1;
            break;
        }
    }
    return hit;
}

// ---- VtableForward_802E4D20.cpp ----
extern "C" void fn_801F35AC(void* this_);

// fn_802E4D20 - BLZ2: virtual-call wrapper (slot 21, byte offset 0x54)
// + fn_801F35AC. See [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this calls through a real `virtual` member rather than a
// manual cast.
struct ActorSlot21 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void slot21();
};

extern "C" void fn_802E4D20(void* this_) {
    ((ActorSlot21*)this_)->slot21();
    fn_801F35AC(this_);
}

// ---- Blz2_dtor_802E5724.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9D28[];

extern "C" void* fn_802E5724(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9D28;
        for (int i = 0; i < 0x10; i++) {
            void* h0 = *(void**)((char*)this_ + 0x230 + i * 4);
            if (h0) {
                fn_801EE434(h0);
            }
            void* h1 = *(void**)((char*)this_ + 0x270 + i * 4);
            if (h1) {
                fn_801EE434(h1);
            }
            void* h2 = *(void**)((char*)this_ + 0x2b0 + i * 4);
            if (h2) {
                fn_801EE434(h2);
            }
        }
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct Blz2Color {
    Blz2Color(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};
struct Blz2Globals {
    u8 pad0[0x2c];
    void* m2c;
};
extern Blz2Globals* lbl_8053AB10;
extern "C" void* fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80158B5C(void* mgr, s32 room, void* pos, Blz2Color color, f32 size);

extern "C" void fn_802E4E6C(u8* self) {
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(self + 0xc));
    if (*(s32*)(self + 0x2f0) >= 1) {
        for (s32 j = 0; j < *(s32*)(self + 0x2f4); j++) {
            for (s32 k = 0; k < *(s32*)(self + 0x2f8); k++) {
                fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x34c, 0, 0, 0, 0, 1);
                fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x34d, 0, 0, 0, 0, 1);
                fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x54d, 1, 0, 0, 0, 1);
                s32 tex = *(s32*)(self + 4);
                Blz2Color c(0, 0, 0, 0x80);
                fn_80158B5C(lbl_8053AB10->m2c, tex, &pos, c, 32.0f);
                pos.y += 16.0f;
            }
            pos.y = *(f32*)(self + 0x10);
            pos.x += 16.0f;
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
struct Blz2Child {
    u8 pad0[0x24];
    s32 m24;
    u8 pad28[0xf4 - 0x28];
    u32 mFlags;
};

struct Blz2Obj {
    u8 pad0[0x230];
    Blz2Child* mA[16];
    Blz2Child* mB[16];
    Blz2Child* mC[16];
};

extern "C" void fn_802E4D60(Blz2Obj* self) {
    for (s32 i = 0; i < 16; i++) {
        if (self->mA[i] != NULL) {
            Blz2Child* a = self->mA[i];
            a->mFlags |= 1;
            a->m24 = 1;
            self->mA[i] = NULL;
        }
        if (self->mB[i] != NULL) {
            Blz2Child* b = self->mB[i];
            b->mFlags |= 1;
            b->m24 = 1;
            self->mB[i] = NULL;
        }
        if (self->mC[i] != NULL) {
            Blz2Child* c = self->mC[i];
            c->mFlags |= 1;
            c->m24 = 1;
            self->mC[i] = NULL;
        }
    }
}


extern "C" void fn_802E57E0(u8* self) {
    Blz2Obj* obj = (Blz2Obj*)self;
    *(s32*)(self + 0x2f4) = ((*(u32*)(self + 0x90) >> 22) & 0x1f) + 1;
    *(s32*)(self + 0x2f8) = ((*(u32*)(self + 0x90) >> 17) & 0x1f) + 1;
    *(s32*)(self + 0x2fc) = *(u32*)(self + 0x90) & 0xf;
    *(s32*)(self + 0x300) = (*(u32*)(self + 0x90) >> 4) & 1;
    *(s32*)(self + 0x308) = (*(u32*)(self + 0x90) >> 12) & 0x1f;
    for (s32 i = 0; i < 16; i++) {
        obj->mA[i] = NULL;
        obj->mB[i] = NULL;
        obj->mC[i] = NULL;
    }
    if (*(s32*)(self + 0x300) == 0) {
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(self + 0xc));
        s32 n = 0;
        for (s32 i = 0; i < *(s32*)(self + 0x2f4); i++) {
            for (s32 j = 0; j < *(s32*)(self + 0x2f8); j++) {
                fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x34c, 0, 0, 0, 0, 1);
                fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x34d, 0, 0, 0, 0, 1);
                obj->mC[n++] = (Blz2Child*)fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x54d, 1, 0, 0, 0, 1);
                pos.y += 16.0f;
            }
            pos.y = *(f32*)(self + 0x10);
            pos.x += 16.0f;
        }
        *(s32*)(self + 0x2f0) = 2;
        *(u16*)(self + 0x94) = 1;
    } else {
        *(s32*)(self + 0x2f0) = 0;
        *(u16*)(self + 0x94) = 0;
    }
    *(f32*)(self + 0x60) = -8.0f;
    *(f32*)(self + 0x64) = -8.0f;
    *(f32*)(self + 0x68) = 8.0f;
    *(f32*)(self + 0x6c) = 8.0f;
    *(f32*)(self + 0x80) = -7.0f;
    *(f32*)(self + 0x84) = -7.0f;
    *(f32*)(self + 0x88) = 7.0f;
    *(f32*)(self + 0x8c) = 7.0f;
    *(s32*)(self + 0x114) = 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
