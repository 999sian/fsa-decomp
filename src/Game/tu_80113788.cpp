#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" f32 lbl_8053C67C;
extern "C" f32 lbl_8053C684;
extern "C" f32 lbl_8053C690;
extern "C" f32 lbl_8053C698;
extern "C" f32 lbl_8053C69C;
extern "C" u16 lbl_804648E8[];
extern "C" u32 lbl_804648F4[];
extern "C" char lbl_8049D820[];
extern "C" char lbl_80464968[];
extern "C" char lbl_8046497C[];
extern "C" void* lbl_8053AAF8;
extern "C" void fn_801EF830(s32 a, void* b, void* c, s32 d, void* e, s32 f, s32 g);
extern "C" void fn_802F86CC(void* a, void* b, void* c, s32 d, void* e, f32 f1, f32 f2);

struct Vec3_80113B54 {
    f32 x;
    f32 y;
    f32 z;
};

struct Mtx34_8011395C {
    float m[3][4];
};

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SP01) || defined(VERSION_G4SE01)
extern "C" int fn_80113788(char* self) {
    return *(int*)(self + 0x23c);
}

extern "C" void PSMTXTrans(f32 mtx[3][4], f32 x, f32 y, f32 z);
extern "C" void fn_802F745C(void* a, void* b, s32 c, void* d);
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_8053C6A0;
extern "C" void fn_80113790(char* self) {
    u8 buf[0x40];
    f32 mtx[3][4];
    struct P {
        f32 x;
        f32 y;
    };
    struct V {
        P xy;
        f32 z;
    } vec;
    s32 i;

    if (*(s32*)(self + 0x248) > 0) {
        *(s32*)(buf + 0x10) = -1;
        *(s32*)(buf + 0x14) = -1;
        for (i = 0; (u8)i < 0x10; i += 8) {
            buf[(u8)i] = i;
            buf[(u8)(i + 1)] = i + 1;
            buf[(u8)(i + 2)] = i + 2;
            buf[(u8)(i + 3)] = i + 3;
            buf[(u8)(i + 4)] = i + 4;
            buf[(u8)(i + 5)] = i + 5;
            buf[(u8)(i + 6)] = i + 6;
            buf[(u8)(i + 7)] = i + 7;
        }
        *(s32*)(buf + 0x10) = -1;
        *(s32*)(buf + 0x14) = 0;
        *(s32*)(buf + 0x18) = 0;
        buf[0x1c] = 0;
        buf[0x1d] = 0;
        buf[0x1e] = 0;
        buf[0x1f] = 1;
        buf[0x20] = 1;
        buf[0x21] = 0;
        buf[0x22] = 0;
        buf[0x23] = 0;
        buf[0x24] = 0;
        buf[0x25] = 0;
        buf[0x26] = 1;
        *(s32*)(buf + 0x28) = 3;
        buf[0x2c] = 1;
        buf[0x2d] = 0;
        buf[0x2e] = 0;
        *(s32*)(buf + 0x30) = -1;
        *(s32*)(buf + 0x34) = 0;
        *(s32*)(buf + 0x38) = 2;
        PSMTXTrans(mtx, lbl_8053C69C, lbl_8053C69C, lbl_8053C69C);
        mtx[0][0] = lbl_8053C6A0;
        mtx[0][1] = lbl_8053C69C;
        mtx[0][2] = lbl_8053C69C;
        mtx[1][0] = lbl_8053C69C;
        mtx[1][1] = lbl_8053C690;
        mtx[1][2] = lbl_8053C69C;
        mtx[2][0] = lbl_8053C69C;
        mtx[2][1] = lbl_8053C69C;
        mtx[2][2] = lbl_8053C6A0;
        buf[0x14] = 0;
        buf[0x15] = 0;
        buf[0x16] = 0;
        buf[0x17] = *(s32*)(self + 0x248);
        *(f32(**)[4])(buf + 0x18) = mtx;
        *(s8*)(buf + 0x1d) = -1;
        buf[0x2d] = 1;
        vec.z = *(f32*)(self + 0x14);
        vec.xy = *(P*)(self + 0xc);
        vec.z = lbl_8053C69C;
        if (*(s32*)(self + 4) < 8) {
            fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), &vec, *(s32*)(self + 0x260), buf);
        }
    }
}

