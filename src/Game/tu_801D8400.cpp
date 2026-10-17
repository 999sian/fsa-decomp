// Game TU 801D8400-801DA7C0 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801D9C58(char* this_, s32 newState);
extern "C" {
}
extern const f32 lbl_8053F1CC;
extern "C" void fn_801CE694(void* this_);
extern "C" void fn_801CE2BC(void* this_);
extern "C" void fn_801E61C4(void* this_);
struct ActorSlot37 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void slot37();
};
extern void* lbl_8053AF80;
extern "C" s32 fn_80458F9C(void* mgr, s32 handle);

extern "C" void fn_801D8400(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state < 8) {
        fn_801D9C58((char*)this_, 8);
    }
}

extern "C" void fn_801D84E0(void)
{
}

extern "C" void fn_801D8980(void* this_) {
    if (*(f32*)((char*)this_ + 0x10) > *(f32*)((char*)this_ + 0x2d0)) {
        *(f32*)((char*)this_ + 0x10) = *(f32*)((char*)this_ + 0x2d0);
        *(f32*)((char*)this_ + 0x40) = lbl_8053F1CC;
    }
    fn_801CE694(this_);
}

extern "C" void fn_801D89BC(void* this_) {
    u32 flags = *(u32*)((char*)this_ + 0x230);
    if ((flags & 7) == 0) {
        fn_801CE2BC(this_);
    } else {
        s32 state = *(s32*)((char*)this_ + 0x248);
        if (state == 0xf) {
            ((ActorSlot37*)this_)->slot37();
        }
    }
    u16 timer = *(u16*)((char*)this_ + 0x336);
    if (timer != 0) {
        *(u16*)((char*)this_ + 0x336) = timer - 1;
    }
    fn_801E61C4(this_);
}

extern "C" s32 fn_801DA0FC(void) {
    return fn_80458F9C(lbl_8053AF80, 0x3c);
}

#include "JSystem/JGeometry/Vec.h"
extern char* lbl_8053AB10;
extern const f32 lbl_8053F1D0;
extern const f32 lbl_8053F1D4;
extern const f32 lbl_8053F1D8;
extern const f32 lbl_8053F1DC;
extern const f32 lbl_8053F1E0;
extern "C" void fn_801CDD58(void* this_);
extern "C" void fn_8030C210(void* obj, void* pos);
extern "C" void* fn_801D0F40(void* this_);
extern "C" void fn_801DAA24(void* p);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec2_f_Fv();
extern "C" void fn_801EE434(void* handle);
extern "C" s32* fn_801DAC6C();
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7440(void* game, s32 a);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4C58[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct Slot11 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual u8 slot9(f32 a, f32 b, f32 c);
};

extern "C" void fn_801D8430(char* p) {
    if (((Slot11*)p)->slot9(lbl_8053F1CC, lbl_8053F1D0, lbl_8053F1D4)) {
        char* cam = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(cam + 0x840) == 0) {
            *(u8*)(cam + 0x840) = 1;
            *(f32*)(cam + 0x844) = *(f32*)(cam + 0x84c) = *(f32*)(p + 0xc);
            *(f32*)(cam + 0x848) = *(f32*)(cam + 0x850) = *(f32*)(p + 0x10);
            *(f32*)(cam + 0x854) = lbl_8053F1D8;
            *(f32*)(cam + 0x1d4) = lbl_8053F1DC;
            *(f32*)(cam + 0x1d8) = lbl_8053F1DC;
        }
        *(u8*)(*(char**)(lbl_8053AB10 + 0x20) + 0x216) = 1;
    } else {
        fn_801CDD58(p);
    }
}

