#define GAME_ACTOR_USE_SDK_VEC
#include "types.h"
#include "Game/Actor.h"
#include "JSystem/JMath/Inline.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"

extern "C" const f32 lbl_8053D050;
extern "C" const f32 lbl_8053D060;
extern "C" const f32 lbl_8053D064;
extern "C" const f32 lbl_8053D068;
extern "C" const f32 lbl_8053D06C;
extern "C" const f32 lbl_8053D070;
extern "C" const f32 lbl_8053D074;
extern "C" s32 fn_802D6A9C(void);
extern "C" char lbl_8049F4F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80145F60(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_8049F4F0;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, s32 a, void* b, s32 d, void* e);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" u16 fn_80226850(void* a, s32 b);
extern "C" u32 lbl_8053D040;
extern "C" u32 lbl_8053D044;
extern "C" u32 fn_80145FC0(Actor* a, s32 b, void* c) {
    u32 tmp[2];
    tmp[0] = lbl_8053D040;
    tmp[1] = lbl_8053D044;
    s32 region = a->field_198;
    void* base = fn_8020D58C();
    u8 idx = static_cast<u8*>(base)[1];
    if (fn_8020D6AC(static_cast<u8*>(base) + idx * 0x784 + 4, b, c, region, tmp) == 1) {
        return 1;
    }
    s32 kind = fn_8022461C(c, b);
    s32 sub = fn_80226850(c, b);
    if ((u32)(kind - 0x10) <= 7 || (sub >= 0x140 && sub <= 0x15f)) {
        return 0;
    }
    if (kind != 0x0 && kind != 0x4 && kind != 0x5 && kind != 0x6 && kind != 0x7 && kind != 0x2 && kind != 0x3 &&
        kind != 0x50 && kind != 0xe && kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 &&
        kind != 0x2a && kind != 0x2b && kind != 0x2c && kind != 0x2d && kind != 0x2e && kind != 0x2f &&
        kind != 0x20 && kind != 0xd && kind != 0x39 && kind != 0x3a && kind != 0x3b && kind != 0x4c &&
        kind != 0x4d && kind != 0x4e && kind != 0x4f && kind != 0x24 && kind != 0x23) {
        if (kind == 0x25) {
            return ((u8*)fn_802D6A9C())[0x171] == 0;
        }
        if (kind == 0x26) {
            return ((u8*)fn_802D6A9C())[0x171] == 1;
        }
        if (kind != 0x22 || ((u8*)fn_802D6A9C())[0x170] == 1) {
            return 1;
        }
    }
    return 0;
}

extern "C" const f32 lbl_8053D048;
extern "C" char lbl_80465BC0[];
extern "C" void fn_801F06F0(void* this_, void* p, s32 n, void* ids, s32 flag, f32 fa, f32 fb);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" void fn_801461E4(void* this_) {
    DrawRec rec;
    rec.b2d = 1;
    if (*(s32*)((u8*)this_ + 0x234) >= 0x100 || (*(s32*)((u8*)this_ + 0x234) & 2) == 0) {
        fn_801F06F0(this_, lbl_80465BC0, 0x2c, rec.ids, 1, lbl_8053D048, lbl_8053D048);
        fn_803075AC(*(void**)((u8*)this_ + 0x198), *(void**)((u8*)this_ + 4), (u8*)this_ + 0xc, 0x2c, 0, 2, -1, 0, 0, 0);
    }
}

