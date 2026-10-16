#include "types.h"

extern "C" void fn_80458880(void*, s32, s32);
extern const f32 lbl_8053E4A4;
extern const f32 lbl_8053E4A8;
extern void* lbl_8053AF80;
extern "C" void fn_8019EE04(u8* p) {
    if (*(s32*)(p + 0x268) == 3 && *(s32*)(p + 0x230) != 0xf) {
        *(f32*)(p + 0x290) = lbl_8053E4A4;
        *(f32*)(p + 0x10) -= lbl_8053E4A8;
        fn_80458880(lbl_8053AF80, 6, -1);
        *(s32*)(p + 0x230) = 0xf;
    }
}

extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_8022B17C(void);
extern "C" void fn_80138B7C(void* p);
extern "C" void fn_80458508(void* p, s32 x);
extern "C" u8 fn_8022F514(s32 i);
extern "C" void fn_802372F8(s32 i, s32 a, s32 b);
extern void* lbl_804A2B18[];
extern void* lbl_8053AAF8;
extern "C" void* fn_801A024C(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = &lbl_804A2B18;
        if (*(s32*)(this_ + 0x268) == 0) {
            s32 state = *(s32*)(this_ + 0x230);
            if (state == 3 || state == 4) {
                fn_8022B17C();
                if (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 9) {
                    fn_80138B7C(lbl_8053AAF8);
                    fn_80458508(lbl_8053AF80, 0);
                }
                for (s32 i = 0; i < 4; i++) {
                    if (fn_8022F514(i) == 0) {
                        fn_802372F8(i, *(s32*)(this_ + 0x26c + i * 4), *(s32*)(this_ + 0x27c + i * 4));
                    }
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

