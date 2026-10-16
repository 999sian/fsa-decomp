#include "Game/Actor.h"


extern "C" char lbl_804AB464[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8032500C(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AB464;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* lbl_8053AC98;
extern "C" void fn_8029EDB8(void*, void*, s32, s32, void*);
extern "C" void fn_803261B0(u8* p) {
    struct VObj {
        virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
        virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
        virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
        virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
        virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
        virtual void v50(); virtual void v54();
    };
    u8 buf[8];
    ((VObj*)p)->v4C();
    fn_8029EDB8(lbl_8053AC98, p + 0xc, 0, *(s32*)(p + 0x4), buf);
    *(s32*)(p + 0x230) = 3;
}

