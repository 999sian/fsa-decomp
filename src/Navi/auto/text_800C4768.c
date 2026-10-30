#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct Color_800C5104 {
    u8 r, g, b, a;
};

struct VObj_800C5104 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66();
    virtual void setString(const char*, s32);
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72();
    virtual void setColor(Color_800C5104);
};

struct VObj_800C56A0 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32, f32);
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800c4768-0x800c5af8 (33 functions). split_file divides it into the game's real files.

extern "C" void fn_800C55C8(u8* p);
class NaviState_800C4768;
extern void (NaviState_800C4768::*lbl_80288294[])();
extern "C" void fn_8002F358(s32 a, s32 b);

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
extern "C" s32 fn_800C56A0(u8* p, s16 a, u8 b, s32 c, f32 d, f32 e);
extern "C" f32 fn_800C5824(u8* p, u8 b, s16 a);
extern "C" f32* fn_80177B10(void* p);
extern "C" void fn_800C5648(u8* p);
extern "C" void fn_800C5444(u8* p, s32 n);
extern "C" void fn_800C4AC0(u8* p) {
    f32 f = lbl_80300D8C;
    u8* d = lbl_802C565C;
    p[0x38] = 0;
    fn_800C56A0(p, p[0x38], d[0xc], 0, *(f32*)(d + 0x10), f);
}

extern "C" void fn_800C4B04(u8* p) {
    (((NaviState_800C4768*)p)->*lbl_80288294[p[0x37]])();
    fn_800C55C8(p);
}

extern "C" void fn_800C4B50(void) {}

extern "C" void fn_800C4B54(u8* p) {
    u8* d = lbl_802C565C;
    f32 f = *(f32*)(d + 0x10);
    s32 iVar1 = fn_800C56A0(p, p[0x38], d[0xc], 0, lbl_80300D8C, f);
    p[0x38]++;
    if (iVar1 == 1) {
        p[0x38] = 0;
        fn_800C5648(p);
        if (p[0x36]) {
            p[0x35] = 1;
        }
        p[0x37] = 0;
    }
}

extern "C" void fn_800C4BDC(u8* p) {
    s32 iVar1;

    if (p[0x38] == 0 && p[0x35] == 1) {
        fn_8002F358(0x2e, 0);
    }
    iVar1 = fn_800C56A0(p, p[0x38], lbl_802C565C[0xc], 1, *(f32*)(lbl_802C565C + 0x10), lbl_80300D8C);
    p[0x38]++;
    if (iVar1 == 1) {
        if (p[0x35] == 1) {
            p[0x34] = 1;
            p[0x35] = 0;
        }
        p[0x38] = 0;
        p[0x37] = 0;
    }
}

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

extern u8 lbl_80288360[];
extern u8 lbl_80288370[];
extern "C" void fn_800C5008(u8* param_1) {
    Color_800C5104 color;
    s32 iVar1;

    iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, lbl_80300D8C, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        ((VObj_800C5104*)*(u8**)(param_1 + 0x24))->setString((const char*)lbl_80288360, 0);
        ((VObj_800C5104*)*(u8**)(param_1 + 0x20))->setString((const char*)lbl_80288370, 0);
        color.r = 0xff;
        color.g = 0x28;
        color.b = 0x28;
        color.a = 0xff;
        ((VObj_800C5104*)*(u8**)(param_1 + 0x20))->setColor(color);
        fn_800C5444(param_1, 0);
        param_1[0x36] = 0;
        param_1[0x37] = 0;
    }
}

extern char lbl_8028837C[];
extern "C" void fn_800C5104(u8* param_1) {
    u8* tbl = lbl_802C565C;
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], tbl[0xc], 0, lbl_80300D8C, *(f32*)(tbl + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        (*(VObj_800C5104**)(param_1 + 0x24))->setString(lbl_802881B8, 0);
        (*(VObj_800C5104**)(param_1 + 0x20))->setString(lbl_8028837C, 0);
        Color_800C5104 c;
        c.r = 0;
        c.g = 0xff;
        c.b = 0xff;
        c.a = 0xff;
        Color_800C5104 c2 = c;
        (*(VObj_800C5104**)(param_1 + 0x20))->setColor(c2);
        fn_800C5434(param_1);
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

#pragma dont_inline on
extern "C" void fn_800C529C(u8* param_1) {
    s32 iVar1 = fn_800C56A0(param_1, param_1[0x38], lbl_802C565C[0xc], 0, lbl_80300D8C, *(f32*)(lbl_802C565C + 0x10));
    param_1[0x38]++;
    if (iVar1 == 1) {
        param_1[0x38] = 0;
        fn_800C5648(param_1);
        (*(VObj_800C5104**)(param_1 + 0x24))->setString(lbl_80288388, 0);
        (*(VObj_800C5104**)(param_1 + 0x20))->setString(lbl_8028837C, 0);
        Color_800C5104 c;
        c.r = 0;
        c.g = 0xff;
        c.b = 0xff;
        c.a = 0xff;
        (*(VObj_800C5104**)(param_1 + 0x20))->setColor(c);
        param_1[0x35] = 1;
        param_1[0x36] = 1;
        fn_800C5434(param_1);
        param_1[0x37] = 0;
    }
}
#pragma dont_inline reset
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

extern char lbl_80288158[];
extern "C" void fn_800C5444(u8* p, s32 n) {
    void* obj;
    char* base = lbl_80288158;
    *(u8*)(*(u8**)(p + 0x1c) + 0xb0) = 0;
    switch (n) {
    case 0:
        break;
    case 1:
        obj = *(void**)(p + 0x24);
        (*(void (**)(void*, void*, s32))(*(u8**)obj + 0x114))(obj, base + 0x230, 0);
        p[0x35] = 1;
        p[0x36] = 1;
        break;
    case 2:
        obj = *(void**)(p + 0x24);
        (*(void (**)(void*, void*, s32))(*(u8**)obj + 0x114))(obj, base + 0x240, 0);
        break;
    case 3:
        obj = *(void**)(p + 0x24);
        (*(void (**)(void*, void*, s32))(*(u8**)obj + 0x114))(obj, base + 0x60, 0);
        break;
    }
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

extern "C" s32 fn_800C56A0(u8* p, s16 a, u8 b, s32 c, f32 d, f32 e) {
    if (a < 0) {
        return 0;
    }
    if (a > b) {
        return 1;
    }
    f32 t = fn_800C5824(p, b, a);
    f32 lerp = t * (e - d);
    f32 y = d + lerp;
    f32 v = *fn_80177B10(*(void**)(p + 0x10));
    ((VObj_800C56A0*)*(void**)(p + 0x10))->v2(v, *(f32*)(p + 0x14) + y);
    return 0;
}

extern "C" void fn_800C576C(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 4);
}

extern "C" void fn_800C57A8(u8* param_1) {
    void* obj = *(void**)(param_1 + 0x2c);
    if (obj != 0) {
        u32 vt = *(u32*)obj;
        ((void (*)(void*, s32))(*(u32*)(vt + 0x8)))(obj, 1);
    }
    obj = *(void**)(param_1 + 0x8);
    if (obj != 0) {
        u32 vt = *(u32*)obj;
        ((void (*)(void*, s32))(*(u32*)(vt + 0x8)))(obj, 1);
    }
    obj = *(void**)(param_1 + 0xc);
    u32 vt = *(u32*)obj;
    ((void (*)(void*))(*(u32*)(vt + 0x24)))(obj);
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
