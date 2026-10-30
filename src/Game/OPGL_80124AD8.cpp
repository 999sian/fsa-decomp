#include "types.h"
#include "Game/Actor.h"

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

extern "C" void fn_80124B90(void* this_) {
    register void** vtable = (void**)*(void**)this_;
    typedef void (*method_t)(void*, int);
    register method_t method = (method_t)vtable[0x6c / sizeof(void*)];
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
    {
      int r = fn_8012285C(param_1);
      float f = fn_80121DC8(param_1, r);
      return f <= lbl_8053CA6C;
    }
  case 0x11:
  default:
    return false;
  }
}

extern "C" void fn_80124448(void*);
extern "C" int fn_8012285C(void*);
extern "C" float fn_80121DC8(void*, int);
extern float lbl_8053CA6C;
extern "C" void fn_80125858(void* s)
{
  fn_80124448(s);
}