extern "C" void PSMTXTrans(float m[3][4], float x, float y, float z);
extern "C" void PSMTXConcat(float a[3][4], float b[3][4], float ab[3][4]);
extern "C" void fn_8010F668(float m[3][4], float* v, float s);
extern "C" char* fn_801902C0(void);
extern int lbl_804647C8[];
extern float lbl_8053C690;
extern float lbl_8053C694;
extern float lbl_8053C69C;
extern float lbl_8053C6A4;
extern float lbl_8053C6A8;
extern "C" void PSMTXCopy(float src[3][4], float dst[3][4]);
extern "C" void fn_8011395C(char* self) {
    char* tbl = (char*)lbl_804647C8;
    Mtx34_8011395C mtx;
    Mtx34_8011395C rot;
    float v0[3];
    float v1[3];
    PSMTXTrans(mtx.m, *(float*)(self + 0xc), *(float*)(self + 0x10), *(float*)(self + 0x14));
    v0[0] = lbl_8053C690;
    v0[1] = lbl_8053C69C;
    v0[2] = lbl_8053C69C;
    fn_8010F668(mtx.m, v0, lbl_8053C6A4);
    rot.m[2][3] = lbl_8053C69C; rot.m[1][3] = lbl_8053C69C; rot.m[0][3] = lbl_8053C69C;
    rot.m[2][2] = lbl_8053C69C; rot.m[1][2] = lbl_8053C69C; rot.m[0][2] = lbl_8053C69C;
    rot.m[2][1] = lbl_8053C69C; rot.m[1][1] = lbl_8053C69C; rot.m[0][1] = lbl_8053C69C;
    rot.m[2][0] = lbl_8053C69C; rot.m[1][0] = lbl_8053C69C; rot.m[0][0] = lbl_8053C69C;
    v1[0] = lbl_8053C69C;
    v1[1] = lbl_8053C69C;
    v1[2] = lbl_8053C690;
    fn_8010F668(rot.m, v1, *(float*)(self + 0x258));
    PSMTXConcat(mtx.m, rot.m, mtx.m);
    if (*(u8*)(self + 0x234) != 0) {
        (*(int*)(self + 0x24c))++;
    }
    int* lim = (int*)(tbl + 0xf8);
    switch (*(int*)(self + 0x240)) {
    case 0:
    case 2:
        if (*(int*)(self + 0x24c) >= lim[*(int*)(self + 0x240)]) {
            int* rst = (int*)(tbl + 0xec);
            *(int*)(self + 0x24c) = rst[*(int*)(self + 0x240)];
        }
        break;
    case 1:
        if (*(int*)(self + 0x24c) >= lim[*(int*)(self + 0x240)]) {
            *(int*)(self + 0x240) = 2;
        }
        break;
    }
    int* ids = (int*)(tbl + 0x104);
    int idx = ids[*(int*)(self + 0x238)];
    int cnt = *(int*)(self + 0x24c);
    char* e = fn_801902C0() + idx * 0x60 + 8;
    if (*(void**)(e + 0x3c) != 0 && *(u8*)(e + 0x5c) == 0) {
        *(u8*)(e + 0x5c) = 1;
        *(float*)(e + 0) = lbl_8053C694;
        *(float*)(e + 4) = lbl_8053C694;
        *(float*)(e + 8) = lbl_8053C694;
        PSMTXCopy(mtx.m, (float(*)[4])(e + 0xc));
        *(float*)(e + 0x48) = lbl_8053C6A8;
        *(int*)(e + 0x4c) = cnt;
        *(int*)(e + 0x54) = 0;
        *(int*)(e + 0x58) = 2;
    }
}

