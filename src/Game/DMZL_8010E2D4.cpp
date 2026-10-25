#include "types.h"
#include "Game/SinitPoolChain.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"

typedef f32 Mtx[3][4];
typedef struct MtxBox {
    Mtx m;
} MtxBox;
extern "C" void PSMTXTrans(Mtx m, f32 xT, f32 yT, f32 zT);
extern "C" void PSMTXConcat(const Mtx a, const Mtx b, Mtx ab);
extern "C" void PSMTXCopy(const Mtx src, Mtx dst);
extern const f32 lbl_8053C550;
extern const f32 lbl_8053C55C;
extern const f32 lbl_8053C5C8;
extern const f32 lbl_8053C5CC;
extern const f32 lbl_8053C5D0;
extern "C" void* fn_801902C0(void);
extern const f32 lbl_8053C554;
extern const f32 lbl_8053C570;
extern const f32 lbl_8053C58C;
extern const f32 lbl_8053C590;
extern const f32 lbl_8053C59C;
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void fn_8013CC50(u32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void* fn_801C0D70(void);
extern "C" void fn_801C11A4(void);
extern "C" void fn_801C115C(void);
extern "C" void fn_80118454(void);
extern "C" void fn_80118384(void);
extern "C" void fn_801183BC(void);
extern "C" void fn_8022FE80(s32, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(void*);
extern "C" u8 fn_8038BD08(s32, s32, s32, void*, s32);
extern "C" void fn_802D8050(void*, s32, s32, s32);

extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_8010DF78(void* this_);
extern "C" void fn_8010F7EC(u8*, s32);
extern "C" void fn_80110E9C(void*);
extern "C" void fn_8011093C(void*);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_8010F4DC(u8* this_);
extern "C" void fn_8010E7E8(void*, s32);
extern "C" void fn_8010E2D4(void*, s32);
extern "C" void fn_8010F668(f32 m[3][4], f32 axis[3], f32 angle);
extern "C" void* fn_8011921C(void);
extern "C" void* fn_8011871C(void* list, void* it, u32 tag);
extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_8049D208[];
extern "C" char lbl_8049CC34[];
extern char lbl_8046464C[];
extern char lbl_80464660[];
extern const f32 lbl_8053C560;
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];

struct SwbmDrawParam {
    SwbmDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};
extern "C" void fn_801F02BC(void* this_, const char* name, s32 idx, SwbmDrawParam* prm, s32 a, s32 b, s32 c, f32 s0, f32 s1);

extern "C" void* fn_8010FA84(u8* this_) {
#if defined(VERSION_G4SP01)
    return *(void**)(this_ + 0x23c);
#else
    return *(void**)(this_ + 0x238);
#endif
}

extern char lbl_80464550[];
extern "C" void fn_8010F478(u8* this_, s32 param_2);
extern "C" void fn_8010FA8C(u8* this_) {
    void* a = fn_8011921C();
    s32 state = *(s32*)(this_ + 0x234);
    s32 v = *(s32*)((u8*)a + 8);
    switch (state) {
    case 0:
        a = fn_8011921C();
        if (*(s32*)((u8*)a + 4) == 0) {
            if (v == *(s32*)(lbl_80464550 + 0xc)) {
                fn_8010F478(this_, 3);
            } else if (v == *(s32*)(lbl_80464550 + 0x10)) {
                fn_8010F478(this_, 4);
            } else if (v == *(s32*)(lbl_80464550 + 0x14)) {
                fn_8010F478(this_, 5);
            } else if (v == *(s32*)(lbl_80464550 + 0x18)) {
                fn_8010F478(this_, 6);
            } else if (v == *(s32*)(lbl_80464550 + 0x1c)) {
                fn_8010F478(this_, 7);
            } else if (v == *(s32*)(lbl_80464550 + 0x20)) {
                fn_8010F478(this_, 8);
            } else if (v == *(s32*)(lbl_80464550 + 0x24)) {
                fn_8010F478(this_, 9);
            } else if (v == *(s32*)(lbl_80464550 + 0x28)) {
                fn_8010F478(this_, 0xa);
            } else if (v == *(s32*)(lbl_80464550 + 0x2c)) {
                fn_8010F478(this_, 0xb);
            } else if (v == *(s32*)(lbl_80464550 + 0x30)) {
                fn_8010F478(this_, 0xc);
            } else if (v == *(s32*)(lbl_80464550 + 0x34)) {
                fn_8010F478(this_, 0xd);
                fn_8010F478(this_, 0x25);
            }
        }
        break;
    case 1:
        a = fn_8011921C();
        if (*(s32*)((u8*)a + 4) == 1) {
            if (v == *(s32*)(lbl_80464550 + 0x38)) {
                fn_8010F478(this_, 0xe);
            } else if (v == *(s32*)(lbl_80464550 + 0x3c)) {
                fn_8010F478(this_, 0xf);
            } else if (v == *(s32*)(lbl_80464550 + 0x40)) {
                fn_8010F478(this_, 0x10);
            } else if (v == *(s32*)(lbl_80464550 + 0x44)) {
                fn_8010F478(this_, 0x11);
            } else if (v == *(s32*)(lbl_80464550 + 0x48)) {
                fn_8010F478(this_, 0x12);
            } else if (v == *(s32*)(lbl_80464550 + 0x4c)) {
                fn_8010F478(this_, 0x13);
            } else if (v == *(s32*)(lbl_80464550 + 0x50)) {
                fn_8010F478(this_, 0x14);
            } else if (v == *(s32*)(lbl_80464550 + 0x54)) {
                fn_8010F478(this_, 0x15);
            } else if (v == *(s32*)(lbl_80464550 + 0x58)) {
                fn_8010F478(this_, 0x16);
            } else if (v == *(s32*)(lbl_80464550 + 0x5c)) {
                fn_8010F478(this_, 0x17);
            } else if (v == *(s32*)(lbl_80464550 + 0x60)) {
                fn_8010F478(this_, 0x18);
            } else if (v == *(s32*)(lbl_80464550 + 0x64)) {
                fn_8010F478(this_, 0x19);
            } else if (v == *(s32*)(lbl_80464550 + 0x68)) {
                fn_8010F478(this_, 0x1a);
            } else if (v == *(s32*)(lbl_80464550 + 0x6c)) {
                fn_8010F478(this_, 0x1b);
            } else if (v == *(s32*)(lbl_80464550 + 0x70)) {
                fn_8010F478(this_, 0x1c);
            } else if (v == *(s32*)(lbl_80464550 + 0x74)) {
                fn_8010F478(this_, 0x1d);
            } else if (v == *(s32*)(lbl_80464550 + 0x78)) {
                fn_8010F478(this_, 0x1e);
            } else if (v == *(s32*)(lbl_80464550 + 0x7c)) {
                fn_8010F478(this_, 0x1f);
            } else if (v == *(s32*)(lbl_80464550 + 0x80)) {
                fn_8010F478(this_, 0x20);
            } else if (v == *(s32*)(lbl_80464550 + 0x84)) {
                fn_8010F478(this_, 0x21);
            } else if (v == *(s32*)(lbl_80464550 + 0x88)) {
                fn_8010F478(this_, 0x22);
            } else if (v == *(s32*)(lbl_80464550 + 0x8c)) {
                fn_8010F478(this_, 0x23);
            } else if (v == *(s32*)(lbl_80464550 + 0x94)) {
                fn_8010F478(this_, 0x3e);
            }
        }
        break;
    case 2:
        a = fn_8011921C();
        {
            s32 r = *(s32*)((u8*)a + 4);
            if (r != 0xe) {
                if (r > 0xe) {
                    if (r < 0x10) {
                        if (v == *(s32*)(lbl_80464550 + 0x98)) {
                            fn_8010F478(this_, 0x26);
                        } else if (v == *(s32*)(lbl_80464550 + 0x9c)) {
                            fn_8010F478(this_, 0x27);
                        } else if (v == *(s32*)(lbl_80464550 + 0xa0)) {
                            fn_8010F478(this_, 0x28);
                        } else if (v == *(s32*)(lbl_80464550 + 0xa4)) {
                            fn_8010F478(this_, 0x29);
                        } else if (v == *(s32*)(lbl_80464550 + 0xa8)) {
                            fn_8010F478(this_, 0x2a);
                        } else if (v == *(s32*)(lbl_80464550 + 0xac)) {
                            fn_8010F478(this_, 0x2b);
                        } else if (v == *(s32*)(lbl_80464550 + 0xb0)) {
                            fn_8010F478(this_, 0x2c);
                        } else if (v == *(s32*)(lbl_80464550 + 0xb4)) {
                            fn_8010F478(this_, 0x2d);
                        } else if (v == *(s32*)(lbl_80464550 + 0xb8)) {
                            fn_8010F478(this_, 0x2e);
                        } else if (v == *(s32*)(lbl_80464550 + 0xbc)) {
                            fn_8010F478(this_, 0x2f);
                        }
                    }
                } else if (r >= 0xd) {
                    if (v == *(s32*)(lbl_80464550 + 0xc0)) {
                        fn_8010F478(this_, 0x30);
                    } else if (v == *(s32*)(lbl_80464550 + 0xc8)) {
                        fn_8010F478(this_, 0x32);
                    } else if (v == *(s32*)(lbl_80464550 + 0xcc)) {
                        fn_8010F478(this_, 0x33);
                    } else if (v == *(s32*)(lbl_80464550 + 0xd0)) {
                        fn_8010F478(this_, 0x34);
                    } else if (v == *(s32*)(lbl_80464550 + 0xd4)) {
                        fn_8010F478(this_, 0x35);
                    } else if (v == *(s32*)(lbl_80464550 + 0xd8)) {
                        fn_8010F478(this_, 0x36);
                    } else if (v == *(s32*)(lbl_80464550 + 0xdc)) {
                        fn_8010F478(this_, 0x37);
                    } else if (v == *(s32*)(lbl_80464550 + 0xe0)) {
                        fn_8010F478(this_, 0x38);
                    } else if (v == *(s32*)(lbl_80464550 + 0xe4)) {
                        fn_8010F478(this_, 0x39);
                    } else if (v == *(s32*)(lbl_80464550 + 0xe8)) {
                        fn_8010F478(this_, 0x3a);
                    } else if (v == *(s32*)(lbl_80464550 + 0xec)) {
                        fn_8010F478(this_, 0x3b);
                    } else if (v == *(s32*)(lbl_80464550 + 0xf0)) {
                        fn_8010F478(this_, 0x3c);
                    } else if (v == *(s32*)(lbl_80464550 + 0xf4)) {
                        fn_8010F478(this_, 0x3d);
                    }
                }
            }
        }
        break;
    }
}

extern "C" void fn_80110198(u8* this_) {
    fn_8010DF58(this_);
    if (this_[0x230] == 0) {
        if (*(s32*)(this_ + 0x2fc) >= 0x13) {
            fn_8010F7EC(this_, 0x21b);
        } else if (*(s32*)(this_ + 0x2fc) >= 0xf) {
            fn_8010F7EC(this_, 0x274);
        } else {
            fn_8010F7EC(this_, 0x9b);
        }
    }
}

extern "C" void fn_8030C210(void* p, void* q);
extern "C" u8* lbl_8053AB10;
extern "C" Vec* fn_8023E724(s32);
extern "C" void fn_801CD950(f32*, f32, f32);
extern const f32 lbl_8053C598;
extern const f32 lbl_8053C5D8;
extern const f32 lbl_8053C5DC;
extern const f32 lbl_8053C5E0;
extern const f32 lbl_8053C5E4;
extern const f32 lbl_8053C594;
extern const f32 lbl_8053C5A0;

static inline f32 DMZLShiftY(const f32 y, const f32 offset) { return y + offset; }
static inline void DMZLSetBox(const f32 x0, const f32 y0, const f32 x1, const f32 y1) {
    u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
    if (obj[0x840] == 0) {
        obj[0x840] = 1;
        *(f32*)(obj + 0x844) = x0;
        *(f32*)(obj + 0x848) = y0;
        *(f32*)(obj + 0x84c) = x1;
        *(f32*)(obj + 0x850) = y1;
        *(f32*)(obj + 0x854) = lbl_8053C550;
        *(f32*)(obj + 0x1d4) = lbl_8053C5D0;
        *(f32*)(obj + 0x1d8) = lbl_8053C5D0;
    }
}
static inline void DMZLSetBoxAlt(const f32 x0, const f32 y0, const f32 x1, const f32 y1) {
    u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
    if (obj[0x7f5] == 0) {
        obj[0x7f4] = 1;
        *(s32*)(obj + 0x7f8) = 5;
        *(f32*)(obj + 0x808) = x0;
        *(f32*)(obj + 0x80c) = y0;
        *(f32*)(obj + 0x810) = x1;
        *(f32*)(obj + 0x814) = y1;
        obj[0x7f6] = 0;
    }
}

extern "C" void fn_80110210(u8* this_) {
    u8* obj;
    Vec tmp;
    f32 x;
    f32 sum;
    f32 f274;

    switch (*(s32*)(this_ + 0x238)) {
    case 38:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        break;
    case 39:
    case 40:
    case 41:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
        sum = *(f32*)(this_ + 0x10) + *(f32*)(this_ + 0x278);
        f274 = *(f32*)(this_ + 0x274);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        x = *(f32*)(this_ + 0xc);
        if (obj[0x7f5] == 0) {
            obj[0x7f4] = 1;
            *(s32*)(obj + 0x7f8) = 5;
            *(f32*)(obj + 0x808) = x;
            *(f32*)(obj + 0x80c) = sum - f274;
            *(f32*)(obj + 0x810) = x;
            *(f32*)(obj + 0x814) = f274 + sum;
            obj[0x7f6] = 0;
        }
        break;
    case 42:
    case 43:
    case 44:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
        sum = *(f32*)(this_ + 0x10) + *(f32*)(this_ + 0x278);
        f274 = *(f32*)(this_ + 0x274);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        x = *(f32*)(this_ + 0xc);
        if (obj[0x7f5] == 0) {
            obj[0x7f4] = 1;
            *(s32*)(obj + 0x7f8) = 5;
            *(f32*)(obj + 0x808) = x;
            *(f32*)(obj + 0x80c) = sum - f274;
            *(f32*)(obj + 0x810) = x;
            *(f32*)(obj + 0x814) = f274 + sum;
            obj[0x7f6] = 0;
        }
        break;
    case 45:
    case 46:
    case 47:
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        if (obj[0x7f4] == 0) {
            obj[0x7f5] = 1;
        }
        break;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        sum = *(f32*)(this_ + 0x10);
        f274 = *(f32*)(this_ + 0x274);
        x = *(f32*)(this_ + 0xc);
        if (obj[0x840] == 0) {
            obj[0x840] = 1;
            *(f32*)(obj + 0x844) = x;
            *(f32*)(obj + 0x848) = sum - f274;
            *(f32*)(obj + 0x84c) = x;
            *(f32*)(obj + 0x850) = sum + f274;
            *(f32*)(obj + 0x854) = lbl_8053C550;
            *(f32*)(obj + 0x1d4) = lbl_8053C5D0;
            *(f32*)(obj + 0x1d8) = lbl_8053C5D0;
        }
        break;
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x17c) = 1;
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;
        tmp = *(Vec*)(this_ + 0x24);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        sum = tmp.y + *(f32*)(this_ + 0x278);
        f274 = *(f32*)(this_ + 0x274);
        tmp.y = sum;
        if (obj[0x7f5] == 0) {
            obj[0x7f4] = 1;
            *(s32*)(obj + 0x7f8) = 5;
            *(f32*)(obj + 0x808) = tmp.x;
            *(f32*)(obj + 0x80c) = sum - f274;
            *(f32*)(obj + 0x810) = tmp.x;
            *(f32*)(obj + 0x814) = sum + f274;
            obj[0x7f6] = 0;
        }
        break;
    case 59:
    case 60:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        break;
    }
}

