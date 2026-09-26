#ifndef GAME_ACTORS_STGN_H
#define GAME_ACTORS_STGN_H

#include "Game/Actor.h"

/*
 * STGN (4CC "STGN", debug "stage information NPC"), factory ctor 0x801FF7BC,
 * vtable 0x804AA7A8, allocation size 0x230 (no members beyond Actor).
 *
 * The ctor is inline: the factory TU emits the single copy at 0x801FF7BC.
 * This TU emits the dtor and the three overridden virtuals only.
 */
class STGN : public Actor {
public:
    STGN() {}

    virtual ~STGN();
    virtual void v06();
    virtual void v03();
    virtual void v01();
};

#endif
