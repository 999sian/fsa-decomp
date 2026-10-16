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
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" s16 fn_8022461C(s32);
extern "C" s32 fn_80350274(s32 param_1, s32 param_2, s32 param_3) {
    s32 r = (u16)fn_8022461C(param_3);
    if (r == 0x3a || r == 3 || (u32)(r - 0xd) <= 1 || r == 0x3b) {
        return 0;
    }
    return 1;
}

