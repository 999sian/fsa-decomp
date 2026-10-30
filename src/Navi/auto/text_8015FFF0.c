#include "types.h"
extern "C" int fn_801E6578(void* a, void* b);
extern "C" void* lbl_802FF5F8;
extern void* lbl_802FF5F0;
extern "C" void* fn_801611A8(void*, char*, void*);
extern "C" void* fn_801615C4(void);
extern "C" void fn_80159C6C(void*, int);
extern "C" void* fn_80160D88(void*, char*, void*);
extern "C" int fn_801C7D34(void*);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void fn_8011C9EC(const char*, int, const char*, ...);
extern "C" char lbl_802EE2EC[];
extern "C" char lbl_802EE2D4[];
extern "C" char lbl_802981A8[];
extern "C" char lbl_802981B8[];
extern "C" char lbl_802FE368[4];
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_801BDE1C(void*, void*, int);
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015fff0-0x80164978 (90 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8015FC80(void*, int);
extern char lbl_80297CE8[];
extern char lbl_80298208[];
extern "C" void fn_80166C08(void*, int);
extern "C" s32 fn_80166680(void* a, void* b, u32 c, u32 d);
extern "C" void fn_80161678(u16* p, void* s);
extern "C" void* fn_8015FFF0(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80160044(void* self, void* obj, void* start, u16 count) {
    extern char lbl_80297C8C[];
    extern char lbl_80297C7C[];
    struct Obj {
        virtual void v0(); virtual void v1();
    };
    u8* p = (u8*)self;
    *(void**)(p + 0xc) = lbl_80297C8C;
    *(u8*)(p + 0x10) = 0;
    *(u8*)(p + 0x11) = 0;
    *(void**)(p + 0xc) = lbl_80297C7C;
    *(void**)(p + 0x14) = obj;
    *(u8*)(p + 0x10) = (s32)count > 0;
    *(s32*)(p + 0x18) = (s32)start;
    *(s32*)(p + 0x1c) = (s32)start + count - 1;
    *(s32*)(p + 0x20) = *(s32*)(p + 0x18);
    ((Obj*)(p + 0xc))->v1();
    return self;
}

extern "C" u8 fn_801604EC(void*, void*, s32);
extern "C" u8 fn_801600D0(u8* p) {
    struct Entry {
        u8 type;
        u8 pad;
        u16 id;
        u32 offset;
    } e;
    if (*(u8*)(p + 0x10) != 0) {
        *(u8*)(p + 0x10) = *(s32*)(p + 0x20) <= *(s32*)(p + 0x1c);
        if (*(u8*)(p + 0x10) != 0) {
            *(u8*)(p + 0x10) = fn_801604EC(*(void**)(p + 0x14), &e, *(s32*)(p + 0x20));
            *(u32*)(p + 0x0) = e.offset;
            *(s32*)(p + 0x4) = *(s32*)(p + 0x20);
            *(u16*)(p + 0x8) = e.id;
            *(u16*)(p + 0xa) = e.type;
            *(u8*)(p + 0x11) = (*(u16*)(p + 0xa) >> 1) & 1;
            (*(s32*)(p + 0x20))++;
        }
    }
    return *(u8*)(p + 0x10);
}

extern char lbl_80297C8C[];
extern "C" void* fn_8016017C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)((u8*)param_1 + 0xc) = (void*)lbl_80297C8C;
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_801601C4(void* ptr, s16 param_2) {
    extern char lbl_80297C8C[];
    extern char lbl_80297C7C[];
    if (ptr != nullptr) {
        *(void**)((u8*)ptr + 0xc) = lbl_80297C7C;
        if (ptr != nullptr) {
            *(void**)((u8*)ptr + 0xc) = lbl_80297C8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80160220(s32 id, void* owner) {
    extern void* lbl_802FF544;
    void** node;
    u8* p;
    if (owner == 0) {
        owner = lbl_802FF544;
    }
    for (node = *(void***)lbl_802EE2D4; node != 0; node = (void**)node[3]) {
        p = (u8*)node[0];
        if (*(u32*)(p + 0x2c) == 0x52415243 && *(s32*)(p + 0x40) == id && *(void**)(p + 0x38) == owner) {
            (*(s32*)(p + 0x34))++;
            return p;
        }
    }
    return 0;
}

extern "C" BOOL fn_80160464(void* self, char* p) {
    void* r;
    BOOL found;
    if (*p == '/') {
        p++;
        if (*p == 0) {
            p = NULL;
        }
        r = fn_80160D88(self, p, 0);
    } else {
        r = fn_80160D88(self, p, lbl_802FF5F8);
    }
    found = r != NULL;
    if (found) {
        lbl_802FF5F0 = self;
        lbl_802FF5F8 = (void*)(((s32)r - *(s32*)((u8*)self + 0x48)) / 16);
    }
    return found;
}

extern "C" int fn_80160564(void* a, void* b, void* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual int v18(void* a, void* b);
        u8 pad[0x28];
        u32 m2c;
    };
    int ret = 0;
    void** node;
    if (p != 0) {
        return ((Obj*)p)->v18(a, b);
    }
    for (node = *(void***)lbl_802EE2D4; node != 0; node = (void**)node[3]) {
        Obj* o = (Obj*)node[0];
        if (o->m2c == 0x52415243) {
            ret = o->v18(a, b);
            if (ret != 0) {
                break;
            }
        }
    }
    return ret;
}

extern "C" int fn_8016061C(void* a, char* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual int v40(void*, int);
    };
    extern void* lbl_802FF5F8;
    extern void* fn_801611A8(void*, char*, void*);
    Obj* o = (Obj*)a;
    void* r;
    if (*p == '/') {
        r = fn_801611A8(o, p + 1, 0);
    } else {
        r = fn_801611A8(o, p, lbl_802FF5F8);
    }
    if (r != 0) {
        return o->v40(r, 0);
    }
    return 0;
}

extern "C" void* fn_80161518(void*, void*);
extern "C" void* fn_801610AC(void*, u32, void*);
extern "C" int fn_80160698(void* self, u32 id, void* name) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual int v40(void* r, int b);
    };
    void* r;
    if (id == 0 || id == 0x3f3f3f3f) {
        r = fn_80161518(self, name);
    } else {
        r = fn_801610AC(self, id, name);
    }
    if (r != 0) {
        return ((Obj*)self)->v40(r, 0);
    }
    return 0;
}

