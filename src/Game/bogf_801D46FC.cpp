// Game TU 801D46FC-801D6CEC (BOGF). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry.h"
#include "sdk/stl/math.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void dtor_801D7730(void* this_, s32 flag);
extern "C" void dtor_801EB8CC(void* this_, s32 flag);
extern "C" void dtor_80217F80(void* this_, s32 flag);
extern void* lbl_804A4958[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" {
}
extern "C" void fn_801D1C18(void* subObj);
extern void* lbl_8053AF80;
extern "C" s32 fn_80458F9C(void* mgr, s32 handle);
extern "C" void fn_801D7874(void* slot);
extern "C" void fn_8021BD18(void* subObj, s32 arg);
extern "C" void fn_801D789C(void* child);

extern "C" void* fn_801D46FC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4958;
        if (p + 0x568 != 0) {
            char* q = p + 0x578;
            if (q != 0) {
                if (q + 0x24 != 0) {
                    *(void**)(p + 0x59c) = lbl_8049CC34;
                }
            }
        }
        dtor_801D7730(p + 0x4c4, -1);
        dtor_801EB8CC(p + 0x464, -1);
        dtor_80217F80(p + 0x448, -1);
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

extern "C" void fn_801D47D8(void)
{
}

extern "C" void fn_801D4C70(u8* this_);
extern "C" void fn_801E4D74(void* this_);
extern "C" bool fn_801CD2F8(s32 id);
extern "C" void fn_801D5D84(void* this_, s32 state);
extern "C" void fn_80217CD8(void* p);

extern "C" void fn_801D4A84(u8* this_) {
    if (*(s32*)(this_ + 0x248) == 5) {
        fn_801E4D74(this_);
    }
    if (*(u32*)(this_ + 0x230) & 0x8000) {
        *(volatile u32*)(this_ + 0x230) &= 0xFFFF7FFF;
        if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
            fn_801D5D84(this_, 0x15);
        } else {
            fn_801D5D84(this_, 0x17);
        }
    } else if (*(s32*)(this_ + 0x248) == 0xb) {
        if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
            fn_801D5D84(this_, 0xf);
        } else {
            fn_80217CD8(this_ + 0x448);
            fn_801D5D84(this_, 0xc);
        }
    } else if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
        switch (*(s32*)(this_ + 0x248)) {
        case 0x11:
            break;
        case 0xf:
        case 0x10:
        case 0x12:
        case 0x13:
        case 0x14:
            fn_801D5D84(this_, 0xa);
            break;
        }
    } else if (*(s32*)(this_ + 0x108) > 0 && *(s32*)(this_ + 0x248) != 0x17) {
        fn_80217CD8(this_ + 0x448);
    }
}

extern const f32 lbl_8053F0C8;
extern const f32 lbl_8053F0E0;
extern const f32 lbl_8053F0E4;
extern const f32 lbl_8053F0E8;
extern const f32 lbl_8053F0EC;
extern const f32 lbl_8053F0F0;

extern "C" void fn_801D4BAC(u8* this_) {
    fn_801D4C70(this_);
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
        *(f32*)(this_ + 0x44) = lbl_8053F0E0;
        break;
    case 6:
        *(f32*)(this_ + 0x44) = lbl_8053F0E4;
        break;
    case 8:
        *(f32*)(this_ + 0x44) += lbl_8053F0E8;
        break;
    default:
        *(f32*)(this_ + 0x44) = lbl_8053F0C8;
        break;
    }
    if (*(s32*)(this_ + 0x248) == 5) {
        *(s16*)(this_ + 0x5d4) += 0x300;
        *(f32*)(this_ + 0x14) = lbl_8053F0F0 * JMASSin(*(s16*)(this_ + 0x5d4)) + lbl_8053F0EC;
    }
}

extern "C" void fn_801D5338(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 0xb) {
        goto skip;
    }
    if (state < 0xb) {
        if (state >= 8) {
            goto call;
        }
        if (state >= 6) {
            goto skip;
        }
        goto call;
    } else {
        if (state >= 0x1b) {
            goto call;
        }
        if (state >= 0x17) {
            goto skip;
        }
        goto call;
    }
call:
    fn_801D1C18((char*)this_ + 0x270);
skip:
    return;
}

extern "C" s32 fn_801D652C(void) {
    return fn_80458F9C(lbl_8053AF80, 0x3c);
}

