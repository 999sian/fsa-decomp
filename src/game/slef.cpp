// TU 0x80213e00-0x80214244 (actor SLEF).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_80213E00_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A6400[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80213E00(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6400;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            dtor_801F593C(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Slef_Draw_80213E90.cpp ----
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* posPtr, s32 effectRef,
                             s32 unused, s32 mode, s32 targetPlayerIdx, s32 kind,
                             s32 stackArg9, s32 stackArg10);

extern "C" void fn_80213E90(void* this_) {
    fn_803075AC(*(u32*)((char*)this_ + 0x198), *(u32*)((char*)this_ + 0x4),
                 (char*)this_ + 0xc, *(s32*)((char*)this_ + 0x280) + 0x1c3,
                 0, 1, -1, 1, 0, 0);
}

// ---- InitFloatTriple_0x3c_0x40_0x44.cpp ----
// InitFloatTriple_0x3c_0x40_0x44 - loads the float global lbl_8053FB80
// ONCE and stores it into 3 fields (this->0x3c/0x40/0x44).
// EmptyHook_80213EF8 - empty stub.
extern "C" {

extern f32 lbl_8053FB80;

void InitFloatTriple_0x3c_0x40_0x44(void* thisObj) {
	f32 v = lbl_8053FB80;
	*(f32*)((char*)thisObj + 0x3c) = v;
	*(f32*)((char*)thisObj + 0x40) = v;
	*(f32*)((char*)thisObj + 0x44) = v;
}

void EmptyHook_80213EF8(void) {}

}

// ---- Slef_ctor_80213FE4.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A6400[];

extern "C" void* fn_80213FE4(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A6400;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
