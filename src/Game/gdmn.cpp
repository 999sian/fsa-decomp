// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80183544-80184040 (GDMN). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_80183C54_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A1790[];

extern "C" void* fn_80183C54(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1790;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x270));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/fn_80183C18.cpp
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801F5790(void* this_);

// fn_80183C18(this) - sibling of fn_8018316C (see that file's banner
// and project_fsa_80212af0_callers_closed.md) - another class's
// vtable-slot-0x18 override doing the identical "repel from RUSA
// zones, then chain to the generic slot-0x18 default" pattern.
extern "C" void fn_80183C18(void* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, (char*)this_ + 0xc);
    fn_801F5790(this_);
}

// from src/Game/Gdmn_StartTrigger.cpp
// GDMN's vtable-0x44 override. Identical shape to RIVR's own 0x44 override.
extern "C" {
void fn_80183CC0(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(s32*)(p + 0x258) != 0) return;
	if (*(s32*)(p + 0x230) == 5) return;
	*(u32*)(p + 0xb0) = 0x11101;
	*(u32*)(p + 0x254) = 0;
	*(u32*)(p + 0x230) = 4;
}
}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
