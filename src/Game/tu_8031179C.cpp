#include "Game/Actor.h"

extern "C" s8 fn_802D800C(void*, s32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_8022FEB8(f32*, s32, void*, s32, s32);
extern "C" void fn_8022FF8C(s32, f32*, s32, void*, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_802300EC(void);
extern "C" u16 fn_80226850(f32*, s32);
extern "C" u8 fn_8038C678(s32, s32, void*, s32, void*, s32);
extern "C" u8 fn_80388CAC(s32, void*);
extern "C" void fn_80458880(void*, s32, s32);
extern "C" void fn_802A3948(void*, void*, s32, s32, s32);
extern "C" f32 lbl_805417B8;
extern "C" f32 lbl_805417BC;
extern "C" f32 lbl_805417C0;
extern "C" f32 lbl_805417C4;
extern "C" f32 lbl_805417C8;
extern "C" f32 lbl_805417CC;
extern "C" f32 lbl_805417D0;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AF80;
extern "C" void* lbl_8053AC98;
extern "C" f32 lbl_805417E0;


extern "C" char lbl_804AAB40[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_80471488[];
extern "C" f32 lbl_805417C4;
extern "C" void fn_801F06F0(void*, void*, s32, s32, s32, f32, f32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void* lbl_8053AED0;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" u8 fn_8023A97C(s32 i, void* area, s32 b, f32* pos);
extern "C" u16 fn_80226998(f32* pos, s32 room);
extern "C" u8 fn_8022E438(s32 i, s32 b);
extern "C" s32 fn_8022CAF8(s32 i);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 arg, s32 flag);
extern "C" u32 __cvt_fp2unsigned(f64);
extern "C" void fn_8031179C(u8* p) {
    s32 i = 0;
    f32 pos[2];
    do {
        if (fn_8023A97C(i, p + 0x230, 0, pos) && fn_80226998(pos, 0) == 0x1b0) {
            if (*(p + 0x259) == 0) {
                s32 t = *(s32*)(p + 0x250);
                if (t == *(s32*)(p + 0x250) || (fn_8022E438(t, t) && fn_8022CAF8(t) == 4)) {
                    fn_8043D67C(lbl_8053AED0, 0x826, t, 0);
                }
            } else {
                s32 dx = ((__cvt_fp2unsigned(pos[0]) & 0xfffffff0) + 8) - (s32)*(f32*)(p + 0x240);
                s32 dy = ((__cvt_fp2unsigned(pos[1]) & 0xfffffff0) + 8) - (s32)*(f32*)(p + 0x244);
                if (dy < -0x30) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x825, i, 0);
                    }
                } else if (dy > 0x30) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x826, i, 0);
                    }
                } else if (dx < -0x30) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x827, i, 0);
                    }
                } else if (dx > 0x30) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x828, i, 0);
                    }
                } else if (dy < -0x10) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x829, i, 0);
                    }
                } else if (dy > 0x10) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x82a, i, 0);
                    }
                } else if (dx < -0x10) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x82b, i, 0);
                    }
                } else if (dx > 0x10) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x82c, i, 0);
                    }
                } else if (dy < -8) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x82d, i, 0);
                    }
                } else if (dy > 8) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x82e, i, 0);
                    }
                } else if (dx < -8) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x82f, i, 0);
                    }
                } else if (dx > 8) {
                    if (i == *(s32*)(p + 0x250) || (fn_8022E438(i, *(s32*)(p + 0x250)) && fn_8022CAF8(i) == 4)) {
                        fn_8043D67C(lbl_8053AED0, 0x830, i, 0);
                    }
                } else {
                    fn_802D8050(fn_802D6A9C(), 0x14, 1, 0xff);
                }
            }
        }
        i++;
    } while (i < 4);
}

