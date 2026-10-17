#include "types.h"
#include "JSystem/JGeometry/Vec.h"


void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AF018[];
extern f32 lbl_80543090;
extern const f32 lbl_80543094;
extern const char lbl_80475588[];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* posPtr, s32 effectRef, s32 flag,
                            s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);
extern "C" void* fn_8037D784(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF018;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8037D7E4(void* this_) {
    f32 val = lbl_80543090;
    *(f32*)((u8*)this_ + 0x44) = val;
    *(f32*)((u8*)this_ + 0x40) = val;
    *(f32*)((u8*)this_ + 0x3c) = val;
    *(u32*)((u8*)this_ + 0x230) = 2;
}

extern "C" void fn_8037D800(u8* this_) {
    s32 st = *(s32*)(this_ + 0x234);
    if (st >= 0x100 || (st & 2) == 0) {
        if (*(u32*)(this_ + 0x90) == 0) {
            fn_801F06F0(this_, lbl_80475588, 0x5c, 0, 2, lbl_80543094, lbl_80543094);
            fn_803075AC(*(u32*)(this_ + 0x198), *(u32*)(this_ + 0x4), this_ + 0xc, 0x5c, 0, 2, -1, 0, 0, 0);
        } else {
            fn_801F06F0(this_, lbl_80475588, 0x5d, 0, 1, lbl_80543094, lbl_80543094);
            fn_803075AC(*(u32*)(this_ + 0x198), *(u32*)(this_ + 0x4), this_ + 0xc, 0x5d, 0, 2, -1, 0, 0, 0);
        }
    }
}

extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_8023B8E4(f32* box, s32 room, f32* pt, s32 flag);
extern "C" s32 fn_8023AF14(f32* box, s32 room, f32 r, s32 flag);
extern "C" s32 fn_80236B50(s32 x);
extern "C" s32 fn_802375B0(s32 x);
extern "C" void fn_80230EB8(s32 x, s32 y);
extern "C" void fn_80237524(s32 x, s32 y);
extern "C" void fn_8030C210(void* mgr, f32* vec);
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern f32 lbl_80543098;
extern f32 lbl_8054309C;
extern f32 lbl_805430A0;
extern f32 lbl_805430A4;
extern f32 lbl_805430A8;
extern f64 lbl_805430B0;
extern "C" void fn_8037D8F4(u8* this_) {
    f32 pt[2];
    f32 box[4];
    f32 v[3];
    f32 w[3];
    s32 r29;
    s32 r30;
    s32 t;
    pt[0] = *(f32*)(this_ + 0xc);
    pt[1] = *(f32*)(this_ + 0x10);
    *(JGeometry::TVec3<f32>*)(this_ + 0xc) += *(JGeometry::TVec3<f32>*)(this_ + 0x3c);
    *(s32*)(this_ + 0x234) -= 1;
    if (*(s32*)(this_ + 0x234) <= 0) {
        *(u8*)(this_ + 0x11c) = 0;
        return;
    }
    switch (*(s32*)(this_ + 0x230)) {
    case 0: {
        s32 room = *(s32*)(this_ + 0x4);
        if (fn_802D6A9C()[room + 0x131df] != 0) {
            *(f32*)(this_ + 0x40) += lbl_80543098;
            if (*(f32*)(this_ + 0x40) > lbl_80543090) {
                *(s32*)(this_ + 0x230) = 1;
            }
        } else {
            *(f32*)(this_ + 0x44) -= lbl_80543098;
            if (*(f32*)(this_ + 0x44) < lbl_80543090) {
                *(s32*)(this_ + 0x230) = 1;
            }
        }
        break;
    }
    case 1: {
        s32 room = *(s32*)(this_ + 0x4);
        if (fn_802D6A9C()[room + 0x131df] != 0) {
            *(f32*)(this_ + 0x40) += lbl_80543098;
            v[0] = *(f32*)(this_ + 0xc);
            v[1] = *(f32*)(this_ + 0x10) + ((*(s32*)(this_ + 0x90) == 0) ? lbl_8054309C : lbl_805430A0);
            v[2] = *(f32*)(this_ + 0x14);
            if (((u8 (*)(u8*, s32, f32*))(*(void***)this_)[19])(this_, room, v) == 1) {
                t = *(s32*)(this_ + 0x238) - 1;
                *(s32*)(this_ + 0x238) = t;
                if (t > 0) {
                    *(f32*)(this_ + 0x40) = lbl_805430A4 * (f32)t;
                    *(s32*)(this_ + 0x230) = 0;
                } else {
                    *(f32*)(this_ + 0x40) = lbl_80543090;
                    *(s32*)(this_ + 0x230) = 2;
                }
            }
        } else {
            *(f32*)(this_ + 0x44) -= lbl_80543098;
            if (*(f32*)(this_ + 0x14) <= lbl_80543090) {
                t = *(s32*)(this_ + 0x238) - 1;
                *(s32*)(this_ + 0x238) = t;
                *(f32*)(this_ + 0x14) = lbl_80543090;
                if (t > 0) {
                    *(f32*)(this_ + 0x44) = lbl_805430A8 * (f32)t;
                    *(s32*)(this_ + 0x230) = 0;
                } else {
                    *(f32*)(this_ + 0x44) = lbl_80543090;
                    *(s32*)(this_ + 0x230) = 2;
                }
            }
        }
        break;
    }
    }
    box[0] = *(f32*)(this_ + 0x80) + pt[0];
    box[1] = *(f32*)(this_ + 0x84) + pt[1];
    box[2] = *(f32*)(this_ + 0x88) + pt[0];
    box[3] = *(f32*)(this_ + 0x8c) + pt[1];
    r29 = fn_8023B8E4(box, *(s32*)(this_ + 0x4), pt, 1);
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        r30 = fn_8023AF14(box, *(s32*)(this_ + 0x4), lbl_80543090, 0);
        if (r30 >= 0 && fn_80236B50(r30) != 0) {
            r30 = -1;
        }
        if (r29 >= 0 && fn_80236B50(r29) != 0) {
            r29 = -1;
        }
    } else {
        r30 = fn_8023AF14(box, *(s32*)(this_ + 0x4), lbl_80543090, 1);
    }
    if (r30 >= 0) {
        if (fn_802375B0(r30) == 0x180) {
            fn_80230EB8(r30, 0x12);
        }
        fn_80237524(r30, (*(s32*)(this_ + 0x90) != 0) ? 0xc0 : 0x30);
        *(u8*)(this_ + 0x11c) = 0;
    }
    if (r29 >= 0) {
        if (fn_802375B0(r29) == 0x180) {
            fn_80230EB8(r29, 0x12);
        }
        fn_80237524(r29, (*(s32*)(this_ + 0x90) != 0) ? 0xc0 : 0x30);
        *(u8*)(this_ + 0x11c) = 0;
    }
    if (*(s32*)(this_ + 0x4) < 8) {
        w[0] = *(f32*)(this_ + 0xc);
        w[1] = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14);
        w[2] = lbl_80543090;
        fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), w);
    }
}

extern "C" void fn_8037DD38(u8* this_) {
    this_[0x11c] = 0;
}

extern "C" void fn_8037DD44(void) {}

#include "types.h"
#include "Game/SinitPoolChain.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804AF018[];
extern f32 lbl_80543090;
