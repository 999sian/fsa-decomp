#include "types.h"
struct NaviTracker {
    virtual void fn_0();
    virtual void fn_1();
    virtual void fn_2();
    virtual void fn_3(s32);
    virtual u32 fn_4();
    virtual void fn_5(u32);
    virtual u32 fn_6();
    virtual void fn_7(u32);
    virtual void fn_8();
    virtual void fn_9();
    virtual void fn_10();
    virtual void fn_11();
    virtual void fn_12();
    virtual s32 fn_13(u32*, u32, s32);
    virtual void fn_14();
    virtual s32 fn_15(u32*, u32, s32);
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013cd54-0x8013d9a4 (28 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_80293318[];
extern char lbl_80201E80[];
extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013D5DC(void*, void*);
extern "C" void fn_80133694(void*, void*, void*);
extern "C" u8 fn_8013BAB4(void*, void*, u32, u32);
extern "C" void fn_801C6630(void*, void*, void*);
extern u8 lbl_80201E90[];
extern "C" void fn_8013D7E0(void*, void*);
extern "C" void fn_8013D6D8(void*, void*);
extern "C" void fn_8013D8C0(void*, void*);
extern "C" void fn_8013345C();
struct Entry_802C67C4 { s32 unk0; s32 id; u8 pad[0x18]; };
extern Entry_802C67C4 lbl_802C67C4[];
extern u32 lbl_802FF378;
extern void* lbl_8029260C[];
extern void* lbl_80292500[];
extern void* lbl_802933B4[];
struct Slot_8013D1D4 { u8 pad[0x10]; void* ptr; };
struct VObj_8013CD54 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vfA();
    virtual void vfB();
    virtual void vfC();
    virtual void vfD();
    virtual void vfE(void*);
};
struct VObj_8013D304 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5(u32);
};
struct Entry_8013D21C { s32 unk0; s32 id; u8 pad[0xc]; f32 (VObj_8013D304::*fn)(); };
struct Slot_8013D21C { u8 pad[4]; s32 unk4; void* func; f32 value; };
struct VObj_8013D488 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(u32, s32);
};
struct VObj_8013D7E0 {
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf0A(); virtual void vf0B();
    virtual void vf0C(); virtual void vf0D(); virtual void vf0E(); virtual void vf0F();
    virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13();
    virtual void vf14(); virtual void vf15(); virtual void vf16(); virtual void vf17();
    virtual void vf18(); virtual void vf19(); virtual void vf1A(); virtual void vf1B();
    virtual void vf1C(); virtual void vf1D(); virtual void vf1E(); virtual void vf1F(u32*);
    virtual void vf20(f32*);
};
extern "C" void fn_801E0DB8(void* arr, void* ctor, void* dtor, u32 size, u32 n);
struct VObj_8013D5DC {
 virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
 virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
 virtual void vf08(); virtual void vf09(); virtual void vf0A(); virtual void vf0B();
 virtual void vf0C(); virtual void vf0D(); virtual void vf0E(); virtual void vf0F();
 virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13();
 virtual void vf14(); virtual void vf15(); virtual void vf16(); virtual void vf17();
 virtual void vf18(); virtual void vf19(); virtual void vf1A(); virtual void vf1B();
 virtual void vf1C(f32*);
};
extern "C" void fn_801E10DC(void* p);
extern void* lbl_8029260C[];
extern void* lbl_80292500[];
extern "C" void fn_8013CD54(void* param_1) {
    *(u32*)((u8*)param_1 + 4) = 0;
    *(u32*)((u8*)param_1 + 8) = 0;
    *(u32*)((u8*)param_1 + 0x10) = (u32)&lbl_802FF378;
}

extern "C" void* fn_8013CD6C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80293318;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8013CDCC(void* param_1, void* param_2) {
    u8* p = (u8*)param_1 + 8;
    fn_801E10DC(*(void**)((u8*)param_2 + 0x128));
}

static inline void fn_8013D098_base(u8* b, u32 n) {
    *(void**)b = lbl_8029260C;
    *(void**)(b + 4) = b + 0xc;
    *(u32*)(b + 8) = n;
}

