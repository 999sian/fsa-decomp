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
    void** ptr_field = (void**)((u8*)this_ + 4);
    if (*ptr_field != (void*)0) {
      void** obj = (void**)*ptr_field;
      void** vtable = (void**)obj[0];
      typedef void (*Func)(void*, int);
      Func func = (Func)vtable[2];
      func((void*)obj, 1);
    }
    *(u32*)((u8*)this_ + 4) = 0;
    if (param_2 > 0) {
      __dl__FPv(this_);
    }
  }
  return this_;
}

extern "C" void* fn_802ACBE8(void* param_1) {
    void* uVar1;
    void* iVar2;
    
    *(void**)param_1 = (void*)lbl_804A8390;
    lbl_8053ACA0 = param_1;
    
    uVar1 = fn_804030C4(0x54494d47, (void*)lbl_8046C8A0);
    iVar2 = __nw__FUl(0x168);
    
    if (iVar2 != 0) {
        __ct__10J2DPictureFPC7ResTIMG(iVar2, uVar1);
        *(void**)((char*)param_1 + 4) = iVar2;
    }
    
    *(u32*)((char*)param_1 + 0xc) = 0;
    *(u32*)((char*)param_1 + 0x10) = 0;
    *(u32*)((char*)param_1 + 0x14) = 0;
    *(u32*)((char*)param_1 + 0x18) = 0;
    
    return param_1;
}