extern "C" void* dtor_801D69FC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        if (p + 0x10 != 0) {
            if (p + 0x34 != 0) {
                *(void**)(p + 0x34) = lbl_8049CC34;
            }
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801D6A58(void* slot) {
    fn_801D7874(slot);
    return slot;
}

extern "C" void* fn_801D6A88(void* slot) {
    fn_8021BD18((char*)slot + 0xc, 2);
    fn_801D789C(slot);
    return slot;
}

extern "C" void* fn_801D0F40(void* this_);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void fn_80218020(void* p);
extern "C" void fn_801EB950(void* p);
extern "C" void fn_801D77B4(void* p);
extern "C" void fn_801E4B0C(void* p);
extern "C" void fn_801E6AB8(void* p);


extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_801EB418(void* p, Vec* pos);
extern "C" u8 fn_801EB648(void* p);
extern "C" void fn_801E5754(void* this_);
extern "C" void fn_801E4D88(void* this_);
extern "C" void fn_801D6E20(void* p, void* pos);
extern "C" void fn_801CE2BC(void* this_, void* arg);
extern "C" void fn_8021798C(void* p);

extern "C" void fn_801D5180(u8* this_, void* arg) {
    if (!(*(u32*)(this_ + 0x230) & 0x2000)) {
        switch (*(s32*)(this_ + 0x248)) {
        case 1:
        case 2:
        case 3:
            fn_801F0E34(this_, 0x4005e, 0);
            break;
        }
        if (this_[0x5ce] != 0) {
            this_[0x5ce]--;
            if (this_[0x5ce] == 0) {
                *(u32*)(this_ + 0x230) |= 0x4000;
            }
        }
        JGeometry::TVec3<f32> pos(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10), lbl_8053F0EC);
        fn_801EB418(this_ + 0x464, &pos);
        if (fn_801EB648(this_ + 0x464)) {
            fn_801F0E34(this_, 0x40051, 0);
        }
        fn_801E5754(this_);
        fn_801E4D88(this_);
    } else {
        fn_801D6E20(this_ + 0x4c4, this_ + 0xc);
        if (*(s32*)(this_ + 0x108) > 0 && !(*(u32*)(this_ + 0x230) & 7)
            && *(s32*)(this_ + 0x248) != 0xb && *(s32*)(this_ + 0x248) != 0x17)
        {
            fn_801F0E34(this_, 0x4005e, 0);
            switch (*(s32*)(this_ + 0x248)) {
            case 0xc:
            case 0xd:
                fn_801F0E34(this_, 0x4005f, 0);
                break;
            }
        }
    }
    bool doIt = false;
    switch (*(s32*)(this_ + 0x248)) {
    case 6:
    case 7:
        doIt = true;
        break;
    default:
        if (!(*(u32*)(this_ + 0x230) & 7)) {
            doIt = true;
        }
        break;
    }
    if (doIt) {
        fn_801CE2BC(this_, arg);
    }
    fn_8021798C(this_ + 0x448);
}

struct BogfA { u8 b[0x18]; };
struct BogfB { u8 b[0x14]; };
struct BogfBody {
    u8 pad[0x2a8];
    BogfA mA[4];
    BogfB mB[16];
    void initA(int i) { fn_801D789C(&mA[i]); }
    void initB(int i) { fn_801D7874(&mB[i]); }
};