extern "C" void* fn_8013CDFC(void* param_1, void* param_2, void* param_3) {
    u8* self = (u8*)param_1;
    void* vt = lbl_80292500;
    *(void**)self = lbl_8029260C;
    *(void**)(self + 4) = self + 0xc;
    *(u32*)(self + 8) = 4;
    *(void**)self = vt;
    fn_801E0DB8(self + 0xc, (void*)fn_8013CD54, 0, 0x14, 4);
    *(void**)self = lbl_802933B4;
    *(void**)(self + 0x5c) = param_2;
    *(void**)(self + 0x60) = param_3;
    return param_1;
}

extern void* lbl_802933B4[];
extern "C" void* fn_8013414C(void* ptr, s16 param_2);
extern "C" void* fn_8013CE9C(void* ptr, s16 param_2) {
    if (ptr) {
        *(void**)ptr = lbl_802933B4;
        ((NaviTracker*)ptr)->fn_3(0);
        fn_8013414C(ptr, 0);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8013CF14(void) {
}

extern "C" void fn_801336CC(void* param_1, void* param_2, void* param_3);
extern "C" void fn_8013CF18(void* param_1) {
    void* o = *(void**)((u8*)param_1 + 0x60);
    ((NaviTracker*)o)->fn_5(((NaviTracker*)o)->fn_4() | 1);
    o = *(void**)((u8*)param_1 + 0x60);
    u32 local = ((u32 (*)(void*))(*(void***)o)[15])(o);
    fn_801336CC(param_1, lbl_80201E80, &local);
}

extern "C" void fn_8013CFA4(void* param_1) {
    VObj_8013D304* o = *(VObj_8013D304**)((u8*)param_1 + 0x60);
    o->vf5(o->vf4() & 0xfffffffe);
}

extern "C" void fn_801337AC(void* param_1, void* param_2, void* param_3);
extern "C" void fn_8013CFF8(void* param_1) {
    void* local;
    void* local2;
    fn_801337AC(param_1, &local, lbl_80201E80);
    local2 = local;
    (*(VObj_8013CD54**)((u8*)param_1 + 0x60))->vfE(&local2);
    (*(VObj_8013CD54**)((u8*)param_1 + 0x60))->vf3();
}

extern "C" void fn_8013D064(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x60), param_3, param_4, param_5, param_6);
}

extern void* lbl_80292438[];
extern "C" void* fn_8013D098(void* param_1, void* param_2, void* param_3) {
    extern char lbl_802934A8[];
    u8* self = (u8*)param_1;
    fn_8013D098_base(self, 0xc);
    *(void**)self = lbl_80292438;
    fn_801E0DB8(self + 0xc, (void*)fn_8013CD54, 0, 0x14, 0xc);
    *(void**)self = lbl_802934A8;
    *(void**)(self + 0xfc) = param_2;
    *(void**)(self + 0x100) = param_3;
    *(u32*)(self + 0x104) = 0;
    *(u32*)(self + 0x108) = 0;
    *(s32*)(self + 0x10c) = -1;
    *(u8*)(self + 0x110) = 0;
    *(u32*)(self + 0x114) = 0;
    *(s32*)(self + 0x118) = -1;
    *(u8*)(self + 0x11c) = 0;
    return param_1;
}

extern char lbl_802934A8[];
extern "C" void fn_801343E4(void* ptr, s32 param_2);
extern "C" void* fn_8013BD28(void* a, void* b);
extern "C" void fn_801336CC(void* a, void* b, void* c);
extern "C" void* fn_8013D15C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802934A8;
        ((NaviTracker*)ptr)->fn_3(0);
        fn_801343E4(ptr, 0);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8013D1D4(void* param_1) {
    Entry_802C67C4* e;
    s32 id;
    for (e = lbl_802C67C4; (id = e->id) != -1; e++) {
        Slot_8013D1D4* s = (Slot_8013D1D4*)((u8*)*(void**)((u8*)param_1 + 4) + id * 0x14);
        void* p = e ? (void*)e : (void*)&lbl_802FF378;
        s->ptr = p;
    }
}

