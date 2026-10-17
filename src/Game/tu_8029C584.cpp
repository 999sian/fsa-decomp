

struct Vec {
    float x, y, z;
};

extern "C" void fn_8022CA6C(int a, int b, int c);
extern "C" void fn_8022CDD4(int a);
extern "C" void fn_80134FE0(void* p, int b);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804A7BE8[];
extern void* lbl_8053AAF8;
extern "C" void* fn_8029CF44(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A7BE8;
        if (*(unsigned char*)((char*)this_ + 0x244) == 0) {
            if (*(int*)((char*)this_ + 0x240) != *(int*)((char*)this_ + 0x23c)) {
                fn_8022CA6C(*(int*)((char*)this_ + 0x90) & 3, *(int*)((char*)this_ + 0x23c), 1);
            }
        }
        if (*(unsigned char*)((char*)lbl_8053AAF8 + 0x7e) == 0) {
            fn_80134FE0(lbl_8053AAF8, 0);
        }
        fn_8022CDD4(*(int*)((char*)this_ + 0x90) & 3);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" unsigned char fn_8022F514(int a);
extern "C" void fn_8022CF08(int a);
extern "C" float* fn_8023E724(int i);
extern "C" int fn_8022CAF8(int a);
extern "C" void fn_801F0D20(void* this_, int a);
extern "C" unsigned char* fn_802D6A9C(void);
extern "C" int* fn_801F856C(void);
extern float lbl_8054075C;
extern "C" void fn_8029CFF8(void* this_) {
    float* p;
    int i;
    int n;
    int count;
    int j;
    void* a;
    if (fn_8022F514(*(int*)((char*)this_ + 0x90) & 3)) {
        *(unsigned char*)((char*)this_ + 0x11c) = 0;
        return;
    }
    fn_8022CF08(*(int*)((char*)this_ + 0x90) & 3);
    p = fn_8023E724(*(int*)((char*)this_ + 0x90) & 3);
    *(float*)((char*)this_ + 0xc) = p[0];
    *(float*)((char*)this_ + 0x10) = p[1];
    *(float*)((char*)this_ + 0x14) = p[2];
    *(float*)((char*)this_ + 0x14) += lbl_8054075C;
    *(int*)((char*)this_ + 0x108) = 0;
    *(int*)((char*)this_ + 0x234) = 1;
    *(int*)((char*)this_ + 0x238) = 0;
    count = fn_8022CAF8(*(int*)((char*)this_ + 0x90) & 3);
    *(int*)((char*)this_ + 0x23c) = count;
    *(int*)((char*)this_ + 0x240) = count;
    *(unsigned char*)((char*)this_ + 0x244) = 1;
    *(unsigned char*)((char*)this_ + 0x11f) = 1;
    fn_801F0D20(this_, 0x45);
    *(int*)((char*)this_ + 0x248) = *(int*)((char*)this_ + 0x90) & 3;
    n = 3;
    for (i = 0; i < 4; i++) {
        if (fn_8022F514(i)) {
            n--;
        }
    }
    if (n == 0) {
        *(unsigned char*)((char*)this_ + 0x24c) = 1;
        if (fn_802D6A9C()[*(int*)((char*)this_ + 4) + 0x131df] != 0) {
            *(int*)((char*)this_ + 0x230) = 0x3f;
        } else {
            *(int*)((char*)this_ + 0x230) = 0x3d;
        }
        if (*(int*)((char*)this_ + 0x23c) == 5) {
            *(int*)((char*)this_ + 0x23c) = 3;
        }
    } else {
        *(unsigned char*)((char*)this_ + 0x24c) = 0;
        if (fn_802D6A9C()[*(int*)((char*)this_ + 4) + 0x131df] != 0) {
            *(int*)((char*)this_ + 0x230) = 0x44;
        } else {
            *(int*)((char*)this_ + 0x230) = 0x43;
        }
        if (*(int*)((char*)this_ + 0x23c) == 5) {
            *(int*)((char*)this_ + 0x23c) = 0;
        }
    }
    *(int*)((char*)this_ + 0x250) = 0;
    *(int*)((char*)this_ + 0x254) = 0;
    count = fn_801F856C()[0x1008 / 4];
    j = 0;
    for (i = 0; i < count; i++) {
        a = (void*)fn_801F856C()[(j + 8) / 4];
        if (a != 0 && *(int*)((char*)a + 0x1a0) == 0x4647414c && *(unsigned char*)((char*)a + 0x11c) == 1) {
            *(void**)((char*)this_ + 0x254) = a;
        }
        j += 4;
    }
}