extern "C" void fn_801D84E4(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0:
        break;
    case 1:
    case 2:
    case 3: {
        char* a = *(char**)(lbl_8053AB10 + 0x30);
        if (*(u8*)(a + 0x284) == 0) {
            *(u8*)(a + 0x284) = 1;
            *(f32*)(a + 0x28c) = lbl_8053F1E0;
        }
        char* cam = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(cam + 0x7f5) == 0) {
            *(u8*)(cam + 0x7f4) = 1;
            *(s32*)(cam + 0x7f8) = 4;
            *(f32*)(cam + 0x7fc) = *(f32*)(p + 0xc);
            *(f32*)(cam + 0x800) = *(f32*)(p + 0x10);
            *(f32*)(cam + 0x804) = *(f32*)(p + 0x14);
            *(u8*)(cam + 0x7f6) = 0;
        }
        break;
    }
    default: {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
        char* cam = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(cam + 0x179) == 0) {
            *(u8*)(cam + 0x178) = 1;
        }
        break;
    }
    }
}

extern "C" void* fn_801DA438(char* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_804A4C58;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x2c0 + i * 4));
            *(void**)(p + 0x2c0 + i * 4) = 0;
        }
        s32* h = fn_801DAC6C();
        *h = -1;
        fn_802D7440(fn_802D6A9C(), 1);
        if (p != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(p, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_801DA504(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A4C58;
    fn_801DAA24(p + 0x2a8);
    *(f32*)(p + 0x2d0) = lbl_8053F1CC;
    __construct_array(p + 0x2d4, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 0xc);
    *(u8*)(p + 0x334) = 0;
    *(u16*)(p + 0x336) = 0;
    *(u16*)(p + 0x338) = 0;
    *(u16*)(p + 0x33a) = 0;
    *(u16*)(p + 0x33c) = 0;
    *(u8*)(p + 0x33e) = 0;
    *(u8*)(p + 0x33f) = 0;
    *(s32*)(p + 0x2c0) = 0;
    *(s32*)(p + 0x2c4) = 0;
    *(s32*)(p + 0x2c8) = 0;
    *(s32*)(p + 0x2cc) = 0;
    return p;
}

extern "C" s32 fn_801DA96C(void* p);
extern "C" void fn_801DA7C0(void* p);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" void fn_801DE12C(void* this_);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);
extern const f32 lbl_8053F1F0;
extern f32 lbl_8053EFB8;

extern "C" void fn_801D882C(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe: {
        JGeometry::TVec2<f32>* tgt = (JGeometry::TVec2<f32>*)(p + 0x2d4) + *(u8*)(p + 0x334);
        JGeometry::TVec2<f32> dir(tgt->x - *(f32*)(p + 0xc), tgt->y - *(f32*)(p + 0x10));
        dir.normalize();
        dir.scale(*(f32*)(p + 0x254));
        fn_801F71A4((f32*)(p + 0x3c), dir.x, lbl_8053F1F0, lbl_8053F1D8);
        fn_801F71A4((f32*)(p + 0x40), dir.y, lbl_8053F1F0, lbl_8053F1D8);
        break;
    }
    default:
        *(f32*)(p + 0x3c) = lbl_8053F1CC;
        switch (*(s32*)(p + 0x248)) {
        case 8:
        case 0x10:
        {
            f32 kick = __fabsf(lbl_8053EFB8);
            f32 vy = *(f32*)(p + 0x40);
            *(f32*)(p + 0x40) = vy + kick;
        }
            break;
        default:
            *(f32*)(p + 0x40) = lbl_8053F1CC;
            break;
        }
        break;
    }
    *(f32*)(p + 0x44) = lbl_8053F1CC;
}

extern "C" void fn_801D8A30(char* p) {
    bool snd = false;
    s32 prev = fn_801DA96C(p + 0x2a8);
    fn_801DA7C0(p + 0x2a8);
    switch (*(s32*)(p + 0x2a8)) {
    case 8:
        if (prev != 0x1e && fn_801DA96C(p + 0x2a8) == 0x1e) {
            snd = true;
        }
        break;
    case 0xe:
        if (prev != 0x2c && fn_801DA96C(p + 0x2a8) == 0x2c) {
            snd = true;
        }
        break;
    case 0xf:
        if (prev != 0x2f && fn_801DA96C(p + 0x2a8) == 0x2f) {
            snd = true;
        }
        break;
    }
    if (snd) {
        fn_801F0E34(p, 0x40058, 0);
    }
    fn_801DE12C(p);
}

extern "C" s32 fn_801CD664(s32 n);

struct T84List {
    T84List() : n(0) {}
    void add(s32 x) {
        v[n] = x;
        n++;
    }
    s32 v[11];
    s32 n;
};

static inline void t84PickTarget(char* p) {
    if (*(u8*)(p + 0x33f) == 3) {
                            s32 l[12];
          s32 n = 1;
          l[0] = 1;
          l[n++] = 2;
          l[n++] = 5;
          l[n++] = 6;
          l[n++] = 9;
          l[n++] = 10;
          if (n > 0) {
              *(u8*)(p + 0x334) = l[fn_801CD664(n)];
          } else {
              *(u8*)(p + 0x334) = 0;
          }
    } else {
        *(u8*)(p + 0x334) = fn_801CD664(0xc);
    }
    *(u16*)(p + 0x338) = fn_801CD664(0x3d) + 0x3c;
}

s32 l[6];
extern "C" void fn_801D85B0(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
        if (*(s32*)(p + 0x248) == 0xc) {
            t84PickTarget(p);
            bool left = false;
            f32 tx = ((JGeometry::TVec2<f32>*)(p + 0x2d4))[*(u8*)(p + 0x334)].x;
            f32 x = *(f32*)(p + 0xc);
            if (x < tx || (x == tx && (*(u32*)(p + 0x230) & 0x2000))) {
                left = true;
            }
            if (left) {
                *(u32*)(p + 0x230) &= ~0x2000;
            } else {
                *(u32*)(p + 0x230) |= 0x2000;
            }
        } else {
            t84PickTarget(p);
            bool turn = false;
            bool left = false;
            f32 tx = ((JGeometry::TVec2<f32>*)(p + 0x2d4))[*(u8*)(p + 0x334)].x;
            f32 x = *(f32*)(p + 0xc);
            if (x < tx || (x == tx && (*(u32*)(p + 0x230) & 0x2000))) {
                left = true;
            }
            if (left) {
                if (!(*(u32*)(p + 0x230) & 0x2000)) {
                    turn = true;
                }
            } else {
                if (*(u32*)(p + 0x230) & 0x2000) {
                    turn = true;
                }
            }
            if (turn) {
                fn_801D9C58(p, 0xc);
            } else {
                fn_801D9C58(p, 0xb);
            }
        }
        break;
    }
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801CCCC4(JGeometry::TVec2<f32>* v);
extern "C" void fn_801DA9E8(void* p, s32 a, s32 b);
extern "C" void fn_801E63D8(void* this_);
extern "C" void fn_801DAF44(s32* mgr, u32 id);
extern const f32 lbl_8053F1E4;
extern const f32 lbl_8053F1E8;
extern const f32 lbl_8053F1F4;
extern const f32 lbl_8053F1F8;
extern const f32 lbl_8053F228;
extern const f32 lbl_8053F22C;
extern const f32 lbl_8053F230;

struct T84Slot19 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual u8 v17(u32 room, JGeometry::TVec3<f32>* pos);
};

