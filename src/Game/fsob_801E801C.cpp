// Game TU 801E801C-801E9AFC (FSOB). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A5568[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" {
}

extern "C" int fn_801E90BC(void) { return 0; }

extern "C" void* fn_801E97B4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5568;
        fn_801EE434(*(void**)(p + 0x3c0));
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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
