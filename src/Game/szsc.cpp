// TU 0x80347e90-0x803481b8 (actor SZSC).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AC708[];

extern "C" void* fn_80347E90(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC708;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* mgr);
extern "C" void fn_8022ADE4(void);
extern "C" void fn_8022ADCC(void);
extern "C" void detach__5ActorFv(void* actor);
// Minimal view of the Actor vtable: slot 11 (vtable +0x34) is the
// "is off screen / done" query.
class SzscActorV {
public:
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual u8 s11();
};

extern "C" void fn_80347EF0(void) {}

extern "C" void fn_80347EF4(void* thisPtr) {
    char* p = (char*)thisPtr;
    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (!fn_802DCD0C(fn_802D6A9C())) {
            fn_8022ADE4();
            *(s32*)(p + 0x230) = 1;
        }
        break;
    case 1:
        fn_8022ADE4();
        if (((SzscActorV*)p)->s11() == 1) {
            fn_8022ADCC();
            detach__5ActorFv(p);
        }
        break;
    }
}

extern "C" void fn_80347F88(void* thisPtr) {
    *(s32*)((char*)thisPtr + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
