// TU 0x8021d26c-0x8021d734 (actor EZGE).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- Fbge_ctor_8021D4CC.cpp ----
extern "C" {
void __dt__5ActorFv(void* this_, int flag);
void detach__5ActorFv(void* this_);
u8 fn_801CECF4(void* this_, u32 id, f32 a, f32 b);
void fn_801F0E34(void* this_, u32 a, s32 b);
void fn_801D0ED0(void* this_);
extern u8* lbl_8053AAF8;
}
void operator delete(void* p);
extern void* lbl_804A6660[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct EzgeVtbl {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual bool v11();
};
#define EZGE_V11(p) (((EzgeVtbl*)(p))->v11())

extern "C" void* fn_8021D26C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6660;
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

extern "C" void fn_8021D2FC(void* this_) {
    char* p = (char*)this_;
    if (EZGE_V11(p)) {
        detach__5ActorFv(p);
    } else {
        switch (*(s32*)(p + 0x248)) {
        case 0:
            if (*(u16*)(p + 0x2a8) > 1) {
                (*(u16*)(p + 0x2a8))--;
            } else if (fn_801CECF4(p, 'FBAL', 1.5f, 112.0f)) {
                fn_801F0E34(p, 0x50030, 0);
                *(u16*)(p + 0x2a8) = 120;
            }
            break;
        }
    }
}

extern "C" void fn_8021D3AC(void* this_) {
    char* p = (char*)this_;
    fn_801D0ED0(p);
    if (lbl_8053AAF8[0x7e] != 0) {
        if ((*(u32*)(p + 0x90) >> 1) & 1) {
            *(u8*)(p + 0x11c) = 0;
            return;
        }
    } else if (*(u32*)(p + 0x90) & 1) {
        *(u8*)(p + 0x11c) = 0;
        return;
    }
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
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x250) = -1;
    *(s32*)(p + 0x24c) = 0;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    if (EZGE_V11(p)) {
        detach__5ActorFv(p);
    }
}

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A6660[];

extern "C" void* fn_8021D4CC(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A6660;
    *(s16*)((char*)this_ + 0x2a8) = 120;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
