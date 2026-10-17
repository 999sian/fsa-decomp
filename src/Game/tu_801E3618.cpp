#include "types.h"
#include "sdk/stl/float.h"
#include "Game/SinitPoolChain.h"

extern "C" f32 lbl_8053F0BC;
extern "C" f32 lbl_8053F510;
extern "C" f32 lbl_8053F554;
extern "C" f32 lbl_8053F558;
extern "C" f32 lbl_8053F55C;
extern "C" f32 lbl_8053F560;

extern "C" f32 lbl_8053F530;
extern "C" f32 lbl_8053F514;
extern "C" f32 lbl_8053F518;
extern "C" f32 lbl_8053F51C;
extern "C" f32 lbl_8053F520;
extern "C" f32 lbl_8053F524;
extern "C" f64 lbl_8053F528;
extern "C" char* fn_802D6A9C();
extern "C" u8 fn_801CD2F8(void* obj);
extern "C" s32 fn_801F2B7C(u8* p, s32 a, s32 b, s32 c);
extern "C" u8 fn_801E3618(u8* p, void* obj, f32* pos) {
    u8 flag = 1;
    u8 ret = 0;
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;

    if (fn_801CD2F8(obj)) {
        x1 = *(f32*)(p + 0x5e0);
        y1 = *(f32*)(p + 0x5e4);
        x2 = lbl_8053F510 * (f32)*(u8*)(p + 0x5e8) + x1;
        y2 = lbl_8053F510 * (f32)*(u8*)(p + 0x5e9) + y1;
    } else {
        s32 idx = *(s32*)(p + 0x5d8);
        u8* base = (u8*)fn_802D6A9C();
        f32* q;
        if (idx < 8) {
            q = (f32*)(base + 0xcc);
        } else {
            q = (f32*)(base + 0xdc);
        }
        if (*(u32*)(p + 0x230) & 0x2000) {
            x1 = lbl_8053F514 + q[0];
            y1 = lbl_8053F518 + q[1];
            x2 = q[2] - lbl_8053F514;
            y2 = q[3] - lbl_8053F51C;
        } else {
            x1 = lbl_8053F518 + q[0];
            y1 = lbl_8053F520 + q[1];
            x2 = q[2] - lbl_8053F518;
            y2 = q[3] - lbl_8053F524;
        }
    }
    if (pos[0] < x1 || pos[1] < y1 || x2 <= pos[0] || y2 <= pos[1]) {
        flag = 0;
    }
    if (!flag) {
        ret = 1;
    }
    return ret;
}

extern "C" s32 fn_801E3A4C(u8* p) {
    s32 ret = 0;
    s32 state = *(s32*)(p + 0x248);
    u8 ok = 1;
    if (state < 9) {
        if (state != 5 && (state >= 5 || state >= 0)) {
            ok = 0;
        }
    } else if (state < 0x1b) {
        if (state >= 0x15) {
            ok = 0;
        }
    }
    if (ok && (*(u32*)(p + 0x230) & 0x2000) && fn_801CD2F8(*(void**)(p + 4))) {
        if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F530 &&
            *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F530) {
            ret = fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 1);
        }
    }
    return ret;
}

extern "C" void fn_801F317C(char* this_, void* out);
extern "C" s32 fn_8023AE34(void* a, s32 b, void* c);
extern "C" u8 fn_801CC730(s32 a, s32 b, s32 c);
extern "C" u8 fn_801CC820(s32 a, s32 b);
extern "C" void fn_801CB688(s32 a, void* b, s32 c, s32 d);
extern "C" void fn_801F0E34(char* this_, s32 a, s32 b);
extern "C" void fn_801D5D84(char* this_, s32 a);
extern "C" s32 fn_801E4348(char* this_) {
    s32 state = *(s32*)(this_ + 0x248);
    s32 ok = 1;
    f32 pos[2];
    f32 vec[3];
    u8 buf[0x24];
    s32 r;
    u8 cv;

    if (state < 9) {
        if (state == 5 || (state < 5 && state < 0)) {
            ok = 0;
        }
    } else if (state >= 0x1b || state < 0x15) {
        ok = 0;
    }
    if (!ok) {
        return 0;
    }
    if (!(*(u32*)(this_ + 0x230) & 0x2000)) {
        return 0;
    }
    fn_801F317C(this_, buf);
    r = fn_8023AE34(buf, *(s32*)(this_ + 4), pos);
    if (r < 0) {
        return 0;
    }
    state = *(s32*)(this_ + 0x248);
    if (state != 0x13 && (state < 0xc || state >= 0xe)) {
        cv = fn_801CC820(r, 0);
        if (!cv) {
            return 0;
        }
        vec[0] = pos[0];
        vec[1] = pos[1] + *(f32*)(this_ + 0x14);
        vec[2] = *(f32*)(this_ + 0x14);
        fn_801CB688(*(s32*)(this_ + 4), vec, 1, 1);
        fn_801F0E34(this_, 0x5003c, 0);
        state = *(s32*)(this_ + 0x248);
        if (state != 0x13) {
            if (state < 0x13) {
                if (state != 10) {
                    if (state < 10 || state < 0xe) {
                        return 1;
                    }
                }
            } else if (state > 0x14) {
                return 1;
            }
            fn_801D5D84(this_, 0xb);
        }
        return 1;
    }
    cv = fn_801CC730(r, 0, 0);
    if (cv != 0) {
        return 1;
    }
    return 0;
}

