// Game TU 801CDC8C-801D11FC (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"
extern "C" void fn_801D1C18(void* obj);
extern "C" s32 ClassifyBamAngleToQuadrant(u16 angle);
extern "C" u8 fn_801F2FAC(void* this_);
extern const f32 lbl_8053EFD4;
extern const f32 lbl_8053EFD8;
extern const f32 lbl_8053EFEC;
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JAUSoundObject.h"

extern "C" JAUSoundObject* fn_801F1184(void* this_);
extern "C" void fn_801F0E34(void* this_, void* arg, u32 c);
extern "C" u8* fn_802D6A9C(void);
extern const f32 lbl_8053EFC8;
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void* fn_801D267C(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern void* lbl_804A4808[];
extern const f32 lbl_8053EFC4;
extern const f32 lbl_8053EFD0;
extern const f32 lbl_8053EFDC;
extern const f32 lbl_8053F010;
extern const f32 lbl_8053F014;

extern "C" {
}

extern "C" void fn_801CDC8C(void* this_, u32 id) {
    JAUSoundObject* obj = fn_801F1184(this_);
    if (obj != 0) {
        obj->stopSound(id, 0);
    }
}

struct Vec3f { f32 x, y, z; };

extern "C" void fn_801CDCD0(u8* this_, u32 id, const JGeometry::TVec3<f32>& pos, void* arg) {
    JGeometry::TVec3<f32> save(*(JGeometry::TVec3<f32>*)(this_ + 0xc));
    u32 old = *(u32*)(this_ + 0x4);
    *(u32*)(this_ + 0x4) = id;
    *(f32*)(this_ + 0xc) = pos.x;
    *(f32*)(this_ + 0x10) = pos.y;
    *(f32*)(this_ + 0x14) = pos.z;
    fn_801F0E34(this_, arg, 0);
    *(u32*)(this_ + 0x4) = old;
    *(f32*)(this_ + 0xc) = save.x;
    *(f32*)(this_ + 0x10) = save.y;
    *(f32*)(this_ + 0x14) = save.z;
}

extern "C" void fn_801CE00C(void) {}

extern "C" void fn_801CE010(u8* this_, f32* out) {
    s32 idx = *(s32*)(this_ + 0x4);
    u8* mgr = fn_802D6A9C();
    f32* r;
    if (idx < 8) {
        r = (f32*)(mgr + 0xcc);
    } else {
        r = (f32*)(mgr + 0xdc);
    }
    f32 y0 = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14);
    out[0] = *(f32*)(this_ + 0xc);
    out[1] = y0;
    out[2] = lbl_8053EFC4;
    f32 lim = lbl_8053EFC8 + r[1];
    f32 y = out[1];
    out[1] = (f32)__fsel(lim - y, lim, y);
}

extern "C" void fn_801CE0A4(ItemBase* this_) {
    if ((this_->m230 & 7) == 0) {
        this_->m24C++;
        if (this_->m24C < 0) {
            this_->m24C = 0;
        }
        this_->v34();
        this_->v35();
    }
}

extern "C" void fn_801CE4BC(u8* this_) {
    fn_801D1C18(this_ + 0x270);
}

extern "C" void fn_801CE4E0(void) {}

extern "C" void fn_801CE4E4(void) {}

extern "C" void fn_801CE594(u8* this_) {
    if (*(s32*)(this_ + 0xd8) > 0 && *(s32*)(this_ + 0xf8) == 2) {
        return;
    }
    *(f32*)(this_ + 0x44) += -0.2f;
    if (*(f32*)(this_ + 0x44) < -4.0f) {
        *(f32*)(this_ + 0x44) = -4.0f;
    }
}

extern "C" void fn_801CE914(void) {}

extern "C" void fn_801CE918(void) {}

extern "C" void fn_801CE91C(void) {}

extern "C" void fn_801CE920(void) {}

extern "C" void fn_801CE924(void) {}

extern "C" u8 fn_801CEB78(u8* this_) {
    u8 result = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        result = fn_801F2FAC(this_);
    }
    return result;
}

extern "C" int fn_801CECEC(void) { return 0; }

