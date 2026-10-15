#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A8520[];
extern "C" void* fn_802B114C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8520;
        char* p = (char*)this_;
        void* h1 = *(void**)(p + 0x230);
        if (h1 != 0) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)(p + 0x234);
        if (h2 != 0) {
            fn_801EE434(h2);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}
