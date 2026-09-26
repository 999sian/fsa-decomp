// TU 0x80210d90-0x80212ac0 (actor RUSA).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- fn_80212760_dtor.cpp ----
extern "C" void* RusaRegistry_GetOrInit();
extern "C" void RusaRegistry_Unregister(void* registry, s32 id);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6270[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80212760(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6270;
        void* registry = RusaRegistry_GetOrInit();
        RusaRegistry_Unregister(registry, *(s32*)(p + 0x198));
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
            dtor_80084580(this_);
        }
    }
    return this_;
}


extern const f32 lbl_8053FAF8;
extern const f32 lbl_8053FAFC;
extern const f32 lbl_8053FB00;
extern const f32 lbl_8053FB14;
extern void* lbl_804A6270[];
extern "C" void fn_802110A8(char* p);
extern "C" void fn_801D0F40(char* p);
extern "C" void fn_800FE3EC(char* a, u8 b, JGeometry::TVec3f pos, void* c);

extern "C" BOOL fn_80211000(char* p, const f32* v) {
    BOOL r = FALSE;
    if (v[2] <= lbl_8053FAF8 && *(s32*)(p + 0x248) != 0) {
        f32 rad = lbl_8053FAFC * (lbl_8053FB00 * *(f32*)(p + 0x54));
        f32 dx = v[0] - *(f32*)(p + 0xc);
        f32 dy = v[1] - *(f32*)(p + 0x10);
        f32 dx2 = dx * dx;
        f32 dy2 = dy * dy;
        f32 r2 = rad * rad;
        if (dx2 + dy2 <= r2) {
            r = TRUE;
        }
    }
    return r;
}

extern "C" void fn_80211078(char* p) {
    f32 z = lbl_8053FAF8;
    *(f32*)(p + 0x3c) = z;
    *(f32*)(p + 0x40) = z;
    *(f32*)(p + 0x44) = z;
    fn_802110A8(p);
}

extern "C" void fn_80212170(char* p) {
    if ((*(u32*)(p + 0x230) & 0x8000) && *(u8*)(p + 0x2bc) != 0) {
        fn_800FE3EC(p + 0x2c0, *(u8*)(p + 0x2bc), *(JGeometry::TVec3f*)(p + 0xc), *(void**)(p + 0x4));
    }
}

extern "C" char* fn_80212800(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A6270;
    *(s32*)(p + 0x2a8) = 0;
    *(s32*)(p + 0x2ac) = 0;
    *(s32*)(p + 0x2b0) = 0;
    *(s32*)(p + 0x2b4) = 0;
    *(s32*)(p + 0x2b8) = 0;
    *(u8*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x388) = -1;
    *(s32*)(p + 0x38c) = -1;
    *(f32*)(p + 0x390) = lbl_8053FAF8;
    *(f32*)(p + 0x394) = lbl_8053FAF8;
    *(f32*)(p + 0x398) = lbl_8053FAF8;
    *(f32*)(p + 0x39c) = lbl_8053FAF8;
    *(f32*)(p + 0x3a0) = lbl_8053FAF8;
    *(f32*)(p + 0x3a4) = lbl_8053FAF8;
    *(f32*)(p + 0x3a8) = lbl_8053FB14;
    *(s32*)(p + 0x3ac) = -1;
    *(u8*)(p + 0x3b0) = 0;
    *(u8*)(p + 0x2c2) = 0;
    *(u8*)(p + 0x2c3) = 0;
    *(u8*)(p + 0x2c1) = 0;
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
