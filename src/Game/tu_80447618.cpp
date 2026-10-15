#include "types.h"

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
}

extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" const char* lbl_804B1BF8[];
typedef void (*PaneSetFn)(J2DPane*, void*, int);
extern "C" void fn_804479A0(Obj80447C30* self)
{
    TagEntry* e = lbl_80490410;
    int i = 0;
    do {
        self->f2c &= (u8)~(u8)(1 << i);
        void* res = fn_804030C4('TIMG', lbl_804B1BF8[0]);
        J2DPane* p;
        p = self->screen->search(*(u64*)(e->pad2 + 0x10));
        (*(PaneSetFn**)p)[0x110 / 4](p, res, 0);
        p = self->screen->search(*(u64*)(e->pad2 + 0x18));
        (*(PaneSetFn**)p)[0x110 / 4](p, res, 0);
        p = self->screen->search(*(u64*)(e->pad2 + 0x20));
        (*(PaneSetFn**)p)[0x110 / 4](p, res, 0);
        p = self->screen->search(*(u64*)(e->pad2 + 0x28));
        (*(PaneSetFn**)p)[0x110 / 4](p, res, 0);
        ((u8*)self->screen->search(e->tag0))[0xb0] = 0;
        ((u8*)self->screen->search(e->tag1))[0xb0] = 0;
        i++;
        e++;
    } while (i < 4);
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
