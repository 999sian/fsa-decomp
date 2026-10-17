#include "types.h"
#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800175b8-0x80018c90 (23 functions). split_file divides it into the game's real files.

extern "C" s32 fn_8001D5B8(void*, void*);
extern "C" s32 fn_8001D5F4(void*, void*);
extern "C" void fn_8001AAFC(void*);
extern "C" void fn_8001836C(void*);
extern "C" void fn_80017F88(void*);
extern "C" void cTg_Addition__FP15node_list_classP16create_tag_class(void*, void*);
extern u8 lbl_80205388[];

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801A7C3C(void* p, void* data);
extern "C" char lbl_80202540[];
extern "C" int fn_800175B8(int param_1) {
    fn_801A7C3C((void*)(param_1 + 0x180), lbl_80202540);
    return param_1;
}

extern "C" void* fn_800175F4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_80017630(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_8001766C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" s32 fn_80017C9C(void* p) {
    s32 r = fn_8001D5B8(*(void**)((u8*)p + 0xec), p);
    if (r == 1) {
        fn_8001AAFC((u8*)p + 0xd8);
    }
    return r;
}

extern "C" s32 fn_80017CF0(void* p) {
    s32 r = fn_8001D5F4(*(void**)((u8*)p + 0xec), p);
    if (r == 1) {
        fn_80017F88((u8*)p + 0xc4);
        fn_8001AAFC((u8*)p + 0xd8);
        fn_8001836C(p);
    }
    return r;
}

extern u32 lbl_802FEBF4;
extern "C" s32 fn_8001892C(void);
extern "C" s32 fn_8001C2E4(void* a, void* b);
extern f32 lbl_802FF238;
extern f32 lbl_802FFBEC;
extern "C" s32 fn_80116840(f32* p, f32 a, f32 b);
extern "C" double fabs(double);

extern "C" void fn_80017F5C(void* tag) {
    cTg_Addition__FP15node_list_classP16create_tag_class(lbl_80205388, tag);
}

extern "C" void cTg_SingleCutFromTree__FP16create_tag_class(void*);
extern "C" void fn_80017F88(void* tag) {
    cTg_SingleCutFromTree__FP16create_tag_class(tag);
}

extern "C" void cTg_Create__FP16create_tag_classPv(void*, void*);
extern "C" s32 fn_80017FA8(void* tag, void* data) {
    cTg_Create__FP16create_tag_classPv(tag, data);
    return 1;
}

extern "C" void fn_8001C9FC(void);
extern "C" void fn_80017FCC(void) {
    fn_8001C9FC();
}

extern u8 lbl_802F0BC0[];
extern "C" void fn_800187B0(void* p) {
    u8* b = (u8*)p;
    s32 idx = (*(s16*)(b + 0x136) >> 2) & 0x3ff8;
    f32 a = *(f32*)(b + 0x230) * *(f32*)(lbl_802F0BC0 + idx);
    f32 v = *(f32*)(b + 0x154) + *(f32*)(b + 0x234);
    f32 c = *(f32*)(b + 0x230) * *(f32*)(lbl_802F0BC0 + idx + 4);
    f32 lim = *(f32*)(b + 0x238);
    if (v < lim) {
        v = lim;
    }
    *(f32*)(b + 0x150) = a;
    *(f32*)(b + 0x154) = v;
    *(f32*)(b + 0x158) = c;
}

extern s32 lbl_802FB9AC;
extern "C" void* fn_800200E4(s16 param_1, u8 param_2);
extern "C" void fn_80018804(u8* p, f32* q) {
    *(f32*)(p + 0x128) = *(f32*)(p + 0x128) + *(f32*)(p + 0x150);
    *(f32*)(p + 0x12c) = *(f32*)(p + 0x12c) + *(f32*)(p + 0x154);
    *(f32*)(p + 0x130) = *(f32*)(p + 0x130) + *(f32*)(p + 0x158);
    if (q == nullptr) {
        return;
    }
    *(f32*)(p + 0x128) = *(f32*)(p + 0x128) + q[0];
    *(f32*)(p + 0x12c) = *(f32*)(p + 0x12c) + q[1];
    *(f32*)(p + 0x130) = *(f32*)(p + 0x130) + q[2];
}

extern "C" void fn_80018870(u8* p, f32* q) {
    s32 idx = (*(s16*)(p + 0x136) >> 2) & 0x3ff8;
    f32 v = *(f32*)(p + 0x154) + *(f32*)(p + 0x234);
    u8* t = lbl_802F0BC0 + idx;
    f32 a = *(f32*)(p + 0x230) * *(f32*)t;
    f32 c = *(f32*)(p + 0x230) * *(f32*)(t + 4);
    if (v < *(f32*)(p + 0x238)) {
        v = *(f32*)(p + 0x238);
    }
    *(f32*)(p + 0x150) = a;
    *(f32*)(p + 0x154) = v;
    *(f32*)(p + 0x158) = c;
    fn_80018804(p, q);
}

extern "C" void* fn_80018C54(u8* p) {
    void* r = fn_800200E4(*(s16*)(p + 0xe), *(u8*)(p + 0x240));
    if (r != nullptr) {
        return r;
    }
    return &lbl_802FB9AC;
}

