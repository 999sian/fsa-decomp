#include "types.h"
#include "Game/SinitPoolChain.h"

extern f32 lbl_8053F388;
extern f32 lbl_8053F38C;
extern f32 lbl_8053F390;
extern "C" s32 fn_801DD1AC(u8* this_) {
    s32 result = 0;
    if (!(*(u32*)(this_ + 0x230) & 0x1000)) {
        if (*(f32*)(this_ + 0xc) < *(f32*)(this_ + 0x2d4)) {
            *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x2d4);
            result = 1;
            f32 b = lbl_8053F38C;
            f32 a = lbl_8053F388;
            *(f32*)(this_ + 0x264) = a;
            *(f32*)(this_ + 0x268) = b;
            *(f32*)(this_ + 0x26c) = b;
        } else if (*(f32*)(this_ + 0x2ec) < *(f32*)(this_ + 0xc)) {
            *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x2ec);
            result = 1;
            f32 b = lbl_8053F38C;
            f32 a = lbl_8053F390;
            *(f32*)(this_ + 0x264) = a;
            *(f32*)(this_ + 0x268) = b;
            *(f32*)(this_ + 0x26c) = b;
        }
        if (*(f32*)(this_ + 0x10) > *(f32*)(this_ + 0x2d0)) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x2d0);
            result = 1;
            f32 b = lbl_8053F390;
            f32 a = lbl_8053F38C;
            *(f32*)(this_ + 0x264) = a;
            *(f32*)(this_ + 0x268) = b;
            *(f32*)(this_ + 0x26c) = a;
        } else if (*(s32*)(this_ + 0x248) < 0x11 && *(s32*)(this_ + 0x248) > 10 && *(f32*)(this_ + 0x10) < *(f32*)(this_ + 0x2d8)) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x2d8);
            result = 1;
            f32 b = lbl_8053F388;
            f32 a = lbl_8053F38C;
            *(f32*)(this_ + 0x264) = a;
            *(f32*)(this_ + 0x268) = b;
            *(f32*)(this_ + 0x26c) = a;
        }
    }
    return result;
}

extern "C" s32 fn_8023AE34(f32* pos, s32 arg, f32* out);
extern "C" s32 fn_8023AA18(f32* pos, s32 arg, f32* out);
extern "C" s32 fn_8023AC74(f32* pos, s32 arg, f32* out);
extern "C" s32 fn_8023AD54(f32* pos, s32 arg, f32* out);
extern "C" void fn_801D9C58(void* this_, s32 state);
extern f32 lbl_8053F3B0;
extern f32 lbl_8053F3A8;
extern f32 lbl_8053F3AC;
extern f32 lbl_8053F3A4;
extern "C" s32 fn_801DE018(char* this_) {
    s32 r = 0;
    s32 state = *(s32*)(this_ + 0x248);
    s32 ok = 0;
    if (state != 5) {
        if (state < 5) {
            if (state < 4) {
                goto skip;
            }
        } else if (state > 7) {
            goto skip;
        }
        ok = 1;
    }
skip:
    if (ok) {
        f32 pos[4];
        f32 tmp[4];
        s32 res;
        pos[0] = lbl_8053F3A4 + *(f32*)(this_ + 0xc);
        pos[1] = lbl_8053F3B0 + *(f32*)(this_ + 0x10);
        pos[2] = lbl_8053F3A8 + *(f32*)(this_ + 0x10);
        pos[3] = lbl_8053F3AC + *(f32*)(this_ + 0xc);
        res = fn_8023AE34(pos, *(s32*)(this_ + 4), tmp);
        if (res >= 0) {
            res = fn_8023AA18(pos, *(s32*)(this_ + 4), tmp);
            if (res >= 0) {
                res = fn_8023AC74(pos, *(s32*)(this_ + 4), tmp);
                if (res >= 0) {
                    res = fn_8023AD54(pos, *(s32*)(this_ + 4), tmp);
                }
            }
        }
        if (res >= 0) {
            fn_801D9C58(this_, 5);
            r = 1;
        }
    }
    return r;
}

void __sinit_tu_801DD1AC_cpp(void) {}

