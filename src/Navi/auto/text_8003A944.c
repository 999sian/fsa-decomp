#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8003a944-0x80041b7c (90 functions). split_file divides it into the game's real files.

extern void* lbl_802469E8[];
extern void* lbl_80246AF4[];
extern void* lbl_80246B28[];
extern void* lbl_80246ABC[];
extern void* lbl_80246A88[];
extern void* lbl_80246A20[];
extern void* lbl_80246A54[];
extern void* lbl_80299A8C[];
extern void* lbl_802BF110[];
extern s64 lbl_802FFEC8;
extern s16 lbl_802FEFB4[3];
extern u8 lbl_802FEF6C[8];
extern u8 lbl_802FEF74[4];
extern f32 lbl_802FEE74;
extern f32 lbl_802FEE78;
extern "C" void fn_801E41AC(void* dst, void* src, ...);
extern "C" void fn_801E66C0(void* dst, void* src);
extern "C" void fn_8003AA34(u32* p);
struct VObj_8003A988 {
    virtual void m0(s32 a);
    virtual void m1();
    virtual void m2(s32 a);
};
struct VObj_800402B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(s16 a);
};
extern "C" void* fn_800F0D64(void* p);
extern u8 lbl_802BB0FC[];
extern u8 lbl_802B7CA0[];
extern s32 lbl_802FC158;
struct Vec3_8003C318 {
    f32 x, y, z;
};
extern u8 lbl_802BF188[];
extern s16 lbl_802FF04C;
extern "C" void fn_80043FCC(void* a, void* b, void* c, void* d);
extern "C" void fn_80043518(void* a, void* b, void* c, void* d);
struct VObj_80041AC4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void vf60(s32 a, void* b);
    virtual void m24();
    virtual void* vf68(s32 a);
};
struct VObj_80041740 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void* vf30();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void vf6C(s32 a, void* b);
    virtual void m26();
    virtual void* vf74(s32 a);
};
struct Color_8003C7DC {
    u8 r, g, b, a;
};
struct FogAdjTable_8003C7DC {
    u16 r[10];
};
extern "C" void fn_801DEA74(s32 type, Color_8003C7DC color, f32 startz, f32 endz, f32 nearz, f32 farz);
extern "C" void fn_801DEC98(u8 enable, u16 center, FogAdjTable_8003C7DC* table);
extern s16 lbl_802FEFAC[3];
extern f32 lbl_802FFDD0;
extern f32 lbl_802FFDD4;
extern f32 lbl_802FFDF0;
extern u16 lbl_802FF054;
extern u8 lbl_802FF056;
extern u8 lbl_802FF057;
extern FogAdjTable_8003C7DC lbl_80246984[];
extern FogAdjTable_8003C7DC lbl_802BF1FC;
extern u8 lbl_802FEFA8[4];
extern s16 lbl_802FEF80[3];
extern f32 lbl_802FEE5C;
extern f32 lbl_802FEE60;
extern "C" void fn_80017FEC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern "C" void fn_80115914(Vec3_8003C318* out, f32 s);
struct VObj_8003B920 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
};
extern "C" void* fn_801E0D40(void* dst, void* src, s16 size, s16 count);
extern "C" void fn_8000CEC4(void);
extern "C" void fn_8015AB1C(void* ptr);
extern u8 lbl_802EE470[];
extern "C" void fn_8003CDD4(void);
extern "C" void* fn_8003CD98(void* ptr, s16 param_2);
extern "C" void fn_8004816C(void* dst, void* src);
extern "C" void fn_80047B58(void* dst, void* src);
extern "C" void fn_80047144(void* dst, void* src);
extern "C" void fn_80042638(void* dst, void* src, void* src2);
extern "C" void* fn_801E0DB8(void* dst, void* src, void* src2, s16 size, s16 count);
extern "C" u32* fn_8003A944(u32* param_1) {
    fn_8003AA34(param_1);
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    return param_1;
}

