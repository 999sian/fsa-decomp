#include "types.h"

extern "C" char lbl_8049E500[];
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void* fn_801286C0(void* p, s16 n) {
    if (p) {
        *(void**)p = lbl_8049E500;
        *(s32*)((u8*)p + 0x23c) = 0;
        __dt__13Base_8010E074Fv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" u8 fn_80128B18(char* p) {
    return *(s32*)(p + 0x230) == 10;
}

extern "C" s32 fn_80128B2C(char* p) {
    return *(s32*)(p + 0x230);
}

extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AF38;
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_80539F38;
extern "C" void fn_8010DF58(void* p);
extern "C" void fn_8010DF98(void);
extern "C" void fn_8044C028(u8* this_, f32 val);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, s32 x);
extern "C" void fn_80128728(void* p, s32 x);
extern "C" void fn_80128C58(u8 val) {
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x2c) + 0xc) = val;
}

extern "C" void fn_80128C68(char* p) {
    fn_80128C58((s32)*(f32*)(p + 0x234));
    if (*(s32*)(p + 0x230) > 0 && *(s32*)(p + 0x230) < 4) {
        fn_8044C028((u8*)lbl_8053AF38, *(f32*)(p + 0x238));
    }
    fn_8010DF58(p);
}

extern "C" void fn_80128F10(char* p) {
    fn_8010DF98();
    void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
    *(s32*)(p + 0x23c) = ((s32 (*)(void*, s32, void*))(*(void***)obj)[6])(obj, 0x3f3f3f3f, lbl_80539F38);
    fn_802D7440(fn_802D6A9C(), 0);
    fn_80128728(p, 0);
}

