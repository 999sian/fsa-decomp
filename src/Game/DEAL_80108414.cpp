// DEAL_80108414: .text 0x80108414-0x80108A6C — Actor 'DEAL' (Unused Item Shop Dealer).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
void operator delete(void* p);
extern void* lbl_8049CD48[];
extern void* lbl_8049CC34[];

struct DEAL_Box {
    f32 x0, y0, x1, y1;
};

struct DealSub238 {
    /* 0x00 */ u8 _pad00[0x10];
    /* 0x10 */ s32 mAnimOffset; // +0x248 on DealActor
    /* 0x14 */ u8 _pad14[0x10];
    /* 0x24 */ void* mVtable;   // +0x25C on DealActor
};

struct DealActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3f mPos;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ DEAL_Box mBounds;
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ DEAL_Box mHitBounds;
    /* 0x090 */ u8 _pad90[0x108 - 0x90];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x198 - 0x10C];
    /* 0x198 */ void* mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;          // 0 = idle, 1 = talking, 3 = post-talk
    /* 0x234 */ s32 mTalkingPlayer;  // Player index interacting with shop (-1 = none)
    /* 0x238 */ DealSub238 mAnimSub; // Embedded animation controller
};

extern "C" void* fn_80108414(DealActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_8049CD48;
        if (&this_->mAnimSub != 0) {
            if (&this_->mAnimSub.mVtable != 0) {
                this_->mAnimSub.mVtable = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void v06__5ActorFv(void* this_);
extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, s32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_8022FEB8(void*, s32, void*, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_802300EC(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void*, u32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" u8 fn_8038AD24(s32, u16, void*, s32, JGeometry::TVec3f, s32);
extern "C" void fn_8022FF8C(s32, void*, s32, void*, s32, s32);
extern "C" u8 fn_80388CAC(s32, void*);
extern "C" u8 fn_80388EEC(s32);

extern const char lbl_80464014[];
extern u8 lbl_80539ED8[8];
extern const f32 lbl_8053C318;
extern const f32 lbl_8053C31C;
extern const f32 lbl_8053C320;
extern const f32 lbl_8053C324;
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;

class DEAL_ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

// DEAL draw (vtable slot 6)
extern "C" void fn_80108494(DealActor* this_) {
    v06__5ActorFv(this_);
    s32 id = this_->mAnimSub.mAnimOffset + 0x1AB;
    void* pos = &this_->mPos;
    if (this_->mRoomId < 8) {
        void* res = (*(DEAL_ResMgr**)(lbl_8053AAF8 + 0xA4))->vf18('SOB ', lbl_80464014);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053C318, lbl_8053C318, 0);
    }
    fn_803075AC(this_->mRoomHandle, this_->mRoomId, &this_->mPos,
                this_->mAnimSub.mAnimOffset + 0x1AB, 0, 1, -1, 0, 0, 0);
}

static inline u8 DEAL_HasItem() {
    s32 idx = fn_801F7A08(fn_801F856C(), 'SITM');
    if (idx < 0) {
        return 0;
    }
    if (fn_801F666C(fn_801F856C(), idx) == 0) {
        return 0;
    }
    return 1;
}

// DEAL update (vtable slot 3)
extern "C" void fn_80108568(DealActor* this_) {
    v03__5ActorFv(this_);
    DEAL_Box b;
    b.x0 = this_->mBounds.x0;
    b.y0 = this_->mBounds.y0;
    b.x1 = this_->mBounds.x1;
    b.y1 = this_->mBounds.y1;
    b.x0 += this_->mPos.x;
    b.y0 += this_->mPos.y;
    b.x1 += this_->mPos.x;
    b.y1 += this_->mPos.y;
    fn_80239914(&b, this_->mRoomId, this_->mRoomHandle);
    switch (this_->mState) {
    case 0: {
        fn_8022FEB8(&b, this_->mRoomId, this_->mRoomHandle, 1, 0);
        s32 slot = fn_8022FD8C(this_->mRoomHandle);
        if (slot >= 0 && fn_802300EC()) {
            int msg = 0x259;
            if (!DEAL_HasItem()) {
                msg = 0x2AA;
            }
            void* room = this_->mRoomHandle;
            s32 player = this_->mRoomId;
            if (fn_8038AD24(slot, msg, room, player, this_->mPos, 0x28)) {
                this_->mTalkingPlayer = slot;
                this_->mState = 1;
            }
        }
        break;
    }
    case 1:
        fn_8022FF8C(this_->mTalkingPlayer, &b, this_->mRoomId, this_->mRoomHandle, 1, 0);
        if (fn_80388CAC(this_->mTalkingPlayer, this_->mRoomHandle)) {
            this_->mTalkingPlayer = -1;
            this_->mState = 0;
        }
        break;
    case 3:
        if (fn_80388EEC(this_->mTalkingPlayer)) {
            this_->mTalkingPlayer = -1;
            this_->mState = 0;
        }
        break;
    }
    fn_801D1C18(&this_->mAnimSub);
}

// DEAL init (vtable slot 1)
extern "C" void fn_80108764(DealActor* this_) {
    v01__5ActorFv(this_);
    this_->mBounds.x0 = lbl_8053C31C;
    this_->mBounds.y0 = lbl_8053C31C;
    this_->mBounds.x1 = lbl_8053C320;
    this_->mBounds.y1 = lbl_8053C320;
    this_->mHitBounds.x0 = lbl_8053C324;
    this_->mHitBounds.y0 = lbl_8053C324;
    this_->mHitBounds.x1 = lbl_8053C324;
    this_->mHitBounds.y1 = lbl_8053C324;
    this_->mSortPriority = 0;
    fn_801D2608(&this_->mAnimSub, lbl_80539ED8, 1);
    fn_801D22DC(&this_->mAnimSub, 0, 2, 0);
    fn_801D1F14(&this_->mAnimSub, lbl_8053C324);
}

struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_801D267C(void*);

class fn_801087F4_actor : public Actor {
public:
    fn_801087F4_actor();
};

fn_801087F4_actor::fn_801087F4_actor() : Actor() {
    DealActor* self = (DealActor*)this;
    self->mVtable = lbl_8049CD48;
    self->mState = 0;
    self->mTalkingPlayer = -1;
    fn_801D267C(&self->mAnimSub);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
