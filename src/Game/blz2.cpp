// TU 0x802e4c74-0x802e5c44 (actor BLZ2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
extern "C" f32 lbl_80541210;

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
  f32 z, y, x, dx, dy;
  x = pos->x;
  dx = lbl_8046F148[i];
  y = pos->y;
  dy = lbl_8046F188[i];
  x += dx;
  z = pos->z;
  y += dy;
  Blz2Vec q(x,y,z);
  if (fn_801EE3C0(fn_80226850(&q, *(u32*)(p + 4))) == 1) {
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
    virtual u8 v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void slot21();
    virtual u8 slot22(void*);
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

extern "C" void fn_8020D7D0(void* a, u32 b);
extern "C" void* fn_8020D58C(void);
extern "C" void fn_801F2718(void* self, u32 kind);
extern "C" void* fn_801F856C(void);
extern "C" u8 fn_801F2B7C(void* self, u32 a, s32 b, s32 c);
extern "C" void fn_80239914(void* box, u32 room, u32 handle);
extern "C" u8 fn_80234CF8(s32 a);
extern "C" void fn_801F0E34(void* self, u32 a, u32 b);
extern "C" void* Actor_CreateByID(void* mgr, u32 id, u32 room, void* pos, u32 flag, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* mgr, u32 v, s32 a, s32 b);
static inline void blz2CreateGrid(u8* self, JGeometry::TVec3<f32>& pos, s32& i, s32& j) {
    ((ActorSlot21*)self)->slot21();
    for (i = 0; i < *(s32*)(self + 0x2f4); i++) {
        for (j = 0; j < *(s32*)(self + 0x2f8); j++) {
            Actor_CreateByID(fn_801F856C(), 0x424c5a45, *(u32*)(self + 4), &pos, (*(u32*)(self + 0x98) << 4) | 15, -1, -1);
            *(u32*)(self + 0x1a0) = 0x424c5a45;
            pos.y += 16.0f;
        }
        pos.y = *(f32*)(self + 0x10);
        pos.x += 16.0f;
    }
    *(u16*)(self + 0x94) = 0;
    ((ActorSlot21*)self)->v7();
}
static inline void blz2TouchRoom(u32 handle) {
    u8* mgr = (u8*)fn_8020D58C();
    fn_8020D7D0(mgr + mgr[0] * 0x784 + 4, handle);
}
extern "C" const f32 lbl_8046F0C8[];
extern "C" const f32 lbl_8046F108[];
extern "C" void fn_802E4FD8(u8* self) {
    JGeometry::TVec3<f32> pos;
    JGeometry::TVec3<f32> grid;
    Blz2Vec probe;
    JGeometry::TVec3<f32> saved;
    JGeometry::TBox2<f32> box;
    JGeometry::TVec3<f32> check;
    s32 j;
    s32 i;
    f32 savedY;
    u8* q;
    s32 h;
    u8* p;
    f32 spacing3;
    pos = *(JGeometry::TVec3<f32>*)(self + 0xc);
    if (*(s32*)(self + 0x2f0) >= 1) {
        blz2TouchRoom(*(u32*)(self + 0x198));
    }
    pos = *(JGeometry::TVec3<f32>*)(self + 0xc);
    fn_801F2718(self, 0x5455424f);
    switch (*(s32*)(self + 0x2f0)) {
    case 0:
        if (*(s32*)(self + 0x300) == 0 || (*(s32*)(self + 0x300) != 0 && ((ActorSlot21*)self)->v11() == 1)) {
            f32 spacing = lbl_80541210;
            grid = *(JGeometry::TVec3<f32>*)(self + 0xc);
            p = self;
            for (j = 0; j < *(s32*)(self + 0x2f4); j++) {
                q = p;
                for (i = 0; i < *(s32*)(self + 0x2f8); ) {
                    *(void**)(q + 0x230) = fn_8013CC50(*(s32*)(self + 4), &grid, 1.0f, 0x34c, 0, 0, 0, 0, 1);
                    *(void**)(q + 0x270) = fn_8013CC50(*(s32*)(self + 4), &grid, 1.0f, 0x34d, 0, 0, 0, 0, 1);
                    *(void**)(q + 0x2b0) = fn_8013CC50(*(s32*)(self + 4), &grid, 1.0f, 0x54d, 1, 0, 0, 0, 1);
                    q += 4;
                    p += 4;
                    i++;
                    grid.y += spacing;
                }
                grid.y = *(f32*)(self + 0x10);
                grid.x += spacing;
            }
            if (*(s32*)(self + 0x2fc) == 0) *(s32*)(self + 0x2f0) = 2;
            else if (*(s32*)(self + 0x2fc) == 3) *(s32*)(self + 0x2f0) = 6;
            else *(s32*)(self + 0x2f0) = 1;
            *(u16*)(self + 0x94) = 1;
        }
        break;
    case 1:
        for (j = 0; j < 8; j++) {
            probe.x = *(f32*)(self + 0xc) + lbl_8046F0C8[j];
            probe.y = *(f32*)(self + 0x10) + lbl_8046F108[j];
            probe.z = *(f32*)(self + 0x14);
            if (fn_801EE3C0((u16)fn_80226850(&probe, *(u32*)(self + 4))) == 1) {
                Actor_CreateByID(fn_801F856C(), 0x424c5a45, *(u32*)(self + 4), &probe, (*(u32*)(self + 0x98) << 4) | 15, -1, -1);
                *(u32*)(self + 0x1a0) = 0x424c5a45;
                *(s32*)(self + 0x2f0) = 4;
                *(s32*)(self + 0x304) = 40;
                break;
            }
        }
        break;
    case 2:
        if (*(u16*)(self + 0x94) == 2 || (*(s32*)(self + 0x2fc) == 2 && ((ActorSlot21*)self)->v11() == 1)) {
            fn_802D8050(fn_802D6A9C(), *(u32*)(self + 0x308), 1, 255);
            ((ActorSlot21*)self)->slot21();
            f32 spacing = lbl_80541210;
            q = self;
            for (j = 0; j < *(s32*)(self + 0x2f4); j++) {
                p = q;
                for (i = 0; i < *(s32*)(self + 0x2f8); ) {
                    *(void**)(p + 0x230) = fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x4f2, 1, 0, 0, 0, 1);
                    p += 4;
                    q += 4;
                    i++;
                    pos.y += spacing;
                }
                pos.y = *(f32*)(self + 0x10);
                pos.x += spacing;
            }
            *(s32*)(self + 0x2f0) = 5;
            *(s32*)(self + 0x304) = 60;
            *(u16*)(self + 0x94) = 0;
        } else {
            saved = *(JGeometry::TVec3<f32>*)(self + 0xc);
            f32 spacing = lbl_80541210;
            savedY = saved.y;
            for (j = 0; j < *(s32*)(self + 0x2f4); j++) {
                for (i = 0; i < *(s32*)(self + 0x2f8); ) {
                    check = *(JGeometry::TVec3<f32>*)(self + 0xc);
                    if (((ActorSlot21*)self)->slot22(&check) == 1) {
                        *(s32*)(self + 0x2f0) = 3;
                        goto done;
                    }
                    box.set(*(JGeometry::TBox2<f32>*)(self + 0x60));
                    box.addPos(*(f32*)(self + 0xc), *(f32*)(self + 0x10));
                    fn_801F2B7C(self, *(u32*)(self + 0x114), -1, 7);
                    box = *(JGeometry::TBox2<f32>*)(self + 0x80);
                    box.addPos(*(f32*)(self + 0xc), *(f32*)(self + 0x10));
                    fn_80239914(&box, *(u32*)(self + 4), *(u32*)(self + 0x198));
                    i++;
                    *(f32*)(self + 0x10) += spacing;
                }
                *(f32*)(self + 0x10) = savedY;
                *(f32*)(self + 0xc) += spacing;
            }
            (*(JGeometry::TVec3<f32>*)(self + 0xc)).x = saved.x;
            (*(JGeometry::TVec3<f32>*)(self + 0xc)).y = saved.y;
            (*(JGeometry::TVec3<f32>*)(self + 0xc)).z = saved.z;
        }
        break;
    case 3: {
        ((ActorSlot21*)self)->slot21();
        for (j = 0; j < *(s32*)(self + 0x2f4); j++) {
            for (i = 0; i < *(s32*)(self + 0x2f8); ) {
                Actor_CreateByID(fn_801F856C(), 0x424c5a45, *(u32*)(self + 4), &pos, (*(u32*)(self + 0x98) << 4) | 15, -1, -1);
                *(u32*)(self + 0x1a0) = 0x424c5a45;
                i++;
                pos.y += 16.0f;
            }
            pos.y = *(f32*)(self + 0x10);
            pos.x += 16.0f;
        }
        *(u16*)(self + 0x94) = 0;
        ((ActorSlot21*)self)->v7();
        break;
    }
    case 4:
        --*(s32*)(self + 0x304);
        if (*(s32*)(self + 0x304) == 0) ((ActorSlot21*)self)->v7();
        break;
    case 5:
        --*(s32*)(self + 0x304);
        if (*(s32*)(self + 0x304) == 0) ((ActorSlot21*)self)->v7();
        else if (*(s32*)(self + 0x304) == 52) fn_801F0E34(self, 0x30061, 0);
        break;
    case 6:
        if (fn_801F2B7C(self, *(u32*)(self + 0x114), -1, 7)) {
            if (!fn_80234CF8(0)) *(s32*)(self + 0x304) = 1;
            else *(s32*)(self + 0x304) = 0;
        }
        if (*(s32*)(self + 0x300) != 0 && !((ActorSlot21*)self)->v11()) {
            ((ActorSlot21*)self)->slot21();
            *(u16*)(self + 0x94) = 0;
            *(s32*)(self + 0x2f0) = 0;
        }
        break;
    }
done:;
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
    register s32 zero = 0;
    *(s32*)(self + 0x2f4) = ((*(u32*)(self + 0x90) >> 22) & 0x1f) + 1;
    *(s32*)(self + 0x2f8) = ((*(u32*)(self + 0x90) >> 17) & 0x1f) + 1;
    *(s32*)(self + 0x2fc) = *(u32*)(self + 0x90) & 0xf;
    *(s32*)(self + 0x300) = (*(u32*)(self + 0x90) >> 4) & 1;
    *(s32*)(self + 0x308) = (*(u32*)(self + 0x90) >> 12) & 0x1f;
    for (s32 i = 0; i < 16; i += 8) {
        obj->mA[i + 0] = (Blz2Child*)zero;
        obj->mB[i + 0] = (Blz2Child*)zero;
        obj->mC[i + 0] = (Blz2Child*)zero;
        obj->mA[i + 1] = (Blz2Child*)zero;
        obj->mB[i + 1] = (Blz2Child*)zero;
        obj->mC[i + 1] = (Blz2Child*)zero;
        obj->mA[i + 2] = (Blz2Child*)zero;
        obj->mB[i + 2] = (Blz2Child*)zero;
        obj->mC[i + 2] = (Blz2Child*)zero;
        obj->mA[i + 3] = (Blz2Child*)zero;
        obj->mB[i + 3] = (Blz2Child*)zero;
        obj->mC[i + 3] = (Blz2Child*)zero;
        obj->mA[i + 4] = (Blz2Child*)zero;
        obj->mB[i + 4] = (Blz2Child*)zero;
        obj->mC[i + 4] = (Blz2Child*)zero;
        obj->mA[i + 5] = (Blz2Child*)zero;
        obj->mB[i + 5] = (Blz2Child*)zero;
        obj->mC[i + 5] = (Blz2Child*)zero;
        obj->mA[i + 6] = (Blz2Child*)zero;
        obj->mB[i + 6] = (Blz2Child*)zero;
        obj->mC[i + 6] = (Blz2Child*)zero;
        obj->mA[i + 7] = (Blz2Child*)zero;
        obj->mB[i + 7] = (Blz2Child*)zero;
        obj->mC[i + 7] = (Blz2Child*)zero;
    }
    if (*(s32*)(self + 0x300) == 0) {
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(self + 0xc));
        u8* q;
        register u8* p = self;
        for (s32 i = 0; i < *(s32*)(self + 0x2f4); i++) {
            q = p;
            for (s32 j = 0; j < *(s32*)(self + 0x2f8); j++) {
                fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x34c, 0, 0, 0, 0, 1);
                fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x34d, 0, 0, 0, 0, 1);
                *(void**)(q + 0x2b0) = fn_8013CC50(*(s32*)(self + 4), &pos, 1.0f, 0x54d, 1, 0, 0, 0, 1);
                q += 4;
                pos.y += 16.0f;
                p += 4;
            }
            pos.y = *(f32*)(self + 0x10);
            pos.x += 16.0f;
        }
        *(s32*)(self + 0x2f0) = 2;
        *(u16*)(self + 0x94) = 1;
    } else {
        *(s32*)(self + 0x2f0) = zero;
        *(u16*)(self + 0x94) = zero;
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
