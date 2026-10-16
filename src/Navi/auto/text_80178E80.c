

#include "types.h"
extern "C" void fn_80177F0C(void);


class UnkVObj_80184B60 {
public:
    virtual void vfn0(void* self);
    virtual void vfn1(void* self);
};

extern "C" void fn_8016A39C(void* item, UnkVObj_80184B60* obj);
extern "C" u8 fn_8018A318(void* self, s32* param_2, s32* param_3);
extern "C" void fn_80118BD0(void* p, s32 flag);
extern "C" void fn_8015AB1C(void* p);
extern "C" void fn_80176FE8(void* self, s32 flag);
extern char lbl_80298DF0[];

extern "C" void fn_8017A488(void) {
    fn_80177F0C();
}

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

extern "C" void* fn_8017B7E4(void* self, s16 param_2) {
    if (self != 0) {
        *(void**)self = lbl_80298DF0;
        fn_80118BD0(*(void**)((u8*)self + 0x100), 1);
        fn_80118BD0(*(void**)((u8*)self + 0x104), 1);
        fn_80118BD0(*(void**)((u8*)self + 0x108), 1);
        fn_80118BD0(*(void**)((u8*)self + 0x10c), 1);
        fn_8015AB1C(*(void**)((u8*)self + 0x124));
        fn_80118BD0(*(void**)((u8*)self + 0x110), 1);
        fn_80176FE8(self, 0);
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern "C" void fn_80177F0C(void);
extern "C" void fn_80176550(void* self);
extern "C" void fn_8018119C(void* self, s32 a, s32 b, s32 c, s32 d, s32 e);
extern char lbl_80299040[];
extern "C" void fn_80180B88(void) {
    fn_80177F0C();
}

extern "C" void fn_80180BA8(void) {
}

extern "C" u32* fn_80180BAC(u32* self) {
    fn_80176550(self);
    self[0] = (u32)lbl_80299040;
    self[0x40] = 0;
    self[0x41] = 0xFFFFFFFF;
    self[0x42] = 0xFFFFFFFF;
    self[0x49] = 0;
    self[0x4A] = 0xFFFFFFFF;
    self[0x4B] = 0xFFFFFFFF;
    fn_8018119C(self, 0, 0, 0, 2, 2);
    return self;
}

extern "C" void fn_80184BF4(void) {
    fn_80177F0C();
}

extern "C" void fn_8018901C(void) {
    fn_80177F0C();
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

extern "C" void* fn_8018C1E8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C200(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C260(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C278(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C290(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2A8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2C0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2D8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2F0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern void* lbl_80286A30[];
extern void* lbl_80299634[];
extern void* lbl_80299540[];
extern "C" void* fn_8018E9FC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299634;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299540;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299670[];
extern "C" void* fn_8018EA68(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299670;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299540;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299764[];
extern void* lbl_80286A1C[];
extern "C" void* fn_8018EBDC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299764;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A1C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802997A4[];
extern "C" void* fn_8018EC78(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802997A4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A1C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80286A30;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

