// tu_8029B75C
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A7B38[];

extern "C" void* fn_8029B75C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7B38;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8029B7BC(void) {
}

extern "C" void fn_8029B95C(void* this_) {
    f32* v = (f32*)((u8*)this_ + 0x60);
    u32 w = *(u32*)((u8*)this_ + 0x90);
    switch ((w >> 17) & 3) {
    case 0: {
        s32 n = 1;
        s32 m = (w >> 12) & 0x1f;
        if (m != 0) {
            n = m;
        }
        v[0] = -15.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 16.0f * (f32)n;
        break;
    }
    case 1: {
        s32 n = 1;
        s32 m = (w >> 12) & 0x1f;
        if (m != 0) {
            n = m;
        }
        v[0] = 16.0f;
        v[1] = 0.0f;
        v[2] = 31.0f;
        v[3] = 16.0f * (f32)n;
        break;
    }
    case 2: {
        s32 n = 1;
        s32 m = (w >> 12) & 0x1f;
        if (m != 0) {
            n = m;
        }
        v[0] = 0.0f;
        v[1] = -15.0f;
        v[2] = 16.0f * (f32)n;
        v[3] = 0.0f;
        break;
    }
    case 3: {
        s32 n = 1;
        s32 m = (w >> 12) & 0x1f;
        if (m != 0) {
            n = m;
        }
        v[0] = 0.0f;
        v[1] = 16.0f;
        v[2] = 16.0f * (f32)n;
        v[3] = 31.0f;
        break;
    }
    }
    v[8] = v[0];
    v[9] = v[1];
    v[10] = v[2];
    v[11] = v[3];
}

