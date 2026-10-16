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
    if (buf[0] == 0x5343524e && (buf[1] == 0x626c6f31 || buf[1] == 0x626c6f32)) {
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

extern "C" void fn_8016A0B4(void* p, void* obj);
extern "C" void fn_8017A56C(void* self, void* obj) {
    u8* p = (u8*)self;
    u8* q = (u8*)obj;
    ((void (*)(void*, void*))(*(void***)obj)[0xc / 4])(obj, self);
    for (u16 i = 0; i < *(u16*)(q + 0x18); i++) {
        u16 idx = ((u16*)*(u8**)(q + 0x1c))[i];
        if (idx < *(u16*)(p + 0x102)) {
            fn_8016A0B4(*(u8**)(p + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_80178990(void);
extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" void fn_8017A928(void) {
    fn_801788C0();
}

extern "C" u8 fn_80180B58(u8* self) {
    return self[0x110];
}

extern "C" void fn_80176550(u32* self);
extern "C" void fn_8018119C(u32* self, int a, int b, int c, int d, int e);
extern u32 lbl_80299040[];
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

extern "C" void fn_80184B34(unsigned char* self, unsigned int* dest) {
    unsigned int* src = (unsigned int*)(self + 0x148);
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
    dest[3] = src[3];
    dest[4] = *(unsigned int*)(self + 0x160);
}

extern "C" void fn_80184B60(void* self, f32 x, f32 y, f32 w, f32 h) {
    volatile f32 p[2];
    f32 rect[4];
    p[0] = x;
    p[1] = y;
    rect[0] = (f32)(double)x;
    rect[1] = (f32)(double)y;
    rect[2] = x + w;
    rect[3] = y + h;
    void (**vt)(void*, f32*) = *(void (***)(void*, f32*))self;
    vt[0x94 / 4](self, rect);
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

extern "C" void fn_80184C58(void* self, void* unused, void* param_3) {
    void* obj = *(void**)((u8*)self + 0x168);
    if (*(void**)((u8*)obj + 0x28) == 0) {
        if (((u8 (*)(void*, f32))(*(void***)self)[0x9c / 4])(self, lbl_80301BF8) && param_3 != 0) {
            void* sub = *(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
            if (((void* (*)(void*, s32))(*(void***)sub)[0xa4 / 4])(sub, 0) == 0) {
                sub = *(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
                ((void (*)(void*, s32, void*))(*(void***)sub)[0x98 / 4])(sub, 0, param_3);
            }
        }
    }
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

extern "C" void fn_8018A87C(void) {
    fn_80177E84();
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

extern void* lbl_80299764[];
extern void* lbl_80286A1C[];
extern void* lbl_80299634[];
extern void* lbl_80299540[];
extern "C" void fn_8018E9EC(u32* p) {
    p[0] = 0;
    p[1] = 0;
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
            if ((u32)ptr + 0x20 != 0) {
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
// Placeholder view of an unknown polymorphic class: virtual slots by vtable offset (0x08 + 4 * index).
class UnkVObj_80184B60 {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(f32* rect);
    virtual void v98(s32, void*);
    virtual u8 v9C(f32);
    virtual void* vA4(s32);
};
