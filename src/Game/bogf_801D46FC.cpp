// Game TU 801D46FC-801D6CEC (BOGF). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry.h"
#include "JSystem/JKernel/JKRArchive.h"

extern "C" u8* fn_802D6A9C(void);
extern u8* lbl_8053AB10;
extern struct BogfGame* lbl_8053AAF8;

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
extern "C" s32 fn_801CD664(s32 id);
extern "C" void fn_801E4D54(void* this_);
extern "C" void fn_801E4618(void* this_, JGeometry::TVec2<f32>* out, bool id);
extern "C" void fn_801D7638(void* p);
extern "C" void fn_801D76B4(void* p);
extern "C" void fn_80217A74(void* p);
extern "C" void fn_80217DE8(void* p);
extern "C" void fn_80217BC8(void* p);
extern "C" void fn_80217AB8(void* p);
extern "C" void fn_80217ED4(void* p);
extern "C" void fn_801E6A84(void* p, s32 arg);
extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_801D74E0(void* a, void* b, s32 c);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" u8 fn_801E44CC(void* p, const void* a, void* b, void* n);
extern "C" void fn_801CDCD0(void* p, s32 a, void* b, s32 c);
extern const f32 lbl_8053F0DC;
extern const f32 lbl_8053F0F8;
extern const f32 lbl_8053F104;
extern const f32 lbl_8053F110;
extern const f32 lbl_8053F12C;
extern const f32 lbl_8053F130;

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

extern "C" u8 fn_801CD228(s32 id);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F68E0(void);
extern "C" void fn_801F6884(void* p);
extern "C" u8 fn_801D0B44(u8* this_, s32 i);
extern "C" void fn_801D4C70(u8* this_);
extern "C" void fn_801E4D74(void* this_);
extern "C" bool fn_801CD2F8(s32 id);
extern "C" void fn_801D5D84(u8* this_, s32 state);
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

