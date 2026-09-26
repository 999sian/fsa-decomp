// TU 0x802B334C-0x802B3674.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A85E0[];
extern "C" void* fn_802B334C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A85E0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B33AC(void) {}

extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 id);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);

static const u32 lbl_8046CA98[4] = {0x7c00000, 0x3e0000, 0x1f000, 0xf80};
static const u32 lbl_8046CAA8[4] = {0x16, 0x11, 0xc, 0x7};

extern "C" void fn_802B33B0(u8* this_) {
    u32 bits;
    s32 count;
    s32 i;
    count = 0;
    for (i = 0; i < 4; i++) {
        bits = *(u32*)(this_ + 0x90) & lbl_8046CA98[i];
        if (bits != 0 && fn_802D800C(fn_802D6A9C(), bits >> lbl_8046CAA8[i])) {
            count++;
        }
    }
    if (count != 0) {
        fn_801F0E34(this_, 0x30024, 0);
    }
}

extern "C" void fn_802B344C(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D1ED4[0x94];