extern "C" void fn_80110454(u8* p) {
    switch (*(s32*)(p + 0x238)) {
    case 3: case 4: case 5: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *fn_8023E724(0);
        tmp.y = DMZLShiftY(tmp.y, lbl_8053C5D8);
        DMZLSetBox(tmp.x, tmp.y - lbl_8053C598, tmp.x, lbl_8053C598 + tmp.y);
        break;
    }
    case 6: case 7: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *fn_8023E724(0);
        tmp.y = DMZLShiftY(tmp.y, *(f32*)(p + 0x278));
        DMZLSetBoxAlt(tmp.x, tmp.y - lbl_8053C598, tmp.x, lbl_8053C598 + tmp.y);
        break;
    }
    case 8: case 9: case 10: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *fn_8023E724(0);
        fn_801CD950((f32*)(p + 0x278), lbl_8053C5D8, lbl_8053C550);
        tmp.y = DMZLShiftY(tmp.y, *(f32*)(p + 0x278));
        DMZLSetBoxAlt(tmp.x, tmp.y - lbl_8053C598, tmp.x, lbl_8053C598 + tmp.y);
        break;
    }
    case 11: case 12: case 13:
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x17d) = 1;

        break;
    case 14: case 15: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x17c) = 1;

        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *(Vec*)(p + 0x24);
        tmp.y = DMZLShiftY(tmp.y, lbl_8053C5A0);
        DMZLSetBox(tmp.x, tmp.y - lbl_8053C5DC, tmp.x, lbl_8053C5DC + tmp.y);
        break;
    }
    case 16: case 17: case 18: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        DMZLSetBox(*(f32*)(p + 0x24), *(f32*)(p + 0x28) - lbl_8053C5E0, *(f32*)(p + 0x24), lbl_8053C5E0 + *(f32*)(p + 0x28));
        break;
    }
    case 19: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        DMZLSetBox(*(f32*)(p + 0x2d0), *(f32*)(p + 0x2d4) - lbl_8053C5E0, *(f32*)(p + 0x2d0), lbl_8053C5E0 + *(f32*)(p + 0x2d4));
        break;
    }
    case 20: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *(Vec*)(p + 0xc);
        tmp.y = DMZLShiftY(tmp.y, lbl_8053C5E4);
        DMZLSetBox(tmp.x, tmp.y - lbl_8053C594, tmp.x, lbl_8053C594 + tmp.y);
        break;
    }
    case 21: case 22: case 23: {
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x179) = 1;

        JGeometry::TVec3<f32> tmp = *(Vec*)(p + 0xc);
        tmp.y = DMZLShiftY(tmp.y, lbl_8053C5E4);
        DMZLSetBoxAlt(tmp.x, tmp.y - lbl_8053C594, tmp.x, lbl_8053C594 + tmp.y);
        break;
    }
    case 24: case 25: case 26: case 27: case 28: {
        u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
        if (obj[0x179] == 0) {
            obj[0x17a] = 1;
            obj[0x179] = 0;
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
        obj = *(u8**)(lbl_8053AB10 + 0x24);
        if (obj[0x840] == 0) {
            obj[0x840] = 1;
            f32 x = *(f32*)(p + 0xc);
            *(f32*)(obj + 0x84c) = x;
            *(f32*)(obj + 0x844) = x;
            f32 y = *(f32*)(p + 0x10);
            *(f32*)(obj + 0x850) = y;
            *(f32*)(obj + 0x848) = y;
            *(f32*)(obj + 0x854) = lbl_8053C550;
            *(f32*)(obj + 0x1d4) = lbl_8053C5D0;
            *(f32*)(obj + 0x1d8) = lbl_8053C5D0;
        }
        break;
    }
    }
}

