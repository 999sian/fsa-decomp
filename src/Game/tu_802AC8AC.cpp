#include "types.h"


extern "C" void fn_802AC8AC(u8* this_, u32 val) { *(u32*)(this_ + 0x18) = val; }

extern void* lbl_8053AAF8;
extern "C" s32 fn_802AC8B4(u8* this_) {
    s32 state = *(s32*)((u8*)lbl_8053AAF8 + 0x58);
    if (state == 1 || state == 5) {
        *(s32*)(this_ + 0xc) += 10;
        if (*(s32*)(this_ + 0xc) >= 0xfe) {
            *(s32*)(this_ + 0xc) = 0xff;
            if (*(s32*)((u8*)lbl_8053AAF8 + 0x58) == 5) {
                *(s32*)(this_ + 0x14) = 10;
            }
            return 1;
        }
        return 0;
    }
    if (state == 4) {
        *(s32*)(this_ + 0xc) -= 10;
        if (*(s32*)(this_ + 0xc) < 0) {
            *(s32*)(this_ + 0xc) = 0;
            return 1;
        }
        return 0;
    }
    if (state == 6) {
        if (*(s32*)(this_ + 0x14) == 0) {
            return 1;
        }
        *(s32*)(this_ + 0x14) -= 1;
        return 0;
    }
    return 1;
}

extern "C" void fn_802AC980(u8* this_) { *(u32*)(this_ + 0x10) = 2; }

extern void* lbl_8053AB10;
extern void fn_8013B490(void*);
extern "C" void fn_802AC98C(u8* this_) {
    s32 v = *(s32*)(this_ + 0x10);
    if (v > 0) {
        if (v < 0xfd) {
            *(s32*)(this_ + 0x10) = v + 2;
        } else {
            *(s32*)(this_ + 0x10) = 0xff;
        }
        fn_8013B490(lbl_8053AB10);
        s32 a = 0;
        s32 b = 0xff;
        s32 c = 0xff;
        s32 d = 0;
        void* obj = *(void**)(this_ + 4);
        ((void (*)(void*, s32*, s32*))(*(void***)obj)[0x130 / 4])(obj, &b, &a);
        ((void (*)(void*, u8))(*(void***)obj)[0x24 / 4])(obj, (u8)*(s32*)(this_ + 0x10));
        ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))(*(void***)obj)[0xec / 4])(obj, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f);
    }
}

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