inline void t84Row(char* p, s32 n, f32 x, f32 y) {
    for (s32 j = 0; j < 4; j++) {
        ((JGeometry::TVec2<f32>*)(p + 0x2d4))[n + j].set(x, y);
        x += lbl_8053F1F4;
    }
}
struct T84 { u8 pad[0x2d4]; JGeometry::TVec2<f32> mTbl[12]; };

extern "C" void fn_801DA124(char* p) {
    fn_801D0ED0(p);
    *(f32*)(p + 0x60) = lbl_8053F1D8;
    *(f32*)(p + 0x64) = lbl_8053F1D8;
    *(f32*)(p + 0x68) = lbl_8053F1DC;
    *(f32*)(p + 0x6c) = lbl_8053F1DC;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = lbl_8053F1D8;
    *(f32*)(p + 0x84) = lbl_8053F1D8;
    *(f32*)(p + 0x88) = lbl_8053F1DC;
    *(f32*)(p + 0x8c) = lbl_8053F1DC;
    *(s32*)(p + 0xb0) = 0x40004;
    *(s32*)(p + 0x98) = 2;
    *(u32*)(p + 0x230) |= 0x2a0;
    *(s32*)(p + 0x108) = 0x8c;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(s32*)(p + 0x114) = 0;
    *(u8*)(p + 0x196) = 1;
    s32 room = *(s32*)(p + 4);
    char* game = (char*)fn_802D6A9C();
    char* area;
    if (room < 8) {
        area = game + 0xcc;
    } else {
        area = game + 0xdc;
    }
    JGeometry::TVec2<f32> v(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    while (v.y < *(f32*)(area + 0xc)) {
        JGeometry::TVec3<f32> pos(v.x, v.y, lbl_8053F1CC);
        if (((T84Slot19*)p)->v17(*(u32*)(p + 4), &pos)) {
            fn_801CCCC4(&v);
            v.y += lbl_8053F228;
            break;
        }
        v.y += lbl_8053F1F8;
    }
    *(f32*)(p + 0x2d0) = v.y;
    f32 x0 = *(f32*)(p + 0x24) - lbl_8053F22C;
    f32 y = lbl_8053F1E4 + *(f32*)(p + 0x28);
    f32 dy = lbl_8053F1E8 * ((*(f32*)(p + 0x2d0) - lbl_8053F230) - y);
    t84Row(p, 0, x0, y);
    y += dy;
    t84Row(p, 4, x0, y);
    y += dy;
    t84Row(p, 8, x0, y);
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = lbl_8053F1CC;
    *(f32*)(p + 0x258) = lbl_8053F1CC;
    fn_801DA9E8(p + 0x2a8, 0, 2);
    fn_801E63D8(p);
    fn_801DAF44(fn_801DAC6C(), *(u32*)(p + 0x198));
    fn_802D7440(fn_802D6A9C(), 0);
}

extern "C" void fn_801DA994(void* p, s32 a, s32 b);
extern "C" void fn_801E6394(void* this_);
extern "C" void fn_801E631C(void* this_);
extern "C" void fn_801DAE24(s32* mgr);
extern const f32 lbl_8053F224;

static inline void t84ResetTarget(char* p, f32 v) {
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x258) = v;
}

