#include "types.h"
#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

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

extern "C" void fn_80124B08(void* this_) {
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
    if (fn_80122834(this_) && *(s32*)((char*)this_ + 0x33c) < 10) {
        ((VObj*)this_)->v19(10);
    }
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

extern "C" void* fn_801F856C(void);
extern "C" void fn_801F3604(void*);
extern "C" void fn_8012202C(void*);
extern "C" void fn_80121FA8(void*);
extern "C" s32 fn_80230CFC(s32);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_80121F34(void*);
extern "C" void fn_801F6884(void*);
extern "C" void fn_80121764(void*);
extern "C" void fn_80121ABC(void*);
extern "C" void fn_80121D68(void*);
extern "C" void fn_801220C4(void*);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" s32 fn_80123E80(u8*, s32);
extern "C" void fn_80124CA8(u8* p, u32 param) {
    *(u8*)(p + 0x330) = 0;
    *(u8*)(p + 0x335) = 0;
    *(s32*)(p + 0x378) = 0;
    switch (param) {
    case 0:
        *(u8*)(p + 0x330) = 1;
        fn_801D22DC(p + 0x230, 7, 2, 0);
        break;
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        *(u8*)(p + 0x11E) = 1;
        fn_801F3604(p);
        break;
    case 5:
        fn_8012202C(p);
        break;
    case 6:
        fn_80121FA8(p);
        fn_801D22DC(p + 0x230, 2, 2, 0);
        break;
    case 7:
        fn_801D22DC(p + 0x230, fn_80230CFC(fn_8012285C(p)), 2, 0);
        *(u8*)(p + 0x333) = 0;
        *(s32*)(p + 0x354) = 0;
        break;
    case 8:
        fn_801D22DC(p + 0x230, fn_80230CFC(fn_8012285C(p)), 2, 0);
        break;
    case 9:
        fn_801D22DC(p + 0x230, *(s32*)(p + 0x98) + 0xA, 0, 0);
        *(u8*)(p + 0x333) = 1;
        fn_801F0E34(p, 0x40071, 0);
        *(s32*)(p + 0x3C8) = 0;
        fn_80121F34(p);
        break;
    case 10:
        fn_801D22DC(p + 0x230, 4, 0, 0);
        fn_801F0E34(p, 0x40072, 0);
        break;
    case 11:
        fn_801F6884(fn_801F856C());
        fn_80121764(p);
        break;
    case 12:
        fn_801D22DC(p + 0x230, 2, 2, 0);
        fn_80121764(p);
        fn_80121ABC(p);
        *(u8*)(p + 0x333) = 1;
        break;
    case 13:
        fn_80121D68(p);
        fn_801220C4(p);
        break;
    case 14:
        *(u8*)(p + 0x331) = 0;
        break;
    case 15:
        fn_802D8050(fn_802D6A9C(), *(s32*)(p + 0x3CC), 1, 0xFF);
        *(u8*)(p + 0x11C) = 0;
        break;
    case 16:
    case 17:
        break;
    }
    fn_80123E80(p, param);
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

extern "C" void* fn_8012FF9C(void);
extern "C" u8 fn_80130030(void*, s32);
extern "C" void* fn_8022EA0C(void);
extern "C" void fn_8022FE80(void*, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_8038AD24(s32, s32, s32, s32, Vec*, s32);
extern "C" int fn_80125668(void* this_, s32 param_2) {
    typedef u8 (*method_t)(void*);
    typedef void (*vmethod_t)(void*, s32);
    if (*(s32*)((char*)this_ + 0x33c) == 0x11) {
        return 3;
    }
    if (!((method_t)(*(void***)this_)[0x54 / sizeof(void*)])(this_)) {
        return 0;
    }
    if (fn_80130030(fn_8012FF9C(), param_2) == 0) {
        s32 state = *(s32*)((char*)this_ + 0x33c);
        if (state != 3 && state != 0) {
            fn_8012285C(this_);
            fn_8022FE80(fn_8022EA0C(), *(s32*)((char*)this_ + 0x4), *(s32*)((char*)this_ + 0x198), 0, 0);
            s32 r = fn_8022FD8C(*(s32*)((char*)this_ + 0x198));
            if (r >= 0) {
                Vec v = *(Vec*)((char*)this_ + 0xc);
                if (fn_8038AD24(r, 0x442, *(s32*)((char*)this_ + 0x198), *(s32*)((char*)this_ + 0x4), &v, 0x28)) {
                    *(s32*)((char*)this_ + 0x3d0) = *(s32*)((char*)this_ + 0x33c);
                    vmethod_t move = (vmethod_t)(*(void***)this_)[0x6c / sizeof(void*)];
                    move(this_, 3);
                }
            }
        }
        return 1;
    }
    if (((method_t)(*(void***)this_)[0x58 / sizeof(void*)])(this_)) {
        return 2;
    }
    return 1;
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

void __sinit_OPGL_80124AD8_cpp(void) {
}

