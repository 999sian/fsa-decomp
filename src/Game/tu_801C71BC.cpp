#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JMath/JMath.h"
extern "C" void fn_801C8B50(char* this_);
extern "C" void fn_801C3B7C(void* this_, s32 state);
extern "C" u8 fn_800FD4C0(void* ring, u8 a, u8 b);
extern "C" JGeometry::TVec3<f32> fn_800FE294(void* ring, u8 i);
extern "C" void fn_800FD818(void* p, s32 n);
extern "C" void* GetCurrentSlotPtr(void* thisPtr);
extern "C" s32 fn_801CD664(s32 n);

struct TndrG { u8 pad[0x131df]; u8 arr[4]; };
extern "C" u8 fn_800FD5E8(void* ring, u8 i);
extern "C" s32 fn_800FE25C(void* ring, u8 i);
extern "C" u8 fn_801CC9F8(void* p, s32 room);
extern "C" u16 fn_8022461C(void* p, s32 room);
extern "C" u8 fn_801CAEF4(char* this_, void* p, s32 room);
extern "C" void fn_801C9234(char* this_, f32* out);
extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_8053EEF4;
extern "C" f32 lbl_8053EF04;
extern "C" f32 lbl_8053EED4;
extern "C" TndrG* fn_802D6A9C(void);
extern "C" u32 fn_800FD548(void* ring, u8 i);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 c);
extern "C" void* GetCurrentSlotPtr(void* thisPtr);
extern "C" f32 lbl_8053EEC8;
extern "C" void fn_800FDE38(void* p);
extern "C" void fn_801C8C84(char* this_, s32 a, s32 b);
extern "C" s16 fn_801D02E0(char* this_, void* p);
extern "C" u8 fn_800FD894(void* ring, s32 id, u8* buf, s32 n);
extern "C" s32 fn_801CD664(s32 n);

extern "C" f32 lbl_8053EECC;
extern "C" f32 lbl_8053EED0;
extern "C" f32 lbl_8053EED4;
extern "C" f32 lbl_8053EED8;
extern "C" f32 lbl_8053EEDC;
extern "C" f32 lbl_8053EEE0;
extern "C" f32 lbl_8053EEE4;
extern "C" void* lbl_8053AC98;

extern "C" void fn_801C71BC(char* this_) {
    u8 done;
    u8 ca;
    u8 c9;
    u8 c8;
    u8 a;
    u8 b;
    u8 c;
    u8* s;
    s32 t;

    *(u32*)(this_ + 0x230) &= 0xffefffff;
    if (!(*(u32*)(this_ + 0x230) & 0x2000000)) {
        done = 0;
        a = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), 1);
        b = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        if (a < s[2]) {
            s[3] = a;
        }
        fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), -1);
        c = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        if ((u8)(s8)a < s[2]) {
            s[3] = a;
        }
        if (&c8 != 0) {
            c8 = c;
        }
        if (&c9 != 0) {
            c9 = a;
        }
        if (&ca != 0) {
            ca = b;
        }
        if (fn_800FD4C0(GetCurrentSlotPtr(this_ + 0x358), c9, c8) ||
            fn_800FD4C0(GetCurrentSlotPtr(this_ + 0x358), c9, ca)) {
            *(s32*)(this_ + 0x2a8) = 0;
            *(u32*)(this_ + 0x230) &= 0xfffdefff;
            *(u32*)(this_ + 0x230) |= 0x400000;
            const JGeometry::TVec3<f32>& pos = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff);
            done = 1;
            *(f32*)(this_ + 0x32c) = pos.x;
            *(f32*)(this_ + 0x330) = pos.y;
            *(f32*)(this_ + 0x334) = pos.z;
        }
        if (done) {
            return;
        }
    }
    fn_801C8B50(this_);
    t = fn_801CD664(0x4001) - 0x2000;
    *(s16*)(this_ + 0x33c) += t;
    if (!(*(u32*)(this_ + 0x524) & 0x40)) {
        fn_801C3B7C(this_, 0x1c);
    }
}

