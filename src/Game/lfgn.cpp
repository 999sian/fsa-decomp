// TU 0x8036d7f8-0x8036dd6c — Actor 'LFGN' (Spawns 'LEAF' Actors on Matching Room Tiles).
#include "types.h"
#include "dolphin/mtx.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AE288[];

struct LeafActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ Vec mPos;
    /* 0x018 */ u8 _pad18[0x11C - 0x18];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x1A0 - 0x11D];
    /* 0x1A0 */ u32 mActorFourCC; // 'LEAF'
    /* 0x1A4 */ u8 _pad1A4[0x230 - 0x1A4];
    /* 0x230 */ u8 mTriggered;
};

extern "C" void* fn_8036D7F8(LeafActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804AE288;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct LfgnMgr {
    u8 pad0[8];
    LeafActor* mActors[0x400];
    s32 mCount;
    int getNum() { return mCount; }
    LeafActor* get(int i) { return mActors[i]; }
};
extern "C" LfgnMgr* fn_801F856C(void);

extern "C" void fn_8036D858(void* thisPtr, Vec* pos) {
    LeafActor* a;
    int n = fn_801F856C()->getNum();
    for (int i = 0; i < n; i++) {
        a = fn_801F856C()->get(i);
        if (a != NULL && a->mActorFourCC == 'LEAF' && a->mActiveFlag == 1
            && PSVECDistance(pos, &a->mPos) <= 57.0f
            && __fabsf(a->mPos.x - pos->x) <= 42.0f) {
            a->mTriggered = 1;
            return;
        }
    }
}

extern "C" void fn_8036D91C(void) {}
extern "C" void fn_8036D920(void) {}

extern "C" u8 fn_802DEBA0(void* actor);
struct LfgnVec2 { f32 x, y; };
extern "C" u32 fn_80226BC4(LfgnVec2* pos, u32 id);
extern "C" u32 fn_802F9908(void* map, u32 id, u32 tile);
extern "C" void Actor_CreateByID(void* mgr, u32 type, u32 id, Vec* pos, u32 p5, s32 a, s32 b);
extern "C" char* lbl_8053AB10;

// LFGN init (vtable slot 1): scans 32x24 room tile grid and spawns 'LEAF' on leaf tiles
extern "C" void fn_8036D924(LeafActor* p) {
    u16 kind;
    s32 x;
    s32 y;
    if (fn_802DEBA0(p)) {
        return;
    }
    f32 baseX = 512.0f * (f32)(s32)(p->mPos.x / 512.0f);
    f32 baseY = 384.0f * (f32)(s32)(p->mPos.y / 384.0f);
    for (s32 row = 0; row < 24; row++) {
        y = 16.0f * (f32)row + baseY;
        for (s32 col = 0; col < 32; col++) {
            x = 16.0f * (f32)col + baseX;
            LfgnVec2 q;
            q.x = x;
            q.y = y;
            u32 tile = fn_80226BC4(&q, p->mRoomId);
            kind = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), p->mRoomId, tile) & 0x3FF;
            if ((u16)(kind - 0x1e1) <= 1 || kind == 0x1f1 || kind == 0x1f2) {
                Vec pos;
                pos.x = x;
                pos.y = y;
                pos.z = 0.0f;
                Actor_CreateByID(fn_801F856C(), 'LEAF', p->mRoomId, &pos, kind, -1, -1);
            }
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
