#include "types.h"

extern "C" const f32 lbl_80541AE0;
extern "C" void* lbl_804AB308[];
extern "C" const f32 lbl_80541ADC;
extern "C" const f32 lbl_80541AE4;
extern "C" s32 fn_8022461C(f32* pos);
extern "C" u16 fn_80226850(f32* pos, s32 p2);
extern "C" u8 fn_802DEB58(void);
extern "C" u8 fn_802DE9A0(void);
extern "C" void* fn_802D6A9C(void);
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, short);
extern "C" s32 fn_801F0E34(void* a, u32 code, u32 z);
extern "C" s32 fn_80236228(s32 idx);
extern "C" s32 fn_80237774(s32 idx);
extern "C" u8 fn_8023F264(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" u8 fn_80230188(s32 idx);
extern "C" const f32 lbl_80541AD8;
extern "C" const f32 lbl_80541AE8;
extern "C" const f32 lbl_80541B2C;
extern "C" const f32 lbl_80541B48;
extern "C" const f32 lbl_80541B4C;
extern "C" char* lbl_8053AAF8;
extern "C" const f32 lbl_80541AEC;
extern "C" const f32 lbl_80541B38;
extern "C" s32 lbl_80471760[];
extern "C" s32 lbl_80471784[][7];

extern "C" void fn_803221F4(char* p) {
    *(f32*)(p + 0x44) = lbl_80541AE0;
    *(f32*)(p + 0x40) = lbl_80541AE0;
    *(f32*)(p + 0x3c) = lbl_80541AE0;
    if (*(s32*)(p + 0x278) <= 0xb4) {
        *(s32*)(p + 0x278) = 0xb6;
    }
}

extern "C" s32 fn_8032221C(char* p, s32 p2, f32* pos) {
    s32 b;
    s32 a;
    s32 t;
    f32 x;
    f32 y;

    t = (u16)fn_8022461C(pos);
    fn_80226850(pos, p2);
    if ((u32)(t - 0x10) <= 6 || t == 0x17) {
        *(s32*)(p + 0x274) = 1;
        return 0;
    }
    if (*(s32*)(p + 0x2a8) == 0 && t == 3) {
        if (*(f32*)(p + 0x14) < lbl_80541AD8) {
            x = lbl_80541ADC + (f32)((s32)pos[0] & 0xfff0);
            y = lbl_80541ADC + (f32)((s32)pos[1] & 0xfff0);
            *(f32*)(p + 0x2b8) = x;
            *(f32*)(p + 0x2bc) = y;
            *(s32*)(p + 0x2a8) = 1;
            *(f32*)(p + 0x14) = lbl_80541AE0;
            *(f32*)(p + 0x3c) = lbl_80541AE0;
            *(f32*)(p + 0x40) = lbl_80541AE0;
            *(f32*)(p + 0x44) = lbl_80541AE0;
        }
        return 0;
    }
    if (t == 0xe && *(u8*)(p + 0x2ac) == 0) {
        if (*(f32*)(p + 0x14) < lbl_80541AD8) {
            if (fn_802DEB58() != 0) {
                a = 0x45e;
                b = 0x45f;
            } else {
                if (fn_802DE9A0() != 0) {
                    a = 0x2a9;
                    b = 0x2aa;
                    fn_801F0E34(p, 0x5005f, 0);
                } else {
                    if (*(f32*)(p + 0x14) < lbl_80541AD8) {
                        x = lbl_80541ADC + (f32)((s32)pos[0] & 0xfff0);
                        y = lbl_80541ADC + (f32)((s32)pos[1] & 0xfff0);
                        *(f32*)(p + 0x2b8) = x;
                        *(f32*)(p + 0x2bc) = y;
                        *(s32*)(p + 0x2a8) = 1;
                        *(u8*)(p + 0x2ac) = 1;
                        *(f32*)(p + 0x14) = lbl_80541AE0;
                        *(f32*)(p + 0x3c) = lbl_80541AE0;
                        *(f32*)(p + 0x40) = lbl_80541AE0;
                        *(f32*)(p + 0x44) = lbl_80541AE0;
                    }
                    return 0;
                }
            }
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_80541AE4, a, -1, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_80541AE4, b, 0, 0, 0, 0, 1);
            *(u8*)(p + 0x2ac) = 1;
            detach__5ActorFv(p);
        }
        return 0;
    }
    if ((t == 0xd || t == 0x3b) && *(u8*)(p + 0x2ac) == 0) {
        if (*(f32*)(p + 0x14) < lbl_80541AD8) {
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_80541AE4, 0x3d0, 0, 1, 0, 0, 1);
            detach__5ActorFv(p);
            *(u8*)(p + 0x2ac) = 1;
        }
        return 0;
    }
    if (t != 0 && t != 3 && t != 0xe && t != 0xd && t != 0x3b && t != 4 && t != 5 && t != 6 && t != 7 && t != 2 && t != 0x50 && t != 0xc && t != 0x27 && t != 0x28 && t != 0x29 && t != 0x2a && t != 0x2b && t != 0x2c && t != 0x2d && t != 0x2e && t != 0x2f && t != 0x20 && t != 0x39 && t != 0x3a && t != 0x4c && t != 0x4d && t != 0x4e && t != 0x4f) {
        if (fn_80226850(pos, p2) == 0x3a || fn_80226850(pos, p2) == 0x3d) {
            *(s32*)(p + 0x274) = 0;
            return 0;
        }
        if (t == 0x25) {
            if (*(s32*)(p + 0x274) == 0 && *(u8*)((char*)fn_802D6A9C() + 0x171) == 0) {
                return 1;
            }
            return 0;
        }
        if (t == 0x26) {
            if (*(s32*)(p + 0x274) == 0 && *(u8*)((char*)fn_802D6A9C() + 0x171) == 1) {
                return 1;
            }
            return 0;
        }
        if (*(s32*)(p + 0x274) == 0 && (t != 0x22 || *(u8*)((char*)fn_802D6A9C() + 0x170) == 1)) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_803226EC(char* p) {
    s32 mode = *(s32*)(p + 0x230);
    if (mode == 0 || (u32)(mode - 5) <= 3 || *(u16*)(p + 0x94) == 2) {
        if (*(s32*)(p + 0x248) <= 0) {
            *(s32*)(p + 0x264) ^= 1;
            *(s32*)(p + 0x248) = 10;
        }
    } else if (mode == 2) {
        if (*(u8*)(p + 0x2a6) == 1) {
            if (*(s32*)(p + 0x260) > 0) {
                if (*(s32*)(p + 0x248) <= 0) {
                    *(s32*)(p + 0x264) ^= 1;
                    *(s32*)(p + 0x248) = 10;
                }
                *(s32*)(p + 0x260) -= 1;
            } else {
                u32 bits;
                char* rng = lbl_8053AAF8;
                *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
                bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
                *(s32*)(p + 0x24c) = (s32)(lbl_80541B38 * (*(f32*)&bits - lbl_80541AEC)) + 0x28;
                *(s32*)(p + 0x268) = *(s32*)(p + 0x2b4) - *(s32*)(p + 0x24c) % 7;
                if (*(s32*)(p + 0x268) < 0) {
                    *(s32*)(p + 0x268) += 7;
                }
                *(s32*)(p + 0x264) = lbl_80471784[*(s32*)(p + 0x288)][*(s32*)(p + 0x268)];
                *(s32*)(p + 0x248) = 5;
                *(u8*)(p + 0x2a6) = 0;
            }
        } else if (*(s32*)(p + 0x248) <= 0) {
            if (*(s32*)(p + 0x24c) > 7) {
                *(s32*)(p + 0x248) = 5;
            } else {
                if (*(s32*)(p + 0x24c) < 0) {
                    *(s32*)(p + 0x24c) = 0;
                }
                *(s32*)(p + 0x248) = lbl_80471760[7 - *(s32*)(p + 0x24c)];
            }
            *(s32*)(p + 0x268) += 1;
            *(s32*)(p + 0x268) = *(s32*)(p + 0x268) % 7;
            *(s32*)(p + 0x264) = lbl_80471784[*(s32*)(p + 0x288)][*(s32*)(p + 0x268)];
            fn_801F0E34(p, 0x3006a, 0);
            *(s32*)(p + 0x24c) -= 1;
        }
    }
    if (*(s32*)(p + 0x248) >= 0) {
        *(s32*)(p + 0x248) -= 1;
    }
}

extern "C" void fn_80322BC4(char* p) {
    f32 chance;
    s32 count = 0;
    s32 n = 0;
    s32 a;
    s32 i;
    s32 buf[10];
    u32 flags;

    if (*(u8*)(lbl_8053AAF8 + 0x7e) == 0) {
        count = 4;
    } else if (*(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
        a = fn_80236228(*(s32*)(p + 0x23c));
        for (i = 0; i < 4; i++) {
            if (fn_8023F264(i) == 1 && *(s32*)(p + 4) == fn_8023DE58(i) && !fn_80230188(i) && a < fn_80236228(i)) {
                count++;
            }
        }
    } else {
        a = fn_80237774(*(s32*)(p + 0x23c));
        for (i = 0; i < 4; i++) {
            if (fn_8023F264(i) && *(s32*)(p + 4) == fn_8023DE58(i) && !fn_80230188(i) && a < fn_80237774(i)) {
                count++;
            }
        }
    }

    flags = *(u32*)(p + 0x90);
    if ((flags >> 18) & 1) {
        buf[0] = 10;
        n = 1;
    }
    if ((flags >> 19) & 1) {
        buf[n++] = 3;
    }
    if ((flags >> 20) & 1) {
        buf[n++] = 4;
    }
    if ((flags >> 21) & 1) {
        buf[n++] = 8;
    }
    if ((flags >> 22) & 1) {
        buf[n++] = 6;
    }
    if ((flags >> 23) & 1) {
        buf[n++] = 5;
    }
    if ((flags >> 24) & 1) {
        buf[n++] = 7;
    }
    if ((flags >> 25) & 1) {
        buf[n++] = 1;
    }
    if ((flags >> 26) & 1) {
        buf[n++] = 9;
    }
    if ((flags >> 4) & 1) {
        buf[n++] = 2;
    }

    {
        u32 bits;
        char* rng = lbl_8053AAF8;

        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(p + 0x294) = buf[(s32)((f32)n * (*(f32*)&bits - lbl_80541AEC)) % n];
    }

    if (*(s32*)(p + 0x294) != 2) {
        switch (count) {
        case 0:
            chance = lbl_80541B48;
            break;
        case 1:
            chance = lbl_80541B2C;
            break;
        case 2:
            chance = lbl_80541B4C;
            break;
        case 3:
            chance = lbl_80541AD8;
            break;
        case 4:
            chance = lbl_80541AE8;
            break;
        }
        {
            u32 bits;
            char* rng = lbl_8053AAF8;

            *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
            bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
            if (*(f32*)&bits - lbl_80541AEC >= chance) {
                *(s32*)(p + 0x298) = 2;
                *(s32*)(p + 0x230) = 4;
            }
        }
    }
}

extern "C" s32 fn_80236228(s32 i);
extern "C" u8 fn_8022F514(s32 i);
extern "C" void fn_80322F44(char* p) {
    s32 hi;
    s32 lo;
    s32 v;
    s32 i;
    char* rng;

    if (*(s32*)(p + 0x284) == 0) {
        rng = lbl_8053AAF8;
        if (*(u8*)(rng + 0x7e) == 0) {
            *(s32*)(p + 0x288) = 0;
        } else if (*(u8*)(rng + 0x7f) == 1) {
            v = hi = lo = fn_80236228(*(s32*)(p + 0x23c));
            for (i = 0; i < 4; i++) {
                if (fn_8022F514(i) == 0) {
                    if (hi < fn_80236228(i)) {
                        hi = fn_80236228(i);
                    }
                    if (lo > fn_80236228(i)) {
                        lo = fn_80236228(i);
                    }
                }
            }
            if (hi == v) {
                *(s32*)(p + 0x288) = 1;
            } else if (lo == v) {
                *(s32*)(p + 0x288) = 3;
                if (hi - v >= 500) {
                    *(u8*)(p + 0x2ad) = 1;
                }
            } else {
                *(s32*)(p + 0x288) = 2;
                if (hi - v >= 500) {
                    *(u8*)(p + 0x2ad) = 1;
                }
            }
        } else {
            *(s32*)(p + 0x288) = 4;
        }
    } else if (*(s32*)(p + 0x284) == 1) {
        *(s32*)(p + 0x288) = 5;
    } else {
        *(s32*)(p + 0x288) = 5;
    }
    *(s32*)(p + 0x230) = 2;
    if (*(s32*)(p + 0x284) == 0) {
        u32 bits;
        rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(p + 0x2b4) = (s32)(lbl_80541B38 * (*(f32*)&bits - lbl_80541AEC)) % 7;
    } else if (*(s32*)(p + 0x284) == 1) {
        u32 bits;
        rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(p + 0x2b4) = (s32)(lbl_80541B38 * (*(f32*)&bits - lbl_80541AEC)) % 7;
    } else {
        *(s32*)(p + 0x2b4) = *(s32*)(p + 0x284);
    }
    *(s32*)(p + 0x294) = lbl_80471784[*(s32*)(p + 0x288)][*(s32*)(p + 0x2b4)];
    rng = lbl_8053AAF8;
    if (*(u8*)(rng + 0x7f) == 0) {
        *(s32*)(p + 0x260) = 0x14;
    } else {
        u32 bits;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(p + 0x24c) = (s32)(lbl_80541B38 * (*(f32*)&bits - lbl_80541AEC)) + 0x28;
        *(s32*)(p + 0x268) = *(s32*)(p + 0x2b4) - *(s32*)(p + 0x24c) % 7;
        if (*(s32*)(p + 0x268) < 0) {
            *(s32*)(p + 0x268) += 7;
        }
        *(s32*)(p + 0x264) = lbl_80471784[*(s32*)(p + 0x288)][*(s32*)(p + 0x268)];
        *(s32*)(p + 0x248) = 5;
        *(u8*)(p + 0x2a6) = 0;
    }
}

extern "C" const f32 lbl_80541B20;
extern "C" const f32 lbl_80541B50;
extern "C" const f32 lbl_80541B54;
extern "C" const f32 lbl_80541AEC;
extern "C" const f32 lbl_80541B38;
extern "C" s32 lbl_80471760[];
extern "C" s32 lbl_80471784[][7];
extern "C" char* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* a, void* b, s32 c, f32 d, f32 e);
extern "C" u8 fn_801F2B7C(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_80236074(s32 a, s32 b, s32 c);
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" s32 fn_801F0E34(void* a, u32 code, u32 z);
extern "C" void fn_803232B8(char* p) {
    *(f32*)(p + 0x14) = lbl_80541AE0;
    *(s32*)(p + 0xb0) = 0;
    *(f32*)(p + 0x60) = lbl_80541B50;
    *(f32*)(p + 0x64) = lbl_80541B50;
    *(f32*)(p + 0x68) = lbl_80541B20;
    *(f32*)(p + 0x6c) = lbl_80541B20;
    fn_802D79E8(fn_802D6A9C(), *(void**)(p + 4), 0, lbl_80541B54, lbl_80541AE0);
    s32 flags;
    if (*(u8*)(lbl_8053AAF8 + 0x7f) == 0) {
        flags = fn_801F2B7C(p, 2, -1, 1);
    } else {
        flags = fn_801F2B7C(p, 0, -1, 1);
    }
    if (flags > 0) {
        s32 i = 0;
        do {
            if ((flags >> i) & 1) {
                fn_80236074(i, 100, 1);
            }
            i++;
        } while (i < 4);
    }
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_80541AEC, 0x59, 1, 1, 0, 0, 1);
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_80541AEC, 0x5a, 1, 1, 0, 0, 1);
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_80541AEC, 0x5b, 1, 1, 0, 0, 1);
    fn_801F0E34(p, 0x30001, 0);
}