extern "C" void fn_80113B54(char* self, int arg) {
    u8 buf50[0x3c];
    u8 buf14[0x3c];
    Vec3_80113B54 vec;
    int i;
    int idx;
    void* spr;

    *(s32*)(buf50 + 0x10) = -1;
    *(s32*)(buf50 + 0x14) = -1;
    for (i = 0; (u8)i < 0x10; i += 8) {
        buf50[(u8)i] = i;
        buf50[(u8)(i + 1)] = i + 1;
        buf50[(u8)(i + 2)] = i + 2;
        buf50[(u8)(i + 3)] = i + 3;
        buf50[(u8)(i + 4)] = i + 4;
        buf50[(u8)(i + 5)] = i + 5;
        buf50[(u8)(i + 6)] = i + 6;
        buf50[(u8)(i + 7)] = i + 7;
    }
    *(s32*)(buf50 + 0x10) = -1;
    *(s32*)(buf50 + 0x14) = 0;
    *(s32*)(buf50 + 0x18) = 0;
    buf50[0x1c] = 0;
    buf50[0x1d] = 0;
    buf50[0x1e] = 0;
    buf50[0x1f] = 1;
    buf50[0x20] = 1;
    buf50[0x21] = 0;
    buf50[0x22] = 0;
    buf50[0x23] = 0;
    buf50[0x24] = 0;
    buf50[0x25] = 0;
    buf50[0x26] = 1;
    *(s32*)(buf50 + 0x28) = 3;
    buf50[0x2c] = 1;
    buf50[0x2d] = 0;
    buf50[0x2e] = 0;
    *(s32*)(buf50 + 0x30) = -1;
    *(s32*)(buf50 + 0x34) = 0;
    *(s32*)(buf50 + 0x38) = 2;
    *(s32*)(buf14 + 0x10) = -1;
    *(s32*)(buf14 + 0x14) = -1;

    for (i = 0; (u8)i < 0x10; i += 8) {
        buf14[(u8)i] = i;
        buf14[(u8)(i + 1)] = i + 1;
        buf14[(u8)(i + 2)] = i + 2;
        buf14[(u8)(i + 3)] = i + 3;
        buf14[(u8)(i + 4)] = i + 4;
        buf14[(u8)(i + 5)] = i + 5;
        buf14[(u8)(i + 6)] = i + 6;
        buf14[(u8)(i + 7)] = i + 7;
    }
    *(s32*)(buf14 + 0x10) = -1;
    *(s32*)(buf14 + 0x14) = 0;
    *(s32*)(buf14 + 0x18) = 0;
    buf14[0x1c] = 0;
    buf14[0x1d] = 0;
    buf14[0x1e] = 0;
    buf14[0x1f] = 1;
    buf14[0x20] = 1;
    buf14[0x21] = 0;
    buf14[0x22] = 0;
    buf14[0x23] = 0;
    buf14[0x24] = 0;
    buf14[0x25] = 0;
    buf14[0x26] = 1;
    *(s32*)(buf14 + 0x28) = 3;
    buf14[0x2c] = 1;
    buf14[0x2d] = 0;
    buf14[0x2e] = 0;
    *(s32*)(buf14 + 0x30) = -1;
    *(s32*)(buf14 + 0x34) = 0;
    *(s32*)(buf14 + 0x38) = 2;

    vec = *(Vec3_80113B54*)(self + 0xc);
    vec.y = *(f32*)(self + 0x28);

    if (arg == 0x1d6) {
        fn_801EF830(*(s32*)(self + 4), &vec, buf14, 7, lbl_80464968, arg + *(s32*)(self + 0x274), 0);
        idx = arg + *(s32*)(self + 0x274);
        if (*(s32*)(self + 4) < 8) {
            spr = ((void* (*)(void*, u32, void*))((void**)*(void**)*(void**)((char*)lbl_8053AAF8 + 0xa4))[6])(*(void**)((char*)lbl_8053AAF8 + 0xa4), 0x534f4220, lbl_80464968);
            fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), self + 0xc, spr, idx, buf50, lbl_8053C690, lbl_8053C690);
        }
    } else {
        fn_801EF830(*(s32*)(self + 4), &vec, buf14, 7, lbl_8046497C, arg + *(s32*)(self + 0x274), 0);
        idx = arg + *(s32*)(self + 0x274);
        if (*(s32*)(self + 4) < 8) {
            spr = ((void* (*)(void*, u32, void*))((void**)*(void**)*(void**)((char*)lbl_8053AAF8 + 0xa4))[6])(*(void**)((char*)lbl_8053AAF8 + 0xa4), 0x534f4220, lbl_8046497C);
            fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), self + 0xc, spr, idx, buf50, lbl_8053C690, lbl_8053C690);
        }
    }
}

