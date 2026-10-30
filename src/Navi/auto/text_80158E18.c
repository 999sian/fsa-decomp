#include "types.h"
#include "dolphin/os/OSFastCast.h"
extern "C" int fn_8015CAD4(void* p, u32 r4, s32 r5);
extern "C" u8* fn_8015C57C(u8* p, u32 size, u8 a, u8 b, u8 c, u8 flags);
extern "C" void fn_8015BC38(u8* list, u8* node);
extern "C" void fn_8015BBEC(u8* list, u8* node, u8* prev, u8* next);
extern "C" void fn_8015BB50(char* p, char* q);
extern "C" int fn_8015CBAC(void* p, u32 r4, s32 r5);
extern "C" void fn_8011C9EC(const char*, int, const char*, ...);
extern char lbl_80297240[];
extern char lbl_80297250[];
extern char lbl_802FE168;
extern "C" u32 fn_80159E0C(void* p, u32 r4);
extern "C" void* fn_80159BE0(u32 size, u32 r4, void* p);
extern "C" void* fn_8015C89C(void* p, void* p2, u32 size, void* r6, void* r7);
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_8015A48C(void*);
extern "C" void fn_80124034(const char* fmt, ...);
extern "C" void fn_801BDDBC(void* p, void* data, u32 count);
extern "C" void fn_80166C84(void* p, void* p2);
extern u8 lbl_802EE20C[];
extern char lbl_8029765C[];
extern char lbl_80297690[];
extern char lbl_802979B8[];
extern "C" int fn_801C0288(void* p);
extern "C" void fn_801C0E4C(void* p);
extern "C" void OSCancelThread(void* p);
extern char lbl_8029783C[];
extern void* lbl_802977D0[];
extern "C" void* fn_8015D050(void* p);
extern "C" void fn_80166B58(void* a, void* b);
extern "C" void fn_8015D3E4(void* p, u32 a, u32 b, u32 c);
extern "C" void fn_8015D374(u8* p, void* r4, u32 r5);
struct VObj_80088CF8;
extern "C" void fn_8015D474(VObj_80088CF8* obj);
extern "C" void fn_801C0884(void*, void*, void*, void*, u32, u32, s32);
struct VObj_8003B920 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
};

struct VObj_80159E0C {
virtual void m0();
virtual void m1();
virtual void m2();
virtual void m3();
virtual void m4();
virtual void m5();
virtual void m6();
virtual void m7();
virtual void m8();
virtual void m9();
virtual void m10();
virtual void m11();
virtual void m12();
virtual void m13();
virtual u32 m14();
virtual u32 m15();
};

struct VObj_80088CF8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158e18-0x8015db8c (138 functions). split_file divides it into the game's real files.

extern void* lbl_8029796C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80159C6C(void*, int);
struct Unk8015AD64 {
    virtual void vf08(int);
};
struct Unk802FF544 {
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual int vf24(int, int);
};
extern "C" void fn_80159DB4(void);
extern u32 lbl_802FF540;
extern char lbl_802979A4[];
extern u32 lbl_802FF580;
extern "C" void* OSGetArenaLo(void);
extern "C" void* OSGetArenaHi(void);
extern "C" void OSSetArenaLo(void*);
extern "C" void OSSetArenaHi(void*);
extern "C" char* fn_801BBE50(char*, char*, void*);
extern char* lbl_802FF554;
extern char* lbl_802FF558;
extern char* lbl_802FF55C;
extern char* lbl_802FF560;
extern u32 lbl_802FF564;
#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void fn_80158E18(u32* p) {
    u32 mode = 0;
    u32 cnt0 = 0;
    u32 cnt1 = 0;
    u32 w0 = 0;
    u32 flags = 0;
    u32 w1 = 1;
    u32 w2 = 0;
    u32 f10 = 0;
    u32 f11 = 0;
    u32 f12 = 0;
    u32 f31 = 0;
    u32 f30 = 0;
    u32 f29 = 0;
    u32 f28 = 0;
    u32 f27 = 0;
    u32 f26 = 0;
    u32 f25 = 0;
    u32 cmd;

    while ((cmd = p[0]) != 0xff) {
        switch (cmd) {
        case 0:
            w0 = p[1];
            break;
        case 1:
            flags = (flags & ~1) | p[1];
            break;
        case 2:
            flags = (flags & ~2) | (p[1] << 1);
            break;
        case 3:
            flags = (flags & ~4) | (p[1] << 2);
            break;
        case 4:
            flags = (flags & ~8) | (p[1] << 3);
            break;
        case 5:
            flags = (flags & ~16) | (p[1] << 4);
            break;
        case 6:
            flags = (flags & ~32) | (p[1] << 5);
            break;
        case 7:
            flags = (flags & ~64) | (p[1] << 6);
            break;
        case 8:
            flags = (flags & ~128) | (p[1] << 7);
            break;
        case 9:
            w1 = p[1];
            break;
        case 10: {
            u32 d = p[1];
            if (d != 0) {
                w2 = d;
                mode = 1;
            }
            break;
        }
        case 11: {
            u32 d = p[1];
            if (d != 0) {
                w2 = d;
                mode = 2;
            }
            break;
        }
        case 12:
            f10 = p[1];
            cnt0 += f10 != 0;
            break;
        case 13:
            f11 = p[1];
            cnt0 += f11 != 0;
            break;
        case 14:
            f12 = p[1];
            cnt1 += f12 != 0;
            break;
        case 15:
            f31 = p[1];
            cnt1 += f31 != 0;
            break;
        case 16:
            f30 = p[1];
            cnt1 += f30 != 0;
            break;
        case 17:
            f29 = p[1];
            cnt1 += f29 != 0;
            break;
        case 18:
            f28 = p[1];
            cnt1 += f28 != 0;
            break;
        case 19:
            f27 = p[1];
            cnt1 += f27 != 0;
            break;
        case 20:
            f26 = p[1];
            cnt1 += f26 != 0;
            break;
        case 21:
            f25 = p[1];
            cnt1 += f25 != 0;
            break;
        case 22:
        case 23:
        case 24:
        case 25:
            break;
        }
        p += 2;
    }

    w0 |= flags << 1;
    *(volatile u8*)0xCC008000 = 8;
    *(volatile u8*)0xCC008000 = 0x50;
    *(volatile u32*)0xCC008000 = (f11 << 15) | (f10 << 13) | (w2 << 11) | (w1 << 9) | w0;
    *(volatile u8*)0xCC008000 = 8;
    *(volatile u8*)0xCC008000 = 0x60;
    *(volatile u32*)0xCC008000 = (f25 << 14) | (f26 << 12) | (f27 << 10) | (f28 << 8) | (f29 << 6) | (f30 << 4) | (f31 << 2) | f12;
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u16*)0xCC008000 = 0;
    *(volatile u16*)0xCC008000 = 0x1008;
    *(volatile u32*)0xCC008000 = (cnt1 << 4) | cnt0 | (mode << 2);
}

