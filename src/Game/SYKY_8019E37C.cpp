#include "types.h"
#include "Game/ItemBase.h"

extern "C" void fn_80458880(void*, s32, s32);
extern const f32 lbl_8053E4A4;
extern const f32 lbl_8053E4A8;
extern void* lbl_8053AF80;
extern "C" void fn_801F02BC(void* p, f32 a, f32 b, const char* s, s32 x, s32 y, s32 z, s32 w, s32 v);
extern "C" u8 fn_8022F478(s32 i);
extern "C" s32 fn_8022F340(u32 p);
extern "C" void fn_8019E480(u8* p);
extern "C" void fn_8019E7A4(u8* p);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern const f32 lbl_8053E464;
extern const char lbl_80468494[];
extern s32 lbl_804C6330[];
extern u8 lbl_8053ABB8[];
struct SykyVT { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual u8 v11(); virtual u8 v12(); };
extern void* lbl_8053AF10;
extern const f32 lbl_8053E460;
extern const f32 lbl_8053E46C;
extern const f32 lbl_8053E474;
extern const f32 lbl_8053E48C;
extern const f32 lbl_8053E490;
extern const f32 lbl_8053E494;
extern const f32 lbl_8053E498;
extern const f32 lbl_8053E49C;
extern const f32 lbl_8053E4A0;
extern "C" void fn_801F71A4(void* p, f32 a, f32 b, f32 c);
extern const char lbl_80468480[];
extern "C" void fn_8019E37C(u8* p) {
    s32 state = *(s32*)(p + 0x268);
    switch (state) {
    case 0: {
        s32 i;
        fn_801F02BC(p, lbl_8053E460, lbl_8053E460, lbl_80468480, *(s32*)(p + 0x264) + 0x1ab, 0, 0, 0, 0);
        if (p[0x28c] != 0) {
            for (i = 0; i < 4; i++) {
                if (!fn_8022F478(i)) {
                    s32 idx = fn_8022F340(i);
                    ((u8*)lbl_8053AF10)[0x2c] |= (u8)(1 << idx);
                    ((u8*)lbl_8053AF10)[idx + 0x28] = (u8)(10 - lbl_804C6330[idx]);
                }
            }
        }
        break;
    }
    case 1:
    case 2:
    case 4:
        fn_8019E480(p);
        break;
    case 3:
        fn_8019E7A4(p);
        break;
    }
}

extern "C" void fn_8019E7A4(u8* p) {
    DrawRec rec;
    f32 vec[4][3];
    f32 zero = lbl_8053E464;
    vec[1][0] = zero;
    vec[2][1] = zero;
    vec[3][2] = zero;
    f32 s = *(f32*)(p + 0x290);
    vec[0][0] = s;
    vec[0][1] = zero;
    vec[0][2] = zero;
    vec[1][1] = zero;
    vec[1][2] = s;
    vec[2][0] = zero;
    vec[2][2] = zero;
    vec[3][0] = zero;
    vec[3][1] = s;
    rec.w18 = vec;
    fn_801F06F0(p, lbl_80468494, *(s32*)(p + 0x264) + 8, &rec, 0, lbl_8053E460, lbl_8053E460);
}

extern "C" void fn_8019EE04(u8* p) {
    if (*(s32*)(p + 0x268) == 3 && *(s32*)(p + 0x230) != 0xf) {
        *(f32*)(p + 0x290) = lbl_8053E4A4;
        *(f32*)(p + 0x10) -= lbl_8053E4A8;
        fn_80458880(lbl_8053AF80, 6, -1);
        *(s32*)(p + 0x230) = 0xf;
    }
}

extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_8022B17C(void);
extern "C" void fn_80138B7C(void* p);
extern "C" void fn_80458508(void* p, s32 x);
extern "C" u8 fn_8022F514(s32 i);
extern "C" void fn_802372F8(s32 i, s32 a, s32 b);
extern void* lbl_804A2B18[];
extern void* lbl_8053AAF8;
extern "C" void* fn_801A024C(u8* this_, s16 freeFlag) {
    s32 i;
    u8* cur;
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2B18;
        if (*(s32*)(this_ + 0x268) == 0) {
            s32 state = *(s32*)(this_ + 0x230);
            if (state == 3 || state == 4) {
                fn_8022B17C();
                if (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 9) {
                    fn_80138B7C(lbl_8053AAF8);
                    fn_80458508(lbl_8053AF80, 0);
                }
                for (i = 0, cur = this_; i < 4; i++, cur += 4) {
                    if (fn_8022F514(i) == 0) {
                        fn_802372F8(i, *(s32*)(cur + 0x26c), *(s32*)(cur + 0x27c));
                    }
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern const f32 lbl_8053E4E0;
extern const f32 lbl_8053E4B4;
extern const f32 lbl_8053E4E4;
extern const f32 lbl_8053E47C;
extern const f32 lbl_8053E4E8;
extern "C" void fn_801A033C(u8* p) {
    *(f32*)(p + 0x60) = lbl_8053E4E0;
    *(f32*)(p + 0x64) = lbl_8053E4E0;
    *(f32*)(p + 0x68) = lbl_8053E4B4;
    *(f32*)(p + 0x6c) = lbl_8053E4B4;
    *(f32*)(p + 0x80) = lbl_8053E4E0;
    *(f32*)(p + 0x84) = lbl_8053E4E0;
    *(f32*)(p + 0x88) = lbl_8053E4B4;
    *(f32*)(p + 0x8c) = lbl_8053E4B4;
    *(f32*)(p + 0x70) = lbl_8053E4E4;
    *(f32*)(p + 0x74) = lbl_8053E4E4;
    *(f32*)(p + 0x78) = lbl_8053E47C;
    *(f32*)(p + 0x7c) = lbl_8053E47C;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x98) = 2;
    *(s32*)(p + 0x264) = 0;
    *(f32*)(p + 0x290) = lbl_8053E460;
    *(f32*)(p + 0x294) = lbl_8053E464;
    *(f32*)(p + 0x298) = lbl_8053E4E8;
    p[0x28c] = 0;
    *(f32*)(p + 0x2a8) = lbl_8053E464;
    *(f32*)(p + 0x2a4) = lbl_8053E464;
    *(f32*)(p + 0x2a0) = lbl_8053E464;
    *(f32*)(p + 0x44) = lbl_8053E464;
    *(f32*)(p + 0x40) = lbl_8053E464;
    *(f32*)(p + 0x3c) = lbl_8053E464;
    *(f32*)(p + 0x29c) = *(f32*)(p + 0x10);
    *(s32*)(p + 0x268) = *(u32*)(p + 0x90) & 0xf;
    switch (*(s32*)(p + 0x268)) {
    case 0:
        lbl_8053ABB8[0] = 0;
        lbl_804C6330[0] = 0;
        lbl_8053ABB8[1] = 0;
        lbl_804C6330[1] = 0;
        lbl_8053ABB8[2] = 0;
        lbl_804C6330[2] = 0;
        lbl_8053ABB8[3] = 0;
        lbl_804C6330[3] = 0;
        *(s32*)(p + 0xb0) = 0xa040004;
        if (((SykyVT*)p)->v11()) {
            *(s32*)(p + 0x230) = 6;
        } else {
            *(s32*)(p + 0x230) = 0;
        }
        break;
    case 1:
    case 2:
        *(s32*)(p + 0x230) = 9;
        break;
    case 3:
        *(s32*)(p + 0x108) = 10000;
        *(s32*)(p + 0xb0) = 0xf;
        *(s32*)(p + 0x230) = 0xe;
        break;
    case 4:
        *(s32*)(p + 0x230) = 0xb;
        break;
    }
}

