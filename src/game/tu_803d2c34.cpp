// TU 0x803d2c34-0x803d6434.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_803D5710.cpp ----
// vtable slot 2 (byte offset 8) - see [[reference_fsa_virtual_dispatch_codegen_trick]].
struct DtorSlot2 {
	virtual void destroy(s32 freeFlag);
};

extern "C" void getTotalFreeSize__7JKRHeapFv(void* p);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0288[];
extern u8 lbl_80529DEC[];
extern s32 lbl_8053ADB8;

static inline void DispatchSlot2(char* slot) {
	DtorSlot2* obj = *(DtorSlot2**)slot;
	if (obj != 0) {
		obj->destroy(1);
	}
	*(void**)slot = 0;
}

// fn_803D5710 - actor@lbl_804B0288: destructor (0x1D0). Standard
// DESTROYBASE template: manager-notify (getTotalFreeSize__7JKRHeapFv on
// lbl_80529DEC->0x8) first, then owned-sub-object teardown: singles at
// 0x4/0x8/0x14, a single+2-element-array pair (0x18 then 0x1c-0x20), a
// single (0x24), then another single+8-element-array pair (0x28 then
// 0x2c-0x48), finished by the standard "> 0 means also deallocate"
// conditional chain to __dl__FPv.
extern "C" void* fn_803D5710(void* this_, s16 how) {
	if (this_ != 0) {
		*(void**)this_ = lbl_804B0288;
		void* mgr = *(void**)(lbl_80529DEC + 0x8);
		getTotalFreeSize__7JKRHeapFv(mgr);

		char* t = (char*)this_;

		DispatchSlot2(t + 0x4);
		DispatchSlot2(t + 0x8);
		DispatchSlot2(t + 0x14);

		DispatchSlot2(t + 0x18);
		for (s32 i = 0; i < 2; i++) {
			DispatchSlot2(t + 0x1c + i * 4);
		}

		DispatchSlot2(t + 0x24);

		DispatchSlot2(t + 0x28);
		for (s32 j = 0; j < 8; j++) {
			DispatchSlot2(t + 0x2c + j * 4);
		}

		lbl_8053ADB8 = 0;
		if (how > 0) {
			__dl__FPv(this_);
		}
	}
	return this_;
}
