#include "Game/Actor.h"


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

