// TU 0x803372D0-0x80337650.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804ABAE8[];
extern "C" void* fn_803372D0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804ABAE8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern "C" s32 fn_803075AC(u32 caller, s32 room, void* pos, s32 id, bool on, s32 mode, s32 target, s32 kind,
                           bool b, s32 d);

extern "C" void fn_80337330(u8* this_) {
    fn_801F06F0(this_, "enemy_both2_sob.bin", *(s32*)(this_ + 0x234) + 0x1af, 0, -1, 1.0f, 1.0f);
    fn_803075AC(*(u32*)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x234) + 0x1af, 0, 2, -1, 0,
                0, 0);
}

extern "C" void fn_803373B0(u8* this_) {
    (*(s32*)(this_ + 0x230))--;
    if (*(s32*)(this_ + 0x230) <= 0) {
        if ((*(u32*)(this_ + 0x90) & 0xf) == 0) {
            (*(s32*)(this_ + 0x234))++;
            *(s32*)(this_ + 0x234) = *(s32*)(this_ + 0x234) & 1;
        }
        *(s32*)(this_ + 0x230) = 10;
    }
}

extern "C" void fn_803373F8(u8* this_) {
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x230) = 10;
    if ((*(u32*)(this_ + 0x90) & 0xf) == 2) {
        *(s32*)(this_ + 0x234) = 1;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_80509764[0x94];