extern "C" s32 fn_80458FF0(void* mgr, s32 handle, s32 a, s32 b);
extern "C" void fn_801D5B70(u8* this_);
extern "C" s32 fn_801D05F8(void* this_, void* pos, f32 range);
extern "C" void fn_801D72C0(void* p, void* pos);
extern "C" void fn_801D70BC(void* p, void* pos, s32 player);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);
extern "C" void fn_801E667C(void* p);
extern "C" void fn_80217A30(void* p);
extern "C" void fn_802179EC(void* p);
extern "C" void fn_80217874(void* p, f32 t);
extern "C" void fn_8021775C(void* p, f32 t);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_801E4790(void*, bool);
extern const f32 lbl_8053F0CC;
extern const f32 lbl_8053F108;
extern const f32 lbl_8053F114;
static inline s32 fn_801D5390_pick(u8* this_) {
    s32 out[4];
    s32 pick = -1;
    s32* o = out;
    s32 i;
    s32 count = 0;
    for (i = 0; i < 4; i++) {
        if (i != *(s32*)(this_ + 0x5b0) && this_[0x2a8 + i * 0x18] == 0 && fn_801D0B44(this_, i)) {
            *o++ = i;
            count++;
        }
    }
    if (count > 0) {
        pick = out[fn_801CD664(count)];
    }
    return pick;
}
extern "C" void fn_801D5390(u8* this_) {
    switch (*(u32*)(this_ + 0x248)) {
    case 0:
        if (fn_801CD228(*(s32*)(this_ + 0x4))) {
            fn_801F856C();
            if (fn_801F68E0() != 0) {
                fn_801D5D84(this_, 1);
            }
        }
        break;
    case 1:
        if (*(f32*)(this_ + 0x14) <= lbl_8053F0EC) {
            *(f32*)(this_ + 0x14) = lbl_8053F0EC;
            fn_801D5D84(this_, 2);
        }
        break;
    case 2:
        if (*(s32*)(this_ + 0x24c) >= 0xb4) {
            fn_801D5D84(this_, 3);
        }
        break;
    case 3:
        if (*(s32*)(this_ + 0x24c) >= 0x3c) {
            fn_801F6884(fn_801F856C());
            fn_80458FF0(lbl_8053AF80, 0x1000004, 1, 0);
            fn_801D5D84(this_, 4);
        }
        break;
    case 4:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            *(s32*)(this_ + 0x5b0) = fn_801D5390_pick(this_);
            fn_801D5D84(this_, 5);
        }
        break;
    case 5: {
        s32 cur = *(s32*)(this_ + 0x5b0);
        if (cur != -1 && ((*(u8(*)[4][0x18])(this_ + 0x2a8))[cur][0] != 0 || !fn_801D0B44(this_, cur))) {
            *(s32*)(this_ + 0x5b0) = fn_801D5390_pick(this_);
            fn_801D5D84(this_, 5);
        } else if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            s32 pick = fn_801D5390_pick(this_);
            if (*(s32*)(this_ + 0x5b0) != -1 || pick != -1) {
                *(s32*)(this_ + 0x5b0) = pick;
                fn_801D5D84(this_, 5);
            }
        }
        break;
    }
    case 6:
        if (*(f32*)(this_ + 0x14) >= lbl_8053F108) {
            *(f32*)(this_ + 0x14) = lbl_8053F108;
            fn_801D5D84(this_, 7);
        }
        break;
    case 7:
        if (!(*(u32*)(this_ + 0x230) & 1) && *(s32*)(this_ + 0x24c) >= 0x1e) {
            fn_801D5D84(this_, 8);
        }
        break;
    case 8:
        if (*(f32*)(this_ + 0x14) <= lbl_8053F110) {
            *(f32*)(this_ + 0x14) = lbl_8053F110;
            fn_801D5D84(this_, 9);
        }
        break;
    case 9:
        if (*(s32*)(this_ + 0x24c) >= 0x78) {
            fn_801D5D84(this_, 0xa);
        }
        break;
    case 10:
        fn_801D5B70(this_);
        break;
    case 11:
        if (*(s32*)(this_ + 0x24c) >= 0xb4) {
            if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
                fn_801D5D84(this_, 0xf);
            } else {
                fn_80217CD8(this_ + 0x448);
                fn_801D5D84(this_, 0xc);
            }
        }
        break;
    case 12:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            fn_801D5D84(this_, 0xd);
        }
        break;
    case 13:
        if (this_[0x5cf] != 0) {
            this_[0x5cf]--;
            if (this_[0x5cf] == 0) {
                fn_801D72C0(this_ + 0x4c4, this_ + 0xc);
                fn_801F0E34(this_, 0x40060, 0);
                fn_801D5D84(this_, 0xe);
            }
        } else if (*(f32*)(this_ + 0x3c) < lbl_8053F0CC && *(f32*)(this_ + 0x40) < lbl_8053F0CC) {
            this_[0x5cf] = 10;
        }
        break;
    case 14:
        if (*(s32*)(this_ + 0x24c) >= 6) {
            if (this_[0x5d0] != 0 && (*(u32*)(this_ + 0x230) & 0x10000)) {
                this_[0x5d0]--;
            }
            fn_801D5D84(this_, 0xa);
        }
        break;
    case 15:
        if (this_[0x5cf] != 0) {
            this_[0x5cf]--;
            if (this_[0x5cf] == 0) {
                fn_801D70BC(this_ + 0x4c4, this_ + 0xc, fn_801D05F8(this_, this_ + 0xc, lbl_8053F0C8));
                fn_801F0E34(this_, 0x40069, 0);
                fn_801D5D84(this_, 0x10);
            }
        } else if (*(f32*)(this_ + 0x3c) < lbl_8053F0CC && *(f32*)(this_ + 0x40) < lbl_8053F0CC) {
            this_[0x5cf] = 10;
        }
        break;
    case 16:
        if (*(s32*)(this_ + 0x24c) >= 6) {
            if (this_[0x5d0] != 0 && (*(u32*)(this_ + 0x230) & 0x10000)) {
                this_[0x5d0]--;
            }
            fn_801D5D84(this_, 0xa);
        }
        break;
    case 17:
        if (*(s32*)(this_ + 0x24c) >= 0xf) {
            fn_801D5D84(this_, 0x12);
        }
        break;
    case 18:
        if (*(s32*)(this_ + 0x24c) >= 0xf) {
            fn_801D5D84(this_, 0x13);
        }
        break;
    case 19:
        if (*(s32*)(this_ + 0x24c) >= 0x32) {
            fn_801D5D84(this_, 0x14);
        }
        break;
    case 20:
        if (*(s32*)(this_ + 0x24c) >= 0xf) {
            fn_801D5D84(this_, 0xa);
        }
        break;
    case 21:
        if (__fabsf(*(f32*)(this_ + 0xc) - *(f32*)(this_ + 0x5ec)) < lbl_8053F114 &&
            __fabsf(*(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x5f0)) < lbl_8053F114) {
            fn_801D5D84(this_, 0x16);
        }
        break;
    case 22:
        if (__fabsf(*(f32*)(this_ + 0xc) - *(f32*)(this_ + 0x5f4)) < lbl_8053F114 &&
            __fabsf(*(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x5f8)) < lbl_8053F114) {
            fn_801D5D84(this_, 0x17);
        }
        break;
    case 23:
        if (*(s32*)(this_ + 0x24c) >= 0x32) {
            *(s32*)(this_ + 0x5b4) = 0;
            *(s32*)(this_ + 0x5b8) = fn_801CD664(4);
            *(f32*)(this_ + 0x5bc) = *(f32*)(this_ + 0x600);
            *(f32*)(this_ + 0x5c0) = *(f32*)(this_ + 0x604);
            *(s32*)(this_ + 0x4) = *(s32*)(this_ + 0x5fc);
            *(JGeometry::TVec3<f32>*)(this_ + 0xc) = *(JGeometry::TVec3<f32>*)(this_ + 0x600);
            *(JGeometry::TVec3<f32>*)(this_ + 0x18) = *(JGeometry::TVec3<f32>*)(this_ + 0x600);
            fn_801E4790(this_, fn_801CD2F8(*(s32*)(this_ + 0x4)));
            if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
                this_[0x5d0] = fn_801CD664(4) + 3;
                fn_80217A30(this_ + 0x448);
            } else {
                this_[0x5d0] = fn_801CD664(2) + 1;
                fn_802179EC(this_ + 0x448);
                fn_80217DE8(this_ + 0x448);
                fn_80217CD8(this_ + 0x448);
            }
            fn_801D5D84(this_, 0xa);
        } else if (fn_801CD2F8(*(s32*)(this_ + 0x5fc))) {
            fn_80217874(this_ + 0x448, (f32)(0x32 - *(s32*)(this_ + 0x24c)));
        } else {
            fn_8021775C(this_ + 0x448, (f32)(0x32 - *(s32*)(this_ + 0x24c)));
        }
        break;
    case 24:
        fn_801F856C();
        if (fn_801F68E0() != 0) {
            fn_80134DE4(lbl_8053AAF8, 3, 0);
            fn_801D5D84(this_, 0x19);
        }
        break;
    case 25:
        if (*(s32*)(this_ + 0x24c) >= 0x1c2) {
            fn_801D5D84(this_, 0x1a);
        } else if (*(s32*)(this_ + 0x24c) == 0xc8) {
            this_[0x11d] = 0;
        }
        break;
    case 26:
        fn_801E667C(this_ + 0x568);
        break;
    }
}

