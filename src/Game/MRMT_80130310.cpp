#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void v01__5ActorFv(void* this_);
void operator delete(void* p);
extern "C" char lbl_8049EA88[];
extern const f32 lbl_8053CC94;
extern const f32 lbl_8053CC98;
extern "C" void* fn_80130310(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_8049EA88;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80130CEC(char* p) {
    v01__5ActorFv(p);
    f32 b = lbl_8053CC98;
    f32 a = lbl_8053CC94;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x84) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x88) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x8c) = *(f32*)(p + 0x6c);
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 0x16) & 0x1f;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 0x11) & 0x1f;
}

