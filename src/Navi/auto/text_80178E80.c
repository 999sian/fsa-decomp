#include "types.h"


extern "C" void fn_80177E84(void);
extern "C" u32 fn_8015FDA8(void* self, int flag);
extern "C" void fn_8018ECE4(void* a, void* b);
extern "C" void fn_8016A72C(void* p);
extern void* lbl_802FF6A0;
extern "C" void fn_8017A468(void) {
    fn_80177E84();
}

extern "C" void fn_8017A4A8(void* self) {
    if (fn_8015FDA8(self, 0) == 0) {
        void* p = lbl_802FF6A0;
        if (p != 0) {
            fn_8018ECE4(p, self);
        }
    }
}

extern "C" void fn_8017A4F8(void* self) {
    u8* p = (u8*)self;
    ((void (*)(void*, u32))(*(void***)p)[0x90 / 4])(self, *(u32*)(p + 0xf8));
    for (u16 i = 0; i < *(u16*)(p + 0x102); i++) {
        fn_8016A72C(*(u8**)(p + 0x104) + i * 0x88);
    }
}

extern "C" void fn_80178990(void);
extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" int fn_80184B08(unsigned char* self, unsigned char idx) {
    int* p;
    if (idx >= 4) {
        return 0;
    }
    p = (int*)(self + (idx << 2));
    return p[0x148 / 4];
}

extern "C" int fn_80184B2C(unsigned char* self) {
    return *(int*)(self + 0x160);
}

extern "C" void fn_801788C0(void);
extern "C" void fn_80184C34(void) {
    fn_801788C0();
}

extern "C" void fn_80178990(void);
extern "C" void fn_8018903C(void) {
    fn_80178990();
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

extern "C" void* fn_8018C2D8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C2F0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

