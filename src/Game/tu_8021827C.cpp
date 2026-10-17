#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_801CE010(void*, void*);
extern "C" void fn_8030C210(void*, void*);
extern u8* lbl_8053AB10;
extern f32 lbl_8053FC40;
extern "C" bool fn_801CD2F8(s32 id);
extern "C" u8 fn_8022BA58(s32 room, f32* pos);
extern "C" bool fn_8030C2A8(u8* p, f32* v);
extern "C" bool fn_801E1DE8(void* this_);
extern "C" void fn_801F0E34(void* p, u32 id, s32 flag);
extern "C" void fn_8021827C(u8* p) {
    u8 buf[0x10];
    if (*(s32*)(p + 0x248) != 0) {
        s32 kind = *(s32*)(p + 4);
        u8* mgr = fn_802D6A9C();
        f32* b;
        if (kind < 8) {
            b = (f32*)(mgr + 0xcc);
        } else {
            b = (f32*)(mgr + 0xdc);
        }
        if (b[1] < *(f32*)(p + 0x10) && *(f32*)(p + 0x10) < b[3]) {
            f32 hi = *(f32*)(p + 0xc);
            f32 min = *(f32*)(p + 0x60);
            f32 max = *(f32*)(p + 0x68);
            f32 lo = hi;
            if (max - min > lbl_8053FC40) {
                lo = hi + min;
                hi = hi + max;
            }
            bool in = false;
            if (b[0] < lo && hi < b[2]) {
                in = true;
            }
            if (in) {
                fn_801CE010(p, buf);
                fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), buf);
            }
        }
    }
}

extern "C" void fn_8021835C(u8* p) {
    if (*(s32*)(p + 0x248) == 1) {
        JGeometry::TVec3<f32> v;
        JGeometry::TVec3<f32> lo;
        JGeometry::TVec3<f32> hi;
        bool ok = false;
        fn_801CE010(p, &v);
        lo = v;
        hi = v;
        if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053FC40) {
            hi.x = hi.x + *(f32*)(p + 0x68);
            lo.x = lo.x + *(f32*)(p + 0x60);
        }
        if (fn_801CD2F8(*(s32*)(p + 4))) {
            if (fn_8022BA58(*(s32*)(p + 4), &lo.x) && fn_8022BA58(*(s32*)(p + 4), &hi.x)) {
                ok = true;
            }
        } else {
            if (fn_8030C2A8(*(u8**)(lbl_8053AB10 + 0x24), &lo.x) && fn_8030C2A8(*(u8**)(lbl_8053AB10 + 0x24), &hi.x)) {
                ok = true;
            }
        }
        if (ok) {
            u32 f = *(u32*)(p + 0x230);
            if (!(f & 0x200000) && !(f & 0x4000)) {
                if (!fn_801E1DE8(p)) {
                    if (*(u32*)(p + 0x230) & 0x20000) {
                        fn_801F0E34(p, 0x5001C, 0);
                    } else {
                        fn_801F0E34(p, 0x50018, 0);
                    }
                }
                *(u32*)(p + 0x230) |= 0x200000;
            }
        } else {
            u32 f = *(u32*)(p + 0x230);
            if ((f & 0x200000) && !(f & 0x400000) && (f & 0x4000) && !(f & 0x80000) && *(s32*)(p + 0x2bc) >= 0) {
                if (!fn_801E1DE8(p)) {
                    fn_801F0E34(p, 0x5001B, 0);
                }
                *(u32*)(p + 0x230) |= 0x400000;
            }
        }
    }
}

extern "C" bool fn_801CD2F8(s32 id);
extern "C" u8 fn_8022B978(s32 room, f32* pos, u8 mode);
extern "C" bool fn_8030C2A8(u8* p, f32* v);
extern "C" u32 fn_80218538(u8* p) {
    u32 ret = 0;
    f32 pt[2][2];
    f32 w[3];
    f32 v[3];
    f32 min = *(f32*)(p + 0x60);
    f32 max = *(f32*)(p + 0x68);
    f32 x = *(f32*)(p + 0xc);
    f32 y = *(f32*)(p + 0x10);
    pt[0][0] = x;
    pt[0][1] = y;
    pt[1][0] = x;
    pt[1][1] = y;
    if (max - min > lbl_8053FC40) {
        pt[0][0] = x + min;
        pt[1][0] = x + max;
    }
    min = *(f32*)(p + 0x64);
    max = *(f32*)(p + 0x6c);
    if (max - min > lbl_8053FC40) {
        pt[0][1] = pt[0][1] + min;
        pt[1][1] = pt[1][1] + max;
    }
    if (fn_801CD2F8(*(s32*)(p + 4))) {
        if (fn_8022B978(*(s32*)(p + 4), pt[0], 0)) {
            ret = 1;
        }
    } else {
        bool ok = false;
        u8* cam = *(u8**)(lbl_8053AB10 + 0x24);
        v[0] = pt[0][0];
        v[1] = pt[0][1];
        v[2] = lbl_8053FC40;
        if (fn_8030C2A8(cam, v)) {
            w[0] = pt[1][0];
            w[1] = pt[1][1];
            w[2] = lbl_8053FC40;
            if (fn_8030C2A8(cam, w)) {
                ok = true;
            }
        }
        if (ok) {
            ret = 1;
        }
    }
    return ret;
}

