#include "types.h"

extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern const char lbl_80465B68[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_8049F3B0[];
extern "C" void fn_801438D4(u8* this_) {
    fn_801F06F0(this_, lbl_80465B68, *(s32*)(this_ + 0x240) + 0x1a, 0, 0, 1.0f, 1.0f);
}
