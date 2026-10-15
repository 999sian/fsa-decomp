#include "types.h"


void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AF018[];
extern f32 lbl_80543090;
extern "C" void* fn_8037D784(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF018;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8037DD38(u8* this_) {
    this_[0x11c] = 0;
}
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804AF018[];
extern f32 lbl_80543090;
