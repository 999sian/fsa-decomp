// Game TU 801D8400-801DA7C0 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801D9C58(void* this_, s32 newState);
extern "C" {
}
extern const f32 lbl_8053F1CC;
extern "C" void fn_801CE694(void* this_);
extern "C" void fn_801CE2BC(void* this_);
extern "C" void fn_801E61C4(void* this_);
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
extern void* lbl_8053AF80;
extern "C" s32 fn_80458F9C(void* mgr, s32 handle);

extern "C" void fn_801D8400(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state < 8) {
        fn_801D9C58(this_, 8);
    }
}

extern "C" void fn_801D84E0(void)
{
}

extern "C" void fn_801D8980(void* this_) {
    if (*(f32*)((char*)this_ + 0x10) > *(f32*)((char*)this_ + 0x2d0)) {
        *(f32*)((char*)this_ + 0x10) = *(f32*)((char*)this_ + 0x2d0);
        *(f32*)((char*)this_ + 0x40) = lbl_8053F1CC;
    }
    fn_801CE694(this_);
}

extern "C" void fn_801D89BC(void* this_) {
    u32 flags = *(u32*)((char*)this_ + 0x230);
    if ((flags & 7) == 0) {
        fn_801CE2BC(this_);
    } else {
        s32 state = *(s32*)((char*)this_ + 0x248);
        if (state == 0xf) {
            ((ActorSlot37*)this_)->slot37();
        }
    }
    u16 timer = *(u16*)((char*)this_ + 0x336);
    if (timer != 0) {
        *(u16*)((char*)this_ + 0x336) = timer - 1;
    }
    fn_801E61C4(this_);
}

extern "C" s32 fn_801DA0FC(void) {
    return fn_80458F9C(lbl_8053AF80, 0x3c);
}

#include "JSystem/JGeometry/Vec.h"
extern char* lbl_8053AB10;
extern const f32 lbl_8053F1D0;
extern const f32 lbl_8053F1D4;
extern const f32 lbl_8053F1D8;
extern const f32 lbl_8053F1DC;
extern const f32 lbl_8053F1E0;
extern "C" void fn_801CDD58(void* this_);
extern "C" void fn_8030C210(void* obj, void* pos);
extern "C" void* fn_801D0F40(void* this_);
extern "C" void fn_801DAA24(void* p);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec2_f_Fv();
extern "C" void fn_801EE434(void* handle);
extern "C" s32* fn_801DAC6C();
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7440(void* game, s32 a);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4C58[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct Slot11 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual u8 slot9(f32 a, f32 b, f32 c);
};

extern "C" void fn_801D8430(char* p) {
    if (((Slot11*)p)->slot9(lbl_8053F1CC, lbl_8053F1D0, lbl_8053F1D4)) {
        char* cam = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(cam + 0x840) == 0) {
            *(u8*)(cam + 0x840) = 1;
            *(f32*)(cam + 0x844) = *(f32*)(cam + 0x84c) = *(f32*)(p + 0xc);
            *(f32*)(cam + 0x848) = *(f32*)(cam + 0x850) = *(f32*)(p + 0x10);
            *(f32*)(cam + 0x854) = lbl_8053F1D8;
            *(f32*)(cam + 0x1d4) = lbl_8053F1DC;
            *(f32*)(cam + 0x1d8) = lbl_8053F1DC;
        }
        *(u8*)(*(char**)(lbl_8053AB10 + 0x20) + 0x216) = 1;
    } else {
        fn_801CDD58(p);
    }
}

