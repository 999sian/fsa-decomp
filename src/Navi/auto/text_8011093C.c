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
// .text 0x8011093c-0x80111bac (17 functions). split_file divides it into the game's real files.

extern void* lbl_8028F1BC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301358;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
struct NaviState_8011093C;
typedef void (NaviState_8011093C::*NaviStateFn_8011093C)();
extern NaviStateFn_8011093C lbl_8028F100[];
extern "C" void fn_80060820(f32 a);
extern "C" void fn_8002F308(s32 a);
extern "C" void fn_8002F228(s32 a);
extern "C" s32 fn_8002F2E0(s32 a);
extern "C" s32 fn_8011171C(u8* self, s16 a, u8 b, u32 c, u32 d);
extern f32 lbl_8030134C;
extern u8 lbl_802C5B7C[];
extern void* lbl_802FF278;
extern u8 lbl_802FF140;
extern f32 lbl_80301340;
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" f32 fn_801118D8(u8* self, u8 b, s16 a);
struct VObj_801116EC {
    virtual void m0();
    virtual void m1(s32 a);
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7(s32 a);
};
extern "C" void fn_80111170(NaviState_8011093C* p) {
    (p->*lbl_8028F100[((u8*)p)[0x118]])();
}

extern "C" void fn_801111A8(u8* self) {
    s32 iVar1;
    if (*(s16*)(self + 0x116) == 0) {
        fn_80060820(lbl_8030134C);
        fn_8002F308(0x1e);
    }
    iVar1 = fn_8011171C(self, *(s16*)(self + 0x116), lbl_802C5B7C[0xc], 0, 0);
    *(s16*)(self + 0x116) = *(s16*)(self + 0x116) + 1;
    if (iVar1 == 1) {
        *(s16*)(self + 0x116) = 0;
        fn_8002F228(0x27);
        self[0x11c] = lbl_802C5B7C[0xd];
        self[0x118] = 1;
    }
}

extern "C" void fn_80111248(u8* self) {
    if (self[0x11c] != 0) {
        self[0x11c]--;
        return;
    }
    self[0x118] = 2;
}

extern "C" void fn_801115C4(u8* self) {
    s32 iVar2;
    void* piVar1;
    u8 b;
    iVar2 = fn_8002F2E0(0x27);
    if (iVar2 != 1) {
        if (self[0x11c] != 0) {
            self[0x11c]--;
        } else {
            self[0x11c] = 0x3c;
            b = self[0x11c];
            piVar1 = *(void**)((u8*)lbl_802FF278 + 4);
            if (piVar1 != nullptr) {
                void** vt = *(void***)piVar1;
                ((void (*)(void*, u8))vt[4])(piVar1, b);
            }
            self[0x118] = 4;
        }
    }
}

extern "C" void fn_80111648(u8* p) {
    if (p[0x11c] != 0) {
        p[0x11c]--;
    } else {
        (*(VObj_801116EC**)(p + 0x110))->m7(0xff);
        (*(u8**)(p + 0x14))[0xb0] = 0;
        p[0x11d] = 1;
        lbl_802FF140 = 0;
        p[0x11c] = 0x1e;
        u8 t = p[0x11c];
        VObj_801116EC* obj = *(VObj_801116EC**)((u8*)lbl_802FF278 + 4);
        if (obj != 0) {
            obj->m1(t);
        }
        p[0x118] = 5;
    }
}

extern "C" void fn_801116EC(u8* p) {
    if (p[0x11c] != 0) {
        p[0x11c]--;
    } else {
        p[0x11e] = 1;
        p[0x118] = 6;
    }
}

extern "C" void fn_80111718(void)
{
}

extern "C" s32 fn_8011171C(u8* self, s16 a, u8 b, u32 c, u32 d) {
    f32 f;
    if (a < 0) {
        return 0;
    }
    if (a > (u8)b) {
        return 1;
    }
    f = fn_801118D8(self, b, a);
    if ((s32)d != 2) {
        if ((s32)d == 1) {
            f = lbl_80301340 - f;
        }
        (*(VObj_801116EC**)(self + 0x110))->m7((int)((float)self[0x114] * f));
    }
    return 0;
}

extern "C" void fn_801117DC(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    if (p[0x11d] == 0) {
        fn_80060794(base, base + 0xb4, base + 0xb8, p + 8);
    } else {
        fn_80060794(base, base + 0x204, base + 0x208, p + 8);
    }
}

extern "C" void fn_80111B00(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301358;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_80111B64(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F1BC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
