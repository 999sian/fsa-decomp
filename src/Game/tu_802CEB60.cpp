#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void fn_801F132C(void* a, void* b, void* c, void* d);
extern "C" char lbl_804A92D0[];

struct Vt802CEBC0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" void* fn_802CEB60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A92D0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802CEBC0(Vt802CEBC0* p) {
    p->m7();
}

