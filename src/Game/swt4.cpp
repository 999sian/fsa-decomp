// TU 0x802a964c-0x802aa364 (actor SWT4).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_802A964C_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A80A0[];

extern "C" void* fn_802A964C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A80A0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Swt4_Draw.cpp ----
// Swt4_Draw(this) - SWT4's real draw(). A pure no-op (`blr`), matching
// the SAME pattern DOOR's draw uses ([[project_fsa_door_key0_full_depth]])
// - SWT4 renders nothing itself, relying on static level geometry or
// effects triggered from elsewhere rather than an actor-drawn model.
extern "C" {

void Swt4_Draw(void) {}

extern "C" void* fn_802D6A9C(...);
extern "C" u8 fn_802D800C(...);
extern "C" s32 fn_802D7E1C(...);
extern "C" void fn_802D8050(void*, u32, s32, s32);
extern "C" void fn_8022E2D8(s32);
extern "C" void fn_801F0D20(void*, s32);
extern "C" u8 fn_8023077C();
extern "C" void* fn_8023E724(s32);
extern "C" void fn_80230498(s32, void*, s32, s32, s32, s32, s32);
extern "C" void fn_8030C210(void*, void*);
extern "C" void fn_80230FD0(s32, s32);
extern "C" void fn_80230E1C(s32, s32);
extern "C" u8 fn_80230534(s32);
extern "C" u8* fn_801F856C();
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
#define SWT4_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define SWT4_U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define SWT4_PTR(p, o) (*(u8**)((u8*)(p) + (o)))
static inline void swt4Set(void* p, s32 value) {
    ((void (*)(void*, s32, s32))(*(void***)p)[12])(p, 0xff, value);
}
extern "C" void fn_802A96B0(u8* this_) {
    u32 slots[4];
    s32 i;
    s32 n = 0;
    u8* p = this_;

    *(u32*)this_ = *(u32*)this_;
    for (i = 0; i < 4; i++) {
        slots[i] = 0xff;
        fn_802D6A9C(p);
        if (fn_802D800C(*(u32*)(p + 0x244), 0) != 0) {
            fn_802D6A9C(p);
            slots[i] = fn_802D7E1C(p, *(u32*)(p + 0x244));
            n++;
        }
    }
    if (n != 4) {
        return;
    }
}

}

// ---- fn_802AA0B8 ----
extern const u32 lbl_8046C850[4];

extern "C" void fn_802AA0B8(u8* this_) {
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0x1F;
    if (*(s32*)(this_ + 0x234) != 5) {
        *(u32*)(this_ + 0x230) = 0;
    } else {
        *(u32*)(this_ + 0x230) = 7;
    }
    const u32* sh = lbl_8046C850;
    *(u32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> sh[0]) & 0x1F;
    *(u32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> sh[1]) & 0x1F;
    *(u32*)(this_ + 0x24C) = (*(u32*)(this_ + 0x90) >> sh[2]) & 0x1F;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> sh[3]) & 0x1F;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
