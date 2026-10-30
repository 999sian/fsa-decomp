// ICOB_8012F8AC: .text 0x8012F8AC-0x8012FBCC — Actor 'ICOB' (Ice Block / Condition Trigger).
#include "types.h"

extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void* fn_8012F554(void);
extern "C" u8 fn_8012F3E4(void* mgr);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern void* lbl_8049E9A8[];

class ICOB_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C();
    virtual void vf30(s32, s32);

    /* 0x004 */ u8 _pad04[0x230 - 0x04];
    /* 0x230 */ s32 mState; // 0 = waiting for condition, 1 = triggered
};

extern "C" void* fn_8012F8AC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E9A8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8012F90C(ICOB_Actor* this_) {
    v03__5ActorFv(this_);
    switch (this_->mState) {
    case 0:
        if (fn_8012F3E4(fn_8012F554())) {
            this_->vf30(0xFF, 1);
            this_->mState = 1;
        }
        break;
    case 1:
        break;
    }
}

extern "C" void fn_8012F988(ICOB_Actor* this_) {
    v01__5ActorFv(this_);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
