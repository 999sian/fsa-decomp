// TU 0x80377e20-0x80378294 — Actor 'ENDR' (Rectangular Player Trigger Zone).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AE830[];

struct EndrVec { f32 x, y, z; };

struct EndrActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ f32 mBounds60[4]; // x0, y0, x1, y1
    /* 0x070 */ u8 _pad70[0x90 - 0x70];
    /* 0x090 */ u32 mSpawnParam;
};

extern "C" void* fn_80377E20(EndrActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804AE830;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" EndrVec* fn_8023E724(s32 player);
extern "C" void fn_80230050(s32 player);

// ENDR update (vtable slot 3)
extern "C" void fn_80377E80(EndrActor* p) {
    f32 x0 = p->mBounds60[0];
    f32 y0 = p->mBounds60[1];
    f32 x1 = p->mBounds60[2];
    f32 y1 = p->mBounds60[3];
    x0 += p->mPosX;
    x1 += p->mPosX;
    y0 += p->mPosY;
    y1 += p->mPosY;
    for (s32 i = 0; i < 4; i++) {
        EndrVec* v = fn_8023E724(i);
        f32 x = v->x;
        f32 y = v->y;
        u8 in = false;
        if (x >= x0 && y >= y0 && x < x1 && y < y1) {
            in = true;
        }
        if (in == true) {
            fn_80230050(i);
        }
    }
}

// ENDR init (vtable slot 1)
extern "C" void fn_80377F70(EndrActor* p) {
    u32 flags = p->mSpawnParam;
    f32 w = (u32)(((flags & 0xFF) + 1) * 8);
    f32 h = (u32)((((flags >> 8) & 0xFF) + 1) * 8);
    if ((flags >> 16) & 1) {
        p->mPosX += w;
        p->mPosY += h;
    } else {
        p->mPosX = w + (f32)((s32)p->mPosX / 16 * 16);
        p->mPosY = h + (f32)((s32)p->mPosY / 16 * 16);
    }
    p->mBounds60[0] = -w;
    p->mBounds60[1] = -h;
    p->mBounds60[2] = w;
    p->mBounds60[3] = h;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
