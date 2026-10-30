// Game TU 801C26D8-801C5B08 (SLK2). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry.h"
extern void* lbl_804A46F4[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void* fn_801C0D70();
extern "C" void fn_801C1374(void* subRecord, s32 flag);
extern "C" void fn_801F4F28(void* this_);
extern "C" void fn_801C3B7C(void* this_, s32 state);
extern "C" u8 fn_8021D020(void* this_);
extern "C" void fn_8021CDE4(void* this_, s32 state);
extern "C" void fn_80214AF8(void* this_);
extern "C" u8 fn_801C11F0(void* rec);
extern "C" s32 fn_801D05F8(void* this_, f32 r, void* pos);
extern "C" u8 fn_801D0D50(void* this_, s32 idx, void* pos, f32 r);
extern "C" void fn_801C1440(void* rec, u32 v);
extern "C" void dtor_80214F9C(void* p, s32 flag);
extern void* lbl_804A43E8[];
extern const f32 lbl_8053EE08;
extern u16 lbl_8046A748;
extern const f32 lbl_8053EE14;
extern const f32 lbl_8053EE20;
extern const f32 lbl_8053EE28;
extern f32 lbl_8053EE50;
extern "C" void fn_80214900(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern void* lbl_8053AC98;
extern "C" void fn_801C12B8(void* rec);
extern const f32 lbl_8053EFB8;
extern const f32 lbl_8053EE08;
extern const f32 lbl_8053EE0C;
extern const f32 lbl_8053EE10;
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];
extern "C" void fn_801D1974(void* this_);
extern "C" void Slk2_ResetFlags7(void* p);
extern "C" void Slk2_InitVtablePairRecord(void* p);
extern "C" void Slk2_ResetBlock0x0(void* p);
extern "C" void fn_80217128(void* p);
extern "C" void fn_80218A8C(void* p);
extern "C" void ResetFlagBlock3c_Zero(void* p);
extern "C" void fn_80217484(void* p);

extern "C" void fn_801C26D8(void* this_) { fn_801C3B7C(this_, 0xd); }

extern "C" void fn_801C26FC(void* this_) {
    if (*(s32*)((char*)this_ + 0x248) != 0xe) {
        fn_801C3B7C(this_, 0xe);
    }
}

extern "C" void fn_801C272C(void* this_) {
    *(u8*)((char*)this_ + 0x11d) = 1;
    if (fn_801C11F0(fn_801C0D70())) {
        fn_801C3B7C(this_, 6);
    } else if (*(u16*)fn_801C0D70() & 1) {
        fn_801C3B7C(this_, 7);
    } else {
        fn_801C3B7C(this_, 9);
    }
}

extern "C" void fn_801C27A8(void* this_) {
    if (*(u32*)((char*)this_ + 0x230) & 0x4000) {
        switch (*(s32*)((char*)this_ + 0x248)) {
        case 0:
        case 1:
            fn_801C3B7C(this_, 2);
            break;
        }
    }
}

extern "C" void fn_801C27F0(void* this_) {
    s32 flag = (*(u32*)((char*)this_ + 0x230) >> 27) & 1;
    void* subRecord = fn_801C0D70();
    fn_801C1374(subRecord, flag);
    ((Actor*)this_)->Actor::v07();
}

extern f32 lbl_8053EE04;
extern char* lbl_8053AB10;
extern void* lbl_8053AED0;
extern "C" void fn_8030C210(void* cam, void* pos);
extern "C" void fn_8043E7CC(void* a, void* b);
extern "C" void fn_801C283C(u8* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 1:
    case 2:
    case 0xd:
    case 0x17:
        return;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xa:
    case 0xb:
    case 0xc:
        if (*(u32*)(this_ + 0x230) & 0x2000) {
            char* a = *(char**)(lbl_8053AB10 + 0x30);
            if (*(u8*)(a + 0x284) == 0) {
                *(u8*)(a + 0x284) = 1;
                *(f32*)(a + 0x28c) = lbl_8053EE04;
            }
            f32 x = *(f32*)(this_ + 0xc);
            f32 y = *(f32*)(this_ + 0x10);
            char* cam = *(char**)(lbl_8053AB10 + 0x24);
            if (*(u8*)(cam + 0x7f5) == 0) {
                *(u8*)(cam + 0x7f4) = 1;
                *(s32*)(cam + 0x7f8) = 4;
                *(f32*)(cam + 0x7fc) = x;
                *(f32*)(cam + 0x800) = y;
                *(f32*)(cam + 0x804) = lbl_8053EE08;
                *(u8*)(cam + 0x7f6) = 0;
            }
        }
        break;
    default:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        {
            char* cam = *(char**)(lbl_8053AB10 + 0x24);
            if (*(u8*)(cam + 0x179) == 0) {
                *(u8*)(cam + 0x178) = 1;
            }
        }
        break;
    }
    JGeometry::TVec3<f32> tmp(*(JGeometry::TVec3<f32>*)(this_ + 0xc));
    JGeometry::TVec3<f32> pos(tmp);
    fn_8043E7CC(lbl_8053AED0, &pos);
}

