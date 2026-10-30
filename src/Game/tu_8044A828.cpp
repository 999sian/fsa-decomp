#include "types.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
struct J2DScreen;
struct J2DGrafContext;

struct VObj {
    virtual ~VObj();
};

extern "C" {
extern void* lbl_804B1D00[];
extern int lbl_8053AF28;
extern void __dl__FPv(void* obj);
extern void fn_8013B490(void*);
extern void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
}
struct J2DScreenVT {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual void m11() = 0;
    virtual void m12() = 0;
    virtual u32 m13(u32, u32, u32) = 0;
    virtual void m14() = 0;
    virtual u32 m15(u32, u32, u32) = 0;
};
extern u8* lbl_8053AB10;
extern f32 lbl_80543DB8;
extern u32 lbl_804B1CD8[];
extern u32 lbl_80490DB8[];
extern u32 lbl_80490E00[];
extern "C" void* fn_804030C4(u32 tag, u32 name);
typedef void (*VFn)(void*, u32, u32);
typedef u32 (*VFnRet)(void*, u32, u32, u32);
static void* Make(u8* self, u32* table, int i) {
    return (void*)(*(VFnRet**)*(void**)(self + 4))[15](*(void**)(self + 4), (u32)table, table[i], table[i + 1]);
}
static void Attach(void* o, void* handle) {
    (*(VFn**)o)[68](o, (u32)handle, 0);
}

extern "C" f32 fn_8043D514(void* a);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" void* lbl_8053AED0;
static inline void SetHudDigit(u8* self, u32* keys, int idx, int digit) {
    void* handle = fn_804030C4(0x54494d47, lbl_804B1CD8[digit]);
    ((J2DPicture*)((J2DPane*)*(void**)(self+4))->search(*(u64*)(keys+idx)))->changeTexture((const ResTIMG*)handle,0);
    ((J2DPicture*)((J2DPane*)*(void**)(self+4))->search(*(u64*)(keys+idx+2)))->changeTexture((const ResTIMG*)handle,0);
}
static inline void SetHudThree(u8* self, int v, int hundreds, int tens) {
SetHudDigit(self,lbl_80490DB8,4,hundreds);
SetHudDigit(self,lbl_80490DB8,8,tens);
SetHudDigit(self,lbl_80490DB8,12,v%10);
}
static inline void SetHudFour(u8* self, int b, int first, int rem, int tens) {
SetHudDigit(self,lbl_80490E00,8,first);
SetHudDigit(self,lbl_80490E00,12,rem);
SetHudDigit(self,lbl_80490E00,16,tens);
SetHudDigit(self,lbl_80490E00,20,b%10);
}
#pragma opt_propagation off
extern "C" void fn_8044A828(void* self_) {
    u16 v;
    int tens;
    int rem;
    int a;
    void* obj;
    u8* p;
    int i;
    void* handle;
    u8* self = (u8*)self_;
    p = self;

    for (i = 0; i < 2; i++) {
        fn_80402E08(*(void**)(p + 8), lbl_80543DB8, fn_8043D514(lbl_8053AED0));
        p += 4;
    }
    if (self[0x14] & 1) {
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 16));
        if (((u8*)obj)[0xb0] == 0) {
            obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 16));
            ((u8*)obj)[0xb0] = 1;
        }
    } else {
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 16));
        if (((u8*)obj)[0xb0] != 0) {
            obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 16));
            ((u8*)obj)[0xb0] = 0;
        }
    }

    obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 16));
    if (((u8*)obj)[0xb0] != 0) {

        if (*(u16*)(self + 0x10) >= 1000) {
            *(u16*)(self + 0x10) = 999;
        }
        v = *(u16*)(self + 0x10);
        tens = (v % 100) / 10;
        handle = fn_804030C4(0x54494D47, lbl_804B1CD8[v / 100]);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 4));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 6));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        handle = fn_804030C4(0x54494D47, lbl_804B1CD8[tens]);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 8));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 10));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        handle = fn_804030C4(0x54494D47, lbl_804B1CD8[v % 10]);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 12));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 14));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);

    }

    if (self[0x14] & 2) {
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 24));
        if (((u8*)obj)[0xb0] == 0) {
            obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 24));
            ((u8*)obj)[0xb0] = 1;
        }
    } else {
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 24));
        if (((u8*)obj)[0xb0] != 0) {
            obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 24));
            ((u8*)obj)[0xb0] = 0;
        }
    }

    obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 24));
    if (((u8*)obj)[0xb0] != 0) {

        if (self[0x12] >= 100) {
            self[0x12] = 99;
            self[0x13] = 99;
        }
        if (self[0x13] >= 100) {
            self[0x13] = 99;
        }
        a = self[0x12];
        v = self[0x13];
        rem=a%10;
        tens=v/10;
        handle = fn_804030C4(0x54494D47, lbl_804B1CD8[a / 10]);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 8));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 10));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        handle = fn_804030C4(0x54494D47, lbl_804B1CD8[rem]);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 12));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 14));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        handle = fn_804030C4(0x54494D47, lbl_804B1CD8[tens]);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 16));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 18));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        handle = fn_804030C4(0x54494D47, lbl_804B1CD8[v % 10]);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 20));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
        obj = ((J2DPane*)*(void**)(self + 4))->search(*(u64*)(lbl_80490E00 + 22));
        ((J2DPicture*)obj)->changeTexture((const ResTIMG*)handle, 0);
    }
    self[0x14] = 0;
}
#pragma opt_propagation reset
extern "C" void fn_8044AF90(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DB8;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_8044AFD8(void* self_) {
    u8* self = (u8*)self_;
    ResTIMG* handle;
    J2DPicture* obj;
    self[0x14] &= 0xfe;
    handle = (ResTIMG*)fn_804030C4(0x54494d47, lbl_804B1CD8[0]);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 4));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 6));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 8));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 10));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 12));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 14));
    obj->changeTexture(handle, (u8)0);
    self[0x14] &= ~2;
    handle = (ResTIMG*)fn_804030C4(0x54494d47, lbl_804B1CD8[0]);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490E00 + 8));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490E00 + 10));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490E00 + 12));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490E00 + 14));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490E00 + 16));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490E00 + 18));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490E00 + 20));
    obj->changeTexture(handle, (u8)0);
    obj = (J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490E00 + 22));
    obj->changeTexture(handle, (u8)0);
    (*(J2DPane**)(self + 4))->search(*(u64*)(lbl_80490DB8 + 16))->hide();
    u32 high = *(volatile u32*)(lbl_80490E00 + 24);
    J2DPane* screen = *(J2DPane* volatile*)(self + 4);
    u32 low = lbl_80490E00[25];
    screen->search(((u64)high << 32) | low)->hide();
}