extern "C" void fn_8015949C(int attr, u32 base, u8 stride)
{
    int idx;
    if (attr == 0x19) {
        idx = 1;
    } else {
        idx = attr - 9;
    }
    *(volatile u8*)0xCC008000 = 8;
    *(volatile u8*)0xCC008000 = idx + 0xA0;
    *(volatile u32*)0xCC008000 = base - 0x80000000;
    *(volatile u8*)0xCC008000 = 8;
    *(volatile u8*)0xCC008000 = idx + 0xB0;
    *(volatile u32*)0xCC008000 = stride;
}

extern "C" void fn_801594E0(unsigned int idx, unsigned char* c) {
    *(volatile unsigned char*)0xCC008000 = 0x10;
    *(volatile unsigned short*)0xCC008000 = 0;
    *(volatile unsigned short*)0xCC008000 = 0x100C + (idx & 1);
    *(volatile unsigned int*)0xCC008000 = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
}

extern "C" void fn_80159528(int type, int src, int dst, int op, u8 a, u8 b, u8 c) {
    u8 en = 0;
    *(volatile u8*)0xCC008000 = 0x61;
    if (type == 1 || type == 3) {
        en = 1;
    }
    *(volatile u32*)0xCC008000 = en | ((type == 2) << 1) | (c << 2) | (a << 3) | (b << 4) | (dst << 5) | (src << 8) | ((type == 3) << 11) | (op << 12) | 0x41000000;
}

extern "C" void fn_801595B0(int id, unsigned char* p) {
    u32 reg0 = p[0] | (p[3] << 12) | ((id * 2 + 0xe0) << 24);
    u32 reg1 = p[2] | (p[1] << 12) | ((id * 2 + 0xe1) << 24);
    *(volatile unsigned char*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg0;
    *(volatile unsigned char*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg1;
    *(volatile unsigned char*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg1;
    *(volatile unsigned char*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg1;
}

extern "C" void fn_80159608(int id, short* p) {
    u32 reg;
    reg = (p[0] & 0x7ff) | ((p[3] & 0x7ff) << 12) | ((id * 2 + 0xe0) << 24);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg;
    reg = (p[2] & 0x7ff) | ((p[1] & 0x7ff) << 12) | ((id * 2 + 0xe1) << 24);
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg;
    *(volatile u8*)0xCC008000 = 0x61;
    *(volatile u32*)0xCC008000 = reg;
}

extern "C" void fn_80159668(float* m, u32 id) {
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u16*)0xCC008000 = 0xb;
    *(volatile u16*)0xCC008000 = (u16)(id << 2);
    {
        float f = m[0];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[1];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[2];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[3];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[4];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[5];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[6];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[7];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[8];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[9];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[10];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
    {
        float f = m[11];
        *(volatile u32*)0xCC008000 = *(u32*)&f;
    }
}

extern "C" void fn_80159750(float* m, int id) {
    volatile unsigned char* fifo = (volatile unsigned char*)0xCC008000;
    float f;
    *(volatile unsigned char*)0xCC008000 = 0x10;
    *(volatile unsigned short*)0xCC008000 = 8;
    *(volatile unsigned short*)0xCC008000 = id * 3 + 0x400;
    f = m[0]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&f;
    { float g = m[1]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&g; }
    { float g = m[2]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&g; }
    { float g = m[4]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&g; }
    { float g = m[5]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&g; }
    { float g = m[6]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&g; }
    { float g = m[8]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&g; }
    { float g = m[9]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&g; }
    { float g = m[10]; *(volatile unsigned int*)0xCC008000 = *(unsigned int*)&g; }
    (void)fifo;
}

#pragma dont_inline on
extern "C" void fn_8015980C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 b0, u32 b1, u32 b2, u32 b3) {
    u32 regA;
    u32 regB;
    u8 cmd = 0x08;
    regA = a0 | (a1 << 6) | (a2 << 12) | (a3 << 18) | (a4 << 24);
    *(volatile u8*)0xCC008000 = cmd;
    *(volatile u8*)0xCC008000 = 0x30;
    *(volatile u32*)0xCC008000 = regA;
    regB = b0 | (b1 << 6) | (b2 << 12) | (b3 << 18);
    *(volatile u8*)0xCC008000 = cmd;
    *(volatile u8*)0xCC008000 = 0x40;
    *(volatile u32*)0xCC008000 = regB;
    *(volatile u8*)0xCC008000 = 0x10;
    *(volatile u16*)0xCC008000 = 1;
    *(volatile u16*)0xCC008000 = 0x1018;
    *(volatile u32*)0xCC008000 = regA;
    *(volatile u32*)0xCC008000 = regB;
}
#pragma dont_inline reset
extern "C" int fn_80159AE4(char** outStart, int* outSize, void* arg) {
    char* lo = (char*)OSGetArenaLo();
    char* hi = (char*)OSGetArenaHi();
    if (lo == hi) {
        return 0;
    }
    lo = (char*)(((u32)fn_801BBE50(lo, hi, arg) + 0x1f) & ~0x1f);
    hi = (char*)((u32)hi & ~0x1f);
    lbl_802FF554 = (char*)0x80000000;
    lbl_802FF558 = lo;
    lbl_802FF55C = lo;
    lbl_802FF560 = hi;
    lbl_802FF564 = *(u32*)0x80000028;
    OSSetArenaLo(hi);
    OSSetArenaHi(hi);
    *outStart = lo;
    *outSize = hi - lo;
    return 1;
}
#pragma pop

extern "C" u32 fn_80159B94(u32 param_1) {
    u32 old = lbl_802FF540;
    lbl_802FF540 = param_1;
    return old;
}

extern u32 lbl_802FF544;
extern "C" u32 fn_80159BA4(u32 param_1) {
    u32 old = lbl_802FF544;
    lbl_802FF544 = param_1;
    return old;
}

extern "C" void fn_80159BB4(VObj_8003B920* obj) {
    obj->m6();
}

extern "C" void* fn_80159C40(void* p, u32 size, u32 align);
#pragma dont_inline on
extern "C" void* fn_80159BE0(u32 size, u32 align, void* p) {
    if (p != 0) {
        return fn_80159C40(p, size, align);
    }
    if (lbl_802FF544 != 0) {
        return fn_80159C40((void*)lbl_802FF544, size, align);
    }
    return 0;
}

#pragma dont_inline reset
extern "C" void* fn_80159C40(void* p, u32 size, u32 align) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6();
        virtual void* v7(u32, u32);
    };
    return ((Obj*)p)->v7(size, align);
}

extern "C" char* lbl_802FF548;
extern "C" void* fn_80159E8C(void* ptr);
extern "C" void fn_80159CB4(void* heap, void* p);
#pragma push
#pragma dont_inline on
extern "C" void fn_80159C6C(void* p, int heap) {
    void* h = (void*)heap;
    if (h == 0) {
        h = fn_80159E8C(p);
        if (h == 0) {
            return;
        }
    }
    fn_80159CB4(h, p);
}
#pragma pop

extern "C" void fn_80159CB4(void* heap, void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(void*);
    };
    ((Obj*)heap)->v8(p);
}