extern "C" void fn_80111CC0(u8* this_) {
    fn_8010DF78(this_);
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
    case 1:
        fn_80110E9C(this_);
        break;
    case 2:
        fn_8011093C(this_);
        break;
    case 3:
        break;
    }
    fn_801D1C18(this_ + 0x2f4);
    fn_801D1C18(this_ + 0x32c);
    if (this_[0x230] != 0) {
        fn_8010F4DC(this_);
    }
}

extern "C" void fn_80111D44(u8* this_) {
    u8* list;
    u8** it;
    u8* elem;
    s32 idx;
    Vec tmp;

    list = (u8*)fn_8011921C();
    it = (u8**)fn_8011871C(list, *(void**)(list + 0x10), 0x444d474c);
    if (it != *(u8***)((u8*)fn_8011921C() + 0x14)) {
        elem = *it;
        tmp = *(Vec*)(elem + 0xc);
        *(Vec*)(this_ + 0x27c) = tmp;
    }

    list = (u8*)fn_8011921C();
    it = (u8**)fn_8011871C(fn_8011921C(), *(void**)(list + 0x10), 0x444d4d44);
    if (it != *(u8***)((u8*)fn_8011921C() + 0x14)) {
        do {
            elem = *it;
            idx = *(s32*)(elem + 0x234);
            if (idx < 6) {
                tmp = *(Vec*)(elem + 0xc);
                *(Vec*)(this_ + 0x288 + idx * 12) = tmp;
            }
            it++;
        } while (it != *(u8***)((u8*)fn_8011921C() + 0x14));
    }

    tmp = *(Vec*)(this_ + 0xc);
    *(Vec*)(this_ + 0x2d0) = tmp;
}

