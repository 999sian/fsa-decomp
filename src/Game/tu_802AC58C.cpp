// TU 0x802AC58C-0x802AC8AC.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A8338[];
extern "C" void* fn_802AC58C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8338;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802AC5EC(void) {}

extern "C" void fn_802AC5F0(void) {}

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_8023F1D4(int idx, void* pos, int a, int b, u8 c);
static const s32 lbl_8046C890[4] = {2, 3, 0, 1};

extern "C" void fn_802AC5F4(u8* this_) {
    *(u32*)(this_ + 0x234) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    if (fn_802D6A9C()[0x131f6] == 0 || fn_802D6A9C()[0x131f9] == 2) {
        *(u32*)(this_ + 0x234) = 0;
    }
    u32 params = *(u32*)(this_ + 0x90);
    fn_8023F1D4(params & 0xf, this_ + 0xc, lbl_8046C890[(params >> 4) & 3],
                *(u32*)(this_ + 0x234), (params >> 12) & 1);
    this_[0x11c] = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D15D4[0x94];
