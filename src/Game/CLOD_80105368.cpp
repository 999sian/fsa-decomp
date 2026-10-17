// CLOD_80105368: .text 0x80105368-0x80105DD4 (actor CLOD)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_802F745C(void* mgr, JGeometry::TVec3f* pos, s32 id, void* out);
extern char* lbl_8053AB10;
extern const f32 lbl_8053C23C;
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049CBE0[];
extern const f32 lbl_8053C228;
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void* anim, void* arg, s32 n);
extern "C" void fn_801D22DC(void* anim, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* anim, f32 scale);
extern u8 lbl_80539EC0;
extern char* lbl_8053AAF8;
extern const char* lbl_8049CBB0[][4];
extern const f32 lbl_8053C250;
extern const f32 lbl_8053C254;
extern const f32 lbl_8053C258;
extern const f32 lbl_8053C25C;
extern const f32 lbl_8053C260;
extern const f32 lbl_8053C264;
extern const f32 lbl_8053C268;
extern const f32 lbl_8053C26C;
class CLOD_ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

extern "C" void fn_80105654(char* p) {
    v06__5ActorFv(p);
    p[0x325] = -1;
    s32 idx = *(s32*)(p + 0x390);
    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
    if (*(s32*)(p + 0x36c) == 2) {
        pos.y -= lbl_8053C23C;
    }
    s32 id = ((s32*)(p + 0x2f8))[idx];
    if (*(s32*)(p + 0x4) < 8) {
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, id, p + 0x308);
    }
}

extern "C" void fn_80105A34(char* p) {
    v01__5ActorFv(p);
    *(s32*)(p + 0x354) = *(s32*)(p + 0x90) & 0xFF;
    *(s32*)(p + 0x358) = (*(s32*)(p + 0x90) >> 12) & 0x1F;
    *(s32*)(p + 0x36c) = (*(s32*)(p + 0x90) >> 17) & 0x1F;
    *(s32*)(p + 0x364) = (*(s32*)(p + 0x90) >> 22) & 0x1F;
    *(s32*)(p + 0x368) = (*(s32*)(p + 0x90) >> 22) & 0x1F;
    *(u32*)(p + 0x35c) = (u32)*(s32*)(p + 0x90) >> 27;
    s32 off = 0;
    char* q = p;
    for (s32 i = 0; i < 4; i++) {
        *(void**)(q + 0x2f8) = (*(CLOD_ResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x3f3f3f3f, *(const char**)((char*)lbl_8049CBB0 + *(s32*)(p + 0x36c) * 16 + off));
        off += 4;
        q += 4;
    }
    switch (*(s32*)(p + 0x36c)) {
    case 1:
        *(f32*)(p + 0x60) = lbl_8053C250;
        *(f32*)(p + 0x64) = lbl_8053C250;
        *(f32*)(p + 0x68) = lbl_8053C254;
        *(f32*)(p + 0x6c) = lbl_8053C254;
        break;
    case 2:
        *(f32*)(p + 0x60) = lbl_8053C258;
        *(f32*)(p + 0x64) = lbl_8053C25C;
        *(f32*)(p + 0x68) = lbl_8053C260;
        *(f32*)(p + 0x6c) = lbl_8053C264;
        break;
    default:
        *(f32*)(p + 0x60) = lbl_8053C268;
        *(f32*)(p + 0x64) = lbl_8053C268;
        *(f32*)(p + 0x68) = lbl_8053C26C;
        *(f32*)(p + 0x6c) = lbl_8053C26C;
        break;
    }
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x84) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x88) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x8c) = *(f32*)(p + 0x6c);
    fn_801D2608(p + 0x374, &lbl_80539EC0, 1);
    fn_801D22DC(p + 0x374, 0, 2, 0);
    fn_801D1F14(p + 0x374, lbl_8053C228);
}

