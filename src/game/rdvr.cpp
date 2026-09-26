// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80182914-80183544 (RDVR). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_80183100_dtor.cpp
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A1718[];

extern "C" void* fn_80183100(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1718;
        char* p = (char*)this_;
        fn_801EE434(*(void**)(p + 0x274));
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/fn_8018316C.cpp
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801F5790(void* this_);

// fn_8018316C(this) - closes the loop on RUSA's fn_80212AF0 (see
// project_fsa_rusa_actor_progress.md and
// project_fsa_80212af0_callers_closed.md). This is one of (at least) 3
// near-identical vtable-slot-0x18 overrides found across a large,
// still-entirely-unclaimed actor family in the 0x8018xxxx address
// range (siblings: fn_80183C18, fn_80184A14). Each: fetches RUSA's
// "active instances" registry via fn_80212AC0, pushes
// this's own position (&this->0xc) away from any RUSA zone it's
// inside via fn_80212AF0, THEN chains to the confirmed GENERIC
// slot-0x18 default fn_801F5790 (extending, not replacing, the
// generic behavior). This confirms vtable offset 0x18 - previously
// catalogued as an always-generic slot - is in fact a real override
// point, used here as a "resolve collision with RUSA instances"
// post-step.
extern "C" void fn_8018316C(void* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, (char*)this_ + 0xc);
    fn_801F5790(this_);
}

// from src/Game/Rivr_StartTrigger.cpp
// RIVR's vtable-0x44 override. A start trigger gated by two early-return conditions.
extern "C" {
void fn_801831A8(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(s32*)(p + 0x258) != 0) return;
	if (*(s32*)(p + 0x230) == 5) return;
	*(u32*)(p + 0xb0) = 0x11101;
	*(u32*)(p + 0x254) = 6;
	*(u32*)(p + 0x230) = 4;
}
}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
