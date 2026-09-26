// Game TU 801B4D0C-801B6634 (TLWP). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void* fn_8013C824(void);
extern "C" void fn_800EC240(void* a, void* b);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A38D4[];

extern "C" void* fn_801B609C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A38D4;
        char* p = (char*)this_;
        int i = 0;
        do {
            if (*(void**)(p + 0x294)) {
                void* base = fn_8013C824();
                void* a = *(void**)((char*)base + 0xc);
                fn_800EC240(a, *(void**)(p + 0x294));
                *(void**)(p + 0x294) = 0;
            }
            i++;
            p += 4;
        } while (i < 3);
        p = (char*)this_;
        int j = 0;
        do {
            if (*(void**)(p + 0x2a0)) {
                void* base = fn_8013C824();
                void* a = *(void**)((char*)base + 0xc);
                fn_800EC240(a, *(void**)(p + 0x2a0));
                *(void**)(p + 0x2a0) = 0;
            }
            j++;
            p += 4;
        } while (j < 0x14);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
