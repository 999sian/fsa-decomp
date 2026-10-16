#include "types.h"
extern "C" void fn_801788C0(void);



extern "C" void fn_80177E84(void);
extern "C" u32 fn_8015FDA8(void* self, int flag);
extern "C" void fn_8018ECE4(void* a, void* b);
extern "C" void fn_8016A72C(void* p);
extern void* lbl_802FF6A0;
extern "C" void fn_801670D0(int, void*, int);
extern "C" int fn_801792B4(void* param_1, int param_2) {
    u32 buf[8];
    fn_801670D0(param_2, buf, 0x20);
    if (buf[0] != 0x5343524e) {
        return 0;
    }
    if (buf[1] == 0x626c6f31) {
        return 1;
    }
    if (buf[1] == 0x626c6f32) {
        return 1;
    }
    return 0;
}

extern "C" void fn_8017A468(void) {
    fn_80177E84();
}

extern "C" void fn_8017A4A8(void* self) {
    if (fn_8015FDA8(self, 0) == 0) {
        if ((u32)lbl_802FF6A0 != 0) {
            fn_8018ECE4((void*)lbl_802FF6A0, self);
        }
    }
}

extern "C" void fn_8017A4F8(void* self) {
    u8* p = (u8*)self;
    void** vtbl = *(void***)self;
    ((void (*)(void*, u32))vtbl[0x90 / 4])(self, *(u32*)(p + 0xf8));
    for (u16 i = 0; i < *(u16*)(p + 0x102); i++) {
        fn_8016A72C(*(u8**)(p + 0x104) + i * 0x88);
    }
}

extern "C" void fn_80178990(void);
extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" void fn_8017A928(void) {
    fn_801788C0();
}

extern "C" int fn_80184B08(unsigned char* self, unsigned char idx) {
    unsigned char* p;
    if (idx >= 4) {
        return 0;
    }
    p = self + (idx << 2);
    return *(int*)(p + 0x148);
}

extern "C" int fn_80184B2C(unsigned char* self) {
    return *(int*)(self + 0x160);
}

extern "C" void fn_80177F0C(void);
extern "C" void fn_80184BF4(void) {
    fn_80177F0C();
}

extern "C" f32 lbl_80301BF8;
extern "C" void fn_80184C14(void) {
    fn_80178990();
}

extern "C" void fn_801788C0(void);
extern "C" void fn_80184C34(void) {
    fn_801788C0();
}

extern "C" void fn_80184C54(void) {
}

extern "C" void fn_8018901C(void) {
    fn_80177F0C();
}

extern "C" void fn_80178990(void);
extern "C" void fn_8018903C(void) {
    fn_80178990();
}

extern "C" void fn_8018905C(void) {
    fn_801788C0();
}

extern "C" u8 fn_8018A318(void* self, s32* a, s32* b);
extern "C" int fn_8018A064(void* self, s32* param_2) {
    s32 local_14 = -1;
    s32 local_10 = -1;
    if (fn_8018A318(self, &local_14, &local_10) == 0) {
        return 0;
    }
    s32 local_18 = *param_2;
    s32 local_c = local_14;
    void** vtbl = *(void***)self;
    return ((int (*)(void*, s32*, s32*))vtbl[0xac / 4])(self, &local_c, &local_18);
}

extern "C" void fn_8018A8C0(void) {
    fn_801788C0();
}

extern "C" void fn_8018BFA4(void* unused, void* dest, void* src);
extern "C" void fn_8018BDF0(void* unused, void* dest, void* src);
extern "C" void fn_8018BD24(void* unused, void* dest, void* src);
extern "C" void fn_8018BCFC(void* self, void* src) {
    fn_8018BD24(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018BDC8(void* self, void* src) {
    fn_8018BDF0(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018BF7C(void* self, void* src) {
    fn_8018BFA4(self, *(void**)((u8*)self + 4), src);
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

extern "C" void* fn_8018C218(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8018C248(void* base, u32 offset) {
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

extern void* lbl_802996C0[];
extern void* lbl_8029970C[];
extern void* lbl_80286A4C[];
extern void* lbl_80286A30[];
extern "C" void* fn_8018EAD4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802996C0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029970C;
            if ((char*)ptr + 0x20 != nullptr) {
                ((void**)ptr)[8] = lbl_80286A4C;
            }
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

