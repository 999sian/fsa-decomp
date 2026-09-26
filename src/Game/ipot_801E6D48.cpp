// Game TU 801E6D48-801E7BF4 (IPOT). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_80210AB4(void* this_);
extern void* lbl_804A5418[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A61C8[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void fn_80210630(void* this_, s32 flag18, s32 zero1, s32 zero2, s32 extra);
extern "C" void fn_801CDD58(void* this_);
extern "C" void* fn_801E9AFC();
extern "C" s32 fn_801EA6D8(void* entryPtr, u32 variant, s32 id);

extern "C" void* fn_801E6D48(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5418;
        if (this_ != 0) {
            *(void**)p = lbl_804A61C8;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct Vec2f {
    f32 x, y;
    Vec2f(f32 x_, f32 y_) { x = x_; y = y_; }
};

extern "C" f32 fn_80210B34(void* p);
extern "C" f32 fn_80210AF8(void* p);
extern "C" void fn_801EA108(void* mgr, f32* pos, s32 a, f32 r);
extern "C" u8 fn_80210A6C(void* this_);
extern "C" void fn_801E728C(char* p, s32 type);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* cfg, s32 id, s32 a, s32 b);
extern "C" void detach__5ActorFv(void* this_);

extern "C" void fn_801E6DE8(char* p) {
    if (*(u32*)(p + 0x230) & 0x8000) {
        return;
    }
    static f32 radius = 128.0f;
    switch (*(s32*)(p + 0x248)) {
    case 0:
    case 2: {
        f32 dx = fn_80210B34(*(void**)(p + 0x98));
        f32 dz = fn_80210AF8(*(void**)(p + 0x98));
        Vec2f pos(*(f32*)(p + 0xc) + dx, *(f32*)(p + 0x10) + dz);
        fn_801EA108(fn_801E9AFC(), &pos.x, *(s16*)(p + 0x2b0), radius);
        break;
    }
    }
}

extern "C" void fn_801E6EAC(char* p) {
    if (*(u32*)(p + 0x230) & 0x8000) {
        s32 id = *(s32*)(p + 0x2b4);
        if (id != 0) {
            fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
        }
        detach__5ActorFv(p);
    } else if (*(s32*)(p + 0x248) != 1) {
        fn_801E728C(p, 1);
    }
}

extern "C" void fn_801E6F28(void* this_) {
    u32 flags = *(u32*)((char*)this_ + 0x230);
    if (flags & 0x8000) {
        return;
    }
    s32 extra = 0;
    if (*(s32*)((char*)this_ + 0x248) == 2) {
        extra = (s32)*(f32*)((char*)this_ + 0x2a8);
    }
    fn_80210630(this_, (flags >> 13) & 1, 0, 0, extra);
}

extern "C" void fn_801E6F80(void* this_) {
    s32 flags = *(s32*)((char*)this_ + 0x230);
    if (!(flags & 0x8000)) {
        fn_801CDD58(this_);
    }
}

extern "C" void fn_801E9C00(s32 a, f32* out);
extern "C" s32 fn_801E9B58(void* this_);
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F82CC(void* mgr, void* actor, u8 a, f32 r);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" s32 fn_802BA9F8(char* actor, u32 id);
extern "C" void fn_801CB538(s32 a, void* pos, s32 b, s32 c);
extern "C" u8 fn_801EAC54(void* p, s32 id);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 a);

extern "C" s32 fn_801E6FAC(char* p) {
    s32 id;
    s32 hit = -1;
    if (*(s32*)(p + 0x248) == 0 && *(s32*)(p + 0x2ac) == -1) {
        f32 x0 = *(f32*)(p + 0x60);
        f32 y0 = *(f32*)(p + 0x64);
        f32 x1 = *(f32*)(p + 0x68);
        f32 y1 = *(f32*)(p + 0x6c);
        f32 cx = fn_80210B34(*(void**)(p + 0x98));
        f32 cy = fn_80210AF8(*(void**)(p + 0x98));
        f32 r = 6.0f;
        *(f32*)(p + 0x60) = cx - r;
        *(f32*)(p + 0x64) = cy - r;
        *(f32*)(p + 0x68) = cx + r;
        *(f32*)(p + 0x6c) = cy + r;
        f32 off[2];
        fn_801E9C00(*(s16*)(p + 0x2b0), off);
        *(f32*)(p + 0x60) += off[0];
        *(f32*)(p + 0x64) += off[1];
        *(f32*)(p + 0x68) += off[0];
        *(f32*)(p + 0x6c) += off[1];
        hit = fn_801E9B58(p);
        if (hit >= 0) {
            fn_801E728C(p, 1);
        }
        *(f32*)(p + 0x60) = x0;
        *(f32*)(p + 0x64) = y0;
        *(f32*)(p + 0x68) = x1;
        *(f32*)(p + 0x6c) = y1;
    }
    if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > 0.0f && *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > 0.0f) {
        id = fn_801F82CC(fn_801F856C(), p, *(u8*)(p + 0x195), 32.0f);
        if (id >= 0 && id != *(s32*)(p + 0x198) && id != hit) {
            char* other = fn_801F666C(fn_801F856C(), id);
            if (other != 0) {
                if (*(u32*)(other + 0x1a0) == 'FIRE' && fn_802BA9F8(other, *(u32*)(other + 0x1a0)) == 1) {
                    if (*(s32*)(p + 0x248) == 0) {
                        fn_801E728C(p, 2);
                    }
                } else if (*(u32*)(other + 0x1a0) == 'SWBM') {
                    fn_801CB538(*(s32*)(p + 0x4), other + 0xc, 0, 0);
                } else if (fn_801EAC54(p + 0x1dc, *(s32*)(other + 0x198))) {
                    switch (*(u32*)(other + 0x1a0)) {
                    case 'FIRE':
                        fn_801F0E34(p, 0x3002e, 0);
                        break;
                    }
                }
                other[0x164] = 1;
            }
        }
    }
    return 0;
}

struct IpotRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct IpotGame { u8 pad[0xb4]; IpotRandom rnd; };
extern IpotGame* lbl_8053AAF8;

struct RupyDrop {
    u32 param;
    s32 count;
};
extern const RupyDrop lbl_80469C40[4];

extern "C" void fn_80210A30(void* this_, void* box);
extern "C" void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801F3128(void* this_, JGeometry::TVec2<f32>* out);
extern "C" u16 fn_80226998(JGeometry::TVec2<f32>* pos, s32 room);
extern "C" u8 fn_801EE3C0(u16 tile);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern "C" s32 fn_801F8544(void* mgr, u32 id, s32 owner, void* pos, u32 param);
extern "C" void fn_802D79E8(void* cfg, s32 id, s32 a, f32 x, f32 y);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);
extern "C" u32 fn_8013CC50(u32 id, void* pos, s32 type, s32 p4, u32 p5, u32 p6, u32 p7, u32 p8, f32 f);

