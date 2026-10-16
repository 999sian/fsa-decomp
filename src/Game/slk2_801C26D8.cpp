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
extern "C" void fn_801C12B8(void* rec);
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
    *(s32*)(p + 0x560) = 4;
    *(u8*)(p + 0x55d) = 0;
    *(u8*)(p + 0x55e) = 0;
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
