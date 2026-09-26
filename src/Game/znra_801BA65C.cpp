// Game TU 801BA65C-801BB618 (ZNRA). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_8030C210(void* obj, void* pos);
extern "C" u32 fn_8022461C(void* p);
extern "C" int fn_801F15BC(void* this_, void* a, void* b);
extern u8* lbl_8053AB10;
extern u8 lbl_80469380[];
extern const f32 lbl_8053EBAC;
extern const f32 lbl_8053EBA8;
extern const f32 lbl_8053EBB0;
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D0E58(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801D2608(void* obj, void* tbl, u32 n);
extern "C" void fn_801D22DC(void* obj, u32 a, u32 b, u32 c);
extern "C" void fn_801D1D60(void* obj);
extern u8 lbl_804A3D68[];
extern const f32 lbl_8053EBC8;
extern const f32 lbl_8053EBE4;
extern const f32 lbl_8053EBE8;

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3D7C[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void fn_801BA65C(void) {}
extern "C" int fn_801BA660(void) { return 0; }
extern "C" void fn_801BA668(void) {}
extern "C" void fn_801BA66C(void) {}

inline bool znraIsZero(const Vec* v) {
    return JMathInlineVEC::PSVECSquareMag(v) <= lbl_8053EBA8 * FLT_EPSILON;
}
inline bool znraNotZero(const Vec* v) {
    return !(JMathInlineVEC::PSVECSquareMag(v) <= lbl_8053EBA8 * FLT_EPSILON);
}

extern "C" void fn_801BA670(u8* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 1:
        return;
    }
    if (!znraNotZero((Vec*)(this_ + 0x54))) {
        return;
    }
    DrawRec rec;
    f32 mtx[3][4];
    f32 zero = lbl_8053EBAC;
    mtx[0][3] = zero;
    mtx[1][3] = zero;
    mtx[2][3] = zero;
    f32 sy, sz;
    sz = *(f32*)(this_ + 0x5c);
    sy = *(f32*)(this_ + 0x58);
    mtx[0][0] = *(f32*)(this_ + 0x54);
    mtx[0][1] = zero;
    mtx[0][2] = zero;
    mtx[1][0] = zero;
    mtx[1][1] = sy;
    mtx[1][2] = zero;
    mtx[2][0] = zero;
    mtx[2][1] = zero;
    mtx[2][2] = sz;
    rec.w18 = mtx;
    switch (*(s32*)(this_ + 0x280)) {
    case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        *(s8*)&rec.b1c = -1;
        break;
    }
    fn_801F06F0(this_, lbl_80469380, *(s32*)(this_ + 0x280) + 0xd5, &rec, -1, lbl_8053EBB0, lbl_8053EBB0);
}

extern "C" void fn_801BA854(u8* this_) {
    if (*(s32*)(this_ + 0x248) != 0) {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
    }
}

extern "C" int fn_801BA88C(void* this_, void* a, void* b) {
    if ((u16)fn_8022461C(b) == 0xd) {
        return 0;
    }
    return fn_801F15BC(this_, a, b);
}

extern "C" void fn_801BB1A8(void) {}

template <typename T>
inline T znraClamp(T v, T lo, T hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

class ZNRA : public ItemBase {
public:
    virtual void v39();
};

extern "C" void fn_801BB1AC(ZNRA* this_) {
    u8* p = (u8*)this_;
    fn_801D0ED0(this_);
    fn_801D0E58(this_);
    *(u32*)(p + 0x98) = 2;
    *(f32*)(p + 0x60) = lbl_8053EBB0;
    *(f32*)(p + 0x64) = lbl_8053EBB0;
    *(f32*)(p + 0x68) = lbl_8053EBC8;
    *(f32*)(p + 0x6c) = lbl_8053EBC8;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = lbl_8053EBE4;
    *(f32*)(p + 0x84) = lbl_8053EBE4;
    *(f32*)(p + 0x88) = lbl_8053EBE8;
    *(f32*)(p + 0x8c) = lbl_8053EBE8;
    if (*(u32*)(p + 0x1a0) == 'LTZR') {
        *(u32*)(p + 0xb0) = 0;
    } else {
        *(u32*)(p + 0xb0) = 0x10101;
    }
    this_->m230 |= 0x100;
    *(f32*)(p + 0x54) = lbl_8053EBAC;
    *(f32*)(p + 0x58) = lbl_8053EBAC;
    *(f32*)(p + 0x5c) = lbl_8053EBAC;
    *(u32*)(p + 0x248) = 0;
    this_->m24C = 0;
    this_->m250 = fn_801CD664(0x79) + 0x3c;
    this_->m254 = lbl_8053EBAC;
    this_->m258 = lbl_8053EBAC;
    fn_801D2608(p + 0x270, lbl_804A3D68, 5);
    fn_801D22DC(p + 0x270, 0, 2, 0);
    fn_801D1D60(p + 0x270);
    *(u32*)(p + 0x90) = znraClamp<u32>(*(u32*)(p + 0x90), 0, 0xf);
    this_->v39();
}

extern "C" void* fn_801BB30C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A3D7C;
        fn_801EE434(*(void**)(p + 0x2a8));
        *(s32*)(p + 0x2a8) = 0;
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

extern "C" void* fn_801BB3B0(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3D7C;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
