// Game TU 801D7AFC-801D8400 (BGBL). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A4BB0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);

extern "C" void* fn_801D80F0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4BB0;
        fn_801EE434(*(void**)(p + 0x2a8));
        fn_801EE434(*(void**)(p + 0x2ac));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801D8194(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4BB0;
    *(int*)((char*)this_ + 0x2a8) = 0;
    *(int*)((char*)this_ + 0x2ac) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
