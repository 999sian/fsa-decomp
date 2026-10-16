#include "types.h"
#include "Game/Actor.h"

struct F4 {
    f32 a, b, c, d;
};

extern "C" char lbl_8049E8A0[];
extern "C" f32 lbl_8053CC3C;
extern "C" void __ct__5ActorFv(Actor*);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" f32 lbl_8053CC50;
extern "C" f32 lbl_8053CC58;
extern "C" f32 lbl_8053CC5C;
extern "C" f32 lbl_8053CC60;
extern "C" const char* lbl_80539F40;
extern "C" void* fn_804032E8(u32 type, const char* name);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_8012E5A0(Actor* p) {
    v01__5ActorFv(p);
    *(f32*)((char*)p + 0x60) = lbl_8053CC58;
    *(f32*)((char*)p + 0x64) = lbl_8053CC5C;
    *(f32*)((char*)p + 0x68) = lbl_8053CC60;
    *(f32*)((char*)p + 0x6c) = lbl_8053CC50;
    *(f32*)((char*)p + 0x70) = *(f32*)((char*)p + 0x60);
    *(f32*)((char*)p + 0x74) = *(f32*)((char*)p + 0x64);
    *(f32*)((char*)p + 0x78) = *(f32*)((char*)p + 0x68);
    *(f32*)((char*)p + 0x7c) = *(f32*)((char*)p + 0x6c);
    *(f32*)((char*)p + 0x80) = *(f32*)((char*)p + 0x60);
    *(f32*)((char*)p + 0x84) = *(f32*)((char*)p + 0x64);
    *(f32*)((char*)p + 0x88) = *(f32*)((char*)p + 0x68);
    *(f32*)((char*)p + 0x8c) = *(f32*)((char*)p + 0x6c);
    *(s32*)((char*)p + 0x108) = 1000;
    *(s32*)((char*)p + 0xb8) = 1;
    *(s32*)((char*)p + 0xf8) = 2;
    *(s32*)((char*)p + 0xbc) = 3;
    *(s32*)((char*)p + 0x1a4) = 1;
    *(s32*)((char*)p + 0xb0) = 0xa040304;
    if (*(void**)((char*)p + 0x23c) == 0) {
        *(void**)((char*)p + 0x23c) = fn_804032E8('TIMG', lbl_80539F40);
    }
    if (*(void**)((char*)p + 0x240) == 0) {
        *(void**)((char*)p + 0x240) = fn_8013CC50(p->field_04, (char*)p + 0xc, 0x452, 0, 0, 0, 0, 1, lbl_8053CC3C);
    }
    if (*(void**)((char*)p + 0x244) == 0) {
        *(void**)((char*)p + 0x244) = fn_8013CC50(p->field_04, (char*)p + 0xc, 0x453, 0, 0, 0, 0, 1, lbl_8053CC3C);
    }
}

extern "C" Actor* fn_8012E6EC(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_8049E8A0;
        if (*(void**)((char*)p + 0x240) != 0) {
            fn_801EE434(*(void**)((char*)p + 0x240));
            *(s32*)((char*)p + 0x240) = 0;
        }
        if (*(void**)((char*)p + 0x244) != 0) {
            fn_801EE434(*(void**)((char*)p + 0x244));
            *(s32*)((char*)p + 0x244) = 0;
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" Actor* fn_8012E780(Actor* p) {
    __ct__5ActorFv(p);
    void** vt = (void**)p;
    *vt = lbl_8049E8A0;
    *(s32*)((char*)p + 0x230) = 0;
    *(s32*)((char*)p + 0x234) = 0;
    *(f32*)((char*)p + 0x238) = lbl_8053CC3C;
    *(s32*)((char*)p + 0x23c) = 0;
    *(s32*)((char*)p + 0x240) = 0;
    *(s32*)((char*)p + 0x244) = 0;
    return p;
}
