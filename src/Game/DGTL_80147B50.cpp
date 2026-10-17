#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" char __vt__4DGTL[];
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, s32 p);
extern "C" void __dl__FPv(void* p);
extern s32 lbl_80539F58;
extern s32 lbl_80539F5C;
extern "C" void* fn_80149A10(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4DGTL;
        char* p = this_;
        int i = 0;
        do {
            fn_801EE434(*(void**)(p + 0x798));
            i++;
            p += 4;
        } while (i < 10);
        i = 0;
        p = this_;
        do {
            fn_801EE434(*(void**)(p + 0x7c0));
            i++;
            p += 4;
        } while (i < 2);
        if (*(s32*)(this_ + 0x90) == 1) {
            lbl_80539F58 = -1;
        }
        if (*(s32*)(this_ + 0x90) == 0) {
            lbl_80539F5C = -1;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
