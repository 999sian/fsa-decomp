#include "types.h"
#include "sdk/stl/float.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"

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
    s32 j;
    s32 i;
    u8* p;
    u8* q;
    s32 room;
    JGeometry::TVec3<f32> pv;
    JGeometry::TVec3<f32> sum;
    JGeometry::TVec3<f32> out;
    f32 xy[2];
    f32 dx, dy;
    u8 first, second;
    s32 result;
    for (i = 0, q = this_; i < 4; i++, q += 0x18) {
        if (q[0x2a8] != 0) {
            if (!(u8)fn_8023F264(i) || (u8)fn_80236B50(i) || (u8)fn_8022D75C(i)) goto clear_slot;
            room = *(s32*)(this_ + 4);
            s32 playerRoom = fn_8023DE58(i);
            if (playerRoom != room) {
clear_slot:
                p = q + 0x2a8;
                fn_801D789C(p);
                p[0] = 0;
                if ((u8)fn_80230188(i)) fn_80230224(i, 0);
            }
        }
    }
    for (j = 0, p = this_; j < 4; j++, p += 0x18) {
        if (*(s32*)(p + 0x2ac) > 0) {
            if (*(s32*)(p + 0x2ac) > 0) --*(volatile s32*)(p + 0x2ac);
            continue;
        }
        if (!p[0x2a8] && !(u8)fn_801D08B4(this_, j, this_ + 0xc, *(f32*)(this_ + 0x47c))) continue;
        dy = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x1c);
        dx = *(f32*)(this_ + 0xc) - *(f32*)(this_ + 0x18);
        f32* v = fn_8023E724(j);
        pv.x = v[0]; pv.y = v[1]; pv.z = v[2];
        if (p[0x2a8]) {
            pv.x += dx; pv.y += dy;
            if (*(u32*)(this_ + 0x230) & 0x4000) {
                ++*(volatile s32*)(p + 0x2b0);
                if (*(s32*)(p + 0x2b0) % 40 == 0) fn_80236074(j, 10, 0);
            }
        }
        fn_801EB00C(this_ + 0x464, &pv.x, &out.x);
        if (out.z > lbl_8053F578) {
            if ((*(u32*)(this_ + 0x230) & 0x4000) && !(u8)fn_80230188(j) &&
                (u8)fn_802300EC(j) && !(u8)fn_80236BEC(j)) {
                fn_80230C6C(j); fn_80230AD4(j); p[0x2a8] = 1;
                fn_8021BD18(p + 0x2b4, fn_80230CFC(j));
            }
            if (!(u8)fn_80230188(j)) {
                if ((*(u32*)(this_ + 0x230) & 0x4000) && !(u8)fn_80236BEC(j)) {
                    out.x += dx; out.y += dy;
                    fn_8023DFF4(j, &out.x); fn_8022CD48(j);
                }
            } else {
                sum.x = pv.x; sum.y = pv.y; sum.z = pv.z;
                sum.add(out);
                fn_8021BCBC(p + 0x2b4);
                fn_80230498(j, &sum.x, *(s32*)(p + 0x2b4), 255, -128, -128, 0);
                fn_8022CB94(j);
                first = 0; second = 0; result = 0;
                xy[0] = pv.x; xy[1] = pv.y;
                xy[0] -= out.x; xy[1] -= out.y;
                if (!(*(u32*)(this_ + 0x230) & 0x4000)) {
                    first = 1;
                    result = fn_80238548(j, 0, xy, 25);
                } else if (sum.z > *(f32*)(this_ + 0x478)) {
                    second = 1;
                    result = fn_80238548(j, *(s32*)(this_ + 0x114), xy, 23);
                }
                if (first || second) {
                    fn_80230224(j, 0);
                    fn_801D789C(p + 0x2a8);
                    p[0x2a8] = 0;
                    if ((u8)result) *(s32*)(p + 0x2ac) = 120;
                    else *(s32*)(p + 0x2ac) = 30;
                }
            }
        } else if ((*(u32*)(this_ + 0x230) & 0x4000) && !(fn_8023E724(j)[2] >= *(f32*)(this_ + 0x478)) &&
                   !(u8)fn_80236BEC(j)) {
            fn_8023DFF4(j, &out.x); fn_8022CD48(j);
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

