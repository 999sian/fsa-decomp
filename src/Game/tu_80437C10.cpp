#include "Game/Actor.h"


extern "C" char lbl_804B16E0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" void fn_8043824C(u8* p) {
    for (int i = 0; i < 4; i++) {
        *(void**)(p + 0x230 + i * 4) = 0;
        *(u8*)(p + 0x240 + i) = 0xff;
    }
    p[0x11e] = 1;
    p[0x11f] = 1;
}
