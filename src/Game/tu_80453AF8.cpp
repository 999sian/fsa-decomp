#include "types.h"
#include "JSystem/J2D/J2DScreen.h"


extern "C" void* lbl_8053AF48;
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AEC0;
extern "C" void fn_8013B490(void* a);
extern "C" void fn_804316EC(void* a);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* self, f32 x, f32 y, void* ctx);
extern "C" void* lbl_804B1DA8[];
extern "C" void* lbl_8053AF80;
extern "C" void fn_80459274(void* a);
extern "C" void __dl__FPv(void* p);

struct Slot0 {
    virtual void slot0(s32 arg);
};

struct T80454DEC {
    void* vtable;
    J2DScreen* screen;
    void* backdrop;
    void* panel;
    void* entries[3];
    s16 selected;
    s16 state;
    s16 field20;
    f32 left[3];
    f32 top[3];
    f32 right[3];
    f32 bottom[3];
    u8 field54;
    u8 field55;
};

struct T80454CD8 {
    u8 pad0[0x10];
    Slot0* a[3];
};
extern "C" s32 fn_80453AF8(void) {
    if (lbl_8053AF48 != 0) {
        return *(s32*)((u8*)lbl_8053AF48 + 0x58);
    }
    return 9;
}

extern "C" void fn_80454A00(u8* p) {
    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 4), 1.0f, 1.0f, *(void**)((u8*)lbl_8053AB10 + 0x10));
    if (*(s16*)(p + 0x1e) == 7 || *(s16*)(p + 0x1e) == 8 || *(s16*)(p + 0x1e) == 9) {
        fn_804316EC(lbl_8053AEC0);
    }
}

extern "C" void fn_804310CC(void* a);
extern "C" void fn_80402E08(void* a, f32 x, f32 y);
extern "C" u32 fn_80403084(u32 a, void* b);
extern "C" u8 lbl_80491488[];
extern "C" u32 lbl_80491470[];
extern "C" void fn_80402E08(void* p, f32 x, f32 y);
extern "C" void fn_80454A6C(void* this_) {
    typedef void (*VFn2)(void*, s32);
    typedef void* (*VFn4)(void*, u32, u32, u32);
    typedef void (*VFnPtr)(void*, void*);
    typedef void (*VFn3)(void*, u32, u32);

    fn_804310CC(lbl_8053AEC0);
    *(s16*)((u8*)this_ + 0x1c) = 0;
    *(s16*)((u8*)this_ + 0x1e) = 2;
    *(s16*)((u8*)this_ + 0x20) = 0;
    void* p8 = *(void**)((u8*)this_ + 0x8);
    void* p4 = *(void**)((u8*)p8 + 0x4);
    void** vt = *(void***)p4;
    ((VFn2)vt[9])(p4, 0);
    *(s16*)((u8*)*(void**)((u8*)this_ + 0x8) + 0x26) = 0;
    fn_80402E08(*(void**)((u8*)this_ + 0xc), 0.0f, -480.0f);
    *(s16*)((u8*)*(void**)((u8*)this_ + 0xc) + 0x22) = 0;
    u32 uVar1 = fn_80403084(0x54494d47, lbl_80491488);
    void* o = *(void**)((u8*)this_ + 0x4);
    o = ((VFn4)(*(void***)o)[15])(o, 0x73630000, 0x50, 0x73633031);
    ((VFn3)(*(void***)o)[68])(o, uVar1, 0);

    u32* p = lbl_80491470;
    for (s32 i = 0; i < 3; i++, p += 2) {
        if (i == *(s16*)((u8*)this_ + 0x1c)) {
            u32 c1;
            u8 col1[4];
            col1[0] = 0xff;
            col1[1] = 0xed;
            col1[2] = 0xa0;
            col1[3] = 0xff;
            c1 = *(u32*)col1;
            o = *(void**)((u8*)this_ + 0x4);
            o = ((VFn4)(*(void***)o)[15])(o, 0xff, p[0], p[1]);
            ((VFnPtr)(*(void***)o)[75])(o, &c1);
            u32 c2;
            u8 col2[4];
            col2[0] = 0x27;
            col2[1] = 0x10;
            col2[2] = 0;
            col2[3] = 0;
            c2 = *(u32*)col2;
            o = *(void**)((u8*)this_ + 0x4);
            o = ((VFn4)(*(void***)o)[15])(o, 0x27, p[0], p[1]);
            ((VFnPtr)(*(void***)o)[74])(o, &c2);
        } else {
            u32 c3;
            u8 col3[4];
            col3[0] = 0xa7;
            col3[1] = 0x4c;
            col3[2] = 0x2a;
            col3[3] = 0xff;
            c3 = *(u32*)col3;
            o = *(void**)((u8*)this_ + 0x4);
            o = ((VFn4)(*(void***)o)[15])(o, 0x4c, p[0], p[1]);
            ((VFnPtr)(*(void***)o)[74])(o, &c3);
            u32 z;
            u8 zero[4];
            zero[0] = 0;
            zero[1] = 0;
            zero[2] = 0;
            zero[3] = 0;
            z = *(u32*)zero;
            o = *(void**)((u8*)this_ + 0x4);
            o = ((VFn4)(*(void***)o)[15])(o, 0, p[0], p[1]);
            ((VFnPtr)(*(void***)o)[74])(o, &z);
        }
    }
    *(s32*)((u8*)this_ + 0x58) = 9;
}

