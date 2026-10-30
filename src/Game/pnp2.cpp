// TU 0x802e794c-0x802e7db4 — Actor 'PNP2' / 'MJGR' (Switch-Triggered Tile Replacer).
#include "Game/esd/types.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A9F58[];

struct Pnp2Vec { f32 x, y, z; };
struct Pnp2VT {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual u8 check();
};

struct Pnp2Actor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u8 _pad08[0x90 - 0x08];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x16C - 0x11D];
    /* 0x16C */ void* mRoomConfigId;
    /* 0x170 */ u8 _pad170[0x230 - 0x170];
    /* 0x230 */ s32 mSourceTileId; // Unpacked from spawnParam & 0xFFF
    /* 0x234 */ u32 mDestTileId;   // Unpacked from (spawnParam >> 12) & 0xFFF
    /* 0x238 */ s32 mPlaySfxFlag;  // Unpacked from (spawnParam >> 24) & 1
    /* 0x23C */ s32 mSpawnSmoke;   // Unpacked from (spawnParam >> 25) & 1
};

extern "C" void* fn_802E794C(Pnp2Actor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804A9F58;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Mjgr_EmptyHook(void) {}
}

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

// PNP2 update (vtable slot 3): replaces all matching tiles in the 0x400-tile room map
extern "C" void fn_802E79B0(Pnp2Actor* this_) {
    u32 room;
    s32 i;
    if (((Pnp2VT*)this_)->check() == 1) {
        for (i = 0; i < 0x400; i++) {
            u16 v = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), this_->mRoomId, i);
            if (this_->mSourceTileId == v) {
                fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), this_->mRoomId, i, this_->mDestTileId);
                if (this_->mSpawnSmoke != 0) {
                    Pnp2Vec pos;
                    fn_80226CA8(i, this_->mRoomId, &pos);
                    room = this_->mRoomId;
                    if ((s32)room >= 8) {
                        Actor_CreateByID(fn_801F856C(), 'KMRI', room, &pos, 0, -1, -1);
                    } else {
                        fn_8013CC50(lbl_80541258, room, &pos, 0x35c, 1, 0, 0, 0, 1);
                    }
                }
                if (this_->mPlaySfxFlag != 0) {
                    fn_801F0E34(this_, 0x30003, 0);
                }
            }
        }
        fn_802D7584(fn_802D6A9C(), (u32)this_->mRoomConfigId, 1);
        this_->mActiveFlag = 0;
    }
}

extern "C" u8 fn_802D7544(void*, void*);

struct ActorSlot5 {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void slot5();
};

// PNP2 init (vtable slot 1)
extern "C" void fn_802E7B04(Pnp2Actor* this_) {
    this_->mSourceTileId = this_->mSpawnParam & 0xFFF;
    this_->mDestTileId = (this_->mSpawnParam >> 12) & 0xFFF;
    this_->mPlaySfxFlag = (this_->mSpawnParam >> 24) & 0x1;
    this_->mSpawnSmoke = (this_->mSpawnParam >> 25) & 0x1;
    void* configRecord = fn_802D6A9C();
    if (fn_802D7544(configRecord, this_->mRoomConfigId) != 0) {
        this_->mSpawnSmoke = 0;
        this_->mPlaySfxFlag = 0;
    }
    ((ActorSlot5*)this_)->slot5();
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
