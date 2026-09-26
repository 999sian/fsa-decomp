// TU 0x8020db74-0x8020f798 (actor FLOR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_8020F474_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6004[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8020F474(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6004;
        fn_801EE434(*(void**)(p + 0x2b0));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8030C210(void* mgr, void* pos);
extern char* lbl_8053AB10;

extern "C" void fn_8020DDC4(char* this_) {
    if (*(s32*)(this_ + 0x248) != 0) {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
    }
}

extern "C" void* fn_801D0F40(void* this_);
extern "C" const f32 lbl_8053FA2C;

extern "C" void* fn_8020F510(char* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A6004;
    *(f32*)(this_ + 0x2a8) = lbl_8053FA2C;
    *(f32*)(this_ + 0x2ac) = lbl_8053FA2C;
    *(s32*)(this_ + 0x2b0) = 0;
    *(f32*)(this_ + 0x2b4) = lbl_8053FA2C;
    *(s32*)(this_ + 0x2b8) = -1;
    *(s32*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x2c0) = -1;
    return this_;
}

extern "C" void fn_801D00B4(void* this_, s32 id, f32 f, f32* out);
extern "C" const f32 lbl_8053FA28;

extern "C" void fn_8020E268(char* this_) {
    f32 v[2];
    *(f32*)(this_ + 0x3c) = lbl_8053FA2C;
    *(f32*)(this_ + 0x40) = lbl_8053FA2C;
    *(f32*)(this_ + 0x44) = lbl_8053FA2C;
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
        if (*(s32*)(this_ + 0x2b8) >= 0) {
            fn_801D00B4(this_, *(s32*)(this_ + 0x2b8), lbl_8053FA28, v);
            *(f32*)(this_ + 0x3c) = v[0];
            *(f32*)(this_ + 0x40) = v[1];
        }
        break;
    }
}

extern "C" u8 fn_801F2DB4(void* this_, u32 a, u32 b, u32 c);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" void fn_8020ED5C(void* this_, s32 st);

extern "C" u8 fn_8020DF4C(char* this_) {
    u8 r = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053FA2C &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053FA2C) {
        r = fn_801F2DB4(this_, *(u32*)(this_ + 0x1a0), 'NULL', 0);
        if (r) {
            fn_801F0E34(this_, 0x5007d, 0);
            u8 ok = 0;
            switch (*(s32*)(this_ + 0x248)) {
            case 3:
            case 5:
            case 6:
            case 8:
                ok = 1;
                break;
            }
            if (ok) {
                fn_8020ED5C(this_, 4);
            }
        }
    }
    return r;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
