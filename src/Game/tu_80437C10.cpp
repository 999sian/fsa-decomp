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

extern "C" Actor* fn_80438284(Actor* a, s16 n) {
    if (a) {
        *(void**)a = lbl_804B16E0;
        void** p = (void**)a;
        for (int i = 0; i < 4; i++) {
            if (p[0x8c]) {
                void* mgr = *(void**)((u8*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, p[0x8c]);
                p[0x8c] = 0;
            }
            p++;
        }
        __dt__5ActorFv(a, 0);
        if (n > 0) operator delete(a);
    }
    return a;
}