extern "C" void fn_801C79A0(char* this_);
extern "C" u8 fn_801C5340(void);
extern "C" u8 fn_801C53C4(char* this_);
extern "C" BOOL fn_801C7BD0(char* this_);
extern "C" s32 fn_801D05F8(void* p, void* pos, f32 radius);
extern "C" s16 fn_801D0280(void* p);
extern "C" u8 fn_801D0DD4(void* p);
extern "C" u8 fn_8029E248(void* p, void* pos, s32 room);
extern "C" u8 fn_801CCB1C(void* p, s32 room);
extern "C" void fn_801CD930(void* p, s32 v, s32 n);
extern "C" void fn_801C7370(char* this_, u8 param_2) {
    u8 c8;
    u8 c9;
    JGeometry::TVec3<f32> v1c;
    JGeometry::TVec3<f32> v28;
    JGeometry::TVec3<f32> tmp;
    JGeometry::TVec3<f32> v40;
    JMARandFast* rnd;
    u8 a;
    u8 b;
    u8 c;
    u8 r28;
    u8* s;
    s32 room;
    s32 d;
    s16 s14;
    s16 s15;
    u8 busy;

    if (!(*(u32*)(this_ + 0x230) & 0x2000000)) {
        if (fn_801C5340()) {
            *(u32*)(this_ + 0x230) |= 0x2000000;
            fn_801C3B7C(this_, 0x1e);
            return;
        }
        if (*(u32*)(this_ + 0x230) & 0x400000) {
            *(u32*)(this_ + 0x230) &= 0xffbfffff;
            fn_801C3B7C(this_, 0x12);
            return;
        }
        if (*(u8*)(this_ + 0x55c) >= 0x1e && *(u8*)(this_ + 0x55d) == 1) {
            rnd = (JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4);
            if (rnd->get_ufloat_1() < lbl_8053EECC) {
                *(u8*)(this_ + 0x55d) = 0;
            }
        }
    }
    busy = fn_801C53C4(this_);
    if (!(*(u32*)(this_ + 0x230) & 0x2000000) && !busy && *(u8*)(this_ + 0x55d) == 0 &&
        fn_801D05F8(this_, this_ + 0xc, *(f32*)(this_ + 0x5a8)) < 0) {
        fn_801C3B7C(this_, 0xf);
        return;
    }
    if (!(*(u32*)(this_ + 0x230) & 0x2000000) && !busy && *(u8*)(this_ + 0x598) == 0 &&
        fn_801D05F8(this_, this_ + 0xc, lbl_8053EED0) >= 0) {
        fn_801C3B7C(this_, 0x1b);
        return;
    }
    r28 = fn_801C7BD0(this_);
    if (*(u32*)(this_ + 0x524) & 0x1000) {
        if (fn_800FD5E8(GetCurrentSlotPtr(this_ + 0x358), 0xff) &&
            !fn_8029E248(lbl_8053AC98, this_ + 0xc, *(s32*)(this_ + 0x4))) {
            tmp.x = *(f32*)(this_ + 0xc);
            tmp.y = *(f32*)(this_ + 0x10) - lbl_8053EED4;
            tmp.z = *(f32*)(this_ + 0x14);
            fn_8029E248(lbl_8053AC98, &tmp, *(s32*)(this_ + 0x4));
        }
    }
    room = *(s32*)(this_ + 0x4);
    if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
        fn_801C79A0(this_);
        return;
    }
    if (r28) {
        if (*(u8*)(this_ + 0x55d) != 0) {
            *(u8*)(this_ + 0x55d) -= 1;
        }
        if (fn_800FD548(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
            fn_801C3B7C(this_, 0x12);
            return;
        }
        v40 = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff);
        if (fn_801CCB1C(&v40, *(s32*)(this_ + 0x4))) {
            fn_801C8B50(this_);
            if (!fn_801D0DD4(this_)) {
                return;
            }
            if (*(u32*)(this_ + 0x524) & 0x40) {
                return;
            }
            rnd = (JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4);
            if (rnd->get_ufloat_1() >= lbl_8053EED8) {
                return;
            }
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            a = s[3];
            fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), 1);
            b = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            if (a < s[2]) {
                s[3] = a;
            }
            fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), -1);
            c = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            if (a < s[2]) {
                s[3] = a;
            }
            c8 = c;
            c9 = b;
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            if (s[1] == 0) {
                room = *(s32*)(this_ + 0x4);
                if (room == fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), c9)) {
                    v28 = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), c9);
                    if (*(f32*)(this_ + 0xc) >= v28.x) {
                        *(s16*)(this_ + 0x33c) = -0x4000;
                    } else {
                        *(s16*)(this_ + 0x33c) = 0x4000;
                    }
                } else {
                    rnd = (JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4);
                    if (rnd->get_ufloat_1() >= lbl_8053EED8) {
                        *(s16*)(this_ + 0x33c) = -0x4000;
                    } else {
                        *(s16*)(this_ + 0x33c) = 0x4000;
                    }
                }
            } else {
                room = *(s32*)(this_ + 0x4);
                if (room == fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), c8)) {
                    v1c = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), c8);
                    if (*(f32*)(this_ + 0xc) >= v1c.x) {
                        *(s16*)(this_ + 0x33c) = -0x4000;
                    } else {
                        *(s16*)(this_ + 0x33c) = 0x4000;
                    }
                } else {
                    rnd = (JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4);
                    if (rnd->get_ufloat_1() >= lbl_8053EED8) {
                        *(s16*)(this_ + 0x33c) = -0x4000;
                    } else {
                        *(s16*)(this_ + 0x33c) = 0x4000;
                    }
                }
            }
            fn_801C3B7C(this_, 0x1c);
            return;
        }
    } else {
        if (param_2) {
            fn_801C8C84(this_, 1, 0);
        }
    }
    s14 = fn_801D02E0(this_, this_ + 0x32c);
    if (*(u32*)(this_ + 0x230) & 0x20000) {
        fn_801CD930(this_ + 0x33c, s14, 0x500);
    } else {
        *(s16*)(this_ + 0x33c) = s14;
    }
    if (*(s32*)(this_ + 0x24c) % 30 == 0 && !busy) {
        r28 = 0;
        d = fn_801D05F8(this_, this_ + 0xc, lbl_8053EEDC);
        if (d >= 0) {
            s15 = fn_801D0280(this_);
            s14 = *(s16*)(this_ + 0x33c);
            if (lbl_8053EEE0 * fabs((f32)(s16)(s14 - s15)) <= lbl_8053EEE4) {
                r28 = 1;
            }
        }
        if (r28) {
            fn_801C8B50(this_);
        }
    }
}

