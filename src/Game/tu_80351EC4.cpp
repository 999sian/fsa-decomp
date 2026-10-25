#include "types.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

extern void* lbl_804ACB40[];

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" const f32 lbl_80542684;
extern "C" const f32 lbl_80542688;

extern "C" void* fn_80351EC4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804ACB40;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80351F24(void) {}

extern u8* lbl_8053AB10;
extern u8* lbl_8053AD78;
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* pool, u32 type, s32 afterId);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" char* fn_802D6A9C(void);
extern "C" bool fn_802D800C(char* p, s32 bit);
extern "C" void fn_8030C058(void* a, void* b);
extern "C" void* fn_80204638(void);
extern f32 lbl_80542680;
extern "C" void fn_80351F28(char* p) {
    s32 id;
    char* actor;
    u8 bVar1;

    *(s32*)(p + 0x238) = 0;
    id = -1;
    do {
        do {
            id = fn_801F78F4(fn_801F856C(), 0x545a4f4b, id);
            if (id < 0) {
                goto done;
            }
            actor = (char*)fn_801F666C(fn_801F856C(), id);
        } while (actor == NULL);
        bVar1 = 0;
        if (*(s32*)(p + 4) == *(s32*)(actor + 4) &&
            (*(f32*)(actor + 0x14) < lbl_80542680 || *(s32*)(actor + 0xd8) > 0) && *(u8*)(actor + 0xc4) == 0 &&
            *(f32*)(actor + 0xc) >= *(f32*)(p + 0x240) && *(f32*)(actor + 0x10) >= *(f32*)(p + 0x244) &&
            *(f32*)(actor + 0xc) < *(f32*)(p + 0x248) && *(f32*)(actor + 0x10) < *(f32*)(p + 0x24c))
        {
            bVar1 = 1;
        }
        if (bVar1 == 1 && !fn_802D800C(fn_802D6A9C(), *(s32*)(p + 0x23c))) {
            *(s16*)(actor + 0x94) = 1;
            *(s32*)(p + 0x238) = *(s32*)(p + 0x238) + 1;
            continue;
        }
        *(s16*)(actor + 0x94) = 0;
    } while (true);

done:
    *(s32*)(lbl_8053AD78 + 0x10c) = *(s32*)(p + 0x234) - *(s32*)(p + 0x238);
    if (*(s32*)(p + 0x238) > 0) {
        fn_8030C058(*(void**)(lbl_8053AB10 + 0x24), p + 0x240);
    }
    bVar1 = *(s32*)(p + 0x238) >= *(s32*)(p + 0x234);
    if (bVar1 == 1 && !((u8 (*)(char*))(*(void***)p)[13])(p)) {
        ((void (*)(char*, s32, s32))(*(void***)p)[12])(p, 0xff, 1);
    }
    *(u8*)fn_80204638() = 1;
    if (*(s32*)(p + 0x23c) > 0 && fn_802D800C(fn_802D6A9C(), *(s32*)(p + 0x23c))) {
        if (((u8 (*)(char*))(*(void***)p)[13])(p) == 1) {
            ((void (*)(char*, s32, s32))(*(void***)p)[12])(p, 0xff, 0);
        }
    }
}

extern "C" void fn_80352160(void* this_) {
    u8* p = (u8*)this_;
    f32 zero = lbl_80542688;
    f32 scale = lbl_80542684;
    u32 w = *(u32*)(p + 0x90);
    *(u32*)(p + 0x234) = w & 0xff;
    *(u32*)(p + 0x23c) = (w >> 0x16) & 0x1f;
    *(u32*)(p + 0x238) = 0;
    *(f32*)(p + 0xc) = scale * (f32)((s32)*(f32*)(p + 0xc) / 16);
    *(f32*)(p + 0x10) = scale * (f32)((s32)*(f32*)(p + 0x10) / 16);
    *(f32*)(p + 0x60) = zero;
    *(f32*)(p + 0x64) = zero;
    w = *(u32*)(p + 0x90);
    *(f32*)(p + 0x68) = (f32)((w >> 5) & 0x1f8);
    *(f32*)(p + 0x6c) = (f32)((w >> 13) & 0x1f8);
    *(u32*)(p + 0x240) = *(u32*)(p + 0x60);
    *(u32*)(p + 0x244) = *(u32*)(p + 0x64);
    *(u32*)(p + 0x248) = *(u32*)(p + 0x68);
    *(u32*)(p + 0x24c) = *(u32*)(p + 0x6c);
    *(f32*)(p + 0x240) = *(f32*)(p + 0x240) + *(f32*)(p + 0xc);
    *(f32*)(p + 0x244) = *(f32*)(p + 0x244) + *(f32*)(p + 0x10);
    *(f32*)(p + 0x248) = *(f32*)(p + 0x248) + *(f32*)(p + 0xc);
    *(f32*)(p + 0x24c) = *(f32*)(p + 0x24c) + *(f32*)(p + 0x10);
}

void fn_803522A4(void) {}

