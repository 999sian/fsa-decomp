#include "JSystem/JGeometry/Vec.h"


extern "C" s32 fn_801F132C(void* this_, u32 param2, u32 param3, void* statePtr);
extern "C" char lbl_804A93D0[];
extern "C" void __dt__5ActorFv(void* p, int flags);
extern "C" void __dl__FPv(void* p);
extern "C" f32 lbl_80540EB8;
extern "C" f32 lbl_80540EBC;
extern "C" f32 lbl_80540EC0;
extern "C" f32 lbl_80540EC4;
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

extern "C" void fn_802D0B84(void* p) {
    (*(void (***)(void*))p)[9](p);
}

extern "C" s32 fn_802D0BB0(void* this_, u32 param2, u32 param3) {
    return fn_801F132C(this_, param2, param3, (u32*)((char*)this_ + 0x230));
}