extern "C" void fn_801D9C58(char* p, s32 state) {
    *(u16*)(p + 0x336) = 0;
    if (*(s32*)(p + 0x248) == 0x11) {
        *(u32*)(p + 0x230) &= ~0x80;
    }
    switch (state) {
    case 0:
    case 1:
        break;
    case 2:
        fn_801DA9E8(p + 0x2a8, 3, 0);
        fn_801F0E34(p, 0x40052, 0);
        break;
    case 3:
        fn_801DA9E8(p + 0x2a8, 4, 0);
        fn_801F0E34(p, 0x4005d, 0);
        break;
    case 4:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA994(p + 0x2a8, 0, 2);
        break;
    case 5:
        t84ResetTarget(p, lbl_8053F1CC);
        switch (*(s32*)(p + 0x248)) {
        case 6:
        case 7:
            fn_801DA9E8(p + 0x2a8, 2, 0);
            break;
        default:
            fn_801DA9E8(p + 0x2a8, 1, 0);
            break;
        }
        fn_801F0E34(p, 0x40052, 0);
        break;
    case 6:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 3, 0);
        fn_801F0E34(p, 0x40052, 0);
        break;
    case 7:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 4, 0);
        fn_801F0E34(p, 0x4005d, 0);
        if (*(s32*)(p + 0x248) == 5) {
            *(u32*)(p + 0x230) |= 0x4000;
        } else {
            *(u32*)(p + 0x230) &= ~0x4000;
        }
        break;
    case 8:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 5, 0);
        fn_801F0E34(p, 0x40056, 0);
        fn_801E6394(p);
        fn_801E631C(p);
        break;
    case 9:
        *(u32*)(p + 0x230) &= ~0x280;
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 6, 0);
        fn_801F0E34(p, 0x40057, 0);
        fn_801E631C(p);
        break;
    case 10:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 7, 0);
        break;
    case 11:
        t84ResetTarget(p, lbl_8053F224);
        fn_801DA994(p + 0x2a8, 8, 2);
        if (*(s32*)(p + 0x248) != 0xc) {
            *(u16*)(p + 0x33c) = fn_801CD664(0xf1) + 0x78;
        }
        break;
    case 12:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 9, 0);
        break;
    case 13:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 0xe, 0);
        break;
    case 14:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 0xf, 0);
        break;
    case 15:
        *(u8*)(p + 0x33f) = 0;
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 0xa, 0);
        break;
    case 16:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 0xb, 0);
        break;
    case 17:
        *(u32*)(p + 0x230) |= 0x80;
        *(s32*)(p + 0x250) = -1;
        *(u16*)(p + 0x336) = fn_801CD664(1) + 0xf0;
        *(f32*)(p + 0x258) = lbl_8053F1CC;
        fn_801DA994(p + 0x2a8, 0xc, 2);
        fn_801F0E34(p, 0x40057, 0);
        fn_801E631C(p);
        break;
    case 18:
        t84ResetTarget(p, lbl_8053F1CC);
        fn_801DA9E8(p + 0x2a8, 0xd, 0);
        break;
    case 19:
        *(f32*)(p + 0x60) = lbl_8053F1D8;
        *(f32*)(p + 0x64) = lbl_8053F1D8;
        *(f32*)(p + 0x68) = lbl_8053F1DC;
        *(f32*)(p + 0x6c) = lbl_8053F1DC;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x258) = lbl_8053F1CC;
        *(f32*)(p + 0x254) = lbl_8053F1CC;
        *(f32*)(p + 0x3c) = lbl_8053F1CC;
        *(f32*)(p + 0x40) = lbl_8053F1CC;
        *(f32*)(p + 0x44) = lbl_8053F1CC;
        *(s32*)(p + 0xd8) = 0x10;
        *(s32*)(p + 0xdc) = 0x10;
        fn_801F0E34(p, 0x4005a, 0);
        break;
    case 20:
        fn_801DAE24(fn_801DAC6C());
        break;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
}

