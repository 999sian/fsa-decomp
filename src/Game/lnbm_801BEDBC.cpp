// Game TU 801BEDBC-801BF810 (LNBM). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, s32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" u32 fn_8022461C(void* p);
extern "C" u8 fn_802265DC(void* a, void* b, u32 c);
extern "C" u8* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* obj, void* a, void* b, u32 c, u32 d);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern const f32 lbl_8053ED00;
extern const f32 lbl_8053ED18;
extern const f32 lbl_8053ED1C;
extern const f32 lbl_8053ED20;

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A4188[];

extern "C" void fn_801BEDBC(u8* this_) {
    if (this_[0x11c] != 0 && !(*(u32*)(this_ + 0x230) & 0x2000)) {
        fn_8013CC50(*(u32*)(this_ + 0x4), this_ + 0xc, 0x1e, 0, -1, 0, 0, 1, lbl_8053ED00);
        fn_8013CC50(*(u32*)(this_ + 0x4), this_ + 0xc, 0x1f, 0, 0, 0, 0, 1, lbl_8053ED00);
        fn_801F0E34(this_, 0x30061, 0);
        *(u32*)(this_ + 0x230) |= 0x2000;
    }
}

inline void* lnbmMgr() { u8* m = fn_8020D58C(); return m + m[1] * 0x784 + 4; }

extern "C" BOOL fn_801BEE6C(ItemBase* this_, void* a, void* b) {
    switch ((u16)fn_8022461C(b)) {
    case 3:
    case 13:
    case 14:
        return FALSE;
    }
    BOOL result = TRUE;
    if (!fn_802265DC(b, a, 0)) {
        u32 v = *(u32*)((u8*)this_ + 0x90);
        if (!fn_8020D6AC(lnbmMgr(), a, b, v, 0)) {
            result = FALSE;
        }
    }
    return result;
}

extern "C" void fn_801BF464(u8* this_) {
    fn_801D0ED0(this_);
    f32 a = lbl_8053ED18;
    f32 c = lbl_8053ED00;
    f32 b = lbl_8053ED1C;
    f32 d = lbl_8053ED20;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x70) = c;
    *(f32*)(this_ + 0x74) = c;
    *(f32*)(this_ + 0x78) = d;
    *(f32*)(this_ + 0x7c) = d;
    *(f32*)(this_ + 0x80) = d;
    *(f32*)(this_ + 0x84) = d;
    *(f32*)(this_ + 0x88) = c;
    *(f32*)(this_ + 0x8c) = c;
    *(u32*)(this_ + 0xb0) = 0;
    *(u32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x280;
    *(u32*)(this_ + 0x108) = 1000;
    *(u32*)(this_ + 0x244) = *(u32*)(this_ + 0x108);
    this_[0x194] = 1;
    *(u32*)(this_ + 0x114) = 2;
    *(u32*)(this_ + 0x24c) = 0;
}

extern "C" void* fn_801BF50C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4188;
        fn_801EE434(*(void**)(p + 0x2a8));
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

extern "C" void* fn_801BF5A8(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4188;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

extern "C" void fn_8013CB44(void* h, void* pos, u32 a, u32 b, u32 c);
extern "C" void fn_8013CAA4(void* h, f32 angle);
extern const f32 lbl_8053ED04;
extern const f32 lbl_8053ED08;
extern const f32 lbl_8053ED0C;

extern "C" void fn_801BF380(u8* this_) {
    *(void**)(this_ + 0x2a8) = fn_8013CC50(*(u32*)(this_ + 0x4), this_ + 0xc, 0x1b, 0, *(u16*)(this_ + 0x94), 0, 0, 1, lbl_8053ED00);
    if (*(void**)(this_ + 0x2a8) != 0) {
        u32 n = 1;
        if (*(s32*)(this_ + 0x24c) < 2) {
            n = *(u16*)(this_ + 0x94);
        }
        fn_8013CB44(*(void**)(this_ + 0x2a8), this_ + 0xc, 0, n, 1);
        f32 r = JMath::atanTable_.atan2_(*(f32*)(this_ + 0x3c), *(f32*)(this_ + 0x40));
        s16 ang = r * lbl_8053ED04;
        fn_8013CAA4(*(void**)(this_ + 0x2a8), lbl_8053ED08 * (lbl_8053ED0C * ang));
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
