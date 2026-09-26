// Game TU 801E7BF4-801E801C (FSPO). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A54C0[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" {
}

extern "C" void* fn_801E7BF4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A54C0;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801E7C84(void) {}

extern "C" void fn_801D0ED0(void* this_);
extern "C" f32 fn_80210B34(u32 dir);
extern "C" f32 fn_80210AF8(u32 dir);
extern "C" u8* fn_801E9AFC(void);
extern "C" void fn_801EA75C(void* entry, u32 a, u32 b, u32 c, u32 d, f32* pos);
extern const f32 lbl_8053F5F0;
extern const f32 lbl_8053F5F4;

extern "C" void fn_801E7C88(u8* this_) {
    u32 hi, lo, d, mid, dir;
    fn_801D0ED0(this_);
    u32 flags = *(u32*)(this_ + 0x90);
    if ((flags >> 23) & 1) {
        dir = (flags >> 21) & 3;
        *(f32*)(this_ + 0x24) += fn_80210B34(dir);
        *(f32*)(this_ + 0x28) += fn_80210AF8(dir);
        JGeometry::setTVec3f((f32*)(this_ + 0x24), (f32*)(this_ + 0xc));
        JGeometry::setTVec3f((f32*)(this_ + 0x24), (f32*)(this_ + 0x18));
    }
    f32 b = lbl_8053F5F4;
    f32 a = lbl_8053F5F0;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(u32*)(this_ + 0xb0) = 0;
    *(u32*)(this_ + 0x230) |= 0x100;
    d = *(u32*)(this_ + 0x4);
    lo = *(u32*)(this_ + 0x90) & 0xff;
    hi = *(u32*)(this_ + 0x90) >> 24;
    mid = (lo == 0) ? ((*(u32*)(this_ + 0x90) >> 16) & 0x1f) : 0;
    u8* mgr = fn_801E9AFC();
    fn_801EA75C(mgr + mgr[0xf0] * 0x78, hi, (u8)mid, lo, d, (f32*)(this_ + 0xc));
    this_[0x11c] = 0;
}

extern "C" void* fn_801E7DBC(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A54C0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
