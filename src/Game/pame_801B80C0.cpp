// Game TU 801B80C0-801B9730 (PAME). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry.h"
#include "Game/ItemBase.h"
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3B10[];

extern "C" void* fn_801B80C0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A3B10;
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

extern "C" void* fn_801B94C8(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3B10;
    *(s32*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

extern "C" void fn_801B91A8(u8* this_, s32 mode);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" s32 fn_801F2DB4(void* actor, u32 a, u32 b, u32 c);
extern "C" s32 fn_801D22A0(void* obj, s32 a, s32 b);
extern "C" void fn_801CE4BC(void* this_);
extern const f32 lbl_8053EB20;
extern const f32 lbl_8053EB24;
extern const f32 lbl_8053EB34;
extern const f32 lbl_8053EB50;
extern s32 lbl_8053A100;

static inline u8 pameIsActive(s32 st) {
    u8 r = 0;
    switch (st) {
    case 1:
    case 2:
    case 3:
    case 5:
        r = 1;
        break;
    }
    return r;
}

extern "C" s32 fn_801B87DC(u8* this_) {
    u8 use = 1;
    s32 result = 0;
    s32 st = *(s32*)(this_ + 0x248);
    if (pameIsActive(st)) {
        use = 0;
        if (*(s32*)(this_ + 0x24c) < 10) {
            switch (st) {
            case 1:
            case 5:
                use = 1;
                break;
            }
        }
    }
    if (use) {
        fn_801F2DB4(this_, *(u32*)(this_ + 0x1a0), 'NULL', 0);
    } else {
        result = fn_801F2DB4(this_, 'NULL', 'NULL', 0);
    }
    return result;
}

extern "C" void fn_801B88A4(u8* this_) {
    if (__fabsf(*(f32*)(this_ + 0x44)) >= lbl_8053EB34) {
        if (*(u32*)(this_ + 0x230) & 0x2000) {
            fn_801F0E34(this_, 0x50014, 0);
        } else {
            fn_801F0E34(this_, 0x50015, 0);
        }
    }
}

extern "C" void fn_801B8908(u8* this_) {
    if (this_[0xd4] == 1) {
        u8 ok = 0;
        if (*(u32*)(this_ + 0x230) & 0x4000) {
            if (*(s32*)(this_ + 0x2a8) == lbl_8053A100) {
                ok = 1;
            }
        } else {
            ok = 1;
        }
        if (ok && *(f32*)(this_ + 0x14) <= lbl_8053EB20) {
            switch (*(s32*)(this_ + 0x248)) {
            case 0:
                fn_801B91A8(this_, 1);
                break;
            case 2:
            case 3:
            case 5:
                fn_801B91A8(this_, 4);
                break;
            }
        }
        this_[0xd4] = 0;
    }
}

extern "C" void fn_801B8C08(u8* this_) {
    s32 on = 0;
    if (pameIsActive(*(s32*)(this_ + 0x248))) {
        on = 1;
    }
    fn_801D22A0(this_ + 0x270, on, 2);
    f32 v = lbl_8053EB24;
    if (*(s32*)(this_ + 0x248) == 3) {
        v = lbl_8053EB50;
    }
    *(f32*)(this_ + 0x2a0) = v;
    fn_801CE4BC(this_);
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* base, u32 fourCC, u32 owner, void* posPtr, s32 flag);
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void v07__5ActorFv(void* this_);
extern "C" void fn_801F31C4(void* this_, void* out);
extern "C" void fn_802397B4(void* in, u32 a, u32 b);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" void fn_80236074(s32 player, s32 amount, s32 c);
extern const f32 lbl_8053EB28;
extern const f32 lbl_8053EB2C;

static inline void pameDropRupees(u8* this_) {
    s32 id;
    f32 neg = -lbl_8053EB28;
    for (s32 i = 0; i < 2; i++) {
        id = fn_801F8544(fn_801F856C(), 'RUPY', *(u32*)(this_ + 4), this_ + 0xc, 2);
        if (id >= 0) {
            u8* r = (u8*)fn_801F666C(fn_801F856C(), id);
            if (r != 0) {
                f32 x = lbl_8053EB28;
                if (i != 0) {
                    x = neg;
                }
                *(JGeometry::TVec3<f32>*)(r + 0x3c) = JGeometry::TVec3<f32>(x, lbl_8053EB20, lbl_8053EB2C);
            }
        }
    }
}

extern "C" void fn_801B82E8(u8* this_) {
    u32 fl = *(u32*)(this_ + 0x230);
    if ((fl & 0x2000) && (fl & 0x4000)) {
        s32 p = *(s32*)(this_ + 0x10c);
        if (p >= 0 && p < 4 && p == *(s32*)(this_ + 0x2a8)) {
            pameDropRupees(this_);
        }
    }
    v07__5ActorFv(this_);
}

extern "C" u8 fn_801B83F4(u8* this_) {
    u8 hit = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053EB20 &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053EB20) {
        u8 held = 0;
        switch (*(s32*)(this_ + 0x248)) {
        case 1:
            held = 1;
            break;
        case 2:
        case 3:
            held = 1;
            break;
        }
        if (held) {
            u8 buf[0x18];
            fn_801F31C4(this_, buf);
            fn_802397B4(buf, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        } else {
            hit = fn_801F2B7C(this_, *(u32*)(this_ + 0x114), -1, 1);
            u8 mask = hit;
            if (mask != 0 && *(s32*)(this_ + 0x248) == 5) {
                for (s32 i = 0; i < 4; i++) {
                    if (mask & (1 << i)) {
                        fn_80236074(i, 100, 0);
                    }
                }
            }
        }
    }
    return hit;
}

extern "C" void fn_801B8700(u8* this_) {
    if (*(s32*)(this_ + 0x248) == 5) {
        pameDropRupees(this_);
    }
}

extern "C" void fn_801F06F0(void* this_, void* table, u32 id, void* data, f32 f1, f32 f2, s32 mode);
extern u8 lbl_80469198[];

static inline void pameScaleMtx(f32 m[3][4], f32 x, f32 y, f32 z) {
    m[0][0] = x;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = y;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = z;
}

extern "C" void fn_801B8150(u8* this_) {
    DrawRec r;
    f32 m[3][4];
    if (*(u32*)(this_ + 0x230) & 0x2000) {
        m[0][3] = 0.0f;
        m[1][3] = 0.0f;
        m[2][3] = 0.0f;
        pameScaleMtx(m, *(f32*)(this_ + 0x54), *(f32*)(this_ + 0x58), *(f32*)(this_ + 0x5c));
        r.w18 = m;
    }
    if (*(u32*)(this_ + 0x230) & 0x4000) {
        r.ids[8] = *(s32*)(this_ + 0x2a8) + 2;
    }
    fn_801F06F0(this_, lbl_80469198, *(u32*)(this_ + 0x280) + 0xbd, &r, lbl_8053EB24, lbl_8053EB24, 0);
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801D2608(void* obj, void* tbl, u32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);
extern "C" void fn_801D1D60(void* obj);
extern const f32 lbl_8053EB5C;
extern const f32 lbl_8053EB68;
extern u8 lbl_8053A120[8];

extern "C" void fn_801B9378(u8* this_) {
    fn_801D0ED0(this_);
    if (*(u32*)(this_ + 0x90) & 1) {
        *(u32*)(this_ + 0x230) |= 0x2000;
        u32 p = (*(u32*)(this_ + 0x90) >> 1) & 7;
        if (p >= 1 && p <= 4) {
            *(u32*)(this_ + 0x230) |= 0x4000;
            *(s32*)(this_ + 0x2a8) = p - 1;
        }
    }
    if (*(u32*)(this_ + 0x230) & 0x2000) {
        f32 sc = lbl_8053EB68;
        *(f32*)(this_ + 0x54) = sc;
        *(f32*)(this_ + 0x58) = sc;
        *(f32*)(this_ + 0x5c) = sc;
        *(f32*)(this_ + 0x60) *= sc;
        *(f32*)(this_ + 0x64) *= sc;
        *(f32*)(this_ + 0x68) *= sc;
        *(f32*)(this_ + 0x6c) *= sc;
        *(f32*)(this_ + 0x80) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x84) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x88) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x8c) = *(f32*)(this_ + 0x6c);
    } else {
        *(s32*)(this_ + 0x108) = 1;
    }
    *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x108);
    *(u32*)(this_ + 0xb0) = 0x4130b;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = fn_801CD664(0x10) + 0x1e;
    *(f32*)(this_ + 0x254) = lbl_8053EB5C;
    *(f32*)(this_ + 0x258) = lbl_8053EB5C;
    fn_801D2608(this_ + 0x270, lbl_8053A120, 2);
    fn_801D22DC(this_ + 0x270, 0, 2, 0);
    fn_801D1D60(this_ + 0x270);
}

