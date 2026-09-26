// TU 0x80391ce4-0x80394134 (actor SCRE).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_80391CE4_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF4C0[];

extern "C" void* fn_80391CE4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF4C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_8039394C.cpp ----
// fn_8039394C - actor@lbl_804AF490: coordinator function. Dispatches
// on this->0x234 (mode): 0/4 -> fn_80393228(this); 1 -> nothing;
// 2 -> fn_80391F58(this); 3/5/6/7 -> if (!fn_80230188(this->0x238))
// fn_80391D44(this).
extern "C" void fn_80393228(void* this_);
extern "C" void fn_80391F58(void* this_);
extern "C" u8 fn_80230188(s32 a);
extern "C" void fn_80391D44(void* this_);

extern "C" void fn_8039394C(void* this_) {
    s32 mode = *(s32*)((char*)this_ + 0x234);
    if (mode == 0 || mode == 4) {
        fn_80393228(this_);
    } else if (mode == 1) {
        // nothing
    } else if (mode == 2) {
        fn_80391F58(this_);
    } else if (mode == 3 || mode == 5 || mode == 6 || mode == 7) {
        if (!fn_80230188(*(s32*)((char*)this_ + 0x238))) {
            fn_80391D44(this_);
        }
    }
}

// ---- fn_803939E0: update
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" s32 fn_8023BC38(s32);
extern "C" void fn_80393514(void* this_);
extern const f32 lbl_805431A8;
extern const f32 lbl_805431AC;
extern const f32 lbl_805431B0;
extern const f32 lbl_805431C4;

struct SCRE {
    u8 pad00[0xc];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3f mVel; // 0x3c
    u8 pad48[0x11c - 0x48];
    u8 m11C;
    u8 pad11D[0x230 - 0x11d];
    s32 m230;
    s32 mMode; // 0x234
    s32 mPlayer; // 0x238
};

extern "C" void fn_803939E0(SCRE* this_) {
    s32 mode = this_->mMode;
    if (mode == 0 || mode == 4) {
        fn_80393514(this_);
    } else if (mode == 1) {
        if (this_->m230 >= 0x50) {
            s32 d = 0x5a - this_->m230;
            this_->mVel.y = lbl_805431AC * (lbl_805431B0 - (f32)(d * d / 100));
            this_->mPos.add(this_->mVel);
        }
        if (this_->m230-- == 0) {
            this_->m11C = 0;
        }
    } else if (mode == 2) {
        this_->mVel.x = lbl_805431A8 * JMASinShort((this_->m230 % 60) << 10);
        this_->mPos.add(this_->mVel);
        if (this_->m230-- == 0) {
            this_->m11C = 0;
        }
    } else if (mode == 3 || mode == 5 || mode == 6 || mode == 7) {
        f32 y, z;
        z = fn_8023E724(this_->mPlayer)->z;
        y = fn_8023E724(this_->mPlayer)->y - lbl_805431C4;
        this_->mPos.set(fn_8023E724(this_->mPlayer)->x, y, z);
        if (!fn_80230188(this_->mPlayer) && fn_8023BC38(this_->mPlayer) <= 0) {
            this_->m11C = 0;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
