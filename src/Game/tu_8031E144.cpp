#include "Game/Actor.h"


extern "C" char lbl_804AB1F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" f32 lbl_80541A20;
extern "C" f32 lbl_80541A24;
extern "C" f32 lbl_80541A38;
extern "C" f32 lbl_80541A3C;
extern "C" f32 lbl_80541A40;
extern "C" f32 lbl_80541A44;
extern "C" f32 lbl_80541A48;
extern "C" f32 lbl_80541A4C;
extern "C" f32 lbl_80541A50;
extern "C" void* lbl_8053AAF8;
extern "C" s32 fn_8013CC50(void* p, void* q, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_801F0E34(Actor* p, s32 a, s32 b);
extern "C" s32 fn_8022461C(s32 a);
extern "C" BOOL fn_8031EA3C(Actor* p, s32 param_2, s32 param_3) {
    s32 status = (u16)fn_8022461C(param_3);
    if (status == 0xc || status == 3 || status == 0xe) {
        p->field_3C.x = p->field_3C.y = p->field_3C.z = lbl_80541A20;
        *(s32*)((char*)p + 0x230) = 2;
        return FALSE;
    } else if (status == 0xd) {
        p->field_3C.x = p->field_3C.y = p->field_3C.z = lbl_80541A20;
        if (*(u32*)((char*)p + 0x268) == 0) {
            *(s32*)((char*)p + 0x268) = fn_8013CC50(*(void**)((char*)p + 4), (char*)p + 0xc, lbl_80541A24, 0x3d0, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x30022, 0);
        }
        *(s32*)((char*)p + 0x230) = 3;
        return FALSE;
    }
    return status != 0;
}

extern "C" Actor* fn_8031ECBC(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB1F0;
        fn_801EE434(*(void**)((char*)p + 0x268));
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}
