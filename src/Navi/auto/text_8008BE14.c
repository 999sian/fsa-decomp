#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008be14-0x8008db20 (36 functions). split_file divides it into the game's real files.

extern void* lbl_80284C98[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8008BE64(void);
extern char lbl_802BB0FC[];
extern char lbl_801FDAC8[];
extern f32 lbl_802C53E4[];
extern "C" void fn_8008D820(void* p, s32 n);
extern void* lbl_8024751C[];
extern "C" void fn_8008BE14(void* p);
extern "C" void fn_80041268(void* a, void* b, s32 n);
extern "C" void fn_8000E0F0(void* self, void* arg, f32 value);
extern "C" void fn_8000EBB8(void* a);
extern s16 lbl_802FF04C[3];
extern char lbl_802B7CA0[];
extern char lbl_80284B68[];
extern char lbl_802FCEF8[8];
extern char lbl_802FCF00[4];
extern char lbl_802FCF04[8];
extern "C" void* fn_800638A4(const char* name, s32 a, void* b, s32 c);
extern "C" void* fn_80011CF4(void* res, s32 a, u32 flags);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void* a, const char* b, s32 c, const char* d, ...);
extern "C" void fn_80007AB8(const char* file, s32 line, const char* msg, ...);
struct Arg_8008CF88 { u32 a, b, c; };
extern const Arg_8008CF88 lbl_80284BCC;
extern const Arg_8008CF88 lbl_80284BD8;
extern u32 lbl_802FEDD8;
extern s32 lbl_802FEDE4;
extern Arg_8008CF88 lbl_802026C0;
extern f32 lbl_80300A7C;
extern f32 lbl_802FF1E8;
extern s32 lbl_802FF1EC;
extern "C" int fn_80020EA4(void* p, void* q);
extern "C" int fn_800175B8(void* p);
extern "C" void fn_80011688(void);
extern "C" void fn_8000CEC4(void);
extern "C" void fn_801E0DB8(void* self, void* a, void* b, s32 size, s32 count);
extern "C" int fn_800183AC(void* p, void* f, s32 n);
extern "C" int fn_8008C6E0(void* p);
struct StateObj_8008CF88;
typedef BOOL (StateObj_8008CF88::*StateFunc_8008CF88)(int);
struct StateObj_8008CF88 {
    u8 pad[0x2e0];
    s8 m_state;
    u8 pad2[3];
    StateFunc_8008CF88 m_func;
    u8 pad3[0xc];
    s32 m_unk2fc[4];
    f32 m_unk30c[2];
};
extern "C" s32 fn_801E10A0(void*);
extern "C" s32 fn_801E1070(void*);
extern "C" void fn_801E10DC(void*, void*);
extern "C" BOOL fn_8008CF88(void* self, Arg_8008CF88* arg, s32 n);
struct VObj_8008C40C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void* v24(s32);
};
extern "C" void fn_8008BE14(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_8024751C;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
}

extern "C" void fn_8008BE44(void) {
    fn_8008BE64();
}

extern "C" BOOL fn_8008C0A4(char* p) {
    if (p[0x260] == 0) {
        p[0x260]++;
    }
    return TRUE;
}

extern u8 lbl_802FCEC8;
extern "C" void fn_800636F4(void*, void*, s32);
extern char lbl_802B7CA0[];
extern char lbl_802EE470[];
extern "C" int fn_8008C24C(void)
{
    fn_800636F4(&lbl_802FCEC8, lbl_802B7CA0 + 0x2200, 0x40);
    return 1;
}

extern "C" int fn_8008C40C(char* p) {
    char* m = p + 0x180;
    fn_80041268(*(void**)(p + 0x24c), m, 5);
    fn_8000EBB8(*(void**)(p + 0x24c));
    fn_80041268(*(void**)(p + 0x250), m, 2);
    char* c = *(char**)(*(char**)(*(char**)(p + 0x250) + 4) + 0x60);
    VObj_8008C40C* e = *(VObj_8008C40C**)(*(char**)c + 0x2c);
    s16* dst = (s16*)e->v24(0);
    dst[0] = lbl_802FF04C[0];
    dst[1] = lbl_802FF04C[1];
    dst[2] = lbl_802FF04C[2];
    fn_8000E0F0(p + 0x254, *(char**)(*(char**)(p + 0x250) + 4) + 0x58, *(f32*)(*(char**)(p + 0x258) + 0x10));
    fn_8000EBB8(*(void**)(p + 0x250));
    return 1;
}

extern "C" BOOL fn_8008C4D4(void);
extern "C" BOOL fn_8008C4D4(void)
{
    return TRUE;
}

extern "C" s32 fn_8008C5F4(u8* self);
extern "C" void fn_8008C4DC(u8* self) {
    fn_8008C5F4(self);
}