extern "C" void fn_801C2960(u8* this_) {
    *(u32*)(this_ + 0x230) &= 0xfdffffff;
    switch (*(s32*)(this_ + 0x248)) {
    case 0x10:
        if (!(*(u32*)(this_ + 0x230) & 0x800000)) {
            fn_80214AF8(this_ + 0x4ec);
        }
        break;
    case 0x21:
        if (fn_8021D020(this_)) {
            switch (*(s32*)(this_ + 0x564)) {
            case 0:
                if (!(*(u32*)(this_ + 0x230) & 0x10000)) {
                    fn_801C3B7C(this_, 0x29);
                } else if (*(u32*)(this_ + 0x524) & 0x80) {
                    fn_8021CDE4(this_, 1);
                } else {
                    fn_8021CDE4(this_, 2);
                }
                break;
            case 1:
                fn_8021CDE4(this_, 2);
                break;
            case 2:
                fn_8021CDE4(this_, 3);
                break;
            case 3:
                fn_801C3B7C(this_, 0x29);
                break;
            }
        } else {
            fn_801C3B7C(this_, 0x1b);
        }
        break;
    }
}

extern "C" void fn_801CE32C(void* this_);
extern "C" void fn_801CE5D4(void* this_);
extern "C" void fn_80214CE4(void* this_);
extern "C" void fn_80214994(void* this_);
extern "C" u8 fn_801CD2F8(void* this_);
extern "C" u16 fn_8022461C(void* p, void* a);
extern "C" u16 fn_80226850(void* p, void* a);
extern "C" void fn_802A381C(void* a, void* b, void* c, s32 d);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern "C" void fn_801C2A84(u8* this_) {
    s32 state = *(s32*)(this_ + 0x248);
    switch (state) {
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x2f:
        *(f32*)(this_ + 0x3c) = lbl_8053EE08;
        *(f32*)(this_ + 0x40) = lbl_8053EE08;
        *(f32*)(this_ + 0x44) = lbl_8053EE08;
        return;
    }
    u32 flags = *(u32*)(this_ + 0x230);
    u32 moving = (flags & 7) != 0;
    if (moving == 0) {
        fn_801CE32C(this_);
    } else if (!(flags & 2)) {
        fn_801CE5D4(this_);
    }
    fn_80214CE4(this_ + 0x4ec);
    fn_80214994(this_ + 0x4ec);
    if ((*(u32*)(this_ + 0x524) & 1) && !fn_801CD2F8(*(void**)(this_ + 4)) && *(f32*)(this_ + 0x14) <= lbl_8053EE08) {
        state = *(s32*)(this_ + 0x248);
        switch (state) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
        case 0xb: case 0xc: case 0xd: case 0xe:
        case 0x17: case 0x18: case 0x19: case 0x1a:
        case 0x29:
            return;
        }
        if (fn_8022461C(this_ + 0xc, *(void**)(this_ + 4)) == 0 && fn_80226850(this_ + 0xc, *(void**)(this_ + 4)) != 0xad) {
            fn_802A381C(lbl_8053AC98, this_ + 0xc, *(void**)(this_ + 4), 0xad);
            fn_801F0E34(this_, 0x3008a, 0);
        }
    }
}

extern "C" void fn_801C2BF4(void* this_) {
    char* p = (char*)this_;
    s32 state = *(s32*)(p + 0x248);

    switch (state) {
    case 6:
    case 0x14:
    case 0x1e:
        *(f32*)(p + 0x44) += lbl_8053EFB8;
        return;
    }
    f32 scale = *(f32*)(p + 0x254);
    f32 mul = scale;
    switch (state) {
    case 0x20:
        if (!(*(f32*)(p + 0x14) <= lbl_8053EE08)) {
            *(f32*)(p + 0x3c) *= lbl_8053EE0C;
            *(f32*)(p + 0x40) *= lbl_8053EE0C;
        }
        break;
    case 0x11: {
        s16 angle = *(s16*)(p + 0x33c);
        *(f32*)(p + 0x3c) = sincosTable___5JMath[(u16)angle >> 5].sin * scale;
        *(f32*)(p + 0x40) = sincosTable___5JMath[(u16)angle >> 5].cos * *(f32*)(p + 0x254);
        break;
    }
    default:
        if (state == 0x1c) {
            switch (*(u8*)(p + 0x34d)) {
            case 0:
            case 8:
                mul = lbl_8053EE08;
                break;
            default:
                mul = lbl_8053EE10;
                break;
            }
        }
        {
            s16 angle = *(s16*)(p + 0x33c);
            *(f32*)(p + 0x3c) = sincosTable___5JMath[(u16)angle >> 5].sin * mul;
            *(f32*)(p + 0x40) = sincosTable___5JMath[(u16)angle >> 5].cos * mul;
        }
        break;
    }
    char* vt = *(char**)this_;
    (*(void (**)(void*))(vt + 0x84))(this_);
}

