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
            f32 x = dir[0];
            f32 y = dir[1];
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