#pragma dont_inline on
extern "C" int fn_8008C4FC(u8* p) {
    int r = fn_80020EA4(p + 0x244, lbl_802FCEF8);
    if (r == 4) {
        if ((*(u32*)(p + 0xf8) & 8) == 0) {
            if (p != nullptr) {
                fn_800175B8(p);
                fn_801E0DB8(p + 0x250, (void*)fn_80011688, (void*)fn_8000CEC4, 0xc, 9);
                Arg_8008CF88 a = lbl_802026C0;
                *(Arg_8008CF88*)(p + 0x2e4) = a;
                *(Arg_8008CF88*)(p + 0x2f0) = a;
                lbl_802FF1E8 = lbl_80300A7C;
                lbl_802FF1EC = 0;
            }
            *(u32*)(p + 0xf8) |= 8;
        }
        if ((u8)fn_800183AC(p, (void*)fn_8008C4DC, 0x6830)) {
            return fn_8008C6E0(p);
        }
        return 5;
    }
    return r;
}
#pragma dont_inline reset

extern "C" s32 fn_8008C5F4(u8* self) {
    char* str = lbl_80284B68;
    void* res = fn_800638A4(lbl_802FCEF8, 10, lbl_802B7CA0 + 0x2200, 0x40);
    if (res == NULL) {
        fn_8011FD18(fn_8011FD10(), str + 0x18, 0x15b, lbl_802FCF00, str + 0x28);
        fn_80007AB8(str + 0x18, 0x15b, lbl_802FCF04);
    }
    *(void**)(self + 0x24c) = fn_80011CF4(res, 0, 0x11000022);
    if (*(void**)(self + 0x24c) == NULL) {
        fn_8011FD18(fn_8011FD10(), str + 0x18, 0x161, lbl_802FCF00, str + 0x38);
        fn_80007AB8(str + 0x18, 0x161, lbl_802FCF04);
    }
    return 1;
}

extern "C" s32 fn_8008CB14(u8* self) {
    if (*(s8*)(self + 0x2e0) == 0) {
        (*(s8*)(self + 0x2e0))++;
    } else if (*(s8*)(self + 0x2e0) != -1) {
        if (*(s32*)(lbl_802BB0FC + 0x44) >= 0xe) {
            Arg_8008CF88 a = lbl_80284BCC;
            fn_8008CF88((StateObj_8008CF88*)self, &a, 0);
        } else if (lbl_802FEDD8 & 1) {
            switch (lbl_802FEDE4) {
            case 1: {
                Arg_8008CF88 b = lbl_80284BD8;
                fn_8008CF88((StateObj_8008CF88*)self, &b, 0);
                break;
            }
            }
        }
    }
    return 1;
}

extern f32 lbl_80300A8C;
extern f32 lbl_80300A90;
extern char lbl_802C5408[];
extern "C" void fn_80017FCC(void);
extern "C" BOOL fn_8008CE70(char* p) {
    if (p[0x2e0] == 0) {
        p[0x2e0]++;
    } else if (p[0x2e0] != -1) {
        f32* f = (f32*)lbl_802C5408;
        f[3] -= lbl_80300A8C;
        if (f[3] < lbl_80300A90) {
            fn_80017FCC();
        }
    }
    return TRUE;
}

extern char lbl_8029F8D8[];
extern f32 lbl_802C53CC[];
extern s16 lbl_802FF1E0[];
extern "C" void fn_801C61AC(void* p, f32 x, f32 y, f32 z);
extern "C" void fn_8000CB28(void* p, s32 n);
extern "C" void fn_8000CA54(void* p, s32 n);
extern "C" void fn_8000CBFC(void* p, s32 n);
extern "C" void fn_801C5D74(void* p, void* q);
extern s16 lbl_802FF1E0[3];
extern "C" void fn_8008CEDC(char* p) {
    char* sub = *(char**)(p + 0x24c);
    *(f32*)(sub + 0x18) = *(f32*)(p + 0x144);
    *(f32*)(sub + 0x1c) = *(f32*)(p + 0x148);
    *(f32*)(sub + 0x20) = *(f32*)(p + 0x14c);
    fn_801C61AC(lbl_8029F8D8, lbl_802C53CC[0], lbl_802C53CC[1], lbl_802C53CC[2]);
    fn_8000CB28(lbl_8029F8D8, lbl_802FF1E0[1]);
    fn_8000CA54(lbl_8029F8D8, lbl_802FF1E0[0]);
    fn_8000CBFC(lbl_8029F8D8, lbl_802FF1E0[2]);
    fn_801C5D74(lbl_8029F8D8, *(char**)(p + 0x24c) + 0x24);
}

extern "C" BOOL fn_8008CF88(void* self, Arg_8008CF88* arg, s32 n) {
    StateObj_8008CF88* obj = (StateObj_8008CF88*)self;
    if (fn_801E10A0(&obj->m_func) != 0) {
        if (fn_801E1070(&obj->m_func) != 0) {
            obj->m_state = -1;
            (obj->*obj->m_func)(n);
        }
        obj->m_func = *(StateFunc_8008CF88*)arg;
        obj->m_state = 0;
        obj->m_unk2fc[0] = 0;
        obj->m_unk2fc[1] = 0;
        obj->m_unk2fc[2] = 0;
        obj->m_unk2fc[3] = 0;
        obj->m_unk30c[0] = 0.0f;
        obj->m_unk30c[1] = 0.0f;
        (obj->*obj->m_func)(n);
    }
    return TRUE;
}

