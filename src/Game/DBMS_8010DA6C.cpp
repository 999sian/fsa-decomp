// DBMS_8010DA6C: .text 0x8010DA6C-0x8010DF44 — Actor 'DBMS' (Animated Stage Object).
#include "types.h"

extern "C" void v06__5ActorFv(void* this_);
extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void* __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void*);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, s32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
void operator delete(void* p);

extern void* lbl_8049D0E8[];
extern void* lbl_8049CC34[];
extern const char lbl_80464348[];
extern u8 lbl_80539EF0[8];
extern const f32 lbl_8053C500;
extern const f32 lbl_8053C504;
extern const f32 lbl_8053C508;
extern const f32 lbl_8053C50C;

class DBMS_ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;

struct DBMS_Box {
    f32 x0, y0, x1, y1;
};

struct DbmsSub230 {
    /* 0x00 */ u8 _pad00[0x10];
    /* 0x10 */ s32 mAnimOffset; // +0x240 on DbmsActor
    /* 0x14 */ u8 _pad14[0x10];
    /* 0x24 */ void* mVtable;   // +0x254 on DbmsActor
};

struct DbmsActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ DBMS_Box mBounds60;
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ DBMS_Box mBounds80;
    /* 0x090 */ u8 _pad90[0x108 - 0x90];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x198 - 0x10C];
    /* 0x198 */ void* mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ DbmsSub230 mAnimSub;
};

extern "C" void* fn_8010DA6C(DbmsActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_8049D0E8;
        if (&this_->mAnimSub != 0) {
            if (&this_->mAnimSub.mVtable != 0) {
                this_->mAnimSub.mVtable = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// DBMS draw (vtable slot 6)
extern "C" void fn_8010DAEC(DbmsActor* this_) {
    v06__5ActorFv(this_);
    s32 id = this_->mAnimSub.mAnimOffset + 0x386;
    void* pos = &this_->mPosX;
    if (this_->mRoomId < 8) {
        void* res = (*(DBMS_ResMgr**)(lbl_8053AAF8 + 0xA4))->vf18('SOB ', lbl_80464348);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053C500, lbl_8053C500, 0);
    }
    fn_803075AC(this_->mRoomHandle, this_->mRoomId, &this_->mPosX,
                this_->mAnimSub.mAnimOffset + 0x386, 0, 1, -1, 0, 0, 0);
}

// DBMS update (vtable slot 3)
extern "C" void fn_8010DBC0(DbmsActor* this_) {
    v03__5ActorFv(this_);
    DBMS_Box b;
    b.x0 = this_->mBounds60.x0;
    b.y0 = this_->mBounds60.y0;
    b.x1 = this_->mBounds60.x1;
    b.y1 = this_->mBounds60.y1;
    b.x0 += this_->mPosX;
    b.y0 += this_->mPosY;
    b.x1 += this_->mPosX;
    b.y1 += this_->mPosY;
    fn_80239914(&b, this_->mRoomId, this_->mRoomHandle);
    fn_801D1C18(&this_->mAnimSub);
}

// DBMS init (vtable slot 1)
extern "C" void fn_8010DC4C(DbmsActor* this_) {
    v01__5ActorFv(this_);
    this_->mBounds60.x0 = lbl_8053C504;
    this_->mBounds60.y0 = lbl_8053C504;
    this_->mBounds60.x1 = lbl_8053C508;
    this_->mBounds60.y1 = lbl_8053C508;
    this_->mBounds80.x0 = lbl_8053C50C;
    this_->mBounds80.y0 = lbl_8053C50C;
    this_->mBounds80.x1 = lbl_8053C50C;
    this_->mBounds80.y1 = lbl_8053C50C;
    this_->mSortPriority = 0;
    fn_801D2608(&this_->mAnimSub, lbl_80539EF0, 1);
    fn_801D22DC(&this_->mAnimSub, 0, 2, 0);
    fn_801D1F14(&this_->mAnimSub, lbl_8053C50C);
}

struct Actor {
    Actor();
    ~Actor();
};

class Dbms : public Actor {
public:
    Dbms();
};

Dbms::Dbms() : Actor() {
    DbmsActor* p = (DbmsActor*)this;
    p->mVtable = lbl_8049D0E8;
    fn_801D267C(&p->mAnimSub);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
