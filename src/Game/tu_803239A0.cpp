#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804AB3A8[];
struct FsaParam {
    s32 w0;
    s32 w1;
    s32 w2;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    s32 w3;
    u8 b11;
    u8 b12;
    u8 b13;
    s32 w4;
    s32 w5;
    s32 w6;
};

extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80541B70;
extern "C" char lbl_8047184C[];
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_802F86CC(void*, void*, void*, f32, f32, s32, void*);
extern "C" void fn_803239A0(char* this_) {
    u8 tbl[16];
    FsaParam p;
    u8 i;
    p.w0 = -1;
    p.w1 = -1;
    for (i = 0; i < 0x10; i += 8) {
        tbl[i] = i;
        tbl[(u8)(i + 1)] = i + 1;
        tbl[(u8)(i + 2)] = i + 2;
        tbl[(u8)(i + 3)] = i + 3;
        tbl[(u8)(i + 4)] = i + 4;
        tbl[(u8)(i + 5)] = i + 5;
        tbl[(u8)(i + 6)] = i + 6;
        tbl[(u8)(i + 7)] = i + 7;
    }
    p.w2 = 0;
    p.b0 = 0;
    p.b1 = 0;
    p.b2 = 0;
    p.b3 = 1;
    p.b4 = 1;
    p.b5 = 0;
    p.b6 = 1;
    p.w3 = 3;
    p.b7 = 1;
    p.w4 = -1;
    p.w5 = 0;
    p.w6 = 2;
    if (*(s16*)(this_ + 0x94) == 1 && *(s32*)(this_ + 4) < 8) {
        void* obj = *(void**)((char*)lbl_8053AAF8 + 0xa4);
        void* res = (void*)(*(void*(**)(void*, u32, char*))(*(void***)obj)[6])(obj, 0x534F4220, lbl_8047184C);
        fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), this_ + 0xc, res, lbl_80541B70, lbl_80541B70, 0xe7, tbl);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, 0xe7, 0, 2, -1, 0, 0, 0);
}

extern "C" void* fn_80324570(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB3A8;
        fn_801EE434(*(void**)(this_ + 0x26c));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}



