

#include "types.h"

class UnkVObj_80184B60 {
public:
    virtual void vfn0(void* self);
    virtual void vfn1(void* self);
};

extern "C" void fn_8016A39C(void* item, UnkVObj_80184B60* obj);
extern "C" u8 fn_8018A318(void* self, s32* param_2, s32* param_3);

extern "C" void fn_8017A6CC(void* self, UnkVObj_80184B60* obj) {
    u16 count;
    u16 i;
    obj->vfn1(self);
    count = *(u16*)((u8*)obj + 0x1a);
    for (i = 0; i < count; i++) {
        u16 idx = ((u16*)*(u8**)((u8*)obj + 0x1c))[i];
        if (idx < *(u16*)((u8*)self + 0x102)) {
            fn_8016A39C(*(u8**)((u8*)self + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_80178990(void);
extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" void fn_80178990(void);
extern "C" void fn_8018903C(void) {
    fn_80178990();
}

extern "C" int fn_8018A064(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_8018A318(self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c;
    s32 local_18;
    local_18 = *param_2;
    local_c = local_14;
    int (*fn)(void*, s32*, s32*) = (int (*)(void*, s32*, s32*))(*(void***)self)[0xac / 4];
    return fn(self, &local_c, &local_18);
}

extern void* lbl_80299504[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8018C1A0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299504;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

