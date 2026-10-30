// IFCK_8012F008: .text 0x8012F008-0x8012F3E4 — Actor 'IFCK' (Tile-Change Condition Watcher).
#include "types.h"

extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" u16 fn_80226850(void* p, void* q);
extern "C" void* fn_8012F554(void);
extern "C" void fn_8012F530(void* mgr, void* actor);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern void* lbl_8049E950[];

class IFCK_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C();
    virtual void vf30(s32, s32);
    virtual void vf34();
    virtual void vf38();
    virtual s32 vf3C();

    /* 0x004 */ void* mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x230 - 0x18];
    /* 0x230 */ s32 mState;         // 0 = watching tile, 1 = tile changed
    /* 0x234 */ u16 mInitialTileId; // Tile ID sampled at init
};

extern "C" s32 fn_8012F008(IFCK_Actor* this_) {
    switch (this_->mState) {
    case 0:
        break;
    case 1:
        return 1;
    }
    return 0;
}

// IFCK update (vtable slot 3)
extern "C" void fn_8012F02C(IFCK_Actor* this_) {
    v03__5ActorFv(this_);
    switch (this_->mState) {
    case 0:
        if (this_->mInitialTileId != fn_80226850(this_->mPos, this_->mRoomId)) {
            if (this_->vf3C() > 0) {
                this_->vf30(0xFF, 1);
            }
            this_->mState = 1;
        }
        break;
    case 1:
        break;
    }
}

// IFCK init (vtable slot 1)
extern "C" void fn_8012F0D0(IFCK_Actor* this_) {
    v01__5ActorFv(this_);
    this_->mInitialTileId = fn_80226850(this_->mPos, this_->mRoomId);
    fn_8012F530(fn_8012F554(), this_);
}

extern "C" void* fn_8012F118(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E950;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void* __ct__5ActorFv(void* this_);

extern "C" void* fn_8012F178(IFCK_Actor* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_8049E950;
    this_->mState = 0;
    this_->mInitialTileId = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
