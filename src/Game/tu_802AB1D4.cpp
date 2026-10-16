#include "types.h"


extern "C" void __dt__5ActorFv(void*, s16);
extern char lbl_804A81C8[];
extern f32 lbl_805408B0;
extern f32 lbl_80540898;
extern "C" void* fn_802AB1D4(void* p, s16 d) {
    if (p != NULL) {
        *(char**)p = lbl_804A81C8;
        __dt__5ActorFv(p, 0);
        if (d > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802AB234(void) {}
