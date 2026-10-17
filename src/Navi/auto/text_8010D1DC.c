#include "types.h"
struct VObj_8010F81C_b {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32, f32);
};

struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8010d1dc-0x80110794 (35 functions). split_file divides it into the game's real files.

extern void* lbl_8028F058[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_803012EC;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_8010EA4C(u8* p);
extern "C" void fn_8010EB54(u8* p);
extern "C" void fn_8010EA18(u8* p) {
    if (p[0xce] == 0) {
        fn_8010EA4C(p);
    } else {
        fn_8010EB54(p);
    }
}

struct NaviState_8010D1DC;
typedef void (NaviState_8010D1DC::*NaviStateFn_8010D1DC)();
extern NaviStateFn_8010D1DC lbl_8028EF1C[];
extern "C" void fn_8010EC3C(NaviState_8010D1DC* p) {
    ((u8*)p)[0xd7] = 0;
    (p->*lbl_8028EF1C[((u8*)p)[0xcf]])();
}

extern u8 lbl_802C5B44[];
extern u8 lbl_8029FDB4[];
extern f32 lbl_80301310;
extern "C" void* fn_80177B10(void* p);
extern "C" void fn_800127A0(void* p);
extern "C" s32 fn_8011024C(u8* p, s16 t, u8 a, s32 b, s32 c);
extern "C" s32 fn_8010FEDC(u8* p, s16 t, u8 a, s32 b, s32 c, f32 x, f32 y);
extern "C" void fn_8010F570(u8* p) {
    s32 r1 = fn_8011024C(p, *(s16*)(p + 0xcc), lbl_802C5B44[0x19], 0, 1);
    s32 r2 = fn_8010FEDC(p, *(s16*)(p + 0xcc), lbl_802C5B44[0x18], 0, 1, lbl_803012EC, *(f32*)(lbl_802C5B44 + 0x14));
    *(s16*)(p + 0xcc) += 1;
    if (r1 == 1 && r2 == 1) {
        *(s16*)(p + 0xcc) = 0;
        p[0xcf] = 5;
    }
}

extern "C" s32 fn_8002F6BC();
extern "C" void fn_8002F458(s32, s32);
extern "C" void fn_8010F760(u8* p) {
    if (p[0xd4] != 0) {
        p[0xd4]--;
    } else {
        if (fn_8002F6BC() == 0) {
            p[0xd6] = p[0xd5];
            p[0xcf] = 8;
            fn_8002F458(0x9c, 0);
        }
    }
}

extern "C" void fn_8002F358(s32, s32);
extern "C" void fn_8010F7C8(u8* param_1) {
    if (fn_8002F6BC() == 0) {
        param_1[0xd4] = 0x3c;
        fn_8002F358(0x143c, 0);
        param_1[0xcf] = 1;
    }
}

extern "C" void fn_8010F818(void)
{
}

extern "C" void fn_8010F81C(u8* param_1) {
    f32 off = 53.0f * param_1[0x7c];
    (*(VObj_8010F81C_b**)(param_1 + 0x60))->v2(*(f32*)(param_1 + 0x74), *(f32*)(param_1 + 0x78) + off);
}

extern "C" void fn_801103A0(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 4);
}

extern "C" void fn_8015FDA8(void*, void*);
extern "C" void fn_80110494(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 0x10));
}

extern "C" void fn_801106E8(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_803012EC;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_8011074C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F058;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
struct VObj_8010F81C {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32, f32);
};
struct VObj_8010FD00 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32, f32);
};
struct VObj_8010F880 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(u8);
};
struct VObj_801103DC {
    virtual void v0(u8);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
