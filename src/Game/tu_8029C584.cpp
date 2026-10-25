

extern "C" void fn_803703C8(void);
extern "C" void fn_8030AAF4(int a);
extern "C" char* fn_8008E328(void);
extern "C" unsigned int fn_8022C5EC(int a, int b);
extern "C" unsigned int fn_8022C52C(int a, int b);
extern "C" unsigned char fn_8022C9AC(int a);
extern "C" void fn_80230EB8(int a, int b);
extern "C" const int lbl_8046C400[][6];
extern float lbl_80540760;
extern float lbl_8054075C;
extern "C" float* fn_8023E724(int i);
extern "C" unsigned char* fn_802D6A9C(void);
extern "C" void fn_801F0D20(void* this_, int a);

struct TVec3f {
    float x, y, z;
};

#include "JSystem/JGeometry/Vec.h"

struct Vec2 {
    float x, y;
};

struct Box2 {
    Vec2 min;
    Vec2 max;
};

struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual unsigned int getResource(unsigned int fourccType, const char* fileName);
};

// 0x3C-byte 2D SOB draw configuration payload (same layout tu_802CFDCC.cpp)
struct SobDrawParams {
    unsigned char paletteMap[0x10];
    union {
        int raw;
        struct {
            unsigned char r, g, b, a;
        } rgba;
    } primaryColor;
    int envColor;
    void* transformMtx;
    signed char renderFlags[0xB];
    int blendMode;
    unsigned char shadowFlags[3];
    int lightId;
    int animPhase;
    int cullMode;

    SobDrawParams() {
        int i;
        primaryColor.raw = -1;
        envColor = -1;
        for (i = 0; (unsigned char)i < 0x10; i += 8) {
            paletteMap[(unsigned char)i] = i;
            paletteMap[(unsigned char)(i + 1)] = i + 1;
            paletteMap[(unsigned char)(i + 2)] = i + 2;
            paletteMap[(unsigned char)(i + 3)] = i + 3;
            paletteMap[(unsigned char)(i + 4)] = i + 4;
            paletteMap[(unsigned char)(i + 5)] = i + 5;
            paletteMap[(unsigned char)(i + 6)] = i + 6;
            paletteMap[(unsigned char)(i + 7)] = i + 7;
        }
        primaryColor.raw = -1;
        envColor = 0;
        transformMtx = 0;
        renderFlags[0] = 0;
        renderFlags[1] = 0;
        renderFlags[2] = 0;
        renderFlags[3] = 1;
        renderFlags[4] = 1;
        renderFlags[5] = 0;
        renderFlags[6] = 0;
        renderFlags[7] = 0;
        renderFlags[8] = 0;
        renderFlags[9] = 0;
        renderFlags[10] = 1;
        blendMode = 3;
        shadowFlags[0] = 1;
        shadowFlags[1] = 0;
        shadowFlags[2] = 0;
        lightId = -1;
        animPhase = 0;
        cullMode = 2;
    }
};

