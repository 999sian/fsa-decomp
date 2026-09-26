// Game TU 801B6C50-801B7784 (GEWP). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A39DC[];
extern "C" {
}
extern void* lbl_8053AB10[2];

extern "C" void fn_801B6C50(void) {}

extern "C" void* fn_801B7324(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A39DC;
        char* p = (char*)this_;
        int i = 0;
        do {
            void* h = *(void**)(p + 0x294);
            fn_801EE434(h);
            i++;
            p += 4;
        } while (i < 4);
        dtor_801F593C(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8 fn_801B7550(void) {
	void* p1 = lbl_8053AB10[0];
	void* p2 = *(void**)((char*)p1 + 0x2c);
	return *(u8*)((char*)p2 + 0xc);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