extern "C" void* fn_8044B3FC(VObj** param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B1D00;
        delete param_1[1];
        param_1[1] = 0;
        for (int i = 0; i < 2; i++) {
            delete param_1[2 + i];
            param_1[2 + i] = 0;
        }
        lbl_8053AF28 = 0;
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" void __ct__9J2DScreenFv(J2DScreen* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(J2DScreen* self, const char* name, u32 flags, void* archive);
extern "C" void* __nw__FUl(u32 size);
extern "C" void fn_80402F04(void* self, u32 value);
extern "C" void* lbl_804AF86C[];
extern "C" char lbl_80490F30[];
extern "C" u8 lbl_80529DEC[];
extern "C" void* fn_8044B4B8(VObj** param_1) {
    *(void**)param_1 = lbl_804B1D00;
    lbl_8053AF28 = (int)param_1;
    J2DScreen* screen = (J2DScreen*)__nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv(screen);
    }
    param_1[1] = (VObj*)screen;
    setPriority__9J2DScreenFPCcUlP10JKRArchive((J2DScreen*)param_1[1], lbl_80490F30, 0x1100000, *(void**)(lbl_80529DEC + 0x10));
    VObj* a = (VObj*)__nw__FUl(0x2c);
    if (a != 0) {
        *(void**)a = lbl_804AF86C;
    }
    param_1[2] = a;
    fn_80402F04(param_1[2], (u32)((J2DPane*)param_1[1])->search(0x4e646174613030LL));
    VObj* b = (VObj*)__nw__FUl(0x2c);
    if (b != 0) {
        *(void**)b = lbl_804AF86C;
    }
    param_1[3] = b;
    fn_80402F04(param_1[3], (u32)((J2DPane*)param_1[1])->search(0x4e646174613031LL));
    *(u16*)(param_1 + 4) = 0;
    *(u8*)((u8*)param_1 + 0x12) = 0;
    *(u8*)((u8*)param_1 + 0x13) = 0;
    *(u8*)((u8*)param_1 + 0x14) = 0;
    return param_1;
}

extern "C" void fn_8044B5E8(void) {
}

