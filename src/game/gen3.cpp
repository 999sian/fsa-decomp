// TU 0x802ec1d4-0x802ec73c (actor GEN3).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Gen3_dtor_802EC1D4.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA1D0[];

extern "C" void* fn_802EC1D4(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA1D0;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Gen3_EmptyHook.cpp ----
// Gen3_EmptyHook - GEN3: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Gen3_EmptyHook(void) {}

}

// ---- Gen3_SetParams.cpp ----
#include "game/esd/Actor.h"

// Gen3_SetParams - GEN3: setParams (0x70)
// Extracts a 7-bit selector from this->0x90 into this->0x234, used to
// index a FourCC lookup table (lbl_8046F398, stride 4) whose result is
// stored at this->0x250 (the target FourCC searched for by update());
// extracts 0x238/0x23c/0x240/0x244 from further bitfields, copies 0x23c
// into 0x248, sets the initial countdown (0x24c=1) and state (0x230=0).
// GEN3 is a generic "spawn/find" template actor whose target type is
// data-driven rather than hardcoded.
extern "C" {
extern u32 lbl_8046F398[0x2e]; // real symbol size is 0xb8 bytes (46 words) per symbols.txt

void Gen3_SetParams(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 typeIdx = ((Actor*)thisPtr)->spawnParam & 0x7f;
	*(u32*)(p + 0x234) = typeIdx;
	u32 idx = *(u32*)(p + 0x234);
	*(u32*)(p + 0x250) = lbl_8046F398[idx];
	*(u32*)(p + 0x238) = (((Actor*)thisPtr)->spawnParam >> 7) & 0x1ff;
	*(u32*)(p + 0x23c) = (((Actor*)thisPtr)->spawnParam >> 16) & 0xf;
	*(u32*)(p + 0x240) = (((Actor*)thisPtr)->spawnParam >> 20) & 0xf;
	*(u32*)(p + 0x244) = (((Actor*)thisPtr)->spawnParam >> 24) & 0x1;
	*(u32*)(p + 0x248) = *(u32*)(p + 0x23c);
	*(u32*)(p + 0x24c) = 1;
	*(u32*)(p + 0x230) = 0;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
