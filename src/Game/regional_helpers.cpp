#include "types.h"

#if defined(VERSION_G4SP01)
extern "C" int fn_800219A0(void) {
    return 1;
}
#endif

#if defined(VERSION_G4SJ01)
struct Slot0 {
    virtual void slot0(int) = 0;
};

extern "C" void __dl__FPv(void*);
extern "C" char lbl_804A1C68[];

extern "C" void* fn_8036E210(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1C68;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* p3 = *(void**)((char*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((char*)this_ + 0xc) = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#endif
