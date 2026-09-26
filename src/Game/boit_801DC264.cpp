// Game TU 801DC264-801DCC98 (BOIT). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" {
}
extern f32 lbl_8053F344;
extern f32 lbl_8053EFB8;
extern "C" void fn_801CE2BC(void* this_);
struct ActorSlot37 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void slot37();
};
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void* fn_801DAC6C(void);
extern void* lbl_804A4F90[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);

extern "C" u8 fn_801DC264(void* thisPtr)
{
    char* t = (char*)thisPtr;
    s32 total;
    u8 result = 0;
    if (*(s32*)(t + 0x278) == 1) {
        total = *(s32*)(t + 0xdc);
        s32 elapsed = *(s32*)(t + 0xd8);
        s32 remain = total - 25;
        if (elapsed > remain || total < 25) {
            if (total < 25) {
                result = (u8)(elapsed * 255 / total);
            } else {
                result = (u8)((elapsed - remain) * 255 / 25);
            }
        }
    }
    return result;
}

extern "C" void fn_801DC758(void* thisPtr)
{
    f32 zero = lbl_8053F344;
    *(f32*)((char*)thisPtr + 0x3c) = zero;
    *(f32*)((char*)thisPtr + 0x44) = zero;
    if (*(s32*)((char*)thisPtr + 0x248) == 2) {
        f32 kick = __fabsf(lbl_8053EFB8);
        f32 vy = *(f32*)((char*)thisPtr + 0x40);
        *(f32*)((char*)thisPtr + 0x40) = vy + kick;
    } else {
        *(f32*)((char*)thisPtr + 0x40) = zero;
    }
}

extern "C" void fn_801DC790(void* this_) {
    u32 flags = *(u32*)((char*)this_ + 0x230);
    if ((flags & 7) == 0) {
        fn_801CE2BC(this_);
    } else {
        ((ActorSlot37*)this_)->slot37();
    }
}

extern "C" void* fn_801DC990(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4F90;
        void* singleton = fn_801DAC6C();
        *(s32*)((char*)singleton + 0x4) = -1;
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
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801DCA30(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4F90;
    *(u8*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
