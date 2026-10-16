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
    s32 sw = *(s32*)(this_ + 0x2f0);
    s16 v = *(s16*)(this_ + 0x2f8);
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
    u8* p = this_;
    for (s32 i = 0; i < *(s32*)(this_ + 0x2a8); i++) {
        fn_801BD8C0(fn_801F666C(fn_801F856C(), *(s32*)(p + 0x2ac)), pos, *(s16*)(this_ + 0x2fc));
        pos.x += dx;
        pos.y += dy;
        p += 4;
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

extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D0E58(void* this_);
extern "C" u16 fn_801F6874(s32 dir);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern const f32 lbl_8053EC80;
extern const f32 lbl_8053EC84;

static inline s32 ezmrCreate(s32 room, void* pos, u32 flag) {
    return Actor_CreateByID(fn_801F856C(), 0x46424f42, room, pos, flag, -1, -1);
}

extern "C" void fn_801BD348(u8* this_) {
    fn_801D0ED0(this_);
    if (!((*(u32*)(this_ + 0x90) >> 17) & 1)) {
        fn_801D0E58(this_);
    }
    *(u8*)(this_ + 0x2ec) = (*(u32*)(this_ + 0x90) >> 31) ^ 1;
    *(s32*)(this_ + 0x2f0) = (*(u32*)(this_ + 0x90) >> 26) & 0x1f;
    s32 speed = (*(u32*)(this_ + 0x90) >> 24) & 3;
    if (speed > 2) {
        speed = 2;
    } else if (speed < 0) {
        speed = 0;
    }
    *(s32*)(this_ + 0x2f4) = ((*(u32*)(this_ + 0x90) >> 20) & 0xf) + 1;
    s32 dir = (*(u32*)(this_ + 0x90) >> 8) & 0xff;
    u32 cw = (*(u32*)(this_ + 0x90) >> 16) & 1;
    if (dir > 3) {
        dir = 3;
    } else if (dir < 0) {
        dir = 0;
    }
    s32 n = *(u32*)(this_ + 0x90) & 0xff;
    if (n > 16) {
        n = 16;
    } else if (n < 1) {
        n = 1;
    }
    *(s32*)(this_ + 0x2a8) = n;
    *(s16*)(this_ + 0x2fa) = fn_801F6874(dir);
    switch (speed) {
    case 0:
        *(s16*)(this_ + 0x2f8) = 0x80;
        break;
    case 1:
        *(s16*)(this_ + 0x2f8) = 0x100;
        break;
    default:
        *(s16*)(this_ + 0x2f8) = 0x40;
        break;
    }
    if (cw == 0) {
        *(s16*)(this_ + 0x2f8) = -*(s16*)(this_ + 0x2f8);
    }
    f32 hi = lbl_8053EC84;
    f32 lo = lbl_8053EC80;
    *(f32*)(this_ + 0x60) = lo;
    *(f32*)(this_ + 0x64) = lo;
    *(f32*)(this_ + 0x68) = hi;
    *(f32*)(this_ + 0x6c) = hi;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = lo;
    *(f32*)(this_ + 0x84) = lo;
    *(f32*)(this_ + 0x88) = hi;
    *(f32*)(this_ + 0x8c) = hi;
    *(u32*)(this_ + 0xb0) = 0;
    *(s32*)(this_ + 0x98) = 2;
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
        *(s32*)(this_ + i * 4 + 0x2ac) = ezmrCreate(*(s32*)(this_ + 0x4), &pos, *(u8*)(this_ + 0x2ec) == 0);
        fn_801BD8C0(fn_801F666C(fn_801F856C(), *(s32*)(this_ + i * 4 + 0x2ac)), pos, *(s16*)(this_ + 0x2fc));
        pos.x += dx;
        pos.y += dy;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