extern "C" s32 fn_801CF6B8(void* this_);
extern "C" s32 fn_801CD354(s32 val);
extern "C" void fn_801CEBD0(void* this_);
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_801F2FAC(void* this_);
extern "C" f32* fn_8023E724(s32 idx);
extern const f32 lbl_8053EB30;
extern const f32 lbl_8053EB38;
extern const f32 lbl_8053EB60;
extern const f32 lbl_8053EB64;
extern int __float_epsilon[];

extern "C" void fn_801B91A8(u8* this_, s32 mode) {
    switch (mode) {
    case 0:
        *(s32*)(this_ + 0x250) = fn_801CD664(0x10) + 0x1e;
        *(f32*)(this_ + 0x258) = lbl_8053EB5C;
        if (*(s32*)(this_ + 0x248) != 4) {
            *(s32*)(this_ + 0x98) = fn_801CF6B8(this_);
        }
        break;
    case 1:
    case 4:
        if (mode == 1) {
            if (*(u32*)(this_ + 0x230) & 0x2000) {
                fn_801F0E34(this_, 0x50016, 0);
            } else {
                fn_801F0E34(this_, 0x50017, 0);
            }
        } else {
            if (*(u32*)(this_ + 0x230) & 0x2000) {
                fn_801F0E34(this_, 0x50021, 0);
            } else {
                fn_801F0E34(this_, 0x50022, 0);
            }
        }
        *(s32*)(this_ + 0x250) = -1;
        *(s32*)(this_ + 0x98) = fn_801CD354(*(s32*)(this_ + 0x98));
        *(f32*)(this_ + 0x258) = lbl_8053EB60;
        *(f32*)(this_ + 0x254) = lbl_8053EB60;
        if (*(u32*)(this_ + 0x230) & 0x2000) {
            *(f32*)(this_ + 0x44) = lbl_8053EB50;
        } else {
            *(f32*)(this_ + 0x44) = lbl_8053EB38;
        }
        break;
    case 2:
        *(s32*)(this_ + 0x250) = fn_801CD664(0x65) + 0x190;
        *(f32*)(this_ + 0x258) = lbl_8053EB20;
        break;
    case 3:
        *(s32*)(this_ + 0x250) = fn_801CD664(0xb) + 0x1e;
        *(f32*)(this_ + 0x258) = lbl_8053EB20;
        break;
    case 5:
        *(s32*)(this_ + 0x250) = fn_801CD664(1) + 0x21c;
        *(s32*)(this_ + 0x98) = fn_801CD354(*(s32*)(this_ + 0x98));
        *(f32*)(this_ + 0x258) = lbl_8053EB64;
        *(f32*)(this_ + 0x254) = lbl_8053EB64;
        *(f32*)(this_ + 0x44) = lbl_8053EB50;
        break;
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = mode;
}


extern "C" s32 fn_801B8518(u8* this_) {
    s32 result = 0;
    u8 use = 1;
    s32 st = *(s32*)(this_ + 0x248);
    if (pameIsActive(st)) {
        use = 0;
        if (*(s32*)(this_ + 0x24c) < 10) {
            switch (st) {
            case 1:
            case 5:
                use = 1;
                break;
            }
        }
    }
    if (use) {
        if (*(u32*)(this_ + 0x230) & 0x2000) {
            fn_801CEBD0(this_);
        } else if (st == 0) {
            s32 pl = fn_801F285C(this_, 0, 0, 1, -1);
            if (pl >= 0) {
                fn_801B91A8(this_, 5);
                JGeometry::TVec2<f32> d;
                d.y = *(f32*)(this_ + 0x10) - fn_8023E724(pl)[1];
                d.x = *(f32*)(this_ + 0xc) - fn_8023E724(pl)[0];
                if (d.squared() <= JGeometry::TUtil<f32>::epsilon()) {
                    *(f32*)(this_ + 0x3c) = 0.0f;
                    *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x254);
                } else {
                    d.normalize();
                    d.scale(*(f32*)(this_ + 0x254));
                    *(f32*)(this_ + 0x3c) = d.x;
                    *(f32*)(this_ + 0x40) = d.y;
                }
                fn_801F0E34(this_, 0x4003b, 0);
            }
        }
    } else {
        result = fn_801F2FAC(this_);
    }
    return result;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
