#ifndef GAME_ACTORS_BOTS_H
#define GAME_ACTORS_BOTS_H

#include "Game/Actor.h"

/*
 * BOTS (4CC "BOTS"), factory ctor 0x802020F0, vtable lbl_8049C7F0,
 * allocation size 0x248 (Actor 0x230 + 0x18 bytes of members that the
 * constructor does not initialise).
 *
 * The ctor is inline: the factory TU emits the single copy at 0x802020F0.
 * This TU emits the dtor and the three overridden virtuals only.
 */
class BOTS : public Actor {
public:
    BOTS() {}

    virtual ~BOTS();
    virtual void v06();
    virtual void v03();
    virtual void v01();

    /* 0x230 */ u8 field_230[0x18];
};

#endif
