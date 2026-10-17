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
extern "C" void fn_80142684(Actor* this_) {
    u8 buf[16];
    f32 mtx[12];
    s32 size[2];
    s32 sA;
    s32 sB;
    s32* sP;
    u8 flags[11];
    s32 sC;
    s32 sD;
    s32 sE;
    f32 fl;
    s32 idx;
    s32 i;
    s32 sF;
    s32 sG;
    s32 sH;
    s32 sI;
    s64 tmp;
    f32 f0;
    u8* p;
    u32 tmp2;

    if (((*(s32*)((u8*)this_ + 0x254) != 0 || *(u16*)((u8*)this_ + 0x94) < 4 || *(u16*)((u8*)this_ + 0x94) > 7) ||
         ((*(s32 (**)(Actor*))(*(u32*)this_ + 0x34))(this_) != 0)) &&
        *(u16*)((u8*)this_ + 0x94) != 8 && (*(s32*)((u8*)this_ + 0x230) == 1 || *(s32*)((u8*)this_ + 0x230) == 0)) {
        for (i = 0; i < 16; i += 8) {
            buf[i] = i;
            buf[i + 1] = i + 1;
            buf[i + 2] = i + 2;
            buf[i + 3] = i + 3;
            buf[i + 4] = i + 4;
            buf[i + 5] = i + 5;
            buf[i + 6] = i + 6;
            buf[i + 7] = i + 7;
        }
    }
}

void __sinit_POOH_80142624_cpp(void) {}
struct Local50 {
    s32 a;
    s32 b;
    s32* p;
    u8 c[11];
    s32 cc;
    u8 d[3];
    s32 dd;
    s32 e;
    s32 f;
};
