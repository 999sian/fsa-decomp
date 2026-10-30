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
    u8 pad0[0x4];
    s32 mRoom;                    // 0x04
    u8 pad8[0x4];
    JGeometry::TVec3<f32> mPos;   // 0x0C
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3<f32> mVel;   // 0x3C
    u8 pad48[0x60 - 0x48];
    f32 m60, m64, m68, m6C;       // 0x60
    u8 pad70[0x90 - 0x70];
    u32 mParam;                   // 0x90
    u8 pad94[0x198 - 0x94];
    void* m198;                   // 0x198
    u8 pad19C[0x230 - 0x19c];
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

#pragma opt_propagation off
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
            f32 divisor;
            f32 height;
            JGeometry::TVec3<f32> dst(*fn_8023E724(this_->mPlayer));
            this_->mStart.x = this_->mPos.x;
            this_->mStart.y = this_->mPos.y;
            this_->mStart.z = this_->mPos.z;
            this_->mStart.z += lbl_8054314C;
            divisor = lbl_80543150;
            height = lbl_80543130;
            dst.z = height;
            this_->mStep.set((dst.x - this_->mStart.x) / divisor, (dst.y - this_->mStart.y) / divisor, (dst.z - this_->mStart.z) / divisor);
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
#pragma opt_propagation reset
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

struct BeryDrawParam {
    BeryDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};


struct BeryTables {
    s32 mNormal[11];
    s32 mAlt[11];
};
extern const BeryTables lbl_80475600;
extern const char lbl_80475658[];
extern const f32 lbl_80543100;
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, BeryDrawParam* prm, s32 mode, f32 sx, f32 sy);
extern "C" void fn_803075AC(void* a, s32 room, void* pos, s32 id, s32 p5, s32 p6, s32 p7, s32 p8, s32 p9, s32 p10);

extern "C" void fn_8038E0A0(BeryFull* this_) {
    if (this_->m248 != 1 && (this_->m240 & 2) && this_->mParam != 3) {
        fn_801F06F0(this_, lbl_80475658, this_->m244 + 0x61, NULL, 7, lbl_80543100, lbl_80543100);
        fn_803075AC(this_->m198, this_->mRoom, &this_->mPos, this_->m244 + 0x61, 0, 2, -1, 0, 0, 0);
    }
    s32 state = this_->mState;
    if ((state == 8 || state == 10 || state == 11 || state == 12) && this_->m26C == 0 && this_->mParam == 3) {
        BeryDrawParam prm;
        s32 mode = 7;
        prm.reset();
        JGeometry::TVec3<f32> pos = this_->mPos;
        s32 id = lbl_80475600.mNormal[this_->mKind - 1];
        prm.m4D = 0;
        prm.m4C = 0;
        this_->mPos = this_->mStart;
        if (this_->mState == 10 || this_->mState == 11 || this_->mState == 12) {
            id = lbl_80475600.mAlt[this_->mKind - 1];
        }
        if (this_->mState == 11 || this_->mState == 12) {
            mode = -1;
            prm.m4D = 1;
            prm.m4C = 1;
        }
        fn_801F06F0(this_, lbl_80475658, id, &prm, mode, lbl_80543100, lbl_80543100);
        fn_803075AC(this_->m198, this_->mRoom, &this_->mPos, id, 0, 2, -1, 1, 0, 0);
        this_->mPos = pos;
    }
}

extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_8022F478(s32 i);
extern "C" u8 fn_80236B50(s32 i);
extern "C" void fn_80239914(f32* box, s32 room, void* p);
extern "C" s32 fn_80138A30(void* p);
extern const f32 lbl_80543104;
extern const f32 lbl_80543108;
extern const f32 lbl_8054310C;
extern const f32 lbl_80543110;
#include "JSystem/JGeometry/Box.h"
extern const f32 lbl_80543118, lbl_8054311C, lbl_80543120, lbl_80543124, lbl_80543128, lbl_8054312C, lbl_80543134, lbl_80543138, lbl_8054313C, lbl_80543140, lbl_80543144;
extern const s32 lbl_804755E0[];
extern u8 lbl_80529DEC[];
extern "C" u8 fn_8023EFEC(s32);
extern "C" u8 fn_8023EA28(s32);
extern "C" s32 fn_80237060(s32);
extern "C" void fn_8022FF8C(s32, void*, s32, void*, s32, s32);
extern "C" u8 fn_8023B0F4(s32, void*, s32, s32, f32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_8038AD24(s32,s32,void*,s32,void*,s32);
extern "C" void fn_8022FEB8(void*,s32,void*,s32,s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_80237810(s32);
extern "C" s32 fn_80237774(s32);
extern "C" void fn_80236554(s32,s32,s32);
extern "C" void fn_801F0E34(void*,s32,s32);
extern "C" u8 fn_80236E3C(s32);
extern "C" void fn_80230498(s32,void*,s32,s32,s32,s32,s32);
extern "C" u8 fn_8023061C(s32,s32);
extern "C" void fn_80230EB8(s32,s32);
extern "C" void* fn_801F666C(void*,s32);
extern "C" u8 fn_8022E438(s32,s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" void* fn_8013CC50(s32,void*,f32,s32,s32,s32,s32,s32,s32);
extern "C" void fn_80230F44(s32,s32);
extern "C" u8 fn_8038BD08(s32,s32,s32,void*,s32);
extern "C" void fn_80236ED8(s32,s32);
extern "C" void fn_80236DB0(s32);
extern "C" void fn_802370FC(s32,s32);
extern "C" void detach__5ActorFv(void*);
extern "C" void fn_8038E368(BeryFull* this_) {
    if (this_->m248 != 1) {
        if (this_->mParam != 3) {
            if (fn_80138A30(lbl_8053AAF8) > 1 && this_->mRoom >= 8) {
                s32 room = this_->mRoom;
                for (s32 i = 0; i < 4; i++) {
                    if (fn_8023DE58(i) == room) {
                        if (!fn_8022F478(i) && !fn_80236B50(i)) {
                            if ((&this_->m24C)[fn_8022F340(i)] == 0) {
                                fn_803037D4(fn_8022F340(i), 0x11);
                                (&this_->m24C)[fn_8022F340(i)] = 1;
                            }
                        }
                    }
                }
            }
            f32 box[4];
            box[0] = this_->m60 + this_->mPos.x;
            box[1] = this_->m64 + this_->mPos.y;
            box[2] = this_->m68 + this_->mPos.x;
            box[3] = this_->m6C + this_->mPos.y;
            fn_80239914(box, this_->mRoom, this_->m198);
        }
        f32 pts[8];
        f32 f24 = *(f32*)((u8*)this_ + 0x24);
        f32 f28 = *(f32*)((u8*)this_ + 0x28);
        pts[0] = lbl_8054310C + f24;
        pts[1] = lbl_8054310C + f28;
        pts[2] = lbl_80543110 + f24;
        pts[3] = lbl_80543110 + f28;
        pts[4] = lbl_80543104 + f24;
        pts[5] = lbl_80543104 + f28;
        pts[6] = lbl_80543108 + f24;
        pts[7] = lbl_80543108 + f28;
        /* TODO: switch on mState (jumptable_804AF3B8, cases 0..13) and the rest of the function */
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
