#include "types.h"
#include "Game/ItemBase.h"

extern "C" void fn_80458880(void*, s32, s32);
extern const f32 lbl_8053E4A4;
extern const f32 lbl_8053E4A8;
extern void* lbl_8053AF80;
extern "C" void fn_801F02BC(void* p, f32 a, f32 b, const char* s, s32 x, s32 y, s32 z, s32 w, s32 v);
extern "C" u8 fn_8022F478(s32 i);
extern "C" s32 fn_8022F340(u32 p);
extern "C" void fn_8019E480(u8* p);
extern "C" void fn_8019E7A4(u8* p = 0);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern const f32 lbl_8053E464;
extern const char lbl_80468494[];
extern s32 lbl_804C6330[];
extern void* lbl_8053AF10;
extern const f32 lbl_8053E460;
extern const char lbl_80468480[];
extern "C" void fn_8019E37C(u8* p) {
    s32 state = *(s32*)(p + 0x268);
    switch (state) {
    case 0: {
        s32 i;
        fn_801F02BC(p, lbl_8053E460, lbl_8053E460, lbl_80468480, *(s32*)(p + 0x264) + 0x1ab, 0, 0, 0, 0);
        if (p[0x28c] != 0) {
            for (i = 0; i < 4; i++) {
                if (!fn_8022F478(i)) {
                    s32 idx = fn_8022F340(i);
                    ((u8*)lbl_8053AF10)[0x2c] |= (u8)(1 << idx);
                    ((u8*)lbl_8053AF10)[idx + 0x28] = (u8)(10 - lbl_804C6330[idx]);
                }
            }
        }
        break;
    }
    case 1:
    case 2:
    case 4:
        fn_8019E480(p);
        break;
    case 3:
        fn_8019E7A4();
        break;
    }
}

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
    s32 i;
    u8* cur;
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2B18;
        if (*(s32*)(this_ + 0x268) == 0) {
            s32 state = *(s32*)(this_ + 0x230);
            if (state == 3 || state == 4) {
                fn_8022B17C();
                if (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 9) {
                    fn_80138B7C(lbl_8053AAF8);
                    fn_80458508(lbl_8053AF80, 0);
                }
                for (i = 0, cur = this_; i < 4; i++, cur += 4) {
                    if (fn_8022F514(i) == 0) {
                        fn_802372F8(i, *(s32*)(cur + 0x26c), *(s32*)(cur + 0x27c));
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

