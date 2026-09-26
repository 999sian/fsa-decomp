// TU 0x802e794c-0x802e7db4 (actor PNP2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Mjgr_dtor_802E794C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A9F58[];

extern "C" void* fn_802E794C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9F58;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Mjgr_EmptyHook.cpp ----
// Mjgr_EmptyHook - MJGR: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Mjgr_EmptyHook(void) {}

}

// fn_802E79B0 - PNP2: update(). When the virtual trigger (vtable +0x34)
// fires, walks all 0x400 slots of the manager at global->0x20; for every slot
// owned by this actor's key (this->0x230) it rewrites the slot value, then
// optionally spawns a "KMRI" actor / effect at the slot position and plays a
// sound, and finally notifies the room config and disables itself.
struct Pnp2Vec { f32 x, y, z; };
struct Pnp2VT {
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
    virtual u8 check();
};
extern char* lbl_8053AB10;
extern f32 lbl_80541258;
extern "C" u16 fn_802F9908(void* mgr, u32 room, s32 idx);
extern "C" void fn_802F9974(void* mgr, u32 room, s32 idx, u16 value);
extern "C" void fn_80226CA8(s32 idx, u32 room, Pnp2Vec* out);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8013CC50(f32 scale, u32 owner, Pnp2Vec* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7584(void* rec, u32 id, s32 flag);

extern "C" void fn_802E79B0(void* this_) {
    char* p = (char*)this_;
    u32 room;
    s32 i;
    if (((Pnp2VT*)this_)->check() == 1) {
        for (i = 0; i < 0x400; i++) {
            u16 v = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(u32*)(p + 0x4), i);
            if (*(s32*)(p + 0x230) == v) {
                fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), *(u32*)(p + 0x4), i, *(u32*)(p + 0x234));
                if (*(s32*)(p + 0x23c) != 0) {
                    Pnp2Vec pos;
                    fn_80226CA8(i, *(u32*)(p + 0x4), &pos);
                    room = *(u32*)(p + 0x4);
                    if ((s32)room >= 8) {
                        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, room, &pos, 0, -1, -1);
                    } else {
                        fn_8013CC50(lbl_80541258, room, &pos, 0x35c, 1, 0, 0, 0, 1);
                    }
                }
                if (*(s32*)(p + 0x238) != 0) {
                    fn_801F0E34(this_, 0x30003, 0);
                }
            }
        }
        fn_802D7584(fn_802D6A9C(), *(u32*)(p + 0x16c), 1);
        *(u8*)(p + 0x11c) = 0;
    }
}

// ---- RoomBitfieldClearParams_802E7B04.cpp ----
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7544(void*, void*);

// fn_802E7B04 - MJGR: setParams. Extracts 4 bitfields from this->0x90
// into this->0x230/0x234/0x238/0x23c, calls fn_802D6A9C then
// fn_802D7544(this->0x16c); if that query returns true, clears
// 0x238/0x23c; finally calls own virtual slot 5 (byte offset 0x14,
// notify/draw call). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802E7B04(void* this_) {
    *(u32*)((char*)this_ + 0x230) = *(u32*)((char*)this_ + 0x90) & 0xFFF;
    *(u32*)((char*)this_ + 0x234) = (*(u32*)((char*)this_ + 0x90) >> 12) & 0xFFF;
    *(u32*)((char*)this_ + 0x238) = (*(u32*)((char*)this_ + 0x90) >> 24) & 0x1;
    *(u32*)((char*)this_ + 0x23c) = (*(u32*)((char*)this_ + 0x90) >> 25) & 0x1;
    void* configRecord = fn_802D6A9C();
    if (fn_802D7544(configRecord, *(void**)((char*)this_ + 0x16c)) != 0) {
        *(u32*)((char*)this_ + 0x23c) = 0;
        *(u32*)((char*)this_ + 0x238) = 0;
    }
    ((ActorSlot5*)this_)->slot5();
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
