#include "types.h"
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
extern "C" void* fn_8015FFF0(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
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

extern "C" void fn_80160C34(void*, void*, int);
extern "C" u8 fn_80161A2C(void*, void*, void*);
extern "C" void fn_80166D3C(void*, void*);
extern "C" char lbl_80297DD4[];
extern "C" char lbl_802EE2D4[];
extern "C" void* fn_80161710(void*, void*);
extern "C" void* fn_80161874(void* a, void** b) {
    *b = fn_80161710(a, *b);
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

extern "C" BOOL fn_80161CE0(void) {
    u8* p = (u8*)fn_801615C4();
    if (p == NULL) {
        return 0;
    }
    *(u32*)(p + 0x10) = 0;
    return 1;
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

extern "C" void* fn_801615C4(void);
extern "C" void fn_80159C6C(void*, int);
extern "C" void* fn_80160D88(void*, char*, void*);
extern void fn_80166B70(void* p, int r4);
extern void fn_8015D0B8(void* p, int r4);
extern void fn_8015AB1C(void* p);
extern void fn_801BE368(void* p);
extern void fn_801BDDBC(void* p, void* p2, int r5);
extern u32 fn_801C7C6C(u32 r4, void* p);
extern void fn_80166C84(u32 r3, void* p);
extern void fn_801CA1E4(void* p);
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
        u8 flag = (u8)((-(s32)result >> 0x18) | (result >> 0x18)) >> 7;
        p[0x18] = flag;
        
        if (flag != 0) {
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