extern "C" void fn_80159CE0(void* p) {
    while (*(void**)((u8*)p + 0x5c) != 0) {
        Unk8015AD64* obj = **(Unk8015AD64***)((u8*)p + 0x5c);
        obj->vf08(-1);
    }
}

extern "C" void fn_80159D30(void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14();
    };
    ((Obj*)p)->v9();
}

extern "C" s32 fn_80159D5C(void* p, void* a, s32 b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual s32 v12(); virtual void v13(); virtual void v14();
    };
    return ((Obj*)p)->v12();
}

extern "C" void fn_80159D88(void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14();
    };
    ((Obj*)p)->v13();
}

extern "C" u32 fn_80159DE0(void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual u32 v16();
    };
    return ((Obj*)p)->v16();
}

extern "C" u32 fn_80159E0C(void* p, u32 align) {
    u32 a = ((VObj_80159E0C*)p)->m15();
    u32 b = ((VObj_80159E0C*)p)->m14();
    u32 m = align - 1;
    u32 off = m & (align - (a & 0xf));
    m = ~m;
    return m & (b - off);
}

extern "C" void* fn_80159EEC(char* heap, void* ptr);
extern "C" void* fn_8015A168(char* heap, void* ptr);
#pragma dont_inline on
extern "C" void* fn_80159E8C(void* ptr) {
    void* ret;
    if (lbl_802FF548 == 0) {
        ret = 0;
    } else if (*(void**)(lbl_802FF548 + 0x30) <= ptr && ptr < *(void**)(lbl_802FF548 + 0x34)) {
        ret = fn_80159EEC(lbl_802FF548, ptr);
    } else {
        ret = fn_8015A168(lbl_802FF548, ptr);
    }
    return ret;
}

extern "C" int fn_8015A3E4(void* heap, u32 start, u32 size) {
    struct HeapObj {
        virtual void vf8(int);
    };
    struct Node {
        HeapObj* obj; u32 unk4; u32 unk8; Node* next;
    };
    Node* prev = 0;
    u32 end = start + size;
    Node* n = *(Node**)((u8*)heap + 0x5c);
    while (n != 0) {
        HeapObj* o = n->obj;
        if (start <= (u32)o && (u32)o < end) {
            o->vf8(-1);
            if (prev == 0) {
                n = *(Node**)((u8*)heap + 0x5c);
            } else {
                n = prev->next;
            }
        } else {
            prev = n;
            n = n->next;
        }
    }
    return 0;
}

#pragma dont_inline on
extern "C" void fn_8015A530(void* p) {
    while (*(void**)((u8*)p + 0x5c) != 0) {
        Unk8015AD64* obj = **(Unk8015AD64***)((u8*)p + 0x5c);
        obj->vf08(-1);
    }
}
#pragma dont_inline reset

extern "C" void fn_8015A580(u32* dst, u32* src, u32 size) {
    u32 n = (size + 3) >> 2;
    while (n != 0) {
        *dst++ = *src++;
        n--;
    }
}

extern "C" u8 fn_8015A644(u8* p, u8 v) {
    u8 old = p[0x68];
    p[0x68] = v;
    return old;
}

extern "C" void fn_8015A60C(void);
extern u32 lbl_802FF54C;
extern "C" u32 fn_8015A654(u32 param_1) {
    u32 old = lbl_802FF54C;
    if (param_1 == 0) {
        param_1 = (u32)fn_8015A60C;
    }
    lbl_802FF54C = param_1;
    return old;
}

extern "C" int fn_8015A90C(int a) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6();
        virtual int v8(int, int);
    };
    if (lbl_802FF544 != 0) {
        return ((Obj*)lbl_802FF544)->v8(a, 4);
    }
    return 0;
}

extern "C" int fn_8015A958(int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6();
        virtual int v8(int, int);
    };
    if (lbl_802FF544 != 0) {
        return ((Obj*)lbl_802FF544)->v8(a, b);
    }
    return 0;
}

extern "C" int fn_8015A9A8(int a, void* p, int c) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6();
        virtual int v8(int);
    };
    if (p != 0) {
        return ((Obj*)p)->v8(a);
    }
    if (lbl_802FF544 != 0) {
        return ((Obj*)lbl_802FF544)->v8(a);
    }
    return 0;
}

extern "C" int fn_8015AA14(int a) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6();
        virtual int v8(int, int);
    };
    if (lbl_802FF544 != 0) {
        return ((Obj*)lbl_802FF544)->v8(a, 4);
    }
    return 0;
}

extern "C" int fn_8015AA60(int a, int b) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6();
        virtual int v8(int, int);
    };
    if (lbl_802FF544 != 0) {
        return ((Obj*)lbl_802FF544)->v8(a, b);
    }
    return 0;
}

extern "C" int fn_8015AAB0(int a, void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6();
        virtual int v8(int);
    };
    if (p != 0) {
        return ((Obj*)p)->v8(a);
    }
    if (lbl_802FF544 != 0) {
        return ((Obj*)lbl_802FF544)->v8(a);
    }
    return 0;
}

#pragma dont_inline on
extern "C" void fn_8015AB1C(void* p) {
    fn_80159C6C(p, 0);
}
#pragma dont_inline reset

extern "C" void fn_80159C6C(void*, int);
extern "C" void fn_8015AB40(void* p) {
    fn_80159C6C(p, 0);
}

extern "C" void fn_8015AB64() {
}

extern "C" bool fn_8015AB68(void* a, int* b, int* c) {
    return b[1] == c[1];
}

extern "C" void fn_8015AB80(void) {
}

extern "C" int fn_8015AB84()
{
	return 0;
}

extern "C" int fn_8015AB8C() {
    return 0;
}

extern "C" int fn_8015AB94(int* p, int v) {
    return (unsigned int)((v - *p) | (*p - v)) >> 31;
}

extern "C" int fn_8015ABAC()
{
	return 0;
}

