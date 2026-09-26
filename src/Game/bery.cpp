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
extern void* lbl_8053AAF8;
extern "C" s32 Actor_CreateByID(void* mgr, u32 kind, s32 room, void* pos, u32 param, s32 a, s32 b);

#include "JSystem/JGeometry.h"

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

struct BeryFull {
    u8 pad0[0xc];
    JGeometry::TVec3<f32> mPos;   // 0x0C
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3<f32> mVel;   // 0x3C
    u8 pad48[0x60 - 0x48];
    f32 m60, m64, m68, m6C;       // 0x60
    u8 pad70[0x90 - 0x70];
    u32 mParam;                   // 0x90
    u8 pad94[0x230 - 0x94];
    s32 mState;         // 0x230
    s32 mPlayer;        // 0x234
    s32 m238;
    s32 m23C;
    s32 m240;
    s32 m244;
    s32 m248;
    s32 m24C;
    s32 m250;
    s32 m254;
    s32 m258;
    s32 m25C;
    s32 mMsg;           // 0x260
    s32 m264;
    s32 m268;
    s32 m26C;
    s32 mChildId;       // 0x270
    s32 mSw[4];         // 0x274
    JGeometry::TVec3<f32> mStart; // 0x284
    JGeometry::TVec3<f32> mStep;  // 0x290
    s32 mKind;          // 0x29C
    s32 m2A0;
    s32 m2A4;
};

struct BeryGameState { u8 pad[0x83]; u8 m83; };
extern const f32 lbl_80543114;
extern const f32 lbl_80543130;
extern const f32 lbl_80543148;
extern const f32 lbl_8054314C;
extern const f32 lbl_80543150;
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);

static inline u32 beryLevel(s32 p) {
    return (((BeryGameState*)lbl_8053AAF8)->m83 >> (p * 2)) & 3;
}
static inline u8 beryLevel2(s32 p) {
    return (((BeryGameState*)lbl_8053AAF8)->m83 >> (fn_8022F340(p) * 2)) & 3;
}

extern "C" void fn_8038F464(BeryFull* this_) {
    this_->m60 = lbl_80543148;
    this_->m64 = lbl_80543148;
    this_->m68 = lbl_80543130;
    this_->m6C = lbl_80543130;
    this_->mVel.x = lbl_80543114;
    this_->mVel.y = lbl_80543114;
    this_->mVel.z = lbl_80543114;
    this_->mPlayer = -1;
    this_->m238 = -1;
    this_->mMsg = 0;
    this_->m268 = 0;
    this_->mChildId = -1;
    this_->mKind = 0;
    this_->mStart.z = lbl_80543114;
    this_->mStart.y = lbl_80543114;
    this_->mStart.x = lbl_80543114;
    this_->mStep.z = lbl_80543114;
    this_->mStep.y = lbl_80543114;
    this_->mStep.x = lbl_80543114;
    this_->mSw[0] = this_->mParam >> 27;
    this_->mSw[1] = (this_->mParam >> 22) & 0x1f;
    this_->mSw[2] = (this_->mParam >> 17) & 0x1f;
    this_->mSw[3] = (this_->mParam >> 12) & 0x1f;
    if ((this_->mParam & 0xf) == 3) {
        this_->mKind = (this_->mParam >> 4) & 0xf;
        this_->mPlayer = (this_->mParam >> 8) & 3;
        if (this_->mKind == 0xb) {
            JGeometry::TVec3<f32> dst = *fn_8023E724(this_->mPlayer);
            this_->mStart.x = this_->mPos.x;
            this_->mStart.y = this_->mPos.y;
            this_->mStart.z = this_->mPos.z;
            this_->mStart.z += lbl_8054314C;
            dst.z = lbl_80543130;
            this_->mStep.set((dst.x - this_->mStart.x) / lbl_80543150,
                             (dst.y - this_->mStart.y) / lbl_80543150,
                             (dst.z - this_->mStart.z) / lbl_80543150);
            this_->mState = 9;
        } else {
            this_->m264 = 0x78;
            this_->mState = 7;
        }
        s32 player = this_->mPlayer;
        switch (this_->mKind) {
        case 1:
            this_->mMsg = 0x260;
            break;
        case 2:
            this_->mMsg = 0x261;
            break;
        case 3:
            this_->mMsg = 0x262;
            break;
        case 4:
            this_->mMsg = 0x263;
            break;
        case 5:
            this_->mMsg = 0x264;
            break;
        case 6:
            this_->mMsg = 0x268;
            break;
        case 8:
            this_->mMsg = 0x269;
            break;
        case 7:
            this_->mMsg = 0x26a;
            break;
        case 9:
            if (beryLevel(fn_8022F340(player)) == 2) {
                this_->mMsg = 0x27f;
            } else {
                this_->mMsg = 0x284;
            }
            break;
        case 10:
            this_->mMsg = 0x265;
            break;
        case 11:
            this_->mMsg = 0x266;
            break;
        case 12:
            this_->mMsg = 0x267;
            break;
        }
    } else {
        this_->mState = 0;
    }
    this_->m240 = 2;
    this_->m244 = 0;
    this_->m23C = 0;
    this_->m248 = 0;
    this_->m24C = 0;
    this_->m250 = 0;
    this_->m254 = 0;
    this_->m258 = 0;
    this_->m25C = 0x1e;
    this_->m264 = 0;
    this_->m26C = 0;
    this_->m2A0 = 0;
    this_->m2A4 = 0;
    this_->mParam &= 0xf;
}

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
