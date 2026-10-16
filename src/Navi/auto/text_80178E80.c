

#include "types.h"

extern "C" void fn_80177F0C(void);
extern "C" void fn_80177E84(void);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_8016A0B4(void* p, void* obj);
extern "C" void fn_801788C0(void);
extern "C" void fn_8015AB1C(void* p);
extern "C" u8 fn_8018A318(void* self, s32* param_2, s32* param_3);
extern u8 lbl_80301BF8[];
extern void* lbl_80286A30[];
extern void* lbl_80299634[];
extern void* lbl_80299540[];
extern "C" int fn_801792B4(void* param_1, int param_2) {
    u32 buf[8];
    fn_801670D0(param_2, buf, 0x20);
    if (buf[0] == 0x5343524e) {
        if (buf[1] == 0x626c6f31 || buf[1] == 0x626c6f32) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_8017A468(void) {
    fn_80177E84();
}

extern "C" void fn_8017A488(void) {
    fn_80177F0C();
}

extern "C" void* fn_8015FDA8(void*, void*);
extern "C" void fn_8018ECE4(void*, void*);
extern "C" void fn_8016A72C(void*);
extern void* lbl_802FF6A0;
extern "C" void fn_8017A4A8(void* param_1) {
    void* p;
    if (fn_8015FDA8(param_1, nullptr) == nullptr) {
        p = lbl_802FF6A0;
        if (p) {
            fn_8018ECE4(p, param_1);
        }
    }
}

extern "C" void fn_8017A4F8(void* self) {
    void (*vfn)(void*, void*) = (void (*)(void*, void*))((*(void***)self)[0x90 / 4]);
    u16 i;
    vfn(self, *(void**)((u8*)self + 0xf8));
    for (i = 0; i < *(u16*)((u8*)self + 0x102); i++) {
        fn_8016A72C(*(u8**)((u8*)self + 0x104) + i * 0x88);
    }
}

extern "C" void fn_8017A56C(void* self, void* obj) {
    void (*vfn)(void*, void*) = (void (*)(void*, void*))((*(void***)obj)[0xc / 4]);
    u16 count;
    u16 i;
    vfn(obj, self);
    count = *(u16*)((u8*)obj + 0x18);
    for (i = 0; i < count; i++) {
        u16 idx = ((u16*)*(u8**)((u8*)obj + 0x1c))[i];
        if (idx < *(u16*)((u8*)self + 0x102)) {
            fn_8016A0B4(*(u8**)((u8*)self + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_8017A928(void) {
    fn_801788C0();
}

extern "C" int fn_80180B60(u8* self, u8* src) {
    u8 a = src[0];
    u8 b = src[1];
    self[0x14c] = a;
    a = src[2];
    self[0x14d] = b;
    b = src[3];
    self[0x14e] = a;
    self[0x14f] = b;
    return 1;
}

extern "C" void fn_80176550(void* self);
extern "C" void fn_8018119C(void* self, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void* lbl_80299040[];
extern "C" void fn_80180B88(void) {
    fn_80177F0C();
}

extern "C" void fn_80180BA8(void) {
}

extern "C" void* fn_80180BAC(u32* self) {
    fn_80176550(self);
    *(void**)self = lbl_80299040;
    self[0x40] = 0;
    self[0x41] = -1;
    self[0x42] = -1;
    self[0x49] = 0;
    self[0x4a] = -1;
    self[0x4b] = -1;
    fn_8018119C(self, 0, 0, 0, 2, 2);
    return self;
}

extern "C" void fn_80184BF4(void) {
    fn_80177F0C();
}

extern "C" void fn_80184C34(void) {
    fn_801788C0();
}

extern "C" void fn_80184C54(void) {
}

extern "C" void fn_80184C58(void* self, void* unused, void* param_3) {
    void* obj = *(void**)((u8*)self + 0x168);
    if (*(void**)((u8*)obj + 0x28) == 0) {
        if (((s32 (*)(void*, void*))(*(void***)self)[0x9c / 4])(self, lbl_80301BF8) && param_3 != 0) {
            register void* sub = *(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
            if (((s32 (*)(void*, s32))(*(void***)sub)[0xa4 / 4])(sub, 0) == 0) {
                sub = *(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
                ((void (*)(void*, s32, void*))(*(void***)sub)[0x98 / 4])(sub, 0, param_3);
            }
        }
    }
}

extern "C" void fn_80188814(u8* param_1, u8 param_2) {
    *(u8*)(param_1 + 0xb2) = param_2;
    void* p = *(void**)(param_1 + 0x168);
    if (p == nullptr) return;
    if (((u8*)p + 0x10) == 0) return;
    *(u8*)((u8*)p + 0x3) = param_2;
}

extern "C" void fn_8018901C(void) {
    fn_80177F0C();
}

extern "C" int fn_8018A064(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_8018A318(self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_c;
    long local_18;
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

extern "C" void* fn_8018C1E8(void* base, u32 offset) {
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

extern "C" void* fn_8018C308(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

