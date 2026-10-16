#include "JSystem/JGeometry/Vec.h"


extern "C" void __dt__5ActorFv(void* p, int f);
extern void* lbl_804A5B28[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern void* lbl_804A5C88[];
extern void* fn_801F856C();
extern void* fn_801F666C(void*, s32);
extern void fn_8020B434(void*);
extern void fn_8020B3E4(void*, s32, s32, void*, s32);
extern void* fn_80207AC0(void*);
extern f32 lbl_8053F918;
extern f32 lbl_8053F91C;
extern f32 lbl_8053F920;
extern "C" void fn_80209640(void* this_, f32* out);
void operator delete(void* p);
extern "C" void* fn_80208E5C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5C88;
        if (this_ != 0) {
            *(void**)p = lbl_804A5B28;
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

extern "C" void fn_80209164(char* this_) {
    if (*(s32*)(this_ + 0x248) != 3) {
        *(s32*)(this_ + 0x24c) = 0;
        *(s32*)(this_ + 0x248) = 3;
    }
    for (s32 i = 0; i < 4; i++) {
        char* ptr = this_ + i * 0x24;
        void* a = fn_801F666C(fn_801F856C(), *(s32*)(ptr + 0x2b0));
        if (a != 0) {
            fn_8020B3E4(a, *(s32*)(ptr + 0x2b8), *(s32*)(ptr + 0x2bc), ptr + 0x2c0, *(s32*)(ptr + 0x2cc));
        }
    }
}

extern "C" void fn_802091EC(char* this_) {
    if (*(s32*)(this_ + 0x248) != 2) {
        *(s32*)(this_ + 0x24c) = 0;
        *(s32*)(this_ + 0x248) = 2;
    }
    for (s32 i = 0; i < 4; i++) {
        void* a = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2b0 + i * 0x24));
        if (a != 0) {
            fn_8020B434(a);
        }
    }
}

extern "C" void fn_80209264(char* this_) {
    *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x24);
    *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28);
    *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x2c);
}

extern "C" void* fn_802095C4(char* this_) {
    fn_80207AC0(this_);
    s32 zero = 0;
    *(void**)this_ = lbl_804A5C88;
    s32 r0 = (s32)lbl_804A5C88;
    f32 const_val = lbl_8053F918;
    *(s32*)(this_ + 0x340) = zero;
    *(s32*)(this_ + 0x344) = zero;
    *(s32*)(this_ + 0x348) = zero;
    *(s32*)(this_ + 0x34c) = zero;
    *(f32*)(this_ + 0x350) = const_val;
    *(f32*)(this_ + 0x354) = const_val;
    *(s32*)(this_ + 0x358) = zero;
    *(s16*)(this_ + 0x35c) = -0x8000;
    *(s16*)(this_ + 0x35e) = zero;
    *(f32*)(this_ + 0x360) = const_val;
    *(f32*)(this_ + 0x364) = const_val;
    *(f32*)(this_ + 0x368) = const_val;
    *(f32*)(this_ + 0x36c) = const_val;
    return this_;
}

