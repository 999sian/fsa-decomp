// Game TU 801E6D48-801E7BF4 (IPOT). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_80210AB4(void* this_);
extern void* lbl_804A5418[];
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A61C8[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void fn_80210630(void* this_, s32 flag18, s32 zero1, s32 zero2, s32 extra);
extern "C" void fn_801CDD58(void* this_);
extern "C" void* fn_801E9AFC(void* this_);
extern "C" s32 fn_801EA6D8(void* entryPtr, u32 variant, s32 id);

extern "C" void* fn_801E6D48(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5418;
        if (this_ != 0) {
            *(void**)p = lbl_804A61C8;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                dtor_801F593C(this_, 0);
            }
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801E6F28(void* this_) {
    u32 flags = *(u32*)((char*)this_ + 0x230);
    if (flags & 0x8000) {
        return;
    }
    s32 extra = 0;
    if (*(s32*)((char*)this_ + 0x248) == 2) {
        extra = (s32)*(f32*)((char*)this_ + 0x2a8);
    }
    fn_80210630(this_, (flags >> 13) & 1, 0, 0, extra);
}

extern "C" void fn_801E6F80(void* this_) {
    s32 flags = *(s32*)((char*)this_ + 0x230);
    if (!(flags & 0x8000)) {
        fn_801CDD58(this_);
    }
}

extern "C" void fn_801E773C(void* this_) {
    u32 variant = *(u32*)((char*)this_ + 0x90) >> 24;
    s32 id = *(s32*)((char*)this_ + 0x198);
    void* self = fn_801E9AFC(this_);
    s32 slot = *(unsigned char*)((char*)self + 0xf0);
    void* entryPtr = (char*)self + slot * 0x78;
    *(s32*)((char*)this_ + 0x2ac) = fn_801EA6D8(entryPtr, variant, id);
}

extern "C" void* fn_801E78F0(void* this_) {
    fn_80210AB4(this_);
    *(void**)this_ = lbl_804A5418;
    *(s32*)((char*)this_ + 0x2ac) = -1;
    *(s16*)((char*)this_ + 0x2b0) = 0;
    *(s32*)((char*)this_ + 0x2b4) = 0;
    return this_;
}

extern "C" void* fn_801E7940(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A61C8;
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
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
