// TU 0x80213e00-0x80214244 (actor SLEF).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_80213E00_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
void operator delete(void* p);
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
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            operator delete(this_);
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



void InitFloatTriple_0x3c_0x40_0x44(void* thisObj) {
	f32 v = 0.0f;
	*(f32*)((char*)thisObj + 0x3c) = v;
	*(f32*)((char*)thisObj + 0x40) = v;
	*(f32*)((char*)thisObj + 0x44) = v;
}

void EmptyHook_80213EF8(void) {}

extern f32 lbl_8053FB84;
extern f32 lbl_8053FB88;
extern void* lbl_8053A180[2];
void fn_801D0ED0(void* this_);
void fn_801D2608(void* seq, void* table, s32 count);
void fn_801D22DC(void* this_, s32 seqIndex, s32 mode, s32 evalNow);

void fn_80213EFC(void* this_) {
	char* p = (char*)this_;
	fn_801D0ED0(this_);
	*(f32*)(p + 0x60) = 1.0f;
	*(f32*)(p + 0x64) = 1.0f;
	*(f32*)(p + 0x68) = -1.0f;
	*(f32*)(p + 0x6c) = -1.0f;
	*(f32*)(p + 0x70) = *(f32*)(p + 0x60);
	*(f32*)(p + 0x74) = *(f32*)(p + 0x64);
	*(f32*)(p + 0x78) = *(f32*)(p + 0x68);
	*(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
	*(f32*)(p + 0x80) = 1.0f;
	*(f32*)(p + 0x84) = 1.0f;
	*(f32*)(p + 0x88) = -1.0f;
	*(f32*)(p + 0x8c) = -1.0f;
	*(s32*)(p + 0xb0) = 0;
	*(s32*)(p + 0x98) = 2;
	*(u32*)(p + 0x230) |= 0x380;
	*(s32*)(p + 0x108) = 1000;
	*(s32*)(p + 0x244) = *(s32*)(p + 0x108);
	*(u8*)(p + 0x194) = 1;
	*(s32*)(p + 0x248) = 0;
	*(s32*)(p + 0x24c) = 0;
	*(s32*)(p + 0x250) = -1;
	*(f32*)(p + 0x254) = 0.0f;
	*(f32*)(p + 0x258) = 0.0f;
	fn_801D2608(p + 0x270, lbl_8053A180, 1);
	fn_801D22DC(p + 0x270, 0, 2, 0);
}

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