extern const f32 lbl_8053EFB8;
extern const f32 lbl_8053EFBC;
extern "C" void fn_801C2D40(u8* this_) {
    if (*(s32*)(this_ + 0xd8) > 0 && *(s32*)(this_ + 0xf8) == 2) {
        return;
    }
    f32 min = -lbl_8053EFBC;
    *(f32*)(this_ + 0x44) += lbl_8053EFB8;
    if (*(f32*)(this_ + 0x44) < min) {
        *(f32*)(this_ + 0x44) = min;
    }
}

extern "C" void fn_801CE2BC(void* this_);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" void fn_80214578(void* this_);
extern "C" void fn_801C2D84(u8* this_) {
  fn_801CE2BC(this_);
  if (*(u8*)(this_ + 0x59c) != 0) {
    *(u8*)(this_ + 0x59c) = *(u8*)(this_ + 0x59c) - 1;
  }
  if (*(s32*)(this_ + 0x564) == 3 && *(u16*)(this_ + 0x59e) != 0) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0x2e:
    case 0x10:
      *(u16*)(this_ + 0x59e) -= 1;
      break;
    }
  }
  switch (*(s32*)(this_ + 0x248)) {
  case 0x24:
  case 0x25:
  case 0x26:
    if (*(s32*)(this_ + 0x340) == 9 && *(u8*)(this_ + 0x34d) == 0 && *(s32*)(this_ + 0x350) == 5) {
      fn_801F0E34(this_, 0x400c4, 0);
      fn_801F0E34(this_, 0x400c5, 0);
      fn_80214578(this_ + 0x4ec);
    }
    break;
  }
}

extern "C" void fn_800FE8C0(u8*);
extern "C" void fn_80216A8C(u8*);
extern "C" void fn_801C2E70(u8* this_) {
    *(u8*)(this_ + 0x34c) = *(s32*)(this_ + 0x98);
    if (*(s32*)(this_ + 0x248) != 0x13 || *(s32*)(this_ + 0x24c) <= 1) {
        if (!(*(u32*)(this_ + 0x230) & 0x80000)) {
            fn_800FE8C0(this_ + 0x340);
        }
    }
    fn_80216A8C(this_ + 0x528);
}

extern "C" void fn_801D01A0(u8* this_, void* src, f32* out, f32 r);
extern "C" u8 fn_801D0DD4(u8* this_);
extern "C" void fn_802188B0(void* p);
extern "C" void fn_801C71BC(u8* this_);
extern "C" s32 ClassifyBamAngleToQuadrant(u16 ang);
extern "C" u8 fn_801C0FEC(void* rec, void* pos, f32* out);
extern "C" u8 fn_801CD228(void* room);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F68E0(void* p);
extern "C" void fn_80458F9C(void* p, s32 x);
extern void* lbl_8053AF80;
extern "C" void fn_80214E50(void* p);
extern "C" void fn_801C8BC4(u8* this_, s32 a);
extern "C" s16 fn_80217374(void* p, s16 ang);
extern "C" void fn_801C7370(u8* this_, u8 flag);
extern "C" u8 fn_802189AC(void* p);
extern "C" void fn_802144F0(void* p);
extern "C" void fn_801C5B08(u8* this_, u8 flag);
extern "C" void fn_802146A4(void* p);
extern "C" void fn_801C6C7C(u8* this_);
extern "C" void fn_801C6BA8(u8* this_);
extern "C" void fn_801C6A4C(u8* this_);
extern u8* lbl_8053AAF8;
extern "C" u8 fn_801D183C(u8* this_, f32 r);
extern "C" void fn_801C1224(void* rec, void* p);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 a, f32 x, f32 y);
extern "C" void fn_801C6784(u8* this_);
extern "C" u8 fn_802153A8(void* p);
extern s32 lbl_80469450[];
extern "C" u8 fn_8021CFF8(void* this_);
extern const f32 lbl_8053EE18;
extern const f32 lbl_8053EE1C;
extern const f32 lbl_8053EE24;
extern const f32 lbl_8053EE2C;
extern const f32 lbl_8053EE30;
extern const f32 lbl_8053EE34;
extern const f32 lbl_8053EE38;


static inline void slk2ResetHitRect(u8* this_) {
    if (*(u8*)(this_ + 0x34d) == 7) {
        *(u32*)(this_ + 0x230) &= ~0x100;
        s32 room = *(s32*)(this_ + 4);
        if (*(u8*)((u32)fn_802D6A9C() + 0x10000 + room + 0x31df) == 0) {
            f32 a;
            f32 b;
            a = lbl_8053EE20;
            b = lbl_8053EE14;
            *(f32*)(this_ + 0x60) = a;
            *(f32*)(this_ + 0x64) = a;
            *(f32*)(this_ + 0x68) = b;
            *(f32*)(this_ + 0x6c) = b;
            *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
            *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
            *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
            *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        }
    }
}