extern "C" void fn_801E728C(char* p, s32 type) {
    switch (type) {
    case 1:
        if ((*(u32*)(p + 0x230) & 0x4000) && !(*(u32*)(p + 0x230) & 0x10000)) {
            Actor_CreateByID(fn_801F856C(), 'IBBM', *(s32*)(p + 0x4), p + 0xc, *(u32*)(p + 0x90),
                             *(s32*)(p + 0x16c), -1);
            p[0x11c] = 0;
            break;
        }
        {
            f32 x0 = *(f32*)(p + 0x60);
            f32 y0 = *(f32*)(p + 0x64);
            f32 x1 = *(f32*)(p + 0x68);
            f32 y1 = *(f32*)(p + 0x6c);
            fn_80210A30(p, p + 0x60);
            *(f32*)(p + 0x60) *= 1.5f;
            *(f32*)(p + 0x64) *= 1.5f;
            *(f32*)(p + 0x68) *= 1.5f;
            *(f32*)(p + 0x6c) *= 1.5f;
            fn_801F2B7C(p, 4, -1, 0x16);
            JGeometry::TVec2<f32> pos;
            JGeometry::TVec2<f32> center;
            fn_801F3128(p, &center);
            pos.y = center.y - 16.0f;
            for (s32 i = 0; i < 3; i++) {
                pos.x = center.x - 16.0f;
                for (s32 j = 0; j < 3; j++) {
                    if (fn_801EE3C0(fn_80226998(&pos, *(s32*)(p + 0x4)))) {
                        JGeometry::TVec3<f32> spawn(pos.x, pos.y, 0.0f);
                        Actor_CreateByID(fn_801F856C(), 'BLZE', *(s32*)(p + 0x4), &spawn, 0xf, -1, -1);
                    }
                    pos.x += 16.0f;
                }
                pos.y += 16.0f;
            }
            *(f32*)(p + 0x60) = x0;
            *(f32*)(p + 0x64) = y0;
            *(f32*)(p + 0x68) = x1;
            *(f32*)(p + 0x6c) = y1;
        }
        fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 0x4), 0, 8.0f, 0.0f);
        fn_80134DE4(lbl_8053AAF8, 2, 0);
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x59, 0, 0, 0, 0, 1, 2.0f);
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x5a, 0, 0, 0, 0, 1, 2.0f);
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x5b, 0, 0, 0, 0, 1, 2.0f);
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x5c, 0, 0, 0, 0, 1, 1.0f);
        if (*(u32*)(p + 0x230) & 0x2000) {
            fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x262, 0, 0, 0, 0, 1, 1.0f);
            for (s32 i = 0; i < 4; i++) {
                s32 n = lbl_80469C40[i].count;
                for (s32 j = 0; j < n; j++) {
                    s32 idx = fn_801F8544(fn_801F856C(), 'RUPY', *(s32*)(p + 0x4), p + 0xc, lbl_80469C40[i].param);
                    if (idx >= 0) {
                        char* rupy = fn_801F666C(fn_801F856C(), idx);
                        if (rupy != 0) {
                            JGeometry::TVec3<f32> vel(0.6f * (2.0f * lbl_8053AAF8->rnd.get_ufloat_1() - 1.0f),
                                                      0.6f * (2.0f * lbl_8053AAF8->rnd.get_ufloat_1() - 1.0f),
                                                      6.0f * lbl_8053AAF8->rnd.get_ufloat_1() + 6.0f);
                            *(JGeometry::TVec3<f32>*)(rupy + 0x3c) = vel;
                        }
                    }
                }
            }
        } else {
            fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x261, 0, 0, 0, 0, 1, 1.0f);
        }
        {
            s32 id = *(s32*)(p + 0x2b4);
            if (id != 0) {
                fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
            }
        }
        fn_801F0E34(p, 0x30001, 0);
        detach__5ActorFv(p);
        break;
    case 2:
        break;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = type;
}