#if defined(VERSION_G4SE01)
extern "C" int fn_80113E98(char* self) {
    switch (*(int*)(self + 0x23c)) {
    case 10:
    case 0x11:
        return 1;
    }
    return 0;
}
#endif

extern "C" void fn_8010DF58(char*);
extern "C" void fn_80113790(char*);
extern "C" void fn_80113B54(char*, int);
extern int lbl_80464830[];
extern "C" void fn_80114C1C(char* self) {
    fn_8010DF58(self);
    fn_80113790(self);
    switch (*(int*)(self + 0x23c)) {
    case 0x10:
        fn_80113B54(self, 0x1d6);
        break;
    default:
        if (*(unsigned char*)(self + 0x232) != 0) {
            fn_80113B54(self, lbl_80464830[*(int*)(self + 0x238)]);
        }
        break;
    }
}

extern "C" void fn_8010DF98(char* self);
extern "C" void fn_801D2608(char* p, char* s, s32 n);
extern "C" void fn_801D22DC(char* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(char* p);
extern "C" s32 fn_8013CC50(void* obj, void* v, u16 a, s32 b, f32 c, u32 d, s32 e, s32 f, s32 g);
extern "C" void fn_802D6A9C(void);
extern "C" void fn_802D7440(s32 a);
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_80539F00;
extern "C" void fn_80115248(char* self) {
    f32 vec[5][3];
    fn_8010DF98(self);
    *(u32*)(self + 0x238) = *(u32*)(self + 0x90) & 0xff;
    *(u32*)(self + 0x244) = (*(u32*)(self + 0x90) >> 22) & 0x1f;
    char* obj = *(char**)((char*)lbl_8053AAF8 + 0xa4);
    s32 (*vfn)(char*, s32, void*) = (s32(*)(char*, s32, void*))(*(void***)obj)[6];
    *(s32*)(self + 0x260) = vfn(obj, 0x3f3f3f3f, lbl_80539F00);
    fn_801D2608(self + 0x264, lbl_8049D820, 7);
    s32 st = *(s32*)(self + 0x238);
    if (st > 5 || st < 0) {
        fn_801D22DC(self + 0x264, 6, 2, 0);
    } else {
        fn_801D22DC(self + 0x264, 4, 2, 0);
    }
    fn_801D1F14(self + 0x264);
    *(f32*)(self + 0x10) = *(f32*)(self + 0x10) - lbl_8053C67C;
    vec[0][0] = *(f32*)(self + 0xc);
    vec[0][1] = *(f32*)(self + 0x10);
    vec[0][2] = *(f32*)(self + 0x14);
    vec[1][0] = *(f32*)(self + 0x24) - lbl_8053C698;
    vec[1][1] = *(f32*)(self + 0x28) - lbl_8053C684;
    vec[1][2] = lbl_8053C69C;
    vec[2][0] = *(f32*)(self + 0x24) + lbl_8053C698;
    vec[2][1] = *(f32*)(self + 0x28) - lbl_8053C684;
    vec[2][2] = lbl_8053C69C;
    vec[3][0] = *(f32*)(self + 0x24) - lbl_8053C698;
    vec[3][1] = *(f32*)(self + 0x28) + lbl_8053C684;
    vec[3][2] = lbl_8053C69C;
    vec[4][0] = *(f32*)(self + 0x24) + lbl_8053C698;
    vec[4][1] = *(f32*)(self + 0x28) + lbl_8053C684;
    vec[4][2] = lbl_8053C69C;
    for (s32 i = 0; i < 5; i++) {
        *(s32*)(self + 0x2d0 + i * 4) = fn_8013CC50(*(void**)(self + 0x4), vec[i], lbl_804648E8[i], 0, lbl_8053C690, lbl_804648F4[i], 0, 0, 1);
    }
    fn_802D6A9C();
    fn_802D7440(0);
}

extern "C" void fn_801EE434(void* handle);
extern "C" void __dl__FPv(void* p);
extern "C" void __dt__13Base_8010E074Fv(void* p, s32 how);
extern "C" void* fn_80115430(char* p, s16 freeFlag) {
    extern void* lbl_8049D83C[];
    extern void* lbl_8049CC34[];
    if (p != 0) {
        *(void**)p = lbl_8049D83C;
        if (*(void**)(p + 0x2a0) != 0) {
            fn_801EE434(*(void**)(p + 0x2a0));
            *(s32*)(p + 0x2a0) = 0;
        }
        if (*(void**)(p + 0x29c) != 0) {
            fn_801EE434(*(void**)(p + 0x29c));
            *(s32*)(p + 0x29c) = 0;
        }
        s32 i = 0;
        char* q = p;
        for (; i < 7; i++) {
            fn_801EE434(*(void**)(q + 0x2a8));
            *(s32*)(q + 0x2a8) = 0;
            if (i < 2) {
                fn_801EE434(*(void**)(q + 0x2e8));
                *(s32*)(q + 0x2e8) = 0;
            }
            if (i < 3) {
                fn_801EE434(*(void**)(q + 0x2c4));
                *(s32*)(q + 0x2c4) = 0;
            }
            if (i < 5) {
                fn_801EE434(*(void**)(q + 0x2d0));
                *(s32*)(q + 0x2d0) = 0;
            }
            q += 4;
        }
        if (*(void**)(p + 0x2a4) != 0) {
            fn_801EE434(*(void**)(p + 0x2a4));
            *(s32*)(p + 0x2a4) = 0;
        }
        if (*(void**)(p + 0x2e4) != 0) {
            fn_801EE434(*(void**)(p + 0x2e4));
            *(s32*)(p + 0x2e4) = 0;
        }
        if (p + 0x264 != 0 && p + 0x288 != 0) {
            *(void**)(p + 0x288) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" char lbl_8049D83C[];
extern "C" s32 lbl_8053AF80;
extern "C" f32 lbl_8053C69C;
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" void fn_80458F9C(s32, s32);
extern "C" void* fn_80115590(char* self) {
    s32 i;
    s32 off;
    f32 zero;

    fn_8010E074(self);
    *(void**)self = lbl_8049D83C;
    zero = lbl_8053C69C;
    *(u8*)(self + 0x230) = 1;
    *(u8*)(self + 0x231) = 1;
    *(u8*)(self + 0x232) = 0;
    *(u8*)(self + 0x233) = 0;
    *(u8*)(self + 0x234) = 1;
    *(s32*)(self + 0x238) = 0;
    *(s32*)(self + 0x23c) = 0;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x244) = 0;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x24c) = 0;
    *(f32*)(self + 0x250) = zero;
    *(f32*)(self + 0x254) = zero;
    *(f32*)(self + 0x258) = zero;
    *(f32*)(self + 0x25c) = zero;
    *(s32*)(self + 0x260) = 0;
    fn_801D267C(self + 0x264);
    *(s32*)(self + 0x29c) = 0;
    *(s32*)(self + 0x2a0) = 0;
    *(s32*)(self + 0x2a4) = 0;
    *(s32*)(self + 0x2e4) = 0;
    for (i = 0, off = 0; i < 7; off += 4, i++) {
        *(s32*)((u8*)self + off + 0x2a8) = 0;
        if (i < 2) {
            *(s32*)((u8*)self + off + 0x2e8) = 0;
        }
        if (i < 3) {
            *(s32*)((u8*)self + off + 0x2c4) = 0;
        }
        if (i < 5) {
            *(s32*)((u8*)self + off + 0x2d0) = 0;
        }
    }
    fn_80458F9C(lbl_8053AF80, 0x3c);
    return self;
}

void __sinit_tu_80113788_cpp(void) {}

#endif
