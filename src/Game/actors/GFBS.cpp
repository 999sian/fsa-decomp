#include "Game/SinitPoolChain.h"

#include "Game/actors/GFBS.h"

// Game/scene manager helpers that live in the TU at 0x802D39B8 (not decompiled yet, so they are
// referenced by their dtk labels).
extern "C" {
void* fn_802D6A9C();
void fn_802D7440(void* mgr, int flag);
}

/* Definitions must stay in this order: the retail object emits v01 first
 * (0x8012679C) and the destructor second (0x801267C8), then the
 * compiler-generated __sinit_GFBS_cpp last (0x80126828). */
void GFBS::v01() {
    Actor::v01();
    fn_802D7440(fn_802D6A9C(), 0);
}

GFBS::~GFBS() {}
