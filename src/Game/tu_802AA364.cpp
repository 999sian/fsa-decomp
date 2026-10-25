

extern "C" char lbl_804A8118[];
extern "C" void __dt__5ActorFv(void *, int);
extern "C" void *fn_802AA364(void *self, short flags) {
    if (self != 0) {
        *(void **)self = lbl_804A8118;
        __dt__5ActorFv(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}

extern "C" void fn_802AA3C4(void) {
}

// Actor virtual at vtable +0x34: nonzero once the actor is ready to act.
struct Tu802AA364Actor {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual unsigned char isReady();
};

// Resource manager at game+0xa4; vtable +0x18 looks a resource up by type and name.
struct Tu802AA364ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(unsigned int type, const char* name);
};

extern "C" void fn_802A3948(void* a, void* b, int c, int d, int e);
extern "C" void fn_802A3884(void* a, void* b, int c, int d, int e);
extern "C" void fn_801F0E34(void* a, unsigned int code, unsigned int z);
extern "C" void fn_801F0D20(void* a, unsigned int b);
extern "C" void fn_801F35AC(void* a);
extern "C" void fn_802FA160(void* a, void* b, int c, int d, int e, int f);
extern "C" void* fn_802D6A9C(void);
extern "C" unsigned char fn_802D800C(void* mgr, int kind);
extern void* lbl_8053AC98;
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern char lbl_8046C860[];
extern float lbl_80540888;
extern float lbl_8054088C;
extern "C" void fn_802AA3C8(void* self) {
    unsigned char* s = (unsigned char*)self;
    int* p = (int*)self;
    switch (p[0x8c]) {
    case 0:
        if (((Tu802AA364Actor*)self)->isReady() == 1) {
            float v[3];
            fn_802A3948(lbl_8053AC98, s + 0xc, 0, p[1], 0x38);
            float y = *(float*)(s + 0x10) - lbl_80540888;
            int r = p[1] + 1;
            v[0] = *(float*)(s + 0xc);
            v[1] = y;
            v[2] = lbl_8054088C;
            fn_802A3948(lbl_8053AC98, v, 0, r, 0x39);
            fn_801F0E34(self, 0x30016, 0);
            if (p[1] < 8) {
                p[0x8c] = 2;
                p[0x90] = 2;
            } else {
                void* res = (*(Tu802AA364ResMgr**)((unsigned char*)lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_8046C860);
                fn_802FA160(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), res, 0, 0, 0x40, 0xc0);
                p[0x8c] = 1;
            }
        }
        break;
    case 1:
        if (fn_802D800C(fn_802D6A9C(), p[0x8d])) {
            fn_801F0D20(self, 3);
            p[0x8c] = 4;
        }
        break;
    case 2:
        p[0x90] = p[0x90] - 1;
        if (p[0x90] == 0) {
            void* res = (*(Tu802AA364ResMgr**)((unsigned char*)lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_8046C860);
            fn_802FA160(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), res, 0xc0, 0, 0x40, 0xc0);
            fn_801F0E34(self, 0x30016, 0);
            p[0x8c] = 3;
            p[0x90] = 2;
        }
        break;
    case 3:
        p[0x90] = p[0x90] - 1;
        if (p[0x90] == 0) {
            void* res = (*(Tu802AA364ResMgr**)((unsigned char*)lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_8046C860);
            fn_802FA160(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), res, 0, 0, 0x40, 0xc0);
            p[0x8c] = 1;
            p[0x90] = 2;
        }
        break;
    case 4:
        p[0x90] = p[0x90] - 1;
        if (p[0x90] == 0) {
            if (p[1] < 8) {
                void* res = (*(Tu802AA364ResMgr**)((unsigned char*)lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_8046C860);
                fn_802FA160(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), res, 0xc0, 0, 0x40, 0xc0);
                p[0x8c] = 5;
                p[0x90] = 2;
            } else {
                float v[3];
                fn_802A3884(lbl_8053AC98, s + 0xc, 0, p[1], *(unsigned short*)(s + 0x244));
                float y = *(float*)(s + 0x10) - lbl_80540888;
                int r = p[1] + 1;
                v[0] = *(float*)(s + 0xc);
                v[1] = y;
                v[2] = lbl_8054088C;
                fn_802A3884(lbl_8053AC98, v, 0, r, 0);
                void* res = (*(Tu802AA364ResMgr**)((unsigned char*)lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_8046C860);
                fn_802FA160(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), res, 0x180, 0, 0x40, 0xc0);
                if (p[0x8f] == 0) {
                    fn_801F35AC(self);
                } else {
                    s[0x11c] = 0;
                }
            }
            fn_801F0E34(self, 0x30015, 0);
        }
        break;
    case 5:
        p[0x90] = p[0x90] - 1;
        if (p[0x90] == 0) {
            float v[3];
            fn_802A3884(lbl_8053AC98, s + 0xc, 0, p[1], *(unsigned short*)(s + 0x244));
            float y = *(float*)(s + 0x10) - lbl_80540888;
            int r = p[1] + 1;
            v[0] = *(float*)(s + 0xc);
            v[1] = y;
            v[2] = lbl_8054088C;
            fn_802A3884(lbl_8053AC98, v, 0, r, 0);
            void* res = (*(Tu802AA364ResMgr**)((unsigned char*)lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_8046C860);
            fn_802FA160(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), res, 0x180, 0, 0x40, 0xc0);
            if (p[0x8f] == 0) {
                fn_801F35AC(self);
            } else {
                s[0x11c] = 0;
            }
        }
        break;
    }
}

extern "C" int fn_80226AE0(void* a, int b);
extern "C" unsigned short fn_802F9908(void* a, int b, int c);
extern "C" void fn_802AA868(void* self) {
    int* p = (int*)self;
    float* f = (float*)self;
    float vec[3];
    int room;
    unsigned char cVar;
    void* mgr;
    void* res;

    p[0x8d] = ((unsigned int)p[0x24] >> 22) & 0x1f;
    p[0x8f] = ((unsigned int)p[0x24] >> 17) & 0x1f;
    p[0x8c] = 0;
    room = fn_80226AE0(f + 3, p[1]);
    *(unsigned short*)((unsigned char*)self + 0x244) = fn_802F9908(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), p[1], room);
    cVar = fn_802D800C(fn_802D6A9C(), p[0x8d]);
    if (cVar != 0) {
        fn_802A3884(lbl_8053AC98, f + 3, 0, p[1], *(unsigned short*)((unsigned char*)self + 0x244));
        vec[0] = f[3];
        vec[1] = f[4] - lbl_80540888;
        vec[2] = lbl_8054088C;
        fn_802A3884(lbl_8053AC98, vec, 0, p[1] + 1, 0);
        mgr = *(void**)((unsigned char*)lbl_8053AAF8 + 0xa4);
        res = ((void* (*)(void*, unsigned int, void*))((void**)*(void**)mgr)[6])(mgr, 0x53434820, lbl_8046C860);
        fn_802FA160(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), res, 0x180, 0, 0x40, 0xc0);
        ((unsigned char*)self)[0x11c] = 0;
    } else {
        mgr = *(void**)((unsigned char*)lbl_8053AAF8 + 0xa4);
        res = ((void* (*)(void*, unsigned int, void*))((void**)*(void**)mgr)[6])(mgr, 0x53434820, lbl_8046C860);
        fn_802FA160(*(void**)((unsigned char*)lbl_8053AB10 + 0x20), res, 0, 0, 0x40, 0xc0);
    }
}



