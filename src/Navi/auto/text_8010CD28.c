#include "types.h"
struct VObj_800A1A64 {
    virtual void v0(s32 b);
 virtual void v1();
    virtual void v2(s32 b);
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8010cd28-0x8010d18c (7 functions). split_file divides it into the game's real files.

extern void* lbl_8028EB80[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_803012D8;
extern s32 lbl_802FEC60;
extern s32 lbl_802FDBD0;
extern s32 lbl_802FDBD4;
extern s32 lbl_802FDBDC;
extern char lbl_8028EB08[];
extern char lbl_8028EB18[];
extern char lbl_802C5B2C[];
extern char lbl_8029FDB4[];
extern "C" void fn_800127A0(void* p);
extern "C" void* fn_8015A90C(u32 size);
extern "C" void* fn_80178E80(void* self);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void* a, void* b, s32 c, void* d, void* e, ...);
extern "C" void fn_80007AB8(void* a, s32 b, void* c, ...);
extern "C" void fn_80179030(void* a, void* b, s32 c, void* d);
extern "C" void fn_8010CDD8(u8* p);
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_8010CD28(u8* p) {
    *(s32*)(p + 0xc) = lbl_802FEC60;
    void* obj = fn_8015A90C(0x118);
    if (obj != nullptr) {
        obj = fn_80178E80(obj);
    }
    *(void**)(p + 8) = obj;
    if (*(void**)(p + 8) == nullptr) {
        void* v = fn_8011FD10();
        fn_8011FD18(v, lbl_8028EB08, 0x67, &lbl_802FDBD0, lbl_8028EB18);
        fn_80007AB8(lbl_8028EB08, 0x67, &lbl_802FDBD4);
    }
    fn_80179030(*(void**)(p + 8), &lbl_802FDBDC, 0x100000, *(void**)(p + 0xc));
    fn_8010CDD8(p);
}

extern "C" void fn_8017A4F8(void*);
extern "C" void fn_8010CF1C(u8* p) {
    (*(s32*)(p + 0x20))++;
    if (*(s32*)(p + 0x20) >= (s32)*(s16*)(*(u8**)(p + 0x18) + 6)) {
        *(s32*)(p + 0x20) = *(s32*)(p + 0x20) - *(s16*)(*(u8**)(p + 0x18) + 6);
    }
    *(f32*)(*(u8**)(p + 0x18) + 8) = *(s32*)(p + 0x20);
    (*(s32*)(p + 0x24))++;
    if (*(s32*)(p + 0x24) >= (s32)*(s16*)(*(u8**)(p + 0x1c) + 6)) {
        *(s32*)(p + 0x24) = *(s32*)(p + 0x24) - *(s16*)(*(u8**)(p + 0x1c) + 6);
    }
    *(f32*)(*(u8**)(p + 0x1c) + 8) = *(s32*)(p + 0x24);
    fn_8017A4F8(*(void**)(p + 8));
}

extern "C" void fn_8010CFE0(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 4);
}

extern "C" void fn_8010D01C(u8* p) {
    VObj_800A1A64* obj;
    s32 n;
    obj = *(VObj_800A1A64**)(p + 0x18);
    if (obj != nullptr) {
        obj->v0(1);
    }
    obj = *(VObj_800A1A64**)(p + 0x1c);
    if (obj != nullptr) {
        obj->v0(1);
    }
    obj = *(VObj_800A1A64**)(p + 0x8);
    if (obj != nullptr) {
        obj->v0(1);
    }
    if ((s8)lbl_802C5B2C[4] >= 0) {
        n = *(s32*)(lbl_802C5B2C + 8) - 1;
        *(s32*)(lbl_802C5B2C + 8) = n;
        if (n == 0) {
            fn_800127A0(lbl_8029FDB4 + 4);
            lbl_802C5B2C[4] = -1;
        }
    }
}

extern "C" void fn_8010D0E0(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_803012D8;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_8010D144(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028EB80;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