extern "C" f32 lbl_8053F534;
extern "C" f32 lbl_8053F538;
extern "C" f32 lbl_8053F53C;
extern "C" s32 fn_801CC29C(const f32* a, const f32* b, f32* out);
#pragma fp_contract off
extern "C" u8 fn_801E44CC(u8* p, const f32* a, f32* b, f32* n) {
    f32 box[4];
    f32 d[2];
    box[0] = *(f32*)(p + 0x80);
    box[1] = *(f32*)(p + 0x84);
    box[2] = *(f32*)(p + 0x88);
    box[3] = *(f32*)(p + 0x8c);
    box[0] += b[0];
    box[2] += b[0];
    box[1] += b[1];
    box[3] += b[1];
    s32 ret = fn_801CC29C(a, box, d);
    b[0] += d[0];
    b[1] += d[1];
    if (n != NULL) {
        f32 lenSq = d[0] * d[0] + d[1] * d[1];
        if (lenSq <= lbl_8053F534 * FLT_EPSILON) {
        } else {
            f32 scale;
            if (lenSq <= lbl_8053F530) {
                scale = lenSq;
            } else {
                f32 y = __frsqrte(lenSq);
                scale = lbl_8053F538 * y * (lbl_8053F53C - lenSq * (y * y));
            }
            d[0] *= scale;
            d[1] *= scale;
        }
        n[0] = d[0];
        n[1] = d[1];
        n[2] = lbl_8053F530;
    }
    return ret;
}
#pragma fp_contract on
extern "C" void fn_801E4618(char* param_1, f32* param_2, u8 param_3) {
    if (param_3 != 0) {
        f32 x = *(f32*)(param_1 + 0x5e0);
        f32 cx = *(u8*)(param_1 + 0x5e8) - lbl_8053F528;
        f32 out2 = lbl_8053F510 * cx + x;
        f32 y = *(f32*)(param_1 + 0x5e4);
        f32 cy = *(u8*)(param_1 + 0x5e9) - lbl_8053F528;
        f32 out3 = lbl_8053F510 * cy + y;
        param_2[0] = x;
        param_2[1] = y;
        param_2[2] = out2;
        param_2[3] = out3;
    } else {
        f32* p;
        s32 idx = *(s32*)(param_1 + 0x5d8);
        char* base = fn_802D6A9C();
        if (idx < 8) {
            p = (f32*)(base + 0xcc);
        } else {
            p = (f32*)(base + 0xdc);
        }
        if (*(u32*)(param_1 + 0x230) & 0x2000) {
            f32 a = lbl_8053F514 + p[0];
            f32 b = lbl_8053F518 + p[1];
            f32 c = p[2] - lbl_8053F514;
            f32 d = p[3] - lbl_8053F51C;
            param_2[0] = a;
            param_2[1] = b;
            param_2[2] = c;
            param_2[3] = d;
        } else {
            f32 a = lbl_8053F518 + p[0];
            f32 b = lbl_8053F520 + p[1];
            f32 c = p[2] - lbl_8053F518;
            f32 d = p[3] - lbl_8053F524;
            param_2[0] = a;
            param_2[1] = b;
            param_2[2] = c;
            param_2[3] = d;
        }
    }
}

extern "C" void fn_801E4758(u8* p) {
    f32 a = lbl_8053F554 * lbl_8053F0BC;
    f32 b = lbl_8053F558 * lbl_8053F0BC;
    f32 c = lbl_8053F510 * lbl_8053F0BC;
    f32 d = lbl_8053F55C * lbl_8053F0BC;

    *(f32*)(p + 0x80) = a;
    *(f32*)(p + 0x84) = b;
    *(f32*)(p + 0x88) = c;
    *(f32*)(p + 0x8c) = d;
}

extern "C" void fn_801E4790(u8* p, u8 flag) {
    f32 s = lbl_8053F0BC;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    if (flag) {
        s = lbl_8053F560;
    }
    a = lbl_8053F554 * s;
    b = lbl_8053F558 * s;
    c = lbl_8053F510 * s;
    d = lbl_8053F55C * s;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = b;
    *(f32*)(p + 0x68) = c;
    *(f32*)(p + 0x6c) = d;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
}

void __sinit_tu_801E3618_cpp(void) {}

