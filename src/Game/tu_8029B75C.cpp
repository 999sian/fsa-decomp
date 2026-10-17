// tu_8029B75C
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

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

extern "C" int fn_8023DE58(int);
extern "C" int fn_8022DB04(int);
extern "C" int fn_80230CFC(int);
extern "C" f32* fn_8023E724(int);
extern "C" BOOL fn_8022DB04(int);
extern "C" void fn_8029B7C0(void* this_) {
    u8* self = (u8*)this_;
    f32 left = *(f32*)(self + 0x60) + *(f32*)(self + 0xc);
    f32 top = *(f32*)(self + 0x64) + *(f32*)(self + 0x10);
    f32 right = *(f32*)(self + 0x68) + *(f32*)(self + 0xc);
    f32 bottom = *(f32*)(self + 0x6c) + *(f32*)(self + 0x10);
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        s32 owner = *(s32*)(self + 4);
        if (fn_8023DE58(i) == owner && fn_8022DB04(i)) {
            u32 flags = *(u32*)(self + 0x90);
            s32 mode = (flags >> 17) & 3;
            if (fn_80230CFC(i) == mode) {
                f32* pos = fn_8023E724(i);
                BOOL inside = pos[0] >= left && pos[1] >= top && pos[0] < right && pos[1] < bottom;
                if (inside) {
                    count++;
                }
            }
        }
    }

    {
        u32 flags = *(u32*)(self + 0x90);
        s32 need = 1;
        s32 t = (flags >> 22) & 0x1f;
        if (t) {
            need = t;
        }
        if (count >= need) {
            ((void (*)(void*, int, int))(*(void***)this_)[12])(this_, 0xff, 1);
        } else {
            ((void (*)(void*, int, int))(*(void***)this_)[12])(this_, 0xff, 0);
        }
    }
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

