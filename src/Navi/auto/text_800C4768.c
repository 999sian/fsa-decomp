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
// .text 0x800c4768-0x800c5af8 (33 functions). split_file divides it into the game's real files.

extern "C" void fn_800C55C8(u8* p);
class NaviState_800C4768;
extern void (NaviState_800C4768::*lbl_80288294[])();

extern void* lbl_80288450[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300D8C;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_8017A4F8(void*);
extern "C" void fn_800C5648(u8* p);
extern f64 lbl_80300D90;
extern char lbl_802881B8[];
extern char lbl_80288398[];
extern char lbl_80288388[];
extern "C" void fn_800C5434(u8* param_1);
extern "C" void fn_800C5444(u8* param_1, s32 param_2);
extern u8 lbl_802C565C[];
extern "C" s32 fn_800C56A0(u8* p, u8 a, u8 b, s32 c, f32 d, f32 e);
extern "C" void fn_800C5648(u8* p);
extern "C" void fn_800C5444(u8* p, s32 n);
extern "C" void fn_800C4AC0(u8* p) {
    f32 f = lbl_80300D8C;
    u8* d = lbl_802C565C;
    p[0x38] = 0;
    fn_800C56A0(p, p[0x38], d[0xc], 0, *(f32*)(d + 0x10), f);
}

extern "C" void fn_800C4B50(void) {}

extern "C" void fn_800C4C88(u8* param_1) {
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, 0.0f, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        fn_800C5434(param_1);
        param_1[0x37] = 0;
    }
}

extern "C" void fn_800C4D04(u8* param_1) {
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, 0.0f, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        fn_800C5434(param_1);
        u8* obj = *(u8**)(param_1 + 0x24);
        void (*fn)(void*, void*, s32) = *(void (**)(void*, void*, s32))(*(u8**)obj + 0x114);
        fn(obj, lbl_802881B8, 0);
        param_1[0x36] = 0;
        param_1[0x37] = 0;
    }
}

extern "C" void fn_800C4DA4(u8* param_1) {
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, 0.0f, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        fn_800C5444(param_1, 0);
        param_1[0x36] = 0;
        param_1[0x37] = 0;
    }
}

extern "C" void fn_800C4E28(u8* param_1) {
    u8* tbl = lbl_802C565C;
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], tbl[0xc], 0, lbl_80300D8C, *(f32*)(tbl + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        fn_800C5444(param_1, 1);
        param_1[0x35] = 1;
        param_1[0x36] = 1;
        param_1[0x37] = 0;
    }
}

extern "C" void fn_800C4EB4(u8* param_1) {
    fn_800C5648(param_1);
    fn_800C5444(param_1, 1);
    param_1[0x35] = 1;
    param_1[0x36] = 1;
    param_1[0x37] = 0;
}

extern "C" void fn_800C4F00(u8* param_1) {
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, lbl_80300D8C, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        fn_800C5444(param_1, 2);
        param_1[0x36] = 0;
        param_1[0x37] = 0;
    }
}

extern "C" void fn_800C4F84(u8* param_1) {
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, lbl_80300D8C, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        fn_800C5444(param_1, 3);
        param_1[0x36] = 0;
        param_1[0x37] = 0;
    }
}

extern "C" void fn_800C51FC(u8* param_1) {
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, 0.0f, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        u8* obj = *(u8**)(param_1 + 0x24);
        void (*fn)(void*, void*, s32) = *(void (**)(void*, void*, s32))(*(u8**)obj + 0x114);
        fn(obj, lbl_80288388, 0);
        param_1[0x35] = 1;
        param_1[0x36] = 1;
        param_1[0x37] = 0;
    }
}

extern "C" void fn_800C539C(u8* param_1) {
    void* obj;
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, 0.0f, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        obj = *(void**)(param_1 + 0x24);
        ((void (*)(void*, void*, s32))(*(u8**)(*(u8**)obj + 0x114)))(obj, lbl_80288398, 0);
        param_1[0x36] = 0;
        param_1[0x37] = 0;
    }
}

extern "C" void fn_800C5434(u8* param_1) {
    *(u8*)(*(u8**)(param_1 + 0x1c) + 0xb0) = 1;
}

extern "C" void fn_800C5510(u8* param_1) {
    u8* p = *(u8**)(param_1 + 0x18);
    if (p[0xb0] != 0) {
        return;
    }
    p[0xb0] = 1;
}

extern "C" void fn_800C552C(u8* param_1) {
    u8* p = *(u8**)(param_1 + 0x18);
    if (p[0xb0] == 0) {
        return;
    }
    p[0xb0] = 0;
}

extern "C" void fn_800C5548(u8* param_1) {
    *(u8*)(*(u8**)(param_1 + 0x1c) + 0xb0) = 1;
    *(u8*)(*(u8**)(param_1 + 0x18) + 0xb0) = 1;
    param_1[0x35] = 0;
    param_1[0x34] = 0;
    param_1[0x36] = 0;
    fn_800C5648(param_1);
    {
        void* obj = *(void**)(param_1 + 0x24);
        void** vt = *(void***)obj;
        ((void (*)(void*, void*, s32))vt[0x114 / 4])(obj, lbl_802881B8, 0);
    }
}

extern "C" void fn_800C55B8(u8* param_1, u8 param_2) {
    if (param_2 != 0) {
        param_1[0x37] = param_2;
    }
}

extern "C" void fn_800C55C8(u8* param_1) {
    if (param_1[0x34] != 0) {
        u8* p;

        *(s32*)(param_1 + 0x30) = *(s32*)(param_1 + 0x30) + 1;
        p = *(u8**)(param_1 + 0x2c);
        if (*(s32*)(param_1 + 0x30) >= *(s16*)(p + 6)) {
            *(s32*)(param_1 + 0x30) = *(s32*)(param_1 + 0x30) - *(s16*)(p + 6);
        }
        *(f32*)(*(u8**)(param_1 + 0x2c) + 8) = (f32)*(s32*)(param_1 + 0x30);
        fn_8017A4F8(*(void**)(param_1 + 8));
    }
}

extern "C" void fn_800C5648(u8* param_1) {
    param_1[0x34] = 0;
    *(s32*)(param_1 + 0x30) = 0;
    *(f32*)(*(u8**)(param_1 + 0x2c) + 8) = (f32)*(s32*)(param_1 + 0x30);
    fn_8017A4F8(*(void**)(param_1 + 8));
}

extern "C" void fn_800C576C(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 4);
}

extern "C" void fn_800C57A8(u8* param_1) {
    void* obj = *(void**)(param_1 + 0x2c);
    if (obj != 0) {
        (*(void (**)(void*, s32))(*(u8**)obj + 0x8))(obj, 1);
    }
    obj = *(void**)(param_1 + 0x8);
    if (obj != 0) {
        (*(void (**)(void*, s32))(*(u8**)obj + 0x8))(obj, 1);
    }
    obj = *(void**)(param_1 + 0xc);
    (*(void (**)(void*))(*(u8**)obj + 0x24))(obj);
}

extern "C" void fn_800C5A4C(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300D8C;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800C5AB0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288450;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
