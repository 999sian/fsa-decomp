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
struct Arg_8008CF88 { u32 a, b, c; };
extern const Arg_8008CF88 lbl_80284BCC;
extern const Arg_8008CF88 lbl_80284BD8;
extern u32 lbl_802FEDD8;
extern s32 lbl_802FEDE4;
extern "C" void fn_8008CF88(void* self, Arg_8008CF88* arg, s32 n);
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

extern "C" void fn_8008C5F4(void);
extern "C" void fn_8008C4DC(void) {
    fn_8008C5F4();
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

extern "C" void fn_8008C4FC(void);
extern "C" void fn_8008D420(void) {
    fn_8008C4FC();
}

extern "C" void fn_8008C994(void);
extern "C" void fn_8008D4BC(void) {
    fn_8008C994();
}

extern "C" BOOL fn_8008D5B4(void);
extern "C" BOOL fn_8008D5B4(void)
{
    return TRUE;
}

extern "C" void fn_8008D6F8(f32* p) {
    f32 v[3] = {lbl_802C53E4[0], lbl_802C53E4[1], lbl_802C53E4[2]};
    p[0] = v[0];
    p[1] = v[1];
    p[2] = v[2];
}

extern "C" void fn_8008D938(void* p) {
    fn_8008D820(p, *(s32*)(lbl_802BB0FC + 0x3f0) + 1);
}

extern char lbl_802BB0FC[];
extern char lbl_801FDAC8[];
extern f32 lbl_802C53E4[];
extern "C" void fn_8008D820(void* p, s32 n);
struct Rec8008DA68 { u32 a, b, c; };

extern "C" void fn_8008DA68(Rec8008DA68* p) {
    Rec8008DA68* src = &((Rec8008DA68*)lbl_801FDAC8)[*(s32*)(lbl_802BB0FC + 0x424)];
    u32 a = src->a;
    u32 b = src->b;
    p->a = a;
    u32 c = src->c;
    p->b = b;
    p->c = c;
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
