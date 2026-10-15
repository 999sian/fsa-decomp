// TU 0x8020b354-0x8020c0a8 (actor FOBR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- Fobr_ctor_8020BE40.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A5E98[];

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_8020B354(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5E98;
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

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_802075D8(void*, u16);
extern "C" void v07__5ActorFv(void*);
extern "C" void fn_8020B74C(u8* this_) {
    void* actor = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2A8));
    if (actor != 0) {
        fn_802075D8(actor, *(u16*)(this_ + 0x94));
    }
    v07__5ActorFv(this_);
}

extern "C" void fn_8020BCE4(char* this_) {
    *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x24);
    *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28);
    *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x2c);
}

extern "C" void* fn_8020BE40(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A5E98;
    *(s32*)((char*)this_ + 0x2a8) = -1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
