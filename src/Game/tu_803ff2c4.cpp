// TU 0x803ff2c4-0x80400dc4.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_804007C4.cpp ----
// vtable slot 2 (byte offset 8) - see [[reference_fsa_virtual_dispatch_codegen_trick]].
struct DtorSlot2 {
	virtual void destroy(s32 freeFlag);
};

// manager sub-object with 2 virtual slots (dummy v0 at offset 8, real
// slot1 at offset 0xc) - same shape as fn_803A87A8's SlotB.
struct SlotB {
	virtual void v0();
	virtual void slot1();
};

extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0F50[];
extern u8 lbl_80529DEC[];

static inline void DispatchSlot2(char* slot) {
	DtorSlot2* obj = *(DtorSlot2**)slot;
	if (obj != 0) {
		obj->destroy(1);
	}
	*(void**)slot = 0;
}

// SafeDestroy(obj) - own internal null check. RESOLVES a pattern
// previously filed as an unfixable "redundant-branch-preservation"
// wall (see extab_8013a27c.s's banner): retail's bytes for each of the
// 7 array slots below show an OUTER caller-side null check wrapping a
// call whose callee does its OWN (inlined) null check again - a
// genuine, readable 2-layer safety idiom, not a compiler peephole
// artifact. Getting the doubled `beq` requires BOTH (1) this small
// static-inline wrapper with its own `if (obj)` guard, called from an
// already-guarded call site, AND (2) each of the 7 slots written out as
// a LITERAL repeated block (a real `for` loop over the array compiles
// to an actual small loop here, NOT unrolled - confirmed by a failed
// first attempt that produced a 0x10C-byte function instead of
// retail's 0x208; retail's own bytes show no back-branch at all, i.e.
// the original source itself did not use a loop for this array).
static inline void SafeDestroy(void* obj) {
	if (obj != 0) {
		((DtorSlot2*)obj)->destroy(1);
	}
}

// fn_804007C4 - actor@lbl_804B0F50: destructor (0x208). Unconditionally
// dispatches through a global manager sub-object first
// (lbl_80529DEC->0x18's own vtable, slot1() at offset 0xc, no arg - the
// SlotB shape), then tears down 2 plain singles (0xc/0x14, standard
// vtable-slot-2 dispatch with an unconditional clear), then a 7-element
// array (0x18-0x30, stride 4) each guarded by an OUTER null check (only
// cleared if non-null) wrapping a call to SafeDestroy() (which redoes
// its own null check internally - the source of the doubled `beq`).
// Finishes by unconditionally clearing boot-config->0x225, then the
// standard "> 0 means also deallocate" conditional chain to
// __dl__FPv.
extern "C" void* fn_804007C4(void* this_, s16 how) {
	if (this_ != 0) {
		*(void**)this_ = lbl_804B0F50;

		void* mgr = *(void**)(lbl_80529DEC + 0x18);
		((SlotB*)mgr)->slot1();

		char* p = (char*)this_;

		DispatchSlot2(p + 0xc);
		DispatchSlot2(p + 0x14);

		{
			void* obj = *(void**)(p + 0x18);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x18) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x1c);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x1c) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x20);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x20) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x24);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x24) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x28);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x28) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x2c);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x2c) = 0;
			}
		}
		{
			void* obj = *(void**)(p + 0x30);
			if (obj != 0) {
				SafeDestroy(obj);
				*(void**)(p + 0x30) = 0;
			}
		}

		lbl_80529DEC[0x225] = 0;
		if (how > 0) {
			__dl__FPv(this_);
		}
	}
	return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
