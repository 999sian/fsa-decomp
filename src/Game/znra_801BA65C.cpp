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
    virtual void v40();
    virtual void v41();
    virtual void v42();
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

class J3DFrameCtrl { public: int checkPass(f32); };
extern "C" s32 fn_801D05F8(void* this_, void* pos, f32 r);
extern "C" s32 fn_801CD950(f32* value, f32 target, f32 step);
extern "C" u8 fn_801D217C(void* anim);
extern "C" u8 fn_801D21F0(void* anim);
extern "C" u8 fn_801CECF4(void* this_, u32 id, f32 a, f32 b);
extern "C" void fn_801F0E34(void* actor, u32 msg, s32 arg);
extern "C" void fn_801BACE8(ZNRA* this_, s32 state);

static inline void znraSetBox(u8* p, f32 lo, f32 hi) {
    *(f32*)(p + 0x60) = lo;
    *(f32*)(p + 0x64) = lo;
    *(f32*)(p + 0x68) = hi;
    *(f32*)(p + 0x6c) = hi;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
}

extern "C" void fn_801BA8F8(ZNRA* this_) {
    u8* p = (u8*)this_;
    switch (*(s32*)(p + 0x248)) {
    case 0:
        if (*(u32*)(p + 0x1a0) == 'LTZR') {
            znraSetBox(p, -8.4f, 8.4f);
        }
        this_->v40();
        if (this_->m24C >= (s32)this_->m250 && fn_801D05F8(this_, p + 0xc, 300.0f) >= 0) {
            fn_801BACE8(this_, 1);
        }
        break;
    case 1:
        fn_801F0E34(this_, 0x4006f, 0);
        if (*(u32*)(p + 0x1a0) == 'LTZR') {
            znraSetBox(p, -8.4f, 8.4f);
        }
        this_->v40();
        if (1.5f != *(f32*)(p + 0x54)) {
            fn_801CD950((f32*)(p + 0x54), 1.5f, 0.05f);
            *(f32*)(p + 0x58) = *(f32*)(p + 0x54);
            *(f32*)(p + 0x5c) = *(f32*)(p + 0x54);
        } else if (this_->m24C >= (s32)this_->m250 && fn_801D217C(p + 0x270)) {
            fn_801BACE8(this_, 2);
            this_->v42();
        }
        break;
    case 2:
        if (this_->m24C > 1 && fn_801D21F0(p + 0x270)) {
            fn_801BACE8(this_, 3);
        }
        break;
    case 3:
        if (this_->m24C >= (s32)this_->m250 && fn_801D217C(p + 0x270)) {
            fn_801BACE8(this_, 4);
        }
        break;
    case 4:
        if (this_->m24C > 1) {
            if (*(u32*)(p + 0x1a0) == 'ZORA' &&
                ((J3DFrameCtrl*)(p + 0x294))->checkPass(*(s32*)(p + 0x27c) - 2) &&
                fn_801CECF4(this_, 'ZOSH', 1.5f, 300.0f)) {
                fn_801F0E34(this_, 0x50030, 0);
            }
            if (fn_801D21F0(p + 0x270)) {
                fn_801BACE8(this_, 5);
            }
        }
        break;
    case 5:
        if (*(u32*)(p + 0x1a0) == 'LTZR') {
            znraSetBox(p, -8.4f, 8.4f);
        }
        if (this_->m24C > 1 && fn_801D21F0(p + 0x270)) {
            fn_801BACE8(this_, 0);
        }
        break;
    }
    this_->v41();
    switch (*(s32*)(p + 0x248)) {
    case 0:
    case 1:
    case 2:
    case 5:
        znraSetBox(p, 1.0f, -1.0f);
        break;
    default:
        znraSetBox(p, -12.0f, 12.0f);
        break;
    }
}

struct ZnraCell {
    ZnraCell() {}
    s32 x, y;
};
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, s32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801D22A0(void* obj, u32 a, u32 b);

extern "C" void fn_801BACE8(ZNRA* this_, s32 state) {
    u8* p = (u8*)this_;
    switch (state) {
    case 0:
        this_->m250 = fn_801CD664(0x79) + 0x3c;
        *(f32*)(p + 0x54) = 0.0f;
        *(f32*)(p + 0x58) = 0.0f;
        *(f32*)(p + 0x5c) = 0.0f;
        break;
    case 1:
        this_->m250 = fn_801CD664(0x79) + 0x3c;
        fn_801D22DC(p + 0x270, 0, 2, 0);
        if (*(u32*)(p + 0x1a0) == 'ZORA') {
            JGeometry::TVec3<f32> pos;
            s32 i, j;
            u32 n = *(u32*)(p + 0x90);
            JGeometry::TVec3<f32> dst(*(JGeometry::TVec3<f32>*)(p + 0x24));
            if (n != 0) {
                s32 cnt = 0;
                ZnraCell cells[0x3c1];
                for (i = -n; i <= (s32)n; i++) {
                    f32 dx = 16.0f * i;
                    for (j = -n; j <= (s32)n; j++) {
                        pos.x = *(f32*)(p + 0x24);
                        pos.y = *(f32*)(p + 0x28);
                        pos.z = *(f32*)(p + 0x2c);
                        pos.x = pos.x + dx;
                        pos.y = 16.0f * j + pos.y;
                        if ((u16)((u32(*)(void*, u32))fn_8022461C)(&pos, *(u32*)(p + 4)) == 13) {
                            cells[cnt].x = i;
                            cells[cnt].y = j;
                            cnt++;
                        }
                    }
                }
                if (cnt > 0) {
                    s32 k = fn_801CD664(cnt);
                    dst.x = 16.0f * cells[k].x + dst.x;
                    dst.y = 16.0f * cells[k].y + dst.y;
                }
            }
            *(JGeometry::TVec3<f32>*)(p + 0xc) = dst;
            *(JGeometry::TVec3<f32>*)(p + 0x18) = dst;
        }
        *(f32*)(p + 0x54) = 0.0f;
        *(f32*)(p + 0x58) = 0.0f;
        *(f32*)(p + 0x5c) = 0.0f;
        *(void**)(p + 0x2a8) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x555, -1, 0, 0, 0, 1, 1.0f);
        break;
    case 2:
        this_->m250 = (u32)-1;
        fn_801D22DC(p + 0x270, 1, 0, 0);
        fn_801EE434(*(void**)(p + 0x2a8));
        *(void**)(p + 0x2a8) = 0;
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x15b, 0, 1, 0, 0, 1, 1.0f);
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x15c, -1, 0, 0, 0, 1, 1.0f);
        fn_801F0E34(this_, 0x40050, 0);
        break;
    case 3:
        znraSetBox(p, -12.0f, 12.0f);
        this_->m230 &= ~0x100;
        this_->m250 = fn_801CD664(0x29) + 0x28;
        fn_801D22A0(p + 0x270, 2, 2);
        break;
    case 4:
        this_->m250 = (u32)-1;
        fn_801D22DC(p + 0x270, 3, 0, 0);
        break;
    case 5:
        this_->v39();
        znraSetBox(p, 1.0f, -1.0f);
        this_->m230 |= 0x100;
        this_->m250 = (u32)-1;
        fn_801D22DC(p + 0x270, 4, 0, 0);
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x15b, 0, 1, 0, 0, 1, 1.0f);
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x15c, -1, 0, 0, 0, 1, 1.0f);
        fn_801F0E34(this_, 0x50032, 0);
        break;
    }
    this_->m24C = 0;
    *(s32*)(p + 0x248) = state;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
