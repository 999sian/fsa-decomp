

#include "types.h"

extern "C" void fn_80176550(void* self);
extern "C" void fn_8016A39C(void* p, void* obj);
extern "C" void fn_80178B74(void);
extern "C" void fn_8017B07C(u32* self, int a, int b, int c);
extern void* lbl_80298DF0[];

extern "C" void fn_80177F0C(void);
extern "C" void fn_801813CC(u32*, int, int, int);

struct UnkVObj_80181CCC {
    virtual void vf8(int);
    virtual u16 vfC();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void* vf3C();
};
extern "C" void fn_80177E84(void);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_8016A0B4(void* p, void* obj);
extern "C" void fn_8016A1F8(void* p, void* obj);
extern "C" void fn_801788C0(void);
extern "C" void fn_80178990(void);
extern "C" void fn_8015AB1C(void* p);
extern "C" u8 fn_8018A318(void* self, s32* param_2, s32* param_3);
extern u8 lbl_80301BF8[];

struct DtorVObj_80178F90 {
    virtual void Destroy(int);
};

struct Quad_8017C0A8 {
    u8 v[4];
};

struct VObj_8017C154 {
    virtual void vf8();
    virtual void vfC();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38(void* buf, f32 x, f32 y);
};
extern void* lbl_80286A30[];
extern void* lbl_80299634[];
extern void* lbl_80299540[];
extern void* lbl_80298D38[];
extern "C" void fn_80178F90(void*);
extern "C" void fn_80176FE8(void*, int);
extern "C" void fn_80176698(void* self, s32 a, s32 b, s32 c, s32 d, u32 e, void* f);
extern "C" void* fn_80178E80(void* self) {
    f32 rect[6];
    s32 unused;
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 0.0f;
    rect[3] = 0.0f;
    rect[4] = 640.0f;
    rect[5] = 480.0f;
    fn_80176698(self, 0, 1, unused, 0, 0x726f6f74, &rect[2]);
    *(void**)self = lbl_80298D38;
    *(s32*)((u8*)self + 0x114) = -1;
    *(u16*)((u8*)self + 0x4) = 0xffff;
    *(u8*)((u8*)self + 0x100) = 0;
    *(u16*)((u8*)self + 0x102) = 0;
    *(s32*)((u8*)self + 0x104) = 0;
    *(s32*)((u8*)self + 0x108) = 0;
    *(s32*)((u8*)self + 0x10c) = 0;
    *(s32*)((u8*)self + 0x110) = 0;
    return self;
}

