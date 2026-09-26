// TU 0x802ef448-0x802ef76c (actor ELSK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Emsk_dtor_802EF448.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA498[];

extern "C" void* fn_802EF448(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA498;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Emsk_EmptyHook.cpp ----
// Emsk_EmptyHook - EMSK: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Emsk_EmptyHook(void) {}

}

// ---- fn_802EF4AC ----
extern "C" void* GetRoomConfigRecord(void);
extern "C" void fn_802D9FF4(void* rec, u32 a, u32 b);
static inline void elskSet(u32 a, u32 b) { fn_802D9FF4(GetRoomConfigRecord(), a, b); }
extern "C" void fn_80136798(void* mgr, s32 a, s32 b);
struct ElskEntry { u32 a; u32 b; };
extern const ElskEntry lbl_8046F610[3];
extern void* lbl_8053AAF8;

extern "C" void fn_802EF4AC(void* this_) {
    char* p = (char*)this_;
    (*(s32*)(p + 0x234))--;
    if (*(s32*)(p + 0x234) == 0) {
        s32 idx = *(s32*)(p + 0x230);
        elskSet(lbl_8046F610[idx].a, lbl_8046F610[idx].b);
        fn_80136798(lbl_8053AAF8, 0xf, 0);
    }
}

// ---- Emsk_SetParams.cpp ----
#include "game/esd/Actor.h"

// EMSK: setParams.
extern "C" {
void Emsk_SetParams(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 v = ((Actor*)thisPtr)->spawnParam;
	*(u32*)(p + 0x230) = v & 0x7F;
	*(s32*)(p + 0x234) = 0x1f4;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
