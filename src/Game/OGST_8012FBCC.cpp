// OGST_8012FBCC: .text 0x8012FBCC-0x8012FF9C (actor OGST)
#include "types.h"

extern "C" void v01__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* mgr, u32 id);
extern "C" u8* fn_801F666C(void* mgr, s32 handle);
extern "C" void* fn_8012FF9C(void);
extern "C" void fn_801300B4(void* mgr, u32 v);
void operator delete(void* p);
extern void* lbl_8049EA00[];

extern "C" void* fn_8012FBCC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049EA00;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8012FC2C(u8* this_, s32* counts) {
    s32 h = fn_801F7A08(fn_801F856C(), 0x4F50474C);
    if (h < 0) {
        return 1;
    }
    u8* obj = fn_801F666C(fn_801F856C(), h);
    if (obj == 0) {
        return 1;
    }
    if (*(u32*)(obj + 0x1A0) != 0x4F50474C) {
        return 1;
    }
    u32 flags = *(u32*)(this_ + 0x230);
    if ((flags & 1) && counts[0] <= 0) {
        return 1;
    }
    if (((flags >> 1) & 1) && counts[0] >= 0) {
        return 1;
    }
    if (((flags >> 2) & 1) && counts[1] <= 0) {
        return 1;
    }
    if (((flags >> 3) & 1) && counts[1] >= 0) {
        return 1;
    }
    return 0;
}

extern "C" void fn_8012FD34(u8* this_) {
    v01__5ActorFv(this_);
    *(u32*)(this_ + 0x230) = *(u32*)(this_ + 0x90) & 0xF;
    fn_801300B4(fn_8012FF9C(), *(u32*)(this_ + 0x198));
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
