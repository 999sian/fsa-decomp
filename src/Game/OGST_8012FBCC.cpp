// OGST_8012FBCC: .text 0x8012FBCC-0x8012FF9C — Actor 'OGST' ('OPGL' Gate Condition Node).
#include "types.h"

struct OgstActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x198 - 0x94];
    /* 0x198 */ u32 mActorHandle;
    /* 0x19C */ u32 mField19C;
    /* 0x1A0 */ u32 mActorFourCC; // 'OPGL' (0x4F50474C)
    /* 0x1A4 */ u8 _pad1A4[0x230 - 0x1A4];
    /* 0x230 */ u32 mConditionMask; // Unpacked from spawnParam & 0xF
};

extern "C" void v01__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* mgr, u32 id);
extern "C" OgstActor* fn_801F666C(void* mgr, s32 handle);
extern "C" void* fn_8012FF9C(void);
extern "C" void fn_801300B4(void* mgr, u32 v);
void operator delete(void* p);
extern void* lbl_8049EA00[];

extern "C" void* fn_8012FBCC(OgstActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_8049EA00;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8012FC2C(OgstActor* this_, s32* counts) {
    s32 h = fn_801F7A08(fn_801F856C(), 'OPGL');
    if (h < 0) {
        return 1;
    }
    OgstActor* obj = fn_801F666C(fn_801F856C(), h);
    if (obj == 0) {
        return 1;
    }
    if (obj->mActorFourCC != 'OPGL') {
        return 1;
    }
    u32 flags = this_->mConditionMask;
    if ((flags & 1) && counts[0] <= 0) {
        return 1;
    }
    if (((flags >> 1) & 1) && counts[0] >= 0) {
        return 1;
    }
    if (((flags >> 2) & 1) && counts[1] <= 0) {
        return 1;
    }
    if (((flags >> 3) & 1) && counts[1] >= 0) {
        return 1;
    }
    return 0;
}

// OGST init (vtable slot 1)
extern "C" void fn_8012FD34(OgstActor* this_) {
    v01__5ActorFv(this_);
    this_->mConditionMask = this_->mSpawnParam & 0xF;
    fn_801300B4(fn_8012FF9C(), this_->mActorHandle);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
