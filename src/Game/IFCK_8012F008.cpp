// IFCK_8012F008: .text 0x8012F008-0x8012F3E4 (actor IFCK)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" u16 fn_80226850(void* p, void* q);
extern "C" void* fn_8012F554(void);
extern "C" void fn_8012F530(void* mgr, void* actor);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern void* lbl_8049E950[];

class IFCK_Actor {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30(s32, s32);
    virtual void vf34();
    virtual void vf38();
    virtual s32 vf3C();
};

extern "C" s32 fn_8012F008(u8* this_) {
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        break;
    case 1:
        return 1;
    }
    return 0;
}

extern "C" void fn_8012F02C(u8* this_) {
    v03__5ActorFv(this_);
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if (*(u16*)(this_ + 0x234) != fn_80226850(this_ + 0xC, *(void**)(this_ + 4))) {
            if (((IFCK_Actor*)this_)->vf3C() > 0) {
                ((IFCK_Actor*)this_)->vf30(0xFF, 1);
            }
            *(s32*)(this_ + 0x230) = 1;
        }
        break;
    case 1:
        break;
    }
}

extern "C" void fn_8012F0D0(u8* this_) {
    v01__5ActorFv(this_);
    *(u16*)(this_ + 0x234) = fn_80226850(this_ + 0xC, *(void**)(this_ + 4));
    fn_8012F530(fn_8012F554(), this_);
}

extern "C" void* fn_8012F118(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E950;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- from Game/Ifck_ctor_8012F178.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* __ct__5ActorFv(void* this_);

extern "C" void* fn_8012F178(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_8049E950;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s16*)((char*)this_ + 0x234) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
