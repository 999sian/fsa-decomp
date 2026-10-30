// SHTM_80108A6C: .text 0x80108A6C-0x80109534 — Actor 'SHTM' (Shop Item Counter).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CDC0[];
extern void* lbl_8049CC34[];

struct SHTM_Box {
    f32 x0, y0, x1, y1;
};

struct ShtmSub230 {
    /* 0x00 */ u8 _pad00[0x10];
    /* 0x10 */ s32 mAnimOffset; // +0x240 on ShtmActor
    /* 0x14 */ u8 _pad14[0x10];
    /* 0x24 */ void* mVtable;   // +0x254 on ShtmActor
    /* 0x28 */ u8 _pad28[0x10];
};

struct ShtmActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3f mPos;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ SHTM_Box mBounds60;
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ SHTM_Box mBounds80;
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x108 - 0x94];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x11D - 0x10C];
    /* 0x11D */ u8 mFlag11D;
    /* 0x11E */ u8 _pad11E[0x198 - 0x11E];
    /* 0x198 */ void* mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ ShtmSub230 mAnimSub;
    /* 0x268 */ s32 mItemIndex;     // 0..7 shop item type (spawnParam & 0xFF)
    /* 0x26C */ s32 mState;         // 0 = idle, 1 = prompt, 2 = grant item, 3 = wait anim, 4/5 = close msg, 6 = detach
    /* 0x270 */ s32 mBuyerPlayer;   // Player index buying item (-1 = none)
    /* 0x274 */ s32 mField274;
    /* 0x278 */ JGeometry::TVec3f mPromptPos;
};

