// TU 0x802e4c74-0x802e5c44 (actor BLZ2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// NONMATCHING (43%): MWCC hoists pos->x/y/z into f30/f31 here; retail
// reloads them every iteration.
// fn_802E4C74 - BLZ2: true if any of the four probe points around pos lies
// on a blocking tile.
struct Blz2Vec {
    f32 x, y, z;
    Blz2Vec() {}
    Blz2Vec(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
};
extern const f32 lbl_8046F148[4];
extern const f32 lbl_8046F188[4];
extern "C" u16 fn_80226850(Blz2Vec* pos, u32 room);
extern "C" u8 fn_801EE3C0(u16 tile);
extern "C" u8 fn_802E4C74(char* p, const Blz2Vec* pos) {
    u8 hit = 0;
    for (s32 i = 0; i < 4; i++) {
        Blz2Vec q(pos->x + lbl_8046F148[i], pos->y + lbl_8046F188[i], pos->z);
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
extern "C" void dtor_801F593C(void* this_, int how);
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
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
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