extern "C" void fn_8010DF98(void*);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void*, s32);
extern "C" char lbl_8049D1A0[];
extern "C" void* lbl_80539EF8;
extern "C" const f32 lbl_8053C55C;
extern "C" void fn_80111E38(u8* this_) {
    fn_8010DF98(this_);
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xff;
    *(u32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    *(u32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 17) & 0x1f;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    fn_801D2608(this_ + 0x2f4, lbl_8049D1A0, 0x1a);
    fn_801D22DC(this_ + 0x2f4, 8, 2, 0);
    fn_801D1F14(this_ + 0x2f4, lbl_8053C55C);
    fn_801D2608(this_ + 0x32c, (void*)&lbl_80539EF8, 2);
    fn_801D22DC(this_ + 0x32c, 0, 2, 0);
    fn_801D1F14(this_ + 0x32c, lbl_8053C55C);
    if (*(s32*)(this_ + 0x234) == 2) {
        if (fn_802D800C(fn_802D6A9C(), *(s32*)(this_ + 0x250))) {
            switch (*(s32*)(this_ + 0x234)) {
            case 0:
            case 1:
                fn_8010E7E8(this_, 0x3d);
                break;
            case 2:
                fn_8010E2D4(this_, 0x3d);
                break;
            case 3:
            default:
                break;
            }
            *(s32*)(this_ + 0x238) = 0x3d;
        } else {
            this_[0x11d] = 0;
        }
    }
}

extern "C" void* fn_80111F74(char* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_8049D208;
        fn_801EE434(*(void**)(p + 0x364));
        *(s32*)(p + 0x364) = 0;
        fn_801EE434(*(void**)(p + 0x368));
        *(s32*)(p + 0x368) = 0;
        fn_801EE434(*(void**)(p + 0x36c));
        *(s32*)(p + 0x36c) = 0;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x370 + i * 4));
            *(s32*)(p + 0x370 + i * 4) = 0;
            if (i < 2) {
                fn_801EE434(*(void**)(p + 0x380 + i * 4));
                *(s32*)(p + 0x380 + i * 4) = 0;
            }
        }
        if (p + 0x32c != 0) {
            if (p + 0x350 != 0) {
                *(void**)(p + 0x350) = lbl_8049CC34;
            }
        }
        if (p + 0x2f4 != 0) {
            if (p + 0x318 != 0) {
                *(void**)(p + 0x318) = lbl_8049CC34;
            }
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_8010E074(void* this_);
extern "C" void fn_801D267C(void* this_);
extern const f32 lbl_8053C55C;
extern const f32 lbl_8053C5FC;
extern const f32 lbl_8053C598;
extern void __construct_array(void* p, void* ctor, void* dtor, s32 size, s32 count);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
extern "C" void __construct_array(void*, void*, void*, long, long);
extern "C" void* fn_80112070(u8* this_) {
    fn_8010E074(this_);
    *(void**)this_ = lbl_8049D208;
    this_[0x230] = 0;
    this_[0x231] = 0;
    *(s32*)(this_ + 0x234) = 4;
    *(s32*)(this_ + 0x238) = 1;
    *(s32*)(this_ + 0x23c) = -1;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = -1;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(f32*)(this_ + 0x268) = lbl_8053C55C;
    *(f32*)(this_ + 0x26c) = lbl_8053C55C;
    *(f32*)(this_ + 0x270) = lbl_8053C5FC;
    *(f32*)(this_ + 0x274) = lbl_8053C598;
    *(f32*)(this_ + 0x278) = lbl_8053C55C;
    __construct_array(this_ + 0x288, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 7);
    fn_801D267C(this_ + 0x2f4);
    fn_801D267C(this_ + 0x32c);
    *(s32*)(this_ + 0x364) = 0;
    *(s32*)(this_ + 0x368) = 0;
    *(s32*)(this_ + 0x36c) = 0;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(this_ + 0x370 + i * 4) = 0;
        if (i < 2) {
            *(s32*)(this_ + 0x380 + i * 4) = 0;
        }
    }
    return this_;
}

