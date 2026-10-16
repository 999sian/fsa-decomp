#include "types.h"
#include "JSystem/J2D/J2DPane.h"

extern const f32 lbl_80543C88;
extern const f32 lbl_80543CC4;
extern const f32 lbl_80543CC8;
extern const f32 lbl_80543CE8;
extern const f32 lbl_80543CEC;


extern void* lbl_8053AED0;
extern "C" void* fn_8043DF8C(void* game);
extern char* lbl_8053AAF8;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern "C" void fn_8043A450(void* param_1, s32 param_2, s32 param_3);
extern const f32 lbl_80543CFC;
extern const f32 lbl_80543CF8;
extern "C" void fn_8041E708(void* p);
extern "C" void fn_80425234(void* p);
extern "C" void fn_8043E7CC(void* game, void* v);
extern "C" void fn_8041E58C(void* p);
extern "C" void fn_80425128(void* p);
extern "C" void fn_8043A0E8(u8 param_1) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0 && (*(u32*)(lbl_8050EC80 + 0x28 + 0xc8 * *(s32*)(lbl_8050EC80 + 0x10)) & 1) == 0 &&
        *(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 0) {
        if (param_1 == 0) {
            return;
        }
    }
    if (*(s32*)(lbl_80529DEC + 0x118) == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
        return;
    }
    *((u8*)lbl_8053AED0 + 0xdd) = 0xf;
}

extern "C" void fn_8043A170(u32 param_1, u8 param_2) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0 && (*(u32*)(lbl_8050EC80 + 0x28 + 0xc8 * *(s32*)(lbl_8050EC80 + 0x10)) & 1) == 0 &&
        *(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 0) {
        if (param_2 == 0) {
            return;
        }
    }
    if (*(s32*)(lbl_80529DEC + 0x118) == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2) {
        return;
    }
    *((u8*)lbl_8053AED0 + 0xdd) = *((u8*)lbl_8053AED0 + 0xdd) | (u8)(1 << param_1);
}

extern "C" void fn_8043A208(u8* param_1, f32 param_2, f32 param_3, f32 param_4, f32 param_5) {
    struct VObj {
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
    };
    if (*(void**)(param_1 + 0x10) != NULL) {
        *(f32*)(param_1 + 0x1c0) = param_2;
        *(f32*)(param_1 + 0x1c4) = param_3;
        *(f32*)(param_1 + 0x1c8) = param_4;
        *(f32*)(param_1 + 0x1cc) = param_5;
        ((VObj*)*(void**)(param_1 + 0x10))->v07();
        *(u8*)(param_1 + 0x254) = 1;
    }
}

extern "C" void fn_8043A608(void* param_1) {
    fn_8043A450(param_1, *(s32*)(lbl_80529DEC + 0x118), *(s32*)(lbl_80529DEC + 0x11c));
}

extern "C" void fn_8043D874(char* param_1) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041E708(*(void**)(param_1 + 0x290));
    } else {
        fn_80425234(*(void**)(param_1 + 0x294));
    }
}

extern "C" s32 fn_8043DF24(f32 x, f32 y, f32 px, f32 py, f32 r) {
    f32 a = lbl_80543CFC;
    f32 b = lbl_80543CF8;
    f32 left = (x - a) - r;
    f32 right = r + (a + x);
    f32 bottom = (y - b) - r;
    f32 top = r + (b + y);
    if (px >= left && px <= right && py >= bottom && py <= top) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8043EDE8(char* param_1, s32 param_2) {
    *(s32*)(param_1 + 0xe0) = param_2;
    *(s32*)(param_1 + 0xe4) = 0x1e;
}

extern "C" void* fn_80440928(void) { return fn_8043DF8C(lbl_8053AED0); }
