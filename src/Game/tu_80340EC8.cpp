#include "Game/Actor.h"


extern "C" char lbl_804AC4D0[];
extern "C" void* lbl_8053AAF8;
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dt__5ActorFv(Actor* self, s32 flag);
extern "C" Actor* fn_80341A00(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AC4D0;
        if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
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
