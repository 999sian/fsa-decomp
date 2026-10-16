#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"

extern const f32 lbl_80543C88;
extern const f32 lbl_80543CC4;
extern const f32 lbl_80543CC8;
extern const f32 lbl_80543CE8;
extern const f32 lbl_80543CEC;


extern void* lbl_8053AED0;
extern "C" void* fn_8043DF8C(void* game);
extern char* lbl_8053AAF8;
extern s32 lbl_8053AEF0;
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
extern "C" void fn_8041FC2C(void* p);
extern "C" void fn_8044A06C(...);
extern "C" void fn_80445D24(...);
extern "C" void fn_80448334(...);
extern "C" void fn_8044AFD8(...);
extern "C" void fn_804490B8(...);
extern "C" void fn_804479A0(...);
extern "C" void fn_80446DB0(...);
extern "C" void fn_804263A8(void* p);
extern "C" void fn_80443688(s32 p);
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

extern "C" void fn_8043CEA0(u8* self) {
    *(s16*)(self + 0x104) = *(s16*)(self + 0x104) - 1;
    if (*(s32*)(lbl_8053AAF8 + 0x4c) != 7) {
        *(s16*)(self + 0x104) = 0;
    }
    if (*(s16*)(self + 0x104) > 0) {
        return;
    }
    *(s16*)(*(u8**)(self + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x50) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x54) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x58) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x5c) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x60) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x64) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x68) + 0x22) = 0;
    *(s16*)(*(u8**)(self + 0x6c) + 0x22) = 0;
    self[0x10b] = 3;
}

extern "C" f32 fn_8043D514(u8* param_1) {
    f32 ret = lbl_80543C88;
    if (param_1[0x10b] != 0 && param_1[0x10c] == 1) {
        J2DPane* pane = *(J2DPane**)(*(u8**)(param_1 + 0x64) + 4);
        ret = (lbl_80543CE8 * (lbl_80543CEC - (pane->getBounds()->i.y - lbl_80543CC8))) / lbl_80543CC4;
    }
    return ret;
}

extern "C" f32 fn_8043D57C(u8* param_1) {
    f32 ret = lbl_80543C88;
    if (param_1[0x10b] != 0 && param_1[0x10c] == 0) {
        J2DPane* pane = *(J2DPane**)(*(u8**)(param_1 + 0x40) + 4);
        f32 dy = pane->getBounds()->i.y - *(f32*)(*(u8**)(param_1 + 0x40) + 0xc);
        ret = (lbl_80543CE8 * (lbl_80543CC4 - dy)) / lbl_80543CC4;
    }
    return ret;
}

extern void* lbl_8053AB10;
extern "C" void fn_8013B490(void* p);
extern "C" void fn_8043D5F0(u8* param_1) {
    fn_8013B490(lbl_8053AB10);
    *(u8*)(*(u8**)(param_1 + 4) + 0x100) = 1;
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543C88, lbl_80543C88, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
}

extern "C" void fn_8043D834(u8* self) {
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041E58C(*(void**)(self + 0x290));
    } else {
        fn_80425128(*(void**)(self + 0x294));
    }
}

extern "C" void fn_8043D874(u8* param_1) {
    u8* game = (u8*)lbl_8053AAF8;
    if (game[0x7f] != 0) {
        fn_8041E708(*(void**)(param_1 + 0x290));
    } else {
        fn_80425234(*(void**)(param_1 + 0x294));
    }
}

extern "C" s32 fn_8043DF24(f32 x, f32 y, f32 px, f32 py, f32 r) {
    f32 a = lbl_80543CFC;
    f32 b = lbl_80543CF8;
    f32 dx = x - a;
    f32 dy = y - b;
    f32 sx = a + x;
    f32 left = dx - r;
    f32 sy = b + y;
    f32 bottom = dy - r;
    f32 right = r + sx;
    f32 top = r + sy;
    if (px >= left && px <= right && py >= bottom && py <= top) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8043EDE8(char* param_1, s32 param_2) {
    *(s32*)(param_1 + 0xe0) = param_2;
    *(s32*)(param_1 + 0xe4) = 0x1e;
}

extern "C" void fn_8043EDF8(u8* param_1) {
    param_1[0xdd] = 0;
    param_1[0xdc] = 0;
    param_1[0x255] = 0;
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        fn_8041FC2C(*(void**)(param_1 + 0x290));
        if (*(void**)(param_1 + 0x2b0) != NULL) {
            fn_8044A06C();
        }
        if (*(void**)(param_1 + 0x29c) != NULL) {
            fn_80445D24();
        }
        if (*(void**)(param_1 + 0x2a8) != NULL) {
            fn_80448334();
        }
        if (*(void**)(param_1 + 0x2b4) != NULL) {
            fn_8044AFD8();
        }
        if (*(void**)(param_1 + 0x2ac) != NULL) {
            fn_804490B8();
        }
        if (*(void**)(param_1 + 0x2a4) != NULL) {
            fn_804479A0();
        }
        if (*(void**)(param_1 + 0x2a0) != NULL) {
            fn_80446DB0();
        }
    } else {
        fn_804263A8(*(void**)(param_1 + 0x294));
    }
    if (*(void**)(param_1 + 0x298) != NULL) {
        fn_80443688(lbl_8053AEF0);
    }
}

extern "C" void fn_804408F0(JGeometry::TVec3<f32>* self) {
    JGeometry::TVec3<f32> v;
    v.x = self->x;
    v.y = self->y;
    v.z = self->z;
    fn_8043E7CC(lbl_8053AED0, &v);
}

extern "C" void* fn_80440928(void) { return fn_8043DF8C(lbl_8053AED0); }
