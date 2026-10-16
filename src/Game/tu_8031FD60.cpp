#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804AB2B0[];
extern u8* lbl_8053AAF8;
extern f32 lbl_80541AA0;
extern f32 lbl_80541AC8;
extern "C" void* fn_8031FD60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB2B0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
