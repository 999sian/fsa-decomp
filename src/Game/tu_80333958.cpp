#include "Game/Actor.h"


extern "C" char lbl_804AB968[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80333958(Actor* p, s16 n)
{
  if (p) {
    *(void**)p = lbl_804AB968;
    __dt__5ActorFv(p, 0);
    if (n > 0) operator delete(p);
  }
  return p;
}

extern const f32 lbl_80541F40;
extern const f32 lbl_80541F54;
extern const f32 lbl_80541F58;
extern const f32 lbl_80541F5C;
extern const f32 lbl_80541F60;
extern const f32 lbl_80541F64;
extern const f32 lbl_80541F68;
extern "C" void fn_801F0E34(void* this_, u32 a, u32 b);
extern "C" void fn_80333FC4(void* this_) {
    char* p = (char*)this_;
    s32 mode = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(s32*)(p + 0x240) = mode;
    *(s32*)(p + 0x108) = 0x80;
    if ((*(u32*)(p + 0x90) & 0xf) != 0) {
        *(s32*)(p + 0x23c) = 1;
        *(f32*)(p + 0x60) = lbl_80541F54;
        *(f32*)(p + 0x64) = lbl_80541F54;
        *(f32*)(p + 0x68) = lbl_80541F58;
        *(f32*)(p + 0x6c) = lbl_80541F58;
    } else {
        *(s32*)(p + 0x23c) = 0;
        *(f32*)(p + 0x60) = lbl_80541F5C;
        *(f32*)(p + 0x64) = lbl_80541F5C;
        *(f32*)(p + 0x68) = lbl_80541F60;
        *(f32*)(p + 0x6c) = lbl_80541F60;
    }
    switch (*(s32*)(p + 0x240)) {
    case 0:
        *(f32*)(p + 0x3c) = lbl_80541F40;
        *(f32*)(p + 0x40) = lbl_80541F64;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 1:
        *(f32*)(p + 0x3c) = lbl_80541F40;
        *(f32*)(p + 0x40) = lbl_80541F68;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 2:
        *(f32*)(p + 0x3c) = lbl_80541F64;
        *(f32*)(p + 0x40) = lbl_80541F40;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 3:
        *(f32*)(p + 0x3c) = lbl_80541F68;
        *(f32*)(p + 0x40) = lbl_80541F40;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    }
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x234) = 0x1e;
    *(s32*)(p + 0x244) = 0;
    fn_801F0E34(this_, 0x30019, 0);
}

