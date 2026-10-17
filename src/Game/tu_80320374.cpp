#include "types.h"

extern "C" const f32 lbl_80541AE0;
extern "C" void* lbl_804AB308[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, short);
extern "C" s32 fn_801F0E34(void* a, u32 code, u32 z);
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
