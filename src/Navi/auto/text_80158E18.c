#include "types.h"
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

extern "C" void fn_80159CB4(VObj_8003B920* obj) {
    obj->m8();
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
