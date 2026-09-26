// TU 0x802201d8-0x802205e0 (actor FBAL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

struct GXColor_FBAL {
    GXColor_FBAL(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};

extern "C" {
extern void* lbl_8053AB10;
void fn_80158B5C(void* mgr, u32 id, void* pos, GXColor_FBAL color, f32 size);
void fn_801D2E70(void* this_);
void fn_801D2FEC(void* this_);
void fn_8013CB44(s32 handle, void* pos, s32 a, s32 b, s32 c);
s32 fn_8013CC50(u32 id, void* pos, s32 kind, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e);
void fn_801EE434(s32 handle);
void __dt__5ActorFv(void* this_, int flag);
}
void operator delete(void* p);
extern void* lbl_804A6828[];
extern void* lbl_804A48B0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct FBAL_Mgr { u8 pad[0x2c]; void* mShadow; };
extern "C" void fn_802201D8(void* this_) {
    u32 id = *(u32*)((char*)this_ + 0x4);
    GXColor_FBAL c(0, 0, 0, 0x80);
    fn_80158B5C(((FBAL_Mgr*)lbl_8053AB10)->mShadow, id, (char*)this_ + 0xc, c, 24.0f);
}

extern "C" void fn_80220230(void* this_) {
    char* p = (char*)this_;
    fn_801D2E70(this_);
    fn_8013CB44(*(s32*)(p + 0x2ac), p + 0xc, 0, 0, 1);
}

extern "C" void fn_80220274(void* this_) {
    char* p = (char*)this_;
    fn_801D2FEC(this_);
    *(s32*)(p + 0x2ac) = fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, 0x290, 1.0f, 0, 0, 0, 0, 1);
}

extern "C" void* fn_802202CC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6828;
        fn_801EE434(*(s32*)(p + 0x2ac));
        if (this_ != 0) {
            *(void**)p = lbl_804A48B0;
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
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Fbal_ctor_80220378.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D30B8(void* this_);
extern void* lbl_804A6828[];

extern "C" void* fn_80220378(void* this_) {
    fn_801D30B8(this_);
    *(void**)this_ = lbl_804A6828;
    *(s32*)((char*)this_ + 0x2ac) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