extern "C" void* fn_80108A6C(ShtmActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_8049CDC0;
        if (&this_->mAnimSub != 0) {
            if (&this_->mAnimSub.mVtable != 0) {
                this_->mAnimSub.mVtable = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void v06__5ActorFv(void* this_);
struct SHTM_DrawKey {
    s32 a, b;
    SHTM_DrawKey() { a = -1; b = -1; }
};
struct SHTM_DrawParam {
    u8 map[16];      // 0x00
    SHTM_DrawKey key; // 0x10
    s32 c;           // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    SHTM_DrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern const char lbl_8046404C[];
extern const f32 lbl_8053C368;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, SHTM_DrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);

// SHTM draw (vtable slot 6)
extern "C" void fn_80108AEC(ShtmActor* this_) {
    v06__5ActorFv(this_);
    SHTM_DrawParam param;
    fn_801F02BC(this_, lbl_8046404C, this_->mAnimSub.mAnimOffset + 0x17B, &param, 7, 0, 0, lbl_8053C368, lbl_8053C368);
}

extern "C" void v03__5ActorFv(void* this_);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_8022FEB8(void*, s32, void*, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_802300EC(void);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" s32 fn_8030AAF4(s32);
extern "C" u32 fn_80309D6C(void*, s32, u32);
extern void* lbl_8053AD30;
extern "C" u8 fn_8038AD24(s32, u32, void*, s32, JGeometry::TVec3f, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" void fn_8038470C(s32, u32);
extern "C" s32 fn_80237774(s32);
extern "C" s32 fn_80236228(s32);
extern "C" u8 fn_80388CAC(s32, void*);
extern "C" void fn_802308E0(s32);
extern "C" void fn_802362C4(s32, s32);
extern "C" void fn_8023764C(s32, s32);
extern "C" void fn_80235FE8(s32);
extern "C" void fn_802372F8(s32, s32, s32);
extern "C" void* fn_8023E724(s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern "C" u8 fn_80230188(s32);
extern "C" void fn_8023061C(s32, s32);
extern "C" void detach__5ActorFv(void* this_);
extern const u16 lbl_80464028[8];
extern const u32 lbl_8046403C[4];

// SHTM update (vtable slot 3): shop purchase state machine (spawns 'IMUP' item get on purchase)
extern "C" void fn_80108C34(ShtmActor* this_) {
    v03__5ActorFv(this_);
    SHTM_Box b;
    b.x0 = this_->mBounds60.x0;
    b.y0 = this_->mBounds60.y0;
    b.x1 = this_->mBounds60.x1;
    b.y1 = this_->mBounds60.y1;
    b.x0 += this_->mPos.x;
    b.y0 += this_->mPos.y;
    b.x1 += this_->mPos.x;
    b.y1 += this_->mPos.y;
    switch (this_->mState) {
    case 0: {
        fn_80239914(&b, this_->mRoomId, this_->mRoomHandle);
        fn_8022FEB8(&b, this_->mRoomId, this_->mRoomHandle, 0, 0);
        s32 pad;
        s32 slot = fn_8022FD8C(this_->mRoomHandle);
        if (slot >= 0 && fn_802300EC()) {
            pad = slot;
            if (fn_8022F514(slot)) {
                pad = fn_8022F3DC(slot);
            }
            if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(pad), 0x120)) {
                void* room = this_->mRoomHandle;
                s32 player = this_->mRoomId;
                if (fn_8038AD24(slot, lbl_8046403C[0], room, player, this_->mPromptPos, 0x28)) {
                    this_->mBuyerPlayer = slot;
                    this_->mState = 1;
                }
            }
        }
        break;
    }
    case 1:
        fn_8022FEB8(&b, this_->mRoomId, this_->mRoomHandle, 1, 0);
        if (fn_803865B8(this_->mBuyerPlayer)) {
            switch (fn_8037EFB4(this_->mBuyerPlayer)) {
            case 0: {
                u8 ok;
                s32 p = this_->mBuyerPlayer;
                switch (this_->mItemIndex) {
                case 2:
                    if (fn_80237774(p) > lbl_80464028[this_->mItemIndex]) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                    break;
                case 0:
                case 1:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    if (fn_80236228(p) >= lbl_80464028[this_->mItemIndex]) {
                        ok = 1;
                    } else {
                        ok = 0;
                    }
                    break;
                default:
                    ok = 0;
                    break;
                }
                if (ok) {
                    fn_80388CAC(this_->mBuyerPlayer, this_->mRoomHandle);
                    fn_802308E0(this_->mBuyerPlayer);
                    this_->mState = 2;
                } else {
                    fn_8038470C(this_->mBuyerPlayer, lbl_8046403C[2]);
                    this_->mState = 5;
                }
                break;
            }
            case 1:
            default:
                fn_8038470C(this_->mBuyerPlayer, lbl_8046403C[3]);
                this_->mState = 4;
                break;
            }
        }
        break;
    case 2: {
        s32 p = this_->mBuyerPlayer;
        if (p >= 0) {
            this_->mFlag11D = 0;
            switch (this_->mItemIndex) {
            case 0:
                fn_802362C4(p, -lbl_80464028[0]);
                break;
            case 1:
                fn_802362C4(p, -lbl_80464028[1]);
                break;
            case 2:
                fn_8023764C(p, fn_80237774(p) - lbl_80464028[2]);
                break;
            case 3:
                fn_802362C4(p, -lbl_80464028[3]);
                break;
            case 4:
                fn_802362C4(p, -lbl_80464028[4]);
                fn_80235FE8(p);
                fn_802372F8(p, 9, 1);
                break;
            case 5:
                fn_802362C4(p, -lbl_80464028[5]);
                fn_80235FE8(p);
                fn_802372F8(p, 4, 1);
                break;
            case 6:
                fn_802362C4(p, -lbl_80464028[6]);
                fn_80235FE8(p);
                fn_802372F8(p, 3, 1);
                break;
            case 7:
                fn_802362C4(p, -lbl_80464028[7]);
                fn_80235FE8(p);
                fn_802372F8(p, 6, 1);
                break;
            }
        }
        u32 param = 0;
        this_->mState = 3;
        switch (this_->mItemIndex) {
        case 2:
            param |= 0x4;
            break;
        case 0:
            param |= 0x40020;
            break;
        case 1:
            param |= 0x50000;
            break;
        case 3:
            param |= 0x40014;
            break;
        case 4:
            param |= 0x10008;
            break;
        case 5:
            param |= 0x10003;
            break;
        case 6:
            param |= 0x10002;
            break;
        case 7:
            param |= 0x10005;
            break;
        }
        s32 who = this_->mBuyerPlayer;
        param |= who << 24;
        param |= who << 26;
        Actor_CreateByID(fn_801F856C(), 'IMUP', this_->mRoomId, fn_8023E724(who), param, -1, -1);
        break;
    }
    case 3:
        if (!fn_80230188(this_->mBuyerPlayer)) {
            fn_8023061C(this_->mBuyerPlayer, 0);
            this_->mState = 6;
        }
        break;
    case 4:
        fn_8022FEB8(&b, this_->mRoomId, this_->mRoomHandle, 1, 0);
        if (fn_80388CAC(this_->mBuyerPlayer, this_->mRoomHandle)) {
            this_->mState = 0;
            this_->mBuyerPlayer = -1;
        }
        break;
    case 5:
        fn_8022FEB8(&b, this_->mRoomId, this_->mRoomHandle, 1, 0);
        if (fn_80388CAC(this_->mBuyerPlayer, this_->mRoomHandle)) {
            this_->mState = 0;
            this_->mBuyerPlayer = -1;
        }
        break;
    case 6:
        this_->mBuyerPlayer = -1;
        detach__5ActorFv(this_);
        break;
    }
    fn_801D1C18(&this_->mAnimSub);
}

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern void* lbl_8049CDA0[];
extern const f32 lbl_8053C36C;
extern const f32 lbl_8053C370;
extern const f32 lbl_8053C374;
extern const f32 lbl_8053C378;

// SHTM init (vtable slot 1)
extern "C" void fn_801091EC(ShtmActor* this_) {
    v01__5ActorFv(this_);
    this_->mBounds60.x0 = lbl_8053C36C;
    this_->mBounds60.y0 = lbl_8053C36C;
    this_->mBounds60.x1 = lbl_8053C370;
    this_->mBounds60.y1 = lbl_8053C370;
    this_->mBounds80.x0 = lbl_8053C36C;
    this_->mBounds80.y0 = lbl_8053C36C;
    this_->mBounds80.x1 = lbl_8053C370;
    this_->mBounds80.y1 = lbl_8053C370;
    this_->mSortPriority = 0;
    this_->mItemIndex = this_->mSpawnParam & 0xFF;
    this_->mPromptPos.x = this_->mPos.x;
    this_->mPromptPos.y = this_->mPos.y;
    this_->mPromptPos.z = this_->mPos.z;
    this_->mPromptPos.y -= lbl_8053C374;
    fn_801D2608(&this_->mAnimSub, lbl_8049CDA0, 8);
    fn_801D22DC(&this_->mAnimSub, this_->mItemIndex, 2, 0);
    fn_801D1F14(&this_->mAnimSub, lbl_8053C378);
}

struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_801D267C(void*);

class fn_801092B0_actor : public Actor {
public:
    fn_801092B0_actor();
};

fn_801092B0_actor::fn_801092B0_actor() : Actor() {
    ShtmActor* p = (ShtmActor*)this;
    p->mVtable = lbl_8049CDC0;
    fn_801D267C(&p->mAnimSub);
    p->mItemIndex = 8;
    p->mState = 0;
    p->mBuyerPlayer = -1;
    p->mField274 = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