extern "C" void fn_801D84E4(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0:
        break;
    case 1:
    case 2:
    case 3: {
        char* a = *(char**)(lbl_8053AB10 + 0x30);
        if (*(u8*)(a + 0x284) == 0) {
            *(u8*)(a + 0x284) = 1;
            *(f32*)(a + 0x28c) = lbl_8053F1E0;
        }
        char* cam = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(cam + 0x7f5) == 0) {
            *(u8*)(cam + 0x7f4) = 1;
            *(s32*)(cam + 0x7f8) = 4;
            *(f32*)(cam + 0x7fc) = *(f32*)(p + 0xc);
            *(f32*)(cam + 0x800) = *(f32*)(p + 0x10);
            *(f32*)(cam + 0x804) = *(f32*)(p + 0x14);
            *(u8*)(cam + 0x7f6) = 0;
        }
        break;
    }
    default: {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
        char* cam = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(cam + 0x179) == 0) {
            *(u8*)(cam + 0x178) = 1;
        }
        break;
    }
    }
}

extern "C" void* fn_801DA438(char* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_804A4C58;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x2c0 + i * 4));
            *(void**)(p + 0x2c0 + i * 4) = 0;
        }
        s32* h = fn_801DAC6C();
        *h = -1;
        fn_802D7440(fn_802D6A9C(), 1);
        if (p != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(p, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_801DA504(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A4C58;
    fn_801DAA24(p + 0x2a8);
    *(f32*)(p + 0x2d0) = lbl_8053F1CC;
    __construct_array(p + 0x2d4, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 0xc);
    *(u8*)(p + 0x334) = 0;
    *(u16*)(p + 0x336) = 0;
    *(u16*)(p + 0x338) = 0;
    *(u16*)(p + 0x33a) = 0;
    *(u16*)(p + 0x33c) = 0;
    *(u8*)(p + 0x33e) = 0;
    *(u8*)(p + 0x33f) = 0;
    *(s32*)(p + 0x2c0) = 0;
    *(s32*)(p + 0x2c4) = 0;
    *(s32*)(p + 0x2c8) = 0;
    *(s32*)(p + 0x2cc) = 0;
    return p;
}

extern "C" s32 fn_801DA96C(void* p);
extern "C" void fn_801DA7C0(void* p);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" void fn_801DE12C(void* this_);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);
extern const f32 lbl_8053F1F0;
extern f32 lbl_8053EFB8;

extern "C" void fn_801D882C(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe: {
        JGeometry::TVec2<f32>* tgt = (JGeometry::TVec2<f32>*)(p + 0x2d4) + *(u8*)(p + 0x334);
        JGeometry::TVec2<f32> dir(tgt->x - *(f32*)(p + 0xc), tgt->y - *(f32*)(p + 0x10));
        dir.normalize();
        dir.scale(*(f32*)(p + 0x254));
        fn_801F71A4((f32*)(p + 0x3c), dir.x, lbl_8053F1F0, lbl_8053F1D8);
        fn_801F71A4((f32*)(p + 0x40), dir.y, lbl_8053F1F0, lbl_8053F1D8);
        break;
    }
    default:
        *(f32*)(p + 0x3c) = lbl_8053F1CC;
        switch (*(s32*)(p + 0x248)) {
        case 8:
        case 0x10:
        {
            f32 kick = __fabsf(lbl_8053EFB8);
            f32 vy = *(f32*)(p + 0x40);
            *(f32*)(p + 0x40) = vy + kick;
        }
            break;
        default:
            *(f32*)(p + 0x40) = lbl_8053F1CC;
            break;
        }
        break;
    }
    *(f32*)(p + 0x44) = lbl_8053F1CC;
}

extern "C" void fn_801D8A30(char* p) {
    bool snd = false;
    s32 prev = fn_801DA96C(p + 0x2a8);
    fn_801DA7C0(p + 0x2a8);
    switch (*(s32*)(p + 0x2a8)) {
    case 8:
        if (prev != 0x1e && fn_801DA96C(p + 0x2a8) == 0x1e) {
            snd = true;
        }
        break;
    case 0xe:
        if (prev != 0x2c && fn_801DA96C(p + 0x2a8) == 0x2c) {
            snd = true;
        }
        break;
    case 0xf:
        if (prev != 0x2f && fn_801DA96C(p + 0x2a8) == 0x2f) {
            snd = true;
        }
        break;
    }
    if (snd) {
        fn_801F0E34(p, 0x40058, 0);
    }
    fn_801DE12C(p);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
