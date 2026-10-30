// TU 0x80222cc4-0x802233a4 — Dodongo ('DDGO') Spawner/Controller Enemy (derived from Base_802218C8).
#include "types.h"

extern "C" {
void fn_801CDD58();
void fn_801CE120();
void fn_801CE4BC();
void fn_801CE4E4();
void fn_801CE594();
void fn_801CE694();
void fn_801CE914();
void fn_801CE918();
void fn_801CE920();
void fn_801CE928();
void fn_801CE98C();
void fn_801CEB78();
void fn_801CECEC();
void fn_801D0ECC();
void fn_80220F54();
void fn_80221114();
void fn_80221158();
void fn_80221160();
void fn_80221210();
void v02__5ActorFv();
void v04__5ActorFv();
void v05__5ActorFv();
void v07__5ActorFv();
void v08__5ActorFv();
void v09__5ActorFv();
void v10__5ActorFUlUl();
void v11__5ActorFv();
void v12__5ActorFv();
void v13__5ActorFv();
void v14__5ActorFv();
void v15__5ActorFv();
void v16__5ActorFv();
void v17__5ActorFiPf();
void v18__5ActorFiPf();
}
extern "C" void* fn_80223060(void* this_, s16 freeFlag);
extern "C" void fn_80222FF0(void* this_);
extern "C" void fn_80222CC4(void* this_);
extern "C" void fn_80222D28(void* this_);
extern "C" void fn_80222D5C(void* this_);
void* lbl_804A6C38[] = {
    0,
    0,
    (void*)fn_80223060,
    (void*)fn_80222FF0,
    (void*)v02__5ActorFv,
    (void*)fn_801CDD58,
    (void*)v04__5ActorFv,
    (void*)v05__5ActorFv,
    (void*)fn_80220F54,
    (void*)v07__5ActorFv,
    (void*)v08__5ActorFv,
    (void*)v09__5ActorFv,
    (void*)v10__5ActorFUlUl,
    (void*)v11__5ActorFv,
    (void*)v12__5ActorFv,
    (void*)v13__5ActorFv,
    (void*)v14__5ActorFv,
    (void*)v15__5ActorFv,
    (void*)v16__5ActorFv,
    (void*)v17__5ActorFiPf,
    (void*)v18__5ActorFiPf,
    (void*)fn_801D0ECC,
    (void*)fn_801CECEC,
    (void*)fn_801CEB78,
    (void*)fn_80221158,
    (void*)fn_801CE98C,
    (void*)fn_801CE928,
    (void*)fn_80222CC4,
    (void*)fn_801CE920,
    (void*)fn_80221160,
    (void*)fn_801CE918,
    (void*)fn_801CE914,
    (void*)fn_801CE694,
    (void*)fn_801CE594,
    (void*)fn_80222D28,
    (void*)fn_801CE4E4,
    (void*)fn_80222D5C,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_80221210,
    (void*)fn_80221114,
};

struct DdgoSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on DdgoHostActor
    u8 _pad28[0x10];
};

struct DdgoChildActor {
    u8 _pad00[0x98];
    s32 mFacingDir;    // +0x98
    u8 _pad9C[0x108 - 0x9C];
    s32 mSortPriority; // +0x108
};

struct DdgoHostActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x44 - 0x18];
    /* 0x044 */ f32 mVelZ;
    /* 0x048 */ u8 _pad48[0x90 - 0x48];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u32 mField94;
    /* 0x098 */ s32 mFacingDir;
    /* 0x09C */ u8 _pad9C[0x230 - 0x9C];
    /* 0x230 */ u32 mItemFlags;
    /* 0x234 */ u8 _pad234[0x248 - 0x234];
    /* 0x248 */ s32 mState;
    /* 0x24C */ s32 mStateTimer;
    /* 0x250 */ s32 mStateDuration;
    /* 0x254 */ f32 mSpeedX;
    /* 0x258 */ f32 mSpeedY;
    /* 0x25C */ u8 _pad25C[0x270 - 0x25C];
    /* 0x270 */ DdgoSub270 mAnimSub;
    /* 0x2A8 */ u8 _pad2A8[0x2B8 - 0x2A8];
    /* 0x2B8 */ s32 mChildDdgoId; // Handle to spawned 'DDGO' actor (-1 = none)
};

extern "C" void fn_80221184(void* this_);
extern "C" void* fn_801F856C();
extern "C" DdgoChildActor* fn_801F666C(void* base, s32 id);

extern "C" void fn_80222CC4(void* this_) {
    fn_80221184(this_);
    DdgoHostActor* p = (DdgoHostActor*)this_;
    s32 id = p->mChildDdgoId;
    if (id >= 0) {
        void* base = fn_801F856C();
        DdgoChildActor* found = fn_801F666C(base, id);
        if (found != 0) {
            found->mSortPriority = 0;
        }
        p->mChildDdgoId = -1;
    }
}

extern "C" void fn_80221250(void* this_);
extern "C" void fn_801CE4E8(void* this_);

