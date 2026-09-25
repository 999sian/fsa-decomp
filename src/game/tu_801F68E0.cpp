// TU 0x801f68e0-0x801f9484.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- stub_801f714c.cpp ----
// fn_801F714C(shortPtr, target, divisor, maxStep) - integer/angle "ease
// toward" helper: delta = (target - *shortPtr) / divisor (word divide,
// sign-extended through 16 bits at each step, matching 16-bit angle
// arithmetic), then clamps that delta to +/-maxStep before adding it
// to *shortPtr.
extern "C" void fn_801F714C(void* shortPtr, s32 target, s32 divisor, s32 maxStep) {
	u16 current = *(u16*)shortPtr;
	s32 divisorMasked = divisor & 0xffff;
	s32 maxStepMasked = maxStep & 0xffff;
	s16 delta = (s16)(target - current);
	s32 rawDiv = delta / divisorMasked;
	s16 clampedDelta = (s16)rawDiv;
	if (clampedDelta > maxStepMasked) {
		*(u16*)shortPtr = current + maxStep;
		return;
	}
	if (clampedDelta < -maxStepMasked) {
		*(u16*)shortPtr = current - maxStep;
		return;
	}
	*(u16*)shortPtr = current + (u16)clampedDelta;
}

// ---- fn_801F8544.cpp ----
extern "C" s32 fn_801F9484(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);

// fn_801F8544(slotTable, code4, ownerID, posPtr, flags) - NOT a separate
// "spawn by code" primitive after all: it's a thin trampoline around the
// CONFIRMED universal actor dispatcher `fn_801F9484` itself (see
// project_fsa_actor_system_discovery.md), appending 2 fixed trailing
// args (-1, -1) that most callers don't need to specify. This means
// fn_801F9484's real signature has (at least) 7 parameters, not the
// (slotTable, code4, ownerID, ...) 3-4 previously documented - the 2
// extra args this wrapper defaults are still unconfirmed in meaning.
// Confirmed used by WIZR's rupee-drop-on-defeat mechanic (see
// project_fsa_stal_wizr_full_depth.md) with code4='RUPY'.
extern "C" s32 fn_801F8544(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param) {
    return fn_801F9484(base, fourCC, owner, posPtr, param, -1, -1);
}

// ---- stub_801f857c.cpp ----
extern "C" void fn_80456120(void* handle);

// vtable slot 2 (byte offset 8) - see [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this is a real `virtual` member rather than a manual cast dispatch.
struct ActorSlot2 {
    virtual void destroy(s32 freeFlag);
};

// fn_801F857C(actorPoolBase) - "DESTROY ALL ACTIVE ACTORS", the 3rd sibling
// in the actor-pool API alongside fn_801F8658 (draw-all) and fn_801F871C
// (update-all). Walks the 1024-slot pool; per occupied slot, calls
// fn_80456120(this->0x100c[slot-parallel-array]) (unexplored - shape
// matches an OS lock/mutex acquire given the paired release-style call at
// the very end), destructs via actor->vtable[2](freeFlag=1), clears the
// slot to 0, then maintains a "high-water mark" cache at this->0x1008 -
// if the slot just freed WAS the current high-water index, scans backward
// for the new highest occupied slot. After the full sweep, calls
// fn_80456120(this->0x200c) once more (a 2nd, different lock/counter).
extern "C" void fn_801F857C(void* actorPoolBase) {
    u8* slot = (u8*)actorPoolBase;

    for (u32 i = 0; i < 0x400; i++) {
        if (*(void**)(slot + 8) != 0) {
            fn_80456120(*(void**)(slot + 0x100c));

            ActorSlot2* actor = (ActorSlot2*)*(void**)(slot + 8);
            if (actor != 0) {
                actor->destroy(1);
            }

            *(void**)(slot + 8) = 0;

            s32 highWater = *(s32*)((u8*)actorPoolBase + 0x1008);
            if ((s32)(i + 1) == highWater) {
                s32 j = highWater - 2;
                u8* scan = (u8*)actorPoolBase + j * 4;
                while (j >= 0) {
                    if (*(void**)(scan + 8) != 0) break;
                    scan = scan - 4;
                    j = j - 1;
                }
                *(s32*)((u8*)actorPoolBase + 0x1008) = j + 1;
            }
        }
        slot += 4;
    }

    fn_80456120(*(void**)((u8*)actorPoolBase + 0x200c));
}
