#include "types.h"

struct FsaObjVtbl {
    char pad_00[0x24];
    void (*fn24)(void* self, u8 b);
    char pad_28[0xec - 0x28];
    void (*fnEC)(void* self, s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g);
};

struct FsaObj {
    FsaObjVtbl* vtbl;
};


extern "C" void fn_8013B490(void* this_);
extern u8 lbl_80529DEC[];
extern void* lbl_8053AB10;
extern "C" void fn_803B7DCC(u8* this_) {
    if (*(s32*)(lbl_80529DEC + 0x118) != 8 || *(s32*)(lbl_80529DEC + 0x11c) != 3) {
        fn_8013B490(lbl_8053AB10);
        ((void (*)(void*, u8))(*(void***)*(void**)(this_ + 4))[9])(*(void**)(this_ + 4), this_[0x296]);
        ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))(*(void***)*(void**)(this_ + 4))[59])(*(void**)(this_ + 4), 0, 0, 0, 0.0f, 0.0f, 800.0f, 640.0f);
    }
}
