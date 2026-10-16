#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void v01__5ActorFv(void* this_);
void operator delete(void* p);
extern "C" char lbl_8049EA88[];
extern const f32 lbl_8053CC94;
extern const f32 lbl_8053CC98;
extern "C" void* fn_80130310(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_8049EA88;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
