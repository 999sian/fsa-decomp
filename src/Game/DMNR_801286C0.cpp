#include "types.h"

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

