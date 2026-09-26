#ifndef GAME_ACTORS_GFBS_H
#define GAME_ACTORS_GFBS_H

#include "Game/Actor.h"

/*
 * Actor 4CC 'GFBS'.
 *
 * The factory TU emits the constructor (0x80201630, 0x3C bytes) and allocates
 * 0x230 bytes for it (verified: the case body in fn_801F9484 at 0x801FD930 does
 * `addi r3, r0, 0x230` before calling it), so this class adds no data members to
 * Actor.
 *
 * This TU (0x8012679C-0x80126A4C) defines the two overridden virtuals below plus
 * the shared per-TU JAS-pool __sinit:
 *   0x8012679C v01__4GFBSFv
 *   0x801267C8 __dt__4GFBSFv
 *   0x80126828 __sinit_GFBS_cpp   (compiler-generated, see below)
 * Its .data holds only the vtable at 0x8049E3A8.
 *
 * The __sinit is not written by hand: it is emitted because this TU includes the
 * shared header that carries the nine `JASPoolAllocObject<T>::memPool_`
 * specialisations every game TU registers with __register_global_object.
 */
class GFBS : public Actor {
public:
    /* 0x8012679C */ virtual void v01();  // Actor vtable slot 1
    /* 0x801267C8 */ virtual ~GFBS();     // Actor vtable slot 0
};

#endif