extern "C" u8 fn_800FD594(void* ring, u8 i);
extern "C" u8 fn_801CD2F8(s32 p);
extern "C" s32 fn_800FE25C(void* ring, u8 i);
extern "C" void fn_801C79A0(char* this_) {
    JGeometry::TVec3<f32> pos;
    u8 buf[0x30];
    s32 r;
    u8 t;

    *(u32*)(this_ + 0x230) &= 0xfdffffff;
    pos = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff);
    *(f32*)(this_ + 0x32c) = pos.x;
    *(f32*)(this_ + 0x330) = pos.y;
    *(f32*)(this_ + 0x334) = pos.z;
    *(s32*)(this_ + 0x56c) = *(s32*)(this_ + 0x4);
    *(f32*)(this_ + 0x570) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x574) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x578) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x4) = fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), 0xff);
    *(JGeometry::TVec3<f32>*)(this_ + 0xc) = *(JGeometry::TVec3<f32>*)(this_ + 0x32c);
    *(JGeometry::TVec3<f32>*)(this_ + 0x18) = *(JGeometry::TVec3<f32>*)(this_ + 0x32c);
    *(s32*)(this_ + 0x57c) = *(s32*)(this_ + 0x4);
    *(f32*)(this_ + 0x580) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x584) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x588) = *(f32*)(this_ + 0x14);
    if (fn_800FD594(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
        *(u32*)(this_ + 0x230) |= 0x20000;
    } else {
        *(u32*)(this_ + 0x230) &= 0xfffdffff;
    }
    s32 n = 1;
    if (((u8*)GetCurrentSlotPtr(this_ + 0x358))[1] != 0) {
        n = -1;
    }
    fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), n);
    fn_801C8C84(this_, 0, 1);
    r = fn_800FD894(GetCurrentSlotPtr(this_ + 0x358), *(s32*)(this_ + 0x4), buf, 0x30);
    if (r <= 3) {
        *(u8*)(this_ + 0x55d) = 1;
    } else {
        *(u8*)(this_ + 0x55d) = fn_801CD664(4) + 1;
        if (*(u32*)(this_ + 0x524) & 0x100) {
            *(u8*)(this_ + 0x55d) += 1;
        }
        t = r - 2;
        if (t >= *(u8*)(this_ + 0x55d)) {
            t = *(u8*)(this_ + 0x55d);
        }
        *(u8*)(this_ + 0x55d) = t;
    }
    if (*(u32*)(this_ + 0x524) & 0x4) {
        *(s32*)(this_ + 0x4) = *(s32*)(this_ + 0x56c);
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x570);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x574);
        *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x578);
        if (fn_801CD2F8(*(s32*)(this_ + 0x56c))) {
            *(s32*)(this_ + 0x58c) = 1;
        } else {
            *(s32*)(this_ + 0x58c) = 0;
        }
        fn_801C3B7C(this_, 0x18);
    } else {
        fn_801C3B7C(this_, 0x17);
    }
}