extern "C" void fn_8010E2D4(void* this_, s32 param) {
    u8* p = (u8*)this_;
    switch ((u32)param) {
    case 0:
    case 1:
    case 2:
        fn_801C0D70();
        fn_801C11A4();
        break;
    case 3:
    case 4: {
        u8* q = (u8*)fn_8011921C();
        q[2] = 1;
        *(f32*)(p + 0x274) = lbl_8053C594;
        *(f32*)(p + 0x278) = lbl_8053C554;
        break;
    }
    case 5:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C550, 0x4d3, 0, 0, 0, 0, 1);
    case 6:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C550, 0x4d4, 0, 0, 0, 0, 1);
    case 7:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C550, 0x4d5, 0, 0, 0, 0, 1);
    case 8:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C550, 0x4d6, 0, 0, 0, 0, 1);
    case 9:
    case 10:
        fn_801F0E34(p, 0x30079, 0);
        break;
    case 11:
        p[0x11d] = 1;
        *(u16*)fn_801C0D70() |= 0x800;
        break;
    case 12:
    case 13: {
        Vec v;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        v.x = lbl_8053C55C;
        v.y = lbl_8053C570;
        v.z = lbl_8053C55C;
        if (fn_8038BD08(0, 0x2d4, *(s32*)(p + 4), &v, 0x4002)) {
            fn_8011921C();
            fn_80118454();
        }
        break;
    }
    case 14:
        fn_801D22DC(p + 0x2f4, 0xf, 0, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 15:
    case 16:
        fn_801D22DC(p + 0x2f4, 0x15, 0, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 17:
        fn_801D22DC(p + 0x2f4, 0x14, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        fn_801C0D70();
        fn_801C115C();
        break;
    case 18:
    case 19: {
        Vec v;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        v.x = lbl_8053C55C;
        v.y = lbl_8053C570;
        v.z = lbl_8053C55C;
        if (fn_8038BD08(0, 0x2d3, *(s32*)(p + 4), &v, 0x4002)) {
            fn_8011921C();
            fn_80118454();
        }
        break;
    }
    case 20:
        fn_801D22DC(p + 0x2f4, 0x13, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        *(u16*)fn_801C0D70() &= ~0x400;
        fn_8011921C();
        fn_80118384();
        *(s32*)(p + 0x264) = 0;
        break;
    case 21:
    case 22: {
        u8* q;
        *(f32*)(p + 0x274) = lbl_8053C598;
        fn_802D8050(fn_802D6A9C(), *(s32*)(p + 0x254), 1, 0xff);
        q = (u8*)fn_8011921C();
        q[2] = 1;
        fn_8011921C();
        fn_80118454();
        break;
    }
    case 23:
        fn_801D22DC(p + 0x2f4, 0x14, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        fn_8011921C();
        fn_801183BC();
        break;
    case 24:
    case 25: {
        Vec v;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        fn_8022FD8C(*(void**)(p + 0x198));
        v.x = lbl_8053C55C;
        v.y = lbl_8053C55C;
        v.z = lbl_8053C55C;
        fn_8038BD08(0, 0x2d1, *(s32*)(p + 4), &v, 0x22);
        fn_8011921C();
        fn_80118454();
        break;
    }
    case 26:
        fn_801D22DC(p + 0x2f4, 0x13, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        *(u16*)fn_801C0D70() &= ~0x1000;
        break;
    case 27:
    case 28: {
        Vec v;
        fn_8022FE80(0, *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        v.x = lbl_8053C55C;
        v.y = lbl_8053C570;
        v.z = lbl_8053C55C;
        if (fn_8038BD08(0, 0x2d5, *(s32*)(p + 4), &v, 0x4002)) {
            fn_8011921C();
            fn_80118454();
        }
        break;
    }
    case 29:
        *(s32*)(p + 0x24c) = 0;
        *(f32*)(p + 0x274) = lbl_8053C598;
        *(f32*)(p + 0x278) = lbl_8053C590;
        fn_801D22DC(p + 0x2f4, 0xd, 0, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 30:
    case 31:
        fn_801D22DC(p + 0x2f4, 0x12, 0, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 32:
    case 33:
    case 34:
        ((void (*)(void*, s32, s32))((void**)*(void**)this_)[12])(this_, 0xff, 1);
        break;
    case 35:
        fn_801D22DC(p + 0x2f4, 0x8, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        break;
    case 36:
    case 37:
        fn_801D22DC(p + 0x2f4, 0x0, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        *(f32*)(p + 0x324) = lbl_8053C58C;
        break;
    case 38:
    case 39:
    case 40:
        fn_801D22DC(p + 0x2f4, 0x8, 2, 0);
        fn_801D1F14(p + 0x2f4, lbl_8053C55C);
        *(f32*)(p + 0x324) = lbl_8053C550;
        break;
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
        p[0x231] = 1;
        fn_802D8050(fn_802D6A9C(), *(s32*)(p + 0x250), 1, 0xff);
        *(f32*)(p + 0xc) = lbl_8053C59C + *(f32*)(p + 0x24);
        break;
    }
}

extern "C" void fn_8010F478(u8* this_, s32 param_2) {
    switch (*(s32*)(this_ + 0x234)) {
    case 3:
    default:
        break;
    case 0:
    case 1:
        fn_8010E7E8(this_, param_2);
        break;
    case 2:
        fn_8010E2D4(this_, param_2);
        break;
    }
    *(s32*)(this_ + 0x238) = param_2;
}

extern "C" void fn_8010F4DC(u8* this_) {
    Vec v1;
    Vec v2;
    Mtx m1;
    Mtx m2;
    u8* e;
    s32 n;
    f32 z;

    *(f32*)(this_ + 0x268) = *(f32*)(this_ + 0x268) + lbl_8053C5C8;
    PSMTXTrans(m1, *(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14));
    v1.x = lbl_8053C550;
    v1.y = lbl_8053C55C;
    v1.z = lbl_8053C55C;
    fn_8010F668(m1, (f32*)&v1, lbl_8053C5CC);
    m2[2][3] = lbl_8053C55C;
    m2[1][3] = lbl_8053C55C;
    m2[0][3] = lbl_8053C55C;
    m2[2][2] = lbl_8053C55C;
    m2[1][2] = lbl_8053C55C;
    m2[0][2] = lbl_8053C55C;
    m2[2][1] = lbl_8053C55C;
    m2[1][1] = lbl_8053C55C;
    m2[0][1] = lbl_8053C55C;
    m2[2][0] = lbl_8053C55C;
    m2[1][0] = lbl_8053C55C;
    m2[0][0] = lbl_8053C55C;
    v2.x = lbl_8053C55C;
    v2.y = lbl_8053C55C;
    v2.z = lbl_8053C550;
    fn_8010F668(m2, (f32*)&v2, *(f32*)(this_ + 0x268));
    PSMTXConcat(m1, m2, m1);

    n = *(s32*)(this_ + 0x240) + 1;
    *(s32*)(this_ + 0x240) = n;
    if (*(s32*)(this_ + 0x240) >= 0xc8) {
        *(s32*)(this_ + 0x240) = 0;
    }
    n = *(s32*)(this_ + 0x240);
    z = *(f32*)(this_ + 0x270);
    e = (u8*)fn_801902C0();
    if (*(u32*)(e + 0x284) != 0 && e[0x2a4] == 0) {
        e[0x2a4] = 1;
        *(f32*)(e + 0x248) = z;
        *(f32*)(e + 0x24c) = z;
        *(f32*)(e + 0x250) = z;
        PSMTXCopy(m1, *(Mtx*)(e + 0x254));
        *(f32*)(e + 0x290) = lbl_8053C5D0;
        *(s32*)(e + 0x294) = n;
        *(s32*)(e + 0x29c) = 0;
        *(s32*)(e + 0x2a0) = 1;
    }
}

extern const f32 lbl_8053C58C;
extern const f32 lbl_8053C5B4;
extern const f32 lbl_8053C5D4;
extern int __float_epsilon[];
extern "C" f64 sin(f64);
extern "C" f64 cos(f64);
void fn_8010F668(f32 m[3][4], f32 axis[3], f32 angle) {
    f32 v[3];
    f32 len2 = (axis[2] * axis[2] + axis[0] * axis[0]) + (axis[2] * axis[2] + axis[1] * axis[1]);

    if (len2 <= lbl_8053C5B4 * *(f32*)__float_epsilon) {
        v[0] = lbl_8053C55C;
        v[1] = lbl_8053C55C;
        v[2] = lbl_8053C55C;
    } else {
        f32 inv;
        if (len2 <= lbl_8053C55C) {
            inv = len2;
        } else {
            f32 y = __frsqrte(len2);
            inv = lbl_8053C58C * y * (lbl_8053C5D4 - (len2 * (y * y)));
        }
        v[0] = axis[0] * inv;
        v[1] = axis[1] * inv;
        v[2] = axis[2] * inv;
    }

    f32 s = sin(angle);
    f32 c = cos(angle);
    f32 t = lbl_8053C550 - c;
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];

    m[0][0] = t * (x * x) + c;
    m[0][1] = t * x * y - s * z;
    m[0][2] = t * x * z + s * y;
    m[1][0] = t * x * y + s * z;
    m[1][1] = t * (y * y) + c;
    m[1][2] = t * y * z - s * x;
    m[2][0] = t * x * z - s * y;
    m[2][1] = t * y * z + s * x;
    m[2][2] = t * (z * z) + c;
}

extern "C" void fn_8010F7EC(u8* this_, s32 param) {
    SwbmDrawParam prm;
    Mtx m;
    prm.reset();
    prm.m4D = *(u32*)(this_ + 0x24c);
    if (*(s32*)(this_ + 0x238) == 0x2f) {
        *(s32*)(this_ + 0x264) += 0x258;
        if (*(s32*)(this_ + 0x264) >= 0x10000) {
            *(s32*)(this_ + 0x264) -= 0x10000;
        }
        f32 s = sincosTable___5JMath[(u16)*(s32*)(this_ + 0x264) >> 5].sin;
        m[0][0] = lbl_8053C550;
        m[0][1] = lbl_8053C55C;
        m[0][2] = lbl_8053C55C;
        m[0][3] = lbl_8053C55C;
        m[1][0] = lbl_8053C55C;
        m[1][1] = lbl_8053C550;
        m[1][2] = lbl_8053C55C;
        m[1][3] = lbl_8053C55C;
        m[2][0] = lbl_8053C55C;
        m[2][1] = lbl_8053C55C;
        m[2][2] = lbl_8053C550;
        m[2][3] = lbl_8053C560 * s;
        prm.mMtx = m;
    }
    if (param == 0x21b) {
        fn_801F02BC(this_, lbl_8046464C, param + *(s32*)(this_ + 0x304), &prm, 0x407, 0, 0, lbl_8053C550, lbl_8053C550);
    } else {
        fn_801F02BC(this_, lbl_80464660, param + *(s32*)(this_ + 0x304), &prm, 0x407, 0, 0, lbl_8053C550, lbl_8053C550);
    }
}

extern "C" void fn_8010F9F0(u8* p) {
    switch (*(s32*)(p + 0x234)) {
    case 0:
    case 1:
        fn_8010E7E8(p, 0x31);
        break;
    case 2:
        fn_8010E2D4(p, 0x31);
        break;
    case 3:
        break;
    }
    *(s32*)(p + 0x238) = 0x31;
}

extern "C" s32 fn_8010FA54(u8* this_) {
#if defined(VERSION_G4SP01)
    switch (*(s32*)(this_ + 0x23c)) {
#else
    switch (*(s32*)(this_ + 0x238)) {
#endif
    case 47:
    case 61:
    case 62:
        return 1;
    }
    return 0;
}
