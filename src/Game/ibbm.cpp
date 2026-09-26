// TU 0x8020fe50-0x80210630 (actor IBBM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

extern "C" {
void fn_801CDD58();
void fn_801CE120();
void fn_801CE4BC();
void fn_801CE4E4();
void fn_801CE4E8();
void fn_801CE594();
void fn_801CE694();
void fn_801CE914();
void fn_801CE918();
void fn_801CE91C();
void fn_801CE920();
void fn_801CE924();
void fn_801CE928();
void fn_801CE98C();
void fn_801CECEC();
void fn_801D0ECC();
void fn_80210898();
void fn_802108BC();
void v02__5ActorFv();
void v04__5ActorFv();
void v05__5ActorFv();
void v07__5ActorFv();
void v08__5ActorFv();
void v09__5ActorFv();
void v10__5ActorFv();
void v11__5ActorFv();
void v12__5ActorFv();
void v13__5ActorFv();
void v14__5ActorFv();
void v15__5ActorFv();
void v16__5ActorFv();
void v17__5ActorFv();
void v18__5ActorFv();
void* fn_80210314(void* this_, s16 freeFlag);
void fn_802101C0(void* this_);
void fn_8020FE50(void* this_);
s32 fn_8020FF4C(void* this_);
void fn_80210014(void* this_);
void fn_8020FED4(void* this_);
}
void* lbl_804A6100[] = {
    0,
    0,
    (void*)fn_80210314,
    (void*)fn_802101C0,
    (void*)v02__5ActorFv,
    (void*)fn_801CDD58,
    (void*)v04__5ActorFv,
    (void*)v05__5ActorFv,
    (void*)fn_8020FE50,
    (void*)v07__5ActorFv,
    (void*)v08__5ActorFv,
    (void*)v09__5ActorFv,
    (void*)v10__5ActorFv,
    (void*)v11__5ActorFv,
    (void*)v12__5ActorFv,
    (void*)v13__5ActorFv,
    (void*)v14__5ActorFv,
    (void*)v15__5ActorFv,
    (void*)v16__5ActorFv,
    (void*)v17__5ActorFv,
    (void*)v18__5ActorFv,
    (void*)fn_801D0ECC,
    (void*)fn_801CECEC,
    (void*)fn_80210898,
    (void*)fn_8020FF4C,
    (void*)fn_801CE98C,
    (void*)fn_801CE928,
    (void*)fn_801CE924,
    (void*)fn_801CE920,
    (void*)fn_801CE91C,
    (void*)fn_801CE918,
    (void*)fn_801CE914,
    (void*)fn_801CE694,
    (void*)fn_801CE594,
    (void*)fn_801CE4E8,
    (void*)fn_801CE4E4,
    (void*)fn_80210014,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_802108BC,
    (void*)fn_8020FED4,
    0,
};

// ---- IBBM draw / hit / update / init ----
#include "JSystem/JGeometry.h"

struct IbbmRect { f32 x0, y0, x1, y1; };

extern "C" {
extern void* lbl_8053AB10;
extern void* lbl_8053AED0;
void fn_80210630(void* this_, s32 a, s32 b, s32 c, s32 d);
void fn_80210A30(void* this_, IbbmRect* out);
void fn_8030C058(void* dl, IbbmRect* r);
void* fn_801F856C();
s32 fn_801F82CC(void* mgr, void* actor, u8 layer, f32 radius);
void* fn_801F666C(void* base, s32 id);
void fn_801CB538(u32 id, void* pos, u32 a, u32 b);
s32 fn_801CD950(f32* value, f32 target, f32 step);
void fn_80210990(void* this_, s32 dir, IbbmRect* out);
u8 fn_80210A6C(void* this_);
void fn_80341CB0(u32 room, void* pos);
void* fn_802D6A9C(void);
void fn_802D8050(void* mgr, s32 a, s32 b, s32 c);
void detach__5ActorFv(void* this_);
f32 fn_80210AF8(s32 dir);
f32 fn_80210B34(s32 dir);
void fn_8013CB44(void* h, JGeometry::TVec3<f32>* pos, u32 a, u32 b, u32 c);
void fn_801D0ED0(void* this_);
void fn_8043D67C(void* mgr, s32 id, s32 a, s32 b);
void fn_801F0E34(void* this_, s32 p1, s32 p2);
s32 fn_8013CC50(u32 id, void* pos, s32 kind, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e);

void fn_8020FE50(void* this_) {
    char* p = (char*)this_;
    if (((JGeometry::TVec3<f32>*)(p + 0x54))->isZero() == false) {
        s32 frame = 0;
        if (*(s32*)(p + 0x248) == 2) {
            frame = (s32)*(f32*)(p + 0x2a8);
        }
        fn_80210630(this_, 0, 0, 0, frame);
    }
}

void fn_8020FED4(void* this_) {
    char* p = (char*)this_;
    IbbmRect r;
    fn_80210A30(this_, &r);
    r.x0 = r.x0 + *(f32*)(p + 0xc);
    r.y0 = r.y0 + *(f32*)(p + 0x10);
    r.x1 = r.x1 + *(f32*)(p + 0xc);
    r.y1 = r.y1 + *(f32*)(p + 0x10);
    fn_8030C058(*(void**)((char*)lbl_8053AB10 + 0x24), &r);
}

s32 fn_8020FF4C(void* this_) {
    char* p = (char*)this_;
    if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > 0.0f && *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > 0.0f) {
        s32 id = fn_801F82CC(fn_801F856C(), this_, *(u8*)(p + 0x195), 32.0f);
        if (id >= 0 && id != *(s32*)(p + 0x198)) {
            char* other = (char*)fn_801F666C(fn_801F856C(), id);
            if (other != 0) {
                if (*(u32*)(other + 0x1a0) == 'SWBM') {
                    fn_801CB538(*(u32*)(p + 0x4), other + 0xc, 0, 0);
                }
                *(u8*)(other + 0x164) = 1;
            }
        }
    }
    return 0;
}