extern "C" void fn_8015ABB4(char** p) {
    char* q = *(char**)(*p + 0x18);
    if (q != 0) q -= 0xc;
    *p = q;
}

extern "C" void* fn_8015ABD0(void** p) {
    return ((void**)*p)[3];
}

extern "C" void fn_8015ABDC(void** param_1, void* param_2) {
    *param_1 = param_2;
}

extern "C" void* fn_8015ABE4(void* p) {
    return ((void**)p)[2];
}

extern "C" void* fn_8015ABEC(void** p) {
    return ((void**)*p)[3];
}

extern "C" void* fn_8015ABF8(void* p) {
    return ((void**)p)[2];
}

extern "C" int fn_80159AE4(char** start, int* size, void* arg);
extern void* lbl_802975C4[];
extern "C" void fn_801598A4(void* p);
extern "C" void fn_8015C518(void* p, int a, int b, int c, int d, int e);
extern "C" char* fn_8015ADE8(char* base, char* data, int size, int flag, void* arg);
extern "C" char* lbl_802FF548;
extern char* lbl_802FF548;
extern "C" char* fn_8015AC00(void* arg, void* arg2) {
    char* p = 0;
    if (lbl_802FF548 == 0) {
        char* start;
        int size;
        fn_80159AE4(&start, &size, arg);
        char* base = start;
        char* data = base + 0x90;
        int len = size - 0x90;
        if (base != 0) {
            base = fn_8015ADE8(base, data, len, 0, arg2);
        }
        p = base;
        lbl_802FF548 = p;
    }
    p[0x6e] = 1;
    return p;
}

extern "C" char* fn_8015AC80(u32 param_1, char* param_2, char* param_3) {
    char* iVar1;
    char* iVar2;
    char* iVar3;
    char* iVar4;
    if (param_2 == 0) {
        param_2 = lbl_802FF548;
    }
    if (param_1 == 0xffffffff) {
        param_1 = fn_80159E0C(param_2, 0x10);
    }
    param_1 = param_1 & 0xfffffff0;
    if (param_1 < 0xa0) {
        return 0;
    }
    iVar1 = (char*)fn_80159BE0(param_1, 0x10, param_2);
    iVar2 = iVar1;
    iVar4 = iVar2 + 0x90;
    if (iVar2 == 0) {
        return 0;
    }
    iVar3 = iVar2;
    if (iVar2 != 0) {
        iVar3 = fn_8015ADE8(iVar2, iVar4, (int)(param_1 - 0x90), (int)param_2, param_3);
    }
    if (iVar3 == 0) {
        fn_80159C6C(iVar2, 0);
        return 0;
    }
    *(u8*)(iVar3 + 0x6e) = 0;
    return iVar3;
}

extern "C" void fn_8015AD64(Unk8015AD64* p) {
    if (*((u8*)p + 0x6e) == 0) {
        u32 iVar = *(u32*)(*(u32*)((u8*)p + 0x50) + 0xc);
        if (iVar != 0) {
            p->vf08(-1);
            fn_80159C6C(p, iVar);
        }
    } else {
        p->vf08(-1);
    }
}

extern "C" char* fn_8015ADE8(char* p, char* param_2, int param_3, int param_4, void* param_5) {
    fn_801598A4(p);
    *(void**)p = lbl_802975C4;
    p[0x6c] = 0;
    *(u8*)(p + 0x6d) = 0xff;
    *(char**)(p + 0x78) = param_2;
    *(char**)(p + 0x7c) = *(char**)(p + 0x78);
    fn_8015C518(*(char**)(p + 0x78), 0, 0, param_3 - 0x10, 0, 0);
    *(u32*)(p + 0x80) = 0;
    *(u32*)(p + 0x84) = 0;
    return p;
}

