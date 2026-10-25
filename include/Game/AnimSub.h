#ifndef GAME_ANIMSUB_H
#define GAME_ANIMSUB_H
#include "types.h"
extern "C" void fn_801D267C(void*);
struct AnimSub {
    AnimSub() { fn_801D267C(this); }
    ~AnimSub();
    u8 pad[0x38];
};
#endif
