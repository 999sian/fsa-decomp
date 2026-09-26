// TU 0x8038de74-0x8038f9f4 (actor BERY).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_8038F720_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void fn_803037D4(s32 index, s32 kind);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF338[];

extern "C" void* fn_8038F720(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF338;
        fn_801EE434(*(void**)((char*)this_ + 0x2a0));
        fn_801EE434(*(void**)((char*)this_ + 0x2a4));
        if (*(u32*)((char*)this_ + 0x90) != 3) {
            char* q = (char*)this_;
            for (s32 i = 0; i < 4; i++) {
                if (*(s32*)(q + 0x24c) == 1) {
                    fn_803037D4(i, 0x12);
                    *(s32*)(q + 0x24c) = 0;
                }
                q += 4;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}


extern "C" s32 fn_8022F340(s32 p);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 id);
extern "C" void fn_802D8050(void* mgr, s32 id, s32 a, s32 b);
extern "C" s32 fn_802373EC(s32 player);
extern "C" s32 fn_8023725C(s32 player);
extern "C" void fn_8038470C(s32 player, s32 msg);
extern "C" u8 fn_80388CAC(s32 player, void* p);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 kind, s32 room, void* pos, u32 param, s32 a, s32 b);

struct Bery {
    u8 pad0[0x4];
    s32 mRoom;          // 0x004
    u8 pad8[0x4];
    f32 mPos[3];        // 0x00C
    u8 pad18[0x198 - 0x18];
    void* m198;         // 0x198
    u8 pad19C[0x230 - 0x19c];
    s32 mState;         // 0x230
    s32 mPlayer;        // 0x234
    u8 pad238[0x260 - 0x238];
    s32 mMsg;           // 0x260
    u8 pad264[0x270 - 0x264];
    s32 mChildId;       // 0x270
    s32 mItemId[4];     // 0x274
    u8 pad284[0x29c - 0x284];
    s32 mKind;          // 0x29C
};

static inline u8 beryCheckItem(Bery* this_) {
    s32 id = this_->mItemId[fn_8022F340(this_->mPlayer)];
    return fn_802D800C(fn_802D6A9C(), id);
}

extern "C" void fn_8038DE74(Bery* this_) {
    if (this_->mItemId[fn_8022F340(this_->mPlayer)] != 0
        && beryCheckItem(this_) == 1)
    {
        this_->mKind = 0xc;
    } else {
        switch (fn_802373EC(fn_8022F340(this_->mPlayer))) {
        case 10:
            this_->mKind = 1;
            break;
        case 6:
            this_->mKind = 2;
            break;
        case 5:
            this_->mKind = 3;
            break;
        case 3:
            this_->mKind = 4;
            break;
        case 4:
            this_->mKind = 5;
            break;
        case 8:
            this_->mKind = 6;
            break;
        case 1:
            this_->mKind = 7;
            break;
        case 7:
            this_->mKind = 8;
            break;
        case 9:
            this_->mKind = 9;
            break;
        default:
            this_->mKind = 0xc;
            break;
        }
    }
    if (this_->mKind != 0xc && fn_8023725C(fn_8022F340(this_->mPlayer)) >= 2) {
        this_->mKind = 0xc;
    }
    if (this_->mKind == 0xc) {
        this_->mMsg = 0x267;
        fn_8038470C(this_->mPlayer, this_->mMsg);
        this_->mState = 2;
    } else if (fn_80388CAC(this_->mPlayer, this_->m198) == 1) {
        this_->mChildId = Actor_CreateByID(fn_801F856C(), 'BFRY', this_->mRoom, this_->mPos,
                                           ((this_->mKind & 0xf) << 4) | 3 | ((this_->mPlayer & 3) << 8), -1, -1);
        if (this_->mChildId >= 0) {
            this_->mState = 5;
            if (this_->mItemId[fn_8022F340(this_->mPlayer)] != 0) {
                s32 id = this_->mItemId[fn_8022F340(this_->mPlayer)];
                fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
            }
        } else {
            this_->mKind = 0;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
