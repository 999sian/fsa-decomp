#include "Game/Actor.h"


extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void* lbl_8053AAF8;
extern "C" void fn_8034335C(Actor* a, s32 room, f32* pos);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 flag, f32 a, f32 b);
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern "C" u8 fn_8022D75C(s32 i);
extern "C" u8 fn_80234ECC(s32 i);
extern "C" u8 fn_8023ED8C(s32 i);
extern "C" s32 fn_8023ECF0(s32 i);
extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_8022F478(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" u8 fn_8022B7C4(s32 i);
extern "C" u8 fn_802349EC(s32 i);
extern "C" void fn_80238548(s32 i, s32 b, f32* p, s32 d);
extern "C" void fn_802F601C(void* obj, f32* pos, f32 a, f32 b, s32 c, s32 d);
extern "C" void fn_8013CC50(s32 room, f32* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
extern "C" void fn_801F0E34(Actor* a, u32 code, u32 z);
extern "C" void* lbl_8053AB10;

extern "C" void fn_80341CB0(s32 id, f32* pos) {
    Actor_CreateByID(fn_801F856C(), 0x42424D42, id, pos, 0x30000, -1, -1);
}

extern "C" void fn_8034335C(Actor* p, s32 room, f32* pos) {
    u8 flags[4];
    s32 i;

    fn_802D79E8(fn_802D6A9C(), room, 0, 1.0f, 0.0f);
    fn_80134DE4(lbl_8053AAF8, 3, 0);
    flags[0] = 0;
    flags[1] = 0;
    flags[2] = 0;
    flags[3] = 0;
    for (i = 0; i < 4; i++) {
        if (fn_8022D75C(i) == 1 && fn_80234ECC(i) == 0) {
            flags[i] = 1;
            if (fn_8023ED8C(i) == 1) {
                flags[fn_8023ECF0(i)] = 1;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (fn_8023F264(i) != 0 && fn_8022F478(i) == 0) {
            if (fn_8023DE58(i) < 8) {
                if (fn_80230188(i) == 0 && fn_8022B7C4(i) == 0 && fn_802349EC(i) == 0 && flags[i] == 0) {
                    fn_80238548(i, 0x20, pos, 0x13);
                }
            }
        }
    }
    if (room < 8) {
        fn_802F601C(*(void**)((u8*)lbl_8053AB10 + 0x20), pos, 1.0f, 1.0f, 6, 0);
    }
    fn_8013CC50(room, pos, 0x33, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x34, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x35, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x36, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x37, 1, 1, 0, 0, 1, 1.0f);
    fn_8013CC50(room, pos, 0x38, 1, 1, 0, 0, 1, 1.0f);
    fn_801F0E34(p, 0x30001, 0);
}

extern "C" void fn_803435F8(Actor* p) {
    *(u32*)((u8*)p + 0x244) = *(u32*)((u8*)p + 0x90) & 0xfff;
    *(u32*)((u8*)p + 0x118) = 0x80;
    *(u32*)((u8*)p + 0x230) = 0;
    *(u32*)((u8*)p + 0x23c) = 0;
    *(u32*)((u8*)p + 0x240) = 0;
    *(u32*)((u8*)p + 0x234) = 0;
    *(u8*)((u8*)p + 0x260) = 0;
    *(u32*)((u8*)p + 0x238) = 0;
    *(u32*)((u8*)p + 0x248) = (*(u32*)((u8*)p + 0x90) >> 12) & 3;
    *(u32*)((u8*)p + 0x24c) = (*(u32*)((u8*)p + 0x90) >> 16) & 0xf;
    *(u8*)((u8*)p + 0x261) = 0;
    *(u32*)((u8*)p + 0x250) = 0x100000d;
    *(u32*)((u8*)p + 0x108) = 10000;
    *(f32*)((u8*)p + 0x80) = -24.0f;
    *(f32*)((u8*)p + 0x84) = -24.0f;
    *(f32*)((u8*)p + 0x88) = 24.0f;
    *(f32*)((u8*)p + 0x8c) = 24.0f;
    *(f32*)((u8*)p + 0x60) = -24.0f;
    *(f32*)((u8*)p + 0x64) = -24.0f;
    *(f32*)((u8*)p + 0x68) = 24.0f;
    *(f32*)((u8*)p + 0x6c) = 24.0f;
    *(f32*)((u8*)p + 0x70) = -24.0f;
    *(f32*)((u8*)p + 0x74) = -24.0f;
    *(f32*)((u8*)p + 0x78) = 24.0f;
    *(f32*)((u8*)p + 0x7c) = 24.0f;
    *(f32*)((u8*)p + 0x254) = 0.75f;
    *(f32*)((u8*)p + 0x258) = 0.75f;
    *(f32*)((u8*)p + 0x25c) = 0.75f;
    switch (*(u32*)((u8*)p + 0x24c)) {
    case 0:
        *(f32*)((u8*)p + 0x80) = 0.0f;
        *(f32*)((u8*)p + 0x84) = 0.0f;
        *(f32*)((u8*)p + 0x88) = 0.0f;
        *(f32*)((u8*)p + 0x8c) = 0.0f;
        *(f32*)((u8*)p + 0x60) = 0.0f;
        *(f32*)((u8*)p + 0x64) = 0.0f;
        *(f32*)((u8*)p + 0x68) = 0.0f;
        *(f32*)((u8*)p + 0x6c) = 0.0f;
        *(f32*)((u8*)p + 0x70) = 0.0f;
        *(f32*)((u8*)p + 0x74) = 0.0f;
        *(f32*)((u8*)p + 0x78) = 0.0f;
        *(f32*)((u8*)p + 0x7c) = 0.0f;
        *(f32*)((u8*)p + 0x25c) = 0.0f;
        *(f32*)((u8*)p + 0x258) = 0.0f;
        *(f32*)((u8*)p + 0x254) = 0.0f;
        break;
    case 1:
        *(f32*)((u8*)p + 0x14) = 400.0f;
        *(u32*)((u8*)p + 0x230) = 2;
        if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
            *(u8*)((u8*)p + 0x261) = 1;
        }
        break;
    case 2:
        *(u32*)((u8*)p + 0x230) = 3;
        if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
            *(u8*)((u8*)p + 0x261) = 1;
        }
        break;
    case 3:
        fn_8034335C(p, *(u32*)((u8*)p + 0x4), (f32*)((u8*)p + 0xc));
        *(u32*)((u8*)p + 0x230) = 7;
        *(u32*)((u8*)p + 0x234) = 3;
        break;
    }
    *(u32*)((u8*)p + 0x264) = 0;
    *(u32*)((u8*)p + 0x268) = 0;
}

extern "C" char lbl_804AC588[];
extern "C" void fn_801EE434(void* obj);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dt__5ActorFv(Actor* self, s32 flag);
extern "C" Actor* fn_803437B0(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AC588;
        fn_801EE434(*(void**)((u8*)p + 0x264));
        fn_801EE434(*(void**)((u8*)p + 0x268));
        if (((u8*)p)[0x261] == 1) {
            s32 kind = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
            if (kind != 9 && kind != 0xb) {
                fn_80138B7C(lbl_8053AAF8);
            }
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

