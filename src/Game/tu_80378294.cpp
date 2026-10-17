

#include "Game/SinitPoolChain.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void* p);
extern char lbl_804AE888[];
extern "C" void* fn_801F856C(void);
extern "C" int fn_801F78F4(void* mgr, unsigned int type, int idx);
extern "C" void* fn_801F666C(void* mgr, int idx);
extern "C" int fn_802BA9F8(void* obj);
extern "C" int fn_802BA9F0(void* obj);
extern "C" int fn_801F78F4(void* pool, unsigned int type, int afterId);
extern "C" void* fn_801F666C(void* reg, int id);
extern "C" void* fn_8023E724(int i);
extern "C" unsigned char fn_8023077C(void);
extern "C" void fn_80230498(int i, void* p, int a, int b, int c, int d, int e);
extern "C" void fn_80230FD0(int i, int a);
extern "C" unsigned char fn_80230534(int a);
extern "C" void fn_801F0D20(void* this_, int id);
extern "C" void detach__5ActorFv(void* this_);
extern int lbl_804751A8[];
extern "C" int fn_8037845C(void* param_1) {
    int* p = (int*)param_1;
    int i;

    if (0 < p[0x91]) {
        p[0x91] = p[0x91] - 1;
    }
    if (p[0x92] < 0) {
        return 0;
    }
    if (p[0x92] < 4) {
        if (fn_8023077C()) {
            p[0x92] = 4;
            p[0x91] = 0x32;
            p[0x93] = 0;
            for (i = 0; i < 4; i++) {
                fn_80230498(i, fn_8023E724(i), 0xe8, 0xff, -0x80, -0x80, 1);
            }
        }
        return 1;
    }
    if (p[0x93] == 0 && p[0x91] > 0x1e) {
        for (i = 0; i < 4; i++) {
            fn_80230498(i, fn_8023E724(i), 0xe8, 0xff, -0x80, -0x80, 1);
        }
        return 1;
    }
    if (p[0x93] < 0xd) {
        if (p[0x91] == 0) {
            i = 0;
            p[0x93]++;
            p[0x91] = lbl_804751A8[p[0x93]];
            do {
                fn_80230498(i, fn_8023E724(i), p[0x93] + 0xdb, 0xff, -0x80, -0x80, 1);
                if (p[0x93] == 1) {
                    fn_80230FD0(i, 0x10001);
                }
                i++;
            } while (i < 4);
            if (p[0x93] == 0xd) {
                p[0x91] = 0x19;
            }
        }
    } else if (p[0x91] == 0 && fn_80230534(0)) {
        p[0x92] = -1;
        fn_801F0D20(param_1, 3);
        (*(void (**)(void*, int, int))(*(int*)param_1 + 0x30))(param_1, 0xff, 1);
        detach__5ActorFv(param_1);
    }
    return 1;
}

extern "C" int fn_80378680(char* p) {
    struct Vec3f {
        float x;
        float y;
        float z;
    };
    float x0 = *(float*)(p + 0x60) + *(float*)(p + 0xc);
    float y0 = *(float*)(p + 0x64) + *(float*)(p + 0x10);
    float x1 = *(float*)(p + 0x68) + *(float*)(p + 0xc);
    float y1 = *(float*)(p + 0x6c) + *(float*)(p + 0x10);
    int id = fn_801F78F4(fn_801F856C(), 0x48424D42, -1);
    if (id < 0) {
        return 0;
    }
    char* obj = (char*)fn_801F666C(fn_801F856C(), id);
    if (obj != 0 && *(int*)(p + 4) == *(int*)(obj + 4)) {
        float ox0 = *(float*)(obj + 0x60) + *(float*)(obj + 0xc);
        float oy0 = *(float*)(obj + 0x64) + *(float*)(obj + 0x10);
        float ox1 = *(float*)(obj + 0x68) + *(float*)(obj + 0xc);
        float oy1 = *(float*)(obj + 0x6c) + *(float*)(obj + 0x10);
        if (ox0 > x0) {
            ox0 = x0;
        }
        if (oy0 > y0) {
            oy0 = y0;
        }
        if (ox1 < x1) {
            ox1 = x1;
        }
        if (oy1 < y1) {
            oy1 = y1;
        }
        unsigned char hit = 0;
        if (ox1 < ox0 && oy1 < oy0) {
            hit = 1;
        }
        if (hit) {
            Vec3f v = *(Vec3f*)(obj + 0x3c);
            if (v.x == 0.0f && v.y == 0.0f) {
                Vec3f pos = *(Vec3f*)(obj + 0xc);
                if (pos.y > *(float*)(p + 0x10)) {
                    pos.y = *(float*)(p + 0x10) + 16.0f;
                } else {
                    pos.y = *(float*)(p + 0x10) - 16.0f;
                }
                *(Vec3f*)(obj + 0xc) = pos;
            } else {
                *(int*)(obj + 0x108) = 0;
            }
        }
    }
    return 0;
}

