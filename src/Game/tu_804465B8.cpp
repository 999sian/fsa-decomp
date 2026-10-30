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
    bool isVisible() const { return mVisible; }
    void show() { mVisible = true; }
    void hide() { mVisible = false; }
    u8 pad[0xac];
    bool mVisible;
};
struct J2DScreen {
    J2DScreen();
    void setPriority(const char*, unsigned long, JKRArchive*);
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30();
    virtual J2DPane* search(u64);
    u8 pad[0xfc];
    u8 b100;
    u8 tail[0x17];
};


extern "C" void __dl__FPv(void*);
extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" const char* lbl_804B1BC0[];
struct Obj804465B8 {
    void* vt;
    J2DScreen* screen;
    void* a[4];
    void* b[4];
    u8 flags[9];
};
struct ScreenTagEntry {
    u8 pad[0x30];
    u64 tag0;
    u8 pad38[0x80];
    u64 tag1;
};
extern "C" const ScreenTagEntry lbl_80490038[];
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
#pragma opt_propagation off
extern "C" void fn_804465B8(void* self_) {
    void** slot;
    u8* params;
    s32 secs;
    s32 cs;
    s32 secsTens;
    s32 csTens;
    int i;
    u8* self;
    void* tex;
    void* obj;

    self = (u8*)self_;
    slot = (void**)self;
    params = (u8*)lbl_80490038;
    for (i = 0; i < 4; i++, params += 0xc0) {
        if (i < 2) {
            fn_80402E08(slot[2], lbl_80543D90, fn_8043D514(lbl_8053AED0));
            fn_80402E08(slot[6], lbl_80543D90, fn_8043D514(lbl_8053AED0));
        } else {
            fn_80402E08(slot[2], lbl_80543D90, fn_8043D57C(lbl_8053AED0));
            fn_80402E08(slot[6], lbl_80543D90, fn_8043D57C(lbl_8053AED0));
        }
        if (self[0x30] & (u8)(1 << i)) {
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x30));
            if (((u8*)obj)[0xb0] == 0) {
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x30));
                ((u8*)obj)[0xb0] = 1;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x50));
                ((u8*)obj)[0xb0] = 1;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x60));
                ((u8*)obj)[0xb0] = 1;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x70));
                ((u8*)obj)[0xb0] = 1;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x80));
                ((u8*)obj)[0xb0] = 1;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x90));
                ((u8*)obj)[0xb0] = 1;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0xa0));
                ((u8*)obj)[0xb0] = 1;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0xb0));
                ((u8*)obj)[0xb0] = 1;
            }
        } else {
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x30));
            if (((u8*)obj)[0xb0] != 0) {
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x30));
                ((u8*)obj)[0xb0] = 0;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x50));
                ((u8*)obj)[0xb0] = 0;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x60));
                ((u8*)obj)[0xb0] = 0;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x70));
                ((u8*)obj)[0xb0] = 0;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x80));
                ((u8*)obj)[0xb0] = 0;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x90));
                ((u8*)obj)[0xb0] = 0;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0xa0));
                ((u8*)obj)[0xb0] = 0;
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0xb0));
                ((u8*)obj)[0xb0] = 0;
            }
        }
        if (self[0x30] & (u8)(1 << (i + 4))) {
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x40));
            if (((u8*)obj)[0xb0] == 0) {
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x40));
                ((u8*)obj)[0xb0] = 1;
            }
        } else {
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x40));
            if (((u8*)obj)[0xb0] != 0) {
                obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x40));
                ((u8*)obj)[0xb0] = 0;
            }
        }
        obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x30));
        if (((u8*)obj)[0xb0] != 0) {
            u8* p = self + i;
            s32 frames;
            if (p[0x28] >= 100) {
                p[0x28] = 99;
            }
            frames = p[0x2c];
            secs = frames % 60;
            cs = p[0x28];
            secsTens = secs / 10;
            csTens = cs / 10;
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[frames / 60]);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x68));
            ((FsaVObj*)obj)->set(tex, 0);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x70));
            ((FsaVObj*)obj)->set(tex, 0);
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[secsTens]);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x78));
            ((FsaVObj*)obj)->set(tex, 0);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x80));
            ((FsaVObj*)obj)->set(tex, 0);
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[secs % 10]);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x88));
            ((FsaVObj*)obj)->set(tex, 0);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x90));
            ((FsaVObj*)obj)->set(tex, 0);
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[csTens]);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0x98));
            ((FsaVObj*)obj)->set(tex, 0);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0xa0));
            ((FsaVObj*)obj)->set(tex, 0);
            tex = fn_804030C4(0x54494D47, lbl_804B1BC0[cs % 10]);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0xa8));
            ((FsaVObj*)obj)->set(tex, 0);
            obj = ((FsaVObj*)*(void**)(self + 4))->search(*(unsigned long long*)(params + 0xb0));
            ((FsaVObj*)obj)->set(tex, 0);
        }
        slot++;
    }
    self[0x30] = 0;
}
#pragma opt_propagation reset
extern "C" void fn_80446D68(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543D90;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_80446DB0(Obj804465B8* self)
{
    void* res;
    for (int i = 0; i < 4; i++) {
        self->flags[8] &= ~(u8)(1 << i);
        self->flags[8] &= ~(u8)(1 << (i + 4));
        res = fn_804030C4('TIMG', lbl_804B1BC0[0]);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x30))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x38))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x40))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x48))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x50))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x58))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x60))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x68))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x70))->changeTexture(res, 0);
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x78))->changeTexture(res, 0);
        self->screen->search(lbl_80490038[i].tag0)->hide();
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x18))->hide();
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x28))->hide();
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x38))->hide();
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x48))->hide();
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x58))->hide();
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x68))->hide();
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x78))->hide();
        self->screen->search(*(u64*)(lbl_80490038[i].pad38 + 0x08))->hide();
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
extern "C" char lbl_80490400[];
extern "C" u8 lbl_80529DEC[];
#pragma opt_propagation on
extern "C" Obj804465B8* fn_8044728C(Obj804465B8* param_1) {
    typedef void* (*SearchFn)(void*, unsigned long long);
    u8* self = (u8*)param_1;
    Obj804465B8* object = (Obj804465B8*)param_1;
    void** p;
    const ScreenTagEntry* params;
    int i;
    *(void**)self = (void*)lbl_804B1BE8;
    lbl_8053AF00 = (u32)self;

    object->screen = new J2DScreen();
    object->screen->setPriority(lbl_80490400, 0x1100000, *(JKRArchive**)(lbl_80529DEC + 0x10));

    for (i = 0; i < 4; i++) {
        void* obj = __nw__FUl(0x2c);
        if (obj != 0) {
            *(void**)obj = (void*)lbl_804AF86C;
        }
        object->a[i] = obj;
        u64 tag0 = ((const ScreenTagEntry*)lbl_80490038)[i].tag0;
        fn_80402F04(object->a[i], object->screen->search(tag0));

        obj = __nw__FUl(0x2c);
        if (obj != 0) {
            *(void**)obj = (void*)lbl_804AF86C;
        }
        object->b[i] = obj;
        u64 tag1 = ((const ScreenTagEntry*)lbl_80490038)[i].tag1;
        fn_80402F04(object->b[i], object->screen->search(tag1));
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
#pragma opt_propagation reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
