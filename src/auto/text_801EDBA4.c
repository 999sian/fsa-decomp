#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_801EDC0C(char* this_, f32* param_2);
#include "JSystem/JGeometry/Vec.h"

typedef struct {
    f32 x, y;
} Vec2f;

typedef struct {
    Vec2f xy;
    f32 z;
} Vec3f;

extern "C" void fn_801EDBA4(char* this_) {
    Vec3f v;
    if (*(s32*)(this_ + 0x248) != 0x17) {
        v = *(Vec3f*)(this_ + 0xc);
        fn_801EDC0C(this_, (f32*)(*(char**)(this_ + 0x280) + 0x10c));
        *(Vec3f*)(this_ + 0xc) = v;
    }
}