extern "C" f32 lbl_8053EEF0;
extern "C" f32 lbl_8053EDF0;
extern "C" f32 lbl_8053EEF4;
extern "C" f32 lbl_8053EEF8;
extern "C" u8 fn_801CCB1C(void* pos, s32 layer);
extern "C" u8 fn_801CC9F8(void* pos, s32 layer);
extern "C" u16 fn_8022461C(void* pos, s32 room);
#pragma fp_contract off
extern "C" BOOL fn_801C7BD0(char* this_) {
    BOOL result = 0;
    s32 state = *(s32*)(this_ + 0x2a8);
    if (state == 2) {
        f32 dx = *(f32*)(this_ + 0x32c) - *(f32*)(this_ + 0xc);
        f32 dz = *(f32*)(this_ + 0x330) - *(f32*)(this_ + 0x10);
        f32 r = lbl_8053EEF0 + lbl_8053EDF0;
        if (dx * dx + dz * dz <= r * r) {
            s32 i = 1;
            if (state <= 1) {
                i = 0;
            }
            char* py = this_ + i * 8;
            f32 y = *(f32*)(py + 0x2b0);
            f32 z = lbl_8053EEF4;
            s32 j = 1;
            if (state <= 1) {
                j = 0;
            }
            char* px = this_ + j * 8;
            f32 x = *(f32*)(px + 0x2ac);
            *(f32*)(this_ + 0x32c) = x;
            *(f32*)(this_ + 0x330) = y;
            *(f32*)(this_ + 0x334) = z;
            *(s32*)(this_ + 0x2a8) = 0;
            *(u32*)(this_ + 0x230) &= 0xffffefff;
        }
    } else {
        f32 tx = *(f32*)(this_ + 0x32c);
        f32 ty = *(f32*)(this_ + 0x330);
        f32 r = lbl_8053EEF8;
        s32 room = *(s32*)(this_ + 0x4);
        BOOL k = 0;
        TndrG* g = fn_802D6A9C();
        if (g->arr[room] != 0) {
            r = lbl_8053EEF0 + lbl_8053EDF0;
            JGeometry::TVec3<f32> p = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff);
            if (fn_801CCB1C(&p, room)) {
                k = 1;
            } else {
                tx = p.x;
                ty = p.y;
            }
            if (room == fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), 0xff) && !fn_800FD548(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
                JGeometry::TVec3<f32> q = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff);
                if (!fn_801CC9F8(this_ + 0xc, room) || fn_8022461C(&q, room)) {
                    *(f32*)(this_ + 0x32c) = q.x;
                    *(f32*)(this_ + 0x330) = *(f32*)(this_ + 0x10);
                    *(f32*)(this_ + 0x334) = q.z;
                } else {
                    *(f32*)(this_ + 0x32c) = q.x;
                    *(f32*)(this_ + 0x330) = q.y;
                    *(f32*)(this_ + 0x334) = q.z;
                }
            }
        }
        f32 dx = tx - *(f32*)(this_ + 0xc);
        f32 dz = ty - *(f32*)(this_ + 0x10);
        if (dx * dx + dz * dz <= r * r) {
            if (k) {
                fn_801C8B50(this_);
                result = 1;
            } else {
                if (fn_800FD594(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
                    *(u32*)(this_ + 0x230) |= 0x20000;
                } else {
                    *(u32*)(this_ + 0x230) &= 0xfffdffff;
                }
                result = 1;
                if (((u8*)GetCurrentSlotPtr(this_ + 0x358))[1] != 0) {
                    result = -1;
                }
                fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), result);
                fn_801C8C84(this_, 0, 0);
                result = 1;
            }
        }
    }
    return result;
}
#pragma fp_contract reset
extern "C" void fn_801C7EE4(char* this_) {
    TndrG* g;
    s32 id;
    if (*(u32*)(this_ + 0x230) & 0x2000000) {
        return;
    }
    if (!(u8)fn_800FD548(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
        return;
    }
    id = *(s32*)(this_ + 0x4);
    g = fn_802D6A9C();
    if (!(g->arr[id] != 0 && __fabsf(*(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x330)) > lbl_8053EEC8) && !fn_801CF888(this_, this_ + 0xc, this_ + 0x32c, *(s32*)(this_ + 0x4))) {
        return;
    }
    *(u32*)(this_ + 0x230) |= 0x400000;
}

extern "C" void fn_801C844C(char* p);
extern "C" f32 lbl_8053EEFC;
extern "C" void fn_801C7F98(char* this_) {
    JGeometry::TVec3<f32> va;
    JGeometry::TVec3<f32> vb;
    u8 cb;
    u8 ca;
    u8 p9;
    u8 p8;
    s32 ang;
    u8 a1;
    u8 b1;
    u8 c1;
    u8 a2;
    u8 b2;
    u8 c2;
    u8* s;
    f32 ax;
    f32 ay;

    fn_801C844C(this_);
    fn_801C8C84(this_, 0, 0);
    ang = (s16)(*(s16*)(this_ + 0x33c) = fn_801D02E0(this_, this_ + 0x32c));
    *(u32*)(this_ + 0x230) &= 0xfffdffff;
    a1 = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), 1);
    b1 = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
    if (a1 < s[2]) {
        s[3] = a1;
    }
    fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), -1);
    c1 = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
    if ((u8)(s8)a1 < s[2]) {
        s[3] = a1;
    }
    if (&cb != 0) {
        cb = c1;
    }
    if (&ca != 0) {
        ca = b1;
    }
    if (*(u32*)(this_ + 0x230) & 0x2000000) {
        s32 room = *(s32*)(this_ + 0x4);
        if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), cb)) {
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            s[1] = 1;
            return;
        }
        s32 room2 = *(s32*)(this_ + 0x4);
        if (room2 != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), ca)) {
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            s[1] = 0;
            return;
        }
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        s[1] = 0;
        return;
    }
    s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
    if (fn_800FD5E8(GetCurrentSlotPtr(this_ + 0x358), s[3])) {
        a2 = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), 1);
        b2 = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        if (a2 < s[2]) {
            s[3] = a2;
        }
        fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), -1);
        c2 = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        if ((u8)(s8)a2 < s[2]) {
            s[3] = a2;
        }
        if (&p8 != 0) {
            p8 = c2;
        }
        if (&p9 != 0) {
            p9 = b2;
        }
        JMARandFast* rnd = (JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4);
        if (rnd->get_ufloat_1() < 0.5f) {
            c2 = p9;
            s32 room = *(s32*)(this_ + 4);
            if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), c2)) {
                c2 = p8;
            }
        } else {
            c2 = p8;
            s32 room = *(s32*)(this_ + 4);
            if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), c2)) {
                c2 = p9;
            }
        }
        if (ca == c2) {
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            s[1] = 1;
        } else {
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            s[1] = 0;
        }
        return;
    }
    va = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), ca);
    vb = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), cb);
    ay = va.y - *(f32*)(this_ + 0x330);
    ax = va.x - *(f32*)(this_ + 0x32c);
    f32 tb = JMAAtan2Radian(vb.x - *(f32*)(this_ + 0x32c), vb.y - *(f32*)(this_ + 0x330));
    f32 db = __fabsf((f32)(s16)(ang - (s32)(tb * lbl_8053EEFC)));
    f32 ta = JMAAtan2Radian(ax, ay);
    f32 da = __fabsf((f32)(s16)(ang - (s32)(ta * lbl_8053EEFC)));
    if (0.000030517578f * da < 0.000030517578f * db) {
        s32 room = *(s32*)(this_ + 4);
        if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), cb)) {
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            s[1] = 1;
        } else {
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            s[1] = 0;
        }
    } else {
        s32 room = *(s32*)(this_ + 4);
        if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), ca)) {
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            s[1] = 0;
        } else {
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            s[1] = 1;
        }
    }
}