extern "C" u8* fn_8003A988(u8* param_1, s16 param_2) {
    VObj_8003A988* obj;

    if (param_1 != 0) {
        obj = *(VObj_8003A988**)(param_1 + 0x34);
        if (obj != 0) {
            obj->m0(1);
        }
        obj = *(VObj_8003A988**)(param_1 + 0x38);
        if (obj != 0) {
            obj->m0(1);
        }
        obj = *(VObj_8003A988**)(param_1 + 0x3c);
        if (obj != 0) {
            obj->m0(1);
        }
        if (0 < param_2) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8003ABDC(u32* param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5) {
    param_1[0] = param_2;
    param_1[1] = param_3;
    param_1[2] = param_4;
    param_1[3] = param_5;
}

extern "C" void fn_8003B920(VObj_8003B920* obj) {
    obj->m8();
}

extern "C" void* fn_80160564(u32 tag, void* name, void* data);
extern u8 lbl_80246678[];
extern u8 lbl_802464E8[];
extern void* lbl_802FECC8;
extern "C" void fn_8003B94C(void* a, s32 mode, void* p) {
    switch (mode) {
    case 0:
        fn_801E41AC(p, &lbl_802FC158, fn_800F0D64(lbl_802B7CA0));
        break;
    case 1:
        fn_801E41AC(p, &lbl_802FC158, *(s32*)(lbl_802BB0FC + 0x3f8));
        break;
    default:
        return;
    }
}

extern "C" u32 fn_8003BCA4(void* a, u16 idx) {
    u32* p = (u32*)fn_80160564(0x524f4f54, lbl_80246678, lbl_802FECC8);
    return *(u32*)((u8*)p + idx * 4 + 0x2c);
}

extern s32 lbl_802FC144;
extern "C" void fn_8003C19C(void* a, s32 n, void* p) {
    char buf[16];
    if (n > 0) {
        fn_801E41AC(buf, &lbl_802FC144, n);
        fn_801E66C0(p, buf);
    }
}

extern "C" void* fn_8003C1EC(void* a, s32 idx) {
    u8* p = (u8*)fn_80160564(0x524f4f54, lbl_802464E8, lbl_802FECC8) + 0x20;
    return p + *(s32*)(p + 4) + *(s32*)(p + (idx << 3) + 0x10) + 8;
}

extern "C" u16 fn_8003C250(void* a, char* p) {
    char c;
    u16 n = 0;
    while ((c = *p) != 0) {
        if (c == 0x1a) {
            p += p[1];
        } else {
            if (c == 0xa) {
                n++;
            }
            p++;
        }
    }
    return n + 1;
}

extern "C" void fn_8003C2A4(u8* p) {
    p[4] = 0;
    p[3] = 0;
}

extern "C" void fn_8003C2B4(u8* p, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f, s16 g, s16 h, s16 i, s16 j, s16 k, s16 l, s16 m) {
    *(s16*)(p + 0x18) = a;
    *(s16*)(p + 0x1a) = b;
    *(s16*)(p + 0x1c) = c;
    *(s16*)(p + 0xc) = d;
    *(s16*)(p + 0xe) = e;
    *(s16*)(p + 0x10) = f;
    *(s16*)(p + 0x12) = g;
    *(s16*)(p + 0x14) = h;
    *(s16*)(p + 0x16) = i;
    *(s16*)(p + 0x6) = j;
    *(s16*)(p + 0x8) = k;
    *(s16*)(p + 0xa) = l;
    *(s16*)(p + 0x24) = m;
    *(s16*)(p + 0x26) = m;
    *(s16*)(p + 0x28) = m;
    *(s16*)(p + 0x1e) = m;
    *(s16*)(p + 0x20) = m;
    *(s16*)(p + 0x22) = m;
}

extern "C" void* memset(void* dst, int c, unsigned long n);
extern "C" void fn_8003C34C(f32* out, u8* obj);
extern "C" f32* fn_8003C318(f32* out) {
    fn_8003C34C(out, lbl_802BB0FC);
    return out;
}

extern "C" void fn_8003C34C(f32* out, u8* obj) {
    out[0] = *(f32*)(obj + 0x408);
    out[1] = *(f32*)(obj + 0x40c);
    out[2] = *(f32*)(obj + 0x410);
}

extern "C" void fn_8003C368(u8* p, u8 a, u8 b) {
    memset(p, 0, 0xb0);
    p[0xa9] = a;
    p[0xa5] = p[0xa9];
    p[0xa6] = p[0xa9];
    p[0xaa] = b;
    p[0xa4] = 1;
    p[0xac] = 0x7b;
    *(s16*)(p + 0x80) = 0;
    *(s16*)(p + 0x82) = 0;
    *(s16*)(p + 0x84) = 0;
    *(s16*)(p + 0x86) = 0xff;
    p[0x88] = 0xff;
    p[0x89] = 0xff;
    p[0x8a] = 0xff;
    p[0x8b] = 0xff;
    *(s16*)(p + 0x96) = 0xff;
    p[0x8c] = 0;
    p[0x8d] = 0;
    p[0x8e] = 0;
    p[0x8f] = 0;
}

extern "C" void fn_8003C418(void) {
    fn_80017FEC(0x1e, 0, 0, 0, 0, -1, 0);
    fn_80017FEC(0x1c, 0, 0, 0, 0, -1, 0);
    fn_80017FEC(0x1d, 0, 0, 0, 0, -1, 0);
}

extern "C" void fn_8003C494(Vec3_8003C318* out) {
    Vec3_8003C318 v;
    Vec3_8003C318 w;
    fn_80115914(&v, *(f32*)(lbl_802BF188 + 0x1c));
    w = v;
    *out = w;
}

extern "C" void* fn_8003C4F4(void) {
    return lbl_802BF188;
}

extern "C" f32 fn_8003C500(void) {
    return *(f32*)(lbl_802BF188 + 0x1c);
}

extern "C" void fn_8003C7DC(void) {
    Color_8003C7DC color;
    f32 nearz = lbl_802FFDD0;
    u8* cam = *(u8**)(lbl_802B7CA0 + 0x16c0);
    f32 farz;
    int i;
    color.r = lbl_802FEFAC[0];
    color.g = lbl_802FEFAC[1];
    color.b = lbl_802FEFAC[2];
    farz = lbl_802FFDF0;
    if (cam != 0) {
        if (*(f32*)(cam + 0xc8) >= lbl_802FFDD4 && *(f32*)(cam + 0xcc) >= lbl_802FFDD4 &&
            *(f32*)(cam + 0xc8) < *(f32*)(cam + 0xcc)) {
            nearz = *(f32*)(cam + 0xc8);
            farz = *(f32*)(cam + 0xcc);
        }
    }
    fn_801DEA74(2, color, lbl_802FEE5C, lbl_802FEE60, nearz, farz);
    for (i = 0; i < 10; i++) {
        lbl_802BF1FC.r[i] = lbl_80246984[lbl_802FF057].r[i];
    }
    fn_801DEC98(lbl_802FF056, lbl_802FF054, &lbl_802BF1FC);
}

extern "C" void fn_8003CB48(void* p) {
    fn_80043518(lbl_802EE470, (u8*)p + 0x10, (u8*)p + 0x4c, (u8*)p + 0x50);
}

extern "C" void fn_8003CB80(void* p) {
    fn_80043FCC(lbl_802EE470, (u8*)p + 0x20, (u8*)p + 0x10, (u8*)p + 0x14);
}

extern "C" void fn_8003CC68(void);
extern "C" void* fn_8003CC2C(void* ptr, s16 param_2);
extern "C" void* fn_8003CBB8(void* param_1) {
    *(void**)param_1 = lbl_80299A8C;
    *((s32*)param_1 + 1) = 0;
    *((s32*)param_1 + 2) = 0;
    *((s32*)param_1 + 3) = 0;
    *(void**)param_1 = lbl_80246ABC;
    fn_801E0DB8((char*)param_1 + 0x18, (void*)fn_8003CC68, (void*)fn_8003CC2C, 0x38, 0x64);
    return param_1;
}

extern "C" void* fn_8003CC2C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8003CC68(void) {}

extern "C" void fn_8003CC6C(int param_1) {
    fn_80047B58(lbl_802EE470, (void*)(param_1 + 0x10));
    fn_80047144(lbl_802EE470, (void*)(param_1 + 0x10));
}

extern "C" void* fn_8003CCB4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8003CCF0(void) {}

extern "C" void fn_8003CCF4(void* param_1) {
    fn_8004816C(lbl_802EE470, (char*)param_1 + 0x10);
}

extern "C" void* fn_8003CD24(void* param_1) {
    *(void**)param_1 = lbl_80299A8C;
    *((s32*)param_1 + 1) = 0;
    *((s32*)param_1 + 2) = 0;
    *((s32*)param_1 + 3) = 0;
    *(void**)param_1 = lbl_80246A54;
    fn_801E0DB8((char*)param_1 + 0x20, (void*)fn_8003CDD4, (void*)fn_8003CD98, 0x2c, 0x64);
    return param_1;
}

extern "C" void* fn_8003CD98(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8003CDD4(void) {}

extern "C" void fn_8003CDD8(void* param_1) {
    fn_80042638(lbl_802EE470, (char*)param_1 + 0x10, (char*)param_1 + 0x14);
}

extern "C" void fn_8003CEBC(void);
extern "C" void* fn_8003CE80(void* ptr, s16 param_2);
extern "C" void* fn_8003CE0C(void* param_1) {
    *(void**)param_1 = lbl_80299A8C;
    *((s32*)param_1 + 1) = 0;
    *((s32*)param_1 + 2) = 0;
    *((s32*)param_1 + 3) = 0;
    *(void**)param_1 = lbl_80246A20;
    fn_801E0DB8((char*)param_1 + 0x18, (void*)fn_8003CEBC, (void*)fn_8003CE80, 0x38, 0x96);
    return param_1;
}

extern "C" void* fn_8003CE80(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8003CEBC(void) {}

extern "C" void fn_80045AB8(void* dst, void* src);
extern "C" void fn_8003CEC0(void* param_1) {
    fn_80045AB8(lbl_802EE470, (char*)param_1 + 0x10);
}

extern "C" void fn_80040120(void) {
    extern void* lbl_802BF0E8[];
    register void* obj1 = lbl_802BF0E8[1];
    if (obj1 != nullptr) {
        register void** vtable = *(void***)obj1;
        void (*dtor)(void*, s16) = (void (*)(void*, s16))vtable[4];
        dtor(obj1, 1);
    }
    lbl_802BF0E8[1] = nullptr;
    
    register void* obj2 = lbl_802BF0E8[2];
    if (obj2 != nullptr) {
        register void** vtable = *(void***)obj2;
        void (*dtor)(void*, s16) = (void (*)(void*, s16))vtable[4];
        dtor(obj2, 1);
    }
    lbl_802BF0E8[2] = nullptr;
}

extern "C" void* fn_80040628(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_800415DC(void) {}

extern "C" void fn_800415E0(void) {}

extern "C" void fn_800415E4(void* self) {
    u8* p = (u8*)(*(VObj_80041AC4**)((u8*)self + 0x2c))->vf68(0);
    if (p != 0) {
        *(s16*)(lbl_802FEF6C + 6) = *(s16*)(p + 6);
        (*(VObj_80041AC4**)((u8*)self + 0x2c))->vf60(0, lbl_802FEF6C);
    }
    u8* q = (u8*)(*(VObj_80041740**)((u8*)self + 0x2c))->vf74(0);
    if (q != 0) {
        lbl_802FEF74[3] = q[3];
        (*(VObj_80041740**)((u8*)self + 0x2c))->vf6C(0, lbl_802FEF74);
    }
    if ((*(VObj_80041740**)((u8*)self + 0x34))->vf30() != 0) {
        u8* r = (u8*)(*(VObj_80041740**)((u8*)self + 0x34))->vf30();
        if (r[0] != 0) {
            r[0] = 2;
            *(f32*)(r + 4) = lbl_802FEE74;
            *(f32*)(r + 8) = lbl_802FEE78;
            if (*(f32*)(r + 4) > *(f32*)(r + 8)) {
                *(f32*)(r + 4) = *(f32*)(r + 8);
            }
            *(f32*)(r + 0xc) = *(f32*)(*(u8**)(lbl_802B7CA0 + 0x16c0) + 0xc8);
            *(f32*)(r + 0x10) = *(f32*)(*(u8**)(lbl_802B7CA0 + 0x16c0) + 0xcc);
            r[0x14] = lbl_802FEFAC[0];
            r[0x15] = lbl_802FEFAC[1];
            r[0x16] = lbl_802FEFAC[2];
        }
    }
}

extern "C" void fn_80041740(void* self) {
    u8* p = (u8*)(*(VObj_80041740**)((u8*)self + 0x2c))->vf74(0);
    if (p != 0) {
        lbl_802FEFA8[3] = p[3];
        (*(VObj_80041740**)((u8*)self + 0x2c))->vf6C(0, lbl_802FEFA8);
    }
    if ((*(VObj_80041740**)((u8*)self + 0x34))->vf30() != 0) {
        u8* q = (u8*)(*(VObj_80041740**)((u8*)self + 0x34))->vf30();
        if (q[0] != 0) {
            q[0] = 2;
            *(f32*)(q + 4) = lbl_802FEE5C;
            *(f32*)(q + 8) = lbl_802FEE60;
            if (*(f32*)(q + 4) > *(f32*)(q + 8)) {
                *(f32*)(q + 4) = *(f32*)(q + 8);
            }
            *(f32*)(q + 0xc) = *(f32*)(*(u8**)(lbl_802B7CA0 + 0x16c0) + 0xc8);
            *(f32*)(q + 0x10) = *(f32*)(*(u8**)(lbl_802B7CA0 + 0x16c0) + 0xcc);
            q[0x14] = lbl_802FEF80[0];
            q[0x15] = lbl_802FEF80[1];
            q[0x16] = lbl_802FEF80[2];
        }
    }
}

extern u8 lbl_802FF00C[4];
extern s16 lbl_802FEFAC[3];
extern f32 lbl_802FEE74;
extern f32 lbl_802FEE78;
extern "C" void fn_80041854(void* self) {
    u8* p = (u8*)(*(VObj_80041740**)((u8*)self + 0x2c))->vf74(0);
    if (p != 0) {
        lbl_802FF00C[3] = p[3];
        (*(VObj_80041740**)((u8*)self + 0x2c))->vf6C(0, lbl_802FF00C);
    }
    if ((*(VObj_80041740**)((u8*)self + 0x34))->vf30() != 0) {
        u8* q = (u8*)(*(VObj_80041740**)((u8*)self + 0x34))->vf30();
        if (q[0] != 0) {
            q[0] = 2;
            *(f32*)(q + 4) = lbl_802FEE74;
            *(f32*)(q + 8) = lbl_802FEE78;
            if (*(f32*)(q + 4) > *(f32*)(q + 8)) {
                *(f32*)(q + 4) = *(f32*)(q + 8);
            }
            *(f32*)(q + 0xc) = *(f32*)(*(u8**)(lbl_802B7CA0 + 0x16c0) + 0xc8);
            *(f32*)(q + 0x10) = *(f32*)(*(u8**)(lbl_802B7CA0 + 0x16c0) + 0xcc);
            q[0x14] = lbl_802FEFAC[0];
            q[0x15] = lbl_802FEFAC[1];
            q[0x16] = lbl_802FEFAC[2];
        }
    }
}

extern u8 lbl_802FF030[8];
extern u8 lbl_802FF038[4];
extern "C" void fn_80041968(void* self) {
    u8* p = (u8*)(*(VObj_80041AC4**)((u8*)self + 0x2c))->vf68(0);
    if (p != 0) {
        *(s16*)(lbl_802FF030 + 6) = *(s16*)(p + 6);
        (*(VObj_80041AC4**)((u8*)self + 0x2c))->vf60(0, lbl_802FF030);
    }
    u8* q = (u8*)(*(VObj_80041740**)((u8*)self + 0x2c))->vf74(0);
    if (q != 0) {
        lbl_802FF038[3] = q[3];
        (*(VObj_80041740**)((u8*)self + 0x2c))->vf6C(0, lbl_802FF038);
    }
    if ((*(VObj_80041740**)((u8*)self + 0x34))->vf30() != 0) {
        u8* r = (u8*)(*(VObj_80041740**)((u8*)self + 0x34))->vf30();
        if (r[0] != 0) {
            r[0] = 2;
            *(f32*)(r + 4) = lbl_802FEE74;
            *(f32*)(r + 8) = lbl_802FEE78;
            if (*(f32*)(r + 4) > *(f32*)(r + 8)) {
                *(f32*)(r + 4) = *(f32*)(r + 8);
            }
            *(f32*)(r + 0xc) = *(f32*)(*(u8**)(lbl_802B7CA0 + 0x16c0) + 0xc8);
            *(f32*)(r + 0x10) = *(f32*)(*(u8**)(lbl_802B7CA0 + 0x16c0) + 0xcc);
            r[0x14] = lbl_802FEFAC[0];
            r[0x15] = lbl_802FEFAC[1];
            r[0x16] = lbl_802FEFAC[2];
        }
    }
}

extern "C" void fn_80041AC4(void* self) {
    s16* p = (s16*)(*(VObj_80041AC4**)((u8*)self + 0x2c))->vf68(0);
    if (p != 0) {
        *(s16*)((u8*)&lbl_802FF04C + 6) = p[3];
        (*(VObj_80041AC4**)((u8*)self + 0x2c))->vf60(0, &lbl_802FF04C);
    }
}

extern "C" void* fn_80041B34(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802469E8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_800401AC(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246AF4;
        fn_801E0D40((char*)param_1 + 0x20, &fn_8000CEC4, 0xc, 0x8);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80040230(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246B28;
        fn_801E0D40((char*)param_1 + 0x10, &fn_8000CEC4, 0xc, 0x2);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800402B4(void) {
    extern void* lbl_802BF110[];
    register void* obj = lbl_802BF110[2];
    if (obj != nullptr) {
        void (*dtor)(void*, s16) = (void (*)(void*, s16)) * (void**)((*(void***)obj)[4]);
        dtor(obj, 1);
    }
    lbl_802BF110[2] = nullptr;
}

extern "C" void* fn_80040308(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246ABC;
        fn_801E0D40((char*)param_1 + 0x18, &fn_8003CC2C, 0x38, 0x64);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_8004038C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246A88;
        fn_801E0D40((char*)param_1 + 0x14, &fn_8003CCB4, 0x38, 0x64);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80040464(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246A20;
        fn_801E0D40((char*)param_1 + 0x18, &fn_8003CE80, 0x38, 0x96);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800404E8(void) {
    extern void* lbl_802BF0F4[];
    if (lbl_802BF0F4[3] != nullptr) {
        register void** vtable = *(void***)lbl_802BF0F4[3];
        void (*fn)(void*, s16) = (void (*)(void*, s16))vtable[4];
        fn(lbl_802BF0F4[3], 1);
    }
    lbl_802BF0F4[3] = nullptr;
}

extern "C" void* fn_8004053C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246A54;
        fn_801E0D40((char*)param_1 + 0x20, &fn_8003CD98, 0x2c, 0x64);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800405C0(void) {
    extern void* lbl_802BF128[];
    void* obj = lbl_802BF128[2];
    if (obj != nullptr) {
        fn_801E0D40(obj, &fn_80040628, 0x34, 0x1e);
        fn_8015AB1C(obj);
    }
    lbl_802BF128[2] = nullptr;
}

extern "C" void fn_8003FBA4(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFB4[0] = (s16)(s32)d1;
    lbl_802FEFB4[1] = (s16)(s32)d2;
    lbl_802FEFB4[2] = (s16)(s32)d3;
}

extern s16 lbl_802FEFBC[3];
extern "C" void fn_8003FC40(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFBC[0] = (s16)(s32)d1;
    lbl_802FEFBC[1] = (s16)(s32)d2;
    lbl_802FEFBC[2] = (s16)(s32)d3;
}

extern s16 lbl_802FEFC4[3];
extern "C" void fn_8003FCDC(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFC4[0] = (s16)(s32)d1;
    lbl_802FEFC4[1] = (s16)(s32)d2;
    lbl_802FEFC4[2] = (s16)(s32)d3;
}

extern s16 lbl_802FEFCC[3];
extern "C" void fn_8003FD78(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFCC[0] = (s16)(s32)d1;
    lbl_802FEFCC[1] = (s16)(s32)d2;
    lbl_802FEFCC[2] = (s16)(s32)d3;
}

extern s16 lbl_802FEFD4[3];
extern "C" void fn_8003FE14(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFD4[0] = (s16)(s32)d1;
    lbl_802FEFD4[1] = (s16)(s32)d2;
    lbl_802FEFD4[2] = (s16)(s32)d3;
}

extern s16 lbl_802FEFDC[3];
extern "C" void fn_8003FEB0(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFDC[0] = (s16)(s32)d1;
    lbl_802FEFDC[1] = (s16)(s32)d2;
    lbl_802FEFDC[2] = (s16)(s32)d3;
}

extern s16 lbl_802FEFE4[3];
extern "C" void fn_8003FF4C(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFE4[0] = (s16)(s32)d1;
    lbl_802FEFE4[1] = (s16)(s32)d2;
    lbl_802FEFE4[2] = (s16)(s32)d3;
}

extern s16 lbl_802FEFEC[3];
extern "C" void fn_8003FFE8(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFEC[0] = (s16)(s32)d1;
    lbl_802FEFEC[1] = (s16)(s32)d2;
    lbl_802FEFEC[2] = (s16)(s32)d3;
}

extern s16 lbl_802FEFF4[3];
extern "C" void fn_80040084(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    f32 d1 = (f32)param_1 * factor;
    f32 d2 = (f32)param_2 * factor;
    f32 d3 = (f32)param_3 * factor;

    lbl_802FEFF4[0] = (s16)(s32)d1;
    lbl_802FEFF4[1] = (s16)(s32)d2;
    lbl_802FEFF4[2] = (s16)(s32)d3;
}

