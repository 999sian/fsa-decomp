#include "types.h"
#include "Game/Actor.h"

typedef f32 Mtx[3][4];
typedef struct MtxBox {
    Mtx m;
} MtxBox;
extern "C" void PSMTXTrans(Mtx m, f32 xT, f32 yT, f32 zT);
extern "C" void PSMTXConcat(const Mtx a, const Mtx b, Mtx ab);
extern const f32 lbl_8053C550;
extern const f32 lbl_8053C55C;
extern const f32 lbl_8053C5C8;
extern const f32 lbl_8053C5CC;
extern const f32 lbl_8053C5D0;
extern "C" void* fn_801902C0(void);

extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_8010DF78(void* this_);
extern "C" void fn_8010F7EC(void*, s32);
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

extern "C" void* fn_8010FA84(u8* this_) {
#if defined(VERSION_G4SP01)
    return *(void**)(this_ + 0x23c);
#else
    return *(void**)(this_ + 0x238);
#endif
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

extern "C" void fn_8010F478(u8* this_, s32 param_2) {
    switch (*(s32*)(this_ + 0x234)) {
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

void fn_8010F668(f32 m[3][4], f32 axis[3], f32 angle) {
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