extern "C" void fn_801C887C(char*);
extern "C" void fn_800FE2E4(void*, void*, s32);
extern "C" f32 lbl_8053EF00;
extern "C" void fn_801C844C(char* p) {
    JGeometry::TVec3<f32> nextA;
    JGeometry::TVec3<f32> nextB;
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
    u32 bitsSecond;
    u32 bitsThird;
    u32 bitsFirst;
    u8 pairB1;
    u8 pairB0;
    u8 pairA1;
    u8 pairA0;
    u8 x;
    u8 c;
    u8 b;
    u32 a;
    u8* slot;
    s32 room;
    fn_800FE2E4(GetCurrentSlotPtr(p + 0x358), &pos, *(s32*)(p + 4));
    if (*(u32*)(p + 0x230) & 0x2000000) return;
    if ((*(u32*)(p + 0x524) & 0x100) != 0) {
        u8* current = (u8*)GetCurrentSlotPtr(p + 0x358);
        if (fn_800FD5E8(GetCurrentSlotPtr(p + 0x358), current[3])) {
            a = ((u8*)GetCurrentSlotPtr(p + 0x358))[3];
            fn_800FD818(GetCurrentSlotPtr(p + 0x358), 1);
            b = ((u8*)GetCurrentSlotPtr(p + 0x358))[3];
            slot = (u8*)GetCurrentSlotPtr(p + 0x358);
            if (a < slot[2]) slot[3] = a;
            fn_800FD818(GetCurrentSlotPtr(p + 0x358), -1);
            c = ((u8*)GetCurrentSlotPtr(p + 0x358))[3];
            slot = (u8*)GetCurrentSlotPtr(p + 0x358);
            if ((u8)a < slot[2]) slot[3] = a;
            if (&pairA0 != 0) pairA0 = c;
            if (&pairA1 != 0) pairA1 = b;
            f32 one = lbl_8053EEC8;
            f32 threshold = lbl_8053EED8;
            u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
            *seed = *seed * 0x19660d + 0x3c6ef35f;
            bitsFirst = (*seed >> 9) | 0x3f800000;
            f32 random = *(f32*)&bitsFirst - one;
            if (random < threshold) {
                x = pairA1;
                room = *(s32*)(p + 4);
                if (room != fn_800FE25C(GetCurrentSlotPtr(p + 0x358), x)) x = pairA0;
            } else {
                x = pairA0;
                room = *(s32*)(p + 4);
                if (room != fn_800FE25C(GetCurrentSlotPtr(p + 0x358), x)) x = pairA1;
            }
            slot = (u8*)GetCurrentSlotPtr(p + 0x358);
            if ((u8)x < slot[2]) slot[3] = x;
        }
    }
    if (*(u32*)(p + 0x230) & 0x200000) return;
    room = *(s32*)(p + 4);
    if (fn_802D6A9C()->arr[room]) {
        fn_801C887C(p);
        return;
    }
    f32 one = lbl_8053EEC8;
    f32 threshold = lbl_8053EF00;
    u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    bitsSecond = (*seed >> 9) | 0x3f800000;
    if (!(*(f32*)&bitsSecond - one < threshold)) return;
    a = ((u8*)GetCurrentSlotPtr(p + 0x358))[3];
    fn_800FD818(GetCurrentSlotPtr(p + 0x358), 1);
    b = ((u8*)GetCurrentSlotPtr(p + 0x358))[3];
    slot = (u8*)GetCurrentSlotPtr(p + 0x358);
    if (a < slot[2]) slot[3] = a;
    fn_800FD818(GetCurrentSlotPtr(p + 0x358), -1);
    c = ((u8*)GetCurrentSlotPtr(p + 0x358))[3];
    slot = (u8*)GetCurrentSlotPtr(p + 0x358);
    if ((u8)a < slot[2]) slot[3] = a;
    if (&pairB1 != 0) pairB1 = c;
    if (&pairB0 != 0) pairB0 = b;
    one = lbl_8053EEC8;
    threshold = lbl_8053EED8;
    seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    bitsThird = (*seed >> 9) | 0x3f800000;
    f32 random = *(f32*)&bitsThird - one;
    if (random < threshold) {
        room = *(s32*)(p + 4);
        if (room == fn_800FE25C(GetCurrentSlotPtr(p + 0x358), pairB1)) {
            nextA = fn_800FE294(GetCurrentSlotPtr(p + 0x358), pairB1);
            if (!fn_801CF888(p, p + 0xc, &nextA, *(s32*)(p + 4))) {
                x = pairB1;
                slot = (u8*)GetCurrentSlotPtr(p + 0x358);
                if (x < slot[2]) slot[3] = x;
            }
        }
    } else {
        room = *(s32*)(p + 4);
        if (room == fn_800FE25C(GetCurrentSlotPtr(p + 0x358), pairB0)) {
            nextB = fn_800FE294(GetCurrentSlotPtr(p + 0x358), pairB0);
            if (!fn_801CF888(p, p + 0xc, &nextB, *(s32*)(p + 4))) {
                x = pairB0;
                slot = (u8*)GetCurrentSlotPtr(p + 0x358);
                if (x < slot[2]) slot[3] = x;
            }
        }
    }
}