extern "C" void fn_80222D28(void* this_) {
    s32 state = ((DdgoHostActor*)this_)->mState;
    if (state == 2) {
        fn_80221250(this_);
    } else {
        fn_801CE4E8(this_);
    }
}

struct Vec_80222CC4 {
    Vec_80222CC4(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
    f32 x, y, z;
};

extern "C" {
extern const f32 lbl_8053FE70;
void fn_80221408(void* this_);
void fn_80221334(void* this_);
void fn_802212AC(void* this_);
void fn_802216E8(void* this_, s32 t);
void fn_8022149C(void* this_, s32 a);
void fn_802217C8(void* this_);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);
u8 fn_801D21F0(void* anim);
s32 Actor_CreateByID(void* mgr, u32 id, u32 arg, Vec_80222CC4* pos, u32 arg2, s32 a, s32 b);

void fn_80222D5C(void* this_) {
    DdgoHostActor* p = (DdgoHostActor*)this_;
    switch ((u32)p->mState) {
    case 0:
        fn_80221408(this_);
        break;
    case 1:
        fn_80221334(this_);
        break;
    case 2:
        fn_802212AC(this_);
        break;
    case 3:
        if (p->mStateTimer >= 0x78) {
            fn_801D22DC(&p->mAnimSub, p->mFacingDir + 0x10, 0, 0);
            p->mStateTimer = 0;
            p->mState = 5;
        }
        break;
    case 4:
        fn_802216E8(this_, 0x78);
        if (p->mPosZ <= 0.0f) {
            if (p->mItemFlags & 0x2000) {
                fn_801D22DC(&p->mAnimSub, p->mFacingDir + 0x10, 0, 0);
                p->mStateTimer = 0;
                p->mState = 5;
            } else {
                p->mVelZ = lbl_8053FE70;
            }
        }
        break;
    case 5:
        if (p->mStateTimer > 1 && fn_801D21F0(&p->mAnimSub)) {
            Vec_80222CC4 pos(p->mPosX, p->mPosY, 0.0f);
            switch (p->mFacingDir) {
            case 0:
                pos.x += 24.0f;
                break;
            case 1:
                pos.x -= 24.0f;
                break;
            case 2:
                pos.x += 4.0f;
                pos.y += 22.0f;
                break;
            case 3:
                pos.x -= 4.0f;
                pos.y -= 26.0f;
                break;
            }
            p->mChildDdgoId = Actor_CreateByID(fn_801F856C(), 'DDGO', p->mRoomId, &pos, 1, -1, -1);
            s32 id = p->mChildDdgoId;
            if (id >= 0) {
                DdgoChildActor* found = fn_801F666C(fn_801F856C(), id);
                if (found != 0) {
                    found->mFacingDir = p->mFacingDir;
                }
            }
            p->mStateTimer = 0;
            p->mState = 6;
        }
        break;
    case 6:
        if (p->mStateTimer >= 0xb4) {
            s32 id = p->mChildDdgoId;
            if (id >= 0) {
                DdgoChildActor* found = fn_801F666C(fn_801F856C(), id);
                if (found != 0) {
                    found->mSortPriority = 0;
                }
                p->mChildDdgoId = -1;
            }
            fn_801D22DC(&p->mAnimSub, p->mFacingDir, 0, 0);
            p->mStateTimer = 0;
            p->mState = 7;
        }
        break;
    case 7:
        if (p->mStateTimer >= 0x78) {
            fn_8022149C(this_, 1);
        }
        break;
    }
}

void fn_80222FF0(void* this_) {
    DdgoHostActor* p = (DdgoHostActor*)this_;
    fn_802217C8(this_);
    p->mFacingDir = p->mSpawnParam & 3;
    p->mState = 4;
    p->mStateTimer = 0;
    p->mStateDuration = -1;
    p->mSpeedX = 0.0f;
    p->mSpeedY = 0.0f;
    fn_801D22DC(&p->mAnimSub, 2, 0, 0);
}
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6C38[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80223060(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        DdgoHostActor* p = (DdgoHostActor*)this_;
        p->mVtable = lbl_804A6C38;
        s32 id = p->mChildDdgoId;
        if (id >= 0) {
            void* base = fn_801F856C();
            DdgoChildActor* found = fn_801F666C(base, id);
            if (found != 0) {
                found->mSortPriority = 0;
            }
            p->mChildDdgoId = -1;
        }
        if (this_ != 0) {
            p->mVtable = lbl_804A6A00;
            if (this_ != 0) {
                p->mVtable = lbl_804A4808;
                if (&p->mAnimSub != 0) {
                    if (&p->mAnimSub.mVtable != 0) {
                        p->mAnimSub.mVtable = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* fn_802218C8(void* this_);

extern "C" void* fn_8022313C(DdgoHostActor* this_) {
    fn_802218C8(this_);
    this_->mVtable = lbl_804A6C38;
    this_->mChildDdgoId = -1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
