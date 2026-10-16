// TU 0x8020c0a8-0x8020cca8 (actor ZASL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern char lbl_8046A3AC[];
extern const f32 lbl_8053F9E8;
extern "C" void fn_801D0ED0(void*);
extern "C" bool fn_801CF144(void*);
extern "C" s32 fn_801CF720(void*, s32);
extern "C" s32 fn_801F6874(s32);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1D60(void*);
extern "C" void detach__5ActorFv(void*);
extern char lbl_8053A178[];

extern "C" void fn_801CE32C(void*);
extern "C" void fn_801CE5D4(void*);
extern "C" u8* fn_802D6A9C(void);
extern "C" bool fn_802265DC(void*, void*, s32);
extern "C" u8* fn_8020D58C(void);
extern "C" bool fn_8020D6AC(void*, void*, void*, u32, void*);
extern "C" char lbl_8053F9E0;

// ---- Zasl_ctor_8020CA34.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A5F40[];

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_8020C0A8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5F40;
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

extern "C" void fn_8020C138(u8* this_) {
    DrawRec rec;
    rec.ids[2] = 4;
    fn_801F06F0(this_, lbl_8046A3AC, *(u32*)(this_ + 0x280) + 0x2c9, &rec, 0, lbl_8053F9E8, lbl_8053F9E8);
}

extern "C" bool fn_8020C26C(void* p, void* a, void* b) {
    bool ret;
    void* l = 0;
    if ((*(u32*)((char*)p + 0x230) & 7) != 0) {
        l = &lbl_8053F9E0;
    }
    ret = true;
    if (!fn_802265DC(b, a, 0)) {
        u32 v = *(u32*)((char*)p + 0x198);
        u8* m = fn_8020D58C();
        if (!fn_8020D6AC(m + m[1] * 0x784 + 4, a, b, v, l)) {
            ret = false;
        }
    }
    return ret;
}

extern "C" void fn_801CE32C(void*);
extern "C" void fn_801CE5D4(void*);
extern "C" u8* fn_802D6A9C(void);
extern "C" bool fn_802265DC(void*, void*, s32);
extern "C" u8* fn_8020D58C(void);
extern "C" bool fn_8020D6AC(void*, void*, void*, u32, void*);
extern "C" char lbl_8053F9E0;
extern "C" void fn_8020C30C(void* p) {
    if ((*(u32*)((char*)p + 0x230) & 7) == 0) {
        fn_801CE32C(p);
    } else {
        s32 off = *(s32*)((char*)p + 4);
        u8* base = fn_802D6A9C();
        if (*(u8*)((u32)base + 0x10000 + off + 0x31df) != 0) {
            fn_801CE5D4(p);
        }
    }
}

extern "C" void fn_8020C374(void* p) {
    char* c = (char*)p;
    s16 a = *(s16*)(c + 0x2ae);
    f32 r = *(f32*)(c + 0x254);
    f32 x = JMASinShort(a) * r;
    f32 y = JMACosShort(a) * r;
    *(f32*)(c + 0x3c) = x;
    *(f32*)(c + 0x40) = y;
    (*(void (**)(void*))(*(char**)p + 0x84))(p);
}

