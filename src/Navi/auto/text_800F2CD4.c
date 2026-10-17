#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800f2cd4-0x800f4a54 (24 functions). split_file divides it into the game's real files.

extern void* lbl_8028C5D0[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301198;
extern f32 lbl_8030119C;
extern u8 lbl_802C5A54[];

struct VObj_800F4328 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32 x, f32 y);
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7(u8 mode);
};
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800F39E8(void);
extern "C" void fn_800F3B20(void);
extern "C" int fn_8002F6BC(void);
extern "C" void fn_8002F9B4(void);
extern "C" int fn_80181BA0(void* self);
extern "C" void fn_8003ABDC(void*, u32, u32, s32, s32);
extern "C" void fn_8003ABF0(void*, u32, s32, u32, s32, s32, s32, s32);
extern "C" void fn_800F4458(u8* p, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern "C" void fn_800F4570(u8* p, s32 i, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern u8 lbl_802C5A54[];
struct NaviState_800F3D84;
typedef void (NaviState_800F3D84::*NaviStateFn_800F3D84)();
extern NaviStateFn_800F3D84 lbl_8028C538[];
extern "C" void fn_800F3730(u8* p) {
    s32 i;
    f32 c = lbl_80301198;
    *(s16*)(p + 0x5c) = 0;
    *(u8*)(*(u8**)(p + 0x4c) + 0xb0) = 0;
    fn_800F4458(p, *(s16*)(p + 0x5c), lbl_802C5A54[0x14], 0, 0, *(f32*)(lbl_802C5A54 + 0x10), c);
    for (i = 0; i < 2; i++) {
        fn_800F4570(p, i, *(s16*)(p + 0x5c), lbl_802C5A54[0x1c], 0, 0, *(f32*)(lbl_802C5A54 + 0x18), lbl_80301198);
    }
}

extern "C" void fn_800F42C4(u8* p);

extern "C" void fn_800F37D8(u8* p) {
    p[0x58] = 0;
    fn_800F42C4(p);
    u32 v;
    s32 id = fn_80181BA0(*(void**)(p + 0x24));
    v = 0x3cd;
    if (p[0x63] != 0) {
        v = 0x289;
    }
    fn_8003ABDC(*(void**)(p + 0xc), *(u32*)(p + 0x28), *(u32*)(p + 0x2c), 0, 0);
    fn_8003ABF0(*(void**)(p + 0xc), id, 0, *(u32*)(p + 0x24), 0, v, 1, 1);
    p[0x61] = 0;
    p[0x5f] = 8;
}

extern "C" void fn_801E10DC(void*);
extern "C" void fn_800F39B4(u8* p) {
    if (p[0x63] == 1) {
        fn_800F39E8();
    } else {
        fn_800F3B20();
    }
}

extern "C" void fn_800F3D84(NaviState_800F3D84* p) {
    ((u8*)p)[0x62] = 0;
    (p->*lbl_8028C538[((u8*)p)[0x5e]])();
}

extern "C" void fn_800F4248(u8* p) {
    if (p[0x5f] != 0) {
        p[0x5f]--;
    } else {
        if (fn_8002F6BC() == 0) {
            if (p[0x63] == 0 && p[0x60] == 2) {
                fn_8002F9B4();
            }
            p[0x61] = p[0x60];
            p[0x5e] = 3;
        }
    }
}

extern "C" void fn_800F42C0(void) {}

extern "C" void fn_800F4328(u8* p) {
    p[0x59] = 0;
    p[0x5a] = 1;
    (*(VObj_800F4328**)(p + 0x4c))->v7(lbl_802C5A54[0x1f]);
}

extern "C" void fn_800F46AC(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 4);
}

extern "C" void fn_800F49A8(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301198;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800F4A0C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028C5D0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
