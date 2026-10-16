#include "types.h"
#include "Game/Actor.h"

extern "C" u8 fn_80122834(void*);

class OPGL : public Actor {
public:
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(s32);
};

extern "C" void fn_80124AD8(void* p) {
    ((OPGL*)p)->v25(9);
}

extern "C" u8 fn_80122834(void*);
extern "C" void fn_80124B60(void* this_) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
        virtual void v0a();
        virtual void v0b();
        virtual void v0c();
        virtual void v0d();
        virtual void v0e();
        virtual void v0f();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual void v18();
        virtual void v19(int);
    };
    ((VObj*)this_)->v19(8);
}

extern "C" void fn_80124B90(void* this_) {
    typedef void (*method_t)(void*, int);
    method_t method = (method_t)(*(void***)this_)[27];
    method(this_, 0x5);
}

extern "C" void fn_80124BC0(void* this_) {
    register void** vtable = (void**)*(void**)this_;
    typedef void (*method_t)(void*, int);
    method_t method = (method_t)vtable[0x6c / sizeof(void*)];
    method(this_, 0x7);
}

extern "C" void fn_80121DB0(void);
extern "C" void fn_80124448(void*);
extern "C" int fn_8012285C(void*);
extern "C" float fn_80121DC8(void*, int);
extern float lbl_8053CA6C;
extern "C" void fn_80124C2C(void) {
    fn_80121DB0();
}

extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern u8 lbl_8049E198[];
extern f32 lbl_8053CA40;
extern "C" void fn_80124C4C(u8* p) {
    fn_801D2608(p + 0x230, lbl_8049E198, 14);
    fn_801D22DC(p + 0x230, 7, 2, 0);
    fn_801D1F14(p + 0x230, lbl_8053CA40);
}

extern "C" void fn_8012562C(void* this_) {
    char* p = (char*)this_;
    *(unsigned int*)(p + 0x35c) = *(unsigned int*)(p + 0x90) & 0xFF;
    *(unsigned int*)(p + 0x3cc) = (*(unsigned int*)(p + 0x90) >> 22) & 0x1F;
}

extern "C" int fn_80125648(void* this_) {
    switch (*(int*)((char*)this_ + 0x33c)) {
    case 0xb:
        return 1;
    default:
        return 0;
    }
}

extern "C" bool fn_801257A8(void* param_1)
{
  int v = *(int*)((char*)param_1 + 0x33c);
  switch (v) {
  case 4:
  case 7:
  case 8:
    return fn_80121DC8(param_1, fn_8012285C(param_1)) <= lbl_8053CA6C;
  case 0x11:
  default:
    return false;
  }
}

extern "C" s32 fn_80125830(void* self) {
    s32 v = *(s32*)((char*)self + 0x33c);
    if (v < 9 && v >= 4) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80124448(void*);
extern "C" int fn_8012285C(void*);
extern "C" float fn_80121DC8(void*, int);
extern float lbl_8053CA6C;
extern "C" void fn_80125858(void* s)
{
  fn_80124448(s);
}

extern void* lbl_8049E1D0[];
extern "C" void fn_80124740(void*, short);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_80125878(void* self, short flag) {
    if (self) {
        *(void***)self = lbl_8049E1D0;
        fn_80124740(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_801247C8(void*, char*, s32, s32);
extern char lbl_80464E8C[];
extern "C" void* fn_801258D8(void* self) {
    fn_801247C8(self, lbl_80464E8C, 0x2e6, 1);
    *(void***)self = lbl_8049E1D0;
    *(s32*)((char*)self + 0x3c4) = 0;
    *(s32*)((char*)self + 0x3c8) = 0;
    *(s32*)((char*)self + 0x3cc) = 0;
    return self;
}

