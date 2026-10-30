// IWAG_800F46C0: .text 0x800F46C0-0x800F4C70 — Actor 'IWAG' (Falling Rock 'OIWA' Spawner).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C46C[];

struct OiwaRockActor {
    u8 _pad00[0x3C];
    JGeometry::TVec3f mVel; // +0x3C
};

class IWAG_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C(); virtual void vf30();
    virtual u8 vf34();

    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3f mPos;
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ u8 mSpawnMode;   // 0..4 rock spawn pattern
    /* 0x231 */ u8 _pad231[3];
    /* 0x234 */ s32 mSpawnTimer; // Countdown between 'OIWA' spawns
};

extern "C" void* fn_800F46C0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C46C;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_800F4720(void) {}

struct IWAG_Random {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct IWAG_Game { u8 pad[0xb4]; IWAG_Random rnd; };
extern IWAG_Game* lbl_8053AAF8;

extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern "C" OiwaRockActor* fn_801F666C(void* mgr, s32 id);

// IWAG update (vtable slot 3): periodically spawns 'OIWA' boulders
extern "C" void fn_800F4724(IWAG_Actor* this_) {
    JGeometry::TVec3f pos;
    if (this_->mSpawnTimer == 0) {
        switch (this_->mSpawnMode) {
        case 0:
            if ((this_->mSpawnParam & 0xF8000000) && !this_->vf34()) {
                return;
            }
            Actor_CreateByID(fn_801F856C(), 'OIWA', this_->mRoomId, &this_->mPos, 0, -1, -1);
            this_->mSpawnTimer = (s32)(50.0f * lbl_8053AAF8->rnd.get()) + 150;
            break;
        case 1: {
            if ((this_->mSpawnParam & 0xF8000000) && !this_->vf34()) {
                return;
            }
            pos = this_->mPos;
            pos.z += 200.0f;
            s32 id = Actor_CreateByID(fn_801F856C(), 'OIWA', this_->mRoomId, &pos, 1, -1, -1);
            OiwaRockActor* rock = fn_801F666C(fn_801F856C(), id);
            rock->mVel = JGeometry::TVec3f(0.0f, -0.01f, 0.0f);
            this_->mSpawnTimer = (s32)(50.0f * lbl_8053AAF8->rnd.get()) + 150;
            break;
        }
        case 2:
            Actor_CreateByID(fn_801F856C(), 'OIWA', this_->mRoomId, &this_->mPos, 3, -1, -1);
            this_->mActiveFlag = 0;
            return;
        case 3:
            Actor_CreateByID(fn_801F856C(), 'OIWA', this_->mRoomId, &this_->mPos, (this_->mSpawnParam & ~0xFF) + 4, -1, -1);
            this_->mSpawnTimer = (s32)(50.0f * lbl_8053AAF8->rnd.get()) + 150;
            break;
        case 4: {
            if ((this_->mSpawnParam & 0xF8000000) && !this_->vf34()) {
                return;
            }
            pos.x = this_->mPos.x;
            pos.y = this_->mPos.y;
            pos.z = this_->mPos.z;
            pos.z += 200.0f;
            pos.x += 0x28 - (s32)(20.0f * lbl_8053AAF8->rnd.get());
            IWAG_Game* g = lbl_8053AAF8;
            pos.y += 0x14 - (s32)(10.0f * g->rnd.get());
            Actor_CreateByID(fn_801F856C(), 'OIWA', this_->mRoomId, &pos, 5, -1, -1);
            this_->mSpawnTimer = (s32)(150.0f * lbl_8053AAF8->rnd.get()) + 0x50;
            break;
        }
        }
    }
    this_->mSpawnTimer -= 1;
}

// IWAG init (vtable slot 1)
extern "C" void fn_800F4B90(IWAG_Actor* this_) {
    this_->mSpawnMode = this_->mSpawnParam;
    if (this_->mSpawnMode == 2) {
        this_->mSpawnTimer = 0;
    } else if (this_->mSpawnMode == 4) {
        this_->mSpawnTimer = 100.0f * lbl_8053AAF8->rnd.get();
    } else {
        this_->mSpawnTimer = 30.0f * lbl_8053AAF8->rnd.get();
    }
}

void fn_800FA85C(void) {
    return;
}

extern void* lbl_804B928C[];
extern "C" void fn_800F52AC(void) {
}
