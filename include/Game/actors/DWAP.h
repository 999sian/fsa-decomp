#ifndef GAME_ACTORS_DWAP_H
#define GAME_ACTORS_DWAP_H

#include "Game/Actor.h"

/*
 * DWAP (4CC "DWAP") - debug warp actor, docs/community_notes.md: "debug warp;
 * variables choose the destination on the map", which is what v01 decodes.
 * Factory ctor 0x80200310, vtable __vt__4DWAP @ 0x8049C9E8, allocation size
 * 0x240 (Actor 0x230 + the members below, which the ctor does not initialise).
 *
 * TU 0x8010307C-0x80103348.  The ctor is inline: the factory TU
 * (0x801F9484-0x80204638) emits the single copy at 0x80200310.  This TU emits
 * the destructor and the three overridden virtuals only, in this order:
 *   0x8010307C  ~DWAP()  slot 0   0x60
 *   0x801030DC  v06()    slot 6   0x04  (empty)
 *   0x801030E0  v03()    slot 3   0x20  (calls Actor 0x801F3668)
 *   0x80103100  v01()    slot 1   0x24
 * Slot 2, 4, 5 and 7-18 stay the inherited Actor defaults.
 */
class DWAP : public Actor {
public:
    DWAP() {}

    /* slot 0 */ virtual ~DWAP();
    /* slot 6 */ virtual void v06();
    /* slot 3 */ virtual void v03();
    /* slot 1 */ virtual void v01();

    /* 0x230 */ u32 field_230;
    /* 0x234 */ u32 field_234;
    /* 0x238 */ u32 field_238;
    /* 0x23C */ u32 field_23C;
};

/* 0x230 + 0x10 = 0x240 (actors.csv alloc size). */
typedef char dwap_size_check[sizeof(DWAP) == 0x240 ? 1 : -1];

#endif
