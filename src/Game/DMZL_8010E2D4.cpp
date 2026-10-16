#include "types.h"
#include "Game/Actor.h"

extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_8010DF78(void* this_);
extern "C" void fn_8010F7EC(void*, s32);
extern "C" void fn_80110E9C(void*);
extern "C" void fn_8011093C(void*);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_8010F4DC(void*);
extern "C" void fn_8010E7E8(void*, s32);
extern "C" void fn_8010E2D4(void*, s32);
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
