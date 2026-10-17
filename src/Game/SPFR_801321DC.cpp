#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_8010DF58(void);
extern "C" void* fn_8011921C(void);
extern "C" void fn_80132454(char* a, s32 b);
extern "C" s32 lbl_80465204[];
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

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* mgr, u32 type);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern u8* lbl_8053AB10;
extern f32 lbl_8053CD18;
extern f32 lbl_8053CD1C;
extern f32 lbl_8053CD20;
extern "C" void fn_801321E4(char* p) {
    struct Vec3f {
        f32 x;
        f32 y;
        f32 z;
    } pos;
    char* g;
    char* obj;
    s32 id;
    f32 c;
    f32 x;
    f32 y;
    switch (*(s32*)(p + 0x234)) {
    case 0:
        if (*(s32*)(p + 0x238) == 0) {
            g = *(char**)(lbl_8053AB10 + 0x24);
            *(u8*)(g + 0x17d) = 1;
        } else {
            c = lbl_8053CD18;
            g = *(char**)(lbl_8053AB10 + 0x24);
            *(u8*)(g + 0x179) = 1;
            x = *(f32*)(p + 0x10);
            y = *(f32*)(p + 0xc);
            g = *(char**)(lbl_8053AB10 + 0x24);
            if (*(u8*)(g + 0x7f5) == 0) {
                *(u8*)(g + 0x7f4) = 1;
                *(s32*)(g + 0x7f8) = 5;
                *(f32*)(g + 0x808) = y;
                *(f32*)(g + 0x80c) = x - c;
                *(f32*)(g + 0x810) = y;
                *(f32*)(g + 0x814) = x + c;
                *(u8*)(g + 0x7f6) = 0;
            }
        }
        break;
    case 1:
        g = *(char**)(lbl_8053AB10 + 0x24);
        *(u8*)(g + 0x179) = 1;
        id = fn_801F7A08(fn_801F856C(), 0x42415249);
        if (id >= 0) {
            obj = (char*)fn_801F666C(fn_801F856C(), id);
            if (obj != 0) {
                pos = *(struct Vec3f*)(obj + 0xc);
                pos.y = pos.y + lbl_8053CD18;
                g = *(char**)(lbl_8053AB10 + 0x24);
                if (*(u8*)(g + 0x840) == 0) {
                    *(u8*)(g + 0x840) = 1;
                    *(f32*)(g + 0x844) = pos.x;
                    *(f32*)(g + 0x848) = pos.y - lbl_8053CD1C;
                    *(f32*)(g + 0x84c) = pos.x;
                    *(f32*)(g + 0x850) = pos.y + lbl_8053CD1C;
                    *(f32*)(g + 0x854) = lbl_8053CD00;
                    *(f32*)(g + 0x1d4) = lbl_8053CD20;
                    *(f32*)(g + 0x1d8) = lbl_8053CD20;
                }
            }
        }
        break;
    case 2:
        c = lbl_8053CD18;
        g = *(char**)(lbl_8053AB10 + 0x24);
        *(u8*)(g + 0x179) = 1;
        x = *(f32*)(p + 0x10);
        y = *(f32*)(p + 0xc);
        g = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(g + 0x840) == 0) {
            *(u8*)(g + 0x840) = 1;
            *(f32*)(g + 0x844) = y;
            *(f32*)(g + 0x848) = x - c;
            *(f32*)(g + 0x84c) = y;
            *(f32*)(g + 0x850) = x + c;
            *(f32*)(g + 0x854) = lbl_8053CD00;
            *(f32*)(g + 0x1d4) = lbl_8053CD20;
            *(f32*)(g + 0x1d8) = lbl_8053CD20;
        }
        break;
    case 3:
        g = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(g + 0x7f4) == 0) {
            *(u8*)(g + 0x7f5) = 1;
        }
        break;
    case 4:
        g = *(char**)(lbl_8053AB10 + 0x24);
        *(u8*)(g + 0x17d) = 1;
        break;
    case 5:
        c = lbl_8053CD18;
        g = *(char**)(lbl_8053AB10 + 0x24);
        *(u8*)(g + 0x179) = 1;
        x = *(f32*)(p + 0x10);
        y = *(f32*)(p + 0xc);
        g = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(g + 0x840) == 0) {
            *(u8*)(g + 0x840) = 1;
            *(f32*)(g + 0x844) = y;
            *(f32*)(g + 0x848) = x - c;
            *(f32*)(g + 0x84c) = y;
            *(f32*)(g + 0x850) = x + c;
            *(f32*)(g + 0x854) = lbl_8053CD00;
            *(f32*)(g + 0x1d4) = lbl_8053CD20;
            *(f32*)(g + 0x1d8) = lbl_8053CD20;
        }
        break;
    case 26:
        break;
    }
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

extern "C" void fn_80132B10(char* p)
{
    s32 state;
    s32 v;

    if (*(s32*)((char*)fn_8011921C() + 4) == 0xe) {
        char* ret = (char*)fn_8011921C();
        state = *(s32*)(p + 0x238);
        v = *(s32*)(ret + 8);
        switch (state) {
        case 0:
            if (v == lbl_80465204[5]) {
                fn_80132454(p, 5);
            } else if (v == lbl_80465204[6]) {
                fn_80132454(p, 6);
            } else if (v == lbl_80465204[7]) {
                fn_80132454(p, 7);
            } else if (v == lbl_80465204[8]) {
                fn_80132454(p, 8);
            } else if (v == lbl_80465204[9]) {
                fn_80132454(p, 9);
            } else if (v == lbl_80465204[10]) {
                fn_80132454(p, 10);
            } else if (v == lbl_80465204[11]) {
                fn_80132454(p, 11);
            } else if (v == lbl_80465204[12]) {
                fn_80132454(p, 12);
            } else if (v == lbl_80465204[13]) {
                fn_80132454(p, 13);
            } else if (v == lbl_80465204[14]) {
                fn_80132454(p, 14);
            } else if (v == lbl_80465204[15]) {
                fn_80132454(p, 15);
            } else if (v == lbl_80465204[16]) {
                fn_80132454(p, 16);
            } else if (v == lbl_80465204[17]) {
                fn_80132454(p, 17);
            } else if (v == lbl_80465204[18]) {
                fn_80132454(p, 18);
            } else if (v == lbl_80465204[19]) {
                fn_80132454(p, 19);
            } else if (v == lbl_80465204[20]) {
                fn_80132454(p, 20);
            } else if (v == lbl_80465204[21]) {
                fn_80132454(p, 21);
            }
            break;
        case 1:
            if (v == lbl_80465204[4]) {
                fn_80132454(p, 4);
            } else if (v == lbl_80465204[5]) {
                fn_80132454(p, 5);
            } else if (v == lbl_80465204[6]) {
                fn_80132454(p, 6);
            } else if (v == lbl_80465204[22]) {
                fn_80132454(p, 0x16);
            } else if (v == lbl_80465204[23]) {
                fn_80132454(p, 0x13);
            } else if (v == lbl_80465204[24]) {
                fn_80132454(p, 0x14);
            } else if (v == lbl_80465204[25]) {
                fn_80132454(p, 0x19);
            }
            break;
        }
    }
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
    f32 b = lbl_8053CD08;
    f32 a = lbl_8053CD28;
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

void __sinit_SPFR_801321DC_cpp(void) {}

