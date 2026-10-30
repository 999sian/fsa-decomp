#include "types.h"
#include "JSystem/J2D/J2DPicture.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_8013B490(void*);
extern void* lbl_8053AB10;
extern const f32 lbl_805408B8;
extern const f32 lbl_805408BC;
extern const f32 lbl_805408C0;


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

extern "C" void fn_802AC98C(u8* this_) {
    s32 v = *(s32*)(this_ + 0x10);
    if (v > 0) {
        if (v < 0xfd) {
            *(s32*)(this_ + 0x10) = v + 2;
        } else {
            *(s32*)(this_ + 0x10) = 0xff;
        }
        fn_8013B490(lbl_8053AB10);
        (*(J2DPicture**)(this_ + 4))->setBlackWhite(JUtility::TColor(0xff), JUtility::TColor(0));
        (*(J2DPicture**)(this_ + 4))->setAlpha(*(s32*)(this_ + 0x10));
        (*(J2DPicture**)(this_ + 4))->draw(lbl_805408B8, lbl_805408B8, lbl_805408BC, lbl_805408C0, false, false, false);
    }
}

extern const f32 lbl_805408B8;
extern const f32 lbl_805408BC;
extern const f32 lbl_805408C0;
typedef void (*FnPair)(void*, void*, void*);
typedef void (*FnByte)(void*, u8);
typedef void (*FnFloats)(void*, s32, s32, s32, f32, f32, f32, f32);
extern "C" void fn_802ACA64(u8* this_)
{
    fn_8013B490(lbl_8053AB10);
    if (*(s32*)(this_ + 0x18) == 0) {
        (*(J2DPicture**)(this_ + 4))->setBlackWhite(JUtility::TColor(0xff), JUtility::TColor(0));
    } else {
        (*(J2DPicture**)(this_ + 4))->setBlackWhite(JUtility::TColor(0xffffffff), JUtility::TColor(0xffffff00));
    }
    (*(J2DPicture**)(this_ + 4))->setAlpha(*(u32*)(this_ + 0xc));
    (*(J2DPicture**)(this_ + 4))->draw(lbl_805408B8, lbl_805408B8, lbl_805408BC, lbl_805408C0, false, false, false);
}

extern "C" void fn_802ACB58(u8* this_) {
  *(u32*)(this_ + 0xc) = 0;
  *(u32*)(this_ + 0x18) = 0;
}

extern char lbl_804A8390[];
extern "C" void __dl__FPv(void*);
extern void* lbl_8053ACA0;
extern char lbl_8046C8A0[];
extern "C" void* fn_804030C4(u32, void*);
extern "C" void* __nw__FUl(u32);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void*, void*);
extern "C" void* fn_802ACB68(void* this_, short param_2) {
  if (this_ != (void*)0) {
    *(void**)this_ = (void*)lbl_804A8390;
    delete *(J2DPicture**)((u8*)this_ + 4);
    *(u32*)((u8*)this_ + 4) = 0;
    if (param_2 > 0) {
      __dl__FPv(this_);
    }
  }
  return this_;
}

extern "C" void* fn_802ACBE8(void* this_) {
    *(void**)this_ = (void*)lbl_804A8390;
    lbl_8053ACA0 = this_;
    const ResTIMG* res = (const ResTIMG*)fn_804030C4(0x54494d47, (void*)lbl_8046C8A0);
    *(J2DPicture**)((u8*)this_ + 4) = new J2DPicture(res);
    *(u32*)((u8*)this_ + 0xc) = 0;
    *(u32*)((u8*)this_ + 0x10) = 0;
    *(u32*)((u8*)this_ + 0x14) = 0;
    *(u32*)((u8*)this_ + 0x18) = 0;
    return this_;
}

extern "C" void fn_802ACC80(void) {
}

