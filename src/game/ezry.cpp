// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80160650-801618D0 (EZRY). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_80161638_dtor.cpp
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A03B8[];

extern "C" void* fn_80161638(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A03B8;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x290));
        fn_801EE434(*(void**)(p + 0x294));
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/Fary_SyncEmberEffectPosition.cpp
// FARY actor cluster, part 4/5. If this->0x290 is set, copies this->0xc/
// 0x10/0x14 (position) into that sub-object's own +0xa4/+0xa8/+0xac
// fields. Does the identical copy for this->0x294 if set. A simple "keep
// both flame/ember effect sub-objects synced to my position" helper.
extern "C" {

void fn_801615EC(void* thisPtr) {
	char* p = (char*)thisPtr;
	void* a = *(void**)(p + 0x290);
	if (a != 0) {
		*(f32*)((char*)a + 0xa4) = *(f32*)(p + 0xc);
		*(f32*)((char*)a + 0xa8) = *(f32*)(p + 0x10);
		*(f32*)((char*)a + 0xac) = *(f32*)(p + 0x14);
	}
	void* b = *(void**)(p + 0x294);
	if (b == 0) return;
	*(f32*)((char*)b + 0xa4) = *(f32*)(p + 0xc);
	*(f32*)((char*)b + 0xa8) = *(f32*)(p + 0x10);
	*(f32*)((char*)b + 0xac) = *(f32*)(p + 0x14);
}

}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
