#include "types.h"
extern "C" void fn_8015AB1C(void* ptr);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e0eb4-0x801e0f6c (1 functions). split_file divides it into the game's real files.

extern "C" void* dtor_801E0EB4(void* param_1, s16 param_2) {
    struct Array {
        u8* base;
        u32 stride;
        u32 max;
        void (*release)(void*, s32);
        u32 count;
    };
    Array* self = (Array*)param_1;
    if (self) {
        if (self->count < self->max && self->release) {
            u8* p = self->base + self->stride * self->count;
            while (self->count != 0) {
                p -= self->stride;
                self->release(p, -1);
                self->count--;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}
