#include "types.h"
#include "JSystem/JGeometry/Vec.h"

class Actor;


extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern "C" const f32 lbl_80540A3C;
extern "C" const f32 lbl_80540A38;
extern "C" char lbl_8046CAB8[];
extern "C" char lbl_804A8750[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_801F856C(Actor*);
extern "C" void* Actor_CreateByID(void*, u32, s32, Vec*, s32, s32, s32);
extern "C" u16 fn_8022461C(Vec*);
extern "C" void* fn_8013CC50(u32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(Actor*, u32, s32);
extern "C" Actor* fn_802B61C8(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_804A8750;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B6228(char* p) {
    if (*(s32*)(p + 0x4) >= 8) {
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
        pos.z = lbl_80540A38;
        Actor_CreateByID(fn_801F856C((Actor*)p), 0x4b4d5249, *(s32*)(p + 0x4), &pos, 0, -1, -1);
    } else if (*(f32*)(p + 0x14) < lbl_80540A38 && fn_8022461C((Vec*)(p + 0xc)) == 0xd) {
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_80540A3C, 0x3d0, 0, 1, 0, 0, 1);
    } else {
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_80540A3C, 0x8c, 1, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_80540A3C, 0x8d, 1, 0, 0, 0, 1);
    }
    fn_801F0E34((Actor*)p, 0x30003, 0);
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_802B6358(void* this_) {
    fn_801F06F0(this_, lbl_8046CAB8, 0x29, 0, 0, lbl_80540A3C, lbl_80540A3C);
}

extern "C" const f32 lbl_80540A38;
extern "C" const f32 lbl_80540A40;
extern "C" const f32 lbl_80540A44;
extern "C" const f32 lbl_80540A68;
extern "C" const f32 lbl_80540A6C;
extern "C" const f32 lbl_80540A70;
extern "C" void fn_802B67F8(char* p) {
    *(f32*)(p + 0x60) = lbl_80540A68;
    *(f32*)(p + 0x64) = lbl_80540A68;
    *(f32*)(p + 0x68) = lbl_80540A6C;
    *(f32*)(p + 0x6c) = lbl_80540A6C;
    *(f32*)(p + 0x80) = lbl_80540A44;
    *(f32*)(p + 0x84) = lbl_80540A44;
    *(f32*)(p + 0x88) = lbl_80540A40;
    *(f32*)(p + 0x8c) = lbl_80540A40;
    *(f32*)(p + 0x23c) = lbl_80540A38;
    *(f32*)(p + 0x238) = lbl_80540A38;
    *(f32*)(p + 0x234) = lbl_80540A38;
    *(f32*)(p + 0x240) = lbl_80540A70;
    *(s32*)(p + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
