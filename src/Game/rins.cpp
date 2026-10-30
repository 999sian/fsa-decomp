// TU 0x803578d8-0x80357de8 — Actor 'RINS' (Log 'MRTA' Placement Switch Receptor).
#include "types.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AD220[];

struct RinsVec2 {
    f32 x, y;
    void add(const RinsVec2& o) {
        x += o.x;
        y += o.y;
    }
};
struct RinsBox2 {
    RinsVec2 i, f;
    void addPos(const RinsVec2& p) {
        i.add(p);
        f.add(p);
    }
};

struct MrtaLogActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ RinsVec2 mPosXY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ RinsBox2 mBounds60;
    /* 0x070 */ u8 _pad70[0x230 - 0x70];
    /* 0x230 */ s32 mState;
    /* 0x234 */ u8 _pad234[0x2D4 - 0x234];
    /* 0x2D4 */ JGeometry::TVec3<f32> mMoveVec;
};

class RinsActorV {
public:
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(int a, int b); virtual u8 s11();

    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ RinsBox2 mBounds60;
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ RinsBox2 mBounds80;
    /* 0x090 */ u8 _pad90[0x230 - 0x90];
    /* 0x230 */ s32 mState;
};

extern "C" void* fn_803578D8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AD220;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80357938(void) {}

extern "C" s32 fn_801F2718(void* actor, u32 type);
extern "C" void* fn_801F856C(void);
extern "C" MrtaLogActor* fn_801F666C(void* mgr, s32 id);

static inline bool rinsIsStill(MrtaLogActor* a) {
    if (a->mState == 0 && a->mMoveVec.isZero() == true) {
        return true;
    }
    return false;
}

static inline f32 rinsSqrt(f32 x) {
    if (x <= 0.0f)
        return x;
    f32 y = __frsqrte(x);
    y = 0.5f * y * (3.0f - (x * (y * y)));
    return x * y;
}

// RINS update (vtable slot 3): activates switch when 'MRTA' log rests at center
extern "C" void fn_8035793C(RinsActorV* p) {
    s32 id;
    id = fn_801F2718(p, 'MRTA');
    if (id >= 0) {
        MrtaLogActor* a = fn_801F666C(fn_801F856C(), id);
        if (a != NULL) {
            if (rinsIsStill(a) == true) {
                RinsBox2 box;
                RinsBox2* src = &a->mBounds60;
                box.i.x = src->i.x;
                box.i.y = src->i.y;
                box.f.x = src->f.x;
                box.f.y = src->f.y;
                box.addPos(a->mPosXY);
                f32 cx = 0.5f * (box.i.x - box.f.x) + box.f.x;
                f32 cy = 0.5f * (box.i.y - box.f.y) + box.f.y;
                f32 dx = p->mPosX - cx;
                f32 dy = p->mPosY - cy;
                f32 dx2 = dx * dx;
                f32 dy2 = dy * dy;
                if (rinsSqrt(dx2 + dy2) < 4.0f) {
                    if (!p->s11()) {
                        p->s10(0xff, 1);
                    }
                    return;
                }
            }
        }
    }
    if (p->s11() == 1) {
        p->s10(0xff, 0);
    }
}

// RINS init (vtable slot 1)
extern "C" void fn_80357B14(RinsActorV* p) {
    p->mBounds80.i.x = -12.0f;
    p->mBounds80.i.y = -12.0f;
    p->mBounds80.f.x = 12.0f;
    p->mBounds80.f.y = 12.0f;
    p->mBounds60.i.x = -12.0f;
    p->mBounds60.i.y = -12.0f;
    p->mBounds60.f.x = 12.0f;
    p->mBounds60.f.y = 12.0f;
    p->mPosX = 16.0f * (f32)((s32)p->mPosX / 16);
    p->mPosY = 16.0f * (f32)((s32)p->mPosY / 16);
    p->mState = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
