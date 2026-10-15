#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct Unk802C56B4 {
    u8 pad0[4];
    s8 unk4;
    u8 pad5[3];
    u32 unk8;
    f32 unkC;
    u8 unk10;
    u8 pad11[0x13];
    u8 unk24;
};
struct VObj_800CB688A {
    virtual void v0(s32);
    virtual void v1(s32);
};
struct VObj_800CB688B {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800c9c64-0x800cb9f4 (21 functions). split_file divides it into the game's real files.

extern Unk802C56B4 lbl_802C56B4;
extern "C" s32 fn_800CB450(void*, s16, u8, s32, s32, f32, f32);
extern f32 lbl_80300E40;
struct NaviState_800CAB58 {
    void f();
};
typedef void (NaviState_800CAB58::*NaviStateFunc_800CAB58)();
extern NaviStateFunc_800CAB58 lbl_802887D8[];

extern void* lbl_802888AC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300E30;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern f32 lbl_80300E40;
extern "C" void fn_800CA7C4(u8* p) {
    p[0x160] = 2;
}

extern "C" void fn_800CAB90(void) {}

extern Unk802C56B4 lbl_802C56B4;
extern u8 lbl_8029FDB4[];
extern "C" void fn_800127A0(void*);
extern "C" s32 fn_800CB450(void*, s16, u8, s32, s32, f32, f32);
extern "C" void fn_8002F198(void);
extern "C" void fn_800CACA4(u8* p) {
    s32 r = fn_800CB450(p, *(s16*)(p + 0x15a), lbl_802C56B4.unk10, 4, 1, lbl_80300E30, -lbl_802C56B4.unkC);
    (*(s16*)(p + 0x15a))++;
    if (r == 1) {
        *(s16*)(p + 0x15a) = 0;
        if (*(s32*)(p + 0x164) != -1) {
            fn_8002F198();
        }
        p[0x15f] = 0;
        p[0x15e] = lbl_802C56B4.unk24;
        p[0x159] = 2;
        p[0x160] = 0;
    }
}

extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800CB64C(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_800CB688(u8* p) {
    VObj_800CB688A* a = *(VObj_800CB688A**)(p + 0xc);
    if (a != nullptr) {
        a->v0(1);
    }
    (*(VObj_800CB688B**)(p + 4))->v7();
    if (lbl_802C56B4.unk4 >= 0) {
        if (--lbl_802C56B4.unk8 == 0) {
            fn_800127A0(lbl_8029FDB4 + 4);
            lbl_802C56B4.unk4 = -1;
        }
    }
}

extern "C" void fn_800CB948(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300E30;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800CB9AC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802888AC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