extern "C" int fn_80378880(void* param_1) {
    int idx = -1;
    unsigned char flags = 0;
    float x0 = *(float*)((char*)param_1 + 0x60) + *(float*)((char*)param_1 + 0xc);
    float y0 = *(float*)((char*)param_1 + 0x64) + *(float*)((char*)param_1 + 0x10);
    float x1 = *(float*)((char*)param_1 + 0x68) + *(float*)((char*)param_1 + 0xc);
    float y1 = *(float*)((char*)param_1 + 0x6c) + *(float*)((char*)param_1 + 0x10);

    idx = fn_801F78F4(fn_801F856C(), 0x46495245, idx);
    if (idx >= 0) {
        void* obj = fn_801F666C(fn_801F856C(), idx);
        if (obj != 0 && *(int*)((char*)param_1 + 0x4) == *(int*)((char*)obj + 0x4)) {
            float ox0 = *(float*)((char*)obj + 0x60) + *(float*)((char*)obj + 0xc);
            float oy0 = *(float*)((char*)obj + 0x64) + *(float*)((char*)obj + 0x10);
            float ox1 = *(float*)((char*)obj + 0x68) + *(float*)((char*)obj + 0xc);
            float oy1 = *(float*)((char*)obj + 0x6c) + *(float*)((char*)obj + 0x10);
            unsigned char hit = 0;
            if (ox0 > x0) {
                ox0 = x0;
            }
            if (oy0 > y0) {
                oy0 = y0;
            }
            if (ox1 < x1) {
                ox1 = x1;
            }
            if (oy1 < y1) {
                oy1 = y1;
            }
            if (ox1 < ox0 && oy1 < oy0) {
                hit = 1;
            }
            if (hit) {
                if (fn_802BA9F8(obj) == 1) {
                    flags |= 1 << fn_802BA9F0(obj);
                }
            }
        }
    }
    return flags == 0xF;
}

extern "C" void* fn_80378D18(void* param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = (void*)lbl_804AE888;
        void* val = *(void**)((char*)param_1 + 0x230);
        if (val != 0) {
            ((void (*)(void*))fn_801EE434)(val);
            *(void**)((char*)param_1 + 0x230) = 0;
        }
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80378D94(void* param_1) {
    *(float*)((char*)param_1 + 0x60) = -92.0f;
    *(float*)((char*)param_1 + 0x64) = -16.0f;
    *(float*)((char*)param_1 + 0x68) = 92.0f;
    *(float*)((char*)param_1 + 0x6c) = 16.0f;
    *(float*)((char*)param_1 + 0x70) = *(float*)((char*)param_1 + 0x60);
    *(float*)((char*)param_1 + 0x74) = *(float*)((char*)param_1 + 0x64);
    *(float*)((char*)param_1 + 0x78) = *(float*)((char*)param_1 + 0x68);
    *(float*)((char*)param_1 + 0x7c) = *(float*)((char*)param_1 + 0x6c);
    *(float*)((char*)param_1 + 0x80) = *(float*)((char*)param_1 + 0x60);
    *(float*)((char*)param_1 + 0x84) = *(float*)((char*)param_1 + 0x64);
    *(float*)((char*)param_1 + 0x88) = *(float*)((char*)param_1 + 0x68);
    *(float*)((char*)param_1 + 0x8c) = *(float*)((char*)param_1 + 0x6c);
    *(int*)((char*)param_1 + 0xb8) = 1;
    *(int*)((char*)param_1 + 0xf8) = 2;
    *(int*)((char*)param_1 + 0xbc) = 3;
    *(int*)((char*)param_1 + 0x1a4) = 1;
    *(int*)((char*)param_1 + 0xb0) = 0xa040304;
    *(int*)((char*)param_1 + 0x234) = 0;
    *(float*)((char*)param_1 + 0x23c) = 1.0f;
    *(float*)((char*)param_1 + 0x238) = 1.0f;
    *(int*)((char*)param_1 + 0x230) = 0;
    *(int*)((char*)param_1 + 0x240) = 0;
    *(unsigned char*)((char*)param_1 + 0x250) = 0;
    *(unsigned char*)((char*)param_1 + 0x251) = 0;
    *(int*)((char*)param_1 + 0x244) = 0;
    *(int*)((char*)param_1 + 0x248) = -1;
    *(int*)((char*)param_1 + 0x24c) = 0;
}

extern "C" void fn_80378E54(void) {}

