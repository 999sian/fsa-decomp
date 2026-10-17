#include "Game/SinitPoolChain.h"
#include "Game/Actor.h"


extern "C" char lbl_804AB850[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u32 fn_8022461C(void*);
extern "C" float lbl_80541E40;
extern "C" u32 fn_8032EB28(char* p, void* a, void* b) {
    int t = (u16)fn_8022461C(b);
    if (t == 12 || t == 3 || t == 14) {
        *(float*)(p + 0x3c) = *(float*)(p + 0x40) = *(float*)(p + 0x44) = lbl_80541E40;
        *(s32*)(p + 0x230) = 5;
        return 0;
    }
    if (t == 13) {
        *(s32*)(p + 0x248) = 0;
        *(float*)(p + 0x3c) = *(float*)(p + 0x40) = *(float*)(p + 0x44) = lbl_80541E40;
        *(s32*)(p + 0x230) = 6;
        return 0;
    }
    return t != 0;
}

extern "C" Actor* fn_8032EEB8(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AB850;
        fn_801EE434(*(void**)((char*)p + 0x284));
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
