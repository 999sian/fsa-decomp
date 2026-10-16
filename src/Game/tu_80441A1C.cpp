#include "types.h"
struct Slot0 {
    virtual void slot0(s32 arg);
};


extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B19F0[];
extern "C" u32 lbl_8053AEE0;

struct fn_80442368_Obj {
    virtual void Release(int);
};

extern "C" void* fn_80442368(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B19F0;
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
        lbl_8053AEE0 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