extern "C" void fn_8022CA6C(int a, int b, int c);
extern "C" void fn_8022CDD4(int a);
extern "C" void fn_80134FE0(void* p, int b);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804A7BE8[];
extern void* lbl_8053AAF8;
extern "C" void fn_8022B8EC(unsigned int index, float* a0);
extern "C" unsigned char fn_8022C8EC(int index);
extern "C" void fn_802F86CC(unsigned int sobRenderer, Vec* pos, unsigned int sobResource, int spriteId, float scaleX, float scaleY, SobDrawParams* drawParams);
extern "C" void fn_80307AC8(unsigned int a, int room, Vec* pos, int spriteId, int b, int c, int d);
extern void* lbl_8053AB10;
extern float lbl_80540738;
extern float lbl_8054073C;
extern float lbl_80540740;
extern float lbl_80540744;
extern float lbl_80540748;
extern float lbl_8054074C;
extern float lbl_80540750;
extern float lbl_80540754;
extern float lbl_80540758;
extern "C" const char lbl_8046C490[];
extern "C" void fn_8029C584(void* this_) {
    Vec pos;
    Box2 box;
    char* p = (char*)this_;

    JGeometry::setTVec3f((float*)(p + 0xc), &pos.x);
    if (*(int*)(p + 0x4) == 0) {
        box = *(Box2*)(*(char**)((char*)lbl_8053AB10 + 0x24) + 0x164);
        if (pos.y - pos.z < lbl_80540738 + box.min.y) {
            pos.y += lbl_8054073C;
        }
        if (*(unsigned char*)(p + 0x24c) != 0) {
            if (pos.x < lbl_80540740 + box.min.x) {
                pos.x = lbl_80540740 + box.min.x;
            } else if (pos.x >= box.max.x - lbl_80540744) {
                pos.x = box.max.x - lbl_80540744;
            }
        } else {
            if (pos.x < lbl_8054073C + box.min.x) {
                pos.x = lbl_8054073C + box.min.x;
            } else if (pos.x >= box.max.x - lbl_80540748) {
                pos.x = box.max.x - lbl_80540748;
            }
        }
    } else {
        fn_8022B8EC(*(int*)(p + 0x248), (float*)&box);
        if (pos.y - pos.z < lbl_80540738 + box.min.y) {
            pos.y += lbl_8054073C;
        }
        if (*(unsigned char*)(p + 0x24c) != 0) {
            if (fn_8022C8EC(*(int*)(p + 0x90) & 3)) {
                if (pos.x < lbl_8054073C + box.min.x) {
                    pos.x = lbl_8054073C + box.min.x;
                } else if (pos.x >= box.max.x - lbl_8054073C) {
                    pos.x = box.max.x - lbl_8054073C;
                }
            } else {
                if (pos.x < lbl_8054074C + box.min.x) {
                    pos.x = lbl_8054074C + box.min.x;
                } else if (pos.x >= box.max.x - lbl_8054074C) {
                    pos.x = box.max.x - lbl_8054074C;
                }
            }
        } else {
            if (fn_8022C8EC(*(int*)(p + 0x90) & 3)) {
                if (pos.x < lbl_80540750 + box.min.x) {
                    pos.x = lbl_80540750 + box.min.x;
                } else if (pos.x >= box.max.x - lbl_80540750) {
                    pos.x = box.max.x - lbl_80540750;
                }
            } else {
                if (pos.x < lbl_80540754 + box.min.x) {
                    pos.x = lbl_80540754 + box.min.x;
                } else if (pos.x >= box.max.x - lbl_80540754) {
                    pos.x = box.max.x - lbl_80540754;
                }
            }
        }
    }

    SobDrawParams drawParams;
    unsigned int sobRes;
    drawParams.renderFlags[0] = 2;
    drawParams.shadowFlags[1] = 1;

    int spriteId = *(int*)(p + 0x230);
    if (*(int*)(p + 0x4) < 8) {
        sobRes = ((FsaResourceManager*)*(void**)((char*)lbl_8053AAF8 + 0xa4))->getResource(0x534F4220, lbl_8046C490);
        fn_802F86CC(*(unsigned int*)((char*)lbl_8053AB10 + 0x20), &pos, sobRes, spriteId, lbl_80540758, lbl_80540758, &drawParams);
    }
    if (fn_8022C8EC(*(int*)(p + 0x90) & 3)) {
        fn_80307AC8(*(unsigned int*)(p + 0x198), *(int*)(p + 0x4), &pos, *(int*)(p + 0x230), 0, 0, -1);
    } else {
        fn_80307AC8(*(unsigned int*)(p + 0x198), *(int*)(p + 0x4), &pos, *(int*)(p + 0x230), 1, 0, -1);
    }
}

