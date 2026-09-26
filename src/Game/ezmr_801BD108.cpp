// Game TU 801BD108-801BD8C0 (EZMR). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3F90[];

extern "C" void* fn_801BD108(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A3F90;
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

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 id);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_801BD8C0(void* obj, const JGeometry::TVec3<f32>& pos, s32 angle);
extern const f32 lbl_8053EC70;

static inline s16 ezmrGetSpeed(u8* this_) {
    s16 v = *(s16*)(this_ + 0x2f8);
    s32 sw = *(s32*)(this_ + 0x2f0);
    if (sw != 0 && fn_802D800C(fn_802D6A9C(), sw)) {
        v = -v;
    }
    return v;
}

extern "C" void fn_801BD198(u8* this_) {
    *(s16*)(this_ + 0x2fa) += ezmrGetSpeed(this_);
    if (ezmrGetSpeed(this_) < 0) {
        *(s16*)(this_ + 0x2fc) = *(s16*)(this_ + 0x2fa) - 0x4000;
    } else {
        *(s16*)(this_ + 0x2fc) = *(s16*)(this_ + 0x2fa) + 0x4000;
    }
    f32 dx = JMASSin(*(s16*)(this_ + 0x2fa)) * lbl_8053EC70;
    f32 dy = JMASCos(*(s16*)(this_ + 0x2fa)) * lbl_8053EC70;
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    pos.x += (f32)*(s32*)(this_ + 0x2f4) * dx;
    pos.y += (f32)*(s32*)(this_ + 0x2f4) * dy;
    for (s32 i = 0; i < *(s32*)(this_ + 0x2a8); i++) {
        fn_801BD8C0(fn_801F666C(fn_801F856C(), *(s32*)(this_ + i * 4 + 0x2ac)), pos, *(s16*)(this_ + 0x2fc));
        pos.x += dx;
        pos.y += dy;
    }
}

extern "C" void* fn_801BD640(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3F90;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    *(u8*)((char*)this_ + 0x2ec) = 0;
    *(s32*)((char*)this_ + 0x2f0) = 0;
    *(s32*)((char*)this_ + 0x2f4) = 0;
    *(s16*)((char*)this_ + 0x2f8) = 0;
    *(s16*)((char*)this_ + 0x2fa) = 0;
    *(s16*)((char*)this_ + 0x2fc) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