extern void* lbl_802975C4[];
extern "C" void fn_8015A530(void*);
extern "C" void fn_801599D0(void*, int);
extern "C" void fn_8015AB1C(void* p);
extern "C" void* fn_8015AE80(void* p, s16 param_2) {
    if (p != nullptr) {
        *(void**)p = lbl_802975C4;
        fn_8015A530(p);
        fn_801599D0(p, 0);
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" u8* fn_8015C538(u8* p, u32 size, u8 a, u8 b, u8 c, u8 d);
extern "C" u8* fn_8015B260(u8* p, u32 size) {
    u32 best = 0xffffffff;
    u8* found;
    u8* node;
    u8* ret;
    size = (size + 3) & ~3;
    found = 0;
    for (node = *(u8**)(p + 0x78); node != 0; node = *(u8**)(node + 0xc)) {
        if (*(u32*)(node + 4) >= size && best > *(u32*)(node + 4)) {
            best = *(u32*)(node + 4);
            found = node;
            if (*(u8*)(p + 0x6c) != 0 || best == size) {
                break;
            }
        }
    }
    if (found != 0) {
        ret = fn_8015C538(found, size, *(u8*)(p + 0x6d), 0, 0, 0);
        if (ret != 0) {
            fn_8015BBEC(p, ret, *(u8**)(found + 8), *(u8**)(found + 0xc));
        } else {
            fn_8015BC38(p, found);
        }
        fn_8015BB50((char*)p, (char*)found);
        return found + 0x10;
    }
    return 0;
}

extern "C" u8* fn_8015B4A4(u8* p, u32 size) {
    u8* node;
    u8* found = 0;
    u8* ret;
    u8* prev;
    u8* result;
    u32 aligned = (size + 3) & ~3;
    for (node = *(u8**)(p + 0x7c); node != 0; node = *(u8**)(node + 8)) {
        if (*(u32*)(node + 4) >= aligned) {
            found = node;
            break;
        }
    }
    if (found != 0) {
        ret = fn_8015C57C(found, aligned, 0, 0, *(u8*)(p + 0x6d), 0);
        if (ret != 0) {
            prev = found;
        } else {
            fn_8015BC38(p, found);
            ret = found;
            prev = 0;
        }
        if (prev != 0) {
            fn_8015BBEC(p, prev, *(u8**)(found + 8), *(u8**)(found + 0xc));
        }
        fn_8015BB50((char*)p, (char*)ret);
        result = ret + 0x10;
    } else {
        result = 0;
    }
    return result;
}

extern "C" void* fn_8015C634(u32);
extern "C" int fn_8015C5D4(void*, void*);
extern "C" void fn_8015BC6C(void*, void*);
extern "C" void fn_8015B584(char* p, u32 addr) {
    void* blk;
    fn_801BE3A0(p + 0x18);
    if (*(u32*)(p + 0x30) <= addr && addr <= *(u32*)(p + 0x34) && (blk = fn_8015C634(addr)) != 0) {
        fn_8015C5D4(blk, p);
    }
    fn_801BE47C(p + 0x18);
}

#pragma push
#pragma dont_inline on
extern "C" void fn_8015B5F8(char* p) {
    fn_801BE3A0(p + 0x18);
    fn_80159CE0(p);
    *(int*)(p + 0x78) = *(int*)(p + 0x30);
    *(int*)(p + 0x7c) = *(int*)(p + 0x78);
    fn_8015C518(*(char**)(p + 0x78), 0, 0, *(int*)(p + 0x38) - 0x10, 0, 0);
    *(int*)(p + 0x80) = 0;
    *(int*)(p + 0x84) = 0;
    fn_801BE47C(p + 0x18);
}

#pragma push
#pragma dont_inline on
extern "C" void fn_8015B674(char* p) {
    char* n;
    char* next;
    fn_801BE3A0(p + 0x18);
    n = *(char**)(p + 0x80);
    while (n != 0) {
        if (*(unsigned char*)(n + 2) & 0x80) {
            fn_8015A3E4(p, (unsigned long)(n + 0x10), *(unsigned long*)(n + 4));
            next = *(char**)(n + 0xc);
            fn_8015C5D4(n, p);
            n = next;
        } else {
            n = *(char**)(n + 0xc);
        }
    }
    fn_801BE47C(p + 0x18);
}

extern "C" void fn_8015B704(void) {}

extern "C" char fn_8015B708(char* p, char v) {
    char old;
    fn_801BE3A0(p + 0x18);
    old = *(char*)(p + 0x6d);
    *(char*)(p + 0x6d) = v;
    fn_801BE47C(p + 0x18);
    return old;
}

extern "C" long fn_8015B91C(char* p, unsigned long addr) {
    char* n;
    fn_801BE3A0(p + 0x18);
    n = (char*)fn_8015C634(addr);
    if (n == 0 || addr < *(unsigned long*)(p + 0x30) || *(unsigned long*)(p + 0x34) < addr) {
        fn_801BE47C(p + 0x18);
        return -1;
    }
    fn_801BE47C(p + 0x18);
    return *(long*)(n + 4);
}

extern "C" long fn_8015B9A4(char* p) {
    char* n;
    long max;
    fn_801BE3A0(p + 0x18);
    max = 0;
    for (n = *(char**)(p + 0x78); n != 0; n = *(char**)(n + 0xc)) {
        if (max < *(long*)(n + 4)) {
            max = *(long*)(n + 4);
        }
    }
    fn_801BE47C(p + 0x18);
    return max;
}

extern "C" char* fn_8015BA10(char* p) {
    long max;
    char* best;
    char* n;
    fn_801BE3A0(p + 0x18);
    max = 0;
    best = 0;
    for (n = *(char**)(p + 0x78); n != 0; n = *(char**)(n + 0xc)) {
        if (max < *(long*)(n + 4)) {
            max = *(long*)(n + 4);
            best = n;
        }
    }
    fn_801BE47C(p + 0x18);
    return best;
}

extern "C" long fn_8015BA84(char* p) {
    char* n;
    long sum = 0;
    fn_801BE3A0(p + 0x18);
    for (n = *(char**)(p + 0x78); n != 0; n = *(char**)(n + 0xc)) {
        sum += *(long*)(n + 4);
    }
    fn_801BE47C(p + 0x18);
    return sum;
}

extern "C" long fn_8015BAE8(char* p) {
    char* n;
    long sum;
    fn_801BE3A0(p + 0x18);
    sum = 0;
    for (n = *(char**)(p + 0x80); n != 0; n = *(char**)(n + 0xc)) {
        sum += *(long*)(n + 4) + 0x10;
    }
    fn_801BE47C(p + 0x18);
    return sum;
}

extern "C" void fn_8015BB50(char* p, char* q) {
    char* tail;
    if (q == 0) {
        fn_8011C9EC(lbl_80297240, 0x620, &lbl_802FE168, lbl_80297250);
    }
    tail = *(char**)(p + 0x84);
    *(u16*)q = 0x484d;
    if (tail != 0) {
        *(char**)(tail + 0xc) = q;
        *(char**)(q + 8) = tail;
    } else {
        *(char**)(q + 8) = 0;
    }
    *(char**)(p + 0x84) = q;
    if (*(char**)(p + 0x80) == 0) {
        *(char**)(p + 0x80) = q;
    }
    *(char**)(q + 0xc) = 0;
}

extern "C" void fn_8015BBEC(u8* list, u8* node, u8* prev, u8* next) {
    if (prev == 0) {
        *(u8**)(list + 0x78) = node;
        *(u8**)(node + 0x8) = 0;
    } else {
        *(u8**)(prev + 0xc) = node;
        *(u8**)(node + 0x8) = prev;
    }
    if (next == 0) {
        *(u8**)(list + 0x7c) = node;
        *(u8**)(node + 0xc) = 0;
    } else {
        *(u8**)(next + 0x8) = node;
        *(u8**)(node + 0xc) = next;
    }
    *(u16*)node = 0;
}

extern "C" void fn_8015BC38(u8* list, u8* node) {
    u8* prev = *(u8**)(node + 0x8);
    u8* next = *(u8**)(node + 0xc);
    if (prev == 0) {
        *(u8**)(list + 0x78) = next;
    } else {
        *(u8**)(prev + 0xc) = next;
    }
    if (next == 0) {
        *(u8**)(list + 0x7c) = prev;
        return;
    }
    *(u8**)(next + 0x8) = prev;
}

extern "C" void fn_8015C518(void* p, int a, int b, int c, int d, int e) {
    *(u16*)p = 0x484d;
    ((u8*)p)[2] = e;
    ((u8*)p)[3] = d;
    *(u32*)((u8*)p + 0x4) = c;
    *(u32*)((u8*)p + 0x8) = a;
    *(u32*)((u8*)p + 0xc) = b;
}

extern "C" u8* fn_8015C538(u8* p, u32 size, u8 a, u8 b, u8 c, u8 d) {
    u8* n = 0;
    p[3] = a;
    p[2] = b;
    if (*(u32*)(p + 4) >= size + 0x10) {
        n = (u8*)(size + (u32)p);
        n[0x13] = c;
        n[0x12] = d;
        *(u32*)(n + 0x14) = *(u32*)(p + 4) - (size + 0x10);
        n += 0x10;
        *(u32*)(p + 4) = size;
    }
    return n;
}

extern "C" u8* fn_8015C57C(u8* p, u32 size, u8 a, u8 b, u8 c, u8 flags) {
    u8* n = 0;
    if (*(u32*)(p + 4) >= size + 0x10) {
        n = p + *(u32*)(p + 4) - size;
        n[3] = c;
        n[2] = flags | 0x80;
        *(u32*)(n + 4) = size;
        p[3] = a;
        p[2] = b;
        *(u32*)(p + 4) -= size + 0x10;
    } else {
        p[3] = c;
        p[2] = 0x80;
    }
    return n;
}

extern "C" int fn_8015C5D4(void* node, void* list) {
    u8* next = *(u8**)((u8*)node + 0xc);
    u8* prev = *(u8**)((u8*)node + 0x8);
    if (prev == 0) {
        *(u8**)((u8*)list + 0x80) = next;
    } else {
        *(u8**)(prev + 0xc) = next;
    }
    if (next == 0) {
        *(u8**)((u8*)list + 0x84) = prev;
    } else {
        *(u8**)(next + 0x8) = prev;
    }
    fn_8015BC6C(list, node);
    return 0;
}

extern "C" void* fn_8015C634(u32 addr) {
    if (addr != 0) {
        u16* n = (u16*)(addr - 0x10);
        if (*n == 0x484d) {
            return n;
        }
    }
    return 0;
}

extern "C" void fn_8015C650(u8* p, u32* out, u32 id) {
    u8* e;
    u32 total;
    out[5] = id;
    if (id <= 0xff) {
        fn_801BE3A0(p + 0x18);
        total = 0;
        for (e = *(u8**)(p + 0x80); e != 0; e = *(u8**)(e + 0xc)) {
            if (e[3] == (u8)id) {
                total += *(u32*)(e + 4) + 0x10;
            }
        }
        fn_801BE47C(p + 0x18);
        out[0] = total;
    } else {
        out[0] = *(u32*)(p + 0x38) - fn_80159DE0(p);
    }
    total = 0;
    for (e = *(u8**)(p + 0x80); e != 0; e = *(u8**)(e + 0xc)) {
        if (id <= 0xff) {
            if (e[3] == id) {
                total += (u32)e * 3;
            }
        } else {
            total += (u32)e * 3;
        }
    }
    out[1] = total;
}

#pragma pop

#pragma pop
extern "C" BOOL fn_8015C744(void* p, u32* a, u32* b) {
    BOOL r = 1;
    if (a[1] != b[1]) {
        r = 0;
    }
    if (a[0] == b[0]) {
        return r;
    }
    return 0;
}

extern "C" s32 fn_8015C774(void) {
    return 0x45585048;
}

extern "C" u8 fn_8015C780(u8* p) {
    return p[0x6d];
}

extern "C" void* fn_8015C788(u32 size, void* heap, void* arg) {
    void* p;
    void* q;
    if (heap == NULL) {
        heap = lbl_802FF548;
    }
    if (size == 0xffffffff) {
        size = fn_80159E0C(heap, 0x10);
    }
    size &= ~0xf;
    if (size < 0x80) {
        return NULL;
    }
    p = fn_80159BE0(size, 0x10, heap);
    q = (u8*)p + 0x80;
    if (p == NULL) {
        return NULL;
    }
    return fn_8015C89C(p, q, size - 0x80, heap, arg);
}

extern "C" void fn_8015C83C(Unk8015AD64* p) {
    u32 iVar = *(u32*)(*(u32*)((u8*)p + 0x50) + 0xc);
    if (iVar != 0) {
        p->vf08(-1);
        fn_80159C6C(p, iVar);
    }
}

extern "C" void fn_80166FC4(void* a, void* b);
extern "C" void fn_80166B70(void* a, u32 b);
extern "C" void* fn_8015C89C(void* p, void* p2, u32 size, void* r6, void* r7) {
    fn_801598A4(p);
    *(void**)p = lbl_802977D0;
    *(u32*)((u8*)p + 0x6c) = *(u32*)((u8*)p + 0x38);
    *(u32*)((u8*)p + 0x70) = *(u32*)((u8*)p + 0x30);
    *(u32*)((u8*)p + 0x74) = *(u32*)((u8*)p + 0x34);
    *(u32*)((u8*)p + 0x78) = 0;
    return p;
}

extern void* lbl_802977D0[];
extern "C" void* fn_8015C8F8(void* p, s16 param_2) {
    if (p != nullptr) {
        *(void**)p = lbl_802977D0;
        fn_8015A530(p);
        fn_801599D0(p, 0);
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" int fn_8015C960(void* p) {
    u8* h;
    u32 size;
    u32 aligned;
    u8* self = (u8*)p;
    h = *(u8**)(*(u8**)(self + 0x50) + 0xc);
    if (h != nullptr) {
        fn_801BE3A0(self + 0x18);
        u32 end = *(u32*)(self + 0x30);
        size = end - (u32)self;
        aligned = (*(u32*)(self + 0x70) - end + 0x1f) & ~0x1f;
        size += aligned;
        if (fn_80159D5C(h, self, size) != -1) {
            *(u32*)(self + 0x6c) = 0;
            *(u32*)(self + 0x38) = aligned;
            *(u32*)(self + 0x34) = *(u32*)(self + 0x30) + *(u32*)(self + 0x38);
            *(u32*)(self + 0x70) = *(u32*)(self + 0x34);
            *(u32*)(self + 0x74) = *(u32*)(self + 0x34);
        }
        fn_801BE47C(self + 0x18);
        return size;
    }
    return -1;
}

extern "C" int fn_8015CA24(char* param_1, u32 param_2, s32 param_3) {
    int r;
    fn_801BE3A0(param_1 + 0x18);
    if (param_2 < 4) {
        param_2 = 4;
    }
    if (param_3 >= 0) {
        r = fn_8015CAD4(param_1, param_2, param_3 >= 4 ? param_3 : 4);
    } else {
        s32 n = 4;
        if (-param_3 >= 4) {
            n = -param_3;
        }
        r = fn_8015CBAC(param_1, param_2, n);
    }
    fn_801BE47C(param_1 + 0x18);
    return r;
}

extern char lbl_80297628[];
extern "C" int fn_8015CAD4(void* p, u32 size, s32 align) {
    u8* self = (u8*)p;
    int ret = 0;
    u32 n = (size + 3) & ~3;
    u32 cur = *(u32*)(self + 0x70);
    u32 aligned = ~(align - 1) & (align + cur - 1);
    u32 need = n + (aligned - cur);
    if (need <= *(u32*)(self + 0x6c)) {
        *(u32*)(self + 0x70) = cur + need;
        *(u32*)(self + 0x6c) -= need;
        ret = aligned;
    } else {
        fn_80124034(lbl_80297628);
        if (self[0x68] == 1 && lbl_802FF54C != 0) {
            ((void (*)(void*, u32, s32))lbl_802FF54C)(p, n, align);
        }
    }
    return ret;
}

extern "C" int fn_8015CBAC(void* p, u32 r4, s32 r5) {
    s32 iVar6 = r5;
    u32 uVar5 = 0;
    u32 uVar2 = (r4 + 3) & ~3;
    u32 iVar1 = *(u32*)((u8*)p + 0x74);
    u32 uVar3 = ~(iVar6 - 1) & iVar1 - uVar2;
    u32 uVar4 = iVar1 - uVar3;
    if (uVar4 <= *(u32*)((u8*)p + 0x6c)) {
        *(u32*)((u8*)p + 0x74) = iVar1 - uVar4;
        *(u32*)((u8*)p + 0x6c) = *(u32*)((u8*)p + 0x6c) - uVar4;
        uVar5 = uVar3;
    } else {
        fn_80124034(lbl_8029765C);
        if (*((u8*)p + 0x68) == 1 && lbl_802FF54C != 0) {
            ((void (*)(void*, u32, s32))lbl_802FF54C)(p, uVar2, iVar6);
        }
    }
    return uVar5;
}

extern "C" void fn_8015CC7C(void) {
    fn_80124034(lbl_80297690);
}

extern "C" void fn_8015CCA8(char* p) {
    fn_801BE3A0(p + 0x18);
    fn_80159CE0(p);
    *(int*)(p + 0x6c) = *(int*)(p + 0x38);
    *(int*)(p + 0x70) = *(int*)(p + 0x30);
    *(int*)(p + 0x74) = *(int*)(p + 0x34);
    *(int*)(p + 0x78) = 0;
    fn_801BE47C(p + 0x18);
}

extern "C" void fn_8015CD08(unsigned char* p) {
    unsigned char* q;
    unsigned int a;
    unsigned int b;
    fn_801BE3A0(p + 0x18);
    a = *(unsigned int*)(p + 0x34);
    b = *(unsigned int*)(p + 0x74);
    if (b != a) {
        fn_8015A48C(p);
    }
    *(unsigned int*)(p + 0x6c) += *(unsigned int*)(p + 0x34) - *(unsigned int*)(p + 0x74);
    *(unsigned int*)(p + 0x74) = *(unsigned int*)(p + 0x34);
    for (q = *(unsigned char**)(p + 0x78); q != 0; q = *(unsigned char**)(q + 0x10)) {
        *(unsigned int*)(q + 0xc) = *(unsigned int*)(p + 0x34);
    }
    fn_801BE47C(p + 0x18);
}

extern "C" void fn_8015CD94(void) {
}

extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_8015A48C(void*);
extern "C" void fn_80124034(const char* fmt, ...);
extern char lbl_802976B8[];
extern char lbl_80297718[];
extern "C" int fn_8015CD98(void) {
    fn_80124034(lbl_802976B8);
    return -1;
}

extern char lbl_802976E8[];
extern "C" int fn_8015CDC8(void) {
    fn_80124034(lbl_802976E8);
    return -1;
}

extern "C" int fn_8015CDF8(unsigned char* p) {
    int result;
    fn_801BE3A0(p + 0x18);
    result = 1;
    if (*(unsigned int*)(p + 0x6c) + (*(unsigned int*)(p + 0x70) - *(unsigned int*)(p + 0x30)) + (*(unsigned int*)(p + 0x34) - *(unsigned int*)(p + 0x74)) != *(unsigned int*)(p + 0x38)) {
        result = 0;
        fn_80124034(lbl_80297718);
    }
    fn_801BE47C(p + 0x18);
    return result;
}

extern "C" void fn_8015CF88(void* p, u32* r4, u32 r5) {
    r4[5] = r5;
    u32 n = fn_80159DE0(p);
    r4[0] = *(u32*)((u8*)p + 0x38) - n;
    u32 t = *(u32*)((u8*)p + 0x70);
    t += *(u32*)((u8*)p + 0x74) * 3;
    r4[1] = t;
}

extern "C" BOOL fn_8015CFE4(void* p, u32* a, u32* b) {
    BOOL r = 1;
    if (a[1] != b[1]) {
        r = 0;
    }
    if (a[0] == b[0]) {
        return r;
    }
    return 0;
}

extern "C" u32 fn_8015D014(void)
{
    return 0x534C4944;
}

extern "C" u32 fn_8015D020(u8* p) {
    return *(u32*)(p + 0x6c);
}

extern "C" u32 fn_8015D028(u8* p) {
    return *(u32*)(p + 0x70);
}

extern "C" void fn_8015D030(void) {
    fn_80159DB4();
}

extern "C" void* fn_8015D050(void* p) {
    *(void**)p = lbl_8029783C;
    fn_80166B58((u8*)p + 0x8, p);
    *(u32*)((u8*)p + 0x4) = (u32)fn_80159E8C(p);
    if (*(u32*)((u8*)p + 0x4) != 0) {
        fn_80166C84(*(u8**)((u8*)p + 0x4) + 0x5c, (void*)((u32)p + 0x8));
    }
    return p;
}

extern "C" void* fn_8015D0B8(void* p, s16 param_2) {
    if (p != nullptr) {
        *(void**)p = lbl_8029783C;
        if (*(void**)((u8*)p + 0x4) != 0) {
            fn_80166FC4(*(u8**)((u8*)p + 0x4) + 0x5c, (u8*)p + 0x8);
        }
        if ((s32)p + 0x8 != 0) {
            fn_80166B70((u8*)p + 0x8, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void* fn_8015D13C(void* p, u32 a2, u32 a3, u32 a4) {
    u32 ret;
    fn_8015D050(p);
    *(void**)p = lbl_802979B8;
    fn_80166B58((u8*)p + 0x18, p);
    *(u32*)((u8*)p + 0x68) = 0;
    *(u32*)((u8*)p + 0x64) = 0;
    *(u32*)((u8*)p + 0x6c) = 0;
    *(u8*)((u8*)p + 0x60) = 0;
    *(u32*)((u8*)p + 0x70) = 0;
    ret = (u32)fn_80159E8C(p);
    if (ret == 0) {
        ret = lbl_802FF540;
    }
    fn_8015D3E4(p, ret, a2, a4);
    fn_8015D374((u8*)p, *(void**)((u8*)p + 0x28), a3);
    return p;
}

extern "C" void* fn_8015D1F4(void* p, u8* a2, u32 a3) {
    fn_8015D050(p);
    *(void**)p = lbl_802979B8;
    fn_80166B58((u8*)p + 0x18, p);
    *(u32*)((u8*)p + 0x68) = 0;
    *(u32*)((u8*)p + 0x64) = 0;
    *(u32*)((u8*)p + 0x6c) = 0;
    *(u8*)((u8*)p + 0x60) = 0;
    *(u32*)((u8*)p + 0x70) = 0;
    *(u32*)((u8*)p + 0x28) = 0;
    *(u8**)((u8*)p + 0x2c) = a2;
    *(u32*)((u8*)p + 0x5c) = *(u32*)(a2 + 0x308) - *(u32*)(a2 + 0x304);
    *(u32*)((u8*)p + 0x58) = *(u32*)(a2 + 0x304);
    fn_8015D374((u8*)p, (void*)lbl_802FF540, a3);
    return p;
}

extern "C" void* fn_8015D29C(void* p, s16 param_2) {
    s16 sVar1 = param_2;
    void* pvVar1 = p;
    if (pvVar1 != 0) {
        *(void**)pvVar1 = lbl_802979B8;
        fn_80166FC4(lbl_802EE20C, (u8*)pvVar1 + 0x18);
        if (*(u32*)((u8*)pvVar1 + 0x28) != 0) {
            if (fn_801C0288(*(void**)((u8*)pvVar1 + 0x2c)) == 0) {
                fn_801C0E4C(*(void**)((u8*)pvVar1 + 0x2c));
                OSCancelThread(*(void**)((u8*)pvVar1 + 0x2c));
            }
            fn_80159C6C(*(void**)((u8*)pvVar1 + 0x58), *(s32*)((u8*)pvVar1 + 0x28));
            fn_80159C6C(*(void**)((u8*)pvVar1 + 0x2c), *(s32*)((u8*)pvVar1 + 0x28));
            fn_80159C6C(*(void**)((u8*)pvVar1 + 0x50), 0);
        }
        if ((u32)pvVar1 + 0x18 != 0) {
            fn_80166B70((u8*)pvVar1 + 0x18, 0);
        }
        fn_8015D0B8(pvVar1, 0);
        if (sVar1 > 0) {
            fn_8015AB1C(pvVar1);
        }
    }
    return pvVar1;
}

extern "C" void fn_8015D374(u8* p, void* r4, u32 r5) {
    *(u32*)(p + 0x54) = r5;
    *(void**)(p + 0x50) = fn_80159BE0(*(u32*)(p + 0x54) << 2, 0, r4);
    fn_801BDDBC(p + 0x30, *(void**)(p + 0x50), *(u32*)(p + 0x54));
    fn_80166C84(lbl_802EE20C, p + 0x18);
    *(u32*)(p + 0x74) = 0;
    *(u32*)(p + 0x78) = 0;
}

extern "C" void fn_8015D3E4(void* p, u32 a, u32 b, u32 c) {
    *(u32*)((u8*)p + 0x28) = a;
    *(u32*)((u8*)p + 0x5c) = b & ~0x1f;
    *(void**)((u8*)p + 0x58) = fn_80159BE0(*(u32*)((u8*)p + 0x5c), 0x20, *(void**)((u8*)p + 0x28));
    *(void**)((u8*)p + 0x2c) = fn_80159BE0(0x318, 0x20, *(void**)((u8*)p + 0x28));
    fn_801C0884(*(void**)((u8*)p + 0x2c), (void*)fn_8015D474, p, (void*)(*(u32*)((u8*)p + 0x58) + *(u32*)((u8*)p + 0x5c)), *(u32*)((u8*)p + 0x5c), c, 1);
}

extern "C" void fn_8015D474(VObj_80088CF8* obj) {
    obj->m1();
}

extern "C" void fn_801C00A0(void (*fn)(void));
extern "C" void fn_8015D544(void);
extern u32 lbl_802FF584;
extern u32 lbl_802FF588;
extern u32 lbl_802FF590;
extern u32 lbl_802FF594;
extern "C" void* fn_8015D4A0(void* heap) {
    u32* p;
    if (heap == 0) {
        heap = (void*)lbl_802FF544;
    }
    p = (u32*)fn_8015A9A8(0x28, heap, 0);
    if (p != 0) {
        p[0] = (u32)lbl_8029796C;
        p[1] = (u32)heap;
        fn_801C00A0(fn_8015D544);
        p[3] = 0;
        p[4] = 1;
        p[7] = 0;
        p[6] = 0;
        lbl_802FF588 = 0;
        lbl_802FF594 = 0;
        lbl_802FF590 = 0;
        p[8] = 0;
        p[9] = 0;
        *(u8*)(p + 2) = 1;
    }
    lbl_802FF584 = (u32)p;
    return p;
}

extern "C" void fn_801BDEE4(void* p, void* out, u32 count);
extern "C" void fn_801BDE1C(u32 a, void* b, u32 c);
extern "C" void fn_8015D978(u8* p) {
    u32* ev;
    OSInitFastCast();
    for (;;) {
        fn_801BDEE4(p + 0x30, &ev, 1);
        if (ev[0] != 0) {
            ((void (*)(u32))ev[0])(ev[1]);
            if (*(u32*)(p + 0x94) != 0) {
                fn_801BDE1C(*(u32*)(p + 0x94), (void*)ev[2], 0);
            }
        }
        ev[0] = 0;
    }
}

extern "C" int fn_8015DA14()
{
	return 0;
}

extern "C" void fn_8015DA1C(void* self, int a) {
    struct VObj_8015DA1C {
        virtual void m0(int, int);
    };
    ((VObj_8015DA1C*)self)->m0(a, 0);
}

extern "C" void* fn_8015DA4C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029796C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8015DA94(void)
{
}

extern "C" void* fn_8015DA98(void* p, s16 param_2) {
    if (p != 0) {
        *(void**)p = lbl_802979A4;
        lbl_802FF580 = 0;
        if (p != 0) {
            *(void**)p = lbl_802979B8;
            fn_80166FC4(lbl_802EE20C, (u8*)p + 0x18);
            if (*(u32*)((u8*)p + 0x28) != 0) {
                if (fn_801C0288(*(void**)((u8*)p + 0x2c)) == 0) {
                    fn_801C0E4C(*(void**)((u8*)p + 0x2c));
                    OSCancelThread(*(void**)((u8*)p + 0x2c));
                }
                fn_80159C6C(*(void**)((u8*)p + 0x58), *(s32*)((u8*)p + 0x28));
                fn_80159C6C(*(void**)((u8*)p + 0x2c), *(s32*)((u8*)p + 0x28));
            }
            fn_80159C6C(*(void**)((u8*)p + 0x50), 0);
            if ((u32)p + 0x18 != 0) {
                fn_80166B70((u8*)p + 0x18, 0);
            }
            fn_8015D0B8(p, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_8015DB88(void) {
    while (1) {
    }
}