extern "C" void fn_801C2ED4(u8* this_, u8 flag) {
    f32 pos[2];
    f32 delta[2];
    if (flag && (u8)((Actor*)this_)->v17(*(s32*)(this_ + 4), (f32*)(this_ + 0xc))) {
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x18);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x1c);
        fn_801D01A0(this_, this_ + 0x32c, delta, lbl_8053EE14);
        *(f32*)(this_ + 0xc) += delta[0];
        *(f32*)(this_ + 0x10) += delta[1];
    }
    if ((*(u16*)fn_801C0D70() & 0x400) && fn_801D0DD4(this_)) {
        switch (*(s32*)(this_ + 0x248)) {
        case 0xe:
        case 0xf:
        case 0x11:
        case 0x1b:
        case 0x22:
        case 0x27:
            if (fn_801C0FEC(fn_801C0D70(), this_ + 0xc, pos)) {
                if (*(u16*)fn_801C0D70() & 0x800) {
                    ((JGeometry::TVec3f*)(this_ + 0x32c))->set(pos[0], pos[1], lbl_8053EE08);
                    fn_801C3B7C(this_, 0x1d);
                }
            } else {
                fn_801C3B7C(this_, 0x2f);
            }
            break;
        }
    }
    fn_802188B0(this_ + 0x540);
    if (*(u32*)(this_ + 0x230) & 0x40000) {
        if (*(u8*)(this_ + 0x55c) != 0xff) {
            *(u8*)(this_ + 0x55c) += 1;
        }
    } else {
        *(u8*)(this_ + 0x55c) = 0;
    }
    if (*(u8*)(this_ + 0x597)) *(u8*)(this_ + 0x597) -= 1;
    if (*(u8*)(this_ + 0x598)) *(u8*)(this_ + 0x598) -= 1;
    if (*(u8*)(this_ + 0x599)) *(u8*)(this_ + 0x599) -= 1;
    if (*(u8*)(this_ + 0x59a)) *(u8*)(this_ + 0x59a) -= 1;
    if (*(u8*)(this_ + 0x59b)) *(u8*)(this_ + 0x59b) -= 1;

    s32 state = *(s32*)(this_ + 0x248);
    switch (state) {
    case 0:
        if ((*(u32*)(this_ + 0x230) & 0x2000) && fn_801CD228(*(void**)(this_ + 4))) {
            if (fn_801D05F8(this_, lbl_8053EE18 * (f32)*(u8*)(this_ + 0x55e), this_ + 0xc) >= 0) {
                fn_801C3B7C(this_, 1);
            }
        }
        break;
    case 1:
        if (fn_801F68E0(fn_801F856C()) != 0) {
            fn_80458F9C(lbl_8053AF80, 0x3c);
            *(u16*)fn_801C0D70() |= 8;
        }
        break;
    case 2:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            fn_801C3B7C(this_, 3);
        }
        break;
    case 3:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            fn_801C3B7C(this_, 4);
        }
        break;
    case 4:
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D0DD4(this_)) {
            fn_801C3B7C(this_, 5);
        }
        break;
    case 5:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            *(u32*)(this_ + 0x230) |= 0x8000;
            *(u16*)fn_801C0D70() |= 0x10;
        }
        break;
    case 6:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            *(s16*)(this_ + 0x33c) = 0;
            if ((*(u16*)fn_801C0D70() & 1) == 0) {
                fn_801C3B7C(this_, 9);
            } else {
                fn_801C3B7C(this_, 7);
            }
        }
        break;
    case 7:
        if (*(s32*)(this_ + 0x24c) >= 0x1e) {
            fn_801C3B7C(this_, 8);
        }
        break;
    case 8:
        if (*(s32*)(this_ + 0x24c) >= 0x5a) {
            fn_801C3B7C(this_, 9);
        }
        break;
    case 9:
        if (*(s32*)(this_ + 0x24c) >= 0x3c) {
            if (*(u32*)(this_ + 0x524) & 2) {
                fn_801C3B7C(this_, 0xa);
            } else {
                fn_801C3B7C(this_, 0xc);
            }
        }
        break;
    case 10:
        if (*(s32*)(this_ + 0x24c) >= 0x73) {
            fn_801C3B7C(this_, 0xb);
        }
        break;
    case 11:
        if (*(s32*)(this_ + 0x24c) >= 0x3c) {
            fn_801C3B7C(this_, 0xc);
        }
        break;
    case 12:
        if ((*(u32*)(this_ + 0x230) & 0x2000) && *((u8*)lbl_8053AED0 + 0x10a) == 0) {
            *(u16*)fn_801C0D70() |= 0x20;
        }
        break;
    case 13:
        if (*(s32*)(this_ + 0x24c) >= 0xa0) {
            *(f32*)(this_ + 0x10) += lbl_8053EE1C;
            fn_801C3B7C(this_, 0x1e);
        }
        break;
    case 14:
    case 15:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250) && fn_801D05F8(this_, *(f32*)(this_ + 0x5a4), this_ + 0xc) >= 0) {
            if (*(u8*)(this_ + 0x59c) == 0) {
                fn_80214E50(this_ + 0x4ec);
                *(u8*)(this_ + 0x59c) = 0x3c;
            }
            fn_801C3B7C(this_, 0x11);
        } else {
            u8 r = fn_801CD2F8(*(void**)(this_ + 4));
            if ((!r && *(s32*)(this_ + 0x24c) >= *(u16*)(this_ + 0x5a0)) || (r == 1 && *(s32*)(this_ + 0x24c) >= *(u16*)(this_ + 0x5a2))) {
                fn_801C3B7C(this_, 0x11);
                fn_801C8BC4(this_, 0);
            } else {
                *(s16*)(this_ + 0x33c) = fn_80217374(this_ + 0x550, *(s16*)(this_ + 0x33c));
            }
        }
        break;
    case 16: {
        s32 t = *(s32*)(this_ + 0x24c);
        if (t >= *(s32*)(this_ + 0x250)) {
            if (*(s32*)(this_ + 0x564) == 3) {
                fn_801C3B7C(this_, 0x2e);
            } else {
                fn_801C3B7C(this_, 0xf);
            }
        } else if (t % 6 == 0) {
            *(s16*)(this_ + 0x33c) += 0x4000;
        }
        break;
    }
    case 17:
        fn_801C7370(this_, flag);
        break;
    case 18:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250) || fn_802189AC(this_ + 0x540)) {
            fn_801C3B7C(this_, 0x13);
        }
        break;
    case 19:
        if (fn_801D0DD4(this_)) {
            s32 t = *(s32*)(this_ + 0x24c);
            if (t >= *(s32*)(this_ + 0x250) || (t >= 2 && fn_802189AC(this_ + 0x540))) {
                fn_801C3B7C(this_, 0x14);
            }
        }
        break;
    case 20:
        slk2ResetHitRect(this_);
        if (*(s32*)(this_ + 0x24c) > 1 && *(f32*)(this_ + 0x14) <= lbl_8053EE08) {
            fn_802144F0(this_ + 0x4ec);
            fn_801C3B7C(this_, 0x15);
        }
        break;
    case 21:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            fn_801C3B7C(this_, 0x16);
        }
        break;
    case 22:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            fn_801C3B7C(this_, 0x11);
        }
        break;
    case 23:
        if (*(s32*)(this_ + 0x24c) >= 0x6e) {
            fn_801C3B7C(this_, 0x11);
        }
        break;
    case 24:
    case 25:
    case 26:
        if (*(s32*)(this_ + 0x24c) >= 0x73) {
            if (state == 0x19 || state == 0x1a) {
                fn_801C3B7C(this_, 0xf);
            } else {
                s32 room = *(s32*)(this_ + 4);
                JGeometry::TVec3f save(*(JGeometry::TVec3f*)(this_ + 0xc));
                s32 r;
                *(s32*)(this_ + 4) = *(s32*)(this_ + 0x57c);
                *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x580);
                *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x584);
                *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x588);
                r = fn_801D05F8(this_, lbl_8053EE24, this_ + 0xc);
                *(s32*)(this_ + 4) = room;
                ((JGeometry::TVec3f*)(this_ + 0xc))->set(save);
                if (r >= 0) {
                    fn_801C3B7C(this_, 0x1e);
                } else {
                    fn_801C3B7C(this_, 0x11);
                }
            }
        } else {
            if (*(s32*)(this_ + 0x24c) == 0x46 && *(s32*)(this_ + 0x58c) == 0) {
                fn_802146A4(this_ + 0x4ec);
            }
            if (*(s32*)(this_ + 0x24c) % 4 == 0) {
                *(s16*)(this_ + 0x33c) += 0x4000;
            }
        }
        break;
    case 27:
        fn_801C5B08(this_, flag);
        break;
    case 28:
        slk2ResetHitRect(this_);
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D0DD4(this_)) {
            fn_801C3B7C(this_, 0x1f);
        }
        break;
    case 29:
        if (fn_801D0DD4(this_)) {
            if (*(u16*)fn_801C0D70() & 0x400) {
                if (*(s32*)(this_ + 0x24c) > 0x1e) {
                    fn_801C3B7C(this_, 0x1e);
                }
            } else if (*(s32*)(this_ + 0x24c) > 1) {
                fn_801C3B7C(this_, 0x1e);
            }
        }
        break;
    case 30:
        if (*(s32*)(this_ + 0x24c) > 1 && *(f32*)(this_ + 0x14) <= lbl_8053EE08) {
            fn_802144F0(this_ + 0x4ec);
            if (*(u32*)(this_ + 0x230) & 0x1000000) {
                *(volatile u32*)(this_ + 0x230) &= ~0x1000000;
                fn_801C3B7C(this_, 0x2c);
            } else if (*(u32*)(this_ + 0x230) & 0x2000000) {
                fn_801C3B7C(this_, 0x11);
            } else {
                fn_801C3B7C(this_, 0x1f);
            }
        }
        break;
    case 31:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            fn_801C3B7C(this_, 0x1b);
        }
        break;
    case 33:
        if ((*(u32*)(this_ + 0x230) & 0x4000000) && *(s32*)(this_ + 0x24c) % 4 == 0) {
            *(s16*)(this_ + 0x33c) += 0x4000;
        }
        break;
    case 34:
        fn_801C6C7C(this_);
        break;
    case 35:
    case 36:
        fn_801C6BA8(this_);
        break;
    case 37:
    case 38:
        fn_801C6A4C(this_);
        break;
    case 32:
    case 39:
    case 40:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            if ((*(u32*)(this_ + 0x524) & 8) && *(u8*)(this_ + 0x597) == 0) {
                u8* g = lbl_8053AAF8;
                *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
                u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
                if (*(f32*)&bits - lbl_8053EE28 < lbl_8053EE2C && fn_801D183C(this_, lbl_8053EE30)) {
                    fn_801C3B7C(this_, 0x22);
                    break;
                }
            }
            *(u8*)(this_ + 0x597) = 0x3c;
            fn_801C3B7C(this_, 0x1b);
        }
        break;
    case 41:
        if (*(s32*)(this_ + 0x24c) >= 0xa0) {
            if (*(u32*)(this_ + 0x230) & 0x10000) {
                fn_801C1224(fn_801C0D70(), *(void**)(this_ + 0x10c));
            }
            ((Actor*)this_)->v07();
        } else {
            if (*(u32*)(this_ + 0x230) & 0x8010000) {
                fn_802D79E8(fn_802D6A9C(), *(s32*)(this_ + 4), 0, lbl_8053EE34, lbl_8053EE38);
            }
            if (*(s32*)(this_ + 0x24c) % 8 == 0) {
                *(s16*)(this_ + 0x33c) += 0x4000;
            }
        }
        break;
    case 42:
        if (fn_801D0DD4(this_)) {
            fn_801C6784(this_);
            fn_801C3B7C(this_, 0x1c);
        }
        break;
    case 43:
        if (*(s32*)(this_ + 0x24c) >= 0x78) {
            *(u32*)(this_ + 0x230) |= 0x1000000;
            fn_801C3B7C(this_, 0x1d);
        }
        break;
    case 44: {
        s32 prev = *(s32*)(this_ + 0x560);
        if (fn_802153A8(this_ + 0x548)) {
            fn_801F0E34(this_, 0x400bf, 0);
            fn_801C3B7C(this_, 0x2d);
        }
        *(s32*)(this_ + 0x560) = *(u8*)(this_ + 0x549);
        if (*(s32*)(this_ + 0x248) == 0x2c) {
            s32 cur = *(s32*)(this_ + 0x560);
            if (prev != cur && cur >= 0 && cur <= 3) {
                fn_801F0E34(this_, lbl_80469450[cur], 0);
            }
        }
        break;
    }
    case 45:
        if (*(s32*)(this_ + 0x24c) >= 0x4a) {
            fn_801C3B7C(this_, 0x1b);
        }
        break;
    case 46:
        if (fn_8021CFF8(this_)) {
            fn_8021CDE4(this_, 2);
        }
        break;
    case 47:
        if (!(*(u16*)fn_801C0D70() & 0x400)) {
            fn_801C3B7C(this_, 0xf);
        }
        break;
    }
    if (*(u32*)(this_ + 0x230) & 0x100000) {
        fn_801C71BC(this_);
    }
    *(s32*)(this_ + 0x98) = ClassifyBamAngleToQuadrant((u16)*(s16*)(this_ + 0x33c));
}

