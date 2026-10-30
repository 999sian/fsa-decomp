// TU 0x8029D430-0x8029D898 — Actor 'THCL' (Attached Player Hit/Collision Follower).
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct Vec3 { f32 x, y, z; };
struct Box { f32 x0, y0, x1, y1; };

struct ThclActor {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09();

    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ Vec3 mPos;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ Box mBounds60;
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ Box mBounds80;
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x110 - 0x94];
    /* 0x110 */ s32 mOwnerPlayer;
    /* 0x114 */ s32 mHitType;
    /* 0x118 */ u32 mField118;
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mTrackedPlayer; // Unpacked from spawnParam & 3
};

extern void* lbl_804A7C40[];
extern "C" void* fn_8029D430(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7C40;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" BOOL fn_8029D490(void) {
    return FALSE;
}

extern "C" void fn_8029D498(ThclActor* this_) {
    this_->mActiveFlag = 0;
}

extern "C" void fn_8029D4A4(void) {}

extern "C" Vec3* fn_8023E724(s32 player);
extern "C" u8 fn_80236BEC(s32 player);
extern "C" u8 fn_8022E438(s32 p, s32 q);
extern "C" u8 fn_8023B0F4(s32 player, Box* box, s32 room, s32 a, f32 f);
extern "C" void fn_80238548(s32 player, s32 a, Vec3* pos, s32 b);
extern "C" u8 fn_801F2B20(void* this_, s32 a);
extern u8* lbl_8053AAF8;

// THCL update (vtable slot 3)
extern "C" void fn_8029D4A8(ThclActor* this_) {
    Vec3* src = fn_8023E724(this_->mTrackedPlayer);
    this_->mPos.x = src->x;
    this_->mPos.y = src->y;
    this_->mPos.z = src->z;
    Box box;
    box.x0 = this_->mBounds60.x0;
    box.y0 = this_->mBounds60.y0;
    box.x1 = this_->mBounds60.x1;
    box.y1 = this_->mBounds60.y1;
    box.x0 += this_->mPos.x;
    box.y0 += this_->mPos.y;
    box.x1 += this_->mPos.x;
    box.y1 += this_->mPos.y;
    s32 val;
    if (lbl_8053AAF8[0x7f] != 0) {
        val = 0;
    } else {
        val = this_->mHitType;
    }
    for (s32 i = 0; i < 4; i++) {
        if (!fn_80236BEC(i) && !fn_8022E438(this_->mOwnerPlayer, i) &&
            !fn_8022E438(this_->mTrackedPlayer, i) &&
            fn_8023B0F4(i, &box, this_->mRoomId, 0, 0.0f)) {
            fn_80238548(i, val, &this_->mPos, 4);
            this_->s07();
            return;
        }
    }
    if (fn_801F2B20(this_, 0) || this_->mPos.z <= 0.0f) {
        this_->s07();
    }
}

// THCL init (vtable slot 1)
extern "C" void fn_8029D634(ThclActor* this_) {
    this_->mBounds60.x0 = -10.0f;
    this_->mBounds60.y0 = -10.0f;
    this_->mBounds60.x1 = 10.0f;
    this_->mBounds60.y1 = 10.0f;
    this_->mBounds80.x0 = -4.0f;
    this_->mBounds80.y0 = -4.0f;
    this_->mBounds80.x1 = 4.0f;
    this_->mBounds80.y1 = 4.0f;
    this_->mTrackedPlayer = this_->mSpawnParam & 3;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D08D4[0x94];
