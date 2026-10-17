#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

extern "C" void fn_801F06F0(void* this_, void* name, s32 a, s32 b, s32 c, f32 x, f32 y);
extern f32 lbl_80540710;
extern char lbl_8046C3E8[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A7B90[];

extern "C" void* fn_8029BD18(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7B90;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8029BD78(u8* this_) {
    this_[0x11c] = 0;
}

extern "C" void fn_8029BD84(void* this_) {
    fn_801F06F0(this_, lbl_8046C3E8, 0x17e, 0, 0, 1.0f, 1.0f);
}