#include "JSystem/JMath/JMath.h"
extern "C" s32 fn_801D0338(void* this_, JGeometry::TVec3<f32>* pos, s16 ang);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);
extern "C" u8 fn_801DA894(void* p);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* mgr, u32 type, s32 room, JGeometry::TVec3<f32>* pos, s32 a, s32 b, s32 c);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern const f32 lbl_8053F200;
extern const f32 lbl_8053F204;
extern const f32 lbl_8053F208;
extern const f32 lbl_8053F20C;
extern const f32 lbl_8053F220;

static inline void t84FrontPos(char* p, JGeometry::TVec3<f32>* v) {
    if (*(u32*)(p + 0x230) & 0x2000) {
        v->set(*(f32*)(p + 0xc) - lbl_8053F204, lbl_8053F200 + *(f32*)(p + 0x10), lbl_8053F1CC);
    } else {
        v->set(lbl_8053F204 + *(f32*)(p + 0xc), lbl_8053F200 + *(f32*)(p + 0x10), lbl_8053F1CC);
    }
}

static inline s16 t84FaceAngle(char* p) {
    return (*(u32*)(p + 0x230) & 0x2000) ? 0x2000 : -0x2000;
}

static inline s32 t84FindPlayer(char* p) {
    JGeometry::TVec3<f32> v;
    t84FrontPos(p, &v);
    s16 ang = t84FaceAngle(p);
    s32 pl = fn_801D0338(p, &v, ang);
    s32 found = -1;
    if (pl >= 0) {
        f32 dy = fn_8023E724(pl)->y - v.y;
        f32 a = JMAAtan2Radian(fn_8023E724(pl)->x - v.x, dy);
        s16 d = ang - (s16)(a * lbl_8053F208);
        if (lbl_8053F20C * __fabsf(d) <= lbl_8053F1F0) {
            found = pl;
        }
    }
    return found;
}