extern "C" void* fn_801614F0(void*);
extern "C" int fn_80160718(void* self) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual int v40(void* r, int b);
    };
    void* r = fn_801614F0(self);
    if (r != 0) {
        return ((Obj*)self)->v40(r, 0);
    }
    return 0;
}

extern "C" void* fn_801615F8(void*);
extern "C" int fn_8016076C(void* self) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual int v40(void* r, int b);
    };
    void* r = fn_801615F8(self);
    if (r != 0) {
        return ((Obj*)self)->v40(r, 0);
    }
    return 0;
}

extern "C" int fn_801607C0(void* self, void* a, void* b, u32 id, void* name) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual int v40(void* r, int b);
        virtual void v44(void* a, void* b, void* r, int* out);
    };
    void* r;
    int out;
    if (id == 0 || id == 0x3f3f3f3f) {
        r = fn_80161518(self, name);
    } else {
        r = fn_801610AC(self, id, name);
    }
    if (r != 0) {
        ((Obj*)self)->v44(a, b, r, &out);
        return out;
    }
    return 0;
}

extern "C" int fn_8016086C(void* self, void* a, void* b, char* p) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
        virtual void v12(); virtual void v13();
        virtual int v40(void* r, int b);
        virtual void v44(void* a, void* b, void* r, int* out);
    };
    void* r;
    int out;
    if (*p == '/') {
        r = fn_801611A8(self, p + 1, 0);
    } else {
        r = fn_801611A8(self, p, lbl_802FF5F8);
    }
    if (r != 0) {
        ((Obj*)self)->v44(a, b, r, &out);
        return out;
    }
    return 0;
}