extern "C" s32 fn_801D652C(void) {
    return fn_80458F9C(lbl_8053AF80, 0x3c);
}

extern "C" void fn_801D0ED0(void*);
extern "C" void fn_801E4758(void*);
extern "C" void fn_801EBA14(void*);
extern "C" void fn_801EB710(void*, s32, void*);
extern "C" void fn_801D2608(void*, const char*, s32);
extern "C" void fn_801D1D60(void*);
extern "C" void fn_802D7440(void*, s32);
extern "C" void fn_80304C10(s32, const char*, u32, s32, s32);
extern "C" void fn_802F9714(void*, void*, s32, s32, s32, s32);
extern const char lbl_8053A138[8];
extern const char lbl_804694C0[];
#pragma opt_propagation off
extern "C" void fn_801D6554(u8* p) {
    char rec[0x28];
    s32 i;
    fn_801D0ED0(p);
    *(s32*)(p + 0x5dc) = *(u32*)(p + 0x90) & 0xf;
    if (*(s32*)(p + 0x5dc) != 0) *(s32*)(p + 0x5dc) += 7;
    u32 bits = *(u32*)(p + 0x90);
    f32 unit = 8.0f;
    f32 y = (f32)((bits >> 13) & 0x1f8);
    f32 x = (f32)((bits >> 21) & 0x1f8);
    *(f32*)(p + 0x5e0) = unit + x;
    *(f32*)(p + 0x5e4) = unit + y;
    *(u8*)(p + 0x5e8) = (*(u32*)(p + 0x90) >> 10) & 0x3f;
    *(u8*)(p + 0x5e9) = (*(u32*)(p + 0x90) >> 4) & 0x3f;
    fn_801E4790(p, 0);
    fn_801E4758(p);
    *(s32*)(p + 0xb0) = 0;
    *(s32*)(p + 0x98) = 2;
    *(u32*)(p + 0x230) |= 0x320;
    *(s32*)(p + 0x114) = 2;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(u8*)(p + 0x196) = 1;
    *(f32*)(p + 0x54) = 1.7f;
    *(f32*)(p + 0x58) = 1.7f;
    *(f32*)(p + 0x5c) = 1.7f;
    *(f32*)(p + 0x60c) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x610) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x614) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x14) = 500.0f;
    fn_801EBA14(rec);
    *(s32*)(rec + 0) = 1;
    *(s32*)(rec + 4) = 1;
    *(s32*)(p + 0x470) = 1;
    *(s32*)(p + 0x474) = *(s32*)(rec + 4);
    *(f32*)(p + 0x478) = *(f32*)(rec + 8);
    *(f32*)(p + 0x47c) = *(f32*)(rec + 12);
    *(f32*)(p + 0x480) = *(f32*)(rec + 16);
    *(f32*)(p + 0x484) = *(f32*)(rec + 20);
    *(f32*)(p + 0x488) = *(f32*)(rec + 24);
    *(f32*)(p + 0x48c) = *(f32*)(rec + 28);
    *(f32*)(p + 0x490) = *(f32*)(rec + 32);
    *(s16*)(p + 0x494) = *(s16*)(rec + 36);
    fn_801EB710(p + 0x464, *(s32*)(p + 4), p + 0xc);
    *(s32*)(p + 0x5d8) = *(s32*)(p + 4);
    *(s32*)(p + 0x5b8) = fn_801CD664(4);
    *(f32*)(p + 0x5bc) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x5c0) = *(f32*)(p + 0x10);
    f32 top = *(f32*)(p + 0x5e4);
    *(f32*)(p + 0x5ec) = 32.0f + (8.0f * (f32)*(u8*)(p + 0x5e8) + *(f32*)(p + 0x5e0));
    *(f32*)(p + 0x5f0) = top;
    f32 bottom = -32.0f + *(f32*)(p + 0x5e4);
    *(f32*)(p + 0x5f4) = *(f32*)(p + 0x5ec);
    *(f32*)(p + 0x5f8) = bottom;
    if (((u8*)lbl_8053AAF8)[0x7e]) *(u8*)(p + 0x5cc) = 6;
    else *(u8*)(p + 0x5cc) = 3;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    fn_801D2608(p + 0x270, lbl_8053A138, 2);
    fn_801D22DC(p + 0x270, 0, 2, 0);
    fn_801D1D60(p + 0x270);
    fn_802D7440(fn_802D6A9C(), 0);
    for (i = 0; i < 4; i++) fn_80304C10(i, lbl_804694C0, 0x6017000, 1, 0);
    void* mgr = *(void**)((char*)lbl_8053AAF8 + 0xa4);
    void* resource = ((JKRArchive*)mgr)->getResource('SCH ', lbl_804694C0);
    fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), resource, 0, 0, 0x7000, 0);
}
#pragma opt_propagation reset
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
static inline f32 bogfRandFrom(BogfGame* game, int multiplier) {
    union { f32 f; u32 bits; } random;
    game->rnd.seed = game->rnd.seed * multiplier + 0x3c6ef35f;
    random.bits = (game->rnd.seed >> 9) | 0x3f800000;
    return random.f-lbl_8053F0D8;
}
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
                f32 y = (lbl_8053F138 * lbl_8053AAF8->rnd.get_ufloat_1() - lbl_8053F0D8) * lbl_8053F134;
                f32 x = (lbl_8053F138 * lbl_8053AAF8->rnd.get_ufloat_1() - lbl_8053F0D8) * lbl_8053F134;
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

