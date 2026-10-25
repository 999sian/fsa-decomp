#include "types.h"
#include "sdk/stl/float.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_801E4D54(u8* this_) {
    *(u32*)(this_ + 0x230) &= ~0x4000;
    this_[0x5ce] = 0;
    *(f32*)(this_ + 0x4bc) = 0.0f;
}

extern "C" void fn_801E4D74(u8* this_) {
    this_[0x5ce] = 0x32;
    *(f32*)(this_ + 0x4bc) = 255.0f;
}

extern "C" f32 lbl_8053F578;
extern "C" s32 fn_8023F264(s32 i);
extern "C" s32 fn_80236B50(s32 i);
extern "C" s32 fn_8022D75C(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void fn_801D789C(u8* p);
extern "C" s32 fn_80230188(s32 i);
extern "C" void fn_80230224(s32 i, s32 b);
extern "C" s32 fn_801D08B4(u8* this_, s32 i, u8* pos, f32 range);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void fn_80236074(s32 i, s32 a, s32 b);
extern "C" void fn_801EB00C(u8* a, f32* b, f32* c);
extern "C" s32 fn_802300EC(s32 i);
extern "C" s32 fn_80236BEC(s32 i);
extern "C" void fn_80230C6C(s32 i);
extern "C" void fn_80230AD4(s32 i);
extern "C" s32 fn_80230CFC(s32 i);
extern "C" void fn_8021BD18(u8* p, s32 v);
extern "C" void fn_8021BCBC(u8* p);
extern "C" void fn_80230498(s32 i, f32* v, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8022CB94(s32 i);
extern "C" s32 fn_80238548(s32 i, s32 b, f32* p, s32 d);
extern "C" void fn_8023DFF4(s32 i, f32* v);
extern "C" void fn_8022CD48(s32 i);
extern "C" void fn_801E5754(u8* this_) {
    s32 i;
    u8* p;
    f32 pv[3];
    f32 pv2[3];
    f32 dx;
    f32 dy;
    f32 dz;
    f32* v;
    f32 out[3];
    if (this_[0x2a8] != 0) {
        for (i = 0; i < 4; i++) {
            p = this_ + 0x2a8 + i * 0x18;
            if (fn_8023F264(i) == 0 || fn_80236B50(i) != 0 || fn_8022D75C(i) != 0) {
                fn_80230224(i, 0);
            } else if (fn_8023DE58(i) != *(s32*)(this_ + 4)) {
                fn_801D789C(p);
                p[0] = 0;
                if (fn_80230188(i) != 0) {
                    fn_80230224(i, 0);
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        p = this_ + i * 0x18;
        if (*(s32*)(p + 0x2ac) > 0) {
            *(s32*)(p + 0x2ac) -= 1;
            continue;
        }
        if (p[0x2a8] == 0) {
            if (fn_801D08B4(this_, i, this_ + 0xc, *(f32*)(this_ + 0x47c)) == 0) {
                continue;
            }
        }
    }
}

extern "C" f32 lbl_8053F578;
extern "C" f32 lbl_8053F580;
extern "C" f32 lbl_8053F584;
extern "C" f32 lbl_8053F588;
extern "C" f32 lbl_8053F58C;
extern "C" f32 lbl_8053F590;
extern "C" f32 lbl_8053F594;
extern "C" f32 lbl_8053F598;
extern "C" s32 fn_801D05F8(u8* this_, u8* pos, f32 range);
extern "C" u32 fn_801D0280(u8* this_);
extern "C" f32 sincosTable___5JMath[];
extern "C" void fn_801E5BA8(u8* this_, u8* actor, f32* dir, u8 flag) {
    s32 id = *(s32*)(actor + 0x198);
    s32 i;
    for (i = 0; i < 16; i++) {
        u8* slot = this_ + i * 0x14;
        if (*(u8*)(slot + 0x30c) == 0 || *(s32*)(slot + 0x308) != id) {
            continue;
        }
        if (flag == 0) {
            f32 y = dir[1];
            f32 x = dir[0];
            f32 lenSq = x * x + y * y;
            if (lenSq > lbl_8053F580 * FLT_EPSILON) {
                if (lenSq > lbl_8053F578) {
                    f32 inv = __frsqrte(lenSq);
                    lenSq = lbl_8053F584 * inv * (lbl_8053F588 - lenSq * (inv * inv));
                }
                x *= lenSq;
                y *= lenSq;
            }
            x *= lbl_8053F58C;
            y *= lbl_8053F58C;
            *(f32*)(slot + 0x310) = x;
            *(f32*)(slot + 0x314) = y;
            *(f32*)(slot + 0x318) = lbl_8053F590;
            *(u8*)(slot + 0x30d) = 1;
            return;
        }
        {
            s32 idx = fn_801D05F8(this_, this_ + 0xc, lbl_8053F594);
            f32 x;
            f32 y;
            if (idx >= 0 && this_[idx * 0x18 + 0x2a8] == 0) {
                u32 off = (fn_801D0280(this_) >> 2) & 0x3ff8;
                x = *(f32*)((u8*)sincosTable___5JMath + off);
                y = *(f32*)((u8*)sincosTable___5JMath + off + 4);
            } else {
                f32 lenSq;
                x = dir[0];
                y = dir[1];
                lenSq = x * x + y * y;
                if (lenSq > lbl_8053F580 * FLT_EPSILON) {
                    if (lenSq > lbl_8053F578) {
                        f32 inv = __frsqrte(lenSq);
                        lenSq = lbl_8053F584 * inv * (lbl_8053F588 - lenSq * (inv * inv));
                    }
                    x *= lenSq;
                    y *= lenSq;
                }
            }
            x *= lbl_8053F598;
            y *= lbl_8053F598;
            *(f32*)(slot + 0x310) = x;
            *(f32*)(slot + 0x314) = y;
            *(f32*)(slot + 0x318) = lbl_8053F588;
            *(u8*)(slot + 0x30d) = 1;
            return;
        }
    }
}