extern "C" void fn_8029C9AC(void* this_) {
    const int (*tbl)[6] = lbl_8046C400;
    char* p = (char*)this_;
    char* obj = *(char**)(p + 0x254);
    if (obj != 0) {
        int state = *(int*)(obj + 0x230);
        if (state >= 1 && state <= 10) {
            fn_803703C8();
        }
    }
    if (*(int*)(p + 0x250) != 0) {
        *(int*)(p + 0x250) -= 1;
        if (*(int*)(p + 0x250) == 0) {
            *(unsigned char*)(p + 0x11c) = 0;
            return;
        }
        *(int*)(p + 0x238) = 0;
    } else {
        TVec3f* src = (TVec3f*)fn_8023E724(*(int*)(p + 0x90) & 3);
        *(TVec3f*)(p + 0xc) = *src;
        *(float*)(p + 0x14) += lbl_8054075C;
        if (*(int*)(p + 0x234) > 0) {
            char* base;
            *(int*)(p + 0x234) -= 1;
            base = *(char**)(p + 4);
            if (*(unsigned char*)(base + ((int)fn_802D6A9C() + 0x10000) + 0x31df) != 0) {
                if (*(unsigned char*)(p + 0x24c) != 0) {
                    *(int*)(p + 0x230) = 0x3f;
                } else {
                    *(int*)(p + 0x230) = 0x44;
                }
            } else {
                if (*(unsigned char*)(p + 0x24c) != 0) {
                    *(int*)(p + 0x230) = 0x3d;
                } else {
                    *(int*)(p + 0x230) = 0x43;
                }
            }
        } else {
            unsigned char flag;
            int dir;
            char* pad;
            flag = 0;
            dir = -1;
            fn_8030AAF4(*(int*)(p + 0x90) & 3);
            pad = fn_8008E328();
            if (fn_8022C5EC(*(int*)(p + 0x90) & 3, 0x100)) {
                *(unsigned char*)(p + 0x244) = 0;
                *(unsigned char*)(p + 0x11c) = 0;
                if (*(int*)(p + 0x240) == *(int*)(p + 0x23c)) {
                    fn_80230EB8(*(int*)(p + 0x90) & 3, 0x58);
                }
                goto setAnim;
            }
            if (fn_8022C5EC(*(int*)(p + 0x90) & 3, 0x200) || fn_8022C5EC(*(int*)(p + 0x90) & 3, 0x40)) {
                *(unsigned char*)(p + 0x244) = 1;
                *(unsigned char*)(p + 0x11c) = 0;
                fn_80230EB8(*(int*)(p + 0x90) & 3, 0x58);
                goto setAnim;
            }
            {
                char* base = *(char**)(p + 4);
                if (*(unsigned char*)(base + ((int)fn_802D6A9C() + 0x10000) + 0x31df) != 0) {
                    *(int*)(p + 0x23c) = 5;
                    goto setAnim;
                }
            }
            if (fn_8022C52C(*(int*)(p + 0x90) & 3, 0x40)) {
                if (fn_8022C9AC(*(int*)(p + 0x90) & 3)) {
                    if (fn_8022C5EC(*(int*)(p + 0x90) & 3, 8)) {
                        dir = 0;
                    } else if (fn_8022C5EC(*(int*)(p + 0x90) & 3, 4)) {
                        dir = 1;
                    } else if (fn_8022C5EC(*(int*)(p + 0x90) & 3, 1)) {
                        dir = 2;
                    } else if (fn_8022C5EC(*(int*)(p + 0x90) & 3, 2)) {
                        dir = 3;
                    }
                }
            } else if (pad != 0 && *(unsigned char*)(p + 0x244) == 1 && fn_8022C9AC(*(int*)(p + 0x90) & 3) &&
                       *(float*)(pad + 0x60) > lbl_80540760) {
                short a = *(short*)(pad + 0x64);
                if (a < -0x7000 || a >= 0x7000) {
                    dir = 0;
                } else if (a >= -0x5000 && a < -0x3000) {
                    dir = 2;
                } else if (a >= -0x1000 && a < 0x1000) {
                    dir = 1;
                } else if (a >= 0x3000 && a < 0x5000) {
                    dir = 3;
                }
            } else {
                if (fn_8022C5EC(*(int*)(p + 0x90) & 3, 1)) {
                    fn_801F0D20(this_, 0x46);
                    if (*(unsigned char*)(p + 0x24c) != 0) {
                        *(int*)(p + 0x23c) = tbl[0][*(int*)(p + 0x23c)];
                    } else {
                        *(int*)(p + 0x23c) = tbl[1][*(int*)(p + 0x23c)];
                    }
                } else if (fn_8022C5EC(*(int*)(p + 0x90) & 3, 2)) {
                    fn_801F0D20(this_, 0x46);
                    if (*(unsigned char*)(p + 0x24c) != 0) {
                        *(int*)(p + 0x23c) = tbl[2][*(int*)(p + 0x23c)];
                    } else {
                        *(int*)(p + 0x23c) = tbl[3][*(int*)(p + 0x23c)];
                    }
                }
                goto setAnim;
            }
            if (dir >= 0) {
                if (dir == 0) {
                    if (*(unsigned char*)(p + 0x24c) != 0) {
                        *(int*)(p + 0x23c) = 2;
                    } else {
                        *(int*)(p + 0x23c) = 1;
                    }
                } else if (dir == 1) {
                    *(int*)(p + 0x23c) = 1;
                } else if (dir == 2) {
                    if (*(unsigned char*)(p + 0x24c) != 0) {
                        *(int*)(p + 0x23c) = 3;
                    } else {
                        *(int*)(p + 0x23c) = 0;
                    }
                } else {
                    *(int*)(p + 0x23c) = 0;
                }
                flag = 1;
            }
            if (flag == 1) {
                *(unsigned char*)(p + 0x244) = 0;
                if (*(int*)(p + 0x240) == *(int*)(p + 0x23c)) {
                    fn_80230EB8(*(int*)(p + 0x90) & 3, 0x58);
                }
                *(int*)(p + 0x250) = 6;
                *(int*)(p + 0x238) = 0;
            }
setAnim:
            if (*(unsigned char*)(p + 0x24c) != 0) {
                *(int*)(p + 0x230) = tbl[4][*(int*)(p + 0x23c)];
            } else {
                *(int*)(p + 0x230) = tbl[5][*(int*)(p + 0x23c)];
            }
        }
    }
    *(int*)(p + 0x238) += 1;
    if (*(int*)(p + 0x238) >= 12) {
        *(int*)(p + 0x238) = 0;
    }
    {
        char* base = *(char**)(p + 4);
        if (*(unsigned char*)(base + ((int)fn_802D6A9C() + 0x10000) + 0x31df) != 0) {
            if (*(unsigned char*)(p + 0x24c) != 0) {
                *(int*)(p + 0x230) = 0x3f;
            } else {
                *(int*)(p + 0x230) = 0x44;
            }
        } else if (*(int*)(p + 0x238) >= 6) {
            if (*(unsigned char*)(p + 0x24c) != 0) {
                *(int*)(p + 0x230) = 0x3d;
            } else {
                *(int*)(p + 0x230) = 0x43;
            }
        }
    }
}

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
    int j;
    int count;
    int n;
    int i;
    void* a;
    Vec v;
    if (fn_8022F514(*(int*)((char*)this_ + 0x90) & 3)) {
        *(unsigned char*)((char*)this_ + 0x11c) = 0;
        return;
    }
    fn_8022CF08(*(int*)((char*)this_ + 0x90) & 3);
    p = fn_8023E724(*(int*)((char*)this_ + 0x90) & 3);
    v = *(Vec*)p;
    *(Vec*)((char*)this_ + 0xc) = v;
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
        char* base;
        *(unsigned char*)((char*)this_ + 0x24c) = 1;
        base = *(char**)((char*)this_ + 4);
        if (*(unsigned char*)(base + ((int)fn_802D6A9C() + 0x10000) + 0x31df) != 0) {
            *(int*)((char*)this_ + 0x230) = 0x3f;
        } else {
            *(int*)((char*)this_ + 0x230) = 0x3d;
        }
        if (*(int*)((char*)this_ + 0x23c) == 5) {
            *(int*)((char*)this_ + 0x23c) = 3;
        }
    } else {
        char* base;
        *(unsigned char*)((char*)this_ + 0x24c) = 0;
        base = *(char**)((char*)this_ + 4);
        if (*(unsigned char*)(base + ((int)fn_802D6A9C() + 0x10000) + 0x31df) != 0) {
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
    i = 0;
    count = *(int*)((char*)fn_801F856C() + 0x1008);
    j = i;
    for (; i < count; i++) {
        a = *(void**)((char*)fn_801F856C() + j + 8);
        if (a != 0 && *(int*)((char*)a + 0x1a0) == 0x4647414c && *(unsigned char*)((char*)a + 0x11c) == 1) {
            *(void**)((char*)this_ + 0x254) = a;
        }
        j += 4;
    }
}

