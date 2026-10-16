#include "types.h"
#include "Game/Actor.h"


extern "C" char lbl_804A78B0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
struct ObjSlots {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(s32 a, void* b);
};

extern "C" Actor* fn_80289648(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A78B0;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
