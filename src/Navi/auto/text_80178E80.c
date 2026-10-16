

#include "types.h"

extern "C" void fn_8017A56C(void* self, void* obj) {
    u16 count;
    u16 i;
    ((void (*)(void*, void*))(*(void***)obj)[0xc / 4])(obj, self);
    count = *(u16*)((u8*)obj + 0x18);
    for (i = 0; (u32)i < count; i++) {
        u16 idx = ((u16*)*(u8**)((u8*)obj + 0x1c))[i];
        if (idx < *(u16*)((u8*)self + 0x102)) {
            fn_8016A0B4(*(u8**)((u8*)self + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_80184C58(UnkVObj_80184B60* self, void* unused, void* param_3) {
    void* obj = *(void**)((u8*)self + 0x168);
    if (*(void**)((u8*)obj + 0x28) == 0) {
        if (((s32 (*)(void*, void*))(*(void***)self)[0x9c / 4])(self, lbl_80301BF8) && param_3 != 0) {
            register UnkVObj_80184B60* sub = *(UnkVObj_80184B60**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
            if (sub->vA4(0) == 0) {
                sub = *(UnkVObj_80184B60**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
                sub->v98(0, param_3);
            }
        }
    }
}

extern "C" int fn_8018A064(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_8018A318(self, &local_14, &(uLong)local_10) == 0) {
        return 0;
    }
    s32 local_c;
    s32 local_18;
    local_18 = *param_2;
    local_c = local_14;
    void** vtbl = *(void***)self;
    return ((int (*)(void*, s32*, s32*))vtbl[0xac / 4])(self, &local_c, &local_18);
}

extern "C" void fn_80177E84(void);
extern "C" void fn_80178990(void);
extern "C" void fn_801788C0(void);
extern "C" void fn_8015AB1C(void* p);
extern u8 lbl_802994F0[];
extern u8 lbl_80299504[];
extern "C" void* fn_8018B098(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802994F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299504;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

