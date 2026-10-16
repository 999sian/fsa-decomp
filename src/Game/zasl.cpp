// TU 0x8020c0a8-0x8020cca8 (actor ZASL).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern void* lbl_8046A3AC;
extern const f32 lbl_8053F9E8;

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