extern "C" void fn_801D5D84(u8* p, s32 state) {
    switch (state) {
    case 0:
    case 21:
    case 22:
        break;
    case 1:
    case 2:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    case 3:
        fn_80217CD8(p + 0x448);
        fn_801F0E34(p, 0x40089, 0);
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    case 4:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        *(s32*)(p + 0x250) = fn_801CD664(1) + 0x1e;
        break;
    case 5:
        fn_801E4D74(p);
        *(f32*)(p + 0x258) = lbl_8053F12C;
        if (*(s32*)(p + 0x5b0) == -1) {
            *(s32*)(p + 0x250) = fn_801CD664(0xb5) + 0x3c;
        } else {
            *(s32*)(p + 0x250) = fn_801CD664(0xf1) + 0x78;
        }
        break;
    case 6:
        fn_801E4D54(p);
        *(u8*)(p + 0x4c0) = 1;
        *(f32*)(p + 0x4bc) = lbl_8053F0C8;
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    case 7:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    case 8: {
        JGeometry::TVec2<f32> box[2];
        *(s32*)(p + 0x108) = 0x32;
        *(u32*)(p + 0x230) |= 0x2000;
        *(u32*)(p + 0x230) &= 0xFFFFFCFF;
        *(s32*)(p + 0x5b0) = -1;
        *(s32*)(p + 0xb0) = 3;
        fn_801E4618(p, box, fn_801CD2F8(*(s32*)(p + 0x4)));
        f32 dx=box[1].x-box[0].x;
        f32 dy=box[1].y-box[0].y;
        f32 cx=box[0].x+0.5f*dx;
        f32 cy=box[0].y+0.5f*dy;
        *(f32*)(p + 0x60c) = cx;
        *(f32*)(p + 0x610) = cy;
        *(f32*)(p + 0x614) = lbl_8053F0C8;
        *(f32*)(p + 0x5bc) = box[0].x + (box[1].x - box[0].x) * bogfRandFrom(lbl_8053AAF8,0x19660d);
        *(f32*)(p + 0x5c0) = box[0].y + (box[1].y - box[0].y) * bogfRandFrom(lbl_8053AAF8,0x19660d);
        *(u8*)(p + 0x5d0) = fn_801CD664(2) + 1;
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    }
    case 9:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    case 10:
        if (fn_801CD2F8(*(s32*)(p + 0x4))) {
            *(f32*)(p + 0x258) = lbl_8053F104;
            *(s32*)(p + 0x250) = fn_801CD664(0xb5) + 0xb4;
            break;
        }
        *(f32*)(p + 0x258) = lbl_8053AAF8->pad[0x7e] ? lbl_8053F104 : lbl_8053F0D8;
        *(s32*)(p + 0x250) = fn_801CD664(0x1e1) + 0xf0;
        break;
    case 11:
        if (*(s32*)(p + 0x508) != 4) {
            fn_801D7638(p + 0x4c4);
            fn_801D76B4(p + 0x4c4);
        }
            fn_80217A74(p + 0x448);
            *(f32*)(p + 0x254) = lbl_8053F0C8;
            *(f32*)(p + 0x258) = lbl_8053F0C8;
            *(f32*)(p + 0x3c) = lbl_8053F0C8;
            *(f32*)(p + 0x40) = lbl_8053F0C8;
            *(f32*)(p + 0x44) = lbl_8053F0C8;
            *(u8*)(p + 0x5d1) = 0;
            break;
    case 12:
        *(f32*)(p + 0x258) = lbl_8053AAF8->pad[0x7e] ? lbl_8053F104 : lbl_8053F0D8;
        *(s32*)(p + 0x250) = fn_801CD664(0x79) + 0x78;
        fn_801D74E0(p + 0x4c4, p + 0xc, *(s32*)(p + 0x4));
        break;
    case 13:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        if (*(s32*)(p + 0x508) == 3) {
            *(u8*)(p + 0x51c) = 1;
        }
        *(u8*)(p + 0x5cf) = 0;
        break;
    case 14:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    case 15:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        *(u8*)(p + 0x5cf) = 0;
        fn_801D74E0(p + 0x4c4, p + 0xc, *(s32*)(p + 0x4));
        fn_801F0E34(p, 0x40068, 0);
        break;
    case 16:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    case 17:
        *(f32*)(p + 0x254) = lbl_8053F0C8;
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        break;
    case 18:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        fn_801F0E34(p, 0x40061, 0);
        break;
    case 19:
        *(f32*)(p + 0x258) = lbl_8053F130;
        fn_801D22DC(p + 0x270, 1, 2, 0);
        fn_801F0E34(p, 0x40062, 0);
        break;
    case 20:
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        fn_801D22DC(p + 0x270, 0, 2, 0);
        break;
    case 23: {
        JGeometry::TVec2<f32> box[2];
        *(s32*)(p + 0x5fc) = *(s32*)(p + 0x5dc);
        *(f32*)(p + 0x608) = lbl_8053F0C8;
        if (fn_801CD2F8(*(s32*)(p + 0x4))) {
            *(s32*)(p + 0x5fc) = *(s32*)(p + 0x5d8);
            *(f32*)(p + 0x608) = lbl_8053F110;
        }
            fn_801E4618(p, box, fn_801CD2F8(*(s32*)(p + 0x5fc)));
            *(f32*)(p + 0x600) = box[0].x + (box[1].x - box[0].x) * bogfRandFrom(lbl_8053AAF8,0x19660d);
            *(f32*)(p + 0x604) = box[0].y + (box[1].y - box[0].y) * bogfRandFrom(lbl_8053AAF8,0x19660d);
            fn_801E44CC(p, box, p + 0x600, 0);
        *(f32*)(p + 0x254) = lbl_8053F0C8;
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        *(f32*)(p + 0x3c) = lbl_8053F0C8;
        *(f32*)(p + 0x40) = lbl_8053F0C8;
        *(f32*)(p + 0x44) = lbl_8053F0C8;
        *(u8*)(p + 0x5d1) = 0;
        if (!fn_801CD2F8(*(s32*)(p + 0x4))) {
            fn_80217A74(p + 0x448);
            fn_80217DE8(p + 0x448);
            fn_80217BC8(p + 0x448);
            fn_801F0E34(p, 0x5003e, 0);
        } else {
            fn_80217AB8(p + 0x448);
            fn_801CDCD0(p, *(s32*)(p + 0x5fc), p + 0x60c, 0x5003d);
        }
        break;
    }
    case 24:
        *(f32*)(p + 0x60) = lbl_8053F0D8;
        *(f32*)(p + 0x64) = lbl_8053F0D8;
        *(f32*)(p + 0x68) = lbl_8053F0DC;
        *(f32*)(p + 0x6c) = lbl_8053F0DC;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x80) = lbl_8053F0D8;
        *(f32*)(p + 0x84) = lbl_8053F0D8;
        *(f32*)(p + 0x88) = lbl_8053F0DC;
        *(f32*)(p + 0x8c) = lbl_8053F0DC;
        *(f32*)(p + 0x258) = lbl_8053F0C8;
        *(f32*)(p + 0x254) = lbl_8053F0C8;
        *(f32*)(p + 0x3c) = lbl_8053F0C8;
        *(f32*)(p + 0x40) = lbl_8053F0C8;
        *(f32*)(p + 0x44) = lbl_8053F0C8;
        *(u8*)(p + 0x5d1) = 0;
        break;
    case 25:
        fn_801F0E34(p, 0x4008a, 0);
        fn_80217ED4(p + 0x448);
        break;
    case 26:
        fn_801E6A84(p + 0x568, 0);
        detach__5ActorFv(p);
        *(u8*)(p + 0x11c) = 1;
        break;
    default:
        break;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
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
        f32 s = JMath::sincosTable_.mTable[(u16)ang >> 5].first;
        f32 c = JMath::sincosTable_.mTable[(u16)ang >> 5].second;
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

extern const f32 lbl_8053F104;
extern const f32 lbl_8053F108;
extern const f32 lbl_8053F10C;
extern const f32 lbl_8053F110;
extern "C" void fn_801CE32C(void* p);
extern "C" s32 fn_801CD580(s32 id);
extern "C" void fn_801E4A18(void* p);
#pragma opt_propagation off
extern "C" void fn_801D4ED4(u8* this_) {
    u8 sel = 0;
    if (this_[0x5d1] != 0) {
        this_[0x5d1]--;
        if (this_[0x5d1] == 0) {
            fn_80217CD8(this_ + 0x448);
            s16 ang = *(s16*)(this_ + 0x5d2);
            const f32* __restrict table = (const f32*)JMath::sincosTable_.mTable;
            f32 s = table[((u16)ang >> 5)*2];
            f32 k = lbl_8053F104;
            f32 c = table[((u16)ang >> 5)*2 + 1];
            ((JGeometry::TVec2f*)(this_ + 0x3c))->set(k * s, k * c);
        }
    }
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 11:
    case 23:
    case 26:
        break;
    case 6:
        if (*(u32*)(this_ + 0x230) & 1) {
            *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x20);
            *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x23c);
        }
        sel = 1;
        break;
    case 7:
        *(f32*)(this_ + 0x14) = lbl_8053F108;
        break;
    default: {
        f32 x0 = *(f32*)(this_ + 0x5bc);
        f32 y0 = *(f32*)(this_ + 0x5c0);
        switch (*(s32*)(this_ + 0x5b8)) {
        case 0:
            *(f32*)(this_ + 0x5bc) = *(volatile f32*)(this_ + 0x5bc) + lbl_8053F10C;
            break;
        case 1:
            *(f32*)(this_ + 0x5bc) = *(volatile f32*)(this_ + 0x5bc) - lbl_8053F10C;
            break;
        case 2:
            *(f32*)(this_ + 0x5c0) = *(volatile f32*)(this_ + 0x5c0) + lbl_8053F10C;
            break;
        case 3:
            *(f32*)(this_ + 0x5c0) = *(volatile f32*)(this_ + 0x5c0) - lbl_8053F10C;
            break;
        }
        bool done = false;
        JGeometry::TVec3<f32> pos(*(f32*)(this_ + 0x5bc), *(f32*)(this_ + 0x5c0), 0.0f);
        u8 ok = ((ItemBase*)this_)->v17(*(s32*)(this_ + 0x4), (f32*)&pos);
        if (ok) {
            *(f32*)(this_ + 0x5bc) = x0;
            done = true;
            *(f32*)(this_ + 0x5c0) = y0;
        } else {
            *(s32*)(this_ + 0x5b4) = *(s32*)(this_ + 0x5b4) + 1;
            if (*(s32*)(this_ + 0x5b4) >= 0x3c) {
                done = true;
            }
        }
        if (done) {
            *(s32*)(this_ + 0x5b8) = fn_801CD580(*(s32*)(this_ + 0x5b8));
            *(s32*)(this_ + 0x5b4) = 0;
        }
        if (!(*(u32*)(this_ + 0x230) & 7)) {
            sel = 1;
        }
        break;
    }
    }
    if (sel) {
        fn_801CE32C(this_);
    }
    switch (*(s32*)(this_ + 0x248)) {
    case 1: {
        f32 height = *(f32*)(this_ + 0x14);
        if (height < lbl_8053F0EC) {
            *(f32*)(this_ + 0x14) = lbl_8053F0EC;
        }
    } break;
    default:
    if (!fn_801CD2F8(*(s32*)(this_ + 0x4))) {
        f32 v = *(f32*)(this_ + 0x14);
        if (v > lbl_8053F108) {
            v = lbl_8053F108;
        } else if (v < lbl_8053F110) {
            v = lbl_8053F110;
        }
        *(f32*)(this_ + 0x14) = v;
    }
    }
    fn_801E4A18(this_ + 0x52c);
    fn_801E4A18(this_ + 0x540);
    fn_801E4A18(this_ + 0x554);
}
#pragma opt_propagation reset
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_8030C210(void* cam, JGeometry::TVec3<f32>* pos);
extern u8* lbl_8053AB10;
extern const f32 lbl_8053F0CC;
extern const f32 lbl_8053F0D4;
extern const f32 lbl_8053F0DC;