extern "C" s32 fn_8023AF14(f32* box, u32 room, s32 a, f32 f);
extern "C" s32 fn_8023B8E4(f32* box, u32 room, f32* pt, s32 flag);
extern "C" s32 fn_8023B768(f32* box, u32 room, f32* pt);
extern "C" s32 fn_80237810(s32 i);
extern "C" s32 fn_80237774(s32 i);
extern "C" void fn_80230EB8(s32 i, s32 a);
extern "C" void fn_80236554(s32 i, s32 a, s32 b);
extern "C" s32 fn_801F2718(void* a, u32 code);
extern "C" void fn_801F0E34(void* a, u32 code, u32 z);
extern "C" void fn_8030C210(void* a, void* b);
extern "C" const f32 lbl_8053D04C;
extern "C" const f32 lbl_8053D054;
extern "C" const f32 lbl_8053D058;
extern "C" const f32 lbl_8053D05C;
extern "C" u32 lbl_8053AAF8;
extern "C" u32 lbl_8053AB10;
extern "C" s32 lbl_8053AB9C;
extern "C" s32 lbl_8053ABEC;
extern "C" u8 sincosTable___5JMath[];
extern "C" void fn_80146364(void* this_) {
    Vec* pos = (Vec*)((u8*)this_ + 0xc);
    Vec* vel = (Vec*)((u8*)this_ + 0x3c);
    f32 py = pos->y;
    f32 px = pos->x;
    f32 pos2[2];
    pos2[0] = px;
    pos2[1] = py;
    if (*(s32*)((u8*)this_ + 0x240) == 0) {
        *(s32*)((u8*)this_ + 0x234) -= 1;
        if (*(s32*)((u8*)this_ + 0x234) <= 0) {
            *(u8*)((u8*)this_ + 0x11c) = 0;
            return;
        }
    }
    JMathInlineVEC::PSVECAdd(pos, vel, pos);
    switch (*(s32*)((u8*)this_ + 0x230)) {
    case 0:
        vel->z -= lbl_8053D04C;
        if (vel->z < lbl_8053D050) {
            *(s32*)((u8*)this_ + 0x238) = 0;
            u8* g = (u8*)lbl_8053AAF8;
            *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            if (*(f32*)&bits - lbl_8053D048 < lbl_8053D054) {
                *(s32*)((u8*)this_ + 0x238) = 1;
            }
            *(s32*)((u8*)this_ + 0x23c) = 0;
            *(s32*)((u8*)this_ + 0x230) = 1;
        }
        break;
    case 1: {
        vel->z -= lbl_8053D058;
        if (*(s32*)((u8*)this_ + 0x238) == 0) {
            *(s32*)((u8*)this_ + 0x23c) += 0x700;
        } else {
            *(s32*)((u8*)this_ + 0x23c) -= 0x700;
        }
        s32 ang = *(s32*)((u8*)this_ + 0x23c);
        pos->x = pos->x + *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8));
        if (pos->z <= lbl_8053D050) {
            vel->x = lbl_8053D050;
            vel->z = lbl_8053D050;
            pos->z = lbl_8053D050;
            *(s32*)((u8*)this_ + 0x230) = 4;
        }
        break;
    }
    case 2:
        vel->y += lbl_8053D04C;
        if (vel->y > lbl_8053D050) {
            *(s32*)((u8*)this_ + 0x238) = 0;
            u8* g = (u8*)lbl_8053AAF8;
            *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            if (*(f32*)&bits - lbl_8053D048 < lbl_8053D054) {
                *(s32*)((u8*)this_ + 0x238) = 1;
            }
            *(s32*)((u8*)this_ + 0x23c) = 0;
            *(s32*)((u8*)this_ + 0x230) = 3;
        }
        break;
    case 3: {
        Vec v;
        vel->y += lbl_8053D058;
        if (vel->y > lbl_8053D05C) {
            vel->y = lbl_8053D05C;
        }
        if (*(s32*)((u8*)this_ + 0x238) == 0) {
            *(s32*)((u8*)this_ + 0x23c) += 0x700;
        } else {
            *(s32*)((u8*)this_ + 0x23c) -= 0x700;
        }
        s32 ang = *(s32*)((u8*)this_ + 0x23c);
        pos->x = pos->x + *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8));
        v.x = pos->x;
        v.y = pos->y;
        v.z = pos->z;
        v.y = v.y + lbl_8053D060;
        u8 (*vfn)(void*, u32, Vec*) = *(u8 (**)(void*, u32, Vec*))((u8*)*(void**)this_ + 0x4c);
        if (vfn(this_, *(u32*)((u8*)this_ + 4), &v) == 1) {
            vel->x = lbl_8053D050;
            vel->y = lbl_8053D050;
            *(s32*)((u8*)this_ + 0x230) = 4;
        }
        break;
    }
    case 4: {
        f32 box[4];
        box[0] = *(f32*)((u8*)this_ + 0x60);
        box[1] = *(f32*)((u8*)this_ + 0x64);
        box[2] = *(f32*)((u8*)this_ + 0x68);
        box[3] = *(f32*)((u8*)this_ + 0x6c);
        box[0] += pos2[0];
        box[1] += pos2[1];
        box[2] += pos2[0];
        box[3] += pos2[1];
        s32 flag = 1;
        if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
            flag = 0;
        }
        u32 room = *(u32*)((u8*)this_ + 4);
        s32 a = fn_8023AF14(box, room, flag, lbl_8053D050);
        s32 b = fn_8023B8E4(box, room, pos2, 1);
        if (b < 0) {
            fn_8023B768(box, room, pos2);
        }
        if (a >= 0) {
            s32 t = fn_80237810(a);
            if (fn_80237774(a) == t) {
                fn_80230EB8(a, 9);
            }
            fn_80236554(a, 4, 0);
            *(u8*)((u8*)this_ + 0x11c) = 0;
        } else if (b >= 0) {
            s32 t = fn_80237810(b);
            if (fn_80237774(b) == t) {
                fn_80230EB8(b, 9);
            }
            fn_80236554(b, 4, 0);
            *(u8*)((u8*)this_ + 0x11c) = 0;
        } else if (fn_801F2718(this_, 0x5a4c4432) >= 0) {
            fn_801F0E34(this_, 0x400c9, 0);
            lbl_8053AB9C = 4;
            *(u8*)((u8*)this_ + 0x11c) = 0;
        } else if (fn_801F2718(this_, 0x5a4c4434) >= 0) {
            fn_801F0E34(this_, 0x400c9, 0);
            lbl_8053ABEC = 4;
            *(u8*)((u8*)this_ + 0x11c) = 0;
        }
        break;
    }
    }
    if (*(s32*)((u8*)this_ + 4) < 8) {
        Vec v;
        v.x = pos->x;
        v.y = pos->y - pos->z;
        v.z = lbl_8053D050;
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &v);
    }
}

