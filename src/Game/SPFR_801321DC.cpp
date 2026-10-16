#include "types.h"

extern "C" void fn_8010DF58(void);
extern const char lbl_80465270[];
extern f32 lbl_8053CD00;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, struct SPFR_DrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);

struct SPFR_DrawKey {
    s32 a, b;
    SPFR_DrawKey() { a = -1; b = -1; }
};
struct SPFR_DrawParam {
    u8 map[16];
    SPFR_DrawKey key;
    s32 c;
    u8 palette;
    u8 color;
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;
    u8 f2c, f2d, f2e;
    s32 g;
    s32 h;
    s32 i;

    SPFR_DrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};

extern "C" s32 fn_801321DC(char* p) {
    return *(s32*)(p + 0x234);
}

extern "C" char lbl_8049EB8C[];
extern "C" char lbl_8049CC34[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, int);
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
void operator delete(void*);
extern "C" s32 fn_80132AE0(char* p) {
    switch (*(s32*)(p + 0x234)) {
    case 21:
    case 25:
    case 26:
        return 1;
    }
    return 0;
}

extern "C" void fn_80132E18(void* param_1) {
    fn_8010DF58();
    SPFR_DrawParam param;
    fn_801F02BC(param_1, lbl_80465270, *(s32*)((char*)param_1 + 0x260) + 0x2fb, &param, 0x407, 0, 0, lbl_8053CD00, lbl_8053CD00);
}

extern "C" void fn_8010DF98(void);
extern "C" void fn_801D2608(void* a, void* b, s32 c);
extern "C" void fn_801D22DC(void* a, s32 b, s32 c, s32 d);
extern "C" void fn_801D1F14(void* a, f32 b);
extern "C" s32 fn_8013CC50(void* a, void* b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, f32 i);
extern "C" void fn_80132454(char* a, s32 b);
extern char lbl_8049EB80[];
extern f32 lbl_8053CD28;
extern f32 lbl_8053CD08;
extern f32 lbl_8053CCF0;
extern f32 lbl_8053CD00;
extern "C" void fn_801334CC(char* p) {
    struct Vec3f {
        f32 x;
        f32 y;
        f32 z;
    } pos;
    fn_8010DF98();
    f32 a = lbl_8053CD28;
    f32 b = lbl_8053CD08;
    *(s32*)(p + 0x238) = *(s32*)(p + 0x90) & 1;
    *(s32*)(p + 0x248) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x84) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x88) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x8c) = *(f32*)(p + 0x6c);
    fn_801D2608(p + 0x250, lbl_8049EB80, 3);
    fn_801D22DC(p + 0x250, 0, 2, 0);
    fn_801D1F14(p + 0x250, lbl_8053CCF0);
    *(f32*)(p + 0x14) = lbl_8053CD08;
    *(u8*)(p + 0x11d) = 0;
    if (*(s32*)(p + 0x238) == 1) {
        if ((*(s32(**)(char*))(*(char**)p + 0x34))(p)) {
            *(u8*)(p + 0x11d) = 1;
            pos = *(struct Vec3f*)(p + 0xc);
            *(s32*)(p + 0x288) = fn_8013CC50(*(void**)(p + 0x4), &pos, 0x184, 0, -1, 0, 0, 1, lbl_8053CD00);
        }
    }
    fn_80132454(p, 2);
}

extern "C" void* fn_80133624(char* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_8049EB8C;
        fn_801EE434(*(void**)(p + 0x288));
        *(void**)(p + 0x288) = 0;
        if (p + 0x250 != 0 && p + 0x274 != 0) {
            *(void**)(p + 0x274) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_801336B4(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049EB8C;
    p[0x230] = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    fn_801D267C(p + 0x250);
    *(void**)(p + 0x288) = 0;
    return p;
}