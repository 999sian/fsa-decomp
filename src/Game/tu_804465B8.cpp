#include "types.h"
struct J2DScreen {
    u8 pad[0x100];
    u8 b100;
};


extern "C" void __dl__FPv(void*);
extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" const char* lbl_804B1BC0[];
extern "C" u8 lbl_80490038[];
extern "C" u8 lbl_804B1BE8[];
extern "C" u32 lbl_8053AF00;

struct fn_80447190_Obj {
    virtual void Release(int);
};

struct FsaVObj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void* search(unsigned long long key);
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void set(void* tex, int flag);
};

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543D90;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern "C" f32 fn_8043D514(void*);
extern "C" f32 fn_8043D57C(void*);
extern "C" void fn_80402E08(void*, f32, f32);
extern "C" u8* lbl_8053AED0;
extern "C" void fn_804465B8(void* self_) {
    typedef void* (*SearchFn)(void*, unsigned long long);
    typedef void (*SetFn)(void*, void*, int);
    u8* self = (u8*)self_;
    void** slot = (void**)self_;
    u8* params;
    int i;
    s32 secs;
    s32 cs;
    s32 secsTens;
    s32 csTens;
    void* tex;
    void* obj;

    for (i = 0, params = lbl_80490038; i < 4; i++, params += 0xc0) {
        if (i < 2) {
            fn_80402E08(slot[2], lbl_80543D90, fn_8043D514(lbl_8053AED0));
            fn_80402E08(slot[6], lbl_80543D90, fn_8043D514(lbl_8053AED0));
        } else {
            fn_80402E08(slot[2], lbl_80543D90, fn_8043D57C(lbl_8053AED0));
            fn_80402E08(slot[6], lbl_80543D90, fn_8043D57C(lbl_8053AED0));
        }
        if (self[0x30] & (u8)(1 << i)) {
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x30));
            if (((u8*)obj)[0xb0] == 0) {
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x30));
                ((u8*)obj)[0xb0] = 1;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x50));
                ((u8*)obj)[0xb0] = 1;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x60));
                ((u8*)obj)[0xb0] = 1;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x70));
                ((u8*)obj)[0xb0] = 1;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x80));
                ((u8*)obj)[0xb0] = 1;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x90));
                ((u8*)obj)[0xb0] = 1;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xa0));
                ((u8*)obj)[0xb0] = 1;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xb0));
                ((u8*)obj)[0xb0] = 1;
            }
        } else {
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x30));
            if (((u8*)obj)[0xb0] != 0) {
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x30));
                ((u8*)obj)[0xb0] = 0;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x50));
                ((u8*)obj)[0xb0] = 0;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x60));
                ((u8*)obj)[0xb0] = 0;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x70));
                ((u8*)obj)[0xb0] = 0;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x80));
                ((u8*)obj)[0xb0] = 0;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x90));
                ((u8*)obj)[0xb0] = 0;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xa0));
                ((u8*)obj)[0xb0] = 0;
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xb0));
                ((u8*)obj)[0xb0] = 0;
            }
        }
        if (self[0x30] & (u8)(1 << (i + 4))) {
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x40));
            if (((u8*)obj)[0xb0] == 0) {
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x40));
                ((u8*)obj)[0xb0] = 1;
            }
        } else {
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x40));
            if (((u8*)obj)[0xb0] != 0) {
                obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x40));
                ((u8*)obj)[0xb0] = 0;
            }
        }
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x30));
        if (((u8*)obj)[0xb0] != 0) {
            u8* p = self + i;
            s32 frames;
            s32 mins;
            if (p[0x28] >= 100) {
                p[0x28] = 99;
            }
            frames = p[0x2c];
            mins = frames / 60;
            secs = frames % 60;
            cs = p[0x28];
            secsTens = secs / 10;
            csTens = cs / 10;
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[mins]);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x68));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x70));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[secsTens]);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x78));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x80));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[secs - secsTens * 10]);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x88));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x90));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[csTens]);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x98));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xa0));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[cs - csTens * 10]);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xa8));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
            obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xb0));
            ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        }
        slot++;
    }
    self[0x30] = 0;
}

