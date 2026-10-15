#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80178e80-0x80192e18 (416 functions). split_file divides it into the game's real files.

extern void* lbl_80299504[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80174BA0(void* base, u32 offset);
extern "C" void* fn_8018C2C0(void* base, u32 offset);
extern "C" void* fn_8018C230(void* base, u32 offset);
extern "C" void fn_801193D8(void* dest, void* src);
extern "C" void fn_8018B384(void* unused, void* dest, void* src);
extern void* lbl_802994F0[];
extern "C" void fn_8018B07C(void* ptr) {
    register void* a asm("r5") = (void*)lbl_80299504;
    register void* b asm("r4") = (void*)lbl_802994F0;
    *(void**)ptr = a;
    *(void**)ptr = b;
}

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

extern "C" void fn_8018B35C(void* self, void* src) {
    fn_8018B384(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_8018C308(void* base, u32 offset);
extern "C" void* fn_8018C2F0(void* base, u32 offset);
extern "C" void* fn_8018C2D8(void* base, u32 offset);
extern "C" void* fn_8018C260(void* base, u32 offset);
extern const f32 lbl_80301C30;
extern "C" void fn_8018B384(void* /*unused*/, void* dest, void* src) {
    u8* d = (u8*)dest;
    u8* s = (u8*)src;

    s16 t0 = *(s16*)(s + 0x0a);
    *(u16*)(d + 0x22) = *(u16*)(s + 0x0c);
    u8 t1 = *(u8*)(s + 0x08);
    *(s16*)(d + 0x06) = t0;
    u8 t2 = *(u8*)(s + 0x09);
    *(u8*)(d + 0x04) = t1;
    u32 t3 = *(u32*)(s + 0x14);
    *(u32*)(d + 0x24) = t2;
    *(f32*)(d + 0x08) = 0.0f;
    *(void**)(d + 0x28) = (void*)fn_8018C308(src, t3);
    *(void**)(d + 0x10) = (void*)fn_8018C2F0(src, *(u32*)(s + 0x18));
    *(void**)(d + 0x14) = (void*)fn_8018C2D8(src, *(u32*)(s + 0x1c));
    *(void**)(d + 0x18) = (void*)fn_8018C2F0(src, *(u32*)(s + 0x20));
}

extern "C" void fn_8018B448(void* unused, void* dest, void* src);
extern "C" void fn_8018B420(void* self, void* src) {
    fn_8018B448(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B65C(void* unused, void* dest, void* src);
extern "C" void fn_8018B634(void* self, void* src) {
    fn_8018B65C(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B770(void* unused, void* dest, void* src);
extern "C" void fn_8018B748(void* self, void* src) {
    fn_8018B770(self, *(void**)((u8*)self + 4), src);
}

extern void* lbl_802994BC[];
extern "C" void* fn_8018BAF0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802994BC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299504;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8018BB74(void* /*unused*/, void* dest, void* src) {
    u8* d = (u8*)dest;
    u8* s = (u8*)src;

    *(u16*)(d + 0x22) = *(u16*)(s + 0x0c);
    *(s16*)(d + 0x06) = *(s16*)(s + 0x0a);
    u8 t4 = *(u8*)(s + 0x08);
    u32 t14 = *(u32*)(s + 0x14);
    *(u8*)(d + 0x04) = t4;
    *(f32*)(d + 0x08) = lbl_80301C30;
    *(void**)(d + 0x24) = (void*)fn_8018C260(src, t14);
    *(void**)(d + 0x10) = (void*)fn_8018C2F0(src, *(u32*)(s + 0x18));
    *(void**)(d + 0x14) = (void*)fn_8018C2D8(src, *(u32*)(s + 0x1c));
    *(void**)(d + 0x18) = (void*)fn_8018C2F0(src, *(u32*)(s + 0x20));
}

extern "C" void fn_8018BC30(void* unused, void* dest, void* src);
extern "C" void fn_8018BC08(void* self, void* src) {
    fn_8018BC30(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018BD24(void* /*unused*/, void* dest, void* src) {
    u8* d = (u8*)dest;
    u8* s = (u8*)src;

    u8 t1 = *(u8*)(s + 0x08);
    *(s16*)(d + 0x06) = *(s16*)(s + 0x0a);
    u16 t2 = *(u16*)(s + 0x0c);
    *(u8*)(d + 0x04) = t1;
    u16 t3 = *(u16*)(s + 0x0e);
    *(f32*)(d + 0x08) = lbl_80301C30;
    *(u16*)(d + 0x1a) = t2;
    u32 t4 = *(u32*)(s + 0x10);
    *(u16*)(d + 0x18) = t3;
    *(void**)(d + 0x14) = fn_8018C230(src, t4);
    *(void**)(d + 0x10) = fn_80174BA0(src, *(u32*)(s + 0x14));
    *(void**)(d + 0x1c) = fn_80174BA0(src, *(u32*)(s + 0x18));
    fn_801193D8(d + 0x20, fn_8018C2C0(src, *(u32*)(s + 0x1c)));
}

extern "C" void fn_8018BDF0(void* unused, void* dest, void* src);
extern "C" void fn_8018BDC8(void* self, void* src) {
    fn_8018BDF0(self, *(void**)((u8*)self + 4), src);
}

extern void* lbl_80299540[];
extern void* lbl_80286A30[];
extern "C" void* fn_8018C144(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299540;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

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

extern "C" void* fn_8018C230(void* base, u32 offset) {
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

extern "C" void* fn_8018C308(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* lbl_80299634[];
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

extern "C" void* lbl_80299670[];
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

extern "C" void* lbl_80299764[];
extern "C" void* lbl_80286A1C[];
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

extern "C" void* lbl_802997A4[];
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

