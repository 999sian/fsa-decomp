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
    u32 m2A0;
    u32 m2A4;
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
extern "C" int fn_80237810(s32);
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
static inline u8 beryCheckFullItem(BeryFull* actor) {
    s32 id = actor->mSw[fn_8022F340(actor->mPlayer)];
    return fn_802D800C(fn_802D6A9C(), id);
}
#pragma peephole off
extern "C" void fn_8038E368(BeryFull* this_) {
    s32 i;
    s32 anim;
    s32 id;
    s32 index;
    s32 current;
    s32 n;
    JGeometry::TVec3f playerPos;
    if (this_->m248 != 1) {
        if (this_->mParam != 3) {
            if (fn_80138A30(lbl_8053AAF8) > 1 && this_->mRoom >= 8) {
                for (i = 0; i < 4; i++) {
                    n = this_->mRoom;
                    if ((s32)fn_8023DE58(i) == n && !fn_8022F478(i) && !fn_80236B50(i) && (&this_->m24C)[fn_8022F340(i)] == 0) {
                        fn_803037D4(fn_8022F340(i), 0x11);
                        (&this_->m24C)[fn_8022F340(i)] = 1;
                    }
                }
            }
            JGeometry::TBox2f box;
            box.i.x = this_->m60; box.i.y = this_->m64; box.f.x = this_->m68; box.f.y = this_->m6C;
            box.i.x += this_->mPos.x; box.i.y += this_->mPos.y;
            box.f.x += this_->mPos.x; box.f.y += this_->mPos.y;
            fn_80239914((f32*)&box, this_->mRoom, this_->m198);
        }
        JGeometry::TBox2f nearBox(-24.0f, -24.0f, 24.0f, 24.0f);
        nearBox.addPos(*(JGeometry::TVec2f*)((u8*)this_ + 0x24));
        JGeometry::TBox2f farBox(-36.0f, -36.0f, 36.0f, 36.0f);
        farBox.addPos(*(JGeometry::TVec2f*)((u8*)this_ + 0x24));
        switch (this_->mState) {
        case 0:
            for (i = 0; i < 4; i++) {
                if (this_->m238 != i && lbl_80543114 == fn_8023E724(i)->z && !fn_8023EFEC(i) && !fn_8023EA28(i) && !fn_80236B50(i)) {
                    if (!((u8*)lbl_8053AAF8)[0x7f] && fn_80237060(fn_8022F340(i)) >= 2) {
                        if (fn_8023725C(fn_8022F340(i)) >= 2 || fn_8023725C(fn_8022F340(i)) == 0) continue;
                    }
                    fn_8022FF8C(i, &nearBox, this_->mRoom, this_->m198, 0, 1);
                } else if (!fn_8023B0F4(i, &farBox, this_->mRoom, 0, lbl_80543118)) {
                    this_->m238 = -1;
                }
            }
            this_->mPlayer = fn_8022FD8C(this_->m198);
            if (this_->mPlayer >= 0 && lbl_80543114 == fn_8023E724(this_->mPlayer)->z) {
                switch (this_->mParam) {
                case 0: this_->mMsg = 0x25e; break;
                default: this_->mMsg = 0x25f; break;
                }
                void* handle = this_->m198;
                s32 room = this_->mRoom;
                JGeometry::TVec3f pos = this_->mPos;
                if (fn_8038AD24(this_->mPlayer, this_->mMsg, handle, room, &pos, 0x2080)) {
                    this_->m238 = this_->mPlayer;
                    this_->mState = 1;
                }
            }
            break;
        case 1:
            fn_8022FEB8(&nearBox, this_->mRoom, this_->m198, 0, 1);
            if (fn_803865B8(this_->mPlayer)) {
                switch ((s32)this_->mParam) {
                case 0:
                    if (fn_80388CAC(this_->mPlayer, this_->m198)) {
                n = fn_80237810(fn_8022F340(this_->mPlayer));
                fn_80236554(fn_8022F340(this_->mPlayer), n, 0);
                s32 room = this_->mRoom;
                if (room >= 8) Actor_CreateByID(fn_801F856C(), 'PEFF', room, &this_->mPos, (this_->mPlayer & 3) | 4, -1, -1);
                fn_801F0E34(this_, 0x40090, 0);
                this_->mState = 3;
                    }
                    break;
                case 1: fn_8038DE74((Bery*)this_); break;
                case 2:
                    if (fn_80236E3C(fn_8022F340(this_->mPlayer)) || (this_->mSw[fn_8022F340(this_->mPlayer)] != 0 && beryCheckFullItem(this_) == 1)) {
                        this_->mMsg = 0x267;
                        fn_8038470C(this_->mPlayer, this_->mMsg);
                        this_->mState = 2;
                    } else if (fn_80388CAC(this_->mPlayer, this_->m198)) {
                        this_->mChildId = Actor_CreateByID(fn_801F856C(), 'BFRY', this_->mRoom, &this_->mPos, ((this_->mKind & 15) << 4) | 3 | ((this_->mPlayer & 3) << 8), -1, -1);
                        if (this_->mChildId >= 0) {
                            this_->mKind = 11; this_->mState = 5;
                            if (this_->mSw[fn_8022F340(this_->mPlayer)] != 0) {
                                id = this_->mSw[fn_8022F340(this_->mPlayer)];
                                fn_802D8050(fn_802D6A9C(), id, 1, 255);
                            }
                        }
                    }
                    break;
                }
            }
            fn_80230498(this_->mPlayer, fn_8023E724(this_->mPlayer), 0x3f, 255, -128, -128, 1);
            break;
        case 2:
            fn_8022FEB8(&nearBox, this_->mRoom, this_->m198, 0, 1);
            if (fn_80388CAC(this_->mPlayer, this_->m198)) {
                n = fn_80237810(fn_8022F340(this_->mPlayer));
                fn_80236554(fn_8022F340(this_->mPlayer), n, 0);
                s32 room = this_->mRoom;
                if (room >= 8) Actor_CreateByID(fn_801F856C(), 'PEFF', room, &this_->mPos, (this_->mPlayer & 3) | 4, -1, -1);
                fn_801F0E34(this_, 0x40090, 0);
                this_->mState = 3;
            }
            break;
        case 3:
            if (fn_80237810(fn_8022F340(this_->mPlayer)) == ((s32*)(lbl_80529DEC + 0xd8))[fn_8022F340(this_->mPlayer)] && this_->m25C == 0 && fn_8023061C(this_->mPlayer, 0) == 1) {
                this_->m25C = 30; this_->mKind = 0; this_->mState = 6;
            }
            index = fn_8022F340(this_->mPlayer);
            current = fn_80237810(fn_8022F340(this_->mPlayer));
            if (current == ((s32*)(lbl_80529DEC + 0xd8))[index] && this_->m25C > 0) {
                if (this_->m25C % 10 == 0) fn_80230EB8(fn_8022F340(this_->mPlayer), 9);
                this_->m25C--;
            }
            break;
        case 4:
            if (this_->m240-- == 0) this_->m248 = 1;
            break;
        case 5:
            if (!fn_801F666C(fn_801F856C(), this_->mChildId)) {
                if (this_->mParam == 2) { this_->m240 = 180; this_->mState = 4; }
                else { this_->mKind = 0; this_->mState = 6; }
            }
            break;
        case 6:
            for (i = 0; i < 4; i++) {
                if (i == this_->mPlayer) {
                    if (!fn_8023B0F4(i, &farBox, this_->mRoom, 0, lbl_80543118)) { this_->mState = 0; goto state_done; }
                } else if (fn_8023B0F4(i, &farBox, this_->mRoom, 0, lbl_80543118) && !fn_8022F478(i)) {
                    if (!fn_8022E438(i, this_->mPlayer) || fn_8022CAF8(this_->mPlayer) == 4) { this_->mState = 0; goto state_done; }
                }
            }
            break;
        case 7:
            if (this_->m264 >= 60 && this_->mParam == 3) {
                JGeometry::TVec3f* pos = fn_8023E724(this_->mPlayer);
                this_->mStart.x = pos->x; this_->mStart.y = pos->y; this_->mStart.z = pos->z;
                this_->mStart.y += lbl_8054311C;
                this_->mStart.z = lbl_80543120;
                this_->mStep.x = lbl_80543114; this_->mStep.y = lbl_80543124; this_->mStep.z = lbl_80543114;
                this_->m264 = 0; this_->mState = 8;
            } else this_->m264++;
            break;
        case 8: {
            anim = 0x331;
            if (this_->m264 >= 8) {
                if (this_->m264 < 9) anim = 0x332;
                else if (this_->m264 < 10) anim = 0x333;
                else if (this_->m264 < 18) anim = 0x334;
                else anim = 0x3f;
            }
            fn_80230498(this_->mPlayer, fn_8023E724(this_->mPlayer), anim, 255, -128, -128, 1);
            if (this_->m264 >= 10) {
                this_->mStart += this_->mStep;
                if (this_->mStart.z <= lbl_80543114) {
                    this_->mStart.z = lbl_80543114; this_->m264 = 0;
                    s32 room = this_->mRoom;
                    if (room < 8) fn_8013CC50(room, &this_->mStart, lbl_80543100, 0x3d0, 0, 0, 0, 0, 1);
                    else Actor_CreateByID(fn_801F856C(), 'PEFF', room, &this_->mStart, 0x2c, -1, -1);
                    fn_801F0E34(this_, 0x30022, 0);
                    this_->mStart.x = this_->mPos.x; this_->mStart.y = this_->mPos.y; this_->mStart.z = this_->mPos.z;
                    this_->mStart.x = fn_8023E724(this_->mPlayer)->x;
                    this_->mStep.x = lbl_80543114; this_->mStep.y = lbl_80543128; this_->mStep.z = lbl_80543128; this_->mState = 9;
                    goto state_done;
                } else this_->mStep.z -= lbl_8054312C;
            }
            this_->m264++;
            break;
        }
        case 9:
            if (this_->m264 >= 120) {
                this_->m264 = 0;
                if (this_->mKind != 11) {
                    s32 room = this_->mRoom;
                    if (room < 8) fn_8013CC50(room, &this_->mStart, lbl_80543100, 0x3d0, 0, 0, 0, 0, 1);
                    else Actor_CreateByID(fn_801F856C(), 'PEFF', room, &this_->mStart, 0x2c, -1, -1);
                    this_->mState = 10;
                } else { this_->m264 = 3; this_->m268 = 7; this_->m26C = 3; this_->mState = 10; }
            } else this_->m264++;
            break;
        case 10:
            this_->mStart += this_->mStep;
            playerPos = *fn_8023E724(this_->mPlayer);
            if (playerPos.y - this_->mStart.y < lbl_80543130) { this_->m264 = 0; this_->mState = 11; }
            else if (this_->mKind != 11) this_->mStep.z -= lbl_80543134;
            else if (this_->m264 > 0) {
                if (this_->m26C <= 0) {
                    this_->m26C = this_->m264;
                    this_->m268--;
                    if (this_->m268 <= 0) {
                        this_->m268 = 7; this_->m264--;
                        if (this_->m264 <= 0) { this_->m26C = 0; goto state_done; }
                    }
                }
                this_->m26C--;
            }
            break;
        case 11: {
            JGeometry::TVec3f* pos = fn_8023E724(this_->mPlayer);
            playerPos.x = pos->x; playerPos.y = pos->y; playerPos.z = pos->z;
            if (this_->m264 < 10) anim = 0;
            else if (this_->m264 < 14) {
                anim = 1;
                this_->mStart.x = lbl_8054311C + playerPos.x;
                this_->mStart.y = playerPos.y - lbl_80543120;
                this_->mStart.z = playerPos.z;
                if (this_->m264 == 10) fn_80230F44(fn_8022F340(this_->mPlayer), 0x1000002);
            } else {
                anim = 2;
                this_->mStart.x = lbl_80543138 + playerPos.x;
                this_->mStart.y = playerPos.y - lbl_8054313C;
                this_->mStart.z = playerPos.z;
                if (!this_->m2A0) this_->m2A0 = (s32)fn_8013CC50(this_->mRoom, &this_->mStart, lbl_80543140, 0x562, 0, 1, 0, 0, 1);
                if (!this_->m2A0) this_->m2A4 = (s32)fn_8013CC50(this_->mRoom, &this_->mStart, lbl_80543144, 0x563, 0, 1, 0, 0, 1);
                if (this_->m264 >= 100) {
                    s32 room = this_->mRoom;
                    JGeometry::TVec3f vec = *(JGeometry::TVec3f*)((u8*)this_ + 0x24);
                    if (fn_8038BD08(this_->mPlayer, this_->mMsg, room, &vec, 0x2022) == 1) {
                        this_->mState = 12;
                        if (this_->mKind == 10) fn_80236ED8(fn_8022F340(this_->mPlayer), 2);
                        else if (this_->mKind == 11) fn_80236DB0(fn_8022F340(this_->mPlayer));
                        else fn_802370FC(fn_8022F340(this_->mPlayer), 2);
                        goto state_done;
                    } else this_->m264 = 100;
                }
            }
            fn_80230498(this_->mPlayer, &playerPos, anim + 0xe9, 255, -128, -128, 1);
            this_->m264++;
            break;
        }
        case 12:
            if (fn_80388CAC(this_->mPlayer, this_->m198) == 1) {
                if (this_->m2A0) {
                    u8* e = (u8*)this_->m2A0;
                    *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; this_->m2A0 = 0;
                }
                if (this_->m2A4) {
                    u8* e = (u8*)this_->m2A4;
                    *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; this_->m2A4 = 0;
                }
                if (fn_8023061C(this_->mPlayer, 0) == 1) {
                    if (!((u8*)lbl_8053AAF8)[0x7f]) detach__5ActorFv(this_);
                    else {
                        this_->mState = 13; fn_801F0E34(this_, 0x40090, 0);
                n = fn_80237810(fn_8022F340(this_->mPlayer));
                fn_80236554(fn_8022F340(this_->mPlayer), n, 0);
                s32 room = this_->mRoom;
                if (room >= 8) Actor_CreateByID(fn_801F856C(), 'PEFF', room, &this_->mPos, (this_->mPlayer & 3) | 4, -1, -1);
                
                    }
                }
            }
            break;
        case 13:
            if (fn_80237774(fn_8022F340(this_->mPlayer)) <= ((s32*)(lbl_80529DEC + 0xd8))[fn_8022F340(this_->mPlayer)] && this_->m25C == 0) detach__5ActorFv(this_);
            index = fn_8022F340(this_->mPlayer);
            current = fn_80237774(fn_8022F340(this_->mPlayer));
            if (current <= ((s32*)(lbl_80529DEC + 0xd8))[index] && this_->m25C > 0) {
                if (this_->m25C % 10 == 0) fn_80230EB8(fn_8022F340(this_->mPlayer), 9);
                this_->m25C--;
            }
            break;
        }
state_done:
        if (this_->mParam != 3) {
            this_->m23C++;
            if (this_->m23C > lbl_804755E0[this_->m244]) {
                this_->m244++;
                if (this_->m244 >= 8) { this_->m244 = 0; this_->m23C = 0; }
            }
        }
    }
    if (this_->mParam != 3 && fn_80138A30(lbl_8053AAF8) > 1) {
        u8 present[4];
        present[0] = 0; present[1] = 0; present[2] = 0; present[3] = 0;
        for (i = 0; i < 4; i++) {
            s32 room = this_->mRoom;
            if (fn_8023DE58(i) == room && !fn_8022F478(i) && !fn_80236B50(i)) present[fn_8022F340(i)] = 1;
        }
        for (i = 0; i < fn_80138A30(lbl_8053AAF8); i++) {
            if (!present[i] && (&this_->m24C)[i] == 1) { fn_803037D4(i, 0x12); (&this_->m24C)[i] = 0; }
        }
    }
}
#pragma peephole reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
