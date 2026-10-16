#include "types.h"
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
extern "C" void* fn_80159BE0(u32 size, u32 align, void* p) {
    if (p != 0) {
        return fn_80159C40(p, size, align);
    }
    if (lbl_802FF544 != 0) {
        return fn_80159C40((void*)lbl_802FF544, size, align);
    }
    return 0;
}

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

extern "C" void fn_80159D5C(void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14();
    };
    ((Obj*)p)->v12();
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

extern "C" void fn_80159DE0(void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
        virtual void v16();
    };
    ((Obj*)p)->v16();
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

extern "C" int fn_8015A9A8(int a, void* p) {
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

extern "C" void* fn_8015C634(u32);
extern "C" void fn_8015C5D4(void*, void*);
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

extern "C" void fn_8015D030(void) {
    fn_80159DB4();
}

extern "C" void fn_8015D474(VObj_80088CF8* obj) {
    obj->m1();
}

extern "C" int fn_8015DA14()
{
	return 0;
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
