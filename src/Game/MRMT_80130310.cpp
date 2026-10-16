#include "types.h"
#include "Game/Actor.h"

extern "C" void* fn_801F856C(void);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_8022FE80(s32 a, void* b, s32 c, s32 d, s32 e);
extern "C" u8 fn_8038BD08(s32 a, u16 id, void* b, Vec* pos, s32 c);
extern "C" void fn_80125C58(void* p, s32 x);

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

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7884(void* mgr, u32 tag, s32 id);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801F78F4(void* mgr, u32 tag, s32 idx);
extern const f32 lbl_8053CC90;
extern "C" void fn_80130C18(char* p) {
    s32 idx = fn_801F7884(fn_801F856C(), 0x4f504741, *(s32*)(p + 4));
    while (idx != -1) {
        u8* actor = fn_801F666C(fn_801F856C(), idx);
        if (actor != 0) {
            if (*(s32*)(actor + 0x238) == 1) {
                *(s32*)(p + 0x238) = *(s32*)(actor + 0x198);
            } else {
                *(s32*)(p + 0x234) = *(s32*)(actor + 0x198);
            }
            idx = fn_801F78F4(fn_801F856C(), 0x4f504741, idx);
        }
    }
    u8* actor = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x238));
    *(Vec*)(p + 0xc) = *(Vec*)(actor + 0xc);
    *(f32*)(p + 0x10) += lbl_8053CC90;
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