extern "C" void fn_8013D21C(void* param_1, void* param_2) {
    VObj_8013D304* o = *(VObj_8013D304**)((u8*)param_1 + 0x100);
    o->vf5(o->vf4() | 1);
    void* v = *(void**)((u8*)param_2 + 0x14);
    fn_8013D6D8(param_1, v);
    fn_8013D8C0(param_1, v);
    Entry_8013D21C* e;
    for (e = (Entry_8013D21C*)lbl_802C67C4; e->id != -1; e++) {
        f32 val = ((*(VObj_8013D304**)((u8*)param_1 + 0x100))->*(e->fn))();
        Slot_8013D21C* s = (Slot_8013D21C*)((u8*)*(void**)((u8*)param_1 + 4) + e->id * 0x14);
        s->func = (void*)fn_8013345C;
        s->unk4 = 0;
        s->value = val;
    }
}

extern "C" void fn_8013D304(void* param_1) {
    VObj_8013D304* o = *(VObj_8013D304**)((u8*)param_1 + 0x100);
    o->vf5(o->vf4() & 0xfffffffe);
}

extern "C" void fn_8013D358(void* param_1, void* param_2) {
    void* v;
    v = *(void**)((u8*)param_2 + 0x14);
    fn_8013D5DC(param_1, v);
    fn_8013D7E0(param_1, v);
    (*(VObj_8013D304**)((u8*)param_1 + 0x100))->vf3();
}

extern "C" void fn_8013D3B4(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x100), param_3, param_4, param_5, param_6);
}

extern "C" void* fn_8013BCDC(void* param_1, void* param_2);
extern "C" void fn_8013D3E8(void* param_1, s32 param_2, void* param_3) {
    switch (param_2) {
    case 0x18:
        *(void**)((u8*)param_1 + 0x108) = fn_8013BCDC(*(void**)((u8*)param_1 + 0xfc), param_3);
        break;
    }
}

extern "C" void fn_8013D42C(void* param_1, s32 param_2, u32* param_3) {
    switch (param_2) {
    case 0x18:
        *(void**)((u8*)param_1 + 0x10c) = fn_8013BD28(*(void**)((u8*)param_1 + 0x108), param_3);
        break;
    case 0x19:
        *(u32*)((u8*)param_1 + 0x10c) = *param_3;
        break;
    }
}

extern "C" void fn_8013D488(void* param_1, s32 param_2, u32* param_3) {
    switch (param_2) {
    case 2: {
        u8 b = (u8)((0 - *param_3 | *param_3) >> 31);
        *(u8*)((u8*)param_1 + 0x110) = b;
        switch (*(s32*)((u8*)param_1 + 0x104)) {
        case 1: {
            u32 a = 0;
            s32 c = -1;
            if (*(u8*)((u8*)param_1 + 0x110) != 0) {
                a = *(u32*)((u8*)param_1 + 0x108);
                c = *(s32*)((u8*)param_1 + 0x10c);
            }
            (*(VObj_8013D488**)((u8*)param_1 + 0x100))->vf9(a, c);
            break;
        }
        case 0:
            break;
        }
        break;
    }
    }
}

extern "C" void fn_8013D508(void* param_1, s32 param_2, u32* param_3) {
    if (param_2 != 2) {
        return;
    }
    *(u32*)((u8*)param_1 + 0x104) = *param_3;
}

extern "C" void fn_8013D51C(void* param_1, s32 param_2, void* param_3) {
    switch (param_2) {
    case 0x18:
        *(void**)((u8*)param_1 + 0x114) = fn_8013BCDC(*(void**)((u8*)param_1 + 0xfc), param_3);
        break;
    }
}

extern "C" void fn_8013D560(void* param_1, s32 param_2, u32* param_3) {
    switch (param_2) {
    case 0x18:
        *(void**)((u8*)param_1 + 0x118) = fn_8013BD28(*(void**)((u8*)param_1 + 0x114), param_3);
        break;
    case 0x19:
        *(u32*)((u8*)param_1 + 0x118) = *param_3;
        break;
    }
}

