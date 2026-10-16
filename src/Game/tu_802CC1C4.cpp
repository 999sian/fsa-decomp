

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