extern "C" const f32 lbl_80541B3C;
extern "C" const f32 lbl_80541B40;
extern "C" const f32 lbl_80541B44;
extern "C" const f32 lbl_80541B58;
extern "C" const f32 lbl_80541B5C;
extern "C" const f32 lbl_80541B60;
extern "C" const f32 lbl_80541B64;
extern "C" const f32 lbl_80541ADC;
extern "C" u8 fn_8022F9E4(s32 index, s32 a0, u8 a1, u8 a2);
extern "C" void fn_80322F44(char* p);
extern "C" void fn_80323434(char* p) {
    *(u16*)(p + 0x94) = *(u32*)(p + 0x90) & 0xf;
    *(s32*)(p + 0x284) = (*(u32*)(p + 0x90) >> 8) & 0xf;
    *(s32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 16) & 3;
    *(s32*)(p + 0x290) = 0;
    *(s32*)(p + 0x2c4) = 0;
    *(s32*)(p + 0x2c8) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x280) = 0;
    *(s32*)(p + 0x294) = 0;
    *(s32*)(p + 0x288) = 0;
    *(s32*)(p + 0x298) = 1;
    *(u8*)(p + 0x2a4) = 0;
    *(u8*)(p + 0x2a5) = 0;
    *(u8*)(p + 0x2a6) = 1;
    *(u8*)(p + 0x2ad) = 0;
    *(s32*)(p + 0x2b4) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x278) = 900;
    *(s32*)(p + 0x27c) = 0;
    *(f32*)(p + 0x234) = lbl_80541AEC;
    *(f32*)(p + 0x238) = lbl_80541AE0;
    *(u8*)(p + 0x28c) = 0xff;
    *(s32*)(p + 0x29c) = -1;
    *(f32*)(p + 0x80) = lbl_80541B58;
    *(f32*)(p + 0x84) = lbl_80541B3C;
    *(f32*)(p + 0x88) = lbl_80541B54;
    *(f32*)(p + 0x8c) = lbl_80541B40;
    *(f32*)(p + 0x60) = lbl_80541B44;
    *(f32*)(p + 0x64) = lbl_80541B44;
    *(f32*)(p + 0x68) = lbl_80541ADC;
    *(f32*)(p + 0x6c) = lbl_80541ADC;
    *(f32*)(p + 0x70) = lbl_80541B5C;
    *(f32*)(p + 0x74) = lbl_80541B60;
    *(f32*)(p + 0x78) = lbl_80541B64;
    *(f32*)(p + 0x7c) = lbl_80541ADC;
    *(s32*)(p + 0x2a8) = 0;
    *(u8*)(p + 0x2ac) = 0;
    *(f32*)(p + 0x2c0) = lbl_80541AE0;
    *(f32*)(p + 0x2bc) = lbl_80541AE0;
    *(f32*)(p + 0x2b8) = lbl_80541AE0;
    *(s32*)(p + 0x2a0) = -1;

    switch (*(u16*)(p + 0x94)) {
    case 0:
    case 2:
        *(s32*)(p + 0x248) = 10;
        *(s32*)(p + 0xb0) = 0x2100a;
        *(s32*)(p + 0x230) = 0;
        break;
    case 1:
        *(s32*)(p + 0xb0) = 0;
        if (fn_8022F9E4(*(s32*)(p + 0x23c), *(s32*)(p + 0x198), 0, 0) == 1) {
            fn_80322F44(p);
        } else {
            *(s32*)(p + 0x230) = 1;
        }
        break;
    case 3:
        *(s32*)(p + 0xb0) = 0;
        *(s32*)(p + 0x294) = 2;
        *(s32*)(p + 0x264) = 2;
        if (fn_8022F9E4(*(s32*)(p + 0x23c), *(s32*)(p + 0x198), 0, 0) == 1) {
            *(s32*)(p + 0x230) = 4;
        } else {
            *(s32*)(p + 0x230) = 3;
        }
        break;
    }

    s32 room = *(s32*)(p + 4);
    if (*(u8*)((u8*)fn_802D6A9C() + room + 0x131df) == 1) {
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
        *(f32*)(p + 0x14) = lbl_80541AE0;
        *(f32*)(p + 0x40) = *(f32*)(p + 0x40) - *(f32*)(p + 0x44);
        *(f32*)(p + 0x44) = lbl_80541AE0;
    }
    *(s32*)(p + 0x2b0) = (*(u32*)(p + 0x90) >> 12) & 0xf;
    if (*(s32*)(p + 0x2b0) != 0) {
        *(s32*)(p + 0xb0) = 0;
        *(s32*)(p + 0x230) = 7;
    }
    if (*(s32*)(p + 0x230) == 0 && (*(u8 (**)(char*, s32, char*))(*(s32*)p + 0x4c))(p, *(s32*)(p + 4), p + 0xc) == 1) {
        *(u8*)(p + 0x11c) = 0;
    }
}

extern "C" void** fn_80323708(void** p, short del) {
    if (p != 0) {
        *p = lbl_804AB308;
        fn_801EE434(*(void**)((char*)p + 0x2c4));
        fn_801EE434(*(void**)((char*)p + 0x2c8));
        __dt__5ActorFv(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_8032377C(void) {
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

