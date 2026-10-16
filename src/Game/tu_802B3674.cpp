#include "types.h"


extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" char* fn_8016A3AC(void);
extern "C" void fn_801EE434(void*);
extern "C" void fn_802B39E8(char* p) {
    *(s32*)(p + 0x290) = 0;
    if (*(void**)(p + 0x23c) != NULL) {
        void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x23c));
        *(void**)(p + 0x23c) = NULL;
    }
}

extern "C" void fn_802B3A3C(char* p) {
    *(s32*)(p + 0x2b8) = 0;
}

extern "C" void fn_802B3A48(char* p) {
    char* q = fn_8016A3AC();
    q[0x1ee] = 0;
    void* e = *(void**)(p + 0x234);
    if (e != NULL) {
        fn_801EE434(e);
    }
    e = *(void**)(p + 0x238);
    if (e != NULL) {
        fn_801EE434(e);
    }
    e = *(void**)(p + 0x23c);
    if (e != NULL) {
        fn_801EE434(e);
    }
    p[0x11c] = 0;
}

extern "C" void fn_802B3AB4(void) {
}