extern "C" void* fn_80105BEC(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049CBE0;
    *(s32*)(p + 0x318) = -1;
    *(s32*)(p + 0x31c) = -1;
    for (s32 i = 0; (u8)i < 0x10; i += 8) {
        p[(u8)(i + 0) + 0x308] = i + 0;
        p[(u8)(i + 1) + 0x308] = i + 1;
        p[(u8)(i + 2) + 0x308] = i + 2;
        p[(u8)(i + 3) + 0x308] = i + 3;
        p[(u8)(i + 4) + 0x308] = i + 4;
        p[(u8)(i + 5) + 0x308] = i + 5;
        p[(u8)(i + 6) + 0x308] = i + 6;
        p[(u8)(i + 7) + 0x308] = i + 7;
    }
    *(s32*)(p + 0x318) = -1;
    *(s32*)(p + 0x31c) = 0;
    *(s32*)(p + 0x320) = 0;
    p[0x324] = 0;
    p[0x325] = 0;
    p[0x326] = 0;
    p[0x327] = 1;
    p[0x328] = 1;
    p[0x329] = 0;
    p[0x32a] = 0;
    p[0x32b] = 0;
    p[0x32c] = 0;
    p[0x32d] = 0;
    p[0x32e] = 1;
    *(s32*)(p + 0x330) = 3;
    p[0x334] = 1;
    p[0x335] = 0;
    p[0x336] = 0;
    *(s32*)(p + 0x338) = -1;
    *(s32*)(p + 0x33c) = 0;
    *(s32*)(p + 0x340) = 2;
    *(f32*)(p + 0x344) = lbl_8053C228;
    *(f32*)(p + 0x348) = lbl_8053C228;
    *(f32*)(p + 0x34c) = lbl_8053C228;
    *(f32*)(p + 0x350) = lbl_8053C228;
    *(s32*)(p + 0x354) = 0;
    *(s32*)(p + 0x358) = 0;
    *(s32*)(p + 0x35c) = -1;
    *(s32*)(p + 0x360) = 0;
    *(s32*)(p + 0x364) = 0;
    *(s32*)(p + 0x368) = 0;
    *(s32*)(p + 0x36c) = 0;
    *(s32*)(p + 0x370) = 0;
    fn_801D267C(p + 0x374);
    *(s32*)(p + 0x2f8) = 0;
    *(s32*)(p + 0x2fc) = 0;
    *(s32*)(p + 0x300) = 0;
    *(s32*)(p + 0x304) = 0;
    return p;
}

// ---- from Game/fn_80105368_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CBE0[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80105368(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CBE0;
        if (p + 0x374 != 0) {
            if (p + 0x398 != 0) {
                *(void**)(p + 0x398) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8023DE58(s32 arg);
extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_8023B0F4(s32 arg, f32* box, s32 id, s32 flag);
extern "C" void fn_8022DF48(s32 arg);
extern "C" void fn_8022E088(s32 arg, s32 idx, JGeometry::TVec3f* out);
extern const f32 lbl_8053C22C;
extern const f32 lbl_8053C230;
extern "C" s32 fn_801053E8(char* p, s32 arg) {
    if (arg < 0) {
        return 0;
    }
    s32 ret = fn_8023DE58(arg);
    s32 id = *(s32*)(p + 4);
    if (id != ret) {
        return 0;
    }
    f32 box[4];
    box[0] = *(f32*)(p + 0x60);
    box[1] = *(f32*)(p + 0x64);
    box[2] = *(f32*)(p + 0x68);
    box[3] = *(f32*)(p + 0x6c);
    if (*(u8*)(fn_802D6A9C() + id + 0x131df) != 0) {
        box[0] += *(f32*)(p + 0xc);
        box[2] += *(f32*)(p + 0xc);
        box[1] += *(f32*)(p + 0x10);
        box[3] += *(f32*)(p + 0x10);
        box[1] -= lbl_8053C22C;
        if (fn_8023B0F4(arg, box, *(s32*)(p + 4), 0)) {
            fn_8022DF48(arg);
            return 1;
        }
        return 0;
    }
    for (s32 i = 0; i < 8; i++) {
        JGeometry::TVec3f tmp;
        fn_8022E088(arg, i, &tmp);
        tmp -= *(JGeometry::TVec3f*)(p + 0xc);
        tmp.z = lbl_8053C228;
        s32 ang = lbl_8053C230 * JMath::atanTable_.atan2_(tmp.y, tmp.x);
        f32 r = JGeometry::TUtilf::sqrt(tmp.x * tmp.x + tmp.y * tmp.y);
        f32 x = r * JMath::sincosTable_.mTable[(u16)ang >> 5].second;
        f32 y = r * JMath::sincosTable_.mTable[(u16)ang >> 5].first;
        if (x < box[0] && y < box[1] && x < box[2] && y < box[3]) {
            fn_8022DF48(arg);
            return 1;
        }
    }
    return 0;
}

// ---- from Game/dtor_80105D80.cpp

#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CC34[];

extern "C" void* __dt__7AnimSubFv(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        if (p + 0x24 != 0) {
            *(void**)(p + 0x24) = lbl_8049CC34;
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}