#pragma fp_contract off
extern "C" s32 fn_801CF0F4(u8* this_) {
    f32 a = JMAAtan2Radian(*(f32*)(this_ + 0x3c), *(f32*)(this_ + 0x40));
    return ClassifyBamAngleToQuadrant((s32)(a * lbl_8053EFEC));
}

extern "C" u8 fn_801CCB1C(const f32* pos, s32 layer);
extern "C" u8 fn_801CFCF0(u8* this_, s32 idx);
extern "C" s32 fn_801CF798(u8* this_, s32 idx, s32 dir);
extern "C" s32 fn_801CD580(s32 exclude);
extern "C" s32 fn_801CF720(u8* this_, s32 dir) {
    s32 idx = fn_801CD580(dir);
    if (fn_801CFCF0(this_, idx)) {
        idx = fn_801CF798(this_, dir, idx);
    }
    return idx;
}

extern "C" s16 fn_801D0280(u8* this_, s32 idx) {
    f32* rec = (f32*)(this_ + idx * 0xc + 0x1ac);
    return lbl_8053EFEC * JMAAtan2Radian(rec[0] - *(f32*)(this_ + 0xc), rec[1] - *(f32*)(this_ + 0x10));
}

extern "C" s16 fn_801D02E0(u8* this_, const Vec& pos) {
    return lbl_8053EFEC * JMAAtan2Radian(pos.x - *(f32*)(this_ + 0xc), pos.y - *(f32*)(this_ + 0x10));
}

extern "C" s32 fn_801D0D50(void* thisArg, s32 playerIdx, f32* point, f32 radius) {
    u8* p = (u8*)thisArg;
    f32 radiusSq = radius * radius;
    s32 result = 0;
    f32* record = (f32*)(p + playerIdx * 0xc + 0x1ac);
    f32 dz = record[1] - point[1];
    f32 dx = record[0] - point[0];
    f32 distSq = dx * dx + dz * dz;
    if (distSq <= radiusSq) {
        result = 1;
    }
    return result;
}
#pragma fp_contract reset

#pragma fp_contract off
extern "C" f32 fn_801D0DA0(void* thisArg, s32 playerIdx, f32* point) {
    u8* p = (u8*)thisArg;
    f32* record = (f32*)(p + playerIdx * 0xc + 0x1ac);
    f32 dz = record[1] - point[1];
    f32 dx = record[0] - point[0];
    return dx * dx + dz * dz;
}
#pragma fp_contract reset

extern "C" void fn_801D0ECC(void) {}

extern "C" void fn_801D0ED0(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053F010;
    *(f32*)(this_ + 0x64) = lbl_8053F010;
    *(f32*)(this_ + 0x68) = lbl_8053EFDC;
    *(f32*)(this_ + 0x6c) = lbl_8053EFDC;
    *(f32*)(this_ + 0x80) = lbl_8053F010;
    *(f32*)(this_ + 0x84) = lbl_8053F010;
    *(f32*)(this_ + 0x88) = lbl_8053EFDC;
    *(f32*)(this_ + 0x8c) = lbl_8053EFDC;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x98) = fn_801CD664(4);
    *(u32*)(this_ + 0x244) = *(u32*)(this_ + 0x108);
}

extern "C" void* fn_801D0F40(u8* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_804A4808;
    *(u32*)(this_ + 0x230) = 0;
    *(f32*)(this_ + 0x234) = lbl_8053EFC4;
    *(f32*)(this_ + 0x238) = lbl_8053EFC4;
    *(f32*)(this_ + 0x23c) = lbl_8053EFC4;
    *(u8*)(this_ + 0x240) = 0;
    *(u32*)(this_ + 0x244) = 8;
    *(u32*)(this_ + 0x248) = 0;
    *(u32*)(this_ + 0x24c) = 0;
    *(u32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x254) = lbl_8053EFC4;
    *(f32*)(this_ + 0x258) = lbl_8053EFC4;
    *(f32*)(this_ + 0x25c) = lbl_8053EFD0;
    *(f32*)(this_ + 0x260) = lbl_8053F014;
    *(f32*)(this_ + 0x264) = lbl_8053EFC4;
    *(f32*)(this_ + 0x268) = lbl_8053EFC4;
    *(f32*)(this_ + 0x26c) = lbl_8053EFC4;
    fn_801D267C(this_ + 0x270);
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