extern "C" void fn_801D9960(char* p) {
    if (*(u16*)(p + 0x33c) != 0) {
        (*(u16*)(p + 0x33c))--;
    }
    if (*(u16*)(p + 0x33c) == 0) {
        if (t84FindPlayer(p) >= 0 && fn_801DA894(p + 0x2a8)) {
            fn_801D9C58(p, 0xd);
        }
    }
    if (*(s32*)(p + 0x248) == 0xb) {
        (*(u16*)(p + 0x338))--;
        if (*(u16*)(p + 0x338) == 0) {
            t84PickTarget(p);
            bool turn = false;
            bool left = false;
            f32 x = *(f32*)(p + 0xc);
            f32 tx = ((JGeometry::TVec2<f32>*)(p + 0x2d4))[*(u8*)(p + 0x334)].x;
            if (x < tx || (x == tx && (*(u32*)(p + 0x230) & 0x2000))) {
                left = true;
            }
            if (left) {
                if (!(*(u32*)(p + 0x230) & 0x2000)) {
                    turn = true;
                }
            } else {
                if (*(u32*)(p + 0x230) & 0x2000) {
                    turn = true;
                }
            }
            if (turn) {
                fn_801D9C58(p, 0xc);
            }
        }
    }
}

extern "C" BOOL fn_801D95F4(char* p) {
    BOOL ok = FALSE;
    JGeometry::TVec3<f32> pos;
    t84FrontPos(p, &pos);
    s32 id = Actor_CreateByID(fn_801F856C(), 0x424f4942, *(s32*)(p + 4), &pos, 0, -1, -1);
    if (id >= 0) {
        char* a = fn_801F666C(fn_801F856C(), id);
        if (a != NULL) {
            s32 pl = t84FindPlayer(p);
            JGeometry::TVec2<f32> dir;
            if (pl >= 0) {
                dir.y = fn_8023E724(pl)->y - pos.y;
                dir.x = fn_8023E724(pl)->x - pos.x;
                if (dir.squared() <= JGeometry::TUtilf::epsilon()) {
                    dir.set(lbl_8053F1D8, lbl_8053F1CC);
                } else {
                    dir.normalize();
                }
            } else {
                s16 ang = -t84FaceAngle(p);
                f32 sn = JMASSin(ang);
                f32 cs = JMASCos(ang);
                dir.x = lbl_8053F1CC * cs - lbl_8053F1D8 * sn;
                dir.y = lbl_8053F1CC * sn + lbl_8053F1D8 * cs;
            }
            s16 r = -(s16)(fn_801CD664(0xe39) - 0x71c);
            f32 sn = JMASSin(r);
            f32 cs = JMASCos(r);
            JGeometry::TVec3<f32> vel((dir.x * cs - dir.y * sn) * lbl_8053F220, (dir.x * sn + dir.y * cs) * lbl_8053F220, lbl_8053F1CC);
            *(JGeometry::TVec3<f32>*)(a + 0x3c) = vel;
            ok = TRUE;
        }
    }
    return ok;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