extern "C" s32 fn_8023F264(s32);
extern "C" s32 fn_8022D75C(s32);
extern "C" s32 fn_8022F478(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" f32 fn_801D0DA0(void*, s32, void*);
extern "C" s32 fn_801CD664(s32);
extern const f32 lbl_8053F9F4;
extern const f32 lbl_8053F9F8;
extern "C" void fn_8020C6E8(void* this_) {
    char* p = (char*)this_;
    s32 i;
    s32 best = -1;
    if (*(u32*)(p + 0x230) & 0x2000) {
        f32 min = FLT_MAX;
        for (i = 0; i < 4; i++) {
            if (!(u8)fn_8023F264(i)) {
                continue;
            }
            if ((u8)fn_8022D75C(i)) {
                continue;
            }
            if ((u8)fn_8022F478(i)) {
                continue;
            }
            s32 owner = *(s32*)(p + 4);
            if (fn_8023DE58(i) == owner) {
                f32 d = fn_801D0DA0(this_, i, p + 0xc);
                if (d < min) {
                    min = d;
                    best = i;
                }
            }
        }
    }
    if (*(s32*)(p + 0x248) == 2) {
        if (best < 0) {
            *(s32*)(p + 0x250) = fn_801CD664(0x3d) + 0x28;
            *(f32*)(p + 0x258) = lbl_8053F9F4;
            *(s32*)(p + 0x2a8) = -1;
            *(u8*)(p + 0x2ac) = 0;
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 0;
        } else if (*(u8*)(p + 0x2ac) == 0) {
            if (*(s32*)(p + 0x2a8) != best) {
                *(s32*)(p + 0x2a8) = best;
                *(u8*)(p + 0x2ac) = 0x5a;
            }
        } else {
            *(u8*)(p + 0x2ac) = *(u8*)(p + 0x2ac) - 1;
        }
    } else if (best >= 0) {
        *(s32*)(p + 0x2a8) = best;
        *(u8*)(p + 0x2ac) = 0x5a;
        *(f32*)(p + 0x258) = lbl_8053F9F8;
        *(s32*)(p + 0x24c) = 0;
        *(s32*)(p + 0x248) = 2;
    } else {
        *(u8*)(p + 0x2ac) = 0;
    }
}

extern "C" void fn_8020C878(void* this_) {
    char* p = (char*)this_;
    fn_801D0ED0(this_);
    if (*(u32*)(p + 0x90) & 1) {
        *(u32*)(p + 0x230) |= 0x2000;
    }
    *(s32*)(p + 0xb0) = 0x31101;
    if (*(s32*)(p + 0x98) == 3) {
        if (fn_801CF144(this_)) {
            *(s32*)(p + 0x98) = fn_801CF720(this_, 3);
        }
    }
    *(s16*)(p + 0x2ae) = fn_801F6874(*(s32*)(p + 0x98));
    *(u8*)(p + 0x194) = 1;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    s32 v = fn_801CD664(0x3d) + 0x28;
    f32 f = lbl_8053F9F4;
    *(s32*)(p + 0x250) = v;
    *(f32*)(p + 0x254) = f;
    *(f32*)(p + 0x258) = f;
    fn_801D2608(p + 0x270, lbl_8053A178, 1);
    fn_801D22DC(p + 0x270, 0, 2, 0);
    fn_801D1D60(p + 0x270);
    if (*(u32*)(p + 0x230) & 0x2000) {
        if ((*(u8 (**)(void*, s32, void*))(*(s32*)this_ + 0x4c))(this_, *(s32*)(p + 4), p + 0xc)) {
            detach__5ActorFv(this_);
        } else {
            s32 n = *(s32*)(p + 4);
            u8* base = fn_802D6A9C();
            f32* pf;
            if (n < 8) {
                pf = (f32*)(base + 0xcc);
            } else {
                pf = (f32*)(base + 0xdc);
            }
            f32 x = *(f32*)(p + 0xc);
            f32 y = *(f32*)(p + 0x10);
            bool bVar1 = false;
            if (*(f32*)(p + 0x80) + x < pf[0]) {
                if (*(f32*)(p + 0x84) + y < pf[1]) {
                    if (*(f32*)(p + 0x88) + x < pf[2]) {
                        if (*(f32*)(p + 0x8c) + y < pf[3]) {
                            bVar1 = true;
                        }
                    }
                }
            }
            if (!bVar1) {
                detach__5ActorFv(this_);
            }
        }
    }
}

extern "C" void* fn_8020CA34(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A5F40;
    *(s32*)((char*)this_ + 0x2a8) = -1;
    *(u8*)((char*)this_ + 0x2ac) = 0;
    *(s16*)((char*)this_ + 0x2ae) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
#include "sdk/stl/float.h"