extern "C" void* fn_80454CD8(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1DA8;
        fn_80459274(lbl_8053AF80);
        void* p1 = *(void**)((u8*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((u8*)this_ + 0x4) = 0;
        void* p2 = *(void**)((u8*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((u8*)this_ + 0x8) = 0;
        void* p3 = *(void**)((u8*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((u8*)this_ + 0xc) = 0;
        T80454CD8* o = (T80454CD8*)this_;
        for (int i = 0; i < 3; i++) {
            if (o->a[i] != 0) {
                o->a[i]->slot0(1);
            }
            o->a[i] = 0;
        }
        lbl_8053AF48 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8 lbl_80529DEC[];
extern "C" void* lbl_804AF86C[];
extern "C" void fn_80402F04(void* a, void* b);
extern "C" void* __nw__FUl(u32 size);
extern "C" void* getBounds__7J2DPaneFv(void* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* self, const char* name, u32 pri, void* archive);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" char lbl_8049149C[];
extern "C" const f32 lbl_80543E44;
extern "C" const f32 lbl_80543E40;
extern "C" u8* fn_80454DEC(u8* p) {
    typedef void* (*Search)(void*, u64);
    typedef void (*SetColor)(void*, void*);
    typedef void (*SetAlpha)(void*, u8);
    void* s;
    *(void**)p = lbl_804B1DA8;
    lbl_8053AF48 = p;
    s = __nw__FUl(0x118);
    if (s) __ct__9J2DScreenFv(s);
    *(void**)(p + 4) = s;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(p+4), lbl_8049149C, 0x1100000, *(void**)(lbl_80529DEC+0x4c));
    *(f32*)(p+0x24) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x506b656e633031ULL)) + 0);
    *(f32*)(p+0x30) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x506b656e633031ULL)) + 4);
    *(f32*)(p+0x3c) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x506b656e633032ULL)) + 0);
    *(f32*)(p+0x48) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x506b656e633032ULL)) + 4);
    f32 left = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(*(u64*)lbl_80491470)) + 0) - *(f32*)(p+0x24);
    f32 right = *(f32*)(p+0x3c) - *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(*(u64*)lbl_80491470)) + 8);
    *(f32*)(p+40) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[1])) + 0) - left;
    *(f32*)(p+52) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[1])) + 4);
    *(f32*)(p+64) = right + *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[1])) + 8);
    *(f32*)(p+76) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[1])) + 4);
    *(f32*)(p+44) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[2])) + 0) - left;
    *(f32*)(p+56) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[2])) + 4);
    *(f32*)(p+68) = right + *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[2])) + 8);
    *(f32*)(p+80) = *(f32*)((u8*)getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[2])) + 4);
    s = __nw__FUl(0x2c);
    if (s) *(void**)s = lbl_804AF86C;
    *(void**)(p+8) = s;
    fn_80402F04(*(void**)(p+8), (*(J2DScreen**)(p+4))->search(0x50626c61636bULL));
    s = __nw__FUl(0x2c);
    if (s) *(void**)s = lbl_804AF86C;
    *(void**)(p+12) = s;
    fn_80402F04(*(void**)(p+12), (*(J2DScreen**)(p+4))->search(0x4e646174613031ULL));
    for (int i=0; i<3; i++) {
        s = __nw__FUl(0x2c);
        if (s) *(void**)s = lbl_804AF86C;
        ((void**)(p+0x10))[i] = s;
        fn_80402F04(((void**)(p+0x10))[i], (*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[i]));
    }
    *(s16*)(p+0x1c) = 0;
    *(s16*)(p+0x1e) = 2;
    *(s16*)(p+0x20) = 0;
    void* pane = *(void**)((u8*)*(void**)(p+8)+4);
    ((SetAlpha)(*(void***)pane)[9])(pane,0);
    *(s16*)((u8*)*(void**)(p+8)+0x26) = 0;
    fn_80402E08(*(void**)(p+0xc), lbl_80543E44, lbl_80543E40);
    *(s16*)((u8*)*(void**)(p+0xc)+0x22) = 0;
    for (int i=0; i<3; i++) {
        if (i == *(s16*)(p+0x1c)) {
            u32 c1; u8 c1bytes[4];
            c1bytes[0] = 255;
            c1bytes[1] = 237;
            c1bytes[2] = 160;
            c1bytes[3] = 255;
            c1 = *(u32*)c1bytes;
            pane = (*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[i]);
            ((SetColor)(*(void***)pane)[75])(pane,&c1);
            u32 c2; u8 c2bytes[4];
            c2bytes[0] = 39;
            c2bytes[1] = 16;
            c2bytes[2] = 0;
            c2bytes[3] = 0;
            c2 = *(u32*)c2bytes;
            pane = (*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[i]);
            ((SetColor)(*(void***)pane)[74])(pane,&c2);
        } else {
            u32 c3; u8 c3bytes[4];
            c3bytes[0] = 167;
            c3bytes[1] = 76;
            c3bytes[2] = 42;
            c3bytes[3] = 255;
            c3 = *(u32*)c3bytes;
            pane = (*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[i]);
            ((SetColor)(*(void***)pane)[75])(pane,&c3);
            u32 c4; u8 c4bytes[4];
            c4bytes[0] = 0;
            c4bytes[1] = 0;
            c4bytes[2] = 0;
            c4bytes[3] = 0;
            c4 = *(u32*)c4bytes;
            pane = (*(J2DScreen**)(p+4))->search(((u64*)lbl_80491470)[i]);
            ((SetColor)(*(void***)pane)[74])(pane,&c4);
        }
    }
    p[0x55] = 0;
    p[0x54] = 1;
    return p;
}

