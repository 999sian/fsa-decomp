#include "types.h"

extern "C" void fn_801EE434(void*);
extern "C" void fn_8022ADCC(void);
extern "C" void fn_80134FC4(void*, s32);
extern "C" void fn_8037AE30(void*);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern char lbl_804A2AB0[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AD70;
extern u8 lbl_8053ABB0;
extern "C" void* fn_8019DEB4(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2AB0;
        char* p = this_;
        int i = 0;
        do {
            fn_801EE434(*(void**)(p + 0x260));
            i++;
            p += 4;
        } while (i < 2);
        if (*(s32*)(this_ + 0x248) == 1) {
            fn_8022ADCC();
            *(s32*)(this_ + 0x248) = 0;
            fn_80134FC4(lbl_8053AAF8, 0);
            lbl_8053ABB0 = 0;
            fn_8037AE30(lbl_8053AD70);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
