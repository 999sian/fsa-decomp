// TU 0x80376b4c-0x80376fa0 — Actor 'PTMI' (Switch-Gated Rectangular Collision Box).
#include "types.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AE780[];

class PtmiActorV {
public:
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual u8 s11();

    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec2<f32> mPosXY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ f32 mVel[3];
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ JGeometry::TBox2<f32> mBounds60;
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ JGeometry::TBox2<f32> mBounds80;
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x198 - 0x94];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mSwitchGate; // Unpacked from spawnParam >> 27
};

extern "C" void* fn_80376B4C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE780;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80239914(JGeometry::TBox2<f32>* box, u32 id, u32 p3);

// PTMI update (vtable slot 3)
extern "C" void fn_80376BAC(PtmiActorV* p) {
    if (p->mSwitchGate == 0 || p->s11()) {
        JGeometry::TBox2<f32> box = p->mBounds60;
        box.addPos(p->mPosXY);
        fn_80239914(&box, p->mRoomId, p->mRoomHandle);
    }
}

static inline u32 ptmiMode(PtmiActorV* p) { return p->mSpawnParam >> 27; }

// PTMI init (vtable slot 1)
extern "C" void fn_80376C50(PtmiActorV* p) {
    p->mVel[0] = 0.0f;
    p->mVel[1] = 0.0f;
    p->mVel[2] = 0.0f;
    u32 flags = p->mSpawnParam;
    f32 w = (u32)(((flags & 0xFF) + 1) * 8);
    f32 h = (u32)((((flags >> 8) & 0xFF) + 1) * 8);
    if ((flags >> 16) & 1) {
        p->mPosXY.x += w;
        p->mPosXY.y += h;
    } else {
        p->mPosXY.x = w + (f32)((s32)p->mPosXY.x / 16 * 16);
        p->mPosXY.y = h + (f32)((s32)p->mPosXY.y / 16 * 16);
    }
    p->mBounds60.i.x = -w;
    p->mBounds60.i.y = -h;
    p->mBounds60.f.x = w;
    p->mBounds60.f.y = h;
    p->mBounds80.i.x = -w;
    p->mBounds80.i.y = -h;
    p->mBounds80.f.x = w;
    p->mBounds80.f.y = h;
    p->mSwitchGate = ptmiMode(p);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
