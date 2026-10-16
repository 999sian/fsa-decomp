#include "JSystem/JGeometry/Vec.h"

struct Vtable802D31E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" char lbl_804A94D8[];
extern "C" void __dt__5ActorFv(void* p, int flags);
extern "C" void __dl__FPv(void* p);
extern "C" const f32 lbl_80540F44;
extern "C" const f32 lbl_80540F48;
extern "C" const f32 lbl_80540F4C;
extern "C" const f32 lbl_80540F50;

extern "C" s32 fn_801F132C(void* this_, u32 param2, u32 param3, void* statePtr);
extern "C" s32 fn_802D3210(void* this_, u32 param2, u32 param3) {
    return fn_801F132C(this_, param2, param3, (u32*)((char*)this_ + 0x230));
}
