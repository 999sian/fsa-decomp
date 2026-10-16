#include "JSystem/JMath/JMath.h"
#include "dolphin/mtx.h"
#include "JSystem/JGeometry.h"

struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];
extern const u32 lbl_80472718[];
extern const s16 lbl_80472748[];
extern const f32 lbl_80542930;
extern const f32 lbl_80542940;
extern const f32 lbl_80542950;
extern const f32 lbl_80542954;
extern const f32 lbl_80542980;
extern const f32 lbl_80542984;

struct Unk8035CD00 {
    u8 pad0[0x14];
    f32 m14;
    u8 pad18[0x25c - 0x18];
    f32 m25C;
    s16 m260;
    u8 pad262[2];
    f32 m264;
    f32 m268;
    u8 pad26c[4];
    s16 m270;
};

extern "C" Vec fn_8035CD00(Unk8035CD00* p) {
    s16 old = p->m260;
    p->m260 += 0x400;
    Vec pos;
    pos.x = 25.0f * JMACosShort(p->m260) + (0.0f + p->m264);
    pos.y = 25.0f * JMASinShort(p->m260) + (25.0f + (p->m268 - p->m25C));
    pos.z = p->m14;
    Vec ret = pos;
    if ((u16)p->m260 >= 0xC000 && (u16)old < 0xC000) {
        if (p->m270 < 0) {
            p->m270 = -0x4000;
        } else {
            p->m270 = -0x8000;
        }
    }
    return ret;
}

extern const f32 lbl_80542938;
extern const f32 lbl_8054293C;
extern "C" JGeometry::TVec3<f32> fn_8035CDC0(char* p) {
    s16 old = *(s16*)(p + 0x260);
    *(s16*)(p + 0x260) = old + 0x400;
    s16 ang = *(s16*)(p + 0x260);
    f32 z = *(f32*)(p + 0x14);
    JGeometry::TVec3<f32> v(lbl_80542938 * JMath::sincosTable_.mTable[(u16)ang >> 5].second + (*(f32*)(p + 0x264) - lbl_8054293C),
        lbl_80542938 * JMath::sincosTable_.mTable[(u16)ang >> 5].first + (*(f32*)(p + 0x268) + *(f32*)(p + 0x25c) - lbl_80542938),
        z);
    if (ang >= 0x4000 && old < 0x4000) {
        if (*(s16*)(p + 0x270) < 0) {
            *(s16*)(p + 0x270) = -0x4000;
        } else {
            *(s16*)(p + 0x270) = -0x8000;
        }
    }
    return v;
}

extern "C" void fn_8035D6C4(char* p) {
    if (*(int*)(p + 0x238) == 0) return;
    *(int*)(p + 0x234) = 0x400;
    *(int*)(p + 0x230) = 1;
    *(int*)(p + 0x244) = 0x38;
    *(int*)(p + 0x238) = 4;
}

extern void* lbl_804AD5B8[];
extern void* lbl_804A5958[];
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern "C" void* fn_8035D6F4(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AD5B8;
        if (*(u8**)(this_ + 0x274) != 0) {
            u8* p = *(u8**)(this_ + 0x274);
            *(u32*)(p + 0xf4) |= 1;
            *(s32*)(p + 0x24) = 1;
            *(void**)(this_ + 0x274) = 0;
        }
        if (*(u8**)(this_ + 0x278) != 0) {
            u8* p = *(u8**)(this_ + 0x278);
            *(u32*)(p + 0xf4) |= 1;
            *(s32*)(p + 0x24) = 1;
            *(void**)(this_ + 0x278) = 0;
        }
        if (this_ != 0) {
            *(void**)this_ = lbl_804A5958;
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

struct Unk8035DA78;
typedef void (Unk8035DA78::*Unk8035DA78Func)();
extern Unk8035DA78Func lbl_804AD528[];
extern "C" void fn_8035DA78(Unk8035DA78* self) {
    char* p = (char*)self;
    if (*(int*)(p + 0x234) != 0) *(int*)(p + 0x234) -= 1;
    if (*(int*)(p + 0x244) != 0) *(int*)(p + 0x244) -= 1;
    (self->*lbl_804AD528[*(int*)(p + 0x230)])();
}

extern "C" void fn_8035DAD8(char* p) {
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 8;
    *(s32*)(p + 0x24c) = 0;
    *(u32*)(p + 0x250) = lbl_80472718[*(u32*)(p + 0x90) & 7];
    *(f32*)(p + 0x254) = lbl_80542954;
    *(f32*)(p + 0x258) = lbl_80542980;
    *(f32*)(p + 0x25c) = lbl_80542940;
    *(s16*)(p + 0x260) = lbl_80472748[*(u32*)(p + 0x90) & 7];
    *(f32*)(p + 0x264) = lbl_80542984;
    *(f32*)(p + 0x268) = lbl_80542950;
    *(f32*)(p + 0x26c) = lbl_80542930;
    *(s16*)(p + 0x270) = 0;
    *(u8*)(p + 0x272) = 0;
    *(f32*)(p + 0xc) = *(f32*)(p + 0x258) * JMACosShort(*(s16*)(p + 0x260)) + *(f32*)(p + 0x264);
    *(f32*)(p + 0x10) = *(f32*)(p + 0x25c) * JMASinShort(*(s16*)(p + 0x260)) + *(f32*)(p + 0x268);
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x278) = 0;
}

