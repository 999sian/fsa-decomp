#include "types.h"
#include "JSystem/J2D/J2DPane.h"

struct MenuTextData {
    u32 ids[8];
    char archiveFormat[0x20];
    char screenFormat[0x12];
};

struct MenuArchive {
    u8 pad0[8];
    virtual void release(int);
};

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
            FsaHeapUser* obj = *(FsaHeapUser**)(p + 8);
            obj->m0(1);
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

extern "C" const MenuTextData lbl_80490F48;
extern "C" void* lbl_8053AD78;
extern "C" int snprintf(char* s, unsigned long n, const char* fmt, ...);
extern "C" void* fn_80401E10(const char* path, int mode, void* heap);
extern "C" void* __nw__FUl(unsigned long size);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* pane, const char* name, unsigned long id, void* archive);
extern "C" const char* getStringPtr__10J2DTextBoxCFv(void* self);
extern "C" void fn_803832BC(const char*, u32, u32, u32, u32);
#pragma peephole on
#pragma opt_strength_reduction off
extern "C" void fn_8044B960(u8* p)
{
    const MenuTextData& tbl = lbl_80490F48;
    void* oldHeap;
    void* screen;
    char acStack_34[36];
    char acStack_48[20];
    JUTFont* font;
    J2DPane* pane;

    if (p[0x16] == 1 || p[0x16] == 2) {
        oldHeap = sCurrentHeap__7JKRHeap;
        becomeCurrentHeap__7JKRHeapFv(*(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x30));
        if (p[0x16] == 1) {
            snprintf(acStack_34, 0x1f, tbl.archiveFormat, p[0x15] + 1);
            *(void**)(p + 0xc) = fn_80401E10(acStack_34, 0, *(void**)((u8*)*(void**)((u8*)lbl_8053AAF8 + 4) + 0x30));
            p[0x16] = 2;
        }
        if (*(void**)(p + 0xc) != NULL) {
            if (((u8*)*(void**)(p + 0xc))[4] == 1) {
                screen = __nw__FUl(0x118);
                if (screen != NULL) {
                    __ct__9J2DScreenFv(screen);
                }
                *(void**)(p + 8) = screen;
                snprintf(acStack_48, 0x11, tbl.screenFormat, p[0x15] + 1);
                setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(p + 8), acStack_48, 0x1100000, *(void**)((u8*)*(void**)(p + 0xc) + 0x14));
                font = *(JUTFont**)((u8*)lbl_8053AD78 + 0x154);
                pane = (*(J2DPane**)(p + 8))->search(0x0000547374663031ULL);
                ((J2DTextBox*)pane)->setFont(font);
                font = *(JUTFont**)((u8*)lbl_8053AD78 + 0x154);
                pane = (*(J2DPane**)(p + 8))->search(0x0000547374663032ULL);
                ((J2DTextBox*)pane)->setFont(font);
                pane = (*(J2DPane**)(p + 8))->search(0x0000547374663031ULL);
                {
                    const char* text = getStringPtr__10J2DTextBoxCFv(pane);
                    const u32* __restrict ids = tbl.ids;
                    fn_803832BC(text, ids[p[0x15]], 0, 0, 0);
                }
                pane = (*(J2DPane**)(p + 8))->search(0x0000547374663032ULL);
                {
                    const char* text = getStringPtr__10J2DTextBoxCFv(pane);
                    const u32* __restrict ids = tbl.ids;
                    fn_803832BC(text, ids[p[0x15]], 0, 0, 0);
                }
                if (p[0x15] == 5) {
                    font = *(JUTFont**)((u8*)lbl_8053AD78 + 0x154);
                    pane = (*(J2DPane**)(p + 8))->search(0x0000547374663033ULL);
                    ((J2DTextBox*)pane)->setFont(font);
                    font = *(JUTFont**)((u8*)lbl_8053AD78 + 0x154);
                    pane = (*(J2DPane**)(p + 8))->search(0x0000547374663034ULL);
                    ((J2DTextBox*)pane)->setFont(font);
                    pane = (*(J2DPane**)(p + 8))->search(0x0000547374663033ULL);
                    fn_803832BC(getStringPtr__10J2DTextBoxCFv(pane), 0x861, 0, 0, 0);
                    pane = (*(J2DPane**)(p + 8))->search(0x0000547374663034ULL);
                    fn_803832BC(getStringPtr__10J2DTextBoxCFv(pane), 0x861, 0, 0, 0);
                }
                if (*(void**)(p + 0xc) != NULL) {
                    (*(MenuArchive**)(p + 0xc))->release(1);
                }
                p[0x16] = 3;
            }
        }
        becomeCurrentHeap__7JKRHeapFv(oldHeap);
    }
}
#pragma opt_strength_reduction reset
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

void __sinit_tu_8044B80C_cpp(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