extern "C" void fn_801C887C(char* this_) {
    JGeometry::TVec3<f32> v28 = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), 0xff);
    JGeometry::TVec3<f32> v1c;
    JGeometry::TVec3<f32> v10;
    u8 ba;
    u8 b9;
    u8 b8;
    u8 a;
    u8 b;
    u8 c;
    u8* s;
    s32 room;
    JMARandFast* rnd;

    if (fn_801CCB1C(&v28, *(s32*)(this_ + 4))) {
        a = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), 1);
        b = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        if (a < s[2]) {
            s[3] = a;
        }
        fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), -1);
        c = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
        s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
        if (a < s[2]) {
            s[3] = a;
        }
        if (&ba != 0) {
            ba = c;
        }
        if (&b9 != 0) {
            b9 = a;
        }
        if (&b8 != 0) {
            b8 = b;
        }
        room = *(s32*)(this_ + 4);
        if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), ba)) {
            a = b8;
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            if (a < s[2]) {
                s[3] = a;
            }
        } else if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), b8)) {
            a = ba;
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            if (a < s[2]) {
                s[3] = a;
            }
        } else {
            rnd = (JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4);
            if (rnd->get_ufloat_1() < lbl_8053EED8) {
                v1c = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), ba);
                if (fn_801CCB1C(&v1c, *(s32*)(this_ + 4))) {
                    a = b8;
                } else {
                    a = ba;
                }
            } else {
                v10 = fn_800FE294(GetCurrentSlotPtr(this_ + 0x358), b8);
                if (fn_801CCB1C(&v10, *(s32*)(this_ + 4))) {
                    a = ba;
                } else {
                    a = b8;
                }
            }
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            if (a < s[2]) {
                s[3] = a;
            }
        }
        room = *(s32*)(this_ + 4);
        if (room != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), 0xff)) {
            a = b9;
            s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
            if (a < s[2]) {
                s[3] = a;
            }
        }
    }
}

extern "C" void fn_801C8B50(char* this_) {
    *(s32*)(this_ + 0x2a8) = 0;
    *(u32*)(this_ + 0x230) &= 0xffffefff;
    fn_800FDE38(GetCurrentSlotPtr(this_ + 0x358));
    fn_801C8C84(this_, 0, 0);
    *(s16*)(this_ + 0x33c) = fn_801D02E0(this_, this_ + 0x32c);
    *(u32*)(this_ + 0x230) &= 0xfffdffff;
}

extern "C" void fn_801C8BC4(char* this_, u8 param_2) {
    u8 buf[0x30];
    void* p;
    s32 r;
    u8 t;
    if (param_2) {
        p = GetCurrentSlotPtr(this_ + 0x358);
        r = fn_800FD894(p, *(s32*)(this_ + 0x4), buf, 0x30);
        if (r <= 3) {
            *(u8*)(this_ + 0x55d) = 1;
        } else {
            *(u8*)(this_ + 0x55d) = fn_801CD664(4) + 1;
            if (*(u32*)(this_ + 0x524) & 0x100) {
                *(u8*)(this_ + 0x55d) += 1;
            }
            t = r - 2;
            if (t >= *(u8*)(this_ + 0x55d)) {
                t = *(u8*)(this_ + 0x55d);
            }
            *(u8*)(this_ + 0x55d) = t;
        }
    } else {
        *(u8*)(this_ + 0x55d) = fn_801CD664(0xc) + 1;
    }
}