extern "C" void fn_8013D5BC(void* param_1, s32 param_2, u32* param_3) {
    if (param_2 != 2) {
        return;
    }
    *(u8*)((u8*)param_1 + 0x11c) = *param_3 != 0;
}

extern "C" void fn_8013D5DC(void* param_1, void* param_2) {
    u8* self = (u8*)param_1;
    u8* other = (u8*)param_2;
    f32 pos[3];
    f32 v[3];
    f32 m[12];
    f32* p;
    f32* q;
    u8 ok;
    fn_80133694(self, pos, lbl_80201E90);
    if (self[0x110] == 0) {
        if (other[0x74] == 0) {
            q = pos;
        } else {
            fn_801C6630(other + 0x98, pos, v);
            q = v;
        }
        p = q;
    } else {
        p = pos;
        switch (*(s32*)(self + 0x104)) {
        case 0:
            if (!fn_8013BAB4(m, pos, *(u32*)(self + 0x108), *(u32*)(self + 0x10c))) {
                ok = 0;
            } else {
                v[0] = m[3];
                v[1] = m[7];
                v[2] = m[11];
                ok = 1;
            }
            if (!ok) {
                return;
            }
            p = v;
            break;
        case 1:
            break;
        }
    }
    ((VObj_8013D5DC*)*(void**)(self + 0x100))->vf1C(p);
}

extern "C" void fn_80133694(void*, void*, void*);
extern "C" u8 fn_8013BAB4(void*, void*, u32, u32);
extern "C" u8 fn_8013BBF0(void*, void*, void*, void*);
extern "C" void fn_80133624(void*, void*, void*);
extern "C" void fn_801C6630(void*, void*, void*);
extern u8 lbl_80201E9C[];
extern u8 lbl_80201E90[];
extern "C" void fn_8013D7E0(void* param_1, void* param_2) {
    u8* self = (u8*)param_1;
    u8* other = (u8*)param_2;
    f32 pos[3];
    f32 v[3];
    f32 m[12];
    f32* p;
    f32* q;
    u8 ok;
    fn_80133694(self, pos, lbl_80201E9C);
    if (self[0x11c] == 0) {
        if (other[0x74] == 0) {
            q = pos;
        } else {
            fn_801C6630(other + 0x98, pos, v);
            q = v;
        }
        p = q;
    } else {
        if (!fn_8013BAB4(m, pos, *(u32*)(self + 0x114), *(u32*)(self + 0x118))) {
            ok = 0;
        } else {
            v[0] = m[3];
            v[1] = m[7];
            v[2] = m[11];
            ok = 1;
        }
        if (!ok) {
            return;
        }
        p = v;
    }
    (*(VObj_8013D7E0**)(self + 0x100))->vf20(p);
}

extern "C" void fn_8013D8C0(void* param_1, void* param_2) {
    u32 auStack_4c[3];
    f32 local_58[3];
    u8 auStack_40[0x30];
    void* p;
    void* q;
    u8 ok;

    VObj_8013D7E0* obj = *(VObj_8013D7E0**)((u8*)param_1 + 0x100);
    obj->vf1F(auStack_4c);
    if (*(u8*)((u8*)param_1 + 0x11c) == 0) {
        if (*(u8*)((u8*)param_2 + 0x75) == 0) {
            q = auStack_4c;
        } else {
            fn_801C6630((u8*)param_2 + 0xc8, auStack_4c, local_58);
            q = local_58;
        }
        p = q;
    } else {
        if (!fn_8013BBF0(auStack_40, auStack_4c, *(void**)((u8*)param_1 + 0x114), *(void**)((u8*)param_1 + 0x118))) {
            ok = 0;
        } else {
            local_58[0] = *(f32*)(auStack_40 + 0xc);
            local_58[1] = *(f32*)(auStack_40 + 0x1c);
            local_58[2] = *(f32*)(auStack_40 + 0x2c);
            ok = 1;
        }
        if (!ok) {
            return;
        }
        p = local_58;
    }
    fn_80133624(param_1, lbl_80201E9C, p);
}

