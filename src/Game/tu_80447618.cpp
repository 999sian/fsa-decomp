#include "types.h"

struct fn_80447B34_Obj {
    virtual void Release(int);
};

struct JKRArchive;
struct J2DPane {
virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
virtual void vfE0(); virtual void vfE4(); virtual void vfE8(); virtual void vfEC();
virtual void vfF0(); virtual void vfF4(); virtual void vfF8(); virtual void vfFC();
virtual void vf100(); virtual void vf104();
virtual void changeTexture(void*, u8);
u8 pad[0xac];
u8 mVisible;
};
struct J2DScreen {
    J2DScreen();
    void setPriority(const char*, unsigned long, JKRArchive*);
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual J2DPane* search(u64);
    u8 pad[0x114];
};
struct TagEntry {
    u8 pad[0x30];
    u64 tag0;
    u8 pad2[0x30];
    u64 tag1;
};
struct ArcHolder {
    u8 pad[0x10];
    JKRArchive* arc;
};
extern "C" {
extern TagEntry lbl_80490410[];
extern ArcHolder lbl_80529DEC_;
}
struct PaneCtrl {
    PaneCtrl();
    void* vt;
    u8 pad[0x28];
};
struct Obj80447C30 {
    void* vt;
    J2DScreen* screen;
    PaneCtrl* a[4];
    PaneCtrl* b[4];
    u8 f28, f29, f2a, f2b, f2c;
};

extern "C" {
extern void* lbl_804B1C20;
extern void* lbl_8053AF08;
extern void* lbl_80490698;
extern void* lbl_804AF86C;
extern void* lbl_80529DEC;

extern void* __nw__FUl(unsigned long size);
extern void __ct__9J2DScreenFv();
extern void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* pane, const char* name, unsigned long id, void* archive);
extern void fn_80402F04(void* a, void* b);
extern void* lbl_8053AED0;
extern f32 fn_8043D514(void* a);
extern f32 fn_8043D57C(void* a);
extern void fn_80402E08(void* a, f32 b);
}

extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" const char* lbl_804B1BF8[];
typedef void (*PaneSetFn)(J2DPane*, void*, int);
extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543D98;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern "C" void fn_80447618(void* self_) {
    u8* self = (u8*)self_;
    u8* params = (u8*)(lbl_80490410);
    typedef void* (*VFunc)(void*, void*, void*);
    typedef void (*VFunc2)(void*, void*, int);

    for (int i = 0; i < 4; i++) {
        if (i < 2) {
            fn_80402E08(*(void**)(self + 8 + i * 4), lbl_80543D98, fn_8043D514(lbl_8053AED0));
            fn_80402E08(*(void**)(self + 0x18 + i * 4), lbl_80543D98, fn_8043D514(lbl_8053AED0));
        } else {
            fn_80402E08(*(void**)(self + 8 + i * 4), lbl_80543D98, fn_8043D57C(lbl_8053AED0));
            fn_80402E08(*(void**)(self + 0x18 + i * 4), lbl_80543D98, fn_8043D57C(lbl_8053AED0));
        }

        u8 flag = self[0x2c];
        u8 bit = 1 << i;

        if ((flag & bit) == 0) {
            VFunc method = (VFunc)((*(void***)(*(void**)(self + 4)))[15]);
            void* res = method(*(void**)(self + 4), *(void**)(params + 0x30 + i * 0x70), *(void**)(params + 0x34 + i * 0x70));
            if (((u8*)res)[0xb0] != 0) {
                res = method(*(void**)(self + 4), *(void**)(params + 0x30 + i * 0x70), *(void**)(params + 0x34 + i * 0x70));
                ((u8*)res)[0xb0] = 0;
                res = method(*(void**)(self + 4), *(void**)(params + 0x68 + i * 0x70), *(void**)(params + 0x6c + i * 0x70));
                ((u8*)res)[0xb0] = 0;
            }
        } else {
            VFunc method = (VFunc)((*(void***)(*(void**)(self + 4)))[15]);
            void* res = method(*(void**)(self + 4), *(void**)(params + 0x30 + i * 0x70), *(void**)(params + 0x34 + i * 0x70));
            if (((u8*)res)[0xb0] == 0) {
                res = method(*(void**)(self + 4), *(void**)(params + 0x30 + i * 0x70), *(void**)(params + 0x34 + i * 0x70));
                ((u8*)res)[0xb0] = 1;
                res = method(*(void**)(self + 4), *(void**)(params + 0x68 + i * 0x70), *(void**)(params + 0x6c + i * 0x70));
                ((u8*)res)[0xb0] = 1;
            }
        }

        VFunc method = (VFunc)((*(void***)(*(void**)(self + 4)))[15]);
        void* res = method(*(void**)(self + 4), *(void**)(params + 0x30 + i * 0x70), *(void**)(params + 0x34 + i * 0x70));
        if (((u8*)res)[0xb0] != 0) {
            if (self[0x28 + i] > 0x64) {
                self[0x28 + i] = 0x63;
            }
            u8 val = self[0x28 + i];
            u8 div = val / 10;
            u8 mod = val % 10;

            void* c1 = fn_804030C4(0x54494d47, lbl_804B1BF8[div]);
            res = method(*(void**)(self + 4), *(void**)(params + 0x48 + i * 0x70), *(void**)(params + 0x4c + i * 0x70));
            VFunc2 method2 = (VFunc2)((*(void***)res)[68]);
            method2(res, c1, 0);

            res = method(*(void**)(self + 4), *(void**)(params + 0x50 + i * 0x70), *(void**)(params + 0x54 + i * 0x70));
            method2 = (VFunc2)((*(void***)res)[68]);
            method2(res, c1, 0);

            void* c2 = fn_804030C4(0x54494d47, lbl_804B1BF8[mod]);
            res = method(*(void**)(self + 4), *(void**)(params + 0x58 + i * 0x70), *(void**)(params + 0x5c + i * 0x70));
            method2 = (VFunc2)((*(void***)res)[68]);
            method2(res, c2, 0);

            res = method(*(void**)(self + 4), *(void**)(params + 0x60 + i * 0x70), *(void**)(params + 0x64 + i * 0x70));
            method2 = (VFunc2)((*(void***)res)[68]);
            method2(res, c2, 0);
        }
    }

    self[0x2c] = 0;
}

extern "C" void fn_80447958(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543D98;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_804479A0(Obj80447C30* self)
{
    for (int i = 0; i < 4; i++) {
        self->f2c &= ~(u8)(1 << i);
        void* res = fn_804030C4('TIMG', lbl_804B1BF8[0]);
        TagEntry* e = &lbl_80490410[i];
        self->screen->search(*(u64*)(e->pad2 + 0x10))->changeTexture(res, 0);
        self->screen->search(*(u64*)(e->pad2 + 0x18))->changeTexture(res, 0);
        self->screen->search(*(u64*)(e->pad2 + 0x20))->changeTexture(res, 0);
        self->screen->search(*(u64*)(e->pad2 + 0x28))->changeTexture(res, 0);
        self->screen->search(e->tag0)->mVisible = 0;
        self->screen->search(e->tag1)->mVisible = 0;
    }
}

extern "C" Obj80447C30* fn_80447C30(Obj80447C30* self) {
    self->vt = &lbl_804B1C20;
    lbl_8053AF08 = self;
    self->screen = new J2DScreen();
    self->screen->setPriority((const char*)&lbl_80490698, 0x1100000, ((ArcHolder*)&lbl_80529DEC)->arc);
    for (int i = 0; i < 4; i++) {
        PaneCtrl* p = (PaneCtrl*)operator new(0x2c);
        if (p) p->vt = &lbl_804AF86C;
        self->a[i] = p;
        fn_80402F04(self->a[i], self->screen->search(lbl_80490410[i].tag0));
        p = (PaneCtrl*)operator new(0x2c);
        if (p) p->vt = &lbl_804AF86C;
        self->b[i] = p;
        fn_80402F04(self->b[i], self->screen->search(lbl_80490410[i].tag1));
    }
    self->f28 = 0;
    self->f29 = 0;
    self->f2a = 0;
    self->f2b = 0;
    self->f2c = 0;
    return self;
}
