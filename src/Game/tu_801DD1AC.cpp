#include "types.h"
#include "Game/SinitPoolChain.h"

extern f32 lbl_8053F388;
extern f32 lbl_8053F38C;
extern f32 lbl_8053F390;
extern f32 lbl_8053F394;
extern f32 lbl_8053F398;
extern f32 lbl_8053F39C;
extern f32 lbl_8053F3A0;
extern "C" u8 fn_801DA904(void* p);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
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
    bool ok = false;
    if (state != 5) {
        if (state < 5) {
            if (state < 4) {
                goto skip;
            }
        } else if (state > 7) {
            goto skip;
        }
        ok = true;
    }
skip:
    if (ok) {
        f32 tmp[2];
        f32 pos[4];
        s32 res;
        pos[0] = lbl_8053F3A4 + *(f32*)(this_ + 0xc);
        pos[1] = lbl_8053F3A8 + *(f32*)(this_ + 0x10);
        pos[2] = lbl_8053F3AC + *(f32*)(this_ + 0xc);
        pos[3] = lbl_8053F3B0 + *(f32*)(this_ + 0x10);
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

extern f32 lbl_8053F398;
extern f32 lbl_8053F3B4;
extern f32 lbl_8053F3C0;
extern f32 lbl_8053F3C8;
extern f32 lbl_8053F3D8;
extern f32 lbl_8053F3DC;
extern f32 lbl_8053F3E0;
extern f32 lbl_8053F3E4;
extern f32 lbl_8053F3E8;
extern f32 lbl_8053F3EC;
extern f32 lbl_8053F3F0;
extern f32 lbl_8053F3F4;
extern f32 lbl_8053F3F8;
extern f32 lbl_8053F3FC;
extern f32 lbl_8053F400;
extern f32 lbl_8053F404;
extern f32 lbl_8053F408;
extern f32 lbl_8053F40C;
extern f32 lbl_8053F410;
extern f32 lbl_8053F414;
extern f32 lbl_8053F418;
extern f32 lbl_8053F41C;
extern f32 lbl_8053F420;
extern f32 lbl_8053F424;
extern f32 lbl_8053F428;
extern f32 lbl_8053F42C;
extern f32 lbl_8053F430;
extern f32 lbl_8053F434;
extern f32 lbl_8053F438;
extern f32 lbl_8053F43C;
extern f32 lbl_8053F440;
extern f32 lbl_8053F444;
extern f32 lbl_8053F448;
extern "C" u8 fn_801DA904(void* p);
extern "C" s32 fn_801DA96C(void* p);
extern "C" void fn_801DE12C(u8* this_) {
    s32 state = *(s32*)(this_ + 0x248);
    s32 frame;

    if (state >= 0x13) {
        if (state >= 0x15) {
            goto frame_anim;
        }
    } else if (state >= 4 || state < 0) {
        goto frame_anim;
    }

    *(f32*)(this_ + 0x60) = 1.0f;
    *(f32*)(this_ + 0x64) = 1.0f;
    *(f32*)(this_ + 0x68) = -1.0f;
    *(f32*)(this_ + 0x6c) = -1.0f;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    return;

frame_anim:
    frame = fn_801DA96C(this_ + 0x2a8);
    switch (frame) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 11: case 12:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -16.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 6: case 7:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -22.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 10.0f;
        break;
    case 8:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -25.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 7.0f;
        break;
    case 9:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -28.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 4.0f;
        break;
    case 10:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -31.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 1.0f;
        break;
    case 13: case 14: case 15: case 16:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -48.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 17: case 23:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -40.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 18: case 19: case 20: case 21: case 22:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -32.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 24:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -52.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    case 25:
        *(f32*)(this_ + 0x60) = -41.0f;
        *(f32*)(this_ + 0x64) = -41.0f;
        *(f32*)(this_ + 0x68) = 6.0f;
        *(f32*)(this_ + 0x6c) = 9.0f;
        break;
    case 26:
        *(f32*)(this_ + 0x60) = -41.0f;
        *(f32*)(this_ + 0x64) = -47.0f;
        *(f32*)(this_ + 0x68) = 6.0f;
        *(f32*)(this_ + 0x6c) = 3.0f;
        break;
    case 27:
        *(f32*)(this_ + 0x60) = -38.0f;
        *(f32*)(this_ + 0x64) = -61.0f;
        *(f32*)(this_ + 0x68) = 8.0f;
        *(f32*)(this_ + 0x6c) = -8.0f;
        break;
    case 28:
        *(f32*)(this_ + 0x60) = -38.0f;
        *(f32*)(this_ + 0x64) = -66.0f;
        *(f32*)(this_ + 0x68) = 10.0f;
        *(f32*)(this_ + 0x6c) = -12.0f;
        break;
    case 29:
        *(f32*)(this_ + 0x60) = -35.0f;
        *(f32*)(this_ + 0x64) = -68.0f;
        *(f32*)(this_ + 0x68) = 14.0f;
        *(f32*)(this_ + 0x6c) = -16.0f;
        break;
    case 30:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -72.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = -36.0f;
        break;
    case 31:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -76.0f;
        *(f32*)(this_ + 0x68) = 28.0f;
        *(f32*)(this_ + 0x6c) = -36.0f;
        break;
    case 32:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -68.0f;
        *(f32*)(this_ + 0x68) = 28.0f;
        *(f32*)(this_ + 0x6c) = -28.0f;
        break;
    case 33:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -60.0f;
        *(f32*)(this_ + 0x68) = 28.0f;
        *(f32*)(this_ + 0x6c) = -20.0f;
        break;
    case 34: case 35: case 36: case 37: case 38: case 39: case 40:
    case 41: case 42: case 43: case 44: case 45: case 46: case 47:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -36.0f;
        *(f32*)(this_ + 0x68) = 28.0f;
        *(f32*)(this_ + 0x6c) = 16.0f;
        break;
    }

    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > 0.0f &&
        (*(u32*)(this_ + 0x230) & 0x2000) && fn_801DA904(this_ + 0x2a8)) {
        f32 x0 = *(f32*)(this_ + 0x60);
        f32 x1 = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x60) = -x1;
        *(f32*)(this_ + 0x68) = -x0;
    }
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
}

void __sinit_tu_801DD1AC_cpp(void) {}

