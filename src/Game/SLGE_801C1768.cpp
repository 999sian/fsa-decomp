#include "types.h"
#include "Game/ItemBase.h"

extern "C" char lbl_804A4310[];
extern "C" char lbl_804A4808[];
extern "C" char lbl_8049CC34[];
extern "C" void fn_801EE434(void* p);
extern "C" void fn_8021FAB8(u8* p, s32 n);
extern "C" void __dt__5ActorFv(u8* this_, s32 flags);
extern "C" void __dl__FPv(void* p);

extern "C" s32 fn_801CD664(s32 n);
extern "C" u32 fn_801C5660(s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_801C26D8(void);
extern "C" u16 lbl_80469424[];
extern "C" u16 lbl_8053EDB8;
extern "C" f32 lbl_8053EDC0;
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" void fn_801C1768(u8* this_) {
    u16* kind = lbl_80469424;
    void** p = (void**)this_;
    for (s32 i = 0; i < 5; i++, p++, kind++) {
        p[0xb0] = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, *kind, 0, 0, 0, 0, 1, lbl_8053EDC0);
    }
    for (s32 i = 0; i < 4; i++) {
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, (&lbl_8053EDB8)[i], 0, 0, 0, 0, 1, lbl_8053EDC0);
    }
    fn_801EE434(*(void**)(this_ + 0x2b0));
    *(void**)(this_ + 0x2b0) = 0;
    fn_801F0E34(this_, 0x50049, 0);
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = 4;
}

extern "C" void fn_801C186C(u8* p)
{
    u32 mgr;
    s32 diff = p[0x2a9] - p[0x2a8];
    u8 lo = p[0x2a8];
    s32 i;

    for (i = 0; i < 4; i++) {
        s32 n = fn_801CD664(diff + 1);
        mgr = fn_801C5660(8, 0, lo + n, 0, 0);
        s32 id = Actor_CreateByID(fn_801F856C(), 0x534c4b32, *(u32*)(p + 4), (f32*)(p + 0xc), mgr, -1, -1);
        if (id >= 0) {
            if (fn_801F666C(fn_801F856C(), id) != 0) {
                fn_801C26D8();
            }
        }
    }
}

extern "C" void* fn_801C231C(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A4310;
        fn_801EE434(*(void**)(this_ + 0x2b0));
        for (s32 i = 0; i < 3; i++) {
            fn_801EE434(*(void**)(this_ + 0x2b4 + i * 4));
        }
        for (s32 i = 0; i < 5; i++) {
            fn_801EE434(*(void**)(this_ + 0x2c0 + i * 4));
        }
        fn_8021FAB8(this_ + 0x3f8, -1);
        if (this_ != 0) {
            *(void**)this_ = lbl_804A4808;
            if (this_ + 0x270 != 0) {
                if (this_ + 0x294 != 0) {
                    *(void**)(this_ + 0x294) = lbl_8049CC34;
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

extern "C" void fn_801D0F40(u8* this_);
extern "C" u8* fn_8021C5B0(u8* this_);
extern "C" void fn_8021FB44(char* p);
extern "C" void __construct_array(void* p, void* ctor, void* dtor, int size, int n);
extern "C" char lbl_804A4310[];
extern "C" u8* fn_801C2414(u8* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4310;
    *(u8*)(this_ + 0x2a8) = 0;
    *(u8*)(this_ + 0x2a9) = 0;
    *(s16*)(this_ + 0x2aa) = 0;
    *(s16*)(this_ + 0x2ac) = 0;
    *(s32*)(this_ + 0x2b0) = 0;
    *(s32*)(this_ + 0x2d4) = 0;
    __construct_array(this_ + 0x2d8, (void*)fn_8021C5B0, 0, 0x48, 4);
    fn_8021FB44((char*)(this_ + 0x3f8));
    *(s32*)(this_ + 0x2b4) = 0;
    *(s32*)(this_ + 0x2b8) = 0;
    *(s32*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x2c0) = 0;
    *(s32*)(this_ + 0x2c4) = 0;
    *(s32*)(this_ + 0x2c8) = 0;
    *(s32*)(this_ + 0x2cc) = 0;
    *(s32*)(this_ + 0x2d0) = 0;
    return this_;
}

