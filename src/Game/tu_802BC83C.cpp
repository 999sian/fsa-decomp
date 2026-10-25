#include "types.h"
#include "Game/Actor.h"

extern "C" void* lbl_8053AC98;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80540BBC;
extern "C" f32 lbl_80540BC0;
extern "C" f32 lbl_80540BC4;
extern "C" f32 lbl_80540BC8;
extern "C" f32 lbl_80540BCC;
extern "C" f32 lbl_8046D3B0[];
extern "C" f32 lbl_8046D3F0[];
extern "C" u8 fn_801F2B7C(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801F2B20(void* p, s32 a);
extern "C" void fn_801F0E34(void* p, u32 a, s32 b);
extern "C" void fn_802A20F0(void* a, void* b, s32 c, s32 d, u32 e, s32 f);
extern "C" void fn_802A381C(void* a, void* b, s32 c, s32 d);
extern "C" void fn_802A3948(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" void fn_8030C210(void* a, void* b);
extern "C" void* fn_801F856C(void);
extern "C" void* Actor_CreateByID(void* mgr, u32 id, s32 room, void* pos, u32 flags, s32 a, s32 b);


extern "C" void* fn_802D6A9C();
extern "C" void fn_802D73CC(void*, u32, s32);
extern "C" void fn_801EE434(void*);
extern "C" char lbl_804A8A50[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_802BC83C(u8* p) {
    struct VObj {
        virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
        virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
        virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
        virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
        virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    };
    ((VObj*)p)->v4C();
    *(u8*)(p + 0x11c) = 0;
    fn_802D73CC(fn_802D6A9C(), *(u32*)(p + 0x26c), 0);
}

extern "C" void fn_802BC88C(u8* p) {
    u8* e = *(u8**)(p + 0x230);
    if (e) {
        *(u32*)(e + 0xf4) |= 1;
        *(s32*)(e + 0x24) = 1;
        *(u8**)(p + 0x230) = 0;
    }
    e = *(u8**)(p + 0x234);
    if (e) {
        *(u32*)(e + 0xf4) |= 1;
        *(s32*)(e + 0x24) = 1;
        *(u8**)(p + 0x234) = 0;
    }
    e = *(u8**)(p + 0x238);
    if (e) {
        *(u32*)(e + 0xf4) |= 1;
        *(s32*)(e + 0x24) = 1;
        *(u8**)(p + 0x238) = 0;
    }
    e = *(u8**)(p + 0x23c);
    if (e) {
        *(u32*)(e + 0xf4) |= 1;
        *(s32*)(e + 0x24) = 1;
        *(u8**)(p + 0x23c) = 0;
    }
}

extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F06F0(void*, char*, s32, s32, s32, f32, f32);
extern "C" char lbl_8046D430[];
extern "C" f32 lbl_80540BB8;
extern "C" void fn_802BC930(u8* p) {
    if (*(s32*)(p + 0x240) != 6) {
        s32 n = *(s32*)(p + 0x4);
        if (n >= 8) {
            fn_803075AC(*(void**)(p + 0x198), n, p + 0xc, (*(s32*)(p + 0x280) >> 1) + 0x109, 0, 2, -1, 0, 0, 0);
        }
    } else {
        fn_801F06F0(p, lbl_8046D430, 0x18e, 0, 0, lbl_80540BB8, lbl_80540BB8);
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 0x4), p + 0xc, 0x18e, 0, 2, -1, 0, 0, 0);
    }
}

extern "C" Actor* fn_802BD1A8(Actor* a, s16 n) {
    if (a) {
        u8* p = (u8*)a;
        *(void**)p = lbl_804A8A50;
        if (*(void**)(p + 0x230)) fn_801EE434(*(void**)(p + 0x230));
        if (*(void**)(p + 0x234)) fn_801EE434(*(void**)(p + 0x234));
        if (*(void**)(p + 0x238)) fn_801EE434(*(void**)(p + 0x238));
        if (*(void**)(p + 0x23c)) fn_801EE434(*(void**)(p + 0x23c));
        fn_802D73CC(fn_802D6A9C(), *(u32*)(p + 0x26c), 0);
        __dt__5ActorFv(a, 0);
        if (n > 0) operator delete(a);
    }
    return a;
}

extern "C" u8 fn_801EE3C0(s32 id);
extern "C" u8 fn_802D7384(void* mgr, u32 v);
extern "C" u16 fn_80226850(void* a, s32 b);
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern void* lbl_8053AAF8;
extern "C" void fn_802BD25C(u8* p) {
    struct Box4 {
        u32 v[4];
    };
    s32 room;
    u8* mgr;
    Box4* src;

    *(u32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 6) & 0xf;
    *(u32*)(p + 0x98) = (*(u32*)(p + 0x90) >> 4) & 3;
    *(s32*)(p + 0x258) = *(u32*)(p + 0x90) & 0xf;
    if (*(s32*)(p + 0x258) == 0xf) {
        *(s32*)(p + 0x258) = -1;
    }
    *(u8*)(p + 0x290) = 0;
    *(s32*)(p + 0x294) = 0;
    *(s32*)(p + 0x27c) = 0;
    *(void**)(p + 0x230) = 0;
    *(void**)(p + 0x234) = 0;
    *(void**)(p + 0x238) = 0;
    *(void**)(p + 0x23c) = 0;

    room = *(s32*)(p + 4);
    mgr = (u8*)fn_802D6A9C();
    src = (Box4*)(room < 8 ? mgr + 0xcc : mgr + 0xdc);
    *(Box4*)(p + 0x25c) = *src;

    *(s32*)(p + 0x270) = (s32)(*(f32*)(p + 0xc) - *(f32*)(p + 0x25c));
    *(s32*)(p + 0x274) = (s32)(*(f32*)(p + 0x10) - *(f32*)(p + 0x260));
    if (*(s32*)(p + 0x270) < 0) {
        *(s32*)(p + 0x270) = 0;
    } else if (*(s32*)(p + 0x270) >= 0x200) {
        *(s32*)(p + 0x270) = 0x1ff;
    }
    if (*(s32*)(p + 0x274) < 0) {
        *(s32*)(p + 0x274) = 0;
    } else if (*(s32*)(p + 0x274) >= 0x200) {
        *(s32*)(p + 0x274) = 0x1ff;
    }
    *(u32*)(p + 0x26c) = ((*(u32*)(p + 0x274) & 0x100) << 1) | (*(u32*)(p + 0x270) & 0x100) | (*(u32*)(p + 0x274) & 0xf0) | ((*(u32*)(p + 0x270) >> 4) & 0xf);

    if (*(s32*)(p + 0x250) != 0 || (*(s32*)(p + 0x250) == 0 && !fn_802D7384(fn_802D6A9C(), *(u32*)(p + 0x26c)))) {
        *(f32*)(p + 0x60) = -6.0f;
        *(f32*)(p + 0x64) = -6.0f;
        *(f32*)(p + 0x68) = 6.0f;
        *(f32*)(p + 0x6c) = 6.0f;
        *(f32*)(p + 0x80) = -8.0f;
        *(f32*)(p + 0x84) = -8.0f;
        *(f32*)(p + 0x88) = 8.0f;
        *(f32*)(p + 0x8c) = 8.0f;
        *(u16*)(p + 0x29c) = fn_80226850(p + 0xc, *(s32*)(p + 4));

        if (*(s32*)(p + 4) < 8) {
            *(s32*)(p + 0x240) = 0;
            if (*(s32*)(p + 0x250) == 3) {
                *(s32*)(p + 0x230) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x19f, 0, 0, 0, 0, 1);
                *(s32*)(p + 0x234) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x1a0, 0, 0, 0, 0, 1);
                *(s32*)(p + 0x238) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x1a1, 0, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.5f, 0x54d, 1, 0, 0, 0, 1);
            } else if (*(s32*)(p + 0x250) != 6) {
                fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x349, 0, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x34a, 0, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x34b, 0, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x54d, 1, 0, 0, 0, 1);
                *(u8*)(p + 0x290) = 1;
                *(s32*)(p + 0x294) = 10;
            }

            if ((*(u32*)(p + 0x90) >> 12 & 0xf) == 0) {
                *(s32*)(p + 0x254) = 0x1e;
            } else {
                *(u32*)(p + 0x254) = (*(u32*)(p + 0x90) >> 12 & 0xf) << 1;
                if (*(s32*)(p + 0x254) < 0x15) {
                    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
                    u32 bits;
                    *s = *s * 0x19660du + 0x3c6ef35fu;
                    bits = (*s >> 9) | 0x3f800000u;
                    *(u32*)(p + 0x27c) = (s32)(1000.88f * (*(f32*)&bits - 1.0f)) & 7;
                }
            }

            *(u8*)(p + 0x278) = 0;
            room = *(s32*)(p + 4);
            mgr = (u8*)fn_802D6A9C();
            if (mgr[room + 0x131df] == 0 && fn_801EE3C0(*(u16*)(p + 0x29c)) == 1) {
                fn_802D73CC(fn_802D6A9C(), *(u32*)(p + 0x26c), 1);
            }
        } else {
            *(s32*)(p + 0x240) = 3;
            *(s32*)(p + 0x280) = 0;
        }
    } else {
        *(u8*)(p + 0x11c) = 0;
    }
}

void fn_802BD69C(void) {}

#include "Game/SinitPoolChain.h"