extern "C" void fn_801E722C(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 1:
        break;
    case 2:
        if (fn_80210A6C(p)) {
            *(u32*)(p + 0x230) |= 0x10000;
            fn_801E728C(p, 1);
        }
        break;
    }
}

extern "C" void fn_801E773C(void* this_) {
    u32 variant = *(u32*)((char*)this_ + 0x90) >> 24;
    s32 id = *(s32*)((char*)this_ + 0x198);
    void* self = fn_801E9AFC();
    s32 slot = *(unsigned char*)((char*)self + 0xf0);
    void* entryPtr = (char*)self + slot * 0x78;
    *(s32*)((char*)this_ + 0x2ac) = fn_801EA6D8(entryPtr, variant, id);
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_80210990(void* this_, s32 type, void* box);
extern "C" s16 fn_801F6874(s32 type);

extern "C" void fn_801E77A0(char* p) {
    fn_801D0ED0(p);
    *(u32*)(p + 0x98) = *(u32*)(p + 0x90) & 3;
    *(u32*)(p + 0x2b4) = (*(u32*)(p + 0x90) >> 2) & 0x1f;
    u32 params = *(u32*)(p + 0x90);
    if ((params >> 21) & 1) {
        *(u32*)(p + 0x230) |= 0x8000;
    } else if ((params >> 23) & 1) {
        *(u32*)(p + 0x230) |= 0x2000;
    } else if ((params >> 22) & 1) {
        *(u32*)(p + 0x230) |= 0x4000;
    }
    f32 one = 1.0f;
    f32 neg = -1.0f;
    *(f32*)(p + 0x80) = one;
    *(f32*)(p + 0x84) = one;
    *(f32*)(p + 0x88) = neg;
    *(f32*)(p + 0x8c) = neg;
    if (*(u32*)(p + 0x230) & 0x8000) {
        *(f32*)(p + 0x60) = one;
        *(f32*)(p + 0x64) = one;
        *(f32*)(p + 0x68) = neg;
        *(f32*)(p + 0x6c) = neg;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(u32*)(p + 0xb0) = 0;
    } else {
        fn_80210990(p, *(s32*)(p + 0x98), p + 0x60);
        *(u32*)(p + 0xb0) = 0x40004;
    }
    *(u32*)(p + 0x230) |= 0x380;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(s16*)(p + 0x2b0) = fn_801F6874(*(s32*)(p + 0x98));
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
}

extern "C" void* fn_801E78F0(void* this_) {
    fn_80210AB4(this_);
    *(void**)this_ = lbl_804A5418;
    *(s32*)((char*)this_ + 0x2ac) = -1;
    *(s16*)((char*)this_ + 0x2b0) = 0;
    *(s32*)((char*)this_ + 0x2b4) = 0;
    return this_;
}

extern "C" void* fn_801E7940(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A61C8;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
