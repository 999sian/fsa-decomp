#include "types.h"

struct Actor {
    ~Actor();
};

extern "C" void __dt__5ActorFv(Actor* self, s16 flag);
extern u8 lbl_804ACA00[];
void operator delete(void* p);

extern "C" Actor* fn_8034EDDC(Actor* self, s16 flag) {
    if (self != 0) {
        *(u8**)self = lbl_804ACA00;
        self->Actor::~Actor();
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
