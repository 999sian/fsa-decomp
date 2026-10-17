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

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543D90;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern "C" void fn_80446D68(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543D90;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_80446DB0(void* self_) {
    typedef void* (*SearchFn)(void*, unsigned long long);
    typedef void (*SetFn)(void*, void*, int);
    u8* params = lbl_80490038;
    int i;
    u8* self = (u8*)self_;
    void* obj;
    void* tex;
    for (i = 0; i < 4; i++, params += 0xc0) {
        self[0x30] &= ~(1 << i);
        self[0x30] &= ~(1 << (i + 4));
        tex = fn_804030C4(0x54494D47, *(const char**)&lbl_804B1BC0);

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
    *(void**)self = (void*)lbl_804B1BE8;
    lbl_8053AF00 = (u32)self;

    void* screen = __nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv(screen);
    }
    *(void**)(self + 4) = screen;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 4), lbl_80490400, 0x1100000, *(void**)(lbl_80529DEC + 0x10));

    void** p = (void**)self;
    u8* params = lbl_80490038;
    for (int i = 0; i < 4; i++, params += 0xc0, p++) {
        void* obj = __nw__FUl(0x2c);
        if (obj != 0) {
            *(void**)obj = (void*)lbl_804AF86C;
        }
        p[2] = obj;
        unsigned long long tag = *(unsigned long long*)(params + 0x30);
        fn_80402F04(p[2], ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), tag));

        obj = __nw__FUl(0x2c);
        if (obj != 0) {
            *(void**)obj = (void*)lbl_804AF86C;
        }
        p[6] = obj;
        tag = *(unsigned long long*)(params + 0xb8);
        fn_80402F04(p[6], ((SearchFn)((*(void***)(*(void**)(self + 4)))[15]))(*(void**)(self + 4), tag));
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

