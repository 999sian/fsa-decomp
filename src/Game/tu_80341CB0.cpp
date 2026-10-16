#include "Game/Actor.h"


extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void* lbl_8053AAF8;
extern "C" void fn_8034335C(s32 a, void* b);

extern "C" void fn_80341CB0(s32 id, f32* pos) {
    Actor_CreateByID(fn_801F856C(), 0x42424D42, id, pos, 0x30000, -1, -1);
}

extern "C" char lbl_804AC588[];
extern "C" void fn_801EE434(void* obj);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dt__5ActorFv(Actor* self, s32 flag);
extern "C" Actor* fn_803437B0(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AC588;
        fn_801EE434(*(void**)((u8*)p + 0x264));
        fn_801EE434(*(void**)((u8*)p + 0x268));
        if (((u8*)p)[0x261] == 1) {
            s32 kind = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
            if (kind != 9 && kind != 0xb) {
                fn_80138B7C(lbl_8053AAF8);
            }
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

