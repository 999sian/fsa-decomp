// TU 0x802f3f7c-0x802f43c0 — Actor 'TBGN' (Spawns 'TBO2' Pots Across Room Tile Grids).
#include "Game/esd/types.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
void operator delete(void* p);
extern void* lbl_804AA6F8[];

struct TbgnVec { f32 x, y, z; };

struct TbgnActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mTileScanIndex; // Current 0..1023 tile index in 32x32 scan
};

extern "C" void* fn_802F3F7C(TbgnActor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804AA6F8;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Tbgn_EmptyHook1(void) {}
void Tbgn_EmptyHook2(void) {}
}

extern char* lbl_8053AB10;
extern "C" u16 fn_802F9908(void* mgr, s32 room, s32 idx);
extern "C" void fn_802F9974(void* mgr, s32 room, s32 idx, u16 value);
extern "C" void fn_80226CA8(s32 idx, s32 room, TbgnVec* out);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, s32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D76A8(void* rec, u32 id);

// TBGN init (vtable slot 1): scans room 0 and rooms 8..14 for tile 0x41 and spawns 'TBO2'
extern "C" void fn_802F3FE4(TbgnActor* p) {
    u32 tile;
    s32 y, x;
    s32 r, room, y2, x2;
    TbgnVec pos;
    u32 sw = p->mSpawnParam;
    p->mTileScanIndex = 0;
    for (y = 0; y < 32; y++) {
        for (x = 0; x < 32; x++) {
            tile = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), 0, p->mTileScanIndex) & 0x3FF;
            if (tile == 0x41) {
                if (!fn_802D76A8(fn_802D6A9C(), sw)) {
                    fn_80226CA8(p->mTileScanIndex, 0, &pos);
                    Actor_CreateByID(fn_801F856C(), 'TBO2', 0, &pos, tile, sw, -1);
                } else {
                    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), 0, p->mTileScanIndex, 0x12);
                }
                sw++;
            }
            p->mTileScanIndex = p->mTileScanIndex + 1;
        }
    }
    for (r = 0; r < 7; r++) {
        room = r + 8;
        p->mTileScanIndex = 0;
        for (y2 = 0; y2 < 32; y2++) {
            for (x2 = 0; x2 < 32; x2++) {
                tile = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, p->mTileScanIndex) & 0x3FF;
                if (tile == 0x41) {
                    if (!fn_802D76A8(fn_802D6A9C(), sw)) {
                        fn_80226CA8(p->mTileScanIndex, room, &pos);
                        Actor_CreateByID(fn_801F856C(), 'TBO2', room, &pos, tile, sw, -1);
                    } else {
                        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, p->mTileScanIndex, 0x12);
                    }
                    sw++;
                }
                p->mTileScanIndex = p->mTileScanIndex + 1;
            }
        }
    }
}

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