extern "C" void fn_801C50A8(void* this_, s32 state);
#pragma auto_inline off
extern "C" void fn_801C3B7C(void* this_, s32 state) {
    u8* p = (u8*)this_;
    fn_801C50A8(this_, state);
    if ((u32)state > 0x2f) {
        *(s32*)(p + 0x248) = state;
        return;
    }
    *(s32*)(p + 0x250) = 1;
}
#pragma auto_inline reset

extern "C" void fn_801C50A8(void* this_, s32 state) {
    u8* p = (u8*)this_;
    f32 b;
    f32 a;

    *(u32*)(p + 0x230) &= ~0x40000;
    *(u8*)(p + 0x55c) = 0;
    if (state != 0x12 && *(s32*)(p + 0x248) != 0x12 && state != 0x13 && *(s32*)(p + 0x248) != 0x13 && state != 0x14 && *(s32*)(p + 0x248) != 0x14 && state != 0x15 && *(s32*)(p + 0x248) != 0x15 && state != 0x16 && *(s32*)(p + 0x248) != 0x16 && state != 0x17 && *(s32*)(p + 0x248) != 0x17 && state != 0x18 && *(s32*)(p + 0x248) != 0x18) {
        *(u8*)(p + 0x55d) = 0;
    }
    if (*(s32*)(p + 0x248) == 0x11) {
        *(u8*)(p + 0x598) = 0;
    }
    a = 1.0f;
    b = -1.0f;
    *(f32*)(p + 0x52c) = a;
    *(f32*)(p + 0x530) = a;
    *(f32*)(p + 0x534) = b;
    *(f32*)(p + 0x538) = b;
    switch (*(s32*)(p + 0x248)) {
    case 0x10:
        fn_80214900(p + 0x4ec);
        *(u32*)(p + 0x230) &= ~0x800000;
        break;
    case 0x11:
        *(u32*)(p + 0x230) &= ~0x1000;
        break;
    case 0x14:
        a = -8.0f;
        b = 8.0f;
        *(u32*)(p + 0x230) &= ~0x100;
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = a;
        *(f32*)(p + 0x68) = b;
        *(f32*)(p + 0x6c) = b;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x80) = a;
        *(f32*)(p + 0x84) = a;
        *(f32*)(p + 0x88) = b;
        *(f32*)(p + 0x8c) = b;
        break;
    case 0x17:
    case 0x18:
    case 0x19:
        a = -8.0f;
        b = 8.0f;
        *(u32*)(p + 0x230) &= ~0x1100;
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = a;
        *(f32*)(p + 0x68) = b;
        *(f32*)(p + 0x6c) = b;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(u32*)(p + 0x230) |= 0x40000;
        if (*(s32*)(p + 0x248) == 0x17) {
            *(u8*)(p + 0x59b) = 6;
            break;
        }
        if (*(s32*)(p + 0x248) == 0x19) {
            *(s32*)(p + 0x560) = fn_801CD664(4);
        }
            *(s32*)(p + 4) = *(s32*)(p + 0x57c);
            *(JGeometry::TVec3f*)(p + 0xc) = *(JGeometry::TVec3f*)(p + 0x580);
            *(JGeometry::TVec3f*)(p + 0x18) = *(JGeometry::TVec3f*)(p + 0x580);
            break;
    case 0x20:
        *(u32*)(p + 0x230) &= ~0x80000;
        break;
    case 0x21:
        *(u32*)(p + 0x230) &= ~0x4000000;
        break;
    case 0x12:
    case 0x13:
    case 0x15:
    case 0x16:
    case 0x2f:
        a = -8.0f;
        b = 8.0f;
        *(u32*)(p + 0x230) &= ~0x100;
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = a;
        *(f32*)(p + 0x68) = b;
        *(f32*)(p + 0x6c) = b;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        break;
    }
}

