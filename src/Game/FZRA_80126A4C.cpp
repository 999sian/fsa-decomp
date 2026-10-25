#include "types.h"
#include "Game/SinitPoolChain.h"
#define Vec SDKVec
#include "JSystem/JGeometry/Vec.h"
#undef Vec
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" void* fn_801283E8(void);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_800FE3EC(void* a, s32 b, void* c, s32 d);
extern "C" s32 fn_800FD894(void* a, s32 b, s32 c, s32 d);
extern "C" void fn_800FDC70(void* out, void* a, void* pos, s32 b, u8 c);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_8012824C(void);
extern "C" void fn_80128228(void);
extern "C" void fn_80128074(void);
extern "C" void* fn_80127F90(void);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* a, s32 b);
extern "C" void Actor_CreateByID(void* a, s32 id, s32 room, void* pos, s32 flags, s32 c, s32 d);
extern "C" void* fn_80237810(s32 i);
extern "C" void fn_80236554(s32 i, void* a, s32 b);
extern "C" void fn_80237524(s32 i, s32 a);
extern "C" void fn_802D8050(void* mgr, s32 kind, s32 a, s32 b);
extern "C" void detach__5ActorFv(void* this_);
extern "C" f32 lbl_8053CAB8;
extern "C" f32 lbl_8053CAC0;
extern "C" void* lbl_8053AAF8;
extern "C" f32 lbl_8053CAA0;
extern "C" f32 lbl_8053CABC;

