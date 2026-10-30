// TU 0x802f43c0-0x802f4820 — Actor 'TBO2' (Static Pot / Obstacle Object).
#include "Game/esd/types.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA750[];

struct Tbo2Vec {
    f32 x, y, z;
    Tbo2Vec(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
};
struct Tbo2Pt { f32 x, y; };
struct Tbo2Box { Tbo2Pt min, max; Tbo2Box(const Tbo2Pt& a, const Tbo2Pt& b) : min(a), max(b) {} };

struct Tbo2Actor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x80 - 0x18];
    /* 0x080 */ Tbo2Pt mHitMin;
    /* 0x088 */ Tbo2Pt mHitMax;
    /* 0x090 */ u8 _pad90[0x198 - 0x90];
    /* 0x198 */ u32 mRoomHandle;
};

extern "C" void* fn_802F43C0(Tbo2Actor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804AA750;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

struct Tbo2ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
extern const f32 lbl_805414D0;
extern const f32 lbl_805414D4;
extern const f32 lbl_805414D8;
extern const char lbl_8046F928[];
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern "C" void fn_802F86CC(void* map, Tbo2Vec* pos, void* res, f32 a, f32 b, s32 id, s32 c);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, Tbo2Vec* pos, s32 effectRef, s32 flag,
                            s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);

// TBO2 draw (vtable slot 6): renders 'SOB ' sprite 0x21 on TV and GBA
extern "C" void fn_802F4420(Tbo2Actor* p) {
    Tbo2Vec a(p->mPosX, p->mPosY - lbl_805414D0, lbl_805414D4);
    if (p->mRoomId < 8) {
        void* res = (*(Tbo2ResMgr**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_8046F928);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &a, res, lbl_805414D8, lbl_805414D8, 0x21, 0);
    }
    Tbo2Vec b(p->mPosX, p->mPosY - lbl_805414D0, lbl_805414D4);
    fn_803075AC(p->mRoomHandle, p->mRoomId, &b, 0x21, 0, 2, -1, 0, 0, 0);
}

extern const f32 lbl_805414DC;
extern const f32 lbl_805414E0;
extern "C" void fn_80239914(Tbo2Box* box, u32 room, u32 id);
extern "C" u8* fn_8020D58C();
extern "C" void fn_8020D7D0(void* slot, u32 id);

// TBO2 update (vtable slot 3)
extern "C" void fn_802F4510(Tbo2Actor* p) {
    p->mHitMin.x = lbl_805414DC;
    p->mHitMin.y = lbl_805414DC;
    p->mHitMax.x = lbl_805414E0;
    p->mHitMax.y = lbl_805414E0;
    Tbo2Box box(p->mHitMin, p->mHitMax);
    f32 x = p->mPosX;
    f32 y = p->mPosY;
    box.min.x += x;
    box.min.y += y;
    box.max.x += x;
    box.max.y += y;
    fn_80239914(&box, p->mRoomId, p->mRoomHandle);
    u32 id = p->mRoomHandle;
    u8* mgr = fn_8020D58C();
    fn_8020D7D0(mgr + 4 + mgr[0] * 0x784, id);
}

// TBO2 init (vtable slot 1)
extern "C" void fn_802F45DC(Tbo2Actor* p) {
    p->mPosX += lbl_805414E0;
    p->mPosY += lbl_805414E0;
}

#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
