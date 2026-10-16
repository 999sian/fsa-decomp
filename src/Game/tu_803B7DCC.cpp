#include "types.h"

struct FsaObjVtbl {
    char pad_00[0x24];
    void (*fn24)(void* self, u8 b);
    char pad_28[0xec - 0x28];
    void (*fnEC)(void* self, s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g);
};

struct FsaObj {
    FsaObjVtbl* vtbl;
};


extern "C" void fn_8013B490(void* this_);
extern u8 lbl_80529DEC[];
extern void* lbl_8053AB10;
extern "C" void fn_803B7DCC(u8* this_) {
    if (*(s32*)(lbl_80529DEC + 0x118) != 8 || *(s32*)(lbl_80529DEC + 0x11c) != 3) {
        fn_8013B490(lbl_8053AB10);
        FsaObj* obj = *(FsaObj**)(this_ + 4);
        obj->vtbl->fn24(obj, this_[0x296]);
        obj = *(FsaObj**)(this_ + 4);
        obj->vtbl->fnEC(obj, 0, 0, 0, 0.0f, 0.0f, 800.0f, 640.0f);
    }
}

extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053ADC8;
extern "C" void* sManager__8JUTVideo;
extern "C" void fn_8013B414(void* this_, f32* rect, s32 n);
extern "C" void fn_803B7E64(u8* this_) {
    f32 rect[4];
    void* obj;
    u8* video;
    u16 w;
    u16 h;

    fn_8013B490(lbl_8053AB10);
    if (this_[0x294] == 3 || this_[0x294] == 4) {
        ((u8*)lbl_8053ADC8)[0x20] = 1;
        ((u8*)lbl_8053ADC8)[0x21] = 2;
    }
    obj = *(void**)(this_ + 4);
    (*(void (***)(void*, u8))obj)[9](obj, this_[0x296]);
    obj = *(void**)(this_ + 4);
    (*(void (***)(void*, s32, s32, s32, f32, f32, f32, f32))obj)[59](obj, 0, 0, 0, 0.0f, 0.0f, 800.0f, 640.0f);
    video = *(u8**)((u8*)sManager__8JUTVideo + 4);
    h = *(u16*)(video + 6);
    w = *(u16*)(video + 4);
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)(s32)w;
    rect[3] = (f32)(s32)h;
    fn_8013B414(lbl_8053AB10, rect, 1);
}

extern "C" void __dl__FPv(void* this_);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* p);
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" char lbl_804AFAB0[];
extern "C" s32 lbl_8053ADA8;
extern "C" void* fn_803B82FC(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AFAB0;
        s32 i = 0;
        void** p = (void**)this_;
        for (; i < 50; i++) {
            if (p[9] != 0) {
                void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, p[9]);
                p[9] = 0;
            }
            p++;
        }
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        void* p1 = ((void**)this_)[1];
        if (p1 != 0) {
            ((void (*)(void*, s32))(*(void**)((char*)*(void**)p1 + 0x8)))(p1, 1);
        }
        ((void**)this_)[1] = 0;
        void* p7 = ((void**)this_)[7];
        if (p7 != 0) {
            ((void (*)(void*, s32))(*(void**)((char*)*(void**)((char*)p7 + 0x8) + 0x30)))(p7, 1);
        }
        ((void**)this_)[7] = 0;
        void* p8 = ((void**)this_)[8];
        if (p8 != 0) {
            ((void (*)(void*, s32))(*(void**)((char*)*(void**)((char*)p8 + 0x8) + 0x30)))(p8, 1);
        }
        ((void**)this_)[8] = 0;
        lbl_8053ADA8 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
struct SlotVt {
    virtual void m0(void);
    virtual void m1(void);
    virtual void m2(int);
    virtual void m3(void);
    virtual void m4(void);
    virtual void m5(void);
    virtual void m6(void);
    virtual void m7(void);
    virtual void m8(void);
    virtual void m9(void);
    virtual void m10(void);
    virtual void m11(void);
    virtual void m12(int);
};
