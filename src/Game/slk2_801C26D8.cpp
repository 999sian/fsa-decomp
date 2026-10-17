// Game TU 801C26D8-801C5B08 (SLK2). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/Actor.h"
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
extern f32 lbl_8053EE14;
extern f32 lbl_8053EE20;
extern f32 lbl_8053EE28;
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
    struct Vec3f {
        f32 x;
        f32 y;
        f32 z;
    } pos;
    pos = *(struct Vec3f*)(this_ + 0xc);
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
    if (!(flags & 7)) {
        fn_801CE32C(this_);
    } else if (!(flags & 2)) {
        fn_801CE5D4(this_);
    }
    fn_80214CE4(this_ + 0x4ec);
    fn_80214994(this_ + 0x4ec);
    if ((*(u32*)(this_ + 0x524) & 1) && !fn_801CD2F8(*(void**)(this_ + 4)) && *(f32*)(this_ + 0x14) <= lbl_8053EE08) {
        state = *(s32*)(this_ + 0x248);
        if (state < 0x17) {
            if (state != 10) {
                if (state < 10) {
                    if (state >= 0) {
                        return;
                    }
                } else if (state < 0xf) {
                    return;
                }
            }
        } else {
            if (state == 0x29) {
                return;
            }
            if (state < 0x29 && state < 0x1b) {
                return;
            }
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
    (*(void (**)(void*))(*(u32*)p + 0x84))(p);
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
    s32 s = *(s32*)(this_ + 0x248);
    switch (s) {
    case 0x2e:
    case 0x10:
      *(u16*)(this_ + 0x59e) = *(u16*)(this_ + 0x59e) - 1;
      break;
    }
  }
  if (*(s32*)(this_ + 0x248) < 0x27 && *(s32*)(this_ + 0x248) >= 0x24) {
    if (*(s32*)(this_ + 0x340) == 9 && *(u8*)(this_ + 0x34d) == 0 && *(s32*)(this_ + 0x350) == 5) {
      fn_801F0E34(this_, 0x400c4, 0);
      fn_801F0E34(this_, 0x400c5, 0);
      fn_80214578(this_ + 0x4ec);
    }
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
extern f32 lbl_8053EE28;
extern f32 lbl_8053EE50;
extern "C" void fn_801C544C(void* this_) {
    u32 mode;
    void* sub;
    s32 level;
    f32 a;
    f32 b;

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
