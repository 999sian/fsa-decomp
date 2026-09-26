// Game TU 801C26D8-801C5B08 (SLK2). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
extern void* lbl_804A46F4[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void* fn_801C0D70(void* this_);
extern "C" void fn_801C1374(void* subRecord, s32 flag);
extern "C" void fn_801F4F28(void* this_);
extern "C" {
}

extern "C" void fn_801C27F0(void* this_) {
    s32 flag = (*(u32*)((char*)this_ + 0x230) >> 27) & 1;
    void* subRecord = fn_801C0D70(this_);
    fn_801C1374(subRecord, flag);
    fn_801F4F28(this_);
}

extern "C" int fn_801C5340(void) { return 0; }

extern "C" bool fn_801C53C4(void* thisObj) {
	return ((*(u32*)((char*)thisObj + 0x230) & 0x40000) != 0 && *(u8*)((char*)thisObj + 0x55c) <= 20) ? true : false;
}

extern "C" void* dtor_801C5854(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A46F4;
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
