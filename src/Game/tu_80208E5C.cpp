#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"


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

extern "C" void fn_80208EFC(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 2:
    case 3: {
        f32 zero = lbl_8053F918;
        *(f32*)(this_ + 0x3c) = zero;
        *(f32*)(this_ + 0x40) = zero;
        *(f32*)(this_ + 0x44) = zero;
        break;
    }
    case 1: {
        f32 pos[2];
        if (*(s32*)(this_ + 0x344) == 0) {
            fn_80209640(this_ + 0x34c, pos);
            *(f32*)(this_ + 0x3c) = pos[0];
            *(f32*)(this_ + 0x40) = pos[1];
            *(f32*)(this_ + 0x44) = lbl_8053F918;
        } else if (*(s32*)(this_ + 0x340) == 0) {
            *(f32*)(this_ + 0x3c) = lbl_8053F91C;
            *(f32*)(this_ + 0x40) = lbl_8053F918;
            *(f32*)(this_ + 0x44) = lbl_8053F918;
        } else {
            *(f32*)(this_ + 0x3c) = lbl_8053F920;
            *(f32*)(this_ + 0x40) = lbl_8053F918;
            *(f32*)(this_ + 0x44) = lbl_8053F918;
        }
        s32 i = 0;
        char* e = this_;
        do {
            char* actor = (char*)fn_801F666C(fn_801F856C(), *(s32*)(e + 0x2b0));
            if (actor != 0) {
                *(f64*)(actor + 0x3c) = *(f64*)(this_ + 0x3c);
                *(f32*)(actor + 0x44) = *(f32*)(this_ + 0x44);
            }
            i++;
            e += 0x24;
        } while (i < 4);
        break;
    }
    }
}

extern void fn_80207A60(void* this_);
extern void* fn_802D6A9C();
extern void fn_8020B500(void* p);
extern f32 lbl_8053F924;
extern "C" void fn_80207A60(void* this_);
extern "C" void* fn_802D6A9C();
extern "C" void fn_8020B500(void* p);
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_80209014(char* this_) {
    fn_80207A60(this_);
    switch (*(s32*)(this_ + 0x248)) {
    case 0: {
        if ((*(s32*)(this_ + 0x348) == 0 && *(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) ||
            (*(u8 (**)(void*))(*(s32*)this_ + 0x34))(this_)) {
            s32 i = 0;
            char* p = this_;
            while (i < 4) {
                void* a = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x2b0));
                if (a != 0) {
                    fn_8020B500(a);
                }
                i++;
                p += 0x24;
            }
            *(s32*)(this_ + 0x24c) = 0;
            *(s32*)(this_ + 0x248) = 1;
        }
    } break;
    case 1: {
        s32 i = *(s32*)(this_ + 0x4);
        char* p = (char*)fn_802D6A9C();
        f32* pf;
        if (i < 8) {
            pf = (f32*)(p + 0xcc);
        } else {
            pf = (f32*)(p + 0xdc);
        }
        if (*(f32*)(this_ + 0xc) < *pf - lbl_8053F924 || *(f32*)(this_ + 0xc) > lbl_8053F924 + pf[2]) {
            *(u8*)(this_ + 0x11c) = 0;
            for (s32 j = 0; j < 4; j++) {
                void* a = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2b0));
                if (a != 0) {
                    *(u8*)((char*)a + 0x11c) = 0;
                }
                this_ += 0x24;
            }
        }
    } break;
    }
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