extern "C" void fn_80311C58(u8* this_) {
    fn_801F06F0(this_, lbl_80471488, 0x386, 0, 0, lbl_805417C4, lbl_805417C4);
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, 0x386, 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_80311CD0(u8* p) {
    f32 box[4];
    f32 pos[3];
    Vec pv;
    Vec sv;
    u8* rng;
    u32 seed;
    u32 bits;
    f32 fx, fy, fx1, fy1, fx2, fy2;
    f32 r1, r2;
    s32 r28, r30, r29;
    s32 state;
    s32 found;
    void* h;
    s32 room;

    box[0] = *(f32*)(p + 0x60);
    box[1] = *(f32*)(p + 0x64);
    box[2] = *(f32*)(p + 0x68);
    box[3] = *(f32*)(p + 0x6c);
    box[0] += *(f32*)(p + 0xc);
    box[2] += *(f32*)(p + 0xc);
    box[1] += *(f32*)(p + 0x10);
    box[3] += *(f32*)(p + 0x10);
    h = *(void**)(p + 0x198);
    room = *(s32*)(p + 4);
    fn_80239914(p, room, h);

    state = *(s32*)(p + 0x24c);
    switch (state) {
    case 0:
        fn_8022FEB8(box, room, h, 1, 0);
        r29 = fn_8022FD8C(h);
        if (r29 < 0) {
            break;
        }
        if (!fn_802300EC()) {
            break;
        }
        if (fn_802D800C(fn_802D6A9C(), 0x14)) {
            pv = *(Vec*)(p + 0xc);
            if (fn_8038C678(r29, 0x834, h, room, &pv, 0x28)) {
                *(s32*)(p + 0x254) = r29;
                *(s32*)(p + 0x24c) = 3;
            }
            break;
        }
        rng = (u8*)lbl_8053AAF8;
        fx = *(f32*)(p + 0x230) + lbl_805417B8;
        fy = *(f32*)(p + 0x234) + lbl_805417BC;
        fx1 = *(f32*)(p + 0x238) - lbl_805417BC;
        fy1 = *(f32*)(p + 0x23c) - lbl_805417BC;
        seed = *(u32*)(rng + 0xb4);
        seed = seed * 0x19660d + 0x3c6ef35f;
        *(u32*)(rng + 0xb4) = seed;
        bits = (seed >> 9) | 0x3f800000;
        r1 = *(f32*)&bits - lbl_805417C4;
        seed = seed * 0x19660d + 0x3c6ef35f;
        *(u32*)(rng + 0xb4) = seed;
        bits = (seed >> 9) | 0x3f800000;
        r2 = *(f32*)&bits - lbl_805417C4;
        fx2 = lbl_805417C0 * r1 + fx;
        fy2 = lbl_805417C8 * r2 + fy;
        found = 0;
        for (r30 = 0; r30 < 0x14 && !found; r30++) {
            for (r28 = 0; r28 < 0x1a && !found; r28++) {
                pos[0] = fx2;
                pos[1] = fy2;
                pos[2] = lbl_805417CC;
                if (fn_80226850(pos, 0) == 0x1b0) {
                    pos[0] = (f32)(__cvt_fp2unsigned(pos[0]) & ~0xf);
                    pos[1] = (f32)(__cvt_fp2unsigned(pos[1]) & ~0xf);
                    *(f32*)(p + 0x240) = pos[0];
                    *(f32*)(p + 0x244) = pos[1];
                    *(f32*)(p + 0x248) = pos[2];
                    sv.x = pos[0];
                    sv.y = pos[1];
                    sv.z = pos[2];
                    *(Vec*)((u8*)fn_802D6A9C() + 0x13280) = sv;
                    found = 1;
                    break;
                }
                fx2 = fx2 + lbl_805417D0;
                if (fx2 >= fx1) {
                    fx2 = fx;
                }
            }
            fy2 = fy2 + lbl_805417D0;
            if (fy2 >= fy1) {
                fy2 = fy;
            }
        }
        if (fn_8038C678(r29, 0x84f, h, room, &pv, 0x28)) {
            *(s32*)(p + 0x254) = r29;
            *(s32*)(p + 0x24c) = 3;
        }
        break;
    case 1:
        fn_8022FF8C(*(s32*)(p + 0x250), box, room, h, 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x250), h)) {
            *(f32*)(p + 0x240) = *(f32*)(p + 0x240) + lbl_805417E0;
            *(f32*)(p + 0x244) = *(f32*)(p + 0x244) + lbl_805417E0;
            p[0x258] = 0;
            p[0x259] = 1;
            *(s32*)(p + 0x24c) = 2;
        }
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

extern "C" Actor* fn_803122F8(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AAB40;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_802D6A9C(void);
extern "C" s8 fn_802D800C(void*, s32);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" void fn_802A3948(void*, void*, s32, s32, s32);
extern "C" void* lbl_8053AC98;
extern "C" f32 lbl_805417E0;
extern "C" f32 lbl_805417E4;
extern "C" void fn_80312358(Actor* p) {
    void* base;
    f32 zero = lbl_805417E0;
    f32 one = lbl_805417E4;
    *(f32*)((u8*)p + 0x60) = one;
    *(f32*)((u8*)p + 0x64) = one;
    *(f32*)((u8*)p + 0x68) = zero;
    *(f32*)((u8*)p + 0x6c) = zero;
    base = fn_802D6A9C();
    s32* src = (s32*)((u8*)base + 0xcc);
    s32 a = src[0];
    s32 b = src[1];
    *(s32*)((u8*)p + 0x230) = a;
    *(s32*)((u8*)p + 0x234) = b;
    s32 c = src[2];
    s32 d = src[3];
    *(s32*)((u8*)p + 0x238) = c;
    *(s32*)((u8*)p + 0x23c) = d;
    *(f32*)((u8*)p + 0x240) = *(f32*)((u8*)p + 0xc);
    *(f32*)((u8*)p + 0x244) = *(f32*)((u8*)p + 0x10);
    *(f32*)((u8*)p + 0x248) = *(f32*)((u8*)p + 0x14);
    *(s32*)((u8*)p + 0x24c) = 0;
    *(s32*)((u8*)p + 0x250) = -1;
    *(s32*)((u8*)p + 0x254) = -1;
    *((u8*)p + 0x258) = 0;
    *((u8*)p + 0x259) = 0;
    *((u8*)p + 0x25a) = 0;
    base = fn_802D6A9C();
    if ((u8)fn_802D800C(base, 0x14) != 0) {
        base = fn_802D6A9C();
        fn_802A3948(lbl_8053AC98, (u8*)base + 0x13280, 0, 0, 0x7a);
    } else {
        base = fn_802D6A9C();
        fn_802D8050(base, 0x15, 0, 0xff);
    }
}


