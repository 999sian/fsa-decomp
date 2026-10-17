#include "types.h"
#include "Game/ItemBase.h"

extern "C" void fn_8010E074(u8* this_);
extern "C" void fn_801D267C(u8* p);
extern u8 lbl_8049D740[];
extern f32 lbl_8053C628;
extern f32 lbl_8053C65C;

extern const f32 lbl_8053C644;
extern const f32 lbl_8053C64C;
extern const f32 lbl_8053C650;
extern const f32 lbl_8053C654;
extern "C" void fn_8010F668(f32 m[3][4], f32 axis[3], f32 angle);
extern "C" void* fn_801902C0(void);

extern "C" s32 fn_801123C8(s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 3:
            switch (param_2) {
                case 3: return 0x2d3;
                case 1: return 0x2df;
                case 0: return 0x2d0;
                case 2: return 0x2d6;
                case 4: return 0x2dc;
                default: return 0x2d9;
            }
        case 1:
            switch (param_2) {
                case 3: return 0x300;
                case 1: return 0x308;
                case 0: return 0x2fe;
                case 2: return 0x302;
                case 4: return 0x306;
                default: return 0x304;
            }
        case 0:
            switch (param_2) {
                case 3: return 0x2ff;
                case 1: return 0x307;
                case 0: return 0x2fd;
                case 2: return 0x301;
                case 4: return 0x305;
                default: return 0x303;
            }
        case 2:
            switch (param_2) {
                case 3: return 0x2d2;
                case 1: return 0x2de;
                case 0: return 0x2cf;
                case 2: return 0x2d5;
                case 4: return 0x2db;
                default: return 0x2d8;
            }
        case 5:
            switch (param_2) {
                case 3: return 0x2d4;
                case 1: return 0x2e0;
                case 0: return 0x2d1;
                case 2: return 0x2d7;
                case 4: return 0x2dd;
                default: return 0x2da;
            }
        default:
            switch (param_2) {
                case 3: return 0x2e5;
                case 1: return 0x2e9;
                case 0: return 0x2e4;
                case 2: return 0x2e6;
                case 4: return 0x2e8;
                default: return 0x2e7;
            }
    }
}

extern "C" s32 fn_80112C8C(void) {
    return 1;
}

extern "C" s32 fn_80112C94(u8* this_) {
    return *(s32*)(this_ + 0x238);
}

extern "C" void fn_80112C9C(u8* this_) {
    extern s32 lbl_80464678[];
    extern void* fn_8011921C(void);
    extern void fn_80112654(u8* this_, s32 n);

    if (*(s32*)(this_ + 0x23c) == 0) {
        s32 v = *(s32*)((char*)fn_8011921C() + 8);
        if (v == lbl_80464678[0x2b]) {
            fn_80112654(this_, 2);
        } else if (v == lbl_80464678[0x2c] + lbl_80464678[0x39 + *(s32*)(this_ + 0x234)]) {
            fn_80112654(this_, 3);
        } else if (v == lbl_80464678[0x2d]) {
            fn_80112654(this_, 4);
        } else if (v == lbl_80464678[0x2e]) {
            fn_80112654(this_, 5);
        } else if (v == lbl_80464678[0x2f]) {
            fn_80112654(this_, 6);
        } else if (v == lbl_80464678[0x30]) {
            fn_80112654(this_, 7);
        } else if (v == lbl_80464678[0x31]) {
            fn_80112654(this_, 8);
        } else if (v == lbl_80464678[0x32] + lbl_80464678[0x45 + *(s32*)(this_ + 0x234)]) {
            fn_80112654(this_, 9);
        } else if (v == lbl_80464678[0x33]) {
            fn_80112654(this_, 10);
        } else if (v == lbl_80464678[0x34]) {
            fn_80112654(this_, 11);
        } else if (v == lbl_80464678[0x35] + lbl_80464678[0x3f + *(s32*)(this_ + 0x234)]) {
            fn_80112654(this_, 12);
        } else if (v == lbl_80464678[0x37]) {
            fn_80112654(this_, 15);
        }
    }
}

extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern s32 lbl_80464704[];
extern const char lbl_804647B0[];
extern const f32 lbl_8053C644;
extern "C" void fn_80112E68(u8* this_) {
    fn_8010DF58(this_);
    if (this_[0x230] == 0) {
        s32 id = lbl_80464704[*(s32*)(this_ + 0x234)];
        DrawRec rec;
        fn_801F06F0(this_, lbl_804647B0, id + *(s32*)(this_ + 0x270), &rec, 7, lbl_8053C644, lbl_8053C644);
    }
}

extern "C" void fn_8010E074(u8* this_);
extern "C" void fn_801D267C(u8* p);
extern u8 lbl_8049D740[];
extern f32 lbl_8053C628;
extern f32 lbl_8053C65C;
extern "C" u8* fn_801134DC(u8* this_) {
    fn_8010E074(this_);
    *(u8**)(this_ + 0x0) = lbl_8049D740;
    f32 b = lbl_8053C65C;
    f32 a = lbl_8053C628;
    *(u8*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = -1;
    *(s32*)(this_ + 0x244) = 0;
    *(f32*)(this_ + 0x248) = a;
    *(f32*)(this_ + 0x24c) = a;
    *(f32*)(this_ + 0x250) = b;
    fn_801D267C(this_ + 0x260);
    *(s32*)(this_ + 0x298) = 0;
    *(s32*)(this_ + 0x29c) = 0;
    *(s32*)(this_ + 0x2a0) = 0;
    return this_;
}

