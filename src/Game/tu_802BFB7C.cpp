#include "types.h"


extern "C" char lbl_804A8C80[];
extern "C" void __dt__5ActorFv(void*, int);
void operator delete(void*);
extern "C" f32 lbl_80540C40;
extern "C" void* fn_802BFB7C(void* p, s16 flags) {
    if (p != 0) {
        *(char**)p = lbl_804A8C80;
        __dt__5ActorFv(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}