void fn_80210014(void* this_) {
    char* p = (char*)this_;
    switch (*(s32*)(p + 0x248)) {
    case 0:
        if (*(s32*)(p + 0x24c) >= 0x3c) {
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 1;
        }
        break;
    case 1:
        if (3.0f != *(f32*)(p + 0x54)) {
            fn_801CD950((f32*)(p + 0x54), 3.0f, 0.004f);
            *(f32*)(p + 0x58) = *(f32*)(p + 0x54);
            *(f32*)(p + 0x5c) = *(f32*)(p + 0x54);
            fn_80210990(this_, *(s32*)(p + 0x98), (IbbmRect*)(p + 0x60));
            *(IbbmRect*)(p + 0x70) = *(IbbmRect*)(p + 0x60);
        } else {
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 2;
        }
        break;
    case 2:
        if (fn_80210A6C(this_)) {
            fn_80341CB0(*(u32*)(p + 0x4), p + 0xc);
            s32 flag = *(s32*)(p + 0x2ac);
            if (flag != 0) {
                fn_802D8050(fn_802D6A9C(), flag, 1, 0xff);
            }
            detach__5ActorFv(this_);
        }
        break;
    }
    if (*(u8*)(p + 0x11c)) {
        f32 y = *(f32*)(p + 0x58) * fn_80210AF8(*(s32*)(p + 0x98)) + *(f32*)(p + 0x10);
        f32 x = *(f32*)(p + 0x54) * fn_80210B34(*(s32*)(p + 0x98)) + *(f32*)(p + 0xc);
        JGeometry::TVec3<f32> pos(x, y, 0.0f);
        fn_8013CB44(*(void**)(p + 0x2b4), &pos, 0, 2, 1);
        fn_801F0E34(this_, 0x50026, 0);
    }
}

void fn_802101C0(void* this_) {
    char* p = (char*)this_;
    fn_801D0ED0(this_);
    *(u32*)(p + 0x98) = *(u32*)(p + 0x90) & 3;
    *(u32*)(p + 0x2ac) = (*(u32*)(p + 0x90) >> 2) & 0x1f;
    s32 se = 0x1a8;
    if ((*(u32*)(p + 0x90) >> 7) & 1) {
        se = 0x1c1;
    }
    *(s32*)(p + 0x2b0) = se;
    fn_80210990(this_, *(s32*)(p + 0x98), (IbbmRect*)(p + 0x60));
    *(f32*)(p + 0x80) = 1.0f;
    *(f32*)(p + 0x84) = 1.0f;
    *(f32*)(p + 0x88) = -1.0f;
    *(f32*)(p + 0x8c) = -1.0f;
    *(s32*)(p + 0xb0) = 0x40004;
    *(u32*)(p + 0x230) |= 0x380;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    fn_8043D67C(lbl_8053AED0, *(s32*)(p + 0x2b0), 0, 0);
    f32 y = *(f32*)(p + 0x58) * fn_80210AF8(*(s32*)(p + 0x98)) + *(f32*)(p + 0x10);
    f32 x = *(f32*)(p + 0x54) * fn_80210B34(*(s32*)(p + 0x98)) + *(f32*)(p + 0xc);
    JGeometry::TVec3<f32> pos(x, y, 0.0f);
    *(s32*)(p + 0x2b4) = fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x260, 1.0f, 0, 2, 0, 0, 1);
}
}

// ---- fn_80210314_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6100[];
extern void* lbl_804A61C8[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80210314(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6100;
        fn_801EE434(*(void**)(p + 0x2b4));
        if (this_ != 0) {
            *(void**)p = lbl_804A61C8;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Ibbm_ctor_802103C0.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_80210AB4(void* this_);
extern void* lbl_804A6100[];

extern "C" void* fn_802103C0(void* this_) {
    fn_80210AB4(this_);
    *(void**)this_ = lbl_804A6100;
    *(s32*)((char*)this_ + 0x2ac) = 0;
    *(s32*)((char*)this_ + 0x2b0) = 0;
    *(s32*)((char*)this_ + 0x2b4) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
