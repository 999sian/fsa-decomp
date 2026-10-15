#include "types.h"


extern "C" void fn_802AC8AC(u8* this_, u32 val) { *(u32*)(this_ + 0x18) = val; }

extern "C" void fn_802AC980(u8* this_) { *(u32*)(this_ + 0x10) = 2; }

extern "C" void fn_802ACB58(u8* this_) {
  *(u32*)(this_ + 0xc) = 0;
  *(u32*)(this_ + 0x18) = 0;
}

extern void __dl__FPv(void*);
extern char lbl_804A8390[];
extern "C" void __dl__FPv(void*);
extern void* lbl_8053ACA0;
extern char lbl_8046C8A0[];
extern void* fn_804030C4(u32, void*);
extern void* __nw__FUl(u32);
extern void __ct__10J2DPictureFPC7ResTIMG(void*, void*);
extern "C" void* fn_802ACB68(void* this_, short param_2) {
  if (this_ != (void*)0) {
    *(void**)this_ = (void*)lbl_804A8390;
    void** ptr = (void**)*(u32*)((u8*)this_ + 4);
    if (ptr != NULL) {
      void** vtable = (void**)*(u32*)ptr;
      typedef void (*Func)(void*, int);
      Func func = (Func)*(u32*)((u8*)vtable + 8);
      func(ptr, 1);
    }
    *(u32*)((u8*)this_ + 4) = 0;
    if (param_2 > 0) {
      __dl__FPv(this_);
    }
  }
  return this_;
}

