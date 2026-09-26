// TU 0x802ABC74-0x802AC03C.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A8250[];
extern "C" void* fn_802ABC74(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8250;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802ABCD4(void) {}

struct Mgr {
    u32 get(s32 i) { return mCount[i < 8 ? 0 : i - 7]; }
    u8 pad[0x6748];
    u32 mCount[8];
};
extern "C" Mgr* fn_802D6A9C(void);
extern "C" void fn_80138B7C(void* game);
extern u8* lbl_8053AF80;
extern void* lbl_8053AAF8;

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

extern "C" void fn_802ABCD8(u8* this_) {
    u32 total = 0;
    if (*(s32*)(this_ + 0x234) == 0) {
        for (s32 i = 0; i < 8; i++) {
            total += fn_802D6A9C()->mCount[i];
        }
    } else {
        total = fn_802D6A9C()->get(*(s32*)(this_ + 4));
    }
    if (total >= *(u32*)(this_ + 0x238)) {
        ((ActorV*)this_)->s10(0xff, 1);
        if (*(u32*)(this_ + 0x244) != *(u32*)(lbl_8053AF80 + 0x58) && this_[0x240] == 0) {
            fn_80138B7C(lbl_8053AAF8);
        }
        this_[0x11c] = 0;
    }
}

extern "C" void fn_802ABDDC(u8* this_) {
    *(s32*)(this_ + 0x230) = 0;
    *(u32*)(this_ + 0x234) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    *(u32*)(this_ + 0x238) = *(u32*)(this_ + 0x90) & 0xff;
    *(u32*)(this_ + 0x244) = *(u32*)(lbl_8053AF80 + 0x58);
    this_[0x240] = (*(u32*)(this_ + 0x90) >> 21) & 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D13D4[0x94];