extern "C" void fn_80146890(void* this_) {
    f32 val = lbl_8053D050;
    *(f32*)((u8*)this_ + 0x44) = val;
    *(f32*)((u8*)this_ + 0x40) = val;
    *(f32*)((u8*)this_ + 0x3c) = val;
    *(u32*)((u8*)this_ + 0x230) = 4;
}

#pragma global_optimizer off
extern "C" void fn_801468AC(void* this_) {
    *(f32*)((u8*)this_ + 0x60) = lbl_8053D064;
    *(f32*)((u8*)this_ + 0x64) = lbl_8053D064;
    *(f32*)((u8*)this_ + 0x68) = lbl_8053D068;
    *(f32*)((u8*)this_ + 0x6c) = lbl_8053D068;
    *(f32*)((u8*)this_ + 0x80) = lbl_8053D06C;
    *(f32*)((u8*)this_ + 0x84) = lbl_8053D06C;
    *(f32*)((u8*)this_ + 0x88) = lbl_8053D060;
    *(f32*)((u8*)this_ + 0x8c) = lbl_8053D060;
    *(s32*)((u8*)this_ + 0x238) = 0;
    *(s32*)((u8*)this_ + 0x234) = 0x3ff;
    *(u32*)((u8*)this_ + 0x240) = *(u32*)((u8*)this_ + 0x90) & 3;
    *(u32*)((u8*)this_ + 0xb0) = 0x21000;
    if (*(s32*)((u8*)this_ + 0x240) != 1) {
        *(f32*)((u8*)this_ + 0x44) = lbl_8053D070;
        {
            s32 zero = 0;
            *(s32*)((u8*)this_ + 0x230) = zero;
        }
        s32 iVar1 = *(s32*)((u8*)this_ + 0x4);
        s32 iVar4 = fn_802D6A9C();
        if (*(u8*)(iVar4 + 0x10000 + iVar1 + 0x31df) != 0) {
            *(f32*)((u8*)this_ + 0x10) = *(f32*)((u8*)this_ + 0x10) - *(f32*)((u8*)this_ + 0x14);
            *(f32*)((u8*)this_ + 0x14) = lbl_8053D050;
            *(f32*)((u8*)this_ + 0x44) = lbl_8053D050;
            *(f32*)((u8*)this_ + 0x40) = lbl_8053D074;
            *(s32*)((u8*)this_ + 0x230) = 2;
        }
    } else {
        *(s32*)((u8*)this_ + 0x230) = 4;
    }
}
#pragma global_optimizer reset
