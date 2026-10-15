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
extern "C" void fn_8016A0B4(void*);
extern "C" void fn_8018DEF0(void*, u16, u8*);
extern "C" void fn_80178BFC(void*, void*);
extern "C" void fn_801780D4(void);
extern "C" int fn_80177E84(void*, int);
extern "C" void fn_80177F0C(void);
extern "C" void fn_8017A488(void) {
    fn_80177F0C();
}

extern "C" void fn_80178B74(void);
extern "C" void fn_8017A85C(void) {
    fn_80178B74();
}

extern "C" int fn_8017A8CC(void) {
    return 8;
}

extern "C" void fn_801788C0(void);
extern "C" void fn_8017A928(void) {
    fn_801788C0();
}

extern "C" void fn_80188814(u8* param_1, u8 param_2) {
    *(u8*)(param_1 + 0xb2) = param_2;
    u8* p = (u8*)*(void**)(param_1 + 0x168);
    if ((u32)p == 0) return;
    if ((u32)p + 0x10 == 0) return;
    *(u8*)(p + 0x3) = param_2;
}

extern "C" void fn_80188834(u8* param_1, u8 param_2) {
    *(u8*)(param_1 + 0xb1) = param_2;
    u8* q = (u8*)*(void**)(param_1 + 0x168);
    if (q != nullptr) {
        *(u8*)(q + 0x22) = param_2;
    }
    fn_801780D4();
}

extern "C" void fn_80188868(u8* param_1) {
    void* p = *(void**)(param_1 + 0x168);
    if (p != nullptr) {
        u8 val = *(u8*)((u8*)p + 0x13);
        *(u8*)((u8*)param_1 + 0xb2) = val;
    }
}

extern "C" int fn_80188880(u8* param_1, int param_2) {
    void* base = *(void**)(param_1 + 0x168);
    if (base != nullptr) {
        void* table = *(void**)((u8*)base + 0x70);
        if (table != nullptr) {
            for (int i = 0; i < 8; i++) {
                void** vtable = *(void***)table;
                void* method_addr = *(void**)((u8*)vtable + 0xa0);
                void* result = ((void* (*)(void*, int))method_addr)(table, i);
                if (result != nullptr && *(int*)((u8*)result + 0x20) == param_2) {
                    return 1;
                }
            }
        }
    }
    return fn_80177E84(param_1, param_2);
}

extern "C" void fn_80188928(u8* param_1) {
    void* p = *(void**)(param_1 + 0x168);
    if (p != nullptr) {
        fn_8016A0B4(p);
    }
}

extern "C" void fn_801889D8(u8* param_1, void* param_2) {
    *(void**)((u8*)param_1 + 0x19c) = param_2;
}

extern "C" void fn_8018A700(u8* self) {
    void* p = *(void**)(self + 0x138);
    if (p != NULL) {
        fn_8016A0B4(p);
    }
}

extern "C" void fn_8016A1F8(void*);
extern "C" void fn_8018A72C(u8* self) {
    void* p = *(void**)(self + 0x138);
    if (p != NULL) {
        fn_8016A1F8(p);
    }
}

extern "C" void fn_8016A39C(void*);
extern "C" void fn_8018A758(u8* self) {
    void* p = *(void**)(self + 0x138);
    if (p != NULL) {
        fn_8016A39C(p);
    }
}

extern "C" void fn_8016A530(void*);
extern "C" void fn_8018A784(u8* self) {
    void* p = *(void**)(self + 0x138);
    if (p != NULL) {
        fn_8016A530(p);
    }
}

extern "C" void fn_8018A7B0(u8* self, void* p) {
    *(void**)(self + 0x144) = p;
}

extern "C" void fn_8018A7B8(u8* self, void* arg) {
    u8 buf[8];
    void* p = *(void**)(self + 0x144);
    if (p != NULL && *(u16*)(self + 0x13c) != 0xffff) {
        fn_8018DEF0(p, *(u16*)(self + 0x13c), buf);
        if (buf[0] != 0) {
            self[0xb0] = 1;
        } else {
            self[0xb0] = 0;
        }
    }
    fn_80178BFC(self, arg);
}

extern "C" void fn_8018B07C(void* ptr) {
    void* a = lbl_80299504;
    void* b = lbl_802994F0;
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

extern "C" void fn_8018BFA4(void* unused, void* dest, void* src);
extern "C" void fn_8018BF7C(void* self, void* src) {
    fn_8018BFA4(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018C048(void* unused, void* dest, void* src);
extern "C" void fn_8018C020(void* self, void* src) {
    fn_8018C048(self, *(void**)((u8*)self + 4), src);
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

extern "C" void fn_8018E9EC(u32* p) {
    p[0] = 0;
    p[1] = 0;
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