extern "C" void __ct__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_801D267C(void* this_);
extern void* lbl_8049E424[];
extern void* lbl_8049CC34[];
extern const f32 lbl_8053CAA4;
extern const f32 lbl_8053CAA8;
extern "C" void fn_80126A4C(void* this_, s32 state) {
    u8* p = (u8*)this_;
    JGeometry::TVec3f vel;
    JGeometry::TVec3f pos5;
    JGeometry::TVec3f pos11;
    JGeometry::TVec3f out;
    JGeometry::TVec3f pos2;
    JGeometry::TVec3f pos8;
    *(s32*)(p + 0x230) = state;
    switch (state) {
    case 0:
        *(u8*)(p + 0x259) = 0;
        break;
    case 1:
        *(s32*)(p + 0x254) = 0xff;
        *(u8*)(p + 0x259) = 1;
        *(u8*)(p + 0x11d) = 1;
        *(s32*)(p + 0x23c) = -1;
        break;
    case 4:
        fn_801283E8();
        fn_8012824C();
        break;
    case 5: {
        pos5 = *(JGeometry::TVec3f*)(p + 0xc);
        fn_800FE3EC(p + 0x2b4, *(s32*)(p + 0x238), &pos5, *(s32*)(p + 4));
        break;
    }
    case 6:
        fn_801D22DC(p + 0x27c, 6, 2, 0);
        break;
    case 7:
        *(s32*)(p + 0x240) = 0;
        break;
    case 8: {
        *(s32*)(p + 0x254) = 0xff;
        *(s32*)(p + 0x244) = 0;
        *(f32*)(p + 0x264) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x268) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x26c) = *(f32*)(p + 0x14);
        fn_801D22DC(p + 0x27c, 8, 2, 0);
        f32 q0 = lbl_8053CAB8;
        f32 q1 = lbl_8053CABC;
        *(f32*)(p + 0x60) = q0;
        f32 q2 = lbl_8053CAC0;
        *(f32*)(p + 0x64) = q1;
        f32 q3 = lbl_8053CAA0;
        *(f32*)(p + 0x68) = q2;
        *(f32*)(p + 0x6c) = q3;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x80) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x84) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x88) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x8c) = *(f32*)(p + 0x6c);
        if (*(u8*)(p + 0x258) != 0) {
            pos8 = *(JGeometry::TVec3f*)(p + 0xc);
            pos8.x = pos8.x + q3;
            *(void**)(p + 0x37c) = fn_8013CC50(*(s32*)(p + 4), &pos8, 0x183, 0, -1, 0, 0, 1, lbl_8053CAA4);
            *(void**)(p + 0x380) = fn_8013CC50(*(s32*)(p + 4), &pos8, 0x184, 0, -1, 0, 0, 1, lbl_8053CAA4);
        }
        s32 kind = ((ItemBase*)this_)->v13();
        void* mgr = fn_802D6A9C();
        fn_802D8050(mgr, kind, 1, 0xff);
        fn_801283E8();
        fn_80128228();
        break;
    }
    case 10:
        for (s32 i = 0; i < 4; i++) {
            if (((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) {
                fn_80236554(i, fn_80237810(i), 0);
                fn_80237524(i, 0x180);
            }
        }
        fn_801F0E34(this_, 0x40090, 0);
        break;
    case 11: {
        pos11 = *(JGeometry::TVec3f*)(p + 0xc);
        fn_800FE3EC(p + 0x2b4, *(s32*)(p + 0x238), &pos11, *(s32*)(p + 4));
        vel.x = lbl_8053CAA8;
        vel.y = lbl_8053CAA8;
        vel.z = lbl_8053CAA8;
        *(f32*)(p + 0x260) = lbl_8053CAA4;
        u8 n = fn_800FD894(p + 0x2b4, -1, 0, 0) - 1;
        pos2 = *(JGeometry::TVec3f*)(p + 0xc);
        fn_800FDC70(&out, p + 0x2b4, &pos2, 1, n);
        vel = out;
        ((JGeometry::TVec3f*)(p + 0x3c))->set(vel);
        *(JGeometry::TVec3f*)(p + 0xc) += *(JGeometry::TVec3f*)(p + 0x3c);
        *(f32*)(p + 0x264) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x268) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x26c) = *(f32*)(p + 0x14);
        break;
    }
    case 12:
        fn_801D22DC(p + 0x27c, 6, 2, 0);
        *(s32*)(p + 0x250) = 0;
        break;
    case 13:
        fn_801D22DC(p + 0x27c, 6, 2, 0);
        *(s32*)(p + 0x250) = 0x78;
        *(s32*)(p + 0x254) = 0;
        fn_801283E8();
        *(JGeometry::TVec3f*)(p + 0x270) = *(JGeometry::TVec3f*)fn_80127F90();
        if (*(u8*)(p + 0x258) != 0) {
            fn_801F0E34(this_, 0x400EE, 0);
        }
        break;
    case 14:
        *(s32*)(p + 0x250) = 0;
        break;
    case 15:
        if (fn_801F7A08(fn_801F856C(), 0x53504652) < 0) {
            s32 kind = ((ItemBase*)this_)->v13() << 27;
            Actor_CreateByID(fn_801F856C(), 0x53504652, *(s32*)(p + 4), p + 0x270, kind, -1, -1);
            fn_801283E8();
            fn_80128074();
        }
        break;
    case 16:
        if (*(void**)(p + 0x37c) != 0) {
            u8* e = (u8*)*(void**)(p + 0x37c);
            *(u32*)(e + 0xf4) |= 1;
            *(s32*)(e + 0x24) = 1;
        }
        if (*(void**)(p + 0x380) != 0) {
            u8* e = (u8*)*(void**)(p + 0x380);
            *(u32*)(e + 0xf4) |= 1;
            *(s32*)(e + 0x24) = 1;
        }
        detach__5ActorFv(this_);
        break;
    }
}

extern "C" u8 fn_80126EF8(u8* this_) {
    s32 v = *(s32*)(this_ + 0x230);
    if (v == 1 || v == 0xc) {
        return 1;
    }
    return 0;
}

extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 idx, u8* buf, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern const char lbl_80464FAC[];
extern "C" void fn_80126F1C(void* this_) {
    u8 buf[0x40];

    v06__5ActorFv(this_);

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;

    for (u8 i = 0; i < 16; i++) {
        buf[i] = i;
    }

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
    buf[0x1e] = 0;
    buf[0x1f] = 1;
    buf[0x20] = 1;
    buf[0x21] = 0;
    buf[0x22] = 0;
    buf[0x23] = 0;
    buf[0x24] = 0;
    buf[0x25] = 0;
    buf[0x26] = 1;
    *(s32*)(buf + 0x28) = 3;
    buf[0x2c] = 1;
    buf[0x2d] = 0;
    buf[0x2e] = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x38) = 2;

    if (*(s32*)((char*)this_ + 0x230) == 0xd || *(s32*)((char*)this_ + 0x230) == 0xe) {
        buf[0x14] = *(s32*)((char*)this_ + 0x254);
        buf[0x15] = *(s32*)((char*)this_ + 0x254);
        buf[0x16] = *(s32*)((char*)this_ + 0x254);
    }

    fn_801F02BC(this_, lbl_80464FAC, *(s32*)((char*)this_ + 0x28c) + 0x242, buf, 0x407, 0, 0, lbl_8053CAA4, lbl_8053CAA4);
}

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void* p, void* a, s32 b);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* p, f32 f);
extern "C" void* fn_801283E8(void);
extern "C" void fn_80128398(void* a, void* b);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 kind);
extern "C" void fn_80126A4C(void* this_, s32 flag);
extern "C" void* lbl_8049E400[];
extern "C" f32 lbl_8053CAD0;
extern "C" f32 lbl_8053CABC;
extern "C" f32 lbl_8053CAD4;
extern "C" f32 lbl_8053CAA0;
extern "C" void fn_80127958(void* this_) {
    v01__5ActorFv(this_);
    u8* p = (u8*)this_;
    if (*(u32*)(p + 0x90) & 1) {
        *(u8*)(p + 0x258) = 1;
    }
    f32 q0 = lbl_8053CAD0;
    f32 q1 = lbl_8053CABC;
    f32 q2 = lbl_8053CAD4;
    f32 q3 = lbl_8053CAA0;
    *(s32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(s32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 8) & 0xff;
    *(f32*)(p + 0x60) = q0;
    *(f32*)(p + 0x64) = q1;
    *(f32*)(p + 0x68) = q2;
    *(f32*)(p + 0x6c) = q3;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x84) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x88) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x8c) = *(f32*)(p + 0x6c);
    fn_801D2608(p + 0x27c, lbl_8049E400, 9);
    fn_801D22DC(p + 0x27c, 6, 2, 0);
    fn_801D1F14(p + 0x27c, lbl_8053CAA8);
    *(u8*)(p + 0x2b6) = 0;
    *(u8*)(p + 0x2b7) = 0;
    *(u8*)(p + 0x2b5) = 0;
    *(u8*)(p + 0x11d) = 0;
    fn_80128398(fn_801283E8(), this_);
    if (*(s32*)(p + 0x234) > 0) {
        if (!((u8 (*)(void*))(*(void***)this_)[13])(this_)) {
            void* mgr = fn_802D6A9C();
            if (fn_802D800C(mgr, *(s32*)(p + 0x234))) {
                fn_80126A4C(this_, 1);
            }
        }
    }
}

extern "C" void* fn_80127AAC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049E424;
        fn_801EE434(*(void**)(p + 0x37c));
        fn_801EE434(*(void**)(p + 0x380));
        *(s32*)(p + 0x37c) = 0;
        *(s32*)(p + 0x380) = 0;
        if (p + 0x27c != 0) {
            if (p + 0x2a0 != 0) {
                *(void**)(p + 0x2a0) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_80127B48(void* this_) {
    __ct__5ActorFv(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_8049E424;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0xff;
    *(u8*)(p + 0x258) = 0;
    *(u8*)(p + 0x259) = 0;
    *(f32*)(p + 0x25c) = lbl_8053CAA8;
    *(f32*)(p + 0x260) = lbl_8053CAA4;
    *(f32*)(p + 0x264) = lbl_8053CAA8;
    *(f32*)(p + 0x268) = lbl_8053CAA8;
    *(f32*)(p + 0x26c) = lbl_8053CAA8;
    *(f32*)(p + 0x270) = lbl_8053CAA8;
    *(f32*)(p + 0x274) = lbl_8053CAA8;
    *(f32*)(p + 0x278) = lbl_8053CAA8;
    fn_801D267C(p + 0x27c);
    *(s32*)(p + 0x37c) = 0;
    *(s32*)(p + 0x380) = 0;
    return this_;
}

void __sinit_FZRA_80126A4C_cpp(void) {}