extern "C" f32 __fsels(f32, f32, f32);
#pragma fp_relax on
extern "C" void fn_801D47DC(u8* this_) {
    s32 room = *(s32*)(this_ + 0x4);
    u8* g = fn_802D6A9C();
    f32* rect;
    if (room < 8) {
        rect = (f32*)(g + 0xcc);
    } else {
        rect = (f32*)(g + 0xdc);
    }
    JGeometry::TVec3<f32> pos(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14), 0.0f);
    f32 lim = lbl_8053F0CC + rect[1];
    pos.y = __fsel(lim - pos.y, lim, pos.y);
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 0x17:
        break;
    case 1: {
        JGeometry::TVec3<f32> c0(32.0f + rect[0], 32.0f + rect[1], 0.0f);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &c0);
        JGeometry::TVec3<f32> c1(rect[2] - 32.0f, 32.0f + rect[1], 0.0f);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &c1);
        JGeometry::TVec3<f32> c2(32.0f + rect[0], rect[3] - 32.0f, 0.0f);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &c2);
        JGeometry::TVec3<f32> c3(rect[2] - 32.0f, rect[3] - 32.0f, 0.0f);
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
            *(f32*)(cam + 0x7fc) = pos.x;
            *(f32*)(cam + 0x800) = pos.y;
            *(f32*)(cam + 0x804) = pos.z;
            cam[0x7f6] = 0;
        }
        break;
    }
    case 0x19: {
        u8* cam = *(u8**)(lbl_8053AB10 + 0x24);
        if (cam[0x840] == 0) {
            cam[0x840] = 1;
            *(f32*)(cam + 0x844) = *(f32*)(cam + 0x84c) = pos.x;
            *(f32*)(cam + 0x848) = *(f32*)(cam + 0x850) = pos.y;
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
#pragma fp_relax reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
