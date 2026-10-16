#include "types.h"

struct FsaHeapUser {
    virtual void m0(int) = 0;
    virtual void m1() = 0;
    virtual void m2(int) = 0;
};


extern "C" char lbl_804B1D10[];
extern "C" void* lbl_8053AF30;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80543DC0;
extern "C" void fn_8013B490(void*);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
extern "C" void* lbl_8053AAF8;
extern "C" void* sCurrentHeap__7JKRHeap;
extern "C" void becomeCurrentHeap__7JKRHeapFv(void*);
extern "C" void freeAll__7JKRHeapFv(void*);
extern "C" void __dl__FPv(void* p);
extern "C" int fn_8044B80C(u8* p, u8 param_2)
{
    void* oldHeap;

    if (param_2 >= 8) {
        return 0;
    }
    if (p[0x16] == 3) {
        if (p[0x15] == param_2) {
            return 1;
        }
        p[0x15] = param_2;
        p[0x16] = 1;
        oldHeap = sCurrentHeap__7JKRHeap;
        becomeCurrentHeap__7JKRHeapFv(*(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x30));
        if (*(void**)(p + 8) != NULL) {
            void* obj = *(void**)(p + 8);
            void (*fn)(void*, int) = (void (*)(void*, int))(*(void***)obj)[2];
            fn(obj, 1);
        }
        *(void**)(p + 8) = NULL;
        freeAll__7JKRHeapFv(*(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x30));
        becomeCurrentHeap__7JKRHeapFv(oldHeap);
    } else if (p[0x16] == 0) {
        p[0x15] = param_2;
        p[0x16] = 1;
    }
    return 0;
}

extern "C" void fn_8044B8EC(u8* p)
{
    if (p[0x14] != 0 && p[0x16] == 3 && *(void**)(p + 8) != NULL) {
        fn_8013B490(lbl_8053AB10);
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 8), lbl_80543DC0, lbl_80543DC0, *(void**)((u8*)lbl_8053AB10 + 0x10));
        p[0x14] = 0;
    }
}

extern "C" void* fn_8044BCA4(u8* p, s16 param_2)
{
    void* oldHeap;

    if (p != 0) {
        *(char**)p = lbl_804B1D10;
        if (*(void**)(p + 4) != 0) {
            oldHeap = sCurrentHeap__7JKRHeap;
            becomeCurrentHeap__7JKRHeapFv(*(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x30));
            if (*(void**)(p + 4) != 0) {
                ((FsaHeapUser*)*(void**)(p + 4))->m0(1);
            }
            *(void**)(p + 4) = 0;
            freeAll__7JKRHeapFv(*(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x30));
            becomeCurrentHeap__7JKRHeapFv(oldHeap);
        }
        if (*(void**)(p + 8) != 0) {
            oldHeap = sCurrentHeap__7JKRHeap;
            becomeCurrentHeap__7JKRHeapFv(*(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x30));
            if (*(void**)(p + 8) != 0) {
                ((FsaHeapUser*)*(void**)(p + 8))->m0(1);
            }
            *(void**)(p + 8) = 0;
            freeAll__7JKRHeapFv(*(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x30));
            becomeCurrentHeap__7JKRHeapFv(oldHeap);
        }
        lbl_8053AF30 = 0;
        if (param_2 > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_8044BDCC(u8* p)
{
    *(char**)p = lbl_804B1D10;
    lbl_8053AF30 = p;
    *(u32*)(p + 4) = 0;
    *(u32*)(p + 8) = 0;
    *(u32*)(p + 0xc) = 0;
    *(u32*)(p + 0x10) = 0;
    p[0x14] = 0;
    p[0x15] = 0xff;
    p[0x16] = 0;
}
