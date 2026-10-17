#include "types.h"


extern "C" void __dt__5ActorFv(void*, s16);
extern char lbl_804A81C8[];
extern f32 lbl_805408B0;
extern f32 lbl_80540898;
struct Obj802AB9DC {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual bool check();
};

extern "C" void* fn_802AB1D4(void* p, s16 d) {
    if (p != NULL) {
        *(char**)p = lbl_804A81C8;
        __dt__5ActorFv(p, 0);
        if (d > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802AB234(void) {}

extern "C" void fn_802AB9DC(Obj802AB9DC* obj) {
    char* self = (char*)obj;
    f32 b = lbl_80540898;
    f32 a = lbl_805408B0;
    *(u32*)(self + 0x234) = *(u32*)(self + 0x90) & 0x1f;
    *(f32*)(self + 0x60) = a;
    *(f32*)(self + 0x64) = a;
    *(f32*)(self + 0x68) = b;
    *(f32*)(self + 0x6c) = b;
    *(u32*)(self + 0x230) = 0;
    if (obj->check()) {
        *(u32*)(self + 0x230) = 4;
    }
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