extern "C" u8* fn_801D686C(u8* this_) {
    s32 i;
    s32 off = 0;
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4958;
    __construct_array(this_ + 0x2a8, (void*)fn_801D6A88, NULL, 0x18, 4);
    __construct_array(this_ + 0x308, (void*)fn_801D6A58, NULL, 0x14, 0x10);
    fn_80218020(this_ + 0x448);
    fn_801EB950(this_ + 0x464);
    fn_801D77B4(this_ + 0x4c4);
    fn_801E4B0C(this_ + 0x52c);
    fn_801E4B0C(this_ + 0x540);
    fn_801E4B0C(this_ + 0x554);
    fn_801E6AB8(this_ + 0x568);
    *(s32*)(this_ + 0x5b0) = -1;
    *(s32*)(this_ + 0x5b4) = off;
    *(s32*)(this_ + 0x5b8) = off;
    *(f32*)(this_ + 0x5bc) = lbl_8053F0C8;
    *(f32*)(this_ + 0x5c0) = lbl_8053F0C8;
    *(f32*)(this_ + 0x5c4) = lbl_8053F0C8;
    *(f32*)(this_ + 0x5c8) = lbl_8053F0C8;
    this_[0x5cc] = off;
    this_[0x5cd] = off;
    this_[0x5ce] = off;
    this_[0x5cf] = off;
    this_[0x5d0] = off;
    this_[0x5d1] = off;
    *(s16*)(this_ + 0x5d2) = off;
    *(s16*)(this_ + 0x5d4) = off;
    *(s32*)(this_ + 0x5d8) = off;
    *(s32*)(this_ + 0x5dc) = off;
    *(f32*)(this_ + 0x5e0) = lbl_8053F0C8;
    *(f32*)(this_ + 0x5e4) = lbl_8053F0C8;
    this_[0x5e8] = off;
    this_[0x5e9] = off;
    *(f32*)(this_ + 0x5ec) = lbl_8053F0C8;
    *(f32*)(this_ + 0x5f0) = lbl_8053F0C8;
    *(f32*)(this_ + 0x5f4) = lbl_8053F0C8;
    *(f32*)(this_ + 0x5f8) = lbl_8053F0C8;
    *(s32*)(this_ + 0x5fc) = off;
    *(f32*)(this_ + 0x600) = lbl_8053F0C8;
    *(f32*)(this_ + 0x604) = lbl_8053F0C8;
    *(f32*)(this_ + 0x608) = lbl_8053F0C8;
    *(f32*)(this_ + 0x60c) = lbl_8053F0C8;
    *(f32*)(this_ + 0x610) = lbl_8053F0C8;
    *(f32*)(this_ + 0x614) = lbl_8053F0C8;
    for (i = 0; i < 4; i++) {
        fn_801D789C(this_ + (off + 0x2a8));
        off += 0x18;
    }
    i = 0;
    off = i;
    for (; i < 16; i++) {
        fn_801D7874(this_ + (off + 0x308));
        off += 0x14;
    }
    *(u8**)(this_ + 0x460) = this_;
    return this_;
}

extern const f32 lbl_8053F0D8;
extern const f32 lbl_8053F0FC;
extern const f32 lbl_8053F134;
extern const f32 lbl_8053F138;

struct BogfGame;
extern BogfGame* lbl_8053AAF8;
struct BogfRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053F0D8;
    }
};
struct BogfGame { u8 pad[0xb4]; BogfRandom rnd; };
static inline f32 bogfRand() { return lbl_8053AAF8->rnd.get_ufloat_1(); }
static inline f32 bogfRandF(f32 s) { return s * lbl_8053AAF8->rnd.get_ufloat_1(); }
static inline f32 bogfRandPM(f32 s) { return s * (lbl_8053F138 * lbl_8053AAF8->rnd.get_ufloat_1() - lbl_8053F0D8); }

struct BogfRupy {
    u8 pad[0x3c];
    JGeometry::TVec3<f32> mVel;
};

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* mgr, u32 kind, s32 room, void* pos, s32 n);
extern "C" void* fn_801F666C(void* mgr, s32 id);

extern "C" void fn_801D63D0(u8* this_) {
    for (s32 i = 0; i < 5; i++) {
        s32 id = fn_801F8544(fn_801F856C(), 'RUPY', *(s32*)(this_ + 0x4), this_ + 0xc, 2);
        if (id >= 0) {
            BogfRupy* rupy = (BogfRupy*)fn_801F666C(fn_801F856C(), id);
            if (rupy != NULL) {
                JGeometry::TVec3<f32> v;
                f32 z = lbl_8053F0FC * lbl_8053AAF8->rnd.get_ufloat_1() + lbl_8053F0FC;
                f32 y = lbl_8053F134 * (lbl_8053F138 * lbl_8053AAF8->rnd.get_ufloat_1() - lbl_8053F0D8);
                f32 x = lbl_8053F134 * (lbl_8053F138 * lbl_8053AAF8->rnd.get_ufloat_1() - lbl_8053F0D8);
                v.set(x, y, z);
                rupy->mVel = v;
            }
        }
    }
}


extern const f32 lbl_8053F0D0;
extern const f32 lbl_8053F120;
extern const f32 lbl_8053F124;
extern const f32 lbl_8053F128;
extern "C" s32 fn_801D05F8(void* this_, void* pos, f32 range);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);

