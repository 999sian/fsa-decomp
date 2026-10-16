#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_801EDC0C(char* this_, f32* param_2);
typedef struct {
    f32 x, y, z;
} Vec3f;

extern "C" void fn_801EDBA4(char* this_) {
    f32 v[3];
    if (*(s32*)(this_ + 0x248) != 0x17) {
        v[0] = *(f32*)(this_ + 0xc);
        v[1] = *(f32*)(this_ + 0x10);
        v[2] = *(f32*)(this_ + 0x14);
        fn_801EDC0C(this_, (f32*)(*(char**)(this_ + 0x280) + 0x10c));
        *(f32*)(this_ + 0xc) = v[0];
        *(f32*)(this_ + 0x10) = v[1];
        *(f32*)(this_ + 0x14) = v[2];
    }
}
