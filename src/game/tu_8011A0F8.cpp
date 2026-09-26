// tu_8011A0F8: .text 0x8011A0F8-0x8011A4BC
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern "C" void fn_801F5930(void* this_);
extern "C" void fn_801F5938(void* this_);
extern "C" u8* fn_8011921C(void);
extern "C" u8 fn_801186B0(u8* mgr, s32 id);
extern "C" void dtor_801F593C(void* this_, s16 freeFlag);
void operator delete(void* p);
extern void* lbl_8049DAD8[];

class tu_8011A0F8_Actor {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual u8 vf34();
};

extern "C" void fn_8011A0F8(u8* this_) {
    fn_801F5930(this_);
    if (*(u8*)(this_ + 0x239) != 0) {
        return;
    }
    if (*(u8*)(this_ + 0x238) != 0) {
        (*(s32*)(this_ + 0x234))++;
        if (*(s32*)(this_ + 0x234) >= 30) {
            if (*fn_8011921C() != 0) {
                return;
            }
            if (!fn_801186B0(fn_8011921C(), *(s32*)(this_ + 0x230))) {
                return;
            }
            *(u8*)(this_ + 0x239) = 1;
        }
    }
    if ((*(u32*)(this_ + 0x90) & 0xF8000000) != 0) {
        if (((tu_8011A0F8_Actor*)this_)->vf34()) {
            *(u8*)(this_ + 0x238) = 1;
        }
    }
}

extern "C" void fn_8011A1B0(u8* this_) {
    fn_801F5938(this_);
    *(u32*)(this_ + 0x230) = *(u32*)(this_ + 0x90) & 0x1F;
}

extern "C" void* fn_8011A1E8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049DAD8;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_8011A248_ctor.cpp


extern "C" void* fn_801F5AE0(void*);
extern "C" void* fn_8011A248(void* this_) {
    fn_801F5AE0(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_8049DAD8;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(u8*)(p + 0x238) = 0;
    *(u8*)(p + 0x239) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
