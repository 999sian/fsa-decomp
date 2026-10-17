#include "types.h"


void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A7960[];
extern "C" void fn_801EE434(void* handle);
extern "C" u8 fn_80303750(s32 i);
extern "C" u8 fn_8028B850(u8* this_);
extern "C" f32 lbl_805404CC;
extern "C" f32 lbl_805404C0;
extern "C" f32 lbl_805404D8;
extern "C" f32 lbl_805404F0;
extern void* lbl_8053AAF8;
extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_80138A30(void* game);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id);
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_8028AB7C(u8* this_) {
    u8 idx[16];
    s32 i;
    f32 ang;
    f32 s0, s1, s2, c0, c1, c2;

    for (i = 0; i < 16; i++) {
        idx[i] = i;
    }
    ang = (1.0f - *(f32*)(this_ + 0x240)) * 0.0f;
    s0 = sin(ang);
    s1 = sin(ang);
    s2 = sin(ang);
    c0 = cos(ang);
    c1 = cos(ang);
    c2 = cos(ang);
    fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x25c) + 0x129);
}

extern "C" void fn_8028BA5C(u8* this_) {
    s32 i;
    this_[0x250] = 1;
    for (i = 0; i < 4; i++) {
        if (fn_80303750(i)) {
            this_[0x250] = 0;
            break;
        }
    }
    if (this_[0x250] == 1) {
        this_[0x234] = fn_8028B850(this_);
    }
    *(f32*)(this_ + 0x240) = (this_[0x234] == 1) ? lbl_805404CC : lbl_805404C0;
    *(s32*)(this_ + 0x244) = (this_[0x234] == 1) ? 0x6e : 0;
}

extern "C" void* fn_8028BDD0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7960;
        fn_801EE434(*(void**)((u8*)this_ + 0x274));
        fn_801EE434(*(void**)((u8*)this_ + 0x278));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}
