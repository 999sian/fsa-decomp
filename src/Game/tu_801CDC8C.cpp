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
extern "C" void fn_801CCD34(f32* in, f32* out);
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
extern const f32 lbl_8053EFF0;
extern "C" s32 fn_801CF720(u8* this_, s32 dir);
extern "C" u8 fn_801CCB1C(const f32* pos, s32 layer);
extern "C" u8 fn_801CFCF0(u8* this_, s32 idx);
extern "C" s32 fn_801CF798(u8* this_, s32 idx, s32 dir);
extern "C" s32 fn_801CD580(s32 exclude);

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

extern "C" void fn_801F2B7C(u8* this_, u32 a, s32 b, s32 c);
extern "C" s32 fn_801F2618(u8* this_, s32 a);
extern "C" s32 fn_801F2DB4(u8* this_, u32 a, u32 b, s32 c);
extern "C" void fn_801CE5D4(u8* this_) {
    if (*(u32*)(this_ + 0x230) & 7) {
        *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x20);
        *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x23c);
        ((ItemBase*)this_)->v31();
        *(f32*)(this_ + 0x14) += *(f32*)(this_ + 0x44);
        if (*(f32*)(this_ + 0x14) <= lbl_8053EFC4) {
            if (*(fn_802D6A9C() + 0x131df + *(u32*)(this_ + 0x4))) {
                ((ItemBase*)this_)->v30();
            } else {
                *(f32*)(this_ + 0x14) = lbl_8053EFC4;
                *(f32*)(this_ + 0x44) = lbl_8053EFC4;
            }
        }
    }
}

extern "C" void fn_801CE914(void) {}

extern "C" void fn_801CE918(void) {}

extern "C" void fn_801CE91C(void) {}

extern "C" void fn_801CE920(void) {}

extern "C" void fn_801CE924(void) {}

extern "C" s32 fn_801CE928(u8* this_) {
    s32 result = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        result = ((s32 (*)(u8*, u32, s32, s32))fn_801F2B7C)(this_, *(u32*)(this_ + 0x114), -1, 1);
    }
    return result;
}

extern "C" s32 fn_801CE98C(u8* this_) {
    s32 result = 0;
    if (!(*(u32*)(this_ + 0x230) & 0x1000) && *(f32*)(this_ + 0x88) - *(f32*)(this_ + 0x80) > lbl_8053EFC4 && *(f32*)(this_ + 0x8c) - *(f32*)(this_ + 0x84) > lbl_8053EFC4) {
        result = fn_801F2618(this_ + 0x264, 0);
    }
    return result;
}

extern "C" s32 fn_801CE9F8(u8* this_) {
    s32 result = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EFC4 && *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EFC4) {
        u32 tag = 0x4E554C4C;
        result = fn_801F2DB4(this_, tag, tag, 0);
    }
    return result;
}

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
    f32 x = *(f32*)(this_ + 0x3c);
    f32 y = *(f32*)(this_ + 0x40);
    f32 a = JMAAtan2Radian(x, y);
    return ClassifyBamAngleToQuadrant((s32)(a * lbl_8053EFEC));
}

extern "C" bool fn_801CF144(u8* this_) {
    f32 pos[3];
    bool result = false;
    f32 y = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14) - lbl_8053EFF0;
    pos[0] = *(f32*)(this_ + 0xc);
    pos[1] = y;
    pos[2] = lbl_8053EFC4;
    if (fn_801CCB1C(pos, *(s32*)(this_ + 0x4))) {
        result = true;
    }
    return result;
}

extern "C" s32 fn_801CF6B8(u8* this_) {
    s32 idx = fn_801CD664(4);
    if (fn_801CFCF0(this_, idx)) {
        idx = fn_801CF720(this_, idx);
    }
    return idx;
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

extern "C" BOOL fn_801D0DD4(char* this_) {
    struct TndrG { u8 pad[0x131df]; u8 arr[4]; };
    struct Self { u8 pad0[4]; s32 room; u8 pad8[0xc]; f32 f14; u8 pad18[0x218]; u32 flags; };
    Self* s = (Self*)this_;
    s32 room = s->room;
    TndrG* g = (TndrG*)fn_802D6A9C();
    if (g->arr[room] != 0) {
        return (s->flags & 0x18) != 0;
    }
    return s->f14 <= lbl_8053EFC4 ? TRUE : FALSE;
}

extern "C" void fn_801D0E58(char* p) {
    f32 v[2];
    fn_801CCD34((f32*)(p + 0xc), v);
    *(f32*)(p + 0xc) = v[0];
    *(f32*)(p + 0x10) = v[1];
    *(f32*)(p + 0x18) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x1c) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x20) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x24) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x28) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2c) = *(f32*)(p + 0x14);
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