static inline void bogfAim(u8* this_, JGeometry::TVec2<f32>* dst, f32 tx, f32 ty) {
    if (dst != NULL) {
        JGeometry::TVec2<f32> d(tx - *(f32*)(this_ + 0xc), ty - *(f32*)(this_ + 0x10));
        if (d.squared() <= lbl_8053F0D0 * FLT_EPSILON) {
            d.set(lbl_8053F0D8, lbl_8053F0C8);
        }
        f32 sq = d.squared();
        if (!(sq <= lbl_8053F0D0 * FLT_EPSILON)) {
            d.scale(JGeometry::TUtilf::inv_sqrt(sq));
        }
        dst->x = *(f32*)(this_ + 0xc);
        d.scale(lbl_8053F128);
        dst->y = *(f32*)(this_ + 0x10);
        dst->add(d);
    }
}

extern "C" void fn_801D5B70(u8* this_) {
    if (*(s32*)(this_ + 0x24c) < *(s32*)(this_ + 0x250)) {
        return;
    }
    if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
        if (this_[0x5d0] == 0) {
            fn_801D5D84(this_, 0x15);
        } else {
            if (lbl_8053AAF8->rnd.get_ufloat_1() < lbl_8053F120) {
                bool found = false;
                s32 player = fn_801D05F8(this_, this_ + 0xc, lbl_8053F124);
                if (player >= 0) {
                    JGeometry::TVec3<f32>* target = fn_8023E724(player);
                    f32 tx = target->x;
                    f32 ty = target->y;
                    found = true;
                    bogfAim(this_, (JGeometry::TVec2<f32>*)(this_ + 0x5c4), tx, ty);
                }
                if (found) {
                    fn_801D5D84(this_, 0x11);
                    return;
                }
            }
            fn_801D5D84(this_, 0xf);
        }
    } else if (this_[0x5d0] == 0) {
        if (*(s32*)(this_ + 0x108) <= 0xc) {
            fn_801D5D84(this_, 0xc);
        } else {
            fn_801D5D84(this_, 0x17);
        }
    } else {
        fn_801D5D84(this_, 0xc);
    }
}


extern const f32 lbl_8053F0F4;
extern const f32 lbl_8053F0F8;
extern const f32 lbl_8053F100;
extern "C" void fn_801D01A0(void* this_, void* target, JGeometry::TVec2<f32>* out, f32 speed);
extern "C" void fn_801F71A4(f32* p, f32 target, f32 a, f32 b);

extern "C" void fn_801D4C70(u8* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0x11:
        *(f32*)(this_ + 0x3c) = lbl_8053F0C8;
        *(f32*)(this_ + 0x40) = lbl_8053F0C8;
        return;
    case 0x15: {
        JGeometry::TVec2<f32> v;
        fn_801D01A0(this_, this_ + 0x5ec, &v, lbl_8053F0F4);
        *(f32*)(this_ + 0x3c) = v.x;
        *(f32*)(this_ + 0x40) = v.y;
        return;
    }
    case 0x16: {
        JGeometry::TVec2<f32> v;
        fn_801D01A0(this_, this_ + 0x5f4, &v, lbl_8053F0F8);
        *(f32*)(this_ + 0x3c) = v.x;
        *(f32*)(this_ + 0x40) = v.y;
        return;
    }
    }
    if (this_[0x5d1] != 0) {
        s16 ang = *(s16*)(this_ + 0x5d2);
        f32 k = lbl_8053F0E4;
        f32 s = JMASSin(ang);
        f32 c = JMASCos(ang);
        *(f32*)(this_ + 0x3c) = k * s;
        *(f32*)(this_ + 0x40) = k * c;
        return;
    }
    JGeometry::TVec2<f32> vel(lbl_8053F0C8, lbl_8053F0C8);
    bool move = true;
    f32 tx, ty;
    switch (*(s32*)(this_ + 0x248)) {
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
        move = false;
        break;
    case 0x12:
    case 0x13:
    case 0x14:
        tx = *(f32*)(this_ + 0x5c4);
        ty = *(f32*)(this_ + 0x5c8);
        break;
    default:
        if (*(s32*)(this_ + 0x5b0) >= 0) {
            JGeometry::TVec3<f32>* p = fn_8023E724(*(s32*)(this_ + 0x5b0));
            tx = p->x;
            ty = p->y;
        } else {
            tx = *(f32*)(this_ + 0x5bc);
            ty = *(f32*)(this_ + 0x5c0);
        }
        break;
    }
    if (move) {
        vel.set(tx - *(f32*)(this_ + 0xc), ty - *(f32*)(this_ + 0x10));
        vel.normalize();
        if (*(s32*)(this_ + 0x248) == 0x12) {
            vel.scale(lbl_8053F0E0);
        } else {
            vel.scale(*(f32*)(this_ + 0x254));
        }
    }
    fn_801F71A4((f32*)(this_ + 0x3c), vel.x, lbl_8053F100, lbl_8053F0D8);
    fn_801F71A4((f32*)(this_ + 0x40), vel.y, lbl_8053F100, lbl_8053F0D8);
}


extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_8030C210(void* cam, JGeometry::TVec3<f32>* pos);
extern u8* lbl_8053AB10;
extern const f32 lbl_8053F0CC;
extern const f32 lbl_8053F0D4;
extern const f32 lbl_8053F0DC;

extern "C" void fn_801D47DC(u8* this_) {
    s32 room = *(s32*)(this_ + 0x4);
    u8* g = fn_802D6A9C();
    f32* rect;
    if (room < 8) {
        rect = (f32*)(g + 0xcc);
    } else {
        rect = (f32*)(g + 0xdc);
    }
    JGeometry::TVec3<f32> pos(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14), lbl_8053F0C8);
    f32 lim = lbl_8053F0CC + rect[1];
    pos.y = (lim - pos.y >= 0.0f) ? lim : pos.y;
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 0x17:
        break;
    case 1: {
        JGeometry::TVec3<f32> c0(lbl_8053F0D0 + rect[0], lbl_8053F0D0 + rect[1], lbl_8053F0C8);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &c0);
        JGeometry::TVec3<f32> c1(rect[2] - lbl_8053F0D0, lbl_8053F0D0 + rect[1], lbl_8053F0C8);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &c1);
        JGeometry::TVec3<f32> c2(lbl_8053F0D0 + rect[0], rect[3] - lbl_8053F0D0, lbl_8053F0C8);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &c2);
        JGeometry::TVec3<f32> c3(rect[2] - lbl_8053F0D0, rect[3] - lbl_8053F0D0, lbl_8053F0C8);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &c3);
        break;
    }
    case 2:
    case 3: {
        u8* p = *(u8**)(lbl_8053AB10 + 0x30);
        if (p[0x284] == 0) {
            p[0x284] = 1;
            *(f32*)(p + 0x28c) = lbl_8053F0D4;
        }
        u8* cam = *(u8**)(lbl_8053AB10 + 0x24);
        if (cam[0x7f5] == 0) {
            cam[0x7f4] = 1;
            *(s32*)(cam + 0x7f8) = 4;
            *(JGeometry::TVec3<f32>*)(cam + 0x7fc) = pos;
            cam[0x7f6] = 0;
        }
        break;
    }
    case 0x19: {
        u8* cam = *(u8**)(lbl_8053AB10 + 0x24);
        if (cam[0x840] == 0) {
            cam[0x840] = 1;
            *(f32*)(cam + 0x84c) = pos.x;
            *(f32*)(cam + 0x844) = pos.x;
            *(f32*)(cam + 0x850) = pos.y;
            *(f32*)(cam + 0x848) = pos.y;
            *(f32*)(cam + 0x854) = lbl_8053F0D8;
            *(f32*)(cam + 0x1d4) = lbl_8053F0DC;
            *(f32*)(cam + 0x1d8) = lbl_8053F0DC;
        }
        (*(u8**)(lbl_8053AB10 + 0x20))[0x216] = 1;
        break;
    }
    case 0x1a: {
        u8* cam = *(u8**)(lbl_8053AB10 + 0x24);
        if (cam[0x7f5] == 0) {
            cam[0x7f4] = 1;
            *(s32*)(cam + 0x7f8) = -1;
            cam[0x7f6] = 0;
        }
        (*(u8**)(lbl_8053AB10 + 0x20))[0x216] = 1;
        break;
    }
    default: {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &pos);
        u8* cam = *(u8**)(lbl_8053AB10 + 0x24);
        if (cam[0x179] == 0) {
            cam[0x178] = 1;
        }
        break;
    }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
