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
// .text 0x800be1cc-0x800c43d8 (61 functions). split_file divides it into the game's real files.

extern void* lbl_80288148[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300D34;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern u8 lbl_802BB0FC[];
extern u8 lbl_802C562C[];
extern "C" s32 fn_800C3494(void);
extern "C" s32 fn_800C3900(void* p, s16 idx, u8 b, s32 c);
extern "C" s32 fn_800C3A1C(void* p, s16 idx, u8 b, s32 c, s32 d);
extern "C" s32 fn_800C3B30(void* p, s16 idx, u8 b, f32 f, f32 g, s32 c, s32 d);
extern "C" void fn_8002F458(s32 a, s32 b);
extern "C" void fn_8002F358(s32 a, s32 b);
extern "C" void fn_8003ABDC(void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_8003ABF0(void* p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern "C" s32 fn_8002F168(void* p);
extern u8 lbl_80287F74[];
extern u8 lbl_802313EC[];
extern "C" u8 fn_800F0E14(void* p, u8 b);
extern "C" void fn_800C2364(u8* p) {
    fn_8002F358(0x8e, 0);
    *(*(u8**)(p + 0x194) + 0xb0) = 1;
    fn_8003ABDC(*(void**)(p + 0x28), 0, 0, 0, 0);
    u8* q = p + ((p[0x182] ^ 1) * 4);
    fn_8003ABF0(*(void**)(p + 0x28), *(u32*)(q + 0x184), 0, *(u32*)(q + 0x178), 0, 0x285, 1, 0);
    p[0x212] = 7;
}

extern "C" void fn_800C23F8(u8* p) {
    *(*(u8**)(p + 0x19c) + 0xb0) = 1;
    *(*(u8**)(p + 0x1a0) + 0xb0) = 1;
    p[0x212] = 7;
}

extern "C" void fn_800C256C(u8* p) {
    s32 a = fn_800C3900(p, *(s16*)(p + 0x21e), lbl_802C562C[0x15], 0);
    s32 b = fn_800C3A1C(p, *(s16*)(p + 0x21e), lbl_802C562C[0x15], 0, 0);
    *(s16*)(p + 0x21e) = *(s16*)(p + 0x21e) + 1;
    if (a == 1 && b == 1) {
        *(s16*)(p + 0x21e) = 0;
        p[0x182] = p[0x182] ^ 1;
        p[0x212] = 8;
    }
}

extern "C" void fn_800C2610(u8* p) {
    if ((*(u32*)(lbl_802BB0FC + 0x108) & 0x4000) == 0) {
        return;
    }
    p[0x222] = 2;
    *(u16*)(p + 0x220) = 0xe;
    p[0x212] = 9;
}

extern "C" void fn_800C2640(u8* p) {
    u16 n;
    p[0x220] = p[0x220];
    n = *(u16*)(p + 0x220);
    if (n != 0) {
        *(u16*)(p + 0x220) = n - 1;
    } else {
        if (fn_800C3494() == 1) {
            p[0x222] = 1;
            p[0x212] = 10;
        }
    }
}

extern "C" void fn_800C2850(u8* p) {
    if (*(s16*)(p + 0x21e) == 0) {
        fn_8002F458(0x9a, 0);
    }
    s32 r = fn_800C3B30(p, *(s16*)(p + 0x21e), lbl_802C562C[0x14], *(f32*)(lbl_802C562C + 0x10), lbl_80300D34, 0, 0);
    *(s16*)(p + 0x21e) = *(s16*)(p + 0x21e) + 1;
    if (r == 1) {
        *(s16*)(p + 0x21e) = 0;
        p[0x1d8] = 1;
        fn_8002F458(0x96, 0);
        p[0x212] = 0xc;
    }
}

extern "C" void fn_800C28F0(u8* p) {
    if (fn_8002F168(p) != 1) {
        *(u16*)(p + 0x220) = lbl_802C562C[0x1e];
        p[0x212] = 0xd;
    }
}

extern "C" void fn_800C293C(u8* p) {
    if (*(u16*)(p + 0x220) != 0) {
        *(u16*)(p + 0x220) = *(u16*)(p + 0x220) - 1;
        return;
    }
    p[0x222] = 2;
    *(u16*)(p + 0x220) = 10;
    p[0x212] = 0xe;
}

extern "C" s32 fn_800C301C(u8* p, u8* a, u8* b) {
    p[0x12c] = a[0];
    p[0x12d] = a[1];
    p[0x12e] = a[2];
    p[0x12f] = a[3];
    p[0x128] = b[0];
    p[0x129] = b[1];
    p[0x12a] = b[2];
    p[0x12b] = b[3];
    return 1;
}

extern "C" void fn_800C3240(u8* p) {
    u16 n = *(u16*)(p + 0x220);
    if (n != 0) {
        *(u16*)(p + 0x220) = n - 1;
        return;
    }
    *(u8*)(*(u32*)(p + 0x1fc) + 0xb0) = 1;
    p[0x212] = 0x12;
}

extern "C" void fn_800C3270(u8* p) {
    if (fn_8002F168(p) != 1) {
        *(u16*)(p + 0x220) = 0x46;
        p[0x212] = 0x13;
    }
}

extern "C" void fn_800C32B4(u8* p) {
    if (*(u16*)(p + 0x220) != 0) {
        *(u16*)(p + 0x220) = *(u16*)(p + 0x220) - 1;
    } else {
        if (fn_8002F168(p) != 1) {
            *(u16*)(p + 0x220) = lbl_802C562C[0x1f];
            p[0x212] = 0x14;
        }
    }
}

extern "C" void fn_800C3318(u8* p) {
    if (*(u16*)(p + 0x220) != 0) {
        *(u16*)(p + 0x220) = *(u16*)(p + 0x220) - 1;
        return;
    }
    p[0x222] = 2;
    *(u16*)(p + 0x220) = 10;
    p[0x212] = 0x15;
}

extern "C" void fn_800C334C(u8* p) {
    if (*(u16*)(p + 0x220) != 0) {
        *(u16*)(p + 0x220) = *(u16*)(p + 0x220) - 1;
    } else {
        if (fn_800C3494() == 1) {
            p[0x222] = 1;
            p[0x212] = 0x16;
        }
    }
}

extern "C" void fn_800C3490(void) {}

extern "C" void fn_800C40D8(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800C432C(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300D34;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800C4390(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288148;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
