#include "types.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

extern "C" char lbl_8049F330[];
extern "C" void __dt__5ActorFv(Actor* this_, s32 flag);
extern "C" Actor* fn_80142624(Actor* this_, s16 flag) {
    if (this_) {
        *(void**)this_ = lbl_8049F330;
        __dt__5ActorFv(this_, 0);
        if (flag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80158B5C(void* obj, s32 room, void* pos, s32* size);
extern "C" void fn_801EFD34(Actor* this_, s32 id, u8* idx, s32 n, f32 a, f32 b, f32 c);
extern "C" void fn_801F06F0(Actor* this_, void* res, s32 id, u8* idx, s32 n, f32 a, f32 b);
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AAF8;
extern "C" s32 lbl_8049F318[];
extern "C" void* lbl_80465B50;
extern "C" void fn_801F0E34(Actor* this_, s32 id, s32 flag);
extern "C" s32 lbl_8049F2B8[];
extern "C" const f32 sincosTable___5JMath[];

/* 0x19660d/0x3c6ef35f LCG at lbl_8053AAF8+0xB4, mantissa read as [0,1) */
static inline f32 poohRand01() {
    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *s = 0x19660du * *s + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - 1.0f;
}
extern "C" void fn_80142684(Actor* this_) {
    struct {
        s32 a;
        s32 b;
        f32* p;
        u8 c[11];
        s32 cc;
        u8 d[3];
        s32 dd;
        s32 e;
        s32 f;
    } s;
    u8 buf[16];
    f32 mtx[12];
    s32 size[2];
    u8 i;
    s32 idx;
    f32 scale;

    if (((*(s32*)((u8*)this_ + 0x254) != 0 || *(u16*)((u8*)this_ + 0x94) < 4 || *(u16*)((u8*)this_ + 0x94) > 7) ||
         ((*(u8 (**)(Actor*))(*(u32*)this_ + 0x34))(this_) != 0)) &&
        *(u16*)((u8*)this_ + 0x94) != 8 && (*(s32*)((u8*)this_ + 0x230) == 1 || *(s32*)((u8*)this_ + 0x230) == 0)) {
        s.a = -1;
        s.b = -1;
        for (i = 0; i < 16; i += 8) {
            buf[i] = i;
            buf[(u8)(i + 1)] = i + 1;
            buf[(u8)(i + 2)] = i + 2;
            buf[(u8)(i + 3)] = i + 3;
            buf[(u8)(i + 4)] = i + 4;
            buf[(u8)(i + 5)] = i + 5;
            buf[(u8)(i + 6)] = i + 6;
            buf[(u8)(i + 7)] = i + 7;
        }
        s.a = -1;
        s.b = 0;
        s.p = 0;
        s.c[0] = 0;
        s.c[1] = 0;
        s.c[2] = 0;
        s.c[3] = 1;
        s.c[4] = 1;
        s.c[5] = 0;
        s.c[6] = 0;
        s.c[7] = 0;
        s.c[8] = 0;
        s.c[9] = 0;
        s.c[10] = 1;
        s.cc = 3;
        s.d[0] = 1;
        s.d[1] = 0;
        s.d[2] = 0;
        s.dd = -1;
        s.e = 0;
        s.f = 2;
        size[0] = 0x80;
        size[1] = 0x80;
        fn_80158B5C(*(void**)((u8*)lbl_8053AB10 + 0x2c), *(s32*)((u8*)this_ + 0x4), (u8*)this_ + 0xc, size);
        ((u8*)&s.a)[3] = (u8)(s32)*(f32*)((u8*)this_ + 0x270);
        s.dd = 9;
        if (*(u16*)((u8*)this_ + 0x94) == 3 || *(u16*)((u8*)this_ + 0x94) == 7) {
            idx = *(s32*)((u8*)this_ + 0x25c);
            scale = 0.5f;
            if (idx > 5) {
                scale = 1.0f;
                idx -= 6;
            }
            mtx[0] = scale;
            mtx[1] = 0.0f;
            mtx[2] = 0.0f;
            mtx[3] = 0.0f;
            mtx[4] = 0.0f;
            mtx[5] = 1.0f;
            mtx[6] = 0.0f;
            mtx[7] = 0.0f;
            mtx[8] = 0.0f;
            mtx[9] = 0.0f;
            mtx[10] = 1.0f;
            mtx[11] = 0.0f;
            s.p = mtx;
            fn_801EFD34(this_, (*(s32 (**)(void*, u32, s32))(*(u32*)(*(u32*)((u8*)lbl_8053AAF8 + 0xa4)) + 0x18))(*(void**)((u8*)lbl_8053AAF8 + 0xa4), 0x54494d47, lbl_8049F318[idx]), buf, 7, 0.0f, 0.0f, 0.0f);
        } else {
            fn_801F06F0(this_, lbl_80465B50, *(s32*)((u8*)this_ + 0x25c) + 0x84, buf, 7, 1.0f, 1.0f);
        }
    }
}

void __sinit_POOH_80142624_cpp(void) {}
