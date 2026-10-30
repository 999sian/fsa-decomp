#include "JSystem/JGeometry/Vec.h"

struct Vtable802D0B84 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" s32 fn_801F132C(void* this_, u32 param2, u32 param3, void* statePtr);
extern "C" char lbl_804A93D0[];
extern "C" void __dt__5ActorFv(void* p, int flags);
extern "C" void __dl__FPv(void* p);
extern "C" const f32 lbl_80540EB8;
extern "C" const f32 lbl_80540EBC;
extern "C" const f32 lbl_80540EC0;
extern "C" const f32 lbl_80540EC4;
extern "C" void* fn_802D0B24(void* p, s16 flags) {
    if (p != 0) {
        *(void**)p = lbl_804A93D0;
        __dt__5ActorFv(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_802D0B84(Vtable802D0B84* p) {
    p->m7();
}

extern "C" s32 fn_802D0BB0(void* this_, u32 param2, u32 param3) {
    return fn_801F132C(this_, param2, param3, (u32*)((char*)this_ + 0x230));
}

extern "C" void fn_802D1270(char* p) {
    *(f32*)(p + 0x60) = lbl_80540EB8;
    *(f32*)(p + 0x64) = lbl_80540EB8;
    *(f32*)(p + 0x68) = lbl_80540EBC;
    *(f32*)(p + 0x6c) = lbl_80540EBC;
    *(f32*)(p + 0x80) = lbl_80540EC0;
    *(f32*)(p + 0x84) = lbl_80540EC0;
    *(f32*)(p + 0x88) = lbl_80540EC4;
    *(f32*)(p + 0x8c) = lbl_80540EC4;
    *(s32*)(p + 0x230) = 0;
    *(u8*)(p + 0x234) = 0xff;
    *(u8*)(p + 0x235) = 0;
}

