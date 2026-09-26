// TU 0x802BA048-0x802BA334: small actor (vtable lbl_804A8998): dtor, two
// empty overrides, a "remove when room flag set" hook, JAudio pool __sinit.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" u8* fn_802D6A9C(void);
extern "C" void detach__5ActorFv(void* this_);
extern void* lbl_804A8998[];

struct ActorV {
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10(s32 a, s32 b);

};

extern "C" void* fn_802BA048(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8998;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802BA0A8(void) {}

extern "C" void fn_802BA0AC(ActorV* this_) {
    if (fn_802D6A9C()[0x131de] != 0) {
        this_->s10(0xff, 1);
        detach__5ActorFv(this_);
    }
}

extern "C" void fn_802BA10C(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D26D4[0x94];