extern "C" void fn_80446D68(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543D90;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_80446DB0(void* self_) {
    typedef void* (*SearchFn)(void*, unsigned long long);
    typedef void (*SetFn)(void*, void*, int);
    u8* self;
    u8* params;
    int i;
    void* tex;
    void* obj;
    self = (u8*)self_;
    for (i = 0, params = lbl_80490038; i < 4; i++, params += 0xc0) {
        self[0x30] &= ~(u8)(1 << i);
        self[0x30] &= ~(u8)(1 << (i + 4));
        tex = fn_804030C4(0x54494D47, lbl_804B1BC0[0]);

        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x68));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x70));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x78));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x80));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x88));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x90));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x98));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xa0));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xa8));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xb0));
        ((SetFn)((*(void***)obj)[68]))(obj, tex, 0);

        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x30));
        ((u8*)obj)[0xb0] = 0;
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x50));
        ((u8*)obj)[0xb0] = 0;
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x60));
        ((u8*)obj)[0xb0] = 0;
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x70));
        ((u8*)obj)[0xb0] = 0;
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x80));
        ((u8*)obj)[0xb0] = 0;
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x90));
        ((u8*)obj)[0xb0] = 0;
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xa0));
        ((u8*)obj)[0xb0] = 0;
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xb0));
        ((u8*)obj)[0xb0] = 0;
        obj = ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x40));
        ((u8*)obj)[0xb0] = 0;
    }
}

extern "C" void* fn_80447190(void* param_1, short param_2)
{
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B1BE8;

        if (((fn_80447190_Obj**)result)[1] != 0) {
            ((fn_80447190_Obj**)result)[1]->Release(1);
        }
        ((fn_80447190_Obj**)result)[1] = 0;

        fn_80447190_Obj** ptr = (fn_80447190_Obj**)result;
        int i = 0;
        do {
            if (ptr[2] != 0) {
                ptr[2]->Release(1);
            }
            ptr[2] = 0;
            if (ptr[6] != 0) {
                ptr[6]->Release(1);
            }
            i++;
            ptr[6] = 0;
            ptr++;
        } while (i < 4);

        lbl_8053AF00 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}

extern "C" void* __nw__FUl(unsigned long size);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* pane, const char* name, unsigned long id, void* archive);
extern "C" void fn_80402F04(void* a, void* b);
extern "C" u8 lbl_804AF86C[];
extern "C" u8 lbl_80490038[];
extern "C" char lbl_80490400[];
extern "C" u8 lbl_80529DEC[];
extern "C" void* fn_8044728C(void* param_1) {
    typedef void* (*SearchFn)(void*, unsigned long long);
    u8* self = (u8*)param_1;
    void* screen;
    void** p;
    u8* params;
    int i;
    *(void**)self = (void*)lbl_804B1BE8;
    lbl_8053AF00 = (u32)self;

    screen = __nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv(screen);
    }
    *(void**)(self + 4) = screen;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 4), lbl_80490400, 0x1100000, *(void**)(lbl_80529DEC + 0x10));

    p = (void**)self;
    params = lbl_80490038;
    for (i = 0; i < 4; i++, params += 0xc0, p++) {
        void* obj = __nw__FUl(0x2c);
        if (obj != 0) {
            *(void**)obj = (void*)lbl_804AF86C;
        }
        p[2] = obj;
        fn_80402F04(p[2], ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0x30)));

        obj = __nw__FUl(0x2c);
        if (obj != 0) {
            *(void**)obj = (void*)lbl_804AF86C;
        }
        p[6] = obj;
        fn_80402F04(p[6], ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), *(unsigned long long*)(params + 0xb8)));
    }

    self[0x28] = 0;
    self[0x2c] = 0;
    self[0x29] = 0;
    self[0x2d] = 0;
    self[0x2a] = 0;
    self[0x2e] = 0;
    self[0x2b] = 0;
    self[0x2f] = 0;
    self[0x30] = 0;
    return param_1;
}

