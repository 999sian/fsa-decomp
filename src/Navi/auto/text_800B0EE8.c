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
// .text 0x800b0ee8-0x800bace4 (71 functions). split_file divides it into the game's real files.

extern void* lbl_8028794C[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80287910[];
extern void* lbl_80286A30[];
extern unsigned char lbl_802313EC[];
extern "C" unsigned char fn_800B51E8(void* self, int i) {
    return lbl_802313EC[i];
}

extern "C" void fn_800B96D8(char* p) {
    if (*(u8*)(*(char**)(p + 0x1b0) + 0xb0) != 0 || *(u8*)(*(char**)(p + 0x1b4) + 0xb0) != 0) {
        *(s32*)(p + 0x1bc) += 1;
        s32 n = *(s16*)(*(char**)(p + 0x1b8) + 6);
        s32 c = *(s32*)(p + 0x1bc);
        if (c >= n) {
            *(s32*)(p + 0x1bc) = c - n;
        }
        *(f32*)(*(char**)(p + 0x1b8) + 8) = *(s32*)(p + 0x1bc);
    }
}

extern "C" void fn_800B9754(char* self) {
    if (*(unsigned char*)(*(char**)(self + 0x19c) + 0xb0) != 0) {
        *(int*)(self + 0x1ac) += 1;
        short n = *(short*)(*(char**)(self + 0x1a8) + 6);
        int v = *(int*)(self + 0x1ac);
        if (v >= n) {
            *(int*)(self + 0x1ac) = v - n;
        }
        *(float*)(*(char**)(self + 0x1a8) + 8) = (float)*(int*)(self + 0x1ac);
    }
}

extern u32 lbl_802BB0FC[];
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800B97C0(u8* p) {
    (*(u8**)(p + 0x1c0))[0xb0] = 0;
    (*(u8**)(p + 0x64))[0xb0] = 0;
    (*(u8**)(p + 0x78))[0xb0] = 0;
    (*(u8**)(p + 0x188))[0xb0] = 0;
    (*(u8**)(p + 0x68))[0xb0] = 0;
    (*(u8**)(p + 0x7c))[0xb0] = 0;
    (*(u8**)(p + 0x18c))[0xb0] = 0;
}

extern "C" void* fn_800B9970(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287910;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern char lbl_802B7CA0[];
extern f32 lbl_80300C88;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_800BAC38(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300C88;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800BAC9C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028794C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
