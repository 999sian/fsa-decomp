#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804AB2B0[];
extern u8* lbl_8053AAF8;
extern f32 lbl_80541AA0;
extern f32 lbl_80541AC8;
extern "C" void* fn_8031FD60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB2B0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80320024(void* this_) {
    u8* obj = (u8*)this_;
    *(u32*)(obj + 0x24c) = 0;
    *(u32*)(obj + 0x250) = *(u32*)(obj + 0x90) & 0xf;
    if (*(u32*)(obj + 0x250) < 3) {
        *(u32*)(obj + 0x250) = 3;
    }
    *(u64*)(obj + 0x230) = *(u64*)(obj + 0xc);
    *(f32*)(obj + 0x238) = *(f32*)(obj + 0x14);
    *(f32*)(obj + 0x23c) = lbl_80541AC8;
    *(u8*)(obj + 0x244) = (*(u32*)(obj + 0x90) >> 8) & 0xff;
    *(u8*)(obj + 0x245) = (*(u32*)(obj + 0x90) >> 16) & 0xff;
    u8* rng = lbl_8053AAF8;
    *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
    f32 r = *(f32*)&bits - lbl_80541AA0;
    *(s32*)(obj + 0x240) = (s32)((f32)*(u8*)(obj + 0x245) * r);
    *(u8*)(obj + 0x254) = (*(u32*)(obj + 0x90) >> 24) & 1;
    *(u8*)(obj + 0x255) = (*(u32*)(obj + 0x90) >> 25) & 1;
    u32 v = *(u32*)(obj + 0x90);
    u32 t = ((v & 0x30) ^ 0x20) | 0xf;
    *(u32*)(obj + 0x24c) = (v & 0xF8000000) | (t | (*(u32*)(obj + 0x250) << 6)) | (*(u8*)(obj + 0x255) << 16);
    *(u32*)(obj + 0x248) = ((*(u32*)(obj + 0x90) >> 4) & 3) ^ 2;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