extern "C" void fn_801C8C84(char* this_, s32 a2, s32 a3) {
    char* me = this_;
    u8 bA;
    s32 room;
    u8 bB;
    u8* s;
    u8 done;
    u8 bC;
    u8 c8;
    u8 c9;
    u8 ca;
    u8 cb;
    u8 cc;
    f32 v[2];
    JGeometry::TVec3<f32> p;
    JGeometry::TVec3<f32> old;
    u8* rng;
    u32 bits;
    f32 r;

    if (!(u8)a2) {
        const JGeometry::TVec3<f32>& q = fn_800FE294(GetCurrentSlotPtr(me + 0x358), 0xff);
        *(f32*)(me + 0x32c) = q.x;
        *(f32*)(me + 0x330) = q.y;
        *(f32*)(me + 0x334) = q.z;
        room = *(s32*)(me + 0x4);
        if (fn_802D6A9C()->arr[room]) {
            room = *(s32*)(me + 0x4);
            if (room != fn_800FE25C(GetCurrentSlotPtr(me + 0x358), 0xff)) {
                return;
            }
            if ((u8)fn_800FD548(GetCurrentSlotPtr(me + 0x358), 0xff)) {
                return;
            }
            p = fn_800FE294(GetCurrentSlotPtr(me + 0x358), 0xff);
            if (fn_801CC9F8(me + 0xc, room) && !(u16)fn_8022461C(&p, room)) {
                *(f32*)(me + 0x32c) = p.x;
                *(f32*)(me + 0x330) = p.y;
                *(f32*)(me + 0x334) = p.z;
            } else {
                *(f32*)(me + 0x32c) = p.x;
                *(f32*)(me + 0x330) = *(f32*)(me + 0x10);
                *(f32*)(me + 0x334) = p.z;
            }
            return;
        }
        if ((u8)a3) {
            return;
        }
        done = 0;
        if (!(*(u32*)(me + 0x230) & 0x200000)) {
            s = (u8*)GetCurrentSlotPtr(me + 0x358);
            if (fn_800FD5E8(GetCurrentSlotPtr(me + 0x358), s[3])) {
                done = 1;
            } else if (*(u32*)(me + 0x524) & 0x100) {
                s = (u8*)GetCurrentSlotPtr(me + 0x358);
                bA = s[3];
                fn_800FD818(GetCurrentSlotPtr(me + 0x358), 1);
                s = (u8*)GetCurrentSlotPtr(me + 0x358);
                bB = s[3];
                if (bA < s[2]) {
                    s[3] = bA;
                }
                fn_800FD818(GetCurrentSlotPtr(me + 0x358), -1);
                s = (u8*)GetCurrentSlotPtr(me + 0x358);
                bC = s[3];
                if (bA < s[2]) {
                    s[3] = bA;
                }
                if (&cb != 0) {
                    cb = bC;
                }
                if (&cc != 0) {
                    cc = bB;
                }
                if (fn_800FD5E8(GetCurrentSlotPtr(me + 0x358), cb)) {
                    done = 1;
                } else if (fn_800FD5E8(GetCurrentSlotPtr(me + 0x358), cc)) {
                    done = 1;
                }
            }
        } else {
            done = 1;
        }
        if (done) {
            return;
        }
        old = *(JGeometry::TVec3<f32>*)(me + 0x32c);
        rng = (u8*)lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        r = *(f32*)&bits;
        *(f32*)(me + 0x32c) += lbl_8053EED4 * (lbl_8053EF04 * (r - 1.0f) - 1.0f);
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        r = *(f32*)&bits;
        *(f32*)(me + 0x330) += lbl_8053EED4 * (lbl_8053EF04 * (r - 1.0f) - 1.0f);
        if (fn_801CAEF4(me, me + 0x32c, room)) {
            *(JGeometry::TVec3<f32>*)(me + 0x32c) = old;
        }
        return;
    }

    done = 1;
    room = *(s32*)(me + 0x4);
    if (*(u8*)(me + 0x59b) == 0 && fn_802D6A9C()->arr[room] == 0) {
        if (*(u32*)(me + 0x524) & 0x100) {
            if (fn_800FD5E8(GetCurrentSlotPtr(me + 0x358), 0xff)) {
                done = 0;
            }
        }
    } else {
        done = 0;
    }
    if (!done) {
        return;
    }
    fn_801C9234(me, v);
    if ((*(u32*)(me + 0x524) & 0x800) && !(*(u32*)(me + 0x230) & 0x2000000) && !(*(u32*)(me + 0x230) & 0x100000) && fn_801CF888(me, v, me + 0x32c, room)) {
        s = (u8*)GetCurrentSlotPtr(me + 0x358);
        bA = s[3];
        fn_800FD818(GetCurrentSlotPtr(me + 0x358), 1);
        s = (u8*)GetCurrentSlotPtr(me + 0x358);
        bB = s[3];
        if (bA < s[2]) {
            s[3] = bA;
        }
        fn_800FD818(GetCurrentSlotPtr(me + 0x358), -1);
        s = (u8*)GetCurrentSlotPtr(me + 0x358);
        bC = s[3];
        if (bA < s[2]) {
            s[3] = bA;
        }
        if (&c8 != 0) {
            c8 = bC;
        }
        if (&c9 != 0) {
            c9 = bA;
        }
        if (&ca != 0) {
            ca = bB;
        }
        if (fn_800FD4C0(GetCurrentSlotPtr(me + 0x358), c9, c8) || fn_800FD4C0(GetCurrentSlotPtr(me + 0x358), c9, ca)) {
            *(s32*)(me + 0x2a8) = 0;
            *(u32*)(me + 0x230) &= 0xfffdefff;
            *(u32*)(me + 0x230) |= 0x400000;
            const JGeometry::TVec3<f32>& q2 = fn_800FE294(GetCurrentSlotPtr(me + 0x358), 0xff);
            *(f32*)(me + 0x32c) = q2.x;
            *(f32*)(me + 0x330) = q2.y;
            *(f32*)(me + 0x334) = q2.z;
            return;
        }
    }
    if (*(s32*)(me + 0x2a8) < 0x10) {
        *(f32*)(me + 0x2ac + *(s32*)(me + 0x2a8) * 8) = v[0];
        *(f32*)(me + 0x2b0 + *(s32*)(me + 0x2a8) * 8) = v[1];
        *(s32*)(me + 0x2a8) += 1;
    }
    if (*(s32*)(me + 0x2a8) < 0x10) {
        *(f32*)(me + 0x2ac + *(s32*)(me + 0x2a8) * 8) = *(f32*)(me + 0x32c);
        *(f32*)(me + 0x2b0 + *(s32*)(me + 0x2a8) * 8) = *(f32*)(me + 0x330);
        *(s32*)(me + 0x2a8) += 1;
    }
    *(f32*)(me + 0x32c) = v[0];
    *(f32*)(me + 0x330) = v[1];
    *(f32*)(me + 0x334) = lbl_8053EEF4;
    *(s16*)(me + 0x33c) = fn_801D02E0(me, me + 0x32c);
    *(u32*)(me + 0x230) &= 0xfffdffff;
    *(u32*)(me + 0x230) |= 0x1000;
}