#pragma dont_inline on
extern "C" int fn_8008C4FC(u8* p);
#pragma dont_inline reset
extern "C" void fn_8008D420(u8* p) {
    fn_8008C4FC(p);
}

extern "C" void fn_8008C994(void);
extern "C" void fn_8008D4BC(void) {
    fn_8008C994();
}

#pragma use_lmw_stmw off
extern "C" int fn_8008D4DC(char* p) {
    u16 i;
    u8 v;
    char* obj;
    char* elem;
    char* o;
    char* r;
    *(u32*)(lbl_802EE470 + 0x48) = *(u32*)(lbl_802B7CA0 + 0x142c);
    *(u32*)(lbl_802EE470 + 0x4c) = *(u32*)(lbl_802B7CA0 + 0x1430);
    if (*(u8*)(lbl_802C5408 + 0x34) == 0) {
        obj = *(char**)(*(char**)(p + 0x24c) + 4);
        for (i = 0; i < *(u16*)(obj + 0x5c); i++) {
            v = (u8)*(s16*)(lbl_802C5408 + 0x2e);
            elem = ((char**)*(char**)(obj + 0x60))[i];
            o = *(char**)(elem + 0x34);
            r = ((char*(*)(char*))((*(void***)o)[0xf]))(o);
            r[2] = v;
        }
        fn_8000EBB8(*(void**)(p + 0x24c));
    }
    *(u32*)(lbl_802EE470 + 0x48) = *(u32*)(lbl_802B7CA0 + 0x1434);
    *(u32*)(lbl_802EE470 + 0x4c) = *(u32*)(lbl_802B7CA0 + 0x1438);
    return 1;
}
#pragma use_lmw_stmw reset
extern "C" BOOL fn_8008D5B4(void);
extern "C" BOOL fn_8008D5B4(void)
{
    return TRUE;
}

extern "C" void fn_8008D5BC(f32* p, s16* q);

extern "C" void fn_8008D6F8(f32* p) {
    f32 v[3] = {lbl_802C53E4[0], lbl_802C53E4[1], lbl_802C53E4[2]};
    p[0] = v[0];
    p[1] = v[1];
    p[2] = v[2];
}

extern "C" void fn_8008D72C(f32* p, s32 idx) {
    f32 t[3];
    s16 s[2];
    f32 v[3];
    s32 n = idx - 1;
    char* e = (char*)lbl_802BB0FC + ((n % 10) % 10) * 12;
    s16 a = *(s16*)(e + 0x2d6);
    s16 b = *(s16*)(e + 0x2d4);
    s[1] = a;
    s[0] = b;
    fn_8008D5BC(v, s);
    t[0] = v[0];
    t[1] = v[1];
    t[2] = v[2] + (f32)a * *(f32*)((char*)lbl_802C5408 + 0x24);
    p[0] = t[0];
    p[1] = t[1];
    p[2] = t[2];
}

extern "C" void fn_8008D938(void* p) {
    fn_8008D820(p, *(s32*)(lbl_802BB0FC + 0x3f0) + 1);
}

extern "C" void fn_8008D974(f32* p) {
    struct V3 { f32 x, y, z; };
    s32 n = *(s32*)(lbl_802BB0FC + 0x3f0);
    s16 s[2];
    V3 v;
    V3 t;
    s16 x, y;
    char* e = (char*)lbl_802BB0FC + ((n % 10) % 10) * 12;
    s16 a = *(s16*)(e + 0x2d4);
    s16 b = *(s16*)(e + 0x2d6);
    if (lbl_802FEDE4 == 2) {
        x = (a & 0xff00) + 0x80;
        y = (b & 0xff00) + 0x80;
    } else {
        x = (a & 0xfe00) + 0x100;
        y = (b & 0xfe00) + 0x100;
    }
    s[0] = x;
    s[1] = y;
    fn_8008D5BC((f32*)&v, s);
    t = v;
    *(V3*)p = t;
}

extern char lbl_802BB0FC[];
extern char lbl_801FDAC8[];
extern f32 lbl_802C53E4[];
extern "C" void fn_8008D820(void* p, s32 n);
struct Rec8008DA68 {
    u32 a, b, c;
    Rec8008DA68() {}
    Rec8008DA68(const Rec8008DA68& o) { a = o.a; b = o.b; c = o.c; }
    Rec8008DA68(u32 x, u32 y, u32 z) { a = x; b = y; c = z; }
};

extern "C" void fn_8008DA68(void* p) {
    s32 idx = *(s32*)(lbl_802BB0FC + 0x424);
    u32* src = (u32*)(lbl_801FDAC8 + (u32)idx * 12);
    u32* dst = (u32*)p;
    u32 a = src[0];
    u32 b = src[1];
    dst[0] = a;
    u32 c = src[2];
    dst[1] = b;
    dst[2] = c;
}

extern "C" void* fn_8008DAD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80284C98;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
