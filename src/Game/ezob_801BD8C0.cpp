// Game TU 801BD8C0-801BDE5C (EZOB). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JUtility/TColor.h"
#include "JSystem/JGeometry/Vec.h"
#include "dolphin/gx/GXStruct.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A4038[];

extern "C" void fn_8013CB44(void* h, void* pos, u32 a, u32 b, u32 c);
extern "C" int fn_801CB7CC(void* arg);
extern void JPAGetXYZRotateMtx(s16 x, s16 y, s16 z, f32 (*mtx)[4]);
extern "C" void fn_80158B5C(void* obj, u32 id, void* pos, GXColor color, f32 f);
extern u8* lbl_8053AB10;
extern const f32 lbl_8053EC8C;
extern const f32 lbl_8053EC90;
extern const f32 lbl_8053EC94;
extern const f32 lbl_8053EC98;
extern const f32 lbl_8053EC9C;
extern const u16 lbl_8053EC88[2];
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" void* fn_8013CC50(u32 id, f32* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct EZOB {
    void* vtbl;
    u32 mId;
    u8 pad08[0xc - 0x8];
    JGeometry::TVec3<f32> mPos;
    u8 pad18[0x2a8 - 0x18];
    void* mEmitters[2];
};

extern "C" void fn_801BD8C0(EZOB* this_, const JGeometry::TVec3<f32>& pos, void* arg) {
    this_->mPos.x = pos.x;
    this_->mPos.y = pos.y;
    this_->mPos.z = pos.z;
    s16 rot = fn_801CB7CC(arg);
    for (s32 i = 0; i < 2; i++) {
        fn_8013CB44(this_->mEmitters[i], (void*)&pos, 0, 0, 1);
        if (i == 0) {
            JPAGetXYZRotateMtx(0, rot, 0, (f32(*)[4])((u8*)this_->mEmitters[i] + 0x68));
        }
    }
}

extern "C" void fn_801BD978(EZOB* this_) {
    u32 id = this_->mId;
    JUtility::TColor color(0, 0, 0, 0x80);
    fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), id, &this_->mPos, color, lbl_8053EC8C);
}

extern "C" void fn_801BD9D0(u8* this_) {
    this_[0x240] = fn_801F2B7C(this_, *(u32*)(this_ + 0x114), -1, 1);
    if (*(u32*)(this_ + 0x90) == 0) {
        fn_8013CC50(*(u32*)(this_ + 0x4), (f32*)(this_ + 0xc), 0x54d, 1, 1, 0, 0, 1, lbl_8053EC90);
    }
}

extern "C" void fn_801BDA40(u8* this_) {
    fn_801D0ED0(this_);
    f32 a = lbl_8053EC94;
    f32 c = lbl_8053EC90;
    f32 b = lbl_8053EC98;
    f32 d = lbl_8053EC9C;
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
    this_[0x194] = 1;
    *(u32*)(this_ + 0x114) = 2;
    for (s32 i = 0; i < 2; i++) {
        u16 kind = lbl_8053EC88[i];
        ((EZOB*)this_)->mEmitters[i] = fn_8013CC50(*(u32*)(this_ + 0x4), (f32*)(this_ + 0xc), kind, 0, 0, 0, 0, 1, lbl_8053EC90);
    }
}

extern "C" void* fn_801BDB2C(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A4038;
        for (s32 i = 0; i < 2; i++) {
            fn_801EE434(((EZOB*)this_)->mEmitters[i]);
        }
        if (this_ != 0) {
            *(void**)this_ = lbl_804A4808;
            if (this_ + 0x270 != 0) {
                if (this_ + 0x294 != 0) {
                    *(void**)(this_ + 0x294) = lbl_8049CC34;
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

extern "C" void* fn_801BDBF0(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4038;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    *(s32*)((char*)this_ + 0x2ac) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
