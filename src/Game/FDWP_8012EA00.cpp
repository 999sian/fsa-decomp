// FDWP_8012EA00: .text 0x8012EA00-0x8012F008 — Actor 'FDWP' (All-Players-Present Warp Trigger).
#include "types.h"

struct FdwpVec {
    f32 x;
    f32 y;
};

struct FdwpBox {
    f32 x0, y0, x1, y1;
};

extern "C" void v01__5ActorFv(void* this_);
extern "C" void v03__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" u8 fn_8023F264(s32 player);
extern "C" u8 fn_8023EA28(s32 player);
extern "C" u8 fn_8023561C(s32 player);
extern "C" u8 fn_80230188(s32 player);
extern "C" FdwpVec* fn_8023E724(s32 player);
extern "C" void fn_8023077C(void);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void* mgr, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* rec, u32 a, u32 b);
extern "C" void fn_80136798(void* obj, int id, int arg);
void operator delete(void* p);
extern void* lbl_8049E8F8[];
extern u8* lbl_8053AAF8;

class FDWP_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C();
    virtual void vf30(s32, s32);
    virtual u8 vf34();
    virtual void vf38();
    virtual s32 vf3C();

    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ FdwpBox mBounds60;
    /* 0x070 */ FdwpBox mBounds70;
    /* 0x080 */ FdwpBox mBounds80;
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mState;      // 0 = checking players, 1 = delay timer, 2 = warping
    /* 0x234 */ s32 mDestArea;   // Unpacked from (spawnParam >> 8) & 0xF
    /* 0x238 */ s32 mDestRoom;   // Unpacked from (spawnParam >> 12) & 0xF
    /* 0x23C */ s32 mWarpTimer;
};

extern "C" void* fn_8012EA00(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E8F8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// FDWP update (vtable slot 3)
extern "C" void fn_8012EA60(FDWP_Actor* this_) {
    v03__5ActorFv(this_);
    switch (this_->mState) {
    case 0: {
        if (this_->vf3C() != 0 && !this_->vf34()) {
            break;
        }
        f32 x0 = this_->mBounds60.x0;
        f32 y0 = this_->mBounds60.y0;
        f32 x1 = this_->mBounds60.x1;
        f32 y1 = this_->mBounds60.y1;
        x0 += this_->mPosX;
        x1 += this_->mPosX;
        y0 += this_->mPosY;
        y1 += this_->mPosY;
        BOOL all;
        for (s32 i = 0; i < 4; i++) {
            if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
                if (!fn_8023F264(i)) {
                    all = FALSE;
                    goto done;
                }
                if (fn_8023EA28(i)) {
                    all = FALSE;
                    goto done;
                }
                if (!fn_8023561C(i)) {
                    all = FALSE;
                    goto done;
                }
                if (fn_80230188(i)) {
                    all = FALSE;
                    goto done;
                }
                FdwpVec* v = fn_8023E724(i);
                f32 x = v->x;
                u8 in = FALSE;
                if (x >= x0 && v->y >= y0 && x < x1 && v->y < y1) {
                    in = TRUE;
                }
                if (!in) {
                    all = FALSE;
                    goto done;
                }
            }
        }
        all = TRUE;
    done:
        if ((u8)all) {
            this_->mState = 2;
            switch (this_->mState) {
            case 1:
                fn_8023077C();
                fn_80119998(fn_80119DD0(), 0x3C, 0, 1, 0, 1, 0x5A, 0);
                break;
            case 0:
                break;
            case 2:
                fn_802D9FF4(fn_802D6A9C(), this_->mDestArea, this_->mDestRoom);
                fn_80136798(lbl_8053AAF8, 0xF, 0);
                break;
            }
        }
        break;
    }
    case 1:
        this_->mWarpTimer++;
        if (this_->mWarpTimer == 0x78) {
            this_->mState = 2;
            switch (this_->mState) {
            case 1:
                fn_8023077C();
                fn_80119998(fn_80119DD0(), 0x3C, 0, 1, 0, 1, 0x5A, 0);
                break;
            case 0:
                break;
            case 2:
                fn_802D9FF4(fn_802D6A9C(), this_->mDestArea, this_->mDestRoom);
                fn_80136798(lbl_8053AAF8, 0xF, 0);
                break;
            }
        }
        break;
    case 2:
    default:
        break;
    }
}

// FDWP init (vtable slot 1)
extern "C" void fn_8012ED40(FDWP_Actor* this_) {
    v01__5ActorFv(this_);
    this_->mDestArea = (this_->mSpawnParam >> 8) & 0xF;
    this_->mDestRoom = (this_->mSpawnParam >> 12) & 0xF;
    this_->mBounds60.x0 = -32.0f;
    this_->mBounds60.y0 = -16.0f;
    this_->mBounds60.x1 = 32.0f;
    this_->mBounds60.y1 = 16.0f;
    this_->mBounds70.x0 = this_->mBounds60.x0;
    this_->mBounds70.y0 = this_->mBounds60.y0;
    this_->mBounds70.x1 = this_->mBounds60.x1;
    this_->mBounds70.y1 = this_->mBounds60.y1;
    this_->mBounds80.x0 = this_->mBounds60.x0;
    this_->mBounds80.y0 = this_->mBounds60.y0;
    this_->mBounds80.x1 = this_->mBounds60.x1;
    this_->mBounds80.y1 = this_->mBounds60.y1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
