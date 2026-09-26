// Game TU 801DCC98-801DD1AC (BOIB). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A5038[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);

extern "C" void fn_8013CB44(void* h, JGeometry::TVec3<f32>* pos, u32 a, u32 b, u32 c);
extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void* fn_8013CC50(u32 id, JGeometry::TVec3<f32>* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern const f32 lbl_8053F378;
extern const f32 lbl_8053F37C;
extern const f32 lbl_8053F380;
extern const f32 lbl_8053F384;

extern "C" void fn_801DCC98(u8* this_) {
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)(this_ + 0xc);
    pos->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    fn_8013CB44(*(void**)(this_ + 0x2a8), pos, 0, 0, 1);
    fn_8013CB44(*(void**)(this_ + 0x2ac), (JGeometry::TVec3<f32>*)(this_ + 0xc), 0, 0, 1);
    s32 idx = *(s32*)(this_ + 0x4);
    u8* mgr = fn_802D6A9C();
    f32* r;
    if (idx < 8) {
        r = (f32*)(mgr + 0xcc);
    } else {
        r = (f32*)(mgr + 0xdc);
    }
    bool inside = ItemBase_inArea(r, (f32*)(this_ + 0xc));
    if (!inside) {
        this_[0x11c] = 0;
    } else if (fn_801F2B7C(this_, *(u32*)(this_ + 0x114), -1, 0x18)) {
        this_[0x11c] = 0;
    }
}

extern "C" void fn_801DCDB4(u8* this_) {
    fn_801D0ED0(this_);
    f32 a = lbl_8053F378;
    f32 b = lbl_8053F37C;
    f32 c = lbl_8053F380;
    f32 d = lbl_8053F384;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x70) = c;
    *(f32*)(this_ + 0x74) = c;
    *(f32*)(this_ + 0x78) = d;
    *(f32*)(this_ + 0x7c) = d;
    *(f32*)(this_ + 0x80) = c;
    *(f32*)(this_ + 0x84) = c;
    *(f32*)(this_ + 0x88) = d;
    *(f32*)(this_ + 0x8c) = d;
    *(u32*)(this_ + 0xb0) = 0;
    *(u32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x300;
    *(u32*)(this_ + 0x114) = 2;
    this_[0x194] = 1;
    *(void**)(this_ + 0x2a8) = fn_8013CC50(*(u32*)(this_ + 0x4), (JGeometry::TVec3<f32>*)(this_ + 0xc), 0x256, 0, 0, 0, 0, 1, lbl_8053F380);
    *(void**)(this_ + 0x2ac) = fn_8013CC50(*(u32*)(this_ + 0x4), (JGeometry::TVec3<f32>*)(this_ + 0xc), 0x257, 0, 0, 0, 0, 1, lbl_8053F380);
}

extern "C" void* fn_801DCE9C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5038;
        fn_801EE434(*(void**)(p + 0x2a8));
        fn_801EE434(*(void**)(p + 0x2ac));
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

extern "C" void* fn_801DCF40(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A5038;
    *(int*)((char*)this_ + 0x2a8) = 0;
    *(int*)((char*)this_ + 0x2ac) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
