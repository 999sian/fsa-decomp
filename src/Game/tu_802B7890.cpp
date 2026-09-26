// TU 0x802B7890-0x802B7C78.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A8800[];
extern "C" void* fn_802B7890(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8800;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B78F0(void) {}

extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 id);

static const u32 lbl_8046CB40[4] = {0x7c00000, 0x3e0000, 0x1f000, 0xf80};
static const u32 lbl_8046CB50[4] = {0x16, 0x11, 0xc, 0x7};

struct ActorV {
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10(s32 a, s32 b);
};

extern "C" void fn_802B78F4(u8* this_) {
    s32 i;
    s32 count;
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        for (i = 0; i < *(s32*)(this_ + 0x234); i++) {
            if (fn_802D800C(fn_802D6A9C(), (*(u32*)(this_ + 0x90) & lbl_8046CB40[i]) >> lbl_8046CB50[i])) {
                ((ActorV*)this_)->s10(0xff, 1);
                *(s32*)(this_ + 0x230) = 1;
            }
        }
        break;
    case 1:
    default:
        count = 0;
        for (i = 0; i < *(s32*)(this_ + 0x234); i++) {
            if (fn_802D800C(fn_802D6A9C(), (*(u32*)(this_ + 0x90) & lbl_8046CB40[i]) >> lbl_8046CB50[i])) {
                count++;
            }
        }
        if (count == 0) {
            ((ActorV*)this_)->s10(0xff, 0);
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    }
}

extern "C" void fn_802B7A3C(u8* this_) {
    *(s32*)(this_ + 0x230) = 0;
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0x1f;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D22D4[0x94];