extern "C" void fn_801C9420(char* this_, f32* v);
extern "C" void fn_801C9234(char* this_, f32* out)
{
    f32 v[2];
    f32 x = *(f32*)(this_ + 0x264);
    f32 y = *(f32*)(this_ + 0x268);
    s32 ang = JMAAtan2Radian(*(f32*)(this_ + 0x3c), *(f32*)(this_ + 0x40)) * 10430.378f;
    f32 a90x = x * JMACosShort(0x4000) - y * JMASinShort(0x4000);
    f32 a90y = x * JMASinShort(0x4000) + y * JMACosShort(0x4000);
    f32 a270x = x * JMACosShort(0xC000) - y * JMASinShort(0xC000);
    f32 a270y = x * JMASinShort(0xC000) + y * JMACosShort(0xC000);
    f32 d1 = fabs((f32)(s16)(ang - (s32)(JMAAtan2Radian(a90x, a90y) * 10430.378f)));
    f32 d2 = fabs((f32)(s16)(ang - (s32)(JMAAtan2Radian(a270x, a270y) * 10430.378f)));
    if (0.000030517578f * d2 >= 0.000030517578f * d1) {
        v[0] = a90x;
        v[1] = a90y;
    } else {
        v[0] = a270x;
        v[1] = a270y;
    }
    fn_801C9420(this_, v);
    out[0] = *(f32*)(this_ + 0xc) + v[0];
    out[1] = *(f32*)(this_ + 0x10) + v[1];
}

extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_8053EED8;
extern "C" void fn_800FD818(void* p, s32 n);
extern "C" s32 fn_800FE25C(void* p, u8 n);
extern "C" u8 fn_801C976C(char* this_) {
    u8 pair[2];
    u8 a = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), 1);
    u8 b = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    u8* s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
    if (a < s[2]) {
        s[3] = a;
    }
    fn_800FD818(GetCurrentSlotPtr(this_ + 0x358), -1);
    u8 c = ((u8*)GetCurrentSlotPtr(this_ + 0x358))[3];
    s = (u8*)GetCurrentSlotPtr(this_ + 0x358);
    s32 a2 = a;
    if ((u8)a2 < s[2]) {
        s[3] = a;
    }
    u8* pc = &pair[1];
    if (pc != 0) {
        *pc = c;
    }
    u8* pb = &pair[0];
    if (pb != 0) {
        *pb = b;
    }
    f32 one = lbl_8053EEC8;
    f32 thr = lbl_8053EED8;
    u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    u32 bits = (*seed >> 9) | 0x3f800000;
    f32 r = *(f32*)&bits - one;
    s32 cur;
    u8 x;
    if (r < thr) {
        x = pair[0];
        cur = *(s32*)(this_ + 4);
        if (cur != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), x)) {
            x = pair[1];
        }
    } else {
        x = pair[1];
        cur = *(s32*)(this_ + 4);
        if (cur != fn_800FE25C(GetCurrentSlotPtr(this_ + 0x358), x)) {
            x = pair[0];
        }
    }
    return x;
}

void __sinit_tu_801C71BC_cpp(void) {}