extern "C" void fn_80160910(u8* p) {
    if (*(void**)(p + 0x44) != NULL && p[0x3c] != 1) {
        u8* entry = *(u8**)(p + 0x4c);
        for (u32 i = 0; i < *(u32*)(*(u8**)(p + 0x44) + 8); i++) {
            if (*(void**)(entry + 0x10) != NULL) {
                fn_80159C6C(*(void**)(entry + 0x10), *(s32*)(p + 0x38));
                *(void**)(entry + 0x10) = NULL;
            }
            entry += 0x14;
        }
    }
}

extern "C" BOOL fn_801609A8(u8* a, void* b) {
    u8* p = (u8*)fn_801615C4();
    if (p == NULL) {
        return 0;
    }
    *(u32*)(p + 0x10) = 0;
    fn_80159C6C(b, *(s32*)(a + 0x38));
    return 1;
}

extern "C" void* fn_801615C4(void);
extern "C" void fn_80159C6C(void*, int);
extern "C" void* fn_80160D88(void*, char*, void*);
extern "C" void* lbl_802FF5F8;
extern "C" BOOL fn_80160A08(void) {
    u8* p = (u8*)fn_801615C4();
    if (p == NULL) {
        return 0;
    }
    *(u32*)(p + 0x10) = 0;
    return 1;
}

extern "C" s32 fn_80160A44(void) {
    u8* p = (u8*)fn_801615C4();
    if (p == NULL) {
        return -1;
    }
    return *(s32*)(p + 0xc);
}

extern "C" u16 fn_80160A78(void* a, char* p) {
    u8* r;
    if (p[0] == '/') {
        if (*++p == 0) {
            p = NULL;
        }
        r = (u8*)fn_80160D88(a, p, 0);
    } else {
        r = (u8*)fn_80160D88(a, p, lbl_802FF5F8);
    }
    if (r != NULL) {
        return *(u16*)(r + 0xa);
    }
    return 0;
}

extern "C" void* fn_80159E8C(void* ptr);
extern "C" void* fn_80160044(void*, void*, void*, u16);
extern "C" void* fn_8015A9A8(int, void*, int);
extern void* lbl_802FF544;
extern void* lbl_802FF540;
extern void* lbl_802FF5F0;
#pragma dont_inline on
extern "C" u32 fn_80160AD8(void* self, char* p) {
    u8* r;
    void* obj;
    u32 ret;
    if (*p == '/') {
        p++;
        if (*p == 0) {
            p = NULL;
        }
        r = (u8*)fn_80160D88(self, p, 0);
    } else {
        r = (u8*)fn_80160D88(self, p, lbl_802FF5F8);
    }
    if (r != NULL) {
        obj = fn_8015A9A8(0x24, lbl_802FF540, 0);
        if (obj != NULL) {
            ret = (u32)fn_80160044(obj, self, *(void**)(r + 0xc), *(u16*)(r + 0xa));
            return ret;
        }
    }
    return 0;
}
#pragma dont_inline reset
extern "C" void fn_8015FC28(void*);
extern "C" u32 fn_80160B84(void* self) {
    u32* r = (u32*)fn_801614F0(self);
    if (r != 0) {
        return r[1] >> 24;
    }
    return 0;
}

extern "C" void fn_80160BBC(void* self) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual void v10();
    };
    ((Obj*)self)->v10();
}

extern "C" void* fn_80160BE8(void* self) {
    fn_8015FC28(self);
    *(void**)self = lbl_80297CE8;
    *((u8*)self + 0x30) = 0;
    *(s32*)((u8*)self + 0x60) = 1;
    return self;
}

#pragma dont_inline on
extern "C" void* fn_80160C34(void* self, void* a, int b) {
    fn_8015FC28(self);
    *(void**)self = lbl_80297CE8;
    *((u8*)self + 0x30) = 0;
    *((u8*)self + 0x3c) = b;
    *(s32*)((u8*)self + 0x34) = 1;
    *(s32*)((u8*)self + 0x58) = 1;
    *(void**)((u8*)self + 0x38) = fn_80159E8C(self);
    if (*(void**)((u8*)self + 0x38) == NULL) {
        *(void**)((u8*)self + 0x38) = lbl_802FF544;
    }
    *(void**)((u8*)self + 0x40) = a;
    if (lbl_802FF5F0 == NULL) {
        lbl_802FF5F0 = self;
        lbl_802FF5F8 = NULL;
    }
    return self;
}
#pragma dont_inline reset

