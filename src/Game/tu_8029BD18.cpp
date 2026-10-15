#include "types.h"


extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void fn_801F06F0(void* param_1, void* param_2, s32 param_3, s32 param_4, s32 param_5);
void operator delete(void* p);
extern void* lbl_804A7B90[];
extern void* lbl_8046C3E8[];
extern "C" void* fn_8029BD18(u8* param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A7B90;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8029BD78(u8* this_) {
    this_[0x11c] = 0;
}

extern "C" void fn_8029BD84(void* param_1) {
    fn_801F06F0(param_1, lbl_8046C3E8, 0x17e, 0, 0);
}

