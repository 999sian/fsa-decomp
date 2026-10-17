

struct GXColor_CC {
    unsigned char r, g, b, a;
    GXColor_CC(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) : r(r_), g(g_), b(b_), a(a_) {}
};

extern "C" char lbl_804A9020[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, int);
extern "C" char* lbl_8053AB10;
extern "C" void* lbl_8053AC98;
extern "C" void fn_802A3948(void* mgr, void* pos, int player, unsigned long room, int id);
extern "C" unsigned long fn_8013CC50(unsigned long id, void* pos, unsigned long seId, int a, int b, int c, int d, int e, float f);
extern "C" char* fn_802D6A9C(void* this_);

struct Vec3CC {
    float x;
    float y;
    float z;
};
extern "C" void fn_80158B5C(void*, unsigned long, void*, GXColor_CC, float);
extern "C" void fn_802CC1C4(void* this_) {
    unsigned long id = *(unsigned long*)((char*)this_ + 0x4);
    GXColor_CC c(0, 0, 0, 0x80);
    fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), id, (char*)this_ + 0xc, c, 70.0f);
}

extern "C" void* fn_802CCA10(void* this_, short freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A9020;
        if (*(void**)(p + 0x230) != 0) {
            fn_801EE434(*(void**)(p + 0x230));
        }
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        if (*(void**)(p + 0x238) != 0) {
            fn_801EE434(*(void**)(p + 0x238));
        }
        if (*(void**)(p + 0x23c) != 0) {
            fn_801EE434(*(void**)(p + 0x23c));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802CCAB4(void* this_) {
    char* p = (char*)this_;
    *(unsigned long*)(p + 0x230) = 0;
    *(unsigned long*)(p + 0x234) = 0;
    *(unsigned long*)(p + 0x238) = 0;
    *(unsigned long*)(p + 0x23c) = 0;
    *(float*)(p + 0x60) = -8.0f;
    *(float*)(p + 0x64) = -8.0f;
    *(float*)(p + 0x68) = 8.0f;
    *(float*)(p + 0x6c) = 8.0f;
    char* iVar2 = fn_802D6A9C(this_);
    if (*(unsigned char*)(iVar2 + 0x171) == 0) {
        Vec3CC a;
        Vec3CC b;
        fn_802A3948(lbl_8053AC98, p + 0xc, 0, *(unsigned long*)(p + 4), 0xaf);
        *(unsigned long*)(p + 0x240) = 2;
        a.x = 8.0f;
        a.y = a.x + *(float*)(p + 0x10);
        a.z = *(float*)(p + 0x14);
        a.x = a.x + *(float*)(p + 0xc);
        *(unsigned long*)(p + 0x230) = fn_8013CC50(*(unsigned long*)(p + 4), &a, 0x426, 1, 0, 0, 0, 1, 1.0f);
        b.x = 8.0f;
        b.y = b.x + *(float*)(p + 0x10);
        b.z = *(float*)(p + 0x14);
        b.x = b.x + *(float*)(p + 0xc);
        *(unsigned long*)(p + 0x234) = fn_8013CC50(*(unsigned long*)(p + 4), &b, 0x427, 1, 0, 0, 0, 1, 1.0f);
    } else {
        Vec3CC c;
        Vec3CC d;
        *(unsigned long*)(p + 0x240) = 0;
        c.x = 8.0f;
        c.y = c.x + *(float*)(p + 0x10);
        c.z = *(float*)(p + 0x14);
        c.x = c.x + *(float*)(p + 0xc);
        *(unsigned long*)(p + 0x238) = fn_8013CC50(*(unsigned long*)(p + 4), &c, 0x42d, 1, 0, 0, 0, 1, 1.0f);
        d.x = 8.0f;
        d.y = d.x + *(float*)(p + 0x10);
        d.z = *(float*)(p + 0x14);
        d.x = d.x + *(float*)(p + 0xc);
        *(unsigned long*)(p + 0x23c) = fn_8013CC50(*(unsigned long*)(p + 4), &d, 0x42e, 1, 0, 0, 0, 1, 1.0f);
    }
    *(unsigned long*)(p + 0x244) = 0xf;
}