extern "C" void* fn_80178F28(void* p, s16 param_2) {
    if (p != nullptr) {
        *(void**)p = lbl_80298D38;
        fn_80178F90(p);
        fn_80176FE8(p, 0);
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_801E0CC4(void* a, void* b);
extern "C" void fn_80169B1C(void);
extern "C" void fn_8015AB40(void* p);
extern "C" void fn_80178F90(void* self) {
    char* p = (char*)self;
    fn_801E0CC4(*(void**)(p + 0x104), (void*)fn_80169B1C);
    *(u16*)(p + 0x102) = 0;
    *(void**)(p + 0x104) = 0;
    fn_8015AB40(*(void**)(p + 0x108));
    *(void**)(p + 0x108) = 0;
    fn_8015AB40(*(void**)(p + 0x10c));
    *(void**)(p + 0x10c) = 0;
    if (*(void**)(p + 0x110) != 0) {
        fn_8015AB40(*(void**)(*(char**)(p + 0x110) + 4));
        DtorVObj_80178F90* o = *(DtorVObj_80178F90**)(p + 0x110);
        if (o != 0) {
            o->Destroy(1);
        }
        *(void**)(p + 0x110) = 0;
    }
}

extern "C" int fn_80179174(int, int, int, void*);
extern "C" int fn_80179144(int a, int b, int c, void* d) {
    if (d == 0) {
        return 0;
    }
    return fn_80179174(a, b, c, d);
}

extern "C" int fn_801792B4(void* param_1, int param_2) {
    u32 buf[8];
    fn_801670D0(param_2, buf, 0x20);
    if (buf[0] == 0x5343524e && (buf[1] == 0x626c6f31 || buf[1] == 0x626c6f32)) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80118BD0(void* p, s32 x);
extern "C" int fn_80177D24(void);
extern "C" int fn_80179E80(s64 param_1, s64 param_2) {
    int result = 0;
    if (param_2 != result) {
        result = fn_80177D24();
    }
    return result;
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
    if (fn_8015FDA8(param_1, nullptr) == nullptr) {
        void* p = lbl_802FF6A0;
        if (p != nullptr) {
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

extern "C" void fn_8017A610(void* param_1, void* param_2) {
    u16 count;
    u16 i;
    u16 idx;
    void* obj = param_2;
    void* fn = ((void**)*(void**)obj)[3];
    ((void (*)(void*, void*))fn)(obj, param_1);
    count = *(u16*)((u8*)obj + 0x14) / 3;
    for (i = 0; i < count; i++) {
        idx = ((u16*)*(u32*)((u8*)obj + 0x34))[i];
        if (idx < *(u16*)((u8*)param_1 + 0x102)) {
            fn_8016A1F8((u8*)*(u32*)((u8*)param_1 + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_8017A6CC(void* self, void* obj) {
    void (*vfn)(void*, void*) = (void (*)(void*, void*))((*(void***)obj)[0xc / 4]);
    u16 count;
    u16 i;
    vfn(obj, self);
    count = *(u16*)((u8*)obj + 0x1a);
    for (i = 0; i < count; i++) {
        u16 idx = ((u16*)*(u8**)((u8*)obj + 0x1c))[i];
        if (idx < *(u16*)((u8*)self + 0x102)) {
            fn_8016A39C(*(u8**)((u8*)self + 0x104) + idx * 0x88, obj);
        }
    }
}

extern "C" void fn_8017A85C(void) {
    fn_80178B74();
}

extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" void fn_8017A928(void) {
    fn_801788C0();
}

extern "C" void* fn_8017AA68(u32* self, int a, int b, int c) {
    fn_80176550(self);
    *(void**)self = lbl_80298DF0;
    self[0x40] = 0;
    self[0x41] = 0;
    self[0x42] = 0;
    self[0x43] = 0;
    self[0x44] = 0;
    self[0x49] = 0;
    self[0x4a] = -1;
    self[0x4b] = -1;
    self[0x4c] = -1;
    self[0x4d] = -1;
    self[0x4e] = -1;
    self[0x4f] = -1;
    fn_8017B07C(self, a, b, c);
    return self;
}

extern "C" void* fn_8017B7E4(u32* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80298DF0;
        fn_80118BD0((void*)param_1[0x40], 1);
        fn_80118BD0((void*)param_1[0x41], 1);
        fn_80118BD0((void*)param_1[0x42], 1);
        fn_80118BD0((void*)param_1[0x43], 1);
        fn_8015AB1C((void*)param_1[0x49]);
        fn_80118BD0((void*)param_1[0x44], 1);
        fn_80176FE8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801C5D48(void* p);
extern "C" void fn_8017ECFC(void* self, f32 a, f32 b) {
    u8 buf[0x38];
    fn_801C5D48(buf);
    ((void (*)(void*, void*, f32, f32))((*(void***)self)[0x38 / 4]))(self, buf, a, b);
}

extern "C" int fn_80180B60(u8* self, u8* src) {
    u8 a = src[0];
    u8 b = src[1];
    self[0x14c] = a;
    u8 c = src[2];
    self[0x14d] = b;
    u8 d = src[3];
    self[0x14e] = c;
    self[0x14f] = d;
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

extern "C" void* fn_80180C24(u32* self, int a, int b, int c) {
    fn_80176550(self);
    *(void**)self = lbl_80299040;
    self[0x40] = 0;
    self[0x41] = -1;
    self[0x42] = -1;
    self[0x49] = 0;
    self[0x4a] = -1;
    self[0x4b] = -1;
    fn_801813CC(self, a, b, c);
    return self;
}

extern "C" void fn_80176848(void*);
#pragma push
#pragma use_lmw_stmw off
extern "C" void* fn_80181108(u32* self, s32 p1, s32 p2, s32 p3, s32 p4, s32 a, s32 b, s32 c, s32 d, s32 e) {
    fn_80176848(self);
    *(void**)self = lbl_80299040;
    self[0x40] = 0;
    self[0x41] = -1;
    self[0x42] = -1;
    self[0x49] = 0;
    self[0x4a] = -1;
    self[0x4b] = -1;
    fn_8018119C(self, a, b, c, d, e);
    return self;
}

extern "C" void fn_801817BC(char* self, UnkVObj_80181CCC* obj) {
    if (obj != 0) {
        if (*(u8*)(self + 0x131) != 0) {
            UnkVObj_80181CCC* cur = *(UnkVObj_80181CCC**)(self + 0x100);
            if (cur != 0) {
                cur->vf8(1);
            }
        }
        *(UnkVObj_80181CCC**)(self + 0x100) = obj;
        *(u8*)(self + 0x131) = 0;
    }
}

#pragma pop
extern "C" int fn_80181BA0(char* self) {
    return *(int*)(self + 0x124);
}

extern "C" u8 fn_80181CCC(char* self, u8 v) {
    char* p = *(char**)(self + 0xec);
    if (p == 0) {
        return 0;
    }
    if ((*(UnkVObj_80181CCC**)(p + 0xc))->vfC() != 0x11) {
        return 0;
    }
    *(u8*)(self + 0xb5) = v;
    return v;
}

extern "C" int fn_80182058(char* self, void* v) {
    UnkVObj_80181CCC* o = *(UnkVObj_80181CCC**)(self + 0x100);
    if (o != 0 && o->vf3C() == v) {
        return 1;
    }
    return ((int (*)(char*, void*))fn_80177F0C)(self, v);
}

extern "C" void fn_801820F4(void) {
    fn_80177E84();
}

extern "C" void fn_80184B34(u8* self, u32* out) {
    u32 a = *(u32*)(self + 0x148);
    u32 b = *(u32*)(self + 0x14c);
    out[0] = a;
    a = *(u32*)(self + 0x150);
    out[1] = b;
    b = *(u32*)(self + 0x154);
    out[2] = a;
    a = *(u32*)(self + 0x160);
    out[3] = b;
    out[4] = a;
}

extern "C" void fn_80184B60(void* self, f32 x, f32 y, f32 w, f32 h) {
    f32 pos[2];
    f32 rect[4];
    pos[0] = x;
    pos[1] = y;
    rect[0] = pos[0];
    rect[1] = pos[1];
    rect[2] = x + w;
    rect[3] = y + h;
    ((void (*)(void*, f32*))(*(void***)self)[0x94 / 4])(self, rect);
}

extern "C" void fn_80184BF4(void) {
    fn_80177F0C();
}

extern "C" void fn_80184C14(void) {
    fn_80178990();
}

extern "C" void fn_80184C34(void) {
    fn_801788C0();
}

extern "C" void fn_80184C54(void) {
}

extern "C" void fn_80184C58(void* self, void* unused, void* param_3) {
    void* obj = *(void**)((u8*)self + 0x168);
    if (*(void**)((u8*)obj + 0x28) == 0) {
        if (((u8 (*)(void*, f32))(*(void***)self)[0x9c / 4])(self, *(f32*)&lbl_80301BF8) && param_3 != 0) {
            void* sub = *(void**)((u8*)*(void**)((u8*)self + 0x168) + 0x70);
            if (((void* (*)(void*, s32))(*(void***)sub)[0xa4 / 4])(sub, 0) == 0) {
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

extern "C" void fn_80181724(void* self, s32 param_2);
extern void* lbl_802993CC[];
extern "C" void fn_8018903C(void) {
    fn_80178990();
}

extern "C" void fn_8018905C(void) {
    fn_801788C0();
}

extern "C" void* fn_8018939C(void* self, s16 param_2) {
    if (self != nullptr) {
        *(void**)self = lbl_802993CC;
        if (*((u8*)self + 0x140) != 0) {
            void* obj = *(void**)((u8*)self + 0x138);
            if (obj != nullptr) {
                void** vtbl = *(void***)obj;
                ((void (*)(void*, s32))vtbl[0x8 / 4])(obj, 1);
            }
        }
        fn_80181724(self, 0);
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern "C" void fn_80189BD8(void* self, u32 param_2) {
    if (param_2 != 0) {
        void* obj = *(void**)((u8*)self + 0x138);
        if (obj != nullptr) {
            void* sub = *(void**)((u8*)obj + 0x70);
            if (sub != nullptr) {
                ((void (*)(void*))(*(void***)sub)[0x94 / 4])(sub);
            }
        }
    }
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

extern "C" int fn_8018A4B4(u8* self, s32* p1, s32* p2) {
    u8* obj;
    if (*p1 == 0 && *p2 == -1) {
        return 1;
    }
    obj = *(u8**)(*(u8**)(self + 0x138) + 0x70);
    (*(void (**)(void*))(*(u32*)obj + 0x58))(obj);
    obj = *(u8**)(*(u8**)(self + 0x138) + 0x70);
    if ((*(u8 (**)(void*))(*(u32*)obj + 0x18))(obj) == 1) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8018A87C(void) {
    fn_80177E84();
}

extern "C" void fn_8018A8A0(void) {
    fn_80178990();
}

extern "C" void fn_8018A8C0(void) {
    fn_801788C0();
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

extern "C" void fn_8018B384(void* self, void* dst, void* src);
extern "C" void fn_8018B35C(void* self, void* src) {
    fn_8018B384(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B448(void* self, void* dst, void* src);
extern "C" void fn_8018B420(void* self, void* src) {
    fn_8018B448(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B65C(void* self, void* dst, void* src);
extern "C" void fn_8018B634(void* self, void* src) {
    fn_8018B65C(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_8018B770(void* self, void* dst, void* src);
extern "C" void fn_8018B748(void* self, void* src) {
    fn_8018B770(self, *(void**)((u8*)self + 4), src);
}

extern u8 lbl_802994BC[];
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

extern "C" void fn_8018BB74(void* self, void* dst, void* src);
extern "C" void fn_8018BC30(void* self, void* dst, void* src);
extern "C" void fn_8018BD24(void* self, void* dst, void* src);
extern "C" void fn_8018BCFC(void* self, void* src) {
    fn_8018BD24(self, *(void**)((u8*)self + 4), src);
}

extern f32 lbl_80301C30;
extern "C" void* fn_80174B40(void* base, u32 offset);
extern "C" void fn_8018BDF0(void* self, void* dst, void* src);
extern "C" void fn_8018BDC8(void* self, void* src) {
    fn_8018BDF0(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_8018C1E8(void* base, u32 offset);
extern "C" void fn_8018BFA4(void* self, void* dst, void* src) {
    u8 flag = ((u8*)src)[8];
    *(s16*)((u8*)dst + 6) = *(s16*)((u8*)src + 10);
    u16 a = *(u16*)((u8*)src + 0xc);
    *(u8*)((u8*)dst + 4) = flag;
    u16 b = *(u16*)((u8*)src + 0xe);
    *(f32*)((u8*)dst + 8) = lbl_80301C30;
    *(u16*)((u8*)dst + 0x10) = a;
    u32 c = *(u32*)((u8*)src + 0x10);
    *(u16*)((u8*)dst + 0x12) = b;
    *(void**)((u8*)dst + 0x14) = fn_8018C1E8(src, c);
    *(void**)((u8*)dst + 0x18) = fn_80174B40(src, *(u32*)((u8*)src + 0x14));
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

extern "C" void* fn_8018C230(void* base, u32 offset) {
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

