// TU 0x802233a4-0x802242f4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_80223534.cpp ----
extern "C" void fn_80221184(void* this_);
extern "C" void* fn_8013C824();
extern "C" void fn_800EC240(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);
extern "C" void* fn_801EE434(void* handle);

extern "C" void fn_80223534(void* this_) {
    fn_80221184(this_);
    char* p = (char*)this_;
    if (*(u32*)(p + 0x2b8) != 0) {
        void* base = fn_8013C824();
        fn_800EC240(*(void**)((char*)base + 0xc), *(s32*)(p + 0x2b8));
        *(s32*)(p + 0x2b8) = 0;
    }
    fn_801CDC8C(this_, 0x4000E);
    fn_801EE434(*(void**)(p + 0x2bc));
    fn_801EE434(*(void**)(p + 0x2c0));
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2c0) = 0;
}

// ---- fn_80223F90_dtor.cpp ----
extern "C" void* fn_8013C824();
extern "C" void fn_800EC240(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6D00[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80223F90(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6D00;
        if (*(u32*)(p + 0x2b8) != 0) {
            void* base = fn_8013C824();
            fn_800EC240(*(void**)((char*)base + 0xc), *(s32*)(p + 0x2b8));
            *(s32*)(p + 0x2b8) = 0;
        }
        fn_801CDC8C(this_, 0x4000E);
        fn_801EE434(*(void**)(p + 0x2bc));
        fn_801EE434(*(void**)(p + 0x2c0));
        *(s32*)(p + 0x2bc) = 0;
        *(s32*)(p + 0x2c0) = 0;
        if (this_ != 0) {
            *(void**)p = lbl_804A6A00;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_80224084_ctor.cpp ----
extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6D00[];

extern "C" void* fn_80224084(void* this_) {
    fn_802218C8(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A6D00;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2c0) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
