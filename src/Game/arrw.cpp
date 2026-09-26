// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8016545C-80166BD0 (ARRW). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_801662D8_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A05E0[];

extern "C" void* fn_801662D8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A05E0;
        char* p = (char*)this_;
        for (s32 i = 0; i < 2; i++) {
            fn_801EE434(*(void**)(p + 0x278));
            p += 4;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8 fn_8022B160(void);
extern "C" s32 fn_8022F340(u32 params);
extern s32 lbl_804C6330[];

// ARRW init (vtable slot 1)
extern "C" void fn_80166814(char* this_) {
    *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 3;
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 3;
    if (fn_8022B160()) {
        lbl_804C6330[fn_8022F340(*(u32*)(this_ + 0x90))]++;
    }
    *(s32*)(this_ + 0x278) = 0;
    *(s32*)(this_ + 0x27c) = 0;
    *(f32*)(this_ + 0x60) = -2.0f;
    *(f32*)(this_ + 0x64) = -2.0f;
    *(f32*)(this_ + 0x68) = 2.0f;
    *(f32*)(this_ + 0x6c) = 2.0f;
    *(f32*)(this_ + 0x80) = -2.0f;
    *(f32*)(this_ + 0x84) = -2.0f;
    *(f32*)(this_ + 0x88) = 2.0f;
    *(f32*)(this_ + 0x8c) = 2.0f;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    switch (*(s32*)(this_ + 0x98)) {
    case 0:
        *(f32*)(this_ + 0x3c) = 5.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 1:
        *(f32*)(this_ + 0x3c) = -5.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 2:
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 5.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 3:
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = -5.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    }
    *(f32*)(this_ + 0x234) = 255.0f;
    *(s32*)(this_ + 0x24c) = 500;
    *(u8*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x26c) = 0;
    *(s32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x268) = *(s32*)(this_ + 0x98);
    *(s32*)(this_ + 0x230) = 0;
    *(u8*)(this_ + 0x274) = 0;
}

#include "JSystem/JUtility/TColor.h"
#include "dolphin/gx/GXStruct.h"
struct ArrwDrawParam {
    ArrwDrawParam() : m40(-1), m44(-1) {
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
struct ArrwResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
extern const char lbl_8046630C[];
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern const f32 lbl_8053D7C0;
extern const f32 lbl_8053D7C4;
extern "C" void fn_802F86CC(void* map, void* pos, void* res, f32 a, f32 b, s32 id, ArrwDrawParam* prm);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* pos, s32 effectRef, s32 flag,
                            s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);
extern "C" void fn_80158B5C(void* obj, u32 id, void* pos, GXColor color, f32 f);

extern "C" void fn_8016545C(char* p) {
    if (*(u16*)(p + 0x94) == 3) {
        return;
    }
    if (*(s32*)(p + 0x24c) >= 0x32 || !(*(s32*)(p + 0x24c) & 2)) {
        ArrwDrawParam prm;
        prm.reset();
        prm.mIdx[0x13] = (s32)*(f32*)(p + 0x234);
        prm.m4D = 1;
        if (fn_8022B160() == 1) {
            switch (*(s32*)(p + 0x90)) {
            case 0:
                prm.m60 = 0;
                break;
            case 1:
                prm.m60 = 1;
                break;
            case 2:
                prm.m60 = 2;
                break;
            case 3:
                prm.m60 = 3;
                break;
            }
        }
        s32 id = *(s32*)(p + 0x268) + 0x4c;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(ArrwResMgr**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_8046630C);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, res, lbl_8053D7C0, lbl_8053D7C0, id, &prm);
        }
        s32 eff = 0x4c;
        if ((*(u16*)(p + 0x94) == 0 || *(u16*)(p + 0x94) == 4) && *(s32*)(p + 0x230) == 0) {
            eff = 0x2df;
        }
        fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 4), p + 0xc, eff + *(s32*)(p + 0x268), 0, 2, -1, 0, 0, 0);
    }
    if ((*(u16*)(p + 0x94) == 2 || *(u16*)(p + 0x94) == 4) && *(s32*)(p + 0x230) != 4) {
        u32 id = *(u32*)(p + 4);
        JUtility::TColor color(0, 0, 0, 0x80);
        fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), id, p + 0xc, color, lbl_8053D7C4);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
