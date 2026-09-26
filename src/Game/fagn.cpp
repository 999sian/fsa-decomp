// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80184040-80184D64 (FAGN). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_80184040_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A1888[];

extern "C" void* fn_80184040(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1888;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/fn_80184A14.cpp
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801F5790(void* this_);

// fn_80184A14(this) - sibling of fn_8018316C (see that file's banner
// and project_fsa_80212af0_callers_closed.md) - a third class's
// vtable-slot-0x18 override doing the identical "repel from RUSA
// zones, then chain to the generic slot-0x18 default" pattern.
extern "C" void fn_80184A14(void* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, (char*)this_ + 0xc);
    fn_801F5790(this_);
}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
