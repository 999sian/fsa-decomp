// TU 0x803944c8-0x803a3484.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_80396F94.cpp ----
extern "C" void fn_80078C0C(void* subObj);
extern "C" void fn_80396884(void* this_);
extern "C" void fn_80395BE8(void* this_);

// fn_80396F94 - leading helper: calls fn_80078C0C(this->0x8), then
// fn_80396884(this), then fn_80395BE8(this), then sets this->0x3b0=1
// (a "done" latch).
extern "C" void fn_80396F94(void* this_) {
    fn_80078C0C(*(void**)((char*)this_ + 0x8));
    fn_80396884(this_);
    fn_80395BE8(this_);
    *(u8*)((char*)this_ + 0x3b0) = 1;
}

// ---- from src/Game/fn_80397328_dtor.cpp ----
extern "C" void fn_80078050(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF774[];

extern "C" void* fn_80397328(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF774;
        fn_80078050(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80397388_dtor.cpp ----
extern "C" void fn_80077844(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF6D4[];

extern "C" void* fn_80397388(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF6D4;
        fn_80077844(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_803986A0_dtor.cpp ----
extern "C" void dtor_800788C0(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF6E4[];

extern "C" void* fn_803986A0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF6E4;
        dtor_800788C0(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/ClearIndirectFlags_0x2c0_0x2c4.cpp ----
// component C: 3 tiny vtable-slot/helper functions bundled.
extern "C" {
void fn_8039FE54(void* thisPtr) {
	void* p1 = *(void**)((char*)thisPtr + 0x2c0);
	*(u8*)p1 = 0;
	void* p2 = *(void**)((char*)thisPtr + 0x2c4);
	*(u8*)p2 = 0;
}

void fn_8039FE6C(void) {}

int fn_8039FE70(void) { return 1; }
}

// ---- from src/Game/stub_8039a510.cpp ----
// fn_8039A510 - component B vtable slot: advances a byte counter
// (this->0x281), then uses the counter as a byte offset from `this` to
// write 2 fields (a copy of this->0x22c, then a zero) at that
// dynamically-offset location. Each use re-reads the counter from
// memory rather than caching it, matching retail's own reload pattern.
extern "C" void fn_8039A510(void* thisObj) {
	u8* base = (u8*)thisObj;
	base[0x281] = base[0x281] + 1;
	base[base[0x281] + 0x202] = base[0x22c];
	base[base[0x281] + 0x257] = 0;
}