#pragma dont_inline on
extern "C" void* fn_80160CDC(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297CE8;
        fn_8015FC80(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" u32 fn_80160D3C(void* self, u16* p, u32 off, u16 id) {
    if (*p != id) {
        return 0;
    }
    return fn_801E6578((u8*)(*(u32*)((u8*)self + 0x54)) + off, p + 2) == 0;
}

extern "C" void* fn_801610AC(void* p, u32 key, void* name) {
    u16 buf[2];
    u8 tmp[0x124];
    u8* e;
    u8* a;
    u8* base;
    s32 i;
    u32 n;
    u32 off;
    if (key != 0) {
        fn_80161678(buf, name);
        n = **(u32**)((u8*)p + 0x44);
        e = *(u8**)((u8*)p + 0x48);
        while (n != 0) {
            if (*(u32*)e == key) {
                break;
            }
            e += 0x10;
            n--;
        }
        if (n == 0) {
            e = NULL;
        }
        if (e != NULL) {
            a = *(u8**)((u8*)p + 0x4c) + *(u32*)(e + 0xc) * 0x14;
            base = *(u8**)((u8*)p + 0x54);
            for (i = 0; i < *(u16*)(e + 0xa); i++) {
                off = *(u32*)(a + 4) & 0xffffff;
                if (buf[0] != *(u16*)(a + 2)) {
                    off = 0;
                }
                if (fn_801E6578(base + off, tmp) == 0) {
                    return a;
                }
                a += 0x14;
            }
        }
    }
    return NULL;
}

#pragma dont_inline reset

extern "C" void fn_80161678(u16* p, void* s);
extern "C" int fn_801E6578(void* a, void* b);
extern "C" int fn_801E30E8(int c);
#pragma use_lmw_stmw off
extern "C" void* fn_80161518(void* self, void* name) {
    u8* table;
    u8* base;
    char* buf;
    u8* entry;
    u32 i;
    u16 hash[2];
    char tmp[256];
    entry = *(u8**)((u8*)self + 0x4c);
    fn_80161678(hash, name);
    buf = tmp;
    base = *(u8**)((u8*)self + 0x54);
    table = *(u8**)((u8*)self + 0x44);
    for (i = 0; i < *(u32*)(table + 8); i++) {
        u32 off = *(u32*)(entry + 4) & 0xffffff;
        u8 ok;
        if (hash[0] != *(u16*)(entry + 2)) {
            ok = 0;
        } else {
            ok = fn_801E6578(base + off, buf) == 0;
        }
        if (ok) {
            return entry;
        }
        entry += 0x14;
    }
    return 0;
}

#pragma dont_inline on
#pragma use_lmw_stmw off
extern "C" char* fn_80161710(u16* p, char* s, s8 term) {
    s32 i = 0;
    s32 v;
    p[0] = 0;
    while (*s != 0 && *s != term) {
        v = fn_801E30E8(*s);
        p[0] = v + p[0] * 3;
        if (i < 0x100) {
            ((u8*)p)[i++ + 4] = v;
        }
        s++;
    }
    p[1] = i;
    ((u8*)p + i)[4] = 0;
    if (*s != 0) {
        return s + 1;
    }
    return 0;
}
#pragma use_lmw_stmw reset
#pragma dont_inline reset

extern "C" char lbl_80297EF0[];
extern "C" char fn_801621C0(void* p, void* a);
extern "C" void fn_801617D8(u8* p, s32 a, void* v) {
    s32 idx = (a - *(s32*)(p + 0x4c)) / 20;
    void** arr = *(void***)(p + 0x50);
    if (arr == 0) {
        return;
    }
    if ((u32)idx < *(u32*)(*(u8**)(p + 0x44) + 8)) {
        arr[idx] = v;
    } else {
        return;
    }
}

extern "C" void* fn_80161824(u8* p, s32 a) {
    s32 idx = (a - *(s32*)(p + 0x4c)) / 20;
    void** arr = *(void***)(p + 0x50);
    if (arr == 0 || (u32)idx >= *(u32*)(*(u8**)(p + 0x44) + 8)) {
        return 0;
    }
    return arr[idx];
}

#pragma use_lmw_stmw reset
extern "C" void* fn_80160C34(void*, void*, int);
extern "C" u8 fn_80161A2C(void*, void*, void*);
extern "C" void fn_80166D3C(void*, void*);
extern "C" char lbl_80297DD4[];
extern "C" char lbl_802EE2D4[];
extern "C" char* fn_80161710(u16* p, char* s, s8 term);
extern "C" void* fn_80161874(void* a, char** b, s8 term) {
    *b = fn_80161710((u16*)a, *b, term);
    return a;
}

extern "C" int fn_801618B8(int p) { return p + 4; }

extern "C" u16 fn_801618C0(u16* p) { return *p; }

extern "C" u8* fn_801618C8(u8* p, void* a, void* b) {
    fn_80160C34(p, a, 1);
    *(void**)p = lbl_80297DD4;
    p[0x30] = 0;
    *(void**)(p + 0x60) = b;
    if (!fn_80161A2C(p, a, *(void**)(p + 0x60))) {
        return p;
    }
    *(u32*)(p + 0x2c) = 0x52415243;
    *(int*)(p + 0x28) = *(int*)(p + 0x54) + *(int*)(*(u8**)(p + 0x48) + 4);
    fn_80166D3C(lbl_802EE2D4, p + 0x18);
    p[0x30] = 1;
    return p;
}

extern "C" void* fn_80161984(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297DD4;
        if (*((u8*)param_1 + 0x30) == 1) {
            if (*((u8*)param_1 + 0x6c) != 0 && *(void**)((u8*)param_1 + 0x64) != nullptr) {
                fn_80159C6C(*(void**)((u8*)param_1 + 0x64), *(int*)((u8*)param_1 + 0x38));
            }
            fn_80166FC4(lbl_802EE2D4, (u8*)param_1 + 0x18);
            *((u8*)param_1 + 0x30) = 0;
        }
        fn_80160CDC(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" u32 fn_80161B94(u8* a, u8* b, u32* out) {
    if (*(u32*)(b + 0x10) == 0) {
        *(u32*)(b + 0x10) = *(u32*)(a + 0x68) + *(u32*)(b + 0x8);
    }
    if (out != NULL) {
        *out = *(u32*)(b + 0xc);
    }
    return *(u32*)(b + 0x10);
}

extern "C" void* memcpy(void* dst, const void* src, u32 n);
extern "C" u32 fn_80161D1C(u8* src, u32 n, void* dst, u32 size, s32 mode);
extern "C" void* fn_80161BC8(u8* p, void* dst, u32 size, u8* e, u32* out) {
    u32 n;
    s32 mode;
    n = *(u32*)(e + 0xc);
    if (n > size) {
        n = size;
    }
    if (*(void**)(e + 0x10) != 0) {
        memcpy(dst, *(void**)(e + 0x10), n);
    } else {
        u32 f = *(u32*)(e + 4) >> 24;
        if (!(f & 4)) {
            mode = 0;
        } else if (f & 0x80) {
            mode = 2;
        } else {
            mode = 1;
        }
        n = fn_80161D1C(*(u8**)(p + 0x68) + *(u32*)(e + 8), n, dst, size, mode);
    }
    if (out != 0) {
        *out = n;
    }
    return dst;
}

extern "C" void fn_80161C90(u8* p) {
    u8* x;
    u32 i;
    if (*(u32*)(p + 0x44) == 0) {
        return;
    }
    if (p[0x3c] == 1) {
        return;
    }
    x = *(u8**)(p + 0x4c);
    for (i = 0; i < *(u32*)(*(u8**)(p + 0x44) + 0x8); i++) {
        if (*(u32*)(x + 0x10) != 0) {
            *(u32*)(x + 0x10) = 0;
        }
    }
}

extern "C" BOOL fn_80161CE0(void) {
    u8* p = (u8*)fn_801615C4();
    if (p == NULL) {
        return 0;
    }
    *(u32*)(p + 0x10) = 0;
    return 1;
}

extern char lbl_80297D38[];
extern char lbl_80297D4C[];
extern "C" u32 fn_80161D1C(u8* src, u32 n, void* dst, u32 size, s32 mode) {
    switch (mode) {
    case 0:
        if (n > size) {
            n = size;
        }
        memcpy(dst, src, n);
        return n;
    case 1:
    case 2: {
        u32 len = (u32)src[4] << 24 | (u32)src[5] << 16 | (u32)src[6] << 8 | src[7];
        n = len;
        if (len > size) {
            n = size;
        }
        fn_80166680(src, dst, n, 0);
        return n;
    }
    default:
        fn_8011C9EC(lbl_80297D38, 0x2d3, "%s", lbl_80297D4C);
        return 0;
    }
}

extern "C" u32 fn_80161DF4(void* param_1, u8* param_2) {
    struct Obj {
        virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
        virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
        virtual void v8(); virtual void v9(); virtual u32 v10(u8* b);
    };
    u8* p = (u8*)fn_801615C4();
    if (p == NULL) {
        return -1;
    }
    if (((*(u32*)(p + 0x4)) >> 24 & 4) == 0) {
        return ((Obj*)param_1)->v10(param_2);
    }
    return (u32)param_2[4] << 24 | (u32)param_2[5] << 16 | (u32)param_2[6] << 8 | (u32)param_2[7];
}

extern "C" void fn_8015E1F4(void* p, u32 a, u32 b, s32 flag, u32 c, s32 zero, s32 neg, u32* out);
extern "C" char lbl_80297E28[];
extern "C" char lbl_80297E3C[];
#pragma dont_inline on
extern "C" void* fn_80160BE8(void* self);
extern "C" char lbl_802FE2E0[];
extern "C" void* fn_80161E84(void* self) {
    fn_80160BE8(self);
    *(void**)self = lbl_80297EF0;
    return self;
}
#pragma dont_inline reset
extern "C" u8* fn_80161EC0(u8* p, void* a, void* b) {
    u8 ok;
    fn_80160C34(p, a, 2);
    *(void**)p = lbl_80297EF0;
    *(void**)(p + 0x60) = b;
    ok = fn_801621C0(p, a);
    if (!ok) {
        return p;
    }
    *(u32*)(p + 0x2c) = 0x52415243;
    *(int*)(p + 0x28) = *(int*)(p + 0x54) + *(int*)(*(u8**)(p + 0x48) + 4);
    fn_80166D3C(lbl_802EE2D4, p + 0x18);
    p[0x30] = 1;
    return p;
}

#pragma dont_inline on
extern "C" int fn_801620C0(u8* p, s32 a, void* b) {
    if (a < 0) {
        return 0;
    }
    if (fn_80160220(a, lbl_802FF544) != NULL) {
        return 0;
    }
    p[0x30] = 0;
    *(void**)(p + 0x60) = b;
    p[0x3c] = 2;
    *(s32*)(p + 0x34) = 1;
    *(s32*)(p + 0x58) = 2;
    *(void**)(p + 0x38) = lbl_802FF544;
    *(s32*)(p + 0x40) = a;
    if (lbl_802FF5F0 == NULL) {
        lbl_802FF5F0 = p;
        lbl_802FF5F8 = NULL;
    }
    u8 ok = fn_801621C0(p, (void*)a);
    if (ok == 0) {
        return 0;
    }
    *(u32*)(p + 0x2c) = 0x52415243;
    *(int*)(p + 0x28) = *(int*)(p + 0x54) + *(int*)(*(u8**)(p + 0x48) + 4);
    fn_80166D3C(lbl_802EE2D4, p + 0x18);
    p[0x30] = 1;
    return 1;
}
#pragma dont_inline reset
extern "C" s32 fn_80162724(void* p, u32 a, u32 b, u32 c, s32 mode) {
    u32 out;
    u32 w;
    u32 h;
    h = c & ~0x1f;
    w = (a + 0x1f) & ~0x1f;
    switch (mode) {
    case 0:
        if (w > h) {
            w = h;
        }
        fn_8015E1F4(p, b, w, 0, h, 0, -1, &out);
        return out;
    case 1:
    case 2:
        fn_8015E1F4(p, b, w, 1, h, 0, -1, &out);
        return out;
    default:
        fn_8011C9EC(lbl_80297E28, 0x28f, "%s", lbl_80297E3C);
        return 0;
    }
}

extern "C" void fn_8015D0B8(void*, int);
extern char lbl_80297E68[];
extern "C" void* fn_80162A70(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297E68;
        fn_8015D0B8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" u8 fn_80162CAC(void*, void*);
extern "C" char lbl_80298054[];
extern "C" u8* fn_80162AD0(u8* p, void* a, void* b) {
    u8 ok;
    fn_80160C34(p, a, 3);
    *(void**)p = lbl_80298054;
    *(void**)(p + 0x60) = b;
    ok = fn_80162CAC(p, a);
    if (!ok) {
        return p;
    }
    *(u32*)(p + 0x2c) = 0x52415243;
    *(int*)(p + 0x28) = *(int*)(p + 0x54) + *(int*)(*(u8**)(p + 0x48) + 4);
    fn_80166D3C(lbl_802EE2D4, p + 0x18);
    p[0x30] = 1;
    return p;
}

extern "C" u8 fn_801638F8(void*, void*);
extern "C" char lbl_80298158[];
extern "C" u8* fn_801636F8(u8* p, void* a, void* b) {
    u8 ok;
    fn_80160C34(p, a, 4);
    *(void**)p = lbl_80298158;
    *(void**)(p + 0x60) = b;
    ok = fn_801638F8(p, a);
    if (!ok) {
        return p;
    }
    *(u32*)(p + 0x2c) = 0x52415243;
    *(int*)(p + 0x28) = *(int*)(p + 0x54) + *(int*)(*(u8**)(p + 0x48) + 4);
    fn_80166D3C(lbl_802EE2D4, p + 0x18);
    p[0x30] = 1;
    return p;
}

extern "C" void fn_801641A8(u8* p) {
    if (*(void**)(p + 0x44) != NULL && p[0x3c] != 1) {
        u8* entry = *(u8**)(p + 0x4c);
        for (u32 i = 0; i < *(u32*)(*(u8**)(p + 0x44) + 8); i++) {
            u8 flags = *(u32*)(entry + 4) >> 24;
            if (*(void**)(entry + 0x10) != NULL) {
                if ((flags & 0x10) == 0) {
                    fn_80159C6C(*(void**)(entry + 0x10), *(s32*)(p + 0x38));
                }
                *(void**)(entry + 0x10) = NULL;
            }
        }
    }
}

extern "C" BOOL fn_8016424C(u8* a, void* b) {
    u8* p = (u8*)fn_801615C4();
    if (p == NULL) {
        return 0;
    }
    if ((*(u32*)(p + 4) >> 24 & 0x10) == 0) {
        fn_80159C6C(b, *(s32*)(a + 0x38));
    }
    *(u32*)(p + 0x10) = 0;
    return 1;
}

extern "C" void* fn_801615C4(void);
extern "C" void fn_80159C6C(void*, int);
extern "C" void* fn_80160D88(void*, char*, void*);
extern void fn_80166B70(void* p, int r4);
extern void fn_8015D0B8(void* p, int r4);
extern void fn_8015AB1C(void* p);
extern void fn_801BE368(void* p);
extern void fn_801BDDBC(void* p, void* p2, int r5);
extern "C" u32 fn_801C7C6C(u32 r4, void* p);
extern "C" void fn_80166C84(u32 r3, void* p);
extern "C" void fn_801CA1E4(void* p);
extern void fn_8015D050(void);
extern void fn_80166B58(void* p, void* p2);
extern "C" void fn_80164644(u8* p) {
    *(u8**)(p + 0x98) = p;
    fn_801BE368(p + 0x1c);
    fn_801BE368(p + 0x34);
    fn_801BDDBC(p + 0xc0, p + 0xe0, 1);
    fn_801BDDBC(p + 0x9c, p + 0xbc, 1);
    *(u32*)(p + 0xf4) = 0;
    *(u32*)(p + 0x50) = 0;
    *(u32*)(p + 0x58) = 0;
}

extern "C" u8 fn_801646B0(u8* p, u32 r4) {
    if (p[0x18] == 0) {
        u32 result = fn_801C7C6C(r4, p + 0x5c);
        p[0x18] = (result != 0);
        
        if (p[0x18] != 0) {
            fn_80166C84((u32)lbl_802EE2EC, p + 0xe4);
            fn_801CA1E4(p + 0x5c);
        }
    }
    return p[0x18];
}

extern u32 fn_801C7BF8(u32 r4, void* p);
extern "C" u8 fn_80164728(u8* p, u32 r4) {
    if (p[0x18] == 0) {
        u32 result = fn_801C7BF8(r4, p + 0x5c);
        p[0x18] = (result != 0);
        
        if (p[0x18] != 0) {
            fn_80166C84((u32)lbl_802EE2EC, p + 0xe4);
            fn_801CA1E4(p + 0x5c);
        }
    }
    return p[0x18];
}

extern "C" void fn_801647A0(u8* p) {
    if (p[0x18]) {
        if (fn_801C7D34(p + 0x5c)) {
            p[0x18] = 0;
            fn_80166FC4(lbl_802EE2EC, p + 0xe4);
        } else {
            fn_8011C9EC(lbl_802981A8, 0xd5, lbl_802FE368, lbl_802981B8);
        }
    }
}

extern "C" u32 fn_801648EC(u8* p);
extern "C" void fn_80164940(void* a, u8* b);
extern "C" u32 fn_801C027C(void);
extern "C" int fn_801C7F7C(void* p, u32 a, u32 b, u32 c, void* cb, int flags);
extern "C" u32 fn_80164820(u8* p, u32 r4, u32 r5, u32 r6) {
    u32 ret;
    fn_801BE3A0(p + 0x1c);
    if (*(u32*)(p + 0xf4) != 0) {
        fn_801BE47C(p + 0x1c);
        return -1;
    }
    *(u32*)(p + 0xf4) = fn_801C027C();
    ret = -1;
    if (fn_801C7F7C(p + 0x5c, r4, r5, r6, (void*)fn_80164940, 2) != 0) {
        ret = fn_801648EC(p);
    }
    *(u32*)(p + 0xf4) = 0;
    fn_801BE47C(p + 0x1c);
    return ret;
}

extern "C" int fn_801648E4(void) {
    return -1;
}

extern "C" u32 fn_801648EC(u8* p) {
    u32 v;
    fn_801BE3A0(p + 0x1c);
    fn_801BDEE4(p + 0xc0, &v, 1);
    *(u32*)(p + 0xf4) = 0;
    fn_801BE47C(p + 0x1c);
    return v;
}

extern "C" void fn_80164940(void* a, u8* b) {
    fn_801BDE1C(*(u8**)(b + 0x3c) + 0xc0, a, 0);
}

extern "C" int fn_801C7D34(void*);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void fn_8011C9EC(const char*, int, const char*, ...);
extern "C" char lbl_802EE2EC[];
extern "C" char lbl_802981A8[];
extern "C" char lbl_802981B8[];
extern "C" char lbl_802FE368[];
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_801BDE1C(void*, void*, int);
extern "C" u32 fn_80164970(u8* p) { return *(u32*)(p + 0x90); }
extern "C" int fn_801C7D34(void*);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void fn_8011C9EC(const char*, int, const char*, ...);
extern "C" char lbl_802EE2EC[];
extern "C" char lbl_802981A8[];
extern "C" char lbl_802981B8[];
extern "C" char lbl_802FE368[];
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_801BDE1C(void*, void*, int);