extern "C" int fn_801C5340(void) { return 0; }

extern "C" u8 fn_801C5348(void* this_, f32 r) {
    u8 result = 0;
    char* p = (char*)this_;
    s32 idx = fn_801D05F8(this_, lbl_8053EE08, p + 0xc);
    if (idx >= 0) {
        if (fn_801D0D50(this_, idx, p + 0xc, r)) {
            result = 1;
        }
    }
    return result;
}

extern "C" bool fn_801C53C4(void* thisObj) {
	return ((*(u32*)((char*)thisObj + 0x230) & 0x40000) != 0 && *(u8*)((char*)thisObj + 0x55c) <= 20) ? true : false;
}

extern "C" void fn_801C53F8(void* this_) {
    u8 off = (*(u32*)((char*)fn_801C0D70() + 0x50) >> 31) ^ 1;
    if (!off && (*(u32*)((char*)this_ + 0x230) & 0x2000)) {
        fn_801C12B8(fn_801C0D70());
    }
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" u16 fn_801C14A8(void* this_, void* param_2);
extern "C" void fn_802157B8(void* flags, u8 level);
extern "C" void fn_800FEB78(void* this_, s32 opcode);
extern "C" void fn_801C544C(void* this_) {
    u32 mode;
    void* sub;
    s32 level;
    f32 b;
    f32 a;

    fn_801D0ED0(this_);
    *(u16*)((char*)this_ + 0x94) = fn_801C14A8(fn_801C0D70(), *(void**)((char*)this_ + 0x198));
    mode = (*(u32*)((char*)this_ + 0x90) >> 5) & 7;
    if (mode == 1 || mode == 2) {
        *(u32*)((char*)this_ + 0x230) |= 0x6000;
        sub = fn_801C0D70();
        *(f32*)((char*)sub + 0x54) = *(f32*)((char*)this_ + 0xc);
        *(f32*)((char*)sub + 0x58) = *(f32*)((char*)this_ + 0x10);
        *(f32*)((char*)sub + 0x5c) = *(f32*)((char*)this_ + 0x14);
        switch (mode) {
        case 1:
            sub = fn_801C0D70();
            *(u16*)sub |= 2;
            break;
        case 2:
            sub = fn_801C0D70();
            *(u16*)sub |= 4;
            break;
        }
    } else if (mode == 3) {
        *(u32*)((char*)this_ + 0x230) |= 0x4000;
    }
    if (*(u32*)((char*)this_ + 0x230) & 0x4000) {
        sub = fn_801C0D70();
        *(u16*)((char*)sub + 2) += 1;
    }
    *(u8*)((char*)this_ + 0x55e) = (u8)(*(u32*)((char*)this_ + 0x90) >> 20);
    if (*(u8*)((char*)this_ + 0x55e) == 0) {
        *(u8*)((char*)this_ + 0x55e) = 10;
    }
    level = *(s32*)((char*)this_ + 0x90) & 0x1f;
    if (level > 8) {
        level = 8;
    } else if (level < 0) {
        level = 0;
    }
    fn_802157B8((char*)this_ + 0x524, (u8)level);
    b = lbl_8053EE50;
    a = lbl_8053EE28;
    *(f32*)((char*)this_ + 0x60) = a;
    *(f32*)((char*)this_ + 0x64) = a;
    *(f32*)((char*)this_ + 0x68) = b;
    *(f32*)((char*)this_ + 0x6c) = b;
    *(f32*)((char*)this_ + 0x70) = *(f32*)((char*)this_ + 0x60);
    *(f32*)((char*)this_ + 0x74) = *(f32*)((char*)this_ + 0x64);
    *(f32*)((char*)this_ + 0x78) = *(f32*)((char*)this_ + 0x68);
    *(f32*)((char*)this_ + 0x7c) = *(f32*)((char*)this_ + 0x6c);
    *(f32*)((char*)this_ + 0x80) = a;
    *(f32*)((char*)this_ + 0x84) = a;
    *(f32*)((char*)this_ + 0x88) = b;
    *(f32*)((char*)this_ + 0x8c) = b;
    *(u32*)((char*)this_ + 0xb0) = 0x50303;
    *(u32*)((char*)this_ + 0x230) |= 0x100;
    *(u8*)((char*)this_ + 0x11d) = 0;
    *(u32*)((char*)this_ + 0x108) = 1000;
    *(u32*)((char*)this_ + 0x244) = *(u32*)((char*)this_ + 0x108);
    *(u32*)((char*)this_ + 0x114) = 2;
    *(u8*)((char*)this_ + 0x196) = 1;
    *(u16*)((char*)this_ + 0x33c) = 0;
    *(u32*)((char*)this_ + 0x98) = 2;
    *(u32*)((char*)this_ + 0x248) = 0;
    *(u32*)((char*)this_ + 0x24c) = 0;
    *(s32*)((char*)this_ + 0x250) = -1;
    *(f32*)((char*)this_ + 0x254) = lbl_8053EE08;
    *(f32*)((char*)this_ + 0x258) = lbl_8053EE08;
    fn_800FEB78((char*)this_ + 0x340, 0);
    *(f32*)((char*)this_ + 0x32c) = *(f32*)((char*)this_ + 0xc);
    *(f32*)((char*)this_ + 0x330) = *(f32*)((char*)this_ + 0x10);
    *(f32*)((char*)this_ + 0x334) = *(f32*)((char*)this_ + 0x14);
}

extern "C" u32 fn_801C5660(u32 a, u32 b, u32 c, u32 d, u32 e) {
    return ((e & 0xff) << 20) | ((d & 0xf) << 12) | ((c & 0xf) << 8) | ((b & 7) << 5) | (a & 0x1f);
}

extern "C" void* fn_801C5680(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A43E8;
        fn_801C1440(fn_801C0D70(), *(u32*)(p + 0x198));
        dtor_80214F9C(p + 0x4ec, -1);
        if (this_ != 0) {
            *(void**)p = lbl_804A46F4;
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

extern "C" void* fn_801C573C(void* this_) {
    char* p = (char*)this_;
    fn_801D1974(this_);
    *(void**)p = lbl_804A43E8;
    Slk2_ResetFlags7(p + 0x358);
    Slk2_InitVtablePairRecord(p + 0x4ec);
    Slk2_ResetBlock0x0(p + 0x524);
    fn_80217128(p + 0x528);
    fn_80218A8C(p + 0x540);
    ResetFlagBlock3c_Zero(p + 0x548);
    fn_80217484(p + 0x550);
    *(u8*)(p + 0x55c) = 0;
    *(u8*)(p + 0x55d) = 0;
    *(u8*)(p + 0x55e) = 0;
    *(s32*)(p + 0x560) = 4;
    *(s32*)(p + 0x564) = 0;
    *(s32*)(p + 0x568) = lbl_8046A748;
    *(s32*)(p + 0x56c) = 0;
    *(f32*)(p + 0x570) = lbl_8053EE08;
    *(f32*)(p + 0x574) = lbl_8053EE08;
    *(f32*)(p + 0x578) = lbl_8053EE08;
    *(s32*)(p + 0x57c) = 0;
    *(f32*)(p + 0x580) = lbl_8053EE08;
    *(f32*)(p + 0x584) = lbl_8053EE08;
    *(f32*)(p + 0x588) = lbl_8053EE08;
    *(s32*)(p + 0x58c) = 0;
    *(s32*)(p + 0x590) = -1;
    *(u8*)(p + 0x594) = 0;
    *(u8*)(p + 0x595) = 0;
    *(u8*)(p + 0x596) = 0;
    *(u8*)(p + 0x597) = 0;
    *(u8*)(p + 0x598) = 0;
    *(u8*)(p + 0x599) = 0;
    *(u8*)(p + 0x59a) = 0;
    *(u8*)(p + 0x59b) = 0;
    *(u8*)(p + 0x59c) = 0;
    *(u16*)(p + 0x59e) = 0;
    *(u16*)(p + 0x5a0) = 0;
    *(u16*)(p + 0x5a2) = 0;
    *(f32*)(p + 0x5a4) = lbl_8053EE08;
    *(f32*)(p + 0x5a8) = lbl_8053EE08;
    *(f32*)(p + 0x5ac) = lbl_8053EE08;
    *(f32*)(p + 0x5b0) = lbl_8053EE08;
    *(void**)(p + 0x520) = this_;
    *(void**)(p + 0x528) = this_;
    *(void**)(p + 0x540) = this_;
    return this_;
}

extern "C" void* dtor_801C5854(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A46F4;
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
