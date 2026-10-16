#include "types.h"
#include "JSystem/J2D/J2DPane.h"
struct Slot0 {
    virtual void slot0(s32 arg);
};


extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B19F0[];
extern "C" u32 lbl_8053AEE0;

struct fn_80442368_Obj {
    virtual void Release(int);
};

extern "C" void fn_8013B490(void* p);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* screen, f32 x, f32 y, void* ctx);
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80543D40;
extern "C" f32 lbl_80543D44;
extern "C" u8 lbl_804AF86C[];
extern "C" u8 lbl_8048FAF0[];
extern "C" u8 lbl_80529DEC[];
extern "C" void* lbl_8053AD78;
extern "C" void* __nw__FUl(unsigned long size);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* pane, const char* name, unsigned long id, void* archive);
extern "C" void fn_80402F04(void* a, void* b);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
struct J2DScreenVt {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void* m13(s32, s32, u32);
};
struct J2DScreenObjVt {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37(void*);
};
struct Unk80442254Vt {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7(s32) = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual void m11() = 0;
    virtual void m12() = 0;
    virtual void* m13(s32, s32, u32, s32) = 0;
};

extern "C" void fn_80442200(void* this_) {
    fn_8013B490(lbl_8053AB10);
    if (*(int*)((char*)this_ + 0x18) != 0) {
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)((char*)this_ + 0x4), lbl_80543D40, lbl_80543D40, ((void**)lbl_8053AB10)[4]);
    }
}

extern "C" void fn_80402E08(void*, f32, f32);
extern "C" void fn_803832BC(const char*, u32, u32, u32, u32);
extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_80543D44;
extern "C" void fn_80442254(char* this_, s32 param_2, s32 param_3) {
    Unk80442254Vt* obj = *(Unk80442254Vt**)(*(char**)(this_ + 0x8) + 0x4);
    obj->m7(0);
    f32 a = lbl_80543D40;
    *(u16*)(*(char**)(this_ + 0x8) + 0x26) = 0;
    f32 b = lbl_80543D44;
    fn_80402E08(*(void**)(this_ + 0xc), a, b);
    *(u16*)(*(char**)(this_ + 0xc) + 0x22) = 0;
    *(s32*)(this_ + 0x10) = param_2;
    *(s32*)(this_ + 0x14) = param_3 - 1;
    *(s32*)(this_ + 0x18) = 1;
    *(s32*)(this_ + 0x1c) = 0;
    Unk80442254Vt* tb = *(Unk80442254Vt**)(this_ + 0x4);
    char* str = (char*)tb->m13(param_3 - 1, 0x54, 0x77743031, 0);
    const char* text = ((J2DTextBox*)str)->getStringPtr();
    s32 idx = *(s32*)(this_ + 0x14);
    u32 f = ((s32)((u8*)lbl_8053AAF8)[0x83] >> (idx << 1)) & 3;
    if (f == 1) {
        fn_803832BC(text, 0x3b, idx + 1, 0, 0);
    } else if (f == 2) {
        fn_803832BC(text, 0x3a, idx + 1, 0, 0);
    }
}

extern "C" void* fn_80442368(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B19F0;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* p3 = *(void**)((char*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((char*)this_ + 0xc) = 0;
        lbl_8053AEE0 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
