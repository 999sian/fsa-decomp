// TU 0x802f3f7c-0x802f43c0 (actor TBGN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Tbgn_dtor_802F3F7C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA6F8[];

extern "C" void* fn_802F3F7C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA6F8;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Tbgn_EmptyHook1.cpp ----
// Tbgn_EmptyHook1 / Tbgn_EmptyHook2 - TBGN: 2 empty no-op overrides (0x4 each, leaf, no extab needed)
extern "C" {

void Tbgn_EmptyHook1(void) {}

void Tbgn_EmptyHook2(void) {}

}

// fn_802F3FE4 - TBGN: setParams(). Scans the 32x32 tile grid of room 0 and
// of rooms 8..14 for tile type 0x41; for each hit either spawns a "TBO2"
// actor at the tile (numbered from the spawn param) or, when that switch is
// already set, replaces the tile with type 0x12.
struct TbgnVec { f32 x, y, z; };
extern char* lbl_8053AB10;
extern "C" u16 fn_802F9908(void* mgr, s32 room, s32 idx);
extern "C" void fn_802F9974(void* mgr, s32 room, s32 idx, u16 value);
extern "C" void fn_80226CA8(s32 idx, s32 room, TbgnVec* out);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, s32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D76A8(void* rec, u32 id);

// NONMATCHING (98.8%): retail allocates sw=r31, this=r30, tile=r29.
extern "C" void fn_802F3FE4(char* p) {
    u32 sw = *(u32*)(p + 0x90);
    u32 tile;
    s32 y, x;
    s32 r, room, y2, x2;
    TbgnVec pos;
    *(s32*)(p + 0x230) = 0;
    for (y = 0; y < 32; y++) {
        for (x = 0; x < 32; x++) {
            tile = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), 0, *(s32*)(p + 0x230)) & 0x3FF;
            if (tile == 0x41) {
                if (!fn_802D76A8(fn_802D6A9C(), sw)) {
                    fn_80226CA8(*(s32*)(p + 0x230), 0, &pos);
                    Actor_CreateByID(fn_801F856C(), 0x54424f32, 0, &pos, tile, sw, -1);
                } else {
                    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), 0, *(s32*)(p + 0x230), 0x12);
                }
                sw++;
            }
            *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
        }
    }
    for (r = 0; r < 7; r++) {
        room = r + 8;
        *(s32*)(p + 0x230) = 0;
        for (y2 = 0; y2 < 32; y2++) {
            for (x2 = 0; x2 < 32; x2++) {
                tile = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(p + 0x230)) & 0x3FF;
                if (tile == 0x41) {
                    if (!fn_802D76A8(fn_802D6A9C(), sw)) {
                        fn_80226CA8(*(s32*)(p + 0x230), room, &pos);
                        Actor_CreateByID(fn_801F856C(), 0x54424f32, room, &pos, tile, sw, -1);
                    } else {
                        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(p + 0x230), 0x12);
                    }
                    sw++;
                }
                *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
            }
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
