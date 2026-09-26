// TU 0x802C94F4-0x802C9944.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A8EA0[];
extern "C" void* fn_802C94F4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8EA0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802C9554(void) {}

extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 id);
extern "C" void fn_8030C210(void* p, void* pos);
extern "C" u8 fn_8030C2A8(void* p, void* pos);
extern u8* lbl_8053AB10;

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

extern "C" void fn_802C9558(u8* this_) {
    s32 sw;
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        sw = *(u32*)(this_ + 0x234);
        if (sw != 0 && !fn_802D800C(fn_802D6A9C(), sw)) {
            break;
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        if (fn_8030C2A8(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc) == 1) {
            if ((*(u32*)(this_ + 0x90) >> 27) != 0) {
                ((ActorV*)this_)->s10(0xff, 1);
            }
            *(s32*)(this_ + 0x230) = 1;
            *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x23c);
        }
        break;
    case 1:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        if (*(s32*)(this_ + 0x240) == 0) {
            this_[0x11c] = 0;
        } else {
            *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x240) - 1;
        }
        break;
    case 2:
        sw = *(u32*)(this_ + 0x234);
        if (sw != 0 && !fn_802D800C(fn_802D6A9C(), sw)) {
            break;
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        if (fn_8030C2A8(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc) == 1) {
            if ((*(u32*)(this_ + 0x90) >> 27) != 0) {
                ((ActorV*)this_)->s10(0xff, 1);
            }
        }
        break;
    }
}

extern "C" void fn_802C96E0(u8* this_) {
    *(u32*)(this_ + 0x234) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    *(u32*)(this_ + 0x23c) = *(u32*)(this_ + 0x90) & 0xfff;
    *(s32*)(this_ + 0x240) = 0;
    if (*(s32*)(this_ + 0x23c) == 0) {
        *(s32*)(this_ + 0x230) = 2;
    } else {
        *(s32*)(this_ + 0x230) = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D33D4[0x94];
