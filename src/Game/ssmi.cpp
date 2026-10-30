// TU 0x80376394-0x80376850 — Actor 'TOMI' (Collision/Key Receiver Zone, misdecoded as SSMI in early CSV).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AE6D0[];

struct Key0Actor {
    u8 _pad00[0x40];
    f32 mVelY;       // +0x40
    u8 _pad44[0x240 - 0x44];
    s32 mCarryState; // +0x240
};

class SsmiActorV {
public:
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual u8 s11();

    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ f32 mVel[3];
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x198 - 0x94];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mSwitchGate; // Unpacked from spawnParam >> 27
    /* 0x234 */ s32 mMode;       // 0 = solid barrier, 1 = 'KEY0' catcher
};

extern "C" void* fn_80376394(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE6D0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8* fn_8020D58C(void);
extern "C" void fn_8020D7D0(void* slot, u32 id);
extern "C" s32 fn_801F8108(void* actor, u32 type, s32 p3, f32 range);
extern "C" void* fn_801F856C(void);
extern "C" Key0Actor* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_802C2BD0(void* actor);

// TOMI update (vtable slot 3)
extern "C" void fn_803763F4(SsmiActorV* p) {
    switch (p->mMode) {
    case 0:
        if (p->mSwitchGate == 0 || p->s11()) {
            u32 id = p->mRoomHandle;
            u8* sys = fn_8020D58C();
            fn_8020D7D0(sys + sys[0] * 0x784 + 4, id);
        }
        break;
    case 1: {
        s32 n = fn_801F8108(p, 'KEY0', -1, 32.0f);
        if (n >= 0) {
            Key0Actor* a = fn_801F666C(fn_801F856C(), n);
            if (a != NULL && a->mCarryState == 4 && a->mVelY < 0.0f) {
                fn_802C2BD0(a);
            }
        }
        break;
    }
    }
}

// TOMI init (vtable slot 1)
extern "C" void fn_803764D4(SsmiActorV* p) {
    p->mSwitchGate = p->mSpawnParam >> 27;
    p->mMode = (p->mSpawnParam >> 22) & 0x1F;
    p->mVel[0] = 0.0f;
    p->mVel[1] = 0.0f;
    p->mVel[2] = 0.0f;
    u32 flags = p->mSpawnParam;
    f32 w = (u32)(((flags & 0xFF) + 1) * 8);
    f32 h = (u32)((((flags >> 8) & 0xFF) + 1) * 8);
    if (p->mMode == 1) {
        h = 4.0f;
    }
    if ((flags >> 16) & 1) {
        p->mPosX += w;
        p->mPosY += h;
    } else {
        p->mPosX = w + (f32)((s32)p->mPosX / 16 * 16);
        p->mPosY = h + (f32)((s32)p->mPosY / 16 * 16);
    }
    p->mBounds80[0] = -w;
    p->mBounds80[1] = -h;
    p->mBounds80[2] = w;
    p->mBounds80[3] = h;
    if (p->mMode == 1) {
        p->mBounds60[0] = -w;
        p->mBounds60[1] = -h;
        p->mBounds60[2] = w;
        p->mBounds60[3] = h;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
