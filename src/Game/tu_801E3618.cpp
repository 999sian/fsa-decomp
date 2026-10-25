#include "types.h"
#include "sdk/stl/float.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"

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
extern "C" s32 fn_801CC29C(const f32* a, const f32* b, f32* out);
extern "C" s32 fn_801F2B7C(u8* p, s32 a, s32 b, s32 c);
extern "C" void fn_801F0E34(char* this_, s32 a, s32 b);
extern "C" void fn_801D5D84(char* this_, s32 a);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F82CC(void* mgr, void* self, u8 room, f32 r);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" u8 fn_801F37AC(void* p, s32 a, JGeometry::TVec3f* d, s32 b, s32 c, s32 e);
extern "C" void fn_801D63D0(char* p);
extern "C" void fn_801E4D54(char* p);
extern "C" void fn_80217A74(char* p);
extern "C" void fn_801F3128(char* p, f32* out);
extern "C" void fn_801D6D38(char* p, f32* d);
extern "C" s32 fn_8023DE58(s32 i);
// Whether player `player` is in room `room`.
static inline BOOL PlayerInRoom(s32 player, s32 room) {
    return fn_8023DE58(player) == room;
}
extern "C" f32 lbl_8053F54C;
extern "C" f32 lbl_8053F550;
extern "C" f32 lbl_8053F534;
extern "C" f32 lbl_8053F538;
extern "C" f32 lbl_8053F53C;
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

extern "C" u8 fn_801E376C(char* this_) {
    u8 ret = 0;
    s32 state = *(s32*)(this_ + 0x248);
    u8 ok = 1;
    if (state < 9) {
        if (state == 5 || (state < 5 && state < 0)) {
            ok = 0;
        }
    } else if (state >= 0x1b || state < 0x15) {
        ok = 0;
    }
    if (ok && !(*(u32*)(this_ + 0x230) & 0x1000) && !(*(u32*)(this_ + 0x230) & 0x2000)) {
        if (*(f32*)(this_ + 0x88) - *(f32*)(this_ + 0x80) > lbl_8053F530 &&
            *(f32*)(this_ + 0x8c) - *(f32*)(this_ + 0x84) > lbl_8053F530) {
            f32 rect[4];
            f32 box[4];
            f32 d[2];
            if (fn_801CD2F8(*(void**)(this_ + 4))) {
                f32 cy = (f32)*(u8*)(this_ + 0x5e9);
                f32 cx = (f32)*(u8*)(this_ + 0x5e8);
                f32 y = *(f32*)(this_ + 0x5e4);
                f32 x = *(f32*)(this_ + 0x5e0);
                rect[0] = x;
                rect[1] = y;
                rect[2] = lbl_8053F510 * cx + x;
                rect[3] = lbl_8053F510 * cy + y;
            } else {
                s32 idx = *(s32*)(this_ + 0x5d8);
                u8* base = (u8*)fn_802D6A9C();
                f32* q;
                if (idx < 8) {
                    q = (f32*)(base + 0xcc);
                } else {
                    q = (f32*)(base + 0xdc);
                }
                if (*(u32*)(this_ + 0x230) & 0x2000) {
                    rect[3] = q[3] - lbl_8053F51C;
                    rect[2] = q[2] - lbl_8053F514;
                    rect[0] = lbl_8053F514 + q[0];
                    rect[1] = lbl_8053F518 + q[1];
                } else {
                    rect[3] = q[3] - lbl_8053F524;
                    rect[2] = q[2] - lbl_8053F518;
                    rect[0] = lbl_8053F518 + q[0];
                    rect[1] = lbl_8053F520 + q[1];
                }
            }
            box[0] = *(f32*)(this_ + 0x80);
            box[1] = *(f32*)(this_ + 0x84);
            box[2] = *(f32*)(this_ + 0x88);
            box[3] = *(f32*)(this_ + 0x8c);
            box[0] += *(f32*)(this_ + 0xc);
            box[1] += *(f32*)(this_ + 0x10);
            box[2] += *(f32*)(this_ + 0xc);
            box[3] += *(f32*)(this_ + 0x10);
            ret = fn_801CC29C(rect, box, d);
            *(f32*)(this_ + 0xc) += d[0];
            *(f32*)(this_ + 0x10) += d[1];
            if (this_ + 0x264 != NULL) {
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
                f32* n = (f32*)(this_ + 0x264);
                n[0] = d[0];
                n[1] = d[1];
                n[2] = lbl_8053F530;
            }
        }
    }
    return ret;
}

