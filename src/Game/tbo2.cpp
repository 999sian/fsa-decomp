// TU 0x802f43c0-0x802f4820 (actor TBO2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Tbo2_dtor_802F43C0.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA750[];

extern "C" void* fn_802F43C0(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA750;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// fn_802F4420 - TBO2: spawn draw. Places a "SOB " resource object on the
// map (players' rooms only) and fires effect 0x21 at the tile position.
struct Tbo2Vec {
    f32 x, y, z;
    Tbo2Vec(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
};
struct Tbo2ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
extern const f32 lbl_805414D0;
extern const f32 lbl_805414D4;
extern const f32 lbl_805414D8;
extern const char lbl_8046F928[];
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern "C" void fn_802F86CC(void* map, Tbo2Vec* pos, void* res, f32 a, f32 b, s32 id, s32 c);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, Tbo2Vec* pos, s32 effectRef, s32 flag,
                            s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);

extern "C" void fn_802F4420(char* p) {
    Tbo2Vec a(*(f32*)(p + 0xc), *(f32*)(p + 0x10) - lbl_805414D0, lbl_805414D4);
    if (*(s32*)(p + 0x4) < 8) {
        void* res = (*(Tbo2ResMgr**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_8046F928);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &a, res, lbl_805414D8, lbl_805414D8, 0x21, 0);
    }
    Tbo2Vec b(*(f32*)(p + 0xc), *(f32*)(p + 0x10) - lbl_805414D0, lbl_805414D4);
    fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 0x4), &b, 0x21, 0, 2, -1, 0, 0, 0);
}

// fn_802F4510 / fn_802F45DC - TBO2: collision box setup and position nudge.
struct Tbo2Pt { f32 x, y; };
struct Tbo2Box { Tbo2Pt min, max; Tbo2Box(const Tbo2Pt& a, const Tbo2Pt& b) : min(a), max(b) {} };
extern const f32 lbl_805414DC;
extern const f32 lbl_805414E0;
extern "C" void fn_80239914(Tbo2Box* box, u32 room, u32 id);
extern "C" u8* fn_8020D58C();
extern "C" void fn_8020D7D0(void* slot, u32 id);

extern "C" void fn_802F4510(char* p) {
    *(f32*)(p + 0x80) = lbl_805414DC;
    *(f32*)(p + 0x84) = lbl_805414DC;
    *(f32*)(p + 0x88) = lbl_805414E0;
    *(f32*)(p + 0x8c) = lbl_805414E0;
    Tbo2Box box(*(Tbo2Pt*)(p + 0x80), *(Tbo2Pt*)(p + 0x88));
    f32 x = *(f32*)(p + 0xc);
    f32 y = *(f32*)(p + 0x10);
    box.min.x += x;
    box.min.y += y;
    box.max.x += x;
    box.max.y += y;
    fn_80239914(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198));
    u32 id = *(u32*)(p + 0x198);
    u8* mgr = fn_8020D58C();
    fn_8020D7D0(mgr + 4 + mgr[0] * 0x784, id);
}

extern "C" void fn_802F45DC(char* p) {
    *(f32*)(p + 0xc) += lbl_805414E0;
    *(f32*)(p + 0x10) += lbl_805414E0;
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
