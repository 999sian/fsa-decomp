// Game TU 801DB18C-801DC264 (ICHL). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801CE0A4(void* this_);
extern "C" void fn_8013CB44(s32 handle, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801F0E34(void* target, u32 effectId, s32 flag);
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_801DAC6C(void);
extern "C" void fn_801DAEAC(void* singleton, s32 id);
extern void* lbl_804A4EE8[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void fn_801DB51C(void* this_) {
    fn_801CE0A4(this_);
    fn_8013CB44(*(s32*)((char*)this_ + 0x2e4), (char*)this_ + 0xc, 1, 0, 1);
}

extern "C" void fn_801DB560(void* this_) {
    char* p = (char*)this_;
    s32 before = *(s32*)(p + 0x280);
    fn_801CE4BC(this_);
    if (before == 8) {
        if (*(s32*)(p + 0x280) == 7) {
            fn_801F0E34(this_, 0x4005b, 0);
        }
    }
}

extern "C" void* fn_801DBEF4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4EE8;
        fn_801EE434(*(void**)(p + 0x2e4));
        *(s32*)(p + 0x2e4) = 0;
        if (*(s32*)(p + 0x16c) == -1) {
            void* singleton = fn_801DAC6C();
            fn_801DAEAC(singleton, *(s32*)(p + 0x198));
        }
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            dtor_801F593C(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
