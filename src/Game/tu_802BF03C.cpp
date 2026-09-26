// TU 0x802BF03C-0x802BF410.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A8BD0[];
extern "C" void* fn_802BF03C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8BD0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802BF09C(void) {}

extern "C" s32 fn_801CD664(s32 n);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* mgr, u32 id, s32 a, s32 b);
extern "C" void detach__5ActorFv(void* this_);

static const u32 lbl_8046D460[4] = {0x16, 0x11, 0xc, 0x7};

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
    virtual u8 s11();
};

extern "C" void fn_802BF0A0(u8* this_) {
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if ((*(u32*)(this_ + 0x90) >> 27) == 0 || ((ActorV*)this_)->s11() == 1) {
            s32 r = fn_801CD664(100) & 3;
            u32 id = (*(u32*)(this_ + 0x90) >> lbl_8046D460[r]) & 0x1f;
            fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
            s32 mode = *(s32*)(this_ + 0x234);
            if (mode == 0) {
                detach__5ActorFv(this_);
            } else if (mode == 1) {
                *(s32*)(this_ + 0x230) = 1;
            } else if (mode == 2) {
                this_[0x11c] = 0;
            }
        }
        break;
    case 1:
        if (!((ActorV*)this_)->s11()) {
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    }
}

extern "C" void fn_802BF1AC(u8* this_) {
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0x1f;
    *(s32*)(this_ + 0x230) = 0;
    ((ActorV*)this_)->s03();
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D2DD4[0x94];
