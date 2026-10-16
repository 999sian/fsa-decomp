#include "types.h"
extern "C" void fn_801788C0(void);

extern void* lbl_80299540[];
extern void* lbl_80286A30[];

extern void* lbl_80299504[];
extern "C" void fn_8015AB1C(void* ptr);

extern void* lbl_80299504[];
extern "C" void fn_8015AB1C(void* ptr);



extern "C" void fn_80178990(void);
extern "C" void fn_80177F0C(void);
extern "C" int fn_8017A8CC(void) {
    return 8;
}

extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" void fn_8017A928(void) {
    fn_801788C0();
}

extern "C" int fn_8017D1EC()
{
	return 0;
}

extern "C" BOOL fn_80180B60(u8* self, u8* src) {
    u8 b = src[1];
    u8 a = src[0];
    self[0x14C] = a;
    self[0x14D] = b;
    a = src[2];
    b = src[3];
    self[0x14E] = a;
    self[0x14F] = b;
    return 1;
}

extern "C" void fn_80180B88(void) {
    fn_80177F0C();
}

extern "C" void fn_80176550(void* self);
extern "C" void fn_8018119C(void* self, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u32 lbl_80299040[];
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

extern "C" int fn_801820CC(int param_1)
{
    return *(int*)(param_1 + 0x100);
}

extern "C" int fn_80184B08(u8* self, u8 idx) {
    if (idx < 4) {
        return *(int*)(self + idx * 4 + 0x148);
    }
    return 0;
}

extern "C" int fn_80184B2C(u8* self) {
    return *(int*)(self + 0x160);
}

extern "C" void fn_80184B34(u8* self, u32* dest) {
    struct Quad {
        u32 v[4];
    };
    *(Quad*)dest = *(Quad*)(self + 0x148);
    dest[4] = *(u32*)(self + 0x160);
}

extern "C" void fn_80184B60(void* self, f64 x, f64 y, f64 w, f64 h) {
    f32 rect[4];
    rect[0] = x;
    rect[1] = y;
    rect[2] = x + w;
    rect[3] = y + h;
    ((void (*)(void*, f32*))(*(void***)self)[0x94 / 4])(self, rect);
}

extern "C" void fn_80177F0C(void);
extern "C" void fn_80184BF4(void) {
    fn_80177F0C();
}

extern "C" void fn_801788C0(void);
extern "C" void fn_80184C34(void) {
    fn_801788C0();
}

extern "C" void fn_80184C54(void) {
}

extern f32 lbl_80301BF8;
extern "C" void fn_80184C58(void* self, void* unused, s32 param_3) {
    if (*(s32*)((u8*)*(void**)((u8*)self + 0x168) + 0x28) == 0) {
        u8 ok = ((u8 (*)(void*, f32))(*(void***)self)[0x9c / 4])(self, lbl_80301BF8);
        if (ok != 0 && param_3 != 0) {
            if (((s32 (*)(void*, s32))(*(void***)*(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70))[0xa4 / 4])(*(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70), 0) == 0) {
                ((void (*)(void*, s32, s32))(*(void***)*(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70))[0x98 / 4])(*(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70), 0, param_3);
            }
        }
    }
}

extern "C" void fn_8018901C(void) {
    fn_80177F0C();
}

extern "C" void fn_8018905C(void) {
    fn_801788C0();
}

extern "C" void fn_8018A8C0(void) {
    fn_801788C0();
}

extern void* lbl_802994F0[];
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

extern "C" void fn_8018B384(void* unused, void* dest, void* src);
extern "C" void fn_8018B35C(void* self, void* src) {
    fn_8018B384(self, *(void**)((u8*)self + 4), src);
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

extern "C" void fn_8018BB74(void* unused, void* dest, void* src);
extern "C" void fn_8018BB4C(void* self, void* src) {
    fn_8018BB74(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018BC30(void* unused, void* dest, void* src);
extern "C" void fn_8018BC08(void* self, void* src) {
    fn_8018BC30(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018BD24(void* unused, void* dest, void* src);
extern "C" void fn_8018BCFC(void* self, void* src) {
    fn_8018BD24(self, *(void**)((u8*)self + 4), src);
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

