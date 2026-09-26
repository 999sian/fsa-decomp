#ifndef GAME_ACTORS_TJIJ_H
#define GAME_ACTORS_TJIJ_H

#include "Game/Actor.h"

/* Retail class TJIJ: no extra members (0x230 bytes, same as Actor), overrides
 * only the destructor and the empty virtuals at Actor slots 1, 3 and 6. */
class TJIJ : public Actor {
public:
    TJIJ();

    virtual void v06();
    virtual void v03();
    virtual void v01();

    virtual ~TJIJ();
};

#endif
