// TU 0x802233a4-0x802242f4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_80223534.cpp ----
extern "C" void fn_80221184(void* this_);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);
extern "C" void* fn_801EE434(void* handle);

extern "C" void fn_80223534(void* this_) {
    fn_80221184(this_);
    char* p = (char*)this_;
    if (*(u32*)(p + 0x2b8) != 0) {
        void* base = fn_8013C824();
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)base + 0xc), *(s32*)(p + 0x2b8));
        *(s32*)(p + 0x2b8) = 0;
    }
    fn_801CDC8C(this_, 0x4000E);
    fn_801EE434(*(void**)(p + 0x2bc));
    fn_801EE434(*(void**)(p + 0x2c0));
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2c0) = 0;
}

// ---- fn_80223F90_dtor.cpp ----
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6D00[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80223F90(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6D00;
        if (*(u32*)(p + 0x2b8) != 0) {
            void* base = fn_8013C824();
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)base + 0xc), *(s32*)(p + 0x2b8));
            *(s32*)(p + 0x2b8) = 0;
        }
        fn_801CDC8C(this_, 0x4000E);
        fn_801EE434(*(void**)(p + 0x2bc));
        fn_801EE434(*(void**)(p + 0x2c0));
        *(s32*)(p + 0x2bc) = 0;
        *(s32*)(p + 0x2c0) = 0;
        if (this_ != 0) {
            *(void**)p = lbl_804A6A00;
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

// ---- fn_80224084_ctor.cpp ----
extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6D00[];

extern "C" void* fn_80224084(void* this_) {
    fn_802218C8(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A6D00;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2c0) = 0;
    return this_;
}


// ---- fn_802233A4 / fn_802235B0 / fn_80223608 / fn_80223F14 ----
extern "C" {
extern f32 lbl_8053EFB8;
s32 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
void fn_80221250(void* this_);
void fn_801CE4E8(void* this_);
void fn_80221210(void* this_);
void fn_8013CB44(void* h, void* pos, u32 a, u32 b, u32 c);
void fn_802217C8(void* this_);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);

struct Rect_802233A4 {
    Rect_802233A4() {}
    Rect_802233A4(f32 a, f32 b, f32 c, f32 d) { x0 = a; y0 = b; x1 = c; y1 = d; }
    void set(f32 a, f32 b, f32 c, f32 d) { x0 = a; y0 = b; x1 = c; y1 = d; }
    void add(f32 dx, f32 dy) { x0 += dx; y0 += dy; x1 += dx; y1 += dy; }
    bool isValid() const { return x1 - x0 > 0.0f && y1 - y0 > 0.0f; }
    f32 x0, y0, x1, y1;
};

s32 fn_802233A4(void* this_) {
    char* p = (char*)this_;
    s32 ret = 0;
    Rect_802233A4 r(1.0f, 1.0f, -1.0f, -1.0f);
    if (*(s32*)(p + 0x248) == 5) {
        r.set(-8.0f, -8.0f, 8.0f, 8.0f);
        switch (*(s32*)(p + 0x98)) {
        case 0:
            r.add(16.0f, 0.0f);
            break;
        case 1:
            r.add(-16.0f, 0.0f);
            break;
        case 2:
            r.add(0.0f, 16.0f);
            break;
        case 3:
            r.add(0.0f, -16.0f);
            break;
        }
    }
    if (r.x1 - r.x0 > 0.0f && r.y1 - r.y0 > 0.0f) {
        Rect_802233A4 save = *(Rect_802233A4*)(p + 0x60);
        *(Rect_802233A4*)(p + 0x60) = r;
        ret = fn_801F2B7C(this_, *(s32*)(p + 0x114), -1, 1);
        *(Rect_802233A4*)(p + 0x60) = save;
    }
    return ret;
}

void fn_802235B0(void* this_) {
    char* p = (char*)this_;
    switch (*(s32*)(p + 0x248)) {
    case 2:
        fn_80221250(this_);
        break;
    case 6:
        *(f32*)(p + 0x44) += lbl_8053EFB8;
        break;
    default:
        fn_801CE4E8(this_);
        break;
    }
}

void fn_80223608(void* this_) {
    char* p = (char*)this_;
    fn_80221210(this_);
    fn_8013CB44(*(void**)(p + 0x2bc), p + 0xc, 0, 0, 1);
    fn_8013CB44(*(void**)(p + 0x2c0), p + 0xc, 0, 0, 1);
}

void fn_80223F14(void* this_) {
    char* p = (char*)this_;
    fn_802217C8(this_);
    *(u32*)(p + 0x98) = *(u32*)(p + 0x90) & 3;
    *(u32*)(p + 0x230) &= ~0x100;
    *(s32*)(p + 0x248) = 4;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    fn_801D22DC(p + 0x270, 2, 0, 0);
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