extern "C" s32 fn_801E3A4C(u8* p) {
    s32 ret = 0;
    s32 state = *(s32*)(p + 0x248);
    u8 ok = 1;
    switch (state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
        ok = 0;
        break;
    }
    if (ok && (*(u32*)(p + 0x230) & 0x2000) && fn_801CD2F8(*(void**)(p + 4))) {
        if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F530 &&
            *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F530) {
            ret = fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 1);
        }
    }
    return ret;
}

extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_8053F540;
extern "C" f32 lbl_8053F544;
extern "C" f32 lbl_8053F548;
extern "C" u8 lbl_8053F0C4;
extern "C" s32 lbl_8053F0C0;
extern "C" void fn_801F31C4(char* p, f32* out);
extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_80236B50(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" u8 fn_8022D75C(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_80235448(s32 i);
extern "C" JGeometry::TVec3f* fn_8023E724(s32 i);
extern "C" JGeometry::TVec3f* fn_8023E578(s32 i);
extern "C" s32 fn_801F285C(char* p, s32 a, s32* out, s32 b, s32 i);
extern "C" s32 fn_8023B6CC(s32 i);
extern "C" void fn_801D7638(void* p);
extern "C" void fn_801D76B4(void* p);
extern "C" void fn_801D6D08(void* p);
extern "C" u8 fn_801E3B2C(char* this_) {
    s32 k;
    s32 room;
    s32 j;
    s32 i;
    u8 ret = 0;
    s32 state = *(s32*)(this_ + 0x248);
    u8 ok = 1;
    s32 out;
    f32 rect[4];

    switch (state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
        ok = 0;
        break;
    }
    if (ok && state != 0x13 && (*(u32*)(this_ + 0x230) & 0x2000) &&
        *(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053F530 &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053F530) {
        if (*((u8*)lbl_8053AAF8 + 0x7e) != 0 && !fn_801CD2F8(*(void**)(this_ + 4)) &&
            *(s32*)(this_ + 0x248) != 0xb && *(u8*)(this_ + 0x5d1) == 0) {
            fn_801F31C4(this_, rect);
            rect[0] -= lbl_8053F540;
            rect[1] -= lbl_8053F540;
            rect[2] += lbl_8053F540;
            rect[3] += lbl_8053F540;
            for (k = 0; k < 4; k++) {
                if (fn_8023F264(k) && !fn_80236B50(k) && !fn_80230188(k) && !fn_8022D75C(k) &&
                    (room = *(s32*)(this_ + 4), fn_8023DE58(k) == room) && fn_80235448(k) &&
                    fn_8023E724(k)->z <= lbl_8053F544 && fn_8023E724(k)->z < fn_8023E578(k)->z &&
                    ItemBase_inArea(rect, &fn_8023E724(k)->x)) {
                    JGeometry::TVec3f* pl = fn_8023E724(k);
                    f32 dy = *(f32*)(this_ + 0x10) - pl->y;
                    f32 dx = *(f32*)(this_ + 0xc) - pl->x;
                    *(u8*)(this_ + 0x5d1) = lbl_8053F0C4;
                    f32 a = JMath::atanTable_.atan2_(dx, dy);
                    *(s16*)(this_ + 0x5d2) = (s16)(a * lbl_8053F548);
                    fn_80217A74(this_ + 0x448);
                    fn_801F0E34(this_, 0x40062, 0);
                    break;
                }
            }
        }
        if (fn_801CD2F8(*(void**)(this_ + 4))) {
            for (j = 0; j < 4; j++) {
                if (fn_801F285C(this_, 0, &out, 1, j) == j) {
                    if (fn_801F37AC(this_, fn_8023B6CC(j), fn_8023E724(j), 2, out, j)) {
                        ret = 1;
                        if (fn_80235448(j)) {
                            *(u32*)(this_ + 0x230) |= 0x10000;
                            fn_801D63D0(this_);
                        }
                    }
                }
            }
            if (ret) {
                *(s32*)(this_ + 0xf8) = 0;
                fn_801F0E34(this_, 0x40005, 0);
                if (*(s32*)(this_ + 0x508) != 4) {
                    fn_801D7638(this_ + 0x4c4);
                    fn_801D76B4(this_ + 0x4c4);
                }
                if (*(s32*)(this_ + 0x108) <= lbl_8053F0C0) {
                    *(u32*)(this_ + 0x230) |= 0x8000;
                    *(s32*)(this_ + 0x108) = 10;
                }
            }
        } else {
            if (*((u8*)lbl_8053AAF8 + 0x7e) != 0 && *(s32*)(this_ + 0x248) != 0xb) {
                return 0;
            }
            if (*(s32*)(this_ + 0x248) != 9) {
                for (i = 0; i < 4; i++) {
                    if (fn_801F285C(this_, 0, &out, 1, i) == i && fn_80235448(i)) {
                        if (fn_801F37AC(this_, fn_8023B6CC(i), fn_8023E724(i), 2, out, i)) {
                            f32 zero = lbl_8053F530;
                            *(u32*)(this_ + 0x230) |= 0x10000;
                            *(s32*)(this_ + 0xf8) = 0;
                            *(f32*)(this_ + 0x3c) = zero;
                            *(f32*)(this_ + 0x40) = zero;
                            *(f32*)(this_ + 0x44) = zero;
                            *(f32*)(this_ + 0x254) = zero;
                            fn_801D6D08(this_ + 0x52c);
                            fn_80217A74(this_ + 0x448);
                            fn_801F0E34(this_, 0x40005, 0);
                            if (*(s32*)(this_ + 0x108) <= 0) {
                                *(s32*)(this_ + 0xd8) = 0x10;
                                *(s32*)(this_ + 0xdc) = 0x10;
                                fn_801D5D84(this_, 0x18);
                                fn_801D7638(this_ + 0x4c4);
                                fn_801D76B4(this_ + 0x4c4);
                            } else {
                                *(s32*)(this_ + 0xd8) = 0xb4;
                                *(s32*)(this_ + 0xdc) = 0xb4;
                                fn_801D63D0(this_);
                                if (*(s32*)(this_ + 0x508) != 4) {
                                    fn_801D7638(this_ + 0x4c4);
                                    fn_801D76B4(this_ + 0x4c4);
                                }
                                if (*(s32*)(this_ + 0x108) <= lbl_8053F0C0) {
                                    fn_801D5D84(this_, 10);
                                } else {
                                    *(u32*)(this_ + 0x230) |= 0x8000;
                                }
                            }
                            ret = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return ret;
}

extern "C" u8 fn_801E4094(char* this_) {
    u8 ret = 0;
    s32 state = *(s32*)(this_ + 0x248);
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
    if (ok && !(*(u32*)(this_ + 0x230) & 0x2000)) {
        f32 x1 = *(f32*)(this_ + 0x60);
        f32 y1;
        f32 x2 = *(f32*)(this_ + 0x68);
        f32 y2;
        if (x2 - x1 > lbl_8053F530) {
            y1 = *(f32*)(this_ + 0x64);
            y2 = *(f32*)(this_ + 0x6c);
            if (y2 - y1 > lbl_8053F530) {
                *(f32*)(this_ + 0x60) *= lbl_8053F54C;
                *(f32*)(this_ + 0x64) *= lbl_8053F54C;
                *(f32*)(this_ + 0x68) *= lbl_8053F54C;
                *(f32*)(this_ + 0x6c) *= lbl_8053F54C;
                s32 id = fn_801F82CC(fn_801F856C(), this_, *(u8*)(this_ + 0x195), lbl_8053F550);
                *(f32*)(this_ + 0x60) = x1;
                *(f32*)(this_ + 0x64) = y1;
                *(f32*)(this_ + 0x68) = x2;
                *(f32*)(this_ + 0x6c) = y2;
                if (id >= 0 && id != *(s32*)(this_ + 0x198)) {
                    char* obj = fn_801F666C(fn_801F856C(), id);
                    if (obj != 0 && *(u32*)(obj + 0x1a0) == 0x48424D42 && *(u16*)(obj + 0x94) == 1) {
                        JGeometry::TVec3f d(*(JGeometry::TVec3f*)(this_ + 0xc));
                        d.sub(*(JGeometry::TVec3f*)(obj + 0x3c));
                        ret = fn_801F37AC(this_, 0, &d, 2, *(s32*)(obj + 0x168), *(s32*)(obj + 0x110));
                        if (ret) {
                            f32 zero = lbl_8053F530;
                            *(u8*)(obj + 0x164) = 1;
                            *(s32*)(this_ + 0xf8) = 0;
                            *(f32*)(this_ + 0x3c) = zero;
                            *(f32*)(this_ + 0x40) = zero;
                            *(f32*)(this_ + 0x44) = zero;
                            *(s32*)(this_ + 0xd8) = 0xb4;
                            *(s32*)(this_ + 0xdc) = 0xb4;
                            *(f32*)(this_ + 0x254) = zero;
                            fn_801D63D0(this_);
                            fn_801F0E34(this_, 0x40005, 0);
                            fn_801E4D54(this_);
                            fn_80217A74(this_ + 0x448);
                            f32 out[2];
                            f32 pt[2];
                            fn_801F3128(this_, out);
                            pt[0] = out[0] - *(f32*)(obj + 0xc);
                            pt[1] = out[1] - (*(f32*)(obj + 0x10) - *(f32*)(obj + 0x14));
                            fn_801D6D38(this_ + 0x52c, pt);
                            *(u8*)(this_ + 0x5cd) += 1;
                            if (*(u8*)(this_ + 0x5cd) >= *(u8*)(this_ + 0x5cc)) {
                                fn_801D5D84(this_, 6);
                            }
                        }
                    }
                }
            }
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
    s32 ret = 0;
    u8 ok = 1;
    f32 pos[2];
    f32 vec[3];
    u8 buf[0x1c];
    s32 r;
    u8 cv;

    switch (state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
        ok = 0;
        break;
    }
    if (ok) {
        if (*(u32*)(this_ + 0x230) & 0x2000) {
            fn_801F317C(this_, buf);
            r = fn_8023AE34(buf, *(s32*)(this_ + 4), pos);
            if (r >= 0) {
                state = *(s32*)(this_ + 0x248);
                switch (state) {
                case 0xc:
                case 0xd:
                case 0x13:
                    cv = fn_801CC730(r, 0, 0);
                    if (cv) {
                        ret = 1;
                    }
                    break;
                default:
                    cv = fn_801CC820(r, 0);
                    if (cv) {
                        vec[2] = *(f32*)(this_ + 0x14);
                        vec[0] = pos[0];
                        vec[1] = pos[1] + *(f32*)(this_ + 0x14);
                        fn_801CB688(*(s32*)(this_ + 4), vec, 1, 1);
                        fn_801F0E34(this_, 0x5003c, 0);
                        state = *(s32*)(this_ + 0x248);
                        switch (state) {
                        case 10:
                        case 0xe:
                        case 0xf:
                        case 0x10:
                        case 0x11:
                        case 0x12:
                        case 0x14:
                            fn_801D5D84(this_, 0xb);
                            break;
                        }
                        ret = 1;
                    }
                    break;
                }
            }
        }
    }
    return ret;
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
        f32 y = *(f32*)(param_1 + 0x5e4);
        f32 out2 = lbl_8053F510 * (f32)*(u8*)(param_1 + 0x5e8) + x;
        f32 out3 = lbl_8053F510 * (f32)*(u8*)(param_1 + 0x5e9) + y;
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
    f32 s = lbl_8053F0BC;
    f32 a = lbl_8053F554 * s;
    f32 b = lbl_8053F558 * s;
    f32 c = lbl_8053F510 * s;
    f32 d = lbl_8053F55C * s;

    *(f32*)(p + 0x80) = a;
    *(f32*)(p + 0x84) = b;
    *(f32*)(p + 0x88) = c;
    *(f32*)(p + 0x8c) = d;
}

extern "C" void fn_801E4790(u8* p, u8 flag) {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 s = lbl_8053F0BC;

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

