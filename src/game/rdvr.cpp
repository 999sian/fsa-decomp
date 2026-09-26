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
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);

// RDVR draw (vtable slot 6)
extern "C" void fn_80182914(char* this_) {
    s32 flag = -1;
    s32 state = *(s32*)(this_ + 0x230);
    s32 frame = *(s32*)(this_ + 0x254);
    if ((state == 0 || state == 1) && *(s32*)(this_ + 0x23c) == 0) {
        return;
    }
    if (*(s32*)(this_ + 0x258) != 0) {
        flag = 0;
    }
    if (*(s32*)(this_ + 0x25c) == 1 && frame >= 3) {
        frame += 5;
    }
    fn_801F06F0(this_, "enemy_gc_sob.bin", frame + 0x158, 1.0f, 1.0f, 0, flag);
}

extern void** lbl_8053AB10;

extern "C" void fn_8018330C(u32* out);

extern "C" void* fn_802D6A9C(void);

// RDVR init (vtable slot 1)
extern "C" void fn_801831E0(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(u32*)(this_ + 0x25c) = *(u32*)(this_ + 0x90) & 1;
    *(u32*)(this_ + 0x260) = (*(u32*)(this_ + 0x90) >> 8) & 1;
    *(s32*)(this_ + 0x254) = 0;
    *(u8*)(this_ + 0x238) = 0;
    *(u8*)(this_ + 0x239) = 0;
    *(u8*)(this_ + 0x23a) = 0;
    if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
        u8 c[4];
        fn_8018330C((u32*)c);
        *(u8*)(this_ + 0x234) = c[0];
        *(u8*)(this_ + 0x235) = c[1];
        *(u8*)(this_ + 0x236) = c[2];
        *(u8*)(this_ + 0x237) = c[3];
        *(u8*)(this_ + 0x238) = *(u32*)(this_ + 0x234) >> 24;
        *(u8*)(this_ + 0x239) = *(u32*)(this_ + 0x234) >> 16;
        *(u8*)(this_ + 0x23a) = *(u32*)(this_ + 0x234) >> 8;
    }
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(s32*)(this_ + 0x258) = 0;
    *(s16*)(this_ + 0x264) = 0;
    *(u8*)(this_ + 0x195) = 1;
    *(s32*)(this_ + 0x274) = 0;
    *(s32*)(this_ + 0x230) = 0;
}

extern "C" void fn_8018330C(u32* out) {
    *out = ((u32*)lbl_8053AB10[0xb])[1];
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
